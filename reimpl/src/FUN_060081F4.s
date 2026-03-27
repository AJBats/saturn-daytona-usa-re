
    .section .text.FUN_060081F4


    .global FUN_060081F4
    .type FUN_060081F4, @function
FUN_060081F4:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov.l   .L_pool_060082B4, r14
    mov.w   .L_wpool_060082AA, r0
    mov.l @r14, r3
    mov.l @(r0, r3), r0
    tst r0, r0
    bt      .L_06008264
    mov #0x46, r3
    mov.l   .L_pool_060082B8, r2
    mov.l r3, @r2
    mov.l @r14, r5
    mov.w   .L_wpool_060082AA, r0
    mov.l @r14, r3
    mov.l @(r0, r5), r5
    mov.l @(r0, r3), r2
    neg r5, r5
    add #-0x1, r2
    mov.l r2, @(r0, r3)
    mov.l @r14, r2
    mov r2, r0
    mov.b @r0, r0
    tst #0x40, r0
    bt/s    .L_0600822E
    add #0x30, r5
    mov r5, r4
    mov.l   .L_pool_060082BC, r3
    bra     .L_06008234
    shll r4
.L_0600822E:
    mov r5, r4
    shll r4
    mov.l   .L_pool_060082C0, r3
.L_06008234:
    add r3, r4
    mov.l @r14, r2
    mov.w   DAT_060082ac, r0
    mov r2, r1
    mov.l @(r0, r1), r3
    cmp/pz r3
    bt/s    .L_06008248
    mov.w @r4, r4
    bra     .L_0600824C
    exts.w r4, r3
.L_06008248:
    exts.w r4, r1
    neg r1, r3
.L_0600824C:
    mov.w   .L_wpool_060082AE, r0
    mov.l r3, @(r0, r2)
    mov.l @r14, r3
    mov.w   .L_wpool_060082B0, r2
    mov.l @(12, r3), r1
    sub r2, r1
    mov.l r1, @(12, r3)
    mov.l @r14, r0
    mov.w   .L_wpool_060082AA, r1
    mov.l @(r0, r1), r0
    bra     .L_060082FC
    cmp/eq #0x50, r0
.L_06008264:
    mov.l @r14, r2
    mov.l @(8, r2), r3
    mov #0x14, r2
    cmp/ge r2, r3
    bf      .L_060082FC
    mov.l @r14, r2
    mov.w   DAT_060082b2, r0
    mov.l @(r0, r2), r0
    tst r0, r0
    bf      .L_060082FC
    mov.l   .L_pool_060082C4, r6
    mov.l   .L_pool_060082C8, r5
    mov.l @r14, r2
    mov r2, r0
    mov.b @r0, r0
    tst #0x10, r0
    bt/s    .L_060082D4
    mov #0x30, r4
    mov.l @r14, r3
    mov #-0x1, r2
    mov.w   .L_wpool_060082AA, r0
    mov.l r4, @(r0, r3)
    mov.l @r14, r3
    mov.w   DAT_060082ac, r0
    mov.l r2, @(r0, r3)
    mov.l @r6, r3
    and r3, r5
    tst r5, r5
    bt      .L_060082FC
    mov.l   .L_pool_060082CC, r5
    mov.l   .L_pool_060082D0, r3
    jsr @r3
    mov #0x0, r4
    bra     .L_060082FC
    nop
.L_wpool_060082AA:
    .2byte  0x00B8

    .global DAT_060082ac
DAT_060082ac:
    .2byte  0x01DC
.L_wpool_060082AE:
    .2byte  0x01D8
.L_wpool_060082B0:
    .2byte  0x00E3

    .global DAT_060082b2
DAT_060082b2:
    .2byte  0x00BC
.L_pool_060082B4:
    .4byte  sym_0607E944
.L_pool_060082B8:
    .4byte  sym_0607EBD4
.L_pool_060082BC:
    .4byte  sym_0604540C
.L_pool_060082C0:
    .4byte  sym_0604546C
.L_pool_060082C4:
    .4byte  sym_0607EBC4
.L_pool_060082C8:
    .4byte  0x00020000
.L_pool_060082CC:
    .4byte  0xAE111BFF
.L_pool_060082D0:
    .4byte  FUN_0601D5F4
.L_060082D4:
    mov.l @r14, r2
    mov r2, r0
    mov.b @r0, r0
    tst #0x20, r0
    bt      .L_060082FC
    mov.l @r14, r3
    mov #0x1, r2
    .byte   0x90, 0x39    /* mov.w .L_wpool_06008358, r0 */
    mov.l r4, @(r0, r3)
    mov.l @r14, r3
    .byte   0x90, 0x37    /* mov.w .L_wpool_0600835A, r0 */
    mov.l r2, @(r0, r3)
    mov.l @r6, r3
    and r3, r5
    tst r5, r5
    bt      .L_060082FC
    .byte   0xD5, 0x1B    /* mov.l .L_pool_06008364, r5 */
    .byte   0xD3, 0x1C    /* mov.l .L_pool_06008368, r3 */
    jsr @r3
    mov #0x0, r4
