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

4. Copy the `totem` directory into `./keyboards/`.

5. `make totem:vial`

6. The image is generated in `./totem_vial.uf2`

7. Flash the same image into both halves.

8. Connect the keyboard and launch Vial with `sudo Vial`.
   If your keyboard doesn’t show up after flashing Vial firmware, and you’re on
   Linux, [you may need to add udev rules.
   ](https://get.vial.today/manual/linux-udev.html).

9. In Vial upload `the _memory friendly layout`:

        File -> Load saved layout: `vial-musclememory-config-totem1.vil`.

NOTE: this build generates only one firmware image that must be flashed to
both halves of your keyboard. After flashing connect the right half
via USB to your computer. The two halves are connected via the 4 pin audio
cable.

[Geigeigeist Github repository]: https://github.com/GEIGEIGEIST/qmk-config-totem
