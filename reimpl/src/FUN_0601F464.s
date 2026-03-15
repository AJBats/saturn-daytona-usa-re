
    .section .text.FUN_0601F464


    .global FUN_0601F464
    .type FUN_0601F464, @function
FUN_0601F464:
    sts.l pr, @-r15
    mov.l   .L_pool_0601F495, r5
    mov.l   .L_pool_0601F4A1, r2
    mov.l   .L_pool_0601F495, r4
    mov.b @r5, r5
    mov.b @r4, r4
    extu.b r5, r5
    extu.b r4, r4
    mov r5, r3
    shll2 r5
    shll2 r3
    shll r3
    add r3, r5
    add r2, r5
    mov.l   .L_pool_0601F4A5, r3
    add r3, r4
    mov.b @r4, r4
    .reloc ., R_SH_IND12W, FUN_0601E6E0 - 4
    .2byte 0xB000    /* bsr FUN_0601E6E0 (linker-resolved) */
    extu.b r4, r4
    .reloc ., R_SH_IND12W, FUN_0601EB70 - 4
    .2byte 0xB000    /* bsr FUN_0601EB70 (linker-resolved) */
    nop
    .reloc ., R_SH_IND12W, FUN_0601F40C - 4
    .2byte 0xA000    /* bra FUN_0601F40C (linker-resolved) */
    lds.l @r15+, pr
    .2byte  0xFFFF
.L_pool_0601F495:
    .4byte  sym_060877D8
    .4byte  sym_060877DD
    .4byte  sym_0605E098
.L_pool_0601F4A1:
    .4byte  sym_0604A57C
.L_pool_0601F4A5:
    .4byte  sym_060877D9
    .4byte  sym_0605E05C
    .4byte  sym_0601F8BC
    .4byte  0x000B0009
