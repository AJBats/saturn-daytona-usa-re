# Overlay System Study

> **Status**: COMPLETE — APROG.BIN not overwritten by overlays; all data loads to Low RAM/Sound RAM.
> Started: 2026-02-17

## Summary

APROG.BIN is **not** overwritten by overlays. All game data files load to **Low RAM**
(0x00200000) and **Sound RAM** (0x25A00000). APROG code stays intact in High RAM.

This contradicts our earlier hypothesis (from call trace investigation) that overlays
replaced APROG code in memory. The "NEITHER" data we observed in APROG's address
range during memory dumps has a different explanation — likely BSS clearing and
runtime state initialization by APROG's own init code.

---

## 1. Saturn Memory Architecture

```
  LOW RAM (1MB)                     HIGH RAM (1MB)
  0x00200000─0x002FFFFF             0x06000000─0x060FFFFF
  ┌───────────────────┐             ┌───────────────────┐
  │                   │             │ Stack / Vectors    │ 0x06000000
  │  Game data:       │             ├────────────────────┤
  │   Course polys    │             │                    │ 0x06003000
  │   Course lines    │             │  APROG.BIN         │
  │   Course defs     │             │  (all game code)   │
  │   Textures        │             │                    │
  │   Scroll data     │             │  ~385 KB           │
  │   Tables          │             │                    │
  │   PIT model       │             │  Stays intact —    │
  │   GAMED overlay   │             │  NOT overwritten   │
  │   SLCTD overlay   │             │  by overlays       │
  │                   │             │                    │
  └───────────────────┘             ├────────────────────┤ 0x06063690
                                    │ Game state / vars  │
  SOUND RAM (512KB)                 │ Object arrays      │
  0x25A00000─0x25A7FFFF             │ Car structs (0x78900)│
  ┌───────────────────┐             │ ...                │
  │ Sound driver (68K)│             ├────────────────────┤
  │ SOUNDS.BIN        │             │ POLYGON.BIN        │ 0x060F8000
  │ GAMED/SLCTD/OVERD │             │ (26KB, near top)   │
  │ NAMD/MUSICD etc.  │             └────────────────────┘ 0x060FFFFF
  └───────────────────┘
```

## 2. Disc File Inventory

26 files on the data track (Track 01, MODE1/2352):

### Program Binary
| File | Size | Destination | Notes |
|------|------|-------------|-------|
| APROG.BIN | 394,896 (385KB) | 0x06003000 | Loaded by BIOS/IP.BIN at boot |

### Course Data (3 variants — loaded by course selection)
| File | Size | Destination | Notes |
|------|------|-------------|-------|
| CS0POLY.BIN | 296,724 | 0x00200000 | Three Seven Speedway polygons |
| CS1POLY.BIN | 631,032 | 0x00200000 | Dinosaur Canyon polygons |
| CS2POLY.BIN | 846,916 | 0x00200000 | Seaside Street Galaxy polygons |
| CS0_LINE.BIN | 34,990 | 0x00200000 | Course 0 spline/centerline |
| CS1_LINE.BIN | 82,970 | 0x00200000 | Course 1 spline/centerline |
| CS2_LINE.BIN | 164,594 | 0x00200000 | Course 2 spline/centerline |
| COURSE0.BIN | 51,608 | 0x00240000 | Course 0 definition |
| COURSE1.BIN | 130,968 | 0x00240000 | Course 1 definition |
| COURSE2.BIN | 135,600 | 0x00240000 | Course 2 definition |
| TEX_C0.BIN | 177,529 | 0x002A8000 | Course 0 textures |
| TEX_C1.BIN | 243,369 | 0x002A8000 | Course 1 textures |
| TEX_C2.BIN | 250,097 | 0x002A8000 | Course 2 textures |

### Shared Assets (loaded once during init or state transitions)
| File | Size | Destination | Notes |
|------|------|-------------|-------|
| TEX_PL.BIN | 38,824 | 0x002A0000 | Common/palette textures |
| SCROLL.BIN | 327,736 | 0x002A0000 | VDP2 background scroll data |
| TABLE.BIN | 28,448 | 0x002F0000 | Lookup tables (trig? collision?) |
| POLYGON.BIN | 25,992 | 0x060F8000 | Generic polygon data (High RAM!) |
| PIT.BIN | 31,376 | 0x002F8000 | Pit stop model |

