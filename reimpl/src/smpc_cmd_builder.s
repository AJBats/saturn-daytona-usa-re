/* smpc_cmd_builder -- SMPC command issue and secondary SH-2 boot
 * Translation unit: 0x06034E24 - 0x06034F08
 *
 * Function catalog:
 *   smpc_cmd_builder      -- Body of SMPC INTBACK request builder (entry via smpc_cmd_init).
 *                            Fills a stack buffer with INTBACK parameters, calls
 *                            input_proc_analog to send the request, then calls
 *                            input_proc_buttons to process the peripheral response.
 *
 *   sym_06034E58           -- Secondary SH-2 boot + INTBACK sequence.
 *                            1) Sends SSHON (0x03) to start the secondary SH-2
 *                            2) Installs slave_main_loop as its callback
 *                            3) Sends INTBACK (0x02) to begin peripheral polling
 *                            Polls SMPC SF (status flag) between each command.
 *
 * SMPC register map (odd-byte addressed at 0x20100001):
 *   COMREG = 0x2010001F  (command register)
 *   SF     = 0x20100063  (status flag — bit 0: 1=busy, 0=ready)
 */

    .section .text.FUN_06034E24


/* smpc_cmd_builder(r14 = peripheral_id)
 * Called after smpc_cmd_init saves r14 and copies r4 into r14.
 * Builds an 8-byte INTBACK parameter buffer on the stack:
 *   buffer[0] = 0x12  (IREG0: request peripheral data, optimized)
 *   buffer[1] = peripheral_id (IREG1: continuation/port selector)
 * Then dispatches the SMPC request and reads back peripheral state.
 */
    .global smpc_cmd_builder
    .type smpc_cmd_builder, @function
smpc_cmd_builder:
    sts.l pr, @-r15                 ! save return address
    add #-0x8, r15                  ! allocate 8-byte stack buffer for INTBACK params
    mov.l   _pool_input_proc_analog, r3 ! r3 = &input_proc_analog
    jsr @r3                         ! call input_proc_analog(buffer_ptr)
    mov r15, r4                     ! r4 = buffer_ptr (delay slot)
    mov r15, r2                     ! r2 = buffer_ptr
    mov #0x12, r3                   ! r3 = 0x12 (IREG0: peripheral status request)
    extu.b r14, r14                 ! zero-extend peripheral_id to byte
    mov r15, r5                     ! r5 = buffer_ptr (unused arg or side effect)
    mov.b r3, @r2                   ! buffer[0] = 0x12 (IREG0)
    mov r14, r0                     ! r0 = peripheral_id
    mov r15, r2                     ! r2 = buffer_ptr
    mov.b r0, @(1, r2)             ! buffer[1] = peripheral_id (IREG1)
    mov.l   _pool_input_proc_buttons, r3 ! r3 = &input_proc_buttons
    jsr @r3                         ! call input_proc_buttons(0) — process SMPC response
    mov #0x0, r4                    ! r4 = 0 (delay slot: first call, no continuation)
    mov r0, r4                      ! r4 = result from input_proc_buttons (unused)
    add #0x8, r15                   ! free 8-byte stack buffer
    lds.l @r15+, pr                 ! restore return address
    rts                             ! return to caller
    mov.l @r15+, r14                ! restore r14 (delay slot, saved by smpc_cmd_init)
    .2byte  0xFFFF                  ! alignment padding
_pool_input_proc_analog:
    .4byte  input_proc_analog       ! -> input_proc_analog (SMPC request setup)
_pool_input_proc_buttons:
    .4byte  input_proc_buttons      ! -> input_proc_buttons (SMPC response handler)

/* sym_06034E58() — Boot secondary SH-2 and start INTBACK peripheral polling
 *
 * Sequence:
 *   1. Clear secondary SH-2 state flag
 *   2. Poll SF until SMPC is ready
 *   3. Write SF=1 (acknowledge), send SSHON (0x03) to COMREG
 *   4. Poll SF until SSHON completes
 *   5. Busy-wait 1000 iterations (let secondary SH-2 initialize)
 *   6. Install slave_main_loop as secondary callback
 *   7. Write SF=1, send INTBACK (0x02) to COMREG
 *   8. Poll SF until INTBACK completes
 *   9. Return
 */
    .global sym_06034E58
sym_06034E58:
    add #-0x4, r15                  ! allocate 4 bytes on stack (for delay counter)
    mov #0x0, r3                    ! r3 = 0
    mov.l   _pool_sh2_state_flag, r2 ! r2 = &secondary SH-2 state flag
    mov.l r3, @r2                   ! clear secondary SH-2 state flag = 0
    bra     .L_poll_sf_sshon        ! jump to SF poll loop (SSHON phase)
    nop                             ! delay slot

