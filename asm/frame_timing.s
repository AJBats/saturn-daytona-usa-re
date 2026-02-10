! ================================================
! AUDIT: DEFINITE — Frame commit pipeline and sprite command builder.
!   All function addresses, pool constants (including word-size pools), and
!   instruction sequences verified against aprog.s. The 600/0x0258 timing
!   budget, VDP1 0x8000 draw-end marker, 32-byte command size, and all
!   called function addresses confirmed.
! Audited: 2026-02-10
! ================================================
!
! ==========================================================================
! Frame Timing & Display Commit — End-of-Frame Pipeline
! ==========================================================================
!
! FUN_060078DC is tail-called from nearly every state handler (15, 17, 25,
! 28, 29). It is THE end-of-frame function: commits all rendering work,
! builds VDP1 command lists, transfers data via SCU DMA, writes the
! draw-end marker, and resets timing counters.
!
! FUN_06007BCC is the VDP1 sprite command builder loop called from within.
! It iterates a sprite index table, reads 24-byte sprite entries, and
! generates 32-byte VDP1 commands.
!
! FRAME COMMIT PIPELINE (FUN_060078DC):
! CONFIDENCE: DEFINITE — entire pipeline verified step-by-step against
!   aprog.s instruction stream from 0x060078DC to function end
!
!   1. Timing management: decrement accumulator, check frame budget
!   2. Conditional DMA: if budget available, transfer sprite/palette data
!   3. VDP1 command list: FUN_0602C494 builds command table header
!   4. SCU DMA: phase-indexed transfer to display area
!   5. Frame counter increment at [0x0605A008]
!   6. Sprite loop (FUN_06007BCC): build per-sprite VDP1 commands
!   7. Flag set + FUN_060394C2 (per-frame subsystem)
!   8. Second SCU DMA: commit command buffer to VDP1
!   9. Draw-end marker: write 0x8000 at end of command table
!  10. Display flags: set bits 29, 2, conditionally bit 27
!  11. Cleanup: FUN_06026CE0, reset counters, copy results
!
! SPRITE COMMAND BUILDER (FUN_06007BCC):
! CONFIDENCE: DEFINITE — loop structure, index computation, and dispatch
!   verified against aprog.s at 0x06007BCC
!
!   For each sprite index in [0x0606A4F8 + i*2]:
!     entry = 0x0608AC20 + sprite_index * 24
!     if entry[+6] == 9:
!       FUN_060281B8(entry, write_ptr, 0x8000)  — special draw
!     else:
!       FUN_060280F8(entry, write_ptr)           — normal draw
!     write_ptr += 32  (one VDP1 command = 32 bytes)
!
! KEY DATA STRUCTURES:
!
! CONFIDENCE: HIGH — all addresses verified as pool constants
!   Timing state:
!     0x060620D0  Timing counter (accumulates, compared against 600)
!     0x060620D4  Timing accumulator (decremented by 600 each frame)
!     0x0605A008  Frame counter (incremented each frame, reset after commit)
!     0x0605A00C  Frame-ready flag (set=1 during commit, cleared after)
!
! CONFIDENCE: HIGH — addresses verified, 32-byte command size confirmed
!   by add #32 instruction and shll2/shll2/shll multiply pattern
!   VDP1 command system:
!     0x06063F5C  VDP1 command buffer base pointer
!     0x060785FC  VDP1 command write pointer (advances by 32 per sprite)
!     0x0608AC20  Sprite data table (24-byte entries)
!     0x0606A4F8  Sprite index lookup (word per entry, indexes into 0x0608AC20)
!     0x0608E460  DMA source for sprite data transfers
!     0x8000      VDP1 CMDCTRL draw-end marker
!
!   Phase-indexed display:
!     0x0605A016  Phase flag (word, used to index 32-byte display blocks)
!     0x0605A018  Phase display data base (32 bytes per phase)
!
! CONFIDENCE: HIGH — flag values confirmed by or-immediate instructions
!   Display flags (0x0605B6D8):
!     Bit 2  (0x00000004) = display update pending
!     Bit 27 (0x08000000) = extra display flag (when [0x0607EAE0]==0)
!     Bit 29 (0x20000000) = frame committed
!
!   Other:
!     0x06059F44  Results flag (copied to 0x0606BDF8, then cleared)
!     0x0606BDFC  DMA commit buffer (for second SCU DMA)
!     0x0607EAE0  External event flag (controls bit 27)
!     0x0607EBC4  State bits (mask 0x20228000 controls HUD rendering)
!
! CONFIDENCE: HIGH — 24-byte stride confirmed by multiply-by-24 pattern
!   (shll2+shll for *8 combined with shll2+shll2 for *16, then add)
!   Sprite entry (24 bytes at 0x0608AC20):
!     +0x00: data fields (position, attributes)
!     +0x06: word — sprite type (9 = special, else normal)
!     +0x08..+0x17: additional rendering data
!
! CALLED FUNCTIONS:
! CONFIDENCE: HIGH — all called function addresses verified as pool
!   constants in aprog.s. FUN_060281B8 and FUN_060333D8 exist as code
!   addresses but lack top-level labels (mid-function or unlabeled entries).
!     FUN_06027630  — DMA-style sprite data copy (24-byte granularity)
!     FUN_0602761E  — DMA-style palette/attribute copy (word granularity)
!     FUN_0602C494  — VDP1 command table header builder
!     FUN_0602766C  — SCU DMA transfer (generic: src→dst, size)
!     FUN_060394C2  — Per-frame subsystem update
!     FUN_06026CE0  — Display update / palette commit
!     FUN_060280F8  — Normal VDP1 sprite command builder (32 bytes)
!     FUN_060281B8  — Special VDP1 sprite command (type 9, with draw-end)
!     FUN_060333D8  — HUD rendering (conditional on state bits)
!     FUN_06007A50  — Additional rendering pass
!     FUN_06011DC0  — Post-sprite cleanup
!     FUN_060171AC  — Tail call from sprite builder (final cleanup)
!
! ==========================================================================


