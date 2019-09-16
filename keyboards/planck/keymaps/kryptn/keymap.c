#include QMK_KEYBOARD_H
#ifdef AUDIO_ENABLE
#include "muse.h"
#endif
#include "eeprom.h"
#include "keymap_german.h"
#include "keymap_nordic.h"
#include "keymap_french.h"
#include "keymap_spanish.h"
#include "keymap_hungarian.h"
#include "keymap_swedish.h"
#include "keymap_br_abnt2.h"
#include "keymap_canadian_multilingual.h"
#include "keymap_german_ch.h"
#include "keymap_jp.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)

enum planck_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
  DYNAMIC_MACRO_RANGE,
};

enum planck_layers {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST,
  _NAV,
  _RMOUSE,
  _NUMPAD,
};

#include "dynamic_macro.h"

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_planck_grid(
      KC_TAB,          KC_Q,     KC_W,    KC_E,    KC_R,  KC_T,     KC_Y,  KC_U,  KC_I,     KC_O,    KC_P,      KC_BSPACE,
      LT(4,KC_ESCAPE), KC_A,     KC_S,    KC_D,    KC_F,  KC_G,     KC_H,  KC_J,  KC_K,     KC_L,    KC_SCOLON, KC_QUOTE,
      KC_LSPO,         KC_Z,     KC_X,    KC_C,    KC_V,  KC_B,     KC_N,  KC_M,  KC_COMMA, KC_DOT,  KC_SLASH,  MT(MOD_RSFT, KC_ENTER),
      KC_HYPR,         KC_LCTRL, KC_LALT, KC_LGUI, LOWER, KC_SPACE, KC_NO, RAISE, KC_LEFT,  KC_DOWN, KC_UP,     KC_RIGHT),

  [_LOWER] = LAYOUT_planck_grid(
      KC_GRAVE, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,          KC_8,                KC_9,              KC_0,            _______,
      _______,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINUS,      KC_EQUAL,            KC_LBRACKET,       KC_RBRACKET,     KC_BSLASH,
      _______,  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NONUS_HASH, KC_NONUS_BSLASH,     KC_HOME,           KC_END,          _______,
      _______,  _______, _______, _______, _______, _______, KC_NO,   _______,       KC_MEDIA_NEXT_TRACK, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, KC_MEDIA_PLAY_PAUSE),

  [_RAISE] = LAYOUT_planck_grid(
      KC_TILD, KC_EXLM,  KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,       KC_ASTR,             KC_LPRN,           KC_RPRN,         _______,
      _______, KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,       KC_PLUS,             KC_LCBR,           KC_RCBR,         KC_PIPE,
      _______, KC_F7,    KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NONUS_HASH, KC_NONUS_BSLASH,     KC_PGUP,           KC_PGDOWN,       _______,
      _______, _______,  _______, _______, _______, _______, KC_NO,   _______,       KC_MEDIA_NEXT_TRACK, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, KC_MEDIA_PLAY_PAUSE),

  [_ADJUST] = LAYOUT_planck_grid(
      _______, _______, _______, _______, _______, DYN_REC_STOP,    _______,         _______, _______, _______, _______, _______,
      _______, _______, AU_ON,   AU_OFF,  AU_TOG,  DYN_REC_START1,  DYN_REC_START2,  RGB_TOG, RGB_VAI, RGB_VAD, _______, RESET,
      _______, _______, MU_ON,   MU_OFF,  MU_TOG,  DYN_MACRO_PLAY1, DYN_MACRO_PLAY2, RGB_MOD, RGB_HUI, RGB_HUD, _______, _______,
      MO(6),   _______, _______, _______, _______, _______,         KC_NO,           _______, _______, _______, _______, _______),

  [_NAV] = LAYOUT_planck_grid(
      _______, KC_MS_BTN1, KC_MS_UP,   KC_MS_BTN2,  KC_MS_WH_UP,   _______, _______, KC_PGUP, KC_UP,   KC_PGDOWN, _______, KC_DELETE,
      _______, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_MS_WH_DOWN, _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT,  _______, _______,
      _______, _______,    _______,    _______,     _______,       _______, KC_END,  _______, _______, _______,   _______, _______,
      _______, _______,    _______,    _______,     KC_MS_BTN1,    _______, KC_NO,   MO(5),   _______, _______,   _______, _______),

  [_RMOUSE] = LAYOUT_planck_grid(
      _______, _______, _______, _______, _______, _______, _______, KC_MS_BTN1, KC_MS_UP,   KC_MS_BTN2,  KC_MS_WH_UP,   _______,
      _______, _______, _______, _______, _______, _______, _______, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_MS_WH_DOWN, _______,
      _______, _______, _______, _______, _______, _______, _______, _______,    KC_MS_BTN3, _______,     _______,       _______,
      _______, _______, _______, _______, _______, _______, KC_NO,   _______,    _______,    _______,     _______,       _______),

  [_NUMPAD] = LAYOUT_planck_grid(
      _______, _______, _______, _______, _______, _______, _______, KC_7, KC_8,    KC_9,    KC_KP_SLASH,    _______,
      _______, _______, _______, _______, _______, _______, _______, KC_4, KC_5,    KC_6,    KC_KP_ASTERISK, _______,
      _______, _______, _______, _______, _______, _______, _______, KC_1, KC_2,    KC_3,    KC_KP_MINUS,    _______,
      _______, _______, _______, _______, _______, _______, KC_NO,   KC_0, _______, KC_DOT,  KC_KP_PLUS,     _______),

};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_record_dynamic_macro(keycode, record)) {
    return false;
  }
  switch (keycode) {
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}

#ifdef AUDIO_ENABLE
bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
    if (muse_mode) {
        if (IS_LAYER_ON(_RAISE)) {
            if (clockwise) {
                muse_offset++;
            } else {
                muse_offset--;
            }
        } else {
            if (clockwise) {
                muse_tempo+=1;
            } else {
                muse_tempo-=1;
            }
        }
    } else {
        if (clockwise) {
        #ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_DOWN);
            unregister_code(KC_MS_WH_DOWN);
        #else
            register_code(KC_PGDN);
            unregister_code(KC_PGDN);
        #endif
        } else {
        #ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_UP);
            unregister_code(KC_MS_WH_UP);
        #else
            register_code(KC_PGUP);
            unregister_code(KC_PGUP);
        #endif
        }
    }
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
    switch (keycode) {
    case RAISE:
    case LOWER:
        return false;
    default:
        return true;
    }
}
#endif

uint32_t layer_state_set_user(uint32_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
