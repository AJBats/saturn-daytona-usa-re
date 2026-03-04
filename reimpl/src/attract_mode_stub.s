
    .section .text.FUN_06033402


    .global attract_mode_stub
    .type attract_mode_stub, @function
attract_mode_stub:
    sts.l pr, @-r15
    .reloc ., R_SH_IND12W, FUN_06033648 - 4
    .2byte 0xB000    /* bsr FUN_06033648 (linker-resolved) */
    nop
    lds.l @r15+, pr
