/* hud_coord_calc -- L3 assembly (SH-2 mnemonics)
 * Translation unit: 0x06010994 - 0x06010A5C
 *
 * HUD element coordinate calculator. Computes source addresses in the VDP1
 * command table for copying HUD display data (lap, speed, time elements).
 * In split-screen mode, uses a simpler lookup; in single-player mode,
 * combines car index, display type, and buffer offset to compute the
 * source address. Calls memcpy_word_idx twice to transfer two HUD
 * element blocks into the VDP1 command buffer.
 */

    .section .text.FUN_06010994


    .global hud_coord_calc
    .type hud_coord_calc, @function
hud_coord_calc:
    mov.l r14, @-r15                    ! save r14 (callee-saved)
    mov.l r13, @-r15                    ! save r13 (callee-saved)
    mov.l r12, @-r15                    ! save r12 (callee-saved)
    sts.l pr, @-r15                     ! save return address
    mov.l   _pool_game_state_idx_ptr, r12 ! r12 = &game_state_index (persistent across calls)
    mov.l   _pool_vdp1_cmd_buf_ptr, r13 ! r13 = &vdp1_cmd_buf_base (persistent across calls)
    mov.l   _pool_memcpy_word_idx, r14  ! r14 = memcpy_word_idx function address
    mov.l   _pool_split_screen_flag, r0 ! r0 = &split_screen_flag
    mov.b @r0, r0                       ! r0 = split_screen_flag value
    tst r0, r0                          ! test if split-screen mode active
    bt      .L_single_player_path       ! if zero (single player) -> simpler path
    ! --- Split-screen path: compute src from car index + display type + offset ---
    mov #0x20, r6                       ! r6 = 0x20 (32 words = transfer size)
    mov.l   _pool_disp_elem_data_ptr, r5 ! r5 = &display_element_data
    mov.l   _pool_cmd_table_base, r3    ! r3 = cmd_table_base address
    mov.l   _pool_car_index_ptr, r4     ! r4 = &car_index
    mov.l   _pool_color_table_byte, r2  ! r2 = color_table_byte address
    mov.l   _pool_buf_offset_word, r1   ! r1 = &buffer_offset (word)
    mov.l @r12, r0                      ! r0 = game_state_index
    mov.l @r5, r5                       ! r5 = display_element_data value
    mov.l @r4, r4                       ! r4 = car_index value
    mov.w @r1, r1                       ! r1 = buffer_offset (16-bit)
    shll2 r0                            ! r0 = game_state_index * 4
    shll2 r5                            ! r5 = display_element_data * 4
    add r2, r4                          ! r4 = car_index_base + color_table offset
    extu.w r1, r1                       ! r1 = zero-extend buffer_offset to 32-bit
    add r3, r5                          ! r5 = cmd_table_base + (elem_data * 4)
    mov.b @r4, r4                       ! r4 = read display type byte
    mov.l @r5, r5                       ! r5 = dereference -> source data pointer
    extu.b r4, r4                       ! r4 = zero-extend type byte to 32-bit
    add r1, r4                          ! r4 = type + buffer_offset
    shll2 r4                            ! r4 *= 4
    shll2 r4                            ! r4 *= 4 (cumulative: *16)
    shll r4                             ! r4 *= 2 (cumulative: *32 = tile stride)
    shll r0                             ! r0 = game_state_index * 8
    add r0, r4                          ! r4 += state_index * 8 (select within tile)
    mov.l @r13, r1                      ! r1 = vdp1_cmd_buf_base value
    bra     .L_do_first_copy            ! jump to first memcpy call
    add r1, r4                          ! (delay) r4 = final dest = cmd_buf + offset
.L_single_player_path:
    mov.w   DAT_06010a2a, r6            ! r6 = 0x00C0 (192 words = transfer size)

    .global loc_060109E2
