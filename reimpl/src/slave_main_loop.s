
    .section .text.FUN_06034F08


    .global slave_main_loop
    .type slave_main_loop, @function
slave_main_loop:
    sts.l pr, @-r15
    add #-0x8, r15
    mov #0x1, r3
    mov.l r3, @(4, r15)
    mov #0x0, r3
    mov.l r3, @r15
    stc sr, r0
    mov.w   .L_mask_sr_imask, r3
    and r3, r0
    or #0xF0, r0
    ldc r0, sr
    mov #0x0, r2
    mov.w   .L_reg_tier, r3
    mov.w r2, @r3
    mov #0x0, r2
    mov.w   .L_reg_iprb, r3
    mov.w r2, @r3
    mov #0x1, r2
    mov.w   .L_reg_tier_byte, r3
    mov.b r2, @r3
    bra     .L_loop_top
    nop
.L_poll_icf:
    mov.w   .L_reg_ftcsr, r0
    mov.b @r0, r0
    extu.b r0, r0
    and #0x80, r0
    mov.w   .L_icf_bit, r3
    cmp/eq r3, r0
    bf      .L_loop_top
    mov #0x0, r3
    mov.w   .L_reg_ftcsr, r2
    mov.b r3, @r2
    mov.l   .L_ptr_callback, r0
    mov.l @r0, r0
    tst r0, r0
    bt      .L_clear_callback
    mov.l   .L_ptr_callback_ct, r3
    mov.l @r3, r2
    jsr @r2
    nop
.L_clear_callback:
    mov #0x0, r3
    mov.l   .L_ptr_callback, r2
    mov.l r3, @r2
.L_loop_top:
    bra     .L_poll_icf
    nop
.L_mask_sr_imask:
    .2byte  0xFF0F
.L_reg_tier:
    .2byte  0xFEE2
.L_reg_iprb:
    .2byte  0xFE60
.L_reg_tier_byte:
    .2byte  0xFE10
.L_reg_ftcsr:
    .2byte  0xFE11
.L_icf_bit:
    .2byte  0x0080
    .2byte  0xFFFF
.L_ptr_callback:
    .4byte  sym_06063574
.L_ptr_callback_ct:
    .4byte  sym_06063574 + 0x20000000

    .global sym_06034F78
sym_06034F78:
    mov.l r1, @-r15
    mov.l r3, @-r15
    swap.b r1, r3
    extu.b r1, r1
    mov.l r4, @-r15
    extu.b r3, r3
    mov.l r5, @-r15
    mov r1, r4
    mov.l r6, @-r15
    mov #0x0, r5
    mov #-0x1, r6
.L_build_val_mask:
    shll r5
    shll r6
    add #-0x1, r4
    add #0x1, r5
    cmp/pl r4
    bf      .L_shift_to_pos
    shll r5
    shll r6
    add #-0x1, r4
    add #0x1, r5
    cmp/pl r4
    bt      .L_build_val_mask
.L_shift_to_pos:
    and r5, r0
    mov #0x20, r4
    sub r1, r4
    sub r3, r4
    mov r0, r5
    tst r4, r4
    bt      .L_merge_write
.L_shift_up_loop:
    shll r6
    shll r5
    add #-0x1, r4
    add #0x1, r6
    cmp/pl r4
    bf      .L_merge_write
    shll r6
    shll r5
    add #-0x1, r4
    add #0x1, r6
    cmp/pl r4
    bt      .L_shift_up_loop
.L_merge_write:
    mov.l @r2, r4
    and r4, r6
    or r6, r5
    mov.l r5, @r2
    mov.l @r15+, r6
    mov.l @r15+, r5
    mov.l @r15+, r4
    mov.l @r15+, r3
    rts
    mov.l @r15+, r1

    .global sym_06034FE0
sym_06034FE0:
    mov.l r2, @-r15
    mov.l r3, @-r15
    mov.w   .L_reg_frt_base, r3
    mov #0x0, r2
    mov.l r0, @r3
    add #0x8, r3
    mov.l r2, @r3
    mov.l r1, @-r3
    add #0x10, r3
    mov.l @r3, r0
    mov.l @r15+, r3
    rts
    mov.l @r15+, r2
.L_reg_frt_base:
    .2byte  0xFF00

    .global sym_06034FFC
sym_06034FFC:
    tst r0, r0
    mov.l r2, @-r15
    bt      .L_sdiv_by_zero
    mov.l r3, @-r15
    mov #0x0, r2
    div0s r2, r1
    subc r3, r3
    subc r2, r1
    div0s r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    addc r2, r1
    mov r1, r0
    mov.l @r15+, r3
    rts
    mov.l @r15+, r2
.L_sdiv_by_zero:
    mov.l   .L_ptr_div_error, r1
    mov.l   .L_div_error_code, r2
    mov #0x0, r0
    mov.l r2, @r1
    rts
    mov.l @r15+, r2
    .2byte  0x0009
