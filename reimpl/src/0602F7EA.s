	.text
    .global sprite_transform
sprite_transform:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    .byte   0xDE, 0x15    /* mov.l .L_pool_0602F848, r14 */
