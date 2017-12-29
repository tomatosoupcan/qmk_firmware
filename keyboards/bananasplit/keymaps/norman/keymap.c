#include "bananasplit.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h" 
//Norman layout with Qwerty Switch and Function Layer

enum {
  TD_QUPE
};
qk_tap_dance_action_t tap_dance_actions[] = {
	[TD_QUPE] = ACTION_TAP_DANCE_DOUBLE(KC_QUES, KC_PERC)
};

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
  ENDC
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
			SEND_STRING(SS_DOWN(X_LCTRL)SS_TAP(X_GRAVE)SS_UP(X_LCTRL));
			SEND_STRING(SS_DOWN(X_LCTRL)SS_UP(X_LCTRL));
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
			SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_KP_PLUS)SS_TAP(X_KP_0)SS_TAP(X_KP_3)SS_TAP(X_KP_6)SS_TAP(X_KP_1)SS_UP(X_LALT)); //eyebrow
			SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_KP_PLUS)SS_TAP(X_KP_0)SS_TAP(X_KP_0)SS_TAP(X_B)SS_TAP(X_KP_0)SS_UP(X_LALT)); //eye
			SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_KP_PLUS)SS_TAP(X_KP_0)SS_TAP(X_KP_3)SS_TAP(X_KP_5)SS_TAP(X_C)SS_UP(X_LALT)); //mouth
			SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_KP_PLUS)SS_TAP(X_KP_0)SS_TAP(X_KP_2)SS_TAP(X_KP_9)SS_TAP(X_KP_6)SS_UP(X_LALT)); //nose
			SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_KP_PLUS)SS_TAP(X_KP_0)SS_TAP(X_KP_3)SS_TAP(X_KP_6)SS_TAP(X_KP_1)SS_UP(X_LALT)); //eyebrow
			SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_KP_PLUS)SS_TAP(X_KP_0)SS_TAP(X_KP_0)SS_TAP(X_B)SS_TAP(X_KP_0)SS_UP(X_LALT)); //eye
			SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_KP_PLUS)SS_TAP(X_KP_0)SS_TAP(X_KP_0)SS_TAP(X_KP_2)SS_TAP(X_KP_9)SS_UP(X_LALT)); //right parenthesis			
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
#define CN75 LCTL(LGUI(KC_S))
#define CNMS LCTL(LSFT(KC_1))
#define DIM LCTL(LSFT(KC_0))
#define STDC LCTL(KC_HOME)
#define ENDC LCTL(KC_END)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	/*
	-------------------------------------------------------------------------------------------
	| Esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  | F5 |TO-L2 |
	-------------------------------------------------------------------------------------------
	|  Tab   |  Q  |  W  |  D  |  F  | K  |  J  |  U  |  R  |  L  |  ;  |  [  |  ]  |    \    |
	-------------------------------------------------------------------------------------------
	|  Shift  |  A  |  S  |  E  |  T  |  G  |  Y  |  N  |  I  |  O  |  H  |  '  |    Enter    |
	-------------------------------------------------------------------------------------------
	|    Ctrl     |  Z  |  X  |  C  |  V  |  B  |  P  |  M  |  ,  |  .  |    /   |  Up  | ?/% |
	-------------------------------------------------------------------------------------------
	|   `   |  WIN  |  Alt  |  Backspace | KPir |   Space    | OSL-L1|  Left |  Down |  Right |
	-------------------------------------------------------------------------------------------
	*/
	[0] = KEYMAP( \
		KC_ESC , KC_1,    KC_2,    KC_3, KC_4,   KC_5,  KC_6,   KC_7, KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_F5,   TO(2), \
		KC_TAB,  KC_Q,    KC_W,    KC_D, KC_F,   KC_K,  KC_J,   KC_U, KC_R,    KC_L,    KC_SCLN, KC_LBRC, KC_RBRC, KC_BSLS, \
		KC_LSFT, KC_A,    KC_S,    KC_E, KC_T,   KC_G,  KC_Y,   KC_N, KC_I,    KC_O,    KC_H,    KC_QUOT, KC_ENT, \
		KC_LCTL,          KC_Z,    KC_X, KC_C,   KC_V,  KC_B,   KC_P, KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_UP,   TD_QUPE,\
		KC_GRV,  KC_LGUI, KC_LALT,       KC_BSPC,       KPIR,   KC_SPC,        OSL(1),           KC_LEFT, KC_DOWN, KC_RGHT\
	),
	/*
	-------------------------------------------------------------------------------------------
	|Flash| F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 | F11 | F12 |MoveL|MoveR|
	-------------------------------------------------------------------------------------------
	|  Tab   |VolDn| Mute|VolUp|NmLk | Kp/| Kp7 | Kp8 | Kp9 | Kp- | EYES| BEAR|LENNY| PrtScrn |
	-------------------------------------------------------------------------------------------
	|  Shift  | Prev| Play| Next| WINT| Kp* | Kp4 | Kp5 | Kp6 | Kp+ | CALC| MYCM|   KpEnter   |
	-------------------------------------------------------------------------------------------
	|    Ctrl     | AXIN| Stop| Cn75| CnMs| Kp0 | Kp1 | Kp2 | Kp3 | Kp. |  SfTr  | PgUp |Home |
	-------------------------------------------------------------------------------------------
	|  Dim  |  WIN  |  Alt  |    LpTp    |  SHRG |    Desk    | StDc  | EnDc  | PgDwn |  End  |
	-------------------------------------------------------------------------------------------
	*/
	[1] = KEYMAP( \
		RESET,   KC_F1,   KC_F2,   KC_F3,  KC_F4,  KC_F5,  KC_F6, KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  MOVEL,   MOVER, \
		KC_TAB,  KC_VOLD, KC_MUTE, KC_VOLU,KC_NLCK,KC_PSLS,KC_P7, KC_P8,  KC_P9,   KC_PMNS, EYES,    BEAR,    LENNY,   KC_PSCR, \
		KC_LSFT, KC_MPRV, KC_MPLY, KC_MNXT,WINT,   KC_PAST,KC_P4, KC_P5,  KC_P6,   KC_PPLS, KC_CALC, KC_MYCM, KC_PENT, \
		KC_LCTL,          AXIN,    KC_MSTP,CN75,   CNMS,   KC_P0, KC_P1,  KC_P2,   KC_P3,   KC_PDOT, SFTR,    KC_PGUP, KC_HOME,\
		DIM,     KC_LGUI, KC_LALT,         LPTP,           SHRG,  DESK,            STDC,             ENDC,    KC_PGDN, KC_END\
	),
	/*
	-------------------------------------------------------------------------------------------
	| Esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  | F5 |TO-L0 |
	-------------------------------------------------------------------------------------------
	|  Tab   |  Q  |  W  |  E  |  R  | T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |    \    |
	-------------------------------------------------------------------------------------------
	|  Shift  |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter    |
	-------------------------------------------------------------------------------------------
	|    Ctrl     |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |    /   |  Up  | ?/% |
	-------------------------------------------------------------------------------------------
	|   `   |  WIN  |  Alt  |  Backspace |  KPIR  |   Space    | OSL-L1|  Left | Down | Right |
	-------------------------------------------------------------------------------------------
	*/
	[2] = KEYMAP( \
		KC_ESC , KC_1,    KC_2,    KC_3, KC_4,   KC_5,  KC_6,   KC_7, KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_F5,   TO(0), \
		KC_TAB,  KC_Q,    KC_W,    KC_E, KC_R,   KC_T,  KC_Y,   KC_U, KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, \
		KC_LSFT, KC_A,    KC_S,    KC_D, KC_F,   KC_G,  KC_H,   KC_J, KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT, \
		KC_LCTL,          KC_Z,    KC_X, KC_C,   KC_V,  KC_B,   KC_N, KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_UP,   TD_QUPE,\
		KC_GRV,  KC_LGUI, KC_LALT,       KC_BSPC,       KPIR,   KC_SPC,        OSL(1),           KC_LEFT, KC_DOWN, KC_RGHT\
	),
};

const uint16_t PROGMEM fn_actions[] = {
};
