/*
 * SPDX-FileCopyrightText: 2021-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

/**
 * @file
 * @brief ESP BSP: Wrover-kit
 */

#pragma once

#include "driver/gpio.h"
#include "driver/sdmmc_host.h"
#include "sdkconfig.h"
#include "lvgl.h"

#define BSP_LEDSTRIP_IO      (GPIO_NUM_48)

/* Display */
#define BSP_LCD_SPI_MISO      (GPIO_NUM_34)
#define BSP_LCD_SPI_MOSI      (GPIO_NUM_35)
#define BSP_LCD_SPI_CLK       (GPIO_NUM_36)
#define BSP_LCD_SPI_CS        (GPIO_NUM_37)
#define BSP_LCD_BACKLIGHT     (GPIO_NUM_38)

#define BSP_LCD_DC            (GPIO_NUM_40)
#define BSP_LCD_RST           (GPIO_NUM_41)


/* Joyoad */
#define BTN_UP    (GPIO_NUM_4)
#define BTN_DOWN  (GPIO_NUM_5)
#define BTN_LEFT  (GPIO_NUM_6)
#define BTN_RIGHT (GPIO_NUM_7)
#define BTN_MID   (GPIO_NUM_15)
#define BTN_SET   (GPIO_NUM_16)
#define BTN_RES   (GPIO_NUM_17)

/* Button */
typedef enum {
    BSP_BUTTON_BOOT = GPIO_NUM_0
} bsp_button_t;


/* Digital Outputs */
typedef enum {
    BSP_OUT0 = GPIO_NUM_20,
    BSP_OUT1 = GPIO_NUM_21
} bsp_out_t;


/* uSD card */
#define BSP_SD_D0             (GPIO_NUM_9)
#define BSP_SD_D1             (GPIO_NUM_10)
#define BSP_SD_D2             (GPIO_NUM_11)
#define BSP_SD_D3             (GPIO_NUM_12)

#define BSP_SD_CS             (BSP_SD_D3)
#define BSP_SD_CLK            (BSP_LCD_SPI_CLK)
#define BSP_SD_CMD            (BSP_LCD_SPI_MOSI)
#define BSP_SD_DET            (BSP_LCD_SPI_MISO)
#define BSP_SD_DO             (BSP_LCD_SPI_MISO)

