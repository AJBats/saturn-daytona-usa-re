
   .section .text.FUN_06041EE8


   .global track_edge_validate
   .type track_edge_validate, @function
track_edge_validate:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    sts.l pr, @-r15
    add #-0x10, r15
    mov.l   .L_06041FA0, r12
    mov.l   .L_06041FA4, r14
    mov.w   .L_06041F92, r1
    mov.l @r14, r0
    mov.l @(r0, r1), r0
    cmp/eq #0x1, r0
    bf/s    .L_06041F60
    mov r4, r13
    mov.l @r14, r5
    mov.w   DAT_06041f94, r3
    mov.l @r14, r4
    mov.w   DAT_06041f96, r0
    add r3, r5
    mov.l   .L_06041FA8, r3
    jsr @r3
    mov.l @(r0, r4), r4
    mov r15, r4
    mov.l @r13, r2
    add #0x1, r2
    mov.l r2, @r13
    jsr @r12
    add #0x4, r4
    mov r15, r2
    mov #0x40, r0
    mov #0x0, r5
    mov.l @r14, r3
    add #0x4, r2
    mov.b @r2, r1
    mov.b r1, @(r0, r3)
    mov.l @r14, r4
    mov.w   DAT_06041f96, r0
    mov.l   .L_06041FAC, r3
    jsr @r3
    mov.l @(r0, r4), r4
    mov r0, r4
    tst r4, r4
    bt      .L_06041F40
    bra     .L_0604206E
    mov #0x1, r0
.L_06041F40:
    mov r15, r4
    jsr @r12
    add #0x4, r4
    mov.l @r14, r3
    mov r15, r2
    add #0x4, r2
    mov.b @r2, r1
    mov #0x40, r0
    mov.b r1, @(r0, r3)
    mov.l @r13, r3
    add #0x1, r3
    mov.l r3, @r13
    mov.l @r14, r2
    mov #0x2, r3
    mov.w   .L_06041F92, r0
    mov.l r3, @(r0, r2)
.L_06041F60:
    mov.l @r14, r0
    mov.w   .L_06041F92, r1
    mov.l @(r0, r1), r0
    cmp/eq #0x2, r0
    bf      .L_06041FD4
    mov.l @r14, r7
    mov.w   DAT_06041f96, r0
    mov.l @r14, r6
    mov.l @r14, r5
    mov.l @r14, r4
    mov.l   .L_06041FB0, r3
    mov.l @(r0, r7), r7
    add #0xC, r0
    mov.l @(r0, r6), r6
    add #-0x4, r0
    mov.l @(r0, r5), r5
    add #-0x4, r0
    jsr @r3
    mov.l @(r0, r4), r4
    mov r0, r4
    tst r4, r4
    bt      .L_06041FB4
    bra     .L_0604206E
    mov #0x1, r0

    .global DAT_06041f90
DAT_06041f90:
    .word 0x0338
.L_06041F92:
    .2byte  0x0348

    .global DAT_06041f94
DAT_06041f94:
    .2byte  0x035C

    .global DAT_06041f96
DAT_06041f96:
    .2byte  0x034C
    .4byte  0x0000FFF7
    .4byte  smpc_cmd_helper_b
.L_06041FA0:
    .4byte  ai_checkpoint_validate
.L_06041FA4:
    .4byte  sym_060A5400
.L_06041FA8:
    .4byte  track_road_edge_b
.L_06041FAC:
    .4byte  track_road_width_main
.L_06041FB0:
    .4byte  track_post_collision
.L_06041FB4:
    mov r15, r4
    jsr @r12
    add #0x4, r4
    mov.l @r14, r3
    mov r15, r2
    add #0x4, r2
    mov.b @r2, r1
    mov #0x40, r0
    mov.b r1, @(r0, r3)
    mov.l @r13, r3
    add #0x1, r3
    mov.l r3, @r13
    mov.l @r14, r2
    mov #0x3, r3
    mov.w   .L_0604207A, r0
    mov.l r3, @(r0, r2)
.L_06041FD4:
    mov.l @r14, r0
    mov.w   .L_0604207A, r1
    mov.l @(r0, r1), r0
    cmp/eq #0x3, r0
    bf      .L_06042004
    mov.w   DAT_0604207c, r2
    mov.l   .L_06042080, r3
    jsr @r3
    mov.l r2, @r15
    mov r0, r4
    mov.l @r15, r3
    exts.w r4, r5
    and r3, r5
    tst r5, r5
    bt      .L_06041FF6
    bra     .L_06041FF8
    mov #0x1, r5
.L_06041FF6:
    mov #0x0, r5
.L_06041FF8:
    tst r5, r5
    bt      .L_06042004
    mov.l @r14, r3
    mov #0x4, r2
    mov.w   .L_0604207A, r0
    mov.l r2, @(r0, r3)
.L_06042004:
    mov.l @r14, r0
    mov.w   .L_0604207A, r1
    mov.l @(r0, r1), r0
    cmp/eq #0x4, r0
    bf      .L_06042036
    mov.l @r14, r5
    mov.w   DAT_0604207e, r0
    mov.l @r14, r4
    mov.l   .L_06042084, r3
    mov.l @(r0, r5), r5
    add #-0x10, r0
    jsr @r3
    mov.l @(r0, r4), r4
    mov r0, r4
    tst r4, r4
    bt      .L_06042028
    bra     .L_0604206E
    mov #0x1, r0
.L_06042028:
    mov.l @r13, r3
    add #0x1, r3
    mov.l r3, @r13
    mov.l @r14, r2
    mov #0x5, r3
    mov.w   .L_0604207A, r0
    mov.l r3, @(r0, r2)
.L_06042036:
    mov.l @r14, r0
    mov.w   .L_0604207A, r1
    mov.l @(r0, r1), r0
    cmp/eq #0x5, r0
    bf      .L_06042068
    mov #0x40, r2
    mov.l   .L_06042080, r3
    jsr @r3
    mov.l r2, @r15
    mov r0, r4
    mov.l @r15, r3
    exts.w r4, r5
    and r3, r5
    tst r5, r5
    bt      .L_06042058
    bra     .L_0604205A
    mov #0x1, r5
.L_06042058:
    mov #0x0, r5
.L_0604205A:
    mov r5, r0
    cmp/eq #0x1, r0
    bf      .L_06042068
    mov.l @r14, r3
    mov #0x0, r2
    mov.w   .L_0604207A, r0
    mov.l r2, @(r0, r3)
.L_06042068:
    mov.l @r14, r0
    mov.w   .L_0604207A, r1
    mov.l @(r0, r1), r0
.L_0604206E:
    add #0x10, r15
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_0604207A:
    .2byte  0x0348

    .global DAT_0604207c
DAT_0604207c:
    .2byte  0x0100

    .global DAT_0604207e
DAT_0604207e:
    .2byte  0x035C
.L_06042080:
    .4byte  sym_06035C4E
.L_06042084:
    .4byte  track_road_width_main
