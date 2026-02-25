/* course0_physics_init -- L3 assembly (SH-2 mnemonics)
 * Translation unit: 0x06019BC8 - 0x06019D14
 *
 * Course 0 (Beginner/Three-Seven Speedway) car model display list loader.
 *
 * Called during race initialization to load car model display lists for
 * all cars on course 0. Iterates over 3 cars (indices 0-2), selecting a
 * texture slot for each, then calls the display list loader (sym_06028400)
 * to transfer car model data into VRAM.
 *
 * Two paths depending on whether course 0 is the active course:
 *   - NOT course 0 (sym_06085FF0 != 0): Simple slot assignment.
 *     The player's car (matching COURSE_SELECT) gets slot 6, others get 5.
 *   - IS course 0 (sym_06085FF0 == 0): Phase-aware slot assignment.
 *     The player's car uses the display phase counter (sym_0605D242) to
 *     pick slot 6 (phase < 8), 7 (8 <= phase <= 16), or wraps counter
 *     back to 0 when phase > 16. Non-player cars get slot 3.
 *
 * For each car, the function:
 *   1. Reads the car model index from the course 0 model table (sym_06049B12)
 *   2. Computes texture offset = slot * 0x1000
 *   3. Looks up car object data from the car object table (sym_06063750)
 *   4. Computes a combined display list index from offset table (sym_06049B0C)
 *   5. Calls display_list_loader(0xC, dlist_base, index, texture_offset)
 *
 * Key symbols:
 *   sym_06085FF0 = car/course index byte (0 = course 0 active)
 *   sym_0605AD00 = COURSE_SELECT (current course index, 32-bit int)
 *   sym_0605D242 = display phase counter (byte, 0-16+, wraps at >16)
 *   sym_06049B12 = course 0 car model index table (3 words: 0x7B, 0x7C, 0x7D)
 *   sym_06049B0C = course 0 display list offset table (3 byte-pairs)
 *   sym_06063750 = car object table base (per-car struct, 8 bytes each)
 *   sym_06028400 = display_list_loader(r4=layer_count, r5=dlist_base, r6=index, r7=tex_offset)
 *
 * Second symbol (DAT_06019bfc): Embedded data block within the constant pool
 *   area — contains pointers to sym_0605D4F0 (car display data), sym_0605D243
 *   (mode variant byte), sym_0605D242 (display phase counter), and
 *   sym_0605D260 (function pointer table for state transitions).
 */

    .section .text.FUN_06019BC8


    .global course0_physics_init
    .type course0_physics_init, @function

/* =========================================================================
 * Prologue — save callee-saved registers and allocate stack locals
 * Stack layout: [sp+0] = temp ptr, [sp+4] = car obj entry ptr, [sp+8] = car index * 2
 * ========================================================================= */
course0_physics_init:
    mov.l r14, @-r15                ! save r14 (loop limit / non-player slot)
    mov.l r13, @-r15                ! save r13 (car loop counter)
    mov.l r12, @-r15                ! save r12 (display phase counter ptr)
    mov.l r11, @-r15                ! save r11 (player car slot constant = 6)
    mov.l r10, @-r15                ! save r10 (chosen texture slot for this car)
    mov #0x6, r11                   ! r11 = 6 (player car texture slot constant)
    mov.l r9, @-r15                 ! save r9 (display_list_loader fn ptr)
    mov.l r8, @-r15                 ! save r8 (car model index table ptr)
    sts.l pr, @-r15                 ! save PR (return address)
    add #-0xC, r15                  ! allocate 12 bytes for 3 stack locals

/* =========================================================================
 * Load key pointers into callee-saved registers for the loop
 * ========================================================================= */
    mov.l   .L_pool_model_index_table, r8   ! r8 -> course 0 model index table (sym_06049B12)
    mov.l   .L_pool_dlist_loader, r9        ! r9 -> display_list_loader function (sym_06028400)
    mov.l   .L_pool_display_phase_ctr, r12  ! r12 -> &display_phase_counter (sym_0605D242)
    mov.l   .L_pool_car_course_index, r3    ! r3 -> &car_course_index (sym_06085FF0)
    mov.b @r3, r3                           ! r3 = car_course_index byte
    tst r3, r3                              ! is course 0 active? (index == 0?)
    bt/s    .L_is_course0                   ! yes -> use phase-aware slot assignment
    mov #0x3, r14                           ! (delay) r14 = 3 (loop limit: 3 cars)

