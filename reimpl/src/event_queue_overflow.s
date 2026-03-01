
    .section .text.FUN_06040F1C


    .global event_queue_overflow
    .type event_queue_overflow, @function
event_queue_overflow:
    sts.l pr, @-r15
    mov.l   .L_pool_06040F3C, r13
    cmp/pz r14
    bf      .L_index_out_of_range
    mov #0x18, r2
    cmp/ge r2, r14
    bf      .L_check_slot_active
.L_index_out_of_range:
    bra     .L_return
    mov #-0x6, r0
.L_check_slot_active:
    mov.l @r13, r0
    mov.b @(r0, r14), r0
    cmp/eq #0x1, r0
    bt      .L_register_checkpoint
    bra     .L_return
    mov #-0x7, r0
    .2byte  0xFFFF
.L_pool_06040F3C:
    .4byte  sym_060A5400
.L_register_checkpoint:
    .byte   0xD6, 0x19    /* mov.l .L_pool_06040FA8, r6 */
    mov #0x0, r5
    .byte   0xB1, 0xB5    /* bsr 0x060412B2 (external) */
    mov r14, r4
    .byte   0xD4, 0x18    /* mov.l .L_pool_06040FAC, r4 */
    mov.l @r13, r2
    mov.l r4, @(60, r2)
.L_poll_loop:
    .byte   0xB3, 0xA3    /* bsr 0x06041698 (external) */
    nop
    cmp/eq #0x3, r0
    bf/s    .L_check_complete
    mov r0, r4
    bra     .L_return
    mov #-0xC, r0
.L_check_complete:
    .byte   0xB1, 0xD8    /* bsr 0x06041310 (external) */
    mov r14, r4
    cmp/eq #0x1, r0
    bf      .L_not_yet_fired
    bra     .L_clear_and_return
    nop
.L_not_yet_fired:
    bra     .L_poll_loop
    nop
.L_clear_and_return:
    mov #0x0, r4
    mov r4, r5
    mov.l @r13, r2
    mov.l r4, @(60, r2)
    mov.l @r13, r0
    mov.b r5, @(r0, r14)
    mov r5, r0
.L_return:
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
