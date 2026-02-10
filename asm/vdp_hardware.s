! ================================================
! AUDIT: HIGH -- VDP/SCU hardware register access patterns documented with
!   real pool constant addresses verified against aprog.s. All function
!   addresses confirmed. VDP1 region labels CORRECTED (were swapped).
!   Function-level descriptions are accurate.
! Audited: 2026-02-10
! ================================================
!
! =============================================================================
! VDP1/VDP2 Hardware Interface Map
! =============================================================================
!
! This file documents ALL hardware register access patterns found in the
! Daytona USA Saturn binary. The Sega Saturn has two Video Display
! Processors (VDP1 for sprites/polygons, VDP2 for backgrounds/tilemaps)
! plus a DMA controller for bulk transfers.
!
! All hardware addresses are loaded via PC-relative pool constants:
!   mov.l @(offset,PC), rN    ; load address from pool
!   mov.l value, @rN          ; write to hardware register


! =============================================================================
! MEMORY MAP: Saturn Video Hardware
! =============================================================================
!
! AUDIT NOTE: FIXED — VDP1 region labels corrected to match Saturn hardware docs.
!   0x25C00000 = VDP1 VRAM, 0x25C80000 = Framebuffer, 0x25D00000 = I/O Registers.
!   Verified against aprog.s: FUN_0600A140 writes 0x80000000 to 0x25C00000 (VRAM
!   control), clears 0x25C80000 in loop (framebuffer clear), and FUN_06006F3C
!   writes TVMR/FBCR words to 0x25D00000/0x25D00002 (I/O registers).
!
! 0x25C00000  VDP1 VRAM (512KB)
!   - Command tables, character pattern data
!   - Gouraud shading tables
!   - FUN_0600A140 writes 0x80000000 here on init (VRAM enable/reset)
!
! 0x25C80000  VDP1 Framebuffer (512KB)
!   - Double-buffered: 512x224 pixels, 16-bit color
!   - Buffer 0: 0x25C80000 + 0
!   - Buffer 1: 0x25C80000 + 229376 (0x38000)
!   - FUN_0600A140 clears 64K words here (framebuffer init)
!
! 0x25D00000  VDP1 I/O Registers
!   - +0x00: TVMR (TV mode register)
!   - +0x02: FBCR (framebuffer change register)
!   - +0x04: PTMR (plot trigger mode register)
!   - FUN_06006F3C writes TVMR at +0 and FBCR at +2
!
! 0x25E00000  VDP2 VRAM (512KB)
!   - Tilemap/scroll plane data
!   - Character patterns for backgrounds
!   - Layout:
!     0x25E00000-0x25E3FFFF: Tilemap A (256KB)
!     0x25E40000-0x25E4FFFF: Character pattern 1 (64KB)
!     0x25E60000-0x25E6FFFF: Character pattern 2 (64KB)
!     0x25E70000-0x25E7FFFF: Character pattern 3 (64KB)
!   - ~400KB documented VRAM usage for backgrounds
!
! 0x25F00000  VDP2 Color RAM (4KB)
!   - 512 palette entries, 16-bit each
!   - Multiple 16KB banks with shadow register control
!   - Bank select at 0x060635DE
!
! 0x25F80000  VDP2 Control Registers
!   - +0x00: TVMD (screen mode / resolution)
!   - +0x04: EXTEN (extended display enable)
!   - +0x08: RAMCTL (VRAM access control)
!   - +0x0C: DMMODE (DMA mode settings)
!
! 0x25FE0000  SCU DMA Controller
!   - +0x00: DMAD (destination address)
!   - +0x04: DMAS (source address)
!   - +0x08: DMLEN (transfer length)
!   - +0x0C: DMMODE (mode/flags)
!   - +0x10: DMCTL (control)
!   - +0x14: DMSTAT (status/trigger)
!   - +0x7C: Status (busy mask 0x0000272E)
!
! 0xFFFFFF00  SH-2 Hardware Division Unit
!   - +0x00: DVSR (divisor)
!   - +0x04: DVDNT (dividend, triggers 32/32 divide)
!   - +0x10: DVDNTH (dividend high for 64/32 divide)
!   - +0x14: DVDNTL (dividend low, triggers 64/32 divide)
!   - +0x1C: Quotient result


