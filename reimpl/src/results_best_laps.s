
    .section .text.FUN_0601667A


    .global results_best_laps
    .type results_best_laps, @function
results_best_laps:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    add #-0x4, r15
    mov #0x6, r12
    .byte   0xDD, 0x16    /* mov.l .L_pool_060166E1, r13 */
    mov #0x8, r14
    mov.b r4, @r15
    mov #0x0, r4
.L_reset_loop:
    extu.b r4, r3
    extu.b r12, r1
    mov r3, r2
    add #0x1, r4
    mov r1, r0
    shll2 r3
    shll2 r2
    shll2 r2
    shll2 r2
    add r2, r3
    exts.w r3, r3
    add r13, r3
    mov.b r0, @(2, r3)
    extu.b r4, r3
    cmp/ge r14, r3
    bf      .L_reset_loop
    mov.b @r15, r3
    extu.b r3, r3
    mov r3, r2
    shll2 r3
    shll2 r2
    shll2 r2
    shll2 r2
    add r2, r3
    exts.w r3, r3
    add r13, r3
    mov #0x1, r0
    mov.b r0, @(1, r3)
    mov.b @r15, r4
    extu.b r4, r4
    add #0x4, r15
    mov.l @r15+, r12
    mov.l @r15+, r13
    .byte   0xA6, 0x09    /* bra 0x060172E4 (external) */
    mov.l @r15+, r14
    .2byte  0xFFFF
    .4byte  sym_0605BAFA
    .4byte  sym_06035228
    .4byte  sym_06085F89
.L_pool_060166E1:
    .4byte  sym_06084FC8

    .global loc_060166E4
loc_060166E4:
    add #-0x4, r15
    mov.b r4, @r15
    .byte   0xD5, 0x18    /* mov.l .L_pool_0601674F, r5 */
    mov.b @r15, r4
    extu.b r4, r4
    mov r4, r3
    shll2 r4
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r4
    exts.w r4, r4
    add r5, r4
    mov #0x40, r0
    mov.b @(r0, r4), r2
    extu.b r2, r2
    mov r2, r3
    shll2 r2
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r2
    exts.w r2, r2
    add r5, r2
    mov #0x4, r0
    mov.b r0, @(2, r2)
    mov #0x1, r0
    mov.b r0, @(1, r4)
    mov.b @r15, r4
    extu.b r4, r4
    .byte   0xA5, 0xE0    /* bra 0x060172E4 (external) */
    add #0x4, r15

    .global loc_06016724
loc_06016724:
    mov #0x0, r6
    extu.b r4, r5
    .byte   0xD2, 0x08    /* mov.l .L_pool_0601674F, r2 */
    mov #0x40, r0
    mov r5, r3
    shll2 r5
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r5
    exts.w r5, r5
    add r2, r5
    mov.l r6, @(56, r5)
    mov.b r6, @(r0, r5)
    mov.b @(2, r5), r0
    mov r0, r3
    add #0x1, r3
    mov r3, r0
    rts
    mov.b r0, @(2, r5)
.L_pool_0601674F:
    .4byte  sym_06084FC8
