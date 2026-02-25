/* sprite_anim_update -- L3 assembly (SH-2 mnemonics)
 * Translation unit: 0x060266CC - 0x060268B0
 *
 * Menu selection/confirmation sprite animation handler.
 * Manages the "OK" / "CANCEL" text display and processes directional
 * input to cycle through menu options (game mode selection).
 *
 * On entry:
 *   - Renders "OK" text (sym_0605912C) and "CANCEL" text (sym_06059134)
 *     via geom_dispatch_final (sym_060284AE) with display list size 0x0090.
 *   - Reads button state from sym_06063D9A (16-bit input bitfield).
 *
 * Button dispatch logic (sym_06063D9A bitfield):
 *   0x0000          : No input — skip to slot-count check.
 *   0x0E00 bits set : Selection confirm — check if game_mode == 0x12;
 *                     set/clear palette pending flag (sym_06089ED8),
 *                     write anim state (sym_06061198), render main dlist,
 *                     and re-render blank text strings to clear the labels.
 *   0x0100 exact    : Accept — clear pending flag, write anim state,
 *                     render main dlist and blank text strings.
 *   0x1000          : Scroll up — render main dlist, decrement game_mode by 2.
 *   0x2000          : Scroll down — render main dlist, increment game_mode by 2.
 *
 * Game mode (sym_06089EDA word) is clamped to [0x12, 0x14].
 * Values outside this range wrap to the opposite bound.
 *
 * Final rendering:
 *   If slot_count (sym_06089EC6) bit 2 is set: render current selection
 *   via geom_dispatch_final and return normally.
 *   Otherwise: tail-call display_list_loader (sym_06028400) through
 *   dlist entry struct (sym_06063B88).
 *
 * Display list index formula:
 *   dlist_offset = (game_mode * 64 + 0x11) * 2
 *   (computed by shll2 x3, add #0x11, shll)
 *
 * Calls: sym_060284AE (geom_dispatch_final), sym_06028400 (display_list_loader)
 */

    .section .text.FUN_060266CC


    .global sprite_anim_update
    .type sprite_anim_update, @function
sprite_anim_update:
    mov.l r14, @-r15                ! save r14 (game_mode_ptr)
    mov.l r13, @-r15                ! save r13 (dlist_size = 0x0090)
    mov.l r12, @-r15                ! save r12 (geom_dispatch_final)
    mov.l r11, @-r15                ! save r11 (button_state value)
    mov.l r10, @-r15                ! save r10 (blank_text_ptr)
    mov.l r9, @-r15                 ! save r9 (cancel_text_offset = 0x0A26)
    mov.l r8, @-r15                 ! save r8 (ok_text_offset = 0x0926)
    sts.l pr, @-r15                 ! save return address
    add #-0x4, r15                  ! allocate 4 bytes on stack
    mov.l   _pool_blank_text, r10   ! r10 = &blank_text "  " (sym_06059128)
    mov.l   _pool_geom_dispatch, r12 ! r12 = &geom_dispatch_final (sym_060284AE)
    mov.w   _wpool_dlist_size, r13  ! r13 = 0x0090 (display list size param)
    mov.l   _pool_game_mode_ptr, r14 ! r14 = &game_mode word (sym_06089EDA)
    mov.w   DAT_0602672a, r8       ! r8 = 0x0926 (OK text display list offset)
    mov.l   _pool_ok_text, r7      ! r7 = &ok_text "  OK" (sym_0605912C)
    mov r13, r6                     ! r6 = 0x0090 (dlist size)
    mov r8, r5                      ! r5 = 0x0926 (OK text dlist offset)
    jsr @r12                        ! call geom_dispatch_final(0x8, 0x0926, 0x0090, &ok_text)
    mov #0x8, r4                    ! r4 = 0x8 (render layer) [delay slot]
    mov r13, r6                     ! r6 = 0x0090 (dlist size)
    mov.w   DAT_0602672c, r9       ! r9 = 0x0A26 (CANCEL text display list offset)
    mov.l   _pool_cancel_text, r7  ! r7 = &cancel_text "CANCEL" (sym_06059134)
    mov r9, r5                      ! r5 = 0x0A26 (CANCEL text dlist offset)
    jsr @r12                        ! call geom_dispatch_final(0x8, 0x0A26, 0x0090, &cancel_text)
    mov #0x8, r4                    ! r4 = 0x8 (render layer) [delay slot]
    mov.l   _pool_button_state, r11 ! r11 = &button_state word (sym_06063D9A)
    mov.w @r11, r11                 ! r11 = button_state value (16-bit)
    extu.w r11, r3                  ! r3 = button_state zero-extended
    tst r3, r3                      ! test button_state == 0
    bf      .L_has_input            ! if button_state != 0: process input
    bra     .L_check_slot_count     ! no input — skip to slot-count check
    nop                             ! delay slot
