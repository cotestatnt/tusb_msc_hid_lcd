
#include "joypad.h"
#include "custom_hmi.h"

static int btns_pin[BUTTON_NUM] = {BTN_UP, BTN_DOWN, BTN_LEFT, BTN_RIGHT, BTN_MID, BTN_SET, BTN_RES};
static button_handle_t g_btns[BUTTON_NUM];

// Current selected menu item
extern lv_obj_t * current_obj;
extern lv_obj_t * first_obj;
extern lv_obj_t * last_screen;

int get_btn_index(button_handle_t btn)
{
  for (size_t i = 0; i < BUTTON_NUM; i++) {
    if (btn == g_btns[i]) {
      return i;
    }
  }
  return -1;
}


void button_single_click_cb(void *arg, void *data)
{
  int index = get_btn_index((button_handle_t)arg);
  ESP_LOGI(TAG, "BTN%d: BUTTON_SINGLE_CLICK", index);

  menu_item item = get_item(current_obj);
  // If no item selected, set the first one as next
  if (item.next == NULL)
    item.next = first_obj;

  switch (btns_pin[index]) {
    case BTN_RES:
      printf("Go back to previous active screen\n");
      set_menu_screen_active(last_screen);
      break;
    case BTN_SET:
      if (lv_scr_act() == ui_ScreenMain) {
        printf("Enter setup menu\n");
        set_menu_screen_active(ui_ScreenSetup);
      }
      else {
        printf("Exit setup menu\n");
        set_menu_screen_active(ui_ScreenMain);
      }
      break;
    case BTN_UP:
      set_item_active(&item, false);
      break;
    case BTN_DOWN:
      set_item_active(&item, true);
      break;
    case BTN_LEFT:
      update_variable(&item, -1);
      break;
    case BTN_RIGHT:
      update_variable(&item, +1);
      break;
    case BTN_MID:
      set_menu_screen_active(item.screen);
      if (item.cb_function != NULL) {
        item.cb_function(item.obj);
      }

      break;
    default:
      break;
  }
}

// void button_double_click_cb(void *arg, void *data)
// {
//   TEST_ASSERT_EQUAL_HEX(BUTTON_DOUBLE_CLICK, iot_button_get_event(arg));
//   ESP_LOGI(TAG, "BTN%d: BUTTON_DOUBLE_CLICK", get_btn_index((button_handle_t)arg));
// }

void button_long_press_hold_cb(void *arg, void *data)
{
  int index = get_btn_index((button_handle_t)arg);
  menu_item item = get_item(current_obj);
  int step = 10;

  switch (btns_pin[index]) {
    case BTN_LEFT:
      update_variable(&item, -1 * step);
      break;
    case BTN_RIGHT:
      update_variable(&item, step);
      break;
    default:
      break;
  }
}


esp_err_t custom_button_gpio_init(void *param)
{
  button_gpio_config_t *cfg = (button_gpio_config_t *)param;
  return button_gpio_init(cfg);
}

uint8_t custom_button_gpio_get_key_value(void *param)
{
  button_gpio_config_t *cfg = (button_gpio_config_t *)param;
  return button_gpio_get_key_level((void *)cfg->gpio_num);
}

esp_err_t custom_button_gpio_deinit(void *param)
{
  button_gpio_config_t *cfg = (button_gpio_config_t *)param;
  return button_gpio_deinit(cfg->gpio_num);
}

void joypad_buttons_init()
{
  for (size_t i = 0; i < BUTTON_NUM; i++) {
    button_gpio_config_t *gpio_cfg = calloc(1, sizeof(button_gpio_config_t));
    gpio_cfg->active_level = 0;
    gpio_cfg->gpio_num = btns_pin[i];

    button_config_t cfg = {
        .type = BUTTON_TYPE_CUSTOM,
        .long_press_time = CONFIG_BUTTON_LONG_PRESS_TIME_MS,
        .short_press_time = CONFIG_BUTTON_SHORT_PRESS_TIME_MS,
        .custom_button_config = {
            .button_custom_init = custom_button_gpio_init,
            .button_custom_deinit = custom_button_gpio_deinit,
            .button_custom_get_key_value = custom_button_gpio_get_key_value,
            .active_level = 0,
            .priv = gpio_cfg,
        },
    };

    button_handle_t btn = iot_button_create(&cfg);
    g_btns[i] = btn;
    iot_button_register_cb(btn, BUTTON_SINGLE_CLICK, button_single_click_cb, NULL);
    // iot_button_register_cb(btn, BUTTON_DOUBLE_CLICK, button_double_click_cb, NULL);
    iot_button_register_cb(btn, BUTTON_LONG_PRESS_HOLD, button_long_press_hold_cb, NULL);
  }
}