
    .section .text.FUN_0601B6F0


    .global anim_data_loader
    .type anim_data_loader, @function
anim_data_loader:
    sts.l pr, @-r15
    add #-0xC, r15
    mov.l   _pool_frame_counter_ptr, r12
    mov r15, r1
    mov.l   _pool_frame_count_table, r2
    mov.l   _pool_memcpy_byte, r3
    add #0x8, r1
    jsr @r3
    mov r10, r0
    mov r15, r1
    mov.l   _pool_tex_slot_table, r2
    mov.l   _pool_memcpy_byte, r3
    add #0x4, r1
    jsr @r3
    mov r10, r0
    mov.l   _pool_input_state_ptr, r4
    mov.w   DAT_0601b76c, r3
    mov.w @(2, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r3, r2
    tst r2, r2
    bt      .check_btn_up
    mov.b @r12, r3
    add #-0x1, r3
    mov.b r3, @r12
    exts.b r3, r3
    cmp/pz r3
    bt      .begin_car_loop
    exts.b r13, r3
    mov.b r3, @r12
    bra     .begin_car_loop
    nop
.check_btn_up:
    mov.w @(2, r4), r0
    mov.w   DAT_0601b76e, r3
    mov r0, r2
    extu.w r2, r2
    and r3, r2
    tst r2, r2
    bt      .begin_car_loop
    mov.b @r12, r3
    add #0x1, r3
    mov.b r3, @r12
    exts.b r3, r3
    cmp/ge r10, r3
    bf      .begin_car_loop
    mov #0x0, r3
    mov.b r3, @r12
.begin_car_loop:
    mov #0x0, r14
.car_loop_top:
    extu.b r14, r3
    mov.b @r12, r2
    cmp/eq r3, r2
    bf      .car_not_selected
    mov.l   _pool_tex_load_state, r0
    mov.w @r0, r0
    extu.w r0, r0
    tst #0x4, r0
    bt      .use_default_frame
    bra     .frame_selected
    extu.b r8, r11
.use_default_frame:
    bra     .frame_selected
    extu.b r13, r11

    .global DAT_0601b76c
DAT_0601b76c:
    .2byte  0x1000

    .global DAT_0601b76e
DAT_0601b76e:
    .2byte  0x2000
_pool_frame_counter_ptr:
    .4byte  sym_0608600E
_pool_frame_count_table:
    .4byte  sym_0605DF20
_pool_memcpy_byte:
    .4byte  sym_06035228
_pool_tex_slot_table:
    .4byte  sym_0605DF23
_pool_input_state_ptr:
    .4byte  g_pad_state
_pool_tex_load_state:
    .4byte  sym_0605D4F8
.car_not_selected:
    extu.b r13, r11
.frame_selected:
    extu.b r11, r7
    extu.b r14, r2
    extu.b r14, r9
    mov r15, r6
    shll8 r7
    add #0x36, r2
    add #0x4, r6
    shll2 r7
    mov r2, r3
    add r9, r6
    shll2 r7
    shll2 r3
    mov.l   _pool_car_obj_table, r2
    shll r3
    add r3, r2
    mov.l r2, @r15
    mov.l @(4, r2), r3
    mov.b @r6, r6
    add r3, r7
    extu.b r6, r6
    mov r15, r3
    shll2 r6
    add #0x8, r3
    shll2 r6
    add r9, r3
    shll2 r6
    mov.b @r3, r2
    extu.b r2, r2
    add r2, r6
    shll r6
    mov.l @r15, r5
    mov.l @r5, r5
    mov.l   _pool_dlist_loader, r3
    jsr @r3
    mov #0x8, r4
    add #0x1, r14
    extu.b r14, r2
    cmp/ge r10, r2
    bf      .car_loop_top
    add #0xC, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
_pool_car_obj_table:
    .4byte  sym_06063750
_pool_dlist_loader:
    .4byte  sym_06028400
