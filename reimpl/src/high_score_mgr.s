/* high_score_mgr -- L3 assembly (SH-2 mnemonics)
 * Translation unit: 0x0603C10C - 0x0603C1A8
 *
 * High score table manager. Initializes the score table display by setting up
 * VDP2 display channels via the display orchestrator, registering five render
 * callbacks, then clearing every entry in the score table array to zero.
 * Also contains a utility to extract a 2-bit display mode field from a
 * VDP2 control register.
 */

    .section .text.FUN_0603C10C


    .global high_score_mgr
    .type high_score_mgr, @function
high_score_mgr:
    sts.l pr, @-r15                         ! save return address
    mov.l   .L_pool_score_table_base, r12   ! r12 = base ptr to score table array
    .byte   0xB6, 0x24    /* bsr 0x0603CD5C — display orchestrator: sets up VDP2 channels */
    mov #0x0, r14                           ! r14 = 0 (clear value; delay slot of bsr)
    mov.l   .L_pool_render_credits_stub, r3 ! r3 = render_credits_stub
    jsr @r3                                 ! register credits render callback
    nop                                     !
    mov.l   .L_pool_bus_lock_table_ctrl, r3 ! r3 = bus_lock_table_ctrl
    jsr @r3                                 ! register bus lock table callback
    nop                                     !
    mov.l   .L_pool_display_nop_stub_a, r3  ! r3 = display_nop_stub_a
    jsr @r3                                 ! register display stub A callback
    nop                                     !
    mov.l   .L_pool_display_nop_stub_b, r3  ! r3 = display_nop_stub_b
    jsr @r3                                 ! register display stub B callback
    nop                                     !
    mov.l   .L_pool_display_element_draw, r3 ! r3 = display_element_draw
    jsr @r3                                 ! register element draw callback
    nop                                     !
    extu.b r14, r4                          ! r4 = 0 (loop index, byte-clamped)
.L_clear_loop:
    extu.b r4, r0                           ! r0 = index (zero-extended byte)
    shll2 r0                                ! r0 *= 4 (byte offset for 32-bit entry)
    add #0x1, r4                            ! r4++ (advance index)
    extu.b r4, r3                           ! r3 = next index (byte-clamped)
    cmp/ge r13, r3                          ! T = (r3 >= r13)? i.e. done if index >= entry count
    bf/s    .L_clear_loop                   ! loop if not done
    mov.l r14, @(r0, r12)                   ! score_table[r0] = 0 (delay slot: write zero)
    mov #0x0, r2                            ! r2 = 0
    mov.l   .L_pool_score_state_word, r3    ! r3 = &score_state_word
    mov.l r2, @r3                           ! score_state_word = 0 (reset state)
    mov.l   .L_pool_score_active_flag, r2   ! r2 = &score_active_flag
    mov.b r14, @r2                          ! score_active_flag = 0 (mark inactive)
    lds.l @r15+, pr                         ! restore return address
    mov.l @r15+, r12                        ! restore r12 (caller-saved on shared frame)
    mov.l @r15+, r13                        ! restore r13 (caller-saved on shared frame)
    rts                                     ! return
    mov.l @r15+, r14                        ! restore r14 (delay slot; caller-saved)

    .global sym_0603C156
    ! Extract 2-bit display mode field (bits 12-13) from VDP2 control register.
    ! Returns sign-extended field value in r0.
sym_0603C156:
    mov.l   .L_pool_display_mode_reg, r0    ! r0 = &display_mode_reg
    mov.w   .L_wpool_mode_field_mask, r3    ! r3 = 0x3000 (mask for bits 12-13)
    mov.w @r0, r0                           ! r0 = read 16-bit register value
    extu.w r0, r0                           ! zero-extend to 32 bits
    and r3, r0                              ! isolate bits 12-13
    shar r0                                 ! arithmetic right shift 1 (bit 12 -> bit 11)
    shar r0                                 ! arithmetic right shift 2
    shar r0                                 ! arithmetic right shift 3
    shar r0                                 ! arithmetic right shift 4
    shar r0                                 ! arithmetic right shift 5
    shar r0                                 ! arithmetic right shift 6
    shar r0                                 ! arithmetic right shift 7
    shar r0                                 ! arithmetic right shift 8
    shar r0                                 ! arithmetic right shift 9
    shar r0                                 ! arithmetic right shift 10
    shar r0                                 ! arithmetic right shift 11
    rts                                     ! return; r0 = extracted mode field (0-3)
    shar r0                                 ! arithmetic right shift 12 (delay slot)
.L_wpool_mode_field_mask:
    .2byte  0x3000                          ! mask for bits 12-13 of display mode register
.L_pool_score_table_base:
    .4byte  sym_060A4D60                    ! base address of score table array in WRAM
.L_pool_render_credits_stub:
    .4byte  render_credits_stub             ! credits render callback
.L_pool_bus_lock_table_ctrl:
    .4byte  bus_lock_table_ctrl             ! bus lock table control callback
.L_pool_display_nop_stub_a:
    .4byte  display_nop_stub_a              ! display no-op stub A callback
.L_pool_display_nop_stub_b:
    .4byte  display_nop_stub_b              ! display no-op stub B callback
.L_pool_display_element_draw:
    .4byte  display_element_draw            ! display element draw callback
.L_pool_score_state_word:
    .4byte  sym_060A4D80                    ! 32-bit score system state word
.L_pool_score_active_flag:
    .4byte  sym_060A4DA6                    ! 8-bit score system active flag
.L_pool_display_mode_reg:
    .4byte  sym_060A3D96                    ! 16-bit VDP2 display mode register
    .4byte  0xE300D227                      ! (next TU prologue / padding data)
    .4byte  0x000B2230                      ! (next TU prologue / padding data)