! =============================================================================
! VDP1 VRAM (0x25C00000) & FRAMEBUFFER (0x25C80000) — Initialization
! AUDIT NOTE: FIXED — Section title corrected. 0x25C00000 is VDP1 VRAM (not
!   framebuffer). 0x25C80000 is VDP1 framebuffer. Verified against aprog.s
!   pool constants at [0x0600A1A0]=0x25C00000 and [0x0600A1A4]=0x25C80000.
! =============================================================================
!
! Functions:
!   FUN_0600A140 — Initial VDP1 VRAM + framebuffer configuration
!   FUN_06014A04 — Per-frame buffer address update (VBlank synced)
!   FUN_06014A74 — Buffer flip/swap command
!
! CONFIDENCE: DEFINITE — pool constants verified: 0x80000000 at
!   [0x0600A19C], 0x25C00000 at [0x0600A1A0], 0x25C80000 at [0x0600A1A4]
! FUN_0600A140 performs full VDP1 initialization:
!   - Writes 0x80000000 to 0x25C00000 (VDP1 VRAM enable/reset)
!   - Clears framebuffer at 0x25C80000 (64K words)
! AUDIT NOTE: FIXED — Corrected "Clears VDP1 VRAM at 0x25C80000" to
!   "Clears VDP1 framebuffer at 0x25C80000". 0x25C80000 is the framebuffer.
!   - Sets up command buffer state at 0x0605A00C
!   - Calls texture/palette init (FUN_06026CE0)
!   - Sets rendering flag at 0x06059F44
!
! Double-buffering:
!   FUN_06014A04 updates the buffer address register each frame,
!   synchronized to the VBlank interrupt. FUN_06014A74 triggers
!   the buffer swap so the newly-rendered frame becomes visible.
!
! All writes are fire-and-forget (no read-back polling).


! =============================================================================
! VDP1 I/O REGISTERS (0x25D00000) — Display Control
! AUDIT NOTE: FIXED — Section title corrected. 0x25D00000 is VDP1 I/O register
!   space, NOT VRAM. VDP1 VRAM is at 0x25C00000. Verified against aprog.s:
!   FUN_06006F3C loads 0x25D00000 from pool at [0x06007014] and 0x25D00002
!   from pool at [0x06007008], then writes word values (TVMR and FBCR registers).
! =============================================================================
!
! Functions:
! CONFIDENCE: HIGH — function addresses verified in aprog.s
!   FUN_0603931C — Polygon type and parameter setup
!   FUN_06006F3C, FUN_06038F78, FUN_06039050 — VBlank / display list commands
!
! FUN_06006F3C VBlank handler writes:
!   - 0x25D00000 (+0): TVMR — TV mode register (word write)
!   - 0x25D00002 (+2): FBCR — framebuffer change register (word write)
!
! CONFIDENCE: MEDIUM — standard VDP1 command structure, but VDP1 commands
!   on Saturn are actually 32 bytes each (frame_timing.s correctly uses 32).
!   The 16-byte format here may describe a subset or custom format.
! VDP1 command queue format (16 bytes per command):
!   +0x00: Command type (polygon mode 0-7)
!   +0x04: First vertex / command parameter
!   +0x08: Second parameter
!   +0x0C: Size / scale
!
! Polygon type encoding (bits 0-2 of command word):
!   0: Sprite / Billboard (2D textured quad)
!   1: Gouraud-shaded polygon
!   2: Texture-mapped polygon
!   3: Gouraud + texture combined
!   4: Wireframe (debug mode)
!   5: Half-transparent polygon
!   6-7: Reserved
!
! Scale control (param_3):
!   0: 1x scale (normal)
!   1: 2x scale (effects)
!   3: 8x scale (UI elements)
!
! Command parameter source:
!   psVar2 = (short *)(0x060635E0 + (param_2 << 2))
!   Commands read from a pre-built display list in work RAM.
!
! VDP1 processes the command queue asynchronously — functions return
! immediately after writing commands. No status polling needed.


