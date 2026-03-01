
    .section .text.FUN_06014468


    .global track_normal_calc
    .type track_normal_calc, @function
track_normal_calc:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov.l   .L_ptr_car_slot_idx, r14
    mov.l   .L_ptr_input_state, r4
    mov.l   .L_mask_low16, r3
    mov.w @(4, r4), r0
    extu.w r0, r0
    xor r3, r0
    and #0xFF, r0
    shar r0
    shar r0
    shar r0
    extu.w r0, r4
    extu.w r4, r2
    cmp/gt r5, r2
    bf      .L_clamp_done
    extu.w r5, r4
.L_clamp_done:
    mov.l @r14, r2
    mov.l   .L_ptr_prev_slot_idx, r3
    mov.l r2, @r3
    extu.w r4, r2
    mov.l r2, @r14
    mov.l   .L_ptr_car_count, r3
    mov #0x3, r2
    mov.l @r3, r3
    cmp/hs r2, r3
    bf      .L_check_changed
    extu.w r4, r4
    mov #0xF, r2
    cmp/ge r2, r4
    bt      .L_force_high
    mov #0x1B, r2
    mov.l r2, @r14
    bra     .L_check_changed
    nop
.L_force_high:
    mov #0x1C, r3
    mov.l r3, @r14
.L_check_changed:
    mov.l @r14, r3
    mov.l   .L_ptr_prev_slot_idx, r2
    mov.l @r2, r2
    cmp/eq r2, r3
    bt      .L_no_sound
    mov.l   .L_snd_slot_change, r5
    mov.l   .L_ptr_sound_dispatch, r3
    jsr @r3
    mov #0x0, r4
.L_no_sound:
    mov.l @r14, r2
    mov.l   .L_ptr_variant_table, r3
    mov.l   .L_ptr_variant_code, r1
    add r3, r2
    mov.b @r2, r2
    extu.b r2, r2
    mov.l r2, @r1
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
    .4byte  0x01C8FFFF
    .4byte  sym_06084AF0
    .4byte  sym_06034FE0
    .4byte  sym_06028430
.L_ptr_car_slot_idx:
    .4byte  sym_06084B08                /* &car_slot_index (32-bit) */
.L_ptr_input_state:
    .4byte  g_pad_state                /* &input_state struct (+4 = button flags) */
.L_mask_low16:
    .4byte  0x0000FFFF                  /* low 16-bit mask */
.L_ptr_prev_slot_idx:
    .4byte  sym_06084B0C                /* &prev_slot_index (32-bit) */
.L_ptr_car_count:
    .4byte  sym_06084B18                /* &active_car_count (32-bit, max 3) */
.L_snd_slot_change:
    .4byte  0xAB111DFF                  /* slot change notification sound */
.L_ptr_sound_dispatch:
    .4byte  sound_cmd_dispatch          /* sound command dispatch function */
.L_ptr_variant_table:
    .4byte  sym_0605AD2C                /* variant code lookup table (byte array) */
.L_ptr_variant_code:
    .4byte  sym_06084B20                /* &current_variant_code (32-bit) */
