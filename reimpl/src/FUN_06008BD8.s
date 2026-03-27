
    .section .text.FUN_06008BD8


    .global FUN_06008BD8
    .type FUN_06008BD8, @function
FUN_06008BD8:
    sts.l pr, @-r15
    mov #0xB, r3
    mov.l   .L_pool_06008C38, r2
    mov.l r3, @r2
    .byte   0xD3, 0x16    /* mov.l .L_pool_06008C3C, r3 */
    jsr @r3
    nop
    .byte   0xD3, 0x16    /* mov.l .L_pool_06008C40, r3 */
    jsr @r3
    nop
    mov #0x0, r2
    .byte   0xD3, 0x15    /* mov.l .L_pool_06008C44, r3 */
    mov.l r2, @r3
    mov #0x3, r2
    .byte   0xD3, 0x14    /* mov.l .L_pool_06008C48, r3 */
    lds.l @r15+, pr
    rts
    mov.w r2, @r3


    .global FUN_06008BFC
    .type FUN_06008BFC, @function
FUN_06008BFC:
    sts.l pr, @-r15
    .byte   0xD3, 0x13    /* mov.l .L_pool_06008C4C, r3 */
    jsr @r3
    nop
    tst r0, r0
    bt      .L_06008C0E
    mov #0x6, r3
    mov.l   .L_pool_06008C38, r2
    mov.l r3, @r2
.L_06008C0E:
    lds.l @r15+, pr
    rts
    nop

    .global FUN_06008C14
    .type FUN_06008C14, @function
FUN_06008C14:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov.l   .L_pool_06008C38, r14
    mov.l   .L_pool_06008C50, r3
    jsr @r3
    nop
    tst r0, r0
    bt      .L_06008C66
    mov.l   .L_pool_06008C54, r0
    mov.b @r0, r0
    extu.b r0, r0
    tst r0, r0
    bf      .L_06008C58
    mov #0x4, r3
    mov.l r3, @r14
    bra     .L_06008C5C
    nop
    .2byte  0xFFFF
.L_pool_06008C38:
    .4byte  FUN_0605ACC4
    .4byte  FUN_0601B160
    .4byte  sym_06026CE0
    .4byte  sym_06059F44
    .4byte  sym_0605A016
    .4byte  FUN_0601B418
.L_pool_06008C50:
    .4byte  FUN_0601F8C0
.L_pool_06008C54:
    .4byte  sym_0605E0A2
.L_06008C58:
    mov #0x7, r2
    mov.l r2, @r14
.L_06008C5C:
    mov #0x0, r3
    mov.l   .L_pool_06008CBA, r2
    mov.b r3, @r2
    bra     .L_06008C6A
    nop
.L_06008C66:
    mov #0x1F, r2
    mov.l r2, @r14
.L_06008C6A:
    mov #0x3, r3
    .byte   0xD2, 0x12    /* mov.l .L_pool_06008CB8, r2 */
    mov.w r3, @r2
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14


    .global FUN_06008C76
    .type FUN_06008C76, @function
FUN_06008C76:
    sts.l pr, @-r15
    mov.l   .L_pool_06008CC2, r3
    jsr @r3
    nop
    tst r0, r0
    bt      .L_06008CAC
    mov.l   .L_pool_06008CC6, r4
    mov.l   .L_pool_06008CBA, r0
    mov.b @r0, r0
    extu.b r0, r0
    tst r0, r0
    bf      .L_06008CA2
    mov #0x4, r3
    mov.l r3, @r4
    mov.l   .L_pool_06008CCA, r3
    jsr @r3
    nop
    mov.l   .L_pool_06008CCE, r3
    jsr @r3
    nop
    bra     .L_06008CA6
    nop
.L_06008CA2:
    mov #0x6, r2
    mov.l r2, @r4
.L_06008CA6:
    mov #0x0, r3
    mov.l   .L_pool_06008CBA, r2
    mov.b r3, @r2
.L_06008CAC:
    lds.l @r15+, pr
    rts
    nop
    .2byte  0xFFFF
.L_pool_06008CBA:
    .4byte  sym_0605E0A2
    .4byte  sym_0605A016
.L_pool_06008CC2:
    .4byte  FUN_0601F900
.L_pool_06008CC6:
    .4byte  FUN_0605ACC4
.L_pool_06008CCA:
    .4byte  sym_060149E0
.L_pool_06008CCE:
    .4byte  sym_06026CE0
