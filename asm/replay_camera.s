! =============================================================================
! Replay Camera & Cinematic Camera System
! =============================================================================
!
! This file documents the replay/cinematic camera system — camera modes
! used during replay viewing, attract mode, and pre-race flybys.
!
! Address range: 0x0601DBB8-0x0601E810 (replay camera core)
!                0x0601EFC4-0x0601FFB8 (rendering output / display)

! =============================================================================
! REPLAY CAMERA CONTROLLER (0x0601DBB8)
! =============================================================================

! FUN_0601DBB8 — Replay camera controller (472 bytes, 236 insns)
!   Heavy-weight function: saves r8-r14 + macl (9 registers).
!   20-byte stack frame for local variables.
!
!   Key state addresses:
!     0x06078900 — Camera data block
!     0x0608706C — Camera position (target)
!     0x06087074 — Camera state
!     0x06087068 — Camera mode byte
!     0x06087070 — Camera parameter
!     0x060786AC — Camera enable flag
!     0x0608706A — Timer/countdown (word, decremented each frame)
!     0x0608707C — Camera sub-state (byte)
!
!   Enable check:
!     Reads 0x060786AC — if non-zero, camera disabled, jumps to FUN_0601DDF6.
!
!   Controller input:
!     Reads 0x0607EBF4 (button state), checks bit 0x01 for camera change.
!     Reads 0x0607EABC for additional input state.
!     Checks byte at [0x06078900+3] bit 0x08 for secondary trigger.
!
!   Camera state machine:
!     State byte at 0x06087068, incremented by 48 per step.
!     Threshold check: if state >= threshold, wraps to 0.
!
!   Camera positions:
!     Position table at 0x060639F8 with 0x9000 offset for track data.
!     Position data at 0x060639E0 (secondary position table).
!     Track position at 0x0605DDB4 / 0x0605DDD4 (course-dependent).
!
!   Course-dependent behavior:
!     Checks 0x0607EAD8 — if course == 2, changes camera count from 3 to 6.
!     Uses extended position table at 0x0605DDD4 for course 2.
!
!   Per-frame operations:
!     1. Check if replay enabled
!     2. Read controller input for camera switch
!     3. Select camera position from table
!     4. Call FUN_060350B0 (modular function for position selection)
!     5. Call FUN_06028400 (copy 8 bytes — camera parameters)
!     6. Call FUN_0601E26C (interpolate camera position)
!     7. Copy position data to multiple destinations
!     8. Decrement timer at 0x0608706A
!     9. If timer reaches 0, clear mode byte and exit
!
!   Exits by:
!     - Timer expiry: clears state, jumps to FUN_0601DDF6
!     - Disable: immediate exit via register restore

! FUN_0601DDF6 — Camera cleanup/reset (46 bytes, 23 insns)
!   Called when replay camera is disabled or finishes.
!   Resets camera state and restores normal camera mode.
!   State stored at 0x0605ACE3.


! =============================================================================
! 3D GEOMETRY ENGINE (0x0601C3E4-0x0601D12C)
! =============================================================================
!
! These functions handle 3D transforms for the camera system and
! scene rendering.

! FUN_0601C3E4 — Master control dispatcher (1014 bytes, 507 insns)
!   Largest function in this group. Hardware integration — coordinates
!   between game logic and rendering hardware.
!   Dispatches to different rendering paths based on game state.

! FUN_0601C978 — Render pipeline stage 1 (264 bytes, 132 insns)
!   Initial rendering setup — configures viewport and clipping planes.

! FUN_0601CAEE — Render processing stage (612 bytes, 306 insns)
!   Jump target for long init chains from pre_race_states.
!   Processes rendering commands accumulated during frame setup.

! FUN_0601CDC0 — Render stage 3 (250 bytes, 125 insns)
! FUN_0601CEFC — Render stage 4 (250 bytes, 125 insns)
!   Sequential render pipeline stages.