.L_ptr_div_error:
    .4byte  sym_060A246C
.L_div_error_code:
    .4byte  0x0000044E

    .global sym_060350B0
sym_060350B0:
    tst r0, r0
    bt      .L_udiv_by_zero
    mov.l r3, @-r15
    mov #0x0, r3
    mov.l r4, @-r15
    mov r0, r4
    div0u
    rotcl r1
    div1 r4, r3
    rotcl r1
    div1 r4, r3
    rotcl r1
    div1 r4, r3
    rotcl r1
    div1 r4, r3
    rotcl r1
    div1 r4, r3
    rotcl r1
    div1 r4, r3
    rotcl r1
    div1 r4, r3
    rotcl r1
    div1 r4, r3
    rotcl r1
    div1 r4, r3
    rotcl r1
    div1 r4, r3
    rotcl r1
    div1 r4, r3
    rotcl r1
    div1 r4, r3
    rotcl r1
    div1 r4, r3
    rotcl r1
    div1 r4, r3
    rotcl r1
    div1 r4, r3
    rotcl r1
    div1 r4, r3
    rotcl r1
    div1 r4, r3
    rotcl r1
    div1 r4, r3
    rotcl r1
    div1 r4, r3
    rotcl r1
    div1 r4, r3
    rotcl r1
    div1 r4, r3
    rotcl r1
    div1 r4, r3
    rotcl r1
    div1 r4, r3
    rotcl r1
    div1 r4, r3
    rotcl r1
    div1 r4, r3
    rotcl r1
    div1 r4, r3
    rotcl r1
    div1 r4, r3
    rotcl r1
    div1 r4, r3
    rotcl r1
    div1 r4, r3
    rotcl r1
    div1 r4, r3
    rotcl r1
    div1 r4, r3
    rotcl r1
    div1 r4, r3
    bf      .L_udiv_add_remainder
    mov r3, r0
    mov.l @r15+, r4
    rts
    mov.l @r15+, r3
.L_udiv_add_remainder:
    add r3, r0
    mov.l @r15+, r4
    rts
    mov.l @r15+, r3
.L_udiv_by_zero:
    mov.l r2, @-r15
    mov.l   .L_ptr_udiv_error, r1
    mov.l   .L_udiv_error_code, r2
    mov #0x0, r0
    mov.l r2, @r1
    rts
    mov.l @r15+, r2
    .2byte  0x0009
.L_ptr_udiv_error:
    .4byte  sym_060A246C
.L_udiv_error_code:
    .4byte  0x0000044E

    .global sym_06035168
sym_06035168:
    mov.l r3, @-r15
    mov #0x40, r3
    cmp/hs r0, r3
    bf      .L_memcpy_long_loop
    mov.l   .L_ptr_jump_table, r3
    mov.l @(r0, r3), r3
    jmp @r3
    nop
.L_ptr_jump_table:
    .4byte  sym_060351C4
    .2byte  0x0009
    .global loc_0603517E
loc_0603517E:
    mov.l @(60, r2), r0
    mov.l r0, @(60, r1)

    .global loc_06035182
loc_06035182:
    mov.l @(56, r2), r0
    mov.l r0, @(56, r1)

    .global loc_06035186
loc_06035186:
    mov.l @(52, r2), r0
    mov.l r0, @(52, r1)

    .global loc_0603518A
loc_0603518A:
    mov.l @(48, r2), r0
    mov.l r0, @(48, r1)

    .global loc_0603518E
loc_0603518E:
    mov.l @(44, r2), r0
    mov.l r0, @(44, r1)

    .global loc_06035192
loc_06035192:
    mov.l @(40, r2), r0
    mov.l r0, @(40, r1)

    .global loc_06035196
loc_06035196:
    mov.l @(36, r2), r0
    mov.l r0, @(36, r1)

    .global loc_0603519A
loc_0603519A:
    mov.l @(32, r2), r0
    mov.l r0, @(32, r1)

    .global loc_0603519E
loc_0603519E:
    mov.l @(28, r2), r0
    mov.l r0, @(28, r1)

    .global loc_060351A2
loc_060351A2:
    mov.l @(24, r2), r0
    mov.l r0, @(24, r1)

    .global loc_060351A6
loc_060351A6:
    mov.l @(20, r2), r0
    mov.l r0, @(20, r1)

    .global loc_060351AA
loc_060351AA:
    mov.l @(16, r2), r0
    mov.l r0, @(16, r1)

    .global loc_060351AE
loc_060351AE:
    mov.l @(12, r2), r0
    mov.l r0, @(12, r1)

    .global loc_060351B2
loc_060351B2:
    mov.l @(8, r2), r0
    mov.l r0, @(8, r1)

    .global loc_060351B6
