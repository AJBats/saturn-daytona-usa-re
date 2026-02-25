/* anim_frame_counter -- L3 assembly (SH-2 mnemonics)
 * Translation unit: 0x06005928 - 0x06005A22
 *
 * Per-frame animation timing and display list submission.
 * Called every frame from the per-frame update chain (FUN_060058FA).
 *
 * Decrements an animation countdown timer (sym_0607EAC0). While the
 * countdown is positive and animation is enabled (car struct +0x021C),
 * the race event bitfield (sym_0607EBF4) must be zero to proceed.
 *
 * Two rendering paths based on bit 1 of the countdown value:
 *   Bit 1 SET (active anim):
 *     - Reads current frame index from car struct +0x0220, clamps to
 *       max 599,999 (0x927BF).
 *     - If frame == target (+0x0240): loads display list entry A
 *       (sym_06063810); otherwise entry B (sym_06063818).
 *     - Calls display_list_loader (sym_06028400) with mode 0x8.
 *     - BSR to anim_frame_transform (0x06005DD4) for frame computation.
 *     - Tail-calls geom_dispatch_final (sym_060284AE) with render params.
 *   Bit 1 CLEAR (idle/static):
 *     - Calls geom_render_dispatch (sym_060283E0) with static data
 *       pointers (sym_0605ACE5, sym_0605ACDD).
 *     - Tail-calls geom_dispatch_final (sym_060284AE).
 */

    .section .text.FUN_06005928


    .global anim_frame_counter
    .type anim_frame_counter, @function
anim_frame_counter:
    mov.l r14, @-r15             ! save r14
    mov.l r13, @-r15             ! save r13
    sts.l pr, @-r15              ! save return address
    add #-0x4, r15               ! allocate 4 bytes on stack
    mov.w   DAT_060059da, r13    ! r13 = 0x05A4 (display list size param)
    mov.l   _pool_car_array_base, r4 ! r4 = &car_array_base_ptr (sym_0607E944)
    mov.l   _pool_anim_countdown, r5 ! r5 = &anim_countdown (sym_0607EAC0)
    mov.l @r5, r3                ! r3 = anim_countdown value
    cmp/pl r3                    ! test countdown > 0
    bf/s    .L_early_exit        ! if countdown <= 0: exit (nothing to animate)
    mov.l @r4, r4                ! r4 = car_array_base (delay slot: always exec)
    mov.l @r5, r3                ! r3 = anim_countdown (re-read)
    add #-0x1, r3                ! r3-- (decrement countdown)
    mov.l r3, @r5                ! store decremented countdown
    mov.w   DAT_060059dc, r0     ! r0 = 0x021C (car struct anim_enabled offset)
    mov.l @(r0, r4), r0          ! r0 = car[+0x021C] (animation enabled field)
    tst r0, r0                   ! test anim_enabled == 0
    bt      .L_early_exit        ! if animation disabled: exit
    mov.l   _pool_race_event_bits, r0 ! r0 = &race_event_bitfield (sym_0607EBF4)
    mov.l @r0, r0                ! r0 = race_event_bitfield value
    tst r0, r0                   ! test race_events == 0
    bf      .L_early_exit        ! if any race events active: exit
    mov.l @r5, r0                ! r0 = anim_countdown (current value)
    tst #0x2, r0                 ! test bit 1 of countdown
    bt      .L_static_path       ! if bit 1 clear: take static rendering path
    /* --- Active animation path (bit 1 set) --- */
    mov.w   DAT_060059de, r0    ! r0 = 0x0220 (car struct frame_index offset)
    mov.l   _pool_frame_index_max, r5 ! r5 = 0x927BF (max frame: 599,999)
    mov.l @(r0, r4), r14        ! r14 = car[+0x0220] (current frame index)
    cmp/gt r5, r14              ! test frame_index > max
    bf      .L_frame_clamped    ! if frame_index <= max: skip clamp
    mov r5, r14                 ! r14 = max (clamp to 599,999)
.L_frame_clamped:
    mov.w   DAT_060059e0, r0    ! r0 = 0x0240 (car struct target_frame offset)
    mov.l @(r0, r4), r2         ! r2 = car[+0x0240] (target frame)
    cmp/eq r2, r14              ! test current_frame == target_frame
    bf      .L_use_entry_b      ! if not equal: use display list entry B
    /* frame == target: use display list entry A (sym_06063810) */
    mov.l   _pool_dlist_entry_a, r2 ! r2 = &dlist_entry_a (sym_06063810)
    mov r13, r6                 ! r6 = 0x05A4 (display list size)
    mov.l r2, @r15              ! stack[0] = &dlist_entry_a
    mov r2, r7                  ! r7 = &dlist_entry_a (for field access)
    mov r2, r5                  ! r5 = &dlist_entry_a (for field access)
    mov.w   DAT_060059e2, r3    ! r3 = 0x7000 (VRAM base offset)
    mov.l @(4, r7), r7          ! r7 = dlist_entry_a.field4 (src base)
    mov.l @r5, r5               ! r5 = dlist_entry_a.field0 (src ptr)
    add r3, r7                  ! r7 = src_base + 0x7000 (VRAM dest)
    mov.l   _pool_dlist_loader, r3 ! r3 = &display_list_loader (sym_06028400)
    jsr @r3                     ! call display_list_loader(r4=0x8, r5, r6, r7)
    mov #0x8, r4                ! r4 = 0x8 (delay slot: copy mode)
    bra     .L_after_dlist_load ! skip entry B path
    nop                         ! delay slot
