#include "usb_descriptor.h"
#include "msc/tusb_msc.c"
#include "hid/tusb_hid.c"

static const char *USB_TAG = "USB_MAIN";


// A very simple task which increment a variable once a second
static void usb_hid_task(void *arg)
{
    while (1) {
		if (tud_mounted()) {
			static bool send_hid_data = true;
			if (send_hid_data) {
				app_send_hid_demo();
			}
			send_hid_data = !gpio_get_level(APP_BUTTON);
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
        .wl_handle = wl_handle
    };
    ESP_ERROR_CHECK(tinyusb_msc_storage_init_spiflash(&config_spi));
#else // CONFIG_EXAMPLE_STORAGE_MEDIA_SPIFLASH
    static sdmmc_card_t *card = NULL;
    ESP_ERROR_CHECK(storage_init_sdmmc(&card));

    const tinyusb_msc_sdmmc_config_t config_sdmmc = {
        .card = card
    };
    ESP_ERROR_CHECK(tinyusb_msc_storage_init_sdmmc(&config_sdmmc));
#endif  // CONFIG_EXAMPLE_STORAGE_MEDIA_SPIFLASH

    //mounted in the app by default
    _mount();

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
    for (int count = 0; count < sizeof(cmds) / sizeof(esp_console_cmd_t); count++) {
        ESP_ERROR_CHECK( esp_console_cmd_register(&cmds[count]) );
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