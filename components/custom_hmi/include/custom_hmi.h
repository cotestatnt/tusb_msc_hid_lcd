#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "iot_button.h"

#include "esp_board.h"

#include "lvgl.h"
#include "../ui/ui.h"
#include "../ui/ui_helpers.h"

#include "typename.h"
#include "joypad.h"

#ifdef __cplusplus
extern "C"
{
#endif

#define APP_DISP_DEFAULT_BRIGHTNESS 100 // 0-100%
#define TAG "HMI"

// The format to be printed float value on menu (1 decimal point)
#define FLOAT_FORMAT "%3.1f"
#define _OPEN_SYS_ITOA_EXT

    typedef void (*object_callback)(lv_obj_t *obj);

    typedef struct
    {
        lv_obj_t *obj;
        lv_obj_t *prev;        // The previous item in list (in order to navigate the menu properly)
        lv_obj_t *next;        // The next item in list (in order to navigate the menu properly)
        lv_obj_t *screen;      // The screen to be selected on MID button
        lv_obj_t *value_label; // The value object (label) to be updated and shown
        object_callback cb_function;
        void *variable; // The variable linked to the object
        short var_type; // The type of variable linked to the object
        double min;
        double max;

    } menu_item;

    /******************************************************************************
     * Function prototypes
     *******************************************************************************/

    menu_item get_item(lv_obj_t *obj);
    menu_item *get_item_pt(lv_obj_t *obj);
    void set_menu_screen_active(lv_obj_t *target);
    void set_item_active(menu_item *target, bool next);

    void set_bool_value(lv_obj_t *obj, bool value);
    void set_int_value(lv_obj_t *obj, long value);
    void set_unsigned_int_value(lv_obj_t *obj, unsigned long value);
    void set_double_value(lv_obj_t *obj, double value, const char *format);
    void update_variable(menu_item *item, float step);
    void app_lvgl_display(void);

    /*******************************************************************************
     * Public functions
     *******************************************************************************/

    // Add a new item to list. In order to navigate properly in menu, each item
    int add_menu_item(lv_obj_t *obj, lv_obj_t *screen, lv_obj_t *prev, lv_obj_t *next);

    // Bind a specific variable (pointer to) with a menu item
    void bind_variable_to_label(lv_obj_t *obj, lv_obj_t *value_lbl, void *var, int v_type);

    void bind_callback_to_label(lv_obj_t *obj, object_callback cb);

    void set_variable_range(lv_obj_t *obj, double min, double max);

    void set_first_menu_object(lv_obj_t *obj);

    // Init HMI (joypad + LCD)
    void hmi_main();

#ifdef __cplusplus
}
#endif