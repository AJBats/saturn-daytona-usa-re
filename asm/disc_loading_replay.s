! ================================================
! AUDIT: HIGH -- Most function addresses verified in binary; disc loading and replay sections have strong structural evidence; sound and resource descriptions are more speculative
! Audited: 2026-02-10
! ================================================
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
! CONFIDENCE: MEDIUM -- Address verified but description is WRONG.
! AUDIT NOTE: NOT a 4-byte NOP stub. Binary shows mov.l r14,@-r15; mov #0,r7 at this address -- a register push + initialization, indicating a real function, not a NOP.
! FUN_0601B024 (80B)  - Disc sector read initiator
! CONFIDENCE: MEDIUM -- Address verified. Starts with sts.l pr,@-r15; mov #48,r14. References 0x06086014. CD block register claims need hardware address verification.
!   Sets up CD block registers for sector read
!   Writes to CD block command port
!
! FUN_0601B170 (680B) - Main disc loading manager
! CONFIDENCE: HIGH -- Address verified. References 0x0606A4F4 (known data area). Large function with stack frame (add #-12). State machine description plausible for this size.
!   Complete CD-ROM file loading state machine:
!   - File lookup in directory table
!   - Sector calculation from FAD (Frame Address)
!   - DMA transfer setup
!   - Error handling and retry logic
!   - Progress callback for loading screen
!
! FUN_0601B48C (74B)  - Disc read completion check
! CONFIDENCE: MEDIUM -- Address verified. Small function with stack frame. Polling/return pattern plausible but status register claims unverified.
!   Polls CD block status register
!   Returns: 0=still loading, 1=complete, -1=error
!
! FUN_0601B4D6 (174B) - Disc error handler
! CONFIDENCE: MEDIUM -- Address verified. References 0x06063D9A. Retry logic claim is speculative.
!   Retries failed reads up to 3 times
!   Falls back to alternate loading path on persistent failure
!
! FUN_0601B584 (192B) - Course data file loader
! CONFIDENCE: MEDIUM -- Address verified. Saves r14+pr with stack frame. File name claims (COURSE0.BIN etc.) are speculative.
!   Loads course-specific files: COURSE0.BIN, CS0POLY.BIN, etc.
!   Manages loading order for streaming
!
! FUN_0601B644 (152B) - Texture file loader
! CONFIDENCE: MEDIUM -- Address verified. References 0x0605D4F4. "Texture" and "VRAM" claims are speculative.
!   Loads VDP1 texture data from disc to VRAM
!
! FUN_0601B6F0 (260B) - Animation data loader
! CONFIDENCE: SPECULATIVE -- Address verified. References 0x0608600E. "Animation" description is a guess.
!   Loads animation sequences for 3D objects
!
! === Replay Record/Playback (0x0601BBDC-0x0601BE64) ===
!
! FUN_0601BBDC (528B) - Replay recorder
! CONFIDENCE: MEDIUM -- Address verified. Stack frame (add #-36 = 36 bytes). Large local workspace consistent with recording. Specific field layout (steering/button/speed/XYZ) is speculative.
!   Records per-frame input state for replay:
!   - Steering angle (16-bit)
!   - Button state (16-bit)
!   - Speed (16-bit)
!   - Position X/Y/Z (3x32-bit)
!   Writes to replay buffer at ~0x060A0000
!   Circular buffer with lap markers
!
! FUN_0601BE64 (1408B) - Replay playback engine
! CONFIDENCE: MEDIUM -- Address verified. Large function with heavy callee-saved pushes (r14,r13,r12). Called from state handler area. "Ghost car" and "fast-forward" claims are speculative.
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
! CONFIDENCE: HIGH -- Address verified. SCSP address 0x25A00000 confirmed in binary (referenced at 0x06012EB4 and 0x060192FC). Sound command role is strongly supported.
!   Writes commands to SCSP (Saturn Custom Sound Processor)
!   via shared memory area at 0x25A00000
!
! FUN_0601D4A8 (212B) - Sound channel allocator
! CONFIDENCE: MEDIUM -- Address verified. Saves r14,r13,pr. "32 PCM channels" and "priority-based" claims are speculative.
!   Manages 32 PCM channels
!   Priority-based allocation for SFX vs music
!
! === 3D Geometry Utilities (0x0601E48C-0x0601E770) ===
!
! FUN_0601E48C (72B)  - Matrix identity setter
! CONFIDENCE: SPECULATIVE -- Address verified. Starts with sts.l pr,@-r15; add #-4. "Matrix identity" is a guess.
! FUN_0601E636 (110B) - Matrix multiply helper
! CONFIDENCE: SPECULATIVE -- Address verified. Saves r14,r13,pr. "Matrix multiply" and "4x4" claims unverified.
!   4x4 matrix multiply for combined transforms
!
! FUN_0601E6E0 (132B) - Matrix rotation from euler angles
! CONFIDENCE: SPECULATIVE -- Address verified. Saves r14,r13,pr. "Euler angles" and sin/cos table claims unverified. 0x06044000 would need to be confirmed as a trig table.
!   Converts heading/pitch/roll to rotation matrix
!   Uses sin/cos lookup table at 0x06044000
!
! FUN_0601E770 (160B) - Matrix transpose
! CONFIDENCE: SPECULATIVE -- Address verified. Starts with sts.l pr,@-r15; add #-8. "Matrix transpose" is a guess.
!   Needed for inverse view transform
!
! === Resource Management (0x0601F464-0x0601FFB8) ===
!
! FUN_0601F464 (80B)  - Memory pool allocator
! CONFIDENCE: SPECULATIVE -- Address verified. References 0x060877D8 and 0x0604A57C. "Bump allocator" is a guess.
!   Simple bump allocator for runtime memory
!
! FUN_0601F5D0 (16B)  - Memory pool reset
! CONFIDENCE: SPECULATIVE -- Address verified but NOT 16 bytes. Starts with sts.l pr,@-r15; bsr -- calls another function, so not a simple reset.
! AUDIT NOTE: Size claim of 16B is likely wrong -- function makes a bsr call to FUN_0601F87A, implying more complexity than a simple reset.
! FUN_0601F938 (148B) - Resource validation checker
! CONFIDENCE: SPECULATIVE -- "Checksum" and "validation" claims unverified.
!
! FUN_0601FD9C (132B) - VRAM allocation manager
! CONFIDENCE: MEDIUM -- Address verified. References 0x060877F8 and 0x0607EBC4. "VRAM allocation" plausible given address references but unconfirmed.
!   Manages VDP1/VDP2 VRAM allocation for textures
!
! FUN_0601FFA8 (16B)  - VRAM pointer getter
! CONFIDENCE: SPECULATIVE -- Address verified but size is WRONG.
! AUDIT NOTE: NOT 16 bytes. Binary shows mov.l r14,@-r15; mov.l r13,@-r15; mov.l r12,@-r15 -- pushing 3 callee-saved regs means this is a substantial function, not a 16-byte getter.
! FUN_0601FFB8 (236B) - VRAM defragmenter
! CONFIDENCE: SPECULATIVE -- Address verified. Saves pr+macl. "Defragmenter" is a guess.
!   Compacts VRAM when allocation becomes fragmented
!
! =============================================================================
! KEY HARDWARE ADDRESSES
! =============================================================================
!
! CD Block:
! CONFIDENCE: HIGH -- 0x25890008 confirmed in binary pool at 0x06035C78. Saturn CD block register base is well-documented.
!   0x25890000 - CD block registers (status, command, data)
!   0x25818000 - CD buffer area
!
! SCSP (Sound):
! CONFIDENCE: DEFINITE -- 0x25A00000 confirmed at two locations in binary (0x06012EB4, 0x060192FC). Standard Saturn SCSP address.
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
