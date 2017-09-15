#include QMK_KEYBOARD_H

#define LB 0 // base layer
#define LG 1 // gaming layer
#define LF 2 // function layer

#define MLA MOD_LALT
#define MLC MOD_LCTL
#define MLG MOD_LGUI
#define MLS MOD_LSFT
#define MRA MOD_RALT
#define MRC MOD_RCTL
#define MRG MOD_RGUI
#define MRS MOD_RSFT

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LB] = LAYOUT_ergodox( // base layer
        // .....|........|........|........|........|........|........|........|.......
        // Left hand
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    TG(LG),
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_NO,
        OSM(MLC),KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
        OSM(MLG),KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_NO,
        OSL(LF), KC_MINS, KC_PSCR, KC_LALT, OSL(LF),
                                                                       KC_MUTE, KC_VOLU,
                                                                                KC_VOLD,
                                                              OSM(MLS),KC_SPC,  OSM(MLA),

        // Right hand
                          RESET,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
                          KC_NO,   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
                                   KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, OSM(MRC),
                          KC_NO,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, OSM(MRG),
                                            OSL(LF), KC_RALT, KC_MENU, KC_EQL,  OSL(LF),
        KC_MRWD, KC_MFFD,
        KC_MPLY,
        OSM(MRA),KC_ENT,  OSM(MRS)
    ),
    [LG] = LAYOUT_ergodox( // game layer
        // .....|........|........|........|........|........|........|........|.......
        // Left hand
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                                       KC_TRNS, KC_TRNS,
                                                                                KC_TRNS,
                                                              KC_LSFT, KC_TRNS, KC_LALT,

        // Right hand
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,
        KC_TRNS,
        KC_RALT, KC_TRNS, KC_RSFT
    ),
    [LF] = LAYOUT_ergodox( // func layer
        // .....|........|........|........|........|........|........|........|.......
        // Left hand
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,
        KC_TRNS, KC_PGUP, KC_BTN1, KC_UP,   KC_BTN2, KC_LPRN, KC_TRNS,
        KC_TRNS, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_LBRC,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LCBR, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                                       KC_TRNS, KC_TRNS,
                                                                                KC_TRNS,
                                                              KC_TRNS, KC_TRNS, KC_TRNS,

        // Right hand
                          KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL,
                          KC_TRNS, KC_RPRN, KC_TRNS, KC_MS_U, KC_F11,  KC_F12,  KC_INS,
                                   KC_RBRC, KC_MS_L, KC_MS_D, KC_MS_R, KC_QUOT, KC_TRNS,
                          KC_TRNS, KC_RCBR, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_MPRV, KC_MNXT,
        KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS
    ),
};
