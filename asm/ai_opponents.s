! ============================================================
! AUDIT: SPECULATIVE
! This file contains MAJOR factual errors. Most function addresses
! cited (0x06035460, 0x060359E4, 0x06034F78, 0x06034FFC, 0x060350B0,
! 0x06035844, 0x06035B34) do NOT exist as function labels in the
! binary symbol table. They are mid-function addresses within
! FUN_06034F08 (the 2816-byte SMPC peripheral handler) or other
! functions. The descriptions (AI pathfinding, AI steering, AI state
! machine, AI target tracking) appear to be fabricated -- the actual
! code at these addresses is SMPC I/O and peripheral polling, not AI.
! 0x06034E58 is also NOT a function label -- it is a secondary entry
! point within FUN_06034E24. Only FUN_06035D5A and FUN_06035CBC are real
! function labels in this range.
! The car data addresses (0x060620D8 etc.) are valid references.
! The architecture diagram and difficulty scaling descriptions have
! no supporting evidence in the binary.
! ============================================================
!
! =============================================================================
! SMPC Peripheral I/O (High-Address Functions) [was: AI Opponent System]
! =============================================================================
!
! This file was originally titled "AI Opponent System" but the address range
! 0x06034E24-0x06035A07 is dominated by FUN_06034F08, the MAIN SMPC
! PERIPHERAL HANDLER (2816 bytes). The addresses below are mid-function
! entry points within that handler or adjacent SMPC functions.
!
! The actual AI opponent logic lives in FUN_0600C74E (ai_behavior.s) and
! FUN_0600E906, NOT in this address range.
!
! Address range: 0x06034E24-0x06035D5A

! =============================================================================
! SMPC HANDLER ENTRY POINTS (within FUN_06034F08)
! =============================================================================

! 0x06035460 -- Mid-function entry point within FUN_06034F08 (SMPC handler)
! CONFIDENCE: DEFINITE (verified in aprog.s and aprog_syms.txt)
! AUDIT NOTE FIXED: 0x06035460 is NOT a function label in aprog_syms.txt.
! It is a mid-function entry point within FUN_06034F08 (2816-byte SMPC
! handler, 0x06034F08-0x06035A07). Called via jsr from 0x06021C66,
! 0x06021CF6, 0x06021DB0 etc. The original description as "AI main loop"
! was fabricated -- this is SMPC I/O code, not AI behavior.
! The actual AI orchestrator is FUN_0600C74E (see ai_behavior.s).

! 0x060359E4 -- Mid-function entry point within FUN_06034F08 (SMPC handler)
! CONFIDENCE: DEFINITE (verified in aprog.s and aprog_syms.txt)
! AUDIT NOTE FIXED: 0x060359E4 is NOT a function label in aprog_syms.txt.
! It is a mid-function entry point within FUN_06034F08 (0x06034F08-0x06035A07).
! Called via jsr from 0x060105C2 and 0x060105F6. The original description as
! "AI physics integration" was fabricated -- this is SMPC peripheral code.


! =============================================================================
! SMPC COMMAND BUILDING (FUN_06034E24 range)
! =============================================================================

! 0x06034E58 -- Secondary entry point within FUN_06034E24 (SMPC command builder)
! CONFIDENCE: DEFINITE (verified in aprog.s and aprog_syms.txt)
! AUDIT NOTE FIXED: 0x06034E58 is NOT a function label in aprog_syms.txt.
! It falls within the address range of FUN_06034E24 (228 bytes, 0x06034E24-
! 0x06034F07). FUN_06034E24 ends with rts at 0x06034E4A; 0x06034E58 is a
! secondary entry point called via jsr from 0x0600317C. Its code writes 0 to
! 0x06063578, then polls byte at 0x0606358C (masking with 0x01, looping until
! bit clears), writes to 0x06063584 -- SMPC peripheral command building, NOT
! AI pathfinding.

! 0x06034F78 -- Mid-function entry point within FUN_06034F08 (SMPC handler)
! CONFIDENCE: DEFINITE (verified in aprog.s and aprog_syms.txt)
! AUDIT NOTE FIXED: 0x06034F78 is NOT a function label. It is mid-function code
! within FUN_06034F08 (SMPC handler, 0x06034F08-0x06035A07). Called via jsr from
! 0x06008302 and 0x0600830C. The original description as "AI steering input
! generator" was fabricated -- this code manipulates bit masks for SMPC I/O.

