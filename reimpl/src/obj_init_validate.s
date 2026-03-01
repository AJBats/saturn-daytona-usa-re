
    .section .text.FUN_06040010


    .global validation_dispatch
    .type validation_dispatch, @function
validation_dispatch:
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_ptr_game_state, r14
    mov.l r4, @r15
    mov.l @r14, r3
    mov.w   DAT_0604009e, r0
    mov.l @(r0, r3), r1
    and r2, r1
    mov.l r1, @(r0, r3)
    mov.l @r14, r4
    mov.w   .L_off_road_check_base, r3
    add r3, r4
    mov.l   .L_fn_road_seg_check, r3
    jsr @r3
    mov.l @r15, r5
    mov r0, r4
    tst r4, r4
    bf      .L_check_param
    mov.l @r14, r3
    mov.w   DAT_0604009e, r0
    mov.l @(r0, r3), r0
    or #0x1, r0
    mov.w   DAT_0604009e, r1
    add r3, r1
    mov.l r0, @r1
.L_check_param:
    mov.l @r15, r0
    tst r0, r0
    bt/s    .L_param_null
    mov.l @r14, r3
    bra     .L_store_result
    mov #0x17, r2
.L_param_null:
    mov #-0x1, r2
.L_store_result:
    mov.w   .L_off_result_field, r0
    mov.l r2, @(r0, r3)
    bra     .L_dispatch_retcode
    mov r4, r0
.L_ret_success:
    mov #0x0, r0
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_ret_err_0x17:
    mov #-0x17, r0
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_ret_err_2:
    mov #-0x2, r0
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_ret_err_3:
    mov #-0x3, r0
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_ret_err_1:
    mov #-0x1, r0
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_dispatch_retcode:
    cmp/eq #-0xF, r0
    bt      .L_ret_err_3
    cmp/eq #-0xE, r0
    bt      .L_ret_err_2
    cmp/eq #-0xD, r0
    bt      .L_ret_err_0x17
    cmp/eq #0x0, r0
    bt      .L_ret_success
    bra     .L_ret_err_1
    nop

    .global DAT_0604009e
DAT_0604009e:
    .2byte  0x00C4                      /* state struct offset: status flags */
.L_off_road_check_base:
    .2byte  0x00D0                      /* state struct offset: road check base */
.L_off_result_field:
    .2byte  0x00C8                      /* state struct offset: result field */
.L_ptr_game_state:
    .4byte  sym_060A4D14                /* -> game state structure pointer */
.L_fn_road_seg_check:
    .4byte  road_segment_check          /* track road segment validator */
    .4byte  0x7F044F26
    .4byte  0x000B6EF6

.L_stride_from_flags:
    mov #0x4, r3
    and r4, r3
    tst r3, r3
    bt      .L_check_bit3
    mov.w   .L_stride_wide, r4
    bra     .L_stride_return
    nop
.L_check_bit3:
    mov #0x8, r2
    mov.w   .L_stride_default, r5
    and r2, r4
    tst r4, r4
    bt      .L_use_default_stride
    bra     .L_stride_return
    mov r5, r4
.L_use_default_stride:
    mov r5, r4
.L_stride_return:
    rts
    mov r4, r0

    .global obj_init_validate
    .type obj_init_validate, @function
obj_init_validate:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov r5, r13
    mov.l r12, @-r15
    mov.l r11, @-r15
    sts.l pr, @-r15
    mov r6, r11
    add #-0xC, r15
    mov.w   .L_stride_default, r12
    tst r13, r13
    bf/s    .L_copy_from_source
    mov r4, r14
    mov r15, r5
    mov.l   .L_fp_0x4000_0000, r3
    or r11, r3
    mov.l r3, @r14
    mov.l   .L_fn_track_shadow_test, r3
    jsr @r3
    mov r11, r4
    tst r0, r0
    bt      .L_shadow_ok
    bra     .L_epilogue
    mov #0x0, r0
.L_stride_wide:
    .2byte  0x0914                      /* wide stride (bit 2 surface type) */
.L_stride_default:
    .2byte  0x0800                      /* default stride */
