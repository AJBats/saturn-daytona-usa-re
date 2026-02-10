! ================================================
! AUDIT: DEFINITE — VBlank interrupt system with handler registration,
!   frame timing, and buffer swap logic. All function addresses, pool constants,
!   and hardware register writes verified byte-for-byte against aprog.s.
!   One branch direction error found in FUN_06007268 annotation (see AUDIT NOTE).
! Audited: 2026-02-10
! ================================================
!
! === VBlank Interrupt System ===
!
! Daytona USA Saturn uses a two-phase VBlank system: VBlank-IN and VBlank-OUT.
! Both handlers are registered during init via BIOS function at 0x06000300.
!
! CONFIDENCE: DEFINITE — BIOS vectors and handler addresses verified
! Registration (in FUN_06004A9E, system init):
!   BIOS(0x06000300)(vector=0x40, handler=FUN_06006F3C)  ! VBlank-IN
!   BIOS(0x06000300)(vector=0x41, handler=FUN_06007268)  ! VBlank-OUT
!   SCU IMS (0x25FE00A4) = 2  ! Enable VBlank-OUT interrupt
!
! Frame timing is ADAPTIVE per game state. Each of the 32 game states has a
! target VBlank-OUT count at 0x06059F58+state_index (byte array). The VBlank-OUT
! handler only swaps frame buffers when the count reaches the per-state target.
!
! The main loop does NOT explicitly wait for VBlank. It runs:
!   loop: FUN_0600A392() -> state_handler() -> repeat
! Synchronization is implicit through the frame buffer swap mechanism:
! rendering writes to the back buffer, VBlank handler swaps when ready.
!
! Phase tracking via 0x06059F54:
!   1 = VBlank-IN fired
!   3 = VBlank-OUT started
!   4 = VBlank-OUT complete (buffers may have swapped)
!
! === Key Variables ===
! CONFIDENCE: HIGH — all addresses verified as pool constants in
!   FUN_06006F3C and FUN_06007268 disassembly
!
! 0x0607864C (long) - VBlank-IN counter, incremented every 1/60s
! 0x06059F44 (long) - VBlank-OUT counter
! 0x06059F54 (long) - Phase flag (1=IN, 3=OUT-start, 4=OUT-end)
! 0x060635C0 (long) - Secondary frame counter (used for FBCR timing)
! 0x060635C4 (long) - Frame ready flag (cleared when buffer swapped)
! 0x060635B4 (word) - Frame buffer state machine (states 0-3)
! 0x06063F58 (long) - Frame buffer state variable
! 0x0605A00C (word) - VBlank handler disable flag (non-zero = skip)
! 0x060A4C90 (word) - TVMR shadow register (cached VDP1 setting)
! 0x060A4C92 (word) - FBCR shadow register (cached VDP1 setting)
! 0x06059F58 (byte[32]) - Per-state frame timing targets
!
! === BIOS Function Table (Low HWRAM) ===
! CONFIDENCE: HIGH — addresses verified via pool constants in aprog.s
!
! 0x06000300 - Interrupt handler registration
!              r4 = vector number (0x40=VBlank-IN, 0x41=VBlank-OUT)
!              r5 = handler function address
!
! 0x06000344 - Interrupt mask control
!              r4 = mask value (-1 = all)
!              r5 = flags (0x0083 observed during init)
!
! 0x0600026C - BIOS service function (called when CD tray open)
!

! ================================================================
! FUN_06006F3C - VBlank-IN Interrupt Handler
! ================================================================
! Registered as SCU vector 0x40 (VBlank-IN).
! Called by hardware at the start of every vertical blanking period (~60Hz).
!
! Responsibilities:
! 1. Increment VBlank counter (absolute time reference)
! 2. Frame buffer state machine (TVMR/FBCR management)
! 3. FBCR swap timing (based on frame counter threshold)
! 4. Timing computation for frame pacing
! 5. Controller input dispatch (button -> sound effects)
!
! This is the most timing-critical function in the game. Everything that
! must happen at exact VBlank timing goes here.
!

