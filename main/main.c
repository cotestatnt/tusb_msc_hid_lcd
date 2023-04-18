/*
 * main.c
 *
 *  Created on: 12 apr 2023
 *      Author: Cotesta Tolentino
 */
#include "led_strip.h"


// HMI created as components
// GPIOs definitions inside joypad.h
#include "custom_hmi.h"

// USB included as file
#include "usb/usb_main.c"


int counter = 0;
int value1 = 100;
int value2 = 1500;
float value3 = 25.7;
float value4 = 12.1;
bool value5 = true;

static led_strip_handle_t led_strip;
int red = 5;
int green = 5;
int blue = 5;


// Function prototypes
static void link_menu_items();

static void set_led(int r, int g, int b) ;
static void clear_led();
static void configure_led();

void set_white_callback (lv_obj_t * obj);
void set_color_callback (lv_obj_t * obj);


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
static void link_menu_items() {
    // This is the sub menu selection screen
    // object to be highlighted, target screen (MID BUTTON), previous obj, next obj
    add_menu_item(ui_itemLbl1, ui_ScreenEdit1, NULL, ui_itemLbl2);
    add_menu_item(ui_itemLbl2, ui_ScreenEdit2, ui_itemLbl1, ui_itemLblRGB);
    add_menu_item(ui_itemLblRGB, ui_ScreenEditRGB, ui_itemLbl2, ui_itemLblhome);
    add_menu_item(ui_itemLblhome, ui_ScreenMain, ui_itemLblRGB, ui_itemLbl1);

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
    bind_callback_to_label(ui_ButtonOK, set_color_callback);
    bind_callback_to_label(ui_ButtonWHITE, set_white_callback);


    // Attach the variable to be edited to the menu objects (text label)
    // object to be highlighted, target text obj for value, pointer to variable, type of variable
    bind_variable_to_label(ui_Panel1, ui_value1, &value1, typeof(value1));
    bind_variable_to_label(ui_Panel2, ui_value2, &value2, typeof(value2));
    bind_variable_to_label(ui_Panel3, ui_value3, &value3, typeof(value3));
    bind_variable_to_label(ui_Panel4, ui_value4, &value4, typeof(value4));
    bind_variable_to_label(ui_Panel5, ui_value5, &value5, typeof(value5));
    bind_variable_to_label(ui_PanelRed, ui_valueRed, &red, typeof(red));
    bind_variable_to_label(ui_PanelGreen, ui_valueGreen, &green, typeof(green));
    bind_variable_to_label(ui_PanelBlue, ui_valueBlue, &blue, typeof(blue));
    // Set the range for this variables
    set_variable_range(ui_PanelRed, 0, 255);
    set_variable_range(ui_PanelGreen, 0, 255);
    set_variable_range(ui_PanelBlue, 0, 255);
    // Set the first object to be highlighted on edit menu
    set_first_menu_object(ui_itemLbl1);
}


void set_white_callback (lv_obj_t * obj){
    printf("Object %d trigger this callback\n", obj);
    red = 127;
    green = 127;
    blue = 127;
    update_variable(get_item_pt(ui_PanelRed), 0);
    update_variable(get_item_pt(ui_PanelGreen), 0);
    update_variable(get_item_pt(ui_PanelBlue), 0);
    set_led(red, green, blue);
}

void set_color_callback (lv_obj_t * obj){
    printf("Object %d trigger this callback\n", obj);
    set_led(red, green, blue);
}

static void set_led(int r, int g, int b) {
    /* Set the LED pixel using RGB from 0 (0%) to 255 (100%) for each color */
    led_strip_set_pixel(led_strip, 0, r, g, b);
    /* Refresh the strip to send data */
    led_strip_refresh(led_strip);
}

static void clear_led() {
    /* Set all LED off to clear all pixels */
    led_strip_clear(led_strip);
}

static void configure_led()
{
    ESP_LOGI(TAG, "Configure addressable LED!");
    /* LED strip initialization with the GPIO and pixels number*/
    led_strip_config_t strip_config = {
        .strip_gpio_num = BSP_LEDSTRIP_IO,
        .max_leds = 1, // at least one LED on board
    };
    led_strip_rmt_config_t rmt_config = {
        .resolution_hz = 10 * 1000 * 1000, // 10MHz
    };
    ESP_ERROR_CHECK(led_strip_new_rmt_device(&strip_config, &rmt_config, &led_strip));
    /* Set all LED off to clear all pixels */
    clear_led();
}

// A very simple task which increment a variable once a second
// In the same task, update also RGB led when values change
static void counter_task(void *arg)
{
    while (1) {
        counter++;
        set_int_value (ui_Counter, counter);
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

void app_main(void)
{
    configure_led();
    set_led(red, green, blue);

    // Init hmi (lcd + joypad)
    hmi_main();

    // Build items relation for properly navigate menu using joypad buttons
    link_menu_items();

    // Start counter task
    xTaskCreatePinnedToCore(counter_task, "Counter Task", 4096, NULL, 5, NULL, tskNO_AFFINITY);

    // Start USB stuff
    usb_main();
}
