// v1.1

#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#include "keymap_german.h"
#include "keymap_nordic.h"

#define TAPPING_TOGGLE 1
#define PERMISSIVE_HOLD

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD,

};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = KEYMAP(
      KC_GRAVE,         KC_1,     KC_2,    KC_3,     KC_4,      KC_5,             TG(1),
      KC_TAB,           KC_Q,     KC_W,    KC_E,     KC_R,      KC_T,             LCTL(KC_B),
      CTL_T(KC_ESCAPE), KC_A,     KC_S,    KC_D,     KC_F,      KC_G,
      KC_LGUI,          KC_Z,     KC_X,    KC_C,     KC_V,      KC_B,             KC_MINUS,
      OSL(2),           KC_TRNS,  KC_TRNS, KC_MINUS, OSL(2),

      KC_MUTE,          KC_VOLU,
      KC_VOLD,
      KC_LSHIFT,        KC_SPACE, KC_LALT,

      RESET,            KC_6,     KC_7,    KC_8,     KC_9,      KC_0,             KC_BSPACE,
      KC_TRNS,          KC_Y,     KC_U,    KC_I,     KC_O,      KC_P,             KC_BSLASH,
      KC_H,             KC_J,     KC_K,    KC_L,     KC_SCOLON, RCTL_T(KC_QUOTE),
      KC_EQUAL,         KC_N,     KC_M,    KC_COMMA, KC_DOT,    KC_SLASH,         KC_RGUI,
      OSL(2),           KC_EQUAL, KC_TRNS, KC_TRNS,  OSL(2),

      KC_MPRV,          KC_MNXT,
      KC_MPLY,
      KC_RALT,          KC_ENTER, KC_RSHIFT
  ),

  [1] = KEYMAP(
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TO(0),
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

      KC_TRNS, KC_TRNS,
      KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS,

      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

      KC_TRNS, KC_TRNS,
      KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [2] = KEYMAP(
      KC_ESCAPE, KC_F1,     KC_F2,       KC_F3,    KC_F4,       KC_F5,   KC_TRNS,
      KC_TRNS,   KC_PGUP,   KC_HOME,     KC_UP,    KC_END,      KC_TRNS, KC_TRNS,
      KC_TRNS,   KC_PGDOWN, KC_LEFT,     KC_DOWN,  KC_RIGHT,    KC_TRNS,
      KC_TRNS,   KC_TRNS,   KC_TRNS,     KC_LPRN,  KC_LBRACKET, KC_LCBR, KC_TRNS,
      KC_TRNS,   KC_TRNS,   KC_TRNS,     KC_TRNS,  KC_TRNS,

      KC_TRNS,   KC_TRNS,
      KC_TRNS,
      KC_TRNS,   KC_TRNS,   KC_TRNS,

      KC_TRNS,   KC_F6,     KC_F7,       KC_F8,    KC_F9,       KC_F10,  KC_DELETE,
      KC_TRNS,   KC_TRNS,   KC_TRNS,     KC_TRNS,  KC_F11,      KC_F12,  KC_INSERT,
      KC_LEFT,   KC_DOWN,   KC_UP,       KC_RIGHT, KC_QUOTE,    KC_TRNS,
      KC_TRNS,   KC_RCBR,   KC_RBRACKET, KC_RPRN,  KC_TRNS,     KC_TRNS, KC_TRNS,
      KC_TRNS,   KC_TRNS,   KC_TRNS,     KC_TRNS,  KC_TRNS,

      KC_TRNS,   KC_TRNS,
      KC_TRNS,
      KC_TRNS,   KC_TRNS,   KC_TRNS
  ),

};

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(1)
};

// leaving this in place for compatibilty with old keymaps cloned and re-compiled.
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
      }
    return MACRO_NONE;
};

void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
      break;

  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {

    uint8_t layer = biton32(state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      default:
        break;
    }
    return state;

};
