
    .section .text.FUN_0603D7B0


    .global options_menu_state
    .type options_menu_state, @function
options_menu_state:
    mov.l r14, @-r15
    mov #0x1, r6
    mov.l r13, @-r15
    mov #0x2, r14
    mov r6, r0
    mov.l r12, @-r15
    sts.l pr, @-r15
    mov.l   .L_mask_bit0, r12
    mov.l   .L_cfg_target_ptr, r7
    mov.l   .L_cfg_word_base, r5
    mov.l   .L_fn_bitfield_rmw, r3
    mov r12, r13
    mov r7, r2
    add #-0x1, r13
    jsr @r3
    mov r6, r1
    mov.w @(2, r5), r0
    mov.l   .L_mask_bit8, r3
    mov r0, r2
    extu.w r2, r2
    and r3, r2
    extu.w r2, r0
    mov.w r0, @(2, r5)
    mov r7, r2
    mov r6, r0
    mov.l   .L_fn_bitfield_rmw, r3
    jsr @r3
    mov r6, r1
    mov.w @(2, r5), r0
    mov r0, r2
    extu.w r2, r2
    and r12, r2
    extu.w r2, r0
    mov r7, r2
    mov.w r0, @(2, r5)
    mov r6, r0
    mov.l   .L_fn_bitfield_rmw, r3
    jsr @r3
    mov r6, r1
    mov.w @(2, r5), r0
    mov r0, r2
    extu.w r2, r2
    and r13, r2
    extu.w r2, r0
    mov.w r0, @(2, r5)
    mov r7, r2
    mov r6, r0
    mov.l   .L_fn_bitfield_rmw, r3
    jsr @r3
    mov r6, r1
    mov.w @(2, r5), r0
    mov.l   .L_mask_bit2, r3
    mov r0, r2
    extu.w r2, r2
    and r3, r2
    extu.w r2, r0
    mov.w r0, @(2, r5)
    mov r7, r2
    mov r6, r0
    mov.l   .L_fn_bitfield_rmw, r3
    jsr @r3
    mov r6, r1
    mov.w @(2, r5), r0
    mov.l   .L_mask_bit3, r3
    mov r0, r2
    extu.w r2, r2
    and r3, r2
    extu.w r2, r0
    mov.w r0, @(2, r5)
    mov r7, r2
    mov r6, r0
    mov.l   .L_fn_bitfield_rmw, r3
    jsr @r3
    mov r6, r1
    mov.w @(2, r5), r0
    mov.l   .L_mask_bit4, r3
    mov r0, r2
    extu.w r2, r2
    and r3, r2
    extu.w r2, r0
    mov.w r0, @(2, r5)
    mov r7, r2
    mov r6, r0
    mov.l   .L_fn_bitfield_rmw, r3
    jsr @r3
    mov r6, r1
    mov.w @(2, r5), r0
    mov.l   .L_mask_bit5, r3
    mov r0, r2
    extu.w r2, r2
    and r3, r2
    extu.w r2, r2
    mov r2, r0
    mov.w r0, @(2, r5)
    tst r4, r4
    bf      .L_options_active
    bra     .L_epilogue
    nop
.L_options_active:
    mov r6, r0
    mov r7, r2
    mov.l   .L_fn_bitfield_rmw, r3
    jsr @r3
    mov #0x1, r1
    mov.w @(2, r5), r0
    mov.l   .L_mask_bit8, r3
    mov.w   .L_set_bit8, r1
    mov r0, r2
    extu.w r2, r2
    and r3, r2
    or r1, r2
    mov #0x4, r3
    extu.w r2, r2
    and r4, r3
    mov r2, r0
    mov.w r0, @(2, r5)
    tst r3, r3
    bt      .L_check_opt_bit1
    mov r6, r0
    mov r7, r2
    mov.l   .L_fn_bitfield_rmw, r3
    jsr @r3
    mov #0x1, r1
    mov.w @(2, r5), r0
    mov r0, r2
    extu.w r2, r2
    and r12, r2
    or r6, r2
    extu.w r2, r2
    mov r2, r0
    mov.w r0, @(2, r5)
.L_check_opt_bit1:
    mov r4, r3
    and r14, r3
    tst r3, r3
    bt      .L_check_opt_bit3
    mov r6, r0
    mov r7, r2
    bra     .L_set_cfg_bit0
    mov #0x1, r1
.L_set_bit8:
    .2byte  0x0100                          /* bit 8 value (0x0100) */
    .2byte  0xFFFF                          /* padding */
.L_mask_bit0:
    .4byte  0x0000FFFE                      /* clear-mask for bit 0 */
.L_cfg_target_ptr:
    .4byte  sym_060A4D58                    /* bitfield RMW target ptr */
.L_cfg_word_base:
    .4byte  sym_060A4D18                    /* config word array base */
.L_fn_bitfield_rmw:
    .4byte  sym_06034F78                    /* bitfield RMW function */
