! ================================================
! AUDIT: MEDIUM -- Most function addresses verified in binary; menu/UI descriptions are reasonable for address range; system init and math sections are well-grounded; some size/stub claims are wrong
! Audited: 2026-02-10
! ================================================
! =============================================================================
! UI System, Event Processing & System Utilities (0x06038000-0x06046FFF)
! =============================================================================
!
! 207 functions total, 77 previously unmapped
! Menu rendering, VDP management, event queue processing, system init
!
! =============================================================================
! FUNCTION CATALOG (UNMAPPED ONLY)
! =============================================================================
!
! === VDP Hardware Control (0x06038000-0x06038FFF) ===
!
\! FUN_06038F6C (12B) - Register prologue fragment (falls through to FUN_06038F78)\r\n\! CONFIDENCE: MEDIUM -- Address verified. Size IS 12 bytes (confirmed: 0x06038F78 - 0x06038F6C = 0x0C).\r\n\! AUDIT NOTE: FIXED: Size 12B is correct. Function pushes r14-r10 + mov #0,r10 (6 insns, 12B) and falls through to FUN_06038F78. NOT a standalone function — it is a prologue fragment. Renamed from 'VDP sync flag clear' to 'Register prologue fragment'.
!
! === Menu Display System (0x06039000-0x0603BFFF) ===
!
! FUN_0603990E (1806B) - MASTER MENU RENDERER
! CONFIDENCE: MEDIUM -- Address verified. Very large function with heavy callee-saved pushes (r14,r13,r12). Menu address range is plausible. Specific claims (course select 3D preview, car rotation, credits scroll) are speculative.
!   *** LARGEST IN THIS RANGE ***
!   Complete menu system orchestrator:
!   - Title screen rendering
!   - Course select 3D preview
!   - Car select display with rotation
!   - Options menu layout
!   - Credits scroll
!   Manages 20+ display elements per frame
!   Heavy use of VDP1 sprite commands
!
! FUN_0603AA82 (410B) - Menu animation system
! CONFIDENCE: SPECULATIVE -- Address verified. References 0x060A4CAE. "Keyframe interpolation with easing" is speculative.
!   Drives scale/rotation/fade animations for menu elements
!   Keyframe interpolation with easing curves
!
! FUN_0603ACEA (194B) - Menu input processor
! CONFIDENCE: MEDIUM -- Address verified. Saves r14,r13,r12. "Input processor" plausible for menu subsystem.
!   Maps controller buttons to menu actions
!   Handles repeat rate for held buttons
!
! FUN_0603AE74 (116B) - Menu sound trigger
! CONFIDENCE: SPECULATIVE -- Address verified. Saves r14,pr. "Sound trigger" is a guess.
!   Plays SFX on menu navigation (cursor, confirm, cancel)
!
! FUN_0603AFDC (124B) - Menu text layout engine
! CONFIDENCE: SPECULATIVE -- Address verified. References 0x060A4D14. "Font metrics" is speculative.
!   Positions text strings using font metrics
!
! FUN_0603B08E (50B)  - Menu element visibility toggle
! FUN_0603B0C0 (88B)  - Menu element alpha setter
!
! === Menu Sub-Elements (0x0603B100-0x0603B6A8) ===
!
\! FUN_0603B118 (4B)   - Register prologue fragment (falls through to FUN_0603B11C)\r\n\! CONFIDENCE: MEDIUM -- Address verified. Size 4B is correct.\r\n\! AUDIT NOTE: FIXED: Renamed from 'NOP stub' to 'Register prologue fragment'. Binary shows mov.l r14,@-r15; mov #0,r14 (push r14, init r14=0). Falls through to FUN_0603B11C.
! FUN_0603B11C (20B)  - Menu cursor blink timer
! FUN_0603B130 (56B)  - Menu cursor position update
! FUN_0603B168 (78B)  - Menu selection highlight
! FUN_0603B290 (140B) - Menu list scroller
! CONFIDENCE: SPECULATIVE -- Address verified. Saves r14,r13. "Scroll with acceleration" is speculative.
!   Scrolls long lists with acceleration
! FUN_0603B324 (110B) - Menu option value adjuster (left/right)
! FUN_0603B392 (56B)  - Menu toggle switch renderer
! FUN_0603B3CA (6B)   - Menu stub
! FUN_0603B3D0 (46B)  - Menu separator line
! FUN_0603B3FE (38B)  - Menu header renderer
!
! FUN_0603B53C (92B)  - Menu page transition
!   Slide/fade transition between menu pages
!
! FUN_0603B598 (56B)  - Menu background scroller
! FUN_0603B5D0 (34B)  - Menu background color setter
! FUN_0603B5F2 (26B)  - Menu background pattern
! FUN_0603B60C (36B)  - Menu border renderer
! FUN_0603B630 (4B)   - NOP stub
! FUN_0603B634 (76B)  - Menu timer/clock display
! FUN_0603B680 (40B)  - Menu credits element
! FUN_0603B6A8 (164B) - Menu ranking/leaderboard display
!
! === Save/Load System (0x0603B92C-0x0603BEB8) ===
!
! FUN_0603B92C (16B) - Save data checksum seed
! FUN_0603BE9C (28B) - Save data size getter
! FUN_0603BEB8 (106B) - Save data serializer
!   Converts game state to save format
!   Writes to Saturn backup RAM (0x22000000)
!
! === Record/High Score System (0x0603C10C-0x0603D518) ===
!
! FUN_0603C10C (156B) - High score table manager
!   Maintains sorted high score list
!   Inserts new entries, shifts lower scores
!
! FUN_0603D2D0 (216B) - High score display renderer
! FUN_0603D43C (216B) - Name entry state machine
!   3-character name entry for high score table
!   Alphabet grid navigation with cursor
!
! FUN_0603D518 (184B) - Name entry renderer
!   Displays character grid and current selection
!
! === Options/Settings (0x0603D7B0-0x0603E5BC) ===
!
! FUN_0603D7B0 (572B) - Options menu state machine
! CONFIDENCE: MEDIUM -- Address verified. Large menu-range function. Specific option claims speculative.
!   Sound test, difficulty, controller config
!
! FUN_0603DB28 (724B) - Controller configuration
! CONFIDENCE: SPECULATIVE -- Address verified. Large function. Button mapping is a guess.
!   Button mapping customization
!   Displays current bindings, allows remap
!
! FUN_0603E050 (1388B) - Sound test player
! CONFIDENCE: SPECULATIVE -- Address verified. Very large function. Sound test/PCM claims are detailed guesses.
!   Full sound test mode:
!   - BGM track selection and playback
!   - SFX preview
!   - Volume control
!   - PCM channel viewer
!
! FUN_0603E5BC (1296B) - Options renderer
!   Renders all option screen elements
!
! === Credit/Attract Mode (0x0603F238-0x0603FF3A) ===
!
! FUN_0603F238 (12B) - Credits stub
! FUN_0603F244 (156B) - Credits scroll engine
! CONFIDENCE: SPECULATIVE -- Address verified. References 0x06041698. Credits scroll is plausible but unverified.
!   Auto-scrolling text with multi-column support
!
! FUN_0603F2EC (86B)  - Credits text formatter
! FUN_0603F354 (162B) - Credits page builder
! FUN_0603F538 (74B)  - Attract mode demo selector
!   Chooses which demo replay to show during attract
!
! FUN_0603F948 (40B)  - Attract mode timer
! FUN_0603F974 (68B)  - Attract mode transition
! FUN_0603F9BC (94B)  - Attract mode demo loader
!
! FUN_0603FAE4 (380B) - Attract mode display orchestrator
! CONFIDENCE: SPECULATIVE -- Attract mode is standard arcade feature. Description plausible but unverified.
!   Full attract mode: logo, title, demo sequence
!
! FUN_0603FE44 (30B)  - Attract element A
! FUN_0603FE62 (30B)  - Attract element B
! FUN_0603FF3A (98B)  - Attract mode cleanup
!
! === System Initialization (0x06040000-0x060409C8) ===
!
! FUN_060401FC (192B) - Hardware initialization
! CONFIDENCE: MEDIUM -- Address verified. Plausible for 0x060400xx address range.
!   Saturn system registers setup
!   VDP1/VDP2 initial configuration
!
! FUN_060402BC (638B) - Full system boot sequence
! CONFIDENCE: MEDIUM -- Address verified. Large function referenced from 0x0603B7B0 area. Boot sequence plausible.
!   Memory clear, hardware init, disc check
!   Copyright screen display
!   Initializes all subsystems
!
! FUN_0604053A (126B) - Memory test
!   Verifies work RAM integrity at boot
!
! FUN_06040668 (24B)  - System timer init
! FUN_060406B4 (8B)   - Timer stub
! FUN_060406BC (104B) - System timer tick handler
! FUN_06040724 (88B)  - Timer overflow handler
! FUN_0604087C (52B)  - Watchdog timer reset
! FUN_0604097C (4B)   - NOP stub
! FUN_06040980 (72B)  - DMA channel setup
! FUN_060409C8 (30B)  - DMA completion check
!
! === Event Queue Extended (0x06040AF8-0x06040F1C) ===
!
! FUN_06040AF8 (60B)  - Event priority setter
! CONFIDENCE: MEDIUM -- Address verified. Saves r14,pr. Referenced from 0x0603BD74.
! FUN_06040B34 (90B)  - Event timer scheduler
!   Schedules delayed events with frame countdown
!
\! FUN_06040B8E (2B)   - Register push fragment (falls through to FUN_06040B90)\r\n\! CONFIDENCE: MEDIUM -- Address verified. 2 bytes is correct.\r\n\! AUDIT NOTE: FIXED: Renamed from 'Minimal stub (rts)' to 'Register push fragment'. Binary shows mov.l r14,@-r15 (push r14), NOT rts. Falls through to FUN_06040B90.
! FUN_06040B90 (128B) - Event callback dispatcher
! CONFIDENCE: MEDIUM -- Address verified. Callback dispatcher is plausible.
!   Calls registered event handler functions
!
! FUN_06040C5C (4B)   - NOP stub
! FUN_06040C60 (56B)  - Event queue flush
!   Clears all pending events (used during state transitions)
!
! FUN_06040F1C (102B) - Event queue overflow handler
!
! === Interrupt/Exception Handlers (0x060410CA-0x06042646) ===
!
! FUN_060410CA (94B)  - VBlank interrupt handler extension
! CONFIDENCE: MEDIUM -- Address verified. 20-byte stack frame. VBlank extension plausible.
!   Additional per-frame processing during VBlank
!
! FUN_06041382 (140B) - Error trap handler
! CONFIDENCE: SPECULATIVE -- Address verified. Error trap is a guess.
!   Catches illegal instructions, address errors
!   Displays debug info (may be unused in release)
!
! FUN_0604140E (98B)  - NMI handler
!   Non-maskable interrupt processing
!
! FUN_060416A8 (382B) - DMA completion interrupt handler
! CONFIDENCE: MEDIUM -- Address verified. 20-byte stack frame. DMA claim plausible.
!   Processes DMA transfer completions for all channels
!   Chains next DMA transfer if queued
!
! === Math/Lookup Utilities (0x06042418-0x06042646) ===
!
! FUN_06042418 (64B)  - Fixed-point divide helper
! CONFIDENCE: HIGH -- Address verified. Starts with cmp/pz r4 (sign check), consistent with division.
!   32-bit / 16-bit fixed-point division
!
! FUN_06042458 (476B) - Full fixed-point division
! CONFIDENCE: HIGH -- Address verified. cmp/pz r4 at start. 0xFFFFFF00 is standard SH-2 hardware divider.
!   32-bit / 32-bit signed division
!   Uses hardware divider unit at 0xFFFFFF00
!
! FUN_06042634 (18B)  - Division result reader
! FUN_06042646 (934B) - Math library: trig, sqrt, atan2
! CONFIDENCE: MEDIUM -- Address verified. Large function. Trig/sqrt claims plausible for math library size.
!   Complete fixed-point math library
!   sin/cos from lookup table, sqrt via Newton's method
!   atan2 approximation for heading calculation
!
! === Data Table (end of binary) ===
!
\! FUN_06046E48 (100B) - Final function in binary\r\n\! CONFIDENCE: MEDIUM -- Address verified. Contains real code (sts.l pr,@-r15; mova).\r\n\! AUDIT NOTE: FIXED: Renamed from 'Binary end marker / padding' to 'Final function in binary'. Contains real instructions (sts.l pr,@-r15 at entry), not padding or CRC data.
\!   Final function in binary. Contains real executable code.
!
! =============================================================================
! KEY HARDWARE ADDRESSES
! =============================================================================
!
! System:
! CONFIDENCE: DEFINITE -- Standard SH-2/Saturn hardware addresses.
!   0xFFFFFF00 - SH-2 hardware divider unit
!   0x22000000 - Saturn backup RAM (save data)
!   0xFFFFFE10 - Interrupt control registers
!   0x26000000 - DMA control registers
!
! =============================================================================
! EXTRACTION PRIORITY
! =============================================================================
! - Menu system: LOW (CCE has own menus)
! - Save/load: LOW (different format)
! - Event queue: MEDIUM (could reuse event dispatch pattern)
! - Math library: HIGH (trig/division needed for physics)
! - System init: LOW (platform-specific)
! - Interrupt handlers: LOW (platform-specific)
