
    .section .text.FUN_060302D2


    .global engine_sound_body
    .type engine_sound_body, @function
engine_sound_body:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov #0x0, r9
    mov r0, r6
    mov #0x1, r5
    mov #0x0, r7
    .byte   0xD0, 0x04    /* mov.l .L_snd_obj_ptr, r0 */
    mov.l @r0, r0
    .byte   0xD1, 0x04    /* mov.l .L_replay_mode_flag, r1 */
    mov.w @r1, r2
    tst r2, r2
    bt      .L_live_mode
    bra     .L_replay_mode
    nop
    .2byte  0x0000
.L_snd_obj_ptr:
    .4byte  sym_0607E944
.L_replay_mode_flag:
    .4byte  sym_0607ED8C
.L_live_mode:
    .byte   0xD2, 0x08    /* mov.l .L_input_state_a, r2 */
    mov.w @r2, r1
    extu.w r1, r1
    .byte   0xD2, 0x08    /* mov.l .L_btn_mask_zoom_in, r2 */
    mov.w @r2, r2
    mov.w   .L_off_detail_level, r3
    cmp/pl r2
    bf      .L_check_detail_3
    tst r1, r2
    bt      .L_check_zoom_out
    mov.w @(r0, r3), r4
    tst r4, r4
    bt      .L_store_detail
    add #-0x1, r4
.L_store_detail:
    bra     .L_detail_done
    mov.w r4, @(r0, r3)
.L_off_detail_level:
    .2byte  0x00DE
    .2byte  0x0000
.L_input_state_a:
    .4byte  sym_06063D9A
.L_btn_mask_zoom_in:
    .4byte  sym_0608188A
.L_check_zoom_out:
    .byte   0xD2, 0x05    /* mov.l .L_btn_mask_zoom_out, r2 */
    mov.w @r2, r2
    tst r1, r2
    bt      .L_detail_done
    mov.w @(r0, r3), r4
    mov #0x3, r2
    cmp/eq r4, r2
    bt      .L_zoom_out_clamped
    add #0x1, r4
.L_zoom_out_clamped:
    bra     .L_detail_done
    mov.w r4, @(r0, r3)
    .2byte  0x0000
.L_btn_mask_zoom_out:
    .4byte  sym_06081888
.L_check_detail_3:
    .byte   0xD2, 0x03    /* mov.l .L_btn_mask_detail_3, r2 */
    mov.w @r2, r2
    tst r1, r2
    bt      .L_check_detail_2
    mov #0x3, r4
    bra     .L_detail_done
    mov.w r4, @(r0, r3)
    .2byte  0x0000
.L_btn_mask_detail_3:
    .4byte  sym_06081896
.L_check_detail_2:
    .byte   0xD2, 0x03    /* mov.l .L_btn_mask_detail_2, r2 */
    mov.w @r2, r2
    tst r1, r2
    bt      .L_check_detail_1
    mov #0x2, r4
    bra     .L_detail_done
    mov.w r4, @(r0, r3)
    .2byte  0x0000
.L_btn_mask_detail_2:
    .4byte  sym_06081894
.L_check_detail_1:
    .byte   0xD2, 0x03    /* mov.l .L_btn_mask_detail_1, r2 */
    mov.w @r2, r2
    tst r1, r2
    bt      .L_check_detail_0
    mov #0x1, r4
    bra     .L_detail_done
    mov.w r4, @(r0, r3)
    .2byte  0x0000
.L_btn_mask_detail_1:
    .4byte  sym_06081892
.L_check_detail_0:
    .byte   0xD2, 0x0F    /* mov.l .L_btn_mask_detail_0, r2 */
    mov.w @r2, r2
    tst r1, r2
    bt      .L_detail_done
    mov #0x0, r4
    mov.w r4, @(r0, r3)
.L_detail_done:
    mov.w @(r0, r3), r4
    mov r4, r9
    .byte   0xD3, 0x0C    /* mov.l .L_input_state_b, r3 */
    mov.w @r3, r1
    extu.w r1, r1
    mov #0x1, r5
    .byte   0xD2, 0x0B    /* mov.l .L_btn_mask_near_scroll, r2 */
    mov.w @r2, r2
    tst r1, r2
    bt      .L_no_near_scroll
    mov #-0x80, r8
    extu.b r8, r8
    or r8, r9
    mov.w   DAT_060303b6, r2
    mov.l r5, @(r0, r2)
    add #0x8, r2
    mov.w   .L_near_scroll_max, r8
    mov.l @(r0, r2), r4
    cmp/gt r8, r4
    bt      .L_near_scroll_store
    add #0x4, r4
