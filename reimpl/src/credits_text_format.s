
    .section .text.FUN_0603F2EC


    .global credits_text_format
    .type credits_text_format, @function
credits_text_format:
    sts.l pr, @-r15
    add #-0x38, r15
    mov.l r4, @r15
    mov r15, r4
    .byte   0xB0, 0x71    /* bsr 0x0603F3DA (external) */ ! call ring_desc_init — init ring buffer descriptor
    add #0x24, r4
    mov #0x0, r4
    cmp/gt r4, r13
    bf/s    .L_loop_done
    mov r4, r12
.L_loop_body:
    mov r15, r5
    mov r15, r4
    add #0x4, r5
    .byte   0xB1, 0x3C    /* bsr 0x0603F582 (external) */ ! call vblank_dma_chain — read next entry record
    add #0x24, r4
    mov r15, r2
    add #0x4, r2
    mov.b @r2, r3
    extu.b r3, r3
    tst r3, r3
    bf      .L_entry_valid
    bra     .L_loop_done
    nop
.L_entry_valid:
    mov r15, r5
    add #0x4, r5
    .byte   0xB2, 0x95    /* bsr 0x0603F84C (external) */ ! call entry copy routine — copy entry to output
    mov r14, r4
    add #0xC, r14
    add #-0x1, r13
    cmp/pl r13
    bt/s    .L_loop_body
    add #0x1, r12
.L_loop_done:
    add #-0xC, r14
    mov.b @(11, r14), r0
    or #0x80, r0
    mov.b r0, @(11, r14)
    mov r12, r0
    add #0x38, r15
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