.L_has_input:
    mov.l   _pool_anim_state, r6   ! r6 = &anim_state byte (sym_06061198)
    extu.w r11, r3                  ! r3 = button_state zero-extended
    mov.w   DAT_0602672e, r2       ! r2 = 0x0E00 (confirm button mask)
    mov.l   _pool_palette_pending, r4 ! r4 = &palette_pending flag word (sym_06089ED8)
    and r2, r3                      ! r3 = button_state & 0x0E00
    tst r3, r3                      ! test confirm bits
    bt/s    .L_check_accept         ! if no confirm bits: check accept/scroll
    mov #0x6, r5                    ! r5 = 0x6 (anim state value for confirm) [delay slot]
    mov.w @r14, r0                  ! r0 = game_mode value (16-bit)
    extu.w r0, r0                   ! r0 = game_mode zero-extended
    cmp/eq #0x12, r0                ! test game_mode == 0x12 (first option)
    bf      .L_not_first_option     ! if game_mode != 0x12: pending = 0
    bra     .L_set_pending_flag     ! game_mode == 0x12: pending = 1
    mov #0x1, r3                    ! r3 = 1 (pending flag = set) [delay slot]
_wpool_dlist_size:
    .2byte  0x0090                  /* display list size parameter */

    .global DAT_0602672a
DAT_0602672a:
    .2byte  0x0926                  /* OK text display list offset */

    .global DAT_0602672c
DAT_0602672c:
    .2byte  0x0A26                  /* CANCEL text display list offset */

    .global DAT_0602672e
DAT_0602672e:
    .2byte  0x0E00                  /* confirm button mask (A/B/C buttons) */
_pool_blank_text:
    .4byte  sym_06059128            /* blank text "  " */
_pool_geom_dispatch:
    .4byte  sym_060284AE            /* geom_dispatch_final function */
_pool_game_mode_ptr:
    .4byte  sym_06089EDA            /* game mode (word) */
_pool_ok_text:
    .4byte  sym_0605912C            /* "  OK" text string */
_pool_cancel_text:
    .4byte  sym_06059134            /* "CANCEL" text string */
_pool_button_state:
    .4byte  sym_06063D9A            /* button state register (word) */
_pool_anim_state:
    .4byte  sym_06061198            /* animation state byte */
_pool_palette_pending:
    .4byte  sym_06089ED8            /* palette copy pending flag (word) */
.L_not_first_option:
    mov #0x0, r3                    ! r3 = 0 (pending flag = clear, not first option)
.L_set_pending_flag:
    mov r10, r7                     ! r7 = &blank_text (texture ptr for main dlist)
    mov.w r3, @r4                   ! palette_pending = r3 (1 if first option, 0 otherwise)
    mov.b r5, @r6                   ! anim_state = 0x6 (confirm animation)
    mov r13, r6                     ! r6 = 0x0090 (dlist size)
    mov.w @r14, r5                  ! r5 = game_mode value (16-bit)
    extu.w r5, r5                   ! r5 = game_mode zero-extended
    shll2 r5                        ! r5 = game_mode * 4
    shll2 r5                        ! r5 = game_mode * 16
    shll2 r5                        ! r5 = game_mode * 64
    add #0x11, r5                   ! r5 = game_mode * 64 + 0x11
    shll r5                         ! r5 = (game_mode * 64 + 0x11) * 2 = dlist offset
    jsr @r12                        ! call geom_dispatch_final(0x8, dlist_offset, 0x0090, &blank_text)
    mov #0x8, r4                    ! r4 = 0x8 (render layer) [delay slot]
    mov.l   _pool_clear_text_a, r7 ! r7 = &clear_text_a "    " (sym_0605913C)
    mov r13, r6                     ! r6 = 0x0090 (dlist size)
    mov r8, r5                      ! r5 = 0x0926 (OK text dlist offset)
    jsr @r12                        ! call geom_dispatch_final(0x8, 0x0926, 0x0090, &clear_text_a) — blank OK slot
    mov #0x8, r4                    ! r4 = 0x8 (render layer) [delay slot]
    mov r13, r6                     ! r6 = 0x0090 (dlist size)
    mov r9, r5                      ! r5 = 0x0A26 (CANCEL text dlist offset)
    mov.l   _pool_clear_text_b, r7 ! r7 = &clear_text_b "      " (sym_06059144)
    jsr @r12                        ! call geom_dispatch_final(0x8, 0x0A26, 0x0090, &clear_text_b) — blank CANCEL slot
    mov #0x8, r4                    ! r4 = 0x8 (render layer) [delay slot]
    bra     .L_epilogue_return      ! done — go to normal return
    nop                             ! delay slot
