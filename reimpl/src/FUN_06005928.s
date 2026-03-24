
    .section .text.FUN_06005928


    .global FUN_06005928
    .type FUN_06005928, @function
FUN_06005928:
    mov.l r14, @-r15
    mov.l r13, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.w   DAT_060059da, r13
    mov.l   .L_pool_060059EC, r4
    mov.l   .L_pool_060059F0, r5
    mov.l @r5, r3
    cmp/pl r3
    bf/s    .L_06005A18
    mov.l @r4, r4
    mov.l @r5, r3
    add #-0x1, r3
    mov.l r3, @r5
    mov.w   DAT_060059dc, r0
    mov.l @(r0, r4), r0
    tst r0, r0
    bt      .L_06005A18
    mov.l   .L_pool_060059F4, r0
    mov.l @r0, r0
    tst r0, r0
    bf      .L_06005A18
    mov.l @r5, r0
    tst #0x2, r0
    bt      .L_060059BA
    mov.w   DAT_060059de, r0
    mov.l   .L_pool_060059F8, r5
    mov.l @(r0, r4), r14
    cmp/gt r5, r14
    bf      .L_06005966
    mov r5, r14
.L_06005966:
    mov.w   DAT_060059e0, r0
    mov.l @(r0, r4), r2
    cmp/eq r2, r14
    bf      .L_0600598A
    mov.l   .L_pool_060059FC, r2
    mov r13, r6
    mov.l r2, @r15
    mov r2, r7
    mov r2, r5
    mov.w   DAT_060059e2, r3
    mov.l @(4, r7), r7
    mov.l @r5, r5
    add r3, r7
    mov.l   .L_pool_06005A00, r3
    jsr @r3
    mov #0x8, r4
    bra     .L_060059A2
    nop
.L_0600598A:
    mov r13, r6
    mov.l   .L_pool_06005A04, r2
    mov.l r2, @r15
    mov r2, r7
    mov r2, r5
    mov.w   DAT_060059e2, r3
    mov.l @(4, r7), r7
    mov.l @r5, r5
    add r3, r7
    mov.l   .L_pool_06005A00, r3
    jsr @r3
    mov #0x8, r4
.L_060059A2:
    .reloc ., R_SH_IND12W, FUN_06005DD4 - 4
    .2byte 0xB000         /* bsr FUN_06005DD4 (linker-resolved) */
    mov r14, r4
    mov r0, r7
    mov #0x78, r6
    mov.w   DAT_060059e4, r5
    mov #0x8, r4
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    mov.l   .L_pool_06005A08, r3
    jmp @r3
    mov.l @r15+, r14
.L_060059BA:
    mov r13, r5
    mov.l   .L_pool_06005A10, r3
    mov.l   .L_pool_06005A0C, r7
    mov.w   DAT_060059e6, r6
    jsr @r3
    mov #0x8, r4
    mov.l   .L_pool_06005A14, r7
    mov.w   .L_wpool_060059E8, r6
    mov.w   DAT_060059e4, r5
    mov #0x8, r4
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    mov.l   .L_pool_06005A08, r3
    jmp @r3
    mov.l @r15+, r14


    .global DAT_060059da
DAT_060059da:
    .2byte  0x05A4

    .global DAT_060059dc
DAT_060059dc:
    .2byte  0x021C

    .global DAT_060059de
DAT_060059de:
    .2byte  0x0220

    .global DAT_060059e0
DAT_060059e0:
    .2byte  0x0240

    .global DAT_060059e2
DAT_060059e2:
    .2byte  0x7000

    .global DAT_060059e4
DAT_060059e4:
    .2byte  0x061C

    .global DAT_060059e6
DAT_060059e6:
    .2byte  0x5000
.L_wpool_060059E8:
    .2byte  0x0090
    .2byte  0xFFFF


.L_pool_060059EC:
    .4byte  sym_0607E944
.L_pool_060059F0:
    .4byte  sym_0607EAC0
.L_pool_060059F4:
    .4byte  sym_0607EBF4
.L_pool_060059F8:
    .4byte  0x000927BF
.L_pool_060059FC:
    .4byte  sym_06063810
.L_pool_06005A00:
    .4byte  sym_06028400
