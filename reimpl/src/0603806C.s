
    .section .text.FUN_0603806C


    .global display_enable_ctrl
    .type display_enable_ctrl, @function
display_enable_ctrl:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    sts.l pr, @-r15
    mov #0x40, r12
    mov.w   .L_wpool_06038106, r13
    mov.l   .L_0603810C, r14
    mov #0x0, r5
    extu.b r5, r0
    mov.b r0, @(2, r4)
    extu.b r5, r0
    mov.b r0, @(1, r4)
    mov.b r5, @r4
    extu.b r5, r2
    mov r2, r0
    mov.b r0, @(3, r4)
    mov.l r5, @(8, r4)
    mov.l r5, @(12, r4)
    extu.b r5, r3
    mov r3, r0
    mov.b r0, @(4, r4)
    extu.w r5, r6
.L_06038098:
    extu.w r6, r3
    cmp/ge r12, r3
    bt      .L_060380AA
    extu.w r6, r3
    shll2 r3
    mov.w   DAT_06038108, r2
    add r4, r2
    add r2, r3
    mov.l r5, @r3
.L_060380AA:
    mov r6, r7
    mov r6, r3
    mov r4, r2
    mov r6, r0
    shll2 r7
    shll2 r3
    add #0x10, r2
    extu.w r0, r0
    shll r3
    add r3, r7
    exts.w r7, r7
    mov r4, r3
    add r7, r2
    add #0x10, r3
    mov.l r5, @r2
    add r7, r3
    add #-0x10, r15
    mov.l   .L_06038110, r2
    jsr @r2
    mov.l r15, @-r15
    mov #0x0, r1
    mov.l r1, @-r15
    mov.l   .L_06038114, r1
    mov.l r1, @-r15
    mov r15, r2
    mov.l   .L_06038118, r1
    add #0x10, r2
    jsr @r1
    mov.l r2, @-r15
    mov.l   .L_0603811C, r2
    jsr @r2
    nop
    add #0x1, r6
    mov.l r0, @(4, r3)
    extu.w r6, r2
    mov r4, r3
    add #0x10, r3
    add r3, r7
    cmp/ge r13, r2
    bf/s    .L_06038098
    mov.l r14, @(8, r7)
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_wpool_06038106:
    .2byte  0x0200

    .global DAT_06038108
DAT_06038108:
    .2byte  0x1810
    .2byte  0xFFFF
.L_0603810C:
    .4byte  0x00010000
.L_06038110:
    .4byte  sym_06035BC8
.L_06038114:
    .4byte  0x40F00000
.L_06038118:
    .4byte  sym_060359E4
.L_0603811C:
    .4byte  sym_060357B8