! ==========================================================================
! FUN_060078DC — Frame End / Display Commit
! ==========================================================================
! THE end-of-frame function. Every state handler tail-calls this after
! completing its per-frame work. Commits rendering, runs DMA, resets
! timing counters for the next frame.
!
! Constants: 600 (0x0258) = frame time budget
!            1200 (0x04B0) = double budget (for word-indexed tables)
!
! Called from: State 15, 17, 25, 28, 29 (tail call), State 29 (direct jsr)
! Returns to: state handler's caller (since this is a tail call)

! CONFIDENCE: DEFINITE — pool constants verified: r9=600 (word at
!   [0x060079CE]=0x0258), r10=0x0606A4F8 at [0x060079D4],
!   r12=0x0605A008 at [0x060079D8], r13=0x060620D4 at [0x060079DC],
!   r14=0x060620D0 at [0x060079E0]. DMA source 0x0608E460 at [0x060079E4],
!   sprite table 0x0608AC20 at [0x060079E8], copy fn 0x06027630 at [0x060079EC],
!   VDP1 cmd header 0x0602C494 at [0x060079F4], SCU DMA 0x0602766C at [0x06007A04].
!   Prologue and instruction sequence match binary exactly.
FUN_060078DC:       ! 0x060078DC
    mov.l   r14,@-r15
    mov.l   r13,@-r15
    mov.l   r12,@-r15
    mov.l   r11,@-r15
    mov.l   r10,@-r15
    mov.l   r9,@-r15
    sts.l   pr,@-r15

    ! Cache constants and addresses
    mov.w   @(0xE0,PC),r9         ! r9 = 600 (0x0258) — frame time budget
    mov.l   @(0xE4,PC),r10        ! r10 = 0x0606A4F8 (sprite index table)
    mov.l   @(0xE8,PC),r12        ! r12 = 0x0605A008 (&frame_counter)
    mov.l   @(0xE8,PC),r13        ! r13 = 0x060620D4 (&timing_accumulator)
    mov.l   @(0xEC,PC),r14        ! r14 = 0x060620D0 (&timing_counter)

    ! === Step 1: Timing management ===
    ! Decrement accumulator by frame budget
    mov.l   @r13,r3
    sub     r9,r3
    mov.l   r3,@r13                ! [timing_accum] -= 600

    ! Check if timing counter has reached budget threshold
    mov.l   @r14,r2
    cmp/hs  r9,r2                   ! [timing_counter] >= 600?
    bt      .skip_dma               ! yes: skip DMA (frame already committed?)

    ! === Step 2: Conditional DMA transfer (timing allows) ===
    ! Transfer sprite data in 24-byte chunks
    mov.l   @r13,r6                 ! r6 = timing_accum (= byte count for transfer)
    mov.l   @(0xE0,PC),r5         ! r5 = 0x0608E460 (DMA source — sprite staging area)
    mov.l   @r14,r4                 ! r4 = timing_counter

    ! Compute source offset: timing_accum * 24
    mov     r6,r2
    extu.w  r4,r4
    shll2   r6                      ! r6 <<= 2
    shll2   r2                      ! r2 <<= 2
    mov     r4,r3
    shll    r6                      ! r6 <<= 1 (total: r6 = accum * 8)
    shll2   r2                      ! r2 <<= 2 (total: r2 = accum * 16)
    shll2   r4                      ! r4 <<= 2
    shll2   r3                      ! r3 <<= 2
    add     r2,r6                   ! r6 = accum*8 + accum*16 = accum * 24
    shll    r4                      ! r4 <<= 1 (total: counter * 8)
    shll2   r3                      ! r3 <<= 2 (total: counter * 16)

    ! Compute destination: 0x0608AC20 + (counter * 24)
    mov.l   @(0xC8,PC),r2         ! r2 = 0x0608AC20 (sprite data table base)
    add     r3,r4                   ! r4 = counter*8 + counter*16 = counter * 24
    extu.w  r4,r4                   ! wrap to 16-bit
    mov.l   @(0xC4,PC),r3         ! r3 = 0x06027630 (copy function)
    jsr     @r3                     ! FUN_06027630(dst=0x0608AC20+counter*24,
    add     r2,r4                   !   src=0x0608E460, count=accum*24) (delay slot)

    ! Transfer palette/attribute data in word-sized chunks
    mov.l   @r13,r6                 ! r6 = timing_accum
    mov.w   @(0xA0,PC),r5         ! r5 = 1200 (0x04B0 — double budget for words)
    mov.l   @r14,r4                 ! r4 = timing_counter
    mov.l   @(0xBC,PC),r3         ! r3 = 0x0602761E (word copy function)
    shll    r6                      ! r6 = accum * 2
    add     r10,r5                  ! r5 = 0x0606A4F8 + 1200 (palette source offset)
    shll    r4                      ! r4 = counter * 2
    jsr     @r3                     ! FUN_0602761E(dst=base+counter*2,
    add     r10,r4                  !   src=base+1200, count=accum*2) (delay slot)

