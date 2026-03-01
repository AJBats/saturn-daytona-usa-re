/* VERIFIED: friction_stub (0x0600D26A in this TU) called every physics frame during racing
 * Method: call-trace differential — 5 frames idle vs 5 frames with LEFT in race
 *   friction_stub: 117 calls during LEFT (baseline 39, +78) — part of player_physics_main pipeline
 * Date: 2026-02-28
 */

    .section .text.FUN_0600D12C


    .global collision_passive
    .type collision_passive, @function
collision_passive:
    mov.l r14, @-r15
    mov.l   .L_pool_cur_car_ptr, r5
    mov.w   DAT_0600d192, r0
    mov.l   .L_pool_separation_thresh, r6
    mov.l @r5, r5
    mov.l @(r0, r5), r4
    mov.w   .L_wpool_partner_b_offset, r0
    mov.l @(r0, r5), r14
    tst r14, r14
    bt      .L_no_partner_b
    mov.l @(16, r14), r7
    mov.l @(16, r5), r3
    mov.l @(24, r14), r2
    sub r3, r7
    add r2, r7
    mov.l @(24, r5), r3
    mov.l   .L_pool_close_thresh, r2
    sub r3, r7
    cmp/ge r2, r7
    bt      .L_partner_b_far_enough
    mov r14, r4
    bra     .L_apply_push
    mov.l @r15+, r14
.L_partner_b_far_enough:
    mov.l @(16, r4), r2
    mov.l @(16, r5), r3
    mov.l @(24, r4), r1
    sub r3, r2
    add r1, r2
    mov.l @(24, r5), r3
    mov r2, r5
    sub r3, r5
    cmp/ge r6, r5
    bt      .L_cars_separated
    bra     .L_apply_push
    mov.l @r15+, r14
.L_cars_separated:
    bra     .L_return_no_push
    nop
.L_no_partner_b:
    mov.l @(16, r4), r2
    mov.l @(16, r5), r3
    mov.l @(24, r4), r1
    sub r3, r2
    add r1, r2
    mov.l @(24, r5), r3
    mov r2, r5
    sub r3, r5
    cmp/ge r6, r5
    bt      .L_return_no_push
    bra     .L_apply_push
    mov.l @r15+, r14
.L_return_no_push:
    rts
    mov.l @r15+, r14

    .global DAT_0600d192
DAT_0600d192:
    .2byte  0x0118                      /* car struct offset: collision partner A pointer */
.L_wpool_partner_b_offset:
    .2byte  0x0234                      /* car struct offset: collision partner B pointer */
    .2byte  0xFFFF                      /* alignment padding */
.L_pool_cur_car_ptr:
    .4byte  sym_0607E940                /* &current_car_ptr — points to active car struct */
.L_pool_separation_thresh:
    .4byte  0x000F0000                  /* 15.0 in 16.16 fixed-point — diagonal separation threshold */
.L_pool_close_thresh:
    .4byte  0x00080000                  /* 8.0 in 16.16 fixed-point — close proximity threshold */
.L_apply_push:
    mov.l   .L_pool_self_car_ptr_b, r6
    mov.w   DAT_0600d1fa, r0
    mov.l @r6, r6
    mov.l @(r0, r4), r5
    mov.l @(r0, r6), r3
    mov r5, r7
    sub r3, r7
    mov.w   DAT_0600d1fc, r3
    cmp/ge r3, r7
    bf      .L_push_exit
    mov.w   DAT_0600d1fe, r3
    cmp/gt r3, r7
    bt      .L_push_exit
    mov.w   DAT_0600d1fe, r7
    mov.w   DAT_0600d200, r3
    cmp/gt r3, r5
    bt      .L_push_subtract
    bra     .L_push_clamp
    add r7, r5
.L_push_subtract:
    sub r7, r5
.L_push_clamp:
    cmp/pz r5
    bt      .L_push_check_max
    mov #0x0, r3
    mov.w   DAT_0600d202, r0
    bra     .L_push_set_timer
    mov.l r3, @(r0, r6)
.L_push_check_max:
    mov.w   DAT_0600d204, r3
    cmp/gt r3, r5
    bf      .L_push_store_result
    mov.w   DAT_0600d204, r3
    mov.w   DAT_0600d202, r0
    mov.l r3, @(r0, r6)
    bra     .L_push_set_timer
    nop
.L_push_store_result:
    mov.w   DAT_0600d202, r0
    mov.l r5, @(r0, r6)
.L_push_set_timer:
    mov.w   .L_wpool_collision_timer_val, r3
    mov.w   .L_wpool_timer_offset, r0
    mov.l r3, @(r0, r6)
    add #0x30, r0
    mov.l r4, @(r0, r6)
.L_push_exit:
    rts
    nop

    .global DAT_0600d1fa
DAT_0600d1fa:
    .2byte  0x01FC                      /* car struct offset: speed/heading field */

    .global DAT_0600d1fc
DAT_0600d1fc:
    .2byte  0xFD00                      /* -768 (signed) — lower bound for speed delta */

    .global DAT_0600d1fe
DAT_0600d1fe:
    .2byte  0x0300                      /* 768 — upper bound for speed delta / push magnitude */

    .global DAT_0600d200
DAT_0600d200:
    .2byte  0x0400                      /* 1024 — direction threshold for push direction */

    .global DAT_0600d202
DAT_0600d202:
    .2byte  0x01F8                      /* car struct offset: force/push accumulator field */

    .global DAT_0600d204
