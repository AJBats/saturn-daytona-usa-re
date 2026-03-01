/* VERIFIED: called during mode select C press, clears init flag
 * Method: watchpoint on sym_06085FF1 (init pending flag) during C press on Mode Select
 *   PC=0x06019A16 (track_seg_phys_init+0xEA) writes 0x00010000 -> 0x00000000
 *   PR=0x06019A0E (track_seg_phys_init+0xE2, within function body)
 *   Called by car_select_setup; clears flag after loading display lists and physics.
 * Date: 2026-02-28
 */

    .section .text.FUN_06019928


    .global track_seg_phys_init
    .type track_seg_phys_init, @function

track_seg_phys_init:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0x4, r15

    mov.l   .L_ptr_car_dlist_table, r9
    mov.l   .L_ptr_car_slot_params, r11
    mov.l   .L_ptr_disp_elem_renderer, r12
    mov.w   .L_const_base_index, r13
    mov.l   .L_ptr_init_pending_flag, r0
    mov.b @r0, r0
    cmp/eq #0x1, r0
    bf/s    .L_epilogue
    mov #0x8, r10

    mov.l   .L_ptr_render_mode_flags, r4
    mov.l @r4, r0
    or #0x4, r0
    mov.l r0, @r4

    mov #0x0, r14
.L_car_loop:
    extu.b r14, r0
    mov r13, r6
    extu.b r14, r8
    shll2 r0
    shll r8
    mov.l @(r0, r9), r7
    add r11, r8
    mov.b @(1, r8), r0
    mov.b @r8, r3
    mov r0, r5
    extu.b r3, r3
    extu.b r5, r5
    shll2 r5
    shll2 r5
    shll2 r5
    add r3, r5
    shll r5
    jsr @r12
    mov #0x8, r4
    add #0x1, r14
    extu.b r14, r2
    cmp/ge r10, r2
    bf      .L_car_loop

    mov r13, r6
    mov.l   .L_ptr_car_course_index, r14
    mov.b @r14, r0
    mov.b @r14, r5
    shll2 r0
    shll r5
    mov.l @(r0, r9), r7
    add r11, r5
    mov.l r5, @r15
    mov.b @(1, r5), r0
    mov.l @r15, r3
    mov r0, r5
    mov.b @r3, r3
    extu.b r5, r5
    extu.b r3, r3
    shll2 r5
    shll2 r5
    shll2 r5
    add r3, r5
    shll r5
    jsr @r12
    mov #0xC, r4

    mov r13, r6
    mov.b @r14, r5
    mov.l   .L_ptr_secondary_dlist_base, r7
    shll r5
    add r11, r5
    mov.b @(1, r5), r0
    mov r0, r5
    extu.b r5, r5
    shll2 r5
    shll2 r5
    shll2 r5
    add #0x1, r5
    shll r5
    jsr @r12
    mov #0xC, r4

    mov.b @r14, r0
    cmp/eq #0x6, r0
    bt      .L_call_physics_init
    mov.l   .L_ptr_car_display_data, r7
    mov r13, r6
    mov r11, r3
    mov.l @r7, r7
    add #0xC, r3
    mov.l r11, @r15
    mov.b @(13, r11), r0
    mov.b @r3, r3
    mov r0, r5
    extu.b r3, r3
    extu.b r5, r5
    shll2 r5
    shll2 r5
    shll2 r5
    add r3, r5
    add #0xD, r5
    shll r5
    jsr @r12
    mov #0xC, r4

.L_call_physics_init:
    .byte   0xB0, 0xE5    /* bsr 0x06019BC8 (external) */
    nop
    .byte   0xB1, 0xDB    /* bsr 0x06019DB8 (external) */
    nop
    .byte   0xB2, 0xD6    /* bsr 0x06019FB2 (external) */
    nop
    .byte   0xB6, 0x2A    /* bsr 0x0601A65E (external) */
    nop

    mov #0x0, r2
    mov.l   .L_ptr_init_pending_flag, r3
    mov.b r2, @r3

.L_epilogue:
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

.L_const_base_index:
    .2byte  0x0090                      /* 144 = display list base index constant */
    .2byte  0xFFFF                      /* padding to align pool */
.L_ptr_car_dlist_table:
    .4byte  sym_0605D294                /* car display list pointer table (8 entries) */
.L_ptr_car_slot_params:
    .4byte  sym_06049AFC                /* car slot param table (2 bytes/entry) */
.L_ptr_disp_elem_renderer:
    .4byte  sym_060284AE                /* display element renderer function */
.L_ptr_init_pending_flag:
    .4byte  sym_06085FF1                /* init pending flag (byte, 1 = pending) */
.L_ptr_render_mode_flags:
    .4byte  sym_0605B6D8                /* render mode flags (32-bit) */
.L_ptr_car_course_index:
    .4byte  sym_06085FF0                /* current car/course index (byte, 0-7) */
.L_ptr_secondary_dlist_base:
    .4byte  sym_06049E44                /* secondary display list base (variant +1) */
.L_ptr_car_display_data:
    .4byte  sym_0605D4F0                /* car display data pointer (indirect) */