.L_060082FC:
    mov #0x0, r4
    mov.l @r14, r2
    .byte   0x91, 0x2C    /* mov.w .L_wpool_0600835C, r1 */
    .byte   0xD3, 0x1A    /* mov.l .L_pool_0600836C, r3 */
    jsr @r3
    mov r4, r0
    mov.l @r14, r2
    .byte   0x91, 0x28    /* mov.w .L_wpool_0600835E, r1 */
    .byte   0xD3, 0x17    /* mov.l .L_pool_0600836C, r3 */
    jsr @r3
    mov r4, r0
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14


   .global FUN_06008318
   .type FUN_06008318, @function
FUN_06008318:
    sts.l pr, @-r15
    mov.l   .L_06008370, r4
    mov.w   .L_06008358, r0
    mov.l @r4, r3
    mov.l @(r0, r3), r0
    tst r0, r0
    bt      .L_06008378
    mov.l @r4, r3
    mov.w   .L_06008358, r0
    mov.l @(r0, r3), r2
    add #-0x1, r2
    mov.l r2, @(r0, r3)
    mov.l @r4, r5
    mov.l   .L_06008374, r3
    mov.l @r4, r2
    mov.l @(r0, r5), r5
    mov r2, r1
    shll r5
    mov.w   DAT_0600835a, r0
    add r3, r5
    mov.l @(r0, r1), r3
    cmp/pl r3
    bf/s    .L_0600834C
    mov.w @r5, r5
    bra     .L_06008350
    exts.w r5, r3
.L_0600834C:
    exts.w r5, r1
    neg r1, r3
.L_06008350:
    mov.w   .L_06008360, r0
    mov.l r3, @(r0, r2)
    bra     .L_060083DE
    nop
.L_06008358:
    .2byte  0x00B8

    .global DAT_0600835a
DAT_0600835a:
    .2byte  0x01DC
    .4byte  0x03010201
.L_06008360:
    .2byte  0x01D8
    .2byte  0xFFFF
    .4byte  0xAE111BFF
    .4byte  FUN_0601D5F4
    .4byte  sym_06034F78
.L_06008370:
    .4byte  sym_0607E940
.L_06008374:
    .4byte  sym_060453CC
.L_06008378:
    mov.l   .L_06008408, r2
    mov.w   .L_060083FA, r3
    mov.l @r2, r2
    cmp/gt r3, r2
    bf      .L_060083DE
    mov.l   .L_0600840C, r3
    mov.w   DAT_060083fc, r0
    mov.l @r3, r3
    mov.l @(r0, r3), r0
    tst r0, r0
    bf      .L_060083DE
    mov #0x28, r6
    mov.l @r4, r2
    mov.l   .L_06008410, r7
    mov r2, r0
    mov.b @r0, r0
    tst #0x10, r0
    bt/s    .L_060083BA
    mov #0x20, r5
    mov.l @r4, r3
    mov.w   .L_060083FE, r0
    mov.l r5, @(r0, r3)
    mov.l @r4, r3
    mov #-0x1, r2
    mov.w   DAT_06008400, r0
    mov.l r2, @(r0, r3)
    mov.l @r4, r3
    mov.l r3, @r7
    mov.l @r4, r2
    exts.w r6, r6
    mov.w   DAT_06008402, r0
    bra     .L_060083DE
    mov.w r6, @(r0, r2)
.L_060083BA:
    mov.l @r4, r2
    mov r2, r0
    mov.b @r0, r0
    tst #0x20, r0
    bt      .L_060083DE
    mov.l @r4, r3
    mov.w   .L_060083FE, r0
    mov.l r5, @(r0, r3)
    mov.l @r4, r3
    mov #0x1, r2
    mov.w   DAT_06008400, r0
    mov.l r2, @(r0, r3)
    mov.l @r4, r3
    mov.l r3, @r7
    mov.l @r4, r2
    exts.w r6, r6
    mov.w   DAT_06008402, r0
    mov.w r6, @(r0, r2)
.L_060083DE:
    mov #0x0, r5
    mov.l @r4, r2
    mov.w   .L_06008404, r1
    mov.l   .L_06008414, r3
    jsr @r3
    mov r5, r0
    mov.l @r4, r2
    mov.w   .L_06008406, r1
    mov.l   .L_06008414, r3
    jsr @r3
    mov r5, r0
    lds.l @r15+, pr
    rts
    nop
.L_060083FA:
    .2byte  0x0258

    .global DAT_060083fc
DAT_060083fc:
    .2byte  0x00BC
.L_060083FE:
    .2byte  0x00B8

    .global DAT_06008400
DAT_06008400:
    .2byte  0x01DC

    .global DAT_06008402
DAT_06008402:
    .2byte  0x00D4
.L_06008404:
    .2byte  0x0301
.L_06008406:
    .2byte  0x0201
.L_06008408:
    .4byte  sym_0607EBD0
.L_0600840C:
    .4byte  sym_0607E940
.L_06008410:
    .4byte  sym_0607EBE0
.L_06008414:
    .4byte  sym_06034F78
