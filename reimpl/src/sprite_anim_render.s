/* sprite_anim_render -- L3 assembly (SH-2 mnemonics)
 * Translation unit: 0x060100A4 - 0x060102EC
 *
 * Per-car sprite animation renderer. Called once per car each frame to
 * animate and render the car's 3D sprite (billboard or mesh).
 *
 * Input:  r4 = car index (byte, 0-based)
 *
 * Flow:
 *   1. Look up the car's animation base offsets (X, Y) from the sprite
 *      parameter table at sym_060447C8 (16 bytes per entry).
 *   2. Check if this car is the player car (sym_0607EAD8). If not, use
 *      the alternate sprite data source at sym_0605D0BC.
 *   3. Initiate DMA transfer of the car's sprite data via dma_transfer().
 *   4. If game_state (sym_0607887F) > 4 (racing), apply animation:
 *      - Read/increment the per-car animation counter (sym_06078870).
 *      - Interpolate X/Y position offsets using velocity table (sym_060447F8).
 *      - Adjust scale (r12) and alpha/opacity (r13) based on anim frame.
 *   5. If game_state >= 0xC, override Y offset to fixed value (0x00960000).
 *   6. Build final transform parameters and call rigid_body_transform()
 *      to submit the sprite to the VDP1 command list.
 *
 * Constants:
 *   - 0x00010000 = 1.0 in 16.16 fixed-point (initial scale/alpha)
 *   - 0x8000 = initial Y base offset (16.16 high word)
 *   - sym_06044844 = Z-depth ordering table
 *   - 0x00200000 = Work RAM Low base address
 */

    .section .text.FUN_060100A4


    .global sprite_anim_render
    .type sprite_anim_render, @function
sprite_anim_render:
    mov.l r14, @-r15                ! save r14
    mov r4, r14                     ! r14 = car_index (preserved across calls)
    mov.l r13, @-r15                ! save r13
    extu.b r14, r3                  ! r3 = car_index & 0xFF
    extu.b r14, r4                  ! r4 = car_index & 0xFF
    extu.b r14, r1                  ! r1 = car_index & 0xFF (for player check)
    mov.l r12, @-r15                ! save r12
    shll2 r4                        ! r4 = car_index * 0x4
    mov.l r11, @-r15                ! save r11
    shll2 r4                        ! r4 = car_index * 0x10 (16 bytes/entry)
    mov.l r10, @-r15                ! save r10
    sts.l pr, @-r15                 ! save return address
    sts.l macl, @-r15               ! save MAC low
    add #-0x8, r15                  ! allocate 0x8 bytes on stack
    mov.l r3, @r15                  ! [sp+0] = car_index
    mov.w   DAT_060100f6, r2        ! r2 = 0x0101 (palette index offset)
    add r2, r3                      ! r3 = car_index + 0x0101
    extu.w r3, r3                   ! zero-extend to 16 bits
    mov r3, r0                      ! r0 = palette/color index
    mov.w r0, @(4, r15)             ! [sp+4] = color index (16-bit)
    mov.l   .L_p_sprite_param_tbl, r2 ! r2 = &sprite_param_tbl (sym_060447C8)
    mov.w   DAT_060100f8, r12       ! r12 = 0x8000 (initial Y base, 16.16 high)
    mov.l   .L_fp_one, r13          ! r13 = 0x00010000 (1.0 fixed-point alpha)
    mov.l   .L_p_player_car_idx, r0 ! r0 = &player_car_idx (sym_0607EAD8)
    add r2, r4                      ! r4 = &sprite_param_tbl[car_index]
    mov.l @r0, r0                   ! r0 = player_car_idx
    mov.l @r4, r10                  ! r10 = sprite X offset (from param table)
    cmp/eq r0, r1                   ! is this the player car?
    bt/s    .L_is_player_car        ! yes -> use player sprite data
    mov.l @(4, r4), r11             ! r11 = sprite Y offset (delay slot, always runs)
    ! --- not the player car: compute alt sprite source ---
    mov.l @r15, r5                  ! r5 = car_index
    add #0x3, r5                    ! r5 = car_index + 0x3 (skip player entries)
    shll2 r5                        ! r5 *= 0x4
    shll2 r5                        ! r5 *= 0x4 (total: *0x10)
    shll r5                         ! r5 *= 0x2 (total: *0x20 = 32 bytes/entry)
    mov.l   .L_p_alt_sprite_data, r3 ! r3 = &alt_sprite_data (sym_0605D0BC)
    add r3, r5                      ! r5 = &alt_sprite_data[(car+3)*0x20]
    bra     .L_do_dma_transfer      ! jump to DMA
    mov #0x20, r6                   ! r6 = 0x20 (DMA transfer size, delay slot)

    .global DAT_060100f2
