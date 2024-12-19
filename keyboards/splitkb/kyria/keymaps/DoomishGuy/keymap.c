/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "gpio.h"


// TODO handswap

enum keycodes {
  KC_RESET_LAYER_RING = QK_USER,
};

enum layers {
    /* Base layers.
       The right encoder cycles through these.
       Note that this doesn't change the default layer.
       Keep the right encoder button transparent in all base layers for this feature.
       Optionally keep the left encoder button free as a return key.
    */
    _MTGAP = 0,
    /* _QWERTY, // TODO */
    _DOTA,
    _FPS,
    _RPG,

    /* Miroyuku inspired layers.
       Also includes a proper numpad key layer accessible from 1 hand.
    */
    _NUM,
    _TNUM,
    _SYM,
    _NAV,
    _NAV2,
    _FUN,

    /* Marker layers */
    _ENC, // Marker layer for right encoder push
};

/* How many base layers to cycle through.
   Order is determined by the layers enum. */
#define BASE_LAYER_RING_SIZE 4

// Aliases for readability
/* #define MTGAP DF(_MTGAP) */


/* ,? */
const key_override_t comma_shift_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMMA, S(KC_SLASH));
const key_override_t *key_overrides[] = {
  &comma_shift_override,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_MTGAP] = LAYOUT(
     KC_TAB , KC_Y,  KC_P,  KC_O               , KC_U  , KC_J           ,                                                         KC_K             , KC_D            , KC_L, KC_C, KC_W, KC_ENT ,
     KC_LCTL, KC_I,  KC_N,  KC_E               , KC_A  , KC_COMMA       ,                                                         KC_M             , KC_H            , KC_T, KC_S, KC_R, KC_RCTL,
     KC_LALT, KC_Q,  KC_Z,  KC_QUOTE           , KC_DOT, KC_SEMICOLON   , XXXXXXX       , XXXXXXX  ,     XXXXXXX, XXXXXXX       , KC_B             , KC_F            , KC_G, KC_V, KC_X, KC_RALT,
                            KC_RESET_LAYER_RING, KC_ESC, LT(_NAV,KC_SPC), LGUI_T(KC_TAB), MO(_TNUM),     XXXXXXX, LSFT_T(KC_ENT), LT(_NUM, KC_BSPC), LT(_SYM, KC_DEL), LT(_ENC, KC_RESET_LAYER_RING)
    ),

  [_NUM] = LAYOUT(
     _______, KC_LBRC    , KC_7, KC_8   , KC_9   , KC_RBRC  ,                                         _______, _______, _______ , _______ , _______  , _______,
     _______, S(KC_9)    , KC_4, KC_5   , KC_6   , S(KC_0)  ,                                         _______, KC_RGUI, KC_RSFT , KC_RCTL , MO(_FUN) , _______,
     _______, S(KC_COMMA), KC_1, KC_2   , KC_3   , S(KC_DOT), _______, _______,     _______, _______, _______, KC_RALT, _______ ,  _______, MO(_TNUM), _______,
                                 _______, KC_MINS, KC_0     , KC_EQL , _______,     _______, _______, _______, _______, _______
    ),

  [_TNUM] = LAYOUT(
     KC_PSLS, KC_PDOT, KC_P7, KC_P8  , KC_P9  , KC_PMNS,                                         _______, _______, _______ , _______, _______, _______,
     KC_PAST, KC_PENT, KC_P4, KC_P5  , KC_P6  , KC_P0  ,                                         _______, KC_RGUI, KC_RSFT , KC_RCTL, _______, _______,
     KC_PPLS, KC_PCMM, KC_P1, KC_P2  , KC_P3  , KC_PEQL, KC_NUM , _______,     _______, _______, _______, KC_RALT, _______ , _______, _______, _______,
                              _______, KC_PMNS, KC_P0  , KC_PEQL, _______,     _______, _______, _______, _______, _______
    ),


  [_FUN] = LAYOUT(
     _______, _______, KC_F7, KC_F8  , KC_F9  , KC_F12 ,                                         _______, _______, _______, _______, _______, _______,
     _______, _______, KC_F4, KC_F5  , KC_F6  , KC_F11 ,                                         _______, KC_RGUI, KC_RSFT, KC_RCTL, _______, _______,
     _______, _______, KC_F1, KC_F2  , KC_F3  , KC_F10 , _______, _______,     _______, _______, _______, KC_RALT, _______, _______, _______, _______,
                              _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
    ),

  [_SYM] = LAYOUT(
     _______, S(KC_LBRC), S(KC_7), S(KC_8), S(KC_9)   , S(KC_RBRC),                                           _______, _______, _______, _______, _______, _______,
     _______, KC_SLSH   , S(KC_4), S(KC_5), S(KC_6)   , KC_BSLS   ,                                           _______, KC_RGUI, KC_RSFT, KC_RCTL, _______, _______,
     _______, KC_GRV    , S(KC_1), S(KC_2), S(KC_3)   , S(KC_BSLS), _______  , _______,     _______, _______, _______, KC_RALT, _______, _______, _______, _______,
                                   _______, S(KC_MINS), S(KC_GRV) , S(KC_EQL), _______,     _______, _______, _______, _______, _______
    ),


  [_NAV] = LAYOUT(
     _______, _______  , _______, _______, _______, _______,                                         _______, KC_H   , KC_J   , KC_K   , KC_L    , _______,
     _______, MO(_NAV2), KC_LCTL, KC_LSFT, KC_LGUI, _______,                                         _______, KC_LEFT, KC_DOWN, KC_UP  , KC_RIGHT, _______,
     _______, _______  , _______, _______, KC_LALT, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______ , _______,
                                  _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
    ),

  [_NAV2] = LAYOUT(
     _______, _______, _______, _______, _______ , _______,                                     _______, _______, _______, _______, _______, _______,
     _______, _______, KC_LEFT, KC_UP  , KC_RIGHT, _______,                                     _______, _______, _______, _______, _______, _______,
     _______, _______, _______, KC_DOWN, _______ , _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______,
                                _______, _______ , _______, _______, _______,     _______, _______, _______, _______, _______
    ),

  [_DOTA] = LAYOUT(
     _______, KC_Q        , KC_W        , KC_E   , KC_R          , KC_T  ,                                         _______, _______, _______, _______, _______, _______,
     _______, KC_A        , KC_S        , KC_D   , KC_F          , KC_G  ,                                         _______, _______, _______, _______, _______, _______,
     _______, LCTL_T(KC_Z), LSFT_T(KC_X), KC_C   , KC_V          , KC_B  , _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______,
                                          _______, LALT_T(KC_ESC), KC_SPC, KC_TAB , _______,     _______, _______, _______, _______, _______
    ),

  [_FPS] = LAYOUT(
     _______, KC_1   , KC_2, KC_3   , KC_4            , KC_5  ,                                         _______, _______, _______, _______, _______, _______,
     _______, KC_LSFT, KC_A, KC_W   , KC_D            , KC_F  ,                                         _______, _______, _______, _______, _______, _______,
     _______, KC_LCTL, KC_Q, KC_S   , KC_E            , KC_R  , _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______,
                             _______, MT(_FUN, KC_ESC), KC_SPC, KC_TAB , _______,     _______, _______, _______, _______, _______
    ),

  [_RPG] = LAYOUT(
     _______, _______, KC_Z   , KC_X   , KC_C    , _______,                                         _______, _______, _______, _______, _______ , _______,
     _______, KC_LSFT, KC_LEFT, KC_UP  , KC_RIGHT, _______,                                         _______, KC_LEFT, KC_DOWN, KC_UP  , KC_RIGHT, _______,
     _______, _______, _______, KC_DOWN, _______ , _______, _______, _______,     _______, _______, _______, KC_Z   , KC_X   , KC_C   , _______ , _______,
                                _______, KC_ESC  , KC_SPC , KC_LSFT, _______,     _______, KC_LSFT, KC_SPC , KC_ESC , _______
    ),

   [_ENC] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),




  //     [_LAYERINDEX] = LAYOUT(
  //       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
  //       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
  //       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  //                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  //     ),
};



