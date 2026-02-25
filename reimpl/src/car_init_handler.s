/* car_init_handler -- L3 assembly (SH-2 mnemonics)
 * Translation unit: 0x0601A65E - 0x0601A770
 *
 * Car model display list initialization for race start.
 *
 * Called from race_start_transition during pre-race setup. Loads two
 * car model display lists via the display list loader (sym_06028400):
 *   1. A "primary" slot (r12 selects variant index)
 *   2. A "secondary" slot (r14 selects variant index)
 *
 * The slot indices depend on the current car/course index (sym_06085FF0):
 *   - If index == 3 (special course): reads a display phase counter
 *     (sym_0605D242) and picks slot 3 or advances to slot 7 if phase >= 8.
 *     Resets the phase counter to 0 if it exceeds 16.
 *   - Otherwise: primary slot = 5, secondary slot = 6.
 *
 * The two-player flag (sym_0605D241) controls which branch path is taken:
 *   - Single-player: loads secondary slot first, then primary.
 *   - Two-player:    loads primary slot first, then secondary.
 *
 * Second function (race_start_sound_trigger, sym_0601A73E):
 *   Plays a race-start sound effect via sound_cmd_dispatch. Selects the
 *   sound command based on the two-player flag:
 *     - 1P mode: sound_cmd_dispatch(0xF, 0xAE0006FF)
 *     - 2P mode: sound_cmd_dispatch(0xF, 0xAE0007FF)
 *
 * Key symbols:
 *   sym_06085FF0 = car/course index (byte, 0-7)
 *   sym_0605D241 = two-player mode flag (byte, 0=1P, nonzero=2P)
 *   sym_0605D242 = display phase counter (byte, 0-16+)
 *   sym_06063750 = car object table base (per-car struct array)
 *   sym_06028400 = display list loader (r4=mode, r5=dlist_base, r6=index, r7=tex)
 *   sound_cmd_dispatch = sound command dispatcher (r4=channel, r5=command)
 */

    .section .text.FUN_0601A65E


    .global car_init_handler
    .type car_init_handler, @function
car_init_handler:
    mov.l r14, @-r15                         ! save r14 (callee-saved)
    mov.l r13, @-r15                         ! save r13 (callee-saved)
    mov.l r12, @-r15                         ! save r12 (callee-saved)
    mov.l r11, @-r15                         ! save r11 (callee-saved)
    sts.l pr, @-r15                          ! save PR (return address)
    add #-0x4, r15                           ! allocate 4 bytes on stack for local ptr
    .byte   0xD0, 0x1E    /* mov.l _pool_car_course_index, r0 */  ! r0 -> &car_course_index (sym_06085FF0)
    mov.b @r0, r0                            ! r0 = car_course_index (byte, 0-7)
    cmp/eq #0x3, r0                          ! is this course 3 (special)?
    bf/s    .L_not_course_3                  ! no -> use default slots 6/5
    mov #0x6, r5                             ! (delay) r5 = 6 (default secondary slot)
    .byte   0xD4, 0x1C    /* mov.l _pool_display_phase_ctr, r4 */ ! r4 -> &display_phase_ctr (sym_0605D242)
    mov #0x8, r3                             ! r3 = 8 (phase threshold low)
    mov.b @r4, r2                            ! r2 = display_phase_ctr (signed byte)
    extu.b r2, r2                            ! r2 = zero-extend to 32-bit
    cmp/ge r3, r2                            ! phase_ctr >= 8?
    bt/s    .L_phase_ge_8                    ! yes -> check upper bound
    mov #0x3, r12                            ! (delay) r12 = 3 (primary slot for course 3)
    bra     .L_slots_chosen                  ! phase < 8: use slot 6/3
    extu.b r5, r14                           ! (delay) r14 = 6 (secondary slot)
.L_phase_ge_8:
    mov #0x10, r3                            ! r3 = 16 (phase threshold high)
    mov.b @r4, r2                            ! r2 = display_phase_ctr (re-read)
    extu.b r2, r2                            ! r2 = zero-extend to 32-bit
    cmp/gt r3, r2                            ! phase_ctr > 16?
    bf/s    .L_phase_le_16                   ! no -> keep current counter
    mov #0x7, r14                            ! (delay) r14 = 7 (secondary slot, advanced)
    mov #0x0, r3                             ! r3 = 0 (reset value)
    mov.b r3, @r4                            ! display_phase_ctr = 0 (wrap around)
.L_phase_le_16:
    bra     .L_slots_chosen                  ! proceed with chosen slots
    nop                                      ! (delay)
