/*
 * usb_descriptor.h
 *
 *  Created on: 12 apr 2023
 *      Author: cotes
 */

#include "driver/gpio.h"
#include "tinyusb.h"
#include "class/hid/hid_device.h"
#include "tusb_msc_storage.h"

#ifdef CONFIG_EXAMPLE_STORAGE_MEDIA_SDMMCCARD
#include "diskio_impl.h"
#include "diskio_sdmmc.h"
#endif

#ifndef MAIN_USB_DESCRIPTOR_H_
#define MAIN_USB_DESCRIPTOR_H_

#define CDC 0
#define MSC 1
#define HID 0

#define _PID_MAP(itf, n) ((CFG_TUD_##itf) << (n))
#define USB_PID (0x4000 | _PID_MAP(CDC, 0) | _PID_MAP(MSC, 1) | _PID_MAP(HID, 2) | _PID_MAP(MIDI, 3) | _PID_MAP(VENDOR, 4))
#define USB_VID 0x303A
#define USB_BCD 0x0200

/* TinyUSB descriptors
 ********************************************************************* */

enum
{
    REPORT_ID_KEYBOARD = 1,
    REPORT_ID_MOUSE,
    REPORT_ID_GAMEPAD,
    REPORT_ID_COUNT
};

/**
 * @brief HID report descriptor
 *
 * In this example we implement Keyboard + Mouse HID device,
 * so we must define both report descriptors
 */
const uint8_t hid_report_descriptor[] = {
    TUD_HID_REPORT_DESC_KEYBOARD(HID_REPORT_ID(REPORT_ID_KEYBOARD)),
    TUD_HID_REPORT_DESC_MOUSE(HID_REPORT_ID(REPORT_ID_MOUSE)),
    TUD_HID_REPORT_DESC_GAMEPAD(HID_REPORT_ID(REPORT_ID_GAMEPAD))};

enum
{
    ITF_NUM_HID = 0,
    ITF_NUM_MSC,
    ITF_NUM_TOTAL
};

enum
{
    EDPT_CTRL_OUT = 0x00,
    EDPT_CTRL_IN = 0x80,
    EDPT_MSC_OUT = 0x01,
    EDPT_MSC_IN = 0x81,
};

#define CONFIG_TOTAL_LEN (TUD_CONFIG_DESC_LEN + TUD_MSC_DESC_LEN + CFG_TUD_HID * TUD_HID_DESC_LEN)

// full speed configuration
uint8_t const desc_configuration[] =
    {
        // Config number, interface count, string index, total length, attribute, power in mA
        TUD_CONFIG_DESCRIPTOR(1, ITF_NUM_TOTAL, 0, CONFIG_TOTAL_LEN, TUSB_DESC_CONFIG_ATT_REMOTE_WAKEUP, 100),

        // Interface number, string index, boot protocol, report descriptor len, EP In address, size & polling interval
        TUD_HID_DESCRIPTOR(ITF_NUM_HID, 3, false, sizeof(hid_report_descriptor), 0x82, 16, 10),

        // Interface number, string index, EP Out & EP In address, EP size
        TUD_MSC_DESCRIPTOR(ITF_NUM_MSC, 4, EDPT_MSC_OUT, EDPT_MSC_IN, TUD_OPT_HIGH_SPEED ? 512 : 64)};

static tusb_desc_device_t descriptor_config = {
    .bLength = sizeof(descriptor_config),
    .bDescriptorType = TUSB_DESC_DEVICE,
    .bcdUSB = USB_BCD,
    .bDeviceClass = TUSB_CLASS_MISC,
    .bDeviceSubClass = MISC_SUBCLASS_COMMON,
    .bDeviceProtocol = MISC_PROTOCOL_IAD,
    .bMaxPacketSize0 = CFG_TUD_ENDPOINT0_SIZE,
    .idVendor = USB_VID,
    .idProduct = USB_PID,
    .bcdDevice = 0x100,
    .iManufacturer = 0x01,
    .iProduct = 0x02,
    .iSerialNumber = 0x03,
    .bNumConfigurations = 0x01};

static char const *string_desc_arr[] = {
    (const char[]){0x09, 0x04}, // 0: is supported language is English (0x0409)
    "TinyUSB",                  // 1: Manufacturer
    "TinyUSB Device",           // 2: Product
    "123456",                   // 3: Serials
    "Example MSC",              // 4. MSC
};
/*********************************************************************** TinyUSB descriptors*/

#endif /* MAIN_USB_DESCRIPTOR_H_ */
