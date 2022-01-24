/* Copyright 2021 KiwiKey
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names { _BASE, _NAV, _SYM, _NUM, _FN };

#define T_NAV TT(_NAV)
#define S_NAV MO(_NAV)
#define NAVSPC LT(_NAV, KC_SPC)

#define T_SYM TT(_SYM)
#define S_SYM MO(_SYM)
#define SYMSPC LT(_SYM, KC_SPC)
#define ENTSYM LT(_SYM, KC_ENT)

#define ESC_NUM LT(_NUM, KC_ESC)
#define SPCNUM LT(_NUM, KC_SPC)
#define T_NUM TT(_NUM)

#define SFT_ESC LSFT_T(KC_ESC)
#define U_RDO SGUI(KC_Z)
#define U_PST LGUI(KC_V)
#define U_CPY LGUI(KC_C)
#define U_CUT LGUI(KC_X)
#define U_CMPST LSFT(LGUI(KC_V))  // ClipMenu
#define U_UND LGUI(KC_Z)

// Colemak Home-row mods
#define CM_A CTL_T(KC_A)
#define CM_R LALT_T(KC_R)
#define CM_S LGUI_T(KC_S)
#define CM_T LSFT_T(KC_T)
#define CM_N LSFT_T(KC_N)
#define CM_E LGUI_T(KC_E)
#define CM_I LALT_T(KC_I)
#define CM_O LCTL_T(KC_O)

#define CTL_Z LCTL_T(KC_Z)
// Global tab forward and backward
#define TAB_BCK LGUI(LSFT(KC_LBRACKET))
#define TAB_FWD LGUI(LSFT(KC_RBRACKET))
#define TAB_CLS LCTL(KC_W)
#define CMD_NAV LM(_NAV, MOD_LGUI)
#define PNE_BCK LGUI(LALT(KC_LEFT))
#define PNE_FWD LGUI(LALT(KC_RIGHT))
// clang-format off
// LAYOUT_alice_split_bs(
//      _______,   _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______,
//      _______,   _______, _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______, _______, _______, _______,
//      _______,   _______, _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______, _______, _______,
//      _______,   _______, _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______, _______, _______, _______,
//                 _______,          _______,      _______,     _______,                      _______,          _______,                   _______
//  ),
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_alice_split_bs(
        KC_MPLY,  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,       KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,
        KC_MUTE,   KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_LBRC, KC_RBRC, KC_BSLS,
        KC_VOLU,   SFT_ESC, CM_A,    CM_R,    CM_S,    CM_T,    KC_G,                KC_M,    CM_N,    CM_E,    CM_I,    CM_O,    KC_QUOT, KC_ENT,
        KC_VOLD,   KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                KC_BSPC, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_RGUI,
                   TT(_FN),          TT(_NUM),      NAVSPC,      S_SYM,                      ENTSYM,           NAVSPC,                   TT(_NAV)
    ),
    [_NAV] = LAYOUT_alice_split_bs(
       _______,   _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______,
       _______,   _______, _______, _______, _______, _______, _______,             _______, TAB_BCK, PNE_BCK, PNE_FWD, TAB_FWD, _______, _______, _______,
       _______,   _______, _______, _______, _______, _______, _______,             _______, KC_LEFT, KC_DOWN, KC_UP  , KC_RIGHT, _______, _______,
       _______,   _______, _______, _______, _______, _______, _______,             _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END , _______, _______, _______,
                  _______,          _______,      _______,     _______,                      _______,          _______,                   _______
    ),
    [_SYM] = LAYOUT_alice_split_bs(
       _______,   _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______,
       _______,   KC_TILD, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,             KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_EQL , _______, _______,
       _______,   KC_GRV , _______, KC_LPRN, KC_LCBR, KC_RCBR, KC_RPRN,             KC_PLUS, KC_MINUS, KC_EQL, KC_LCBR, KC_RCBR, KC_PIPE, _______,
       _______,   _______, _______, KC_LABK, KC_LBRC, KC_RBRC, KC_RABK,             _______, KC_ASTR, KC_UNDS, KC_BSLASH, KC_LBRC, KC_RBRC, _______, _______,
                  _______,          _______,      _______,     _______,                      _______,          _______,                   _______
    ),
    [_NUM] = LAYOUT_alice_split_bs(
       _______,   _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______,
       _______,   _______, _______, _______, _______, _______, _______,             _______, KC_7   , KC_8   , KC_9   , _______, _______, _______, _______,
       _______,   _______, _______, _______, _______, _______, _______,             _______, KC_4   , KC_5   , KC_6   , _______, _______, _______,
       _______,   _______, _______, _______, _______, _______, _______,             KC_0   , KC_1   , KC_2   , KC_3   , _______, _______, _______, _______,
                  _______,          _______,      _______,     _______,                      _______,          _______,                   _______
    ),
    [_FN] = LAYOUT_alice_split_bs(
        RESET  ,   _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,      KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_DEL,
        _______,   RGB_TOG, RGB_MOD, RGB_RMOD,_______, _______, _______,             BL_TOGG, BL_STEP, BL_BRTG, _______, _______, _______, _______, _______,
        _______,   _______, RGB_HUD, RGB_HUI, _______, _______, _______,             _______, _______, _______, _______, _______, _______, _______,
        _______,   _______, RGB_VAD, RGB_VAI, _______, _______, _______,             _______, _______, _______, _______, _______, _______, _______, _______,
                   _______,          _______,      _______,     _______,                      _______,          _______,                   _______
    )
};
// clang-format on