.L_use_entry_b:
    /* frame != target: use display list entry B (sym_06063818) */
    mov r13, r6                 ! r6 = 0x05A4 (display list size)
    mov.l   _pool_dlist_entry_b, r2 ! r2 = &dlist_entry_b (sym_06063818)
    mov.l r2, @r15              ! stack[0] = &dlist_entry_b
    mov r2, r7                  ! r7 = &dlist_entry_b (for field access)
    mov r2, r5                  ! r5 = &dlist_entry_b (for field access)
    mov.w   DAT_060059e2, r3    ! r3 = 0x7000 (VRAM base offset)
    mov.l @(4, r7), r7          ! r7 = dlist_entry_b.field4 (src base)
    mov.l @r5, r5               ! r5 = dlist_entry_b.field0 (src ptr)
    add r3, r7                  ! r7 = src_base + 0x7000 (VRAM dest)
    mov.l   _pool_dlist_loader, r3 ! r3 = &display_list_loader (sym_06028400)
    jsr @r3                     ! call display_list_loader(r4=0x8, r5, r6, r7)
    mov #0x8, r4                ! r4 = 0x8 (delay slot: copy mode)
.L_after_dlist_load:
    /* Both entry paths converge here — transform frame and tail-call */
    .byte   0xB2, 0x17    /* bsr 0x06005DD4 (anim_frame_transform) */
    mov r14, r4              ! r4 = clamped frame index (delay slot: arg)
    mov r0, r7               ! r7 = transform result (return value)
    mov #0x78, r6            ! r6 = 0x78 (render offset param)
    mov.w   DAT_060059e4, r5 ! r5 = 0x061C (render size param)
    mov #0x8, r4             ! r4 = 0x8 (render mode)
    add #0x4, r15            ! deallocate stack frame
    lds.l @r15+, pr          ! restore return address
    mov.l @r15+, r13         ! restore r13
    mov.l   _pool_geom_dispatch_final, r3 ! r3 = &geom_dispatch_final (sym_060284AE)
    jmp @r3                  ! tail-call geom_dispatch_final(r4, r5, r6, r7)
    mov.l @r15+, r14         ! restore r14 (delay slot)
.L_static_path:
    /* Bit 1 clear — static/idle rendering with fixed data pointers */
    mov r13, r5              ! r5 = 0x05A4 (display list size param)
    mov.l   _pool_geom_render_dispatch, r3 ! r3 = &geom_render_dispatch (sym_060283E0)
    mov.l   _pool_static_data_b, r7 ! r7 = &static_data_b (sym_0605ACE5)
    mov.w   DAT_060059e6, r6 ! r6 = 0x5000 (render region size)
    jsr @r3                  ! call geom_render_dispatch(r4=0x8, r5, r6, r7)
    mov #0x8, r4             ! r4 = 0x8 (delay slot: render mode)
    mov.l   _pool_static_data_a, r7 ! r7 = &static_data_a (sym_0605ACDD)
    mov.w   _wpool_static_size, r6  ! r6 = 0x0090 (static element size)
    mov.w   DAT_060059e4, r5 ! r5 = 0x061C (render size param)
    mov #0x8, r4             ! r4 = 0x8 (render mode)
    add #0x4, r15            ! deallocate stack frame
    lds.l @r15+, pr          ! restore return address
    mov.l @r15+, r13         ! restore r13
    mov.l   _pool_geom_dispatch_final, r3 ! r3 = &geom_dispatch_final (sym_060284AE)
    jmp @r3                  ! tail-call geom_dispatch_final(r4, r5, r6, r7)
    mov.l @r15+, r14         ! restore r14 (delay slot)

    /* --- Word constant pool (PC-relative mov.w targets) --- */

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

    /* --- Longword constant pool (PC-relative mov.l targets) --- */

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

    /* --- Early exit: countdown expired, anim disabled, or race event active --- */

.L_early_exit:
    add #0x4, r15            ! deallocate stack frame
    lds.l @r15+, pr          ! restore return address
    mov.l @r15+, r13         ! restore r13
    rts                      ! return to caller
    mov.l @r15+, r14         ! restore r14 (delay slot)
