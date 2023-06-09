#pragma once

#define USB_POLLING_INTERVAL_MS 1
#define QMK_KEY_PERS_SCAN 12

#ifdef RGB_MATRIX_ENABLE
    #    define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
    #    define ENABLE_RGB_MATRIX_CYCLE_OUT_IN
    #    define ENABLE_RGB_MATRIX_PIXEL_RAIN
    #    define ENABLE_RGB_MATRIX_PIXEL_FLOW
    #    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
    #    define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
    #    define ENABLE_RGB_MATRIX_MULTISPLASH
    #    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
    #    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
    #    define ENABLE_RGB_MATRIX_TYPING_HEATMAP
    //#    define ENABLE_RGB_MATRIX_DIGITAL_RAIN

#endif