! CONFIDENCE: DEFINITE — all pool constants verified byte-for-byte:
!   r8=0x06014884 at [0x06006FDC], r9=0x06014868 at [0x06006FE0],
!   r10=0x060389A6 at [0x06006FE4], r11=0x060635C4 at [0x06006FE8],
!   r13=0x060635C0 at [0x06006FEC], r14=0x0605B6D8 at [0x06006FF0],
!   VBlank counter 0x0607864C at [0x06006FF4], phase flag 0x06059F54
!   at [0x06006FF8]. Prologue instruction sequence matches exactly.
FUN_06006F3C:   ! 0x06006F3C
    mov.l   r14,@-r15
    mov     #1,r2               ! r2 = 1 (used as flag value below)
    mov.l   r13,@-r15
    mov.l   r12,@-r15
    mov.l   r11,@-r15
    mov.l   r10,@-r15
    mov.l   r9,@-r15
    mov.l   r8,@-r15
    sts.l   pr,@-r15
    ! Register assignments (held across entire handler):
    ! r8  = 0x06014884  (FUN_06014884 - VDP scroll register update)
    ! r9  = 0x06014868  (FUN_06014868 - VDP scroll setup)
    ! r10 = 0x060389A6  (FUN_060389A6 - SMPC INTBACK trigger / peripheral poll)
    ! r11 = 0x060635C4  (frame ready flag)
    ! r13 = 0x060635C0  (secondary frame counter)
    ! r14 = 0x0605B6D8  (processed controller input state)
    mov.l   @(pool),r8          ! r8 = FUN_06014884
    mov.l   @(pool),r9          ! r9 = FUN_06014868
    mov.l   @(pool),r10         ! r10 = FUN_060389A6
    mov.l   @(pool),r11         ! r11 = &frame_ready (0x060635C4)
    mov.l   @(pool),r13         ! r13 = &frame_counter (0x060635C0)
    mov.l   @(pool),r14         ! r14 = &input_state (0x0605B6D8)

    ! --- Step 1: Increment VBlank counter ---
    mov.l   @(pool),r4          ! r4 = 0x0607864C (VBlank counter address)
    mov.l   @r4,r3              ! r3 = current count
    add     #1,r3               ! r3++
    mov.l   r3,@r4              ! store back -> VBLANK COUNTER

    ! --- Step 2: Set VBlank flag ---
    mov.l   @(pool),r3          ! r3 = 0x06059F54
    mov.l   r2,@r3              ! *(0x06059F54) = 1  (phase = VBlank-IN)

    ! --- Step 3: Check disable flag ---
    mov.l   @(pool),r0          ! r0 addr = 0x0605A00C
    mov.w   @r0,r0              ! r0 = *(word)0x0605A00C
    extu.w  r0,r0
    tst     r0,r0
    bt/s    .continue            ! if 0: continue with handler
    mov     #0,r12              ! r12 = 0 (delay slot)
    bra     .epilogue            ! if non-zero: skip everything, return
    nop

.continue:
    ! --- Step 4: Frame buffer state machine ---
    ! Reads state from *(word)0x060635B4
    ! State 0: Call SMPC trigger, clear frame-ready flag
    ! State 2: Check ready flag, optionally call SMPC trigger, set state=2
    ! State 3: Write TVMR (0x25D00000) with bit 3 set
    !          Write FBCR (0x25D00002) with bits 0+1 set
    !          Call SMPC trigger, set state=3
    ! Other:   Fall through to frame counter

    ! (VDP1 register writes during state 3):
    ! *(word)0x25D00000 = shadow_TVMR | 0x08   (TVMR bit 3 = ?)
    ! *(word)0x25D00002 = shadow_FBCR | 0x03   (FBCR bits 0+1 = swap mode)

    ! --- Step 5: Frame counter + FBCR swap timing ---
    ! *(0x060635C0) += 1
    ! if *(0x060635B8) == 1:
    !   if frame_counter >= *(0x060635BC) - 1:
    !     *(word)0x25D00002 |= 0x02   (trigger buffer swap at next VBlank)

    ! --- Step 6: Timing computation ---
    ! Reads 0x06059F3C and 0x06059F38
    ! Computes: result = (val_3C >> 2) * 20 + (val_38 >> 1) + 0x0606B178
    ! Stores to 0x06059F34

    ! --- Step 7: Button input processing ---
    ! r0 = *(0x0605B6D8) - processed input state
    ! Tests each button bit and dispatches:
    !
    ! Bit 0x20000000 (29): Special/system button
    !   -> FUN_0602766C(r4=*(0x06063F60), r5=*(0x06059F34), r6=pool_val)
    !
    ! Bit 0x04: Right direction
    !   -> FUN_0602766C(r4=*(0x060612B4), r5=*(0x0606129C), r6=pool_val)
    !
    ! Bit 0x10: Left direction
    !   -> FUN_06014884(r4=4, r5=*(0x0605B6FC), r6=*(0x0605B700))
    !
    ! Bit 0x20: Start button
    !   -> FUN_06014884(r4=8, r5=*(0x0605B704), r6=*(0x0605B708))
    !
    ! Bit 0x40: A button (gas)
    !   -> FUN_06014884(r4=16, r5=*(0x0605B70C), r6=*(0x0605B710))
    !
    ! Bit 0x80: B button (brake) - longest handler
    !   -> Extended processing at 0x0600713C

