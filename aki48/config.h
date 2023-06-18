// Copyright 2023 Hoan (@hvuitsme)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/* key matrix size */
#define MATRIX_COLS 6  // 6 columns on each side
#define MATRIX_ROWS 10   // 4 rows, and 1 extra row for the rotary encoder

/* VIA */
#define DYNAMIC_KEYMAP_LAYER_COUNT 4

// wiring of each half
#define MATRIX_ROW_PINS { D7, E6, B4, B5, C6 }
#define MATRIX_COL_PINS { F6, F7, B1, B3, B2, B6 }

/* encoder pin definitions */
#define ENCODERS_PAD_A { F5 }
#define ENCODERS_PAD_B { F4 }
#define ENCODER_RESOLUTION 5

#define WS2812_DI_PIN D3
#ifdef RGB_MATRIX_ENABLE
    #define RGBLED_NUM       56 // Number of LEDs
    #define RGB_MATRIX_LED_COUNT RGBLED_NUM
    #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 170 // limits maximum brightness of LEDs to 150 out of 255. Higher may cause the controller to crash.
    #    define RGB_MATRIX_KEYPRESSES
    #    define RGB_DISABLE_WHEN_USB_SUSPENDED // turn off effects when suspended
    #    define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#endif
