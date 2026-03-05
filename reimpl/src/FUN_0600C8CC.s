
    .section .text.FUN_0600C8CC


    /* THEORY: steering_toward_track — steers car[+0x28] (slip angle) toward
       atan2-derived track angle with clamped step (max ±0x600).
       Shared by player and AI. Ghidra decompilation. */
    .global FUN_0600C8CC
    .type FUN_0600C8CC, @function
FUN_0600C8CC:
    mov.l r14, @-r15
    mov r4, r14
