
    .section .text.FUN_0603B290

    .global menu_list_scroll
    .type menu_list_scroll, @function
menu_list_scroll:
    mov.l r14, @-r15
    mov r4, r14
    mov.l r13, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0xC, r15
    mov.l r5, @r15
    mov.l r6, @(4, r15)
    mov.l r7, @(8, r15)
    mov.b @(r0, r14), r3
    extu.b r3, r3
    tst r3, r3
    bt      .L_0603B2B8
    mov #-0x10, r4
    add #0xC, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r13
    .byte   0xA3, 0x42    /* bra 0x0603B93C (external) */
    mov.l @r15+, r14
.L_0603B2B8:
    .byte   0xB3, 0x74    /* bsr 0x0603B9A4 (external) */
    mov r14, r4
    mov #0x1, r4
    mov #0x11, r0
    mov.b r4, @(r0, r14)
    mov #0x12, r0
    mov.b r4, @(r0, r14)
    mov.l @r14, r3
    mov.l @(16, r3), r8
    .byte   0xBE, 0xC5    /* bsr 0x0603B058 (external) */
    mov r14, r4
    mov r8, r4
    mov.l @r15, r3
    sub r0, r4
    cmp/ge r4, r3
    bt      .L_0603B2DC
    bra     .L_0603B2DE
    mov.l @r15, r13
.L_0603B2DC:
    mov r4, r13
.L_0603B2DE:
    mov r13, r5
    .byte   0xB5, 0xCC    /* bsr 0x0603BE7C (external) */
    mov.l @r14, r4
    mov r13, r5
    mov.l   .L_pool_0603B311, r3
    jsr @r3
    mov.l @(8, r14), r4
    mov #0x1, r7
    mov.l @(8, r15), r6
    mov.l @(4, r15), r5
    mov.l   .L_pool_0603B315, r3
    jsr @r3
    mov.l @(4, r14), r4
    mov.l   .L_pool_0603B319, r3
    jsr @r3
    mov.l @(8, r14), r4
    mov #0x0, r4
    add #0xC, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r13
    .byte   0xA3, 0x18    /* bra 0x0603B93C (external) */
    mov.l @r15+, r14
    .4byte  cdb_wait_scdq
.L_pool_0603B311:
    .4byte  sym_0603F9DA
.L_pool_0603B315:
    .4byte  sym_0603EF54
.L_pool_0603B319:
    .4byte  sym_0603FA00
