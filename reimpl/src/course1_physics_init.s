/* course1_physics_init -- L3 assembly (SH-2 mnemonics)
 * Translation unit: 0x06019DB8 - 0x06019EF0
 *
 * Course 1 (Advanced / Dinosaur Canyon) car model display list loader.
 *
 * Called during race initialization to load car model display lists for
 * all cars on course 1. Iterates over 5 cars (indices 0-4), selecting a
 * texture slot for each, then calls the display list loader (sym_06028400)
 * to transfer car model data into VRAM.
 *
 * Two paths depending on whether course 1 is the active course:
 *   - NOT course 1 (sym_06085FF0 != 1): Simple slot assignment.
 *     The player's car (matching COURSE_SELECT at sym_0605AD0C) gets slot 6,
 *     others get slot 5.
 *   - IS course 1 (sym_06085FF0 == 1): Phase-aware slot assignment.
 *     The player's car uses the display phase counter (sym_0605D242) to
 *     pick slot 6 (phase < 8), 7 (8 <= phase <= 16), or wraps counter
 *     back to 0 when phase > 16. Non-player cars get slot 3.
 *
 * For each car, the function:
 *   1. Reads the car model index from the course 1 model table (sym_06049B2C)
 *   2. Computes texture offset = slot * 0x1000
 *   3. Looks up car object data from the car object table (sym_06063750)
 *   4. Computes a combined display list index from offset table (sym_06049B18)
 *   5. Calls display_list_loader(0xC, dlist_base, index, texture_offset)
 *
 * Key symbols:
 *   sym_06085FF0 = car/course config byte (1 = course 1 active)
 *   sym_0605AD0C = COURSE_SELECT for course 1 (player's car index, 32-bit)
 *   sym_0605D242 = display phase counter (byte, 0-16+, wraps at >16)
 *   sym_06049B2C = course 1 car model index table (5 words)
 *   sym_06049B18 = course 1 display list offset table (5 byte-pairs)
 *   sym_06063750 = car object table base (per-car struct, 8 bytes each)
 *   sym_06028400 = display_list_loader(r4=layer_count, r5=dlist_base,
 *                  r6=index, r7=tex_offset)
 *
 * Register allocation:
 *   r8  = car_model_table base (sym_06049B2C, word array)
 *   r9  = display_list_loader function pointer (sym_06028400)
 *   r10 = chosen texture slot for current car (computed per iteration)
 *   r11 = player car texture slot constant (0x6)
 *   r12 = pointer to display phase counter byte (sym_0605D242)
 *   r13 = loop counter (car index, 0..r14-1)
 *   r14 = total car count for this course (5)
 *
 * Stack layout (normal path):
 *   sp[0] = &dlist_offset_entry, sp[4] = &car_obj_table[model], sp[8] = car_index*2
 * Stack layout (active path):
 *   sp[0] = car_index*2, sp[4] = &dlist_offset_entry, sp[8] = &car_obj_table[model]
 */

    .section .text.FUN_06019DB8


    .global course1_physics_init
    .type course1_physics_init, @function

/* =========================================================================
 * Prologue -- save callee-saved registers and allocate stack locals
 * ========================================================================= */
course1_physics_init:
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
    mov.l   .L_pool_car_model_table, r8    ! r8 -> course 1 model index table (sym_06049B2C)
    mov.l   .L_pool_dlist_loader, r9       ! r9 -> display_list_loader function (sym_06028400)
    mov.l   .L_pool_display_phase_ctr, r12 ! r12 -> &display_phase_counter (sym_0605D242)
    mov.l   .L_pool_game_config, r0        ! r0 -> &game_config_byte (sym_06085FF0)
    mov.b @r0, r0                          ! r0 = game_config_byte value
    cmp/eq #0x1, r0                        ! is config == 1 (course 1 active)?
    bt/s    .L_active_path                 ! yes -> use phase-aware slot assignment
    mov #0x5, r14                          ! (delay) r14 = 5 (loop limit: 5 cars)

