
    .section .text.FUN_06040980


    .global dma_channel_setup
    .type dma_channel_setup, @function
dma_channel_setup:
    sts.l pr, @-r15
    mov r14, r1
    mov.l r5, @(32, r14)
    add #0x18, r1
    mov.l   .L_pool_memcpy_byte, r3
    jsr @r3
    mov #0x6, r0
    mov #0x0, r2
    mov.l r2, @-r15
    mov r2, r7
    mov.l   .L_pool_buffer_slot_alloc, r3
    jsr @r3
    mov.l @(20, r14), r4
    mov r0, r4
    tst r4, r4
    bt/s    .L_alloc_zero
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_alloc_zero:
    lds.l @r15+, pr
    mov.l   .L_pool_state_field_read, r3
    jmp @r3
    mov.l @r15+, r14
    .4byte  track_surface_check
.L_pool_memcpy_byte:
    .4byte  sym_06035228
.L_pool_buffer_slot_alloc:
    .4byte  buffer_slot_alloc
.L_pool_state_field_read:
    .4byte  state_field_read
    .4byte  0x4F26000B
    .4byte  0x6EF6E500
