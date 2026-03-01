
    .section .text.FUN_0603F244


    .global credits_scroll
    .type credits_scroll, @function
credits_scroll:
    sts.l pr, @-r15
    add #-0xC, r15
    mov.l   .L_dma_handler, r11
    mov.l   .L_checkpoint_check, r12
    mov.l   .L_game_state_ptr, r13
    mov.w   .L_state_field_offset, r0
    mov.l @r13, r5
    jsr @r12
    mov.l @(r0, r5), r5
    cmp/eq #-0x5, r0
    bf/s    .L_initial_state_ok
    mov r0, r14
    bra     .L_return
    mov #-0x1, r0
.L_initial_state_ok:
    mov.l   .L_fp_half, r4
    mov.l   .L_init_callback_param, r3
    jsr @r3
    nop
    bra     .L_check_scroll_done
    nop
.L_process_frame:
    jsr @r11
    nop
    cmp/eq #-0xC, r0
    bf      .L_frame_ok
    bra     .L_return
    mov #-0x1, r0
.L_frame_ok:
    mov.l @r13, r5
    mov.w   .L_state_field_offset, r0
    mov.l @(r0, r5), r5
    jsr @r12
    mov r10, r4
    mov r0, r14
.L_check_scroll_done:
    tst r14, r14
    bf      .L_process_frame
    mov.l   .L_state_field_read, r3
    jsr @r3
    nop
    tst r0, r0
    bt      .L_state_ok
    bra     .L_return
    mov #-0x1, r0
.L_state_ok:
    mov r15, r6
    mov r15, r5
    mov r15, r4
    mov.l   .L_track_shadow_ground, r3
    add #0x8, r6
    jsr @r3
    add #0x4, r4
    mov r0, r4
    tst r4, r4
    bt      .L_shadow_ok
    bra     .L_return
    mov #-0x1, r0
.L_shadow_ok:
    mov.l @r15, r0
    add #0x2, r0
.L_return:
    add #0xC, r15
    lds.l @r15+, pr
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_state_field_offset:
    .2byte  0x00C8
.L_dma_handler:
    .4byte  large_prologue_save
.L_checkpoint_check:
    .4byte  checkpoint_state_check
.L_game_state_ptr:
    .4byte  sym_060A4D14
.L_fp_half:
    .4byte  0x00008000                  /* 0.5 (16.16 fixed-point) */
.L_init_callback_param:
    .4byte  sym_06041884
.L_state_field_read:
    .4byte  state_field_read
.L_track_shadow_ground:
    .4byte  track_shadow_ground
