#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ergodox(
        // ....,|.......,|.......,|.......,|.......,|.......,|.......,|.......,|.......
        // Left hand
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    TG(1),
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_NO,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
        KC_LGUI, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_NO,
        OSL(2),  KC_MINS, KC_PSCR, KC_LALT, OSL(2),
                                                                       KC_MUTE, KC_VOLU,
                                                                                KC_VOLD,
                                                              KC_LSFT, KC_SPC,  KC_LALT,

        // Right hand
                          RESET,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
                          KC_NO,   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
                                   KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_RCTL,
                          KC_NO,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RGUI,
                                            OSL(2),  KC_RALT, KC_MENU, KC_EQL,  OSL(2),
        KC_MRWD, KC_MFFD,
        KC_MPLY,
        KC_RALT, KC_ENT,  KC_RSFT
    ),
};
