
    .section .text.FUN_06041826


    .global evt_callback_handler
    .type evt_callback_handler, @function
evt_callback_handler:
    mov.l r14, @-r15
    mov r5, r14
    bra     .L_06041860
    mov r4, r0
.L_0604182E:
    mov r14, r4
    .byte   0xA0, 0x45    /* bra 0x060418BE (external) */
    mov.l @r15+, r14
.L_06041834:
    mov r14, r4
    .byte   0xA1, 0x33    /* bra 0x06041AA0 (external) */
    mov.l @r15+, r14
.L_0604183A:
    mov r14, r4
    .byte   0xA1, 0x7E    /* bra 0x06041B3C (external) */
    mov.l @r15+, r14
.L_06041840:
    mov r14, r4
    .byte   0xA2, 0x41    /* bra 0x06041CC8 (external) */
    mov.l @r15+, r14
.L_06041846:
    mov r14, r4
    .byte   0xA2, 0x90    /* bra 0x06041D6C (external) */
    mov.l @r15+, r14
.L_0604184C:
    mov r14, r4
    .byte   0xA3, 0x4B    /* bra 0x06041EE8 (external) */
    mov.l @r15+, r14
.L_06041852:
    mov r14, r4
    .byte   0xA4, 0x6E    /* bra 0x06042134 (external) */
    mov.l @r15+, r14
.L_06041858:
    mov r14, r4
    .byte   0xA4, 0x15    /* bra 0x06042088 (external) */
    mov.l @r15+, r14
    .2byte  0x0360
.L_06041860:
    cmp/eq #0x0, r0
    bt      .L_0604182E
    cmp/eq #0x1, r0
    bt      .L_06041834
    cmp/eq #0x2, r0
    bt      .L_0604183A
    cmp/eq #0x3, r0
    bt      .L_06041840
    cmp/eq #0x4, r0
    bt      .L_06041846
    cmp/eq #0x5, r0
    bt      .L_0604184C
    cmp/eq #0x6, r0
    bt      .L_06041852
    cmp/eq #0x7, r0
    bt      .L_06041858
    rts
    mov.l @r15+, r14

    .global sym_06041884
sym_06041884:
    .byte   0xD3, 0x08    /* mov.l .L_pool_060418A8, r3 */
    mov.l @r3, r3
    rts
    mov.l r4, @(60, r3)
