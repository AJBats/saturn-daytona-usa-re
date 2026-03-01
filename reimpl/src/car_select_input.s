/* VERIFIED: active during car select screen (called after mode select C press)
 * Method: call-trace differential — 10 frames idle vs 10 frames with C on mode select
 *   12 calls during C (baseline 10, +2) — runs every frame during car select state
 * Date: 2026-02-28
 */

    .section .text.FUN_06019A48


    .global car_select_input
    .type car_select_input, @function
car_select_input:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_pool_06019B28, r12
    mov.l   .L_pool_06019B2C, r14
    mov.l   .L_pool_06019B30, r3
    mov.b @r3, r3
    extu.b r3, r3
    tst r3, r3
    bt/s    .L_06019A6E
    mov #0x1, r10
    bra     .L_06019B9A
    nop
.L_06019A6E:
    mov.l   .L_pool_06019B34, r4
    mov.l   .L_pool_06019B38, r8
    mov.w   .L_wpool_06019B22, r9
    mov.l   .L_pool_06019B3C, r11
    mov.w @(2, r4), r0
    mov r9, r2
    mov r0, r3
    add #0x70, r2
    extu.w r3, r3
    and r2, r3
    tst r3, r3
    bt/s    .L_06019AD6
    mov #0x7, r13
    mov.l   .L_pool_06019B40, r7
    mov r9, r6
    mov.b @r14, r5
    mov.l @r7, r7
    shll r5
    add r11, r5
    mov.l r5, @r15
    mov.b @(1, r5), r0
    mov.l @r15, r3
    mov r0, r5
    mov.b @r3, r3
    extu.b r5, r5
    extu.b r3, r3
    shll2 r5
    shll2 r5
    shll2 r5
    add r3, r5
    shll r5
    jsr @r8
    mov #0xC, r4
    mov.b @r14, r0
    cmp/eq #0x7, r0
    bf      .L_06019ABE
    mov.l   .L_pool_06019B44, r3
    mov.l r13, @r3
    bra     .L_06019B9A
    nop
.L_06019ABE:
    exts.b r13, r13
    exts.b r10, r2
    mov #0x0, r3
    mov.b r13, @r14
    mov.b r2, @r12
    mov.l   .L_pool_06019B48, r2
    mov.l r3, @r2
    mov.l   .L_pool_06019B4C, r3
    jsr @r3
    nop
    bra     .L_06019B9A
    nop
.L_06019AD6:
    mov.w @(2, r4), r0
    mov.w   .L_wpool_06019B24, r3
    mov r0, r2
    extu.w r2, r2
    and r3, r2
    tst r2, r2
    bt      .L_06019B50
    mov r9, r6
    mov.b @r14, r5
    mov.l   .L_pool_06019B40, r7
    shll r5
    mov.l @r7, r7
    add r11, r5
    mov.l r5, @r15
    mov.b @(1, r5), r0
    mov.l @r15, r3
    mov r0, r5
    mov.b @r3, r3
    extu.b r5, r5
    extu.b r3, r3
    shll2 r5
    shll2 r5
    shll2 r5
    add r3, r5
    shll r5
    jsr @r8
    mov #0xC, r4
    mov.b @r14, r2
    add #0x1, r2
    mov.b r2, @r14
    mov.b @r14, r3
    mov #0x8, r2
    cmp/ge r2, r3
    bf      .L_06019B1E
    mov #0x0, r2
    mov.b r2, @r14
.L_06019B1E:
    bra     .L_06019B9A
    mov.b r10, @r12
.L_wpool_06019B22:
    .2byte  0x0090
.L_wpool_06019B24:
    .2byte  0x2000
    .2byte  0xFFFF
.L_pool_06019B28:
    .4byte  sym_06085FF1
.L_pool_06019B2C:
    .4byte  sym_06085FF0
.L_pool_06019B30:
    .4byte  sym_06085FF3
.L_pool_06019B34:
    .4byte  g_pad_state
.L_pool_06019B38:
    .4byte  sym_060284AE
.L_pool_06019B3C:
    .4byte  sym_06049AFC
.L_pool_06019B40:
    .4byte  sym_0605D4F0
.L_pool_06019B44:
    .4byte  g_game_state
.L_pool_06019B48:
    .4byte  sym_06059F44
.L_pool_06019B4C:
    .4byte  sym_06026CE0
.L_06019B50:
    mov.w @(2, r4), r0
    .byte   0x93, 0x53    /* mov.w _wpool_dpad_left_mask, r3 */
    mov r0, r2
    extu.w r2, r2
    and r3, r2
    tst r2, r2
    bt      .L_06019B9A
    .byte   0xD7, 0x28    /* mov.l .L_pool_06019B40_far, r7 */
    mov r9, r6
    mov.b @r14, r5
    mov.l @r7, r7
    shll r5
    add r11, r5
    mov.l r5, @r15
    mov.b @(1, r5), r0
    mov.l @r15, r3
    mov r0, r5
    mov.b @r3, r3
    extu.b r5, r5
    extu.b r3, r3
    shll2 r5
    shll2 r5
    shll2 r5
    add r3, r5
    shll r5
    jsr @r8
    mov #0xC, r4
    mov.b @r14, r2
    add #-0x1, r2
    mov.b r2, @r14
    mov.b @r14, r3
    cmp/pz r3
    bt      .L_06019B96
    exts.b r13, r13
    mov.b r13, @r14
.L_06019B96:
    exts.b r10, r3
    mov.b r3, @r12
.L_06019B9A:
    .byte   0xD4, 0x1A    /* mov.l .L_pool_06019C04, r4 */
    mov.b @r4, r2
    add #0x1, r2
    mov.b r2, @r4
    .byte   0xD4, 0x19    /* mov.l .L_pool_06019C08, r4 */
    mov.b @r4, r3
    add #0x1, r3
    mov.b r3, @r4
    mov.b @r14, r2
    shll2 r2
    .byte   0xD3, 0x17    /* mov.l .L_pool_06019C0C, r3 */
    add r3, r2
    mov.l @r2, r2
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    jmp @r2
    mov.l @r15+, r14
