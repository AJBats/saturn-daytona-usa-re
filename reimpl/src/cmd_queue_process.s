
    .section .text.FUN_0603AEE8


    .global cmd_queue_process
    .type cmd_queue_process, @function
cmd_queue_process:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    sts.l pr, @-r15
    mov.l   .L_pool_0603AF7A, r14
    mov.w   .L_wpool_0603AF72, r0
    mov.l @r14, r3
    mov.l @(r0, r3), r0
    tst r0, r0
    bt/s    .L_0603AF14
    mov r4, r13
    cmp/pz r13
    bf      .L_0603AF0C
    mov.l @r14, r2
    mov.w   DAT_0603af72, r0
    mov.l @(r0, r2), r3
    cmp/ge r3, r13
    bf      .L_0603AF14
.L_0603AF0C:
    .byte   0xB5, 0x16    /* bsr 0x0603B93C (external) */
    mov #-0xA, r4
    bra     .L_0603AF8A
    mov #0x0, r0
.L_0603AF14:
    .byte   0xB4, 0x83    /* bsr 0x0603B81E (external) */
    nop
    mov r0, r12
    tst r12, r12
    bf      .L_0603AF26
    .byte   0xB5, 0x0D    /* bsr 0x0603B93C (external) */
    mov #-0x13, r4
    bra     .L_0603AF8A
    mov #0x0, r0
.L_0603AF26:
    mov.l @r14, r2
    mov.w   .L_wpool_0603AF72, r0
    mov.l @(r0, r2), r0
    tst r0, r0
    bf      .L_0603AF34
    bra     .L_0603AF5C
    mov #0x0, r5
.L_0603AF34:
    mov.l @r14, r2
    mov.w   .L_wpool_0603AF76, r0
    mov.l @(r0, r2), r0
    tst r0, r0
    bf      .L_0603AF4E
    mov.l @r14, r5
    mov.w   .L_wpool_0603AF72, r0
    mov.l   .L_pool_0603AF7E, r3
    mov.l @(r0, r5), r5
    jsr @r3
    mov r13, r4
    bra     .L_0603AF5A
    nop
.L_0603AF4E:
    mov.l @r14, r5
    mov.w   .L_wpool_0603AF72, r0
    mov.l   .L_pool_0603AF82, r3
    mov.l @(r0, r5), r5
    jsr @r3
    mov r13, r4
.L_0603AF5A:
    mov r0, r5
.L_0603AF5C:
    mov r13, r6
    .byte   0xB5, 0x65    /* bsr 0x0603BA2C (external) */
    mov r12, r4
    mov r0, r14
    tst r14, r14
    bf      .L_0603AF84
    .byte   0xB4, 0xE8    /* bsr 0x0603B93C (external) */
    mov #-0xA, r4
    bra     .L_0603AF88
    nop
.L_wpool_0603AF72:
    .2byte  0x00A0

    .global DAT_0603af72
DAT_0603af72:
    .2byte  0x00A4
.L_wpool_0603AF76:
    .2byte  0x0098
    .2byte  0xFFFF
.L_pool_0603AF7A:
    .4byte  sym_060A4D14
.L_pool_0603AF7E:
    .4byte  sym_0603F1E0
.L_pool_0603AF82:
    .4byte  sym_0603F1F0
.L_0603AF84:
    .byte   0xB4, 0xDA    /* bsr 0x0603B93C (external) */
    mov #0x0, r4
.L_0603AF88:
    mov r14, r0
.L_0603AF8A:
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