.L_not_course_3:
    extu.b r5, r14                           ! r14 = 6 (secondary slot, from r5)
    mov #0x5, r12                            ! r12 = 5 (primary slot, default)
.L_slots_chosen:
    .byte   0xDB, 0x13    /* mov.l _pool_car_obj_table, r11 */    ! r11 -> car object table base (sym_06063750)
    .byte   0xDD, 0x13    /* mov.l _pool_dlist_loader, r13 */     ! r13 -> display list loader (sym_06028400)
    .byte   0xD2, 0x14    /* mov.l _pool_two_player_flag, r2 */   ! r2 -> &two_player_flag (sym_0605D241)
    mov.b @r2, r2                            ! r2 = two_player_flag (byte)
    tst r2, r2                               ! is single-player mode?
    bf      .L_two_player_path               ! nonzero -> two-player path
    extu.b r14, r7                           ! r7 = secondary slot index (zero-ext)
    mov.w   DAT_0601a6de, r3                 ! r3 = 0x0418 (obj table struct offset A)
    shll8 r7                                 ! r7 = slot << 8
    add r11, r3                              ! r3 = &car_obj_table + 0x0418
    shll2 r7                                 ! r7 = slot << 10
    mov.l r3, @r15                           ! [sp] = &car_obj_table[struct_A] (save ptr)
    shll2 r7                                 ! r7 = slot << 12 (= slot * 0x1000, texture offset)
    mov.l @(4, r3), r3                       ! r3 = car_obj_table[struct_A].texture_base (+4)
    mov.w   DAT_0601a6e0, r6                 ! r6 = 0x0624 (display list index A)
    mov.l @r15, r5                           ! r5 = &car_obj_table[struct_A] (reload ptr)
    add r3, r7                               ! r7 = texture_base + (slot * 0x1000)
    mov.l @r5, r5                            ! r5 = car_obj_table[struct_A].dlist_base (+0)
    jsr @r13                                 ! call dlist_loader(0xC, dlist_base, 0x0624, tex)
    mov #0xC, r4                             ! (delay) r4 = 0xC (display layer count)
    extu.b r12, r7                           ! r7 = primary slot index (zero-ext)
    shll8 r7                                 ! r7 = slot << 8
    shll2 r7                                 ! r7 = slot << 10
    shll2 r7                                 ! r7 = slot << 12 (= slot * 0x1000, texture offset)
    mov.w   DAT_0601a6e2, r3                 ! r3 = 0x0420 (obj table struct offset B)
    add r11, r3                              ! r3 = &car_obj_table + 0x0420
    mov.l r3, @r15                           ! [sp] = &car_obj_table[struct_B] (save ptr)
    mov.l @(4, r3), r3                       ! r3 = car_obj_table[struct_B].texture_base (+4)
    add r3, r7                               ! r7 = texture_base + (slot * 0x1000)
    bra     .L_load_final_dlist              ! -> load final display list
    nop                                      ! (delay)
    .2byte  0x00A9                           ! alignment padding

    .global DAT_0601a6de
DAT_0601a6de:
    .2byte  0x0418                           ! struct offset A into car object table

    .global DAT_0601a6e0
DAT_0601a6e0:
    .2byte  0x0624                           ! display list index A

    .global DAT_0601a6e2
DAT_0601a6e2:
    .2byte  0x0420                           ! struct offset B into car object table
_pool_car_course_index:
    .4byte  sym_06085FF0                     ! -> car/course index (byte, 0-7)
_pool_display_phase_ctr:
    .4byte  sym_0605D242                     ! -> display phase counter (byte, 0-16+)
_pool_car_obj_table:
    .4byte  sym_06063750                     ! -> car object table base
_pool_dlist_loader:
    .4byte  sym_06028400                     ! -> display list loader function
_pool_two_player_flag:
    .4byte  sym_0605D241                     ! -> two-player mode flag (byte)
