#pragma once

// clang-format off
enum layer_names {
    _QWERTY = 0,
    _COLEMAKDHM,
    _NAV,
    _SYM,
    _NUM,
    _ADJUST
};

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    COLEMAK,
};

// Layer toggle and switch
#define T_NAV TT(_NAV)
#define T_SYM TT(_SYM)


// Layer keys with functionality on tap
#define T_ESC_N LT(_NUM, KC_ESC)

#define U_RDO SGUI(KC_Z)
#define U_PST LGUI(KC_V)
#define U_CPY LGUI(KC_C)
#define U_CUT LGUI(KC_X)
#define U_CMPST LSFT(LGUI(KC_X)) // ClipMenu
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

// Qwerty Home-row mods
#define QM_A LCTL_T(KC_A)
#define QM_S LALT_T(KC_S)
#define QM_D LGUI_T(KC_D)
#define QM_F LSFT_T(KC_F)
#define QM_J LSFT_T(KC_J)
#define QM_K LGUI_T(KC_K)
#define QM_L LALT_T(KC_L)
#define QM_SCLN LCTL_T(KC_SCLN)

#if (!defined(LAYOUT) && defined(KEYMAP))
#   define LAYOUT KEYMAP
#endif

#define KEYMAP_wrapper(...)                  LAYOUT(__VA_ARGS__)
#define LAYOUT_wrapper(...)                  LAYOUT(__VA_ARGS__)

#define _________________QWERTY_L1_________________ KC_Q    , KC_W    , KC_E    , KC_R    , KC_T
#define _________________QWERTY_L2_________________ QM_A    , QM_S    , QM_D    , QM_F    , KC_G
#define _________________QWERTY_L3_________________ KC_Z    , KC_X    , KC_C    , KC_V    , KC_B

#define _________________QWERTY_R1_________________ KC_Y    , KC_U    , KC_I    , KC_O    , KC_P
#define _________________QWERTY_R2_________________ KC_H    , QM_J    , QM_K    , QM_L    , QM_SCLN
#define _________________QWERTY_R3_________________ KC_N    , KC_M    , KC_COMM , KC_DOT  , KC_SLASH

#define ______________COLEMAK_MOD_DH_L1____________ KC_Q    , KC_W    , KC_F    , KC_P    , KC_B
#define ______________COLEMAK_MOD_DH_L2____________ CM_A    , CM_R    , CM_S    , CM_T    , KC_G
#define ______________COLEMAK_MOD_DH_L3____________ KC_Z    , KC_X    , KC_C    , KC_D    , KC_V

#define ______________COLEMAK_MOD_DH_R1____________ KC_J    , KC_L    , KC_U    , KC_Y    , KC_SCLN
#define ______________COLEMAK_MOD_DH_R2____________ CM_A    , CM_N    , CM_E    , CM_I    , CM_O
#define ______________COLEMAK_MOD_DH_R3____________ KC_K    , KC_H    , KC_COMM , KC_DOT  , KC_SLASH

#define __________________SYM_L1___________________ KC_EXLM , KC_AT   , KC_LBRC , KC_RBRC , KC_BSLS
#define __________________SYM_L2___________________ KC_HASH , KC_DLR  , KC_LPRN , KC_RPRN , KC_PIPE
#define __________________SYM_L3___________________ KC_PERC , KC_CIRC , KC_LCBR , KC_RCBR , KC_AMPR

#define __________________SYM_R1___________________ _______ , _______ , _______ , _______ , _______
#define __________________SYM_R2___________________ _______ , _______ , _______ , _______ , _______
#define __________________SYM_R3___________________ KC_ASTR , _______ , _______ , _______ , _______

#define ________________NUMBER_L1__________________ KC_F1   , KC_F2   , KC_F3   , KC_F4  , KC_F5
#define ________________NUMBER_L2__________________ KC_F6   , KC_F7   , KC_F8   , KC_F9  , KC_F10
#define ________________NUMBER_L3__________________ _______ , _______ , _______ , KC_F11 , KC_F12

#define ________________NUMBER_R1__________________ KC_PAUS , KC_7    , KC_8    , KC_9    , KC_MINS
#define ________________NUMBER_R2__________________ KC_ASTR , KC_4    , KC_5    , KC_6    , KC_PLUS
#define ________________NUMBER_R3__________________ KC_0    , KC_1    , KC_2    , KC_3    , KC_EQL

#define ________________NAV_L1_____________________ _______ , _______ , _______ , _______ , U_UND
#define ________________NAV_L2_____________________ _______ , _______ , _______ , _______ , _______
#define ________________NAV_L3_____________________ _______ , _______ , _______ , _______ , _______

#define ________________NAV_R1_____________________ _______ , U_CPY   , U_PST   , U_CMPST , _______
#define ________________NAV_R2_____________________ _______ , KC_LEFT , KC_DOWN , KC_UP   , KC_RIGHT
#define ________________NAV_R3_____________________ _______ , KC_HOME , KC_PGDN , KC_PGUP , KC_END


#define ________________ADJUST_L1__________________ QWERTY  , _______ , _______ , _______ , KC_NLCK
#define ________________ADJUST_L2__________________ _______ , _______ , COLEMAK , _______ , KC_CAPS
#define ________________ADJUST_L3__________________ _______ , _______ , _______ , _______ , _______

#define ________________ADJUST_R1__________________ RGB_TOG , RGB_M_P , RGB_M_K , _______ , RESET
#define ________________ADJUST_R2__________________ RGB_MOD , RGB_M_B , _______ , _______ , _______
#define ________________ADJUST_R3__________________ RGB_M_T , RGB_M_R , _______ , _______ , _______
// clang-format on
