
    .section .text.FUN_06014F34


    .global ai_position_ranking
    .type ai_position_ranking, @function
ai_position_ranking:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    sts.l pr, @-r15
    mov.l   _pool_countdown_timer, r12
    mov.l   _pool_car_index, r14
    mov.l   _pool_rank_table_default, r13
    mov.l   _pool_game_state, r5
    mov.l @r5, r0
    cmp/eq #0x19, r0
    .word 0x0029
    mov.l   _pool_display_flags, r3
    mov.l @r3, r3
    and r3, r0
    tst #0x1, r0
    bt/s    .L_check_time_attack
    mov #0x23, r4
    mov.l   _pool_rank_table_mode_a, r13
    bra     .L_table_selected
    mov #0x28, r4
.L_check_time_attack:
    mov.l @r5, r0
    cmp/eq #0x15, r0
    bf      .L_table_selected
    mov.l   _pool_rank_table_mode_b, r13
    mov #0x6, r4
.L_table_selected:
    extu.b r4, r4
    mov.w @r14, r5
    extu.w r5, r5
    cmp/gt r4, r5
    .word 0x0029
    xor #0x1, r0
    mov r0, r3
    mov r5, r0
    cmp/eq #0x64, r0
    .word 0x0129
    add #-0x1, r1
    neg r1, r1
    and r1, r3
    tst r3, r3
    bt      .L_epilogue
    mov.l   _pool_frame_decrement, r3
    mov.w @r12, r2
    mov.l @r3, r3
    sub r3, r2
    mov.w r2, @r12
    mov.w @r12, r3
    cmp/pl r3
    bt      .L_epilogue
.L_process_next_entry:
    mov.l   _pool_fn_data_lookup, r3
    jsr @r3
    mov #0x0, r4
    extu.b r0, r5
    extu.b r5, r0
    cmp/eq #0x11, r0
    bt      .L_epilogue
    extu.b r5, r4
    mov.l   _pool_slot_data_base, r2
    mov.w @r14, r0
    mov r4, r3
    extu.w r0, r0
    shll2 r4
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r4
    exts.w r4, r4
    mov r0, r3
    add r2, r4
    shll r0
    add r3, r0
    mov.b @(r0, r13), r2
    mov.b r2, @r4
    mov.w @r14, r3
    extu.w r3, r3
    mov r3, r2
    shll r3
    add r2, r3
    add r13, r3
    mov.b @(2, r3), r0
    mov r0, r1
    mov #0x40, r0
    mov.b r1, @(r0, r4)
    mov.w @r14, r3
    extu.w r3, r3
    mov r3, r2
    shll r3
    add r2, r3
    add r13, r3
    mov.b @(1, r3), r0
    mov r0, r3
    extu.b r3, r3
    mov.w r3, @r12
    mov.w @r14, r3
    add #0x1, r3
    mov.w r3, @r14
    mov.b @r4, r0
    extu.b r0, r0
    cmp/eq #0x15, r0
    bf      .L_check_countdown
    mov #0x64, r2
    mov.w r2, @r14
.L_check_countdown:
    mov.w @r12, r3
    tst r3, r3
    bf      .L_epilogue
    bra     .L_process_next_entry
    nop
_pool_countdown_timer:
    .4byte  sym_06085F94
_pool_car_index:
    .4byte  sym_06085F90
_pool_rank_table_default:
    .4byte  sym_0605B73A
_pool_game_state:
    .4byte  g_game_state
_pool_display_flags:
    .4byte  sym_0607EBF4
_pool_rank_table_mode_a:
    .4byte  sym_0605B7A6
_pool_rank_table_mode_b:
    .4byte  sym_0605B821
_pool_frame_decrement:
    .4byte  sym_0606BDF8
_pool_fn_data_lookup:
    .4byte  vdp2_data_lookup
_pool_slot_data_base:
    .4byte  sym_06084FC8
.L_epilogue:
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
