
    .section .text.FUN_060201B8


    .global obj_pool_alloc
    .type obj_pool_alloc, @function
obj_pool_alloc:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    sts.l pr, @-r15
    mov.l   .L_pool_obj_pos_counter, r13
    mov.l   .L_pool_obj_active_count, r14
    mov.l   .L_pool_btn_state, r3
    mov.w @r3, r2
    mov.w   .L_w_start_btn_mask, r3
    extu.w r2, r2
    and r3, r2
    tst r2, r2
    bt      .L_start_not_pressed
    mov #0x1, r3
    mov.l   .L_pool_lap_counter, r2
    mov.w r3, @r2
.L_start_not_pressed:
    mov.l   .L_pool_obj_type_table, r12
    mov #0x14, r2
    mov.w @r14, r3
    extu.w r3, r3
    cmp/gt r2, r3
    bt      .L_exit_alloc
    mov.w @r13, r2
    extu.w r2, r2
    tst r2, r2
    bf      .L_exit_alloc
.L_alloc_loop:
    .byte   0xB6, 0x26    /* bsr 0x06020E3C (external) */ ! call obj_state_manager — returns slot index in r0
    mov #0x0, r4
    extu.w r0, r4
    extu.w r4, r0
    cmp/eq #0xF, r0
    bt      .L_exit_alloc
    mov r4, r5
    mov r4, r3
    mov.l   .L_pool_slot_array_base, r2
    mov.w @r14, r0
    shll2 r5
    shll2 r3
    extu.w r0, r0
    shll2 r3
    shll2 r3
    add r3, r5
    exts.w r5, r5
    mov r0, r3
    add r2, r5
    shll r0
    add r3, r0
    shll r0
    mov.w @(r0, r12), r2
    mov.b r2, @r5
    mov.w @r14, r3
    extu.w r3, r3
    mov r3, r2
    shll r3
    add r2, r3
    shll r3
    add r12, r3
    mov.w @(4, r3), r0
    mov r0, r3
    mov #0x40, r0
    mov.b r3, @(r0, r5)
    mov.w @r14, r3
    extu.w r3, r3
    mov r3, r2
    shll r3
    add r2, r3
    shll r3
    add r12, r3
    mov.w @(2, r3), r0
    mov r0, r1
    mov.w r1, @r13
    mov.w @r14, r3
    add #0x1, r3
    mov.w r3, @r14
    mov.w @r13, r2
    extu.w r2, r2
    tst r2, r2
    bf      .L_exit_alloc
    bra     .L_alloc_loop
    nop
.L_exit_alloc:
    mov.w @r13, r2
    add #-0x1, r2
    .byte   0xB5, 0x73    /* bsr 0x06020D46 (external) */ ! call obj_state_serializer — record state
    mov.w r2, @r13
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    .byte   0xA0, 0x0D    /* bra 0x06020284 (external) */ ! tail-call obj_pool_deallocator
    mov.l @r15+, r14
.L_w_start_btn_mask:
    .2byte  0x0800                         /* [HIGH] start-button bitmask (bit 11) */
.L_pool_obj_pos_counter:
    .4byte  sym_06087808               /* [MEDIUM] position counter (word) */
.L_pool_obj_active_count:
    .4byte  sym_06087806               /* [MEDIUM] active object count (word) */
.L_pool_btn_state:
    .4byte  sym_06063D9A               /* [HIGH] new button presses (edge-triggered) */
.L_pool_lap_counter:
    .4byte  sym_0608780A               /* [MEDIUM] lap counter (word) */
.L_pool_obj_type_table:
    .4byte  sym_0605F4A8               /* [MEDIUM] object type/param table (6 bytes/row) */
.L_pool_slot_array_base:
    .4byte  sym_0608782C               /* [MEDIUM] object slot array base */
