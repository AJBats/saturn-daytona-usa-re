
    .section .text.FUN_0600E7C8


    .global FUN_0600E7C8
    .type FUN_0600E7C8, @function
FUN_0600E7C8:
    mov.l r14, @-r15
    sts.l pr, @-r15
    sts.l macl, @-r15

    mov.l   .L_0600E878, r14
    mov.l   .L_0600E87C, r3
    jsr @r3
    mov.l @r14, r14
    mov.l   .L_0600E880, r3
    jsr @r3
    nop
    mov.l   .L_0600E884, r3
    jsr @r3
    nop
    mov.l   .L_0600E888, r3
    jsr @r3
    nop
    mov.l   .L_0600E88C, r3
    jsr @r3
    nop

    mov.l   .L_0600E890, r0
    bra     .L_0600E898
    mov.b @r0, r0

.L_0600E7F4:
    mov.l @(40, r14), r4
    mov.w   DAT_0600e86c, r0
    mov.l @(r0, r14), r2
    sub r4, r2
    shll16 r2
    shar r2
    shar r2
    shlr16 r2
    exts.w r2, r2
    add r4, r2
    exts.w r2, r4
    exts.w r4, r5
    mov.l r5, @(48, r14)
    bra     .L_0600E8A0
    mov.l r5, @(40, r14)

.L_0600E812:
    mov.l @(40, r14), r4
    mov.w   DAT_0600e86c, r0
    mov.l   .L_0600E894, r3
    mov.l @(r0, r14), r2
    add #-0x54, r0
    sub r4, r2
    add r3, r2
    shll16 r2
    shar r2
    shlr16 r2
    exts.w r2, r2
    add r4, r2
    exts.w r2, r4
    exts.w r4, r5
    mov.l r5, @(48, r14)
    mov.l r5, @(40, r14)

    mov.l @(r0, r14), r0
    tst r0, r0
    bt      .L_0600E8A0
    mov.w   DAT_0600e86e, r0
    mov.l @(r0, r14), r3
    add #-0x1, r3
    mov.l r3, @(r0, r14)
    tst r3, r3
    bf      .L_0600E868

    mov.w   DAT_0600e870, r0
    mov.l @(r0, r14), r4
    mov r4, r3
    shll2 r4
    shll r4
    shll2 r3
    shll2 r3
    add r3, r4
    add #-0x4, r0
    mov.l @(r0, r14), r3
    add r3, r4
    mov.w @(20, r4), r0
    mov r0, r3
    mov.w   .L_0600E872, r0
    mov.l r3, @(r0, r14)
    mov.w   .L_0600E874, r3
    add #0xC, r0
    mov.l r3, @(r0, r14)

.L_0600E868:
    bra     .L_0600E8A0
    nop

    .global DAT_0600e86c
DAT_0600e86c:
    .2byte  0x025C

    .global DAT_0600e86e
DAT_0600e86e:
    .2byte  0x0208

    .global DAT_0600e870
DAT_0600e870:
    .2byte  0x01E4
.L_0600E872:
    .2byte  0x01F8
.L_0600E874:
    .2byte  0x0400
    .2byte  0xFFFF
.L_0600E878:
    .4byte  sym_0607E940
.L_0600E87C:
    .4byte  FUN_06008318
.L_0600E880:
    .4byte  sym_06008640
.L_0600E884:
    .4byte  FUN_0600D26A
.L_0600E888:
    .4byte  FUN_0600C4F8
.L_0600E88C:
    .4byte  sym_0602D88E
.L_0600E890:
    .4byte  sym_06083261
.L_0600E894:
    .4byte  0x00008000

.L_0600E898:
    cmp/eq #0x1, r0
    bt      .L_0600E7F4
    cmp/eq #0x2, r0
    bt      .L_0600E812