.L_fp_0x4000_0000:
    .4byte  0x40000000                  /* 0.25 (2.30) or 16384.0 (16.16) */
.L_fn_track_shadow_test:
    .4byte  track_shadow_test           /* ground shadow/surface query */
.L_shadow_ok:
    mov r15, r3
    mov r15, r4
    mov.l @r3, r2
    mov.l r2, @(4, r14)
    mov.b @(11, r4), r0
    mov r0, r4
    bsr     .L_stride_from_flags
    extu.b r4, r4
    mov.l r0, @(12, r14)
    mov r15, r1
    mov r0, r3
    mov.l   .L_fn_udiv, r2
    mov.l @(4, r1), r1
    add r3, r1
    jsr @r2
    add #-0x1, r1
    mov.l r0, @(16, r14)
    mov r15, r4
    mov.l   .L_fn_fixed_mod, r3
    mov.l @(4, r4), r4
    mov r4, r1
    jsr @r3
    mov r12, r0
    mov r12, r1
    mov.l   .L_fn_fixed_mod, r3
    sub r0, r1
    jsr @r3
    mov r12, r0
    mov.l r0, @(20, r14)
    mov r15, r2
    mov.b @(10, r2), r0
    mov r0, r3
    mov #0x1C, r0
    mov.b r3, @(r0, r14)
    mov r15, r3
    mov.b @(11, r3), r0
    mov r0, r2
    mov #0x1D, r0
    mov.b r2, @(r0, r14)
    mov r15, r3
    mov.b @(8, r3), r0
    mov r0, r2
    mov #0x1E, r0
    mov.b r2, @(r0, r14)
    mov r15, r3
    mov.b @(9, r3), r0
    mov r0, r2
    mov #0x1F, r0
    bra     .L_zero_trailing_fields
    mov.b r2, @(r0, r14)
.L_copy_from_source:
    mov.l r11, @r14
    mov.l @r13, r2
    mov.l r2, @(4, r14)
    mov.b @(11, r13), r0
    mov r0, r4
    bsr     .L_stride_from_flags
    extu.b r4, r4
    mov.l r0, @(12, r14)
    mov.l @(4, r13), r4
    mov.w   DAT_060401e8, r2
    mov r4, r1
    add r4, r2
    shlr8 r2
    shlr2 r2
    shlr r2
    mov.l r2, @(16, r14)
    mov.l   .L_fn_fixed_mod, r3
    jsr @r3
    mov r12, r0
    mov r12, r1
    mov.l   .L_fn_fixed_mod, r3
    sub r0, r1
    jsr @r3
    mov r12, r0
    mov.l r0, @(20, r14)
    mov.b @(10, r13), r0
    mov r0, r2
    mov #0x1C, r0
    mov.b r2, @(r0, r14)
    mov.b @(11, r13), r0
    mov r0, r3
    mov #0x1D, r0
    mov.b r3, @(r0, r14)
    mov.b @(8, r13), r0
    mov r0, r3
    mov #0x1E, r0
    mov.b r3, @(r0, r14)
    mov.b @(9, r13), r0
    mov r0, r3
    mov #0x1F, r0
    mov.b r3, @(r0, r14)
.L_zero_trailing_fields:
    mov #0x0, r4
    mov.l r4, @(24, r14)
    mov.l r4, @(36, r14)
    mov r4, r3
    mov.l r4, @(32, r14)
    mov.l   .L_fp_max, r2
    mov.l r2, @(40, r14)
    mov r14, r0
.L_epilogue:
    add #0xC, r15
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global sym_060401E4
sym_060401E4:
    rts
    mov.l r5, @(24, r4)

    .global DAT_060401e8
DAT_060401e8:
    .2byte  0x07FF                      /* rounding mask for segment division */
    .2byte  0xFFFF                      /* padding / alignment */
.L_fn_udiv:
    .4byte  input_proc_complete         /* unsigned 32-bit division */
.L_fn_fixed_mod:
    .4byte  sym_06036BE4                /* signed fixed-point modulo */
.L_fp_max:
    .4byte  0x7FFFFFFF                  /* max positive 16.16 */