uint8_t saved_layer = 0;
uint8_t selected_layer = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

  case KC_RESET_LAYER_RING:
    if (record->event.pressed) {
      // Toggle between 2 selected layers
      uint8_t t = saved_layer;
      saved_layer = selected_layer;
      selected_layer = t;

      layer_clear();
      layer_on(selected_layer);
      return false;
    }
    return true;
  case LT(_ENC, KC_RESET_LAYER_RING):
    // On tap
    if (record->tap.count && record->event.pressed) {
      uint8_t t = saved_layer;
      saved_layer = selected_layer;
      selected_layer = t;

      layer_clear();
      layer_on(selected_layer);
      return false;
    }
    return true;

  default:
    return true;
  }
}


bool encoder_update_user(uint8_t index, bool clockwise) {
  switch (index) {
  case 0:
    // TODO left encoder doesn't work
    if (clockwise) {
      tap_code(KC_1);
    } else {
      tap_code(KC_2);
    }
  case 1:
    if (IS_LAYER_ON(_ENC)) {
      // Cycle base layers
      if (clockwise) {
        selected_layer += 1;
        selected_layer %= BASE_LAYER_RING_SIZE;
      } else {
        selected_layer += BASE_LAYER_RING_SIZE - 1;
        selected_layer %= BASE_LAYER_RING_SIZE;
      }
      layer_clear();
      layer_on(_ENC);
      layer_on(selected_layer);
    }
    else {
      // Volume control
      if (clockwise) {
        tap_code(KC_VOLU);
      } else {
        tap_code(KC_VOLD);
      }
    }
  }
  return false;
}

