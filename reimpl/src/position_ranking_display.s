/* position_ranking_display -- L3 assembly (SH-2 mnemonics)
 * Translation unit: 0x06011310 - 0x060114AC
 *
 * Position/ranking HUD display — renders the player's race position
 * indicator (1st/2nd/3rd/etc.) as a multi-element sprite group.
 *
 * position_ranking_display (252 bytes, CALL):
 *   Reads the game mode byte and mode config flags to determine how
 *   many display elements to show (3 or 4). Computes a VDP1 command
 *   table offset via the 0x1000 block multiplier. Renders 3 pairs of
 *   sprite elements, selecting active or inactive variants based on
 *   the transmission type flag (AT vs MT). After the first group,
 *   checks transition state to decide whether to render a second
 *   group at an offset of +2 blocks.
 *
 * render_position_elem_14px (18 bytes, LEAF):
 *   Renders a single 14-pixel-wide position digit/icon at VDP1
 *   display offset 0xD000. Tail-calls the HUD element draw function.
 *
 * render_position_elem_16px (18 bytes, LEAF):
 *   Renders a single 16-pixel-wide position digit/icon at VDP1
 *   display offset 0xE000. Tail-calls the HUD element draw function.
 *
 * set_ranking_display_source (24 bytes, LEAF):
 *   Clears the transition state word and loads a display config entry
 *   from the ranking config table into the active display slot.
 *   Called during post-race transition setup.
 */

    .section .text.FUN_06011310


    .global position_ranking_display
    .type position_ranking_display, @function
position_ranking_display:
    mov.l r14, @-r15                        ! save r14
    mov #0x3, r4                            ! r4 = 3 (default element count)
    mov.l r13, @-r15                        ! save r13
    mov.l r12, @-r15                        ! save r12
    mov.l r11, @-r15                        ! save r11
    mov.l r10, @-r15                        ! save r10
    mov.l r9, @-r15                         ! save r9
    sts.l pr, @-r15                         ! save return address
    add #-0x4, r15                          ! allocate 4 bytes on stack (local var)
    mov.l   .L_mode_config_flags, r5        ! r5 = &mode_config_flags
    mov.l   .L_game_mode_byte, r0           ! r0 = &game_mode_byte
    mov.b @r0, r0                           ! r0 = game_mode (8-bit)
    extu.b r0, r0                           ! zero-extend to 32-bit
    cmp/eq #0xB, r0                         ! mode == 0xB? (variant mode)
    bf/s    .L_not_mode_b                   ! if not mode 0xB, branch
    mov r4, r12                             ! r12 = 3 (delay slot: save default count)
    mov.l @r5, r0                           ! r0 = mode_config_flags
    tst #0x1, r0                            ! bit 0 set?
    bt      .L_mode_b_use_4                 ! if bit 0 clear, use 4 elements
    bra     .L_elem_count_set               ! bit 0 set: use default (3)
    mov r12, r11                            ! r11 = 3 (delay slot)
.L_mode_b_use_4:
    bra     .L_elem_count_set               ! jump to common path
    mov #0x4, r11                           ! r11 = 4 elements (delay slot)
.L_not_mode_b:
    mov #0x2, r3                            ! r3 = 2 (threshold)
    mov.l @r5, r11                          ! r11 = mode_config_flags
    and r4, r11                             ! r11 &= 3 (mask bits 0-1)
    cmp/ge r3, r11                          ! flags_masked >= 2?
    bt      .L_elem_count_4                 ! if so, use 4 elements
    bra     .L_elem_count_set               ! else use default (3)
    mov r12, r11                            ! r11 = 3 (delay slot)
.L_elem_count_4:
    mov #0x4, r11                           ! r11 = 4 elements
.L_elem_count_set:
    mov.l   .L_transition_state, r0         ! r0 = &transition_state
    mov.l @r0, r0                           ! r0 = transition_state value
    tst r0, r0                              ! transition active?
    bt      .L_no_transition                ! if zero, no transition — use r11
    bra     .L_begin_draw_group1            ! transition active: use r12
    mov.l r12, @r15                         ! [sp+0] = r12 (delay slot)
.L_no_transition:
    mov.l r11, @r15                         ! [sp+0] = r11 (elem count from flags)