.L_mask_bit8:
    .4byte  0x0000FEFF                      /* clear-mask for bit 8 */
.L_mask_bit2:
    .4byte  0x0000FFFB                      /* clear-mask for bit 2 */
.L_mask_bit3:
    .4byte  0x0000FFF7                      /* clear-mask for bit 3 */
.L_mask_bit4:
    .4byte  0x0000FFEF                      /* clear-mask for bit 4 */
.L_mask_bit5:
    .4byte  0x0000FFDF                      /* clear-mask for bit 5 */
.L_set_cfg_bit0:
    mov.l   .L_fn_bitfield_rmw_b, r3
    jsr @r3
    nop
    mov.w @(2, r5), r0
    mov r0, r2
    extu.w r2, r2
    and r12, r2
    or r6, r2
    extu.w r2, r2
    mov r2, r0
    mov.w r0, @(2, r5)
.L_check_opt_bit3:
    mov #0x8, r3
    and r4, r3
    tst r3, r3
    bt      .L_check_opt_bit7
    mov r6, r0
    mov r7, r2
    mov.l   .L_fn_bitfield_rmw_b, r3
    jsr @r3
    mov #0x1, r1
    mov.w @(2, r5), r0
    mov r0, r2
    extu.w r2, r2
    and r13, r2
    or r14, r2
    extu.w r2, r2
    mov r2, r0
    mov.w r0, @(2, r5)
.L_check_opt_bit7:
    mov.w   .L_test_bit7, r3
    and r4, r3
    tst r3, r3
    bt      .L_check_opt_bit4
    mov r6, r0
    mov r7, r2
    mov.l   .L_fn_bitfield_rmw_b, r3
    jsr @r3
    mov #0x1, r1
    mov.w @(2, r5), r0
    mov r0, r2
    extu.w r2, r2
    and r13, r2
    or r14, r2
    extu.w r2, r2
    mov r2, r0
    mov.w r0, @(2, r5)
.L_check_opt_bit4:
    mov #0x10, r3
    and r4, r3
    tst r3, r3
    bt      .L_check_opt_bit5
    mov r6, r0
    mov r7, r2
    mov.l   .L_fn_bitfield_rmw_b, r3
    jsr @r3
    mov #0x1, r1
    mov.w @(2, r5), r0
    extu.w r0, r0
    mov.l   .L_mask_bit2_b, r3
    and r3, r0
    or #0x4, r0
    extu.w r0, r0
    mov.w r0, @(2, r5)
.L_check_opt_bit5:
    mov #0x20, r2
    and r4, r2
    tst r2, r2
    bt      .L_check_opt_bit0
    mov r6, r0
    mov r7, r2
    mov.l   .L_fn_bitfield_rmw_b, r3
    jsr @r3
    mov #0x1, r1
    mov.w @(2, r5), r0
    extu.w r0, r0
    mov.l   .L_mask_bit3_b, r3
    and r3, r0
    or #0x8, r0
    extu.w r0, r0
    mov.w r0, @(2, r5)
.L_check_opt_bit0:
    mov r4, r2
    and r6, r2
    tst r2, r2
    bt      .L_check_opt_bit19
    mov r6, r0
    mov r7, r2
    mov.l   .L_fn_bitfield_rmw_b, r3
    jsr @r3
    mov #0x1, r1
    mov.w @(2, r5), r0
    extu.w r0, r0
    mov.l   .L_mask_bit4_b, r3
    and r3, r0
    or #0x10, r0
    extu.w r0, r0
    mov.w r0, @(2, r5)
.L_check_opt_bit19:
    mov.l   .L_mask_bit19, r2
    and r2, r4
    tst r4, r4
    bt      .L_epilogue
    mov r6, r0
    mov r7, r2
    mov.l   .L_fn_bitfield_rmw_b, r3
    jsr @r3
    mov #0x1, r1
    mov.w @(2, r5), r0
    extu.w r0, r0
    mov.l   .L_mask_bit5_b, r3
    and r3, r0
    or #0x20, r0
    extu.w r0, r0
    mov.w r0, @(2, r5)
.L_epilogue:
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_test_bit7:
    .2byte  0x0080                          /* test mask for opt bit 7 */
    .2byte  0xFFFF                          /* padding */
.L_fn_bitfield_rmw_b:
    .4byte  sym_06034F78                    /* bitfield RMW function (2nd pool) */
.L_mask_bit2_b:
    .4byte  0x0000FFFB                      /* clear-mask for bit 2 (2nd pool) */
.L_mask_bit3_b:
    .4byte  0x0000FFF7                      /* clear-mask for bit 3 (2nd pool) */
.L_mask_bit4_b:
    .4byte  0x0000FFEF                      /* clear-mask for bit 4 (2nd pool) */
.L_mask_bit19:
    .4byte  0x00080000                      /* test mask for opt bit 19 (0x80000) */
.L_mask_bit5_b:
    .4byte  0x0000FFDF                      /* clear-mask for bit 5 (2nd pool) */
