/* smpc_peripheral_query.s -- SMPC peripheral status query via CD block HIRQ
 * Translation unit: 0x06035D5A - 0x06035E00
 *
 * Function catalog:
 *   smpc_peripheral_query — Queries CD block status using HIRQ register,
 *                           validates peripheral response, returns error code.
 *
 * This function queries peripheral/CD status through the SCU/CD interface.
 * It reads CD HIRQ (interrupt request register) to check command completion,
 * validates the response, and returns a status code.
 *
 * Arguments:
 *   r4 = HIRQ bit mask (which interrupt bits to check)
 *   r5 = param2 (passed through to sub-calls)
 *   r6 = output buffer pointer (receives peripheral response data)
 *
 * Error codes:
 *   0  = success (peripheral connected and responding)
 *  -1  = HIRQ bits not set (command not completed)
 *  -2  = busy flag set in status
 *  -5  = disconnect marker (0xFF response)
 *  -6  = error flag set (bit 7 of response)
 *
 * Flow:
 *   1. Merge fresh HIRQ bits into cached status word
 *   2. Check if all requested HIRQ bits are set -> -1 if not
 *   3. Check busy flag (bit 0) -> -2 if set
 *   4. Clear busy + requested bits via smpc_cmd_helper_b
 *   5. Issue CD command and read response via input_proc_init helpers
 *   6. Validate response byte: 0xFF -> -5 (disconnect), bit 7 -> -6 (error)
 *   7. On success, clear requested HIRQ bits from cache and return 0
 */

    .section .text.FUN_06035D5A

    .global smpc_peripheral_query
    .type smpc_peripheral_query, @function
smpc_peripheral_query:
    /* ---- Prologue: save callee-saved registers ---- */
    mov.l r14, @-r15               ! push r14 (HIRQ status cache pointer)
    mov.l r13, @-r15               ! push r13 (param2 / response status)
    mov r5, r13                    ! r13 = param2 (peripheral ID or sub-command)
    mov.l r12, @-r15               ! push r12 (HIRQ bit mask)
    mov r4, r12                    ! r12 = requested HIRQ bit mask
    mov.l r11, @-r15               ! push r11 (output buffer pointer)
    sts.l pr, @-r15                ! push return address
    add #-0x4, r15                 ! allocate 4 bytes of stack for local buffer

    /* ---- Read and merge HIRQ status ---- */
    .byte   0xDE, 0x09    /* mov.l .L_hirq_status_cache, r14 */
    .byte   0xD3, 0x09    /* mov.l .L_cd_hirq_reg, r3 */
    mov.w @r14, r2                 ! r2 = cached HIRQ status word
    mov.w @r3, r3                  ! r3 = live CD HIRQ register value
    extu.w r3, r3                  ! zero-extend to 32 bits
    or r3, r2                      ! merge new HIRQ bits into cached value
    mov.w r2, @r14                 ! store merged status back to cache

    /* ---- Test if all requested HIRQ bits are set ---- */
    mov.w @r14, r3                 ! r3 = updated HIRQ status
    extu.w r3, r3                  ! zero-extend to 32 bits
    and r12, r3                    ! isolate only the requested bits
    cmp/eq r12, r3                 ! all requested bits present?
    bt/s    .L_hirq_bits_ready     ! yes -> proceed to busy check
    mov r6, r11                    ! r11 = output buffer pointer (delay slot)
    bra     .L_epilogue_return     ! no -> return error
    mov #-0x1, r0                  ! r0 = -1 (HIRQ not ready)

    /* ---- Constant pool (embedded in code stream) ---- */
    .4byte  0xFF0FFFFF             ! mask constant (unused by this function)
    .4byte  ai_brake_zone_main     ! cross-TU reference (unused by this function)
.L_hirq_status_cache:
    .4byte  sym_06063590           ! pointer to HIRQ status cache word in WRAM
.L_cd_hirq_reg:
    .4byte  0x25890008             ! CD block HIRQ register (memory-mapped I/O)

    /* ---- HIRQ bits matched: check busy flag (bit 0) ---- */