/* =========================================================================
 * NORMAL PATH (config != 1) -- simple slot assignment
 * For each of 5 cars: player car gets slot 6, others get slot 5.
 * ========================================================================= */
    mov #0x0, r13                          ! r13 = 0 (car loop counter init)
.L_normal_loop_top:
    extu.b r13, r2                         ! r2 = car_index (zero-extended)
    mov.l   .L_pool_player_car_index, r3   ! r3 -> &COURSE_SELECT for course 1 (sym_0605AD0C)
    mov.l @r3, r3                          ! r3 = COURSE_SELECT value (player's car index)
    cmp/eq r3, r2                          ! is this the player's car?
    bf      .L_normal_not_player           ! no -> use default slot 5
    bra     .L_normal_slot_chosen          ! yes -> use player slot 6
    extu.b r11, r10                        ! (delay) r10 = 6 (player texture slot)
.L_normal_not_player:
    extu.b r14, r10                        ! r10 = 5 (non-player texture slot, from r14=loop limit=5)

/* =========================================================================
 * NORMAL PATH: compute texture offset and call display list loader
 * ========================================================================= */
.L_normal_slot_chosen:
    extu.b r10, r7                         ! r7 = chosen slot (zero-extended)
    extu.b r13, r0                         ! r0 = car_index (zero-extended)
    shll8 r7                               ! r7 = slot << 8
    shll r0                                ! r0 = car_index * 2 (word offset into model table)
    shll2 r7                               ! r7 = slot << 10
    mov.l r0, @(8, r15)                    ! sp[8] = car_index * 2 (save for later)
    shll2 r7                               ! r7 = slot << 12 = slot * 0x1000 (texture page offset)
    mov.w @(r0, r8), r3                    ! r3 = model_index_table[car_index] (model ID, word)
    mov.l   .L_pool_car_obj_table, r2      ! r2 -> car object table base (sym_06063750)
    extu.w r3, r3                          ! r3 = zero-extend model index to 32-bit
    shll2 r3                               ! r3 = model_index * 4
    shll r3                                ! r3 = model_index * 8 (car obj struct size = 8 bytes)
    add r3, r2                             ! r2 -> car_obj_table[model_index] (8-byte struct)
    mov.l r2, @(4, r15)                    ! sp[4] = &car_obj_table[model_index]
    mov.l @(4, r2), r3                     ! r3 = car_obj_table[model_index].texture_base (+4)
    mov.l @(8, r15), r6                    ! r6 = car_index * 2 (reload)
    add r3, r7                             ! r7 = texture_base + (slot * 0x1000) = final tex param
    mov.l   .L_pool_dlist_offset_table, r3 ! r3 -> course 1 dlist offset table (sym_06049B18)
    add r3, r6                             ! r6 -> dlist_offset_table[car_index] (2-byte entry)
    mov.l r6, @r15                         ! sp[0] = &dlist_offset_table[car_index]
    mov.b @(1, r6), r0                     ! r0 = high byte of dlist offset entry
    mov.l @r15, r2                         ! r2 = &dlist_offset_table[car_index] (reload)
    mov r0, r6                             ! r6 = high byte
    mov.b @r2, r2                          ! r2 = low byte of dlist offset entry
    extu.b r6, r6                          ! r6 = zero-extend high byte
    extu.b r2, r2                          ! r2 = zero-extend low byte
    shll2 r6                               ! r6 = high_byte << 2
    shll2 r6                               ! r6 = high_byte << 4
    shll2 r6                               ! r6 = high_byte << 6 (= high_byte * 64)
    add r2, r6                             ! r6 = (high_byte * 64) + low_byte = combined dlist index
    shll r6                                ! r6 = combined_index * 2 (final display list index)
    mov.l @(4, r15), r5                    ! r5 = &car_obj_table[model_index]
    mov.l @r5, r5                          ! r5 = car_obj_table[model_index].dlist_base (+0)
    jsr @r9                                ! call display_list_loader(0xC, dlist_base, index, tex)
    mov #0xC, r4                           ! (delay) r4 = 0xC (layer count)

/* =========================================================================
 * NORMAL PATH: advance loop counter, check if all 5 cars done
 * ========================================================================= */
    add #0x1, r13                          ! r13++ (next car)
    extu.b r13, r3                         ! r3 = car_index (zero-extended)
    cmp/ge r14, r3                         ! car_index >= 5? (loop limit)
    bf      .L_normal_loop_top             ! no -> process next car
    bra     .L_epilogue                    ! yes -> done, exit
    nop                                    ! (delay)

/* =========================================================================
 * ACTIVE PATH (config == 1) -- phase-aware slot assignment
 * Player car uses display phase counter to cycle through texture slots.
 * ========================================================================= */
.L_active_path:
    mov #0x0, r13                          ! r13 = 0 (car loop counter init)
.L_active_loop_top:
    extu.b r13, r2                         ! r2 = car_index (zero-extended)
    mov.l   .L_pool_player_car_index, r3   ! r3 -> &COURSE_SELECT for course 1 (sym_0605AD0C)
    mov.l @r3, r3                          ! r3 = COURSE_SELECT value (player's car index)
    cmp/eq r3, r2                          ! is this the player's car?
    bf      .L_active_not_player           ! no -> use non-player slot 3

/* --- Player car: phase-based slot selection --- */
    mov #0x8, r2                           ! r2 = 8 (phase threshold low)
    mov.b @r12, r3                         ! r3 = display_phase_counter (byte)
    extu.b r3, r3                          ! r3 = zero-extended phase counter
    cmp/ge r2, r3                          ! phase_counter >= 8?
    bt      .L_active_phase_ge_8           ! yes -> check upper bound
    bra     .L_active_slot_chosen          ! no -> phase < 8: use player slot 6
    extu.b r11, r10                        ! (delay) r10 = 6 (player texture slot)

/* --- Player car: phase >= 8, check if > 16 --- */
.L_active_phase_ge_8:
    mov #0x10, r3                          ! r3 = 16 (phase threshold high)
    mov.b @r12, r2                         ! r2 = display_phase_counter (re-read)
    extu.b r2, r2                          ! r2 = zero-extend phase counter
    cmp/gt r3, r2                          ! phase_counter > 16?
    bf/s    .L_active_phase_le_16          ! no -> keep current phase, use slot 7
    mov #0x7, r10                          ! (delay) r10 = 7 (advanced texture slot)
    mov #0x0, r3                           ! r3 = 0 (phase reset value)
    mov.b r3, @r12                         ! display_phase_counter = 0 (wrap around)
.L_active_phase_le_16:
    bra     .L_active_slot_chosen          ! proceed with chosen slot
    nop                                    ! (delay)
    .2byte  0xFFFF                         ! alignment padding

/* =========================================================================
 * Constant pool (first block) -- referenced by mov.l instructions above
 * CRITICAL: Do not reorder -- PC-relative offsets depend on exact positions.
 * ========================================================================= */
.L_pool_car_model_table:
    .4byte  sym_06049B2C                   ! -> course 1 car model index table (5 words: 0x7E-0x82)
.L_pool_dlist_loader:
    .4byte  sym_06028400                   ! -> display_list_loader function
.L_pool_display_phase_ctr:
    .4byte  sym_0605D242                   ! -> display phase counter (byte, 0-16+)
.L_pool_game_config:
    .4byte  sym_06085FF0                   ! -> car/course config byte (1 = course 1 active)
.L_pool_player_car_index:
    .4byte  sym_0605AD0C                   ! -> COURSE_SELECT for course 1 (player's car index)
.L_pool_car_obj_table:
    .4byte  sym_06063750                   ! -> car object table base (per-car 8-byte structs)
.L_pool_dlist_offset_table:
    .4byte  sym_06049B18                   ! -> course 1 dlist offset table (5 byte-pairs)

/* --- Non-player car on course 1 active: use slot 3 --- */
.L_active_not_player:
    mov #0x3, r10                          ! r10 = 3 (non-player slot)

/* =========================================================================
 * ACTIVE PATH: compute texture offset and call display list loader
 * (Same computation as the normal path but with different stack slot usage)
 * ========================================================================= */
.L_active_slot_chosen:
    extu.b r10, r7                         ! r7 = chosen slot (zero-extended)
    extu.b r13, r0                         ! r0 = car_index (zero-extended)
    shll8 r7                               ! r7 = slot << 8
    shll r0                                ! r0 = car_index * 2 (word offset into model table)
    shll2 r7                               ! r7 = slot << 10
    mov.l r0, @r15                         ! sp[0] = car_index * 2 (save for later)
    shll2 r7                               ! r7 = slot << 12 = slot * 0x1000 (texture page offset)
    mov.w @(r0, r8), r3                    ! r3 = model_index_table[car_index] (model ID, word)
    .byte   0xD2, 0x29    /* mov.l .L_pool_06019F44, r2 */  ! r2 -> car object table (sym_06063750, cross-TU pool)
    extu.w r3, r3                          ! r3 = zero-extend model index to 32-bit
    shll2 r3                               ! r3 = model_index * 4
    shll r3                                ! r3 = model_index * 8 (car obj struct size = 8 bytes)
    add r3, r2                             ! r2 -> car_obj_table[model_index] (8-byte struct)
    mov.l r2, @(8, r15)                    ! sp[8] = &car_obj_table[model_index]
    mov.l @(4, r2), r3                     ! r3 = car_obj_table[model_index].texture_base (+4)
    mov.l @r15, r6                         ! r6 = car_index * 2 (reload)
    add r3, r7                             ! r7 = texture_base + (slot * 0x1000) = final tex param
    .byte   0xD3, 0x25    /* mov.l .L_pool_06019F48, r3 */  ! r3 -> course 1 dlist offset table (sym_06049B18, cross-TU pool)
    add r3, r6                             ! r6 -> dlist_offset_table[car_index] (2-byte entry)
    mov.l r6, @(4, r15)                    ! sp[4] = &dlist_offset_table[car_index]
    mov.b @(1, r6), r0                     ! r0 = high byte of dlist offset entry
    mov.l @(4, r15), r2                    ! r2 = &dlist_offset_table[car_index] (reload)
    mov r0, r6                             ! r6 = high byte
    mov.b @r2, r2                          ! r2 = low byte of dlist offset entry
    extu.b r6, r6                          ! r6 = zero-extend high byte
    extu.b r2, r2                          ! r2 = zero-extend low byte
    shll2 r6                               ! r6 = high_byte << 2
    shll2 r6                               ! r6 = high_byte << 4
    shll2 r6                               ! r6 = high_byte << 6 (= high_byte * 64)
    add r2, r6                             ! r6 = (high_byte * 64) + low_byte = combined dlist index
    shll r6                                ! r6 = combined_index * 2 (final display list index)
    mov.l @(8, r15), r5                    ! r5 = &car_obj_table[model_index]
    mov.l @r5, r5                          ! r5 = car_obj_table[model_index].dlist_base (+0)
    jsr @r9                                ! call display_list_loader(0xC, dlist_base, index, tex)
    mov #0xC, r4                           ! (delay) r4 = 0xC (layer count)

/* =========================================================================
 * ACTIVE PATH: advance loop counter, check if all 5 cars done
 * ========================================================================= */
    add #0x1, r13                          ! r13++ (next car)
    extu.b r13, r3                         ! r3 = car_index (zero-extended)
    cmp/ge r14, r3                         ! car_index >= 5? (loop limit)
    bf      .L_active_loop_top             ! no -> process next car

/* =========================================================================
 * Epilogue -- deallocate stack locals, restore registers, return
 * ========================================================================= */
.L_epilogue:
    add #0xC, r15                          ! free 12 bytes of stack locals
    lds.l @r15+, pr                        ! restore PR (return address)
    mov.l @r15+, r8                        ! restore r8
    mov.l @r15+, r9                        ! restore r9
    mov.l @r15+, r10                       ! restore r10
    mov.l @r15+, r11                       ! restore r11
    mov.l @r15+, r12                       ! restore r12
    mov.l @r15+, r13                       ! restore r13
    rts                                    ! return to caller
    mov.l @r15+, r14                       ! (delay) restore r14
