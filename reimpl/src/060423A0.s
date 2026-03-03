	.text
    .global bulk_struct_init
bulk_struct_init:
    sts.l pr, @-r15
    add #-0xC, r15
    .byte   0xD3, 0x14    /* mov.l .L_pool_060423F8, r3 */
    jsr @r3
    mov r15, r4
    mov r15, r3
    mov #0x40, r0
    .byte   0xD2, 0x13    /* mov.l .L_pool_060423FC, r2 */
    mov.b @r3, r1
    mov.l @r2, r2
    add #0xC, r15
    lds.l @r15+, pr
    rts
    mov.b r1, @(r0, r2)
    .long  0xD60FE04C
    .long  0x63620346
    .long  0x6362E050
    .long  0x000B0356
