
    .section .text.FUN_0603F354


    .global credits_page_build
    .type credits_page_build, @function
credits_page_build:
    sts.l pr, @-r15
    add #-0x38, r15
    mov.l   .L_pool_buf_init, r10
    mov.l r4, @r15
    mov r15, r4
    bsr     ring_desc_init
    add #0x24, r4
    bra     .L_loop_test
    mov #0x0, r13
.L_loop_body:
    mov r15, r5
    mov r15, r4
    add #0x4, r5
    .byte   0xB1, 0x09    /* bsr 0x0603F582 (external) */ ! call vblank_dma_chain — read next entry record
    add #0x24, r4
    mov r15, r2
    add #0x4, r2
    mov.b @r2, r3
    extu.b r3, r3
    tst r3, r3
    bf      .L_entry_valid
    bra     .L_loop_done
    nop
.L_pool_buf_init:
    .4byte  display_buffer_init
.L_entry_valid:
    cmp/gt r12, r13
    bf      .L_copy_entry
    mov #0xC, r6
    mov r15, r5
    mov r14, r4
    .byte   0xD3, 0x28    /* mov.l .L_pool_0603F430, r3 */ ! r3 = &memcmp-like function (cross-TU pool)
    add #0x4, r5
    add #0x10, r5
    jsr @r3
    add #-0xC, r4
    tst r0, r0
    bf      .L_copy_entry
    bra     .L_advance_entry
    nop
.L_copy_entry:
    mov r15, r5
    add #0x4, r5
    .byte   0xB2, 0x52    /* bsr 0x0603F84C (external) */ ! call entry copy routine (cross-TU)
    mov r14, r4
    mov #0xC, r6
    mov r15, r5
    mov r14, r4
    add #0x4, r5
    add #0x10, r5
    jsr @r10
    add #0xC, r4
.L_advance_entry:
    add #0x18, r14
    add #0x1, r13
    add #-0x1, r11
.L_loop_test:
    cmp/pl r11
    bt      .L_loop_body
.L_loop_done:
    add #-0x18, r14
    mov.b @(11, r14), r0
    or #0x80, r0
    mov.b r0, @(11, r14)
    mov r13, r0
    add #0x38, r15
    lds.l @r15+, pr
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

ring_desc_init:
    mov.l r5, @r4
    .byte   0xD3, 0x15    /* mov.l .L_pool_0603F434, r3 */ ! r3 = &game_state_base (cross-TU pool)
    .byte   0x92, 0x24    /* mov.w .L_wpool_0603F42A, r2 */ ! r2 = ring buffer offset constant
    mov.l @r3, r3
    add r3, r2
    mov.l r2, @(4, r4)
    mov #-0x1, r3
    mov.l r3, @(8, r4)
    mov.l @r5, r2
    mov.l @(16, r2), r3
    mov #0x0, r2
    mov.l r3, @(16, r4)
    rts
    mov.l r2, @(12, r4)