loc_060351B6:
    mov.l @(4, r2), r0
    mov.l r0, @(4, r1)

    .global loc_060351BA
loc_060351BA:
    mov.l @r2, r0
    mov.l r0, @r1

    .global loc_060351BE
loc_060351BE:
    rts
    mov.l @r15+, r3
    .2byte  0x0009

    .global sym_060351C4
sym_060351C4:
    .4byte  loc_060351BE
    .4byte  loc_060351BA
    .4byte  loc_060351B6
    .4byte  loc_060351B2
    .4byte  loc_060351AE
    .4byte  loc_060351AA
    .4byte  loc_060351A6
    .4byte  loc_060351A2
    .4byte  loc_0603519E
    .4byte  loc_0603519A
    .4byte  loc_06035196
    .4byte  loc_06035192
    .4byte  loc_0603518E
    .4byte  loc_0603518A
    .4byte  loc_06035186
    .4byte  loc_06035182
    .4byte  loc_0603517E
.L_memcpy_long_loop:
    mov.l r2, @-r15
    mov r2, r3
    add r0, r3
.L_copy_pair:
    mov.l @r2+, r0
    cmp/hs r2, r3
    bf      .L_memcpy_long_done
    mov.l r0, @r1
    mov.l @r2+, r0
    cmp/hs r2, r3
    bf      .L_memcpy_long_done
    mov.l r0, @(4, r1)
    bra     .L_copy_pair
    add #0x8, r1
.L_memcpy_long_done:
    mov.l @r15+, r2
    rts
    mov.l @r15+, r3

    .global sym_06035228
sym_06035228:
    mov.l r2, @-r15
    mov.l r3, @-r15
    mov.l r4, @-r15
    cmp/eq #0x0, r0
    bt      .L_bytecpy_done
    mov r2, r4
    add r0, r4
.L_copy_4bytes:
    mov.b @r2+, r0
    mov.b r0, @r1
    cmp/hi r2, r4
    bf      .L_bytecpy_done
    mov.b @r2+, r0
    mov.b r0, @(1, r1)
    cmp/hi r2, r4
    bf      .L_bytecpy_done
    mov.b @r2+, r0
    mov.b r0, @(2, r1)
    cmp/hi r2, r4
    bf      .L_bytecpy_done
    mov.b @r2+, r0
    mov.b r0, @(3, r1)
    cmp/hi r2, r4
    add #0x4, r1
    bt      .L_copy_4bytes
.L_bytecpy_done:
    mov.l @r15+, r4
    mov.l @r15+, r3
    rts
    mov.l @r15+, r2

    .global sym_06035260
sym_06035260:
    mov.b @(r0, r0), r14
    .word 0x0A08
    .4byte  loc_06040200
    .4byte  0x201E1C1A
    .4byte  0x18161412
    .4byte  0x3432302E
    .4byte  0x2C2A2826
    .4byte  0x403E3C3A
    .4byte  0x4856626C

    .global sym_06035280
sym_06035280:
    mov.l r2, @-r15
    cmp/pz r1
    bf/s    .L_shl_ret
    mov #0x20, r2
    cmp/ge r2, r1
    bt      .L_shl_overflow
    mov.l   .L_ptr_shl_offsets, r2
    add r1, r2
    mov.b @r2, r2
    mov.l   .L_ptr_shl_base, r1
    add r2, r1
    jmp @r1
    nop
    .2byte  0x0009
.L_ptr_shl_base:
    .4byte  sym_060352AA
.L_ptr_shl_offsets:
    .4byte  sym_06035260
.L_shl_overflow:
    mov #0x0, r0
    rts
    mov.l @r15+, r2

    .global sym_060352AA
sym_060352AA:
    shll r0
    shll r0
    shll r0
    shll r0
    shll r0
    shll r0
    shll r0
.L_shl_ret:
    rts
    mov.l @r15+, r2
    .4byte  0x40004000
    .4byte  0x40004000
    .4byte  0x40004000
    .4byte  0x40004018
    .4byte  0x000B62F6
    .4byte  0x40004000
    .4byte  0x40004000
    .4byte  0x40004000
    .4byte  0x40004028
    .4byte  0x000B62F6
    .4byte  0x40004000
    .4byte  0x40004018
    .4byte  0x4028000B
    .4byte  0x62F6C90F
    .4byte  0x40054005
    .4byte  0x40054005
    .4byte  0x000B62F6
    .4byte  0xC9074005
    .4byte  0x40054005
    .4byte  0x000B62F6
    .4byte  0xC9034005
    .4byte  0x4005000B
    .4byte  0x62F6C901
    .4byte  0x4005000B
    .4byte  0x62F60000
    .4byte  0xFCFAF8F6
    .4byte  0xF4F2F0EE
    .4byte  0xECEAE8E6
    .4byte  0xE4E2E0DE
    .4byte  0xDCDAD8D6
    .4byte  0xD4D2D0CE

    .global sym_06035338
