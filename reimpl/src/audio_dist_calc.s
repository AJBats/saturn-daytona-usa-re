
    .section .text.FUN_0600DD88


    .global audio_dist_calc
    .type audio_dist_calc, @function
audio_dist_calc:
    sts.l pr, @-r15
    add #-0x1, r4
    add #-0x10, r15
    shll2 r4
    mov.l   .L_car_struct_ptr, r5
    mov.l   .L_course_data_ptr, r0
    mov.l @r5, r5
    mov.l @r0, r0
    mov.l @(16, r5), r6
    mov.l @(4, r0), r3
    mov.w   DAT_0600de1e, r0
    add r3, r4
    mov.l @r4, r2
    mov r2, r3
    mov.l @(r0, r5), r4
    shll2 r2
    shll2 r3
    shll r2
    shll2 r3
    add r3, r2
    add r2, r4
    mov.l @r4, r7
    mov r7, r2
    sub r6, r2
    cmp/pz r2
    bt/s    .L_x_diff_positive
    mov.l r2, @(12, r15)
    mov r6, r3
    bra     .L_x_abs_done
    sub r7, r3
.L_x_diff_positive:
    mov.l @(12, r15), r3
.L_x_abs_done:
    mov.l @(4, r4), r2
    mov.l r2, @(4, r15)
    mov.l @(24, r5), r2
    mov.l r2, @(8, r15)
    mov.l @(4, r15), r2
    mov.l @(8, r15), r1
    sub r1, r2
    cmp/pz r2
    bt/s    .L_y_diff_positive
    mov.l r2, @r15
    mov.l @(8, r15), r1
    mov.l @(4, r15), r2
    sub r2, r1
    bra     .L_y_abs_done
    nop
.L_y_diff_positive:
    mov.l @r15, r1
.L_y_abs_done:
    mov r3, r4
    mov.l   .L_p_audio_elapsed, r6
    add r1, r4
    mov.l   .L_fn_scale_divide, r3
    mov r4, r1
    jsr @r3
    mov.l @(12, r5), r0
    mov.l r0, @r6
    mov r0, r1
    mov.l   .L_p_audio_remaining, r4
    mov.l   .L_p_frame_counter, r2
    mov.l @r2, r2
    mov r2, r3
    shll2 r2
    add r3, r2
    sub r1, r2
    mov r2, r3
    mov.l r2, @r4
    mov.l   .L_p_prev_remaining, r5
    mov.l @r5, r2
    sub r2, r3
    mov.l   .L_p_remaining_delta, r2
    mov.l r3, @r2
    mov.l @r4, r3
    add #0x10, r15
    lds.l @r15+, pr
    rts
    mov.l r3, @r5

    .global DAT_0600de1e
DAT_0600de1e:
    .2byte  0x01E0                           /* car_struct offset to audio data array pointer */
.L_car_struct_ptr:
    .4byte  sym_0607E940                     /* → current car struct pointer */
.L_course_data_ptr:
    .4byte  sym_06063F3C                     /* → current course data entry pointer */
.L_p_audio_elapsed:
    .4byte  sym_0607869C                     /* → audio_elapsed output (scaled distance) */
.L_fn_scale_divide:
    .4byte  sym_06034FE0                     /* → scale/divide function */
.L_p_audio_remaining:
    .4byte  sym_060786B0                     /* → audio_remaining output (frame_counter*5 - elapsed) */
.L_p_frame_counter:
    .4byte  sym_0607EBD0                     /* → frame counter (32-bit) */
.L_p_prev_remaining:
    .4byte  sym_0605A21C                     /* → previous remaining value (in/out) */
.L_p_remaining_delta:
    .4byte  sym_060786A0                     /* → remaining_delta output (remaining - prev_remaining) */
