
    .section .text.FUN_06014D2C


    .global ai_waypoint_pathfind
    .type ai_waypoint_pathfind, @function
ai_waypoint_pathfind:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov #0x10, r12
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov #0x8, r9
    mov.l r8, @-r15
    sts.l pr, @-r15
    mov.l   .L_pool_06014DE8, r8
    mov.l   .L_pool_06014DEC, r11
    mov.l   .L_pool_06014DF0, r14
    mov.l   .L_pool_06014DF4, r4
    mov.b @r4, r3
    tst r3, r3
    bt/s    .L_check_traffic_light
    mov #0x1, r13
    bra     .L_post_pathfind
    nop
.L_check_traffic_light:
    mov.l   .L_pool_06014DF8, r3
    mov.w @r3, r2
    mov.w   DAT_06014de4, r3
    extu.w r2, r2
    and r3, r2
    tst r2, r2
    bf      .L_race_flag_dispatch
    bra     .L_post_pathfind
    nop
.L_race_flag_dispatch:
    mov #0x4, r7
    mov.l   .L_pool_06014DFC, r3
    mov.l @r3, r3
    and r13, r3
    tst r3, r3
    bf/s    .L_path_b_race_complete
    mov #0xB, r6
    mov.w @r14, r5
    extu.w r5, r5
    cmp/gt r6, r5
    .word 0x0029
    mov #0x16, r3
    cmp/ge r3, r5
    .word 0x0129
    add #-0x1, r1
    neg r1, r1
    and r1, r0
    tst r0, r0
    bt      .L_path_a_wide_range
    exts.b r13, r3
    mov.b r3, @r4
    extu.b r9, r10
.L_path_a_handler_loop:
    mov.l   .L_pool_06014E00, r3
    jsr @r3
    extu.b r10, r4
    add #0x1, r10
    extu.b r10, r2
    cmp/ge r12, r2
    bf      .L_path_a_handler_loop
    exts.w r13, r2
    mov.w r2, @r8
    mov #0x14, r2
    mov.w @r14, r3
    extu.w r3, r3
    cmp/gt r2, r3
    bf/s    .L_path_a_write_phase
    mov #0x20, r4
    mov #0x22, r4
.L_path_a_write_phase:
    extu.b r4, r4
    bra     .L_post_pathfind
    mov.w r4, @r14
.L_path_a_wide_range:
    mov.w @r14, r5
    extu.w r5, r5
    cmp/ge r7, r5
    .word 0x0029
    mov #0x16, r3
    cmp/ge r3, r5
    .word 0x0129
    add #-0x1, r1
    neg r1, r1
    and r1, r0
    tst r0, r0
    bt      .L_path_a_skip
    mov.b r13, @r4
    exts.w r13, r2
    mov.w r2, @r8
    mov.w @r14, r3
    extu.w r3, r3
    add #0x12, r3
    extu.w r3, r3
    mov.w r3, @r14
.L_path_a_skip:
    bra     .L_post_pathfind
    nop

    .global DAT_06014de4
DAT_06014de4:
    .2byte  0x0800                        /* traffic light state bit 11 mask */
    .2byte  0xFFFF
.L_pool_06014DE8:
    .4byte  sym_06085F94               /* waypoint state word (16-bit) */
.L_pool_06014DEC:
    .4byte  sym_06063F64               /* per-slot data table base */
.L_pool_06014DF0:
    .4byte  sym_06085F90               /* waypoint phase counter (16-bit) */
.L_pool_06014DF4:
    .4byte  sym_06085F89               /* waypoint disable flag (byte) */
.L_pool_06014DF8:
    .4byte  sym_06063D9A               /* traffic light state register */
.L_pool_06014DFC:
    .4byte  sym_0607EBF4               /* race complete flag (bit 0 checked) */
.L_pool_06014E00:
    .4byte  sym_060172E4               /* waypoint handler function */
.L_path_b_race_complete:
    mov.w @r14, r5
    extu.w r5, r5
    cmp/gt r6, r5
    .word 0x0029
    mov #0x17, r3
    cmp/ge r3, r5
    .word 0x0129
    add #-0x1, r1
    neg r1, r1
    and r1, r0
    tst r0, r0
    bt      .L_path_b_wide_range
    exts.b r13, r3
    mov.b r3, @r4
    extu.b r9, r10
