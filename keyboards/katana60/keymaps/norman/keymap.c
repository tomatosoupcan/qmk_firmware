/* Copyright 2017 Baris Tosun
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
#include "debug.h"
#include "action_layer.h"
#include "version.h"

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  KPIR,
  MOVER,
  MOVEL,
  EYES,
  BEAR,
  LENNY,
  WINT,
  AXIN,
  CN75,
  CNMS,
  SFTR,
  DIM,
  LPTP,
  SHRG,
  DESK,
  STDC,
  ENDC,
  MINI,
  AVLD,
  AVLM,
  AVLU,
  WAOT,
  LKTW,
  HDTB,
  TSMN,
  CLAP,
  TADA,
  CALL,
  FIRE,
  UPSD,
  THNK,
  CRYL,
  SKLL,
  THDN,
  THUP,
  OKAY,
  TGCP,
  RETB,
  WINE,
  NTPD
};
enum {
  TD_QUPE = 0
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
  case SHRG:
    if (record->event.pressed) {
      SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_KP_0)SS_TAP(X_KP_1)SS_TAP(X_KP_7)SS_TAP(X_KP_5)SS_UP(X_LALT)); //hand
      SEND_STRING(SS_TAP(X_BSLASH)"_("); //arm+_(
      SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_KP_PLUS)SS_TAP(X_KP_3)SS_TAP(X_KP_0)SS_TAP(X_C)SS_TAP(X_KP_4)SS_UP(X_LALT));
      SEND_STRING(")_"SS_TAP(X_SLASH)); //)_+arm
      SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_KP_0)SS_TAP(X_KP_1)SS_TAP(X_KP_7)SS_TAP(X_KP_5)SS_UP(X_LALT)); //hand

    }
  break;
  case EYES:
    if (record->event.pressed) {
      SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_KP_PLUS)SS_TAP(X_KP_0)SS_TAP(X_C)SS_TAP(X_A)SS_TAP(X_KP_0)SS_UP(X_LALT)); //eye
      SEND_STRING("_"); // _
      SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_KP_PLUS)SS_TAP(X_KP_0)SS_TAP(X_C)SS_TAP(X_A)SS_TAP(X_KP_0)SS_UP(X_LALT)); //eye
    }
  break;
  case DESK:
    if (record->event.pressed) {
      SEND_STRING(SS_DOWN(X_LCTRL)SS_DOWN(X_LSHIFT)SS_DOWN(X_LALT)SS_TAP(X_GRAVE)SS_UP(X_LCTRL)SS_UP(X_LALT)SS_UP(X_LSHIFT));
      SEND_STRING(SS_DOWN(X_LCTRL)SS_DOWN(X_LSHIFT)SS_DOWN(X_LALT)SS_UP(X_LCTRL)SS_UP(X_LALT)SS_UP(X_LSHIFT));
    }
  break;
  case LPTP:
    if (record->event.pressed) {
      SEND_STRING(SS_DOWN(X_LCTRL)SS_DOWN(X_LALT)SS_TAP(X_GRAVE)SS_UP(X_LCTRL)SS_UP(X_LALT));
      SEND_STRING(SS_DOWN(X_LCTRL)SS_DOWN(X_LALT)SS_UP(X_LCTRL)SS_UP(X_LALT));
    }
  break;
  case SFTR:
    if (record->event.pressed) {
      SEND_STRING("BEGIN TRAN"SS_TAP(X_ENTER)SS_TAP(X_ENTER)"ROLLBACK TRAN"SS_TAP(X_UP));
    }
  break;
  case BEAR:
    if (record->event.pressed) {
      SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_KP_PLUS)SS_TAP(X_KP_1)SS_TAP(X_D)SS_TAP(X_KP_9)SS_TAP(X_KP_8)SS_UP(X_LALT)); //left bear
      SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_KP_PLUS)SS_TAP(X_KP_1)SS_TAP(X_D)SS_TAP(X_KP_5)SS_TAP(X_KP_2)SS_UP(X_LALT)); //eye
      SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_KP_PLUS)SS_TAP(X_KP_1)SS_TAP(X_D)SS_TAP(X_KP_2)SS_TAP(X_KP_5)SS_UP(X_LALT)); //nose
      SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_KP_PLUS)SS_TAP(X_KP_1)SS_TAP(X_D)SS_TAP(X_KP_5)SS_TAP(X_KP_2)SS_UP(X_LALT)); //eye
      SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_KP_PLUS)SS_TAP(X_KP_1)SS_TAP(X_D)SS_TAP(X_KP_8)SS_TAP(X_KP_5)SS_UP(X_LALT)); //right bear
    }
  break;
  case LENNY:
    if (record->event.pressed) {
      SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_KP_PLUS)SS_TAP(X_KP_0)SS_TAP(X_KP_0)SS_TAP(X_KP_2)SS_TAP(X_KP_8)SS_UP(X_LALT)); //left parenthesis
                        SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_KP_PLUS)SS_TAP(X_KP_0)SS_TAP(X_KP_0)SS_TAP(X_KP_2)SS_TAP(X_KP_0)SS_UP(X_LALT)); //space
      SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_KP_PLUS)SS_TAP(X_KP_0)SS_TAP(X_KP_3)SS_TAP(X_KP_6)SS_TAP(X_KP_1)SS_UP(X_LALT)); //eyebrow
      SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_KP_PLUS)SS_TAP(X_KP_0)SS_TAP(X_KP_0)SS_TAP(X_B)SS_TAP(X_KP_0)SS_UP(X_LALT)); //eye
                        SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_KP_PLUS)SS_TAP(X_KP_0)SS_TAP(X_KP_0)SS_TAP(X_KP_2)SS_TAP(X_KP_0)SS_UP(X_LALT)); //space
      SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_KP_PLUS)SS_TAP(X_KP_0)SS_TAP(X_KP_3)SS_TAP(X_KP_5)SS_TAP(X_C)SS_UP(X_LALT)); //mouth
      SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_KP_PLUS)SS_TAP(X_KP_0)SS_TAP(X_KP_2)SS_TAP(X_KP_9)SS_TAP(X_KP_6)SS_UP(X_LALT)); //nose
                        SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_KP_PLUS)SS_TAP(X_KP_0)SS_TAP(X_KP_0)SS_TAP(X_KP_2)SS_TAP(X_KP_0)SS_UP(X_LALT)); //space
      SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_KP_PLUS)SS_TAP(X_KP_0)SS_TAP(X_KP_3)SS_TAP(X_KP_6)SS_TAP(X_KP_1)SS_UP(X_LALT)); //eyebrow
      SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_KP_PLUS)SS_TAP(X_KP_0)SS_TAP(X_KP_0)SS_TAP(X_B)SS_TAP(X_KP_0)SS_UP(X_LALT)); //eye
      SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_KP_PLUS)SS_TAP(X_KP_0)SS_TAP(X_KP_0)SS_TAP(X_KP_2)SS_TAP(X_KP_9)SS_UP(X_LALT)); //right parenthesis
    }
  break;
        case CLAP:
                if (record->event.pressed) {
      SEND_STRING(SS_DOWN(X_RALT)"clap"SS_UP(X_RALT));
  }
  break;
        case TADA:
                if (record->event.pressed) {
                        SEND_STRING(SS_DOWN(X_RALT)"tada"SS_UP(X_RALT));
        }
        break;
        case CALL:
                if (record->event.pressed) {
                        SEND_STRING(SS_DOWN(X_RALT)"call"SS_UP(X_RALT));
        }
        break;
        case FIRE:
                if (record->event.pressed) {
                        SEND_STRING(SS_DOWN(X_RALT)"fire"SS_UP(X_RALT));
        }
        break;
        case UPSD:
                if (record->event.pressed) {
                        SEND_STRING(SS_DOWN(X_RALT)"upsd"SS_UP(X_RALT));
        }
        break;
        case THNK:
                if (record->event.pressed) {
                        SEND_STRING(SS_DOWN(X_RALT)"thnk"SS_UP(X_RALT));
        }
        break;
        case CRYL:
                if (record->event.pressed) {
                        SEND_STRING(SS_DOWN(X_RALT)"cryl"SS_UP(X_RALT));
        }
        break;
        case SKLL:
                if (record->event.pressed) {
                        SEND_STRING(SS_DOWN(X_RALT)"skll"SS_UP(X_RALT));
        }
        break;
        case THDN:
                if (record->event.pressed) {
                        SEND_STRING(SS_DOWN(X_RALT)"thdn"SS_UP(X_RALT));
        }
        break;
        case THUP:
                if (record->event.pressed) {
                        SEND_STRING(SS_DOWN(X_RALT)"thup"SS_UP(X_RALT));
        }
        break;
        case OKAY:
                if (record->event.pressed) {
                        SEND_STRING(SS_DOWN(X_RALT)"okay"SS_UP(X_RALT));
        }
        break;

  }
  return true;
}

#define KPIR LALT(KC_SPACE)
#define MOVER LGUI(LSFT(KC_RGHT))
#define MOVEL LGUI(LSFT(KC_LEFT))
#define WINT LCTL(LSFT(LGUI(KC_T)))
#define AXIN LCTL(LSFT(KC_GRV))
#define CN75 LSFT(LALT(LGUI(KC_S)))
#define CNMS LCTL(LSFT(KC_1))
#define DIM LCTL(LSFT(KC_0))
#define STDC LCTL(KC_HOME)
#define ENDC LCTL(KC_END)
#define MINI LCTL(LSFT(LGUI(KC_M)))
#define AVLD LALT(LCTL(LGUI(KC_2)))
#define AVLM LALT(LCTL(LGUI(KC_3)))
#define AVLU LALT(LCTL(LGUI(KC_4)))
#define WAOT LCTL(LSFT(KC_8))
#define LKTW LALT(LCTL(LGUI(KC_C)))
#define HDTB LALT(LCTL(LGUI(KC_T)))
#define TSMN LCTL(LSFT(KC_ESC))
#define TGCP LALT(LCTL(LGUI(KC_8)))
#define RETB LCTL(LSFT(KC_T))
#define WINE LGUI(KC_E)
#define NTPD LALT(LCTL(KC_L))

//Emoji requires wincompose to be installed


#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define NORM 0 // Norman
#define QWER 1 // Qwerty
#define FUNT 2 // Functions
#define SWAP 3 // Swap spaces
#define NUMB 4 // Numpad

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[NORM] = LAYOUT( /* Base */
  KC_ESC,  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    TO(1),   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,
  KC_TAB,  KC_Q,    KC_W,    KC_D,    KC_F,    KC_K,    KC_LBRC,          KC_RBRC, KC_J,    KC_U,    KC_R,    KC_L,    KC_SCLN, KC_BSLS,
  KC_LSFT, KC_A,    KC_S,    KC_E,    KC_T,    KC_G,    KC_HOME,          KC_PGUP, KC_Y,    KC_N,    KC_I,    KC_O,    KC_H,    KC_ENT,
  KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_END,  KC_DEL,  KC_PGDN, KC_P,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_QUES,
  KC_PERC, KC_LGUI, KC_LALT, LT(2, KC_SLSH),            KC_BSPC, KPIR,    KC_SPC,           KC_F5,   KC_QUOT, KC_LEFT, KC_DOWN, KC_RIGHT
    ),
 [QWER] = LAYOUT( /* Base */
  KC_ESC,  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    TO(0),   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_PLUS,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC,          KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_HOME,          KC_PGUP, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
  KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_END,  KC_DEL,  KC_PGDN, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_QUES,
  KC_PERC, KC_LGUI, KC_LALT, LT(2, KC_SLSH),            KC_BSPC, KPIR,    KC_SPC,           KC_F5,   KC_QUOT, KC_LEFT, KC_DOWN, KC_RIGHT
    ),