### Sound / Music Data (loaded to Sound RAM)
| File | Size | Destination | Notes |
|------|------|-------------|-------|
| SOUNDS.BIN | 7,312 | 0x25A00000 | Sound samples → Sound RAM base |

### State Overlays (all exactly 446,464 bytes = 0x6D000)
These swap into the same Low RAM / Sound RAM regions depending on game state.

| File | Size | Dest A (Sound) | Dest B (Low RAM) | Notes |
|------|------|----------------|-------------------|-------|
| GAMED.BIN | 446,464 | 0x25A03000 | 0x00200000 | Gameplay data |
| SLCTD.BIN | 446,464 | 0x25A03000 | 0x0026D000 | Selection/menu screen |
| OVERD.BIN | 446,464 | 0x25A03000 | — | Game over screen |
| NAMD.BIN | 446,464 | 0x25A03000 | — | Name entry screen |
| MUSICD.BIN | 446,464 | 0x25A10000 | — | Music set 1 |
| MUSIC2D.BIN | 446,464 | 0x25A10000 | — | Music set 2 |
| MUSIC3D.BIN | 446,464 | 0x25A10000 | — | Music set 3 |

### Audio Tracks (21 CDDA tracks)
Tracks 02-22 are audio (CDDA music), ranging from 1.6MB to 52MB each.

## 3. File Loading API

### Architecture (4 layers)

```
Layer 4: File stub wrappers  (FUN_06012D7C — FUN_06012F60)
         Each hardcodes a filename + destination address
              │
Layer 3: Generic file loader  (FUN_06012C3C)
         Takes filename string + dest addr, retry loop
              │
Layer 2: CD filesystem        (FUN_06012B58, FUN_06012BDC)
         ISO9660 file-by-name open, disc detect
              │
Layer 1: CD block hardware    (0x06035C48 — 0x06035F44)
         HIRQ polling, CR1-CR4 command/response, SCSI commands
```

### Key Functions

| Address | Name | Purpose |
|---------|------|---------|
| 0x06012B58 | cd_init_check | Init CD, verify APROG.BIN integrity |
| 0x06012BDC | disc_detect | Display "SET DAYTONA DISC", poll until inserted |
| 0x06012C3C | **load_file** | Generic loader: filename + dest → CD read |
| 0x06012CF4 | cd_subsystem_init | Initialize CDC config struct, retry loop |
| 0x06012D7C | load_course_poly | CS{0,1,2}POLY.BIN → 0x00200000 |
| 0x06012DB4 | load_course_data | CS_LINE + COURSE → Low RAM |
| 0x06012E00 | load_tex_common | TEX_PL.BIN → 0x002A0000 |
| 0x06012E08 | load_tex_course | TEX_C{0,1,2}.BIN → 0x002A8000 |
| 0x06012E62 | load_scroll | SCROLL.BIN → 0x002A0000 |
| 0x06012E6A | load_tables | TABLE.BIN → 0x002F0000, POLYGON.BIN → 0x060F8000 |
| 0x06012E7C | load_pit | PIT.BIN → 0x002F8000 |
| 0x06012E84 | load_sounds | SOUNDS.BIN → 0x25A00000 (Sound RAM) |
| 0x06012EBC | load_gamed_sound | GAMED.BIN → 0x25A03000 |
| 0x06012EC4 | load_gamed_lowram | GAMED.BIN → 0x00200000 |
| 0x06012F00 | load_slctd_lowram | SLCTD.BIN → 0x0026D000 |
| 0x06012F10 | load_overd | OVERD.BIN → 0x25A03000 |
| 0x06012F20 | load_namd | NAMD.BIN → 0x25A03000 |
| 0x06012F50-60 | load_music{1,2,3} | MUSICD/2D/3D → 0x25A10000 |

### CD Block Driver (0x06035C48-0x06036BA6)

~66 functions implementing Saturn CDB SCSI command API:
- **FUN_06035c6e** — Write HIRQ register
- **FUN_06035e3c** — Write CR1-CR4 command registers
- **FUN_06035e5e** — Read CR1-CR4 response registers
- **FUN_06035e00** — Poll HIRQ with timeout
- **FUN_06035d5a** — Execute command: clear HIRQ → write CR → wait → read response