! =============================================================================
! VDP2 VRAM (0x25E00000) — Tilemap & Background Data
! =============================================================================
!
! Primary initialization function:
! CONFIDENCE: DEFINITE — pool constants verified: r10=0x25E20000,
!   r12=0x0602761E, r13=0x06027630, DMA source 0x00031498 to dest 0x25E4363C
!   confirmed, course offset 0x002A0000 at [0x06003654]
!   FUN_06003578 — Mega-initialization (460 bytes, 230 instructions)
!     1. Loads DMA helper function pointers (0x06027630, 0x0602761E)
!     2. Clears VRAM: 8 iterations zeroing at 0x25E20000
!     3. Executes 40+ sequential DMA transfers
!
! DMA transfer examples from initialization:
!   Source 0x00031498 → Dest 0x25E4363C (31.5KB)
!   Source 0x00037640 → Dest 0x25E497E4 (29.8KB)
!   Source 0x0003CE44 → Dest 0x25E4EFEC (32.9KB)
!   Source 0x00044ED8 → Dest 0x25E40000 (1.95KB)
!   ... (36+ more transfers)
!
! Total initialization: ~400KB transferred from ROM to VDP2 VRAM.
! ALL 3 courses' background tilemaps loaded in a single init call.
!
! Multi-course support:
!   address = 0x25E4xxxx + (course_index * 0x002A0000)
!   Single parameterizable code supports all 3 courses.
!
! Runtime update functions (smaller tilemap changes during gameplay):
!   FUN_06004F28, FUN_06005120, FUN_06036E90, FUN_060370E4
!   Use same DMA mechanism but with smaller transfer sizes.


! =============================================================================
! VDP2 COLOR RAM (0x25F00000) — Palette Management
! =============================================================================
!
! Functions (24 access sites across 17 functions):
! CONFIDENCE: HIGH — function addresses verified, 0x25F00000 is standard
!   Saturn color RAM address
!   FUN_060038D4 — Initial palette setup
!   FUN_0600EC78 — Runtime palette update
!   FUN_0601938C — Per-frame dynamic palette effects
!
! Palette organization:
!   512 entries, 16-bit color each (2 bytes per entry)
!   4-byte stride for 32-bit writes (writes 2 entries at once)
!   Multiple banks selectable via 0x060635DE
!
! Dynamic palette effects:
! CONFIDENCE: MEDIUM — palette cycling confirmed, but specific effect
!   names (sunset, tunnel lighting) are speculative game-context interpretation
!   FUN_0601938C through FUN_060429EC show highest concentration
!   of color RAM access — different palettes per track,
!   per-frame color cycling for environmental effects (sunset,
!   tunnel lighting, etc.)


! =============================================================================
! VDP2 CONTROL REGISTERS (0x25F80000) — Display Configuration
! =============================================================================
!
! Functions:
! CONFIDENCE: HIGH — function address verified, pool constant loads
!   0x0000E000 at [0x06026CD8] confirming register block setup
!   FUN_06026CA4 — Primary register block setup
!   FUN_0603836C — Secondary register configuration
!
! Register write pattern (sequential):
!   mov.l @(PC),r2          ; r2 = 0x25F80000
!   mov.l r3,@r2            ; write register +0x00 (TVMD)
!   add #4,r2
!   mov.l r3,@r2            ; write register +0x04 (EXTEN)
!   add #4,r2
!   ...continues...
!
! Two access methods in FUN_06026CA4:
!   Setup phase: loads from @(0x5C,PC) — full register block
!   Runtime: loads from @(0x18,PC) — specific register subset
!   Suggests dynamic display parameter adjustment during gameplay.


! =============================================================================
! SCU DMA CONTROLLER (0x25FE0000) — Bulk Data Transfer
! =============================================================================
!
! CONFIDENCE: HIGH — SCU address 0x25FE0000 and register layout match
!   Saturn technical documentation. Status mask 0x272E verified.
! Primary DMA function at 0x0602766C (documented in math_helpers.s):
!   1. Poll 0x25FE007C & 0x272E until clear (wait for idle)
!   2. Write source to +0x04
!   3. Write destination to +0x00
!   4. Write size to +0x08
!   5. Write mode 0x0101 to +0x0C
!   6. Write 7 to +0x14 (trigger)
!   7. Write 0x0101 to +0x10 (start)
!
! DMA is SYNCHRONOUS: CPU stalls until transfer completes.
! No status polling after trigger — hardware blocks the CPU.
!
! Performance:
!   Typical transfer: 8KB-33KB per operation
!   40+ calls during initialization = ~400KB total
!   Estimated time: ~50ms for full init (bus priority effects)
!
! Runtime DMA (FUN_0603FE80):
!   Parameter chaining with status monitoring
!   Used for smaller per-frame transfers