! 0x06034FFC -- Mid-function entry point within FUN_06034F08 (SMPC handler)
! CONFIDENCE: DEFINITE (verified in aprog.s and aprog_syms.txt)
! AUDIT NOTE FIXED: 0x06034FFC is NOT a function label. It is mid-function code
! within FUN_06034F08 (SMPC handler, 0x06034F08-0x06035A07). Referenced as pool
! constant from 0x0602DD9E and 0x0602DDC8. The original description as "AI state
! machine" with modes (Normal/Chasing/Defensive/Recovery) was fabricated.

! 0x060350B0 -- Mid-function entry point within FUN_06034F08 (SMPC handler)
! CONFIDENCE: DEFINITE (verified in aprog.s and aprog_syms.txt)
! AUDIT NOTE FIXED: 0x060350B0 is NOT a function label. It is mid-function code
! within FUN_06034F08 (SMPC handler, 0x06034F08-0x06035A07). Referenced as pool
! constant from 0x0601DC86 and 0x0601DCB0. The original description as "AI
! decision logic" was fabricated.


! =============================================================================
! MORE SMPC HANDLER ENTRY POINTS
! =============================================================================

! 0x06035844 -- Mid-function entry point within FUN_06034F08 (SMPC handler)
! CONFIDENCE: DEFINITE (verified in aprog.s and aprog_syms.txt)
! AUDIT NOTE FIXED: 0x06035844 is NOT a function label. It is mid-function code
! within FUN_06034F08 (SMPC handler, 0x06034F08-0x06035A07). Called via jsr from
! 0x0601CB38 and 0x0601CBA0. The original description as "AI target tracking"
! was fabricated -- this is SMPC peripheral code, not AI behavior.


! =============================================================================
! VERIFIED FUNCTION LABELS
! =============================================================================
!
! These are real function labels confirmed in aprog_syms.txt.

! FUN_06035D5A — Purpose unverified (150 bytes, 75 insns)
! CONFIDENCE: MEDIUM
! AUDIT NOTE FIXED: FUN_06035D5A IS a real function label (confirmed in
! aprog_syms.txt). Purpose not verified from binary -- "AI core initialization"
! is plausible but unsubstantiated.
!   Sets up initial AI state for all opponent cars.
!   Called during race start.

! FUN_06035CBC — Purpose unverified (86 bytes, 43 insns)
! CONFIDENCE: MEDIUM
! AUDIT NOTE FIXED: FUN_06035CBC IS a real function label (confirmed in
! aprog_syms.txt). Difficulty parameter descriptions are unsubstantiated.
!   Per-car AI parameter initialization.
!   Sets difficulty-dependent parameters:
!     - Reaction time delay
!     - Speed limit (percentage of maximum)
!     - Cornering aggression
!     - Braking distance multiplier

! 0x06035B34 -- Mid-function entry point within FUN_06035A08
! CONFIDENCE: DEFINITE (verified in aprog.s and aprog_syms.txt)
! AUDIT NOTE FIXED: 0x06035B34 is NOT in the symbol table (aprog_syms.txt).
! It is a mid-function entry point within FUN_06035A08 (512 bytes, 0x06035A08-
! 0x06035C07, secondary input processor). Called via jsr from 0x0601CC14 and
! 0x0601CC52. The original description as "AI system init" was fabricated.


! =============================================================================
! CORRECTED ARCHITECTURE
! =============================================================================
!
! AUDIT NOTE FIXED: The call tree that was here was fabricated. Most listed
! addresses are not real function boundaries -- they are mid-function entry
! points within FUN_06034F08 (SMPC handler). The actual AI update chain is:
!
!   FUN_0600E906 (AI physics entry, see ai_behavior.s)
!     |
!     +-> FUN_0600C74E (AI processing orchestrator)
!           +-> FUN_0600CD40 (waypoint targeting)
!           +-> 0x0600CA96 (course correction)
!           +-> FUN_0600C8CC (speed targeting)
!           +-> 0x0600C970 (speed boost lookup)
!           +-> 0x0600C928 (velocity/friction)
!           +-> FUN_0600C7D4 (heading/steering update)
!           +-> 0x06006838 (coordinate grid packing, within FUN_060067C8)
!           +-> FUN_06027EDE (VDP/sprite rendering update)
!
! Difficulty Scaling:
!   Not verified. FUN_06035CBC is a real function but the description of
!   difficulty-dependent parameters (reaction time, speed limits, cornering
!   aggression, braking distance) has no confirmed basis in the binary.
!
! Car Data:
!   AI cars use the same 4-car data structures as the player:
! CONFIDENCE: HIGH (addresses verified as referenced in the binary)
!     0x060620D8 (car 0 — player)
!     0x0606212C (car 1 — AI opponent 1)
!     0x06062180 (car 2 — AI opponent 2)
!     0x060621D8 (car 3 — AI opponent 3)
!   AI only controls cars 1-3; car 0 is always player-controlled.
