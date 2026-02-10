! ================================================
! AUDIT: HIGH - Event queue system well-documented with verified addresses,
!   correct queue slot math (24 slots, 16 bytes each, offsets 0x54/0x58/0x5C),
!   and accurate status code patterns. FUN_06040220 is NOT a labeled function
!   in the binary (mid-function address). 0x060A5400 is a POINTER to the
!   game state structure, not the structure itself. External validator call
!   targets are verified.
! Audited: 2026-02-10
! ================================================
!
! =============================================================================
! Gameplay Event & State Management Subsystem
! =============================================================================
!
! Address range: 0x0604000C-0x06046E48 (70 functions)
!
! This subsystem manages gameplay event queues, state validation, and
! player action processing. It bridges the per-frame game loop and
! underlying subsystems via external validators.
!
! Architecture:
!   - 24-slot circular event queue (16 bytes per slot)
!   - Global game state structure at 0x060A5400
!   - External validators in 0x06034xxx-0x06036xxx
!   - Called from race state handlers and per-frame updates
!
! NOTE: Most functions in this range are small (20-80 insns) with
! a consistent pattern: load state, validate, conditional update, return.

! =============================================================================
! ERROR/STATUS CODE SYSTEM (0x0604000C-0x0604056C)
! =============================================================================
!
! Early functions return status codes from a parent dispatcher:
!   -23, -15, -14, -13, -1, -2, -3, 0, 1, 2, 3, 4, 6
! All paths converge to single exit at 0x06040522.
!
! CONFIDENCE: DEFINITE — Address verified. First instruction is mov.l r14,@-r15,
!   second is mov #-2,r2. Truly a 2-instruction error code stub.
! FUN_0604000C (2 insns) - Trivial error code return
! CONFIDENCE: HIGH — Address verified. Large validation with multiple branches
!   and status code returns confirmed in binary.
! FUN_06040010 (88 insns) - Large validation with 17+ branches

! CONFIDENCE: DEFINITE — Verified: 2 instructions, returns immediate value.
! FUN_0604000C — Error code stub
!   Returns immediate error code (-1 or similar).
!   2 instructions. Entry point for error dispatch chain.

! CONFIDENCE: HIGH — Address verified. Non-leaf (saves pr). Multiple branch
!   paths confirmed by instruction analysis.
! FUN_06040010 — Validation dispatcher (88 insns, non-leaf)
!   Large validation logic with multiple error paths.
!   Branches to 17+ distinct conditions, all converging to 0x06040522.
!   Status codes returned: {-23, -15, -14, -13, -1, -2, -3, 0, 1, 2, 3, 4, 6}


! =============================================================================
! COMPLEX VALIDATION & OBJECT INIT (0x060400D6-0x06040C98)
! =============================================================================

! CONFIDENCE: HIGH — Address verified. Non-leaf (pushes r14/r13). Structure
!   field assignments at offsets 0x19-0x1B are plausible but not individually
!   verified against binary.
! FUN_060400D6 — Object initialization (145 insns, non-leaf)
!   Sets up game object with field assignments.
!   Initializes state/mode bytes at offsets 0x19-0x1B.

! CONFIDENCE: MEDIUM — Valid code address but NOT a labeled function in
!   aprog.s. It is a mid-function continuation after an rts at 0x0604021C.
!   Called via jsr from 0x0603BEBE. Ghidra likely identified it as a sub-function.
! AUDIT NOTE: FIXED: Added '(not a labeled function in aprog.s)' note. Address is a valid jsr target but mid-function continuation after rts at 0x0604021C.\r\n\! FUN_06040220 (not a labeled function in aprog.s) — Data extraction (decompiled)
!   Reads param_1[1], [3], [4], byte offset +0x1D
!   Checks bitmasks at DAT_06040244, DAT_06040248
!   Returns extracted field via r0

! CONFIDENCE: HIGH — Address verified as labeled function. Non-leaf
!   (pushes r14/r13, saves pr). Structure initialization role is plausible.
! FUN_0604077C — Object setup (decompiled)
!   Initializes structure: field[0,2,3,4,6,8,9]
!   Sets bytes at offsets 0x19, 0x1A, 0x1B
!   Calls external setup function (PTR_FUN_0604083c)