#ifdef __cplusplus
extern "C" {
#endif


/**************************************************************************************************
 *
 * OUTs
 *
 **************************************************************************************************/

/**
 * @brief Set GPIOs as output push-pull
 *
 * @return
 *     - ESP_OK Success
 *     - ESP_ERR_INVALID_ARG Parameter error
 */
esp_err_t bsp_outs_init(void);

/**
 * @brief Turn OUT on/off
 *
 * @param out_io OUT io
 * @param on Switch OUT on/off
 * @return
 *     - ESP_OK Success
 *     - ESP_ERR_INVALID_ARG Parameter error
 */
esp_err_t bsp_out_set(const bsp_out_t out_io, const bool on);

/**************************************************************************************************
 *
 * Button
 *
 **************************************************************************************************/

/**
 * @brief Set button's GPIO as input
 *
 * @param[in] btn Button to be initialized
 * @return
 *     - ESP_OK Success
 *     - ESP_ERR_INVALID_ARG Parameter error
 */
esp_err_t bsp_button_init(const bsp_button_t btn);

/**
 * @brief Get button's state
 *
 * @param[in] btn Button to read
 * @return true  Button pressed
 * @return false Button released
 */
bool bsp_button_get(const bsp_button_t btn);


/**************************************************************************************************
 *
 * uSD card
 *
 * After mounting the uSD card, it can be accessed with stdio functions ie.:
 * \code{.c}
 * FILE* f = fopen(BSP_MOUNT_POINT"/hello.txt", "w");
 * fprintf(f, "Hello %s!\n", bsp_sdcard->cid.name);
 * fclose(f);
 * \endcode
 *
 * @attention IO2 is also routed to RGB LED and push button
 **************************************************************************************************/
#define BSP_MOUNT_POINT      CONFIG_BSP_uSD_MOUNT_POINT
extern sdmmc_card_t *bsp_sdcard;

/**
 * @brief Mount microSD card to virtual file system
 *
 * @return
 *      - ESP_OK on success
 *      - ESP_ERR_INVALID_STATE if esp_vfs_fat_sdmmc_mount was already called
 *      - ESP_ERR_NO_MEM if memory can not be allocated
 *      - ESP_FAIL if partition can not be mounted
 *      - other error codes from SDMMC or SPI drivers, SDMMC protocol, or FATFS drivers
 */
esp_err_t bsp_sdcard_mount(void);

/**
 * @brief Unmount micorSD card from virtual file system
 *
 * @return
 *      - ESP_OK on success
 *      - ESP_ERR_NOT_FOUND if the partition table does not contain FATFS partition with given label
 *      - ESP_ERR_INVALID_STATE if esp_vfs_fat_spiflash_mount was already called
 *      - ESP_ERR_NO_MEM if memory can not be allocated
 *      - ESP_FAIL if partition can not be mounted
 *      - other error codes from wear levelling library, SPI flash driver, or FATFS drivers
 */
esp_err_t bsp_sdcard_unmount(void);

/**************************************************************************************************
 *
 * LCD interface
 *
 * ESP32-WROVER-KIT is shipped with 3.2inch ST7789 or ILI9341 display controller. It features 16-bit colors and 320x240 resolution.
 * If your colours on the display are distorted, try changing the display type in menuconfig.
 *
 * LVGL is used as graphics library. LVGL is NOT thread safe, therefore the user must take LVGL mutex
 * by calling bsp_display_lock() before calling any LVGL API (lv_...) and then give the mutex with
 * bsp_display_unlock().
 *
 * Display's backlight must be enabled explicitly by calling bsp_display_backlight_on()
 **************************************************************************************************/
#define BSP_LCD_H_RES               (80)
#define BSP_LCD_V_RES               (160)
#define BSP_LCD_PIXEL_CLOCK_HZ      (40 * 1000 * 1000)
#define BSP_LCD_SPI_NUM             (SPI2_HOST)

#define BSP_LCD_DRAW_BUFF_SIZE      (BSP_LCD_H_RES * 30)
#define BSP_LCD_DRAW_BUFF_DOUBLE    (1)

/**
 * @brief Initialize display
 *
 * This function initializes SPI, display controller and starts LVGL handling task.
 *
 * @return Pointer to LVGL display or NULL when error occured
 */
lv_disp_t *bsp_display_start(void);

/**
 * @brief Get pointer to input device (touch, buttons, ...)
 *
 * @note The LVGL input device is initialized in bsp_display_start() function.
 *
 * @return Pointer to LVGL input device or NULL when not initialized
 */
lv_indev_t *bsp_display_get_input_dev(void);

/**
 * @brief Take LVGL mutex
 *
 * @param timeout_ms Timeout in [ms]. 0 will block indefinitely.
 * @return true  Mutex was taken
 * @return false Mutex was NOT taken
 */
bool bsp_display_lock(uint32_t timeout_ms);

/**
 * @brief Give LVGL mutex
 *
 */
void bsp_display_unlock(void);

/**
 * @brief Set display's brightness
 *
 * Brightness is controlled with PWM signal to a pin controling backlight.
 *
 * @param[in] brightness_percent Brightness in [%]
 * @return
 *      - ESP_OK                On success
 *      - ESP_ERR_INVALID_ARG   Parameter error
 */
esp_err_t bsp_display_brightness_set(int brightness_percent);

/**
 * @brief Turn on display backlight
 *
 * Display must be already initialized by calling bsp_display_start()
 *
 * @return
 *      - ESP_OK                On success
 *      - ESP_ERR_INVALID_ARG   Parameter error
 */
esp_err_t bsp_display_backlight_on(void);

/**
 * @brief Turn off display backlight
 *
 * Display must be already initialized by calling bsp_display_start()
 *
 * @return
 *      - ESP_OK                On success
 *      - ESP_ERR_INVALID_ARG   Parameter error
 */
esp_err_t bsp_display_backlight_off(void);

/**
 * @brief Rotate screen
 *
 * Display must be already initialized by calling bsp_display_start()
 *
 * @param[in] disp Pointer to LVGL display
 * @param[in] rotation Angle of the display rotation
 */
void bsp_display_rotate(lv_disp_t *disp, lv_disp_rot_t rotation);


#ifdef __cplusplus
}
#endif
