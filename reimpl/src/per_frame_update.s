/* VERIFIED: called every frame in all game states (menu, circuit, car, race)
 * Method: call-trace differential — appears in baselines for all 4 investigated states
 *   Menu: 10x/10frames, Circuit: 10x/10frames, Car: 10x/10frames, Race: confirmed active
 * Date: 2026-02-28
 */

    .section .text.FUN_0600A392


    .global per_frame_update
    .type per_frame_update, @function
per_frame_update:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    sts.l pr, @-r15
    add #-0xC, r15
    .byte   0xDD, 0x10    /* mov.l .L_pool_game_state_ptr, r13 -- r13 = &game_state (g_game_state) */
    .byte   0xD3, 0x11    /* mov.l .L_pool_fn_cdb_read_status, r3 -- r3 = cdb_read_status */
    jsr @r3
    nop
    mov #0xF, r14
    and r0, r14
    mov r14, r0
    cmp/eq #0x6, r0
    bf      .L_tray_ok
    .byte   0xD3, 0x0E    /* mov.l .L_pool_bios_reset_indirect, r3 -- r3 = &bios_reset_ptr (sym_0600026C) */
    mov.l @r3, r3
    jsr @r3
    nop
.L_tray_ok:
    .byte   0xDC, 0x0D    /* mov.l .L_pool_frame_sync_state_ptr, r12 -- r12 = &frame_sync_state (sym_0607864A) */
    mov.b @r12, r0
    tst r0, r0
    bf      .L_sync_not_zero
    .byte   0xD3, 0x0C    /* mov.l .L_pool_fn_cd_block_read_safe, r3 -- r3 = cd_block_read_safe */
    jsr @r3
    mov r15, r4
    mov r15, r4
    mov #0x64, r2
    mov.b @(6, r4), r0
    mov r0, r4
    extu.b r4, r3
    cmp/ge r2, r3
    bt      .L_check_buttons
    .byte   0xD3, 0x08    /* mov.l .L_pool_sync_byte_store, r3 -- r3 = &sync_byte_dest (sym_06078649) */
    mov.b r4, @r3
    bra     .L_check_buttons
    nop
    .2byte  0xFFFF
    .4byte  sym_06078644
.L_pool_game_state_ptr:
    .4byte  g_game_state
.L_pool_fn_cdb_read_status:
    .4byte  cdb_read_status
.L_pool_bios_reset_indirect:
    .4byte  sym_0600026C
.L_pool_frame_sync_state_ptr:
    .4byte  sym_0607864A
.L_pool_fn_cd_block_read_safe:
    .4byte  cd_block_read_safe
.L_pool_sync_byte_store:
    .4byte  sym_06078649
.L_sync_not_zero:
    mov.b @r12, r0
    cmp/eq #0x1, r0
    bf      .L_check_buttons
    mov r14, r0
    cmp/eq #0x1, r0
    bf      .L_check_buttons
    .byte   0xD3, 0x17    /* mov.l .L_pool_fn_cd_status_reader, r3 -- r3 = cd_status_reader */
    jsr @r3
    nop
    mov #0x2, r2
    mov.b r2, @r12
.L_check_buttons:
    .byte   0xD5, 0x16    /* mov.l .L_pool_button_status_ptr, r5 -- r5 = &button_status (g_pad_state) */
    mov.w   DAT_0600a460, r2
    mov.w @(2, r5), r0
    mov r0, r3
    extu.w r3, r3
    and r2, r3
    tst r3, r3
    bt      .L_epilogue
    mov.w   .L_wpool_held_mask, r4
    mov.w @r5, r3
    extu.w r3, r3
    and r4, r3
    cmp/eq r4, r3
    bf      .L_epilogue
    .byte   0xBD, 0xE7    /* bsr 0x06009FFC (external) -- call state_timeext_setup (SCU interrupt reconfigure) */
    nop
    mov #0x6, r3
    mov.l @r13, r2
    cmp/hs r3, r2
    bf      .L_state_lt_6
    .byte   0xBE, 0xBF    /* bsr 0x0600A1B8 (external) -- call secret input handler */
    nop
    mov.l @r13, r0
    cmp/eq #0x17, r0
    bf      .L_reset_state
    .byte   0xD3, 0x0A    /* mov.l .L_pool_fn_obj_state_pack, r3 -- r3 = obj_state_pack */
    jsr @r3
    nop
.L_reset_state:
    mov #0x0, r2
    bra     .L_epilogue
    mov.l r2, @r13
.L_state_lt_6:
    .byte   0xD2, 0x08    /* mov.l .L_pool_bios_reset_indirect_2, r2 -- r2 = &bios_reset_ptr (sym_0600026C) */
    mov.l @r2, r2
    jsr @r2
    nop
.L_epilogue:
    add #0xC, r15
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global DAT_0600a460
DAT_0600a460:
    .2byte  0x0800
.L_wpool_held_mask:
    .2byte  0x0700
.L_pool_fn_cd_status_reader:
    .4byte  cd_status_reader
.L_pool_button_status_ptr:
    .4byte  g_pad_state
.L_pool_fn_obj_state_pack:
    .4byte  obj_state_pack
.L_pool_bios_reset_indirect_2:
    .4byte  sym_0600026C
