
    .section .text.FUN_0603B9A4


    .global FUN_0603B9A4
    .type FUN_0603B9A4, @function
FUN_0603B9A4:
    sts.l pr, @-r15
    add #-0x4, r15
    .reloc ., R_SH_IND12W, FUN_0603B96A - 4
    .2byte 0xB000    /* bsr FUN_0603B96A (linker-resolved) */
    mov.l r4, @r15
    cmp/eq #-0x1, r0
    bf/s    .L_0603B9CE
    mov r0, r4
    .byte   0xD4, 0x0C    /* mov.l .L_pool_0603B9E4, r4 */
    mov.l @r4, r4
    add #0x34, r4
    mov #0x60, r0
    mov.l @(r0, r4), r3
    shll2 r3
    mov r4, r2
    add r2, r3
    mov.l @r15, r1
    mov.l r1, @r3
    mov #0x60, r0
    mov.l @(r0, r4), r3
    add #0x1, r3
    mov.l r3, @(r0, r4)
.L_0603B9CE:
    add #0x4, r15
    lds.l @r15+, pr
    rts
    nop