sym_06035338:
    mov.b @(r0, r0), r0
    mov.l r3, @-r2
    .word 0x4858
    mov.l @r7, r6

    .global sym_06035340
sym_06035340:
    mov.l r2, @-r15
    cmp/pz r1
    bf/s    .L_shra_ret
    mov #0x20, r2
    cmp/ge r2, r1
    bt      .L_shra_ge32
    mov r0, r2
    rotl r2
    bf      .L_shra_small_check
.L_shra_dispatch:
    mov.l   .L_ptr_shra_offsets, r2
    add #-0x18, r1
    add r2, r1
    mov.b @r1, r2
    mov.l   .L_ptr_shra_base, r1
    add r2, r1
    jmp @r1
    nop
.L_shra_small_check:
    mov #0x8, r2
    cmp/gt r2, r1
    bf      .L_shra_dispatch
    mov.l   .L_fn_shra_large, r2
    jmp @r2
    nop
    .2byte  0x0009
.L_ptr_shra_offsets:
    .4byte  sym_06035338
.L_ptr_shra_base:
    .4byte  sym_060353BE
.L_fn_shra_large:
    .4byte  sym_06036068
.L_shra_ge32:
    shll r0
    bt      .L_shra_neg_max
    mov #0x0, r0
    rts
    mov.l @r15+, r2
.L_shra_neg_max:
    mov #-0x1, r0
    rts
    mov.l @r15+, r2
    .4byte  0x40214021
    .4byte  0x40214021
    .4byte  0x40214021
    .4byte  0x40214021
    .4byte  0x40214021
    .4byte  0x40214021
    .4byte  0x40214021
    .4byte  0x40214021
    .4byte  0x40214021
    .4byte  0x40214021
    .4byte  0x40214021
    .2byte  0x4021
.L_shra_ret:
    rts
    mov.l @r15+, r2

    .global sym_060353BE
sym_060353BE:
    swap.w r0, r1
    swap.b r1, r0
    mov #-0x80, r1
    or r1, r0
    rts
    mov.l @r15+, r2
    .2byte  0x4004
    .4byte  0x40044004
    .4byte  0x40044004
    .4byte  0x40044004
    .4byte  0xE1C0201B
    .4byte  0x000B62F6
    .4byte  0x40044004
    .4byte  0x40044004
    .4byte  0x40044004
    .4byte  0xE1E0201B
    .4byte  0x000B62F6
    .4byte  0x40044004
    .4byte  0x40044004
    .4byte  0x4004E1F0
    .4byte  0x201B000B
    .4byte  0x62F64004
    .4byte  0x40044004
    .4byte  0x4004E1F8
    .4byte  0x201B000B
    .4byte  0x62F64004
    .4byte  0x40044004
    .4byte  0xE1FC201B
    .4byte  0x000B62F6
    .4byte  0x40044004
    .4byte  0xE1FE201B
    .4byte  0x000B62F6
    .4byte  0xE0FF000B
    .4byte  0x62F60000

    .global sym_06035438
sym_06035438:
    cmp/pl r4
    bf      .L_negate
    bra     .L_abs_ret
    mov r4, r0
.L_negate:
    neg r4, r0
.L_abs_ret:
    rts
    nop
    .2byte  0x0000
    .4byte  0x2F062F46
    .4byte  0x2F562F66
    .4byte  0x2F7654F6
    .4byte  0x55F756F8
    .4byte  0x57F9D0B4
    .4byte  0xA061260A

    .global sym_06035460
sym_06035460:
    mov.l r0, @-r15
    mov.l r4, @-r15
    mov.l r5, @-r15
    mov.l r6, @-r15
    mov.l r7, @-r15
    mov.l @(24, r15), r6
    mov.l @(28, r15), r7
    mov.l @(32, r15), r4
    mov.l @(36, r15), r5
    mov.l   .L_fp_min, r0
    bra     .L_fadd_entry
    xor r0, r6
.L_exp_a_max:
    tst r4, r4
    bf      .L_result_zero
    tst r5, r5
    bf      .L_result_zero
    cmp/eq r3, r9
    bf      .L_nan_propagate
    tst r7, r7
    bf      .L_result_zero
    div0s r10, r11
    bf      .L_nan_propagate
.L_result_zero:
    mov #0x0, r10
    mov #0x0, r4
    bra     .L_fadd_epilog
    mov #0x8, r5
.L_nan_propagate:
    bra     .L_fadd_epilog
    nop
.L_exp_b_zero:
    tst r8, r8
    bf      .L_check_a_denorm
    tst r4, r4
    bf      .L_swap_and_norm
    tst r5, r5
    bf      .L_swap_and_norm
    tst r7, r7
    bf      .L_copy_b_to_result
    bra     .L_fadd_epilog
    and r11, r10
