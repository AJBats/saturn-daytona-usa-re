
    .section .text.FUN_06041180


    .global FUN_06041180
    .type FUN_06041180, @function
FUN_06041180:
    sts.l pr, @-r15
    .byte   0xD3, 0x1E    /* mov.l .L_pool_060411FC, r3 */
    mov.l @r3, r3
    mov.l @(56, r3), r2
    cmp/eq r5, r2
    bt      .L_06041192
    lds.l @r15+, pr
    rts
    mov #-0x9, r0
.L_06041192:
    .byte   0xD3, 0x1B    /* mov.l .L_pool_06041200, r3 */
    jsr @r3
    nop
    mov #0x0, r0
    lds.l @r15+, pr
    rts
    nop


    .global FUN_060411A0
    .type FUN_060411A0, @function
FUN_060411A0:
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_pool_060411FC, r1
    mov.w   DAT_060411f6, r0
    mov.l @r1, r3
    mov.l @(r0, r3), r0
    tst r0, r0
    bt      .L_060411B8
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov #-0x1, r0
.L_060411B8:
    mov.l @r1, r3
    mov #0x1, r2
    mov.w   DAT_060411f6, r0
    mov.l r2, @(r0, r3)
    mov.l @r1, r3
    add #0x4, r0
    mov #0x0, r2
    mov.l r4, @(r0, r3)
    mov.l @r1, r3
    add #0x4, r0
    mov.l r5, @(r0, r3)
    add #0x4, r0
    mov.l @r1, r3
    mov.l r6, @(r0, r3)
    mov.l @r1, r3
    add #0x4, r0
    mov.l r2, @(r0, r3)
    add #0x4, r0
    mov.l @r1, r3
    mov.l r7, @(r0, r3)
    mov.l @r1, r3
    mov.l @(8, r15), r2
    mov.w   .L_wpool_060411F8, r0
    mov.l r2, @(r0, r3)
    .reloc ., R_SH_IND12W, FUN_06041B3C - 4
    .2byte 0xB000    /* bsr FUN_06041B3C (linker-resolved) */
    mov r15, r4
    mov #0x0, r0
    add #0x4, r15
    lds.l @r15+, pr
    rts
    nop

    .global DAT_060411f6
DAT_060411f6:
    .2byte  0x030C
.L_wpool_060411F8:
    .2byte  0x0324
    .2byte  0xFFFF
.L_pool_060411FC:
    .4byte  sym_060A5400
    .4byte  FUN_06034D1C