.L_pool_06005A04:
    .4byte  sym_06063818
.L_pool_06005A08:
    .4byte  sym_060284AE
.L_pool_06005A0C:
    .4byte  sym_0605ACE5
.L_pool_06005A10:
    .4byte  sym_060283E0
.L_pool_06005A14:
    .4byte  sym_0605ACDD


.L_06005A18:
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14


    .global FUN_06005A22
    .type FUN_06005A22, @function
FUN_06005A22:
    mov.l r14, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    .byte   0xD4, 0x26    /* mov.l .L_pool_06005AC4, r4 */
    mov.l @r4, r3
    cmp/pl r3
    bf      .L_06005AE0
    mov.l @r4, r3
    add #-0x1, r3
    mov r3, r0
    tst #0x1, r0
    bt/s    .L_06005A9C
    mov.l r3, @r4
    .byte   0xD0, 0x22    /* mov.l .L_pool_06005AC8, r0 */
    mov.b @r0, r0
    tst r0, r0
    bt      .L_06005A4A
    mov.w   .L_wpool_06005ABA, r14
    bra     .L_06005A4C
    nop
.L_06005A4A:
    mov #0x21, r14
.L_06005A4C:
    .byte   0xD0, 0x1F    /* mov.l .L_pool_06005ACC, r0 */
    mov.l @r0, r0
    tst r0, r0
    bt      .L_06005A78
    mov r14, r7
    shll2 r7
    shll r7
    .byte   0xD3, 0x1D    /* mov.l .L_pool_06005AD0, r3 */
    add r3, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.w   DAT_06005abc, r3
    add r3, r7
    mov.w   DAT_06005abe, r6
    mov.l @r15, r5
    mov.l @r5, r5
    mov #0x8, r4
    add #0x4, r15
    lds.l @r15+, pr
    .byte   0xD3, 0x18    /* mov.l .L_pool_06005AD4, r3 */
    jmp @r3
    mov.l @r15+, r14
.L_06005A78:
    mov r14, r7
    shll2 r7
    shll r7
    .byte   0xD3, 0x14    /* mov.l .L_pool_06005AD0, r3 */
    add r3, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.w   DAT_06005abc, r3
    add r3, r7
    mov.w   DAT_06005ac0, r6
    mov.l @r15, r5
    mov.l @r5, r5
    mov #0x8, r4
    add #0x4, r15
    lds.l @r15+, pr
    .byte   0xD3, 0x0F    /* mov.l .L_pool_06005AD4, r3 */
    jmp @r3
    mov.l @r15+, r14
.L_06005A9C:
    .byte   0xD7, 0x0E    /* mov.l .L_pool_06005AD8, r7 */
    mov.w   .L_wpool_06005AC2, r6
    mov.w   DAT_06005abe, r5
    .byte   0xD3, 0x0E    /* mov.l .L_pool_06005ADC, r3 */
    jsr @r3
    mov #0x8, r4
    .byte   0xD7, 0x0B    /* mov.l .L_pool_06005AD8, r7 */
    mov.w   .L_wpool_06005AC2, r6
    mov.w   DAT_06005ac0, r5
    mov #0x8, r4
    add #0x4, r15
    lds.l @r15+, pr
    .byte   0xD3, 0x09    /* mov.l .L_pool_06005ADC, r3 */
    jmp @r3
    mov.l @r15+, r14


.L_wpool_06005ABA:
    .2byte  0x00B0

    .global DAT_06005abc
DAT_06005abc:
    .2byte  0x5000

    .global DAT_06005abe
DAT_06005abe:
    .2byte  0x049C

    .global DAT_06005ac0
DAT_06005ac0:
    .2byte  0x059C

.L_wpool_06005AC2:
    .2byte  0x0090


.L_pool_06005AC4:
    .4byte  sym_0607EABC
.L_pool_06005AC8:
    .4byte  sym_06085FF4
.L_pool_06005ACC:
    .4byte  sym_0607EAC0
.L_pool_06005AD0:
    .4byte  sym_06063750
.L_pool_06005AD4:
    .4byte  sym_06028400
.L_pool_06005AD8:
    .4byte  sym_0605ACDD
.L_pool_06005ADC:
    .4byte  sym_060284AE


.L_06005AE0:
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
