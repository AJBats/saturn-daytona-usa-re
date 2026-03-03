	.text
    .global transform_chain_entry
transform_chain_entry:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    .byte   0xD4, 0x2C    /* mov.l .L_pool_0602DBD0, r4 */
    .byte   0xD5, 0x2A    /* mov.l .L_pool_0602DBC8, r5 */
    .byte   0xDD, 0x2A    /* mov.l .L_pool_0602DBCC, r13 */
