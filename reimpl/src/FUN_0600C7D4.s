
    .section .text.FUN_0600C7D4


    /* THEORY: speed_deceleration — applies per-frame speed reduction to cars.
       Evidence: NOP'd BSR→FUN_0600C7D4 at 0x0600c71e in FUN_0600C5D6.
       After 600 frames from rolling start, cars 1 and 3 held starting speed:
         car[1]: 214915→215638 (+723), car[3]: 218352→218723 (+371).
       Baseline (no NOP): car[1]: -6599, car[3]: -7682 over same period.
       Car[2] anomalously dropped (188897, consistent with wall collision
       seen in other experiments). Stronger effect than FUN_0600CA96: ~7K
       speed difference vs ~1K for ca96.
       Tested in FUN_0600C5D6 pipeline (cars 1-3 via FUN_0600E71A).
       Previously misnamed "heading_speed_damping" — heading effect not tested. */
    .global FUN_0600C7D4
    .type FUN_0600C7D4, @function
FUN_0600C7D4:
    mov.l r14, @-r15
    mov r4, r14
