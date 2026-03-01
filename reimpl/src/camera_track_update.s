
    .section .text.FUN_0601450C


    .global camera_track_update
    .type camera_track_update, @function
camera_track_update:
    mov.l r14, @-r15
    mov.l   .L_ptr_car_slot, r14
    mov.l   .L_ptr_button_state, r4
    mov.l   .L_ptr_frame_counter, r0
    mov.w @r4, r4
    mov.l @r0, r0
    tst #0x3, r0
    bf/s    .L_apply_clamp
    mov.l @r14, r5
    extu.w r4, r3
    mov.w   DAT_06014594, r2
    and r2, r3
    tst r3, r3
    bt      .L_check_up
    mov #0x0, r2
    mov.l @r14, r3
    cmp/hi r2, r3
    bf      .L_apply_clamp
    mov.l @r14, r2
    add #-0x1, r2
    bra     .L_apply_clamp
    mov.l r2, @r14
.L_check_up:
    extu.w r4, r4
    mov.l   .L_mask_up_button, r2
    and r2, r4
    tst r4, r4
    bt      .L_apply_clamp
    mov.l @r14, r3
    mov #0x1C, r2
    cmp/hs r2, r3
    bt      .L_apply_clamp
    mov.l @r14, r2
    add #0x1, r2
    mov.l r2, @r14
.L_apply_clamp:
    mov.l   .L_ptr_car_count, r3
    mov #0x3, r2
    mov.l @r3, r3
    cmp/hs r2, r3
    bf      .L_lookup_variant
    mov #0x1B, r4
    mov.l @r14, r2
    cmp/hs r4, r2
    bt      .L_clamp_upper
    bra     .L_lookup_variant
    mov.l r4, @r14
.L_clamp_upper:
    mov #0x1C, r3
    mov.l @r14, r2
    cmp/hi r3, r2
    bf      .L_lookup_variant
    mov #0x1C, r3
    mov.l r3, @r14
.L_lookup_variant:
    mov.l @r14, r2
    mov.l   .L_ptr_variant_table, r3
    mov.l   .L_ptr_variant_code, r1
    add r3, r2
    mov.b @r2, r2
    extu.b r2, r2
    mov.l r2, @r1
    mov.l @r14, r0
    cmp/eq r0, r5
    bt      .L_no_change
    mov.l   .L_snd_slot_change, r5
    mov #0x0, r4
    mov.l   .L_fn_sound_dispatch, r3
    jmp @r3
    mov.l @r15+, r14
.L_no_change:
    rts
    mov.l @r15+, r14

    .global DAT_06014594
DAT_06014594:
    .2byte  0x4000
    .2byte  0xFFFF
.L_ptr_car_slot:
    .4byte  sym_06084B08
.L_ptr_button_state:
    .4byte  g_pad_state
.L_ptr_frame_counter:
    .4byte  sym_0607EBC8
.L_mask_up_button:
    .4byte  0x00008000                  /* 0x8000 = Up button mask (32-bit for AND) */
.L_ptr_car_count:
    .4byte  sym_06084B18
.L_ptr_variant_table:
    .4byte  sym_0605AD2C
.L_ptr_variant_code:
    .4byte  sym_06084B20
.L_snd_slot_change:
    .4byte  0xAB111DFF
.L_fn_sound_dispatch:
    .4byte  sound_cmd_dispatch
