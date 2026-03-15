
    .section .text.FUN_0601228C


    .global FUN_0601228C
    .type FUN_0601228C, @function

FUN_0601228C:
    sts.l pr, @-r15
    mov.l   .L_pool_060122D8, r4
    mov.l @r4, r3
    cmp/ge r2, r3
    bf      .L_060122A2
    .reloc ., R_SH_IND12W, FUN_060122F4 - 4
    .2byte 0xB000    /* bsr FUN_060122F4 (linker-resolved) */
    nop
    .reloc ., R_SH_IND12W, FUN_0601250C - 4
    .2byte 0xB000    /* bsr FUN_0601250C (linker-resolved) */
    nop
    .reloc ., R_SH_IND12W, FUN_06012710 - 4
    .2byte 0xA000    /* bra FUN_06012710 (linker-resolved) */
    lds.l @r15+, pr
.L_060122A2:
    mov #0x64, r3
    mov.l   .L_pool_060122DC, r6
    mov.l @r4, r2
    cmp/ge r3, r2
    bf/s    .L_060122B8
    mov #0x0, r5
    exts.w r5, r5
    .reloc ., R_SH_IND12W, FUN_0601250C - 4
    .2byte 0xB000    /* bsr FUN_0601250C (linker-resolved) */
    mov.w r5, @r6
    .reloc ., R_SH_IND12W, FUN_06012710 - 4
    .2byte 0xA000    /* bra FUN_06012710 (linker-resolved) */
    lds.l @r15+, pr
.L_060122B8:
    mov.l @r4, r2
    mov #0x28, r3
    cmp/ge r3, r2
    bf      .L_060122E0
    exts.w r5, r5
    .reloc ., R_SH_IND12W, FUN_060125D0 - 4
    .2byte 0xB000    /* bsr FUN_060125D0 (linker-resolved) */
    mov.w r5, @r6
    .reloc ., R_SH_IND12W, FUN_06012710 - 4
    .2byte 0xA000    /* bra FUN_06012710 (linker-resolved) */
    lds.l @r15+, pr
    .2byte  0xFFFF
    .4byte  sym_06078636
    .4byte  0xAE110FFF
    .4byte  FUN_0601D5F4
.L_pool_060122D8:
    .4byte  sym_0607EBCC
.L_pool_060122DC:
    .4byte  sym_060788B2
.L_060122E0:
    mov #0x1, r5
    mov #0x10, r2
    mov.l r5, @r4
    exts.b r5, r5
    .byte   0xD3, 0x10    /* mov.l .L_pool_0601232C, r3 */
    mov.l r2, @r3
    .byte   0xD3, 0x10    /* mov.l .L_pool_06012330, r3 */
    lds.l @r15+, pr
    rts
    mov.b r5, @r3
