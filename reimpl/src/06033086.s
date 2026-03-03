
    .section .text.FUN_06033086


    .global disp_util_stub_a
    .type disp_util_stub_a, @function
disp_util_stub_a:
    sts.l pr, @-r15
    .byte   0xB1, 0x52    /* bsr 0x06033330 (external) */
    nop
    lds.l @r15+, pr
