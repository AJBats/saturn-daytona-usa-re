
    .section .text.FUN_06040668


    .global FUN_06040668
    .type FUN_06040668, @function
FUN_06040668:
    sts.l pr, @-r15
    .reloc ., R_SH_IND12W, FUN_060405B8 - 4
    .2byte 0xB000    /* bsr FUN_060405B8 (linker-resolved) */
    mov r5, r4
    tst r0, r0
    bf      .L_06040678
    lds.l @r15+, pr
    rts
    mov #0x1, r0
.L_06040678:
    mov #0x0, r0
    lds.l @r15+, pr
    rts
    nop
