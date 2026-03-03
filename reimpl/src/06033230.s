
    .section .text.FUN_06033230


    .global results_separator
    .type results_separator, @function
results_separator:
    sts.l pr, @-r15
    .byte   0xB0, 0x21    /* bsr 0x06033278 (external) */
    nop
    lds.l @r15+, pr
    .byte   0xD4, 0x0D    /* mov.l .L_pool_06033270, r4 */
    add r4, r1
    and #0xF, r0
    mov r0, r5
