#include "custom_hmi.h"
#include "limits.h"
#include "float.h"

// Current selected menu item
lv_obj_t *current_obj = NULL;
lv_obj_t *first_obj = NULL;
lv_obj_t *last_screen = NULL;

/* Menu item list connections
 *  MID button single click, select next screen (if defined)
 *  LEFT/RIGHT single click, update item value (if defined)
 *  UP/DOWN single click, select next item
 */
#define MAX_ITEMS 16
menu_item items[MAX_ITEMS];
unsigned int item_num = 0;

/*******************************************************************************
 * UI handlers Private functions
 *******************************************************************************/
menu_item get_item(lv_obj_t *obj)
{
    menu_item item = {0};
    for (int i = 0; i < item_num; i++)
    {
        if (items[i].obj == obj)
        {
            return items[i];
            break;
        }
    }
    return item;
}

menu_item *get_item_pt(lv_obj_t *obj)
{
    menu_item *item = NULL;
    for (int i = 0; i < item_num; i++)
    {
        if (items[i].obj == obj)
        {
            item = &items[i];
            break;
        }
    }
    return item;
}

void set_menu_screen_active(lv_obj_t *target)
{
    lv_obj_t *current = lv_scr_act();
    if (NULL != target && target != current)
    {
        last_screen = current;
        printf("Set new screen\n");
        _ui_screen_change(target, LV_SCR_LOAD_ANIM_OVER_LEFT, 500, 0);

        // Set first child for current screen and clear focused state
        lv_obj_t *first_child = lv_obj_get_child(target, 0);
        first_obj = first_child;
        for (int i = 0; i < lv_obj_get_child_cnt(target); i++)
        {
            lv_obj_clear_state(lv_obj_get_child(target, i), LV_STATE_FOCUSED);
        }
        current_obj = NULL;
    }
}

void set_item_active(menu_item *target, bool next)
{
    lv_obj_t *setObj = next ? target->next : target->prev;
    // printf("current %d\n", current_obj);
    // printf("next %d\n", setObj);

    if (NULL != current_obj && lv_scr_act() != ui_ScreenMain)
    {
        printf("Clear actual selected item\n");
        lv_obj_clear_state(current_obj, LV_STATE_FOCUSED);
    }
    if (NULL != setObj && lv_scr_act() != ui_ScreenMain)
    {
        printf("Set new item active\n");
        lv_obj_add_state(setObj, LV_STATE_FOCUSED);
        // Set current selected object as actual
        current_obj = setObj;
    }
}

void set_bool_value(lv_obj_t *obj, bool value)
{
    _ui_label_set_property(obj, _UI_LABEL_PROPERTY_TEXT, value ? "true" : "false");
}

void set_int_value(lv_obj_t *obj, long value)
{
    char val[16];
    itoa(value, val, 10);
    _ui_label_set_property(obj, _UI_LABEL_PROPERTY_TEXT, val);
}

void set_unsigned_int_value(lv_obj_t *obj, unsigned long value)
{
    char val[16];
    utoa(value, val, 10);
    _ui_label_set_property(obj, _UI_LABEL_PROPERTY_TEXT, val);
}

void set_double_value(lv_obj_t *obj, double value, const char *format)
{
    char buff[16];
    snprintf(buff, sizeof(buff), format, value);
    _ui_label_set_property(obj, _UI_LABEL_PROPERTY_TEXT, buff);
}

void update_variable(menu_item *item, float step)
{

    // If this item has a linked variable, edit the value
    if (NULL != item->variable)
    {
        switch (item->var_type)
        {
        case TYPENAME_INT:
        case TYPENAME_LONG_INT:
            *(long *)item->variable += step;
            if (*(long *)item->variable > item->max)
                *(long *)item->variable = item->max;
            if (*(long *)item->variable < item->min)
                *(long *)item->variable = item->min;
            set_int_value(item->value_label, *(long *)item->variable);
            break;

        case TYPENAME_UNSIGNED_INT:
        case TYPENAME_UNSIGNED_LONG_INT:
            *(unsigned int *)item->variable += step;
            if (*(unsigned int *)item->variable > item->max)
                *(unsigned int *)item->variable = item->max;
            if (*(unsigned int *)item->variable < item->min)
                *(unsigned int *)item->variable = item->min;
            set_unsigned_int_value(item->value_label, *(unsigned long *)item->variable);
            break;

        case TYPENAME_FLOAT:
            *(float *)item->variable += step / 10;
            if (*(float *)item->variable > item->max)
                *(float *)item->variable = item->max;
            if (*(float *)item->variable < item->min)
                *(float *)item->variable = item->min;
            set_double_value(item->value_label, *(float *)item->variable, FLOAT_FORMAT);
            break;
        case TYPENAME_DOUBLE:
            *(double *)item->variable += step / 10;
            if (*(double *)item->variable > item->max)
                *(double *)item->variable = item->max;
            if (*(double *)item->variable < item->min)
                *(double *)item->variable = item->min;
            set_double_value(item->value_label, *(double *)item->variable, FLOAT_FORMAT);
            break;
        case TYPENAME_BOOL:
            *(bool *)item->variable = step ? !*(bool *)item->variable : *(bool *)item->variable;
            set_bool_value(item->value_label, *(bool *)item->variable);
            break;

        default:
            break;
        }
    }
}

void set_first_menu_object(lv_obj_t *obj)
{
    first_obj = obj;
}

// Show objects on display
void app_lvgl_display(void)
{
    bsp_display_lock(0);

    ui_init();

    bsp_display_unlock();
}

/*******************************************************************************
 * Public functions
 *******************************************************************************/

// Add a new item to list. In order to navigate properly in menu, each item
int add_menu_item(lv_obj_t *obj, lv_obj_t *screen, lv_obj_t *prev, lv_obj_t *next)
{
    items[item_num].obj = obj;
    items[item_num].prev = prev;
    items[item_num].next = next;
    items[item_num].screen = screen;
    items[item_num].cb_function = NULL;
    items[item_num].value_label = NULL;
    items[item_num].variable = NULL;
    items[item_num].var_type = TYPENAME_NONE;
    item_num++;
    return item_num;
}

// Bind a specific variable (pointer to) with a menu item
void bind_variable_to_object(lv_obj_t *obj, lv_obj_t *value_lbl, void *var, int v_type)
{
    menu_item *item = get_item_pt(obj);
    // printf("%d\n", item);
    if (item != NULL)
    {
        item->value_label = value_lbl;
        item->variable = var;
        item->var_type = v_type;
        item->min = DBL_MIN;
        item->max = DBL_MAX;
    }
    update_variable(item, 0);
}

void set_variable_range(lv_obj_t *obj, double min, double max)
{
    menu_item *item = get_item_pt(obj);
    if (item != NULL)
    {
        item->min = min;
        item->max = max;
    }
}

void bind_callback_to_object(lv_obj_t *obj, object_callback cb)
{
    menu_item *item = get_item_pt(obj);
    if (item != NULL)
    {
        item->cb_function = cb;
    }
}

// Init HMI (joypad + LCD)
void hmi_main()
{
    // Allow other core to finish initialization
    vTaskDelay(pdMS_TO_TICKS(100));

    /* Initialize display and LVGL */
    bsp_display_start();

    /* Set default display brightness */
    bsp_display_brightness_set(APP_DISP_DEFAULT_BRIGHTNESS);

    /* Add and show objects on display */
    app_lvgl_display();
    ESP_LOGI(TAG, "Example initialization done.");

    // Call this function to initialize gamepad buttons
    joypad_buttons_init();
}
