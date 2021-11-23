#include QMK_KEYBOARD_H
#include <stdio.h>

#define _COLEMAKDHM  0
#define _QWERTY  1
#define _NAV 2
#define _SYMBOLS 3
#define _NUMBERS 4
#define _MISC  5


// Base layers
#define QWERTY  DF(_QWERTY)
#define COLEMAK DF(_COLEMAKDHM)

// Layer toggle and switch
#define T_NAV TT(_NAV)
#define S_NAV MO(_NAV)

#define T_SYM TT(_SYMBOLS)
#define S_SYM MO(_SYMBOLS)

#define ESC_NUM LT(_NUMBERS, KC_ESC)

#define U_RDO SGUI(KC_Z)
#define U_PST LGUI(KC_V)
#define U_CPY LGUI(KC_C)
#define U_CUT LGUI(KC_X)
#define U_CMPST LSFT(LGUI(KC_V)) // ClipMenu
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

// Global tab forward and backward
#define TAB_FWD LCTL(KC_TAB)
#define TAB_BCK LCTL(LSFT(KC_TAB))
#define TAB_CLS LCTL(KC_W)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAKDHM] = LAYOUT_split_3x6_3(
        KC_TAB    , KC_Q    , KC_W    , KC_F    , KC_P    , KC_B       , KC_J    , KC_L    , KC_U    , KC_Y    , KC_SCLN , KC_BSPC,
        ESC_NUM   , CM_A    , CM_R    , CM_S    , CM_T    , KC_G       , KC_M    , CM_N    , CM_E    , CM_I    , CM_O    , KC_QUOT ,
        KC_LSHIFT , KC_Z    , KC_X    , KC_C    , KC_D    , KC_V       , KC_K    , KC_H    , KC_COMM , KC_DOT  , KC_SLASH, KC_SFTENT,
                                        KC_LGUI , T_NAV   , KC_SPC     , KC_SPC , T_SYM,   KC_RGUI
    ),
    [_QWERTY] = LAYOUT_split_3x6_3( \
        KC_TAB    , KC_Q    , KC_W    , KC_E    , KC_R    , KC_T       , KC_Y    , KC_U    , KC_I    , KC_O    , KC_P    , KC_BSPC,
        ESC_NUM   , QM_A    , QM_S    , QM_D    , QM_F    , KC_G       , KC_H    , QM_J    , QM_K    , QM_L    , QM_SCLN , KC_QUOT,
        KC_LSHIFT , KC_Z    , KC_X    , KC_C    , KC_V    , KC_B       , KC_N    , KC_M    , KC_COMM , KC_DOT  , KC_SLASH, KC_SFTENT,
                                        KC_LGUI , T_NAV   , KC_SPC     , KC_SPC , T_SYM,   KC_RGUI
    ),
    [_NAV] = LAYOUT_split_3x6_3(
        KC_TILD , KC_GRV , _______ , _______ , _______ , _______       , _______ , TAB_BCK , _______ , _______ , TAB_FWD  , _______,
        _______ , _______ , _______ , _______ , _______ , _______      , _______ , KC_LEFT , KC_DOWN , KC_UP   , KC_RIGHT , _______,
        U_RDO   , U_UND   , U_CUT   , U_CPY   , U_PST , U_CMPST        , _______ , KC_HOME , KC_PGDN , KC_PGUP , KC_END   , _______,
                                        _______ , _______   , _______      , _______ , MO(_MISC) , _______
    ),
    [_SYMBOLS] = LAYOUT_split_3x6_3(
        KC_TILD , KC_EXLM , KC_AT   , KC_LPRN , KC_RPRN , KC_BSLS,                 _______ , _______  , _______  , _______ , _______ , _______,
        KC_GRV  , KC_HASH , KC_DLR  , KC_LCBR , KC_RCBR , KC_PIPE,                 KC_PLUS , KC_MINUS , KC_EQUAL , _______ , _______ , _______,
        _______ , KC_PERC , KC_CIRC , KC_LBRC , KC_RBRC , KC_AMPR,                 KC_ASTR , KC_UNDS  , _______  , _______ , _______ , _______,
                                _______ , MO(_MISC) , _______ ,             _______ , _______ , _______
    ),
    [_NUMBERS] = LAYOUT_split_3x6_3(
        _______ , KC_F1   , KC_F2   , KC_F3   , KC_F4  , KC_F5         , KC_PLUS , KC_7    , KC_8    , KC_9    , KC_MINS , _______,
        _______ , KC_F6   , KC_F7   , KC_F8   , KC_F9  , KC_F10        , KC_ASTR , KC_4    , KC_5    , KC_6    , KC_PLUS , _______,
        _______ , _______ , _______ , _______ , KC_F11 , KC_F12        , KC_0    , KC_1    , KC_2    , KC_3    , KC_EQL  , _______,
                                _______ , _______ , _______      , _______ , _______  , _______
    ),
    [_MISC] = LAYOUT_split_3x6_3(
        RESET  , XXXXXXX, _______, KC_NLCK, _______, COLEMAK,                      RGB_M_T, KC_MPRV, KC_VOLU, KC_MNXT, _______, _______,
        _______, XXXXXXX, _______, KC_CAPS, _______,  QWERTY,                      RGB_M_B, KC_MSTP, KC_VOLD, KC_MPLY, _______, _______,
        _______, KC_SLEP, XXXXXXX, _______, XXXXXXX, XXXXXXX,                      RGB_TOG, XXXXXXX, KC_MUTE, XXXXXXX, XXXXXXX, _______,
                                            _______, _______, _______,    _______, _______, _______
    )
};

