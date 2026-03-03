
    .section .text.FUN_0602F99C


    .global sprite_batch_render
    .type sprite_batch_render, @function
sprite_batch_render:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    .byte   0xDE, 0x18    /* mov.l .L_pool_0602FA08, r14 */
