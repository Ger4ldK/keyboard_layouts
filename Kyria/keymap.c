#include QMK_KEYBOARD_H
#define _COLEMAK 0
#define _NUMBER 1
#define _FUNCTION 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
        [_COLEMAK] = LAYOUT(KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_G, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_BSPC, KC_BSPC, KC_A, KC_R, KC_S, KC_T, KC_D, KC_H, KC_N, KC_E, KC_I, KC_O, KC_QUOT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_SPC, KC_LALT, KC_DEL, KC_ENT, KC_K, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_LBRC, KC_NO, KC_LGUI, KC_LCTL, KC_SPC, KC_LALT, KC_DEL, KC_ENT, LT(1,KC_HOME), LT(2,KC_END), KC_CAPS),
        [_NUMBER] = LAYOUT(KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_MPLY, KC_GRV, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PGUP, KC_TRNS, KC_5, KC_6, KC_7, KC_8, KC_MNXT, KC_TAB, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_PGDN, KC_TRNS, KC_9, KC_0, KC_MINS, KC_EQL, KC_MPRV, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_APP, KC_LPRN, KC_RPRN, KC_NO, KC_BSLS, KC_RBRC, KC_MUTE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TO(1), KC_NO),
        [_FUNCTION] = LAYOUT(KC_TAB, KC_F1, KC_F2, KC_F3, KC_F4, KC_X, KC_WH_U, KC_BTN1, KC_MS_U, KC_BTN2, KC_BTN3, NK_ON, KC_NO, KC_F5, KC_F6, KC_F7, KC_F8, KC_C, KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_INS, KC_PSCR, KC_TRNS, KC_F9, KC_F10, KC_F11, KC_F12, KC_V, KC_TRNS, KC_TRNS, KC_BTN5, KC_BTN4, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN5, KC_BTN4, TO(2), KC_TRNS, KC_NO)
};

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
if (index == 0) {
    switch(biton32(layer_state)) {
      case _COLEMAK:
        clockwise ? tap_code(KC_DOWN) : tap_code(KC_UP);
        break;
      case _NUMBER:
        clockwise ? tap_code(KC_AUDIO_VOL_UP) : tap_code(KC_AUDIO_VOL_DOWN);
        break;
      case _FUNCTION:
        clockwise ? tap_code(tap_code16(C(KC_Y));) : tap_code(tap_code16(C(KC_Z)););
      default:
        clockwise ? tap_code(KC_DOWN) : tap_code(KC_UP);
        break;
      }
  }
else if (index == 1) {
    switch(biton32(layer_state)) {
      case _COLEMAK:
        clockwise ? tap_code(KC_RIGHT) : tap_code(KC_LEFT);
        break;
      case _NUMBER:
        clockwise ? tap_code(KC_PGUP) : tap_code(KC_PGDN);
        break;
      case _FUNCTION:
        clockwise ? tap_code16(C(KC_TAB)) : tap_code16(S(C(KC_TAB)));
        break;
      default:
        clockwise ? tap_code(KC_RIGHT) : tap_code(KC_LEFT);
        break;
      }
    }
    return true;
}
#endif // ENCODER_ENABLE