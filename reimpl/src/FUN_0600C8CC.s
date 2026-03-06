
    .section .text.FUN_0600C8CC


    /* THEORY: speed_delta_calc — computes per-frame speed change for cars.
       Evidence: NOP'd BSR→FUN_0600C8CC at 0x0600c6ac in FUN_0600C5D6.
       After 600 frames from rolling start, cars 1 and 3 nearly froze:
         car[1]: 214915→214683 (-232), car[3]: 218352→217590 (-762).
       Baseline (no NOP): car[1]: 214915→208316, car[3]: 218352→210670.
       car[2] anomalously dropped to 167650 (possibly wall collision via
       a separate code path). Two of three cars freezing is strong evidence
       this function computes the main speed delta each frame.
       Tested in FUN_0600C5D6 pipeline (cars 1-3 via FUN_0600E71A). */
    .global FUN_0600C8CC
    .type FUN_0600C8CC, @function
FUN_0600C8CC:
    mov.l r14, @-r15
    mov r4, r14
