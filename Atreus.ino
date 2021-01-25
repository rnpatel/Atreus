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
#include "Kaleidoscope-Macros.h"

#define MO(n) ShiftToLayer(n)
#define TG(n) LockLayer(n)
#define ML(n) MoveToLayer(n)

#define CH_HYPER LSHIFT(LALT(LGUI(Key_LeftControl)))
#define CH_MEH   LSHIFT(LALT(Key_LeftGui))

enum {
  MACRO_QWERTY,
  MACRO_VERSION_INFO
};

#define Key_Bang    LSHIFT(Key_1)
#define Key_At      LSHIFT(Key_2)
#define Key_Hash    LSHIFT(Key_3)
#define Key_Dollar  LSHIFT(Key_4)
#define Key_Percent LSHIFT(Key_5)
#define Key_Caret   LSHIFT(Key_6)
#define Key_And     LSHIFT(Key_7)
#define Key_Star    LSHIFT(Key_8)
#define Key_Plus    LSHIFT(Key_Equals)

enum {
  QWERTY,
  FUN,
  NUM
};

enum {
    TDLB,
    TDRB,
    TDME
};


/* *INDENT-OFF* */
KEYMAPS(
    /* QWERTY
     * ┌───────┬───────┬───────┬───────┬───────┐                        ┌───────┬───────┬───────┬───────┬───────┐
     * │   Q   │   W   │   E   │   R   │   T   │                        │   Y   │   U   │   I   │   O   │   P   │
     * ├───────┼───────┼───────┼───────┼───────┤                        ├───────┼───────┼───────┼───────┼───────┤
     * │  ⇧•A  │  ^•S  │  ⌘•D  │  ⌥•F  │   G   │                        │   H   │  ⌥•J  │  ⌘•K  │  ^•L  │  ⇧•;  │
     * ├───────┼───────┼───────┼───────┼───────┼───────┐        ┌───────┼───────┼───────┼───────┼───────┼───────┤
     * │   Z   │   X   │   C   │   V   │   B   │  ⇧•⇥  │        │  RET  │   N   │   M   │   ,   │   .   │   /   │
     * ├───────┼───────┼───────┼───────┼───────┼───────┤        ├───────┼───────┼───────┼───────┼───────┼───────┤
     * │ FUN•` │  ESC  │  Ins  │ BKSPC │ (→[→{ │  MEH  │        │ HYPER │ )→]→} │  SPC  │   \   │ - → = │ NUM•' │
     * └───────┴───────┴───────┴───────┴───────┴───────┘        └───────┴───────┴───────┴───────┴───────┴───────┘
     */
    [QWERTY] = KEYMAP_STACKED
    (
        //
        // left hand
        //
        Key_Q,             Key_W,       Key_E,       Key_R,          Key_T,     /*-----*/
        SFT_T(A),          CTL_T(S),    GUI_T(D),    ALT_T(F),       Key_G,     /*-----*/
        Key_Z,             Key_X,       Key_C,       Key_V,          Key_B,     SFT_T(Tab),
        LT(FUN,Backtick),  Key_Escape,  Key_Insert,  Key_Backspace,  TD(TDLB),  CH_MEH,

        //
        // right hand
        //
        /*-----*/   Key_Y,     Key_U,      Key_I,          Key_O,       Key_P,
        /*-----*/   Key_H,     ALT_T(J),   GUI_T(K),       CTL_T(L),    SFT_T(Semicolon),
        Key_Enter,  Key_N,     Key_M,      Key_Comma,      Key_Period,  Key_Slash,
        CH_HYPER,   TD(TDRB),  Key_Space,  Key_Backslash,  TD(TDME),    LT(NUM,Quote)
    ),

    /* FUN
     * ┌───────┬───────┬───────┬───────┬───────┐                        ┌───────┬───────┬───────┬───────┬───────┐
     * │  F1   │  F2   │  F3   │  F4   │  F5   │                        │  F6   │  F7   │  F8   │  F9   │  F10  │
     * ├───────┼───────┼───────┼───────┼───────┤                        ├───────┼───────┼───────┼───────┼───────┤
     * │  F11  │  F12  │       │       │       │                        │ VOLX  │       │   ↑   │       │   ⌘   │
     * ├───────┼───────┼───────┼───────┼───────┼───────┐        ┌───────┼───────┼───────┼───────┼───────┼───────┤
     * │       │       │       │       │       │   ⇧   │        │       │ VOL↑  │   ←   │   ↓   │   →   │   ⌥   │
     * ├───────┼───────┼───────┼───────┼───────┼───────┤        ├───────┼───────┼───────┼───────┼───────┼───────┤
     * │       │       │       │       │       │       │        │       │ VOL↓  │  <<   │  ||   │  >>   │       │
     * └───────┴───────┴───────┴───────┴───────┴───────┘        └───────┴───────┴───────┴───────┴───────┴───────┘
     */
    [FUN] = KEYMAP_STACKED
    (
        //
        // left hand
        //
        Key_F1,   Key_F2,   Key_F3,  Key_F4,         Key_F5,  /*-----*/
        Key_F11,  Key_F12,  XXX,     XXX,            XXX,     /*-----*/
        XXX,      XXX,      XXX,     XXX,            XXX,     Key_LeftShift,
        ___,      ___,      XXX,     Key_Backspace,  XXX,     XXX,

        //
        // right hand
        //
        /*-----*/  Key_F6,                    Key_F7,                      Key_F8,                   Key_F9,                  Key_F10,
        /*-----*/  Consumer_Mute,             XXX,                         Key_UpArrow,              XXX,                     Key_LeftGui,
        ___,       Consumer_VolumeIncrement,  Key_LeftArrow,               Key_DownArrow,            Key_RightArrow,          Key_LeftAlt,
        XXX,       Consumer_VolumeDecrement,  Consumer_ScanPreviousTrack,  Consumer_PlaySlashPause,  Consumer_ScanNextTrack,  ___
    ),

    /* NUM
     * ┌───────┬───────┬───────┬───────┬───────┐                        ┌───────┬───────┬───────┬───────┬───────┐
     * │   1   │   2   │   3   │   4   │   5   │                        │   6   │   7   │   8   │   9   │   0   │
     * ├───────┼───────┼───────┼───────┼───────┤                        ├───────┼───────┼───────┼───────┼───────┤
     * │   !   │   @   │   #   │   $   │   %   │                        │   ^   │   &   │   *   │   (   │   )   │
     * ├───────┼───────┼───────┼───────┼───────┼───────┐        ┌───────┼───────┼───────┼───────┼───────┼───────┤
     * │   =   │       │       │       │       │  PgUP │        │ HOME  │ VOL↑  │   ←   │   ↓   │   →   │   ⌥   │
     * ├───────┼───────┼───────┼───────┼───────┼───────┤        ├───────┼───────┼───────┼───────┼───────┼───────┤
     * │   +   │       │       │       │       │  PgDN │        │  END  │ VOL↓  │  <<   │  ||   │  >>   │       │
     * └───────┴───────┴───────┴───────┴───────┴───────┘        └───────┴───────┴───────┴───────┴───────┴───────┘
     */
    [NUM] = KEYMAP_STACKED
    (
        //
        // left hand
        //
        Key_1,       Key_2,   Key_3,     Key_4,       Key_5,        /*-----*/
        Key_Bang,    Key_At,  Key_Hash,  Key_Dollar,  Key_Percent,  /*-----*/
        Key_Equals,  XXX,     XXX,       XXX,         XXX,          Key_PageUp,
        Key_Plus,    ___,     XXX,       XXX,         XXX,          Key_PageDown,

        //
        // right hand
        //
        /*-----*/  Key_6,      Key_7,    Key_8,     Key_9,          Key_0,
        /*-----*/  Key_Caret,  Key_And,  Key_Star,  Key_LeftParen,  Key_RightParen,
        Key_Home,  XXX,        XXX,      XXX,       XXX,            XXX,
        Key_End,   XXX,        XXX,      XXX,       XXX,            ___
    )
)
/* *INDENT-ON* */

KALEIDOSCOPE_INIT_PLUGINS(
  Qukeys,
  OneShot,
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

void tapDanceAction(uint8_t tap_dance_index, KeyAddr key_addr, uint8_t tap_count,
                    kaleidoscope::plugin::TapDance::ActionType tap_dance_action)
{
    switch (tap_dance_index)
    {
        case TDLB:
            return tapDanceActionKeys(tap_count, tap_dance_action,
                                      Key_LeftParen, Key_LeftBracket, Key_LeftCurlyBracket);
            break;
        case TDRB:
            return tapDanceActionKeys(tap_count, tap_dance_action,
                                      Key_RightParen, Key_RightBracket, Key_RightCurlyBracket);
            break;
        case TDME:
            return tapDanceActionKeys(tap_count, tap_dance_action,
                                      Key_Minus, Key_Equals);
            break;
    }
}