Hardware registers (cache-through):
- HIRQ: 0x25890008
- CR1-CR4: 0x25890018, 0x2589001C, 0x25890020, 0x25890024

## 4. Init Sequence (FUN_060030FC)

Called immediately by `_start` at 0x06003000. Executes 14+ subsystem init calls:

| # | Address | Function | Purpose |
|---|---------|----------|---------|
| 1 | 0x0603BF7C | cache_init | Clear SH-2 cache SRAM, configure TIER |
| 2 | 0x06034E58 | gfx_init | Graphics/rendering setup |
| 3 | 0x06000344 | bios_callback_1 | Via function pointer, params (-1, word) |
| 4 | 0x06012CF4 | **cd_subsystem_init** | CDC config struct, retry FUN_0603AC1C |
| 5 | 0x06003274 | sub_init_1 | 31 instructions |
| 6 | 0x06004A98 | **engine_init** | 424 insns — DMA transfer table setup |
| 7 | 0x06012E6A | **load_tables** | CD load: TABLE.BIN + POLYGON.BIN |
| 8 | 0x06003218 | sub_init_2 | 46 instructions |
| 9 | 0x06018EE4 | **sound_init** | SNDOFF → clear SCSP → load SOUNDS.BIN + GAMED.BIN → SNDON → wait "OK" |
| 10 | 0x06000344 | bios_callback_2 | Via function pointer, params (word, 0) |
| 11 | 0x06005174 | obj_init | Clear animation state buffer (8 shorts) |
| 12 | 0x0601F936 | render_init | Sound/audio system init |
| 13 | 0x0601492C | vdp1_cmd_init | VDP1 command setup |
| 14 | 0x060149E0 | state_init | Game state flag bit setup |
| 15 | — | set state=2 | Write 2 to *(0x0605AD10) → attract mode |

After init, `_start` enters the main loop:
1. Call FUN_0600A392 (per-frame update)
2. Read game state from 0x0605AD10
3. Dispatch through 32-entry jump table

## 5. Game State Machine → File Loading

State handlers trigger file loading at different points:

| State Handler | Files Loaded | When |
|---------------|-------------|------|
| State 0 (0x060088CC) | CD setup | Startup |
| State 2 (0x06008938) | Attract mode data | After init |
| State 5 (0x06008D74) | Course-specific data | Course select |
| States 6-11 | Overlay swap (GAMED/SLCTD etc.) | Mode transitions |
| State 14 (0x06008EBC) | Resource loading | During race |
| State 27 (0x06009E02) | Full scene setup (FUN_06012F80) | Scene transitions |

## 6. Low RAM Usage Map

Low RAM (0x00200000-0x002FFFFF, 1MB) is used as a data workspace:

```
  0x00200000 ┌─────────────────────────────┐
             │ Course polygons             │ CS0: 297KB, CS1: 631KB, CS2: 847KB
             │ (or GAMED.BIN dest B)       │ Overlapping use!
             │ (or CS_LINE data)           │
  0x00240000 ├─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─┤
             │ Course definitions          │ COURSE0/1/2.BIN
             │                             │
  0x0026D000 ├─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─┤
             │ SLCTD.BIN dest B            │ Selection screen overlay
             │                             │
  0x002A0000 ├─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─┤
             │ TEX_PL.BIN (palette tex)    │ OR SCROLL.BIN (share addr!)
  0x002A8000 ├─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─┤
             │ TEX_C{0,1,2}.BIN            │ Course textures
             │                             │
  0x002F0000 ├─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─┤
             │ TABLE.BIN                   │ Lookup tables
  0x002F8000 ├─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─┤
             │ PIT.BIN                     │ Pit stop model
  0x002FFFFF └─────────────────────────────┘
```

Multiple files share the same base address (0x00200000) — they're loaded at
different times and overwrite each other. This is the true "overlay" mechanism:
course selection loads new polygon/line data over the previous course's data.

## 7. Sound RAM Usage Map

