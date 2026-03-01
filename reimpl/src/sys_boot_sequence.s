
    .section .text.FUN_060402BC


    .global sys_boot_sequence
    .type sys_boot_sequence, @function
sys_boot_sequence:
    mov.l r14, @-r15
    mov r4, r14
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0x1C, r15
    mov.l   .L_ptr_boundary_release, r10
    mov r15, r5
    mov.l   .L_ptr_game_state, r13
    mov.l @(24, r14), r12
    mov.l @(32, r14), r11
    mov.l @(36, r14), r3
    add #0x4, r5
    sub r3, r11
    .byte   0xB1, 0x6A    /* bsr 0x060405B8 (external) */ ! call evt_validate_multi(sp, sp+4)
    mov r15, r4
    bra     .L_state_dispatch
    mov r0, r9

.L_state2_redirect:
    bra     .L_process_data
    nop
.L_ptr_boundary_release:
    .4byte  sym_06040FEA
.L_ptr_game_state:
    .4byte  sym_060A4D14

.L_state0_surface_check:
    mov.l   .L_ptr_surface_check, r3
    jsr @r3
    nop
    tst r0, r0
    bf      .L_process_data
    bra     .L_epilogue
    mov #0x1, r0

.L_state3_exit:
    bra     .L_epilogue
    mov #0x3, r0

.L_state4_exit:
    bra     .L_epilogue
    mov #0x4, r0

.L_state5_release_lock:
    jsr @r10
    mov.l @(40, r12), r4
    bra     .L_epilogue
    mov #0x6, r0

.L_state_dispatch:
    cmp/eq #0x0, r0
    bt      .L_state0_surface_check
    cmp/eq #0x1, r0
    bt      .L_process_data
    cmp/eq #0x2, r0
    bt      .L_state2_redirect
    cmp/eq #0x3, r0
    bt      .L_state3_exit
    cmp/eq #0x4, r0
    bt      .L_state4_exit
    bra     .L_state5_release_lock
    nop

.L_process_data:
    mov.l @(32, r14), r4
    tst r4, r4
    bf      .L_clamp_remaining
    mov.l @(36, r14), r3
    cmp/eq r3, r4
    bf      .L_clamp_remaining
    bra     .L_epilogue
    mov #0x2, r0

.L_clamp_remaining:
    mov.l @(40, r14), r4
    cmp/ge r4, r11
    bt      .L_use_max_chunk
    bra     .L_check_boundary
    nop
.L_ptr_surface_check:
    .4byte  track_surface_check
.L_use_max_chunk:
    mov r4, r11

.L_check_boundary:
    mov.l   .L_ptr_boundary_active, r3
    jsr @r3
    mov.l @(40, r12), r4
    tst r0, r0
    bt      .L_enqueue_command
    bra     .L_boundary_active_path
    nop

.L_enqueue_command:
    mov #0x0, r6
    mov.l   .L_fp_max, r5
    mov.l   .L_ptr_evt_cmd_enqueue, r3
    jsr @r3
    mov.l @(24, r14), r4
    mov r0, r9
    cmp/pz r9
    bt      .L_calc_dest_offset
    mov #0x0, r9

.L_calc_dest_offset:
    mov.l   .L_ptr_calc_position, r3
    jsr @r3
    mov r12, r4
    mov r0, r5
    .byte   0xB1, 0xD6    /* bsr 0x06040722 (external) */ ! call offset_compute(ctx)
    mov r14, r4
    mov.l @(4, r14), r8
    cmp/pl r9
    bf/s    .L_check_batch_fits
    add r0, r8
    mov.l   .L_ptr_game_state_b, r3
    mov.w   .L_off_state_pos_ac, r0
    mov.l @r3, r3
    mov.l @(r0, r3), r2
    cmp/ge r2, r8
    bt      .L_check_batch_fits
    mov.l @r13, r2
    mov.w   .L_off_state_pos_ac, r0
    mov.l @(r0, r2), r3
    sub r8, r3
    sub r3, r9

.L_check_batch_fits:
    cmp/ge r11, r9
    bf      .L_partial_remaining
    mov.l @(36, r14), r2
    add r11, r2
    mov.l r2, @(36, r14)
    mov.l @(32, r14), r3
    sub r2, r3
    tst r3, r3
    bf      .L_batch_continue
    bra     .L_epilogue
    mov #0x2, r0

.L_batch_continue:
    bra     .L_epilogue
    mov #0x0, r0

.L_partial_remaining:
    sub r9, r11
    cmp/pl r11
    bt      .L_acquire_lock
    mov.l @(32, r14), r3
    mov.l @(36, r14), r2
    sub r2, r3
    tst r3, r3
    bf      .L_partial_continue
    bra     .L_epilogue
    mov #0x2, r0

.L_partial_continue:
    bra     .L_epilogue
    mov #0x0, r0

.L_acquire_lock:
    mov.l   .L_ptr_boundary_acquire, r3
    jsr @r3
    nop
    mov r0, r9
    cmp/pz r9
    bt      .L_build_sub_batch
    bra     .L_epilogue
    mov #0x6, r0

.L_off_state_pos_ac:
    .2byte  0x00AC
.L_ptr_boundary_active:
    .4byte  sym_06041014
.L_fp_max:
    .4byte  0x7FFFFFFF                  /* max positive 16.16 */
.L_ptr_evt_cmd_enqueue:
    .4byte  evt_cmd_enqueue
.L_ptr_calc_position:
    .4byte  sym_060409DE
.L_ptr_game_state_b:
    .4byte  sym_060A4D14
.L_ptr_boundary_acquire:
    .4byte  sym_06040FB8

