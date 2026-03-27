
    .section .text.FUN_0601A0F0


    .global FUN_0601A0F0
    .type FUN_0601A0F0, @function
FUN_0601A0F0:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l   .L_pool_0601A198, r13
    mov.l   .L_pool_0601A19C, r14
    mov.w @r13, r0
    extu.w r0, r0
    tst #0x1, r0
    bt/s    .L_0601A108
    mov #0x0, r12
    bra     .L_0601A10A
    mov #0x6, r5
.L_0601A108:
    mov #0x19, r5
.L_0601A10A:
    mov.l   .L_0601A1A0, r7
    mov.l   .L_pool_0601A1A4, r4
    mov.w @(2, r13), r0
    mov r0, r2
    extu.w r2, r2
    and r7, r2
    tst r2, r2
    bt      .L_0601A126
    mov.l @r14, r3
    add #0x1, r3
    mov.l r3, @r14
    exts.b r12, r2
    bra     .L_0601A17A
    mov.b r2, @r4
.L_0601A126:
    mov.w   .L_0601A196, r6
    mov.w @(2, r13), r0
    mov r0, r2
    extu.w r2, r2
    and r6, r2
    tst r2, r2
    bt      .L_0601A140
    mov.l @r14, r3
    add #-0x1, r3
    mov.l r3, @r14
    exts.b r12, r2
    bra     .L_0601A17A
    mov.b r2, @r4
.L_0601A140:
    mov.w @r13, r2
    extu.w r2, r2
    and r7, r2
    tst r2, r2
    bt      .L_0601A15E
    mov.b @r4, r3
    extu.b r5, r5
    cmp/eq r5, r3
    bf      .L_0601A17A
    mov.l @r14, r3
    add #0x1, r3
    mov.l r3, @r14
    exts.b r12, r2
    bra     .L_0601A17A
    mov.b r2, @r4
.L_0601A15E:
    mov.w @r13, r2
    extu.w r2, r2
    and r6, r2
    tst r2, r2
    bt      .L_0601A17A
    extu.b r5, r5
    mov.b @r4, r3
    cmp/eq r5, r3
    bf      .L_0601A17A
    mov.l @r14, r3
    add #-0x1, r3
    mov.l r3, @r14
    exts.b r12, r2
    mov.b r2, @r4
.L_0601A17A:
    mov #0x5, r2
    mov.l @r14, r3
    cmp/ge r2, r3
    bf      .L_0601A186
    mov #0x4, r2
    mov.l r2, @r14
.L_0601A186:
    mov.l @r14, r3
    cmp/pz r3
    bt      .L_0601A18E
    mov.l r12, @r14
.L_0601A18E:
    mov.l @r15+, r12
    mov.l @r15+, r13
    .reloc ., R_SH_IND12W, FUN_06019FB2 - 4
    .2byte 0xA000    /* bra FUN_06019FB2 (linker-resolved) */
    mov.l @r15+, r14
.L_0601A196:
    .2byte  0x4000
.L_pool_0601A198:
    .4byte  g_pad_state
.L_pool_0601A19C:
    .4byte  sym_0605AD04
.L_0601A1A0:
    .4byte  0x00008000
.L_pool_0601A1A4:
    .4byte  sym_0605D243

    .global FUN_0601A1A8
FUN_0601A1A8:
    mov.l   .L_pool_0601A24D, r3
    mov.b @r3, r3
    extu.b r3, r3
    shll2 r3
    mov.l   .L_pool_0601A244, r2
    add r2, r3
    mov.l @r3, r3
    jmp @r3
    nop


    .global FUN_0601A1BA
    .type FUN_0601A1BA, @function
FUN_0601A1BA:
    mov.l r14, @-r15
    mov.l r13, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_0601A248, r3
    mov.w @r3, r2
    extu.w r2, r2
    mov.w   .L_0601A23A, r3
    and r3, r2
    tst r2, r2
    bt/s    .L_0601A1FE
    mov #0x0, r14
    mov.l   .L_pool_0601A24D, r4
    mov.b @r4, r3
    add #0x1, r3
    mov.b r3, @r4
    mov.l   .L_0601A24C, r4
    mov.b @r4, r2
    add #0x1, r2
    mov.b r2, @r4
    mov.l   .L_0601A250, r2
    mov.b r14, @r2
    mov.l   .L_0601A254, r2
    mov.l r14, @r2
    mov.l   .L_0601A258, r4
    mov.l   .L_0601A25C, r1
    mov.l   .L_0601A260, r3
    mov.l @r4, r2
    or r1, r2
    jsr @r3
    mov.l r2, @r4
    mov #0x1, r2
    mov.l   .L_0601A264, r3
    mov.b r2, @r3
