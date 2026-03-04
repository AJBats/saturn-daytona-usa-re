
    .section .text.FUN_06033086


    .global disp_util_stub_a
    .type disp_util_stub_a, @function
disp_util_stub_a:
    sts.l pr, @-r15
    .reloc ., R_SH_IND12W, FUN_06033330 - 4
    .2byte 0xB000    /* bsr FUN_06033330 (linker-resolved) */
    nop
    lds.l @r15+, pr
