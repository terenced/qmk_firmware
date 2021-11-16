/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include QMK_KEYBOARD_H
#include <stdio.h>

#include "wrappers.h"

// clang-format off

#define LAYOUT_crkbd_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A  \
  ) \
  LAYOUT_wrapper( \
    KC_TAB    , K01   , K02    , K03    , K04   , K05       , K06 , K07 , K08 , K09 , K0A , KC_BSPC   , \
    ESC_NUM   , K11   , K12    , K13    , K14   , K15       , K16 , K17 , K18 , K19 , K1A , KC_QUOT   , \
    KC_LSHIFT , K21   , K22    , K23    , K24   , K25       , K26 , K27 , K28 , K29 , K2A , KC_SFTENT , \
    KC_LGUI   , TT(_NAV) , KC_SPC , KC_ENT , TT(_SYM) , KC_RGUI \
  )
#define LAYOUT_crkbd_base_wrapper(...) LAYOUT_crkbd_base(__VA_ARGS__)
// clan-format on


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_crkbd_base_wrapper(
        _________________QWERTY_L1_________________, _________________QWERTY_R1_________________, 
        _________________QWERTY_L2_________________, _________________QWERTY_R2_________________, 
        _________________QWERTY_L3_________________, _________________QWERTY_R3_________________
    ),
    [_COLEMAKDHM] = LAYOUT_crkbd_base_wrapper(
        ______________COLEMAK_MOD_DH_L1____________ , ______________COLEMAK_MOD_DH_R1____________ ,
        ______________COLEMAK_MOD_DH_L2____________ , ______________COLEMAK_MOD_DH_R2____________ ,
        ______________COLEMAK_MOD_DH_L3____________ , ______________COLEMAK_MOD_DH_R3____________
    ),
    [_NAV] = LAYOUT_wrapper(
      _______ , ________________NAV_L1_____________________ , ________________NAV_R1_____________________ , _______ ,
      _______ , ________________NAV_L2_____________________ , ________________NAV_R2_____________________ , _______ ,
      _______ , ________________NAV_L3_____________________ , ________________NAV_R3_____________________ , _______ ,
                                  _______ , _______, _______, _______ , _______, _______
    ),
    [_NUM] = LAYOUT_wrapper(
      _______ , ________________NUMBER_L1__________________ , ________________NUMBER_R1__________________ , _______ ,
      _______ , ________________NUMBER_L2__________________ , ________________NUMBER_R2__________________ , _______ ,
      _______ , ________________NUMBER_L3__________________ , ________________NUMBER_R3__________________ , _______ ,
                                  _______ , _______, _______, _______ , _______, _______
    ),
    [_SYM] = LAYOUT_wrapper(
       KC_TILD , __________________SYM_L1___________________ , __________________SYM_R1___________________ , _______ ,
       KC_GRV  , __________________SYM_L2___________________ , __________________SYM_R2___________________ , _______ ,
       _______ , __________________SYM_L3___________________ , __________________SYM_R3___________________ , _______ ,
                                  _______ , _______, _______, _______ , _______, _______
    ),
    // [_ADJUST] = LAYOUT_wrapper(
    //   _______ , ________________ADJUST_L1__________________ , ________________ADJUST_R1__________________ , _______ ,
    //   _______ , ________________ADJUST_L2__________________ , ________________ADJUST_R2__________________ , _______ ,
    //   _______ , ________________ADJUST_L3__________________ , ________________ADJUST_R3__________________ , _______ ,
    //                               _______ , _______, _______, _______ , _______, _______
    // )
};
// clang-format on
#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
    }
    return rotation;
}

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case _COLEMAKDHM:
            oled_write_ln_P(PSTR("COLEMAK"), false);
            break;
        case _QWERTY:
            oled_write_ln_P(PSTR("QWERTY"), false);
            break;
        case _NAV:
            oled_write_ln_P(PSTR("NAV"), false);
            break;
        case _SYM:
            oled_write_ln_P(PSTR("SYN"), false);
            break;
        case _NUM:
            oled_write_ln_P(PSTR("NUM"), false);
            break;
        case _ADJUST:
            /* case _ADJUST | _SYM: */
            /* case _ADJUST | _NAV: */
            /* case _ADJUST | _SYM | _NAV: */
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
        default:
            oled_write_ln_P(PSTR("WHAT!!!!"), false);
            break;
    }
}

char keylog_str[24] = {};

const char code_to_name[60] = {' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\', '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
    char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) {
        keycode = keycode & 0xFF;
    }
    if (keycode < 60) {
        name = code_to_name[keycode];
    }

    // update keylog
    snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c", record->event.key.row, record->event.key.col, keycode, name);
}

void oled_render_keylog(void) { oled_write(keylog_str, false); }

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94, 0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0};
    oled_write_P(crkbd_logo, false);
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        set_keylog(keycode, record);
    }
    return true;
}
#endif  // OLED_ENABLE
