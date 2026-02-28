/* VERIFIED: called during mode select C press, clears init flag
 * Method: watchpoint on sym_06085FF1 (init pending flag) during C press on Mode Select
 *   PC=0x06019A16 (track_seg_phys_init+0xEA) writes 0x00010000 -> 0x00000000
 *   PR=0x06019A0E (track_seg_phys_init+0xE2, within function body)
 *   Called by car_select_setup; clears flag after loading display lists and physics.
 * Date: 2026-02-28
 */
/* track_seg_phys_init -- L3 assembly (SH-2 mnemonics)
 * Translation unit: 0x06019928 - 0x06019A48
 *
 * Pre-race display list loader and physics initializer.
 *
 * Called during race setup when the init pending flag (sym_06085FF1) == 1.
 * Loads car model display lists for all 8 car slots via the display element
 * renderer (sym_060284AE), then calls per-course physics init functions
 * (course0/1/2_physics_init) and the car init handler (0x0601A65E).
 *
 * For each of the 8 cars:
 *   1. Reads the display list base pointer from the car pointer table
 *      (sym_0605D294[i]) into r7.
 *   2. Reads 2 param bytes from the car slot param table (sym_06049AFC):
 *      byte[0] = low bits, byte[1] = high bits.
 *   3. Computes display list offset = ((high << 6) + low) * 2.
 *   4. Calls display_element_renderer(r4=0x8, r5=offset, r6=0x0090, r7=base).
 *
 * After the loop, loads the current car's entry (sym_06085FF0) with r4=0xC,
 * then loads a second variant entry (high_byte + 1) also with r4=0xC.
 * If current car != 6, loads an extra entry from the indirect car display
 * data pointer (sym_0605D4F0) at param offset +0xC/+0xD.
 *
 * Finally calls all 3 course physics init functions and the car init handler,
 * then clears the init pending flag.
 *
 * Key symbols:
 *   sym_0605D294 = car display list pointer table (8 entries, 4 bytes each)
 *   sym_06049AFC = car slot param table (8 entries, 2 bytes each)
 *   sym_060284AE = display element renderer (r4=mode, r5=dlist_offset, r6=index, r7=base)
 *   sym_06085FF1 = init pending flag (byte, 1 = pending)
 *   sym_0605B6D8 = render mode flags (32-bit)
 *   sym_06085FF0 = current car/course index (byte, 0-7)
 *   sym_06049E44 = secondary display list base (for variant +1 entry)
 *   sym_0605D4F0 = car display data pointer (indirect, for extra entry)
 *
 * BSR targets:
 *   0x06019BC8 = course0_physics_init (Beginner course car model loader)
 *   0x06019DB8 = course1_physics_init (Advanced course car model loader)
 *   0x06019FB2 = course2_physics_init (Expert course car model loader)
 *   0x0601A65E = car_init_handler (car model display list init for race start)
 */

    .section .text.FUN_06019928


    .global track_seg_phys_init
    .type track_seg_phys_init, @function

/* =========================================================================
 * Prologue — save callee-saved registers and allocate stack local
 * Stack layout: [sp+0] = temp pointer (used for param table entry addr)
 * ========================================================================= */
track_seg_phys_init:
    mov.l r14, @-r15                    ! save r14 (loop counter / car index ptr)
    mov.l r13, @-r15                    ! save r13 (display list base index constant)
    mov.l r12, @-r15                    ! save r12 (display element renderer fn ptr)
    mov.l r11, @-r15                    ! save r11 (car slot param table ptr)
    mov.l r10, @-r15                    ! save r10 (loop limit = 8)
    mov.l r9, @-r15                     ! save r9 (car display list pointer table)
    mov.l r8, @-r15                     ! save r8 (param table entry offset)
    sts.l pr, @-r15                     ! save PR (return address)
    add #-0x4, r15                      ! allocate 4 bytes for stack local

/* =========================================================================
 * Load key pointers and constants into callee-saved registers
 * ========================================================================= */
    mov.l   .L_ptr_car_dlist_table, r9  ! r9 -> car display list pointer table (sym_0605D294)
    mov.l   .L_ptr_car_slot_params, r11 ! r11 -> car slot param table (sym_06049AFC)
    mov.l   .L_ptr_disp_elem_renderer, r12 ! r12 -> display element renderer fn (sym_060284AE)
    mov.w   .L_const_base_index, r13    ! r13 = 0x0090 (display list base index)
    mov.l   .L_ptr_init_pending_flag, r0 ! r0 -> &init_pending_flag (sym_06085FF1)
    mov.b @r0, r0                       ! r0 = init_pending_flag value
    cmp/eq #0x1, r0                     ! is init pending? (flag == 1?)
    bf/s    .L_epilogue                 ! no -> skip all init, jump to epilogue
    mov #0x8, r10                       ! (delay) r10 = 8 (loop limit: 8 car slots)