// layer_state_t layer_state_set_user(layer_state_t state) {
//     state = update_tri_layer_state(state, _NAV, _SYMBOLS, _MISC);
//     return state;
// }

// clang-format on
#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
      if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    } else {
        return OLED_ROTATION_180;
    }
}
void render_status(void) {
     switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("QWRTY"), false);
            break;
        case _COLEMAKDHM:
            oled_write_P(PSTR("CLMK"), false);
            break;
    }
    oled_write_P(PSTR("\n"), false);

    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_ln_P(PSTR("     "), false);
            break;
        case _NUMBERS:
            oled_write_ln_P(PSTR("NUM  "), false);
            break;
        case _NAV:
            oled_write_ln_P(PSTR("NAV  "), false);
            break;
        case _SYMBOLS:
            oled_write_ln_P(PSTR("SYM  "), false);
            break;
        case _MISC:
            oled_write_ln_P(PSTR("MISC"), false);
            break;
        default:
            oled_write_P(PSTR("?????"), false);
            break;
    }
    oled_write_P(PSTR("\n"), false);

    uint8_t modifiers = get_mods();

    oled_write_P((modifiers & MOD_MASK_SHIFT) ? PSTR("SHIFT") : PSTR("\n"), false);
    oled_write_P((modifiers & MOD_MASK_CTRL) ? PSTR("CTRL ") : PSTR("\n"), false);
    oled_write_P((modifiers & MOD_MASK_ALT) ? PSTR("ALT  ") : PSTR("\n"), false);
    oled_write_P((modifiers & MOD_MASK_GUI) ? PSTR("SUPER") : PSTR("\n"), false);

    oled_write_P(PSTR("\n"), false);

    uint8_t led_usb_state = host_keyboard_leds();
    oled_write_P(PSTR("Mode:"), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK) ? PSTR(" NUM ") : PSTR("\n"), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK) ? PSTR(" CAPS") : PSTR("\n"), false);
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
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status();
        // oled_render_keylog();
    } else {
        oled_render_logo();
    }
}
#endif  // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef OLED_ENABLE
    if (record->event.pressed) {
        set_keylog(keycode, record);
    }
#endif
    return true;
}

void keyboard_post_init_user(void) {
    // Customise these values to desired behaviour
    debug_enable = true;
    //   debug_matrix=true;
    debug_keyboard = true;
    // debug_mouse=true;
}
