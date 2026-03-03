
    .section .text.FUN_06012084


    .global file_size_get
    .type file_size_get, @function
file_size_get:
    sts.l pr, @-r15
    .byte   0xDE, 0x0F    /* mov.l .L_pool_060120C4, r14 */
    jsr @r14
    mov #0x8, r4
    .byte   0x94, 0x19    /* mov.w .L_wpool_060120C2, r4 */
    jsr @r14
    mov #0x5, r5
    mov #0x4, r5
    jsr @r14
    mov #0x10, r4
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14

    .global sym_0601209E
sym_0601209E:
    mov #0x7, r5