.skip_dma:
    ! === Step 3: Accumulate timing and reset ===
    mov.l   @r13,r2                 ! r2 = timing_accum (leftover from this frame)
    mov     r10,r5                  ! r5 = 0x0606A4F8 (sprite index base)
    mov.l   @r14,r3                 ! r3 = timing_counter
    add     r2,r3                   ! r3 = counter + accum
    mov.l   r3,@r14                 ! [timing_counter] += accum
    mov.l   r9,@r13                 ! [timing_accum] = 600 (reset for next frame)

    ! === Step 4: VDP1 command table header ===
    mov.l   @(0xA8,PC),r3         ! r3 = 0x0602C494
    jsr     @r3                     ! FUN_0602C494 — build VDP1 command table header
    mov.l   @r14,r4                 ! r4 = timing_counter (delay slot)

    ! === Step 5: SCU DMA — phase-indexed transfer ===
    ! Transfer 32 bytes of display data indexed by phase flag
    mov     #32,r6                  ! r6 = 32 (transfer size)
    mov.l   @(0xA8,PC),r5         ! r5_addr = 0x0605A016 (&phase_flag)
    mov.l   @(0xA4,PC),r11        ! r11 = 0x06063F5C (&VDP1_cmd_buffer)
    mov.l   @(0xA8,PC),r3         ! r3 = 0x0605A018 (phase display data base)
    mov.l   @(0xAC,PC),r2         ! r2 = 0x0602766C (SCU DMA function)
    mov.w   @r5,r5                  ! r5 = phase_flag value (word)
    shll2   r5                      ! r5 <<= 2
    shll2   r5                      ! r5 <<= 2
    shll    r5                      ! r5 <<= 1 (total: phase * 32)
    add     r3,r5                   ! r5 = 0x0605A018 + phase*32 (DMA dest)
    jsr     @r2                     ! FUN_0602766C(src=[0x06063F5C], dst, size=32)
    mov.l   @r11,r4                 ! r4 = [VDP1_cmd_buffer] (delay slot: DMA source)

    ! Set VDP1 pointer
    mov.l   @(0xA0,PC),r3         ! r3 = 0x0606BDFC (commit buffer addr)
    mov.l   @(0xA0,PC),r2         ! r2 = 0x060785FC (&VDP1_write_ptr)
    mov.l   r3,@r2                  ! [VDP1_write_ptr] = 0x0606BDFC

    ! === Step 6: Increment frame counter ===
    mov.l   @r12,r3                 ! r3 = [frame_counter]
    add     #1,r3
    mov.l   r3,@r12                 ! [frame_counter]++

    ! === Step 7: Sprite command builder loop ===
    bsr     FUN_06007BCC            ! Build all VDP1 sprite commands
    nop

    ! === Step 8: Set frame-ready flag, call subsystem ===
    mov     #1,r2
    mov.l   @(0x94,PC),r3         ! r3 = 0x0605A00C (&frame_ready_flag)
    mov.l   r2,@r3                  ! [frame_ready_flag] = 1

    mov.l   @(0x94,PC),r3         ! r3 = 0x060394C2
    jsr     @r3                     ! FUN_060394C2 — per-frame subsystem
    nop

    ! === Step 9: Second SCU DMA — commit command buffer ===
    ! Transfer (frame_counter - 1) * 32 bytes of VDP1 commands
    mov.l   @r12,r6                 ! r6 = frame_counter
    mov.l   @(0x80,PC),r5         ! r5 = 0x0606BDFC (commit buffer)
    mov.l   @r11,r4                 ! r4 = [VDP1_cmd_buffer]
    mov.l   @(0x78,PC),r3         ! r3 = 0x0602766C (SCU DMA)
    add     #-1,r6                  ! r6 = frame_counter - 1
    shll2   r6
    shll2   r6
    shll    r6                      ! r6 = (frame_counter-1) * 32 (byte count)
    jsr     @r3                     ! FUN_0602766C — DMA commit
    add     #32,r4                  ! r4 = [cmd_buffer] + 32 (skip header, delay slot)

    ! === Step 10: Write VDP1 draw-end marker ===
    ! Write 0x8000 at [cmd_buffer + frame_counter * 32]
    mov.l   @r12,r0                 ! r0 = frame_counter
    mov.l   @r11,r3                 ! r3 = [VDP1_cmd_buffer]
    mov.l   @(0x7C,PC),r2         ! r2 = 0x00008000 (VDP1 CMDCTRL draw-end)
    shll2   r0
    shll2   r0
    shll    r0                      ! r0 = frame_counter * 32
    add     r3,r0                   ! r0 = cmd_buffer + frame_counter * 32
    mov.w   r2,@r0                  ! write 0x8000 = DRAW END marker!

    ! === Step 11: Update display flags ===
    mov.l   @(0x74,PC),r4         ! r4 = 0x0605B6D8 (&display_flags)
    mov.l   @(0x74,PC),r3         ! r3 = 0x20000000 (bit 29)
    mov.l   @r4,r2
    or      r3,r2                   ! display_flags |= 0x20000000 (frame committed)
    mov     r2,r0
    or      #0x04,r0                ! display_flags |= 0x04 (update pending)
    mov.l   r0,@r4

    ! Conditionally set bit 27 when no external event pending
    mov.l   @(0x6C,PC),r0         ! r0 = 0x0607EAE0 (&ext_event)
    mov.l   @r0,r0
    tst     r0,r0
    bf      .skip_bit27             ! ext_event != 0: skip
    mov.l   @(0x68,PC),r3         ! r3 = 0x08000000 (bit 27)
    mov.l   @r4,r2
    or      r3,r2
    mov.l   r2,@r4                  ! display_flags |= 0x08000000
