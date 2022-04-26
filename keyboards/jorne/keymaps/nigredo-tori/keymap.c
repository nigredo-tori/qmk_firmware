// Copyright 2021 Joric (@joric)
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

enum layers {
    _QWERTY = 0,
    _GAME,
    _LOWER,
    _RAISE,
    _SYM,
    _ADJUST,
};


enum custom_keycodes {
    RGBRST = SAFE_RANGE,
    DF_CYCL
};

// Copied from the default keymap
#define RBR_RGU MT(MOD_RGUI, KC_RBRC)
#define F12_RGU MT(MOD_RGUI, KC_F12)
#define PLS_LCT MT(MOD_LCTL, KC_PPLS)
#define EQL_LCT MT(MOD_LCTL, KC_PEQL)
#define APP_LCT MT(MOD_LCTL, KC_APP)
#define EQL_RCT MT(MOD_RCTL, KC_PEQL)
#define QUO_RCT MT(MOD_RCTL, KC_QUOT)
#define APP_RCT MT(MOD_RCTL, KC_APP)
#define MIN_RCT MT(MOD_RCTL, KC_MINS)
#define EQL_LAL MT(MOD_LALT, KC_EQL)
#define BSL_RAL MT(MOD_RALT, KC_BSLS)
#define BSP_LSH MT(MOD_LSFT, KC_BSPC)
#define SPC_RSH MT(MOD_RSFT, KC_SPC)
#define DEL_RSE LT(_RAISE, KC_DEL)
#define TAB_RSE LT(_RAISE, KC_TAB)
#define ENT_LWR LT(_LOWER, KC_ENT)
#define ESC_LWR LT(_LOWER, KC_ESC)

// Custom bindings
#define BSP_SYM LT(_SYM, KC_BSPC)
#define SPC_SYM LT(_SYM, KC_SPC)

#define GUI_A MT(MOD_LGUI, KC_A)
#define ALT_S MT(MOD_LALT, KC_S)
#define CTL_D MT(MOD_LCTL, KC_D)
#define SFT_F MT(MOD_LSFT, KC_F)

#define SFT_J MT(MOD_LSFT, KC_J)
#define CTL_K MT(MOD_LCTL, KC_K)
#define ALT_L MT(MOD_LALT, KC_L)
#define GUI_CLN MT(MOD_LGUI, KC_SCLN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT(\
  _______, KC_GRV,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, \
           _______, GUI_A,   ALT_S,   CTL_D,   SFT_F,   KC_G,         KC_H,    SFT_J,   CTL_K,   ALT_L,   GUI_CLN, KC_QUOT, \
           _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS, \
                                      TAB_RSE, BSP_SYM, ESC_LWR,      ENT_LWR, SPC_SYM, DEL_RSE \
),

[_LOWER] = LAYOUT(\
  DF_CYCL, _______, KC_9,    KC_0,    KC_MINS, KC_PEQL, _______,      KC_PPLS, KC_7,    KC_8,    KC_9,    KC_PAST, _______, _______, \
  /*    */ _______, KC_5,    KC_6,    KC_7,    KC_8,    _______,      KC_PMNS, KC_4,    KC_5,    KC_6,    KC_PSLS, _______, \
  /*    */ _______, KC_1,    KC_2,    KC_3,    KC_4,    _______,      KC_EQL,  KC_1,    KC_2,    KC_3,    _______, _______, \
  /*                               */ _______, _______, _______,      _______, KC_0,    _______ \
),

[_RAISE] = LAYOUT(\
  DF_CYCL, KC_MNXT, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_VOLU,      KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______, KC_SYSTEM_POWER, \
           KC_MPLY, KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_MUTE,      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_INS,  _______, \
           KC_MPRV, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_VOLD,      KC_SLCK, KC_CAPS, KC_PSCR, KC_PAUS, _______, _______, \
                                      _______, _______, _______,      _______, _______, _______\
                  ),

[_ADJUST] = LAYOUT(\
  RESET,   RGBRST,  KC_ASUP, KC_ASTG, KC_ASDN, _______, _______,      _______, _______, KC_ASDN, KC_ASTG, KC_ASUP, RGBRST,  RESET,
           RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, _______, DF_CYCL,      DF_CYCL, _______, RGB_VAI, RGB_SAI, RGB_HUI, RGB_TOG,
           RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, _______, _______,      _______, _______, RGB_VAD, RGB_SAD, RGB_HUD, RGB_MOD,
                                      _______, SH_TG,   _______,      _______, SH_TG,   _______
                   ),

[_SYM] = LAYOUT(\
  _______, _______, _______, KC_RCBR, KC_RBRC, KC_RPRN, KC_CIRC,      KC_AMPR, KC_PAST, KC_PPLS, KC_QUOT, _______, _______, _______, \
           _______, KC_GRV,  KC_LCBR, KC_LBRC, KC_LPRN, KC_UNDS,      KC_DLR,  KC_EQL,  KC_PMNS, KC_DQUO, KC_EXLM, _______, \
           _______, KC_PERC, KC_BSLS, KC_PIPE, KC_SLSH, KC_TILD,      _______, KC_HASH, KC_LT,   KC_GT,   KC_AT,   _______, \
                                      _______, _______, _______,      _______, _______, _______ \
                ),

// Gaming layer - this is added as the default layer over _QWERTY, replacing
// left part's finnicky functionality (tap-hold and layers) with simpler stuff.
[_GAME] = LAYOUT(
  _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______,
  /*    */ KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    _______,      _______, _______, _______, _______, _______, _______,
  /*    */ KC_LCTL, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______,
  /*                               */ KC_TAB,  KC_BSPC, _______,      _______, _______, _______
                 ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case RGBRST:
#ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
            eeconfig_update_rgblight_default();
            rgblight_enable();
        }
#endif
        break;
    case DF_CYCL:
        if (record->event.pressed) {
            default_layer_xor((layer_state_t) 1 << _GAME);
        }
        break;
    }
    return true;
}

/* Local Variables: */
/* eval: (electric-indent-mode -1) */
/* eval: (clean-aindent-mode -1) */
/* End: */
