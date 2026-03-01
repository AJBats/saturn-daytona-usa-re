
    .section .text.FUN_06018278


    .global track_calc_helper
    .type track_calc_helper, @function
track_calc_helper:
    sts.l pr, @-r15
    mov.l   .L_ptr_button_state, r5
    mov.l   .L_ptr_scroll_offset_a, r7
    mov.w @r5, r5
    mov.w @r7, r0
    extu.w r0, r0
    tst r0, r0
    bf/s    .L_exit
    extu.w r5, r5
    tst r5, r5
    bt      .L_exit

    mov #0x0, r6
    mov.l   .L_ptr_scroll_step, r4
    mov.l   .L_ptr_seg_type_table, r3
    mov.l   .L_fn_shift_left_n, r2
    mov.w @r4, r1
    extu.w r1, r1
    add r3, r1
    mov.b @r1, r1
    extu.b r1, r1
    jsr @r2
    mov #0x1, r0
    and r5, r0
    tst r0, r0
    bt      .L_reset_step

    mov.w @r4, r3
    add #0x1, r3
    mov.w r3, @r4
    mov.w @r4, r0
    extu.w r0, r0
    cmp/eq #0x7, r0
    bf      .L_exit

    extu.w r6, r6
    mov #0x1, r2
    mov.w r6, @r4
    mov.w r2, @r7
    mov.l   .L_ptr_slot_table, r5
    mov.l   .L_ptr_slot_index, r4
    mov.l   .L_ptr_proj_param, r2
    mov.w @r4, r3
    mov.l @r2, r2
    extu.w r3, r3
    shll2 r3
    shll r3
    add r5, r3
    mov.l r2, @r3
    mov.w @r4, r3
    extu.w r3, r3
    shll2 r3
    shll r3
    add r5, r3
    mov.w   .L_wpool_slot_flag, r2
    mov r2, r0
    mov.w r0, @(6, r3)
    bra     .L_exit
    nop

.L_reset_step:
    extu.w r6, r6
    mov.w r6, @r4

.L_exit:
    lds.l @r15+, pr
    rts
    nop


    .global DAT_060182f2
DAT_060182f2:
    mov.b r3, @(r0, r5)
.L_wpool_slot_flag:
    .2byte  0x0460
    .2byte  0xFFFF
    .4byte  sym_0607EBC4
    .4byte  0x00800000
.L_ptr_button_state:
    .4byte  sym_06063D9A
.L_ptr_scroll_offset_a:
    .4byte  sym_0605BE1C
.L_ptr_scroll_step:
    .4byte  sym_0605BE1E
.L_ptr_seg_type_table:
    .4byte  sym_06048120
.L_fn_shift_left_n:
    .4byte  sym_06035280
.L_ptr_slot_table:
    .4byte  sym_06063F64
.L_ptr_slot_index:
    .4byte  sym_06069BB6
.L_ptr_proj_param:
    .4byte  sym_06089E3C
