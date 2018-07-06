#include "bananasplit.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h" 
//Norman layout with Qwerty Switch and Function Layer

/*enum {
  TD_QUPE
};
qk_tap_dance_action_t tap_dance_actions[] = {
	[TD_QUPE] = ACTION_TAP_DANCE_DOUBLE(KC_QUES, KC_PERC)
};*/

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
  TGCP
};
enum {
  TD_QUPE = 0
};

qk_tap_dance_action_t tap_dance_actions[] = {
        [TD_QUPE] = ACTION_TAP_DANCE_DOUBLE(KC_QUES, KC_PERC)
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

//Emoji requires wincompose to be installed


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	/*
	-------------------------------------------------------------------------------------------
	| Esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  | F5 |TO-L2 |
	-------------------------------------------------------------------------------------------
	|  Tab   |  Q  |  W  |  D  |  F  | K  |  J  |  U  |  R  |  L  |  ;  |  [  |  ]  |    \    |
	-------------------------------------------------------------------------------------------
	|  Shift  |  A  |  S  |  E  |  T  |  G  |  Y  |  N  |  I  |  O  |  H  |  '  |    Enter    |
	-------------------------------------------------------------------------------------------
	|    Ctrl     |  Z  |  X  |  C  |  V  |  B  |  P  |  M  |  ,  |  .  |    /   |  Up  | ?   |
	-------------------------------------------------------------------------------------------
	|   `   |  WIN  |  Alt  |  Backspace | KPir |   Space    | OSL-L1|  Left |  Down |  Right |
	-------------------------------------------------------------------------------------------
	*/
	[0] = KEYMAP( \
		KC_ESC , KC_1,    KC_2,    KC_3, KC_4,   KC_5,  KC_6,   KC_7, KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_F5,   TO(1), \
		KC_TAB,  KC_Q,    KC_W,    KC_D, KC_F,   KC_K,  KC_J,   KC_U, KC_R,    KC_L,    KC_SCLN, KC_LBRC, KC_RBRC, KC_BSLS, \
		KC_LSFT, KC_A,    KC_S,    KC_E, KC_T,   KC_G,  KC_Y,   KC_N, KC_I,    KC_O,    KC_H,    KC_QUOT, KC_ENT, \
		KC_LCTL,          KC_Z,    KC_X, KC_C,   KC_V,  KC_B,   KC_P, KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_UP,   KC_QUES,\
		KC_PERC,  KC_LGUI, KC_LALT,       KC_BSPC,       KPIR,   KC_SPC,        LT(2, KC_GRV),           KC_LEFT, KC_DOWN, KC_RGHT\
	),
	/*
	-------------------------------------------------------------------------------------------
	|Flash| F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 | F11 | F12 |MoveL|MoveR|
	-------------------------------------------------------------------------------------------
	|  Tab   |VolDn| Mute|VolUp|AVLD |AVLM|AVLU |CLAP |TADA |CALL | EYES| BEAR|LENNY| PrtScrn |
	-------------------------------------------------------------------------------------------
	|  Shift  | Prev| Play| Next| WINT| WAOT|TGCP |FIRE |THNK |CRYL | SKLL|TG-L3|   KpEnter   |
	-------------------------------------------------------------------------------------------
	|    Ctrl     | AXIN| Stop| Cn75| CnMs|LKTW |TSMN |OKAY |THDN |THUP |  SfTr  | PgUp |Home |
	-------------------------------------------------------------------------------------------
	|  Dim  |  WIN  |  Alt  |    LpTp    |  SHRG |    Desk    | Mini  | TRNS  | PgDwn |  End  |
	-------------------------------------------------------------------------------------------
	*/
	[2] = KEYMAP( \
		RESET,   KC_F1,   KC_F2,   KC_F3,  KC_F4,  KC_F5,  KC_F6, KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  MOVEL,   MOVER, \
		KC_DEL,  KC_VOLD, KC_MUTE, KC_VOLU,AVLD,   AVLM,    AVLU, CLAP,   TADA,    CALL, EYES,    BEAR,    LENNY,   KC_PSCR, \
		KC_LSFT, KC_MPRV, KC_MPLY, KC_MNXT,WINT,   WAOT,    TGCP, FIRE,   THNK,    CRYL, SKLL,    TG(3), KC_PENT, \
		KC_LCTL,          AXIN,    KC_MSTP,CN75,   CNMS,   LKTW,  TSMN,   OKAY,    THDN, THUP, SFTR,    KC_PGUP, KC_HOME,\
		DIM,     KC_LGUI, KC_LALT,         LPTP,           SHRG,  DESK,            KC_TRNS,             MINI,    KC_PGDN, KC_END\
	),
	/*
	-------------------------------------------------------------------------------------------
	| Esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  | F5 |TO-L0 |
	-------------------------------------------------------------------------------------------
	|  Tab   |  Q  |  W  |  E  |  R  | T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |    \    |
	-------------------------------------------------------------------------------------------
	|  Shift  |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter    |
	-------------------------------------------------------------------------------------------
	|    Ctrl     |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |    /   |  Up  | ?   |
	-------------------------------------------------------------------------------------------
	|   `   |  WIN  |  Alt  |  Backspace |  KPIR  |   Space    | OSL-L1|  Left | Down | Right |
	-------------------------------------------------------------------------------------------
	*/
	[1] = KEYMAP( \
		KC_ESC , KC_1,    KC_2,    KC_3, KC_4,   KC_5,  KC_6,   KC_7, KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_F5,   TO(0), \
		KC_TAB,  KC_Q,    KC_W,    KC_E, KC_R,   KC_T,  KC_Y,   KC_U, KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, \
		KC_LSFT, KC_A,    KC_S,    KC_D, KC_F,   KC_G,  KC_H,   KC_J, KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT, \
		KC_LCTL,          KC_Z,    KC_X, KC_C,   KC_V,  KC_B,   KC_N, KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_UP,   KC_QUES,\
		KC_PERC,  KC_LGUI, KC_LALT,       KC_BSPC,       KPIR,   KC_SPC,        LT(2, KC_GRV),           KC_LEFT, KC_DOWN, KC_RGHT\
	),
        /*
        -------------------------------------------------------------------------------------------
        |     |     |     |     |     |     |     |     |     |     |     |     |     |    |      |
        -------------------------------------------------------------------------------------------
        |        |     |     |     |     |    |     |     |     |     |     |     |     |         |
        -------------------------------------------------------------------------------------------
        |         |     |     |     |     |     |     |     |     |     |     |     |             |
        -------------------------------------------------------------------------------------------
        |             |     |     |     |     |     |     |     |     |     |        |      |     |
        -------------------------------------------------------------------------------------------
        |       |       |       |    Space   |        |  Backspace |       |       |      |       |
        -------------------------------------------------------------------------------------------
        */
        [3] = KEYMAP( \
                KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,   KC_TRNS,  KC_TRNS,   KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,  KC_TRNS,   KC_TRNS, \
                KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,   KC_TRNS,  KC_TRNS,   KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, \
                KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,   KC_TRNS,  KC_TRNS,   KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS, \
                KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,   KC_TRNS,  KC_TRNS,   KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,\
                KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_SPC , KC_TRNS,   KC_BSPC,  KC_TRNS,   KC_TRNS, KC_TRNS,    KC_TRNS\
        ),
};

const uint16_t PROGMEM fn_actions[] = {
};