.L_begin_draw_group1:
    mov.l   .L_fn_draw_elem, r13            ! r13 = &draw_element (kept across calls)
    mov.l   .L_disp_struct, r14             ! r14 = &display_struct (kept across calls)
    mov.l @r15, r9                          ! r9 = element count from stack
    mov.w   .L_vdp1_cmd_offset_a, r6        ! r6 = 0x0288 (VDP1 cmd table offset)
    mov.l   .L_sprite_position_a, r5        ! r5 = sprite data for position digit
    mov.l @(4, r14), r7                     ! r7 = disp_struct[1] (VDP1 base addr)
    shll8 r9                                ! r9 <<= 8
    shll2 r9                                ! r9 <<= 2
    shll2 r9                                ! r9 <<= 2  (total: r9 * 0x1000)
    add r9, r7                              ! r7 = VDP1 base + block offset
    jsr @r13                                ! call draw_element(4, sprite, cmd_off, base)
    mov #0x4, r4                            ! r4 = 4 (num VDP1 cmds, delay slot)
    mov.l   .L_trans_type_flag, r10          ! r10 = &transmission_type (kept for reuse)
    mov.l @(4, r14), r7                     ! r7 = VDP1 base addr (reload)
    mov.w   DAT_060113b4, r6                ! r6 = 0x051C (VDP1 cmd offset, elem 2)
    mov.l @r10, r0                          ! r0 = transmission_type flag
    tst r0, r0                              ! is MT (manual)?
    bt/s    .L_use_inactive_sprite_a         ! if zero (MT), use inactive sprite
    add r9, r7                              ! r7 += block offset (delay slot)
    mov.l   .L_sprite_active_a, r5          ! AT: r5 = active sprite data
    bra     .L_draw_elem_2                  ! skip inactive load
    nop                                     ! (delay slot)
.L_use_inactive_sprite_a:
    mov.l   .L_sprite_inactive_a, r5        ! MT: r5 = inactive sprite data
.L_draw_elem_2:
    jsr @r13                                ! call draw_element(4, sprite, cmd_off, base)
    mov #0x4, r4                            ! r4 = 4 (delay slot)
    mov.l @(4, r14), r7                     ! r7 = VDP1 base addr (reload)
    mov.w   .L_vdp1_cmd_offset_c, r6        ! r6 = 0x0518 (VDP1 cmd offset, elem 3)
    mov.l @r10, r0                          ! r0 = transmission_type flag
    tst r0, r0                              ! is MT?
    bt/s    .L_use_inactive_sprite_b         ! if zero (MT), use inactive sprite
    add r9, r7                              ! r7 += block offset (delay slot)
    mov.l   .L_sprite_active_b, r5          ! AT: r5 = active sprite data
    bra     .L_draw_elem_3                  ! skip inactive load
    nop                                     ! (delay slot)
.L_use_inactive_sprite_b:
    mov.l   .L_sprite_inactive_b, r5        ! MT: r5 = inactive sprite data
.L_draw_elem_3:
    jsr @r13                                ! call draw_element(4, sprite, cmd_off, base)
    mov #0x4, r4                            ! r4 = 4 (delay slot)
    mov.l   .L_transition_state, r0         ! r0 = &transition_state
    mov.l @r0, r0                           ! r0 = transition_state value
    cmp/eq #0x1, r0                         ! transition == 1?
    bt      .L_use_alt_elem_count           ! if so, use alt elem count for group 2
    bra     .L_begin_draw_group2            ! else use r12 (original count)
    mov.l r12, @r15                         ! [sp+0] = r12 (delay slot)
.L_vdp1_cmd_offset_a:
    .2byte  0x0288                          /* VDP1 cmd offset: position elem 1 */

    .global DAT_060113b4
DAT_060113b4:
    .2byte  0x051C                          /* VDP1 cmd offset: position elem 2 */
.L_vdp1_cmd_offset_c:
    .2byte  0x0518                          /* VDP1 cmd offset: position elem 3 */
.L_mode_config_flags:
    .4byte  sym_0607EBC8                    /* mode configuration flags (32-bit) */
.L_game_mode_byte:
    .4byte  sym_0607887F                    /* game mode byte (0xB = variant) */
.L_transition_state:
    .4byte  sym_0607EADC                    /* transition state (32-bit) */
.L_fn_draw_elem:
    .4byte  sym_06028400                    /* HUD element draw function */
