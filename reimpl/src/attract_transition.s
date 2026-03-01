
    .section .text.FUN_0603F974


    .global attract_transition
    .type attract_transition, @function
attract_transition:
    sts.l pr, @-r15
    mov r5, r14
    add #-0x4, r15
    mov.b @(r0, r4), r3
    mov #0x35, r0
    extu.b r3, r3
    mov.l r3, @r15
    cmp/pz r14
    bf/s    .L_0603F9A4
    mov.b r14, @(r0, r4)
    mov #0x3, r2
    cmp/gt r2, r14
    bt      .L_0603F9A4
    exts.b r14, r6
    mov.l   .L_pool_attract_data_table, r2
    mov r6, r3
    shll2 r6
    shll2 r3
    shll r3
    add r3, r6
    exts.b r6, r6
    add r2, r6
    .byte   0xBF, 0xC4    /* bsr 0x0603F92C (external) */
    mov #0x0, r5
.L_0603F9A4:
    mov.l @r15, r0
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
    .2byte  0x000B
    .4byte  0x145CFFFF
.L_pool_attract_data_table:
    .4byte  sym_0606364C                /* [MEDIUM] attract mode transition data table */
