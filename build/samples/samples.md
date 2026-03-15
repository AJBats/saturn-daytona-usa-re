# Sample Captures Catalog

## tt_throttle_300f

- **Save state**: usa_tt_straight.mc0
- **Scenario**: straight_throttle (hold C, 300 frames)
- **Address**: 0x06078900 (car[0])
- **Size**: 616 bytes (full car struct)
- **Files**: tt_throttle_300f.bin, tt_throttle_300f.csv
- **Captured**: 2026-03-15

## tt_idle_300f

- **Save state**: usa_tt_straight.mc0
- **Scenario**: idle (no input, 300 frames)
- **Address**: 0x06078900 (car[0])
- **Size**: 616 bytes (full car struct)
- **Files**: tt_idle_300f.bin, tt_idle_300f.csv
- **Captured**: 2026-03-15

## tt_steer_left_throttle_300f

- **Save state**: usa_tt_straight.mc0
- **Scenario**: steer_left_throttle (hold C + LEFT, 300 frames)
- **Address**: 0x06078900 (car[0])
- **Size**: 616 bytes (full car struct)
- **Files**: tt_steer_left_throttle_300f.bin, tt_steer_left_throttle_300f.csv
- **Captured**: 2026-03-15

## tt_offtrack_throttle_566f

- **Save state**: usa_tt_offtrack_stop.mc0
- **Scenario**: offtrack_throttle (hold C, 566 frames, road→grass)
- **Address**: 0x06078900 (car[0])
- **Size**: 616 bytes (full car struct)
- **Files**: tt_offtrack_throttle_566f.bin, tt_offtrack_throttle_566f.csv
- **Captured**: 2026-03-15

## tt_rolling_steer_left_300f

- **Save state**: usa_tt_straight.mc0
- **Scenario**: rolling_steer_left (C held 200 frames to ~65 mph, then C+LEFT 300 frames)
- **Address**: 0x06078900 (car[0])
- **Size**: 616 bytes (full car struct)
- **Files**: tt_rolling_steer_left_300f.bin, tt_rolling_steer_left_300f.csv
- **Captured**: 2026-03-15
- **Notes**: Steering capture starts at ~65 mph. Heading visibly changes with LEFT.

## tt_brake_300f

- **Save state**: usa_tt_straight.mc0
- **Scenario**: throttle_then_brake (C held 750 frames to ~27 mph, then B held 300 frames)
- **Address**: 0x06078900 (car[0])
- **Size**: 616 bytes (full car struct)
- **Files**: tt_brake_300f.bin, tt_brake_300f.csv
- **Captured**: 2026-03-15
- **Notes**: Brake capture starts at ~27 mph. Car stops by ~frame 100.

## tt_right_wall_strike_662f

- **Save state**: usa_tt_straight.mc0
- **Scenario**: right_wall_strike (hold C + RIGHT, 662 frames)
- **Address**: 0x06078900 (car[0])
- **Size**: 616 bytes (full car struct)
- **Files**: tt_right_wall_strike_662f.bin, tt_right_wall_strike_662f.csv
- **Captured**: 2026-03-15
