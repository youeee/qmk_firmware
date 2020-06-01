/* Copyright 2018 Jack Humbert
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

#define _BASE 0
#define _FN1 1
#define _FN2 2
#define _FN9_TOGGLE 9

enum custom_keycodes {
  TESTASYNC = SAFE_RANGE,
  TESTSYNC,
  GIT_STATUS,
  GIT_LOG,
  GIT_ADD_ALL,
  GIT_COMMIT,
  GIT_PULL,
  GIT_STASH,
  GIT_STASH_POP,
  GIT_STASH_LIST,
  GIT_PUSH
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case TESTASYNC:
      if (record->event.pressed) {
        // when keycode TESTASYNC is pressed
        SEND_STRING("[Fact]\r\npublic async Task Test()\r\n{\r\n\t// Arrange \r\n\r\n\t// Act \r\n\r\n\t// Assert \r\n\r\n\r\n");
        SEND_STRING(SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP));
        SEND_STRING(SS_TAP(X_RIGHT)SS_TAP(X_RIGHT)SS_TAP(X_RIGHT)SS_TAP(X_RIGHT)SS_TAP(X_RIGHT)SS_TAP(X_RIGHT)SS_TAP(X_RIGHT)SS_TAP(X_RIGHT)SS_TAP(X_RIGHT)SS_TAP(X_RIGHT)SS_TAP(X_RIGHT)SS_TAP(X_RIGHT)SS_TAP(X_RIGHT)SS_TAP(X_RIGHT)SS_TAP(X_RIGHT)SS_TAP(X_RIGHT)SS_TAP(X_RIGHT)SS_TAP(X_RIGHT));
      } else {
        // when keycode TESTASYNC is released
      }
      break;
    case TESTSYNC:
      if (record->event.pressed) {
        // when keycode TESTSYNC is pressed
        SEND_STRING("[Fact]\r\npublic void Test()\r\n{\r\n\t// Arrange \r\n\r\n\t// Act \r\n\r\n\t// Assert \r\n\r\n\r\n");
        SEND_STRING(SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP));
        SEND_STRING(SS_TAP(X_RIGHT)SS_TAP(X_RIGHT)SS_TAP(X_RIGHT)SS_TAP(X_RIGHT)SS_TAP(X_RIGHT)SS_TAP(X_RIGHT)SS_TAP(X_RIGHT)SS_TAP(X_RIGHT)SS_TAP(X_RIGHT)SS_TAP(X_RIGHT)SS_TAP(X_RIGHT)SS_TAP(X_RIGHT));
      } else {
        // when keycode TESTSYNC is released
      }
      break;
      
 case GIT_STATUS:
        if (record->event.pressed) {
          // when keycode TESTSYNC is pressed
          SEND_STRING("git status\r\n");
        } else {
          // when keycode TESTSYNC is released
        }
        break;
    case GIT_LOG:
        if (record->event.pressed) {
          // when keycode TESTSYNC is pressed
          SEND_STRING("git log\r\n");
        } else {
          // when keycode TESTSYNC is released
        }
        break;
    case GIT_ADD_ALL:
        if (record->event.pressed) {
          // when keycode TESTSYNC is pressed
          SEND_STRING("git add --all");
        } else {
          // when keycode TESTSYNC is released
        }
        break;
    case GIT_COMMIT:
        if (record->event.pressed) {
          // when keycode TESTSYNC is pressed
          SEND_STRING("git commit -m \"");
        } else {
          // when keycode TESTSYNC is released
        }
        break;
    case GIT_PULL:
        if (record->event.pressed) {
          // when keycode TESTSYNC is pressed
          SEND_STRING("git pull --rebase");
        } else {
          // when keycode TESTSYNC is released
        }
        break;
    case GIT_STASH:
        if (record->event.pressed) {
          // when keycode TESTSYNC is pressed
          SEND_STRING("git stash");
        } else {
          // when keycode TESTSYNC is released
        }
        break;
    case GIT_STASH_POP:
        if (record->event.pressed) {
          // when keycode TESTSYNC is pressed
          SEND_STRING("git stash pop");
        } else {
          // when keycode TESTSYNC is released
        }
        break;
    case GIT_STASH_LIST:
        if (record->event.pressed) {
          // when keycode TESTSYNC is pressed
          SEND_STRING("git stash list\r\n");
        } else {
          // when keycode TESTSYNC is released
        }
        break;
    case GIT_PUSH:
        if (record->event.pressed) {
          // when keycode TESTSYNC is pressed
          SEND_STRING("git push");
        } else {
          // when keycode TESTSYNC is released
        }
        break;
     }
  return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_BASE] = LAYOUT(
		TESTSYNC, TESTASYNC, KC_1, \
		KC_4, KC_5, KC_6, \
		KC_A, KC_2, KC_3, \
		OSL(9), TO(1), KC_ENT \
	),
  
	[_FN1] = LAYOUT(
		KC_TRNS, KC_HOME, KC_PGUP, \
		KC_TRNS, KC_END, KC_PGDN, \
		KC_TRNS, KC_B, KC_TRNS, \
		OSL(9), TO(2), KC_ENT \
	),
  [_FN2] = LAYOUT(
		GIT_STATUS, GIT_LOG, KC_PGUP, \
		GIT_ADD_ALL, GIT_COMMIT, GIT_PULL, \
		GIT_STASH, GIT_STASH_POP, GIT_STASH_LIST, \
		OSL(9), GIT_PUSH, KC_ENT \
	),
  [_FN9_TOGGLE] = LAYOUT(
		KC_TRNS, KC_TRNS, KC_TRNS, \
		KC_TRNS, KC_TRNS, KC_TRNS, \
		KC_TRNS, TO(2), KC_TRNS, \
		KC_TRNS, TO(0), TO(1) \
	)
};