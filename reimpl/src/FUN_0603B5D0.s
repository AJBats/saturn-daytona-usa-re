
    .section .text.FUN_0603B5D0


    .global FUN_0603B5D0
    .type FUN_0603B5D0, @function
FUN_0603B5D0:
    sts.l pr, @-r15
    mov r4, r3
    add #-0x4, r15
    mov.l r4, @r15
    mov.l r5, @(12, r3)
    mov.l @r15, r4
    .byte   0xD3, 0x12    /* mov.l .L_pool_0603B628, r3 */
    jsr @r3
    mov.l @(8, r4), r4
    mov.l r0, @r15
    .reloc ., R_SH_IND12W, FUN_0603B93C - 4
    .2byte 0xB000    /* bsr FUN_0603B93C (linker-resolved) */
    mov #0x0, r4
    mov.l @r15, r0
    add #0x4, r15
    lds.l @r15+, pr
    rts
    nop
