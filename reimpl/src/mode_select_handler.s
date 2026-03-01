/* VERIFIED: handles B (back) + UP/DOWN on Mode Select screen
 * Method: watchpoint on sym_0605D244 (selection index) + g_game_state (game state)
 *   DOWN: PC=0x0601975A (handler+0xA6) writes index, wraps 4→0
 *   UP:   PC=0x060197B8 (handler+0x104) writes index, wraps -1→3
 *   B:    PC=handler+0x80 writes game_state=4 (return to title)
 *   A/C advance is handled by dispatched per-item renderers, not this function
 * Date: 2026-02-28
 */


    .section .text.FUN_060196B0


    .global mode_select_handler
    .type mode_select_handler, @function
mode_select_handler:
    sts.l pr, @-r15
    add #-0xC, r15
    mov.l   _pool_flag_byte, r10
    mov.l   _pool_counter_byte, r12
    mov.l   _pool_mode_select_idx, r14
    mov.l   _pool_fn_scene_finalize, r3
    jsr @r3
    mov #0x1, r13
    mov.l   _pool_button_state, r4
    mov.w   _wpool_confirm_mask, r3
    mov.w @(2, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r3, r2
    tst r2, r2
    bt      .L_no_confirm
    mov.b @r14, r7
    shll r7
    mov.l r7, @(8, r15)
    mov.l   _pool_06049AF4, r3
    mov.l   _pool_06063750, r2
    add r3, r7
    mov.w @r7, r7
    extu.w r7, r7
    shll2 r7
    shll r7
    add r2, r7
    mov.l r7, @(4, r15)
    mov.l @(4, r7), r7
    mov.w   _wpool_0x2000, r3
    mov.l @(8, r15), r6
    add r3, r7
    mov.l   _pool_06049AEC, r3
    add r3, r6
    mov.l r6, @r15
    mov.b @(1, r6), r0
    mov.l @r15, r2
    mov r0, r6
    mov.b @r2, r2
    extu.b r6, r6
    extu.b r2, r2
    shll2 r6
    shll2 r6
    shll2 r6
    add r2, r6
    shll r6
    mov.l @(4, r15), r5
    mov.l @r5, r5
    mov.l   _pool_fn_06028400, r3
    jsr @r3
    mov #0xC, r4
    mov.b @r14, r2
    cmp/gt r13, r2
    bf      .L_skip_idx_reset
    exts.b r11, r2
    mov.b r2, @r14
.L_skip_idx_reset:
    mov.l   _pool_06059F44, r3
    mov.l r11, @r3
    extu.b r11, r2
    mov.b r2, @r12
    mov #0x4, r3
    mov.l   _pool_game_state, r2
    mov.l r3, @r2
    exts.b r13, r3
    mov.b r3, @r10
    mov.l   _pool_06085FF5, r3
    bra     .L_epilog_rts
    mov.b r13, @r3
.L_no_confirm:
    mov.w @(2, r4), r0
    mov.w   _wpool_0x2000, r3
    mov r0, r2
    extu.w r2, r2
    and r3, r2
    tst r2, r2
    bt/s    .L_check_up
    mov #0x5, r5
    mov.b r13, @r10
    extu.b r5, r5
    mov.b r5, @r12
    mov.b @r14, r2
    add #0x1, r2
    mov.b r2, @r14
    mov.b @r14, r3
    mov #0x4, r2
    cmp/ge r2, r3
    bf      .L_common_exit
    exts.b r11, r2
    bra     .L_common_exit
    mov.b r2, @r14

    .global DAT_06019762
_wpool_confirm_mask:
DAT_06019762:
    .2byte  0x0100
_wpool_0x2000:
    .2byte  0x2000
    .2byte  0xFFFF
_pool_flag_byte:
    .4byte  sym_06085FF1
_pool_counter_byte:
    .4byte  sym_0605D242
_pool_mode_select_idx:
    .4byte  sym_0605D244
_pool_fn_scene_finalize:
    .4byte  scene_dual_finalize
_pool_button_state:
    .4byte  g_pad_state
_pool_06049AF4:
    .4byte  sym_06049AF4
_pool_06063750:
    .4byte  sym_06063750
_pool_06049AEC:
    .4byte  sym_06049AEC
_pool_fn_06028400:
    .4byte  sym_06028400
_pool_06059F44:
    .4byte  sym_06059F44
_pool_game_state:
    .4byte  g_game_state
_pool_06085FF5:
    .4byte  sym_06085FF5
.L_check_up:
    mov.w @(2, r4), r0
    .byte   0x93, 0x63    /* mov.w @(disp,PC), r3 */
    mov r0, r2
    extu.w r2, r2
    and r3, r2
    tst r2, r2
    bt      .L_common_exit
    mov.b r13, @r10
    extu.b r5, r5
    mov.b r5, @r12
    mov.b @r14, r2
    add #-0x1, r2
    mov.b r2, @r14
    mov.b @r14, r3
    cmp/pz r3
    bt      .L_common_exit
    mov #0x3, r3
    mov.b r3, @r14
.L_common_exit:
    .byte   0xD4, 0x2B    /* mov.l @(disp,PC), r4 */
    mov.b @r4, r2
    add #0x1, r2
    mov.b r2, @r4
    mov.b @r12, r3
    add #0x1, r3
    mov.b r3, @r12
    mov.b @r14, r2
    shll2 r2
    .byte   0xD3, 0x28    /* mov.l @(disp,PC), r3 */
    add r3, r2
    mov.l @r2, r2
    add #0xC, r15
    lds.l @r15+, pr
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    jmp @r2
    mov.l @r15+, r14
.L_epilog_rts:
    add #0xC, r15
    lds.l @r15+, pr
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
