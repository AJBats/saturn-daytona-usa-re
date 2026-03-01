
   .section .text.FUN_06041EE8


   .global track_edge_validate
   .type track_edge_validate, @function
track_edge_validate:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    sts.l pr, @-r15
    add #-0x10, r15
    mov.l   .L_fn_checkpoint_validate, r12
    mov.l   .L_car_state_base, r14
    mov.w   .L_off_state_phase, r1
    mov.l @r14, r0
    mov.l @(r0, r1), r0
    cmp/eq #0x1, r0
    bf/s    .L_state2_check
    mov r4, r13
    mov.l @r14, r5
    mov.w   DAT_06041f94, r3
    mov.l @r14, r4
    mov.w   DAT_06041f96, r0
    add r3, r5
    mov.l   .L_fn_road_edge, r3
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
    mov.l   .L_fn_road_width, r3
    jsr @r3
    mov.l @(r0, r4), r4
    mov r0, r4
    tst r4, r4
    bt      .L_state1_revalidate
    bra     .L_epilogue
    mov #0x1, r0
.L_state1_revalidate:
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
    mov.w   .L_off_state_phase, r0
    mov.l r3, @(r0, r2)
.L_state2_check:
    mov.l @r14, r0
    mov.w   .L_off_state_phase, r1
    mov.l @(r0, r1), r0
    cmp/eq #0x2, r0
    bf      .L_state3_check
    mov.l @r14, r7
    mov.w   DAT_06041f96, r0
    mov.l @r14, r6
    mov.l @r14, r5
    mov.l @r14, r4
    mov.l   .L_fn_post_collision, r3
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
    bt      .L_state2_advance
    bra     .L_epilogue
    mov #0x1, r0

    .global DAT_06041f90
DAT_06041f90:
    .word 0x0338
.L_off_state_phase:
    .2byte  0x0348                       /* car state offset: validation phase (0-5) */

    .global DAT_06041f94
DAT_06041f94:
    .2byte  0x035C                       /* car state offset: road edge data */

    .global DAT_06041f96
DAT_06041f96:
    .2byte  0x034C                       /* car state offset: road parameters */
    .4byte  0x0000FFF7                   /* (adjacent pool data) */
    .4byte  smpc_cmd_helper_b            /* (adjacent pool: SMPC helper) */
.L_fn_checkpoint_validate:
    .4byte  ai_checkpoint_validate       /* AI checkpoint validation function */
.L_car_state_base:
    .4byte  sym_060A5400                 /* AI car state base (ptr to struct) */
.L_fn_road_edge:
    .4byte  track_road_edge_b            /* track road edge detection */
.L_fn_road_width:
    .4byte  track_road_width_main        /* track road width validation */
.L_fn_post_collision:
    .4byte  track_post_collision         /* post-collision track recovery */
.L_state2_advance:
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
    mov.w   .L_off_state_phase_b, r0
    mov.l r3, @(r0, r2)
.L_state3_check:
    mov.l @r14, r0
    mov.w   .L_off_state_phase_b, r1
    mov.l @(r0, r1), r0
    cmp/eq #0x3, r0
    bf      .L_state4_check
    mov.w   DAT_0604207c, r2
    mov.l   .L_fn_input_check, r3
    jsr @r3
    mov.l r2, @r15
    mov r0, r4
    mov.l @r15, r3
    exts.w r4, r5
    and r3, r5
    tst r5, r5
    bt      .L_state3_bit_clear
    bra     .L_state3_test_flag
    mov #0x1, r5
.L_state3_bit_clear:
    mov #0x0, r5
.L_state3_test_flag:
    tst r5, r5
    bt      .L_state4_check
    mov.l @r14, r3
    mov #0x4, r2
    mov.w   .L_off_state_phase_b, r0
    mov.l r2, @(r0, r3)
.L_state4_check:
    mov.l @r14, r0
    mov.w   .L_off_state_phase_b, r1
    mov.l @(r0, r1), r0
    cmp/eq #0x4, r0
    bf      .L_state5_check
    mov.l @r14, r5
    mov.w   DAT_0604207e, r0
    mov.l @r14, r4
    mov.l   .L_fn_road_width_b, r3
    mov.l @(r0, r5), r5
    add #-0x10, r0
    jsr @r3
    mov.l @(r0, r4), r4
    mov r0, r4
    tst r4, r4
    bt      .L_state4_advance
    bra     .L_epilogue
    mov #0x1, r0
.L_state4_advance:
    mov.l @r13, r3
    add #0x1, r3
    mov.l r3, @r13
    mov.l @r14, r2
    mov #0x5, r3
    mov.w   .L_off_state_phase_b, r0
    mov.l r3, @(r0, r2)
.L_state5_check:
    mov.l @r14, r0
    mov.w   .L_off_state_phase_b, r1
    mov.l @(r0, r1), r0
    cmp/eq #0x5, r0
    bf      .L_read_final_state
    mov #0x40, r2
    mov.l   .L_fn_input_check, r3
    jsr @r3
    mov.l r2, @r15
    mov r0, r4
    mov.l @r15, r3
    exts.w r4, r5
    and r3, r5
    tst r5, r5
    bt      .L_state5_bit_clear
    bra     .L_state5_test_flag
    mov #0x1, r5
.L_state5_bit_clear:
    mov #0x0, r5
.L_state5_test_flag:
    mov r5, r0
    cmp/eq #0x1, r0
    bf      .L_read_final_state
    mov.l @r14, r3
    mov #0x0, r2
    mov.w   .L_off_state_phase_b, r0
    mov.l r2, @(r0, r3)
.L_read_final_state:
    mov.l @r14, r0
    mov.w   .L_off_state_phase_b, r1
    mov.l @(r0, r1), r0
.L_epilogue:
    add #0x10, r15
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_off_state_phase_b:
    .2byte  0x0348                       /* state phase offset (dup for PC-relative reach) */

    .global DAT_0604207c
DAT_0604207c:
    .2byte  0x0100                       /* input bit mask: state 3 check */

    .global DAT_0604207e
DAT_0604207e:
    .2byte  0x035C                       /* road data offset (dup for PC-relative reach) */
.L_fn_input_check:
    .4byte  sym_06035C4E                 /* input status check function */
.L_fn_road_width_b:
    .4byte  track_road_width_main        /* road width validation (dup for reach) */
