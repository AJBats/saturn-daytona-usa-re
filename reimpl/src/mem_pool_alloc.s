
    .section .text.FUN_0601F464


    .global mem_pool_alloc
    .type mem_pool_alloc, @function
mem_pool_alloc:
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
    .reloc ., R_SH_IND12W, mat_euler_rotate - 4
    .2byte 0xB000    /* bsr mat_euler_rotate (linker-resolved) */
    extu.b r4, r4
    .reloc ., R_SH_IND12W, geom_normal_compute - 4
    .2byte 0xB000    /* bsr geom_normal_compute (linker-resolved) */
    nop
    .reloc ., R_SH_IND12W, geom_output_handler - 4
    .2byte 0xA000    /* bra geom_output_handler (linker-resolved) */
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
