---
title:        totem_vial.uf2
subtitle:     Building howto
author:       Getreu
date:         2025-11-16
lang:         en-US
---

[totem_vial.uf2](<totem_vial.uf2>)
____

The _muscle memory friendly layout_ needs 6 keyboard layers in Vial.
The firmware in the author's [Geigeigeist Github repository] enables only
four layers. Therefor we must compile and flash Vial firmware ourself using
the command line tools:



1. [Install QMK](https://docs.qmk.fm/newbs_getting_started) according to their
   guide. NixOS: `nix-shell -p qmk`

2. Clone the `vial-qmk` repository:

       cd /tmp
       mkdir dev
       cd dev
       git clone --depth 1 https://github.com/vial-kb/vial-qmk.git

   and navigate there in your terminal: `cd vial-qmk`. 

3. Verify that QMK is using the correct repository by running qmk env. It should
   list your vial-qmk folder as your QMK_HOME and QMK_FIRMWARE locations. If it
   lists a qmk_firmware directory, then it’s still using the regular (non-Vial)
   QMK install.

4. Copy the `firmware-src-addto/vial-qmk/keyboards/totem/` directory into
   `./keyboards/`.

5. In the file:

       ./keyboards/totem/keymaps/vial/config.h

   There is a line similar to:

       #define VIAL_KEYBOARD_UID {0x80, 0xD7, 0x5F, 0xD9, 0x25, 0x60, 0xAB, 0x3A}

   This line is auto-generated with the command:

       python3 util/vial_generate_keyboard_uid.py

   Run this command and replace the values if the output differs.

6. `make totem:vial`

7. The image is generated in `./totem_vial.uf2`

8. Flash the same image into both halves.

9. Connect the keyboard and launch Vial with `sudo Vial`.
   If your keyboard doesn’t show up after flashing Vial firmware, and you’re on
   Linux, [you may need to add udev rules.
   ](https://get.vial.today/manual/linux-udev.html).

10. Open the Vial application and upload the _muscle memory friendly_ layout:

        File -> Load saved layout:
        `./vial-config/vial-musclememory-config-totem1.vil`.

NOTE: this build generates only one firmware image that must be flashed to
both halves of your keyboard. After flashing connect the right half
via USB to your computer. The two halves are connected via the 4 pin audio
cable.

[Geigeigeist Github repository]: https://github.com/GEIGEIGEIST/qmk-config-totem