.L_check_accept:
    extu.w r11, r3                  ! r3 = button_state zero-extended
    mov.w   _wpool_accept_mask, r2 ! r2 = 0x0100 (accept/start button mask)
    cmp/eq r2, r3                   ! test button_state == 0x0100 (exact match)
    bf      .L_check_scroll_up      ! if not accept: check scroll buttons
    mov #0x0, r2                    ! r2 = 0 (clear pending flag)
    mov r10, r7                     ! r7 = &blank_text (texture ptr for main dlist)
    mov.w r2, @r4                   ! palette_pending = 0 (accepted, clear flag)
    mov.b r5, @r6                   ! anim_state = 0x6 (accept animation)
    mov r13, r6                     ! r6 = 0x0090 (dlist size)
    mov.w @r14, r5                  ! r5 = game_mode value (16-bit)
    extu.w r5, r5                   ! r5 = game_mode zero-extended
    shll2 r5                        ! r5 = game_mode * 4
    shll2 r5                        ! r5 = game_mode * 16
    shll2 r5                        ! r5 = game_mode * 64
    add #0x11, r5                   ! r5 = game_mode * 64 + 0x11
    shll r5                         ! r5 = (game_mode * 64 + 0x11) * 2 = dlist offset
    jsr @r12                        ! call geom_dispatch_final(0x8, dlist_offset, 0x0090, &blank_text)
    mov #0x8, r4                    ! r4 = 0x8 (render layer) [delay slot]
    mov r13, r6                     ! r6 = 0x0090 (dlist size)
    mov r8, r5                      ! r5 = 0x0926 (OK text dlist offset)
    mov.l   _pool_clear_text_a, r7 ! r7 = &clear_text_a "    " (sym_0605913C)
    jsr @r12                        ! call geom_dispatch_final(0x8, 0x0926, 0x0090, &clear_text_a) — blank OK slot
    mov #0x8, r4                    ! r4 = 0x8 (render layer) [delay slot]
    mov.l   _pool_clear_text_b, r7 ! r7 = &clear_text_b "      " (sym_06059144)
    mov r13, r6                     ! r6 = 0x0090 (dlist size)
    mov r9, r5                      ! r5 = 0x0A26 (CANCEL text dlist offset)
    jsr @r12                        ! call geom_dispatch_final(0x8, 0x0A26, 0x0090, &clear_text_b) — blank CANCEL slot
    mov #0x8, r4                    ! r4 = 0x8 (render layer) [delay slot]
    bra     .L_epilogue_return      ! done — go to normal return
    nop                             ! delay slot