/* =========================================================================
 * Set render mode flag bit 2 — signals display list loading active
 * ========================================================================= */
    mov.l   .L_ptr_render_mode_flags, r4 ! r4 -> &render_mode_flags (sym_0605B6D8)
    mov.l @r4, r0                       ! r0 = current render mode flags
    or #0x4, r0                         ! set bit 2 (display list load active)
    mov.l r0, @r4                       ! store updated flags

/* =========================================================================
 * Main loop — load display list entries for all 8 car slots
 * For each car i (0-7):
 *   r7 = car_dlist_table[i]     (display list base pointer)
 *   r5 = (param[i].high << 6 + param[i].low) * 2  (display list offset)
 *   r6 = 0x0090  (base index)
 *   r4 = 0x8     (mode: standard load)
 * ========================================================================= */
    mov #0x0, r14                       ! r14 = 0 (loop counter init)
.L_car_loop:
    extu.b r14, r0                      ! r0 = car_index (zero-extended)
    mov r13, r6                         ! r6 = 0x0090 (base index for renderer)
    extu.b r14, r8                      ! r8 = car_index (for param table offset)
    shll2 r0                            ! r0 = car_index * 4 (dword offset into ptr table)
    shll r8                             ! r8 = car_index * 2 (byte-pair offset into param table)
    mov.l @(r0, r9), r7                 ! r7 = car_dlist_table[i] (display list base ptr)
    add r11, r8                         ! r8 = &param_table[i] (absolute addr)
    mov.b @(1, r8), r0                  ! r0 = param[i].high (high byte of slot param)
    mov.b @r8, r3                       ! r3 = param[i].low (low byte of slot param)
    mov r0, r5                          ! r5 = high byte
    extu.b r3, r3                       ! zero-extend low byte
    extu.b r5, r5                       ! zero-extend high byte
    shll2 r5                            ! r5 = high << 2
    shll2 r5                            ! r5 = high << 4
    shll2 r5                            ! r5 = high << 6
    add r3, r5                          ! r5 = (high << 6) + low
    shll r5                             ! r5 = ((high << 6) + low) * 2 = dlist offset
    jsr @r12                            ! call display_element_renderer
    mov #0x8, r4                        ! (delay) r4 = 0x8 (mode: standard load)
    add #0x1, r14                       ! increment loop counter
    extu.b r14, r2                      ! r2 = loop counter (zero-extended)
    cmp/ge r10, r2                      ! loop counter >= 8?
    bf      .L_car_loop                 ! no -> continue loop

/* =========================================================================
 * Current car entry — load display list for the player's selected car
 * Uses mode 0xC (extended load) instead of 0x8.
 * ========================================================================= */
    mov r13, r6                         ! r6 = 0x0090 (base index)
    mov.l   .L_ptr_car_course_index, r14 ! r14 -> &car_course_index (sym_06085FF0)
    mov.b @r14, r0                      ! r0 = car_course_index
    mov.b @r14, r5                      ! r5 = car_course_index (for param offset calc)
    shll2 r0                            ! r0 = car_index * 4 (dword offset into ptr table)
    shll r5                             ! r5 = car_index * 2 (byte-pair offset into params)
    mov.l @(r0, r9), r7                 ! r7 = car_dlist_table[car_index] (base ptr)
    add r11, r5                         ! r5 = &param_table[car_index] (absolute addr)
    mov.l r5, @r15                      ! [sp+0] = param entry addr (save for byte read)
    mov.b @(1, r5), r0                  ! r0 = param[car].high
    mov.l @r15, r3                      ! r3 = param entry addr (reload from stack)
    mov r0, r5                          ! r5 = high byte
    mov.b @r3, r3                       ! r3 = param[car].low
    extu.b r5, r5                       ! zero-extend high byte
    extu.b r3, r3                       ! zero-extend low byte
    shll2 r5                            ! r5 = high << 2
    shll2 r5                            ! r5 = high << 4
    shll2 r5                            ! r5 = high << 6
    add r3, r5                          ! r5 = (high << 6) + low
    shll r5                             ! r5 = ((high << 6) + low) * 2 = dlist offset
    jsr @r12                            ! call display_element_renderer
    mov #0xC, r4                        ! (delay) r4 = 0xC (mode: extended load)

