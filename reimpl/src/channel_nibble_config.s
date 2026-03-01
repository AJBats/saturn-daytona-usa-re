
    .section .text.FUN_06038BD4


    .global channel_nibble_config
    .type channel_nibble_config, @function
channel_nibble_config:
    mov.l r14, @-r15
    mov #0x1, r7
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    sts.l pr, @-r15
    mov.l   .L_mask_byte1, r9
    mov.w   DAT_06038cc8, r10
    mov.l   _pool_mask_hi_nib_clear, r11
    mov.l   _pool_mask_lo_nib_clear, r12
    mov.l   _pool_cfg_array_b, r13
    mov.l   _pool_cfg_final, r14
    mov.l   _pool_cfg_array_a, r6
    mov.w   _wpool_bit_a0_lo, r3
    and r4, r3
    tst r3, r3
    bt/s    .L_check_a0_hi_nib
    extu.b r5, r5
    mov r7, r0
    mov.w   _wpool_param_0x101, r1
    mov.l   _pool_bitfield_rmw, r3
    jsr @r3
    mov r14, r2
    mov.w @r6, r2
    extu.w r2, r2
    and r12, r2
    extu.w r5, r3
    or r3, r2
    extu.w r2, r2
    mov.w r2, @r6
.L_check_a0_hi_nib:
    mov.w   _wpool_bit_a0_hi, r2
    and r4, r2
    tst r2, r2
    bt      .L_check_a2_lo_nib
    mov r7, r0
    mov.w   _wpool_param_0x101, r1
    mov.l   _pool_bitfield_rmw, r3
    jsr @r3
    mov r14, r2
    mov.w @r6, r2
    extu.w r2, r2
    and r11, r2
    extu.w r5, r3
    shll8 r3
    or r3, r2
    extu.w r2, r2
    mov.w r2, @r6
.L_check_a2_lo_nib:
    mov.w   _wpool_bit_a2_lo, r2
    and r4, r2
    tst r2, r2
    bt      .L_check_a2_hi_nib
    mov r7, r0
    mov.w   _wpool_param_0x101, r1
    mov.l   _pool_bitfield_rmw, r3
    jsr @r3
    mov r14, r2
    mov.w @(2, r6), r0
    mov r0, r2
    extu.w r2, r2
    and r12, r2
    extu.w r5, r3
    or r3, r2
    extu.w r2, r2
    mov r2, r0
    mov.w r0, @(2, r6)
.L_check_a2_hi_nib:
    mov.w   _wpool_bit_a2_hi, r3
    and r4, r3
    tst r3, r3
    bt      .L_check_a4_lo_nib
    mov r7, r0
    mov.w   _wpool_param_0x101, r1
    mov.l   _pool_bitfield_rmw, r3
    jsr @r3
    mov r14, r2
    mov.w @(2, r6), r0
    mov r0, r2
    extu.w r2, r2
    and r11, r2
    extu.w r5, r3
    shll8 r3
    or r3, r2
    extu.w r2, r2
    mov r2, r0
    mov.w r0, @(2, r6)
.L_check_a4_lo_nib:
    mov.w   DAT_06038cd4, r3
    and r4, r3
    tst r3, r3
    bt      .L_check_a4_hi_nib
    mov r7, r0
    mov.w   _wpool_param_0x101, r1
    mov.l   _pool_bitfield_rmw, r3
    jsr @r3
    mov r14, r2
    mov.w @(4, r6), r0
    mov r0, r2
    extu.w r2, r2
    and r12, r2
    extu.w r5, r3
    or r3, r2
    extu.w r2, r2
    mov r2, r0
    mov.w r0, @(4, r6)
.L_check_a4_hi_nib:
    mov.w   DAT_06038cd6, r3
    and r4, r3
    tst r3, r3
    bt      .L_check_a6_lo_nib
    mov r7, r0
    mov.w   _wpool_param_0x101, r1
    mov.l   _pool_bitfield_rmw, r3
    jsr @r3
    mov r14, r2
    mov.w @(4, r6), r0
    mov r0, r2
    extu.w r2, r2
    and r11, r2
    extu.w r5, r3
    shll8 r3
    or r3, r2
    bra     .L_store_a4_hi_result
    nop

    .global DAT_06038cc8
DAT_06038cc8:
    .2byte  0x00FF
_wpool_bit_a0_lo:
    .2byte  0x0100
_wpool_param_0x101:
    .2byte  0x0101
_wpool_bit_a0_hi:
    .2byte  0x0200
_wpool_bit_a2_lo:
    .2byte  0x0400
_wpool_bit_a2_hi:
    .2byte  0x0800

    .global DAT_06038cd4
DAT_06038cd4:
    .2byte  0x1000

    .global DAT_06038cd6
DAT_06038cd6:
    .2byte  0x2000
.L_mask_byte1:
    .4byte  0x0000FF00                  /* byte 1 mask: keep high byte, clear low byte */
_pool_mask_hi_nib_clear:
    .4byte  0x0000F0FF                  /* mask: clear bits 11:8 (high nibble of low byte) */
_pool_mask_lo_nib_clear:
    .4byte  0x0000FFF0                  /* mask: clear bits 3:0 (low nibble) */
_pool_cfg_array_b:
    .4byte  sym_060A4D30                /* config word array B (2 words at offsets 0/2) */
_pool_cfg_final:
    .4byte  sym_060A4D58                /* final config area (word at offset 4) */
_pool_cfg_array_a:
    .4byte  sym_060A4D28                /* config word array A (4 words at offsets 0/2/4/6) */
_pool_bitfield_rmw:
    .4byte  sym_06034F78                /* bitfield read-modify-write utility */
.L_store_a4_hi_result:
    extu.w r2, r2
    mov r2, r0
    mov.w r0, @(4, r6)
