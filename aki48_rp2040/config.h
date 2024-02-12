// Copyright 2024 hvuitsme (@hvuitsme)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/* key matrix size */
#define MATRIX_COLS 6  // 6 columns on each side
#define MATRIX_ROWS 10   // 4 rows, and 1 extra row for the rotary encoder

/* VIA */
#define DYNAMIC_KEYMAP_LAYER_COUNT 4

// wiring of each half
#define MATRIX_ROW_PINS { GP6, GP7, GP8, GP9, GP5 }
#define MATRIX_COL_PINS { GP27, GP26, GP22, GP20, GP23, GP21 }

/* encoder pin definitions */
#define ENCODERS_PAD_A { GP28 }
#define ENCODERS_PAD_B { GP29 }
#define ENCODER_RESOLUTION 5

#define WS2812_DI_PIN GP0
#ifdef RGB_MATRIX_ENABLE
    #define RGBLED_NUM       57 // Number of LEDs
    #define RGB_MATRIX_LED_COUNT RGBLED_NUM
    #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 170 // limits maximum brightness of LEDs to 150 out of 255. Higher may cause the controller to crash.
    #    define RGB_MATRIX_KEYPRESSES
    #    define RGB_DISABLE_WHEN_USB_SUSPENDED // turn off effects when suspended
    #    define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#endif

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
