# Corrections Log — Crossword Annotation Pass

Errors discovered while adding real SH-2 assembly to comment-only `.s` files.
Each correction was found by decoding the binary and comparing to existing descriptions.

## Batch 1 (5 files)

### hud_ui.s (File 1 — prior session)
- **Section 12 "AI OPPONENT LOGIC"** → DISPLAY CHANNEL MANAGEMENT
  - Functions FUN_06014868/FUN_06014884 manage scene data channels, not AI opponents

### menu_display.s (File 2)
- **"Game Logic Integration" section** → SCENE DATA CHANNEL SYSTEM
  - 6-channel command queue (IDs: 1, 2, 4, 8, 16, 32) at sym_060635A8
- **FUN_06038642 "State machine"** → scene data write additive (adds to scene struct fields)
- **FUN_06038794 "Game state update"** → scene color/intensity processor (clamps fp16.16 color values)
- **sym_06034F78 "bus lock"** → bitfield read-modify-write utility (see lap_counting.s, DEFINITE)

### render_pipeline.s (File 3)
- **FUN_0603DDFC "Master game state machine"** → scene color matrix initializer (3x3 identity at sym_060A53B8)
- **"LARGEST FUNCTION IN THE BINARY"** → INCORRECT. FUN_0603DDFC is 596B; FUN_0602382C is 5352B

### pre_race_states.s (File 4)
- **FUN_06014884 "memory setup (region 4)"** → display channel update B
  - Full signature: FUN_06014884(4, 0xFFFF0000, 0) = channel 4 (transform primary) = offscreen init
  - Previous description omitted r5 and r6 arguments entirely
- **FUN_060149E0 "secondary init"** → display disable (clears bit 15 of 0x060A3D88)
- **State 2 "Stub/Transition States"** → full attract mode initialization (140 bytes)
  - Initializes timer to 920 frames, sets 6 globals, calls 4 subsystem inits
- **State 3 "Countdown/Timer Manager" / "press any button"** → ATTRACT DEMO ACTIVE LOOP
  - Button mask 0x0800 = Start button only (not "any button")
  - No-button path runs FULL GAMEPLAY LOOP (camera, collision, rendering, frame commit)
  - This is why attract mode shows live car movement
- **State number mismatches (NOT FIXED — needs user review)**:
  - File "STATE 12" (0x06008C14) = actually State 30 per jump table
  - File "STATE 13" (0x06008E00) = actually State 12 per jump table
  - File "STATE 30" (0x06008C76) = actually State 31 per jump table

### scene_camera.s (File 5)
- **FUN_0600BF70 "Call FUN_06027344 (cos_lookup)" and "Call FUN_06027552 (fpmul)"** → NO FUNCTION CALLS
  - This is a LEAF function using only mul.l and arithmetic shifts
  - Actual math: (heading * 900) >> 10, exponential smoothing with weights 800/224 (not 0.9/0.1)
- **FUN_0600BFFC "HUD/Racing State Initialization"** → PRIMARY SCENE RENDERING ORCHESTRATOR
  - Writes FUN_0600C170 to sym_06063574 (the SECONDARY CALLBACK POINTER from ICF_FIX)
  - Writes 0xFFFF to 0x21000000 (VDP hardware register)
  - Calls FUN_0600B6A0 (CS0 object rendering)
  - Manages LOD config byte and render budget
  - Size was listed as 296B but is actually ~370B
- **FUN_0600C302 "Wheel State / Speed Limiter"** → wheel animation timer
  - Two counters at car[+0x172]/[+0x174] for front/rear wheel visual effects
  - Speed thresholds: 230 (high→front), 155-229 with gate 140 (medium→rear)
  - Size was listed as 136B but is actually 166B

### ui_event_extended.s (NOT EDITED — noted for future batch)
- **FUN_0603E050 "Sound test player (1388B)"** → color processing / scene channel dispatch
  - Binary shows it loads sym_0603C0A0 (color scale function), not sound test data