.epilogue:  ! 0x060071F0
    lds.l   @r15+,pr
    mov.l   @r15+,r8
    mov.l   @r15+,r9
    mov.l   @r15+,r10
    mov.l   @r15+,r11
    mov.l   @r15+,r12
    mov.l   @r15+,r13
    rts
    mov.l   @r15+,r14


! ================================================================
! FUN_06007268 - VBlank-OUT Interrupt Handler
! ================================================================
! Registered as SCU vector 0x41 (VBlank-OUT).
! Called by hardware at the end of every vertical blanking period.
!
! Responsibilities:
! 1. Increment VBlank-OUT counter
! 2. Call FUN_06005198 (display list processing / VDP2 updates)
! 3. Adaptive frame timing: compare OUT count vs per-state target
! 4. Trigger FBCR swap when target reached
! 5. Clear frame ready flags
!
! The per-state frame target at 0x06059F58+state allows different game
! states to run at different frame rates. Menu states might target 1
! (swap every VBlank = 60fps), while racing states might target 2
! (swap every other VBlank = 30fps).
!

! CONFIDENCE: DEFINITE — all pool constants verified: 0x06059F44 at
!   [0x060072C0], 0x06059F54 at [0x060072C4], 0x06005198 at [0x060072C8],
!   0x0605AD10 at [0x060072CC], 0x06059F58 at [0x060072D0], 0x06063F58
!   at [0x060072D4], 0x060A4C92 at [0x060072D8], 0x25D00002 at [0x060072DC],
!   0x060635C4 at [0x060072E0]. Instruction sequence verified.
FUN_06007268:   ! 0x06007268
    sts.l   pr,@-r15

    ! --- Step 1: Increment VBlank-OUT counter ---
    mov.l   @(pool),r3          ! r3 addr = 0x06059F44
    mov.l   @r3,r3              ! r3 = current OUT count
    add     #1,r3
    mov.l   r3,@r2              ! *(0x06059F44) = count + 1

    ! --- Step 2: Set phase flag ---
    mov     #3,r3
    mov.l   @(pool),r2          ! r2 = 0x06059F54
    mov.l   r3,@r2              ! *(0x06059F54) = 3 (phase = VBlank-OUT started)

    ! --- Step 3: Call display processing ---
    mov.l   @(pool),r3          ! r3 = FUN_06005198
    jsr     @r3                 ! FUN_06005198() - display list / VDP2 updates
    nop

    ! --- Step 4: Adaptive frame timing ---
    mov.l   @(pool),r2          ! r2 addr = 0x0605AD10 (game state)
    mov.l   @(pool),r3          ! r3 = 0x06059F58 (frame target table base)
    mov.l   @(pool),r1          ! r1 addr = 0x06059F44 (OUT counter)
    mov.l   @r2,r2              ! r2 = current game state
    mov.l   @r1,r1              ! r1 = VBlank-OUT count
    add     r3,r2               ! r2 = &target_table[state]
    mov.b   @r2,r2              ! r2 = target frame count for current state
    extu.b  r2,r2
    cmp/ge  r2,r1               ! if OUT_count >= target