.L_disp_struct:
    .4byte  sym_06063828                    /* display structure (VDP1 base at +4) */
.L_sprite_position_a:
    .4byte  sym_0605A7FC                    /* position sprite data (group 1) */
.L_trans_type_flag:
    .4byte  sym_06078644                    /* transmission type flag (nonzero = AT) */
.L_sprite_active_a:
    .4byte  sym_0605A9B0                    /* active state sprite (AT, elem 2) */
.L_sprite_inactive_a:
    .4byte  sym_0605A9B8                    /* inactive state sprite (MT, elem 2) */
.L_sprite_active_b:
    .4byte  sym_0605A998                    /* active state sprite (AT, elem 3) */
.L_sprite_inactive_b:
    .4byte  sym_0605A978                    /* inactive state sprite (MT, elem 3) */
.L_use_alt_elem_count:
    mov.l r11, @r15                         ! [sp+0] = r11 (alt elem count)
.L_begin_draw_group2:
    mov.l @r15, r12                         ! r12 = elem count from stack
    mov.l @(4, r14), r7                     ! r7 = VDP1 base addr
    mov.w   DAT_06011462, r6                ! r6 = 0x02B6 (VDP1 cmd offset, elem 4)
    mov.l   .L_sprite_position_b, r5        ! r5 = sprite data for position digit (group 2)
    add #0x2, r12                           ! r12 += 2 (offset to second group)
    shll8 r12                               ! r12 <<= 8
    shll2 r12                               ! r12 <<= 2
    shll2 r12                               ! r12 <<= 2  (total: (count+2) * 0x1000)
    add r12, r7                             ! r7 = VDP1 base + group 2 block offset
    jsr @r13                                ! call draw_element(4, sprite, cmd_off, base)
    mov #0x4, r4                            ! r4 = 4 (delay slot)
    mov.l @(4, r14), r7                     ! r7 = VDP1 base addr (reload)
    mov.w   .L_vdp1_cmd_offset_e, r6        ! r6 = 0x054A (VDP1 cmd offset, elem 5)
    mov.l @r10, r0                          ! r0 = transmission_type flag
    tst r0, r0                              ! is MT?
    bt/s    .L_use_inactive_sprite_c         ! if zero (MT), use inactive sprite
    add r12, r7                             ! r7 += group 2 block offset (delay slot)
    mov.l   .L_sprite_active_c, r5          ! AT: r5 = active sprite data
    bra     .L_draw_elem_5                  ! skip inactive load
    nop                                     ! (delay slot)
.L_use_inactive_sprite_c:
    mov.l   .L_sprite_inactive_c, r5        ! MT: r5 = inactive sprite data
.L_draw_elem_5:
    jsr @r13                                ! call draw_element(4, sprite, cmd_off, base)
    mov #0x4, r4                            ! r4 = 4 (delay slot)
    mov.l @(4, r14), r7                     ! r7 = VDP1 base addr (reload)
    mov.w   DAT_06011466, r6                ! r6 = 0x0546 (VDP1 cmd offset, elem 6)
    mov.l @r10, r0                          ! r0 = transmission_type flag
    tst r0, r0                              ! is MT?
    bt/s    .L_use_inactive_sprite_d         ! if zero (MT), use inactive sprite
    add r12, r7                             ! r7 += group 2 block offset (delay slot)
    mov.l   .L_sprite_active_d, r5          ! AT: r5 = active sprite data
    bra     .L_draw_elem_6                  ! skip inactive load
    nop                                     ! (delay slot)
.L_use_inactive_sprite_d:
    mov.l   .L_sprite_inactive_d, r5        ! MT: r5 = inactive sprite data
.L_draw_elem_6:
    jsr @r13                                ! call draw_element(4, sprite, cmd_off, base)
    mov #0x4, r4                            ! r4 = 4 (delay slot)
    add #0x4, r15                           ! deallocate local var
    lds.l @r15+, pr                         ! restore return address
    mov.l @r15+, r9                         ! restore r9
    mov.l @r15+, r10                        ! restore r10
    mov.l @r15+, r11                        ! restore r11
    mov.l @r15+, r12                        ! restore r12
    mov.l @r15+, r13                        ! restore r13
    rts                                     ! return
    mov.l @r15+, r14                        ! restore r14 (delay slot)

    .global sym_0601143E
