
    .section .text.FUN_0603F4B0


    .global FUN_0603F4B0
    .type FUN_0603F4B0, @function
FUN_0603F4B0:
    sts.l pr, @-r15
    add #-0x4, r15
    .reloc ., R_SH_IND12W, FUN_0603F3F6 - 4
    .2byte 0xB000    /* bsr FUN_0603F3F6 (linker-resolved) */
    mov r15, r5
    mov.b @r15, r0
    add #0x4, r15
    lds.l @r15+, pr
    rts
    nop
    .2byte  0x0800
    .4byte  FUN_0603B21C
    .4byte  sym_060360FC