.L_poll_sf_sshon:
    mov.l   _pool_sf_ptr, r0       ! r0 = &ptr_to_SF
    mov.l @r0, r0                   ! r0 = ptr_to_SF (-> 0x20100063)
    mov.b @r0, r0                   ! r0 = SF register value
    extu.b r0, r0                   ! zero-extend byte
    and #0x1, r0                    ! isolate bit 0 (busy flag)
    cmp/eq #0x1, r0                 ! is SMPC still busy?
    bt      .L_poll_sf_sshon        ! yes — keep polling

    mov.l   _pool_sf_ptr, r2       ! r2 = &ptr_to_SF
    mov.l @r2, r2                   ! r2 = ptr_to_SF
    mov #0x1, r3                    ! r3 = 1
    mov.b r3, @r2                   ! SF = 1 (acknowledge / begin command)
    mov.l   _pool_comreg_ptr, r2   ! r2 = &ptr_to_COMREG
    mov.l @r2, r2                   ! r2 = ptr_to_COMREG (-> 0x2010001F)
    mov.l   _pool_sshon_cmd, r3    ! r3 = &SSHON command byte (0x03)
    mov.b @r3, r3                   ! r3 = 0x03 (SSHON: start secondary SH-2)
    mov.b r3, @r2                   ! COMREG = 0x03 — issue SSHON command
    bra     .L_poll_sf_sshon_done   ! jump to SF poll loop (wait for SSHON to complete)
    nop                             ! delay slot

.L_poll_sf_sshon_done:
    mov.l   _pool_sf_ptr, r0       ! r0 = &ptr_to_SF
    mov.l @r0, r0                   ! r0 = ptr_to_SF
    mov.b @r0, r0                   ! r0 = SF register value
    extu.b r0, r0                   ! zero-extend byte
    and #0x1, r0                    ! isolate busy flag
    cmp/eq #0x1, r0                 ! SMPC still busy?
    bt      .L_poll_sf_sshon_done   ! yes — keep polling

    mov #0x0, r2                    ! r2 = 0 (loop counter init)
    mov r2, r0                      ! r0 = 0
    mov.w r0, @(2, r15)            ! stack[2] = 0 (16-bit delay counter)
    bra     .L_delay_check          ! jump to delay loop test
    nop                             ! delay slot

.L_delay_increment:
    mov.w @(2, r15), r0            ! r0 = current delay counter
    mov r0, r2                      ! r2 = counter
    add #0x1, r2                    ! r2 = counter + 1
    mov r2, r0                      ! r0 = incremented counter
    mov.w r0, @(2, r15)            ! store incremented counter back

.L_delay_check:
    mov.w @(2, r15), r0            ! r0 = current delay counter
    mov r0, r3                      ! r3 = counter
    extu.w r3, r3                   ! zero-extend to 32-bit unsigned
    mov.w   _wpool_delay_limit, r2 ! r2 = 0x03E8 (1000 decimal)
    cmp/ge r2, r3                   ! counter >= 1000?
    bf      .L_delay_increment      ! no — keep looping (busy-wait for SH-2 init)

    mov.l   _pool_sh2_callback_ptr, r2 ! r2 = &secondary SH-2 callback pointer
    mov.l @r2, r2                   ! r2 = ptr to callback slot
    mov.l   _pool_slave_main_loop, r3 ! r3 = &slave_main_loop
    mov.l r3, @r2                   ! install slave_main_loop as secondary callback

    mov.l   _pool_sf_ptr, r2       ! r2 = &ptr_to_SF
    mov.l @r2, r2                   ! r2 = ptr_to_SF
    mov #0x1, r3                    ! r3 = 1
    mov.b r3, @r2                   ! SF = 1 (acknowledge / begin command)
    mov.l   _pool_comreg_ptr, r2   ! r2 = &ptr_to_COMREG
    mov.l @r2, r2                   ! r2 = ptr_to_COMREG
    mov.l   _pool_intback_cmd, r3  ! r3 = &INTBACK command byte (0x02)
    mov.b @r3, r3                   ! r3 = 0x02 (INTBACK: start peripheral polling)
    mov.b r3, @r2                   ! COMREG = 0x02 — issue INTBACK command
    bra     .L_poll_sf_intback      ! jump to SF poll loop (wait for INTBACK)
    nop                             ! delay slot

.L_poll_sf_intback:
    mov.l   _pool_sf_ptr, r0       ! r0 = &ptr_to_SF
    mov.l @r0, r0                   ! r0 = ptr_to_SF
    mov.b @r0, r0                   ! r0 = SF register value
    extu.b r0, r0                   ! zero-extend byte
    and #0x1, r0                    ! isolate busy flag
    cmp/eq #0x1, r0                 ! SMPC still busy?
    bt      .L_poll_sf_intback      ! yes — keep polling
    add #0x4, r15                   ! free stack space
    rts                             ! return to caller
    nop                             ! delay slot

_wpool_delay_limit:
    .2byte  0x03E8                  ! 1000 — busy-wait iteration count after SSHON
    .2byte  0xFFFF                  ! alignment padding

_pool_sh2_state_flag:
    .4byte  sym_06063578            ! secondary SH-2 state/status flag (cleared on init)
_pool_sf_ptr:
    .4byte  sym_0606358C            ! -> SMPC SF register (0x20100063)
_pool_comreg_ptr:
    .4byte  sym_06063584            ! -> SMPC COMREG register (0x2010001F)
_pool_sshon_cmd:
    .4byte  sym_06059CAD            ! byte = 0x03 (SSHON: activate secondary SH-2)
_pool_sh2_callback_ptr:
    .4byte  sym_06063580            ! -> secondary SH-2 callback function pointer
_pool_slave_main_loop:
    .4byte  slave_main_loop         ! secondary SH-2 main loop entry point
_pool_intback_cmd:
    .4byte  sym_06059CAC            ! byte = 0x02 (INTBACK: peripheral status request)