.L_check_a_denorm:
    tst r6, r6
    bf      .L_norm_b_start
    tst r7, r7
    bf      .L_norm_b_start
    bra     .L_shift_left_3
    nop
.L_swap_and_norm:
    tst r6, r6
    bf      .L_norm_a_start
    tst r7, r7
    bf      .L_norm_a_start
    bra     .L_shift_left_3
    nop
.L_copy_b_to_result:
    mov r6, r4
    mov r7, r5
    mov r9, r8
    mov r11, r10
.L_shift_left_3:
    shll r5
    rotcl r4
    shll r5
    rotcl r4
    shll r5
    bra     .L_fadd_epilog
    rotcl r4
.L_norm_a_start:
    mov.l   .L_fp_sixteen, r3
    shll r5
    rotcl r4
    cmp/ge r3, r4
    bt      .L_norm_b_start
.L_norm_a_loop:
    shll r5
    rotcl r4
    cmp/ge r3, r4
    bf/s    .L_norm_a_loop
    add #-0x1, r8
.L_norm_b_start:
    mov.l   .L_fp_sixteen, r3
    shll r7
    rotcl r6
    cmp/ge r3, r6
    bt      .L_align_mantissas
.L_norm_b_loop:
    shll r7
    rotcl r6
    cmp/ge r3, r6
    bf/s    .L_norm_b_loop
    add #-0x1, r9
.L_align_mantissas:
    bra     .L_shift_up_3
    nop
    .2byte  0xE800
    .4byte  0xE400A0DE
    .4byte  0xE5000009
    .4byte  0x2F062F46
    .4byte  0x2F562F66
    .4byte  0x2F7654F6
    .4byte  0x55F756F8
    .2byte  0x57F9
.L_fadd_entry:
    mov.l r2, @-r15
    mov.l r3, @-r15
    mov.l r8, @-r15
    mov.l r9, @-r15
    mov.l r10, @-r15
    mov.l r11, @-r15
    rotl r4
    rotl r6
    cmp/hs r6, r4
    bt      .L_a_ge_b
    mov r4, r2
    mov r6, r4
    mov r2, r6
    mov r5, r2
    mov r7, r5
    mov r2, r7
.L_a_ge_b:
    rotr r4
    rotr r6
    mov.l   .L_exp_mask, r3
    mov.l   .L_mant_mask, r0
    mov r4, r10
    mov r6, r11
    mov r4, r8
    shlr16 r8
    shlr2 r8
    shlr2 r8
    and r3, r8
    mov r6, r9
    shlr16 r9
    shlr2 r9
    shlr2 r9
    and r3, r9
    and r0, r4
    and r0, r6
    cmp/eq r3, r8
    bt      .L_exp_a_max
    tst r9, r9
    bt      .L_exp_b_zero
.L_shift_up_3:
    shll r5
    rotcl r4
    shll r5
    rotcl r4
    shll r5
    rotcl r4
    shll r7
    rotcl r6
    shll r7
    rotcl r6
    shll r7
    rotcl r6
    mov.l   .L_implicit_one, r0
    or r0, r4
    or r0, r6
    mov r8, r2
    sub r9, r2
    tst r2, r2
    bt      .L_add_sub_mantissa
    mov #0x3, r3
    cmp/ge r2, r3
    bt      .L_small_shift_right
    mov #0x36, r3
    cmp/gt r3, r2
    bt      .L_max_diff
    mov #0x20, r3
    cmp/gt r3, r2
    bf/s    .L_align_by_mul
    mov #0x1, r9
    sub r3, r2
    tst r7, r7
    bt      .L_merge_low
    or r9, r6
.L_merge_low:
    mov r6, r7
    mov #0x0, r6
.L_align_by_mul:
    sts.l mach, @-r15
    .word 0xC75F
    sts.l macl, @-r15
    shll2 r2
    add r2, r0
    mov.l @r0, r0
    dmulu.l r0, r7
    sts mach, r7
    sts macl, r2
    dmulu.l r0, r6
    sts mach, r6
    sts macl, r3
    lds.l @r15+, macl
    tst r2, r2
    lds.l @r15+, mach
    bt/s    .L_add_sub_mantissa
    or r3, r7
    bra     .L_add_sub_mantissa
    or r9, r7
.L_max_diff:
    mov #0x0, r6
    bra     .L_add_sub_mantissa
    mov #0x1, r7
.L_small_shift_right:
    shlr r6
    rotcr r7
    dt r2
    bf      .L_small_shift_right
.L_add_sub_mantissa:
    div0s r10, r11
    bt      .L_sub_path
    addc r7, r5
    addc r6, r4
    mov.l   .L_minit, r3
    cmp/gt r4, r3
    bt      .L_pack_result
    shlr r4
    rotcr r5
    .word 0x0229
    or r2, r5
    add #0x1, r8
    mov.l   .L_exp_mask, r3
    cmp/eq r3, r8
    bf      .L_pack_result
    mov #0x0, r5
    bra     .L_fadd_epilog
    mov #0x0, r4
