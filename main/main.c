/*
 * main.c
 *
 *  Created on: 12 apr 2023
 *      Author: Cotesta Tolentino
 */

/*
 * GPIOs definitions inside
 *    components/esp_custom_board/include/esp_board.h
 */
#include "esp_board.h"

/*
 * HMI created as components
 *    (esp_custom_board as dependency using local path)
 */
#include "custom_hmi.h"

// USB included as file
#include "usb/usb_main.c"

// RGB NeoPixel LED library
#include "led_strip.h"

// Some variables tied to menu items
int counter = 0;
int value1 = 100;
int value2 = 1500;
float value3 = 25.7;
float value4 = 12.1;
bool value5 = true;

const char *var_filename = "/var_tracing.csv";

// RGB led stuffs
static led_strip_handle_t led_strip;
int red = 5;
int green = 5;
int blue = 5;
#include "rgb_led.c"

// HMI function prototypes
static void link_menu_items();

/* Called when "WHITE" HMI button was "pressed" (using joypad MID button)*/
static void set_white_callback(lv_obj_t *obj);

/* Called when "OK" HMI button was "pressed" (using joypad MID button)
 *  A txt file with current variable values will be saved in MSC drive
 */
static void set_color_callback(lv_obj_t *obj);

static void set_HID_callback(lv_obj_t *obj){
    arrow_keypad_active = !arrow_keypad_active;
    if (arrow_keypad_active)
        lv_obj_add_state(ui_CheckboxHID, LV_STATE_CHECKED);
    else
        lv_obj_clear_state(ui_CheckboxHID, LV_STATE_CHECKED);
    printf("%s\n",arrow_keypad_active ? "HID arrrow keypad enabled" : "HID arrrow keypad disabled");
}


/* This function will build items relation for properly navigate menu using joypad buttons
 *  For each menu item, some properties need to be setted:
 *   - object to be highlighted
 *   - target screen to be shown on MID BUTTON click (can be NULL)
 *   - previous obj to point on UP BUTTON click (can be NULL)
 *   - next obj to point on DOWN BUTTON click (can be NULL)
 *
 *  Is also possible bind a variable to a a specific menu item ù
 *  in order to edit it's value using LEFT and RIGHT BUTTON click
 */
static void link_menu_items()
{
    // This is the sub menu selection screen
    // object to be highlighted, target screen (MID BUTTON), previous obj, next obj
    add_menu_item(ui_PanelEdit1, ui_ScreenEdit1, NULL, ui_PanelEdit2);
    add_menu_item(ui_PanelEdit2, ui_ScreenEdit2, ui_PanelEdit1, ui_PanelEditRGB);
    add_menu_item(ui_PanelEditRGB, ui_ScreenEditRGB, ui_PanelEdit2, ui_PanelEditHID);
    add_menu_item(ui_PanelEditHID, ui_ScreenSetup, ui_PanelEditRGB, ui_PanelEdit1);
    bind_callback_to_object(ui_PanelEditHID, set_HID_callback);

    // This is the item in edit screens
    // object to be highlighted, target screen (MID BUTTON), previous obj, next obj
    add_menu_item(ui_Panel1, NULL, NULL, ui_Panel2);
    add_menu_item(ui_Panel2, NULL, ui_Panel1, NULL);

    add_menu_item(ui_Panel3, NULL, NULL, ui_Panel4);
    add_menu_item(ui_Panel4, NULL, ui_Panel3, ui_Panel5);
    add_menu_item(ui_Panel5, NULL, ui_Panel4, NULL);

    add_menu_item(ui_PanelRed, NULL, ui_PanelBlue, ui_PanelGreen);
    add_menu_item(ui_PanelGreen, NULL, ui_PanelRed, ui_PanelBlue);
    add_menu_item(ui_PanelBlue, NULL, ui_PanelGreen, ui_ButtonOK);

    add_menu_item(ui_ButtonOK, NULL, ui_PanelBlue, ui_ButtonWHITE);
    add_menu_item(ui_ButtonWHITE, NULL, ui_ButtonOK, ui_PanelRed);

    // Attach the function to be called (on MID button click) to the menu objects (Buttons)
    bind_callback_to_object(ui_ButtonOK, set_color_callback);
    bind_callback_to_object(ui_ButtonWHITE, set_white_callback);

    // Attach the variable to be edited to the menu objects (text label)
    // object to be highlighted, target text obj for value, pointer to variable, type of variable
    bind_variable_to_object(ui_Panel1, ui_value1, &value1, typeof(value1));
    bind_variable_to_object(ui_Panel2, ui_value2, &value2, typeof(value2));
    bind_variable_to_object(ui_Panel3, ui_value3, &value3, typeof(value3));
    bind_variable_to_object(ui_Panel4, ui_value4, &value4, typeof(value4));
    bind_variable_to_object(ui_Panel5, ui_value5, &value5, typeof(value5));
    bind_variable_to_object(ui_PanelRed, ui_valueRed, &red, typeof(red));
    bind_variable_to_object(ui_PanelGreen, ui_valueGreen, &green, typeof(green));
    bind_variable_to_object(ui_PanelBlue, ui_valueBlue, &blue, typeof(blue));
    // Set the range for this variables
    set_variable_range(ui_PanelRed, 0, 255);
    set_variable_range(ui_PanelGreen, 0, 255);
    set_variable_range(ui_PanelBlue, 0, 255);
    // Set the first object to be highlighted on edit menu
    set_first_menu_object(ui_PanelEdit1);
}

