
    .section .text.FUN_0602E350


    .global rbg_rot_matrix_calc
    .type rbg_rot_matrix_calc, @function
rbg_rot_matrix_calc:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    mov.l   _pool_car_struct_ptr, r0
    mov.l @r0, r0
    mov.w   _wpool_src_field_off, r1
    mov.l @(r0, r1), r3
    mov.w   DAT_0602e376, r1
    mov.l r3, @(r0, r1)
    mov.w   _wpool_cmp_field_off, r1
    mov.l @(r0, r1), r3
    mov.l   _pool_state_threshold, r4
    cmp/gt r3, r4
    bt      .L_0602E36E
.L_0602E36E:
    bra     .L_0602E3F4
    nop

    .global DAT_0602e372
DAT_0602e372:
    clrmac
_wpool_src_field_off:
    .2byte  0x0030

    .global DAT_0602e376
DAT_0602e376:
    .2byte  0x0020
_wpool_cmp_field_off:
    .2byte  0x0008
    .2byte  0x0000
    .4byte  sound_cmd_dispatch
_pool_car_struct_ptr:
    .4byte  sym_0607E940
    .4byte  sym_0602E450
    .4byte  sym_0602E4BC
    .4byte  collision_detect_main
    .4byte  0x00000000
    .4byte  sym_0603053C
    .4byte  checkpoint_detect
_pool_state_threshold:
    .4byte  0x00000096
    .4byte  0xD10BD30C
    .4byte  0x2132D10C
    .4byte  0x6212D10C
    .4byte  0x2122D10C
    .4byte  0xD20C2122
    .4byte  0xD10C9308
    .4byte  0x2132D30C
    .4byte  0xD10C0136
    .4byte  0x93039103
    .4byte  0x0136AF19
    .4byte  0x00090000
    .4byte  0x01B40000
    .4byte  sym_0605A1D0
    .4byte  0x00010000
    .4byte  sym_06082A34
    .4byte  sym_06063E20
    .4byte  sym_06082A30
    .4byte  0x00000000
    .4byte  sym_0605A1C4
    .4byte  0x00000001
    .4byte  sym_0607EAC8
.L_0602E3F4:
    mov.l   _pool_rbg_coeff_ptr, r1
    mov.l @r1, r3
    mov.l   _pool_rbg_threshold, r4
    cmp/gt r3, r4
    .byte   0x89, 0x1C    /* bt 0x0602E438 (external) */
    mov.l   _pool_display_flags_ptr, r2
    mov.b @r2, r2
    mov.l   _pool_flag_bit2_mask, r1
    and r1, r2
    tst r2, r2
    bt      .L_0602E42C
    mov.l   _pool_render_state_ptr, r0
    mov.l   _pool_zero_value, r1
    mov.b r1, @r0
    .byte   0xA0, 0x12    /* bra 0x0602E438 (external) */
    nop
_pool_rbg_coeff_ptr:
    .4byte  sym_06082A2C
_pool_rbg_threshold:
    .4byte  0x00000028
_pool_display_flags_ptr:
    .4byte  sym_06082A25
_pool_flag_bit2_mask:
    .4byte  0x00000004
_pool_render_state_ptr:
    .4byte  sym_06082A26
_pool_zero_value:
    .4byte  0x00000000
.L_0602E42C:
    .byte   0xDD, 0x07    /* mov.l .L_pool_0602E44C, r13 */
