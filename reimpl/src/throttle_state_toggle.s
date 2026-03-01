
    .section .text.FUN_06010470


    .global throttle_state_toggle
    .type throttle_state_toggle, @function
throttle_state_toggle:
    mov.l r14, @-r15
    mov #0x0, r2
    mov.l r13, @-r15
    mov.l r12, @-r15
    sts.l pr, @-r15
    .byte   0xDD, 0x24    /* mov.l .L_pool_throttle_counter, r13 */
    .byte   0x9E, 0x44    /* mov.w .L_wpool_06010508, r14 */
    .byte   0xD0, 0x24    /* mov.l .L_pool_input_word, r0 */
    .byte   0xD3, 0x24    /* mov.l .L_pool_xor_mask, r3 */
    mov.w @r0, r0
    extu.w r0, r0
    xor r3, r0
    and #0xFF, r0
    extu.w r0, r4
    cmp/gt r14, r4
    bf/s    .L_copy_counter
    mov.l r2, @r13
    mov.l @r13, r2
    add #0x1, r2
    mov.l r2, @r13
.L_copy_counter:
    .byte   0xD4, 0x1F    /* mov.l .L_pool_display_mirror, r4 */
    mov.l @r13, r3
    mov.l r3, @r4
    mov.l @r13, r2
    .byte   0xD3, 0x1E    /* mov.l .L_pool_state_shadow, r3 */
    mov.l r2, @r3
    .byte   0xDC, 0x1E    /* mov.l .L_pool_fn_dma_transfer, r12 */
    mov.l @r4, r0
    tst r0, r0
    bt      .L_throttle_off
    mov r14, r6
    .byte   0xD5, 0x1D    /* mov.l .L_pool_tile_on_a, r5 */
    .byte   0xD4, 0x1D    /* mov.l .L_pool_dma_dst_a, r4 */
    mov.l @r5, r5
    jsr @r12
    mov.l @r4, r4
    .byte   0xD5, 0x1C    /* mov.l .L_pool_tile_on_b, r5 */
    bra     .L_dma_second_tile
    mov r14, r6
.L_throttle_off:
    mov r14, r6
    .byte   0xD5, 0x1B    /* mov.l .L_pool_tile_off_a, r5 */
    .byte   0xD4, 0x19    /* mov.l .L_pool_dma_dst_a, r4 */
    mov.l @r5, r5
    jsr @r12
    mov.l @r4, r4
    mov r14, r6
    .byte   0xD5, 0x19    /* mov.l .L_pool_tile_off_b, r5 */
.L_dma_second_tile:
    mov.l @r5, r5
    .byte   0xD4, 0x19    /* mov.l .L_pool_dma_dst_b, r4 */
    jsr @r12
    mov.l @r4, r4
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
