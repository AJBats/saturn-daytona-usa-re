
    .section .text.FUN_060201B8


    .global obj_pool_alloc
    .type obj_pool_alloc, @function
obj_pool_alloc:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    sts.l pr, @-r15
    mov.l   .L_pool_0602026C, r13
    mov.l   .L_pool_06020270, r14
    mov.l   .L_pool_06020274, r3
    mov.w @r3, r2
    mov.w   .L_0602026A, r3
    extu.w r2, r2
    and r3, r2
    tst r2, r2
    bt      .L_060201D8
    mov #0x1, r3
    mov.l   .L_pool_06020278, r2
    mov.w r3, @r2
.L_060201D8:
    mov.l   .L_pool_0602027C, r12
    mov #0x14, r2
    mov.w @r14, r3
    extu.w r3, r3
    cmp/gt r2, r3
    bt      .L_06020258
    mov.w @r13, r2
    extu.w r2, r2
    tst r2, r2
    bf      .L_06020258
.L_060201EC:
    .byte   0xB6, 0x26    /* bsr 0x06020E3C (external) */
    mov #0x0, r4
    extu.w r0, r4
    extu.w r4, r0
    cmp/eq #0xF, r0
    bt      .L_06020258
    mov r4, r5
    mov r4, r3
    mov.l   .L_pool_06020280, r2
    mov.w @r14, r0
    shll2 r5
    shll2 r3
    extu.w r0, r0
    shll2 r3
    shll2 r3
    add r3, r5
    exts.w r5, r5
    mov r0, r3
    add r2, r5
    shll r0
    add r3, r0
    shll r0
    mov.w @(r0, r12), r2
    mov.b r2, @r5
    mov.w @r14, r3
    extu.w r3, r3
    mov r3, r2
    shll r3
    add r2, r3
    shll r3
    add r12, r3
    mov.w @(4, r3), r0
    mov r0, r3
    mov #0x40, r0
    mov.b r3, @(r0, r5)
    mov.w @r14, r3
    extu.w r3, r3
    mov r3, r2
    shll r3
    add r2, r3
    shll r3
    add r12, r3
    mov.w @(2, r3), r0
    mov r0, r1
    mov.w r1, @r13
    mov.w @r14, r3
    add #0x1, r3
    mov.w r3, @r14
    mov.w @r13, r2
    extu.w r2, r2
    tst r2, r2
    bf      .L_06020258
    bra     .L_060201EC
    nop
.L_06020258:
    mov.w @r13, r2
    add #-0x1, r2
    .byte   0xB5, 0x73    /* bsr 0x06020D46 (external) */
    mov.w r2, @r13
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    .byte   0xA0, 0x0D    /* bra 0x06020284 (external) */
    mov.l @r15+, r14
.L_0602026A:
    .2byte  0x0800                         /* [HIGH] start-button bitmask (bit 11) */
.L_pool_0602026C:
    .4byte  sym_06087808               /* [MEDIUM] position counter (word) */
.L_pool_06020270:
    .4byte  sym_06087806               /* [MEDIUM] active object count (word) */
.L_pool_06020274:
    .4byte  sym_06063D9A               /* [HIGH] new button presses (edge-triggered) */
.L_pool_06020278:
    .4byte  sym_0608780A               /* [MEDIUM] lap counter (word) */
.L_pool_0602027C:
    .4byte  sym_0605F4A8               /* [MEDIUM] object type/param table (6 bytes/row) */
.L_pool_06020280:
    .4byte  sym_0608782C               /* [MEDIUM] object slot array base */
