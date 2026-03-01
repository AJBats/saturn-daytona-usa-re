
    .section .text.FUN_0603F538


    .global attract_demo_select
    .type attract_demo_select, @function
attract_demo_select:
    sts.l pr, @-r15
    mov r4, r14
    add #-0x8, r15
    mov r15, r5
    .byte   0xBF, 0x59    /* bsr 0x0603F3F6 (external) */
    add #0x4, r5
    mov.b @(4, r15), r0
    mov r0, r4
    extu.b r4, r4
    tst r4, r4
    bf      .L_0603F578
    mov.l @(12, r14), r3
    add #0x1, r3
    mov.l r3, @(12, r14)
    mov r3, r2
    mov.l @(16, r14), r3
    cmp/eq r3, r2
    bt      .L_0603F578
    .byte   0x97, 0x2C    /* mov.w .L_wpool_0603F5B8, r7 */
    mov #0x1, r5
    .byte   0xD3, 0x16    /* mov.l .L_pool_0603F5BC, r3 */
    mov.l @(4, r14), r6
    jsr @r3
    mov.l @r14, r4
    mov #0x0, r2
    mov r14, r4
    mov #0x1, r6
    mov.l r2, @(8, r14)
    .byte   0xBF, 0x41    /* bsr 0x0603F3F6 (external) */
    mov r15, r5
    mov.b @r15, r5
    extu.b r5, r4
.L_0603F578:
    mov r4, r0
    add #0x8, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
