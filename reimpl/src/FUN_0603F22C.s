
    .section .text.FUN_0603F22C


    .global FUN_0603F22C
    .type FUN_0603F22C, @function
FUN_0603F22C:
    mov.l   .L_0603F234, r4
    .reloc ., R_SH_IND12W, FUN_0603F238 - 4
    .2byte 0xA000    /* bra FUN_0603F238 (linker-resolved) */
    nop
    .2byte  0xFFFF
.L_0603F234:
    .4byte  0x00FFFFFF
