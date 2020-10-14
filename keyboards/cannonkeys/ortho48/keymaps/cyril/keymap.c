/*
Copyright 2012,2013 Jun Wako <wakojun@gmail.com>

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

#define KC_CESC LCTL_T(KC_ESC)
#define SPC_NAV LT(_NAVIG,KC_SPC)
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

enum layer_names {
  _BASE,
  _LOWER,
  _RAISE,
  _NAVIG
};

enum custom_keycodes {
  CTLESC,
  SFTCAP
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |Ctl/Esc|  A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   / |Sft/Ent|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Caps | GUI  | Alt  |Lower | Navig/Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_BASE] = LAYOUT_1x2uC(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    CTLESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    SFTCAP,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT,
    KC_LCTL, KC_CAPS, KC_LGUI, KC_LALT, LOWER,      SPC_NAV,       RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 | Home | PgDn | PgUp | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |RESET |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_1x2uC(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______,
    RESET,   _______, _______, _______, _______,      _______,     _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 | Home | PgDn | PgUp | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_1x2uC(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______,
    RGB_TOG, RGB_MOD, BL_INC,  BL_DEC,  _______,      _______,     _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

[_NAVIG] = LAYOUT_1x2uC(
    KC_DEL,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_PSCR, KC_DEL,
    _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO,
    _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______,
    _______, _______, _______, _______, _______,      _______,     _______, KC_NO,   KC_NO,   KC_NO,   KC_NO
)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  static uint16_t modclick_timer;
  switch (keycode) {
    case CTLESC:
      if(record->event.pressed) {
        modclick_timer = timer_read();
        register_code(KC_LCTL); // Change the key to be held here
      } else {
        unregister_code(KC_LCTL); // Change the key that was held here, too!
        if (timer_elapsed(modclick_timer) < TAPPING_TERM) {
          SEND_STRING(SS_TAP(X_ESCAPE)); // Change the character(s) to be sent on tap here
        }
      } return false; // We handled this keypress
    case SFTCAP:
      if(record->event.pressed) {
        modclick_timer = timer_read();
        register_code(KC_LSFT); // Change the key to be held here
      } else {
        unregister_code(KC_LSFT); // Change the key that was held here, too!
        if (timer_elapsed(modclick_timer) < TAPPING_TERM) {
          SEND_STRING(SS_TAP(X_CAPS)); // Change the character(s) to be sent on tap here
        }
      } return false; // We handled this keypress
  }
  return true; // We didn't handle other keypresses
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CTLESC:
        case SFTCAP:
            return 75;
        default:
            return TAPPING_TERM;
    }
}
