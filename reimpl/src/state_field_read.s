/* state_field_read -- L3 assembly (SH-2 mnemonics)
 * Translation unit: 0x0604188C - 0x060418BE
 *
 * Polls the DMA interrupt state handler until all pending events are
 * processed, then returns the final status.
 *
 * Entry: state_field_read
 *   Called after cmd_enqueue to wait for event completion.
 *
 * Flow:
 *   1. Store 0x8000 (0.5 fixed-point) as a poll timeout counter at state[+0x3C].
 *   2. Call large_prologue_save (which falls through to dma_int_handler).
 *      dma_int_handler returns: 0 = no events, 1 = event triggered, 3 = state reset.
 *   3. If result == 1, loop back and poll again (events still pending).
 *   4. When result != 1, clear the counter at state[+0x3C] and return the result.
 *
 * Returns: r0 = final dma_int_handler result (0 or 3)
 *
 * Key symbols:
 *   sym_060A5400 -- AI/game state base pointer (indirect)
 */

    .section .text.FUN_0604188C


    .global state_field_read
    .type state_field_read, @function
state_field_read:
    sts.l pr, @-r15                      ! save return address
    mov.l   .L_pool_poll_timeout, r4     ! r4 = 0x8000 (0.5 in 16.16 fixed-point)
    mov.l   .L_pool_state_base_ptr, r3   ! r3 = &sym_060A5400 (state base indirect ptr)
    mov.l @r3, r3                        ! r3 = *sym_060A5400 (state base address)
    mov.l r4, @(60, r3)                  ! state[+0x3C] = 0x8000 (set poll timeout counter)
.L_poll_loop:
    .byte   0xBE, 0xFF    /* bsr 0x06041698 (external) */ ! call large_prologue_save -> dma_int_handler
    nop                                  ! delay slot
    cmp/eq #0x1, r0                      ! result == 1? (event still pending)
    bt/s    .L_poll_again                ! if result == 1 -> loop back to poll again
    mov r0, r4                           ! r4 = result (delay slot, saved for return)
    bra     .L_clear_counter             ! result != 1 -> done, go clear counter and return
    nop                                  ! delay slot
.L_poll_again:
    bra     .L_poll_loop                 ! events still pending -> poll again
    nop                                  ! delay slot
.L_pool_state_base_ptr:
    .4byte  sym_060A5400                 ! AI/game state base pointer (indirect)
.L_pool_poll_timeout:
    .4byte  0x00008000                   ! 0.5 (16.16 fixed-point) -- poll timeout value
.L_clear_counter:
    mov #0x0, r5                         ! r5 = 0 (clear value)
    .byte   0xD2, 0x2A    /* mov.l .L_pool_0604195C, r2 */ ! r2 = &sym_060A5400 (cross-TU pool ref)
    mov.l @r2, r2                        ! r2 = state base address
    mov.l r5, @(60, r2)                  ! state[+0x3C] = 0 (clear poll timeout counter)
    lds.l @r15+, pr                      ! restore return address
    rts                                  ! return to caller
    mov r4, r0                           ! r0 = saved result from dma_int_handler (delay slot)
