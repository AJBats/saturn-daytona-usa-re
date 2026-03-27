
    .section .text.FUN_0601AF8C


    .global FUN_0601AF8C
    .type FUN_0601AF8C, @function
FUN_0601AF8C:
    sts.l pr, @-r15
    .reloc ., R_SH_IND12W, FUN_0601B0D8 - 4
    .2byte 0xB000    /* bsr FUN_0601B0D8 (linker-resolved) */
    nop
    mov #0x14, r2
    mov.l   .L_pool_0601AFC8, r3
    mov.b r2, @r3
    mov.l   .L_pool_0601AFCC, r4
    lds.l @r15+, pr
    mov.b @r4, r2
    add #0x1, r2
    rts
    mov.b r2, @r4


    .global FUN_0601AFA4
    .type FUN_0601AFA4, @function
FUN_0601AFA4:
    sts.l pr, @-r15
    .reloc ., R_SH_IND12W, FUN_0601B0D8 - 4
    .2byte 0xB000    /* bsr FUN_0601B0D8 (linker-resolved) */
    nop
    mov #0x60, r6
    mov.l   .L_pool_0601AFD4, r3
    mov.l   .L_pool_0601AFD0, r7
    mov r6, r5
    add #0x36, r5
    jsr @r3
    mov #0x8, r4
    mov.l   .L_pool_0601AFD0, r7
    mov #0x60, r6
    mov.w   .L_0601AFC6, r5
    mov #0x8, r4
    mov.l   .L_pool_0601AFD4, r3
    jmp @r3
    lds.l @r15+, pr
.L_0601AFC6:
    .2byte  0x0196
.L_pool_0601AFC8:
    .4byte  sym_0608600F
.L_pool_0601AFCC:
    .4byte  sym_06086011
.L_pool_0601AFD0:
    .4byte  sym_0604A480
.L_pool_0601AFD4:
    .4byte  sym_060284AE