.L_check_scroll_up:
    extu.w r11, r3                  ! r3 = button_state zero-extended
    mov.w   DAT_0602684a, r2       ! r2 = 0x1000 (up/scroll-up button mask)
    cmp/eq r2, r3                   ! test button_state == 0x1000
    bf      .L_check_scroll_down    ! if not scroll-up: check scroll-down
    mov r10, r7                     ! r7 = &blank_text (texture ptr for main dlist)
    mov r13, r6                     ! r6 = 0x0090 (dlist size)
    mov.w @r14, r5                  ! r5 = game_mode value (16-bit)
    extu.w r5, r5                   ! r5 = game_mode zero-extended
    shll2 r5                        ! r5 = game_mode * 4
    shll2 r5                        ! r5 = game_mode * 16
    shll2 r5                        ! r5 = game_mode * 64
    add #0x11, r5                   ! r5 = game_mode * 64 + 0x11
    shll r5                         ! r5 = (game_mode * 64 + 0x11) * 2 = dlist offset
    jsr @r12                        ! call geom_dispatch_final(0x8, dlist_offset, 0x0090, &blank_text) — clear current
    mov #0x8, r4                    ! r4 = 0x8 (render layer) [delay slot]
    mov.w @r14, r3                  ! r3 = game_mode value (16-bit)
    add #-0x2, r3                   ! r3 = game_mode - 2 (scroll up one option)
    mov.w r3, @r14                  ! game_mode -= 2 (write back)
.L_check_scroll_down:
    extu.w r11, r11                 ! r11 = button_state zero-extended (final use)
    mov.w   _wpool_scroll_down_mask, r2 ! r2 = 0x2000 (down/scroll-down button mask)
    cmp/eq r2, r11                  ! test button_state == 0x2000
    bf      .L_clamp_game_mode      ! if not scroll-down: go to clamping
    mov r10, r7                     ! r7 = &blank_text (texture ptr for main dlist)
    mov r13, r6                     ! r6 = 0x0090 (dlist size)
    mov.w @r14, r5                  ! r5 = game_mode value (16-bit)
    extu.w r5, r5                   ! r5 = game_mode zero-extended
    shll2 r5                        ! r5 = game_mode * 4
    shll2 r5                        ! r5 = game_mode * 16
    shll2 r5                        ! r5 = game_mode * 64
    add #0x11, r5                   ! r5 = game_mode * 64 + 0x11
    shll r5                         ! r5 = (game_mode * 64 + 0x11) * 2 = dlist offset
    jsr @r12                        ! call geom_dispatch_final(0x8, dlist_offset, 0x0090, &blank_text) — clear current
    mov #0x8, r4                    ! r4 = 0x8 (render layer) [delay slot]
    mov.w @r14, r3                  ! r3 = game_mode value (16-bit)
    add #0x2, r3                    ! r3 = game_mode + 2 (scroll down one option)
    mov.w r3, @r14                  ! game_mode += 2 (write back)
.L_clamp_game_mode:
    mov.w @r14, r2                  ! r2 = game_mode value (16-bit)
    mov #0x14, r3                   ! r3 = 0x14 (upper bound for game mode)
    extu.w r2, r2                   ! r2 = game_mode zero-extended
    cmp/gt r3, r2                   ! test game_mode > 0x14
    bf      .L_check_lower_bound    ! if game_mode <= 0x14: check lower bound
    mov #0x12, r3                   ! r3 = 0x12 (wrap to lower bound)
    mov.w r3, @r14                  ! game_mode = 0x12 (wrap around from top)
.L_check_lower_bound:
    mov #0x12, r3                   ! r3 = 0x12 (lower bound for game mode)
    mov.w @r14, r2                  ! r2 = game_mode value (16-bit)
    extu.w r2, r2                   ! r2 = game_mode zero-extended
    cmp/ge r3, r2                   ! test game_mode >= 0x12
    bt      .L_check_slot_count     ! if game_mode >= 0x12: in range, proceed
    mov #0x14, r3                   ! r3 = 0x14 (wrap to upper bound)
    mov.w r3, @r14                  ! game_mode = 0x14 (wrap around from bottom)
.L_check_slot_count:
    mov.l   _pool_slot_count, r0   ! r0 = &slot_count word (sym_06089EC6)
    mov.w @r0, r0                   ! r0 = slot_count value (16-bit)
    extu.w r0, r0                   ! r0 = slot_count zero-extended
    tst #0x4, r0                    ! test bit 2 of slot_count
    bt      .L_tailcall_dlist_loader ! if bit 2 clear: tail-call display_list_loader
    mov r10, r7                     ! r7 = &blank_text (texture ptr for main dlist)
    mov r13, r6                     ! r6 = 0x0090 (dlist size)
    mov.w @r14, r5                  ! r5 = game_mode value (16-bit)
    extu.w r5, r5                   ! r5 = game_mode zero-extended
    shll2 r5                        ! r5 = game_mode * 4
    shll2 r5                        ! r5 = game_mode * 16
    shll2 r5                        ! r5 = game_mode * 64
    add #0x11, r5                   ! r5 = game_mode * 64 + 0x11
    shll r5                         ! r5 = (game_mode * 64 + 0x11) * 2 = dlist offset
    jsr @r12                        ! call geom_dispatch_final(0x8, dlist_offset, 0x0090, &blank_text) — render selection
    mov #0x8, r4                    ! r4 = 0x8 (render layer) [delay slot]
    bra     .L_epilogue_return      ! done — go to normal return
    nop                             ! delay slot