.L_sub_path:
    cmp/eq r4, r6
    bf      .L_sub_body
    cmp/eq r5, r7
    bt      .L_exact_zero
.L_sub_body:
    subc r7, r5
    subc r6, r4
    bf      .L_check_renorm
    clrt
    negc r5, r5
    negc r4, r4
    mov r11, r10
.L_check_renorm:
    tst r4, r4
    bf      .L_norm_xtrct
    mov r5, r4
    mov #0x0, r5
    add #-0x20, r8
.L_norm_xtrct:
    mov.l   .L_fp_neg_one, r3
    tst r4, r3
    bf      .L_check_overflow
    mov r5, r3
    xtrct r4, r3
    mov r3, r4
    shll16 r5
    add #-0x10, r8
.L_check_overflow:
    mov.l   .L_minit, r3
    cmp/hi r4, r3
    bt      .L_norm_left_check
.L_norm_right_loop:
    shlr r4
    rotcr r5
    cmp/hi r4, r3
    bt/s    .L_pack_result
    add #0x1, r8
    shlr r4
    rotcr r5
    cmp/hi r4, r3
    bt/s    .L_pack_result
    add #0x1, r8
    shlr r4
    rotcr r5
    cmp/hi r4, r3
    bt/s    .L_pack_result
    add #0x1, r8
    shlr r4
    rotcr r5
    cmp/hi r4, r3
    bt/s    .L_pack_result
    add #0x1, r8
    bra     .L_norm_right_loop
    nop
.L_norm_left_check:
    mov.l   .L_implicit_one, r3
    .4byte  0x34338913
    .4byte  0x45004424
    .4byte  0x34338D0F
    .4byte  0x78FF4500
    .4byte  0x44243433
    .4byte  0x8D0A78FF
    .4byte  0x45004424
    .4byte  0x34338D05
    .4byte  0x78FF4500
    .4byte  0x44243433
    .4byte  0x8FEC78FF
.L_pack_result:
    .4byte  0x48158905
    .4byte  0x688B7801
    .4byte  0x44014525
    .4byte  0x48108BFB
    .4byte  0x6053C804
    .4byte  0x890BC80B
    .4byte  0x8909E008
    .4byte  0x350EE000
    .4byte  0x340ED019
    .4byte  0x30478902
    .4byte  0x44014525
    .2byte  0x7801
.L_fadd_epilog:
    shlr r4
    rotcr r5
    shlr r4
    rotcr r5
    shlr r4
    rotcr r5
    mov.l   .L_mant_mask, r0
    and r0, r4
    shll16 r8
    shll2 r8
    shll2 r8
    or r8, r4
    shll r4
    shll r10
    rotcr r4
    mov.l @r15+, r11
    mov.l @r15+, r10
    mov.l @r15+, r9
    mov.l @r15+, r8
    mov.l @r15+, r3
    mov.l @r15+, r2
    mov.l @(20, r15), r6
    mov.l r4, @r6
    mov.l r5, @(4, r6)
    mov.l @r15+, r7
    mov.l @r15+, r6
    mov.l @r15+, r5
    mov.l @r15+, r4
    mov.l @r15+, r0
    rts
    add #0x14, r15
.L_exact_zero:
    mov #0x0, r10
    mov #0x0, r8
    mov #0x0, r4
    bra     .L_fadd_epilog
    mov #0x0, r5
    .2byte  0x0009
.L_exp_mask:
    .4byte  0x000007FF
.L_mant_mask:
    .4byte  0x000FFFFF
.L_implicit_one:
    .4byte  0x00800000
    .4byte  0x0000FFFF
.L_minit:
    .4byte  0x01000000
.L_fp_sixteen:
    .4byte  0x00100000
.L_fp_min:
    .4byte  0x80000000
.L_fp_neg_one:
    .4byte  0xFFFF0000

    .global DAT_06035734
