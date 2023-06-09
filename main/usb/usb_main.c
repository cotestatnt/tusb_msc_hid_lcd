#include "usb_descriptor.h"
#include "msc/tusb_msc.c"
#include "hid/tusb_hid.c"

static bool arrow_keypad_active = false;

static const char *USB_TAG = "USB_MAIN";


static void send_keycode(uint8_t* keycode)
{
    ESP_LOGI(HID_TAG, "Sending Keyboard report");
    tud_hid_keyboard_report(HID_ITF_PROTOCOL_KEYBOARD, 0, keycode);
    vTaskDelay(pdMS_TO_TICKS(50));
    tud_hid_keyboard_report(HID_ITF_PROTOCOL_KEYBOARD, 0, NULL);
}

static void app_send_hid_demo(void)
{
    // Keyboard output: Send key 'a/A' pressed and released
    uint8_t keycode[6] = {HID_KEY_A};
    send_keycode(keycode);

    // Mouse output: Move mouse cursor in square trajectory
    ESP_LOGI(HID_TAG, "Sending Mouse report");
    int8_t delta_x;
    int8_t delta_y;
    for (int i = 0; i < (DISTANCE_MAX / DELTA_SCALAR) * 4; i++)
    {
        // Get the next x and y delta in the draw square pattern
        mouse_draw_square_next_delta(&delta_x, &delta_y);
        tud_hid_mouse_report(HID_ITF_PROTOCOL_MOUSE, 0x00, delta_x, delta_y, 0, 0);
        vTaskDelay(pdMS_TO_TICKS(20));
    }
}

// A very simple task which increment a variable once a second
static void usb_hid_task(void *arg)
{
    while (1)
    {
        if (tud_mounted())
        {
            if (arrow_keypad_active) {
                if (!gpio_get_level(BTN_UP)) {
                    uint8_t keycode[6] = {HID_KEY_ARROW_UP};
                    send_keycode(keycode);
                }
                if (!gpio_get_level(BTN_DOWN)) {
                    uint8_t keycode[6] = {HID_KEY_ARROW_DOWN};
                    send_keycode(keycode);
                }
                if (!gpio_get_level(BTN_LEFT)) {
                    uint8_t keycode[6] = {HID_KEY_ARROW_LEFT};
                    send_keycode(keycode);
                }
                if (!gpio_get_level(BTN_RIGHT)) {
                    uint8_t keycode[6] = {HID_KEY_ARROW_RIGHT};
                    send_keycode(keycode);
                }
            }
            else {
                static bool send_hid_data = false;
                if (send_hid_data)
                {
                    app_send_hid_demo();
                }
                send_hid_data = !gpio_get_level(APP_BUTTON);
            }

        }
        vTaskDelay(pdMS_TO_TICKS(100));
    }
}

void usb_main(void)
{
    ESP_LOGI(USB_TAG, "Initializing storage...");

#ifdef CONFIG_EXAMPLE_STORAGE_MEDIA_SPIFLASH
    static wl_handle_t wl_handle = WL_INVALID_HANDLE;
    ESP_ERROR_CHECK(storage_init_spiflash(&wl_handle));

    const tinyusb_msc_spiflash_config_t config_spi = {
        .wl_handle = wl_handle};
    ESP_ERROR_CHECK(tinyusb_msc_storage_init_spiflash(&config_spi));
#else  // CONFIG_EXAMPLE_STORAGE_MEDIA_SPIFLASH
    static sdmmc_card_t *card = NULL;
    ESP_ERROR_CHECK(storage_init_sdmmc(&card));

    const tinyusb_msc_sdmmc_config_t config_sdmmc = {
        .card = card};
    ESP_ERROR_CHECK(tinyusb_msc_storage_init_sdmmc(&config_sdmmc));
#endif // CONFIG_EXAMPLE_STORAGE_MEDIA_SPIFLASH

    // mounted in the app by default
    msc_mount();

    ESP_LOGI(USB_TAG, "USB MSC initialization");
    const tinyusb_config_t tusb_cfg = {
        .device_descriptor = &descriptor_config,
        .string_descriptor = string_desc_arr,
        .string_descriptor_count = sizeof(string_desc_arr) / sizeof(string_desc_arr[0]),
        .external_phy = false,
        .configuration_descriptor = desc_configuration,
    };
    ESP_ERROR_CHECK(tinyusb_driver_install(&tusb_cfg));
    ESP_LOGI(USB_TAG, "USB MSC initialization DONE");

    esp_console_repl_t *repl = NULL;
    esp_console_repl_config_t repl_config = ESP_CONSOLE_REPL_CONFIG_DEFAULT();
    /* Prompt to be printed before each line.
     * This can be customized, made dynamic, etc.
     */
    repl_config.prompt = PROMPT_STR ">";
    repl_config.max_cmdline_length = 64;
    esp_console_register_help_command();
    esp_console_dev_uart_config_t hw_config = ESP_CONSOLE_DEV_UART_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_console_new_repl_uart(&hw_config, &repl_config, &repl));
    for (int count = 0; count < sizeof(cmds) / sizeof(esp_console_cmd_t); count++)
    {
        ESP_ERROR_CHECK(esp_console_cmd_register(&cmds[count]));
    }
    ESP_ERROR_CHECK(esp_console_start_repl(repl));

    // Initialize button that will trigger HID reports
    const gpio_config_t boot_button_config = {
        .pin_bit_mask = BIT64(APP_BUTTON),
        .mode = GPIO_MODE_INPUT,
        .intr_type = GPIO_INTR_DISABLE,
        .pull_up_en = true,
        .pull_down_en = false,
    };
    ESP_ERROR_CHECK(gpio_config(&boot_button_config));

    // Start USB-HID task
    xTaskCreatePinnedToCore(usb_hid_task, "USB HID Task", 4096, NULL, 6, NULL, tskNO_AFFINITY);
}