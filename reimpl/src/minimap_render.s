
    .section .text.FUN_060155A4


    .global minimap_render
    .type minimap_render, @function
minimap_render:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    mov.l   .L_pool_06015668, r8
    mov #0x4, r9
    mov.l   .L_fp_half, r10
    mov.l   .L_pool_06015670, r11
    mov.l   .L_pool_06015674, r13
    mov #0x0, r14
.L_slot_loop:
    extu.b r14, r4
    mov r4, r0
    cmp/eq #0x3, r0
    .word 0x0029
    tst r4, r4
    .word 0x0129
    or r1, r0
    tst r0, r0
    bt      .L_direct_copy
    extu.b r14, r12
    mov r8, r5
    mov r12, r3
    shll2 r12
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r12
    exts.w r12, r12
    add r13, r12
    jsr @r11
    mov.l @(28, r12), r4
    mov.l r0, @(16, r12)
    mov r10, r5
    jsr @r11
    mov.l @(28, r12), r4
    mov r0, r2
    cmp/pz r2
    bt/s    .L_integrate_accum
    mov.l r0, @(20, r12)
    extu.b r14, r4
    mov r4, r3
    shll2 r4
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r4
    exts.w r4, r4
    add r13, r4
    mov.l @(20, r4), r2
    neg r2, r2
    bra     .L_integrate_accum
    mov.l r2, @(20, r4)
.L_direct_copy:
    extu.b r14, r4
    mov r4, r3
    shll2 r4
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r4
    exts.w r4, r4
    add r13, r4
    mov.l @(28, r4), r2
    mov.l r2, @(16, r4)
.L_integrate_accum:
    extu.b r14, r4
    mov r4, r3
    add #0x1, r14
    shll2 r4
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r4
    exts.w r4, r4
    add r13, r4
    mov.l @(36, r4), r2
    mov.l @(24, r4), r3
    add r2, r3
    mov.l r3, @(24, r4)
    mov.l @(32, r4), r2
    mov.l @(28, r4), r3
    add r2, r3
    mov.l r3, @(28, r4)
    extu.b r14, r2
    cmp/ge r9, r2
    bf      .L_slot_loop
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .2byte  0xFFFF
.L_pool_06015668:
    .4byte  0x0000DDB2                  /* ~0.866 (16.16 FP scale factor, sin(60) or cos(30)) */
.L_fp_half:
    .4byte  0x00008000                  /* 0.5 (16.16 fixed-point) */
.L_pool_06015670:
    .4byte  fpmul
.L_pool_06015674:
    .4byte  sym_06084FC8

    .global loc_06015678
loc_06015678:
    add #-0x4, r15
    mov.b r4, @r15
    mov.b @r15, r3
    extu.b r3, r3
    mov r3, r2
    shll2 r3
    shll2 r2
    shll2 r2
    shll2 r2
    add r2, r3
    exts.w r3, r3
    .byte   0xD1, 0x28    /* mov.l .L_pool_06015730, r1 */  ! r1 = sym_06084FC8 (slot array base, cross-TU pool)
    add r1, r3
    mov.b @(2, r3), r0
    mov r0, r3
    extu.b r3, r3
    shll2 r3
    .byte   0xD2, 0x26    /* mov.l .L_pool_06015734, r2 */  ! r2 = handler function table base (cross-TU pool)
    add r2, r3
    mov.l @r3, r3
    mov.b @r15, r4
    jmp @r3
    add #0x4, r15
