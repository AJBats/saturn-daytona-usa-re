
    .section .text.FUN_060429EC


    .global FUN_060429A0
    .type FUN_060429A0, @function
FUN_060429A0:
    mov.l r14, @-r15
    mov r6, r14
    mov.l r13, @-r15
    sts.l pr, @-r15
    add #-0xC, r15
    mov.l r4, @r15
    mov.l r5, @(4, r15)
    mov.l   .L_pool_06042A7C, r3
    jsr @r3
    mov.l r7, @(8, r15)
    cmp/eq #0x2, r0
    bf      .L_06042A3A
    mov.l @(8, r15), r13
    mov.l   .L_pool_06042A80, r3
    jsr @r3
    mov.l @r15, r4
    shll8 r0
    mov.l   .L_06042A84, r2
    mov.l @(4, r15), r3
    shll2 r0
    shll2 r3
    add r2, r0
    mov r0, r4
    add r3, r4
    mov r14, r0
    cmp/eq #0x1, r0
    bf      .L_06042A28
    mov.l @r13, r2
    bra     .L_06042A70
    mov.l r2, @r4
.L_06042A28:
    mov r14, r6
    shll2 r6
    mov r13, r5
    add #0xC, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    mov.l   .L_pool_06042A88, r3
    jmp @r3
    mov.l @r15+, r14
.L_06042A3A:
    mov.l @(8, r15), r13
    mov.l   .L_pool_06042A80, r3
    jsr @r3
    mov.l @r15, r4
    shll8 r0
    mov.l   .L_06042A84, r2
    mov.l @(4, r15), r3
    shll r0
    shll r3
    add r2, r0
    mov r0, r4
    add r3, r4
    mov r14, r0
    cmp/eq #0x1, r0
    bf      .L_06042A5E
    mov.w @r13, r2
    bra     .L_06042A70
    mov.w r2, @r4
.L_06042A5E:
    mov r14, r6
    shll r6
    mov r13, r5
    add #0xC, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    mov.l   .L_pool_06042A88, r3
    jmp @r3
    mov.l @r15+, r14
.L_06042A70:
    add #0xC, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .2byte  0xFFFF
.L_pool_06042A7C:
    .4byte  sym_0603C156
.L_pool_06042A80:
    .4byte  sym_06042BFC
.L_06042A84:
    .4byte  0x25F00000
.L_pool_06042A88:
    .4byte  sym_06038A48

    .global sym_06042A8C
sym_06042A8C:
    mov #-0x50, r6
    mov #-0x9, r3
    mov.l @r4, r2
    mov #0x4, r7
    mov.l @r6, r5
    and r3, r5
    or r2, r5
    mov.l @(8, r4), r3
    and r7, r3
    cmp/eq r7, r3
    bf      .L_06042AAA
    mov #-0x2, r3
    and r3, r5
    mov.l @(4, r4), r2
    or r2, r5
.L_06042AAA:
    mov #0x1, r7
    mov.l @(8, r4), r3
    and r7, r3
    cmp/eq r7, r3
    bf      .L_06042AB8
    mov #-0x5, r3
    and r3, r5
.L_06042AB8:
    mov #0x2, r7
    mov.l @(8, r4), r2
    and r7, r2
    cmp/eq r7, r2
    bf      .L_06042AC6
    mov #-0x3, r2
    and r2, r5
.L_06042AC6:
    rts
    mov.l r5, @r6


    .global FUN_06042A7E
    .type FUN_06042A7E, @function
FUN_06042A7E:
    mov r5, r3
    mov.l @r4, r2
    mov #0x1, r6
    shll2 r3
    shll2 r3
    add #-0x80, r3
    mov.l r2, @r3
    mov.l @(36, r4), r3
    and r6, r3
    cmp/eq r6, r3
    bf      .L_06042AEC
    mov r5, r3
    shll2 r3
    shll2 r3
    add #-0x7C, r3
    mov.l @(4, r4), r2
    mov.l r2, @r3
