
    .section .text.FUN_0603F0FC


    .global scene_frame_render
    .type scene_frame_render, @function
scene_frame_render:
    mov.l r14, @-r15
    mov r4, r14
    mov.l r13, @-r15
    mov.l r12, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    .byte   0xDC, 0x1E    /* mov.l .L_pool_0603F184, r12 */
    mov.l r6, @r15
    tst r14, r14
    bt/s    .L_check_render_mode
    mov r5, r13
    mov.l @r15, r5
    .byte   0xD3, 0x1C    /* mov.l .L_pool_0603F188, r3 */
    jsr @r3
    mov r14, r4
.L_dispatch_loop:
    jsr @r12
    mov r14, r4
    tst r0, r0
    bf      .L_dispatch_loop
.L_check_render_mode:
    mov.l @r13, r0
    tst r0, r0
    bf      .L_render_text
    mov.l @(4, r13), r6
    mov.l @(8, r13), r5
    .byte   0xB0, 0xD8    /* bsr 0x0603F2E0 (external) */
    mov r14, r4
    bra     .L_epilogue
    nop
.L_render_text:
    mov.l @(4, r13), r6
    mov.l @(8, r13), r5
    .byte   0xB1, 0x03    /* bsr 0x0603F342 (external) */
    mov r14, r4
.L_epilogue:
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
