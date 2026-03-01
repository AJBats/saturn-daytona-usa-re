
    .section .text.FUN_060210B8


    .global obj_cleanup
    .type obj_cleanup, @function
obj_cleanup:
    mov.l r14, @-r15
    mov #0x0, r14
    mov.l r13, @-r15
    mov #0x2C, r13
    mov.l r12, @-r15
    sts.l pr, @-r15
    .byte   0xDC, 0x13    /* mov.l .L_pool_06021114, r12 */
    .byte   0xD3, 0x14    /* mov.l .L_pool_06021118, r3 */
    jsr @r3
    mov #0x8, r4
    extu.b r14, r4
.L_060210CE:
    extu.b r4, r2
    .byte   0x93, 0x1F    /* mov.w .L_wpool_06021112, r3 */
    shll2 r2
    add #0x1, r4
    add r12, r3
    add r3, r2
    mov.l r14, @r2
    extu.b r4, r2
    cmp/ge r13, r2
    bf      .L_060210CE
    .byte   0xD4, 0x0C    /* mov.l .L_pool_06021114, r4 */
    .byte   0xD3, 0x0D    /* mov.l .L_pool_0602111C, r3 */
    jsr @r3
    nop
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    .byte   0xD3, 0x0B    /* mov.l .L_pool_06021120, r3 */
    jmp @r3
    mov.l @r15+, r14
