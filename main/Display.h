#ifndef DISPLAY_H
#define DISPLAY_H

#pragma once

#include "driver/i2c_master.h"

#include "esp_lcd_qemu_rgb.h"
#include "esp_lcd_panel_ops.h"
#include "esp_lcd_panel_st7789.h"
#include "esp_lcd_touch_ft5x06.h"

#include <Arduino.h>
#include "lvgl.h"

// Using SPI2 in the example
#define LCD_HOST  SPI2_HOST
#define I2C_BUS_PORT  0

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////// Please update the following configuration according to your LCD spec //////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define EXAMPLE_LCD_PIXEL_CLOCK_HZ     (80 * 1000 * 1000)
#define EXAMPLE_LCD_BK_LIGHT_ON_LEVEL  1
#define EXAMPLE_LCD_BK_LIGHT_OFF_LEVEL !EXAMPLE_LCD_BK_LIGHT_ON_LEVEL
#define EXAMPLE_PIN_NUM_SCLK           14
#define EXAMPLE_PIN_NUM_MOSI           13
#define EXAMPLE_PIN_NUM_MISO           -1
#define EXAMPLE_PIN_NUM_LCD_DC         21
#define EXAMPLE_PIN_NUM_LCD_RST        22
#define EXAMPLE_PIN_NUM_LCD_CS         15
#define EXAMPLE_PIN_NUM_BK_LIGHT       23

#define EXAMPLE_PIN_NUM_SDA            18
#define EXAMPLE_PIN_NUM_SCL            19
#define EXAMPLE_PIN_NUM_RST            -1
#define EXAMPLE_PIN_NUM_INT            36


#define EXAMPLE_LCD_H_RES              320
#define EXAMPLE_LCD_V_RES              480

// Bit number used to represent command and parameter
#define EXAMPLE_LCD_CMD_BITS           8
#define EXAMPLE_LCD_PARAM_BITS         8

#define EXAMPLE_LVGL_DRAW_BUF_LINES    20 // number of display lines in each draw buffer
#define EXAMPLE_LVGL_TICK_PERIOD_MS    2
#define EXAMPLE_LVGL_TASK_MAX_DELAY_MS 500
#define EXAMPLE_LVGL_TASK_MIN_DELAY_MS 1
#define EXAMPLE_LVGL_TASK_STACK_SIZE   (64 * 1024)
#define EXAMPLE_LVGL_TASK_PRIORITY     2

class Display
{
public:
    Display();
    ~Display();

    void init();

    

private:
    void initDisplay();
    void initTouch();

    lv_display_t *display;
};

extern Display display;
#endif
