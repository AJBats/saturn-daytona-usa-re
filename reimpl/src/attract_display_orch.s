
    .section .text.FUN_0603FAE4


    .global attract_display_orch
    .type attract_display_orch, @function
attract_display_orch:
    sts.l pr, @-r15
    add #-0x4, r15
    mov.w   DAT_0603fb22, r13
    mov.l @r14, r10
    mov.l @(20, r14), r3
    cmp/gt r11, r3
    bt/s    .L_0603FAFA
    mov.l @(8, r14), r9
    mov.l r12, @r8
    bra     .L_0603FC4C
    mov #0x5, r0
.L_0603FAFA:
    mov #0x34, r0
    mov.b @(r0, r14), r3
    extu.b r3, r3
    and r13, r3
    cmp/eq r13, r3
    bt      .L_0603FB14
    mov.l r12, @r8
    mov #0x34, r0
    mov.b @(r0, r14), r0
    extu.b r0, r0
    mov.w   DAT_0603fb24, r3
    bra     .L_0603FC4C
    and r3, r0
.L_0603FB14:
    mov #0x34, r0
    mov.b @(r0, r14), r0
    extu.b r0, r0
    mov.w   DAT_0603fb24, r3
    and r3, r0
    bra     .L_0603FC28
    nop

    .global DAT_0603fb22
DAT_0603fb22:
    .2byte  0x0080

    .global DAT_0603fb24
DAT_0603fb24:
    .2byte  0xFF7F
    .2byte  0xFFFF
    .4byte  sym_0603F91C
.L_0603FB2C:
    mov r9, r6
    mov r10, r5
    .byte   0xB0, 0x96    /* bsr 0x0603FC60 (external) */
    mov r14, r4
    mov.l @(4, r14), r0
    tst r0, r0
    bf      .L_0603FB3E
    bra     .L_0603FC40
    nop
.L_0603FB3E:
    mov #0x34, r0
    mov.b @(r0, r14), r0
    extu.b r0, r0
    and r13, r0
    or #0x1, r0
    extu.b r0, r0
    mov #0x34, r1
    add r14, r1
    mov.b r0, @r1
.L_0603FB50:
    mov r9, r6
    mov r10, r5
    .byte   0xB0, 0xC6    /* bsr 0x0603FCE4 (external) */
    mov r14, r4
    mov.l @(12, r14), r0
    tst r0, r0
    bf      .L_0603FB62
    bra     .L_0603FC40
    nop
.L_0603FB62:
    mov #0x34, r0
    mov.b @(r0, r14), r0
    extu.b r0, r0
    and r13, r0
    or #0x2, r0
    extu.b r0, r0
    mov #0x34, r1
    add r14, r1
    mov.b r0, @r1
.L_0603FB74:
    mov.l r14, @r15
    mov r14, r3
    mov r14, r4
    mov.l @(36, r3), r3
    jsr @r3
    mov.l @(32, r4), r4
    mov r0, r4
    tst r4, r4
    bf      .L_0603FB8A
    bra     .L_0603FC40
    nop
.L_0603FB8A:
    .byte   0xB2, 0x07    /* bsr 0x0603FF9C (external) */
    mov r14, r4
    mov #0x34, r0
    mov.b @(r0, r14), r0
    extu.b r0, r0
    and r13, r0
    or #0x3, r0
    extu.b r0, r0
    mov #0x34, r1
    add r14, r1
    mov.b r0, @r1
.L_0603FBA0:
    mov.l r14, @r15
    mov r14, r3
    mov r14, r4
    mov.l @(44, r3), r3
    jsr @r3
    mov.l @(32, r4), r4
    mov r0, r4
    cmp/pl r4
    bf      .L_0603FBB6
    bra     .L_0603FC40
    nop
.L_0603FBB6:
    mov #0x1, r12
    mov #0x34, r0
    mov.b @(r0, r14), r0
    extu.b r0, r0
    and r13, r0
    or #0x4, r0
    extu.b r0, r0
    mov #0x34, r1
    add r14, r1
    mov.b r0, @r1
.L_0603FBCA:
    mov.l @(4, r14), r3
    mov.l @(28, r14), r2
    mov.l @(8, r3), r3
    cmp/eq r3, r2
    bf      .L_0603FBEA
    mov #-0x1, r6
    mov.l @(4, r14), r5
    mov.l   .L_0603FC24, r3
    jsr @r3
    mov r10, r4
    mov.l @(4, r14), r2
    mov.l @(12, r2), r3
    mov.l @(24, r14), r2
    add r3, r2
    mov.l r2, @(24, r14)
    mov.l r11, @(4, r14)
.L_0603FBEA:
    mov #-0x1, r6
    mov.l @(12, r14), r5
    mov.l   .L_0603FC24, r3
    jsr @r3
    mov r9, r4
    mov.l r11, @(12, r14)
    mov.l @(24, r14), r2
    mov.l @(20, r14), r3
    cmp/ge r3, r2
    bf      .L_0603FC12
    mov #0x34, r0
    mov.b @(r0, r14), r0
    extu.b r0, r0
    and r13, r0
    or #0x5, r0
    extu.b r0, r0
    mov #0x34, r1
    add r14, r1
    bra     .L_0603FC1E
    mov.b r0, @r1
.L_0603FC12:
    mov #0x34, r0
    mov.b @(r0, r14), r2
    extu.b r2, r2
    and r13, r2
    extu.b r2, r2
    mov.b r2, @(r0, r14)
.L_0603FC1E:
    bra     .L_0603FC40
    nop
    .2byte  0xFFFF
.L_0603FC24:
    .4byte  sym_0603F91C
.L_0603FC28:
    cmp/eq #0x0, r0
    bf      .L_0603FC30
    bra     .L_0603FB2C
    nop
.L_0603FC30:
    cmp/eq #0x1, r0
    bt      .L_0603FB50
    cmp/eq #0x2, r0
    bt      .L_0603FB74
    cmp/eq #0x3, r0
    bt      .L_0603FBA0
    cmp/eq #0x4, r0
    bt      .L_0603FBCA
.L_0603FC40:
    mov.l r12, @r8
    mov #0x34, r0
    mov.b @(r0, r14), r0
    extu.b r0, r0
    .byte   0x93, 0x35    /* mov.w .L_wpool_0603FCB6, r3 */
    and r3, r0
.L_0603FC4C:
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
