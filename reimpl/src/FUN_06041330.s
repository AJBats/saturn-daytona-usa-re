
    .section .text.FUN_06041330


    .global FUN_06041330
    .type FUN_06041330, @function
FUN_06041330:
    sts.l pr, @-r15
    add #-0x4, r15
    .byte   0xD3, 0x0C    /* mov.l .L_pool_06041368, r3 */
    jsr @r3
    mov.l r4, @r15
    mov r0, r4
    tst r4, r4
    bt      .L_06041346
    .byte   0xD3, 0x0A    /* mov.l .L_pool_0604136C, r3 */
    jsr @r3
    mov.l @r15, r4
.L_06041346:
    add #0x4, r15
    .byte   0xD3, 0x09    /* mov.l .L_pool_06041370, r3 */
    jmp @r3
    lds.l @r15+, pr


    .global FUN_0604134E
    .type FUN_0604134E, @function
FUN_0604134E:
    sts.l pr, @-r15
    mov.l   .L_pool_06041365, r3
    mov.l @r3, r3
    mov.l @(56, r3), r2
    cmp/eq r5, r2
    bt      .L_06041374
    lds.l @r15+, pr
    rts
    mov #-0x9, r0
    .4byte  0x0338033C
.L_pool_06041365:
    .4byte  sym_060A5400
    .4byte  FUN_060349C4
    .4byte  FUN_06034984
    .4byte  sym_06035C4E
.L_06041374:
    .byte   0xD3, 0x1E    /* mov.l @cross-TU pool (FUN_060349B6), r3 */
    jsr @r3
    nop
    mov #0x0, r0
    lds.l @r15+, pr
    rts
    nop

    .global FUN_06041382
    .type FUN_06041382, @function
FUN_06041382:
    mov.l r14, @-r15
    sts.l pr, @-r15
    add #-0x8, r15
    mov.l   .L_pool_060413F5, r14
    mov.l @r14, r3
    add #0x18, r3
    mov.l r3, @(4, r15)
    add r4, r3
    mov.b @r3, r3
    tst r3, r3
    bt      .L_060413A2
    mov.l @(4, r15), r3
    add r5, r3
    mov.b @r3, r3
    tst r3, r3
    bf      .L_060413AC
.L_060413A2:
    mov #-0x7, r0
    add #0x8, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_060413AC:
    mov.l @r14, r3
    mov.w   .L_060413EE, r0
    mov.l @(r0, r3), r0
    tst r0, r0
    bt      .L_060413C0
    mov #-0x1, r0
    add #0x8, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_060413C0:
    mov.l @r14, r3
    mov #0x1, r2
    mov.w   .L_060413EE, r0
    mov.l r2, @(r0, r3)
    mov.l @r14, r3
    add #0x4, r0
    mov.l r4, @(r0, r3)
    add #0x4, r0
    mov.l @r14, r3
    mov.l r5, @(r0, r3)
    mov.l @r14, r3
    add #0x4, r0
    mov.l r6, @(r0, r3)
    add #0x4, r0
    mov.l @r14, r3
    mov.l r7, @(r0, r3)
    .reloc ., R_SH_IND12W, FUN_06041EE8 - 4
    .2byte 0xB000    /* bsr FUN_06041EE8 (linker-resolved) */
    mov r15, r4
    mov #0x0, r0
    add #0x8, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_060413EE:
    .2byte  0x0348
    .4byte  FUN_06034DEA
.L_pool_060413F5:
    .4byte  sym_060A5400
    .4byte  0xD3149026
    .4byte  0x6332003E
    .4byte  0x20088901
    .4byte  0x000BE000
    .4byte  0xE001000B
    .2byte  0x0009

    .global FUN_0604140E
    .type FUN_0604140E, @function
FUN_0604140E:
    sts.l pr, @-r15
    add #-0xC, r15
    cmp/pz r4
    bf      .L_0604141C
    mov #0x18, r2
    cmp/ge r2, r4
    bf      .L_06041424
.L_0604141C:
    add #0xC, r15
    lds.l @r15+, pr
    rts
    mov #-0x6, r0
.L_06041424:
    mov.l   .L_0604144C, r0
    mov.l @r0, r0
    mov.b @(r0, r4), r3
    tst r3, r3
    bf      .L_06041436
    add #0xC, r15
    lds.l @r15+, pr
    rts
    mov #-0x7, r0
.L_06041436:
    mov.l   .L_06041450, r3
    jsr @r3
    nop
    mov r0, r4
    tst r4, r4
    bt      .L_06041454
    add #0xC, r15
    lds.l @r15+, pr
    rts
    mov #-0xA, r0
    .2byte  0x0348
.L_0604144C:
    .4byte  sym_060A5400
.L_06041450:
    .4byte  FUN_0603667E
.L_06041454:
    .byte   0xD3, 0x1C    /* mov.l .L_pool_060414C8, r3 */
    jsr @r3
    mov r15, r4
    mov.l   .L_060414CC, r2
    mov.l @r2, r2
    mov r15, r3
    mov.b @r3, r1
    mov #0x40, r0
    mov.b r1, @(r0, r2)
    mov #0x0, r0
    add #0xC, r15
    lds.l @r15+, pr
    rts
    nop


    .global FUN_06041470
    .type FUN_06041470, @function
FUN_06041470:
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_060414CC, r6
    mov.l @r6, r0
    add #0x18, r0
    mov.b @(r0, r5), r0
    cmp/eq #0x1, r0
    bf      .L_06041488
    mov.l @r6, r0
    mov.b @(r0, r5), r0
    cmp/eq #0x1, r0
    bt      .L_06041490
.L_06041488:
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov #-0x5, r0
.L_06041490:
    mov.l @r6, r2
    mov.w   .L_060414C4, r0
    mov.l @(r0, r2), r0
    tst r0, r0
    bt      .L_060414A2
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov #-0x1, r0
.L_060414A2:
    mov #0x1, r2
    mov.w   .L_060414C4, r0
    mov.l @r6, r3
    mov.l r2, @(r0, r3)
    add #0x4, r0
    mov.l @r6, r3
    mov.l r4, @(r0, r3)
    mov.l @r6, r3
    add #0x4, r0
    mov.l r5, @(r0, r3)
    .reloc ., R_SH_IND12W, FUN_06042088 - 4
    .2byte 0xB000    /* bsr FUN_06042088 (linker-resolved) */
    mov r15, r4
    mov #0x0, r0
    add #0x4, r15
    lds.l @r15+, pr
    rts
    nop
.L_060414C4:
    .2byte  0x0360
    .2byte  0xFFFF
    .4byte  FUN_060349B6
.L_060414CC:
    .4byte  sym_060A5400
