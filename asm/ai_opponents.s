! =============================================================================
! AI Opponent System (High-Address Functions)
! =============================================================================
!
! This file documents the AI opponent control system in the 0x06034xxx-
! 0x06035xxx range. These functions control the computer-driven cars.
!
! NOTE: This supplements asm/ai_behavior.s which covers the mid-range
! AI functions. These high-address functions are the core AI engine.
!
! Address range: 0x06034E58-0x060359E4

! =============================================================================
! AI MAIN LOOP (0x06035460)
! =============================================================================

! FUN_06035460 — AI main loop (662 bytes, 331 insns)
!   Main per-frame AI update for opponent vehicles.
!   Called once per AI car per frame.
!   Operations:
!     1. Read current track segment position
!     2. Query waypoint table for next target
!     3. Calculate steering angle to target
!     4. Apply speed management (accelerate/brake)
!     5. Handle overtaking / defensive driving
!     6. Apply randomized behavior variations
!
!   This is the "brain" of each opponent car.

! FUN_060359E4 — AI physics integration (462 bytes, 231 insns)
!   Applies AI control inputs to the vehicle physics model.
!   Converts AI decisions into actual steering/throttle/brake values.
!   Ensures AI cars obey the same physics as the player.


! =============================================================================
! AI PATHFINDING & NAVIGATION
! =============================================================================

! FUN_06034E58 — AI pathfinding (144 bytes, 72 insns)
!   Waypoint tracking and path planning.
!   Each course has a set of waypoints defining the racing line.
!   AI cars navigate between waypoints with some randomization
!   to avoid all cars following the exact same path.

! FUN_06034F78 — AI steering input generator (104 bytes, 52 insns)
!   Converts waypoint targets into steering commands.
!   Calculates angle between current heading and target direction.
!   Applies smoothing to avoid oscillation.
!   Referenced as "bitfield utility" in some contexts.

! FUN_06034FFC — AI state machine (170 bytes, 85 insns)
!   Controls high-level AI behavior:
!     Mode 0: Normal racing (follow racing line)
!     Mode 1: Chasing (catch up to player)
!     Mode 2: Defensive (block player's path)
!     Mode 3: Recovery (after collision or off-track)
!   State transitions based on position and player proximity.

! FUN_060350B0 — AI decision logic (174 bytes, 87 insns)
!   Evaluates game state for AI decisions.
!   Factors considered:
!     - Distance to player car
!     - Lap position (ahead/behind)
!     - Track segment type (straight/curve)
!     - Current speed vs optimal speed
!   Also called from replay camera (FUN_0601DBB8) for random selection.


! =============================================================================
! AI TARGET TRACKING
! =============================================================================

! FUN_06035844 — AI target tracking (160 bytes, 80 insns)
!   Tracks player vehicle position for AI behavior.
!   Calculates:
!     - Relative position (X/Y/Z distance)
!     - Relative velocity (closing/separating)
!     - Angle between AI heading and player direction
!   Used by chase/defensive modes.


! =============================================================================
! AI INITIALIZATION
! =============================================================================
!
! AI initialization is spread across several small functions.

! FUN_06035D5A — AI core initialization (150 bytes, 75 insns)
!   Sets up initial AI state for all opponent cars.
!   Called during race start.

! FUN_06035CBC — AI setup (86 bytes, 43 insns)
!   Per-car AI parameter initialization.
!   Sets difficulty-dependent parameters:
!     - Reaction time delay
!     - Speed limit (percentage of maximum)
!     - Cornering aggression
!     - Braking distance multiplier

! FUN_06035B34 — AI system init (140 bytes, 70 insns)
!   System-level AI initialization — sets up waypoint tables,
!   racing line data, and shared AI state.


! =============================================================================
! AI ARCHITECTURE
! =============================================================================
!
! AI Data Flow (per frame, per AI car):
!
!   FUN_06035460 (main AI loop)
!     |
!     +-> FUN_06034E58 (pathfinding — where to go)
!     |     +-> FUN_06034F78 (steering angle to target)
!     |
!     +-> FUN_06034FFC (state machine — behavior mode)
!     |     +-> FUN_060350B0 (decision logic)
!     |     +-> FUN_06035844 (target tracking)
!     |
!     +-> FUN_060359E4 (physics integration — apply inputs)
!
! Difficulty Scaling:
!   AI difficulty is controlled by per-car parameters set in
!   FUN_06035CBC. Higher difficulty = faster reaction, higher
!   speed limits, more aggressive cornering. The 3 courses
!   (Beginner/Advanced/Expert) have different difficulty profiles.
!
! Car Data:
!   AI cars use the same 4-car data structures as the player:
!     0x060620D8 (car 0 — player)
!     0x0606212C (car 1 — AI opponent 1)
!     0x06062180 (car 2 — AI opponent 2)
!     0x060621D8 (car 3 — AI opponent 3)
!   AI only controls cars 1-3; car 0 is always player-controlled.
