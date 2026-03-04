
    .section .text.FUN_06033230


    .global results_separator
    .type results_separator, @function
results_separator:
    sts.l pr, @-r15
    .reloc ., R_SH_IND12W, FUN_06033278 - 4
    .2byte 0xB000    /* bsr FUN_06033278 (linker-resolved) */
    nop
    lds.l @r15+, pr
    .byte   0xD4, 0x0D    /* mov.l .L_pool_06033270, r4 */
    add r4, r1
    and #0xF, r0
    mov r0, r5