.L_0600E8A0:
    mov.l   .L_pool_0600E928, r3
    jsr @r3
    nop

    mov.w   .L_pool_0600E91E, r0
    mov.l   .L_pool_0600E92C, r3
    mov.l @(r0, r14), r2
    mov.l @r3, r3
    add #-0x3C, r0
    mul.l r3, r2
    mov.l @(r0, r14), r3
    sts macl, r2
    add #0x8, r0
    add r3, r2
    mov.l r2, @(r0, r14)

    add #-0x10, r0
    mov.l @(r0, r14), r4
    add #-0x4, r0
    mov r4, r3
    shll2 r4
    shll2 r3
    shll r4
    shll2 r3
    add r3, r4
    mov.l @(r0, r14), r3
    add r3, r4
    mov.w @(20, r4), r0
    mov r0, r3
    mov.w   DAT_0600e920, r0
    mov.l r3, @(r0, r14)

    mov.l   .L_pool_0600E930, r3
    mov.l   .L_pool_0600E934, r2
    mov.l @r3, r3
    and r2, r3
    tst r3, r3
    bt      .L_0600E8FE

    mov.l   .L_pool_0600E938, r5
    mov.l   .L_pool_0600E93C, r3
    jsr @r3
    mov.l @(12, r14), r4
    shlr16 r0
    exts.w r0, r0
    mov.w   DAT_0600e922, r1
    add r14, r1
    mov.l r0, @r1
    mov.w   .L_pool_0600E924, r1
    add r14, r1
    mov.l r0, @r1

.L_0600E8FE:
    lds.l @r15+, macl
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14


    .global FUN_0600E906
    .type FUN_0600E906, @function
FUN_0600E906:
    mov.l r14, @-r15
    sts.l pr, @-r15
    sts.l macl, @-r15
    mov.l   .L_pool_0600E942, r14
    mov.l   .L_pool_0600E946, r0
    mov.l @r0, r0
    tst r0, r0
    bt/s    .L_0600E948
    mov.l @r14, r14
    mov #0x0, r3
    bra     .L_0600E994
    mov.l r3, @(12, r14)
.L_pool_0600E91E:
    .2byte  0x0228

    .global DAT_0600e920
DAT_0600e920:
    .word 0x01F8

    .global DAT_0600e922
DAT_0600e922:
    mov.b r14, @(r0, r0)
.L_pool_0600E924:
    .word 0x00E0
    .word 0xFFFF
.L_pool_0600E928:
    .4byte  FUN_0600CEBA
.L_pool_0600E92C:
    .4byte  sym_0607EA9C
.L_pool_0600E930:
    .4byte  sym_0607EBC4
.L_pool_0600E934:
    .4byte  0x00200000
.L_pool_0600E938:
    .4byte  0x066505B3
.L_pool_0600E93C:
    .4byte  FUN_06027552
.L_pool_0600E942:
    .4byte  sym_0607E940
.L_pool_0600E946:
    .4byte  sym_0607EAD8
.L_0600E948:
    mov.l   .L_pool_0600E9F0, r3
    jsr @r3
    nop
    mov.l   .L_pool_0600E9F4, r3
    jsr @r3
    nop
    mov.l   .L_pool_0600E9F8, r5
    mov.l   .L_0600E9FC, r3
    jsr @r3
    mov.l @(12, r14), r4
    shlr16 r0
    exts.w r0, r0
    mov.l r0, @(8, r14)
    mov.l @(32, r14), r2
    mov.l   .L_pool_0600EA00, r3
    jsr @r3
    mov.l r2, @(48, r14)
    mov.w   .L_wpool_0600E9E2, r0
    mov.l   .L_pool_0600EA04, r3
    mov.l @(r0, r14), r2
    mov.l @r3, r3
    add #-0x3C, r0
    mul.l r3, r2
    mov.l @(r0, r14), r3
    sts macl, r2
    add #0x8, r0
    add r3, r2
    mov.l r2, @(r0, r14)
    add #-0x8, r0
    mov.l @(r0, r14), r0
    tst r0, r0
    bf      .L_0600E994
    mov #0x0, r3
    mov.w   DAT_0600e9e4, r0
    mov.l r3, @(r0, r14)
    mov.w   .L_pool_0600E9E6, r3
    add #-0x18, r0
    mov.l r3, @(r0, r14)
.L_0600E994:
    lds.l @r15+, macl
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14


    .global FUN_0600E99C
    .type FUN_0600E99C, @function
FUN_0600E99C:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov.l   .L_0600EA08, r14
    bsr     FUN_0600E906
    mov.l @r14, r14
    mov.l   .L_0600EA0C, r0
    mov.l @r0, r0
    tst r0, r0
    bf      .L_0600E9C6
    mov.l   .L_0600EA10, r5
    mov.l   .L_0600E9FC, r3
    jsr @r3
    mov.l @(12, r14), r4
    shlr16 r0
    exts.w r0, r0
    mov.w   DAT_0600e9e8, r1
    add r14, r1
    mov.l r0, @r1
    mov.w   DAT_0600e9ea, r1
    add r14, r1
    mov.l r0, @r1
