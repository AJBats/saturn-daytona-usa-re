	.text
    .global anim_frame_counter
anim_frame_counter:
    mov.l r14, @-r15
    mov.l r13, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.w   DAT_060059da, r13
    mov.l   .L_pool_060059EC, r4
    mov.l   .L_pool_060059F0, r5
    mov.l @r5, r3
    cmp/pl r3
    bf.s    .L_06005A18
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
    .byte   0xB2, 0x17    /* bsr 0x06005DD4 (anim_frame_transform) */
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
    .short  0x05A4

    .global DAT_060059dc
DAT_060059dc:
    .short  0x021C

    .global DAT_060059de
DAT_060059de:
    .short  0x0220

    .global DAT_060059e0
DAT_060059e0:
    .short  0x0240

    .global DAT_060059e2
DAT_060059e2:
    .short  0x7000

    .global DAT_060059e4
DAT_060059e4:
    .short  0x061C

    .global DAT_060059e6
DAT_060059e6:
    .short  0x5000
.L_wpool_060059E8:
    .short  0x0090
    .short  0xFFFF


.L_pool_060059EC:
    .long  sym_0607E944
.L_pool_060059F0:
    .long  sym_0607EAC0
.L_pool_060059F4:
    .long  sym_0607EBF4
.L_pool_060059F8:
    .long  0x000927BF
.L_pool_060059FC:
    .long  sym_06063810
.L_pool_06005A00:
    .long  sym_06028400
.L_pool_06005A04:
    .long  sym_06063818
.L_pool_06005A08:
    .long  sym_060284AE
.L_pool_06005A0C:
    .long  sym_0605ACE5
.L_pool_06005A10:
    .long  sym_060283E0
.L_pool_06005A14:
    .long  sym_0605ACDD


.L_06005A18:
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
