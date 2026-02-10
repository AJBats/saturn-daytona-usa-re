! ================================================
! AUDIT: MEDIUM — Mixed file covering track data, HUD overlays, menus, and camera systems.
!   Function addresses verified in binary. Subsystem groupings are reasonable but some
!   function-level labels are speculative. Several overlap issues with hud_ui.s noted.
! Audited: 2026-02-10
! ================================================
!
! =============================================================================
! Track Geometry, HUD Overlays & Menu System (0x06014000-0x0601AFFF)
! =============================================================================
!
! 155 functions total, 86 previously unmapped
! Track data processing, HUD overlay rendering, menu state machines
!
! =============================================================================
! FUNCTION CATALOG BY SUBSYSTEM
! =============================================================================
!
! === Track Data Processing (0x06014000-0x060146FF) ===
!
! CONFIDENCE: MEDIUM — FUN_060140C8 verified in binary but "Track segment data decompressor"
!   label is questionable. Binary shows it iterates array at 0x0605AD4C and calls rendering
!   functions (FUN_06026DBC, FUN_06026E2E, etc.), which looks more like a rendering loop
!   than decompression. Track normal/elevation labels are reasonable for racing game geometry.
!
! AUDIT NOTE: FUN_060140C8 overlaps with hud_ui.s which covers FUN_060140C4 (parent
!   function, 2 bytes before). hud_ui.s calls it "Dynamic Object Physics" while this file
!   calls it "Track segment data decompressor" — neither label is well-supported. Binary
!   shows rendering function calls, not physics or decompression.
! FUN_060140C8 (164B) - Track segment data decompressor
!   Expands compressed track geometry from disc into runtime format
!
! FUN_06014468 (164B) - Track normal vector calculator
!   Computes surface normals for road segments (used by physics)
!
! FUN_060146D4 (152B) - Track elevation mapper
!   Converts track height data to world Y coordinates
!
! FUN_06014964 (48B)  - Track data bounds checker
!
! === HUD Overlay System (0x06015000-0x0601607F) ===
!
! CONFIDENCE: HIGH — FUN_0601503A verified: reads display config from 0x06085FF4
!   (byte flag check confirmed in binary). FUN_06015150 at 488 bytes calls display
!   element functions in 0x06032-33 range (cross-referenced with display_elements.s).
!   HUD layout/rendering labels well-supported by call chain to VDP display system.
! FUN_0601503A (278B) - HUD layout manager
!   Positions HUD elements based on screen mode (normal/split)
!   Reads display config from 0x06085F8A
!
! FUN_06015150 (488B) - HUD element renderer
!   Large function: renders speed, position, lap, timer
!   Calls display element functions in 0x06032-33 range
!
! FUN_06015482 (138B) - HUD animation controller
!   Manages blinking, fading, sliding HUD transitions
!
! FUN_0601550C (152B) - HUD priority sorter
! FUN_060155A4 (258B) - Minimap renderer
!   Draws track outline and car positions on minimap
!
! FUN_060156A6 (6B)   - NOP stub (rts;nop;pad)
! FUN_060156AC (160B) - Minimap car dot renderer
! FUN_0601574C (8B)   - Minimap stub
! FUN_06015754 (394B) - Full minimap update
!   Updates all car positions on minimap each frame
!
! === Lap/Position Display (0x060158DE-0x06015E78) ===
!
! CONFIDENCE: HIGH — Lap counter, position display with ordinal suffix (st/nd/rd/th),
!   time comparison, and speed formatting are all standard racing game HUD elements.
!   Function sizes and parameter counts are consistent with described behaviors.
! FUN_060158DE (118B) - Lap counter display updater
! FUN_06015954 (336B) - Position change animator
!   "1st -> 2nd" animation with scale/rotation effect
!
! FUN_06015AA4 (164B) - Best lap time display
! FUN_06015B48 (278B) - Time comparison display (vs best, vs record)
! FUN_06015C5E (78B)  - Time delta formatter (+/- seconds)
! FUN_06015CAC (132B) - Time digit updater
! FUN_06015D30 (100B) - Position suffix renderer (st/nd/rd/th)
! FUN_06015D94 (146B) - Lap progress bar
! FUN_06015E26 (82B)  - Speed unit display (KM/H, MPH)
! FUN_06015E78 (64B)  - Speed value formatter
!
! === Results Screen (0x06015FB0-0x060167DC) ===
!
! CONFIDENCE: HIGH — FUN_06015FC2 at 614 bytes verified. Results screen with final
!   positions, times, and bonuses is a standard racing game feature. "Start to continue"
!   input handler plausible from button state check pattern.
! FUN_06015FB0 (18B)  - Results init stub
! FUN_06015FC2 (614B) - Full results screen renderer
!   Displays final positions, times, bonuses for all cars
!
! FUN_06016228 (8B)   - Results stub
! FUN_06016230 (104B) - Results scroll animator
! FUN_06016298 (20B)  - Results element placer
! FUN_060162AC (356B) - Results time column renderer
! FUN_06016410 (88B)  - Results bonus calculator display
! FUN_06016468 (8B)   - Results stub
! FUN_06016470 (94B)  - Results car name display
! FUN_060164CE (354B) - Results ranking table renderer
! FUN_06016630 (4B)   - NOP stub
! FUN_06016634 (70B)  - Results transition
! FUN_0601667A (214B) - Results page 2 (best laps)
! FUN_06016750 (120B) - Results awards display
! FUN_060167C8 (20B)  - Results cleanup stub
! FUN_060167DC (356B) - Results input handler (Start to continue)
!
! === Number/Text Rendering Utilities (0x06016940-0x06016CE6) ===
!
! CONFIDENCE: HIGH — FUN_06016A60 at 522 bytes verified: extu.b for character extraction,
!   shll2+shll2 (multiply by 16) for font table indexing. Variable-width text rendering
!   is a well-known pattern. BCD-to-sprite conversion also confirmed.
! FUN_06016940 (16B)  - Text stub
! FUN_06016950 (200B) - BCD number to sprite mapper
!   Converts integer to digit sprites for display
!
! FUN_06016A18 (4B)   - NOP stub
! FUN_06016A1C (68B)  - Small number renderer (2-digit)
! FUN_06016A60 (522B) - Full text string renderer
!   Renders character strings using font sprite table
!   Supports variable-width characters
!
! FUN_06016C6A (114B) - Text color setter
! FUN_06016CE6 (242B) - Text scroll/marquee animator
!
! === Polygon Table Utilities (0x060170FC-0x06017740) ===
!
! CONFIDENCE: SPECULATIVE — "Polygon table" functions are small (22-68 bytes) with
!   generic table lookup patterns. Could be any indexed data structure, not necessarily
!   polygon-specific.
! FUN_060170FC (26B) - Polygon table entry reader
! FUN_06017116 (22B) - Polygon table index validator
! FUN_06017740 (68B) - Polygon table lookup
!
! === Course Background Loaders (0x06018700-0x06018938) ===
!
! CONFIDENCE: HIGH — Three parallel functions (252-260 bytes each) with identical structure
!   but different data offsets, matching Daytona 3-course architecture (Three Seven,
!   Dinosaur Canyon, Seaside Street). Course-specific background loading well-supported.
! FUN_06018738 (252B) - Course 0 (Three Seven) background loader
!   Already partially documented in track_geometry.s
! FUN_06018834 (260B) - Course 1 (Dinosaur Canyon) background loader
! FUN_06018938 (260B) - Course 2 (Seaside Street) background loader
!   All three follow identical structure with course-specific data offsets
!
! === Game Mode Transition Helpers (0x06018E00-0x060192FF) ===
!
! CONFIDENCE: MEDIUM — State flag setters and transition helpers are generic patterns.
!   "Save/restore state snapshot" labels are plausible (capture+restore pattern) but
!   specific game mode context (pause/time-extension) is inferred.
! FUN_06018E22 (42B)  - Mode flag setter A
! FUN_06018E4C (36B)  - Mode flag setter B
! FUN_06018E88 (36B)  - Mode flag setter C
!   These set various game state flags during transitions
!
! FUN_06018FA8 (80B)  - Save state snapshot
!   Captures current game state for resume after pause/time-ext
!
! FUN_06018FFC (92B)  - Restore state snapshot
! FUN_0601905C (92B)  - State snapshot comparator
! FUN_060190BC (56B)  - Transition timer setter
! FUN_060190F8 (84B)  - Transition animation driver
! FUN_06019150 (56B)  - Transition fade controller
! FUN_0601918C (84B)  - Transition sound trigger
! FUN_060191E4 (100B) - Multi-step transition orchestrator
! FUN_0601924C (128B) - Full mode transition executor
!
! === Menu State Machines (0x060193FE-0x060197F4) ===
!
! CONFIDENCE: HIGH — FUN_060193FE verified: reads from 0x06085FF0 (config byte),
!   0x0605D245, and 0x06085FF1 at entry. D-pad navigation among 3 choices matches
!   Daytona 3-course selection. Car select with 3D preview rotation also confirmed
!   by call to rendering functions.
!
! AUDIT NOTE: Annotation says "extended version of FUN_060193F4 (already documented)"
!   but FUN_060193F4 is not referenced in the binary — the actual label is FUN_060193FE.
!   The 4-byte discrepancy suggests a Ghidra boundary artifact or stale reference.
! FUN_060193FE (270B) - Course select state machine
!   Full course selection logic:
!   - D-pad navigation between 3 courses
!   - Preview animation triggers
!   - Confirm/cancel handling
!   NOTE: This is the extended version of FUN_060193F4 (already documented)
!
! FUN_060196B0 (324B) - Course select renderer
!   Draws course selection UI elements each frame
!
! FUN_060197F4 (236B) - Car select state machine
!   Car type selection (Hornet, Grasshopper, etc.)
!   D-pad navigation, 3D car preview rotation
!
! === Transmission Select & Pre-Race (0x06019D14-0x0601A578) ===
!
! CONFIDENCE: HIGH — FUN_0601A1BA reads from 0x06063D9A (button state, confirmed)
!   and has mask+compare pattern consistent with button-triggered sequence. Starting
!   light sequence is a universal racing game feature. Green light -> GO! animation
!   label strongly plausible.
! FUN_06019D14 (164B) - Transmission select (AT/MT)
! FUN_06019EF0 (194B) - Pre-race camera sequence
! FUN_0601A0F0 (202B) - Grid position camera
! FUN_0601A1BA (258B) - Starting light sequence controller
! FUN_0601A2BC (136B) - Starting light renderer
! FUN_0601A344 (4B)   - NOP stub
! FUN_0601A348 (172B) - Green light -> GO! animation
! FUN_0601A574 (4B)   - NOP stub
! FUN_0601A578 (230B) - Race start transition (camera sweep to cockpit)
!
! === Track Preview/Replay Camera (0x0601A770-0x0601AFD8) ===
!
! CONFIDENCE: MEDIUM — FUN_0601AC88 at 504 bytes verified. Camera systems with smooth
!   transitions and auto-cut timers are consistent with replay camera. "Spline path
!   follower" for FUN_0601AAE8 is plausible but specific spline math not verified.
!   Replay camera interpretation reasonable for a racing game with replay feature.
! FUN_0601A770 (60B)  - Preview camera position
! FUN_0601A7AC (96B)  - Preview camera target
! FUN_0601AAE8 (224B) - Preview camera path follower
!   Follows spline path for course preview fly-through
!
! FUN_0601ABC8 (180B) - Replay camera position selector
! FUN_0601AC88 (504B) - Replay camera main loop
!   Selects camera angle, tracks target car, smooth transitions
!
! FUN_0601AF1E (110B) - Replay camera auto-cut timer
! FUN_0601AF8C (24B)  - Replay stub
! FUN_0601AFA4 (52B)  - Replay camera interpolation
! FUN_0601AFD8 (6B)   - Replay end stub
! FUN_0601AFDE (66B)  - Replay camera cleanup
!
! =============================================================================
! EXTRACTION PRIORITY
! =============================================================================
! - Track data processing (0x06014xxx): HIGH (needed for physics integration)
! - Menu state machines: LOW (CCE has own menus)
! - HUD rendering: LOW (CCE has own HUD)
! - Results screen: LOW (CCE has own)
! - Pre-race sequence: MEDIUM (may reuse camera logic)
! - Replay camera: MEDIUM (replay system could be ported)
