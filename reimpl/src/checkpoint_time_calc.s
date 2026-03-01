
    .section .text.FUN_0600DCC8


    .global checkpoint_time_calc
    .type checkpoint_time_calc, @function
checkpoint_time_calc:
    sts.l pr, @-r15
    add #-0x10, r15
    mov.l   .L_p_car_struct, r4
    mov.l   .L_p_car_index, r5
    mov.w   .L_off_timing_data, r0
    mov.l @r4, r4
    mov.l @r5, r5
    mov.l @(r0, r4), r2
    mov r5, r3
    shll2 r5
    shll2 r3
    shll r5
    shll2 r3
    add r3, r5
    add r2, r5
    mov.l @r5, r2
    mov.l r2, @r15
    mov r2, r7
    mov.l @(16, r4), r6
    sub r6, r7
    cmp/pz r7
    bt      .L_x_diff_positive
    mov.l @r15, r2
    mov r6, r3
    sub r2, r3
    bra     .L_x_abs_done
    nop
.L_x_diff_positive:
    mov r7, r3
.L_x_abs_done:
    mov.l @(4, r5), r2
    mov.l r2, @(8, r15)
    mov.l @(24, r4), r2
    mov.l r2, @(12, r15)
    mov.l @(8, r15), r2
    mov.l @(12, r15), r1
    sub r1, r2
    cmp/pz r2
    bt/s    .L_z_diff_positive
    mov.l r2, @(4, r15)
    mov.l @(12, r15), r1
    mov.l @(8, r15), r2
    sub r2, r1
    bra     .L_z_abs_done
    nop
.L_z_diff_positive:
    mov.l @(4, r15), r1
.L_z_abs_done:
    mov r3, r5
    mov.l   .L_p_checkpoint_elapsed, r6
    add r1, r5
    mov.l   .L_fn_hw_divide, r3
    mov r5, r1
    jsr @r3
    mov.l @(12, r4), r0
    mov r0, r1
    mov.l r0, @r6
    mov.l   .L_p_checkpoint_remaining, r4
    mov.l   .L_p_frame_counter, r2
    mov.l @r2, r2
    mov r2, r3
    shll2 r2
    add r3, r2
    sub r1, r2
    mov.l r2, @r4
    mov.l   .L_p_race_state, r0
    mov.l @r0, r0
    tst r0, r0
    bt      .L_epilogue
    mov.l   .L_p_prev_remaining, r5
    mov.l @r4, r3
    mov.l @r5, r2
    sub r2, r3
    mov.l   .L_p_remaining_delta, r2
    mov.l r3, @r2
    mov.l @r4, r3
    mov.l r3, @r5
.L_epilogue:
    add #0x10, r15
    lds.l @r15+, pr
    rts
    nop

    .global DAT_0600dd62
.L_off_timing_data:
DAT_0600dd62:
    .2byte  0x01E0
.L_p_car_struct:
    .4byte  sym_0607E940
.L_p_car_index:
    .4byte  sym_0607EA9C
.L_p_checkpoint_elapsed:
    .4byte  sym_0607869C
.L_fn_hw_divide:
    .4byte  sym_06034FE0
.L_p_checkpoint_remaining:
    .4byte  sym_060786B0
.L_p_frame_counter:
    .4byte  sym_0607EBD0
.L_p_race_state:
    .4byte  sym_0607EAD8
.L_p_prev_remaining:
    .4byte  sym_0605A21C
.L_p_remaining_delta:
    .4byte  sym_060786A0
