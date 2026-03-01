
    .section .text.FUN_060406BC


    .global sys_timer_tick
    .type sys_timer_tick, @function
sys_timer_tick:
    sts.l pr, @-r15
    add #-0xC, r15
    .byte   0xBF, 0xD1    /* bsr 0x06040666 (external) */
    mov.l r5, @r15
    tst r0, r0
    bf      .L_060406CC
    bra     .L_06040716
    mov #0x0, r0
.L_060406CC:
    mov.l   .L_060406E4, r3
    jsr @r3
    nop
    mov r0, r14
    cmp/pz r14
    bt      .L_060406E8
    bra     .L_06040716
    mov #0x0, r0
    .4byte  sym_060409DE
    .4byte  evt_checkpoint_handler
.L_060406E4:
    .4byte  sym_06040FB8
.L_060406E8:
    mov r15, r3
    mov #0x1, r2
    add #0x4, r3
    mov.l r2, @r3
    mov r15, r3
    mov.l @r15, r5
    add #0x4, r3
    mov r3, r8
    add #0x4, r8
    bsr     .L_06040722
    mov r13, r4
    mov r14, r5
    mov r15, r4
    mov.l @(4, r13), r2
    add r2, r0
    mov.l r0, @r8
    .byte   0xD3, 0x18    /* mov.l .L_pool_0604076C, r3 */
    jsr @r3
    add #0x4, r4
    .byte   0xD3, 0x18    /* mov.l .L_pool_06040770, r3 */
    jsr @r3
    mov r14, r4
    mov #0x1, r0
.L_06040716:
    add #0xC, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_06040722:
    mov #0x1E, r0