.L_0601A1FE:
    mov #0x8, r3
    mov.l   .L_0601A268, r13
    mov.b @r13, r2
    extu.b r2, r2
    cmp/ge r3, r2
    bt      .L_0601A278
    mov.l   .L_0601A26C, r7
    mov.w   .L_0601A23C, r6
    mov.l   .L_0601A270, r3
    mov.l r3, @r15
    mov r3, r5
    add #0xD, r5
    add #0xC, r3
    mov.b @r5, r5
    mov.b @r3, r3
    extu.b r5, r5
    extu.b r3, r3
    shll2 r5
    shll2 r5
    shll2 r5
    add r3, r5
    add #0xD, r5
    shll r5
    mov #0xC, r4
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    mov.l   .L_0601A274, r3
    jmp @r3
    mov.l @r15+, r14
.L_0601A23A:
    .2byte  0x0600
.L_0601A23C:
    .2byte  0x0090                        /* VDP1 command table offset */
    .2byte  0xFFFF
.L_pool_0601A24D:
    .4byte  sym_06085FF2
.L_pool_0601A244:
    .4byte  sym_0605D280
.L_0601A248:
    .4byte  sym_06063D9A
.L_0601A24C:
    .4byte  sym_06085FF3
.L_0601A250:
    .4byte  sym_0605D245
.L_0601A254:
    .4byte  sym_06059F44
.L_0601A258:
    .4byte  sym_0605B6D8
.L_0601A25C:
    .4byte  0x80000000
.L_0601A260:
    .4byte  sym_06026CE0
.L_0601A264:
    .4byte  sym_06085FF1
.L_0601A268:
    .4byte  sym_0605D242
.L_0601A26C:
    .4byte  sym_06049E48
.L_0601A270:
    .4byte  sym_06049AFC
.L_0601A274:
    .4byte  sym_060284AE
.L_0601A278:
    mov.l   .L_pool_0601A310, r7
    mov.w   .L_pool_0601A30E, r6
    mov.l   .L_pool_0601A314, r2
    mov.l @r7, r7
    mov r2, r5
    mov r2, r3
    mov.l r2, @r15
    add #0xD, r5
    add #0xC, r3
    mov.b @r5, r5
    mov.b @r3, r3
    extu.b r5, r5
    extu.b r3, r3
    shll2 r5
    shll2 r5
    shll2 r5
    add r3, r5
    add #0xD, r5
    mov.l   .L_pool_0601A318, r3
    shll r5
    jsr @r3
    mov #0xC, r4
    mov.b @r13, r2
    mov #0x10, r3
    extu.b r2, r2
    cmp/gt r3, r2
    bf      .L_0601A2B2
    extu.b r14, r3
    mov.b r3, @r13
.L_0601A2B2:
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14


    .global FUN_0601A2BC
    .type FUN_0601A2BC, @function
FUN_0601A2BC:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov.l   .L_0601A31C, r4
    mov.l   .L_0601A320, r3
    mov.l @r4, r2
    or r3, r2
    mov.l   .L_0601A324, r3
    jsr @r3
    mov.l r2, @r4
    mov.l   .L_0601A324, r3
    jsr @r3
    nop
    mov.l   .L_0601A328, r14
    jsr @r14
    mov #0x4, r4
    jsr @r14
    mov #0x8, r4
    jsr @r14
    mov #0xC, r4
    mov.l   .L_0601A32C, r3
    jsr @r3
    nop
    mov #0x8, r7
    mov.l   .L_0601A330, r5
    mov.l   .L_0601A334, r4
    mov.l   .L_0601A338, r3
    jsr @r3
    mov #0x0, r6
    mov #0x9, r7
    mov.l   .L_0601A330, r5
    mov.l   .L_0601A33C, r4
    mov.l   .L_0601A338, r3
    jsr @r3
    mov #0x0, r6
    mov.l   .L_0601A340, r4
    mov.b @r4, r2
    add #0x1, r2
    mov.b r2, @r4
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_pool_0601A30E:
    .2byte  0x0090
.L_pool_0601A310:
    .4byte  sym_0605D4F0
.L_pool_0601A314:
    .4byte  sym_06049AFC
.L_pool_0601A318:
    .4byte  sym_060284AE
.L_0601A31C:
    .4byte  sym_0605B6D8
.L_0601A320:
    .4byte  0x80000000
.L_0601A324:
    .4byte  sym_06026CE0
.L_0601A328:
    .4byte  sym_0602853E
.L_0601A32C:
    .4byte  sym_06028560
.L_0601A330:
    .4byte  0x00017700
.L_0601A334:
    .4byte  0x25E76EFC
.L_0601A338:
    .4byte  sym_0600511E
.L_0601A33C:
    .4byte  0x25E77B18
.L_0601A340:
    .4byte  sym_06085FF2