.L_near_scroll_store:
    bra     .L_check_far_scroll
    mov.l r4, @(r0, r2)

    .global DAT_060303b6
DAT_060303b6:
    .2byte  0x006C
.L_near_scroll_max:
    .2byte  0x00B8
    .2byte  0x0000
.L_btn_mask_detail_0:
    .4byte  sym_06081890
.L_input_state_b:
    .4byte  g_pad_state
.L_btn_mask_near_scroll:
    .4byte  sym_0608188C
.L_no_near_scroll:
    mov.w   DAT_06030402, r3
    mov #0x38, r5
    mov.l @(r0, r3), r4
    add #-0x2, r4
    cmp/gt r5, r4
    bt      .L_near_decay_store
    mov r5, r4
.L_near_decay_store:
    mov.l r4, @(r0, r3)
    .byte   0xD2, 0x0B    /* mov.l .L_off_near_active_l, r2 */
    mov #0x0, r7
    mov.l r7, @(r0, r2)
.L_check_far_scroll:
    .byte   0xD2, 0x0B    /* mov.l .L_btn_mask_far_scroll, r2 */
    mov.w @r2, r2
    tst r1, r2
    bt      .L_no_far_scroll
    mov #0x40, r8
    or r8, r9
    .byte   0xD3, 0x09    /* mov.l .L_off_far_active, r3 */
    mov.l r5, @(r0, r3)
    .byte   0xD3, 0x09    /* mov.l .L_off_far_pos, r3 */
    mov.l @(r0, r3), r4
    .byte   0xD6, 0x09    /* mov.l .L_off_far_prev, r6 */
    mov.w   .L_far_scroll_max, r8
    mov.l r4, @(r0, r6)
    cmp/gt r8, r4
    bt      .L_far_scroll_store
    add #0x5, r4
.L_far_scroll_store:
    bra     .L_write_ringbuf
    mov.l r4, @(r0, r3)

    .global DAT_06030402
DAT_06030402:
    .2byte  0x0074
.L_far_scroll_max:
    .2byte  0x00B8
    .2byte  0x0000
.L_off_near_active_l:
    .4byte  0x0000006C
.L_btn_mask_far_scroll:
    .4byte  sym_0608188E
.L_off_far_active:
    .4byte  0x00000088
.L_off_far_pos:
    .4byte  0x00000090
.L_off_far_prev:
    .4byte  0x0000008C
.L_no_far_scroll:
    .byte   0xD3, 0x10    /* mov.l .L_off_far_pos_l, r3 */
    mov.l @(r0, r3), r4
    .byte   0xD6, 0x10    /* mov.l .L_off_far_prev_l, r6 */
    mov.l r4, @(r0, r6)
    mov #0x38, r3
    add #-0x5, r4
    cmp/ge r3, r4
    bt      .L_far_decay_clamped
    mov r3, r4
.L_far_decay_clamped:
    .byte   0xD3, 0x0C    /* mov.l .L_off_far_pos_l, r3 */
    mov.l r4, @(r0, r3)
    .byte   0xD3, 0x0D    /* mov.l .L_off_far_active_l, r3 */
    mov.l r7, @(r0, r3)
.L_write_ringbuf:
    .byte   0xD2, 0x0D    /* mov.l .L_ringbuf_base, r2 */
    .byte   0xD4, 0x0D    /* mov.l .L_ringbuf_index, r4 */
    mov.l @r4, r6
    add r6, r2
    add #0x2, r6
    mov.b r9, @r2
    mov.w   DAT_0603045e, r3
    cmp/gt r6, r3
    bt      .L_ringbuf_wrap
    add #-0x2, r6
.L_ringbuf_wrap:
    mov.l r6, @r4
    lds.l @r15+, pr
    mov.l @r15+, r14
    mov.l @r15+, r13
    mov.l @r15+, r12
    mov.l @r15+, r11
    mov.l @r15+, r10
    mov.l @r15+, r9
    rts
    mov.l @r15+, r8

    .global DAT_0603045e
DAT_0603045e:
    .2byte  0x2AF6
.L_off_far_pos_l:
    .4byte  0x00000090
.L_off_far_prev_l:
    .4byte  0x0000008C
.L_off_far_active_l:
    .4byte  0x00000088
.L_ringbuf_base:
    .4byte  sym_0607ED90
.L_ringbuf_index:
    .4byte  sym_0607ED88
