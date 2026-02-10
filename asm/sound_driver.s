\! ================================================
\! AUDIT: MEDIUM -- Mixed accuracy. The command dispatcher (FUN_0601D5F4) and channel
\! handler sections are mostly correct in structure, but contain several specific errors.
\! The higher-level sound management section (0x060302C6-0x06030EE0) has significant
\! misidentifications. FUN_0601DB84 is incorrectly described. 0x06086050 semantics are
\! inverted. The "fire and forget" claim directly contradicts the busy-wait protocol.
\! FUN_060302C6 is NOT sound initialization -- it is the per-car engine sound generator
\! (correctly identified in engine_sound.s). File names (SOUNDS.BIN, MUSICD.BIN, etc.)
\! and course-specific sound descriptions are speculative with no binary evidence.
\! Audited: 2026-02-09
\! ================================================

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
!   Enable check:
!     Reads 0x06086050 — if non-zero, sound system has TIMED OUT (error)
!     AUDIT NOTE: 0x06086050 is a TIMEOUT ERROR flag, NOT an enable flag.
!     If non-zero, the sound system had a timeout -- it branches to skip,
!     meaning the sound system is DEAD, not disabled.
!     If error flag set, branches to early return
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
!     0x25A02C20 — SCSP command register (hardware)
!     0x0608604C — Local sound state mirror (software)
!
!   SCSP address encoding:
!     0xA0xxxxxx = base SCSP address space
!     0xA17000FF = channel offset for channel B
!     0xA27000FF = channel offset for channel C
!     0xA37000FF = channel offset for channel D
!     The 0x70 in each = specific register within channel
!     The 0xFF = command parameter mask

! FUN_0601DB84 — Mailbox busy-wait (26 bytes, 13 insns, LEAF)
! AUDIT NOTE: INCORRECTLY DESCRIBED. This is NOT "state prep" -- it is the
!   mailbox busy-wait that polls [0x25A02C20] until the 68000 clears it to 0.
!   Timeout: 100,000 iterations. Sets [0x06086050]=1 on timeout. See sound.s
!   FUN_0601DB84 for the correct and verified description.


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
!   3. If different, call FUN_0601DB84 (prep)
!   4. Write new sound ID to state address
!   5. Write command to 0x0608604C and 0x25A02C20

! FUN_0601D6B2 — Direct sound write (26 bytes, 13 insns)
\! CONFIDENCE: DEFINITE -- Verified byte-for-byte against aprog.s.
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
! SOUND MANAGEMENT SYSTEM (0x060302C6-0x06030EE0)
! =============================================================================
!
! Higher-level sound management — initialization, music playback,
! and sound effect coordination.

! FUN_060302C6 — INCORRECTLY IDENTIFIED (470 bytes, 235 insns)
! AUDIT NOTE: THIS IS NOT SOUND INITIALIZATION. FUN_060302C6 is the per-car
! engine sound generator. Binary confirms: push r8-r13, falls through to FUN_060302D2
! which does mov #0,r9 (sound byte accumulator), mov r0,r6 (input bitmask).
! References 0x0607E944 (car pointer), 0x0607ED8C (replay flag), 0x06063D9A
! (button state), 0x0608188A (accelerate bitmask). See engine_sound.s for the
! CORRECT description.
! CONFIDENCE: SPECULATIVE -- The original description here is WRONG.
!   AUDIT NOTE: File names below are FABRICATED -- no string evidence in binary:
!     SOUNDS.BIN  — Sound effect samples
!     MUSICD.BIN  — Music data (main)
!     MUSIC2D.BIN — Music data (track 2)
!     MUSIC3D.BIN — Music data (track 3)
!   Sets up channel routing and default volumes.

! FUN_0603072E — Sound state dispatcher (542 bytes, 271 insns)
\! CONFIDENCE: SPECULATIVE -- Address confirmed in binary but course-specific
\! descriptions (canyon echoes, dinosaur effects, city ambience) are creative
\! interpretation with no direct binary evidence.
!   Routes sound commands based on game state.
!   Different sound banks per course:
!     Course 0 (Beginner): Standard engine sounds, crowd
!     Course 1 (Advanced): Canyon echoes, dinosaur effects
!     Course 2 (Expert): City ambience, traffic sounds

! FUN_06030B68 — Sound event handler (578 bytes, 289 insns)
\! CONFIDENCE: SPECULATIVE -- Address confirmed but descriptions (collision sounds,
\! tire screech, 3D positional audio) are speculative. No SCSP panning register
\! writes visible from SH-2 side -- panning would be done by the 68000 driver.
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
! | 0x25A02C20  |   4B | Command register           |
! | 0x0605DF94  |   4B | Channel A state (software) |
! | 0x0605DF98  |   4B | Channel B state (software) |
! | 0x06086050  |   4B | Timeout ERROR flag (NOT enable\!) |
! | 0x0608604C  |   4B | Sound state mirror         |
!
! Channel encoding:
!   0xA0 = base
!   0xA1 = channel B offset
!   0xA2 = channel C offset
!   0xA3 = channel D offset
!   0x70 = register offset within channel
!   0xFF = parameter value mask
!
! The sound driver uses a simple command protocol:
!   Write command word to 0x25A02C20 → SCSP processes it
! AUDIT NOTE: WRONG -- There IS handshaking. FUN_0601DB84 polls [0x25A02C20]
!   until clear before every write. This is NOT fire-and-forget.

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
