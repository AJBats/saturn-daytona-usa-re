
    .section .text.FUN_06020C3C


    .global obj_collision_update
    .type obj_collision_update, @function
obj_collision_update:
    sts.l pr, @-r15
    add #-0x20, r15
    mov r15, r1
    mov.l   .L_pool_06020CC8, r2
    mov.l   .L_pool_06020CCC, r3
    add #0x10, r1
    jsr @r3
    mov #0x10, r0
    mov r15, r1
    mov.l   .L_pool_06020CD0, r2
    mov.l   .L_pool_06020CCC, r3
    jsr @r3
    mov #0x10, r0
    mov.l   .L_pool_06020CD4, r7
    mov.l   .L_pool_06020CD8, r6
    mov.l   .L_pool_06020CDC, r5
    mov #0x1, r4
    mov.l   .L_pool_06020CE0, r0
    mov.w @r0, r0
    bra     .L_06020CAA
    extu.w r0, r0
.L_06020C66:
    mov #0xF, r3
    extu.w r4, r4
    mov.l   .L_pool_06020CE4, r0
    mov.w r0, @(10, r5)
    mov #0x20, r0
    mov.w r3, @(r0, r6)
    mov.w r4, @r7
    mov r15, r4
    mov.l   .L_pool_06020CE8, r3
    jsr @r3
    add #0x10, r4
    bra     .L_06020CBA
    nop
.L_06020C80:
    mov.l   .L_pool_06020CEC, r0
    mov #0xF, r3
    extu.w r4, r4
    mov.w r0, @(10, r5)
    mov #0x20, r0
    mov.w r3, @(r0, r6)
    mov.w r4, @r7
    mov.l   .L_pool_06020CE8, r3
    jsr @r3
    mov r15, r4
    bra     .L_06020CBA
    nop
.L_06020C98:
    .byte   0xBE, 0x55    /* bsr 0x06020946 (external) */
    nop
    bra     .L_06020CBA
    nop
.L_06020CA0:
    mov.l   .L_pool_06020CF0, r3
    jsr @r3
    mov #0x4, r4
    bra     .L_06020CBA
    nop
.L_06020CAA:
    cmp/eq #0x1, r0
    bt      .L_06020C66
    cmp/eq #0x2, r0
    bt      .L_06020C80
    cmp/eq #0x3, r0
    bt      .L_06020C98
    cmp/eq #0x4, r0
    bt      .L_06020CA0
.L_06020CBA:
    mov #0x0, r2
    mov.l   .L_pool_06020CE0, r3
    add #0x20, r15
    lds.l @r15+, pr
    rts
    mov.w r2, @r3
    .2byte  0xFFFF
.L_pool_06020CC8:
    .4byte  sym_0605F588
.L_pool_06020CCC:
    .4byte  sym_06035228
.L_pool_06020CD0:
    .4byte  sym_0605F598
.L_pool_06020CD4:
    .4byte  sym_060635AC
.L_pool_06020CD8:
    .4byte  sym_060A3D88
.L_pool_06020CDC:
    .4byte  sym_060A3DB0
.L_pool_06020CE0:
    .4byte  sym_0608780C
.L_pool_06020CE4:
    .4byte  0x0000C060
.L_pool_06020CE8:
    .4byte  sym_06038044
.L_pool_06020CEC:
    .4byte  0x0000C044
.L_pool_06020CF0:
    .4byte  sym_0602853E
