
    .section .text.FUN_06040680


    .global FUN_06040680
    .type FUN_06040680, @function
FUN_06040680:
    sts.l pr, @-r15
    mov #0x0, r5
    .reloc ., R_SH_IND12W, FUN_060405B8 - 4
    .2byte 0xB000    /* bsr FUN_060405B8 (linker-resolved) */
    mov r5, r4
    cmp/eq #0x4, r0
    bf      .L_06040692
    lds.l @r15+, pr
    rts
    mov #0x0, r0
.L_06040692:
    mov #0x1, r0
    lds.l @r15+, pr
    rts
    nop

    .global sym_0604069A
sym_0604069A:
    add #-0x4, r15
    mov.l r4, @r15
    mov.l @(24, r4), r4
    .byte   0xD3, 0x0E    /* mov.l .L_pool_060406DC, r3 */
    jmp @r3
    add #0x4, r15

    .global sym_060406A6
sym_060406A6:
    add #-0x4, r15
    mov.l r4, @r15
    mov #0x0, r6
    mov.l @(24, r4), r4
    .byte   0xD3, 0x0C    /* mov.l .L_pool_060406E0, r3 */
    jmp @r3
    add #0x4, r15