.L_replay_mode:
    .byte   0xD2, 0x0F    /* mov.l .L_rp_ringbuf_base, r2 */
    .byte   0xD4, 0x10    /* mov.l .L_rp_ringbuf_index, r4 */
    mov.l @r4, r6
    add r6, r2
    add #0x2, r6
    mov.b @r2, r1
    mov.w   DAT_060304ac, r3
    extu.b r1, r1
    mov r1, r5
    mov #0x3, r2
    and r2, r5
    mov.w r5, @(r0, r3)
    mov.l r6, @r4
    mov #0x1, r5
    mov #-0x80, r2
    extu.b r2, r2
    tst r1, r2
    bt      .L_rp_no_near_scroll
    mov.w   DAT_060304ae, r2
    mov.l r5, @(r0, r2)
    add #0x8, r2
    mov.w   .L_rp_near_scroll_max, r8
    mov.l @(r0, r2), r4
    cmp/gt r8, r4
    bt      .L_rp_near_scroll_store
    add #0x4, r4
.L_rp_near_scroll_store:
    bra     .L_rp_check_far_scroll
    mov.l r4, @(r0, r2)

    .global DAT_060304ac
DAT_060304ac:
    .2byte  0x00DE

    .global DAT_060304ae
DAT_060304ae:
    .2byte  0x006C
.L_rp_near_scroll_max:
    .2byte  0x00B8
    .2byte  0x0000
.L_rp_ringbuf_base:
    .4byte  sym_0607ED90
.L_rp_ringbuf_index:
    .4byte  sym_0607ED88
.L_rp_no_near_scroll:
    mov.w   DAT_060304f0, r3
    mov #0x38, r5
    mov.l @(r0, r3), r4
    add #-0x2, r4
    cmp/ge r5, r4
    bt      .L_rp_near_decay_store
    mov r5, r4
.L_rp_near_decay_store:
    mov.l r4, @(r0, r3)
    .byte   0xD2, 0x09    /* mov.l .L_rp_off_near_active, r2 */
    mov #0x0, r7
    mov.l r7, @(r0, r2)
.L_rp_check_far_scroll:
    mov #0x40, r2
    tst r1, r2
    bt      .L_rp_no_far_scroll
    .byte   0xD3, 0x07    /* mov.l .L_rp_off_far_active, r3 */
    mov.l r5, @(r0, r3)
    .byte   0xD3, 0x07    /* mov.l .L_rp_off_far_pos, r3 */
    mov.l @(r0, r3), r4
    .byte   0xD6, 0x07    /* mov.l .L_rp_off_far_prev, r6 */
    mov.w   .L_rp_far_scroll_max, r8
    mov.l r4, @(r0, r6)
    cmp/gt r8, r4
    bt      .L_rp_far_scroll_store
    add #0x5, r4
.L_rp_far_scroll_store:
    bra     .L_rp_epilogue
    mov.l r4, @(r0, r3)

    .global DAT_060304f0
DAT_060304f0:
    .2byte  0x0074
.L_rp_far_scroll_max:
    .2byte  0x00B8
.L_rp_off_near_active:
    .4byte  0x0000006C
.L_rp_off_far_active:
    .4byte  0x00000088
.L_rp_off_far_pos:
    .4byte  0x00000090
.L_rp_off_far_prev:
    .4byte  0x0000008C
.L_rp_no_far_scroll:
    .byte   0xD3, 0x0A    /* mov.l .L_rp_off_far_pos_l, r3 */
    mov.l @(r0, r3), r4
    .byte   0xD6, 0x0A    /* mov.l .L_rp_off_far_prev_l, r6 */
    mov.l r4, @(r0, r6)
    mov #0x38, r3
    add #-0x5, r4
    cmp/ge r3, r4
    bt      .L_rp_far_decay_clamped
    mov r3, r4
.L_rp_far_decay_clamped:
    .byte   0xD3, 0x06    /* mov.l .L_rp_off_far_pos_l, r3 */
    mov.l r4, @(r0, r3)
    .byte   0xD3, 0x07    /* mov.l .L_rp_off_far_active_l, r3 */
    mov.l r7, @(r0, r3)
.L_rp_epilogue:
    lds.l @r15+, pr
    mov.l @r15+, r14
    mov.l @r15+, r13
    mov.l @r15+, r12
    mov.l @r15+, r11
    mov.l @r15+, r10
    mov.l @r15+, r9
    rts
    mov.l @r15+, r8
.L_rp_off_far_pos_l:
    .4byte  0x00000090
.L_rp_off_far_prev_l:
    .4byte  0x0000008C
.L_rp_off_far_active_l:
    .4byte  0x00000088

    .global sym_0603053C
sym_0603053C:
    mov.l r12, @-r15
    mov.l r13, @-r15
