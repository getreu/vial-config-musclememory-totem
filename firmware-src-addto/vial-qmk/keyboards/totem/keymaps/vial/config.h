// Copyright 2022 GEIST @geigeigeist
// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

// Generate this line with:
//     python3 util/vial_generate_keyboard_uid.py
#define VIAL_KEYBOARD_UID {0x80, 0xD7, 0x5F, 0xD9, 0x25, 0x60, 0xAB, 0x3A}

#define VIAL_UNLOCK_COMBO_ROWS \
    { 0, 4 }
#define VIAL_UNLOCK_COMBO_COLS \
    { 0, 0 }

// Vial dynamic combo + tap-dance support (muscle memory layout defaults are
// loaded in eeconfig_init_user()).
#define VIAL_COMBO_ENABLE
#define VIAL_TAP_DANCE_ENABLE
#define VIAL_TAP_DANCE_ENTRIES 10
#define VIAL_COMBO_ENTRIES 12

// #define TAPPING_TERM 170
#define TAPPING_TERM 170

// Short combo window so combo-member keys (e.g. TD(0), the right outer thumb,
// used by the OSL(_L4)+TD(0) CapsLock combo) are not buffered long enough to
// break their tap-dance double-tap. Defaults to TAPPING_TERM (170) otherwise.
#define COMBO_TERM 50

// Auto Shift
#define NO_AUTO_SHIFT_ALPHA
#define AUTO_SHIFT_TIMEOUT TAPPING_TERM

#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

// Mousekey acceleration tuning, ported from
// qmk-firmware-musclememory-cheapinov2 keyboards/cheapino/config.h. QMK's
// defaults (MOVE_DELTA=8, TIME_TO_MAX=30) ramp to max speed almost
// immediately; these values give a finer, slower ramp.
#ifdef MOUSEKEY_ENABLE
    #undef MOUSEKEY_INTERVAL
    #define MOUSEKEY_INTERVAL 16

    #undef MOUSEKEY_INITIAL_SPEED
    #define MOUSEKEY_INITIAL_SPEED 2

    #undef MOUSEKEY_MOVE_DELTA
    #define MOUSEKEY_MOVE_DELTA 1

    #undef MOUSEKEY_MAX_SPEED
    #define MOUSEKEY_MAX_SPEED 14

    #undef MOUSEKEY_TIME_TO_MAX
    #define MOUSEKEY_TIME_TO_MAX 100
#endif

#define DYNAMIC_KEYMAP_LAYER_COUNT 16