DAT_06035734:
    .word 0x0000
    .word 0x0000
    mov.b r0, @(0, r0)
    .word 0x0000
    shll r0
    .word 0x0000
    mov.b r0, @r0
    .word 0x0000
    mov.l r0, @(0, r0)
    .word 0x0000
    .word 0x0800
    .word 0x0000
    .word 0x0400
    .word 0x0000
    .word 0x0200
    .word 0x0000
    .word 0x0100
    .word 0x0000
    .word 0x0080
    .word 0x0000
    .word 0x0040
    .word 0x0000
    .word 0x0020
    .word 0x0000
    .word 0x0010
    .word 0x0000
    clrt
    .word 0x0000
    mov.b r0, @(r0, r0)
    .word 0x0000
    stc sr, r0
    .word 0x0000
    .word 0x0001
    .word 0x0000
    .word 0x0000
    mov.b r0, @(0, r0)
    .word 0x0000
    shll r0
    .word 0x0000
    mov.b r0, @r0
    .word 0x0000
    mov.l r0, @(0, r0)
    .word 0x0000
    .word 0x0800
    .word 0x0000
    .word 0x0400
    .word 0x0000
    .word 0x0200
    .word 0x0000
    .word 0x0100
    .word 0x0000
    .word 0x0080
    .word 0x0000
    .word 0x0040
    .word 0x0000
    .word 0x0020
    .word 0x0000
    .word 0x0010
    .word 0x0000
    clrt
    .word 0x0000
    mov.b r0, @(r0, r0)
    .word 0x0000
    stc sr, r0
    .word 0x0000
    .word 0x0001

    .global sym_060357B8
sym_060357B8:
    mov.l r1, @-r15
    mov.l r2, @-r15
    mov.l r3, @-r15
    mov.l r4, @-r15
    mov.l r5, @-r15
    mov.l @(20, r15), r0
    mov.l @(24, r15), r1
    mov.l   .L_f2i_exp_mask, r4
    mov.l   .L_f2i_mant_mask, r5
    mov r0, r3
    mov r0, r2
    shlr16 r2
    shlr2 r2
    shlr2 r2
    and r4, r2
    and r5, r0
    mov.l   .L_f2i_exp_bias, r4
    sub r4, r2
    cmp/pz r2
    bf      .L_f2i_out_of_range
    mov #0x53, r4
    cmp/gt r4, r2
    bt      .L_f2i_out_of_range
    mov.l   .L_f2i_implicit_one, r4
    or r4, r0
    add #-0x14, r2
    cmp/pz r2
    bf      .L_f2i_shift_down
    mov #0x20, r4
    cmp/ge r4, r2
    bt      .L_f2i_shift_high
    add #0x1, r2
.L_f2i_shift_up:
    dt r2
    bt      .L_f2i_apply_sign
    shll r1
    bra     .L_f2i_shift_up
    rotcl r0
.L_f2i_shift_high:
    mov r1, r0
    add #-0x20, r2
    tst r2, r2
    bt      .L_f2i_apply_sign
.L_f2i_shift_extra:
    dt r2
    bf/s    .L_f2i_shift_extra
    shll r0
    bra     .L_f2i_apply_sign
    nop
.L_f2i_shift_down:
    neg r2, r2
.L_f2i_shr_loop:
    dt r2
    bf/s    .L_f2i_shr_loop
    shlr r0
.L_f2i_apply_sign:
    shll r3
    bf      .L_f2i_epilog
    neg r0, r0
.L_f2i_epilog:
    mov.l @r15+, r5
    mov.l @r15+, r4
    mov.l @r15+, r3
    mov.l @r15+, r2
    mov.l @r15+, r1
    rts
    add #0x8, r15
.L_f2i_out_of_range:
    bra     .L_f2i_epilog
    mov #0x0, r0
.L_f2i_exp_mask:
    .4byte  0x000007FF
.L_f2i_mant_mask:
    .4byte  0x000FFFFF
.L_f2i_implicit_one:
    .4byte  0x00100000
.L_f2i_exp_bias:
    .4byte  0x000003FF

    .global sym_06035844
sym_06035844:
    mov.l r4, @-r15
    mov.l r5, @-r15
    mov.l r6, @-r15
    mov.l r7, @-r15
    mov.l @(24, r15), r4
    mov.l @(28, r15), r5
    mov.l @(16, r15), r6
    mov.l @(20, r15), r7
    mov.l r8, @-r15
    mov.l r9, @-r15
    mov.l r10, @-r15
    mov.l r11, @-r15
    mov.l   .L_fsub_exp_field, r0
    mov r4, r10
    mov r6, r11
    mov r4, r8
    and r0, r8
    mov r6, r9
    and r0, r9
    mov.l   .L_fsub_mant_field, r0
    and r0, r4
    and r0, r6
    mov.l   .L_fsub_exp_field, r0
    cmp/eq r0, r8
    bt      .L_fsub_a_is_special
.L_fsub_check_b_exp:
    cmp/eq r0, r9
    bt      .L_fsub_b_is_special
.L_fsub_check_a_zero:
    tst r8, r8
    bt      .L_fsub_a_exp_zero
.L_fsub_compute:
    div0s r10, r11
    bt      .L_fsub_same_sign
    cmp/pz r10
    bf      .L_fsub_neg_a
    clrt
    subc r5, r7
    subc r10, r11
    bra     .L_fsub_epilog
    .word 0x0029
.L_fsub_neg_a:
    subc r7, r5
    subc r11, r10
    bra     .L_fsub_epilog
    .word 0x0029