.skip_bit27:

    ! === Step 12: Cleanup ===
    mov     #0,r11
    mov.l   @(0x48,PC),r3         ! r3 = 0x0605A00C (&frame_ready_flag)
    mov.l   r11,@r3                 ! [frame_ready_flag] = 0
    bra     .common_cleanup
    nop

    ! (pool constants in between: 0x0258, 0x04B0, 0xFFFF, addresses...)

.common_cleanup:
    ! Call display update
    mov.l   @(0x68,PC),r3         ! r3 = 0x06026CE0
    jsr     @r3                     ! FUN_06026CE0 — display/palette commit
    nop

    ! Reset timing counter and frame counter
    mov.l   r11,@r14               ! [timing_counter] = 0
    mov.l   r11,@r12               ! [frame_counter] = 0

    ! Copy results flag, then clear
    mov.l   @(0x64,PC),r4         ! r4 = 0x06059F44 (&results_flag)
    mov.l   @(0x64,PC),r3         ! r3 = 0x0606BDF8 (&results_copy)
    mov.l   @r4,r2
    mov.l   r2,@r3                  ! [results_copy] = [results_flag]
    mov.l   r11,@r4                 ! [results_flag] = 0

    ! Epilogue
    lds.l   @r15+,pr
    mov.l   @r15+,r9
    mov.l   @r15+,r10
    mov.l   @r15+,r11
    mov.l   @r15+,r12
    mov.l   @r15+,r13
    rts
    mov.l   @r15+,r14               ! (delay slot)