.L_hirq_bits_ready:
    mov.w @r14, r0                 ! r0 = current HIRQ status
    extu.w r0, r0                  ! zero-extend to 32 bits
    tst #0x1, r0                   ! test bit 0 (busy flag)
    bf      .L_not_busy            ! bit 0 clear -> not busy, continue
    bra     .L_epilogue_return     ! bit 0 set -> return busy error
    mov #-0x2, r0                  ! r0 = -2 (busy)

    /* ---- Clear busy + requested HIRQ bits, then read response ---- */
.L_not_busy:
    mov #0x1, r4                   ! r4 = busy bit (bit 0)
    or r12, r4                     ! r4 = busy_bit | requested_bits
    not r4, r4                     ! invert to create clear mask
    .byte   0xBF, 0x60    /* bsr sym_06035C6E (smpc_cmd_helper_b: write HIRQ) */
    extu.w r4, r4                  ! zero-extend mask to 16 bits (delay slot)

    /* ---- Update cached status: clear busy bit ---- */
    mov #-0x2, r2                  ! r2 = 0xFFFFFFFE (clears bit 0)
    mov.w @r14, r3                 ! r3 = cached HIRQ status
    and r2, r3                     ! clear bit 0 (busy flag)
    mov.w r3, @r14                 ! write back updated cache

    /* ---- Issue CD command via input_proc_init helper ---- */
    .byte   0xB0, 0x41    /* bsr 0x06035E3C (CD command issue helper) */
    mov r13, r4                    ! r4 = param2 / peripheral ID (delay slot)

    /* ---- Read command response status ---- */
    mov r15, r5                    ! r5 = stack buffer for response
    .byte   0xB0, 0x20    /* bsr input_proc_init (poll HIRQ for response) */
    mov #0x1, r4                   ! r4 = HIRQ bit to wait for (delay slot)

    /* ---- Check sub-call return status ---- */
    mov r0, r13                    ! r13 = response status from sub-call
    tst r13, r13                   ! status == 0?
    bt      .L_validate_response   ! yes -> validate the peripheral data
    bra     .L_epilogue_return     ! no -> propagate error code
    mov r13, r0                    ! r0 = error code from sub-call (delay slot)

    /* ---- Read and validate peripheral response data ---- */
.L_validate_response:
    .byte   0xB0, 0x48    /* bsr sym_06035E5E (read CD command registers into buffer) */
    mov r11, r4                    ! r4 = output buffer pointer (delay slot)

    /* ---- Check for disconnect (0xFF) ---- */
    mov.b @r11, r4                 ! r4 = first response byte (status/ID)
    .byte   0x93, 0x27    /* mov.w .L_wpool_06035E22, r3 */
    extu.b r4, r2                  ! r2 = unsigned first byte
    cmp/eq r3, r2                  ! response == 0xFF? (peripheral disconnected)
    bf      .L_check_error_bit     ! no -> check error bit
    bra     .L_check_clear_hirq    ! yes -> set disconnect error
    mov #-0x5, r13                 ! r13 = -5 (disconnected) (delay slot)

    /* ---- Check for error flag (bit 7) ---- */
.L_check_error_bit:
    extu.b r4, r0                  ! r0 = unsigned first byte
    tst #0x80, r0                  ! test bit 7 (error flag)
    bt      .L_check_clear_hirq    ! bit 7 clear -> no error, proceed
    mov #-0x6, r13                 ! r13 = -6 (error flag set)

    /* ---- On success (r13==0), clear requested HIRQ bits from cache ---- */
.L_check_clear_hirq:
    tst r13, r13                   ! error code == 0 (success)?
    bf      .L_set_return_value    ! no -> skip HIRQ clearing
    not r12, r12                   ! invert request mask for clearing
    mov.w @r14, r3                 ! r3 = cached HIRQ status
    and r12, r3                    ! clear the bits we consumed
    mov.w r3, @r14                 ! store updated cache

    /* ---- Epilogue: restore registers and return ---- */
.L_set_return_value:
    mov r13, r0                    ! r0 = final return value (error code or 0)
.L_epilogue_return:
    add #0x4, r15                  ! free 4 bytes of stack
    lds.l @r15+, pr                ! restore return address
    mov.l @r15+, r11               ! restore r11
    mov.l @r15+, r12               ! restore r12
    mov.l @r15+, r13               ! restore r13
    rts                            ! return to caller
    mov.l @r15+, r14               ! restore r14 (delay slot)