! FUN_0601D12C — Pure matrix/vector math (382 bytes, 191 insns, LEAF)
!   Key reusable math function — performs matrix-vector multiplication.
!   No function calls (LEAF), purely computational.
!   Used extensively by camera, scene, and transform systems.


! =============================================================================
! CAMERA POSITION INTERPOLATION
! =============================================================================

! FUN_0601E26C — Position interpolation (58 bytes, 29 insns)
!   Interpolates camera position between keyframes.
!   Called from replay camera (FUN_0601DBB8) and scene rendering.
!   Uses linear interpolation with frame-rate compensation.

! FUN_0601E2B4 — HUD overlay renderer (158 bytes, 79 insns)
!   Renders camera-related HUD overlays (replay indicator, etc.)


! =============================================================================
! LARGE VERTEX TRANSFORM FUNCTIONS (LEAF)
! =============================================================================
!
! These are the biggest LEAF (no function calls) functions — pure math
! engines for batch vertex transformation.

! FUN_0601EFC4 — Batch vertex transform (930 bytes, 465 insns, LEAF)
!   *** LARGEST LEAF FUNCTION IN BINARY ***
!   Transforms entire vertex batches through the full pipeline:
!   model -> world -> view -> clip -> screen space.
!   All fixed-point arithmetic, no function calls.
!   Unrolled loop for maximum throughput on SH-2.

! FUN_0601EBDA — Pure geometry computation (854 bytes, 427 insns, LEAF)
!   *** SECOND LARGEST LEAF ***
!   Similar to FUN_0601EFC4 but for different geometry types.
!   Handles polygon vs sprite vertex formats.


! =============================================================================
! RENDERING OUTPUT (0x0601F40C-0x0601FFB8)
! =============================================================================
!
! Final output stage — submits rendered frame to hardware.

! FUN_0601F9CC — Large output handler (650 bytes, 325 insns)
!   Final rendering output — writes completed frame data to VDP1.
!   Manages double-buffer swap timing.

! FUN_0601F5E0 — Render utility final pass (348 bytes, 174 insns)
!   Post-processing pass before output.

! FUN_0601F4B4 — Display processor (272 bytes, 136 insns, LEAF)
!   Pure computation for display formatting.

! FUN_0601F784 — Output finalizer (202 bytes, 101 insns)
! FUN_0601FEC0 — Final output (202 bytes, 101 insns)
!   Write final frame to display hardware.

! FUN_0601F40C — Output handler (88 bytes, 44 insns)
! FUN_0601F936 — Output handler B (120 bytes, 60 insns)
! FUN_0601FE20 — Display handler (118 bytes, 59 insns)
! FUN_0601F8C0 — Output control (52 bytes, 26 insns)
!   Referenced from pre_race_states.s as resource check.
! FUN_0601F900 — Output dispatch (54 bytes, 27 insns)
! FUN_0601FD20 — Display control A (40 bytes, 20 insns)
! FUN_0601FD74 — Display control B (40 bytes, 20 insns)


! =============================================================================
! REPLAY CAMERA HIERARCHY
! =============================================================================
!
! Replay Camera Flow:
!
!   FUN_0601DBB8 (replay camera controller)
!     |
!     +-> FUN_060350B0 (position selection / random)
!     +-> FUN_06028400 (memcpy 8 bytes, camera params)
!     +-> FUN_0601E26C (position interpolation)
!     +-> FUN_0601DDF6 (cleanup on timer expiry)
!
! Camera integrates with:
!   - asm/scene_camera.s: Normal gameplay camera (FUN_0600BB94, 7 modes)
!   - asm/pre_race_states.s: Pre-race camera setup
!   - asm/render_pipeline.s: Scene submission
!
! Position Data:
!   0x060639F8 — Primary camera position table
!   0x060639E0 — Secondary position table
!   0x0605DDB4 — Track camera positions (courses 0-1)
!   0x0605DDD4 — Track camera positions (course 2, extended)
!   0x0605DFF4 — Camera direction data
