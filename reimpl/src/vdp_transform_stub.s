
    .section .text.FUN_0602DB0C


    .global vdp_transform_stub
    .type vdp_transform_stub, @function
vdp_transform_stub:
    mov.l r14, @-r15
    .byte   0xD4, 0x2D    /* mov.l .L_pool_0602DBC4, r4 */
    .byte   0xD5, 0x2D    /* mov.l .L_pool_0602DBC8, r5 */
    .byte   0xDD, 0x2E    /* mov.l .L_pool_0602DBCC, r13 */
