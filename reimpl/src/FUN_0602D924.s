
    .section .text.FUN_0602D924


    .global FUN_0602D924
    .type FUN_0602D924, @function
FUN_0602D924:
    sts.l pr, @-r15
    mov r0, r14
    .byte   0x93, 0x11    /* mov.w .L_wpool_0602D94E, r3 */
    mov.l @(48, r0), r5
    mov.l @(r0, r3), r1
    .byte   0xD0, 0x08    /* mov.l .L_pool_0602D950, r0 */
    mov.l r12, @-r15
    .byte   0xDC, 0x08    /* mov.l .L_pool_0602D954, r12 */
