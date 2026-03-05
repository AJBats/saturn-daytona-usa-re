
    .section .text.FUN_0600C7D4


    /* THEORY: heading_speed_damping — airborne path: saves vel to +0x38/+0x3C,
       averages pitch (+0x1C) and roll (+0x24) with track, updates heading
       delta (+0x30). Checks speed brackets (0x118, 0xFA, 0xDC) on +0x08.
       Shared by player and AI. Ghidra decompilation. */
    .global heading_speed_damping
    .type heading_speed_damping, @function
heading_speed_damping:
    mov.l r14, @-r15
    mov r4, r14
