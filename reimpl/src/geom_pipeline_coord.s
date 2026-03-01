
    .section .text.FUN_060173AC


    .global geom_pipeline_coord
    .type geom_pipeline_coord, @function
geom_pipeline_coord:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov #0x8, r11
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0x6C, r15
    mov.w   DAT_0601748a, r8
    mov r15, r12
    mov.l   _pool_globals_base, r14
    mov r15, r1
    mov.l   _pool_vtx_src_a, r2
    mov.l   _pool_fn_memcpy_byte, r3
    add #0x10, r12
    add #0x48, r1
    jsr @r3
    mov #0x24, r0
    mov r15, r1
    mov.l   _pool_vtx_src_b, r2
    mov.l   _pool_fn_memcpy_byte, r3
    add #0x10, r1
    jsr @r3
    mov #0x38, r0
    mov.l   _pool_seg_tbl_default, r13
    mov.l   _pool_demo_mode_flag, r0
    mov.l @r0, r0
    tst r0, r0
    bt      .L_060173EC
    mov.l   _pool_seg_tbl_demo, r13
.L_060173EC:
    mov.w @(2, r13), r0
    mov.w @r13, r6
    mov.w   DAT_0601748c, r10
    mov r0, r7
    extu.w r6, r6
    add r14, r10
    extu.w r7, r7
    mov.l @(4, r10), r5
    add r8, r5
    .byte   0xB1, 0xC1    /* bsr 0x06017784 (geom_computation) */
    mov.l @r10, r4
    mov r13, r7
    add #0x6, r7
    mov.l r7, @r15
    mov.w @(2, r7), r0
    mov.l @r15, r6
    mov.l @(4, r10), r5
    mov r0, r7
    mov.w @r6, r6
    add r8, r5
    extu.w r7, r7
    mov.w   DAT_0601748e, r0
    extu.w r6, r6
    .byte   0xB1, 0xB3    /* bsr 0x06017784 (geom_computation) */
    mov.l @(r0, r14), r4
    mov r13, r7
    add #0x12, r7
    mov.l r7, @r15
    mov.w @(2, r7), r0
    mov.l @r15, r6
    mov.l @(4, r10), r5
    mov r0, r7
    mov.w @r6, r6
    add r8, r5
    extu.w r7, r7
    mov.w   DAT_06017490, r0
    extu.w r6, r6
    .byte   0xB1, 0xA5    /* bsr 0x06017784 (geom_computation) */
    mov.l @(r0, r14), r4
    mov.l   _pool_car_array_base, r2
    mov.l r2, @r15
    mov r2, r3
    mov.w   DAT_06017492, r0
    mov.l @(r0, r3), r2
    mov.l r2, @(4, r15)
    mov.l   _pool_frame_counter, r4
    mov.l   _pool_max_frame_idx, r5
    mov.l @r4, r4
    cmp/ge r5, r4
    bf      .L_06017452
    mov r5, r4
.L_06017452:
    mov.l   _pool_race_event_flags, r0
    mov.l @r0, r0
    tst #0x1, r0
    bf      .L_06017464
    mov.l   _pool_frame_count_var, r4
    mov.l @r4, r4
    mov r4, r3
    shll2 r4
    add r3, r4
.L_06017464:
    mov.l   _pool_fn_anim_xform, r3
    jsr @r3
    nop
    mov r0, r6
    mov #0x0, r4
.L_0601746E:
    extu.b r4, r2
    mov r15, r3
    extu.b r4, r5
    shll r2
    add #0x48, r3
    add r6, r5
    add r3, r2
    mov.b @r5, r0
    extu.b r0, r0
    shll r0
    mov.w @(r0, r12), r0
    mov.w r0, @(4, r2)
    bra     .L_060174C8
    nop

    .global DAT_0601748a
DAT_0601748a:
    .2byte  0x3000

    .global DAT_0601748c
DAT_0601748c:
    .2byte  0x02D8

    .global DAT_0601748e
DAT_0601748e:
    .2byte  0x02E8

    .global DAT_06017490
DAT_06017490:
    .2byte  0x02E0

    .global DAT_06017492
DAT_06017492:
    .2byte  0x0240
_pool_globals_base:
    .4byte  sym_06063750
_pool_vtx_src_a:
    .4byte  sym_0605BC6C
_pool_fn_memcpy_byte:
    .4byte  sym_06035228
_pool_vtx_src_b:
    .4byte  sym_0605BC90
_pool_seg_tbl_default:
    .4byte  sym_06044B84
_pool_demo_mode_flag:
    .4byte  sym_0607EAE0
_pool_seg_tbl_demo:
    .4byte  sym_06044BB4
_pool_car_array_base:
    .4byte  sym_06078900
_pool_frame_counter:
    .4byte  sym_060786A4
_pool_max_frame_idx:
    .4byte  0x000927BF
_pool_race_event_flags:
    .4byte  sym_0607EBF4
_pool_frame_count_var:
    .4byte  sym_0607EBD0
_pool_fn_anim_xform:
    .4byte  anim_frame_transform
