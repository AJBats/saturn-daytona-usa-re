! ================================================
! AUDIT: MEDIUM-HIGH -- Most errors from initial audit now corrected.
! Command dispatcher (FUN_0601D5F4) and channel handler sections verified.
! 0x06086050 correctly identified as timeout error flag. FUN_0601DB84 correctly
! described as mailbox busy-wait. FUN_060302C6 correctly identified as per-car
! engine sound generator (not sound init). Fabricated filenames removed.
! Handshake protocol correctly documented. Course-specific sound descriptions
! in FUN_0603072E and FUN_06030B68 remain speculative.
! Audited: 2026-02-09, FIXED: 2026-02-10
! ================================================

! =============================================================================
! SCSP Sound Driver & Audio System
! =============================================================================
!
! This file documents the Saturn's sound system interface — functions that
! communicate with the SCSP (Saturn Custom Sound Processor) via the
! sound RAM interface at 0x25A00000.
!
! Address range: 0x0601D5F4-0x0601D7D0 (command dispatcher + channel handlers)
!                0x060302C6-0x06030EE0 (sound management)
!
! The SCSP is accessed via shared memory at 0x25A00000-0x25AFFFFF.
! Sound commands are written to specific offsets in this region.

! =============================================================================
! SOUND COMMAND DISPATCHER (0x0601D5F4)
! =============================================================================
!
! FUN_0601D5F4 — Sound command dispatcher (190 bytes, 95 insns)
!
!   Master dispatcher for all sound commands. Called from gameplay code
!   to trigger sound effects, music, and audio state changes.
! CONFIDENCE: HIGH -- Dispatch structure (switch on r4, cases 0-5,15) verified.
! Channel bases confirmed in pool literals. Address is labeled in aprog.s.
!
!   Parameters:
!     r4 = command type (0-5, 15)
!     r5 = sound data / channel parameter
!
!   Timeout error check:
!     Reads [0x06086050] -- timeout error flag (set to 1 by FUN_0601DB84 on timeout)
!     FIXED: Corrected from "enable flag" to "timeout error flag". Binary confirms
!     FUN_0601DB84 sets [0x06086050]=1 after 100,000 failed polls of [0x25A02C20].
!     FUN_0601D5F4 reads it and branches to early return if non-zero (sound system dead).
!     If error flag set, branches to early return (all commands silently dropped)
!
!   Command dispatch (switch on r4):
!     0: Direct play — validates address (must have 0xA0000000 high bits),
!        calls FUN_0601DB84, writes to 0x25A02C20 and 0x0608604C
!     1: Channel A — builds command 0xA07000FF + (r5 << 8), tail-calls FUN_0601D6D4
!     2: Channel B — builds command 0xA17000FF + (r5 << 8), tail-calls FUN_0601D6F8
!     3: Channel C — builds command 0xA27000FF + (r5 << 8), tail-calls FUN_0601D72C
!     4: Direct pass — passes r14 directly, tail-calls FUN_0601D778
!     5: Channel D — builds command 0xA37000FF + (r5 << 8), tail-calls FUN_0601D79C
!    15: Same as 0 (validate + play)
!
!   All commands write to two destinations:
!     0x25A02C20 — SCSP command mailbox (shared sound RAM, read by 68000)
!     0x0608604C — Local sound command mirror (work RAM)
!
!   SCSP address encoding:
!     0xA0xxxxxx = base SCSP address space
!     0xA17000FF = channel offset for channel B
!     0xA27000FF = channel offset for channel C
!     0xA37000FF = channel offset for channel D
!     The 0x70 in each = specific register within channel
!     The 0xFF = command parameter mask

