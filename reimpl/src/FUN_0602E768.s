
    .section .text.FUN_0602E768


    .global FUN_0602E768
    .type FUN_0602E768, @function
FUN_0602E768:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    .global FUN_0602E770
FUN_0602E770:
    mov r0, r7
    cmp/pz r7
    bt      .L_0602E778
    neg r7, r7
.L_0602E778:
    mov.l   .L_0602E788, r11
    cmp/ge r11, r7
    bt      .L_0602E78C
    bra     .L_0602E7C0
    nop
    .2byte  0x0000
    .4byte  FUN_06027476
.L_0602E788:
    .4byte  0x000F0000
    .global FUN_0602E78C
FUN_0602E78C:

.L_0602E78C:
    mov.l   .L_0602E7B0, r0
    mov.l @(r0, r9), r3
    mov.l   .L_0602E7B4, r1
    mov.l r3, @r1
    mov.l   .L_0602E7B8, r0
    mov.l @(r0, r9), r3
    mov.l   .L_0602E7BC, r1
    mov.l r3, @r1
    mov.l @r15+, r14
    mov.l @r15+, r13
    mov.l @r15+, r12
    mov.l @r15+, r11
    mov.l @r15+, r10
    mov.l @r15+, r9
    mov.l @r15+, r8
    rts
    nop
    .2byte  0x0000
.L_0602E7B0:
    .4byte  0x00000238
.L_0602E7B4:
    .4byte  DAT_06083264
.L_0602E7B8:
    .4byte  0x0000023C
.L_0602E7BC:
    .4byte  DAT_06083268
    .global FUN_0602E7C0
FUN_0602E7C0:

.L_0602E7C0:
    mov.l @(16, r9), r6
    mov.l @(24, r9), r7
    mov.l @(16, r10), r11
    mov.l @(24, r10), r12
    mov.l r0, @-r15
    mov r11, r4
    sub r6, r4
    mov r12, r5
    sub r7, r5
    mov.l   .L_pool_0602E80C, r0


    .global FUN_0602E7D4
    .type FUN_0602E7D4, @function
FUN_0602E7D4:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    neg r0, r13
    exts.w r13, r13
    mov.l @r15+, r0
    mov.w   DAT_0602e80a, r4
    mov.l @(40, r9), r1
    extu.w r4, r4
    mov r4, r3
    extu.w r13, r6
    shll r3
    or r3, r6
    sub r6, r1
    cmp/pl r1
    bt      .L_0602E7F8
    neg r1, r1
.L_0602E7F8:
    mov.l   .L_pool_0602E811, r7
    mov.b @r7, r7
    tst r7, r7
    bf      .L_0602E814
    extu.w r1, r1
    cmp/gt r1, r4
    .byte   0x89, 0x2E    /* bt 0x0602E864 (external) */
    bra     .L_0602E81A
    nop

    .global DAT_0602e80a
DAT_0602e80a:
    .2byte  0x8000
.L_pool_0602E80C:
    .4byte  FUN_0602744C
.L_pool_0602E811:
    .4byte  sym_06078663
.L_0602E814:
    extu.w r1, r1
    cmp/gt r1, r4
    .byte   0x8B, 0x24    /* bf 0x0602E864 (external) */
.L_0602E81A:
    mov.l   .L_pool_0602E834, r3
    cmp/ge r3, r8
    .byte   0x89, 0x11    /* bt 0x0602E844 (external) */
    mov.l   .L_pool_0602E838, r4
    mov.l   .L_pool_0602E83C, r5
    mov.l   .L_pool_0602E840, r13


    .global FUN_0602E826
    .type FUN_0602E826, @function
FUN_0602E826:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    bra     FUN_0602E78C
    nop
    .2byte  0x0000
.L_pool_0602E834:
    .4byte  0x00000050
.L_pool_0602E838:
    .4byte  0x00000000
.L_pool_0602E83C:
    .4byte  0xAE1106FF
.L_pool_0602E840:
    .4byte  FUN_0601D5F4
    .4byte  0xD404D505
    .2byte  0xDD05

    .global FUN_0602E84A
    .type FUN_0602E84A, @function
FUN_0602E84A:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    bra     FUN_0602E78C
    nop
    .2byte  0x0000
    .4byte  0x00000000
    .4byte  0xAE110AFF
    .4byte  FUN_0601D5F4
    .4byte  0xD3053833
    .4byte  0x8910D405
    .4byte  0xD505DD06
