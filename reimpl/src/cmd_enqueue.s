
    .section .text.FUN_060411A0


    .global cmd_enqueue
    .type cmd_enqueue, @function
cmd_enqueue:
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_pool_game_state_ptr, r1
    mov.w   DAT_060411f6, r0
    mov.l @r1, r3
    mov.l @(r0, r3), r0
    tst r0, r0
    bt      .L_060411B8
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov #-0x1, r0
.L_060411B8:
    mov.l @r1, r3
    mov #0x1, r2
    mov.w   DAT_060411f6, r0
    mov.l r2, @(r0, r3)
    mov.l @r1, r3
    add #0x4, r0
    mov #0x0, r2
    mov.l r4, @(r0, r3)
    mov.l @r1, r3
    add #0x4, r0
    mov.l r5, @(r0, r3)
    add #0x4, r0
    mov.l @r1, r3
    mov.l r6, @(r0, r3)
    mov.l @r1, r3
    add #0x4, r0
    mov.l r2, @(r0, r3)
    add #0x4, r0
    mov.l @r1, r3
    mov.l r7, @(r0, r3)
    mov.l @r1, r3
    mov.l @(8, r15), r2
    mov.w   .L_wpool_cmd_completion_ptr_offset, r0
    mov.l r2, @(r0, r3)
    .byte   0xB4, 0xA8    /* bsr 0x06041B3C (external) */
    mov r15, r4
    mov #0x0, r0
    add #0x4, r15
    lds.l @r15+, pr
    rts
    nop

    .global DAT_060411f6
DAT_060411f6:
    .2byte  0x030C
.L_wpool_cmd_completion_ptr_offset:
    .2byte  0x0324
    .2byte  0xFFFF
.L_pool_game_state_ptr:
    .4byte  sym_060A5400
    .4byte  ai_throttle_modulate