DAT_060100f2:
    .word 0x06A2 /* UNKNOWN */

    .global DAT_060100f4
DAT_060100f4:
    stc vbr, r11

    .global DAT_060100f6
DAT_060100f6:
    .2byte  0x0101
                                    /* palette index base offset */
    .global DAT_060100f8
DAT_060100f8:
    .2byte  0x8000
                                    /* initial Y base (16.16 high word) */
    .2byte  0xFFFF
    .4byte  sym_0605AB19            /* "MIRROR MODE" string (adjacent data) */
.L_p_sprite_param_tbl:
    .4byte  sym_060447C8            /* sprite animation parameter table (16 bytes/car) */
.L_fp_one:
    .4byte  0x00010000              /* 1.0 (16.16 fixed-point) */
.L_p_player_car_idx:
    .4byte  sym_0607EAD8            /* player car index (dword) */
.L_p_alt_sprite_data:
    .4byte  sym_0605D0BC            /* alternate sprite palette/data (non-player) */
.L_is_player_car:
    ! --- player car: use direct sprite data ---
    mov #0x20, r6                   ! r6 = 0x20 (DMA transfer size)
    extu.b r14, r5                  ! r5 = car_index & 0xFF
    shll2 r5                        ! r5 *= 0x4
    shll2 r5                        ! r5 *= 0x4 (total: *0x10)
    shll r5                         ! r5 *= 0x2 (total: *0x20 = 32 bytes/entry)
    mov.l   .L_p_sprite_palette, r3 ! r3 = &sprite_palette (sym_0605D0BC)
    add r3, r5                      ! r5 = &sprite_palette[car_index * 0x20]
.L_do_dma_transfer:
    ! --- initiate DMA of sprite data ---
    extu.b r14, r4                  ! r4 = car_index & 0xFF
    mov.l   .L_p_car_dma_ptrs, r2  ! r2 = &car_dma_ptrs (sym_06078888)
    mov.l   .L_p_fn_dma_transfer, r1 ! r1 = &dma_transfer
    shll2 r4                        ! r4 = car_index * 0x4 (dword table index)
    add r2, r4                      ! r4 = &car_dma_ptrs[car_index]
    jsr @r1                         ! call dma_transfer(r4=dst, r5=src, r6=size)
    mov.l @r4, r4                   ! r4 = car_dma_ptrs[car_index] (delay slot)
    ! --- check game state for animation ---
    mov.l   .L_p_game_state, r3    ! r3 = &game_state (sym_0607887F)
    mov #0x4, r2                    ! r2 = 0x4 (threshold)
    mov.b @r3, r3                   ! r3 = game_state (byte)
    extu.b r3, r3                   ! zero-extend
    cmp/gt r2, r3                   ! game_state > 0x4? (racing mode?)
    bf      .L_check_y_override     ! no -> skip animation, just check Y override
    ! --- racing mode: check if this is the player car ---
    extu.b r14, r2                  ! r2 = car_index
    mov.l   .L_p_player_car_idx2, r3 ! r3 = &player_car_idx
    mov.l   .L_p_anim_counters, r5 ! r5 = &anim_counters (sym_06078870, 16-bit/car)
    mov.l @r3, r3                   ! r3 = player_car_idx
    cmp/eq r3, r2                   ! is this the player car?
    bf/s    .L_check_other_car      ! no -> handle other car animation
    mov #0x1E, r4                   ! r4 = 0x1E (player anim max = 30, delay slot)
    ! --- player car animation counter ---
    extu.b r14, r0                  ! r0 = car_index
    shll r0                         ! r0 *= 0x2 (word index into anim_counters)
    mov.w @(r0, r5), r3             ! r3 = anim_counters[car_index]
    extu.w r3, r3                   ! zero-extend 16-bit counter
    cmp/ge r4, r3                   ! counter >= 0x1E (30)?
    bf      .L_inc_player_counter   ! no -> increment and continue
    ! --- player counter hit max: wrap to 0x20 ---
    extu.b r14, r0                  ! r0 = car_index
    shll r0                         ! r0 *= 0x2 (word index)
    mov #0x20, r3                   ! r3 = 0x20 (wrap value = 32)
    mov.w r3, @(r0, r5)             ! anim_counters[car_index] = 0x20
    mov r3, r4                      ! r4 = 0x20 (anim frame for interpolation)
    bra     .L_apply_player_anim    ! apply animation with wrapped frame
    nop