DAT_0600d204:
    .2byte  0x0800                      /* 2048 — maximum push value (clamp ceiling) */
.L_wpool_collision_timer_val:
    .2byte  0x0100                      /* 256 — collision timer duration (frames) */
.L_wpool_timer_offset:
    .2byte  0x0204                      /* car struct offset: collision timer / steering countdown */
    .2byte  0xFFFF                      /* alignment padding */
.L_pool_self_car_ptr_b:
    .4byte  sym_0607E940                /* &current_car_ptr (duplicate for push handler reach) */
    .4byte  0xD519D41A
    .4byte  0x90296552
    .4byte  0x6442035E
    .4byte  0x044E6643
    .4byte  0x36389323
    .4byte  0x36338B1C
    .4byte  0x93213637
    .4byte  0x8919901C
    .4byte  0x035E3347
    .4byte  0x8B01A001
    .4byte  0x74F07410
    .4byte  0x44118903
    .4byte  0xE3009015
    .4byte  0xA00A0536
    .4byte  0x93133437
    .4byte  0x8B049310
    .4byte  0x900E0536
    .4byte  0xA0020009
    .4byte  0x900A0546
    .4byte  0xE3409009
    .4byte  0x0536000B
    .2byte  0x0009

    .global friction_stub
friction_stub:
    rts
    nop

    .global DAT_0600d26a
DAT_0600d26a:
    .2byte  0x01FC                      /* car struct offset: speed field (for standalone push) */

    .global DAT_0600d26c
DAT_0600d26c:
    .2byte  0xFD00                      /* -768 (signed) — lower bound (standalone push pool) */

    .global DAT_0600d26e
DAT_0600d26e:
    .2byte  0x0300                      /* 768 — upper bound / push magnitude (standalone pool) */

    .global DAT_0600d270
DAT_0600d270:
    .2byte  0x01F8                      /* car struct offset: force field (standalone push pool) */

    .global DAT_0600d272
DAT_0600d272:
    .2byte  0x0800                      /* 2048 — max push value (standalone push pool) */
    .4byte  0x0204FFFF                  /* 0x0204 = timer offset, 0xFFFF = padding (standalone pool) */
    .4byte  sym_0607E940                /* &current_car_ptr (standalone push: self car) */
    .4byte  sym_0607E944                /* &car_base_ptr (standalone push: other car) */

    .global sym_0600D280
sym_0600D280:
    mov.l r12, @-r15
    sts.l macl, @-r15
    mov.l   .L_pool_car_array_base, r12
    mov.w   .L_wpool_car_stride, r1
    mov #0x28, r7
    mov.l   .L_pool_car_count_ptr, r5
    mov #0x0, r4
    mov.l   .L_pool_list_a_base, r6
    bra     .L_clear_list_a_test
    mov r4, r0
.L_clear_list_a_body:
    mov.l r4, @r6
    add #0x4, r6
    mov.l r4, @r6
    add #0x2, r0
    add #0x4, r6
.L_clear_list_a_test:
    cmp/hs r7, r0
    bf      .L_clear_list_a_body
    mov.l   .L_pool_list_b_base, r6
    bra     .L_clear_list_b_test
    mov r4, r0
.L_clear_list_b_body:
    mov.l r4, @r6
    add #0x4, r6
    mov.l r4, @r6
    add #0x2, r0
    add #0x4, r6
.L_clear_list_b_test:
    cmp/hs r7, r0
    bf      .L_clear_list_b_body
    mov.l   .L_pool_scratch_base, r6
    mov.l r4, @r6
    add #0x4, r6
    mov.l r4, @r6
    add #0x4, r6
    mov.l r4, @r6
    mov.l   .L_pool_list_a_base, r0
    bra     .L_fill_list_a_test
    mov #0x1, r6
.L_fill_list_a_body:
    mov r0, r2
    add #0x4, r0
    mov.l @r5, r3
    sub r6, r3
    mul.l r1, r3
    sts macl, r3
    add r12, r3
    mov.l r3, @r2
    add #0x1, r6
.L_fill_list_a_test:
    mov.l @r5, r2
    cmp/hi r2, r6
    bf      .L_fill_list_a_body
    mov.l   .L_pool_list_b_base, r0
    bra     .L_fill_list_b_test
    mov #0x1, r6
.L_fill_list_b_body:
    mov r0, r2
    add #0x4, r0
    mov.l @r5, r3
    sub r6, r3
    mul.l r1, r3
    sts macl, r3
    add r12, r3
    mov.l r3, @r2
    add #0x1, r6
.L_fill_list_b_test:
    mov.l @r5, r2
    cmp/hi r2, r6
    bf      .L_fill_list_b_body
    lds.l @r15+, macl
    rts
    mov.l @r15+, r12
.L_wpool_car_stride:
    .2byte  0x0268                      /* car struct stride (616 bytes) */
    .2byte  0xFFFF                      /* alignment padding */
.L_pool_car_array_base:
    .4byte  sym_06078900                /* car struct array base address */
.L_pool_car_count_ptr:
    .4byte  sym_0607EA98                /* &total_car_count (long) */
.L_pool_list_a_base:
    .4byte  sym_0607E94C                /* car_ptr_list_a — primary sorted pointer array */
.L_pool_list_b_base:
    .4byte  sym_0607E9EC                /* car_ptr_list_b — secondary sorted pointer array */
.L_pool_scratch_base:
    .4byte  sym_0607EA8C                /* race position scratch state (3 longs) */
