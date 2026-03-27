
    .section .text.FUN_0601B48C


    .global FUN_0601B48C
    .type FUN_0601B48C, @function
FUN_0601B48C:
    sts.l pr, @-r15
    add #-0x4, r15
    mov.w   .L_pool_0601B4F2, r6
    mov.l   .L_pool_0601B4F8, r5
    mov.l   .L_pool_0601B4FC, r4
    mov.l   .L_pool_0601B500, r3
    jsr @r3
    nop
    mov.l   .L_pool_0601B504, r5
    mov.l   .L_pool_0601B508, r4
    mov.l   .L_pool_0601B500, r3
    jsr @r3
    mov #0x20, r6
    mov.l   .L_pool_0601B50C, r3
    jsr @r3
    nop
    mov.l   .L_pool_0601B510, r3
    jsr @r3
    mov #0xC, r4
    mov #0x16, r6
    mov.l   .L_pool_0601B514, r2
    mov.l r2, @r15
    mov r2, r7
    mov r2, r5
    mov.l   .L_pool_0601B518, r3
    mov.l @(4, r7), r7
    mov.l @r5, r5
    add r3, r7
    mov.l   .L_pool_0601B51C, r3
    jsr @r3
    mov #0x8, r4
    mov #0x1, r2
    mov.l   .L_pool_0601B520, r3
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov.b r2, @r3


    .global FUN_0601B4D6
    .type FUN_0601B4D6, @function
FUN_0601B4D6:
    sts.l pr, @-r15
    mov.l   .L_0601B524, r3
    mov.w @r3, r2
    mov.w   .L_0601B4F4, r3
    extu.w r2, r2
    and r3, r2
    tst r2, r2
    bt      .L_0601B530
    mov #0x1, r3
    mov.l   .L_0601B528, r2
    mov.b r3, @r2
    mov.l   .L_0601B52C, r3
    jmp @r3
    lds.l @r15+, pr
.L_pool_0601B4F2:
    .2byte  0x0080
.L_0601B4F4:
    .2byte  0x0100
    .2byte  0xFFFF
.L_pool_0601B4F8:
    .4byte  sym_060485EC
.L_pool_0601B4FC:
    .4byte  0x25F00020
.L_pool_0601B500:
    .4byte  FUN_0602761E
.L_pool_0601B504:
    .4byte  sym_060485CC
.L_pool_0601B508:
    .4byte  0x25F00180
.L_pool_0601B50C:
    .4byte  sym_06028560
.L_pool_0601B510:
    .4byte  sym_0602853E
.L_pool_0601B514:
    .4byte  sym_060638C8
.L_pool_0601B518:
    .4byte  0x0000C000
.L_pool_0601B51C:
    .4byte  sym_06028400
.L_pool_0601B520:
    .4byte  sym_0608600D
.L_0601B524:
    .4byte  sym_06063D9A
.L_0601B528:
    .4byte  sym_0608600C
.L_0601B52C:
    .4byte  FUN_06018E70
.L_0601B530:
    .reloc ., R_SH_IND12W, FUN_0601B7F4 - 4
    .2byte 0xB000    /* bsr FUN_0601B7F4 (linker-resolved) */
    nop
    .reloc ., R_SH_IND12W, FUN_0601B6DC - 4
    .2byte 0xB000    /* bsr FUN_0601B6DC (linker-resolved) */
    nop
    mov.l   .L_0601B570, r2
    mov.w @r2, r3
    mov.w   .L_0601B56E, r2
    extu.w r3, r3
    and r2, r3
    tst r3, r3
    bt      .L_0601B560
    mov.l   .L_0601B574, r0
    mov.b @r0, r0
    cmp/eq #0x2, r0
    bf      .L_0601B55A
    mov #0x1, r2
    mov.l   .L_0601B578, r3
    mov.b r2, @r3
    mov.l   .L_0601B57C, r3
    jmp @r3
    lds.l @r15+, pr
.L_0601B55A:
    mov #0x2, r2
    mov.l   .L_0601B580, r3
    mov.b r2, @r3
.L_0601B560:
    lds.l @r15+, pr
    rts
    nop

    .global FUN_0601B566
FUN_0601B566:
    mov #0x3, r3
    mov.l   .L_0601B580, r2
    rts
    mov.b r3, @r2
.L_0601B56E:
    .2byte  0x0E00
.L_0601B570:
    .4byte  sym_06063D9A
.L_0601B574:
    .4byte  sym_0608600E
.L_0601B578:
    .4byte  sym_0608600C
.L_0601B57C:
    .4byte  FUN_06018E70
.L_0601B580:
    .4byte  sym_0608600D