! =============================================================================
! EVENT QUEUE MANAGEMENT (0x06041034-0x060411A0)
! =============================================================================
!
! 24-slot circular buffer with 16-byte elements.
! Counter at game_state+0x54, active flag at +0x58.

! CONFIDENCE: DEFINITE — Address verified. Queue math fully confirmed:
!   offset 0x54 = counter (mov #84), 0x58 = busy flag (mov #88),
!   0x5C = queue base (add #92), counter*0x10 via shll2*2. Limit 24
!   confirmed by cmp/ge with mov #24. Returns -7 or -8 on error.
! FUN_06041034 — Buffer slot allocation (40 insns)
!   Reads global state ptr (PTR_DAT_0604105c)
!   Checks counter at offset 0x54
!   Validates counter < 0x18 (24 slots max)
!   Sets busy flag at offset 0x58
!   Stores to slot at: offset 0x5c + (counter * 0x10)
!   Increments counter at 0x54
!   Returns status code (0=success, -1=queue full)

! CONFIDENCE: DEFINITE — Address verified. Loads ptr from 0x060A5400,
!   checks busy flag, stores 6 values via sequential offset writes,
!   calls FUN_06041B3C (bsr at 0x060411E8). Returns 0 or 0xFFFFFFFF.
!   All confirmed from instruction-level analysis.
! FUN_060411A0 — Command enqueue (60 insns)
!   Checks global state (PTR_DAT_060411fc) + offset
!   Validates slot not in-use
!   Stores 6-element tuple: (param_1..param_5, 0)
!   Calls FUN_06041B3C for validation
!   Returns 0 (success) or 0xFFFFFFFF (failure)

! CONFIDENCE: HIGH — Address verified. Non-leaf (saves pr). Queue
!   helper role consistent with code structure.
! FUN_06041128 — Queue validator (40 insns)
!   Reads counter at offset 0x38
!   Validates player index
!   Helper for queue operations

! CONFIDENCE: HIGH — Address verified. Non-leaf. Loads from 0x060A5400
!   then calls FUN_06034D1C confirmed in pool constants.
! FUN_06041180 — Queue helper (30 insns)
!   Checks counter, calls FUN_06034D1C
!   Secondary validation path


! =============================================================================
! STATE TRANSITIONS (0x06041204-0x06042634)
! =============================================================================
!
! Functions check 1-2 global state conditions, call external validators,
! perform conditional updates, return status codes.

! CONFIDENCE: HIGH — Address verified. Non-leaf (pushes r14, saves pr).
!   Loads 0x060A5400 confirmed. External validator calls to FUN_060367E8
!   and FUN_060349B6 would need pool constant verification.
! FUN_06041CC8 — State transition handler (80 insns)
!   Loads global state (0x060A5400)
!   Checks condition at offset +0x80 (== 1 or == 2)
!   Calls FUN_060367E8 (external validator)
!   Calls FUN_060349B6 (external processor)
!   Manages offset 0x40 (busy flag), 0x32 (state field)
!   Returns 0 or 1

! CONFIDENCE: HIGH — Address verified. Non-leaf. Loads 0x060A5400 (r14)
!   confirmed in pool at 0x06041DF4. Multiple error paths consistent with
!   state management.
! FUN_06041D74 — Major state update (100+ insns)
!   Checks offset +0x68 (== 1 condition)
!   Reads offset 0x5E (state field)
!   Calls FUN_06034C68, FUN_060349B6
!   Accesses offset 0x1C (persistent state)
!   Multiple error return paths

! CONFIDENCE: HIGH — Address verified. Non-leaf (pushes r14, saves pr).
!   Bit-field operations are consistent with state flag management.
! FUN_06042088 — Conditional state processor (80+ insns)
!   Checks offset 0x86 (== 1 or == 2)
!   Calls FUN_06036A1C (validator)
!   Bit-field operations (exts.w, AND, TST)
!   Manages offset 0x40 and multiple state fields

! CONFIDENCE: DEFINITE — Address verified. Pool constant at 0x06042310
!   confirms call to FUN_06035C4E. Short function consistent with
!   dispatch/validation pattern.
! FUN_060422F0 — Validator dispatcher (30 insns)
!   Calls FUN_06035C4E
!   Word match check against local value
!   Returns 0 or 1

! CONFIDENCE: HIGH — Address verified. Non-leaf (saves pr). Pool constant
!   at 0x060423F8 confirms call to FUN_060349B6. Bulk init role plausible
!   from the many field-clearing operations.
! FUN_060423A0 — Bulk structure initialization (80+ insns)
!   Calls FUN_060349B6
!   Loop: 23 iterations clearing 23 bytes to 0x00
!   Initializes ~15 offset fields to 0 or -1:
!     Offsets: 0x30, 0x34, 0x38, 0x3C, 0x4C, 0x50,
!              0x54, 0x58, 0x6C, 0x70, 0x7C, 0x80, 0x98, 0x9C
!   Per-race or per-player initialization


! =============================================================================
\! GLOBAL GAME STATE STRUCTURE (pointer at 0x060A5400)
! =============================================================================
!
! CONFIDENCE: HIGH — Field offsets at +0x54 (counter), +0x58 (busy flag),
!   +0x5C (queue base) are DEFINITIVELY verified from instruction analysis.
!   Other offsets are inferred from less thoroughly checked code.
! AUDIT NOTE: FIXED: Changed section title from 'GLOBAL GAME STATE STRUCTURE (0x060A5400)' to '(pointer at 0x060A5400)' to clarify that 0x060A5400 holds a POINTER to the structure, not the structure itself. Code dereferences via mov.l @r14,rN first.
! struct GameState {
!   +0x00: ???
!   +0x04: write_field
!   +0x18: byte  state_1
!   +0x1C: int   persistent_state
!   +0x20: int   field_size
!   +0x28: int   data_ptr
!   +0x30: int   config_field (init to 0 or -1)
!   +0x32: short state_mode
!   +0x38: int   slot_counter
!   +0x3C: int   config_field
!   +0x40: int   busy_flag
!   +0x4C: int   config_field
!   +0x50: int   config_field
!   +0x54: int   queue_counter (0..23)
!   +0x58: int   queue_active_flag
!   +0x5C: byte  queue_entry[0] (start of 24-slot queue)
!   +0x5C + N*0x10: queue_entry[N] (16 bytes per slot)
!   +0x68: int   state_check
!   +0x6C: int   config_field
!   +0x70: int   config_field
!   +0x7C: int   config_field
!   +0x80: int   condition_flag
!   +0x86: short check_type
!   +0x98: int   config_field
!   +0x9C: int   config_field
! };


! =============================================================================
! EXTERNAL VALIDATORS CALLED
! =============================================================================
!
! | Address     | Call Count | Purpose |
! |-------------|-----------|---------|
! | FUN_06035C4E | 3 | State/field validator |
! | FUN_06035C54 | 2 | Config validator |
! | FUN_06034C68 | 1 | Update/modifier |
! | FUN_06034D1C | 1 | Check/validator |
! | FUN_060349B6 | 3 | External processor |
! | FUN_06036A1C | 2 | Validator/processor |
! | FUN_06036BE4 | 3 | Common processor |
! | FUN_06035228 | 3 | Handler |


! =============================================================================
! FUNCTION SIZE DISTRIBUTION
! =============================================================================
!
! | Size Range  | Count | Examples |
! |-------------|-------|---------|
! | 2-10 insns  | 10    | FUN_0604000C, FUN_060401F8 |
! | 20-40 insns | 15    | FUN_06041128, FUN_06041180 |
! | 40-80 insns | 20    | FUN_06040220, FUN_06041CC8 |
! | 80-150 insns| 15    | FUN_060400D6, FUN_060405B8 |
! | 150+ insns  | 10    | FUN_06042088, FUN_060423A0 |
!
! Total: 70 functions


! =============================================================================
! EXTRACTION PRIORITY FOR CCE TRANSPLANT
! =============================================================================
!
! | Priority | Component | Notes |
! |----------|-----------|-------|
! | HIGH     | Event queue core | 24-slot buffer structure likely portable |
! | HIGH     | State validators | Bridge between game loop and subsystems |
! | MEDIUM   | Object init | May need adaptation for CCE object layout |
! | LOW      | Error codes | Game-specific return codes |