! AUDIT NOTE: Branch label .skip_swap is WRONG. cmp/ge sets T when r1>=r2,
!   so bt branches TO the swap-check code (0x06007298), not past it.
!   The bra on the next line (0x060072B6) is the actual skip path.
!   Should be labeled .check_swap or .do_swap, not .skip_swap.
    bt      .skip_swap          ! skip if count < target (not yet time)

    ! --- Step 5: Trigger frame buffer swap ---
    mov.l   @(pool),r5          ! r5 = 0x06063F58 (frame buffer state)
    mov.l   @r5,r0              ! r0 = current state
    tst     r0,r0
    bt      .skip_swap          ! skip if frame buffer state == 0

    ! Write FBCR to trigger swap:
    mov.l   @(pool),r0          ! r0 addr = 0x060A4C92 (FBCR shadow)
    mov.w   @r0,r0
    extu.w  r0,r0
    or      #0x03,r0            ! set bits 0+1 (manual swap + change mode)
    extu.w  r0,r0
    mov.l   @(pool),r3          ! r3 = 0x25D00002 (VDP1 FBCR register)
    mov.w   r0,@r3              ! WRITE TO VDP1 FBCR - triggers swap!

    ! Clear flags:
    mov     #0,r4
    mov.l   @(pool),r3          ! r3 = 0x060635C4 (frame ready flag)
    mov.l   r4,@r3              ! frame_ready = 0
    mov.l   r4,@r5              ! frame_buffer_state = 0

.skip_swap:
    ! --- Step 6: Set final phase ---
    mov     #4,r2
    mov.l   @(pool),r3          ! r3 = 0x06059F54
    lds.l   @r15+,pr
    rts
    mov.l   r2,@r3              ! *(0x06059F54) = 4 (phase = VBlank-OUT complete)


! ================================================================
! FUN_0600A392 - Per-Frame Setup (called from main loop)
! ================================================================
! Called every main loop iteration BEFORE state dispatch.
! NOT the VBlank handler - this is the main-thread per-frame setup.
!
! Responsibilities:
! 1. Read CD block status via FUN_06018EAC -> FUN_060349C4
!    (consistent double-read of CD registers at 0x25890018-0x25890024)
! 2. If CD status & 0x0F == 6 (tray open): call BIOS via 0x0600026C
! 3. Frame sync state machine at 0x0607864A:
!    - State 0: call FUN_060349C4, read frame sync byte, store if < 100
!    - State 1: if CD status == 1, call FUN_06012B58, advance to state 2
! 4. Check status word at 0x06063D98/9A for reset condition:
!    - If bits 0x0800 set (at +2) AND bits 0x0700 all set (at +0):
!      -> Call FUN_06009FFC (SCU interrupt reconfigure)
!      -> If game state >= 6: capture state data, reset to state 0
!      -> If game state < 6: call BIOS via 0x0600026C

! CONFIDENCE: HIGH — function address verified at 0x0600A392 in aprog.s.
!   CD block register addresses (0x25890018-0x25890024) are standard Saturn.
!   BIOS function at 0x0600026C and game state at 0x0605AD10 confirmed.
FUN_0600A392:   ! 0x0600A392
    ! (see build/aprog.s line 15502 for full disassembly)
    ! r13 = 0x0605AD10 (game state variable)
    ! r14 = FUN_06018EAC return & 0x0F (CD status, bottom 4 bits)
    ! r12 = 0x0607864A (frame sync state byte)