/* =========================================================================
 * NOT COURSE 0 PATH — simple slot assignment
 * For each of 3 cars: player car gets slot 6, others get slot 5.
 * ========================================================================= */
    mov #0x0, r13                           ! r13 = 0 (car loop counter init)
.L_not_c0_loop_top:
    extu.b r13, r3                          ! r3 = car_index (zero-extended)
    mov.l   .L_pool_course_select, r2      ! r2 -> &COURSE_SELECT (sym_0605AD00)
    mov.l @r2, r2                           ! r2 = COURSE_SELECT value (player's car index)
    cmp/eq r2, r3                           ! is this the player's car?
    bf      .L_not_c0_not_player            ! no -> use default slot 5
    bra     .L_not_c0_slot_chosen           ! yes -> use player slot 6
    extu.b r11, r10                         ! (delay) r10 = 6 (player texture slot)

/* =========================================================================
 * Embedded data block — referenced by other code via DAT_06019bfc
 * Contains pointers used by car select and state transition systems.
 * These are NOT constant pool entries for this function — they belong
 * to a separate data symbol that happens to sit in this TU's address range.
 * ========================================================================= */
    .global DAT_06019bfc
DAT_06019bfc:
    mov.l r0, @(0, r0)                     ! (data, not executed as code)
    .word 0xFFFF /* UNKNOWN */              ! padding / sentinel
    .4byte  sym_0605D4F0                    ! -> car display data pointer (indirect)
    .4byte  sym_0605D243                    ! -> mode variant byte
.L_pool_display_phase_ctr:
    .4byte  sym_0605D242                    ! -> display phase counter (byte, 0-16+)
    .4byte  sym_0605D260                    ! -> function pointer table (state transitions)
.L_pool_model_index_table:
    .4byte  sym_06049B12                    ! -> course 0 car model index table (3 words)
.L_pool_dlist_loader:
    .4byte  sym_06028400                    ! -> display_list_loader function
.L_pool_car_course_index:
    .4byte  sym_06085FF0                    ! -> car/course index byte (0 = course 0)
.L_pool_course_select:
    .4byte  sym_0605AD00                    ! -> COURSE_SELECT (32-bit, player's car index)

/* =========================================================================
 * NOT COURSE 0: non-player car slot assignment
 * ========================================================================= */
.L_not_c0_not_player:
    mov #0x5, r10                           ! r10 = 5 (non-player texture slot)

/* =========================================================================
 * NOT COURSE 0: compute texture offset and call display list loader
 * ========================================================================= */
.L_not_c0_slot_chosen:
    extu.b r10, r7                          ! r7 = chosen slot (zero-extended)
    extu.b r13, r0                          ! r0 = car_index (zero-extended)
    shll8 r7                                ! r7 = slot << 8
    shll r0                                 ! r0 = car_index * 2 (word offset into model table)
    shll2 r7                                ! r7 = slot << 10
    mov.l r0, @(8, r15)                     ! [sp+8] = car_index * 2 (save for later)
    shll2 r7                                ! r7 = slot << 12 = slot * 0x1000 (texture page offset)
    mov.w @(r0, r8), r3                     ! r3 = model_index_table[car_index] (e.g. 0x7B)
    mov.l   .L_pool_car_obj_table, r2      ! r2 -> car object table base (sym_06063750)
    extu.w r3, r3                           ! r3 = zero-extend model index to 32-bit
    shll2 r3                                ! r3 = model_index * 4
    shll r3                                 ! r3 = model_index * 8 (car obj struct size = 8 bytes)
    add r3, r2                              ! r2 -> car_obj_table[model_index] (8-byte struct)
    mov.l r2, @(4, r15)                     ! [sp+4] = &car_obj_table[model_index]
    mov.l @(4, r2), r3                      ! r3 = car_obj_table[model_index].texture_base (+4)
    mov.l @(8, r15), r6                     ! r6 = car_index * 2 (reload)
    add r3, r7                              ! r7 = texture_base + (slot * 0x1000) = final tex param
    mov.l   .L_pool_dlist_offset_table, r3 ! r3 -> course 0 dlist offset table (sym_06049B0C)
    add r3, r6                              ! r6 -> dlist_offset_table[car_index] (2-byte entry)
    mov.l r6, @r15                          ! [sp+0] = &dlist_offset_table[car_index]
    mov.b @(1, r6), r0                      ! r0 = high byte of dlist offset entry
    mov.l @r15, r2                          ! r2 = &dlist_offset_table[car_index] (reload)
    mov r0, r6                              ! r6 = high byte
    mov.b @r2, r2                           ! r2 = low byte of dlist offset entry
    extu.b r6, r6                           ! r6 = zero-extend high byte
    extu.b r2, r2                           ! r2 = zero-extend low byte
    shll2 r6                                ! r6 = high_byte << 2
    shll2 r6                                ! r6 = high_byte << 4
    shll2 r6                                ! r6 = high_byte << 6 (= high_byte * 64)
    add r2, r6                              ! r6 = (high_byte * 64) + low_byte = combined dlist index
    shll r6                                 ! r6 = combined_index * 2 (final display list index)
    mov.l @(4, r15), r5                     ! r5 = &car_obj_table[model_index]
    mov.l @r5, r5                           ! r5 = car_obj_table[model_index].dlist_base (+0)
    jsr @r9                                 ! call display_list_loader(0xC, dlist_base, index, tex)
    mov #0xC, r4                            ! (delay) r4 = 0xC (layer count)

/* =========================================================================
 * NOT COURSE 0: advance loop counter, check if all 3 cars done
 * ========================================================================= */
    add #0x1, r13                           ! r13++ (next car)
    extu.b r13, r3                          ! r3 = car_index (zero-extended)
    cmp/ge r14, r3                          ! car_index >= 3? (loop limit)
    bf      .L_not_c0_loop_top              ! no -> process next car
    bra     .L_epilogue                     ! yes -> done, exit
    nop                                     ! (delay)

/* =========================================================================
 * IS COURSE 0 PATH — phase-aware slot assignment
 * Player car uses display phase counter to cycle through texture slots.
 * ========================================================================= */
.L_is_course0:
    mov #0x0, r13                           ! r13 = 0 (car loop counter init)
.L_c0_loop_top:
    extu.b r13, r2                          ! r2 = car_index (zero-extended)
    mov.l   .L_pool_course_select_b, r3   ! r3 -> &COURSE_SELECT (sym_0605AD00)
    mov.l @r3, r3                           ! r3 = COURSE_SELECT value (player's car index)
    cmp/eq r3, r2                           ! is this the player's car?
    bf      .L_c0_not_player                ! no -> use non-player slot 3

/* --- Player car: phase-based slot selection --- */
    mov #0x8, r2                            ! r2 = 8 (phase threshold low)
    mov.b @r12, r3                          ! r3 = display_phase_counter (byte)
    extu.b r3, r3                           ! r3 = zero-extended phase counter
    cmp/ge r2, r3                           ! phase_counter >= 8?
    bt      .L_c0_phase_ge_8               ! yes -> check upper bound
    bra     .L_c0_player_slot_chosen        ! no -> phase < 8: use player slot 6
    extu.b r11, r10                         ! (delay) r10 = 6 (player texture slot)

/* --- Player car: phase >= 8, check if > 16 --- */
.L_c0_phase_ge_8:
    mov #0x10, r3                           ! r3 = 16 (phase threshold high)
    mov.b @r12, r2                          ! r2 = display_phase_counter (re-read)
    extu.b r2, r2                           ! r2 = zero-extend phase counter
    cmp/gt r3, r2                           ! phase_counter > 16?
    bf/s    .L_c0_phase_le_16              ! no -> keep current phase, use slot 7
    mov #0x7, r10                           ! (delay) r10 = 7 (advanced texture slot)
    mov #0x0, r3                            ! r3 = 0 (phase reset value)
    mov.b r3, @r12                          ! display_phase_counter = 0 (wrap around)
.L_c0_phase_le_16:
    bra     .L_c0_player_slot_chosen        ! proceed with slot 7
    nop                                     ! (delay)

/* --- Non-player car on course 0: use slot 3 --- */
.L_c0_not_player:
    extu.b r14, r10                         ! r10 = 3 (non-player slot, from r14 which holds loop limit = 3)

/* =========================================================================
 * IS COURSE 0: compute texture offset and call display list loader
 * (Same computation as the NOT COURSE 0 path)
 * ========================================================================= */
.L_c0_player_slot_chosen:
    extu.b r10, r7                          ! r7 = chosen slot (zero-extended)
    extu.b r13, r0                          ! r0 = car_index (zero-extended)
    shll8 r7                                ! r7 = slot << 8
    shll r0                                 ! r0 = car_index * 2 (word offset into model table)
    shll2 r7                                ! r7 = slot << 10
    mov.l r0, @r15                          ! [sp+0] = car_index * 2 (save for later)
    shll2 r7                                ! r7 = slot << 12 = slot * 0x1000 (texture page offset)
    mov.w @(r0, r8), r3                     ! r3 = model_index_table[car_index] (e.g. 0x7B)
    mov.l   .L_pool_car_obj_table, r2      ! r2 -> car object table base (sym_06063750)
    extu.w r3, r3                           ! r3 = zero-extend model index to 32-bit
    shll2 r3                                ! r3 = model_index * 4
    shll r3                                 ! r3 = model_index * 8 (car obj struct size = 8 bytes)
    add r3, r2                              ! r2 -> car_obj_table[model_index] (8-byte struct)
    mov.l r2, @(8, r15)                     ! [sp+8] = &car_obj_table[model_index]
    mov.l @(4, r2), r3                      ! r3 = car_obj_table[model_index].texture_base (+4)
    mov.l @r15, r6                          ! r6 = car_index * 2 (reload)
    add r3, r7                              ! r7 = texture_base + (slot * 0x1000) = final tex param
    mov.l   .L_pool_dlist_offset_table, r3 ! r3 -> course 0 dlist offset table (sym_06049B0C)
    add r3, r6                              ! r6 -> dlist_offset_table[car_index] (2-byte entry)
    mov.l r6, @(4, r15)                     ! [sp+4] = &dlist_offset_table[car_index]
    mov.b @(1, r6), r0                      ! r0 = high byte of dlist offset entry
    mov.l @(4, r15), r2                     ! r2 = &dlist_offset_table[car_index] (reload)
    mov r0, r6                              ! r6 = high byte
    mov.b @r2, r2                           ! r2 = low byte of dlist offset entry
    extu.b r6, r6                           ! r6 = zero-extend high byte
    extu.b r2, r2                           ! r2 = zero-extend low byte
    shll2 r6                                ! r6 = high_byte << 2
    shll2 r6                                ! r6 = high_byte << 4
    shll2 r6                                ! r6 = high_byte << 6 (= high_byte * 64)
    add r2, r6                              ! r6 = (high_byte * 64) + low_byte = combined dlist index
    shll r6                                 ! r6 = combined_index * 2 (final display list index)
    mov.l @(8, r15), r5                     ! r5 = &car_obj_table[model_index]
    mov.l @r5, r5                           ! r5 = car_obj_table[model_index].dlist_base (+0)
    jsr @r9                                 ! call display_list_loader(0xC, dlist_base, index, tex)
    mov #0xC, r4                            ! (delay) r4 = 0xC (layer count)

/* =========================================================================
 * IS COURSE 0: advance loop counter, check if all 3 cars done
 * ========================================================================= */
    add #0x1, r13                           ! r13++ (next car)
    extu.b r13, r3                          ! r3 = car_index (zero-extended)
    cmp/ge r14, r3                          ! car_index >= 3? (loop limit)
    bf      .L_c0_loop_top                  ! no -> process next car

/* =========================================================================
 * Epilogue — deallocate stack locals, restore registers, return
 * ========================================================================= */
.L_epilogue:
    add #0xC, r15                           ! free 12 bytes of stack locals
    lds.l @r15+, pr                         ! restore PR (return address)
    mov.l @r15+, r8                         ! restore r8
    mov.l @r15+, r9                         ! restore r9
    mov.l @r15+, r10                        ! restore r10
    mov.l @r15+, r11                        ! restore r11
    mov.l @r15+, r12                        ! restore r12
    mov.l @r15+, r13                        ! restore r13
    rts                                     ! return to caller
    mov.l @r15+, r14                        ! (delay) restore r14

/* =========================================================================
 * Constant pool — tail pool entries for the IS COURSE 0 path
 * CRITICAL: Do not reorder — .byte-encoded mov.l instructions depend on
 * exact offsets from PC to these entries.
 * ========================================================================= */
    .2byte  0xFFFF                          ! alignment padding
.L_pool_car_obj_table:
    .4byte  sym_06063750                    ! -> car object table base (per-car 8-byte structs)
.L_pool_dlist_offset_table:
    .4byte  sym_06049B0C                    ! -> course 0 dlist offset table (3 byte-pairs)
.L_pool_course_select_b:
    .4byte  sym_0605AD00                    ! -> COURSE_SELECT (32-bit, player's car index)
