
    .section .text.FUN_06017116


    .global poly_table_validate
    .type poly_table_validate, @function
poly_table_validate:
    sts.l pr, @-r15
    add #-0x4, r15
    mov.b r4, @r15
    .byte   0xD3, 0x1F    /* mov.l .L_pool_0601719C, r3 */
    jsr @r3
    mov #0x12, r4
    mov.b @r15, r4
    extu.b r4, r4
    add #0x4, r15
    .byte   0xA0, 0xDC    /* bra 0x060172E4 (external) */
    lds.l @r15+, pr
