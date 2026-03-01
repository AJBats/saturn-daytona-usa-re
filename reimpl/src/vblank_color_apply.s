
    .section .text.FUN_0603EDC4


    .global vblank_color_apply
    .type vblank_color_apply, @function
vblank_color_apply:
    mov.b @(3, r15), r0
    mov #0x4, r3
    mov r0, r1
    and r5, r3
    tst r3, r3
    bf      .L_ch2_enabled
    mov #0x2, r3
    and r5, r3
    tst r3, r3
    bt      .L_ch2_done
.L_ch2_enabled:
    mov #0x4, r3
    and r4, r3
    tst r3, r3
    bf      .L_ch2_set_bits
    mov #0x2, r3
    and r4, r3
    tst r3, r3
    bt      .L_ch2_clear_bits
.L_ch2_set_bits:
    extu.b r7, r3
    mov.b @(1, r6), r0
    mov r0, r2
    or r3, r2
    bra     .L_ch2_store
    mov r2, r0
.L_ch2_clear_bits:
    extu.b r1, r2
    mov.b @(1, r6), r0
    mov r0, r3
    and r2, r3
    mov r3, r0
.L_ch2_store:
    mov.b r0, @(1, r6)
.L_ch2_done:
    mov #0x8, r3
    and r5, r3
    tst r3, r3
    bf      .L_ch3_enabled
    mov.w   .L_wpool_bit7_mask, r3
    and r5, r3
    tst r3, r3
    bt      .L_ch3_done
.L_ch3_enabled:
    mov #0x8, r3
    and r4, r3
    tst r3, r3
    bf      .L_ch3_set_bits
    mov.w   .L_wpool_bit7_mask, r3
    and r4, r3
    tst r3, r3
    bt      .L_ch3_clear_bits
.L_ch3_set_bits:
    extu.b r7, r3
    mov.b @r6, r2
    or r3, r2
    bra     .L_ch3_done
    mov.b r2, @r6
.L_ch3_clear_bits:
    extu.b r1, r2
    mov.b @r6, r3
    and r2, r3
    mov.b r3, @r6
.L_ch3_done:
    mov #0x10, r2
    and r5, r2
    tst r2, r2
    bt      .L_ch4_done
    mov #0x10, r3
    and r4, r3
    tst r3, r3
    bt      .L_ch4_clear_bits
    extu.b r7, r3
    mov.b @(3, r6), r0
    mov r0, r2
    or r3, r2
    bra     .L_ch4_store
    mov r2, r0
.L_ch4_clear_bits:
    extu.b r1, r2
    mov.b @(3, r6), r0
    mov r0, r3
    and r2, r3
    mov r3, r0
.L_ch4_store:
    mov.b r0, @(3, r6)
.L_ch4_done:
    mov #0x20, r3
    and r5, r3
    tst r3, r3
    bt      .L_ch5_done
    mov #0x20, r3
    and r4, r3
    tst r3, r3
    bt      .L_ch5_clear_bits
    extu.b r7, r3
    mov.b @(2, r6), r0
    mov r0, r2
    or r3, r2
    bra     .L_ch5_store
    mov r2, r0
.L_wpool_bit7_mask:
    .2byte  0x0080
.L_ch5_clear_bits:
    extu.b r1, r2
    mov.b @(2, r6), r0
    mov r0, r3
    and r2, r3
    mov r3, r0
.L_ch5_store:
    mov.b r0, @(2, r6)
.L_ch5_done:
    mov #0x1, r3
    and r5, r3
    tst r3, r3
    bt      .L_ch0_done
    mov #0x1, r3
    and r4, r3
    tst r3, r3
    bt      .L_ch0_clear_bits
    extu.b r7, r3
    mov.b @(5, r6), r0
    mov r0, r2
    or r3, r2
    bra     .L_ch0_store
    mov r2, r0
.L_ch0_clear_bits:
    extu.b r1, r2
    mov.b @(5, r6), r0
    mov r0, r3
    and r2, r3
    mov r3, r0
.L_ch0_store:
    mov.b r0, @(5, r6)
.L_ch0_done:
    mov.w   .L_wpool_bit8_mask, r3
    and r5, r3
    tst r3, r3
    bt      .L_ch8_done
    mov.w   .L_wpool_bit8_mask, r3
    and r4, r3
    tst r3, r3
    bt      .L_ch8_clear_bits
    extu.b r7, r3
    mov.b @(4, r6), r0
    mov r0, r2
    or r3, r2
    bra     .L_ch8_store
    mov r2, r0
.L_ch8_clear_bits:
    extu.b r1, r2
    mov.b @(4, r6), r0
    mov r0, r3
    and r2, r3
    mov r3, r0
.L_ch8_store:
    mov.b r0, @(4, r6)
.L_ch8_done:
    mov.l   .L_pool_bit16_mask, r3
    and r5, r3
    tst r3, r3
    bt      .L_ch16_done
    mov.l   .L_pool_bit16_mask, r3
    and r4, r3
    tst r3, r3
    bt      .L_ch16_clear_bits
    extu.b r7, r3
    mov.b @(7, r6), r0
    mov r0, r2
    or r3, r2
    bra     .L_ch16_store
    mov r2, r0
.L_ch16_clear_bits:
    extu.b r1, r2
    mov.b @(7, r6), r0
    mov r0, r3
    and r2, r3
    mov r3, r0
.L_ch16_store:
    mov.b r0, @(7, r6)
.L_ch16_done:
    mov.l   .L_pool_bit17_mask, r3
    and r3, r5
    tst r5, r5
    bt      .L_ch17_done
    mov.l   .L_pool_bit17_mask, r3
    and r3, r4
    tst r4, r4
    bt      .L_ch17_clear_bits
    extu.b r7, r7
    mov.b @(6, r6), r0
    mov r0, r3
    or r7, r3
    mov r3, r0
    bra     .L_ch17_store
    nop
.L_ch17_clear_bits:
    extu.b r1, r1
    mov.b @(6, r6), r0
    mov r0, r2
    and r1, r2
    mov r2, r0
.L_ch17_store:
    mov.b r0, @(6, r6)
.L_ch17_done:
    rts
    nop
.L_wpool_bit8_mask:
    .2byte  0x0100
.L_pool_bit16_mask:
    .4byte  0x00010000                  /* 1.0 (16.16 fixed-point) */
.L_pool_bit17_mask:
    .4byte  0x00020000                  /* 2.0 (16.16 fixed-point) */

    .global sym_0603EF34
sym_0603EF34:
    add #-0x4, r15
    mov #0x0, r6
    mov r4, r0
    mov r6, r7
    mov.l r6, @r15
    mov r7, r2
    mov.l r5, @r4
    mov.l r7, @(4, r4)
    mov.l @r15, r3
    mov.l r3, @(8, r4)
    mov #0x1, r3
    mov.l r3, @(12, r4)
    mov.l r7, @(20, r4)
    mov.l r7, @(16, r4)
    rts
    add #0x4, r15

    .global sym_0603EF54
sym_0603EF54:
    mov.l r5, @(4, r4)
    mov #0x0, r3
    mov.l r6, @(8, r4)
    mov r3, r2
    mov.l r7, @(12, r4)
    mov.l r3, @(20, r4)
    rts
    mov.l r3, @(16, r4)
