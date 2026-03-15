
    .section .text.FUN_0603FE62


    .global FUN_0603FE62
    .type FUN_0603FE62, @function
FUN_0603FE62:
    sts.l pr, @-r15
    mov.l @(8, r15), r3
    mov.l r3, @-r15
    mov.l @(8, r15), r3
    mov.l r3, @-r15
    .reloc ., R_SH_IND12W, FUN_0603FD40 - 4
    .2byte 0xB000    /* bsr FUN_0603FD40 (linker-resolved) */
    mov #0x1, r4
    add #0x8, r15
    lds.l @r15+, pr
    rts
    nop

    .global FUN_0603FE78
FUN_0603FE78:
    rts
    mov #0x0, r0

    .global FUN_0603FE7C
FUN_0603FE7C:
    rts
    mov #0x1, r0
