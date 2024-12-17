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

// TODO setup

// TODO handswap


enum layers {
    _MTGAP = 0,
    _QWERTY, // TODO
    _DOTA,
    _FPS,
    _RPG,
    _NUM,
    _TNUM,
    _SYM,
    _NAV,
    _NAV2,
    _FUN,
    _ENC, // Marker layer for right encoder push
};


// Aliases for readability
#define MTGAP   DF(_MTGAP)


/*,? */
const key_override_t comma_shift_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMMA, S(KC_SLASH));
const key_override_t *key_overrides[] = {
&comma_shift_override,
  };


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_MTGAP] = LAYOUT(
     KC_TAB , KC_Y,  KC_P,  KC_O    , KC_U  , KC_J           ,                                                         KC_K             , KC_D            , KC_L, KC_C, KC_W, KC_ENT ,
     KC_LCTL, KC_I,  KC_N,  KC_E    , KC_A  , KC_COMMA       ,                                                         KC_M             , KC_H            , KC_T, KC_S, KC_R, KC_RCTL,
     KC_LALT, KC_Q,  KC_Z,  KC_QUOTE, KC_DOT, KC_SEMICOLON   , XXXXXXX       , XXXXXXX  ,     XXXXXXX, XXXXXXX       , KC_B             , KC_F            , KC_G, KC_V, KC_X, KC_RALT,
                            XXXXXXX , KC_ESC, LT(_NAV,KC_SPC), LGUI_T(KC_TAB), MO(_TNUM),     XXXXXXX, LSFT_T(KC_ENT), LT(_NUM, KC_BSPC), LT(_SYM, KC_DEL), MO(_ENC)
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

/* The default OLED and rotary encoder code can be found at the bottom of qmk_firmware/keyboards/splitkb/kyria/rev1/rev1.c
 * These default settings can be overriden by your own settings in your keymap.c
 * For your convenience, here's a copy of those settings so that you can uncomment them if you wish to apply your own modifications.
 * DO NOT edit the rev1.c file; instead override the weakly defined default functions by your own.
 */


#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {

    if (index == 0) {
      // Volume control
      // TODO left encoder doesn't work
        if (clockwise) {
          tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        // Page up/Page down

      /* if (IS_LAYER_ON(_ENC)) { */
      /*   if (IS_LAYER_ON(_MTGAP)) { */
      /*     if (clockwise) { */
      /*       tap_code(KC_1); */
      /*       /\* set_single_default_layer(_DOTA); *\/ */
      /*     } else { */
      /*       tap_code(KC_2); */
      /*       /\* set_single_default_layer(_FPS); *\/ */
      /*     } */
      /*   } */
      /* } */
      /* else { */
        if (clockwise) {
          tap_code(KC_VOLU);
        } else {
          tap_code(KC_VOLD);
        }
      /* } */
    }
    return false;
}
#endif