.L_check_a6_lo_nib:
    mov.w   DAT_06038e1a, r3
    and r4, r3
    tst r3, r3
    bt      .L_check_a6_hi_nib
    mov r7, r0
    mov.w   _wpool_param_0x101_b, r1
    mov.l   _pool_bitfield_rmw_b, r3
    jsr @r3
    mov r14, r2
    mov.w @(6, r6), r0
    mov r0, r2
    extu.w r2, r2
    and r12, r2
    extu.w r5, r3
    or r3, r2
    extu.w r2, r2
    mov r2, r0
    mov.w r0, @(6, r6)
.L_check_a6_hi_nib:
    mov.l   .L_bit_a6_hi, r3
    and r4, r3
    tst r3, r3
    bt      .L_check_b0_lo_nib
    mov r7, r0
    mov.w   _wpool_param_0x101_b, r1
    mov.l   _pool_bitfield_rmw_b, r3
    jsr @r3
    mov r14, r2
    mov.w @(6, r6), r0
    mov r0, r2
    extu.w r2, r2
    and r11, r2
    extu.w r5, r3
    shll8 r3
    or r3, r2
    extu.w r2, r2
    mov r2, r0
    mov.w r0, @(6, r6)
.L_check_b0_lo_nib:
    mov #0x4, r3
    and r4, r3
    tst r3, r3
    bt      .L_check_b0_lo_alt
    mov r7, r0
    mov.w   _wpool_param_0x201, r1
    mov.l   _pool_bitfield_rmw_b, r3
    jsr @r3
    mov r14, r2
    mov.w @r13, r2
    extu.w r2, r2
    and r9, r2
    extu.w r5, r3
    or r3, r2
    extu.w r2, r2
    mov.w r2, @r13
.L_check_b0_lo_alt:
    mov #0x2, r2
    and r4, r2
    tst r2, r2
    bt      .L_check_b0_hi_nib
    mov r7, r0
    mov.w   _wpool_param_0x201, r1
    mov.l   _pool_bitfield_rmw_b, r3
    jsr @r3
    mov r14, r2
    mov.w @r13, r2
    extu.w r2, r2
    and r9, r2
    extu.w r5, r3
    or r3, r2
    extu.w r2, r2
    mov.w r2, @r13
.L_check_b0_hi_nib:
    mov #0x8, r2
    and r4, r2
    tst r2, r2
    bt      .L_check_b0_hi_alt
    mov r7, r0
    mov.w   _wpool_param_0x201, r1
    mov.l   _pool_bitfield_rmw_b, r3
    jsr @r3
    mov r14, r2
    mov.w @r13, r2
    extu.w r2, r2
    and r10, r2
    extu.w r5, r3
    shll8 r3
    or r3, r2
    extu.w r2, r2
    mov.w r2, @r13
.L_check_b0_hi_alt:
    mov.w   _wpool_bit_b0_hi_alt, r2
    and r4, r2
    tst r2, r2
    bt      .L_check_b2_lo_nib
    mov r7, r0
    mov.w   _wpool_param_0x201, r1
    mov.l   _pool_bitfield_rmw_b, r3
    jsr @r3
    mov r14, r2
    mov.w @r13, r2
    extu.w r2, r2
    and r10, r2
    extu.w r5, r3
    shll8 r3
    or r3, r2
    extu.w r2, r2
    mov.w r2, @r13
.L_check_b2_lo_nib:
    mov #0x10, r2
    and r4, r2
    tst r2, r2
    bt      .L_check_b2_hi_nib
    mov r7, r0
    mov.w   _wpool_param_0x201, r1
    mov.l   _pool_bitfield_rmw_b, r3
    jsr @r3
    mov r14, r2
    mov.w @(2, r13), r0
    mov r0, r2
    extu.w r2, r2
    and r9, r2
    extu.w r5, r3
    or r3, r2
    extu.w r2, r2
    mov r2, r0
    mov.w r0, @(2, r13)
.L_check_b2_hi_nib:
    mov #0x20, r3
    and r4, r3
    tst r3, r3
    bt      .L_check_final_field
    mov r7, r0
    mov.w   _wpool_param_0x201, r1
    mov.l   _pool_bitfield_rmw_b, r3
    jsr @r3
    mov r14, r2
    mov.w @(2, r13), r0
    mov r0, r2
    extu.w r2, r2
    and r10, r2
    extu.w r5, r3
    shll8 r3
    or r3, r2
    extu.w r2, r2
    mov r2, r0
    mov.w r0, @(2, r13)
.L_check_final_field:
    and r7, r4
    tst r4, r4
    bra     .L_final_field
    nop

    .global DAT_06038e1a
DAT_06038e1a:
    .2byte  0x4000
_wpool_param_0x101_b:
    .2byte  0x0101
_wpool_param_0x201:
    .2byte  0x0201
_wpool_bit_b0_hi_alt:
    .2byte  0x0080
    .2byte  0xFFFF
_pool_bitfield_rmw_b:
    .4byte  sym_06034F78                /* bitfield RMW utility (pool 2) */
.L_bit_a6_hi:
    .4byte  0x00008000                  /* bitmask: bit 15 = array_a word[6] high nibble */
.L_final_field:
    bt      .L_epilogue
    mov r7, r0
    mov.w   _wpool_param_0x201_b, r1
    mov.l   _pool_bitfield_rmw_c, r3
    jsr @r3
    mov r14, r2
    mov r5, r0
    mov.w r0, @(4, r13)
.L_epilogue:
    lds.l @r15+, pr
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
_wpool_param_0x201_b:
    .2byte  0x0201
    .2byte  0xFFFF
_pool_bitfield_rmw_c:
    .4byte  sym_06034F78                /* bitfield RMW utility (pool 3) */
