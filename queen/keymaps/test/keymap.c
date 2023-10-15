// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include <action_layer.h>

#define MY_WEB_FUNCTION LT(1, KC_P)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┬───┐
     * │Tab│web│ 2 │ 3 │ 4 │ 5 │
     * ├───┼───┼───┼───┼───┼───┤
     * │Tab│ Q │ W │ E │ R │ T │
     * ├───┼───┼───┼───┼───┼───┤
     * │Sft│ A │ S │ D │ F │ G │
     * ├───┼───┼───┴───┴───┴───┤
     * │Ctl│Alt│      Spc      │
     * └───┴───┴───────────────┘
     */
    [0] = LAYOUT(
        KC_ESC,  MY_WEB_FUNCTION,    KC_2,    KC_3,    KC_4,    KC_5,
        KC_TAB,  KC_Q,               KC_W,    KC_E,    KC_R,    KC_T,
        KC_LSFT, KC_A,               KC_S,    KC_D,    KC_F,    KC_G,
        KC_LCTL, KC_LALT,                         KC_SPC
    ),
    [1] = LAYOUT(
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______,          _______
    )

};

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MY_WEB_FUNCTION:
            if (record->event.pressed) {
                //Open browser (Edge on Windows)
                SEND_STRING(SS_LGUI("r") SS_DELAY(100) "msedge.exxe" SS_TAP(X_ENTER)); //If this is for typing unicode, add 1 'x' so that when typing in the same way, it will easily become an exe.
                                                                                       //Can replace apps like: msedge.exe, firefox.exe, operagx.exe, opera.exe
                wait_ms(2000); // Wait 500ms (0.5 secs)
                //Open an incognito window (Ctrl+Shift+N)
                //Hold Ctrl and Shift
                register_code(KC_LCTL);
                register_code(KC_LSFT);
                //Press N
                tap_code(KC_N);
                //cancel Ctrl and Shift
                unregister_code(KC_LSFT);
                unregister_code(KC_LCTL);
                //Wait a moment before entering the URL
                wait_ms(500); //Wait another 500ms (0.5 secs)
                //Enter the path in the search bar (replace "https://github.com/hvuitsme" with the actual URL)
                SEND_STRING("https://github.com/hvuitsme");
                //Press Enter
                tap_code(KC_ENT);
            }
            break;
    }
    return true;
}
