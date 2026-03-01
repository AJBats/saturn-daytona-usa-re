
    .section .text.FUN_0603B21C


    .global cmd_multi_validate
    .type cmd_multi_validate, @function
cmd_multi_validate:
    mov.l r14, @-r15
    mov r4, r14
    mov.l r13, @-r15
    sts.l pr, @-r15
    add #-0xC, r15
    mov.l   .L_0603B274, r3
    mov.l r3, @(8, r15)
    mov.l @r14, r4
    mov.l @(40, r4), r13
    mov.l r3, @(40, r4)
    bsr     .L_0603B28E
    mov r14, r4
    mov r0, r4
    tst r4, r4
    bt      .L_0603B244
    mov.l @r14, r5
    .byte   0xB3, 0x7E    /* bsr 0x0603B93C (external) */
    mov.l r13, @(40, r5)
    bra     .L_0603B284
    nop
.L_0603B244:
    .byte   0xB0, 0xEE    /* bsr 0x0603B424 (external) */
    mov r14, r4
    mov r0, r4
    cmp/pz r4
    bt      .L_0603B258
    mov.l @r14, r5
    .byte   0xB3, 0x74    /* bsr 0x0603B93C (external) */
    mov.l r13, @(40, r5)
    bra     .L_0603B284
    nop
.L_0603B258:
    tst r4, r4
    bf      .L_0603B278
    mov r15, r6
    mov r15, r5
    add #0x4, r5
    .byte   0xB0, 0xCA    /* bsr 0x0603B3FA (external) */
    mov r14, r4
    .byte   0xB3, 0x69    /* bsr 0x0603B93C (external) */
    mov #0x0, r4
    mov.l @r14, r4
    bra     .L_0603B282
    mov.l r13, @(40, r4)

    .global DAT_0603b270
DAT_0603b270:
    mov.b r1, @(r0, r9)
    .word 0xFFFF
.L_0603B274:
    .4byte  0x7FFFFFFF
.L_0603B278:
    .byte   0xD3, 0x24    /* mov.l .L_pool_0603B30C, r3 */
    jsr @r3
    nop
    bra     .L_0603B244
    nop
.L_0603B282:
    mov.l @r15, r0
.L_0603B284:
    add #0xC, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_0603B28E:
    mov #0x12, r0