.L_06042AEC:
    mov #0x2, r6
    mov.l @(36, r4), r3
    and r6, r3
    cmp/eq r6, r3
    bf      .L_06042B02
    mov r5, r3
    shll2 r3
    shll2 r3
    add #-0x78, r3
    mov.l @(8, r4), r2
    mov.l r2, @r3
.L_06042B02:
    mov r5, r7
    mov.l @(36, r4), r0
    shll2 r7
    and #0x4, r0
    shll2 r7
    add #-0x74, r7
    cmp/eq #0x4, r0
    bf/s    .L_06042B24
    mov.l @r7, r6
    .byte   0xD2, 0x24    /* mov.l .L_pool_06042BA9, r2 */
    and r2, r6
    mov.l @(12, r4), r3
    shll8 r3
    shll2 r3
    shll2 r3
    shll2 r3
    or r3, r6
.L_06042B24:
    mov.l @(36, r4), r0
    and #0x8, r0
    cmp/eq #0x8, r0
    bf      .L_06042B3A
    mov.w   .L_wpool_06042B9D, r3
    and r3, r6
    mov.l @(16, r4), r2
    shll8 r2
    shll2 r2
    shll2 r2
    or r2, r6
.L_06042B3A:
    mov.l @(36, r4), r0
    and #0x10, r0
    cmp/eq #0x10, r0
    bf      .L_06042B4A
    mov.w   .L_wpool_06042B9F, r2
    and r2, r6
    mov.l @(20, r4), r3
    or r3, r6
.L_06042B4A:
    mov.l @(36, r4), r0
    and #0x20, r0
    cmp/eq #0x20, r0
    bf      .L_06042B5A
    mov.w   .L_wpool_06042BA1, r3
    and r3, r6
    mov.l @(24, r4), r2
    or r2, r6
.L_06042B5A:
    mov #-0x11, r3
    mov #-0x9, r2
    mov.l @(36, r4), r0
    and r3, r6
    and #0x40, r0
    cmp/eq #0x40, r0
    bf/s    .L_06042B72
    and r2, r6
    mov #-0x5, r2
    and r2, r6
    mov.l @(28, r4), r3
    or r3, r6
.L_06042B72:
    mov.l @(36, r4), r2
    mov.w   .L_wpool_06042BA3, r3
    and r3, r2
    mov r3, r1
    cmp/eq r1, r2
    bf      .L_06042B82
    mov #-0x3, r2
    and r2, r6
.L_06042B82:
    mov.l r6, @r7
    mov.w   .L_wpool_06042BA5, r6
    mov.l @(36, r4), r3
    and r6, r3
    cmp/eq r6, r3
    bf      .L_06042B98
    mov.w   DAT_06042ba6, r3
    add r3, r5
    mov.l @(32, r4), r2
    extu.b r2, r2
    mov.b r2, @r5
.L_06042B98:
    rts
    nop
.L_wpool_06042B9D:
    .2byte  0xCFFF
.L_wpool_06042B9F:
    .2byte  0xF3FF
.L_wpool_06042BA1:
    .2byte  0xFDFF
.L_wpool_06042BA3:
    .2byte  0x0100
.L_wpool_06042BA5:
    .2byte  0x0080

    .global DAT_06042ba6
DAT_06042ba6:
    .2byte  0xFE71
.L_pool_06042BA9:
    .4byte  0xFFFF3FFF

    .global sym_06042BAC
sym_06042BAC:
    mov r4, r5
    mov #0x1, r3
    shll2 r5
    shll2 r5
    add #-0x74, r5
    mov.l @r5, r4
    or r3, r4
    rts
    mov.l r4, @r5

    .global sym_06042BBE
sym_06042BBE:
    mov r4, r5
    mov #-0x2, r3
    shll2 r5
    shll2 r5
    add #-0x74, r5
    mov.l @r5, r4
    and r3, r4
    rts
    mov.l r4, @r5
    .4byte  0xE5B0E3FE
    .4byte  0x64522439
    .4byte  0x000B2542
    .4byte  0xE5B0E304
    .4byte  0xE2026552
    .4byte  0x23592529
    .4byte  0x2432000B
    .2byte  0x1451