! ==========================================================================
! FUN_06007BCC — VDP1 Sprite Command Builder Loop
! ==========================================================================
! Iterates through all sprites for this frame, reading sprite indices from
! a lookup table (0x0606A4F8), fetching 24-byte sprite entries from the
! sprite data table (0x0608AC20), and generating 32-byte VDP1 commands.
!
! Sprite type 9 (from entry[+6]) uses the "special" builder FUN_060281B8
! which passes the draw-end marker (0x8000). All other types use the
! normal builder FUN_060280F8.
!
! After the sprite loop:
!   - Accumulates sprite count into frame counter
!   - Conditionally renders HUD (FUN_060333D8) when state bits match
!   - Calls FUN_06011DC0 for cleanup
!   - Tail-calls FUN_060171AC
!
! Called from: FUN_060078DC (bsr)
! Tail-calls: FUN_060171AC

! CONFIDENCE: DEFINITE — pool constants verified: r8=0x060280F8 at
!   [0x06007CAC], r9=0x060620D0 at [0x06007CB0], r10=0x00008000 at
!   [0x06007CB4], r13=0x0608AC20 at [0x06007CB8], r14=0x060785FC at
!   [0x06007CBC]. Loop counter at 0x06078620 [0x06007CC0], controller
!   flag at 0x0607861C [0x06007CC4], controller state at 0x06063DA0
!   [0x06007CC8]. Special builder 0x060281B8 at [0x06007CD0].
!   HUD mask 0x20228000 at [0x06007CDC], state bits at 0x0607EBC4
!   [0x06007CD8]. Tail-call target 0x060171AC at [0x06007CE8].
!   All verified against binary disassembly.
FUN_06007BCC:       ! 0x06007BCC
    mov.l   r14,@-r15
    mov     #0,r4                   ! r4 = 0 (init value for clear)
    mov.l   r13,@-r15
    mov.l   r12,@-r15
    mov.l   r11,@-r15
    mov.l   r10,@-r15
    mov.l   r9,@-r15
    mov.l   r8,@-r15
    sts.l   pr,@-r15

    ! Cache constants
    mov.l   @(0xCC,PC),r8         ! r8 = 0x060280F8 (normal sprite builder)
    mov.l   @(0xCC,PC),r9         ! r9 = 0x060620D0 (&timing_counter = sprite_count)
    mov.l   @(0xD0,PC),r10        ! r10 = 0x00008000 (VDP1 draw-end marker)
    mov.l   @(0xD0,PC),r13        ! r13 = 0x0608AC20 (sprite data table base)
    mov.l   @(0xD4,PC),r14        ! r14 = 0x060785FC (&VDP1_write_ptr)

    ! Clear loop counter
    mov.l   @(0xD4,PC),r3         ! r3 = 0x06078620 (&sprite_loop_counter)
    mov.l   r4,@r3                  ! [sprite_loop_counter] = 0

    ! Check controller bit 0x08 → sets [0x0607861C] flag
    mov.l   @(0xD4,PC),r5         ! r5 = 0x0607861C (&controller_flag)
    mov.l   @(0xD8,PC),r0         ! r0 = 0x06063DA0 (&controller_state)
    mov.w   @r0,r0
    extu.w  r0,r0
    tst     #0x08,r0                ! bit 3 of controller state?
    bt      .ctrl_clear
    mov     #1,r3
    mov.l   r3,@r5                  ! [controller_flag] = 1
    bra     .loop_init
    nop
