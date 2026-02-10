! =============================================================================
! Disc Loading, Replay System & Sound Driver (0x0601B000-0x0601FFFF)
! =============================================================================
!
! 87 functions total, 22 previously unmapped
! CD-ROM loading, replay record/playback, sound command interface
!
! =============================================================================
! FUNCTION CATALOG (UNMAPPED ONLY)
! =============================================================================
!
! === Disc Loading System (0x0601B000-0x0601B6F0) ===
!
! FUN_0601B020 (4B)   - NOP stub (disc ready check passthrough)
! FUN_0601B024 (80B)  - Disc sector read initiator
!   Sets up CD block registers for sector read
!   Writes to CD block command port
!
! FUN_0601B170 (680B) - Main disc loading manager
!   Complete CD-ROM file loading state machine:
!   - File lookup in directory table
!   - Sector calculation from FAD (Frame Address)
!   - DMA transfer setup
!   - Error handling and retry logic
!   - Progress callback for loading screen
!
! FUN_0601B48C (74B)  - Disc read completion check
!   Polls CD block status register
!   Returns: 0=still loading, 1=complete, -1=error
!
! FUN_0601B4D6 (174B) - Disc error handler
!   Retries failed reads up to 3 times
!   Falls back to alternate loading path on persistent failure
!
! FUN_0601B584 (192B) - Course data file loader
!   Loads course-specific files: COURSE0.BIN, CS0POLY.BIN, etc.
!   Manages loading order for streaming
!
! FUN_0601B644 (152B) - Texture file loader
!   Loads VDP1 texture data from disc to VRAM
!
! FUN_0601B6F0 (260B) - Animation data loader
!   Loads animation sequences for 3D objects
!
! === Replay Record/Playback (0x0601BBDC-0x0601BE64) ===
!
! FUN_0601BBDC (528B) - Replay recorder
!   Records per-frame input state for replay:
!   - Steering angle (16-bit)
!   - Button state (16-bit)
!   - Speed (16-bit)
!   - Position X/Y/Z (3x32-bit)
!   Writes to replay buffer at ~0x060A0000
!   Circular buffer with lap markers
!
! FUN_0601BE64 (1408B) - Replay playback engine
!   *** LARGEST IN THIS RANGE ***
!   Full replay playback system:
!   - Reads recorded input data
!   - Drives car physics from recorded input
!   - Camera system for multiple replay angles
!   - Fast-forward/rewind support
!   - Per-lap playback with smooth transitions
!   - Ghost car rendering (semi-transparent)
!
! === Sound Command Interface (0x0601D478-0x0601D4A8) ===
!
! FUN_0601D478 (48B)  - Sound command queue writer
!   Writes commands to SCSP (Saturn Custom Sound Processor)
!   via shared memory area at 0x25A00000
!
! FUN_0601D4A8 (212B) - Sound channel allocator
!   Manages 32 PCM channels
!   Priority-based allocation for SFX vs music
!
! === 3D Geometry Utilities (0x0601E48C-0x0601E770) ===
!
! FUN_0601E48C (72B)  - Matrix identity setter
! FUN_0601E636 (110B) - Matrix multiply helper
!   4x4 matrix multiply for combined transforms
!
! FUN_0601E6E0 (132B) - Matrix rotation from euler angles
!   Converts heading/pitch/roll to rotation matrix
!   Uses sin/cos lookup table at 0x06044000
!
! FUN_0601E770 (160B) - Matrix transpose
!   Needed for inverse view transform
!
! === Resource Management (0x0601F464-0x0601FFB8) ===
!
! FUN_0601F464 (80B)  - Memory pool allocator
!   Simple bump allocator for runtime memory
!
! FUN_0601F5D0 (16B)  - Memory pool reset
! FUN_0601F938 (148B) - Resource validation checker
!   Verifies loaded data integrity (checksums)
!
! FUN_0601FD9C (132B) - VRAM allocation manager
!   Manages VDP1/VDP2 VRAM allocation for textures
!
! FUN_0601FFA8 (16B)  - VRAM pointer getter
! FUN_0601FFB8 (236B) - VRAM defragmenter
!   Compacts VRAM when allocation becomes fragmented
!
! =============================================================================
! KEY HARDWARE ADDRESSES
! =============================================================================
!
! CD Block:
!   0x25890000 - CD block registers (status, command, data)
!   0x25818000 - CD buffer area
!
! SCSP (Sound):
!   0x25A00000 - SCSP shared RAM (sound commands)
!   0x25B00000 - SCSP registers
!
! =============================================================================
! EXTRACTION PRIORITY
! =============================================================================
! - Disc loading: LOW (CCE uses different media format)
! - Replay system: MEDIUM (useful for CCE replay feature)
! - Sound interface: LOW (CCE uses different sound hardware)
! - 3D geometry: HIGH (reusable math code)
! - Resource management: LOW (platform-specific)
