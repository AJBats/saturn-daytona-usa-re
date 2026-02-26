/* draw_priority_resolve -- VDP draw priority adjustment for car rendering
 *
 * Part of the per-frame dispatch chain (jsr @r13 pattern).
 *
 * Purpose:
 *   Manages VDP1/VDP2 draw priority bits for the active car's sprite layers.
 *   On each frame, a pipeline counter (sym_0607EAC8) is decremented.  When
 *   the counter reaches exactly 40 (post-decrement), four pairs of VDP
 *   priority bits are cleared from car_struct[0x214].  A separate countdown
 *   at car_struct[0x208] is also decremented toward zero.  Finally,
 *   car_struct[0xC0] is zeroed and the next dispatch function
 *   (damage_mac_core @ sym_0602F3EC) is loaded into r13.
 *
 *   If car_struct[0x244] >= 7 (priority count threshold), the function
 *   branches to an external continuation at 0x0602E3A0 (interleaved in
 *   rbg_rot_matrix_calc) which handles a high-priority rendering path.
 *
 * Inputs:
 *   r13 = chained dispatch function pointer (called first, then overwritten)
 *   sym_0607E940 = pointer to active car struct
 *   sym_0607EAC8 = pipeline scratch counter (decremented each frame)
 *
 * Outputs:
 *   r13 = next dispatch function (damage_mac_core / sym_0602F3EC)
 *   Car struct fields [0x214], [0x208], [0xC0] may be modified
 *
 * Pool constants at 0x0602E298-0x0602E2AC reside in the adjacent
 * vdp2_scroll_setup TU.  Word pools at 0x0602E284-0x0602E28E are
 * DAT_ exports in that same TU (VDP priority masks and struct offsets).
 *
 * Translation unit: 0x0602E18A - 0x0602E214
 */

    .section .text.FUN_0602E18A


    .global draw_priority_resolve
    .type draw_priority_resolve, @function
draw_priority_resolve:
    sts.l pr, @-r15                           ! save return address
    jsr @r13                                  ! call chained dispatch function
    nop                                       ! (delay slot)
    lds.l @r15+, pr                           ! restore return address
    nop                                       ! (pipeline alignment NOP)
    .byte   0xD0, 0x07    /* mov.l _pool_car_struct_ptr, r0 */  ! r0 = &car_struct_ptr (sym_0607E940)
    mov.l @r0, r0                             ! r0 = car struct base address (dereference)
    .byte   0xD1, 0x08    /* mov.l _pool_priority_field_off, r1 */  ! r1 = 0x0244 (priority count offset)
    mov.l @(r0, r1), r3                       ! r3 = car_struct[0x244] (draw priority count)
    .byte   0xD1, 0x08    /* mov.l _pool_priority_threshold, r1 */  ! r1 = 7 (priority count threshold)
    cmp/ge r1, r3                             ! T = (r3 >= 7) ?
    bf      .L_below_threshold                ! if count < 7, take normal priority path
    .byte   0xA0, 0xFD    /* bra 0x0602E3A0 (external) */  ! else jump to high-priority continuation
    nop                                       ! (delay slot)
    .2byte  0x0000                            ! padding (alignment)
    .4byte  sym_0608325C                      ! adjacent pool: countdown/race state (32-bit)
    .4byte  sym_0602EC54                      ! adjacent pool: draw priority table
    .4byte  sym_06083258                      ! adjacent pool: camera LOD offset base
_pool_car_struct_ptr:
    .4byte  sym_0607E940                      ! pool: &car_struct_ptr (active car)
    .4byte  sym_0600DB64                      ! adjacent pool: finish_proximity entry
_pool_priority_field_off:
    .4byte  0x00000244                        ! pool: car struct offset for draw priority count
_pool_priority_threshold:
    .4byte  0x00000007                        ! pool: threshold — branch to alt path if >= 7
