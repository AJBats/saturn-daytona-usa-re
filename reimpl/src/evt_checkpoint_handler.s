
    .section .text.FUN_060409E6


    .global evt_checkpoint_handler
    .type evt_checkpoint_handler, @function
evt_checkpoint_handler:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov r5, r13
    mov.l r12, @-r15
    mov #0x0, r12
    mov.l r11, @-r15
    sts.l pr, @-r15
    add #-0x8, r15
    .byte   0xDB, 0x0D    /* mov.l .L_ptr_state_field_read, r11 */ ! r11 = &state_field_read
    cmp/pz r13
    bt/s    .L_check_mode
    mov r4, r14
    mov r12, r13
.L_check_mode:
    mov r6, r0
    cmp/eq #0x1, r0
    bf      .L_range_check
    mov.l r13, @r15
    mov.l @(8, r14), r13
    mov.l @(16, r14), r3
    add r3, r13
    mov.l @r15, r2
    bra     .L_forward_update
    add r2, r13
.L_range_check:
    mov.l @(8, r14), r2
    mov.l @(16, r14), r3
    add r3, r2
    cmp/eq r13, r2
    bf      .L_not_at_target
    bra     .L_epilogue
    mov r13, r0
    .2byte  0xFFFF                                      /* padding */
    .4byte  0x0000FFFF                                  /* padding / alignment */
    .4byte  evt_checkpoint_validate                     /* pool: &evt_checkpoint_validate */
.L_ptr_state_field_read:
    .4byte  state_field_read                            /* pool: &state_field_read */
.L_not_at_target:
    mov.l r12, @-r15
    mov #0x0, r5
    mov r15, r7
    .byte   0xD6, 0x26    /* mov.l .L_mask_low16, r6 */ ! r6 = 0x0000FFFF (16-bit mask)
    .byte   0xD3, 0x26    /* mov.l .L_ptr_cmd_enqueue, r3 */ ! r3 = &cmd_enqueue
    add #0x4, r7
    jsr @r3
    mov.l @(4, r14), r4
    mov r0, r4
    tst r4, r4
    bt/s    .L_enqueue_ok
    add #0x4, r15
    bra     .L_epilogue
    mov #-0x1, r0
.L_enqueue_ok:
    jsr @r11
    nop
    tst r0, r0
    bt      .L_state_ok
    bra     .L_epilogue
    mov #-0x1, r0
.L_state_ok:
    mov.l @r15, r3
    cmp/pz r3
    bt      .L_forward_update
    mov.l r12, @r15
.L_forward_update:
    mov.l @(36, r14), r0
    tst r0, r0
    bf      .L_reverse_direction
    mov.l @(8, r14), r4
    cmp/gt r13, r4
    bt      .L_fwd_check_range
    mov.l @(16, r14), r2
    add r4, r2
    cmp/ge r2, r13
    bt      .L_fwd_check_range
    mov.l @(8, r14), r2
    mov r13, r3
    sub r2, r3
    mov.l r3, @r15
.L_fwd_check_range:
    mov.l @r15, r3
    cmp/pl r3
    bf      .L_fwd_store_result
    mov.l @r15, r6
    mov #0x0, r5
    .byte   0xD3, 0x14    /* mov.l .L_ptr_validate, r3 */ ! r3 = &evt_checkpoint_validate
    jsr @r3
    mov.l @(4, r14), r4
    jsr @r11
    nop
    tst r0, r0
    bt      .L_fwd_store_result
    bra     .L_epilogue
    mov #-0x1, r0
.L_fwd_store_result:
    mov.l r13, @(8, r14)
    bra     .L_compute_return
    mov.l r12, @(16, r14)
.L_reverse_direction:
    mov.l @(36, r14), r0
    cmp/eq #0x1, r0
    bf      .L_compute_return
    mov.l @(8, r14), r4
    cmp/ge r4, r13
    bf      .L_rev_out_of_range
    mov.l @(16, r14), r2
    add r4, r2
    add #0x1, r2
    cmp/gt r2, r13
    bf      .L_rev_update_span
.L_rev_out_of_range:
    mov.l r14, @(4, r15)
    mov #0x0, r5
    mov r14, r4
    .byte   0xD6, 0x05    /* mov.l .L_mask_low16, r6 */ ! r6 = 0x0000FFFF (16-bit mask)
    .byte   0xD3, 0x06    /* mov.l .L_ptr_validate, r3 */ ! r3 = &evt_checkpoint_validate
    jsr @r3
    mov.l @(4, r4), r4
    jsr @r11
    nop
    mov r0, r4
    tst r4, r4
    bf      .L_rev_store_base
    bra     .L_epilogue
    mov #-0x1, r0
.L_mask_low16:
    .4byte  0x0000FFFF                  /* low 16-bit mask */
.L_ptr_cmd_enqueue:
    .4byte  cmd_enqueue                 /* pool: &cmd_enqueue */
.L_ptr_validate:
    .4byte  evt_checkpoint_validate     /* pool: &evt_checkpoint_validate */
.L_rev_store_base:
    mov.l r13, @(8, r14)
.L_rev_update_span:
    mov.l @(8, r14), r3
    sub r3, r13
    mov.l r13, @(16, r14)
.L_compute_return:
    mov.l @(8, r14), r0
    mov.l @(16, r14), r2
    add r2, r0
.L_epilogue:
    add #0x8, r15
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
