	.text
    .global hud_post_update
hud_post_update:
    add #-0x4, r15
    mov r4, r5
    mov.l r4, @r15
    shll2 r5
    .byte   0x96, 0x30    /* mov.w .L_wpool_06010AC8, r6 */
    .byte   0xD3, 0x1A    /* mov.l .L_pool_06010AD0, r3 */
    .byte   0xD4, 0x1A    /* mov.l .L_pool_06010AD4, r4 */
    add r3, r5
    mov.l @r4, r4
    mov.l @r5, r5
    shll2 r4
    shll r4
    .byte   0xD2, 0x18    /* mov.l .L_pool_06010AD8, r2 */
    mov.l @r2, r2
    add r2, r4
    mov r6, r1
    add #0x40, r1
    add r1, r4
    .byte   0xD1, 0x16    /* mov.l .L_pool_06010ADC, r1 */
    jmp @r1
    add #0x4, r15
    .short  0x644D
    .long  0x931F2439
    .long  0x24488904
    .long  0xE301D213
    .long  0x2232A003
    .long  0x0009E300
    .long  0xD2102232
    .long  0x000B0009