[FUNT] = LAYOUT(
  KC_ESC,  KC_BTN3, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   TG(4),   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  MOVEL,   MOVER,
  SFTR,    KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, WINT,    KC_F11,           KC_F12,  RETB,    WINE,    EYES,    BEAR,    LENNY,   KC_PSCR,
  KC_LSFT, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, AVLD,    KC_VOLD,          KC_VOLU, AVLU,    WAOT,    MINI,    CLAP,    THNK,    KC_ENT,
  KC_LCTL, AXIN,    LKTW,    CN75,    CNMS,    AVLM,    KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, TSMN,    CALL,    CRYL,    THUP,    TADA,
  DIM,     KC_LGUI, KC_LALT, KC_TRNS,                   LPTP,    SHRG,    DESK,             NTPD,    TG(3),   OKAY,    THDN,    FIRE
    ),
[SWAP] = LAYOUT(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______,                   KC_SPC,  _______, KC_BSPC,          _______, _______, _______, _______, _______
    ),
[NUMB] = LAYOUT(
  _______, _______, _______, _______, _______, _______, _______, _______, KC_PSLS, KC_PAST, KC_PMNS, KC_NLCK, _______, _______, _______,
  RESET,   _______, _______, _______, _______, _______, _______,          KC_P7,   KC_P8,   KC_P9,   KC_PPLS, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,          KC_P4,   KC_P5,   KC_P6,   KC_PPLS, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_P1,   KC_P2,   KC_P3,   KC_PENT, _______, _______, _______,
  _______, _______, _______, _______,                   _______, _______, KC_P0,            KC_PDOT, KC_PENT, _______, _______, _______
    )

};

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}


void led_set_user(uint8_t usb_led) {

}
