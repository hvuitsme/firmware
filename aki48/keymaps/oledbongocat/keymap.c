// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include <stdio.h>
#include "quantum.h"
#include "animation_frames.h"

enum layer_number{
    _BASE = 0,
    _FN1 = 1,
    _FN2 = 2,
    _FN3 = 3
};

enum custom_keycodes {
  PROG = QK_KB_0,
};

#define _______ KC_TRANSPARENT

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* BASE
     * ┌───┬───┬───┬───┬───┬───┐      ┌───┬───┬───┬───┬───┬───┐
     * │ESC│ Q │ W │ E │ R │ T │      │ Y │ U │ I │ O │ P │BSC│
     * ├───┼───┼───┼───┼───┼───┤      ├───┼───┼───┼───┼───┼───┤
     * │TAB│ A │ S │ D │ F │ G │      │ H │ J │ K │ L │ ; │ ' │
     * ├───┼───┼───┼───┼───┼───┤      ├───┼───┼───┼───┼───┼───┤
     * │LSF│ Z │ X │ C │ V │ B │      │ N │ M │ , │ . │ / │RSF│
     * ├───┼───┼───┼───┼───┼───┼──────┼───┼───┼───┼───┼───┼───┤
     * │LCT│LWN│ALT│FN1│FN2│SPC│ MUTE │SPC│ENT│ ← │ ↑ │ ↓ │ → │
     * └───┴───┴───┴───┴───┼───┴──────┴───┼───┴───┴───┴───┴───┘
     *                     │     space    │
     *                     └──────────────┘
     */ 
    [_BASE] = LAYOUT(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,              KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,              KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MUTE,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        KC_LCTL, KC_LGUI, KC_LALT, MO(_FN2),MO(_FN1),KC_SPC,  KC_SPC,   KC_SPC,  KC_ENT,  KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT
    ),
    /* FN1
     * ┌───┬───┬───┬───┬───┬───┐      ┌───┬───┬───┬───┬───┬───┐
     * │ESC│ 1 │ 2 │ 3 │ 4 │ 5 │      │ 6 │ 7 │ 8 │ 9 │ 0 │BSC│
     * ├───┼───┼───┼───┼───┼───┤      ├───┼───┼───┼───┼───┼───┤
     * │TAB│XXX│XXX│XXX│XXX│XXX│      │XXX│XXX│XXX│XXX│XXX│DEL│
     * ├───┼───┼───┼───┼───┼───┤      ├───┼───┼───┼───┼───┼───┤
     * │LSF│XXX│XXX│XXX│XXX│XXX│      │XXX│XXX│XXX│XXX│XXX│RSF│
     * ├───┼───┼───┼───┼───┼───┼──────┼───┼───┼───┼───┼───┼───┤
     * │LCT│XXX│ALT│ ↓ │FN2│SPC│      │SPC│ENT│XXX│XXX│XXX│XXX│
     * └───┴───┴───┴───┴───┼───┴──────┴───┼───┴───┴───┴───┴───┘
     *                     │     space    │
     *                     └──────────────┘
     */
    [_FN1] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_TAB,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL,
        KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RSFT,
        KC_LCTL, XXXXXXX, XXXXXXX, _______, _______, KC_SPC,  KC_SPC,  KC_SPC,  KC_ENT,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),
    /* FN2
     * ┌───┬───┬───┬───┬───┬───┐      ┌───┬───┬───┬───┬───┬───┐
     * │ESC│ ! │ @ │ # │ $ │ % │      │ ^ │ & │ * │ ( │ ) │BSC│
     * ├───┼───┼───┼───┼───┼───┤      ├───┼───┼───┼───┼───┼───┤
     * │TAB│ `~│XXX│XXX│XXX│XXX│      │-_ │=+ │[{ │]} │\| │DEL│
     * ├───┼───┼───┼───┼───┼───┤      ├───┼───┼───┼───┼───┼───┤
     * │LSF│ ~ │XXX│XXX│XXX│XXX│      │XXX│XXX│XXX│XXX│XXX│RSF│
     * ├───┼───┼───┼───┼───┼───┼──────┼───┼───┼───┼───┼───┼───┤
     * │LCT│XXX│ALT│FN1│ ↓ │SPC│      │SPC│ENT│XXX│XXX│XXX│XXX│
     * └───┴───┴───┴───┴───┼───┴──────┴───┼───┴───┴───┴───┴───┘
     *                     │     space    │
     *                     └──────────────┘
     */
    [_FN2] = LAYOUT(
        KC_ESC,  KC_EXLM, KC_AT,   KC_HASH,  KC_DLR, KC_PERC,          KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
        KC_TAB,  KC_GRV,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,
        KC_LSFT, KC_TILD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RSFT,
        KC_LCTL, XXXXXXX, XXXXXXX, _______, _______, KC_SPC,  KC_SPC,  KC_SPC,  KC_ENT,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),
    /* FN3 (FN1+FN2)
     * ┌───┬───┬───┬───┬───┬───┐      ┌───┬───┬───┬───┬───┬───┐
     * │ESC│XXX│XXX│SA+│HUI│SP+│      │XXX│XXX│XXX│XXX│XXX│XXX│
     * ├───┼───┼───┼───┼───┼───┤      ├───┼───┼───┼───┼───┼───┤
     * │XXX│XXX│XXX│SA-│HUD│SP-│      │XXX│XXX│XXX│XXX│XXX│XXX│
     * ├───┼───┼───┼───┼───┼───┤      ├───┼───┼───┼───┼───┼───┤
     * │XXX│XXX│XXX│XXX│VAD│VAI│      │XXX│XXX│XXX│XXX│XXX│XXX│
     * ├───┼───┼───┼───┼───┼───┼──────┼───┼───┼───┼───┼───┼───┤
     * │XXX│XXX│XXX│ ↓ │ ↓ │XXX│      │XXX│XXX│XXX│XXX│XXX│XXX│
     * └───┴───┴───┴───┴───┼───┴──────┴───┼───┴───┴───┴───┴───┘
     *                     │      XXX     │
     *                     └──────────────┘
     */
    [_FN3] = LAYOUT(
        QK_BOOT, XXXXXXX, XXXXXXX, RGB_SAI, RGB_HUI, RGB_SPI,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, RGB_SAD, RGB_HUD, RGB_SPD,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_VAD, RGB_VAI, RGB_TOG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, KC_SPC,  _______, KC_SPC,  KC_ENT,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    )
};