.L_fsub_same_sign:
    cmp/pz r10
    .word 0x0029
.L_fsub_epilog:
    mov.l @r15+, r11
    mov.l @r15+, r10
    mov.l @r15+, r9
    mov.l @r15+, r8
    mov.l @r15+, r7
    mov.l @r15+, r6
    mov.l @r15+, r5
    mov.l @r15+, r4
    rts
    add #0x10, r15
.L_fsub_a_is_special:
    tst r4, r4
    bf      .L_fsub_return_zero
    tst r5, r5
    bf      .L_fsub_return_zero
    bra     .L_fsub_check_b_exp
    nop
.L_fsub_b_is_special:
    tst r6, r6
    bf      .L_fsub_return_zero
    tst r7, r7
    bf      .L_fsub_return_zero
    bra     .L_fsub_check_a_zero
    nop
.L_fsub_a_exp_zero:
    tst r9, r9
    bf      .L_fsub_compute
    tst r4, r4
    bf      .L_fsub_compute
    tst r5, r5
    bf      .L_fsub_compute
    tst r6, r6
    bf      .L_fsub_compute
    tst r7, r7
    bf      .L_fsub_compute
    bra     .L_fsub_epilog
    mov #0x0, r0
.L_fsub_return_zero:
    bra     .L_fsub_epilog
    mov #0x0, r0
.L_fsub_exp_field:
    .4byte  0x7FF00000
.L_fsub_mant_field:
    .4byte  0x000FFFFF

    .global sym_060358EC
sym_060358EC:
    mov.l r1, @-r15
    mov.l r2, @-r15
    mov.l r3, @-r15
    tst r0, r0
    bt      .L_i2f_zero_input
    mov #0x0, r3
    cmp/pz r0
    bt      .L_i2f_positive
    mov #0x1, r3
    neg r0, r0
.L_i2f_positive:
    mov.l   .L_i2f_exp_init, r1
.L_i2f_norm_loop:
    shll r0
    bf/s    .L_i2f_norm_loop
    add #-0x1, r1
    mov r0, r2
    shll16 r2
    shll2 r2
    shll2 r2
    shlr8 r0
    shlr2 r0
    shlr2 r0
    shll16 r1
    shll2 r1
    shll2 r1
    or r1, r0
    shll r0
    shlr r3
    rotcr r0
.L_i2f_store:
    mov.l @(12, r15), r1
    mov.l r0, @r1
    mov.l r2, @(4, r1)
    mov.l @r15+, r3
    mov.l @r15+, r2
    mov.l @r15+, r1
    rts
    add #0x4, r15
.L_i2f_zero_input:
    mov #0x0, r2
    bra     .L_i2f_store
    mov #0x0, r0
    .2byte  0x0009
.L_i2f_exp_init:
    .4byte  0x0000041F
    .4byte  0x24488B4A
    .4byte  0x25588B48
    .4byte  0x39308907
    .4byte  0x29988B40
    .4byte  0x26688B3E
    .4byte  0x27788B3C
    .4byte  0xA03F0009
    .4byte  0x26688B3C
    .4byte  0x27788B3A
    .4byte  0xA0350009
    .4byte  0x26688B36
    .4byte  0x27788B34
    .4byte  0x28888B2E
    .4byte  0x24488B2C
    .4byte  0x25588B2A
    .4byte  0xA02D0009
    .4byte  0x24488B03
    .4byte  0x25588B01
    .4byte  0xA01E0009
    .4byte  0xD0664500
    .4byte  0x44243403
    .4byte  0x89044500
    .4byte  0x44243403
    .4byte  0x8FFB78FF
    .4byte  0xA04B0009
    .4byte  0x26688B03
    .4byte  0x27788B01
    .4byte  0xA00C0009
    .4byte  0xD05D4700
    .4byte  0x46243603
    .4byte  0x89044700
    .4byte  0x46243603
    .4byte  0x8FFB79FF
    .4byte  0xA03B0009
    .4byte  0x4A000129
    .4byte  0xE000A091
    .4byte  0x4105D853
    .4byte  0xE100A07E
    .4byte  0xE000EA00
    .4byte  0xD850E100
    .4byte  0xA079E008

    .global sym_060359E4
sym_060359E4:
    mov.l r0, @-r15
    mov.l r1, @-r15
    mov.l r4, @-r15
    mov.l r5, @-r15
    mov.l r6, @-r15
    mov.l r7, @-r15
    mov.l @(28, r15), r4
    mov.l @(32, r15), r5
    mov.l @(36, r15), r6
    mov.l @(40, r15), r7
    mov.l r2, @-r15
    mov.l r3, @-r15
    mov.l r8, @-r15
    mov.l r9, @-r15
    mov.l r10, @-r15
    mov.l r11, @-r15
    mov.l r12, @-r15
    mov.l r13, @-r15
