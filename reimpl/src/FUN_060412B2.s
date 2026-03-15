
    .section .text.FUN_060412B2


    .global FUN_060412B2
    .type FUN_060412B2, @function
FUN_060412B2:
    sts.l pr, @-r15
    add #-0x4, r15
    .byte   0xD7, 0x15    /* mov.l .L_pool_0604130D, r7 */
    mov.w   .L_06041306, r0
    mov.l @r7, r3
    mov.l @(r0, r3), r0
    tst r0, r0
    bt      .L_060412CA
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov #-0x1, r0
.L_060412CA:
    mov.l @r7, r0
    mov.l @(52, r0), r0
    cmp/eq #0x1, r0
    bf      .L_060412DA
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov #-0x5, r0
.L_060412DA:
    mov #0x1, r3
    mov.l @r7, r2
    mov.l r3, @(52, r2)
    mov.l @r7, r2
    mov.w   .L_06041306, r0
    mov.l r3, @(r0, r2)
    add #0x4, r0
    mov.l @r7, r3
    mov.l r4, @(r0, r3)
    mov.l @r7, r3
    add #0x4, r0
    mov.l r5, @(r0, r3)
    add #0x4, r0
    mov.l @r7, r3
    mov.l r6, @(r0, r3)
    .reloc ., R_SH_IND12W, FUN_06041D6C - 4
    .2byte 0xB000    /* bsr FUN_06041D6C (linker-resolved) */
    mov r15, r4
    mov #0x0, r0
    add #0x4, r15
    lds.l @r15+, pr
    rts
    nop
.L_06041306:
    .2byte  0x0338
    .4byte  FUN_060349B6
.L_pool_0604130D:
    .4byte  sym_060A5400
    .global FUN_06041310
FUN_06041310:
    .4byte  0xD5149025
    .4byte  0x6352003E
    .4byte  0x20088906
    .4byte  0x63529020
    .4byte  0x023E3240
    .4byte  0x8B01000B
    .4byte  0xE000E001
    .4byte  0x000B0009