! FUN_0601DB84 — Mailbox busy-wait (26 bytes, 13 insns, LEAF)
! FIXED: Corrected from "state prep" to "mailbox busy-wait". Binary at 0x0601DB84
!   confirms: loads [0x25A02C20] (mailbox), loops with dt r4 (100,000 iterations),
!   polls until mailbox reads 0 (68000 has consumed previous command).
!   On timeout: sets [0x06086050]=1 (error flag). See sound.s FUN_0601DB84 for
!   full byte-verified instruction listing.
!   NOTE: 0x0601DB84 has no label in aprog.s -- it is an unlabeled subroutine
!   reached via bsr from FUN_0601D5F4, FUN_0601D6B2, and all channel handlers.


! =============================================================================
! CHANNEL HANDLERS (0x0601D6B2-0x0601D7D0)
! =============================================================================
!
! CONFIDENCE: HIGH -- All channel handler addresses confirmed as labels in aprog.s.
! State address 0x0605DF94 confirmed in pool literal. Pattern description is accurate.
! Each channel handler has two entry points:
!   FUN_xxxx: Setup entry (saves r14, sets up parameter)
!   FUN_xxxx+4: Main body (checks if sound already playing, sends command)
!
! Pattern for each channel:
!   1. Check if current sound (at state address) matches request
!   2. If same sound, skip (already playing)
!   3. If different, call FUN_0601DB84 (busy-wait for mailbox clear)
!   4. Write new sound ID to state address
!   5. Write command to 0x0608604C and 0x25A02C20

! FUN_0601D6B2 — Direct sound write (26 bytes, 13 insns)
! CONFIDENCE: DEFINITE -- Verified byte-for-byte against aprog.s.
!   Writes sound command directly without channel routing.
!   Calls FUN_0601DB84, writes to 0x25A02C20 and 0x0608604C.

! FUN_0601D6D4 / FUN_0601D6D8 — Channel A handler
!   State address: 0x0605DF94
!   Checks if current == requested, skips if match.
!   Writes to: 0x0605DF94, 0x0608604C, 0x25A02C20

! FUN_0601D6F8 / FUN_0601D6FC — Channel B handler
!   State address: 0x0605DF98
!   Same pattern as Channel A.

! FUN_0601D72C / FUN_0601D730 — Channel C handler (implied, follows B)
! FUN_0601D750 / FUN_0601D754 — Channel C continued
! FUN_0601D778 / FUN_0601D77C — Direct pass handler
! FUN_0601D79C / FUN_0601D7A0 — Channel D handler

! FUN_0601D7D0 — Display/notification sound handler (400 bytes, 200 insns)
! CONFIDENCE: MEDIUM -- Function exists at this address (confirmed as labeled in aprog.s).
! Pool references 0x06086054 (sound timer), 0x0607EAD8. Description as race event audio
! cues is plausible but specific claims about lap counting are interpretive.
!   Large handler called from lap counting system.
!   Triggers audio cues for race events (lap complete, position change).
!   Referenced by asm/lap_counting.s.


! =============================================================================
! PER-CAR ENGINE SOUND GENERATOR (0x060302C6-0x06030EE0)
! =============================================================================
!
! FIXED: Corrected from "SOUND MANAGEMENT SYSTEM" / "sound initialization" to
! "per-car engine sound generator". Binary confirms FUN_060302C6 is the prologue
! (push r8-r13) that falls through to FUN_060302D2 (labeled in aprog.s), which
! initializes r9=0 (sound byte accumulator) and r6=r0 (input bitmask).
! Pool references: 0x0607E944 (car pointer), 0x0607ED8C (replay flag),
! 0x06063D9A (button state), 0x0608188A (accelerate bitmask).
! See asm/engine_sound.s for the CORRECT and detailed description.

