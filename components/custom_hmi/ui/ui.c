// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.2.3
// LVGL version: 8.3.4
// Project name: SquareLine_SimpleMenu

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////
lv_obj_t * ui_ScreenMain;
lv_obj_t * ui_Counter;
lv_obj_t * ui_ScreenSetup;
lv_obj_t * ui_itemLbl1;
lv_obj_t * ui_itemLbl2;
lv_obj_t * ui_itemLblRGB;
lv_obj_t * ui_CheckboxHID;
lv_obj_t * ui_ScreenEdit1;
lv_obj_t * ui_Panel1;
lv_obj_t * ui_valueLbl1;
lv_obj_t * ui_value1;
lv_obj_t * ui_Panel2;
lv_obj_t * ui_valueLbl2;
lv_obj_t * ui_value2;
lv_obj_t * ui_ScreenEdit2;
lv_obj_t * ui_Panel3;
lv_obj_t * ui_valueLbl3;
lv_obj_t * ui_value3;
lv_obj_t * ui_Panel4;
lv_obj_t * ui_valueLbl4;
lv_obj_t * ui_value4;
lv_obj_t * ui_Panel5;
lv_obj_t * ui_valueLbl5;
lv_obj_t * ui_value5;
lv_obj_t * ui_ScreenEditRGB;
lv_obj_t * ui_PanelRed;
lv_obj_t * ui_valueLblRed;
lv_obj_t * ui_valueRed;
lv_obj_t * ui_PanelGreen;
lv_obj_t * ui_valueLblGreen;
lv_obj_t * ui_valueGreen;
lv_obj_t * ui_PanelBlue;
lv_obj_t * ui_valueLblBlue;
lv_obj_t * ui_valueBlue;
lv_obj_t * ui_PanelButtons;
lv_obj_t * ui_ButtonOK;
lv_obj_t * ui_valueLblOK;
lv_obj_t * ui_ButtonWHITE;
lv_obj_t * ui_valueLblWHITE;
lv_obj_t * ui____initial_actions0;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=1
    #error "LV_COLOR_16_SWAP should be 1 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////

