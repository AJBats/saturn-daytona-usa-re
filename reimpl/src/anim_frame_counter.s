
    .section .text.FUN_06005928


    .global anim_frame_counter
    .type anim_frame_counter, @function
anim_frame_counter:
    mov.l r14, @-r15
    mov.l r13, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.w   DAT_060059da, r13
    mov.l   _pool_car_array_base, r4
    mov.l   _pool_anim_countdown, r5
    mov.l @r5, r3
    cmp/pl r3
    bf/s    .L_06005A18
    mov.l @r4, r4
    mov.l @r5, r3
    add #-0x1, r3
    mov.l r3, @r5
    mov.w   DAT_060059dc, r0
    mov.l @(r0, r4), r0
    tst r0, r0
    bt      .L_06005A18
    mov.l   _pool_race_event_bits, r0
    mov.l @r0, r0
    tst r0, r0
    bf      .L_06005A18
    mov.l @r5, r0
    tst #0x2, r0
    bt      .L_060059BA
    mov.w   DAT_060059de, r0
    mov.l   _pool_frame_index_max, r5
    mov.l @(r0, r4), r14
    cmp/gt r5, r14
    bf      .L_06005966
    mov r5, r14
.L_06005966:
    mov.w   DAT_060059e0, r0
    mov.l @(r0, r4), r2
    cmp/eq r2, r14
    bf      .L_0600598A
    mov.l   _pool_dlist_entry_a, r2
    mov r13, r6
    mov.l r2, @r15
    mov r2, r7
    mov r2, r5
    mov.w   DAT_060059e2, r3
    mov.l @(4, r7), r7
    mov.l @r5, r5
    add r3, r7
    mov.l   _pool_dlist_loader, r3
    jsr @r3
    mov #0x8, r4
    bra     .L_060059A2
    nop
.L_0600598A:
    mov r13, r6
    mov.l   _pool_dlist_entry_b, r2
    mov.l r2, @r15
    mov r2, r7
    mov r2, r5
    mov.w   DAT_060059e2, r3
    mov.l @(4, r7), r7
    mov.l @r5, r5
    add r3, r7
    mov.l   _pool_dlist_loader, r3
    jsr @r3
    mov #0x8, r4
.L_060059A2:
    .byte   0xB2, 0x17    /* bsr 0x06005DD4 (anim_frame_transform) */
    mov r14, r4
    mov r0, r7
    mov #0x78, r6
    mov.w   DAT_060059e4, r5
    mov #0x8, r4
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    mov.l   _pool_geom_dispatch_final, r3
    jmp @r3
    mov.l @r15+, r14
.L_060059BA:
    mov r13, r5
    mov.l   _pool_geom_render_dispatch, r3
    mov.l   _pool_static_data_b, r7
    mov.w   DAT_060059e6, r6
    jsr @r3
    mov #0x8, r4
    mov.l   _pool_static_data_a, r7
    mov.w   _wpool_static_size, r6
    mov.w   DAT_060059e4, r5
    mov #0x8, r4
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    mov.l   _pool_geom_dispatch_final, r3
    jmp @r3
    mov.l @r15+, r14


    .global DAT_060059da
DAT_060059da:
    .2byte  0x05A4                          /* display list size parameter */

    .global DAT_060059dc
DAT_060059dc:
    .2byte  0x021C                          /* car struct offset: anim_enabled */

    .global DAT_060059de
DAT_060059de:
    .2byte  0x0220                          /* car struct offset: current_frame */

    .global DAT_060059e0
DAT_060059e0:
    .2byte  0x0240                          /* car struct offset: target_frame */

    .global DAT_060059e2
DAT_060059e2:
    .2byte  0x7000                          /* VRAM base offset for dlist copy */

    .global DAT_060059e4
DAT_060059e4:
    .2byte  0x061C                          /* render size parameter */

    .global DAT_060059e6
DAT_060059e6:
    .2byte  0x5000                          /* render region size (static path) */
_wpool_static_size:
    .2byte  0x0090                          /* static element size */
    .2byte  0xFFFF                          /* pool alignment padding */


_pool_car_array_base:
    .4byte  sym_0607E944                    /* &car_array_base_ptr */
_pool_anim_countdown:
    .4byte  sym_0607EAC0                    /* &anim_countdown_timer (32-bit) */
_pool_race_event_bits:
    .4byte  sym_0607EBF4                    /* &race_event_bitfield */
_pool_frame_index_max:
    .4byte  0x000927BF                      /* max frame index (599,999) */
_pool_dlist_entry_a:
    .4byte  sym_06063810                    /* display list entry A (frame==target) */
_pool_dlist_loader:
    .4byte  sym_06028400                    /* display_list_loader function */
_pool_dlist_entry_b:
    .4byte  sym_06063818                    /* display list entry B (frame!=target) */
_pool_geom_dispatch_final:
    .4byte  sym_060284AE                    /* geom_dispatch_final (tail call) */
_pool_static_data_b:
    .4byte  sym_0605ACE5                    /* static rendering data B */
_pool_geom_render_dispatch:
    .4byte  sym_060283E0                    /* geom_render_dispatch function */
_pool_static_data_a:
    .4byte  sym_0605ACDD                    /* static rendering data A */


.L_06005A18:
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
