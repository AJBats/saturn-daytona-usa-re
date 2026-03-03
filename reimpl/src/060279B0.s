
    .section .text.FUN_060279B0


    .global transform_pipeline
    .type transform_pipeline, @function
transform_pipeline:


    mov.l r14, @-r15
    mov.l r12, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0x8, r15


    mov.l   .L_pool_06027A2C, r1
    mov.l   .L_pool_06027A30, r2
    mov.l   .L_pool_06027A34, r14
    mov.l @r14, r14


    mov r5, r12
    mov.w @r12, r0
    mov.w r0, @r15
    mov.w @(2, r12), r0
    mov.w r0, @(2, r15)
    mov.w @(4, r12), r0
    mov.w r0, @(4, r15)
    mov.w @(6, r12), r0
    mov.w r0, @(6, r15)


.L_060279D8:
    mov.w @r15, r0
    cmp/eq #0x1, r0
    bf      .L_06027A8A


    mov.w @(2, r12), r0
    cmp/eq #0x0, r0
    bf      .L_06027A38

    mov.l @r4, r7
    dmuls.l r7, r1
    mov.l @(12, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r2
    xtrct r7, r8
    mov.l @(4, r4), r7
    sts mach, r6
    sts macl, r9
    xtrct r6, r9
    dmuls.l r7, r1
    add r8, r9
    mov.l r9, @r4
    mov.l @(16, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r2
    xtrct r7, r8
    mov.l @(8, r4), r7
    sts mach, r6
    sts macl, r9
    xtrct r6, r9
    dmuls.l r7, r1
    add r8, r9
    mov.l r9, @(4, r4)
    mov.l @(20, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r2
    xtrct r7, r8
    sts mach, r6
    sts macl, r9
    xtrct r6, r9
    bra     .L_06027A7E
    add r8, r9

.L_pool_06027A2C:
    .4byte  0x0000E666
.L_pool_06027A30:
    .4byte  0x00001999
.L_pool_06027A34:
    .4byte  sym_06063F08

.L_06027A38:
    mov.l @r4, r7
    dmuls.l r7, r1
    mov.l @(36, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r2
    xtrct r7, r8
    mov.l @(4, r4), r7
    sts mach, r6
    sts macl, r9
    xtrct r6, r9
    dmuls.l r7, r1
    add r8, r9
    mov.l r9, @r4
    mov.l @(40, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r2
    xtrct r7, r8
    mov.l @(8, r4), r7
    sts mach, r6
    sts macl, r9
    xtrct r6, r9
    dmuls.l r7, r1
    add r8, r9
    mov.l r9, @(4, r4)
    mov.l @(44, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r2
    xtrct r7, r8
    sts mach, r6
    sts macl, r9
    xtrct r6, r9
    add r8, r9

.L_06027A7E:
    add #0x4, r9
    mov.l r9, @(8, r4)
    cmp/gt r14, r9
    bf      .L_06027A8A
    mov #0x0, r0
    mov.w r0, @r15


.L_06027A8A:
    mov.w @(2, r15), r0
    cmp/eq #0x1, r0
    bf      .L_06027B30

    mov.w @(4, r12), r0
    cmp/eq #0x0, r0
    bf      .L_06027ADE

    mov.l @(12, r4), r7
    dmuls.l r7, r1
    mov.l @(24, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r2
    xtrct r7, r8
    mov.l @(16, r4), r7
    sts mach, r6
    sts macl, r9
    xtrct r6, r9
    dmuls.l r7, r1
    add r8, r9
    mov.l r9, @(12, r4)
    mov.l @(28, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r2
    xtrct r7, r8
    mov.l @(20, r4), r7
    sts mach, r6
    sts macl, r9
    xtrct r6, r9
    dmuls.l r7, r1
    add r8, r9
    mov.l r9, @(16, r4)
    mov.l @(32, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r2
    xtrct r7, r8
    sts mach, r6
    sts macl, r9
    xtrct r6, r9
    bra     .L_06027B24
    add r8, r9

.L_06027ADE:
    mov.l @(12, r4), r7
    dmuls.l r7, r1
    mov.l @r4, r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r2
    xtrct r7, r8
    mov.l @(16, r4), r7
    sts mach, r6
    sts macl, r9
    xtrct r6, r9
    dmuls.l r7, r1
    add r8, r9
    mov.l r9, @(12, r4)
    mov.l @(4, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r2
    xtrct r7, r8
    mov.l @(20, r4), r7
    sts mach, r6
    sts macl, r9
    xtrct r6, r9
    dmuls.l r7, r1
    add r8, r9
    mov.l r9, @(16, r4)
    mov.l @(8, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r2
    xtrct r7, r8
    sts mach, r6
    sts macl, r9
    xtrct r6, r9
    add r8, r9

.L_06027B24:
    add #0x4, r9
    mov.l r9, @(20, r4)
    cmp/gt r14, r9
    bf      .L_06027B30
    mov #0x0, r0
    mov.w r0, @(2, r15)


.L_06027B30:
    mov.w @(4, r15), r0
    cmp/eq #0x1, r0
    bf      .L_06027BD6

    mov.w @(6, r12), r0
    cmp/eq #0x0, r0
    bf      .L_06027B84

    mov.l @(24, r4), r7
    dmuls.l r7, r1
    mov.l @(36, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r2
    xtrct r7, r8
    mov.l @(28, r4), r7
    sts mach, r6
    sts macl, r9
    xtrct r6, r9
    dmuls.l r7, r1
    add r8, r9
    mov.l r9, @(24, r4)
    mov.l @(40, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r2
    xtrct r7, r8
    mov.l @(32, r4), r7
    sts mach, r6
    sts macl, r9
    xtrct r6, r9
    dmuls.l r7, r1
    add r8, r9
    mov.l r9, @(28, r4)
    mov.l @(44, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r2
    xtrct r7, r8
    sts mach, r6
    sts macl, r9
    xtrct r6, r9
    bra     .L_06027BCA
    add r8, r9

.L_06027B84:
    mov.l @(24, r4), r7
    dmuls.l r7, r1
    mov.l @(12, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r2
    xtrct r7, r8
    mov.l @(28, r4), r7
    sts mach, r6
    sts macl, r9
    xtrct r6, r9
    dmuls.l r7, r1
    add r8, r9
    mov.l r9, @(24, r4)
    mov.l @(16, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r2
    xtrct r7, r8
    mov.l @(32, r4), r7
    sts mach, r6
    sts macl, r9
    xtrct r6, r9
    dmuls.l r7, r1
    add r8, r9
    mov.l r9, @(28, r4)
    mov.l @(20, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r2
    xtrct r7, r8
    sts mach, r6
    sts macl, r9
    xtrct r6, r9
    add r8, r9

.L_06027BCA:
    add #0x4, r9
    mov.l r9, @(32, r4)
    cmp/gt r14, r9
    bf      .L_06027BD6
    mov #0x0, r0
    mov.w r0, @(4, r15)


.L_06027BD6:
    mov.w @(6, r15), r0
    cmp/eq #0x1, r0
    bf      .L_06027C7C

    mov.w @r12, r0
    cmp/eq #0x0, r0
    bf      .L_06027C2A

    mov.l @(36, r4), r7
    dmuls.l r7, r1
    mov.l @r4, r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r2
    xtrct r7, r8
    mov.l @(40, r4), r7
    sts mach, r6
    sts macl, r9
    xtrct r6, r9
    dmuls.l r7, r1
    add r8, r9
    mov.l r9, @(36, r4)
    mov.l @(4, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r2
    xtrct r7, r8
    mov.l @(44, r4), r7
    sts mach, r6
    sts macl, r9
    xtrct r6, r9
    dmuls.l r7, r1
    add r8, r9
    mov.l r9, @(40, r4)
    mov.l @(8, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r2
    xtrct r7, r8
    sts mach, r6
    sts macl, r9
    xtrct r6, r9
    bra     .L_06027C70
    add r8, r9

.L_06027C2A:
    mov.l @(36, r4), r7
    dmuls.l r7, r1
    mov.l @(24, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r2
    xtrct r7, r8
    mov.l @(40, r4), r7
    sts mach, r6
    sts macl, r9
    xtrct r6, r9
    dmuls.l r7, r1
    add r8, r9
    mov.l r9, @(36, r4)
    mov.l @(28, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r2
    xtrct r7, r8
    mov.l @(44, r4), r7
    sts mach, r6
    sts macl, r9
    xtrct r6, r9
    dmuls.l r7, r1
    add r8, r9
    mov.l r9, @(40, r4)
    mov.l @(32, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r2
    xtrct r7, r8
    sts mach, r6
    sts macl, r9
    xtrct r6, r9
    add r8, r9

.L_06027C70:
    add #0x4, r9
    mov.l r9, @(44, r4)
    cmp/gt r14, r9
    bf      .L_06027C7C
    mov #0x0, r0
    mov.w r0, @(6, r15)


.L_06027C7C:
    mov.w @r15, r7
    mov.w @(2, r15), r0
    add r0, r7
    mov.w @(4, r15), r0
    add r0, r7
    mov.w @(6, r15), r0
    add r7, r0
    cmp/eq #0x0, r0
    bt      .L_06027C92
    bra     .L_060279D8
    nop


.L_06027C92:
    add #0x8, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r12
    rts
    mov.l @r15+, r14
    .2byte  0x0000