```
  0x25A00000 ┌─────────────────────────────┐
             │ SOUNDS.BIN (7KB)            │ Sound samples
  0x25A03000 ├─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─┤
             │ GAMED / SLCTD / OVERD /     │ State-dependent overlay
             │ NAMD — one at a time        │ (446KB each, share slot)
             │                             │
  0x25A10000 ├─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─┤
             │ MUSICD / MUSIC2D / MUSIC3D  │ Music overlay
             │ — one at a time             │ (446KB each, share slot)
             │                             │
  0x25A7FFFF └─────────────────────────────┘
```

## 8. Key Discovery: APROG Is NOT Overwritten

### What We Previously Believed
Our call trace investigation (sawyer_l2.md, GT3) found that memory at offsets
0x10000-0x50000 within APROG's range matched NEITHER the production nor
free-layout binary. We concluded "APROG is a bootstrap that gets overwritten
by overlay data."

### What We Now Know
**No overlay file targets APROG's address range (0x06003000-0x06063690).**

All file load destinations are:
- Low RAM (0x002xxxxx) — course data, textures, tables
- Sound RAM (0x25Axxxxx) — sound/music data
- One exception: POLYGON.BIN → 0x060F8000 (High RAM, but above APROG)

### Why Memory Dumps Showed "NEITHER"
The init sequence modifies APROG's own memory through:
1. **BSS clearing** — two loops zero ranges at [0x06059C4C-0x06059C50] and
   [0x06059C54-0x06059C58]. These ranges (addresses stored as pointers) may
   overlap with APROG's data sections.
2. **DMA transfer setup** — FUN_06003A3C (1059 insns) builds ~30 DMA transfer
   descriptors, likely copying initial data FROM APROG to Low RAM, then the
   source regions become stale.
3. **Runtime state** — object arrays, game variables, car structs get written
   into data regions within APROG's address range.

The CODE portions of APROG should remain intact. The NEITHER results may be
from checking offsets that fell on data regions, not code.

## 9. Open Questions

### Critical (Resolved)
- [x] **What are the BSS clear ranges?** — RESOLVED:
      - Loop 1: 0x06063690 → 0x060A2470 (254KB zeroed)
      - Loop 2: 0x060A2470 → 0x060A5404 (12KB zeroed)
      - Total: ~266KB zeroed ABOVE APROG (does NOT touch APROG code)
      - Pointer values read from binary at offsets 0x56C4C-0x56C58
- [ ] **Which APROG offsets are code vs data?** — Need a code/data map of the
      binary to understand which regions survive init
- [ ] **Why did the BRA→BSR discrepancy exist at 0x0601078A?** — If APROG isn't
      overwritten, how did an instruction change? Self-modifying code? Or was
      our analysis flawed?

### Important
- [ ] **DMA transfer table** — What does FUN_06003A3C actually copy and where?
      The 0x002xxxxx addresses in its constant pool suggest it copies data
      FROM High RAM TO Low RAM during init
- [ ] **GAMED.BIN dual loading** — Why is it loaded to both Sound RAM (0x25A03000)
      AND Low RAM (0x00200000)? Sound data portion + game data portion?
- [ ] **TEX_PL and SCROLL share 0x002A0000** — These must be loaded at different
      times. When does SCROLL replace TEX_PL?

### Nice to Have
- [ ] **Filename strings** — The actual ASCII filenames are embedded at
      0x060448E8-0x06044A1C (constant pool region). Dumping these would
      confirm the file→function mapping.
- [ ] **Complete state→file mapping** — Which game states trigger which
      file loads? Full cross-reference needed.

## 10. BSS Clear Ranges (Confirmed)

The two BSS clearing loops in FUN_060030FC zero these ranges:

| Loop | Start | End | Size | Region |
|------|-------|-----|------|--------|
| 1 | 0x06063690 | 0x060A2470 | 254,944 (249KB) | Above APROG end |
| 2 | 0x060A2470 | 0x060A5404 | 12,180 (12KB) | Continuation |

**Total: ~266KB zeroed, all ABOVE APROG's code range.**

This is the runtime data workspace: object arrays, car structs, game state
variables, VDP command lists, etc. APROG code at 0x06003000-0x06063690
is NOT touched by BSS clearing.

Source: pointer values at binary offsets 0x56C4C-0x56C58 (addresses
0x06059C4C-0x06059C58), read as big-endian 32-bit values.