_wpool_accept_mask:
    .2byte  0x0100                  /* accept/start button exact match */

    .global DAT_0602684a
DAT_0602684a:
    .2byte  0x1000                  /* scroll-up button mask */
_wpool_scroll_down_mask:
    .2byte  0x2000                  /* scroll-down button mask */
    .2byte  0xFFFF                  /* pool alignment padding */
_pool_clear_text_a:
    .4byte  sym_0605913C            /* blank text "    " (clears OK slot) */
_pool_clear_text_b:
    .4byte  sym_06059144            /* blank text "      " (clears CANCEL slot) */
_pool_slot_count:
    .4byte  sym_06089EC6            /* slot count (word) */
.L_tailcall_dlist_loader:
    mov.l   _pool_dlist_entry, r2  ! r2 = &dlist_entry struct (sym_06063B88)
    mov.l r2, @r15                  ! stack[0] = &dlist_entry (save for field access)
    mov r2, r7                      ! r7 = &dlist_entry (texture field access)
    mov.w   DAT_060268a6, r3       ! r3 = 0x7000 (VRAM base offset)
    mov.w @r14, r6                  ! r6 = game_mode value (16-bit)
    mov.l @(4, r7), r7              ! r7 = dlist_entry.field4 (source base ptr)
    extu.w r6, r6                   ! r6 = game_mode zero-extended
    add r3, r7                      ! r7 = source_base + 0x7000 (VRAM destination)
    shll2 r6                        ! r6 = game_mode * 4
    shll2 r6                        ! r6 = game_mode * 16
    shll2 r6                        ! r6 = game_mode * 64
    add #0x11, r6                   ! r6 = game_mode * 64 + 0x11
    shll r6                         ! r6 = (game_mode * 64 + 0x11) * 2 = dlist index
    mov r2, r5                      ! r5 = &dlist_entry (source ptr field access)
    mov.l @r5, r5                   ! r5 = dlist_entry.field0 (source data ptr)
    mov #0x8, r4                    ! r4 = 0x8 (copy mode)
    add #0x4, r15                   ! deallocate stack frame
    lds.l @r15+, pr                 ! restore return address (not used — tailcall)
    mov.l @r15+, r8                 ! restore r8
    mov.l @r15+, r9                 ! restore r9
    mov.l @r15+, r10                ! restore r10
    mov.l @r15+, r11                ! restore r11
    mov.l @r15+, r12                ! restore r12
    mov.l @r15+, r13                ! restore r13
    mov.l   _pool_dlist_loader, r3 ! r3 = &display_list_loader (sym_06028400)
    jmp @r3                         ! tail-call display_list_loader(0x8, src_ptr, dlist_idx, vram_dest)
    mov.l @r15+, r14                ! restore r14 [delay slot]
.L_epilogue_return:
    add #0x4, r15                   ! deallocate stack frame
    lds.l @r15+, pr                 ! restore return address
    mov.l @r15+, r8                 ! restore r8
    mov.l @r15+, r9                 ! restore r9
    mov.l @r15+, r10                ! restore r10
    mov.l @r15+, r11                ! restore r11
    mov.l @r15+, r12                ! restore r12
    mov.l @r15+, r13                ! restore r13
    rts                             ! return to caller
    mov.l @r15+, r14                ! restore r14 [delay slot]

    .global DAT_060268a6
DAT_060268a6:
    .2byte  0x7000                  /* VRAM base offset for dlist copy */
_pool_dlist_entry:
    .4byte  sym_06063B88            /* display list entry struct */
_pool_dlist_loader:
    .4byte  sym_06028400            /* display_list_loader function */