! FUN_060302C6 — Per-car engine sound generator (470 bytes, 235 insns)
! FIXED: Corrected from "sound initialization". This function generates engine
! sound bytes from car input state (acceleration, braking, gear level) and writes
! them to a ring buffer. The 68000 sound CPU reads these bytes to modulate
! engine audio. NOTE: 0x060302C6 has no label in aprog.s -- the 6 push
! instructions (mov.l r8-r13,@-r15) are the unlabeled prologue immediately
! before FUN_060302D2 which IS labeled.
! CONFIDENCE: HIGH -- See engine_sound.s for full verified description.
!
! FIXED: Removed fabricated filenames (SOUNDS.BIN, MUSICD.BIN, MUSIC2D.BIN,
! MUSIC3D.BIN). No string evidence exists in the binary for any of these names.
! The original annotation invented these names speculatively.

! FUN_0603072E — Sound state dispatcher (542 bytes, 271 insns)
! CONFIDENCE: SPECULATIVE -- Address confirmed in binary but course-specific
! descriptions (canyon echoes, dinosaur effects, city ambience) are creative
! interpretation with no direct binary evidence.
!   Routes sound commands based on game state.
!   Different sound banks per course:
!     Course 0 (Beginner): Standard engine sounds, crowd
!     Course 1 (Advanced): Canyon echoes, dinosaur effects
!     Course 2 (Expert): City ambience, traffic sounds

! FUN_06030B68 — Sound event handler (578 bytes, 289 insns)
! CONFIDENCE: SPECULATIVE -- Address confirmed but descriptions (collision sounds,
! tire screech, 3D positional audio) are speculative. No SCSP panning register
! writes visible from SH-2 side -- panning would be done by the 68000 driver.
!   Handles sound events from gameplay:
!     - Collision sounds (impact severity mapped to volume)
!     - Tire screech (steering angle mapped to pitch)
!     - Engine RPM (speed mapped to sound frequency)
!   Applies 3D positional audio via SCSP panning.


! =============================================================================
! SOUND HARDWARE MEMORY MAP
! =============================================================================
!
! | Address      | Size | Purpose                    |
! |-------------|------|----------------------------|
! | 0x25A00000  | 512KB| SCSP Sound RAM             |
! | 0x25A02C20  |   4B | Command mailbox (SH-2 writes, 68000 reads+clears) |
! | 0x0605DF94  |   4B | Channel A state (software) |
! | 0x0605DF98  |   4B | Channel B state (software) |
! | 0x06086050  |   4B | Timeout error flag (1=handshake failed) |
! | 0x0608604C  |   4B | Sound command mirror       |
!
! Channel encoding:
!   0xA0 = base
!   0xA1 = channel B offset
!   0xA2 = channel C offset
!   0xA3 = channel D offset
!   0x70 = register offset within channel
!   0xFF = parameter value mask
!
! The sound driver uses a handshake command protocol:
!   1. FUN_0601DB84 polls [0x25A02C20] until 0 (68000 consumed previous command)
!   2. SH-2 writes new 32-bit command to [0x25A02C20]
!   3. 68000 reads and processes the command, then clears [0x25A02C20] to 0
!   4. SH-2 also mirrors the command to [0x0608604C] for local state tracking
! FIXED: Corrected from "fire and forget" / "simple command protocol" to handshake
!   protocol. Binary confirms FUN_0601DB84 (bsr 0x0601DB84) is called before every
!   mailbox write, polling [0x25A02C20] with a 100,000-iteration timeout loop.

! =============================================================================
! CALL SITES (WHERE SOUND IS TRIGGERED)
! =============================================================================
!
! CONFIDENCE: MEDIUM -- Call site addresses are plausible but not individually
! verified. Cross-references to other asm/ files (force_system.s, lap_counting.s)
! are internal project references, not binary-verified.
! Game code calls FUN_0601D5F4 from:
!   - FUN_060200A4: Race start init (BGM command 0, data 0xAB1128FF)
!   - FUN_0600DB64/0600DB9E: Engine sound updates (per-frame)
!   - FUN_0600DA7C: Audio state transitions
!   - FUN_0600DCC8/0600DD88: Race event sounds
!   - asm/force_system.s: Collision sound effects
!   - asm/lap_counting.s: Lap complete / position change sounds
