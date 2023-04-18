#pragma once

#include "custom_hmi.h"


#ifdef __cplusplus
extern "C" {
#endif


/***************************************/
/*              JOYPAD                 */
/***************************************/

#define BUTTON_NUM 7

int get_btn_index(button_handle_t btn);
void button_single_click_cb(void *arg, void *data);
// void button_double_click_cb(void *arg, void *data);
void button_long_press_hold_cb(void *arg, void *data);
esp_err_t custom_button_gpio_init(void *param);
uint8_t custom_button_gpio_get_key_value(void *param);
esp_err_t custom_button_gpio_deinit(void *param);
void joypad_buttons_init();

#ifdef __cplusplus
}
#endif