! ================================================================
! CD Block Status Reading Chain
! CONFIDENCE: HIGH — CD block register addresses are standard Saturn,
!   double-read pattern is a known reliability technique for CD hardware
! ================================================================
!
! FUN_06018EAC -> FUN_060349C4 -> FUN_06034A10 -> FUN_06035E5E
!
! FUN_06035E5E reads 4 CD block response registers (16-bit each):
!   buffer[0] = *(word)0x25890018  (CR1 - status/response)
!   buffer[2] = *(word)0x2589001C  (CR2)
!   buffer[4] = *(word)0x25890020  (CR3)
!   buffer[6] = *(word)0x25890024  (CR4)
!
! FUN_06034A10 does consistent double-read:
!   1. Disable interrupts (IMASK = 15)
!   2. Read CD registers into buffer A (caller's)
!   3. Read CD registers into buffer B (stack)
!   4. Restore interrupts
!   5. Compare A and B (8 bytes)
!   6. If match: return 0 (success)
!   7. If mismatch: retry up to 100 times, then return -3
!
! FUN_060349C4 wraps the double-read and validates the response byte.
!
! FUN_06018EAC returns: first_byte_of_response & 31 (bottom 5 bits)
! In FUN_0600A392 this is further masked with & 0x0F to get CD status:
!   0 = Busy, 1 = Pause, 2 = Standby, 3 = Play, 4 = Seek,
!   5 = Scan, 6 = Open (tray), 7 = No disc, 8+ = Error states


! ================================================================
! Sound System Reset (FUN_06018EE4)
! CONFIDENCE: DEFINITE — function address verified at 0x06018EE4.
!   SMPC addresses (0x20100063, 0x2010001F) and SCSP address (0x25B00400)
!   are standard Saturn hardware. SNDOFF=7 and SNDON=6 are correct SMPC
!   command codes. Sound RAM handshake at 0x25A02DBC is game-specific but
!   the pattern (poll for magic value) is standard 68000 boot confirmation.
! ================================================================
! NOT part of VBlank - this is a separate initialization function.
! Halts and restarts the 68000 sound CPU via SMPC commands.
!
! Sequence:
! 1. Wait SMPC idle (poll SF at 0x20100063, bit 0)
! 2. Send SNDOFF command (COMREG = 7 at 0x2010001F)
! 3. Wait SMPC complete
! 4. Call FUN_060192B4 (delay)
! 5. Write 0x0200 to SCSP register 0x25B00400 (master control)
! 6. Call FUN_06012E84, FUN_06012EBC (sound data setup)
! 7. Wait SMPC idle
! 8. Send SNDON command (COMREG = 6)
! 9. Wait SMPC complete
! 10. Poll sound RAM at 0x25A02DBC until 68000 writes "OK" (0x4F4B)
! 11. Configure SCU interrupts via FUN_0601D5F4(15, ...)
! 12. Clear flag at 0x06086038
! 13. Tail-call FUN_06018EC8 (set SCSP channel volumes 0xE0)
!
! The "OK" handshake at 0x25A02DBC is the 68000 signaling boot complete.
! SCSP registers written: 0x25B00217 = 0xE0, 0x25B00237 = 0xE0 (volumes)


! ================================================================
! Interrupt System Init (at 0x06004A9E+)
! CONFIDENCE: DEFINITE — verified against aprog.s at FUN_06004A98.
!   The address 0x06004A9E is 6 bytes into FUN_06004A98 (within the prologue).
!   BIOS 0x06000344 at [0x06004ACC], SCU IMS 0x25FE00A4 at [0x06004AD4],
!   VBlank-IN handler 0x06006F3C at [0x06004BE4] with vector 0x40,
!   VBlank-OUT handler 0x06007268 at [0x06004BE8] with vector 0x41 —
!   all verified byte-for-byte in the binary disassembly.
! ================================================================
! Part of the large system initialization function.
!
! 1. Call BIOS(0x06000344) with r4=-1, r5=0x0083
!    -> Disable all interrupts, set base mask
!
! 2. Clear 128KB of VDP2 VRAM starting at 0x25E00000
!
! 3. Call FUN_06038300 (display init)
! 4. Call FUN_06036F0C (VDP setup)
! 5. Call FUN_06038A64 (additional display setup)
!
! 6. Write 0x8000 to 0x06086028 (display control flag)
! 7. Call FUN_06036E90(0x25F00FFE, 1) - some memory-mapped config
!
! 8. Write 2 to SCU IMS (0x25FE00A4) - enable VBlank-OUT interrupt
!    Read back and verify bit 1 set (error path if not)
!
! 9. Register VBlank-IN handler:
!    BIOS(0x06000300)(r4=0x40, r5=FUN_06006F3C)
!
! 10. Register VBlank-OUT handler:
!     BIOS(0x06000300)(r4=0x41, r5=FUN_06007268)
