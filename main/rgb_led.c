
static void set_led(int r, int g, int b)
{
  /* Set the LED pixel using RGB from 0 (0%) to 255 (100%) for each color */
  led_strip_set_pixel(led_strip, 0, r, g, b);
  /* Refresh the strip to send data */
  led_strip_refresh(led_strip);
}

static void clear_led()
{
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