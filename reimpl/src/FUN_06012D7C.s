
    .section .text.FUN_06012D7C


    .global FUN_06012D7C
    .type FUN_06012D7C, @function
FUN_06012D7C:
    mov.l r14, @-r15
    mov r4, r0
    mov.l   .L_06012DA4, r14
    cmp/eq #0x1, r0
    bf      .L_06012D8E
    mov r14, r5
    mov.l   .L_pool_06012DA8, r4
    .reloc ., R_SH_IND12W, FUN_06012C3C - 4
    .2byte 0xA000    /* bra FUN_06012C3C (linker-resolved) */
    mov.l @r15+, r14
.L_06012D8E:
    mov r4, r0
    cmp/eq #0x2, r0
    bf      .L_06012D9C
    mov r14, r5
    mov.l   .L_pool_06012DAC, r4
    .reloc ., R_SH_IND12W, FUN_06012C3C - 4
    .2byte 0xA000    /* bra FUN_06012C3C (linker-resolved) */
    mov.l @r15+, r14
.L_06012D9C:
    mov r14, r5
    mov.l   .L_pool_06012DB0, r4
    .reloc ., R_SH_IND12W, FUN_06012C3C - 4
    .2byte 0xA000    /* bra FUN_06012C3C (linker-resolved) */
    mov.l @r15+, r14
.L_06012DA4:
    .4byte  0x00200000
.L_pool_06012DA8:
    .4byte  sym_060448E8
.L_pool_06012DAC:
    .4byte  sym_060448F4
.L_pool_06012DB0:
    .4byte  sym_06044900
