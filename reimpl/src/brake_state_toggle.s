
    .section .text.FUN_060103B8


    .global brake_state_toggle
    .type brake_state_toggle, @function
brake_state_toggle:
    mov.l r14, @-r15
    extu.w r4, r3
    mov.l r13, @-r15
    mov.l r12, @-r15
    sts.l pr, @-r15
    mov.l   .L_pool_06010444, r14
    mov.l   .L_06010448, r2
    and r2, r3
    tst r3, r3
    bt      .L_060103DC
    mov #0x1, r2
    mov.l   .L_pool_06010444, r3
    mov.l @r3, r3
    cmp/ge r2, r3
    bt      .L_060103DC
    mov.l @r14, r2
    add #0x1, r2
    mov.l r2, @r14
.L_060103DC:
    extu.w r4, r4
    mov.w   DAT_0601043e, r3
    and r3, r4
    tst r4, r4
    bt      .L_060103F4
    mov.l   .L_pool_06010444, r3
    mov.l @r3, r3
    cmp/pl r3
    bf      .L_060103F4
    mov.l @r14, r3
    add #-0x1, r3
    mov.l r3, @r14
.L_060103F4:
    mov.l   .L_pool_0601044C, r4
    mov.l @r14, r2
    mov.l r2, @r4
    mov.l @r14, r3
    mov.l   .L_pool_06010450, r2
    mov.l r3, @r2
    mov.l   .L_pool_06010454, r12
    mov.w   .L_wpool_06010440, r13
    mov.l @r4, r0
    tst r0, r0
    bt      .L_0601041C
    mov r13, r6
    mov.l   .L_pool_06010458, r5
    mov.l   .L_pool_0601045C, r4
    mov.l @r5, r5
    jsr @r12
    mov.l @r4, r4
    mov.l   .L_pool_06010460, r5
    bra     .L_0601042C
    mov r13, r6
.L_0601041C:
    mov r13, r6
    mov.l   .L_pool_06010464, r5
    mov.l   .L_pool_0601045C, r4
    mov.l @r5, r5
    jsr @r12
    mov.l @r4, r4
    mov r13, r6
    mov.l   .L_pool_06010468, r5
.L_0601042C:
    mov.l @r5, r5
    mov.l   .L_pool_0601046C, r4
    jsr @r12
    mov.l @r4, r4
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global DAT_0601043e
DAT_0601043e:
    .2byte  0x4000
.L_wpool_06010440:
    .2byte  0x00C0
    .2byte  0xFFFF
.L_pool_06010444:
    .4byte  sym_0607EADC
.L_06010448:
    .4byte  0x00008000                  /* 0.5 (16.16 fixed-point) */
.L_pool_0601044C:
    .4byte  sym_0607EAB8
.L_pool_06010450:
    .4byte  sym_06078868
.L_pool_06010454:
    .4byte  dma_transfer
.L_pool_06010458:
    .4byte  sym_0605D084
.L_pool_0601045C:
    .4byte  sym_06078884
.L_pool_06010460:
    .4byte  sym_0605D060
.L_pool_06010464:
    .4byte  sym_0605D05C
.L_pool_06010468:
    .4byte  sym_0605D088
.L_pool_0601046C:
    .4byte  sym_06078880
