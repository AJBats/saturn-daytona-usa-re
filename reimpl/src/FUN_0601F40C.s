
    .section .text.FUN_0601F40C


    .global FUN_0601F40C
    .type FUN_0601F40C, @function
FUN_0601F40C:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov.l   .L_pool_0601F495, r14
    .byte   0xD2, 0x21    /* mov.l .L_pool_0601F498, r2 */
    mov.b @r14, r3
    extu.b r3, r3
    add r2, r3
    mov.b @r3, r0
    extu.b r0, r0
    tst r0, r0
    bt      .L_0601F45E
    .reloc ., R_SH_IND12W, FUN_0601EFC4 - 4
    .2byte 0xB000    /* bsr FUN_0601EFC4 (linker-resolved) */
    nop
    .byte   0xD6, 0x1D    /* mov.l .L_pool_0601F49C, r6 */
    mov.b @r14, r5
    mov.l   .L_pool_0601F4A1, r2
    mov.b @r14, r4
    mov.l @r6, r6
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
    .reloc ., R_SH_IND12W, FUN_0601E810 - 4
    .2byte 0xB000    /* bsr FUN_0601E810 (linker-resolved) */
    extu.b r4, r4
    mov r0, r4
    tst r4, r4
    bt      .L_0601F45E
    mov #0xC, r3
    .byte   0xD2, 0x15    /* mov.l .L_pool_0601F4A8, r2 */
    mov.b r3, @r2
    lds.l @r15+, pr
    .byte   0xD3, 0x14    /* mov.l .L_pool_0601F4AC, r3 */
    jmp @r3
    mov.l @r15+, r14
.L_0601F45E:
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14


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
    bra     FUN_0601F40C
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