.L_inc_player_counter:
    ! --- increment player animation counter ---
    extu.b r14, r0                  ! r0 = car_index
    shll r0                         ! r0 *= 0x2 (word index)
    mov.w @(r0, r5), r4             ! r4 = anim_counters[car_index]
    add #0x1, r4                    ! r4++ (advance animation)
    mov.w r4, @(r0, r5)             ! write back incremented counter
.L_apply_player_anim:
    ! --- interpolate position using velocity table ---
    mov r14, r5                     ! r5 = car_index (raw)
    mov r14, r3                     ! r3 = car_index (raw)
    mov.l   .L_p_velocity_tbl, r2  ! r2 = &velocity_tbl (sym_060447F8, 12 bytes/entry)
    shll2 r5                        ! r5 = car_index * 0x4
    shll2 r3                        ! r3 = car_index * 0x4
    shll r3                         ! r3 = car_index * 0x8
    add r3, r5                      ! r5 = car_index * 0xC (12 bytes per entry)
    exts.b r5, r5                   ! sign-extend byte offset
    extu.w r4, r3                   ! r3 = anim_frame (16-bit)
    add r2, r5                      ! r5 = &velocity_tbl[car_index]
    mov.l @r5, r1                   ! r1 = vel_x (32-bit fixed-point)
    mul.l r3, r1                    ! macl = anim_frame * vel_x
    mov.l @(4, r5), r1              ! r1 = vel_y (32-bit fixed-point)
    sts macl, r3                    ! r3 = anim_frame * vel_x
    add r3, r10                     ! r10 += X position delta
    extu.w r4, r3                   ! r3 = anim_frame (16-bit)
    mul.l r3, r1                    ! macl = anim_frame * vel_y
    sts macl, r3                    ! r3 = anim_frame * vel_y
    add r3, r11                     ! r11 += Y position delta
    ! --- scale decay: reduce scale by frame * 0x800 ---
    extu.w r4, r3                   ! r3 = anim_frame
    shll8 r3                        ! r3 <<= 0x8
    shll2 r3                        ! r3 <<= 0x2
    shll r3                         ! r3 <<= 0x1 (total: frame * 0x800)
    sub r3, r12                     ! r12 -= scale decay amount
    ! --- alpha decay for player: frame * 0x020C ---
    extu.w r4, r4                   ! r4 = anim_frame (16-bit)
    mov.w   DAT_060101b2, r1        ! r1 = 0x020C (player alpha decay rate)
    bra     .L_apply_alpha_decay    ! goto common alpha subtract
    mul.l r1, r4                    ! macl = anim_frame * 0x020C (delay slot)