loc_060109E2:                           ! entry point for external callers (data-driven dispatch)
    mov.l   _pool_disp_data_base_ptr, r5 ! r5 = &display_data_base
    mov.l   _pool_func_table_base, r3  ! r3 = func_table_base address
    mov.l @r12, r4                      ! r4 = game_state_index
    mov.l @r5, r5                       ! r5 = display_data_base value
    shll2 r4                            ! r4 = game_state_index * 4
    shll2 r5                            ! r5 = display_data * 4
    add r3, r5                          ! r5 = func_table_base + (display_data * 4)
    mov.l @r5, r5                       ! r5 = dereference -> source data pointer
    shll r4                             ! r4 = game_state_index * 8
    mov.l @r13, r2                      ! r2 = vdp1_cmd_buf_base value
    add r2, r4                          ! r4 = cmd_buf + (state_index * 8)
    add #0x40, r4                       ! r4 += 0x40 (64-byte offset into cmd buffer)
.L_do_first_copy:
    jsr @r14                            ! call memcpy_word_idx(r4=dest, r5=src, r6=count)
    nop                                 ! (delay)
    ! --- Second copy: transfer element type block ---
    mov.w   DAT_06010a2a, r6            ! r6 = 0x00C0 (192 words = transfer size)
    mov.l   _pool_elem_type_byte, r5    ! r5 = &element_type_byte
    mov.l   _pool_func_table_base, r3   ! r3 = func_table_base address
    mov.l @r12, r4                      ! r4 = game_state_index
    mov.l @r13, r2                      ! r2 = vdp1_cmd_buf_base value
    mov r6, r1                          ! r1 = 0x00C0 (copy count, used as offset)
    mov.b @r5, r5                       ! r5 = element_type byte value
    shll2 r4                            ! r4 = game_state_index * 4
    add #0x40, r1                       ! r1 = 0x0100 (256 = second block offset)
    extu.b r5, r5                       ! r5 = zero-extend type byte to 32-bit
    shll r4                             ! r4 = game_state_index * 8
    shll2 r5                            ! r5 = element_type * 4
    add r2, r4                          ! r4 = cmd_buf + (state_index * 8)
    add r3, r5                          ! r5 = func_table_base + (type * 4)
    mov.l @r5, r5                       ! r5 = dereference -> source data pointer
    jsr @r14                            ! call memcpy_word_idx(r4=dest, r5=src, r6=count)
    add r1, r4                          ! (delay) r4 += 0x100 (second block dest offset)
    lds.l @r15+, pr                     ! restore return address
    mov.l @r15+, r12                    ! restore r12
    mov.l @r15+, r13                    ! restore r13
    rts                                 ! return to caller
    mov.l @r15+, r14                    ! (delay) restore r14

    .global DAT_06010a2a
DAT_06010a2a:                           ! inline word constant: single-player transfer size
    .2byte  0x00C0                      ! 192 words (0xC0)
_pool_game_state_idx_ptr:               ! -> game state index variable
    .4byte  sym_06059FFC
_pool_vdp1_cmd_buf_ptr:                 ! -> VDP1 command buffer base pointer
    .4byte  sym_06063F5C
_pool_memcpy_word_idx:                  ! -> memcpy_word_idx function
    .4byte  memcpy_word_idx
_pool_split_screen_flag:                ! -> split-screen mode flag byte
    .4byte  sym_06083255
_pool_disp_elem_data_ptr:               ! -> display element data (split-screen path)
    .4byte  sym_0607EAB8
_pool_cmd_table_base:                   ! -> VDP1 command table offset array
    .4byte  sym_0605D0AC
_pool_car_index_ptr:                    ! -> current car index
    .4byte  sym_0607EAD8
_pool_color_table_byte:                 ! -> color/palette table byte (in palette data)
    .4byte  sym_060448B5
_pool_buf_offset_word:                  ! -> display buffer offset (16-bit)
    .4byte  sym_0607886C
_pool_disp_data_base_ptr:               ! -> display data base (single-player path)
    .4byte  sym_06078868
_pool_func_table_base:                  ! -> function/data pointer table for display modes
    .4byte  sym_0605D05C
_pool_elem_type_byte:                   ! -> element type index byte (second copy block)
    .4byte  sym_0607ED91
