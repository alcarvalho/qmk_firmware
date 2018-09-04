// Netable differences vs. the default firmware for the ErgoDox EZ:
// 1. The Cmd key is now on the right side, making Cmd+Space easier.
// 2. The media keys work on OSX (But not on Windows).
#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer
#define WIND 1 // windows layer
#define SYMB 2 // symbols
#define MDIA 3 // media keys

#define MMEH_T(kc) MT((MOD_LGUI | MOD_LSFT | MOD_LALT), kc)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// Keymap 0: Basic Mac layer
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_ESC,           KC_1,     KC_2,        KC_3,    KC_4,    KC_5,   TG(WIND),
        KC_TAB,           KC_Q,     KC_W,        KC_E,    KC_R,    KC_T,   TG(SYMB),
        LT(SYMB,KC_CAPS), KC_A,     KC_S,        KC_D,    KC_F,    KC_G,
        KC_LSFT,          KC_Z,     KC_X,        KC_C,    KC_V,    KC_B,   MMEH_T(KC_NO),
        KC_BSLS,          F(0),     RALT(KC_I),  KC_LEFT, KC_RGHT,
                                                                      KC_LGUI,   KC_HOME,
                                                                                  KC_END,
                                                             KC_BSPC, KC_LALT, KC_DELETE,
        // right hand
        TG(WIND),    KC_6,   KC_7,   KC_8,   KC_9,   KC_0,             KC_MINS,
        TG(SYMB),    KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,             KC_EQL,
                     KC_H,   KC_J,   KC_K,   KC_L,   LT(MDIA, KC_SCLN),KC_QUOT,
        ALL_T(KC_NO),KC_N,   KC_M,   KC_COMM,KC_DOT, CTL_T(KC_SLSH),   KC_RSFT,
                             KC_UP,  KC_DOWN,KC_LBRC,KC_RBRC,          KC_FN1,
        KC_PGUP,        KC_LGUI,
        KC_PGDN,
        KC_RCTRL,KC_ENT, KC_SPC
    ),
// Keymap 0.1: Basic Windows layer
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[WIND] = LAYOUT_ergodox(  // layer 1 : windows
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_GRV,  KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_LCTRL, KC_TRNS,
                                                     KC_TRNS,
                                  KC_TRNS, KC_TRNS,  KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_RCTRL,
       KC_TRNS,
       KC_RGUI, KC_TRNS, KC_TRNS
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   /  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |    . |   0  |   -  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
       KC_TRNS,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_TRNS,KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_PIPE,KC_TRNS,
       KC_TRNS,KC_HASH,KC_DLR, KC_LPRN,KC_RPRN,KC_GRV,
       KC_TRNS,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,     KC_F10,         KC_F11,
       KC_TRNS, KC_UP,   KC_7,   KC_8,    KC_9,      KC_KP_ASTERISK, KC_F12,
                KC_DOWN, KC_4,   KC_5,    KC_6,      KC_KP_PLUS,     KC_TRNS,
       KC_TRNS, KC_AMPR, KC_1,   KC_2,    KC_3,      KC_KP_SLASH,    KC_TRNS,
                         KC_TRNS,KC_TRNS, KC_E,      KC_KP_MINUS,    KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_KP_ENTER, KC_0
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      | Prev | Play | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = LAYOUT_ergodox(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_MPRV, KC_MPLY, KC_MNXT, KC_TRNS, KC_TRNS,
                          KC_VOLD, KC_VOLU, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
),
};

const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_FUNCTION(0), // Calls action_function()
    [1] = ACTION_LAYER_TAP_TOGGLE(MDIA), // FN1 - Momentary Media Layer
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        register_code(KC_RSFT);
      } else {
        unregister_code(KC_RSFT);
      }
      break;
  }
  return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

uint32_t layer_state_set_user(uint32_t state) {

    uint8_t layer = biton32(state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      case 0:
        break;
      case 1:
        ergodox_right_led_1_on();
        break;
      case 2:
        ergodox_right_led_2_on();
        break;
      case 3:
        ergodox_right_led_3_on();
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      default:
        break;
    }
    return state;

};

void function0(keyrecord_t *record) {
  static uint8_t all_mods;
  static uint8_t alt_pressed;
  static uint8_t shift_pressed;
  static bool alt_flag;
  // Handle the combined Grave/Mod keys
  all_mods = get_mods();
  alt_pressed = all_mods & (MOD_BIT(KC_LALT) | MOD_BIT(KC_RALT));
  shift_pressed = all_mods & (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT));

  if (record->event.pressed) {
    // The key is being pressed.
    if (alt_pressed) {
      alt_flag = true;
      if (shift_pressed) {
        del_key(KC_LSHIFT);
        send_keyboard_report();
        del_key(KC_RSHIFT);
        send_keyboard_report();
        SEND_STRING(SS_LALT(SS_TAP(X_GRAVE)));
        if (shift_pressed & MOD_BIT(KC_LSHIFT))
          add_key(KC_LSHIFT);
        if (shift_pressed & MOD_BIT(KC_RSHIFT))
          add_key(KC_RSHIFT);
        send_keyboard_report();
        add_key(KC_A);
        send_keyboard_report();
      } else {
        SEND_STRING(SS_LALT(SS_TAP(X_GRAVE)));
        add_key(KC_A);
        send_keyboard_report();
      }
    } else {
      add_key(KC_GRV);
      send_keyboard_report();
    }
  } else {
    // The key is being released.
    if (alt_flag) {
      alt_flag = false;
      del_key(KC_A);
      send_keyboard_report();
    } else {
      del_key(KC_GRV);
      send_keyboard_report();
    }
  }
}

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  switch (id) {
  case 0:
    function0(record);
    break;
  }
}

bool r_alt_added = false;

bool process_win_accents(uint16_t keycode, keyrecord_t *record) {
  if (!(get_mods() & MOD_BIT(KC_LALT)) && record->event.pressed)
    return true;

  switch(keycode) {
    // D is E on Dvorak
    case KC_D:
    // F is U on Dvorak
    case KC_F:
    // G is I on Dvorak
    case KC_G:
    // I is C on Dvorak
    case KC_I:
    // L is N on Dvorak
    case KC_L:
    case KC_GRAVE:
      if (record->event.pressed) {
        r_alt_added = true;
        add_key(KC_RALT);
        send_keyboard_report();
      } else if (r_alt_added) {
        r_alt_added = false;
        del_key(KC_RALT);
        send_keyboard_report();
      }
      break;
  }
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  uint8_t layer = biton32(layer_state);

  switch(layer) {
    case WIND:
      return process_win_accents(keycode, record);
      break;
  }
  return true;
}