.L_check_other_car:
    ! --- non-player car: check if anim counter hit max ---
    extu.b r14, r0                  ! r0 = car_index
    shll r0                         ! r0 *= 0x2 (word index)
    mov.w @(r0, r5), r3             ! r3 = anim_counters[car_index]
    extu.w r3, r3                   ! zero-extend
    cmp/ge r4, r3                   ! counter >= 0x1E (30)?
    bf      .L_inc_other_counter    ! no -> increment other car counter
    bra     .L_epilogue             ! yes -> skip rendering entirely
    nop

    .global DAT_060101b2
DAT_060101b2:
    .2byte  0x020C                  /* player alpha decay rate per frame */
.L_p_sprite_palette:
    .4byte  sym_0605D0BC            /* sprite palette/data source */
.L_p_car_dma_ptrs:
    .4byte  sym_06078888            /* per-car DMA destination pointer table */
.L_p_fn_dma_transfer:
    .4byte  dma_transfer            /* DMA transfer function */
.L_p_game_state:
    .4byte  sym_0607887F            /* game state byte (>4 = racing) */
.L_p_anim_counters:
    .4byte  sym_06078870            /* per-car animation counters (16-bit each) */
.L_p_player_car_idx2:
    .4byte  sym_0607EAD8            /* player car index (dword) */
.L_p_velocity_tbl:
    .4byte  sym_060447F8            /* per-car XY velocity table (12 bytes/entry) */
.L_inc_other_counter:
    ! --- increment non-player car animation counter ---
    extu.b r14, r0                  ! r0 = car_index
    shll r0                         ! r0 *= 0x2 (word index)
    mov.w @(r0, r5), r4             ! r4 = anim_counters[car_index]
    add #0x1, r4                    ! r4++ (advance animation)
    mov.w r4, @(r0, r5)             ! write back incremented counter
    ! --- scale decay for non-player ---
    extu.w r4, r3                   ! r3 = anim_frame
    shll8 r3                        ! r3 <<= 0x8
    shll2 r3                        ! r3 <<= 0x2
    shll r3                         ! r3 <<= 0x1 (total: frame * 0x800)
    sub r3, r12                     ! r12 -= scale decay amount
    ! --- alpha decay for non-player: frame * 0x072B ---
    extu.w r4, r4                   ! r4 = anim_frame (16-bit)
    mov.w   .L_w_alpha_decay_rate, r2 ! r2 = 0x072B (non-player alpha decay rate)
    mul.l r2, r4                    ! macl = anim_frame * 0x072B
.L_apply_alpha_decay:
    sts macl, r4                    ! r4 = alpha decay amount
    sub r4, r13                     ! r13 -= alpha decay (reduce opacity)
.L_check_y_override:
    ! --- if game_state >= 0xC, override Y offset ---
    mov #0xC, r2                    ! r2 = 0xC (state threshold)
    mov.l   .L_p_game_state2, r3   ! r3 = &game_state
    mov.b @r3, r3                   ! r3 = game_state (byte)
    extu.b r3, r3                   ! zero-extend
    cmp/ge r2, r3                   ! game_state >= 0xC?
    bf      .L_build_transform      ! no -> keep computed Y offset
    mov.l   .L_p_fixed_y_offset, r11 ! r11 = 0x00960000 (fixed Y for state >= 0xC)