.L_0600E9C6:
    mov.w   .L_wpool_0600E9EC, r0
    mov.l @(r0, r14), r0
    tst r0, r0
    bf      .L_0600E9DC
    mov #0x0, r4
    mov.l   .L_0600EA14, r3
    mov.l r4, @r3
    mov.w   .L_wpool_0600E9E2, r0
    mov.l r4, @(r0, r14)
    add #-0xC, r0
    mov.l r4, @(r0, r14)
.L_0600E9DC:
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_wpool_0600E9E2:
    .2byte  0x0228

    .global DAT_0600e9e4
DAT_0600e9e4:
    mov.b @(r0, r1), r2
.L_pool_0600E9E6:
    .word 0x0200

    .global DAT_0600e9e8
DAT_0600e9e8:
    .2byte  0x00E4

    .global DAT_0600e9ea
DAT_0600e9ea:
    .2byte  0x00E0
.L_wpool_0600E9EC:
    .2byte  0x01EC
    .2byte  0xFFFF
.L_pool_0600E9F0:
    .4byte  FUN_0600D26A
.L_pool_0600E9F4:
    .4byte  FUN_0600C74E
.L_pool_0600E9F8:
    .4byte  0x00480000
.L_0600E9FC:
    .4byte  FUN_06027552
.L_pool_0600EA00:
    .4byte  FUN_0600CEBA
.L_pool_0600EA04:
    .4byte  sym_0607EA9C
.L_0600EA08:
    .4byte  sym_0607E944
.L_0600EA0C:
    .4byte  sym_0607EAD8
.L_0600EA10:
    .4byte  0x066505B3
.L_0600EA14:
    .4byte  sym_0607EAD0
    .global FUN_0600EA18
FUN_0600EA18:
    .2byte 0x7FF4
    .2byte 0x952C
    .4byte  0x354C5351
    .4byte  0x2F325352
    .4byte  0x1F3266F2
    .4byte  0x5753263B
    .4byte  0x267B6352
    .4byte  0x1F31263B
    .4byte  0x273952F2
    .4byte  0x61F22729
    .4byte  0x27192F72
    .4byte  0xD50E2668
    .4byte  0x8D03E700
    .4byte  0x60F2C880
    .4byte  0x89022572
    .4byte  0xA0167F0C
    .4byte  0xE2332629
    .4byte  0x26688901
    .4byte  0xA0092572
    .4byte  0x62527201
    .4byte  0x25229307
    .4byte  0x32338B02
    .4byte  0x2572A007
    .4byte  0x7F0C000B
    .2byte  0x7F0C

    .global DAT_0600ea76
DAT_0600ea76:
    .2byte  0x0120
    .4byte  0x00A0FFFF
    .4byte  sym_0605A228
    .4byte  0x903BD31F
    .4byte  0x5244054E
    .4byte  0x63324508
    .4byte  0x45007503
    .4byte  0x45084508
    .4byte  0x353C6652
    .4byte  0x57515346
    .4byte  0x85553628
    .4byte  0x37386203
    .4byte  0x4621534C
    .4byte  0x42084621
    .4byte  0x32384621
    .4byte  0x652FD314
    .4byte  0xE2102322
    .4byte  0x4621D313
    .4byte  0x23624721
    .4byte  0xD3124521
    .4byte  0x47214521
    .4byte  0x47214521
    .4byte  0x47214521
    .4byte  0x2372655F
    .4byte  0xD30E2351
    .4byte  0xE5001453
    .4byte  0x1452900D
    .4byte  0x04567004
    .4byte  0x0456E501
    .4byte  0x703C0456
    .4byte  0x70040456
    .4byte  0x70040456
    .4byte  0x7004000B
    .2byte  0x0456

    .global DAT_0600eafa
DAT_0600eafa:
    .2byte  0x01EC
    .4byte  0x00E0FFFF
    .4byte  sym_0607EB88
    .4byte  sym_060786BC
    .4byte  sym_060786C0
    .4byte  sym_060786C4
    .4byte  sym_060786C8
