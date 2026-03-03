
    .section .text.FUN_06033402


    .global attract_mode_stub
    .type attract_mode_stub, @function
attract_mode_stub:
    sts.l pr, @-r15
    .byte   0xB1, 0x20    /* bsr 0x06033648 (external) */
    nop
    lds.l @r15+, pr