! =============================================================================
! SH-2 HARDWARE DIVIDER (0xFFFFFF00)
! =============================================================================
!
! CONFIDENCE: DEFINITE — standard SH-2 on-chip divider at 0xFFFFFF00
! See math_helpers.s for complete documentation.
! Two access modes:
!   FUN_0602755C — Unprotected 64/32 divide (for non-interrupt contexts)
!   FUN_0602ECCC — Protected 32/32 divide (disables interrupts)
!
! The divider is a SHARED RESOURCE between main code and interrupts.
! FUN_0602ECCC wraps the divide in a critical section:
!   stc.l sr,@-r15           ; save interrupt state
!   ldc 0xF0,sr              ; mask all interrupts
!   ... perform division ...
!   ldc.l @r15+,sr           ; restore interrupts


! =============================================================================
! HARDWARE ACCESS SUMMARY
! =============================================================================
!
! | Hardware        | Address      | Access Mode | Key Functions |
! |-----------------|--------------|-------------|---------------|
! AUDIT NOTE: FIXED — Summary table corrected. VDP1 VRAM is 0x25C00000,
!   VDP1 Framebuffer is 0x25C80000, VDP1 I/O Registers are 0x25D00000.
!   Verified against aprog.s pool constants in FUN_0600A140 and FUN_06006F3C.
! | VDP1 VRAM       | 0x25C00000   | Async       | A140          |
! | VDP1 Framebuf   | 0x25C80000   | Async       | A140, 14A04   |
! | VDP1 I/O Regs   | 0x25D00000   | Async       | 6F3C, 3931C   |
! | VDP2 VRAM       | 0x25E00000   | Sync (DMA)  | 3578 (mega)   |
! | VDP2 Color RAM  | 0x25F00000   | Async       | 38D4, 1938C   |
! | VDP2 Registers  | 0x25F80000   | Async       | 26CA4, 3836C  |
! | DMA Controller  | 0x25FE0000   | Sync/Block  | 2766C, 3FE80  |
! | HW Divider      | 0xFFFFFF00   | Critical    | 2755C, 2ECCC  |
!
! Synchronization model:
!   - VDP1: Asynchronous command queue, fire-and-forget
!   - VDP2: Synchronous bulk init via DMA, async register writes
!   - DMA: CPU blocks during transfer (no polling needed)
!   - Divider: Critical section required in interrupt contexts
!
! The separation between sync (initialization) and async (runtime)
! is a deliberate performance optimization — bulk loading is done
! during state transitions, while per-frame rendering uses non-blocking
! register writes to maximize CPU utilization.


! =============================================================================
! Graphics Subsystem Hierarchy
! =============================================================================
!
! CONFIDENCE: HIGH — all function addresses verified in aprog.s, call
!   order is a reasonable reconstruction from init code analysis
! Game Startup:
!   FUN_06003578 (VDP2 VRAM mega-init, 40+ DMA calls)
!   FUN_060038D4 (palette init)
!   FUN_06026CA4 (VDP2 register config)
!   FUN_0603931C (VDP1 polygon setup)
!   FUN_0600A140 (VDP1 VRAM + framebuffer init)
!
! Per-Frame Rendering:
!   FUN_0601938C (dynamic palette update)
!   FUN_06014A04 (framebuffer address update, VBlank synced)
!   FUN_0602EEB8 (per-car render pipeline, see vertex_pipeline.s)
!   FUN_06027CA4 (3D scene renderer, see scene_renderer.s)
!   FUN_06014A74 (buffer flip)
!
! VDP1 Display List Flow:
!   scene_renderer.s documents FUN_06027CA4 which submits visible
!   models to the VDP1 command queue. The queue is processed
!   asynchronously by VDP1 hardware while the CPU proceeds
!   to the next frame's physics calculations.