.L_060174C8:
    extu.b r4, r3
    mov r15, r2
    mov.b @r5, r1
    add #0x2, r3
    add #0x1, r4
    add #0x48, r2
    extu.b r1, r1
    shll r3
    shll r1
    add r2, r3
    add r12, r1
    mov.w @(28, r1), r0
    mov.w r0, @(16, r3)
    extu.b r4, r3
    cmp/ge r11, r3
    bf      .L_0601746E
    mov r13, r7
    mov r15, r4
    add #0xC, r7
    mov.l r7, @(8, r15)
    mov.w @(2, r7), r0
    mov.l @(8, r15), r6
    mov r0, r7
    mov.w @r6, r6
    extu.w r7, r7
    mov.w   DAT_060175b4, r0
    extu.w r6, r6
    mov.l @(r0, r14), r5
    add r8, r5
    .byte   0xB1, 0x3F    /* bsr 0x06017784 (geom_computation) */
    add #0x48, r4
    mov.l   _pool_fn_anim_xform_b, r3
    jsr @r3
    mov.l @(4, r15), r4
    mov r0, r6
    mov #0x0, r4
.L_06017510:
    extu.b r4, r2
    mov r15, r3
    extu.b r4, r5
    shll r2
    add #0x48, r3
    add r6, r5
    add r3, r2
    mov.b @r5, r0
    extu.b r4, r3
    extu.b r0, r0
    add #0x2, r3
    add #0x1, r4
    shll r0
    shll r3
    mov.w @(r0, r12), r0
    mov.w r0, @(4, r2)
    mov r15, r2
    mov.b @r5, r1
    add #0x48, r2
    extu.b r1, r1
    add r2, r3
    shll r1
    add r12, r1
    mov.w @(28, r1), r0
    mov.w r0, @(16, r3)
    extu.b r4, r3
    cmp/ge r11, r3
    bf      .L_06017510
    mov r13, r7
    mov r15, r4
    add #0x18, r7
    mov.l r7, @(4, r15)
    mov.w @(2, r7), r0
    mov.l @(4, r15), r6
    mov r0, r7
    mov.w @r6, r6
    extu.w r7, r7
    mov.w   DAT_060175b4, r0
    extu.w r6, r6
    mov.l @(r0, r14), r5
    add r8, r5
    .byte   0xB1, 0x0F    /* bsr 0x06017784 (geom_computation) */
    add #0x48, r4
    mov #0xA, r5
    mov.l @r15, r4
    mov.w   DAT_060175b6, r0
    mov.l   _pool_fn_model_lookup, r3
    mov.l @(r0, r4), r4
    add #0x1, r4
    mov r4, r1
    jsr @r3
    mov r5, r0
    mov r4, r1
    mov.l r0, @(4, r15)
    mov.l   _pool_fn_mem_store, r3
    jsr @r3
    mov r5, r0
    mov.l r0, @(8, r15)
    mov.l   _pool_demo_flag_b, r1
    mov.l @r1, r1
    tst r1, r1
    bt      .L_060175CC
    mov r13, r7
    add #0x1E, r7
    mov.l r7, @(4, r15)
    mov.w @(2, r7), r0
    mov.l @(4, r15), r6
    mov.w   DAT_060175b8, r5
    mov r0, r7
    mov.w @r6, r6
    add r14, r5
    extu.w r7, r7
    extu.w r6, r6
    mov.l r5, @r15
    mov.l @(4, r5), r5
    mov.w   DAT_060175ba, r3
    mov.l @r15, r4
    add r3, r5
    .byte   0xB0, 0xEA    /* bsr 0x06017784 (geom_computation) */
    mov.l @r4, r4
    bra     .L_06017714
    nop

    .global DAT_060175b4
DAT_060175b4:
    .2byte  0x02BC

    .global DAT_060175b6
DAT_060175b6:
    .2byte  0x0224

    .global DAT_060175b8
DAT_060175b8:
    .2byte  0x02F0

    .global DAT_060175ba
DAT_060175ba:
    .2byte  0x5000
_pool_fn_anim_xform_b:
    .4byte  anim_frame_transform
_pool_fn_model_lookup:
    .4byte  sym_06034FE0
_pool_fn_mem_store:
    .4byte  sym_06035C2C
_pool_demo_flag_b:
    .4byte  sym_0607EAE0
.L_060175CC:
    mov.w   DAT_06017692, r9
    mov #0xB, r3
    mov.w   _wpool_seg_struct_ofs, r10
    mov.l @r15, r4
    mov.w   DAT_06017696, r0
    mov.l @(r0, r4), r4
    add #0x1, r4
    cmp/ge r3, r4
    .word 0x0029
    xor #0x1, r0
    mov #0xD, r3
    cmp/gt r3, r4
    .word 0x0129
    or r1, r0
    tst r0, r0
    bt      .L_0601769E
    bra     .L_06017682
    mov.l @(8, r15), r0