sym_0601143E:                               ! render_position_elem_14px
    mov.l   .L_disp_struct_b, r7            ! r7 = &display_struct
    mov.l @(4, r7), r7                      ! r7 = disp_struct[1] (VDP1 base addr)
    mov.l   .L_offset_0xD000, r3            ! r3 = 0xD000
    add r3, r7                              ! r7 = VDP1 base + 0xD000
    mov #0xE, r6                            ! r6 = 14 (element width in pixels)
    mov.l   .L_sprite_elem_14px, r5         ! r5 = sprite data for 14px element
    mov.l   .L_fn_draw_elem_b, r3           ! r3 = &draw_element
    jmp @r3                                 ! tail-call draw_element(4, sprite, 14, base)
    mov #0x4, r4                            ! r4 = 4 (num VDP1 cmds, delay slot)

    .global sym_06011450
sym_06011450:                               ! render_position_elem_16px
    mov.l   .L_disp_struct_b, r7            ! r7 = &display_struct
    mov.l @(4, r7), r7                      ! r7 = disp_struct[1] (VDP1 base addr)
    mov.l   .L_mask_0xE000, r3              ! r3 = 0xE000
    add r3, r7                              ! r7 = VDP1 base + 0xE000
    mov #0x10, r6                           ! r6 = 16 (element width in pixels)
    mov.l   .L_sprite_elem_16px, r5         ! r5 = sprite data for 16px element
    mov.l   .L_fn_draw_elem_b, r3           ! r3 = &draw_element
    jmp @r3                                 ! tail-call draw_element(4, sprite, 16, base)
    mov #0x4, r4                            ! r4 = 4 (num VDP1 cmds, delay slot)

    .global DAT_06011462
DAT_06011462:
    .2byte  0x02B6                          /* VDP1 cmd offset: position elem 4 */
.L_vdp1_cmd_offset_e:
    .2byte  0x054A                          /* VDP1 cmd offset: position elem 5 */

    .global DAT_06011466
DAT_06011466:
    .2byte  0x0546                          /* VDP1 cmd offset: position elem 6 */
.L_sprite_position_b:
    .4byte  sym_0605A8B6                    /* position sprite data (group 2) */
.L_sprite_active_c:
    .4byte  sym_0605A9B0                    /* active state sprite (AT, elem 5) */
.L_sprite_inactive_c:
    .4byte  sym_0605A9B8                    /* inactive state sprite (MT, elem 5) */
.L_sprite_active_d:
    .4byte  sym_0605A9A0                    /* active state sprite (AT, elem 6) */
.L_sprite_inactive_d:
    .4byte  sym_0605A980                    /* inactive state sprite (MT, elem 6) */
.L_disp_struct_b:
    .4byte  sym_06063828                    /* display structure (VDP1 base at +4) */
.L_offset_0xD000:
    .4byte  0x0000D000                      /* VDP1 display offset for 14px elem */
.L_sprite_elem_14px:
    .4byte  sym_0605A634                    /* sprite data for 14-pixel position icon */
.L_fn_draw_elem_b:
    .4byte  sym_06028400                    /* HUD element draw function */
.L_mask_0xE000:
    .4byte  0x0000E000                      /* VDP1 display offset for 16px elem */
.L_sprite_elem_16px:
    .4byte  sym_0605A718                    /* sprite data for 16-pixel position icon */

    .global sym_06011494
sym_06011494:                               ! set_ranking_display_source(r4 = index)
    extu.w r4, r0                           ! r0 = index (zero-extend 16-bit)
    mov #0x0, r2                            ! r2 = 0 (clear value)
    .byte   0xD1, 0x19    /* mov.l [transition_state_ptr], r1 */   ! r1 = &transition_state
    .byte   0xD3, 0x18    /* mov.l [ranking_config_table], r3 */   ! r3 = ranking_config_table base
    shll2 r0                                ! r0 <<= 2
    mov.l r2, @r1                           ! *transition_state = 0 (clear)
    shll2 r0                                ! r0 <<= 2  (total: index * 16)
    .byte   0xD1, 0x18    /* mov.l [active_display_slot], r1 */    ! r1 = &active_display_slot
    add r3, r0                              ! r0 = &config_table[index]
    mov.l @r0, r2                           ! r2 = config_table[index]
    rts                                     ! return
    mov.l r2, @r1                           ! *active_display_slot = r2 (delay slot)
