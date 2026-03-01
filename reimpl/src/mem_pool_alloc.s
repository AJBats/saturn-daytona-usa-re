
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
    .byte   0xB9, 0x2B    /* bsr 0x0601E6E0 (mat_euler_rotate) */
    extu.b r4, r4
    .byte   0xBB, 0x71    /* bsr 0x0601EB70 (geom_normal_compute) */
    nop
    .byte   0xAF, 0xBD    /* bra 0x0601F40C (geom_output_handler, tail call) */
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
