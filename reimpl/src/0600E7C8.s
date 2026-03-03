
    .section .text.FUN_0600E7C8


    .global per_frame_race_update
    .type per_frame_race_update, @function
per_frame_race_update:
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
    .byte   0xD3, 0x21    /* mov.l .L_pool_0600E928, r3 */
    jsr @r3
    nop

    .byte   0x90, 0x3A    /* mov.w .L_wpool_0600E91E, r0 */
    .byte   0xD3, 0x20    /* mov.l .L_pool_0600E92C, r3 */
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
    .byte   0x90, 0x23    /* mov.w .L_wpool_0600E920, r0 */
    mov.l r3, @(r0, r14)

    .byte   0xD3, 0x15    /* mov.l .L_pool_0600E930, r3 */
    .byte   0xD2, 0x15    /* mov.l .L_pool_0600E934, r2 */
    mov.l @r3, r3
    and r2, r3
    tst r3, r3
    bt      .L_0600E8FE

    .byte   0xD5, 0x14    /* mov.l .L_pool_0600E938, r5 */
    .byte   0xD3, 0x14    /* mov.l .L_pool_0600E93C, r3 */
    jsr @r3
    mov.l @(12, r14), r4
    shlr16 r0
    exts.w r0, r0
    .byte   0x91, 0x16    /* mov.w .L_wpool_0600E922, r1 */
    add r14, r1
    mov.l r0, @r1
    .byte   0x91, 0x14    /* mov.w .L_wpool_0600E924, r1 */
    add r14, r1
    mov.l r0, @r1

.L_0600E8FE:
    lds.l @r15+, macl
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
