
    .section .text.FUN_06028368


    .global FUN_06028368
    .type FUN_06028368, @function
FUN_06028368:
    sts.l pr, @-r15
    mov.l   .L_06028380, r0
    mov.l @(r0, r4), r2
    mov.l @r2, r2
    add r2, r5
    .reloc ., R_SH_IND12W, FUN_060282C0 - 4
    .2byte 0xB000    /* bsr FUN_060282C0 (linker-resolved) */
    mov r7, r4
    mov r0, r1
    mov #0xC, r7
    add #0x5, r1
    .reloc ., R_SH_IND12W, FUN_06028398 - 4
    .2byte 0xA000    /* bra FUN_06028398 (linker-resolved) */
    mov #0x0, r0
.L_06028380:
    .4byte  sym_06028614