.L_path_b_handler_loop:
    mov.l   .L_pool_06014F14, r3
    jsr @r3
    extu.b r10, r4
    add #0x1, r10
    extu.b r10, r2
    cmp/ge r12, r2
    bf      .L_path_b_handler_loop
    exts.w r13, r2
    mov.w r2, @r8
    mov #0x14, r2
    mov.w @r14, r3
    extu.w r3, r3
    cmp/gt r2, r3
    bf/s    .L_path_b_write_phase
    mov #0x23, r4
    mov #0x26, r4
.L_path_b_write_phase:
    extu.b r4, r4
    bra     .L_post_pathfind
    mov.w r4, @r14
.L_path_b_wide_range:
    mov.w @r14, r5
    extu.w r5, r5
    cmp/ge r7, r5
    .word 0x0029
    mov #0x17, r3
    cmp/ge r3, r5
    .word 0x0129
    add #-0x1, r1
    neg r1, r1
    and r1, r0
    tst r0, r0
    bt      .L_post_pathfind
    mov.b r13, @r4
    exts.w r13, r2
    mov.w r2, @r8
    mov.w @r14, r3
    extu.w r3, r3
    add #0x13, r3
    extu.w r3, r3
    mov.w r3, @r14
.L_post_pathfind:
    mov.l   .L_pool_06014F18, r0
    mov.b @r0, r0
    tst r0, r0
    bt      .L_skip_compact
    mov.l   .L_pool_06014F1C, r3
    jsr @r3
    nop
.L_skip_compact:
    .byte   0xB0, 0x59    /* bsr 0x06014F34 (external) -- post-pathfind handler */
    nop
    mov.l   .L_pool_06014F20, r3
    jsr @r3
    nop
    mov.l   .L_pool_06014F24, r5
    mov #0x0, r4
    mov.l @r5, r5
    mov r5, r10
    add #0x6, r10
    shll2 r10
    shll r10
    add r11, r10
.L_slot_loop:
    extu.b r4, r6
    mov.l   .L_pool_06014F28, r2
    mov r6, r3
    shll2 r6
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r6
    exts.w r6, r6
    add r2, r6
    mov.l @(44, r6), r6
    tst r6, r6
    .word 0x0029
    xor #0x1, r0
    mov.l   .L_pool_06014F2C, r3
    cmp/eq r3, r6
    .word 0x0129
    add #-0x1, r1
    mov.l   .L_pool_06014F30, r3
    neg r1, r1
    and r1, r0
    cmp/eq r3, r6
    .word 0x0129
    add #-0x1, r1
    neg r1, r1
    and r1, r0
    tst r0, r0
    bt      .L_slot_inactive_flags
    extu.b r4, r3
    add r5, r3
    shll2 r3
    shll r3
    add r11, r3
    mov #0x44, r2
    mov r2, r0
    mov.w r0, @(6, r3)
    bra     .L_slot_write_flag_b
    mov #0x48, r0
.L_slot_inactive_flags:
    extu.b r4, r2
    add r5, r2
    shll2 r2
    shll r2
    add r11, r2
    mov #0x4C, r0
    mov.w r0, @(6, r2)
    mov #0x50, r3
    mov r3, r0
.L_slot_write_flag_b:
    add #0x1, r4
    extu.b r4, r3
    cmp/ge r9, r3
    bf/s    .L_slot_loop
    mov.w r0, @(6, r10)
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .2byte  0xFFFF
.L_pool_06014F14:
    .4byte  sym_060172E4               /* waypoint handler (dup for reach) */
.L_pool_06014F18:
    .4byte  sym_06085F8A               /* object compaction needed flag (byte) */
.L_pool_06014F1C:
    .4byte  obj_data_compact           /* object data compaction function */
.L_pool_06014F20:
    .4byte  vdp2_util_loop             /* VDP2 utility loop */
.L_pool_06014F24:
    .4byte  sym_06085F98               /* active slot index (ptr, dereferenced) */
.L_pool_06014F28:
    .4byte  sym_06084FC8               /* slot data array base */
.L_pool_06014F2C:
    .4byte  0x00008000                  /* 0.5 (16.16 fixed-point) */
.L_pool_06014F30:
    .4byte  0x00010000                  /* 1.0 (16.16 fixed-point) */