.ctrl_clear:
    mov.l   r4,@r5                  ! [controller_flag] = 0

.loop_init:
    mov.l   @(0xBC,PC),r11        ! r11_addr = 0x06078620 (&loop_counter)
    bra     .loop_check
    mov.l   @r11,r11               ! r11 = 0 (loop_counter, delay slot)

    ! ==========================================================
    ! SPRITE COMMAND LOOP
    ! r11 = sprite index (0 to sprite_count-1)
    ! Each iteration reads a sprite index from the lookup table,
    ! fetches the 24-byte sprite entry, and dispatches to the
    ! appropriate VDP1 command builder.
    ! ==========================================================

.sprite_loop:
    ! Read sprite index from lookup table
    mov     r11,r12                 ! r12 = loop_index
    shll    r12                     ! r12 *= 2 (word-indexed)
    mov.l   @(0xC0,PC),r3         ! r3 = 0x0606A4F8 (sprite index table)
    add     r3,r12                  ! r12 = &table[loop_index]
    mov.w   @r12,r12                ! r12 = sprite_index (word)
    extu.w  r12,r12

    ! Compute sprite entry address: 0x0608AC20 + sprite_index * 24
    extu.w  r12,r0                  ! r0 = sprite_index
    mov     r0,r2                   ! r2 = copy
    shll2   r0                      ! r0 = index * 4
    shll2   r2                      ! r2 = index * 4
    shll    r0                      ! r0 = index * 8
    shll2   r2                      ! r2 = index * 16
    add     r2,r0                   ! r0 = index * 24
    extu.w  r0,r0                   ! wrap to 16-bit
    add     r13,r0                  ! r0 = 0x0608AC20 + index*24

    ! Read sprite type from entry offset +6
    mov.w   @(0x6,r0),r0           ! r0 = entry[+6] (sprite type word)
    extu.w  r0,r0
    cmp/eq  #9,r0                   ! type == 9? (special sprite)
    bf      .normal_sprite

    ! === Type 9: Special sprite builder ===
    mov     r10,r6                  ! r6 = 0x8000 (draw-end marker)
    extu.w  r12,r4                  ! r4 = sprite_index
    mov.l   @r14,r5                 ! r5 = [VDP1_write_ptr] (dest)
    ! Compute r4 = 0x0608AC20 + sprite_index * 24
    mov     r4,r3
    shll2   r4
    shll2   r3
    shll    r4
    shll2   r3
    add     r3,r4
    extu.w  r4,r4
    mov.l   @(0x8C,PC),r3         ! r3 = 0x060281B8 (special builder)
    jsr     @r3                     ! FUN_060281B8(entry, write_ptr, 0x8000)
    add     r13,r4                  ! r4 = entry address (delay slot)
    bra     .advance
    nop

