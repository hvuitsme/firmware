// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include <action_layer.h>

#define MY_WEB_FUNCTION LT(1, KC_P)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┬───┐
     * │Tab│ Q │ W │ E │ R │ T │
     * ├───┼───┼───┼───┼───┼───┤
     * │Tab│ A │ S │ D │ F │ G │
     * ├───┼───┼───┼───┼───┼───┤
     * │Sft│ Z │ X │ C │ V │ B │
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
                // Mở trình duyệt (Chrome trên Windows)
                SEND_STRING(SS_LGUI("r") SS_DELAY(100) "msedge.exxe" SS_TAP(X_ENTER)); //cái này nếu dành cho gõ unicode thì thêm 1 'x' vào để khi lúc nhập tương tự cách gõ thì ễ thành exe
                                                                                      //có thể thay thế mấy app như : msedge.exe, firefox.exe, operagx.exe, opera.exe
                wait_ms(2000); // Đợi 500ms (0.5 giây)
                // Mở cửa sổ ẩn danh (Ctrl+Shift+N)
                // Giữ Ctrl và Shift
                register_code(KC_LCTL);
                register_code(KC_LSFT);
                // Nhấn N
                tap_code(KC_N);
                // Bỏ Ctrl và Shift
                unregister_code(KC_LSFT);
                unregister_code(KC_LCTL);
                // Đợi một chút trước khi nhập URL
                wait_ms(500); // Đợi thêm 500ms (0.5 giây)
                // Nhập đường dẫn vào thanh tìm kiếm (thay thế "https://ihentai.de/" bằng URL thực tế)
                SEND_STRING("https://ihentai.de/");
                // Nhấn Enter
                tap_code(KC_ENT);
            }
            break;
    }
    return true;
}
