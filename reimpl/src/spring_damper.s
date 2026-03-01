
    .section .text.FUN_060276CC


    .global spring_damper
    .type spring_damper, @function
spring_damper:
    mov.l r14, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    mov.l   .L_pool_retention, r1
    mov.l   .L_pool_approach, r2
    mov.w @r5+, r0
    mov.l   .L_pool_limit_ptr, r14
    mov.l @r14, r14
    cmp/eq #0x1, r0
    bf      .L_axis1_dispatch
    mov.l @(20, r4), r6
    mov.l @(44, r4), r7
    cmp/ge r7, r6
    bf      .L_axis0_reverse
.L_axis0_forward:
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
    add r8, r9
    add #0x4, r9
    mov.l r9, @(8, r4)
    cmp/ge r14, r9
    bf      .L_axis0_forward
    bra     .L_epilogue
    nop
.L_pool_retention:
    .4byte  0x0000E666
.L_pool_approach:
    .4byte  0x00001999
.L_pool_limit_ptr:
    .4byte  sym_06063F04
.L_axis0_reverse:
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
    add #0x4, r9
    mov.l r9, @(8, r4)
    cmp/ge r14, r9
    bf      .L_axis0_reverse
    bra     .L_epilogue
    nop
.L_axis1_dispatch:
    mov.w @r5+, r0
    cmp/eq #0x1, r0
    bf      .L_axis2_dispatch
    mov.l @(32, r4), r6
    mov.l @(8, r4), r7
    cmp/ge r7, r6
    bf      .L_axis1_reverse
.L_axis1_forward:
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
    add r8, r9
    add #0x4, r9
    mov.l r9, @(20, r4)
    cmp/ge r14, r9
    bf      .L_axis1_forward
    bra     .L_epilogue
    nop
.L_axis1_reverse:
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
    add #0x4, r9
    mov.l r9, @(20, r4)
    cmp/ge r14, r9
    bf      .L_axis1_reverse
    bra     .L_epilogue
    nop
.L_axis2_dispatch:
    mov.w @r5+, r0
    cmp/eq #0x1, r0
    bf      .L_axis3_entry
    mov.l @(44, r4), r6
    mov.l @(20, r4), r7
    cmp/ge r7, r6
    bf      .L_axis2_reverse
.L_axis2_forward:
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
    add r8, r9
    add #0x4, r9
    mov.l r9, @(32, r4)
    cmp/ge r14, r9
    bf      .L_axis2_forward
    bra     .L_epilogue
    nop
.L_axis2_reverse:
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
    add #0x4, r9
    mov.l r9, @(32, r4)
    cmp/ge r14, r9
    bf      .L_axis2_reverse
    bra     .L_epilogue
    nop
.L_axis3_entry:
    mov.l @(8, r4), r6
    mov.l @(32, r4), r7
    cmp/ge r7, r6
    bf      .L_axis3_reverse
.L_axis3_forward:
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
    add r8, r9
    add #0x4, r9
    mov.l r9, @(44, r4)
    cmp/ge r14, r9
    bf      .L_axis3_forward
    bra     .L_epilogue
    nop
.L_axis3_reverse:
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
    add #0x4, r9
    mov.l r9, @(44, r4)
    cmp/ge r14, r9
    bf      .L_axis3_reverse
.L_epilogue:
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    rts
    mov.l @r15+, r14