## 11. Corrected Memory Model

```
  BEFORE INIT (frame 46):
  ┌────────────── HIGH RAM ──────────────┐
  │ 0x06003000  ┌──────────────────────┐ │
  │             │ APROG.BIN            │ │   All code + embedded data
  │             │ (385KB, pristine)    │ │   Exactly matches binary on disc
  │ 0x06063690  └──────────────────────┘ │
  │             │ (empty / undefined)  │ │
  │ 0x060FFFFF                           │
  └──────────────────────────────────────┘

  AFTER INIT (frame 48+):
  ┌────────────── HIGH RAM ──────────────┐
  │ 0x06003000  ┌──────────────────────┐ │
  │             │ APROG.BIN            │ │
  │             │  Code sections:      │ │   INTACT — still matches binary
  │             │   engine, CD driver, │ │
  │             │   state machine...   │ │
  │             │                      │ │
  │             │  Data sections:      │ │   MODIFIED — BSS zeroed,
  │             │   BSS (zeroed)       │ │   runtime state written,
  │             │   vars (initialized) │ │   no longer matches binary
  │             │   tables (consumed?) │ │
  │ 0x06063690  └──────────────────────┘ │
  │             │ Game state variables │ │   Object arrays, car structs,
  │ 0x06078900  │ Car[40] × 0x268     │ │   VDP command lists...
  │             │ ...                  │ │
  │ 0x060F8000  ┌──────────────────────┐ │
  │             │ POLYGON.BIN (26KB)   │ │   Only non-APROG file in High RAM
  │ 0x060FFFFF  └──────────────────────┘ │
  └──────────────────────────────────────┘

  ┌────────────── LOW RAM ───────────────┐
  │ 0x00200000  ┌──────────────────────┐ │
  │             │ Course poly/line     │ │   Swapped per course selection
  │ 0x00240000  │ Course definition    │ │
  │ 0x002A0000  │ Textures / Scroll    │ │   Swapped per state
  │ 0x002F0000  │ TABLE.BIN            │ │
  │ 0x002F8000  │ PIT.BIN              │ │
  │ 0x002FFFFF  └──────────────────────┘ │
  └──────────────────────────────────────┘

  ┌────────────── SOUND RAM ─────────────┐
  │ 0x25A00000  │ SOUNDS.BIN (7KB)     │ │
  │ 0x25A03000  │ GAMED/SLCTD/OVERD/   │ │   One overlay at a time
  │             │ NAMD (446KB each)    │ │
  │ 0x25A10000  │ MUSICD/2D/3D         │ │   One music set at a time
  │ 0x25A7FFFF  └──────────────────────┘ │
  └──────────────────────────────────────┘
```

## 11. Implications for Road to Boot

1. **APROG code is the real game** — it's not a disposable bootstrap. Every
   function matters and stays resident.

2. **The black screen bug is in our reimpl code** — since APROG isn't overwritten,
   bugs in any of our 1234 function implementations could cause the black screen.
   There's no "overlay takes over" safety net.

3. **Init correctness is critical** — the init chain (FUN_060030FC) must work
   correctly to set up CD, load TABLE/POLYGON/SOUNDS/GAMED, initialize the
   sound system, and set game state to 2. Any failure here = black screen.

4. **Low RAM setup matters** — the DMA transfer table (FUN_06003A3C) copies
   initial data from APROG to Low RAM. If our reimpl's data sections are wrong,
   the game data in Low RAM will be wrong.

---

## Evidence Sources

| Source | Location | What It Shows |
|--------|----------|---------------|
| File loader disassembly | build/aprog.s lines 34130-34380 | Destination addresses for all files |
| Ghidra CD block decomp | ghidra_project/decomp_all.txt lines 85346-85700 | CD driver architecture |
| Init chain disassembly | build/aprog.s lines 149-500 | Init sequence and callees |
| Memory dump scripts | tools/verify_*.py (6 scripts) | Memory state at various frames |
| Disc file listing | build/disc/files/ | All 26 game files |
| Call trace results | .tmp/call_trace/ | 600K+ function calls, identical traces |
| Determinism test | tools/call_trace_determinism.py | Sequence is deterministic |

---

*Last updated: 2026-02-17*