.L_060175F0:
    mov r13, r7
    mov r14, r5
    add #0x2A, r7
    add r10, r5
    mov.l r7, @(12, r15)
    mov.w @(2, r7), r0
    mov.l @(12, r15), r6
    mov r0, r7
    mov.w @r6, r6
    extu.w r7, r7
    extu.w r6, r6
    mov.l r5, @r15
    mov.l @(4, r5), r5
    mov.l @r15, r4
    add r9, r5
    .byte   0xB0, 0xB9    /* bsr 0x06017784 (geom_computation) */
    mov.l @r4, r4
    bra     .L_060176BE
    nop
.L_06017616:
    mov r13, r7
    mov r14, r5
    add #0x2A, r7
    add r10, r5
    mov.l r7, @r15
    mov.w @(2, r7), r0
    mov.l @r15, r6
    mov.l @(4, r5), r5
    mov r0, r7
    mov.w @r6, r6
    add r9, r5
    extu.w r7, r7
    mov.w   DAT_06017698, r0
    extu.w r6, r6
    .byte   0xB0, 0xA7    /* bsr 0x06017784 (geom_computation) */
    mov.l @(r0, r14), r4
    bra     .L_060176BE
    nop
.L_0601763A:
    mov r13, r7
    mov r14, r5
    add #0x2A, r7
    add r10, r5
    mov.l r7, @r15
    mov.w @(2, r7), r0
    mov.l @r15, r6
    mov.l @(4, r5), r5
    mov r0, r7
    mov.w @r6, r6
    add r9, r5
    extu.w r7, r7
    mov.w   DAT_0601769a, r0
    extu.w r6, r6
    .byte   0xB0, 0x95    /* bsr 0x06017784 (geom_computation) */
    mov.l @(r0, r14), r4
    bra     .L_060176BE
    nop
.L_0601765E:
    mov r13, r7
    mov r14, r5
    add #0x2A, r7
    add r10, r5
    mov.l r7, @r15
    mov.w @(2, r7), r0
    mov.l @r15, r6
    mov.l @(4, r5), r5
    mov r0, r7
    mov.w @r6, r6
    add r9, r5
    extu.w r7, r7
    mov.w   DAT_0601769c, r0
    extu.w r6, r6
    .byte   0xB0, 0x83    /* bsr 0x06017784 (geom_computation) */
    mov.l @(r0, r14), r4
    bra     .L_060176BE
    nop
.L_06017682:
    cmp/eq #0x1, r0
    bt      .L_060175F0
    cmp/eq #0x2, r0
    bt      .L_06017616
    cmp/eq #0x3, r0
    bt      .L_0601763A
    bra     .L_0601765E
    nop

    .global DAT_06017692
DAT_06017692:
    .2byte  0x6000
_wpool_seg_struct_ofs:
    .2byte  0x0348

    .global DAT_06017696
DAT_06017696:
    .2byte  0x0224

    .global DAT_06017698
DAT_06017698:
    .2byte  0x0350

    .global DAT_0601769a
DAT_0601769a:
    .2byte  0x0358

    .global DAT_0601769c
DAT_0601769c:
    .2byte  0x0360
.L_0601769E:
    mov r13, r7
    mov r14, r5
    add #0x2A, r7
    add r10, r5
    mov.l r7, @r15
    mov.w @(2, r7), r0
    mov.l @r15, r6
    mov.l @(4, r5), r5
    mov r0, r7
    mov.w @r6, r6
    add r9, r5
    extu.w r7, r7
    mov.w   DAT_06017728, r0
    extu.w r6, r6
    .byte   0xB0, 0x63    /* bsr 0x06017784 (geom_computation) */
    mov.l @(r0, r14), r4
.L_060176BE:
    mov.l @(4, r15), r0
    tst r0, r0
    bt      .L_060176EC
    mov r13, r7
    add #0x1E, r7
    mov.l r7, @r15
    mov.w @(2, r7), r0
    mov.l @r15, r6
    mov.w   DAT_0601772c, r3
    mov.l @(4, r15), r4
    mov r0, r7
    mov.w @r6, r6
    add #0x5F, r4
    extu.w r7, r7
    mov.w   DAT_0601772a, r0
    extu.w r6, r6
    shll2 r4
    mov.l @(r0, r14), r5
    shll r4
    add r3, r5
    add r14, r4
    .byte   0xB0, 0x4C    /* bsr 0x06017784 (geom_computation) */
    mov.l @r4, r4
.L_060176EC:
    mov r13, r7
    add #0x24, r7
    mov.l r7, @r15
    mov.w @(2, r7), r0
    mov.l @r15, r6
    mov.w   DAT_0601772c, r3
    mov.l @(8, r15), r4
    mov r0, r7
    mov.w @r6, r6
    add #0x5F, r4
    extu.w r7, r7
    mov.w   DAT_0601772a, r0
    extu.w r6, r6
    shll2 r4
    mov.l @(r0, r14), r5
    shll r4
    add r3, r5
    add r14, r4
    .byte   0xB0, 0x38    /* bsr 0x06017784 (geom_computation) */
    mov.l @r4, r4
.L_06017714:
    add #0x6C, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global DAT_06017728
DAT_06017728:
    .2byte  0x0360

    .global DAT_0601772a
DAT_0601772a:
    .2byte  0x02FC

    .global DAT_0601772c
DAT_0601772c:
    .2byte  0x5000
