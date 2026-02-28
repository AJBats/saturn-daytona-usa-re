/* texture_file_loader -- L3 assembly (SH-2 mnemonics)
 * Translation unit: 0x0601B644 - 0x0601B6DC
 *
 * Texture file selection driven by button input.
 *
 * Reads button flags from the input state struct (g_pad_state+2) and
 * adjusts a texture file index stored at sym_0605D4FA:
 *
 *   - Bits 8-11 (0x0F00) set: clear course state flag (sym_0608600D = 0)
 *     and return immediately — this resets/aborts the texture selection.
 *   - Bit 13 (0x2000) set: increment file index by 5, clamping at 0x14
 *     (wraps to 0 if >= 0x14). Then tail-call replay_record_frame.
 *   - Bit 12 (0x1000) set: decrement file index by 5, clamping at 0
 *     (wraps to 0x0F if negative). Then tail-call replay_record_frame.
 *   - No relevant buttons: return without action.
 *
 * The tail call to replay_record_frame passes:
 *   r4 = scroll param A (byte at sym_0605D4F4)
 *   r5 = scroll param B (byte at sym_0605D4F5)
 *   r6 = adjusted file index (byte at sym_0605D4FA)
 *
 * Key symbols:
 *   sym_0605D4F4  — scroll parameter base (A at +0, B at +1)
 *   sym_0605D4FA  — texture file index / course state flag A
 *   g_pad_state  — input button state struct (+2 = button flags word)
 *   sym_0608600D  — course state flag B (cleared on abort)
 */

    .section .text.FUN_0601B644


    .global texture_file_loader
    .type texture_file_loader, @function
texture_file_loader:
    mov.l r14, @-r15                            ! save r14
    mov.l r13, @-r15                            ! save r13
    mov.l   .L_ptr_scroll_param_base, r13       ! r13 = &scroll_param_base (sym_0605D4F4)
    mov.l   .L_ptr_file_index, r14              ! r14 = &file_index (sym_0605D4FA)
    mov.l   .L_ptr_input_state, r4              ! r4 = &input_state struct (g_pad_state)
    mov.w   .L_mask_dpad_bits, r2               ! r2 = 0x0F00 (D-pad / abort button mask)
    mov.w @(2, r4), r0                          ! r0 = button flags word (struct+2)
    mov r0, r3                                  ! r3 = flags copy
    extu.w r3, r3                               ! zero-extend to 32 bits
    and r2, r3                                  ! isolate bits 8-11
    tst r3, r3                                  ! any D-pad bits set?
    bt/s    .L_check_increment                  ! no abort bits -> check scroll buttons
    mov #0x0, r5                                ! r5 = 0 (used as clear value / param)
    mov.l   .L_ptr_course_state_b, r3           ! r3 = &course_state_flag_B (sym_0608600D)
    bra     .L_return                           ! return after clearing flag
    mov.b r5, @r3                               ! clear course_state_flag_B = 0 (delay slot)
.L_check_increment:
    mov.w @(2, r4), r0                          ! re-read button flags word
    mov.w   .L_mask_btn_increment, r3           ! r3 = 0x2000 (bit 13: increment button)
    mov r0, r2                                  ! r2 = flags copy
    extu.w r2, r2                               ! zero-extend to 32 bits
    and r3, r2                                  ! isolate bit 13
    tst r2, r2                                  ! increment button pressed?
    bt      .L_check_decrement                  ! no -> check decrement button
    mov.b @r14, r3                              ! r3 = current file index
    add #0x5, r3                                ! r3 += 5 (step forward)
    mov.b r3, @r14                              ! store updated index
    mov #0x14, r3                               ! r3 = 0x14 (max file index)
    mov.b @r14, r2                              ! r2 = stored index (re-read)
    cmp/ge r3, r2                               ! index >= max?
    bf      .L_load_params_and_call             ! no overflow -> proceed to tail call
    exts.b r5, r5                               ! r5 = 0 (sign-extended, wrap value)
    mov.b r5, @r14                              ! wrap file index to 0
.L_load_params_and_call:
    mov.b @r14, r6                              ! r6 = file index (adjusted)
    mov.b @(1, r13), r0                         ! r0 = scroll_param_B (byte at base+1)
    mov r0, r5                                  ! r5 = scroll_param_B (arg for tail call)
    mov.b @r13, r4                              ! r4 = scroll_param_A (byte at base+0)
    mov.l @r15+, r13                            ! restore r13
    .byte   0xA1, 0xDF    /* bra 0x0601BA50 (external) */
    mov.l @r15+, r14                            ! restore r14 (delay slot)
.L_check_decrement:
    mov.w @(2, r4), r0                          ! re-read button flags word
    mov.w   .L_mask_btn_decrement, r3           ! r3 = 0x1000 (bit 12: decrement button)
    mov r0, r2                                  ! r2 = flags copy
    extu.w r2, r2                               ! zero-extend to 32 bits
    and r3, r2                                  ! isolate bit 12
    tst r2, r2                                  ! decrement button pressed?
    bt      .L_return                           ! no -> return with no action
    mov.b @r14, r3                              ! r3 = current file index
    add #-0x5, r3                               ! r3 -= 5 (step backward)
    mov.b r3, @r14                              ! store updated index
    mov.b @r14, r2                              ! r2 = stored index (re-read)
    cmp/pz r2                                   ! index >= 0? (non-negative)
    bt      .L_load_params_and_call_b           ! no underflow -> proceed to tail call
    mov #0xF, r2                                ! r2 = 0x0F (wrap-around value)
    mov.b r2, @r14                              ! wrap file index to 0x0F
.L_load_params_and_call_b:
    mov.b @r14, r6                              ! r6 = file index (adjusted)
    mov.b @(1, r13), r0                         ! r0 = scroll_param_B (byte at base+1)
    mov r0, r5                                  ! r5 = scroll_param_B (arg for tail call)
    mov.b @r13, r4                              ! r4 = scroll_param_A (byte at base+0)
    mov.l @r15+, r13                            ! restore r13
    .byte   0xA1, 0xC9    /* bra 0x0601BA50 (external) */
    mov.l @r15+, r14                            ! restore r14 (delay slot)
.L_return:
    mov.l @r15+, r13                            ! restore r13
    rts                                         ! return to caller
    mov.l @r15+, r14                            ! restore r14 (delay slot)
.L_mask_dpad_bits:
    .2byte  0x0F00                              /* bits 8-11: D-pad / abort button mask */
.L_mask_btn_increment:
    .2byte  0x2000                              /* bit 13: file index increment button */
.L_mask_btn_decrement:
    .2byte  0x1000                              /* bit 12: file index decrement button */
    .2byte  0xFFFF                              /* alignment padding */
.L_ptr_scroll_param_base:
    .4byte  sym_0605D4F4                        /* scroll parameter base (+0=A, +1=B) */
.L_ptr_file_index:
    .4byte  sym_0605D4FA                        /* texture file index / course state A */
.L_ptr_input_state:
    .4byte  g_pad_state                        /* input button state struct (+2=flags) */
.L_ptr_course_state_b:
    .4byte  sym_0608600D                        /* course state flag B (cleared on abort) */
