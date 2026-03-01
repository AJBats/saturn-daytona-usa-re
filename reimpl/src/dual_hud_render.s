
    .section .text.FUN_06011E7C


    .global dual_hud_render
    .type dual_hud_render, @function
dual_hud_render:
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_pool_06011F08, r3
    mov.l r3, @r15
    mov r3, r7
    mov.w   DAT_06011f00, r6
    mov.l @r15, r5
    mov.l @(4, r7), r7
    mov.w   DAT_06011efe, r3
    mov.l @r5, r5
    add r3, r7
    mov.l   .L_pool_06011F0C, r3
    jsr @r3
    mov #0xC, r4
    mov.l   .L_pool_06011F10, r2
    mov.l r2, @r15
    mov r2, r7
    mov.l @(4, r7), r7
    mov.w   DAT_06011efe, r3
    add r3, r7
    mov.w   DAT_06011f02, r6
    mov r2, r5
    mov.l @r5, r5
    mov #0xC, r4
    add #0x4, r15
    mov.l   .L_pool_06011F0C, r3
    jmp @r3
    lds.l @r15+, pr

    .global sym_06011EB4
sym_06011EB4:
    add #-0x4, r15
    mov.l   .L_pool_06011F14, r0
    mov.b @r0, r0
    tst r0, r0
    bt      .L_single_player_path
    bra     dual_hud_render
    add #0x4, r15
.L_single_player_path:
    mov.l   .L_pool_06011F18, r0
    mov.l @r0, r0
    tst r0, r0
    bt      .L_render_player2_hud
    mov.l   .L_pool_06011F08, r3
    mov.l r3, @r15
    mov r3, r7
    mov.l @(4, r7), r7
    mov.w   DAT_06011efe, r3
    add r3, r7
    mov.w   .L_wpool_06011F04, r6
    mov.l @r15, r5
    mov.l @r5, r5
    mov #0xC, r4
    mov.l   .L_pool_06011F0C, r3
    jmp @r3
    add #0x4, r15
.L_render_player2_hud:
    mov.l   .L_pool_06011F10, r2
    mov.l r2, @r15
    mov r2, r7
    mov.l @(4, r7), r7
    mov.w   DAT_06011efe, r3
    add r3, r7
    mov.w   .L_wpool_06011F04, r6
    mov r2, r5
    mov.l @r5, r5
    mov #0xC, r4
    mov.l   .L_pool_06011F0C, r3
    jmp @r3
    add #0x4, r15

    .global DAT_06011efe
DAT_06011efe:
    .2byte  0x4000

    .global DAT_06011f00
DAT_06011f00:
    .2byte  0x04BE

    .global DAT_06011f02
DAT_06011f02:
    .2byte  0x0486
.L_wpool_06011F04:
    .2byte  0x0420
    .2byte  0xFFFF
.L_pool_06011F08:
    .4byte  sym_060638B0
.L_pool_06011F0C:
    .4byte  sym_06028400
.L_pool_06011F10:
    .4byte  sym_060638A0
.L_pool_06011F14:
    .4byte  sym_06085FF4
.L_pool_06011F18:
    .4byte  sym_0607EADC

    .global sym_06011F1C
sym_06011F1C:
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    .byte   0x99, 0x55    /* mov.w .L_wpool_06011FD4, r9 */  ! r9 = 0x03E0 (green mask: bits 5-9)
    mov #0x1F, r10
    mov #0x10, r11
    .byte   0x9C, 0x53    /* mov.w .L_wpool_06011FD6, r12 */ ! r12 = 0x7C00 (red mask: bits 10-14)
    .byte   0x9D, 0x53    /* mov.w .L_wpool_06011FD8, r13 */ ! r13 = 0xF800 (sign-ext = -0x800, red -2 step)
    mov #0x0, r6
    exts.w r6, r5
.L_fade_loop:
    mov.w @r4, r0
    exts.w r6, r3
    exts.w r0, r7
    mov.w r3, @r4
    and r10, r7
    add #-0x2, r7
    cmp/pl r7
    bf      .L_blue_clamp_zero
    bra     .L_blue_done
    mov r7, r2
.L_blue_clamp_zero:
    mov #0x0, r2
.L_blue_done:
    exts.w r0, r7
    mov.w @r4, r3
    and r9, r7
    or r2, r3
    add #-0x40, r7
    mov.w r3, @r4
    cmp/pl r7
    bf      .L_green_clamp_zero
    bra     .L_green_done
    mov r7, r2
.L_green_clamp_zero:
    mov #0x0, r2
.L_green_done:
    mov.w @r4, r3
    exts.w r0, r7
    or r2, r3
    and r12, r7
    mov.w r3, @r4
    add r13, r7
    cmp/pl r7
    bf      .L_red_clamp_zero
    bra     .L_red_done
    mov r7, r2
.L_red_clamp_zero:
    mov #0x0, r2
.L_red_done:
    add #0x1, r5
    mov.w @r4, r3
    or r2, r3
    mov.w r3, @r4
    exts.w r5, r2
    cmp/ge r11, r2
    bf/s    .L_fade_loop
    add #0x2, r4
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    rts
    mov.l @r15+, r13
