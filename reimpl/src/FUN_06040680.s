
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


    .global FUN_060406B4
    .type FUN_060406B4, @function
FUN_060406B4:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r8, @-r15
    mov r4, r13

    .global FUN_060406BC
    .type FUN_060406BC, @function
FUN_060406BC:
    sts.l pr, @-r15
    add #-0xC, r15
    .reloc ., R_SH_IND12W, FUN_06040666 - 4
    .2byte 0xB000    /* bsr FUN_06040666 (linker-resolved) */
    mov.l r5, @r15
    tst r0, r0
    bf      .L_060406CC
    bra     .L_06040716
    mov #0x0, r0
.L_060406CC:
    mov.l   .L_060406E4, r3
    jsr @r3
    nop
    mov r0, r14
    cmp/pz r14
    bt      .L_060406E8
    bra     .L_06040716
    mov #0x0, r0
    .4byte  sym_060409DE
    .4byte  FUN_060409E6
.L_060406E4:
    .4byte  sym_06040FB8
.L_060406E8:
    mov r15, r3
    mov #0x1, r2
    add #0x4, r3
    mov.l r2, @r3
    mov r15, r3
    mov.l @r15, r5
    add #0x4, r3
    mov r3, r8
    add #0x4, r8
    bsr     .L_06040722
    mov r13, r4
    mov r14, r5
    mov r15, r4
    mov.l @(4, r13), r2
    add r2, r0
    mov.l r0, @r8
    .byte   0xD3, 0x18    /* mov.l .L_pool_0604076C, r3 */
    jsr @r3
    add #0x4, r4
    .byte   0xD3, 0x18    /* mov.l .L_pool_06040770, r3 */
    jsr @r3
    mov r14, r4
    mov #0x1, r0
.L_06040716:
    add #0xC, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .global FUN_06040722
FUN_06040722:
.L_06040722:
    mov #0x1E, r0

    .global FUN_06040724
    .type FUN_06040724, @function
FUN_06040724:
    sts.l pr, @-r15
    sts.l macl, @-r15
    mov.b @(r0, r4), r3
    extu.b r3, r3
    tst r3, r3
    bf      .L_0604073A
    mov r5, r0
    lds.l @r15+, macl
    lds.l @r15+, pr
    rts
    nop
.L_0604073A:
    mov #0x1E, r0
    mov r5, r1
    mov.l   .L_06040774, r3
    mov.b @(r0, r4), r6
    extu.b r6, r6
    jsr @r3
    mov r6, r0
    mov #0x1F, r2
    mov r6, r3
    mov r5, r1
    add r4, r2
    mov.b @r2, r2
    extu.b r2, r2
    add r2, r3
    mul.l r3, r0
    mov.l   .L_06040778, r2
    sts macl, r0
    mov r0, r3
    jsr @r2
    mov r6, r0
    add r3, r0
    lds.l @r15+, macl
    lds.l @r15+, pr
    rts
    nop
    .4byte  FUN_0604134E
    .4byte  sym_06040FEA
.L_06040774:
    .4byte  sym_06034FFC
.L_06040778:
    .4byte  sym_06036BE4
