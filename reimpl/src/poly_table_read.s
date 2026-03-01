
    .section .text.FUN_060170FC


    .global poly_table_read
    .type poly_table_read, @function
poly_table_read:
    sts.l pr, @-r15
    mov #0x0, r6
    mov #0x12, r5
    add #-0x4, r15
    mov.b r4, @r15
    .byte   0xD3, 0x24    /* mov.l .L_pool_06017198, r3 */
    jsr @r3
    mov r5, r4
    mov.b @r15, r4
    extu.b r4, r4
    add #0x4, r15
    .byte   0xA0, 0xE7    /* bra 0x060172E4 (external) */
    lds.l @r15+, pr