.L_build_sub_batch:
    mov.l r9, @(40, r12)
    mov.l   .L_ptr_calc_position_b, r3
    jsr @r3
    mov r12, r4
    mov r11, r5
    add r0, r5
    .byte   0xB1, 0x91    /* bsr 0x06040722 (external) */ ! call offset_compute(ctx)
    mov r14, r4
    mov.l @(4, r14), r2
    mov #0x1, r4
    mov r15, r3
    add r2, r0
    add #0x8, r3
    mov r15, r2
    mov.l r0, @(8, r14)
    add #0x8, r2
    mov.l r4, @r3
    mov #0x10, r0
    mov.l r8, @(4, r2)
    mov r15, r3
    mov r15, r2
    add #0x8, r3
    add #0x8, r2
    mov.l r4, @(8, r3)
    mov r15, r3
    mov.l @(8, r14), r1
    add #0x8, r3
    mov.l @(4, r3), r3
    sub r3, r1
    mov #0x0, r3
    mov.l r1, @(12, r2)
    mov r3, r5
    mov r15, r2
    add #0x8, r2
    mov.b r3, @(r0, r2)
    .byte   0xB0, 0xBF    /* bsr 0x060405B8 (external) */ ! call evt_validate_multi(sp, 0)
    mov r15, r4

    mov r15, r3
    mov.l @r13, r4
    mov.w   .L_off_state_pos_ac_b, r0
    add #0x8, r3
    mov.l @(r0, r4), r4
    mov.l @(4, r3), r2
    cmp/gt r2, r4
    bt      .L_validate_and_commit
    mov r15, r2
    mov.l @r13, r3
    mov.w   .L_off_state_pos_b0, r0
    add #0x8, r2
    mov.l @(r0, r3), r3
    mov.l @(4, r2), r2
    cmp/ge r3, r2
    bt      .L_validate_and_commit
    mov.l @(8, r14), r2
    cmp/ge r2, r4
    bt      .L_validate_and_commit
    mov.l @r13, r2
    mov.l @(8, r14), r3
    mov.w   .L_off_state_pos_b0, r0
    mov.l @(r0, r2), r2
    cmp/gt r2, r3
    bt      .L_validate_and_commit

    mov.l @r13, r2
    mov r15, r3
    add #0x8, r3
    mov.l @(4, r3), r1
    mov.w   .L_off_state_pos_ac_b, r0
    mov.l r1, @(r0, r2)
    bra     .L_epilogue
    mov #0x0, r0

.L_validate_and_commit:
    mov r9, r5
    mov.l   .L_ptr_queue_validator, r3
    jsr @r3
    mov.l @(20, r12), r4
    mov.l   .L_ptr_state_field_read, r3
    jsr @r3
    nop
    tst r0, r0
    bt      .L_commit_queue_entry
    bra     .L_epilogue
    mov #0x6, r0

.L_commit_queue_entry:
    mov r9, r5
    mov r15, r4
    mov.l   .L_ptr_queue_helper, r3
    jsr @r3
    add #0x8, r4
    mov.l @(36, r14), r2
    add r11, r2
    mov.l r2, @(36, r14)
    mov.l @r13, r3
    mov r15, r2
    add #0x8, r2
    mov.l @(4, r2), r1
    mov.w   .L_off_state_pos_ac_b, r0
    mov.l r1, @(r0, r3)
    mov.l @r13, r3
    mov.l @(8, r14), r2
    add #0x4, r0
    mov.l r2, @(r0, r3)
    bra     .L_epilogue
    mov #0x0, r0

.L_off_state_pos_ac_b:
    .2byte  0x00AC
.L_off_state_pos_b0:
    .2byte  0x00B0
    .2byte  0xFFFF
.L_ptr_calc_position_b:
    .4byte  sym_060409DE
.L_ptr_queue_validator:
    .4byte  queue_validator
.L_ptr_state_field_read:
    .4byte  state_field_read
.L_ptr_queue_helper:
    .4byte  queue_helper

.L_boundary_active_path:
    mov.l @(8, r14), r3
    mov.l @r15, r2
    cmp/gt r2, r3
    bt      .L_end_exceeds_boundary
    jsr @r10
    mov.l @(40, r12), r4
    mov.l @r13, r2
    mov.w   .L_off_state_pos_b0_b, r0
    mov.l @(r0, r2), r3
    mov.l @r15, r2
    cmp/gt r2, r3
    bt      .L_boundary_within_range
    mov.l @r13, r2
    mov r2, r3
    mov.w   .L_off_state_pos_b0_b, r0
    mov.l @(r0, r3), r1
    add #-0x4, r0
    mov.l r1, @(r0, r2)
    bra     .L_epilogue
    mov #0x2, r0

.L_boundary_within_range:
    bra     .L_epilogue
    mov #0x0, r0

.L_end_exceeds_boundary:
    mov.l @r13, r3
    mov.l @r15, r2
    mov.w   .L_off_state_pos_ac_c, r0
    mov.l @(r0, r3), r3
    sub r3, r2
    mov.l @(32, r14), r3
    cmp/ge r3, r2
    bf      .L_check_enqueue_result
    jsr @r10
    mov.l @(40, r12), r4
    bra     .L_epilogue
    mov #0x2, r0

.L_check_enqueue_result:
    tst r9, r9
    bf      .L_return_continue
    jsr @r10
    mov.l @(40, r12), r4
    bra     .L_epilogue
    mov #0x6, r0

.L_return_continue:
    mov #0x0, r0

.L_epilogue:
    add #0x1C, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

.L_off_state_pos_b0_b:
    .2byte  0x00B0
.L_off_state_pos_ac_c:
    .2byte  0x00AC