const  rgblight_segment_t PROGMEM dota_light_layer[] = RGBLIGHT_LAYER_SEGMENTS
  (
   // Blue base
   {0, 6, 135, 255, 230},
   {31, 6, 135, 255, 230}
   );

const  rgblight_segment_t PROGMEM fps_light_layer[] = RGBLIGHT_LAYER_SEGMENTS
  (
   // Purple
   {0, 6, 190, 255, 230},
   {31, 6, 190, 255, 230}
   );

const  rgblight_segment_t PROGMEM rpg_light_layer[] = RGBLIGHT_LAYER_SEGMENTS
  (
   // Green
   {0,6, 100, 255, 230},
   {31,6, 100, 255, 230}
   );

const  rgblight_segment_t PROGMEM num_light_layer[] = RGBLIGHT_LAYER_SEGMENTS
  (
   {6,4, HSV_PURPLE}
);

const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST
  (
   dota_light_layer,
   fps_light_layer,
   rpg_light_layer,
   num_light_layer
);

void keyboard_post_init_user(void) {
  rgblight_enable_noeeprom(); // enables RGB, without saving settings

  // Portal orange base
  rgblight_sethsv_noeeprom(12, 255, 230); // sets the color to red without saving
  /* rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING); // sets mode to Fast breathing without saving */
  /* rgblight_set_speed_noeeprom(40); */
  /* debug_enable=true; */
  /* debug_matrix=true; */

  rgblight_layers = rgb_layers;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  rgblight_set_layer_state(0, layer_state_cmp(state, _DOTA));
  rgblight_set_layer_state(1, layer_state_cmp(state, _FPS));
  rgblight_set_layer_state(2, layer_state_cmp(state, _RPG));
  return state;
}

void keyboard_pre_init_user(void) {
  // Disable liatris power led
  gpio_set_pin_output(24);
  gpio_write_pin_high(24);
}