///////////////////// SCREENS ////////////////////
void ui_ScreenMain_screen_init(void)
{
    ui_ScreenMain = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_ScreenMain, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Counter = lv_label_create(ui_ScreenMain);
    lv_obj_set_width(ui_Counter, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Counter, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Counter, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Counter, "0");
    lv_obj_set_style_text_font(ui_Counter, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);

}
void ui_ScreenSetup_screen_init(void)
{
    ui_ScreenSetup = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_ScreenSetup, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_flex_flow(ui_ScreenSetup, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_ScreenSetup, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_set_style_pad_left(ui_ScreenSetup, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_ScreenSetup, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_ScreenSetup, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_ScreenSetup, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_ScreenSetup, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_ScreenSetup, 10, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_itemLbl1 = lv_label_create(ui_ScreenSetup);
    lv_obj_set_width(ui_itemLbl1, lv_pct(60));
    lv_obj_set_height(ui_itemLbl1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_itemLbl1, LV_ALIGN_CENTER);
    lv_label_set_long_mode(ui_itemLbl1, LV_LABEL_LONG_SCROLL);
    lv_label_set_text(ui_itemLbl1, "Menu Item 1");
    lv_obj_set_style_border_color(ui_itemLbl1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_border_opa(ui_itemLbl1, 255, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui_itemLbl1, 1, LV_PART_MAIN | LV_STATE_FOCUSED);

    ui_itemLbl2 = lv_label_create(ui_ScreenSetup);
    lv_obj_set_width(ui_itemLbl2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_itemLbl2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_itemLbl2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_itemLbl2, "Menu Item 2");
    lv_obj_set_style_border_color(ui_itemLbl2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_border_opa(ui_itemLbl2, 255, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui_itemLbl2, 1, LV_PART_MAIN | LV_STATE_FOCUSED);

    ui_itemLblRGB = lv_label_create(ui_ScreenSetup);
    lv_obj_set_width(ui_itemLblRGB, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_itemLblRGB, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_itemLblRGB, LV_ALIGN_CENTER);
    lv_label_set_text(ui_itemLblRGB, "RGB led");
    lv_obj_set_style_border_color(ui_itemLblRGB, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_border_opa(ui_itemLblRGB, 255, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui_itemLblRGB, 1, LV_PART_MAIN | LV_STATE_FOCUSED);

    ui_CheckboxHID = lv_checkbox_create(ui_ScreenSetup);
    lv_checkbox_set_text(ui_CheckboxHID, "USB KEYPAD");
    lv_obj_set_width(ui_CheckboxHID, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_CheckboxHID, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_CheckboxHID, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_CheckboxHID, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags

    lv_obj_set_style_border_color(ui_CheckboxHID, lv_color_hex(0x000000), LV_PART_INDICATOR | LV_STATE_FOCUSED);
    lv_obj_set_style_border_opa(ui_CheckboxHID, 255, LV_PART_INDICATOR | LV_STATE_FOCUSED);

}
void ui_ScreenEdit1_screen_init(void)
{
    ui_ScreenEdit1 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_ScreenEdit1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_flex_flow(ui_ScreenEdit1, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_ScreenEdit1, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_set_style_pad_left(ui_ScreenEdit1, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_ScreenEdit1, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_ScreenEdit1, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_ScreenEdit1, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_ScreenEdit1, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_ScreenEdit1, 10, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Panel1 = lv_obj_create(ui_ScreenEdit1);
    lv_obj_set_width(ui_Panel1, lv_pct(100));
    lv_obj_set_height(ui_Panel1, lv_pct(25));
    lv_obj_set_align(ui_Panel1, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Panel1, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Panel1, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_clear_flag(ui_Panel1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_width(ui_Panel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_Panel1, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Panel1, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Panel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Panel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Panel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_Panel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_Panel1, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Panel1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_border_opa(ui_Panel1, 255, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui_Panel1, 1, LV_PART_MAIN | LV_STATE_FOCUSED);

    ui_valueLbl1 = lv_label_create(ui_Panel1);
    lv_obj_set_width(ui_valueLbl1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_valueLbl1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_valueLbl1, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_valueLbl1, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_valueLbl1, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_label_set_text(ui_valueLbl1, "Value 1: ");

    ui_value1 = lv_label_create(ui_Panel1);
    lv_obj_set_width(ui_value1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_value1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_value1, 117);
    lv_obj_set_y(ui_value1, -33);
    lv_obj_set_align(ui_value1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_value1, "150");
    lv_label_set_recolor(ui_value1, "true");

    ui_Panel2 = lv_obj_create(ui_ScreenEdit1);
    lv_obj_set_width(ui_Panel2, lv_pct(100));
    lv_obj_set_height(ui_Panel2, lv_pct(25));
    lv_obj_set_align(ui_Panel2, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Panel2, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Panel2, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_clear_flag(ui_Panel2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_width(ui_Panel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_Panel2, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Panel2, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Panel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Panel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Panel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_Panel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_Panel2, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Panel2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_border_opa(ui_Panel2, 255, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui_Panel2, 1, LV_PART_MAIN | LV_STATE_FOCUSED);

    ui_valueLbl2 = lv_label_create(ui_Panel2);
    lv_obj_set_width(ui_valueLbl2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_valueLbl2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_valueLbl2, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_valueLbl2, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_valueLbl2, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_label_set_text(ui_valueLbl2, "Value 2: ");

    ui_value2 = lv_label_create(ui_Panel2);
    lv_obj_set_width(ui_value2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_value2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_value2, 117);
    lv_obj_set_y(ui_value2, -33);
    lv_obj_set_align(ui_value2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_value2, "1500");
    lv_label_set_recolor(ui_value2, "true");

}
void ui_ScreenEdit2_screen_init(void)
{
    ui_ScreenEdit2 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_ScreenEdit2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_flex_flow(ui_ScreenEdit2, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_ScreenEdit2, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_set_style_pad_left(ui_ScreenEdit2, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_ScreenEdit2, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_ScreenEdit2, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_ScreenEdit2, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_ScreenEdit2, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_ScreenEdit2, 10, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Panel3 = lv_obj_create(ui_ScreenEdit2);
    lv_obj_set_width(ui_Panel3, lv_pct(100));
    lv_obj_set_height(ui_Panel3, lv_pct(25));
    lv_obj_set_x(ui_Panel3, 5);
    lv_obj_set_y(ui_Panel3, 0);
    lv_obj_set_align(ui_Panel3, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Panel3, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Panel3, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_clear_flag(ui_Panel3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_width(ui_Panel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_Panel3, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Panel3, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Panel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Panel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Panel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_Panel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_Panel3, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Panel3, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_border_opa(ui_Panel3, 255, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui_Panel3, 1, LV_PART_MAIN | LV_STATE_FOCUSED);

    ui_valueLbl3 = lv_label_create(ui_Panel3);
    lv_obj_set_width(ui_valueLbl3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_valueLbl3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_valueLbl3, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_valueLbl3, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_valueLbl3, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_label_set_text(ui_valueLbl3, "Value 3: ");

    ui_value3 = lv_label_create(ui_Panel3);
    lv_obj_set_width(ui_value3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_value3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_value3, 117);
    lv_obj_set_y(ui_value3, -33);
    lv_obj_set_align(ui_value3, LV_ALIGN_CENTER);
    lv_label_set_text(ui_value3, "36.5");
    lv_label_set_recolor(ui_value3, "true");

    ui_Panel4 = lv_obj_create(ui_ScreenEdit2);
    lv_obj_set_width(ui_Panel4, lv_pct(100));
    lv_obj_set_height(ui_Panel4, lv_pct(25));
    lv_obj_set_align(ui_Panel4, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Panel4, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Panel4, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_clear_flag(ui_Panel4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_width(ui_Panel4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_Panel4, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Panel4, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Panel4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Panel4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Panel4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_Panel4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_Panel4, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Panel4, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_border_opa(ui_Panel4, 255, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui_Panel4, 1, LV_PART_MAIN | LV_STATE_FOCUSED);

    ui_valueLbl4 = lv_label_create(ui_Panel4);
    lv_obj_set_width(ui_valueLbl4, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_valueLbl4, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_valueLbl4, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_valueLbl4, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_valueLbl4, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_label_set_text(ui_valueLbl4, "Value 4: ");

    ui_value4 = lv_label_create(ui_Panel4);
    lv_obj_set_width(ui_value4, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_value4, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_value4, 117);
    lv_obj_set_y(ui_value4, -33);
    lv_obj_set_align(ui_value4, LV_ALIGN_CENTER);
    lv_label_set_text(ui_value4, "25.63");
    lv_label_set_recolor(ui_value4, "true");

    ui_Panel5 = lv_obj_create(ui_ScreenEdit2);
    lv_obj_set_width(ui_Panel5, lv_pct(100));
    lv_obj_set_height(ui_Panel5, lv_pct(25));
    lv_obj_set_align(ui_Panel5, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Panel5, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Panel5, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_clear_flag(ui_Panel5, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_width(ui_Panel5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_Panel5, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Panel5, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Panel5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Panel5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Panel5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_Panel5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_Panel5, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Panel5, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_border_opa(ui_Panel5, 255, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui_Panel5, 1, LV_PART_MAIN | LV_STATE_FOCUSED);

    ui_valueLbl5 = lv_label_create(ui_Panel5);
    lv_obj_set_width(ui_valueLbl5, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_valueLbl5, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_valueLbl5, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_valueLbl5, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_valueLbl5, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_label_set_text(ui_valueLbl5, "Value 5: ");

    ui_value5 = lv_label_create(ui_Panel5);
    lv_obj_set_width(ui_value5, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_value5, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_value5, 117);
    lv_obj_set_y(ui_value5, -33);
    lv_obj_set_align(ui_value5, LV_ALIGN_CENTER);
    lv_label_set_text(ui_value5, "true");
    lv_label_set_recolor(ui_value5, "true");

}
void ui_ScreenEditRGB_screen_init(void)
{
    ui_ScreenEditRGB = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_ScreenEditRGB, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_flex_flow(ui_ScreenEditRGB, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_ScreenEditRGB, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_set_style_pad_left(ui_ScreenEditRGB, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_ScreenEditRGB, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_ScreenEditRGB, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_ScreenEditRGB, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_ScreenEditRGB, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_ScreenEditRGB, 10, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelRed = lv_obj_create(ui_ScreenEditRGB);
    lv_obj_set_width(ui_PanelRed, lv_pct(100));
    lv_obj_set_height(ui_PanelRed, lv_pct(25));
    lv_obj_set_x(ui_PanelRed, 5);
    lv_obj_set_y(ui_PanelRed, 0);
    lv_obj_set_align(ui_PanelRed, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_PanelRed, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_PanelRed, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_clear_flag(ui_PanelRed, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_width(ui_PanelRed, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelRed, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_PanelRed, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_PanelRed, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_PanelRed, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_PanelRed, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_PanelRed, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_PanelRed, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_PanelRed, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_border_opa(ui_PanelRed, 255, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui_PanelRed, 1, LV_PART_MAIN | LV_STATE_FOCUSED);

    ui_valueLblRed = lv_label_create(ui_PanelRed);
    lv_obj_set_width(ui_valueLblRed, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_valueLblRed, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_valueLblRed, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_valueLblRed, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_valueLblRed, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_label_set_text(ui_valueLblRed, "Red: ");

    ui_valueRed = lv_label_create(ui_PanelRed);
    lv_obj_set_width(ui_valueRed, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_valueRed, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_valueRed, 117);
    lv_obj_set_y(ui_valueRed, -33);
    lv_obj_set_align(ui_valueRed, LV_ALIGN_CENTER);
    lv_label_set_text(ui_valueRed, "60");
    lv_label_set_recolor(ui_valueRed, "true");

    ui_PanelGreen = lv_obj_create(ui_ScreenEditRGB);
    lv_obj_set_width(ui_PanelGreen, lv_pct(100));
    lv_obj_set_height(ui_PanelGreen, lv_pct(25));
    lv_obj_set_align(ui_PanelGreen, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_PanelGreen, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_PanelGreen, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_clear_flag(ui_PanelGreen, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_width(ui_PanelGreen, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelGreen, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_PanelGreen, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_PanelGreen, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_PanelGreen, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_PanelGreen, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_PanelGreen, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_PanelGreen, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_PanelGreen, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_border_opa(ui_PanelGreen, 255, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui_PanelGreen, 1, LV_PART_MAIN | LV_STATE_FOCUSED);

    ui_valueLblGreen = lv_label_create(ui_PanelGreen);
    lv_obj_set_width(ui_valueLblGreen, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_valueLblGreen, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_valueLblGreen, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_valueLblGreen, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_valueLblGreen, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_label_set_text(ui_valueLblGreen, "Green: ");

    ui_valueGreen = lv_label_create(ui_PanelGreen);
    lv_obj_set_width(ui_valueGreen, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_valueGreen, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_valueGreen, 117);
    lv_obj_set_y(ui_valueGreen, -33);
    lv_obj_set_align(ui_valueGreen, LV_ALIGN_CENTER);
    lv_label_set_text(ui_valueGreen, "10");
    lv_label_set_recolor(ui_valueGreen, "true");

    ui_PanelBlue = lv_obj_create(ui_ScreenEditRGB);
    lv_obj_set_width(ui_PanelBlue, lv_pct(100));
    lv_obj_set_height(ui_PanelBlue, lv_pct(25));
    lv_obj_set_align(ui_PanelBlue, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_PanelBlue, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_PanelBlue, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_clear_flag(ui_PanelBlue, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_width(ui_PanelBlue, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelBlue, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_PanelBlue, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_PanelBlue, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_PanelBlue, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_PanelBlue, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_PanelBlue, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_PanelBlue, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_PanelBlue, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_border_opa(ui_PanelBlue, 255, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui_PanelBlue, 1, LV_PART_MAIN | LV_STATE_FOCUSED);

    ui_valueLblBlue = lv_label_create(ui_PanelBlue);
    lv_obj_set_width(ui_valueLblBlue, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_valueLblBlue, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_valueLblBlue, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_valueLblBlue, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_valueLblBlue, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_label_set_text(ui_valueLblBlue, "Blue: ");

    ui_valueBlue = lv_label_create(ui_PanelBlue);
    lv_obj_set_width(ui_valueBlue, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_valueBlue, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_valueBlue, 117);
    lv_obj_set_y(ui_valueBlue, -33);
    lv_obj_set_align(ui_valueBlue, LV_ALIGN_CENTER);
    lv_label_set_text(ui_valueBlue, "true");
    lv_label_set_recolor(ui_valueBlue, "true");

    ui_PanelButtons = lv_obj_create(ui_ScreenEditRGB);
    lv_obj_set_width(ui_PanelButtons, lv_pct(100));
    lv_obj_set_height(ui_PanelButtons, lv_pct(25));
    lv_obj_set_align(ui_PanelButtons, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_PanelButtons, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_PanelButtons, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_clear_flag(ui_PanelButtons, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_width(ui_PanelButtons, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelButtons, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_PanelButtons, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_PanelButtons, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_PanelButtons, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_PanelButtons, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_PanelButtons, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_PanelButtons, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_PanelButtons, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_border_opa(ui_PanelButtons, 255, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui_PanelButtons, 1, LV_PART_MAIN | LV_STATE_FOCUSED);

    ui_ButtonOK = lv_btn_create(ui_PanelButtons);
    lv_obj_set_width(ui_ButtonOK, 40);
    lv_obj_set_height(ui_ButtonOK, 16);
    lv_obj_set_align(ui_ButtonOK, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ButtonOK, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonOK, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ButtonOK, lv_color_hex(0xE9A047), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_bg_opa(ui_ButtonOK, 255, LV_PART_MAIN | LV_STATE_FOCUSED);

    ui_valueLblOK = lv_label_create(ui_ButtonOK);
    lv_obj_set_width(ui_valueLblOK, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_valueLblOK, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_valueLblOK, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_valueLblOK, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_valueLblOK, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_label_set_text(ui_valueLblOK, "OK");

    ui_ButtonWHITE = lv_btn_create(ui_PanelButtons);
    lv_obj_set_width(ui_ButtonWHITE, 80);
    lv_obj_set_height(ui_ButtonWHITE, 16);
    lv_obj_set_align(ui_ButtonWHITE, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ButtonWHITE, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonWHITE, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ButtonWHITE, lv_color_hex(0xE9A047), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_bg_opa(ui_ButtonWHITE, 255, LV_PART_MAIN | LV_STATE_FOCUSED);

    ui_valueLblWHITE = lv_label_create(ui_ButtonWHITE);
    lv_obj_set_width(ui_valueLblWHITE, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_valueLblWHITE, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_valueLblWHITE, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_valueLblWHITE, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_valueLblWHITE, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_label_set_text(ui_valueLblWHITE, "WHITE");

}

void ui_init(void)
{
    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_ScreenMain_screen_init();
    ui_ScreenSetup_screen_init();
    ui_ScreenEdit1_screen_init();
    ui_ScreenEdit2_screen_init();
    ui_ScreenEditRGB_screen_init();
    ui____initial_actions0 = lv_obj_create(NULL);
    lv_disp_load_scr(ui_ScreenMain);
}