.L_build_transform:
    ! --- look up Z-depth from display mode index ---
    mov.l   .L_p_display_mode_idx, r2 ! r2 = &display_mode_idx (sym_0605AA98)
    mov r11, r5                     ! r5 = Y offset (arg for rigid_body_transform)
    mov.l   .L_p_zdepth_tbl, r3    ! r3 = &zdepth_tbl (sym_06044844)
    mov.l @r2, r2                   ! r2 = display_mode_idx
    shll2 r2                        ! r2 *= 0x4 (dword index)
    add r3, r2                      ! r2 = &zdepth_tbl[display_mode_idx]
    mov.l @r2, r1                   ! r1 = Z-depth value
    mov.l r1, @r15                  ! [sp+0] = Z-depth
    ! --- push transform arguments onto stack ---
    mov.w @(4, r15), r0             ! r0 = color index (from earlier)
    mov r0, r2                      ! r2 = color index
    mov.l r2, @-r15                 ! push color index
    mov.l r13, @-r15                ! push alpha (16.16 fixed-point)
    mov.l r12, @-r15                ! push scale (16.16 fixed-point)
    mov.l   .L_wram_low, r7        ! r7 = 0x00200000 (Work RAM Low base)
    mov.l @(12, r15), r6            ! r6 = Z-depth from stack
    mov.l   .L_p_fn_rigid_body_xform, r2 ! r2 = &rigid_body_transform
    shlr r6                         ! r6 >>= 0x1 (halve Z-depth)
    shll16 r6                       ! r6 <<= 0x10 (pack into high word)
    jsr @r2                         ! call rigid_body_transform(r4=X, r5=Y, r6=Z, r7=wram)
    mov r10, r4                     ! r4 = X offset (delay slot)
    add #0xC, r15                   ! pop 3 dwords from stack
.L_epilogue:
    ! --- restore registers and return ---
    add #0x8, r15                   ! deallocate local stack frame
    lds.l @r15+, macl               ! restore MAC low
    lds.l @r15+, pr                 ! restore return address
    mov.l @r15+, r10                ! restore r10
    mov.l @r15+, r11                ! restore r11
    mov.l @r15+, r12                ! restore r12
    mov.l @r15+, r13                ! restore r13
    rts                             ! return
    mov.l @r15+, r14                ! restore r14 (delay slot)
    .4byte  0xD416E200              /* following TU code (not part of this function) */
    .4byte  0xD016D317
    .4byte  0x6001600D
    .4byte  0x2422203A
    .4byte  0x9215C9FF
    .4byte  0x650D3527
    .4byte  0x8B026242
    .4byte  0x72012422
    .4byte  0x655D930D
    .4byte  0x35378B02
    .4byte  0x63427301
    .4byte  0x24326242
    .4byte  0xD30D2320
    .4byte  0x6142D30D
    .4byte  0x000B2312
.L_w_alpha_decay_rate:
    .2byte  0x072B                  /* non-player alpha decay rate per frame */
    .2byte  0x0080
    .4byte  0x00C0FFFF
.L_p_game_state2:
    .4byte  sym_0607887F            /* game state byte (>=0xC -> fixed Y override) */
.L_p_fixed_y_offset:
    .4byte  0x00960000              /* fixed Y offset for state >= 0xC (16.16) */
.L_p_display_mode_idx:
    .4byte  sym_0605AA98            /* display mode index (dword) */
.L_p_zdepth_tbl:
    .4byte  sym_06044844            /* Z-depth ordering table (dword per mode) */
.L_wram_low:
    .4byte  0x00200000              /* Work RAM Low base */
.L_p_fn_rigid_body_xform:
    .4byte  rigid_body_transform    /* rigid body transform function */
    .4byte  sym_0607EADC            /* frame counter (dword) */
    .4byte  sym_06063D9C            /* input state word */
    .4byte  0x0000FFFF
    .4byte  sym_0607887E            /* game sub-state byte */
    .4byte  sym_0607EAD8            /* player car index (dword) */
    .4byte  0xD519634D              /* following TU code (byte blob) */
    .4byte  0xD2192329
    .4byte  0x23388907
    .4byte  0xE202D316
    .4byte  0x63323323
    .4byte  0x89026252
    .4byte  0x72012522
    .4byte  0x644D9320
    .4byte  0x24392448
    .4byte  0x8906D310
    .4byte  0x63324315
    .4byte  0x8B026352
    .4byte  0x73FF2532
    .4byte  0x6252D30E
    .4byte  0x23206152
    .4byte  0xD30D000B
    .4byte  0x2312624D