.L_below_threshold:
    .byte   0xD3, 0x34    /* mov.l _pool_pipeline_counter, r3 */  ! r3 = &pipeline_counter (sym_0607EAC8)
    mov.l @r3, r3                             ! r3 = pipeline_counter value
    .byte   0xD1, 0x34    /* mov.l _pool_const_one, r1 */  ! r1 = 1
    sub r1, r3                                ! r3 = pipeline_counter - 1 (decrement)
    .byte   0xD4, 0x34    /* mov.l _pool_const_40, r4 */  ! r4 = 0x28 (40)
    cmp/eq r3, r4                             ! T = (counter-1 == 40) ?
    bf      .L_store_counter                  ! if not at frame 40, skip priority clearing
    .byte   0x91, 0x57    /* mov.w .L_wpool_0602E284, r1 */  ! r1 = 0x0214 (VDP priority field offset)
    mov.l @(r0, r1), r3                       ! r3 = car_struct[0x214] (current priority bits)
    .byte   0x92, 0x56    /* mov.w .L_wpool_0602E286, r2 */  ! r2 = 0x0088 (priority mask: bits 7,3)
    not r2, r2                                ! r2 = ~0x0088 = 0xFFFFFF77
    and r2, r3                                ! r3 &= ~0x0088 (clear bits 7 and 3)
    .byte   0x92, 0x54    /* mov.w .L_wpool_0602E288, r2 */  ! r2 = 0x0044 (priority mask: bits 6,2)
    not r2, r2                                ! r2 = ~0x0044 = 0xFFFFFFBB
    and r2, r3                                ! r3 &= ~0x0044 (clear bits 6 and 2)
    .byte   0x92, 0x52    /* mov.w .L_wpool_0602E28A, r2 */  ! r2 = 0x0022 (priority mask: bits 5,1)
    not r2, r2                                ! r2 = ~0x0022 = 0xFFFFFFDD
    and r2, r3                                ! r3 &= ~0x0022 (clear bits 5 and 1)
    .byte   0x92, 0x50    /* mov.w .L_wpool_0602E28C, r2 */  ! r2 = 0x0011 (priority mask: bits 4,0)
    not r2, r2                                ! r2 = ~0x0011 = 0xFFFFFFEE
    and r2, r3                                ! r3 &= ~0x0011 (clear bits 4 and 0)
    mov.l r3, @(r0, r1)                       ! car_struct[0x214] = r3 (priority bits cleared)
    .byte   0xD1, 0x29    /* mov.l _pool_pipeline_counter, r1 */  ! r1 = &pipeline_counter (sym_0607EAC8)
    mov.l @r1, r3                             ! r3 = pipeline_counter (re-read current value)
    .byte   0xD2, 0x29    /* mov.l _pool_const_one, r2 */  ! r2 = 1
    sub r2, r3                                ! r3 = pipeline_counter - 1
.L_store_counter:
    .byte   0xD1, 0x27    /* mov.l _pool_pipeline_counter, r1 */  ! r1 = &pipeline_counter (sym_0607EAC8)
    mov.l r3, @r1                             ! *pipeline_counter = r3 (store decremented value)
    .byte   0x91, 0x47    /* mov.w .L_wpool_0602E28E, r1 */  ! r1 = 0x0208 (effect countdown offset)
    mov.l @(r0, r1), r3                       ! r3 = car_struct[0x208] (effect countdown)
    .byte   0xD2, 0x28    /* mov.l _pool_const_zero, r2 */  ! r2 = 0
    cmp/eq r2, r3                             ! T = (countdown == 0) ?
    bt      .L_clear_and_chain                ! if already zero, skip decrement
    .byte   0xD2, 0x25    /* mov.l _pool_const_one, r2 */  ! r2 = 1
    sub r2, r3                                ! r3 = countdown - 1
    mov.l r3, @(r0, r1)                       ! car_struct[0x208] = r3 (store decremented)
.L_clear_and_chain:
    .byte   0xD3, 0x25    /* mov.l _pool_const_zero, r3 */  ! r3 = 0
    .byte   0xD1, 0x26    /* mov.l _pool_clear_field_off, r1 */  ! r1 = 0xC0 (clear target offset)
    mov.l r3, @(r0, r1)                       ! car_struct[0xC0] = 0 (clear render state)
    .byte   0xDD, 0x26    /* mov.l _pool_next_dispatch, r13 */  ! r13 = damage_mac_core (next dispatch fn)
