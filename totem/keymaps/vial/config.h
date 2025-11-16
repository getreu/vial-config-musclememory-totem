// Copyright 2022 GEIST @geigeigeist
// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

#define VIAL_KEYBOARD_UID {0x62, 0xDB, 0xC0, 0x05, 0x7F, 0x34, 0xDD, 0x20}

#define VIAL_UNLOCK_COMBO_ROWS \
    { 0, 4 }
#define VIAL_UNLOCK_COMBO_COLS \
    { 0, 0 }

// #define TAPPING_TERM 170
#define TAPPING_TERM 170

// Auto Shift
#define NO_AUTO_SHIFT_ALPHA
#define AUTO_SHIFT_TIMEOUT TAPPING_TERM

#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

#define DYNAMIC_KEYMAP_LAYER_COUNT 16
