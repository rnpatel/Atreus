/* -*- mode: c++ -*-
 * Atreus -- Chrysalis-enabled Sketch for the Keyboardio Atreus
 * Copyright (C) 2018, 2019  Keyboard.io, Inc
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef BUILD_INFORMATION
#define BUILD_INFORMATION "locally built"
#endif

#include "Kaleidoscope.h"
#include "Kaleidoscope-Qukeys.h"
#include "Kaleidoscope-OneShot.h"
#include "Kaleidoscope-TapDance.h"
#include "Kaleidoscope-TopsyTurvy.h"
#include "Kaleidoscope-Macros.h"

#define MO(n) ShiftToLayer(n)
#define TG(n) LockLayer(n)

#define KEYCHORD_HYPER LSHIFT(LALT(LGUI(Key_LeftControl)))
#define KEYCHORD_MEH   LSHIFT(LALT(Key_LeftGui))

enum {
  MACRO_QWERTY,
  MACRO_VERSION_INFO
};

#define Key_Exclamation LSHIFT(Key_1)
#define Key_At          LSHIFT(Key_2)
#define Key_Hash        LSHIFT(Key_3)
#define Key_Dollar      LSHIFT(Key_4)
#define Key_Percent     LSHIFT(Key_5)
#define Key_Caret       LSHIFT(Key_6)
#define Key_And         LSHIFT(Key_7)
#define Key_Star        LSHIFT(Key_8)
#define Key_Plus        LSHIFT(Key_Equals)

enum {
  QWERTY,
  FUN,
  UPPER
};

enum { TAPDANCE_LEFT_BRACKET,
       TAPDANCE_RIGHT_BRACKET };


/* *INDENT-OFF* */
KEYMAPS(
    [QWERTY] = KEYMAP_STACKED
    (
        //
        // left hand
        //
        Key_Q,   Key_W,         Key_E,            Key_R,        Key_T,
        Key_A,   SFT_T(S),      CTL_T(D),         GUI_T(F),     ALT_T(G),
        Key_Z,   Key_X,         Key_C,            Key_V,        Key_B,        SFT_T(Tab),
        MO(FUN), Key_Escape,    Key_Backspace,    Key_Space,    KEYCHORD_MEH, TD(TAPDANCE_LEFT_BRACKET),

        //
        // right hand
        //
        /*-----*/                   Key_Y,             Key_U,        Key_I,            Key_O,         Key_P,
        /*-----*/                   ALT_T(H),          GUI_T(J),     CTL_T(K),         SFT_T(L),      Key_Semicolon,
        Key_Enter,                  Key_N,             Key_M,        Key_Comma,        Key_Period,    Key_Slash,
        TD(TAPDANCE_RIGHT_BRACKET), KEYCHORD_HYPER,    Key_Space,    Key_Backslash,    Key_Minus,     MO(UPPER)
    ),

    [FUN] = KEYMAP_STACKED
    (
        //
        // left hand
        //
        Key_F1, Key_F2,  Key_F3,  Key_F4,        ___,
        Key_F5, Key_F6,  Key_F7,  Key_F8,        ___,
        Key_F9, Key_F19, Key_F11, Key_F12,       ___, ___,
        ___,    ___,     ___,     Key_Backspace, ___, ___,

        //
        // right hand
        //
        /*-----*/ Consumer_Mute,            ___,                        Key_UpArrow,             Key_LeftShift,          Key_LeftControl,
        /*-----*/ Consumer_VolumeIncrement, Key_LeftArrow,              Key_DownArrow,           Key_RightArrow,         Key_LeftGui,
        ___,      Consumer_VolumeDecrement, Consumer_ScanPreviousTrack, Consumer_PlaySlashPause, Consumer_ScanNextTrack, Key_LeftAlt,
        ___,      ___,                      Key_Backspace,              ___,                     ___,                    ___
    ),

    [UPPER] = KEYMAP_STACKED
    (
        //
        // left hand
        //
        ___,          Key_And,         Key_Star,    Key_Plus,    ___,
        Key_PageUp,   Key_Dollar,      Key_Percent, Key_Caret,   ___,
        Key_PageDown, Key_Exclamation, Key_At,      Key_Hash,    ___, ___,
        ___,          ___,             ___,         ___,         ___, ___,

        //
        // right hand
        //
        /*-----*/ ___,  Key_7, Key_8, Key_9, ___,
        /*-----*/ ___,  Key_4, Key_5, Key_6, Key_Home,
        ___,      ___,  Key_1, Key_2, Key_3, Key_End,
        ___,      ___,  ___,   Key_0, ___,   ___
    )
)
/* *INDENT-ON* */

KALEIDOSCOPE_INIT_PLUGINS(
  Qukeys,
  OneShot,
  TopsyTurvy,
  TapDance,
  Macros
);

const macro_t *macroAction(uint8_t macroIndex, uint8_t keyState) {
  switch (macroIndex) {
  case MACRO_QWERTY:
    // This macro is currently unused, but is kept around for compatibility
    // reasons. We used to use it in place of `MoveToLayer(QWERTY)`, but no
    // longer do. We keep it so that if someone still has the old layout with
    // the macro in EEPROM, it will keep working after a firmware update.
    Layer.move(QWERTY);
    break;
  case MACRO_VERSION_INFO:
    if (keyToggledOn(keyState)) {
      Macros.type(PSTR("Keyboardio Atreus - Kaleidoscope "));
      Macros.type(PSTR(BUILD_INFORMATION));
    }
    break;
  default:
    break;
  }

  return MACRO_NONE;
}

void setup() {
  Kaleidoscope.setup();
}

void loop() {
  Kaleidoscope.loop();
}

void tapDanceAction(uint8_t tap_dance_index, byte row, byte col, uint8_t tap_count,
                    kaleidoscope::plugin::TapDance::ActionType tap_dance_action)
{
    switch (tap_dance_index)
    {
        case TAPDANCE_LEFT_BRACKET:
            return tapDanceActionKeys(tap_count, tap_dance_action,
                                      TOPSY(9), Key_LeftBracket, Key_LeftCurlyBracket);
            break;
        case TAPDANCE_RIGHT_BRACKET:
            return tapDanceActionKeys(tap_count, tap_dance_action,
                                      TOPSY(0), Key_RightBracket, Key_RightCurlyBracket);
            break;
    }
}