layer_state_t layer_state_set_user(layer_state_t state) {
   return update_tri_layer_state(state, _FN1, _FN2, _FN3);
}

#ifdef OLED_ENABLE
#define IDLE_FRAME_DURATION 200 // Idle animation iteration rate in ms

oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_270; }

uint32_t anim_timer         = 0;
uint32_t anim_sleep         = 0;
uint8_t  current_idle_frame = 0;

bool tap_anim        = false;
bool tap_anim_toggle = false;


// Decompress and write a precompressed bitmap frame to the OLED.
// Documentation and python compression script available at:
// https://github.com/nullbitsco/squeez-o
#ifdef USE_OLED_BITMAP_COMPRESSION
static void oled_write_compressed_P(const char* input_block_map, const char* input_block_list) {
    uint16_t block_index = 0;
    for (uint16_t i=0; i<NUM_OLED_BYTES; i++) {
        uint8_t bit = i%8;
        uint8_t map_index = i/8;
        uint8_t _block_map = (uint8_t)pgm_read_byte_near(input_block_map + map_index);
        uint8_t nonzero_byte = (_block_map & (1 << bit));
        if (nonzero_byte) {
            const char data = (const char)pgm_read_byte_near(input_block_list + block_index++);
            oled_write_raw_byte(data, i);
        } else {
            const char data = (const char)0x00;
            oled_write_raw_byte(data, i);
        }
    }
}
#endif

static void render_anim(void) {
    // Idle animation
    void animation_phase(void) {
        if (!tap_anim) {
            current_idle_frame = (current_idle_frame + 1) % NUM_IDLE_FRAMES;
            uint8_t idx = abs((NUM_IDLE_FRAMES - 1) - current_idle_frame);
            #ifdef USE_OLED_BITMAP_COMPRESSION
            oled_write_compressed_P(idle_block_map[idx], idle_frames[idx]);
            #else
            oled_write_raw_P(idle_frames[idx], NUM_OLED_BYTES);
            #endif
        }
    }

    // Idle behaviour
    if (get_current_wpm() != 000) {  // prevent sleep
        oled_on();
        if (timer_elapsed32(anim_timer) > IDLE_FRAME_DURATION) {
            anim_timer = timer_read32();
            animation_phase();
        }
        anim_sleep = timer_read32();
    } else {  // Turn off screen when timer threshold elapsed or reset time since last input
        if (timer_elapsed32(anim_sleep) > OLED_TIMEOUT) {
            oled_off();
        } else {
            if (timer_elapsed32(anim_timer) > IDLE_FRAME_DURATION) {
                anim_timer = timer_read32();
                animation_phase();
            }
        }
    }
}

bool oled_task_user(void) {
    render_anim();
    oled_set_cursor(0, 14);

    uint8_t n = get_current_wpm();
    char wpm_counter[6];
    wpm_counter[5] = '\0';
    wpm_counter[4] = '0' + n % 10;
    wpm_counter[3] = '0' + (n /= 10) % 10;
    wpm_counter[2] = '0' + n / 10 ;
    wpm_counter[1] = '0';
    wpm_counter[0] = '>';
    oled_write_ln(wpm_counter, false);

    return false;
}
#endif

// Animate tap
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    #ifdef OLED_ENABLE
    // Check if non-mod
    if ((keycode >= KC_A && keycode <= KC_0) || (keycode >= KC_TAB && keycode <= KC_SLASH)) {
        if (record->event.pressed) {
            // Display tap frames
            tap_anim_toggle = !tap_anim_toggle;
            #ifdef USE_OLED_BITMAP_COMPRESSION
            oled_write_compressed_P(tap_block_map[tap_anim_toggle], tap_frames[tap_anim_toggle]);
            #else
            oled_write_raw_P(tap_frames[tap_anim_toggle], NUM_OLED_BYTES);
            #endif
        }
    }
    #endif

    switch(keycode) {
        case PROG:
          if (record->event.pressed) {
            rgblight_disable_noeeprom();
            #ifdef OLED_ENABLE
            oled_off();
            #endif
            bootloader_jump();
          }
        break;

        default:
        break;
    }

    return true;
}

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [_FN1] =  { ENCODER_CCW_CW(KC_TRNS, KC_TRNS)  },
    [_FN2] =  { ENCODER_CCW_CW(KC_TRNS, KC_TRNS)  },
    [_FN3] =  { ENCODER_CCW_CW(RGB_MOD, RGB_RMOD) },
};
#endif

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise){
    if (IS_LAYER_ON(_BASE)) {
        if (clockwise){
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (IS_LAYER_ON(_FN3)) {
        if (clockwise){
            rgblight_step();
        } else {
            rgblight_step_reverse();
        }
    }
    return true;
}
#endif

