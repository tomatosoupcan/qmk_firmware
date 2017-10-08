#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // norman
#define QWRT 1 // function & media
#define NMPD 2 // number pad
#define MDIA 3 // qwerty
#define WHAT 4 // Reserved for more macros
#define MCRO 5 // Macros
#define KEYPR LALT(KC_SPACE)
#define THMUP LCTL(LSFT(KC_U))
#define THMDWN LCTL(LSFT(KC_D))
#define AUDSRC LCTL(LSFT(KC_GRV))
#define DIM LCTL(LSFT(KC_0))

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD,
  SHRUG1,
  EYES,
  WHAT1,
  SLAPTO,
  SDESKT,
  SAFQR,
  DYNAMIC_MACRO_RANGE
};

#include "dynamic_macro.h"

enum {
	TD_QURI,
	TD_SHLE,
	TD_5F5,
	TD_MRB,
	TD_MLB,
	TD_MBS,
	TD_MSS,
	TD_MAT
};

qk_tap_dance_action_t tap_dance_actions[] = {
	[TD_QURI] = ACTION_TAP_DANCE_DOUBLE(KC_QUES, LSFT(KC_0)),
	[TD_SHLE] = ACTION_TAP_DANCE_DOUBLE(KC_LSHIFT, LSFT(KC_9)),
	[TD_5F5]  = ACTION_TAP_DANCE_DOUBLE(KC_5, KC_F5)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   ESC  |   1  |   2  |   3  |   4  | 5/F5 |   `  |           |  _   |   6  |   7  |   8  |   9  |   0  |   =    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | TAB    |   Q  |   W  |   D  |   F  |   K  | LGUI |           |MYCM  |   J  |   U  |   R  |   L  |   ;  |   -    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |LSHIFT/(|   A  |   S  |   E  |   T  |   G  |------|           |------|   Y  |   N  |   I  |   O  |   H  |  ?/)   |
 * |--------+------+------+------+------+------| LALT |           | KYPR |------+------+------+------+------+--------|
 * | LCTRL  |   Z  |   X  |   C  |   V  |   B  |      |           |      |   P  |   M  |   ,  |   .  |   '  |   %    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LK2  | LK1  |  LA3 |  LA4 |  LA5 |                                       |   [  |   ] |   /  |   \  |   @   |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Left | Right|       | Home |  End |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |  Up  |       | PgUp |        |      |
 *                                 |Backsp|  Del |------|       |------| Enter  |Space |
 *                                 |ace   |      | Down |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_ESC,         KC_1  ,         KC_2 ,   KC_3 ,   KC_4 ,TD(TD_5F5),   KC_GRV ,
        KC_TAB,         KC_Q  ,         KC_W ,   KC_D ,   KC_F ,      KC_K,   KC_LGUI,
        TD(TD_SHLE),    KC_A  ,         KC_S ,   KC_E ,   KC_T ,      KC_G,
        KC_LCTL,        KC_Z  ,         KC_X ,   KC_C ,   KC_V ,      KC_B,   KC_LALT,
        TG(2)  ,        TG(1),         OSL(3),   OSL(4),  OSL(5),
																				   KC_LEFT,KC_RIGHT,
																							  KC_UP,
																		   KC_BSPC,KC_DEL,  KC_DOWN,
        // right hand
             DYN_REC_STOP,     KC_6,   KC_7,     KC_8,   KC_9,      KC_0,             KC_EQL,
             KC_MYCM   ,     KC_J,   KC_U,     KC_R,   KC_L,   KC_SCLN,            KC_MINS,
                             KC_Y,   KC_N,     KC_I,   KC_O,      KC_H,            TD(TD_QURI),
                KEYPR,       KC_P,   KC_M,  KC_COMM, KC_DOT,  KC_QUOTE,            KC_PERC,
                                  KC_LBRC,  KC_RBRC,KC_SLSH,   KC_BSLS,              KC_AT,
 KC_HOME,        KC_END,
 KC_PGUP,
 KC_PGDN,KC_ENT, KC_SPC
    ),
/* Keymap 1: QWERTY
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   Q  |   W  |   E  |  R   |  T   |      |           |      |  Y   |   I  |   O  |   U  |   P  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   A  |   S  |   D  |  F   |  G   |------|           |------|  H   |   J  |   K  |   L  |   ;  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   Z  |   X  |   C  |  V   |  B   |      |           |      |  N   |   M  |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |     |       |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// QWERTY
[QWRT] = LAYOUT_ergodox(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_TRNS,
       KC_TRNS, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,
       KC_TRNS, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_Y   , KC_I   , KC_O   , KC_U   , KC_P   , KC_TRNS,
                 KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_TRNS,
       KC_TRNS,  KC_N   , KC_M   , KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Numpad + Mouse
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |   P1 |  P2  |  R1  |  R2  |      |      |           |      |      | NmLck|   /  |   *  |  -   | Calc   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      | MsUp |      |  WHU |      |      |           |      |      |   7  |   8  |   9  |  +   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |MsLeft|MsDown|MsRght| WHD  |      |------|           |------|      |   4  |   5  |   6  |  +   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | Btn1 | Btn3 | Btn2 |      |      |      |           |      |      |   1  |   2  |   3  | Ent  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |   0  |   0  |   .  | Ent  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// NUMPAD
[NMPD] = LAYOUT_ergodox(
       KC_TRNS, DYN_MACRO_PLAY1, DYN_MACRO_PLAY2, DYN_REC_START1, DYN_REC_START2, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_WH_U, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, KC_TRNS,
       KC_TRNS, KC_BTN1, KC_BTN3, KC_BTN2, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, KC_CALC,
       KC_TRNS,  KC_TRNS, KC_P7  , KC_P8  , KC_P9  , KC_PPLS, KC_TRNS,
                 KC_TRNS, KC_P4  , KC_P5  , KC_P6  , KC_PPLS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_P1  , KC_P2  , KC_P3  , KC_PENT, KC_TRNS,
                          KC_P0  , KC_P0  , KC_PDOT, KC_PENT, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS  , KC_TRNS, KC_TRNS
),
/* Keymap 3: Function Keys and Media Keys
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |  TRNS   |  F1  |  F2  |  F3  |  F4  |  F5  | PSCR |           | CAPS |  F6  |  F7  |  F8  |  F9  |  F10 |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |  F11 | F12  |  F13 | F14  | F15  |      |           |      |  F16 | F17  |  F18 | F19  | F20  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |------|           |------| VolD | MUTE | VolU | ThmU |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      | Prev | Play | Next | ThmD |      |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       | Stop |AudSrc|      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      | TNSY |       | TNSY |      |      |
 *                                 `--------------------'       `--------------------'
 */
// Function keys and media keys
[MDIA] = LAYOUT_ergodox(
       // left hand
       KC_TRNS,   KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_PSCR,
       KC_TRNS,  KC_F11, KC_F12, KC_F13, KC_F14, KC_F15,  KC_TRNS,
       KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,  KC_TRNS,
       KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,  RESET,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_TRNS,
       KC_TRNS,KC_F16,  KC_F17, KC_F18,  KC_F19,   KC_F20,  KC_TRNS,
                KC_VOLD, KC_MUTE,KC_VOLU,   THMUP,KC_TRNS,  KC_TRNS,
       KC_TRNS, KC_MPRV, KC_MPLY,KC_MNXT,  THMDWN,KC_TRNS,  KC_TRNS,
                         KC_MSTP, AUDSRC, KC_TRNS,KC_TRNS,  KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       RESET  , KC_TRNS, KC_TRNS
),
/* Keymap 4: Empty layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |      |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |       |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// What
[WHAT] = LAYOUT_ergodox(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_SCLN, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 5: Macro Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      | DIM  |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | SLAP | SDESK| SHRUG| EYES | WHAT |      |           |      | SAFQR|      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MACRO
[MCRO] = LAYOUT_ergodox(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, DIM    , KC_TRNS, KC_TRNS,
       KC_TRNS, SLAPTO , SDESKT , SHRUG1 , EYES   , WHAT1  , KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,          KC_TRNS,         KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,          KC_TRNS,         KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                         KC_TRNS,         KC_TRNS,      KC_TRNS, KC_TRNS, KC_SCLN, KC_TRNS,
       KC_TRNS,            SAFQR,         KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                         KC_TRNS,         KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(MDIA)                // FN1 - Momentary Layer 1 (MEDIA)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
        case 1:
        if (record->event.pressed) { // For resetting EEPROM
          eeconfig_init();
        }
        break;
      }
    return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_dynamic_macro(keycode, record)) {
        return false;
    }
	
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
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
	case SHRUG1:
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
	case WHAT1:
		if (record->event.pressed) {
			SEND_STRING("What the fuck did you just fucking say about me, you little bitch? I'll have you know I graduated top of my class in the Navy Seals, and I've been involved in numerous secret raids on Al-Quaeda, and I have over 300 confirmed kills. I am trained in gorilla warfare and I'm the top sniper in the entire US armed forces. You are nothing to me but just another target. I will wipe you the fuck out with precision the likes of which has never been seen before on this Earth, mark my fucking words. You think you can get away with saying that shit to me over the Internet? Think again, fucker. As we speak I am contacting my secret network of spies across the USA and your IP is being traced right now so you better prepare for the storm, maggot. The storm that wipes out the pathetic little thing you call your life. You're fucking dead, kid. I can be anywhere, anytime, and I can kill you in over seven hundred ways, and that's just with my bare hands. Not only am I extensively trained in unarmed combat, but I have access to the entire arsenal of the United States Marine Corps and I will use it to its full extent to wipe your miserable ass off the face of the continent, you little shit. If only you could have known what unholy retribution your little 'clever' comment was about to bring down upon you, maybe you would have held your fucking tongue. But you couldn't, you didn't, and now you're paying the price, you goddamn idiot. I will shit fury all over you and you will drown in it. You're fucking dead, kiddo.");
		}
	case SDESKT:
		if (record->event.pressed) {
			SEND_STRING(SS_DOWN(X_LCTRL)SS_TAP(X_GRAVE)SS_UP(X_LCTRL));
			SEND_STRING(SS_DOWN(X_LCTRL)SS_UP(X_LCTRL));
		}
	break;
	case SLAPTO:
		if (record->event.pressed) {
			SEND_STRING(SS_DOWN(X_LCTRL)SS_DOWN(X_LALT)SS_TAP(X_GRAVE)SS_UP(X_LCTRL)SS_UP(X_LALT));
			SEND_STRING(SS_DOWN(X_LCTRL)SS_DOWN(X_LALT)SS_UP(X_LCTRL)SS_UP(X_LALT));
		}
	break;
	case SAFQR:
		if (record->event.pressed) {
			SEND_STRING("BEGIN TRAN"SS_TAP(X_ENTER)SS_TAP(X_ENTER)"ROLLBACK TRAN"SS_TAP(X_UP));
		}
	break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