/* Load variables last values from var_tracing.csv file (last line)*/
static int load_last_values()
{
    if (tinyusb_msc_storage_in_use_by_usb_host())
    {
        ESP_LOGE("READ", "storage exposed over USB. Application can't read from storage.");
        return -1;
    }
    ESP_LOGD("READ", "read from storage:");
    char path[32];
    strcpy(path, BASE_PATH);
    strcat(path, var_filename);
    FILE *pFile = fopen(path, "r");
    if (!pFile)
    {
        ESP_LOGE("READ", "Filename not present - %s", var_filename);
        return -1;
    }
    int num_rows = 0;
    int last_pos = 0;
    char ch;
    // Count the rows number and set last-1 position in order to get last row content
    while (!feof(pFile))
    {
        ch = fgetc(pFile);
        if (ch == '\n')
        {
            num_rows++;
            // If this is not the last row, save position
            ch = fgetc(pFile);
            if (!feof(pFile))
            {
                last_pos = ftell(pFile);
            }
        }
    }
    fseek(pFile, last_pos - 1, SEEK_SET);

    // char buf[64];
    // while (fgets(buf, sizeof(buf), pFile) != NULL) {
    //     printf("%s", buf);
    // }
    fscanf(pFile, "%d", &value1);
    fscanf(pFile, "%d", &value2);
    fscanf(pFile, "%f", &value3);
    fscanf(pFile, "%f", &value4);
    fscanf(pFile, "%d", &value5);
    fscanf(pFile, "%d", &red);
    fscanf(pFile, "%d", &green);
    fscanf(pFile, "%d", &blue);
    fclose(pFile);

    printf("Last saved values: %d\t %d\t %3.1f\t %3.1f\t %d\t %d\t %d\t %d\n",
           value1, value2, value3, value4, value5, red, green, blue);
    set_led(red, green, blue);
    return 1;
}

/* Append variables values to file. Create if don't exists*/
static int append_to_file(const char *str)
{
    if (tinyusb_msc_storage_in_use_by_usb_host())
    {
        ESP_LOGE("WRITE", "storage exposed over USB. Application can't write to storage.");
        return -1;
    }
    ESP_LOGD("WRITE", "write to storage:");
    char path[32];
    strcpy(path, BASE_PATH);
    strcat(path, var_filename);
    FILE *pFile = fopen(path, "r");
    if (!pFile)
    {
        ESP_LOGW("WRITE", "%s doesn't exist yet, creating", var_filename);
        pFile = fopen(path, "w");
        fprintf(pFile, "v1\t v2\t v3\t v4\t v5\t R\t G\t B\n");
        fclose(pFile);
    }
    pFile = fopen(path, "a");
    fprintf(pFile, str);
    fclose(pFile);
    return 1;
}

/* Called when "WHITE" HMI button was "pressed" (using joypad MID button)*/
static void set_white_callback(lv_obj_t *obj)
{
    printf("Object %d trigger this callback\n", obj);
    red = 20;
    green = 20;
    blue = 20;
    update_variable(get_item_pt(ui_PanelRed), 0);
    update_variable(get_item_pt(ui_PanelGreen), 0);
    update_variable(get_item_pt(ui_PanelBlue), 0);
    set_led(red, green, blue);
}

/* Called when "OK" HMI button was "pressed" (using joypad MID button)*/
static void set_color_callback(lv_obj_t *obj)
{
    printf("Object %d trigger this callback\n", obj);
    set_led(red, green, blue);

    char var_str[128];
    snprintf(
        var_str, sizeof(var_str),
        "%d\t %d\t %3.1f\t %3.1f\t %d\t %d\t %d\t %d\n",
        value1, value2, value3, value4, value5, red, green, blue);
    append_to_file(var_str);
}

// A very simple task which increment a variable once a second
// In the same task, update also RGB led when values change
static void counter_task(void *arg)
{
    while (1)
    {
        counter++;
        set_int_value(ui_Counter, counter);
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

void app_main(void)
{

    // Init hmi (lcd + joypad)
    hmi_main();

    // Start counter task
    xTaskCreatePinnedToCore(counter_task, "Counter Task", 4096, NULL, 5, NULL, tskNO_AFFINITY);

    // Configure RGB led
    configure_led();

    // Start USB stuff
    usb_main();

    // Load variable values from file
    msc_mount(); // Mount partition in the app
    load_last_values();
    set_led(red, green, blue);

    // expose partition to PC
    // NB: writing variable values will not be possible until drive was unmounted
    // msc_unmount();

    // Build items relation for properly navigate menu using joypad buttons
    link_menu_items();
}
