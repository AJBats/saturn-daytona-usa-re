
    .section .text.FUN_060333F4


    .global disp_result_sub_c
    .type disp_result_sub_c, @function
disp_result_sub_c:
    sts.l pr, @-r15
    .reloc ., R_SH_IND12W, FUN_06033550 - 4
    .2byte 0xB000    /* bsr FUN_06033550 (linker-resolved) */
    nop
    lds.l @r15+, pr
    .byte   0xD1, 0x17    /* mov.l .L_pool_0603345C, r1 */
    mov #0x8, r2
    mov.w r2, @r1