.normal_sprite:
    ! === Normal sprite builder ===
    mov.l   @r14,r5                 ! r5 = [VDP1_write_ptr] (dest)
    extu.w  r12,r4                  ! r4 = sprite_index
    ! Same multiply-by-24 pattern
    mov     r4,r3
    shll2   r4
    shll2   r3
    shll    r4
    shll2   r3
    add     r3,r4
    extu.w  r4,r4
    jsr     @r8                     ! FUN_060280F8(entry, write_ptr)
    add     r13,r4                  ! r4 = entry address (delay slot)

.advance:
    ! Increment loop index and write pointer
    add     #1,r11                  ! sprite_index++
    mov.l   @r14,r2
    add     #32,r2                  ! write_ptr += 32 (one VDP1 command)
    mov.l   r2,@r14

.loop_check:
    ! Check if more sprites to process
    mov.l   @r9,r3                  ! r3 = [0x060620D0] (total sprite count)
    cmp/hs  r3,r11                  ! loop_index >= total?
    bf      .sprite_loop            ! no: continue loop

    ! ==========================================================
    ! POST-LOOP: accumulate, HUD, cleanup
    ! ==========================================================

    ! Add sprite count to frame counter
    mov.l   @(0x60,PC),r4         ! r4 = 0x0605A008 (&frame_counter)
    mov.l   @r9,r3                  ! r3 = sprite_count
    mov.l   @r4,r2
    add     r3,r2
    mov.l   r2,@r4                  ! [frame_counter] += sprite_count

    ! Conditional HUD rendering: check state bits
    mov.l   @(0x5C,PC),r3         ! r3 = 0x0607EBC4 (&state_bits)
    mov.l   @(0x5C,PC),r2         ! r2 = 0x20228000 (HUD-active mask)
    mov.l   @r3,r3
    and     r2,r3
    tst     r3,r3
    bt      .no_hud                 ! none of the HUD bits set: skip

    ! HUD rendering path
    mov.l   @(0x58,PC),r3         ! r3 = 0x060333D8
    jsr     @r3                     ! FUN_060333D8 — HUD overlay rendering
    nop
    bsr     FUN_06007A50            ! FUN_06007A50 — additional rendering pass
    nop

.no_hud:
    ! Post-sprite cleanup
    mov.l   @(0x50,PC),r3         ! r3 = 0x06011DC0
    jsr     @r3                     ! FUN_06011DC0 — post-sprite cleanup
    nop

    ! Epilogue + tail call
    lds.l   @r15+,pr
    mov.l   @r15+,r8
    mov.l   @r15+,r9
    mov.l   @r15+,r10
    mov.l   @r15+,r11
    mov.l   @r15+,r12
    mov.l   @r15+,r13
    mov.l   @(0x40,PC),r3         ! r3 = 0x060171AC
    jmp     @r3                     ! tail call FUN_060171AC (final cleanup)
    mov.l   @r15+,r14               ! restore r14 (delay slot)
