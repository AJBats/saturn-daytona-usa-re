! ================================================
! AUDIT: HIGH — Display element interpreter pattern confirmed by binary; shared processor
!   at 0x06032304 loads from 0x060623B0 array with shll2 index, reads display list at +0x2D8.
!   Thunk chain (0603226C-060322AE) with consecutive r4 values verified. Specific HUD element
!   labels (speed, RPM, gear, lap time) are reasonable for a racing game HUD but rely on
!   parameter inference rather than hardware register access.
! Audited: 2026-02-10
! ================================================
!
! =============================================================================
! VDP Display Element System (0x06030000-0x06033FFF)
! =============================================================================
!
! 215 functions total, 205 previously unmapped
! Mostly small thunks that call shared display renderers with different indices
!
! ARCHITECTURE:
!   The display element system uses a shared interpreter pattern:
!   - FUN_06032304: Core display element processor
!     - Loads object from array at 0x060623B0[r4] (shll2 index)
!     - Reads display list pointer at object+0x2D8
!     - Processes 3 command words (sequence, type, data)
!     - Jump table dispatch through 12 command types at 0x06032334
!   - FUN_060322E8: Display enable check
!     - Reads enable flag at 0x06082A24
!     - If enabled, increments counter at 0x06082A20
!   - Tiny thunks (8-14 bytes) set r4=constant and tail-call into shared code
!
! FUNCTION TABLE:
!
! === Large Display/Sound Controllers ===
!
! CONFIDENCE: MEDIUM — FUN_06030548 is genuinely large (2332B) and reads from car object
!   array and button state. "Sound/music controller" label is plausible (complex state
!   machine with command dispatching) but no SCSP register access found in this function
!   directly; it likely communicates through a sound driver layer.
! FUN_06030540 (8B) - LEAF stub, minimal return
! FUN_06030548 (2332B) - HUGE: Main sound/music controller
!   Reads from 0x0607E944 (car object), 0x0607ED8C (init flag),
!   0x06063D9A (button presses). Complex state machine for sound playback.
!   Manages BGM tracks, SFX channels, and volume control.
!
! FUN_06030E64 (14B) - Wrapper stub for sound subsystem
! FUN_06030E72 (346B) - Sound channel manager
!   Processes audio command queue, dispatches to sound driver
!
! FUN_06030FCC (48B) - Sound enable/disable toggle
! FUN_06030FFC (34B) - Sound volume setter
!
! FUN_0603101E (860B) - HUD number renderer
!   Large function handling digit-by-digit display of race times,
! CONFIDENCE: HIGH — 860-byte function with BCD conversion and digit sprite lookup is
!   a classic number rendering pattern. "HUD number renderer" label well-supported.
!   lap numbers, speed values. Uses BCD conversion and sprite lookup.
!
! FUN_0603137A (34B) - Display element init stub
! FUN_0603139C (820B) - Position/lap display renderer
!   Renders current position (1st-8th), lap count, best lap time.
!   Manages digit sprites and position suffix (st/nd/rd/th).
!
! FUN_06031A34 (972B) - Timer/countdown display
!   Renders race countdown timer with minutes:seconds:centiseconds
! CONFIDENCE: HIGH — Timer with minutes:seconds:centiseconds format, blinking on low time,
!   and flash effects are standard racing game countdown patterns.
!   Handles blinking on low time, color changes, flash effects.
!
! FUN_06031E00 (960B) - Speed/tachometer display
!   Renders speedometer needle, digital speed value, RPM gauge.
! CONFIDENCE: MEDIUM — 960-byte function with fixed-point gauge interpolation is consistent
!   with speedometer/tachometer. mul.l with r6 parameter by 24 at entry suggests indexing
!   into display element array. "Speed/tachometer" is a reasonable label but specific
!   gauge type not independently confirmed.
!   Fixed-point math for gauge interpolation.
!
! === Display Element Setup ===
!
! FUN_060321DC (18B) - Display init helper
! FUN_060321EE (126B) - Display element table initializer
!   Sets up the 0x060623B0 object array with initial display state
!
! === Indexed Display Element Thunks (the "digit renderer" cluster) ===
!
! CONFIDENCE: DEFINITE — Binary verified: FUN_0603226C pushes r8-r14, loads r4=0,
!   falls through to FUN_0603227C which does bsr 0x06032304 (confirmed), then r4=1, etc.
!   Consecutive r4 values 0-6 confirmed in pool literals. Shared prologue/epilogue pattern
!   is an unmistakable display element iteration idiom.
! FUN_0603226C (16B) - Push r8-r14, load r4=0, fall through to FUN_0603227C
! FUN_0603227C (10B) - Call FUN_06032304 (shared processor), set r4=1
! FUN_06032286 (10B) - Call FUN_06032304, set r4=2
! FUN_06032290 (10B) - Call FUN_06032304, set r4=3
! FUN_0603229A (10B) - Call FUN_06032304, set r4=4
! FUN_060322A4 (10B) - Call FUN_06032304, set r4=5
! FUN_060322AE (8B)  - Call FUN_06032304, set r4=6
! FUN_060322B6 (252B) - Call FUN_060322E8 (enable check), pop r8-r14, rts
!   NOTE: FUN_060322B6 is the "epilogue" for the 0603226C-060322AE chain.
!   These functions form a single logical unit with shared prologue/epilogue.
!
! === Display Command Table Handlers (jump targets from 0x06032334) ===
!
! FUN_060323B2 (50B)  - Command type 0: Horizontal scroll
! FUN_060323E4 (70B)  - Command type 1: Vertical scroll
! FUN_0603242A (194B) - Command type 2: Full position update
!
! === Sprite/Tile Index Setters (tiny thunks, 8-14 bytes each) ===
!
! Pattern: sts.l pr; bsr FUN_shared; nop; lds.l pr; <fall-through-to-next>
! Each sets a different display element index or tile ID.
!
! 8-byte thunks (4 insns): Just set r4 and fall through
! FUN_060324EC (8B)  FUN_060324F4 (8B)  FUN_060324FC (8B)
! FUN_06032504 (12B) FUN_06032510 (8B)  FUN_06032518 (8B)
! FUN_06032520 (8B)  FUN_06032528 (8B)
!
! === Multi-digit Display Renderers ===
!
! FUN_06032530 (86B)  - 2-digit number renderer (tens+ones)
! FUN_06032586 (26B)  - Digit separator (colon for time display)
! FUN_060325A0 (14B) FUN_060325AE (86B) - Digit pair thunks
!
! === Position/Rank Display Group ===
!
! FUN_06032604 (20B)  FUN_06032618 (22B)  FUN_0603262E (20B)
! FUN_06032642 (20B)  FUN_06032656 (62B) - Position suffix renderer
!
! === Lap Time Display Group ===
!
! 14-byte thunks (7 insns): Index setters for lap time digits
! FUN_06032694 (14B)  FUN_060326A2 (26B)  FUN_060326BC (14B)
! FUN_060326CA (14B)  FUN_060326D8 (14B)
! FUN_060326E6 (64B)  - Lap time digit group renderer
! FUN_06032726 (24B)  FUN_0603273E (14B)  FUN_0603274C (14B)
! FUN_0603275A (14B)
!
! === Best Time Display Group ===
!
! FUN_06032768 (150B) - Best lap time full renderer
! FUN_060327FE (24B)  FUN_06032816 (14B)  FUN_06032824 (14B)
! FUN_06032832 (14B)
!
! === Speed Display Groups ===
!
! CONFIDENCE: MEDIUM — Grouped thunks with sequential indices for "hundreds/tens/ones"
!   digits, "KM/H" label renderer, and decimal point are consistent with speed display.
!   Specific element names (hundreds digit, tens digit) inferred from rendering order.
! FUN_06032840 (74B)  - Speed hundreds digit
! FUN_0603288A (14B)  - Speed tens digit
! FUN_06032898 (74B)  - Speed ones digit
! FUN_060328E2 (14B)  - Speed decimal point
! FUN_060328F0 (64B)  - Speed group renderer
! FUN_06032930 (24B) FUN_06032948 (14B) FUN_06032956 (14B)
! FUN_06032964 (14B) - Speed digit thunks
! FUN_06032972 (74B)  - Alternate speed renderer
! FUN_060329BC (14B)  - Speed suffix
! FUN_060329CA (74B)  - KM/H label renderer
! FUN_06032A14 (14B)  - Unit selector
! FUN_06032A22 (64B)  - Speed display commit
!
! === RPM/Tachometer Display Group ===
!
! CONFIDENCE: MEDIUM — Similar thunk pattern to Speed group. "RPM" and "tachometer"
!   labels are reasonable given separate display group for engine-related gauge, but
!   could be any secondary numeric display.
! FUN_06032A62 (142B) - RPM gauge renderer
! FUN_06032AF0 (14B) FUN_06032AFE (14B) FUN_06032B0C (14B) - RPM digit thunks
! FUN_06032B1A (64B)  - RPM display commit
! FUN_06032B5A (24B) FUN_06032B72 (14B) FUN_06032B80 (14B)
! FUN_06032B8E (14B) - RPM bar segments
! FUN_06032B9C (74B)  - RPM bar renderer
! FUN_06032BE6 (14B)  - RPM redline marker
! FUN_06032BF4 (64B)  - RPM display group
!
! === Gear/Status Display Group ===
!
! FUN_06032C34 (24B) FUN_06032C4C (14B) FUN_06032C5A (14B)
! FUN_06032C68 (14B) - Gear indicator thunks
! FUN_06032C76 (74B)  - Gear indicator renderer
! FUN_06032CC0 (14B)  - Neutral indicator
! FUN_06032CCE (64B)  - Gear display commit
!
! === Complex Display Controller ===
!
! FUN_06032D0E (432B) - Master HUD compositor
!   Orchestrates multiple display elements per frame.
!   Uses data table at 0x06032D1E for element offsets.
!   Calls rendering functions at 0x06026E2E, 0x06026E94, 0x06026F2A, 0x06026EDE.
!   References 0x06089EDC (VDP1 display list pointer).
!
! === Mini-map/Radar Display Group ===
!
! CONFIDENCE: SPECULATIVE — "Mini-map/Radar" label is inferred from multiple small
!   thunks (car dots, track outline, waypoints). Daytona USA does have a minimap but
!   the specific element assignments are best guesses based on thunk count and ordering.
! FUN_06032EBE (26B)  - Map element offset setter
! FUN_06032ED8 (14B) FUN_06032EE6 (22B) FUN_06032EFC (22B)
! FUN_06032F12 (14B) FUN_06032F20 (10B) FUN_06032F2A (10B)
! FUN_06032F34 (24B) FUN_06032F4C (22B) FUN_06032F62 (14B)
! FUN_06032F70 (10B) FUN_06032F7A (10B) FUN_06032F84 (22B)
!   Mini-map display elements - car dots, track outline, waypoints
!
! === Remaining Display Elements ===
!
! FUN_06032F9A (22B) FUN_06032FB0 (12B) FUN_06032FBC (10B)
! FUN_06032FC6 (14B) - Small display helpers
! FUN_06032FD4 (76B)  - Display mode switcher
! FUN_06033086 (8B) FUN_0603308E (22B) FUN_060330A4 (92B) - Display utility stubs
! FUN_06033100 (44B)  - Display palette loader
! FUN_0603312C (112B) - Color animation controller
!
! === Results/Ranking Display ===
!
! FUN_0603319C (14B) FUN_060331AA (16B) FUN_060331BA (16B)
! FUN_060331CA (16B) - Results digit thunks
! FUN_060331DA (86B)  - Results screen digit group
! FUN_06033230 (16B)  - Results separator
! FUN_06033240 (248B) - Full results display renderer
! FUN_06033338 (86B)  - Results time renderer
! FUN_0603338E (22B) FUN_060333A4 (64B) FUN_060333E4 (16B)
! FUN_060333F4 (14B) - Results sub-elements
!
! === Attract Mode Display ===
!
! FUN_06033402 (8B)   - Attract mode stub
! FUN_0603340A (30B)  - Attract mode init
! FUN_06033428 (10B)  - Attract element
! FUN_06033432 (8B)   - Attract cleanup
!
! === Split-Screen Display ===
!
! FUN_0603343A (152B) - Split-screen HUD renderer
!   Handles 2-player mode display elements
! FUN_060334D2 (8B)   - Split-screen stub
! FUN_060334DA (158B) - Split-screen position display
!
! === Course-Specific Display ===
!
! FUN_06033578 (22B) FUN_0603358E (16B) FUN_0603359E (16B)
! FUN_060335AE (16B) - Course name display thunks
! FUN_060335BE (72B)  - Course name renderer
! FUN_06033606 (14B)  - Course name separator
! FUN_06033614 (102B) - Course description display
! FUN_0603367A (50B)  - Course preview element
! FUN_060336AC (122B) - Course stats display
! FUN_06033726 (18B)  - Course transition
! FUN_06033738 (118B) - Course selector highlight
! FUN_060337AE (16B)  - Course icon
! FUN_060337BE (8B)   - Course stub
!
! === Master Display Manager ===
! CONFIDENCE: HIGH — FUN_060337C6 at 742 bytes is the largest function in range.
!   Binary confirmed: first instruction is bsr 0x06033504. Per-frame orchestrator
!   pattern (checks game state, enables/disables element groups) well-supported by
!   function size and call-out pattern to other display functions.
!
! FUN_060337C6 (742B) - LARGEST in range: Master display element manager
!   Per-frame orchestrator for all HUD elements.
!   Checks game state, enables/disables element groups.
!   Manages display priorities and layering.
!
! === Time Extension Display ===
!
! FUN_06033C08 (12B)  FUN_06033C14 (12B)  FUN_06033C20 (18B)
! FUN_06033C32 (60B)  - Time extension digits
!
! === Selector Digit Thunks (19 consecutive 10-byte functions!) ===
!
! FUN_06033C6E (10B) FUN_06033C78 (10B) FUN_06033C82 (10B)
! FUN_06033C8C (10B) FUN_06033C96 (10B) FUN_06033CA0 (10B)
! FUN_06033CAA (10B) FUN_06033CB4 (10B) FUN_06033CBE (10B)
! FUN_06033CC8 (10B) FUN_06033CD2 (10B) FUN_06033CDC (10B)
! FUN_06033CE6 (10B) FUN_06033CF0 (10B) FUN_06033CFA (10B)
! FUN_06033D04 (10B) FUN_06033D0E (10B) FUN_06033D18 (10B)
! FUN_06033D22 (10B)
! Pattern: bsr shared_handler; nop; lds.l; mov.l r4=N; fall-through
! These render individual digits 0-9 and selector characters for
! the time extension speed selection screen (1-99 speed input).
!
! === Additional Selector Display Thunks ===
!
! FUN_06033D2C (74B) - Selector group renderer
! FUN_06033D76 (20B) FUN_06033D8A (10B) FUN_06033D94 (10B)
! FUN_06033D9E (10B) FUN_06033DA8 (16B) FUN_06033DB8 (10B)
! FUN_06033DC2 (10B) FUN_06033DCC (10B) FUN_06033DD6 (10B)
! FUN_06033DE0 (16B) FUN_06033DF0 (10B) FUN_06033DFA (10B)
! FUN_06033E04 (10B) FUN_06033E0E (10B) FUN_06033E18 (10B)
! FUN_06033E22 (10B) FUN_06033E2C (10B) FUN_06033E36 (10B)
! FUN_06033E40 (10B)
!   Extended selector/digit thunks for various display modes
!
! === Score/Bonus Display ===
!
! FUN_06033E4A (94B)  - Score display renderer
! FUN_06033ED2 (12B) FUN_06033EDE (12B) FUN_06033EEA (12B) - Score digit thunks
! FUN_06033EF6 (138B) - Bonus points display
!
! === Final Stub Group ===
!
! FUN_06033F80 (8B)   FUN_06033F88 (8B)   FUN_06033F90 (32B)
! FUN_06033FB0 (8B)   FUN_06033FB8 (8B)   FUN_06033FC0 (8B)
! FUN_06033FC8 (12B)  FUN_06033FD4 (8B)   FUN_06033FDC (8B)
! FUN_06033FE4 (8B)   FUN_06033FEC (8B)
! FUN_06033FF4 (66B)  - Display cleanup / frame-end flush
!
! =============================================================================
! KEY DATA STRUCTURES
! =============================================================================
!
! 0x060623B0 - Display element object array (indexed by r4, 4-byte pointers)
! 0x06082A24 - Display enable flag (byte)
! 0x06082A20 - Display frame counter (int, incremented per frame)
! 0x06089EDC - VDP1 display list base pointer
! 0x06032334 - Jump table for 12 display command types
!
! =============================================================================
! EXTRACTION PRIORITY: LOW
! =============================================================================
! CCE has its own display/HUD system. These functions are Saturn-specific
! VDP1 sprite renderers that cannot be directly transplanted.
! However, the display DATA structures (what to show, positions, sizes)
! could inform CCE HUD layout.
