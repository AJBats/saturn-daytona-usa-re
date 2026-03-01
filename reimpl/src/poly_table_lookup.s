
    .section .text.FUN_06017740


    .global poly_table_lookup
    .type poly_table_lookup, @function
poly_table_lookup:
    sts.l pr, @-r15
    extu.b r12, r3
    sts.l macl, @-r15
    .byte   0xDA, 0x18    /* mov.l .L_pool_060177A8, r10 */
    .byte   0xDB, 0x18    /* mov.l .L_pool_060177AC, r11 */
    cmp/pl r3
    bf/s    .L_06017774
    mov #0x0, r14
.L_06017750:
    mov #0x0, r7
    mov r13, r6
    extu.b r14, r5
    mov #0x36, r3
    add #0x40, r6
    muls.w r3, r5
    shll r6
    sts macl, r5
    exts.w r5, r5
    add r11, r5
    jsr @r10
    mov #0xC, r4
    add #0x1, r14
    extu.b r12, r3
    extu.b r14, r2
    cmp/ge r3, r2
    bf/s    .L_06017750
    add #0x1, r13
.L_06017774:
    lds.l @r15+, macl
    lds.l @r15+, pr
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
