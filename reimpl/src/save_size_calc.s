
    .section .text.FUN_0603BC12


    .global save_size_calc
    .type save_size_calc, @function
save_size_calc:
    mov.l r14, @-r15
    mov.l r13, @-r15
    sts.l pr, @-r15
    add #-0x10, r15
    mov.l r4, @r15
    mov r15, r4
    .byte   0xBF, 0xB2    /* bsr 0x0603BB86 (external) */
    add #0x4, r4
    tst r0, r0
    bf      .L_0603BC2A
    bra     .L_0603BC3C
    mov #0x0, r14
.L_0603BC2A:
    .byte   0xBD, 0xF8    /* bsr 0x0603B81E (external) */
    nop
    mov r0, r13
    mov #0x0, r6
    mov r15, r5
    add #0x4, r5
    .byte   0xBE, 0xF9    /* bsr 0x0603BA2C (external) */
    mov r0, r4
    mov r0, r14
.L_0603BC3C:
    .byte   0xD0, 0x07    /* mov.l .L_pool_0603BC5D, r0 */
    mov.w   DAT_0603bc56, r1
    mov.l @r0, r0
    mov.l @(r0, r1), r0
    tst #0x1, r0
    bt      .L_0603BC60
    tst r14, r14
    bf      .L_0603BC60
    bra     .L_0603BC7C
    mov #-0x3, r0

    .global DAT_0603bc50
DAT_0603bc50:
    mov.b @(r0, r3), r4

    .global DAT_0603bc52
DAT_0603bc52:
    mov.b @(r0, r9), r0

    .global DAT_0603bc54
DAT_0603bc54:
    mov.l r9, @(r0, r0)

    .global DAT_0603bc56
DAT_0603bc56:
    .2byte  0x00C4
    .4byte  sym_060360FC
.L_pool_0603BC5D:
    .4byte  sym_060A4D14
.L_0603BC60:
    mov r15, r6
    mov.l @r15, r5
    .byte   0xD3, 0x1B    /* mov.l .L_pool_0603BCD4, r3 */
    add #0x4, r6
    mov.l @(4, r6), r6
    jsr @r3
    mov r14, r4
    mov.l r0, @r15
    tst r14, r14
    bt      .L_0603BC7A
    mov r14, r5
    .byte   0xB1, 0x54    /* bsr 0x0603BF22 (external) */
    mov r13, r4
.L_0603BC7A:
    mov.l @r15, r0
.L_0603BC7C:
    add #0x10, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
