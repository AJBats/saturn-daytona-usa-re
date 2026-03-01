
    .section .text.FUN_060103B8


    .global brake_state_toggle
    .type brake_state_toggle, @function
brake_state_toggle:
    mov.l r14, @-r15
    extu.w r4, r3
    mov.l r13, @-r15
    mov.l r12, @-r15
    sts.l pr, @-r15
    mov.l   .L_pool_press_counter, r14
    mov.l   .L_fp_half, r2
    and r2, r3
    tst r3, r3
    bt      .L_check_release
    mov #0x1, r2
    mov.l   .L_pool_press_counter, r3
    mov.l @r3, r3
    cmp/ge r2, r3
    bt      .L_check_release
    mov.l @r14, r2
    add #0x1, r2
    mov.l r2, @r14
.L_check_release:
    extu.w r4, r4
    mov.w   DAT_0601043e, r3
    and r3, r4
    tst r4, r4
    bt      .L_copy_counter
    mov.l   .L_pool_press_counter, r3
    mov.l @r3, r3
    cmp/pl r3
    bf      .L_copy_counter
    mov.l @r14, r3
    add #-0x1, r3
    mov.l r3, @r14
.L_copy_counter:
    mov.l   .L_pool_display_mirror, r4
    mov.l @r14, r2
    mov.l r2, @r4
    mov.l @r14, r3
    mov.l   .L_pool_state_shadow, r2
    mov.l r3, @r2
    mov.l   .L_pool_fn_dma_transfer, r12
    mov.w   .L_wpool_dma_size, r13
    mov.l @r4, r0
    tst r0, r0
    bt      .L_brake_off
    mov r13, r6
    mov.l   .L_pool_tile_on_a, r5
    mov.l   .L_pool_dma_dst_a, r4
    mov.l @r5, r5
    jsr @r12
    mov.l @r4, r4
    mov.l   .L_pool_tile_on_b, r5
    bra     .L_dma_second_tile
    mov r13, r6
.L_brake_off:
    mov r13, r6
    mov.l   .L_pool_tile_off_a, r5
    mov.l   .L_pool_dma_dst_a, r4
    mov.l @r5, r5
    jsr @r12
    mov.l @r4, r4
    mov r13, r6
    mov.l   .L_pool_tile_off_b, r5
.L_dma_second_tile:
    mov.l @r5, r5
    mov.l   .L_pool_dma_dst_b, r4
    jsr @r12
    mov.l @r4, r4
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global DAT_0601043e
DAT_0601043e:
    .2byte  0x4000
.L_wpool_dma_size:
    .2byte  0x00C0
    .2byte  0xFFFF
.L_pool_press_counter:
    .4byte  sym_0607EADC
.L_fp_half:
    .4byte  0x00008000                  /* 0.5 (16.16 fixed-point) */
.L_pool_display_mirror:
    .4byte  sym_0607EAB8
.L_pool_state_shadow:
    .4byte  sym_06078868
.L_pool_fn_dma_transfer:
    .4byte  dma_transfer
.L_pool_tile_on_a:
    .4byte  sym_0605D084
.L_pool_dma_dst_a:
    .4byte  sym_06078884
.L_pool_tile_on_b:
    .4byte  sym_0605D060
.L_pool_tile_off_a:
    .4byte  sym_0605D05C
.L_pool_tile_off_b:
    .4byte  sym_0605D088
.L_pool_dma_dst_b:
    .4byte  sym_06078880
