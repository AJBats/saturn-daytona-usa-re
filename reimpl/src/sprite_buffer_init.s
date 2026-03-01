
    .section .text.FUN_06011678


    .global sprite_buffer_init
    .type sprite_buffer_init, @function
sprite_buffer_init:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    sts.l pr, @-r15
    mov.w   .L_wpool_060116A2, r13
    mov.l   .L_060116A4, r12
    .byte   0xBF, 0xE1    /* bsr 0x0601164A (external) */
    mov #0x0, r14
    extu.w r14, r4
.L_0601168A:
    extu.w r4, r0
    shll2 r0
    add #0x1, r4
    extu.w r4, r3
    cmp/ge r13, r3
    bf/s    .L_0601168A
    mov.l r14, @(r0, r12)
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_wpool_060116A2:
    .2byte  0x0100
.L_060116A4:
    .4byte  0x25E5F800