/* =========================================================================
 * Variant +1 entry — load an adjacent display list for the current car
 * Uses the secondary display list base (sym_06049E44) and adds 1 to
 * the high-byte component before shifting, yielding the next variant.
 * ========================================================================= */
    mov r13, r6                         ! r6 = 0x0090 (base index)
    mov.b @r14, r5                      ! r5 = car_course_index
    mov.l   .L_ptr_secondary_dlist_base, r7 ! r7 -> secondary display list base (sym_06049E44)
    shll r5                             ! r5 = car_index * 2 (byte-pair offset)
    add r11, r5                         ! r5 = &param_table[car_index]
    mov.b @(1, r5), r0                  ! r0 = param[car].high
    mov r0, r5                          ! r5 = high byte
    extu.b r5, r5                       ! zero-extend high byte
    shll2 r5                            ! r5 = high << 2
    shll2 r5                            ! r5 = high << 4
    shll2 r5                            ! r5 = high << 6
    add #0x1, r5                        ! r5 = (high << 6) + 1 (next variant)
    shll r5                             ! r5 = ((high << 6) + 1) * 2 = dlist offset
    jsr @r12                            ! call display_element_renderer
    mov #0xC, r4                        ! (delay) r4 = 0xC (mode: extended load)

/* =========================================================================
 * Extra entry — if car index != 6, load additional display data from
 * the indirect car display data pointer (sym_0605D4F0).
 * Reads param bytes at offset +0xC/+0xD in the param table.
 * ========================================================================= */
    mov.b @r14, r0                      ! r0 = car_course_index
    cmp/eq #0x6, r0                     ! is car index == 6?
    bt      .L_call_physics_init        ! yes -> skip extra entry, go to physics init
    mov.l   .L_ptr_car_display_data, r7 ! r7 -> &car_display_data_ptr (sym_0605D4F0)
    mov r13, r6                         ! r6 = 0x0090 (base index)
    mov r11, r3                         ! r3 = param table base
    mov.l @r7, r7                       ! r7 = *car_display_data_ptr (indirect load)
    add #0xC, r3                        ! r3 = &param_table[6] (offset +0xC)
    mov.l r11, @r15                     ! [sp+0] = param table base (save)
    mov.b @(13, r11), r0                ! r0 = param_table byte at offset 13 (entry 6, high)
    mov.b @r3, r3                       ! r3 = param_table byte at offset 12 (entry 6, low)
    mov r0, r5                          ! r5 = high byte
    extu.b r3, r3                       ! zero-extend low byte
    extu.b r5, r5                       ! zero-extend high byte
    shll2 r5                            ! r5 = high << 2
    shll2 r5                            ! r5 = high << 4
    shll2 r5                            ! r5 = high << 6
    add r3, r5                          ! r5 = (high << 6) + low
    add #0xD, r5                        ! r5 += 0xD (extra entry offset)
    shll r5                             ! r5 = final dlist offset * 2
    jsr @r12                            ! call display_element_renderer
    mov #0xC, r4                        ! (delay) r4 = 0xC (mode: extended load)

/* =========================================================================
 * Call all per-course physics init functions and car init handler
 * ========================================================================= */
.L_call_physics_init:
    .byte   0xB0, 0xE5    /* bsr 0x06019BC8 (external) */  ! call course0_physics_init
    nop                                 ! (delay slot)
    .byte   0xB1, 0xDB    /* bsr 0x06019DB8 (external) */  ! call course1_physics_init
    nop                                 ! (delay slot)
    .byte   0xB2, 0xD6    /* bsr 0x06019FB2 (external) */  ! call course2_physics_init
    nop                                 ! (delay slot)
    .byte   0xB6, 0x2A    /* bsr 0x0601A65E (external) */  ! call car_init_handler
    nop                                 ! (delay slot)

/* =========================================================================
 * Clear the init pending flag — initialization complete
 * ========================================================================= */
    mov #0x0, r2                        ! r2 = 0
    mov.l   .L_ptr_init_pending_flag, r3 ! r3 -> &init_pending_flag (sym_06085FF1)
    mov.b r2, @r3                       ! clear init_pending_flag = 0

/* =========================================================================
 * Epilogue — deallocate stack local, restore registers, return
 * ========================================================================= */
.L_epilogue:
    add #0x4, r15                       ! deallocate 4 bytes of stack local
    lds.l @r15+, pr                     ! restore PR (return address)
    mov.l @r15+, r8                     ! restore r8
    mov.l @r15+, r9                     ! restore r9
    mov.l @r15+, r10                    ! restore r10
    mov.l @r15+, r11                    ! restore r11
    mov.l @r15+, r12                    ! restore r12
    mov.l @r15+, r13                    ! restore r13
    rts                                 ! return to caller
    mov.l @r15+, r14                    ! (delay) restore r14

/* =========================================================================
 * Constant pools — word and long pools referenced by PC-relative loads
 * ========================================================================= */
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
