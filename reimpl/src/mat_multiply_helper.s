
    .section .text.FUN_0601E636


    .global mat_multiply_helper
    .type mat_multiply_helper, @function
mat_multiply_helper:
    mov.l r14, @-r15
    mov.l r13, @-r15
    sts.l pr, @-r15
    .byte   0xDD, 0x15    /* mov.l .L_0601E694, r13 */
    mov #0x1, r14
.L_0601E640:
    mov.b @r13, r2
    extu.b r2, r2
    and r14, r2
    cmp/eq r14, r2
    bt      .L_0601E640
    extu.b r14, r2
    mov.b r2, @r13
    mov #0x1A, r3
    .byte   0xD2, 0x11    /* mov.l .L_0601E698, r2 */
    mov.b r3, @r2
.L_0601E654:
    mov.b @r13, r2
    extu.b r2, r2
    and r14, r2
    tst r2, r2
    bf      .L_0601E654
    .byte   0xD3, 0x0F    /* mov.l .L_0601E69C, r3 */
    .byte   0xD7, 0x0F    /* mov.l .L_0601E6A0, r7 */
    mov.l @r3, r3
    mov.l @(28, r3), r2
    jsr @r2
    mov #0x10, r6
    mov r0, r6
.L_0601E66C:
    mov.b @r13, r2
    extu.b r2, r2
    and r14, r2
    cmp/eq r14, r2
    bt      .L_0601E66C
    extu.b r14, r2
    mov.b r2, @r13
    mov #0x19, r3
    .byte   0xD2, 0x06    /* mov.l .L_0601E698, r2 */
    mov.b r3, @r2
.L_0601E680:
    mov.b @r13, r2
    extu.b r2, r2
    and r14, r2
    tst r2, r2
    bf      .L_0601E680
    mov r6, r0
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_0601E694:
    .4byte  0x20100063                  /* SMPC SF — status flag */
.L_0601E698:
    .4byte  0x2010001F                  /* SMPC COMREG (cache-through) */
.L_0601E69C:
    .4byte  sym_06000354                /* function dispatch table pointer */
.L_0601E6A0:
    .4byte  sym_060870F4                /* data pointer passed as r7 to dispatch */
