
    .section .text.FUN_0603B3FE


    .global FUN_0603B3FE
    .type FUN_0603B3FE, @function
FUN_0603B3FE:
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l r4, @r15
    mov.b @(r0, r3), r3
    extu.b r3, r3
    mov.l r3, @r5
    .byte   0xD5, 0x04    /* mov.l .L_0603B41C, r5 */
    mov.l @r15, r4
    .byte   0xD3, 0x04    /* mov.l .L_0603B420, r3 */
    jsr @r3
    mov.l @(4, r4), r4
    mov #0x0, r4
    add #0x4, r15
    .reloc ., R_SH_IND12W, FUN_0603B93C - 4
    .2byte 0xA000    /* bra FUN_0603B93C (linker-resolved) */
    lds.l @r15+, pr
.L_0603B41C:
    .4byte  0x7FFFFFFF
.L_0603B420:
    .4byte  FUN_0603EF64
