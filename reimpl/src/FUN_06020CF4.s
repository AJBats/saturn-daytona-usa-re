
    .section .text.FUN_06020CF4


    .global FUN_06020CF4
    .type FUN_06020CF4, @function
FUN_06020CF4:
    mov.l r14, @-r15
    sts.l pr, @-r15
    .byte   0x95, 0x5B    /* mov.w .L_wpool_06020DB2, r5 */
    .byte   0xD4, 0x2E    /* mov.l .L_pool_06020DB4, r4 */
    exts.w r5, r0
    mov.w r0, @(8, r4)
    exts.w r5, r0
    mov.w r0, @(10, r4)
    exts.w r5, r0
    mov.w r0, @(12, r4)
    exts.w r5, r0
    mov.w r0, @(14, r4)
    exts.w r5, r0
    mov.w r0, @(16, r4)
    exts.w r5, r0
    mov.w r0, @(18, r4)
    exts.w r5, r0
    mov.w r0, @(20, r4)
    exts.w r5, r0
    mov.w r0, @(22, r4)
    mov #0x17, r0
    mov.w r0, @(6, r4)
    mov #0x0, r0
    mov.b r0, @(4, r4)
    mov #0x3A, r0
    mov.b r0, @(5, r4)
    .byte   0xDE, 0x23    /* mov.l .L_pool_06020DB8, r14 */
    .byte   0xD3, 0x24    /* mov.l .L_pool_06020DBC, r3 */
    mov.l @r14, r5
    jsr @r3
    nop
    .byte   0xD4, 0x23    /* mov.l .L_pool_06020DC0, r4 */
    mov.l @r4, r2
    add #0x1, r2
    mov.l r2, @r4
    mov.l @r14, r3
    add #0x20, r3
    mov.l r3, @r14
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14


    .global FUN_06020D46
    .type FUN_06020D46, @function
FUN_06020D46:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov #0x10, r11