.L_two_player_path:
    extu.b r12, r7                           ! r7 = primary slot index (zero-ext)
    mov.w   DAT_0601a756, r3                 ! r3 = 0x0418 (obj table struct offset A)
    shll8 r7                                 ! r7 = slot << 8
    add r11, r3                              ! r3 = &car_obj_table + 0x0418
    shll2 r7                                 ! r7 = slot << 10
    mov.l r3, @r15                           ! [sp] = &car_obj_table[struct_A] (save ptr)
    shll2 r7                                 ! r7 = slot << 12 (= slot * 0x1000, texture offset)
    mov.l @(4, r3), r3                       ! r3 = car_obj_table[struct_A].texture_base (+4)
    mov.w   DAT_0601a758, r6                 ! r6 = 0x0624 (display list index A)
    mov.l @r15, r5                           ! r5 = &car_obj_table[struct_A] (reload ptr)
    add r3, r7                               ! r7 = texture_base + (slot * 0x1000)
    mov.l @r5, r5                            ! r5 = car_obj_table[struct_A].dlist_base (+0)
    jsr @r13                                 ! call dlist_loader(0xC, dlist_base, 0x0624, tex)
    mov #0xC, r4                             ! (delay) r4 = 0xC (display layer count)
    extu.b r14, r7                           ! r7 = secondary slot index (zero-ext)
    shll8 r7                                 ! r7 = slot << 8
    shll2 r7                                 ! r7 = slot << 10
    shll2 r7                                 ! r7 = slot << 12 (= slot * 0x1000, texture offset)
    mov.w   DAT_0601a75a, r3                 ! r3 = 0x0420 (obj table struct offset B)
    add r11, r3                              ! r3 = &car_obj_table + 0x0420
    mov.l r3, @r15                           ! [sp] = &car_obj_table[struct_B] (save ptr)
    mov.l @(4, r3), r3                       ! r3 = car_obj_table[struct_B].texture_base (+4)
    add r3, r7                               ! r7 = texture_base + (slot * 0x1000)
.L_load_final_dlist:
    mov.w   _wpool_final_dlist_size, r6      ! r6 = 0x063C (display list size / final index)
    mov.l @r15, r5                           ! r5 = &car_obj_table[struct] (from stack)
    mov.l @r5, r5                            ! r5 = car_obj_table[struct].dlist_base (+0)
    jsr @r13                                 ! call dlist_loader(0xC, dlist_base, 0x063C, tex)
    mov #0xC, r4                             ! (delay) r4 = 0xC (display layer count)
    add #0x4, r15                            ! free local stack allocation
    lds.l @r15+, pr                          ! restore PR (return address)
    mov.l @r15+, r11                         ! restore r11
    mov.l @r15+, r12                         ! restore r12
    mov.l @r15+, r13                         ! restore r13
    rts                                      ! return to caller
    mov.l @r15+, r14                         ! (delay) restore r14

    .global sym_0601A73E
sym_0601A73E:
    .byte   0xD3, 0x08    /* mov.l _pool_two_player_flag_b, r3 */ ! r3 -> &two_player_flag (sym_0605D241)
    mov.b @r3, r3                            ! r3 = two_player_flag (byte)
    tst r3, r3                               ! is single-player mode?
    bf      .L_play_2p_sound                 ! nonzero -> play 2-player sound
    .byte   0xD5, 0x07    /* mov.l _pool_snd_cmd_1p, r5 */       ! r5 = 0xAE0006FF (1P race-start sound cmd)
    .byte   0xD3, 0x07    /* mov.l _pool_fn_sound_cmd_dispatch, r3 */ ! r3 -> sound_cmd_dispatch
    jmp @r3                                  ! tail-call sound_cmd_dispatch(0xF, 0xAE0006FF)
    mov #0xF, r4                             ! (delay) r4 = 0xF (sound channel)
.L_play_2p_sound:
    .byte   0xD5, 0x07    /* mov.l _pool_snd_cmd_2p, r5 */       ! r5 = 0xAE0007FF (2P race-start sound cmd)
    .byte   0xD3, 0x05    /* mov.l _pool_fn_sound_cmd_dispatch, r3 */ ! r3 -> sound_cmd_dispatch
    jmp @r3                                  ! tail-call sound_cmd_dispatch(0xF, 0xAE0007FF)
    mov #0xF, r4                             ! (delay) r4 = 0xF (sound channel)

    .global DAT_0601a756
DAT_0601a756:
    .2byte  0x0418                           ! struct offset A into car object table (2P path)

    .global DAT_0601a758
DAT_0601a758:
    .2byte  0x0624                           ! display list index A (2P path)

    .global DAT_0601a75a
DAT_0601a75a:
    .2byte  0x0420                           ! struct offset B into car object table (2P path)
_wpool_final_dlist_size:
    .2byte  0x063C                           ! final display list size / index
    .2byte  0xFFFF                           ! alignment padding
_pool_two_player_flag_b:
    .4byte  sym_0605D241                     ! -> two-player mode flag (byte)
_pool_snd_cmd_1p:
    .4byte  0xAE0006FF                       ! sound command: 1P race-start effect
_pool_fn_sound_cmd_dispatch:
    .4byte  sound_cmd_dispatch               ! -> sound command dispatcher function
_pool_snd_cmd_2p:
    .4byte  0xAE0007FF                       ! sound command: 2P race-start effect
