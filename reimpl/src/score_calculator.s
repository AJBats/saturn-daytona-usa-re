
    .section .text.FUN_06013948


    .global score_calculator
    .type score_calculator, @function
score_calculator:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    sts.l macl, @-r15
    add #-0x8, r15
    mov.l   .L_fn_transform_apply, r8
    mov.l   .L_anim_timer, r11
    mov.l   .L_fp_one, r12
    mov.w   .L_scale_factor, r14
    mov.w @r11, r3
    add #-0x1, r3
    mov.w r3, @r11
    extu.w r3, r3
    tst r3, r3
    bf      .L_timer_active
    mov #0x2, r3
    mov.l   .L_anim_state, r2
    mov.b r3, @r2
.L_timer_active:
    mov.l   .L_fn_pre_setup, r3
    jsr @r3
    nop
    mov #0x0, r4
    mov r4, r9
    mov.l   .L_anim_entry_base, r5
    mov r5, r13
    add r4, r13
    mov.w   .L_entry_array_size, r2
    add r2, r5
    mov.l r5, @(4, r15)
    mov.l   .L_disp_table_ptr, r3
    mov.l r3, @r15
.L_anim_loop:
    mov.l   .L_fn_pre_transform, r3
    jsr @r3
    mov r13, r10
    mov r12, r6
    mov.w   .L_z_angle_base, r5
    jsr @r8
    mov #0x0, r4
    mov.w @(24, r10), r0
    mov.l   .L_fn_rot_z, r3
    jsr @r3
    mov r0, r4
    mov.w   .L_y_angle_scale, r5
    mov.w @r11, r4
    mov.l   .L_fn_fpmul, r3
    extu.w r4, r4
    mul.l r12, r4
    jsr @r3
    sts macl, r4
    mov.l @r10, r5
    mov #0x0, r4
    add r0, r5
    jsr @r8
    mov r4, r6
    mov.w @(24, r10), r0
    mov.l   .L_fn_rot_z, r3
    mov r0, r4
    jsr @r3
    neg r4, r4
    mov.w @r11, r4
    mov.l   .L_fn_rot_y, r3
    extu.w r4, r4
    shll8 r4
    shll2 r4
    jsr @r3
    shll r4
    mov r14, r6
    mov r14, r5
    mov.l   .L_fn_scale, r3
    jsr @r3
    mov r14, r4
    mov #0x4, r5
    mov r9, r10
    mov.l   .L_obj_table, r4
    mov.l   .L_fn_chain_a, r3
    add r9, r4
    jsr @r3
    mov.l @r4, r4
    mov #0x1, r6
    mov.l @r15, r5
    mov.l   .L_disp_table, r4
    mov.l   .L_fn_chain_b, r3
    mov.w @r5, r5
    add r10, r4
    jsr @r3
    mov.l @r4, r4
    add #0x20, r13
    mov.l   .L_global_counter, r2
    mov.l   .L_global_counter, r3
    mov.l @r2, r2
    add #-0x30, r2
    mov.l r2, @r3
    mov.l @(4, r15), r1
    cmp/hs r1, r13
    bf/s    .L_anim_loop
    add #0x4, r9
    add #0x8, r15
    lds.l @r15+, macl
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_scale_factor:
    .2byte  0x4CCC                      /* ~0.3 uniform scale factor (16.16) */
.L_entry_array_size:
    .2byte  0x03A0                      /* total animation entry array size */
.L_z_angle_base:
    .2byte  0x8000                      /* 180° base Z rotation angle */
.L_y_angle_scale:
    .2byte  0x07AE                      /* Y angle scale factor */
.L_fn_transform_apply:
    .4byte  sym_06026E2E               /* transform dispatch function */
.L_anim_timer:
    .4byte  sym_06084AF4               /* animation timer (16-bit, decrements each frame) */
.L_fp_one:
    .4byte  0x00010000                  /* 1.0 (16.16 fixed-point) */
.L_anim_state:
    .4byte  sym_06084AF2               /* animation state: 2 = complete (byte) */
.L_fn_pre_setup:
    .4byte  sym_06026E0C               /* pre-animation setup */
.L_anim_entry_base:
    .4byte  sym_0605AD5C               /* animation entry array (0x20 bytes each) */
.L_disp_table_ptr:
    .4byte  sym_06089E4A               /* display table base pointer */
.L_fn_pre_transform:
    .4byte  sym_06026DBC               /* per-object pre-transform setup */
.L_fn_rot_z:
    .4byte  mat_rot_z                  /* Z-axis rotation */
.L_fn_fpmul:
    .4byte  fpmul                      /* fixed-point multiply */
.L_fn_rot_y:
    .4byte  mat_rot_y                  /* Y-axis rotation */
.L_fn_scale:
    .4byte  mat_scale_columns          /* uniform column scale */
.L_obj_table:
    .4byte  sym_06062338               /* object transform table A */
.L_fn_chain_a:
    .4byte  sym_06031D8C               /* transform chain dispatch A */
.L_disp_table:
    .4byte  sym_060622C0               /* display transform table B */
.L_fn_chain_b:
    .4byte  sym_06031A28               /* transform chain dispatch B */
.L_global_counter:
    .4byte  sym_06089EDC               /* global animation counter (dec by 0x30/iter) */
