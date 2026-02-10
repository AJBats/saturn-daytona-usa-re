# Unmapped Function Analysis -- All Gap Ranges

> Generated 2026-02-06 from aprog_syms.txt (1234 functions), aprog.s (206K lines),
> existing asm/*.s coverage, and src/*.c files.
>
> Method: every function address extracted from aprog_syms.txt, cross-referenced
> against src/FUN_*.c files (glob) and asm/*.s documentation (grep), then assembly
> read from aprog.s to determine size, LEAF/CALL type, and functional category.
>
> Size = bytes from this symbol to the next symbol (includes pool constants/padding).
> LEAF = no jsr/bsr/jmp calls. CALL = calls other functions.

---

## RANGE 1: 0x06007xxx (13 functions)

| # | Function | Addr | Size | Type | Has C | ASM Doc | Category |
|---|----------|------|------|------|-------|---------|----------|
| 1 | FUN_06007268 | 0x06007268 | 0x7E = 126B | CALL | No | vblank_system.s | VBlank-OUT interrupt handler |
| 2 | FUN_060072E6 | 0x060072E6 | 0x86 = 134B | CALL | No | -- | **Timer/periodic interrupt handler**: pushes ALL regs r0-r14+pr+mach+macl, calls via function pointer at [0x06000344], increments counter at 0x06059F40, restores all regs |
| 3 | FUN_0600736C | 0x0600736C | 0x04 = 4B | LEAF | Yes | -- | Tiny stub (Ghidra boundary artifact, 2 insns) |
| 4 | FUN_06007370 | 0x06007370 | 0x10C = 268B | CALL | No | -- | **VDP1 polygon setup orchestrator**: stores to 0x06063F5C + 0x0606A4F4 (display list), calls FUN_06039250, FUN_0603931C (polygon type), FUN_060393FC, FUN_06038E54, FUN_06012E00. Full render pipeline init for a display mode |
| 5 | FUN_0600747C | 0x0600747C | 0x1DC = 476B | CALL | No | -- | **Sprite tile compositor**: shar x8 = divide-by-256, AND 0x3F mask (64-tile index). Reads tile table at 0x060684EC, writes display list at 0x0606A4F4. mul.l stride calc, nested loop. Per-tile sprite rendering |
| 6 | FUN_06007658 | 0x06007658 | 0x138 = 312B | CALL | Yes | -- | Sprite rendering helper (C source at src/FUN_06007658.c) |
| 7 | FUN_06007790 | 0x06007790 | 0x14C = 332B | CALL | Yes | -- | Display list manager (C source at src/FUN_06007790.c) |
| 8 | FUN_060078DC | 0x060078DC | 0x174 = 372B | CALL | Yes | frame_timing.s | **Frame end / display commit**: tail-called from every state handler. VDP1 command submission + frame sync |
| 9 | FUN_06007A50 | 0x06007A50 | 0x17C = 380B | CALL | Yes | frame_timing.s | Additional rendering pass |
| 10 | FUN_06007BCC | 0x06007BCC | 0x120 = 288B | CALL | Yes | frame_timing.s | VDP1 sprite command builder loop |
| 11 | FUN_06007CEC | 0x06007CEC | 0xA2 = 162B | CALL | No | -- | **Sprite batch processor**: pushes r8-r14, calls FUN_0603C000. Loop over 0x0606A4F8 (sprite index table), computes index*20 offset, accesses sprite data at 0x0608AC20 and output at 0x06078624 |
| 12 | FUN_06007D8E | 0x06007D8E | 0x7A = 122B | CALL | No | -- | **Hardware sprite register setup**: pushes r12-r14, embedded data words 0xFE11/0x0080. Accesses 0x060281B8, 0x0608AC20. Small sprite register configurator |
| 13 | FUN_06007E08 | 0x06007E08 | ~502B | CALL | No | -- | **Large sprite/polygon renderer**: pushes r8-r14, stack frame -36B. Signed shift (shar) for depth, shll2/shll for address calc. Reads polygon array at stride, bounds checks. Complex 3D sprite renderer with depth sorting |

**Summary**: 13 functions total. 8 have C source, 3 documented in asm/*.s. 5 truly undocumented (72E6, 7370, 747C, 7CEC, 7D8E, 7E08 -- all rendering pipeline or interrupt handlers).

---

## RANGE 2: 0x06008xxx (25 functions)

### Pre-State Functions (0x060081F4-0x060086C0) -- 7+2 functions

| # | Function | Addr | Size | Type | Has C | ASM Doc | Category |
|---|----------|------|------|------|-------|---------|----------|
| 1 | FUN_060081F4 | 0x060081F4 | 0x124 = 292B | CALL | Yes | force_system.s | Gas force application |
| 2 | FUN_06008318 | 0x06008318 | 0x100 = 256B | CALL | Yes | force_tables.s | Gear shift handler |
| 3 | FUN_06008418 | 0x06008418 | 0x48 = 72B | CALL | Yes | force_system.s | Force lookup variant A |
| 4 | FUN_06008460 | 0x06008460 | 0x6A = 106B | CALL | Yes | force_system.s | Force lookup variant B |
| 5 | FUN_060084CA | 0x060084CA | 0xEE = 238B | CALL | Yes | -- | Force helper |
| 6 | FUN_060085B8 | 0x060085B8 | 0x108 = 264B | CALL | Yes | force_system.s | Brake force application |
| 7 | FUN_060086C0 | 0x060086C0 | ~448B | CALL | Yes | force_system/tables | Force table apply |

### State Machine Handlers (0x060088CC-0x06009F10) -- 18 functions

All 18 documented in state_handlers.s. None have C sources (inline asm via hybrid build).

| # | Function | Addr | Size | State | ASM Doc | Category |
|---|----------|------|------|-------|---------|----------|
| 8 | FUN_060088CC | 0x060088CC | 0x6C = 108B | 0 | state_handlers.s | Game/course init |
| 9 | FUN_06008938 | 0x06008938 | 0x04 = 4B | 2 | state_handlers.s | Transition stub |
| 10 | FUN_0600893C | 0x0600893C | 0xDC = 220B | (sub) | -- | **Game init sub-handler**: zeroes flags at 0x06078634/35, 0x0607ED8C, 0x0607864B. Calls FUN_06018A3C, FUN_0600EB14 (physics init), FUN_06033AAC, FUN_0600A140 (VDP1 init). Conditional call to FUN_0600330A. Sets 0x06087804, 0x0607EBCC, 0x0607EAE0, 0x0607EAD8. State 0 continuation. |
| 11 | FUN_06008A18 | 0x06008A18 | 0xEC = 236B | 3 | state_handlers.s | Attract mode timeout |
| 12 | FUN_06008B04 | 0x06008B04 | 0x30 = 48B | 6 | state_handlers.s | Course select init |
| 13 | FUN_06008B34 | 0x06008B34 | 0x44 = 68B | 7 | state_handlers.s | Course select active |
| 14 | FUN_06008B78 | 0x06008B78 | 0x24 = 36B | 8 | state_handlers.s | Car select init |
| 15 | FUN_06008B9C | 0x06008B9C | 0x3C = 60B | 9 | state_handlers.s | Car select active |
| 16 | FUN_06008BD8 | 0x06008BD8 | 0x24 = 36B | 10 | state_handlers.s | Loading init |
| 17 | FUN_06008BFC | 0x06008BFC | 0x18 = 24B | 11 | state_handlers.s | Loading check |
| 18 | FUN_06008C14 | 0x06008C14 | 0x62 = 98B | 12 | state_handlers.s | Resource check router |
| 19 | FUN_06008C76 | 0x06008C76 | 0x56 = 86B | 30 | state_handlers.s | Memory router |
| 20 | FUN_06008CCC | 0x06008CCC | 0x04 = 4B | 4 | state_handlers.s | State boundary normalizer entry |
| 21 | FUN_06008CD0 | 0x06008CD0 | 0xA4 = 164B | (sub) | -- | **State boundary continuation**: stores r14 to 0x06078644, calls FUN_060149E0, FUN_06026CE0 (VDP init), clears 0x06059F44, calls FUN_0601D2DC, FUN_0601B074. Sets 0x0607EBCC, 0x06086024, state=5 at 0x0605AD10, ORs 0x40000000 into 0x0605B6D8. Full state 4/5 setup. |
| 22 | FUN_06008D74 | 0x06008D74 | 0x8C = 140B | 5 | state_handlers.s | Input detection router |
| 23 | FUN_06008E00 | 0x06008E00 | 0x48 = 72B | 13 | state_handlers.s | Race preparation |
| 24 | FUN_06008E48 | 0x06008E48 | 0x74 = 116B | (sub) | -- | **Race prep dispatcher**: checks 0x0607EBCC (countdown). If negative: sets state=14 at 0x0605AD10, calls FUN_06026CE0, clears 0x06059F44. Else: calls FUN_0600F424 (game state). Then checks state==13, tail-calls FUN_06018E70 (general init). Bridge between pre-race and active racing. |
| 25 | FUN_06008EBC | 0x06008EBC | ~444B | 14 | state_handlers.s | Race first-frame setup |

**Summary**: 25 functions. 9 have C source. 18 documented in state_handlers.s. 3 undocumented sub-handlers (893C, 8CD0, 8E48), all now categorized above.

---

## RANGE 3: 0x0600Fxxx (18 functions)

All documented in race_orchestration.s.

| # | Function | Addr | Size | Has C | ASM Doc | Category |
|---|----------|------|------|-------|---------|----------|
| 1 | FUN_0600F424 | 0x0600F424 | 0x22C = 556B | Yes | race_orchestration.s | **Game state dispatcher** (CRITICAL) |
| 2 | FUN_0600F650 | 0x0600F650 | 0x144 = 324B | No | race_orchestration.s | Post-race transition |
| 3 | FUN_0600F794 | 0x0600F794 | 0x8E = 142B | No | race_orchestration.s | Transition handler |
| 4 | FUN_0600F822 | 0x0600F822 | 0x4E = 78B | No | race_orchestration.s | Small transition |
| 5 | FUN_0600F870 | 0x0600F870 | 0x28 = 40B | Yes | race_orchestration.s | Race countdown timer |
| 6 | FUN_0600F898 | 0x0600F898 | 0x26 = 38B | No | race_orchestration.s | Minimal transition |
| 7 | FUN_0600F8BE | 0x0600F8BE | 0x56 = 86B | No | race_orchestration.s | Transition handler |
| 8 | FUN_0600F914 | 0x0600F914 | 0x78 = 120B | No | race_orchestration.s | Transition handler |
| 9 | FUN_0600F98C | 0x0600F98C | 0x04 = 4B | No | race_orchestration.s | Stub/redirect |
| 10 | FUN_0600F990 | 0x0600F990 | 0x36 = 54B | No | race_orchestration.s | Small transition |
| 11 | FUN_0600F9C6 | 0x0600F9C6 | 0x1B2 = 434B | No | race_orchestration.s | Large transition (menu) |
| 12 | FUN_0600FB78 | 0x0600FB78 | 0x1DC = 476B | No | race_orchestration.s | Large transition (results) |
| 13 | FUN_0600FD54 | 0x0600FD54 | 0x36 = 54B | No | race_orchestration.s | Small transition |
| 14 | FUN_0600FD8A | 0x0600FD8A | 0x74 = 116B | No | race_orchestration.s | Medium transition |
| 15 | FUN_0600FDFE | 0x0600FDFE | 0x3A = 58B | No | race_orchestration.s | Small transition |
| 16 | FUN_0600FE38 | 0x0600FE38 | 0x98 = 152B | No | race_orchestration.s | Medium transition |
| 17 | FUN_0600FED0 | 0x0600FED0 | 0x100 = 256B | No | race_orchestration.s | Medium transition |
| 18 | FUN_0600FFD0 | 0x0600FFD0 | 0xD4 = 212B | Yes | race_orchestration.s | HUD race display |

**Summary**: 18 functions. 3 have C source. All 18 documented in race_orchestration.s. Zero gap.

---

## RANGE 4: 0x06010xxx-0x06011xxx (29 functions)

All documented in hud_ui.s.

| # | Function | Addr | Size | Has C | ASM Doc | Category |
|---|----------|------|------|-------|---------|----------|
| 1 | FUN_060100A4 | 0x060100A4 | 0x248 = 584B | Yes | hud_ui.s | Sprite rendering with animation frames |
| 2 | FUN_060102EC | 0x060102EC | 0xCC = 204B | Yes | hud_ui.s | Input delta detection |
| 3 | FUN_060103B8 | 0x060103B8 | 0xB8 = 184B | Yes | hud_ui.s | Binary state toggle |
| 4 | FUN_06010470 | 0x06010470 | 0x70 = 112B | Yes | hud_ui.s | XOR input state toggle |
| 5 | FUN_060104E0 | 0x060104E0 | 0x280 = 640B | Yes | hud_ui.s | Multi-state animation handler |
| 6 | FUN_06010760 | 0x06010760 | 0x234 = 564B | Yes | hud_ui.s | Advanced animation state machine |
| 7 | FUN_06010994 | 0x06010994 | 0x110 = 272B | Yes | hud_ui.s | HUD coordinate calculator |
| 8 | FUN_06010AA4 | 0x06010AA4 | 0xB0 = 176B | Yes | hud_ui.s | Post-update processing |
| 9 | FUN_06010B54 | 0x06010B54 | 0x70 = 112B | Yes | hud_ui.s | Helper |
| 10 | FUN_06010BC4 | 0x06010BC4 | 0x1D0 = 464B | Yes | hud_ui.s | Graphics mode setup |
| 11 | FUN_06010D94 | 0x06010D94 | 0x170 = 368B | Yes | hud_ui.s | VDP mode selection |
| 12 | FUN_06010F04 | 0x06010F04 | 0x190 = 400B | No | hud_ui.s | Rendering helper (no C) |
| 13 | FUN_06011094 | 0x06011094 | 0x14E = 334B | Yes | hud_ui.s | Course-specific HUD rendering |
| 14 | FUN_060111E2 | 0x060111E2 | 0x12E = 302B | Yes | hud_ui.s | Lap progress indicator |
| 15 | FUN_06011310 | 0x06011310 | 0x12E = 302B | Yes | hud_ui.s | Position/ranking display |
| 16 | FUN_060114AC | 0x060114AC | 0x0C = 12B | Yes | hud_ui.s | Animated UI transition entry |
| 17 | FUN_060114B8 | 0x060114B8 | 0xA6 = 166B | No | hud_ui.s | UI helper (continuation of 114AC) |
| 18 | FUN_0601155E | 0x0601155E | 0x92 = 146B | Yes | hud_ui.s | Sprite batch renderer |
| 19 | FUN_060115F0 | 0x060115F0 | 0x88 = 136B | No | hud_ui.s | Rendering helper (no C) |
| 20 | FUN_06011678 | 0x06011678 | 0x30 = 48B | Yes | hud_ui.s | 3D sprite rendering |
| 21 | FUN_060116A8 | 0x060116A8 | 0x14 = 20B | Yes | hud_ui.s | 3D object rendering entry |
| 22 | FUN_060116BC | 0x060116BC | 0x2BC = 700B | No | hud_ui.s | 3D object rendering body (no C) |
| 23 | FUN_06011978 | 0x06011978 | 0x14 = 20B | Yes | hud_ui.s | 3D vertex transform entry |
| 24 | FUN_0601198C | 0x0601198C | 0x168 = 360B | No | hud_ui.s | 3D vertex transform body (no C) |
| 25 | FUN_06011AF4 | 0x06011AF4 | 0x14 = 20B | Yes | hud_ui.s | Full 3D rigid-body transform entry (CRITICAL) |
| 26 | FUN_06011B08 | 0x06011B08 | 0x2B8 = 696B | No | hud_ui.s | 3D rigid-body transform body (no C) |
| 27 | FUN_06011DC0 | 0x06011DC0 | 0xBC = 188B | Yes | hud_ui.s | Sprite animation frame cycling |
| 28 | FUN_06011E7C | 0x06011E7C | 0x116 = 278B | Yes | hud_ui.s | HUD element |
| 29 | FUN_06011F92 | 0x06011F92 | 0xBE = 190B | Yes | hud_ui.s | Throttle/brake analog input |

**Summary**: 29 functions. 23 have C source. All 29 documented in hud_ui.s. 6 without C are entry/body pairs (the "entry" has C, the "body" is the fall-through continuation). Zero gap.

---

## RANGE 5: 0x06012xxx-0x06013xxx (40 functions)

| # | Function | Addr | Size | Has C | ASM Doc | Category |
|---|----------|------|------|-------|---------|----------|
| 1 | FUN_06012050 | 0x06012050 | 0x04 = 4B | Yes | hud_ui.s | Sound init #1 entry (race music) |
| 2 | FUN_06012054 | 0x06012054 | 0x2C = 44B | No | -- | Sound init #1 body. Fall-through from 12050. |
| 3 | FUN_06012080 | 0x06012080 | 0x04 = 4B | Yes | hud_ui.s | Sound init #2 entry (bonus race) |
| 4 | FUN_06012084 | 0x06012084 | 0x1C = 28B | No | -- | Sound init #2 body. Fall-through from 12080. |
| 5 | FUN_060120A0 | 0x060120A0 | 0x28 = 40B | Yes | hud_ui.s | Sound init #3 (menu audio) |
| 6 | FUN_060120C8 | 0x060120C8 | 0x04 = 4B | Yes | hud_ui.s | Race start init entry |
| 7 | FUN_060120CC | 0x060120CC | 0xDC = 220B | No | -- | Race start init body. Fall-through from 120C8. |
| 8 | FUN_060121A8 | 0x060121A8 | 0xE4 = 228B | Yes | hud_ui.s | Race cleanup A |
| 9 | FUN_0601228C | 0x0601228C | 0xB8 = 184B | Yes | hud_ui.s | Lap progress state machine (PRIMARY LAP TIMER) |
| 10 | FUN_06012344 | 0x06012344 | 0xBC = 188B | Yes | -- | Register-optimized function |
| 11 | FUN_06012400 | 0x06012400 | 0x50 = 80B | Yes | -- | Helper |
| 12 | FUN_06012450 | 0x06012450 | 0x04 = 4B | Yes | -- | Helper entry |
| 13 | FUN_06012454 | 0x06012454 | 0xB8 = 184B | No | -- | Helper body. Fall-through from 12450. |
| 14 | FUN_0601250C | 0x0601250C | 0xC4 = 196B | Yes | hud_ui.s | Graphics update |
| 15 | FUN_060125D0 | 0x060125D0 | 0x140 = 320B | Yes | hud_ui.s | Lap display update (20-frame sequence) |
| 16 | FUN_06012710 | 0x06012710 | 0xD0 = 208B | Yes | hud_ui.s | Race finish/progress check (60-frame timeout) |
| 17 | FUN_060127E0 | 0x060127E0 | 0x2E4 = 740B | Yes | hud_ui.s | Menu logic |
| 18 | FUN_06012AC4 | 0x06012AC4 | 0x36 = 54B | No | vblank_system.s (ref) | **CD DMA setup**: pushes r12-r14, loads 0x0605ACDD (CD status byte), calls FUN_060283E0 (DMA), uses 0xF000 mask. Configures CD data DMA transfer. |
| 19 | FUN_06012AFA | 0x06012AFA | 0x5E = 94B | No | -- | **CD status check**: reads 0x060788FC (CD controller flags), tests bit 0x04. If set: configures DMA from 0x06063800 with size from pool. Helper for CD data loading. |
| 20 | FUN_06012B58 | 0x06012B58 | 0x84 = 132B | Yes | vblank_system.s (ref) | CD data loader |
| 21 | FUN_06012BDC | 0x06012BDC | 0x08 = 8B | Yes | -- | Helper |
| 22 | FUN_06012BE4 | 0x06012BE4 | 0x58 = 88B | No | -- | Paired helper body |
| 23 | FUN_06012C3C | 0x06012C3C | 0xB8 = 184B | Yes | -- | Helper |
| 24 | FUN_06012CF4 | 0x06012CF4 | 0x88 = 136B | Yes | -- | Register-optimized |
| 25 | FUN_06012D7C | 0x06012D7C | 0x38 = 56B | Yes | -- | Helper |
| 26 | FUN_06012DB4 | 0x06012DB4 | 0x54 = 84B | Yes | -- | Helper |
| 27 | FUN_06012E08 | 0x06012E08 | 0x62 = 98B | Yes | -- | Sound data helper |
| 28 | FUN_06012E6A | 0x06012E6A | 0x116 = 278B | Yes | -- | Sound data helper |
| 29 | FUN_06012F80 | 0x06012F80 | 0x91E = 2334B | Yes | hud_ui.s | **Master game initialization** (CRITICAL) |
| 30 | FUN_0601389E | 0x0601389E | 0x20 = 32B | Yes | hud_ui.s | Graphics frame dispatch |
| 31 | FUN_060138BE | 0x060138BE | 0x8A = 138B | No | -- | **3D transform + frame commit**: pushes 0x8000 to stack, calls FUN_06011AF4 (3D rigid-body transform) with arg from r2, tail-calls FUN_060078DC (frame commit). Rendering finalization helper. |
| 32 | FUN_06013948 | 0x06013948 | 0x12C = 300B | No | -- | **VDP2 scroll plane renderer**: pushes r8-r14+macl, stack -8. Loads FUN_06026E2E (VDP2 write), accesses 0x06084AF4 (scroll data table), 0x06084FB4. Complex loop with mul.l and field reads. Configures VDP2 background planes. |
| 33 | FUN_06013A74 | 0x06013A74 | 0x90 = 144B | No | -- | **Per-frame subsystem dispatcher**: calls 5 functions in sequence: FUN_06014360, FUN_0601416C, FUN_0601424C, FUN_060140C4, FUN_0601444C. Reads button state at 0x06063D9E. Orchestrator for per-frame HUD/subsystem updates. |
| 34 | FUN_06013B04 | 0x06013B04 | 0x11C = 284B | No | -- | **Sound + 3D rendering loop**: pushes r8-r11, loads FUN_0601D5F4 (sound trigger), 0x06084FB4 (sound table), 0x06084AF6 (counter). Increments counter, calls FUN_06013E3C (3D object loop). Frame-synchronized sound + render update. |
| 35 | FUN_06013C20 | 0x06013C20 | 0x38 = 56B | No | -- | **Counter clamp + VDP update**: reads counter at 0x06084AF6, clamps to max 20, writes back. Calls FUN_06026E86 (VDP2 register write). Frame counter management. |
| 36 | FUN_06013C58 | 0x06013C58 | 0x1BC = 444B | Yes | hud_ui.s | Lap time display renderer |
| 37 | FUN_06013E14 | 0x06013E14 | 0x28 = 40B | No | -- | **Camera FOV offset**: reads 0x0607EBC8, ANDs with 0x1F, sign-extends. Compares against r2 threshold. If greater: shll8+shll2+shll2 = multiply by 4096, calls FUN_06026EDE (VDP2). Camera zoom/FOV helper. |
| 38 | FUN_06013E3C | 0x06013E3C | 0x3E = 62B | Yes | hud_ui.s | 3D object rendering loop entry |
| 39 | FUN_06013E7A | 0x06013E7A | 0x14A = 330B | No | -- | **3D object rendering loop body**: uses r13 as counter pointer, r14 as multiplier, r11 as function pointer (jsr @r11). mul.l for stride calc, calls FUN_06026E2E (VDP2). Iterates 3D objects for background rendering. Fall-through from 13E3C. |
| 40 | FUN_06013FC4 | 0x06013FC4 | 0xBC = 188B | Yes | hud_ui.s | Simplified 3D object loop (background) |

**Summary**: 40 functions. 31 have C source. 10 documented in hud_ui.s/vblank_system.s. 9 without C or asm doc are: fall-through bodies (12054, 12084, 120CC, 12454, 12BE4, 13E7A), CD helpers (12AC4, 12AFA), and subsystem dispatchers (138BE, 13948, 13A74, 13B04, 13C20, 13E14). All now categorized above.

---

## RANGE 6: 0x06038xxx-0x06039xxx (23 functions) -- Game Logic Integration

Documented in menu_display.s (section "GAME LOGIC INTEGRATION"), vblank_system.s, vdp_hardware.s.

| # | Function | Addr | Size | Has C | ASM Doc | Category |
|---|----------|------|------|-------|---------|----------|
| 1 | FUN_0603806C | 0x0603806C | 0xB4 = 180B | Yes | menu_display.s | Game logic entry point |
| 2 | FUN_06038120 | 0x06038120 | 0x1E0 = 480B | Yes | menu_display.s | Course-specific state handler |
| 3 | FUN_06038300 | 0x06038300 | 0x6C = 108B | Yes | vblank_system.s | Game logic integrator / display init |
| 4 | FUN_0603836C | 0x0603836C | 0x1D0 = 464B | No | vdp_hardware.s | **VDP2 register configuration**: secondary register config for scroll planes, documented as VDP2 setup |
| 5 | FUN_0603853C | 0x0603853C | 0x106 = 262B | Yes | scene_camera.s | Set position (game state) |
| 6 | FUN_06038642 | 0x06038642 | 0x152 = 338B | Yes | menu_display.s | State machine |
| 7 | FUN_06038794 | 0x06038794 | 0x12C = 300B | Yes | menu_display.s | Game state update |
| 8 | FUN_060388C0 | 0x060388C0 | 0xE6 = 230B | Yes | -- | State handler |
| 9 | FUN_060389A6 | 0x060389A6 | 0x122 = 290B | Yes | vblank_system.s | SMPC INTBACK trigger / peripheral poll |
| 10 | FUN_06038AC8 | 0x06038AC8 | 0x10C = 268B | Yes | -- | State handler |
| 11 | FUN_06038BD4 | 0x06038BD4 | 0x280 = 640B | Yes | menu_display.s / scene_camera.s | Complex state integration / display list setup |
| 12 | FUN_06038E54 | 0x06038E54 | 0x118 = 280B | Yes | -- | Display list command setup |
| 13 | FUN_06038F6C | 0x06038F6C | 0x0C = 12B | LEAF | No | -- | Small stub (likely returns constant) |
| 14 | FUN_06038F78 | 0x06038F78 | 0xD8 = 216B | No | vdp_hardware.s | VDP1 display list command |
| 15 | FUN_06039050 | 0x06039050 | 0xB0 = 176B | No | vdp_hardware.s | VDP1 display list command |
| 16 | FUN_06039100 | 0x06039100 | 0x150 = 336B | Yes | -- | Rendering state handler |
| 17 | FUN_06039250 | 0x06039250 | 0xCC = 204B | Yes | vdp_hardware.s | Polygon setup |
| 18 | FUN_0603931C | 0x0603931C | 0x1F0 = 496B | Yes | vdp_hardware.s | VDP1 polygon type/param setup |
| 19 | FUN_0603950C | 0x0603950C | 0x2FC = 764B | Yes | menu_display.s | Major game logic handler |
| 20 | FUN_06039808 | 0x06039808 | 0x106 = 262B | Yes | -- | State handler |
| 21 | FUN_0603990E | 0x0603990E | 0x70E = 1806B | No | -- | **SMPC INTBACK response handler**: pushes r8-r14, stack -4. Reads SMPC peripheral port at 0x20100061, accesses 0x060A4CF4/0x060A4D04/0x060A4CEC/0x060A4CC0 (peripheral data). Reads SR register (stc sr), masks interrupt bits. Reads 0x060A4CAA (controller state byte). Very large -- processes full SMPC INTBACK multi-byte response for all peripherals. Documented in input_smpc.s as "INTBACK Response Handler at 0x06039924, inside FUN_0603953C". |
| 22 | FUN_0603A01C | 0x0603A01C | 0x94 = 148B | Yes | -- | Game logic helper |
| 23 | FUN_0603A0B0 | 0x0603A0B0 | 0x6B6 = 1718B | Yes | menu_display.s / render_pipeline.s | Large game logic handler |

**Summary**: 23 functions. 17 have C source. Multiple documented across menu_display.s, vblank_system.s, vdp_hardware.s, scene_camera.s, input_smpc.s. 3 undocumented: 38F6C (tiny stub), 38F78/39050 (partially documented in vdp_hardware.s), 3990E (SMPC handler, now categorized).

---

## RANGE 7: 0x0603Axxx-0x0603Bxxx (55 functions) -- Object/Entity System

Dense cluster of entity management functions. Most access the entity pool at 0x060A4D14 via pointer dereference, and call FUN_0603B93C (error handler) and FUN_0603B8B4/B8F4 (validators).

| # | Function | Addr | Size | Has C | ASM Doc | Category |
|---|----------|------|------|-------|---------|----------|
| 1 | FUN_0603A766 | 0x0603A766 | 0x4A = 74B | Yes | -- | Entity iteration loop |
| 2 | FUN_0603A7B0 | 0x0603A7B0 | 0x2D2 = 722B | Yes | -- | Entity processor (mul.l stride, 060A4CC0 base) |
| 3 | FUN_0603AA82 | 0x0603AA82 | 0x19A = 410B | No | -- | **Entity field fill**: reads 060A4CAE (count), 060A4CC8 (base). Byte fill loop over entity array. Array initialization/clear. |
| 4 | FUN_0603AC1C | 0x0603AC1C | 0xCE = 206B | Yes | -- | Entity slot allocator (bounds 1-24) |
| 5 | FUN_0603ACEA | 0x0603ACEA | 0xC2 = 194B | Yes | -- | Entity setup (060A4D14 pool, calls F238+B93C) |
| 6 | FUN_0603ADAC | 0x0603ADAC | 0x5C = 92B | Yes | -- | Entity validator |
| 7 | FUN_0603AE08 | 0x0603AE08 | 0x6C = 108B | Yes | -- | Entity state update |
| 8 | FUN_0603AE74 | 0x0603AE74 | 0x74 = 116B | No | -- | **Entity field accessor**: loads 060A4D14 pool, reads offset via r0+r3 indirect. Validates and returns field value. |
| 9 | FUN_0603AEE8 | 0x0603AEE8 | 0xAC = 172B | Yes | -- | Entity processor |
| 10 | FUN_0603AF94 | 0x0603AF94 | 0x3C = 60B | Yes | -- | Entity helper |
| 11 | FUN_0603AFD0 | 0x0603AFD0 | 0x0C = 12B | LEAF | Yes | Tiny entity return (3 insns) |
| 12 | FUN_0603AFDC | 0x0603AFDC | 0x7C = 124B | No | -- | **Entity indirect accessor**: loads 060A4D14 pool, reads r0+r13 indirect byte, extu.b, shll2 x2 (multiply by 16). Computes entity slot offset. |
| 13 | FUN_0603B058 | 0x0603B058 | 0x36 = 54B | Yes | -- | Entity state check |
| 14 | FUN_0603B08E | 0x0603B08E | 0x32 = 50B | No | -- | **Entity validate+clear**: calls B058 (state check), saves result. Calls B93C with r4=0 (reset). Reads entity[0] and saved result, returns. |
| 15 | FUN_0603B0C0 | 0x0603B0C0 | 0x58 = 88B | No | -- | **Entity deref+validate**: loads entity ptr from *param, reads byte at r0+entity offset, extu.b. Calls B93C (error). Reads entity[+4], conditionally processes. |
| 16 | FUN_0603B118 | 0x0603B118 | 0x04 = 4B | LEAF | No | **Fall-through entry**: `mov.l r14,@-r15; mov #0,r14` -- sets r14=0 then falls into B11C. |
| 17 | FUN_0603B11C | 0x0603B11C | 0x14 = 20B | CALL | No | **Entity call wrapper**: sts.l pr, stack -20, saves r4-r7 to stack, sets r5=r14, r6=r14. Falls into B130. |
| 18 | FUN_0603B130 | 0x0603B130 | 0x38 = 56B | No | -- | **Entity multi-arg call**: pushes stack args from caller's frame, calls BE9C (entity dispatch) with args from stack. Stack cleanup, flag test 0x08, conditional return. |
| 19 | FUN_0603B168 | 0x0603B168 | 0x4E = 78B | No | -- | **Entity call variant**: sts.l pr, stack -20, saves r4/r6/r7. Sets r7=0 (no flags). Pushes stack args. Falls into B130-like dispatch path. |
| 20 | FUN_0603B1B6 | 0x0603B1B6 | 0x66 = 102B | Yes | -- | Entity field setter |
| 21 | FUN_0603B21C | 0x0603B21C | 0x74 = 116B | Yes | -- | Entity field accessor |
| 22 | FUN_0603B290 | 0x0603B290 | 0x8C = 140B | No | -- | **Entity conditional processor**: pushes r8/r13/r14, stack -12. Saves r5-r7 to stack. Reads byte at r0+r14 (entity flag), extu.b, tst. Conditional processing based on entity state flags. |
| 23 | FUN_0603B31C | 0x0603B31C | 0x08 = 8B | LEAF | Yes | Tiny entity accessor (2 insns + rts) |
| 24 | FUN_0603B324 | 0x0603B324 | 0x6E = 110B | No | -- | **Entity validate+dispatch**: sts.l pr, reads r0+r14 byte, extu.b, tst. If zero: calls B93C with r4=-16. Restores r8+r15, branches to B93C. Validation with error dispatch. |
| 25 | FUN_0603B392 | 0x0603B392 | 0x38 = 56B | No | -- | **Entity reset+check**: calls B93C(r4=0), reads entity byte at offset +18, extu.b, tst. Conditional branch. Entity state reset with post-check. |
| 26 | FUN_0603B3CA | 0x0603B3CA | 0x06 = 6B | LEAF | No | **Fall-through entry**: pushes r14/r13, sets r14=r4. Falls into B3D0. |
| 27 | FUN_0603B3D0 | 0x0603B3D0 | 0x54 = 84B | No | -- | **Entity multi-step process**: writes r3 at r0+r14 (entity field set). Calls B9D6 (state updater), B8B4 (validator), B8F4 (validator), B058 (state check) in sequence. Comprehensive entity state transition. |
| 28 | FUN_0603B3FE | 0x0603B3FE | 0x26 = 38B | No | -- | **Entity field set+validate**: calls B93C(r4=0), writes r3 to entity[+8]. Calls B8B4 (validator). Small field setter with validation. |
| 29 | FUN_0603B424 | 0x0603B424 | 0x118 = 280B | Yes | -- | Entity major processor |
| 30 | FUN_0603B53C | 0x0603B53C | 0x5C = 92B | No | -- | **Entity offset reader**: pushes r11-r14. Loads 060A4D14 pool, deref, adds #52. Reads via r0+r13 indirect (offset 52+ field). Entity table field accessor. |
| 31 | FUN_0603B598 | 0x0603B598 | 0x38 = 56B | No | -- | **Entity flag check**: reads entity[0] via *r4, accesses byte at +29 (offset r1=29), extu.b. Tests bit 0x60. Conditional entity state check. |
| 32 | FUN_0603B5D0 | 0x0603B5D0 | 0x22 = 34B | No | -- | **Entity field+call**: writes r5 to entity[+0xC], calls FUN_0603F970 with entity[+8] as arg. Entity field setter with callback. |
| 33 | FUN_0603B5F2 | 0x0603B5F2 | 0x1A = 26B | No | -- | **Entity swap field**: reads entity[+0x28], saves to stack. Writes r5 to entity[+0x28]. Calls B93C(r4=0). Returns old value. Atomic-like field swap. |
| 34 | FUN_0603B60C | 0x0603B60C | 0x24 = 36B | No | -- | **Entity call+validate**: saves r4 to stack. Calls FUN_0603F9FA with entity[+8]. Saves result. Calls B93C(r4=0). Returns result. Entity query with validation. |
| 35 | FUN_0603B630 | 0x0603B630 | 0x04 = 4B | LEAF | No | **Fall-through entry**: pushes r14, sets r1=29. Falls into B634. |
| 36 | FUN_0603B634 | 0x0603B634 | 0x4C = 76B | No | -- | **Entity flag check+process**: reads entity[0] via *r4, accesses byte at +29, extu.b. Tests bit 0x60. If set: calls B058 (state check), reads entity[0] byte at r0 offset, conditional update. |
| 37 | FUN_0603B680 | 0x0603B680 | 0x28 = 40B | No | -- | **Entity external call**: reads 060A4D14 pool, adds large offset (from pool constant). Calls FUN_06035168 with r0=12, r1=entity. External validator dispatch. |
| 38 | FUN_0603B6A8 | 0x0603B6A8 | 0xA4 = 164B | No | -- | **Entity field read+dispatch**: loads 060A4D14 pool, reads offset via r0+r3. Tests null. Multiple reads of entity fields, conditional calls to B93C. Multi-field entity reader with validation. |
| 39 | FUN_0603B74C | 0x0603B74C | 0x74 = 116B | Yes | -- | Entity field setter |
| 40 | FUN_0603B7C0 | 0x0603B7C0 | 0xF4 = 244B | Yes | -- | Entity major processor |
| 41 | FUN_0603B8B4 | 0x0603B8B4 | 0x78 = 120B | Yes | -- | Entity validator |
| 42 | FUN_0603B92C | 0x0603B92C | 0x10 = 16B | No | -- | **Entity dual-validate**: calls B8B4 (validator), then tail-branches to B8F4 (second validator). Convenience wrapper. |
| 43 | FUN_0603B93C | 0x0603B93C | 0x68 = 104B | Yes | -- | Entity error handler |
| 44 | FUN_0603B9A4 | 0x0603B9A4 | 0x32 = 50B | Yes | -- | Entity helper |
| 45 | FUN_0603B9D6 | 0x0603B9D6 | 0x56 = 86B | Yes | -- | Entity state updater |
| 46 | FUN_0603BA2C | 0x0603BA2C | 0x9A = 154B | Yes | -- | Entity processor |
| 47 | FUN_0603BAC6 | 0x0603BAC6 | 0xC0 = 192B | Yes | -- | Entity processor |
| 48 | FUN_0603BB86 | 0x0603BB86 | 0x8C = 140B | Yes | -- | Entity validator |
| 49 | FUN_0603BC12 | 0x0603BC12 | 0x74 = 116B | Yes | -- | Entity field setter |
| 50 | FUN_0603BC86 | 0x0603BC86 | 0x96 = 150B | Yes | -- | Entity processor |
| 51 | FUN_0603BD1C | 0x0603BD1C | 0x90 = 144B | Yes | -- | Entity processor |
| 52 | FUN_0603BDAC | 0x0603BDAC | 0xF0 = 240B | Yes | -- | Entity major processor |
| 53 | FUN_0603BE9C | 0x0603BE9C | 0x1C = 28B | No | -- | **Entity dispatch entry**: pushes r11-r14. Reads 5 args from stack (offsets +0x14 through +0x20). Falls into BEB8. |
| 54 | FUN_0603BEB8 | 0x0603BEB8 | 0x6A = 106B | No | -- | **Entity dispatch body**: calls FUN_06040220 (data extraction). Null-checks r5. If non-null: loop with entity byte read, multiplied offset, conditional branches. Entity dispatch with external validation. |
| 55 | FUN_0603BF22 | 0x0603BF22 | 0x1E2 = 482B | Yes | -- | Entity large processor |

**Summary**: 55 functions. 29 have C source. None individually documented in asm/*.s (bulk-referenced in menu_display.s as "59 additional state handlers"). 26 without C source are entity management helpers -- all now categorized above. The entire subsystem revolves around the entity pool at 0x060A4D14 with slot size 16 bytes, max 24 slots.

---

## RANGE 8: 0x0603Cxxx-0x0603Dxxx (19 functions)

### Menu/Display System (0x0603C104-0x0603CD5C)

| # | Function | Addr | Size | Has C | ASM Doc | Category |
|---|----------|------|------|-------|---------|----------|
| 1 | FUN_0603C104 | 0x0603C104 | 0x08 = 8B | Yes | menu_display.s | Display helper stub |
| 2 | FUN_0603C10C | 0x0603C10C | 0x9C = 156B | No | -- | **Display init dispatcher**: loads 0x060A4D60 (display config), calls FUN_0603CD5C (display orchestrator) with r14=0, then calls FUN_0603D2CC and FUN_0603D3A8 (data table configs). Display mode initialization. |
| 3 | FUN_0603C1A8 | 0x0603C1A8 | 0x580 = 1408B | Yes | menu_display.s | Menu screen renderer (LARGE) |
| 4 | FUN_0603C728 | 0x0603C728 | 0x560 = 1376B | Yes | menu_display.s | Extended display system (LARGE) |
| 5 | FUN_0603CC88 | 0x0603CC88 | 0xD4 = 212B | Yes | -- | Display helper |
| 6 | FUN_0603CD5C | 0x0603CD5C | 0x570 = 1392B | Yes | menu_display.s | Display orchestrator (LARGE) |

### Data Table Accessors (0x0603D2CC-0x0603DDFC)

| # | Function | Addr | Size | Has C | ASM Doc | Category |
|---|----------|------|------|-------|---------|----------|
| 7 | FUN_0603D2CC | 0x0603D2CC | 0x04 = 4B | Yes | -- | Data table entry wrapper (falls into D2D0) |
| 8 | FUN_0603D2D0 | 0x0603D2D0 | 0xD8 = 216B | (via D2CC) | -- | Data table config (3-field mask/set) |
| 9 | FUN_0603D3A8 | 0x0603D3A8 | 0x90 = 144B | Yes | -- | Data table config variant |
| 10 | FUN_0603D438 | 0x0603D438 | 0x04 = 4B | Yes | -- | Data table entry wrapper (falls into D43C) |
| 11 | FUN_0603D43C | 0x0603D43C | 0xD8 = 216B | (via D438) | -- | Data table config (3-field mask/set) |
| 12 | FUN_0603D514 | 0x0603D514 | 0x04 = 4B | Yes | -- | Data table entry wrapper (falls into D518) |
| 13 | FUN_0603D518 | 0x0603D518 | 0xB8 = 184B | (via D514) | -- | Data table config variant |
| 14 | FUN_0603D5D0 | 0x0603D5D0 | 0x1E0 = 480B | Yes | -- | Data table large processor |
| 15 | FUN_0603D7B0 | 0x0603D7B0 | 0x23C = 572B | No | -- | **Data table multi-field config**: pushes r12-r14. Loads 0xFFFE mask from pool, accesses 0x060A4D58 and 0x060A4D18 (parameter tables). Calls FUN_06034F78 (table lookup) repeatedly. Reads/masks/writes 16-bit fields at table+2. Multi-pass parameter configuration with 0xFEFF/0xFFFE masks. Complex table configurator. |
| 16 | FUN_0603D9EC | 0x0603D9EC | 0x9C = 156B | Yes | -- | Data table accessor |
| 17 | FUN_0603DA88 | 0x0603DA88 | 0xA0 = 160B | Yes | -- | Data table accessor |
| 18 | FUN_0603DB28 | 0x0603DB28 | 0x2D4 = 724B | No | -- | **Data table multi-mode processor**: pushes r8-r14, stack -12. Accesses 0x060A4C80 (data pool). Checks r6 for mode (0/1/0xFFFF). Checks r7 (==1 condition). Multiple conditional branches. Reads 0x060A4D14 pool, calls FUN_06034C68, FUN_060349B6. Large multi-mode data table handler with 3-way dispatch. |
| 19 | FUN_0603DDFC | 0x0603DDFC | 0x254 = 596B | Yes | render_pipeline.s | **Master game state machine** (LARGEST FUNCTION IN BINARY -- actually 2910B total including continuation). Orchestrates all subsystems per frame. |

**Summary**: 19 functions. 14 have C source. 2 documented in asm/*.s (menu_display.s, render_pipeline.s). 3 undocumented (C10C, D7B0, DB28), all now categorized.

---

## RANGE 9: 0x0603Exxx (7 functions) -- 3D Rendering / Scene Processing

| # | Function | Addr | Size | Has C | ASM Doc | Category |
|---|----------|------|------|-------|---------|----------|
| 1 | FUN_0603E050 | 0x0603E050 | 0x56C = 1388B | No | -- | **3D scene renderer pass A**: pushes r8-r14+macl, stack -56. Loads 0x00040000 mask, 0x00008000 flag, FUN_0603C0A0 callback, 0x060A3E38 (scene object pool), 0x060635A8 (display mode). 3-way mode dispatch (mode==1, mode==2, else). Iterates object array with 0xFF00 mask, sets field +4 flags (OR 0x03 or complex mask). Multi-pass 3D scene rendering. |
| 2 | FUN_0603E5BC | 0x0603E5BC | 0x510 = 1296B | No | -- | **3D scene renderer pass B**: nearly identical structure to E050. Pushes r8-r14+macl, stack -52. Same pools (0x060A3E38, 0x060635A8, 0x0603C0A0). Same 3-way mode dispatch. Uses r12 = r9+1 (offset). Second rendering pass or alternate LOD. |
| 3 | FUN_0603EACC | 0x0603EACC | 0x174 = 372B | Yes | -- | Scene renderer with 3-way mode dispatch |
| 4 | FUN_0603EC40 | 0x0603EC40 | 0x324 = 804B | Yes | -- | Scene object processor (0x060A4C70 pool) |
| 5 | FUN_0603EF64 | 0x0603EF64 | 0x98 = 152B | Yes | -- | Distance/depth calculator (shlr8+shlr2+shlr1 = div 2048) |
| 6 | FUN_0603F0FC | 0x0603F0FC | 0x4C = 76B | Yes | -- | Scene helper |
| 7 | FUN_0603F148 | 0x0603F148 | 0xF0 = 240B | Yes | -- | Scene object setup |

**Summary**: 7 functions. 5 have C source. 2 undocumented large renderers (E050, E5BC), now categorized. These are the two largest unmapped functions in the entire analysis.

---

## RANGE 10: 0x0603Fxxx (32 functions) -- Entity/Game State System

| # | Function | Addr | Size | Has C | ASM Doc | Category |
|---|----------|------|------|-------|---------|----------|
| 1 | FUN_0603F238 | 0x0603F238 | 0x0C = 12B | No | -- | **Entity allocator entry**: pushes r10-r14, sets r10=r4. Falls into F244. |
| 2 | FUN_0603F244 | 0x0603F244 | 0x9C = 156B | No | -- | **Entity allocator body**: loads FUN_06041698, FUN_06041470, 0x060A4D14 pool. Calls allocators, checks result -5 (error). Entity slot allocation with external validation. |
| 3 | FUN_0603F2E0 | 0x0603F2E0 | 0x0C = 12B | Yes | -- | Helper entry |
| 4 | FUN_0603F2EC | 0x0603F2EC | 0x56 = 86B | No | -- | **Entity bulk init**: stack -56. Calls FUN_0603F3DA (init template). Loops over r13 count, calls allocators. Entity array initialization. |
| 5 | FUN_0603F342 | 0x0603F342 | 0x12 = 18B | Yes | -- | Helper |
| 6 | FUN_0603F354 | 0x0603F354 | 0xA2 = 162B | No | -- | **Entity bulk init variant**: stack -56, loads FUN_06036DDC (validator). Same pattern as F2EC but with external validation call per iteration. |
| 7 | FUN_0603F3F6 | 0x0603F3F6 | 0xBA = 186B | Yes | -- | Entity processor |
| 8 | FUN_0603F4B0 | 0x0603F4B0 | 0x1C = 28B | Yes | -- | Helper |
| 9 | FUN_0603F4CC | 0x0603F4CC | 0x14 = 20B | Yes | -- | Helper |
| 10 | FUN_0603F4E0 | 0x0603F4E0 | 0x20 = 32B | Yes | -- | Helper |
| 11 | FUN_0603F500 | 0x0603F500 | 0x20 = 32B | Yes | -- | Helper |
| 12 | FUN_0603F520 | 0x0603F520 | 0x14 = 20B | Yes | -- | Helper |
| 13 | FUN_0603F534 | 0x0603F534 | 0x04 = 4B | Yes | -- | Tiny entry (falls into F538) |
| 14 | FUN_0603F538 | 0x0603F538 | 0x4A = 74B | Yes | -- | Entity field setter |
| 15 | FUN_0603F582 | 0x0603F582 | 0x3B2 = 946B | Yes | -- | Entity large processor |
| 16 | FUN_0603F93C | 0x0603F93C | 0x0C = 12B | Yes | -- | Helper |
| 17 | FUN_0603F948 | 0x0603F948 | 0x28 = 40B | No | -- | **Entity struct zero-fill**: stores r13 (zero) to 7 fields at r14[0..0x18], writes r3 to r14[+0x10]. Calls FUN_0603F970 with r4=r14. Fast entity struct initializer. |
| 18 | FUN_0603F970 | 0x0603F970 | 0x04 = 4B | Yes | -- | Tiny entry |
| 19 | FUN_0603F974 | 0x0603F974 | 0x44 = 68B | No | -- | **Entity field config**: reads byte at r0+r4, writes r14 (signed) to byte at offset +53 of r4. Checks r14 sign (cmp/pz). Conditional paths. Entity configuration with signed field update. |
| 20 | FUN_0603F9B8 | 0x0603F9B8 | 0x04 = 4B | Yes | -- | Tiny entry |
| 21 | FUN_0603F9BC | 0x0603F9BC | 0x5E = 94B | No | -- | **Entity call+restore**: calls FUN_0603FA1A with r5=-1 and r4=r14. Reads saved values from stack, writes to r14[0], r14 entity field. Entity restore after operation. |
| 22 | FUN_0603FA1A | 0x0603FA1A | 0xB4 = 180B | Yes | -- | Entity helper |
| 23 | FUN_0603FACE | 0x0603FACE | 0x16 = 22B | Yes | -- | Helper |
| 24 | FUN_0603FAE4 | 0x0603FAE4 | 0x17C = 380B | No | -- | **Entity traverse+process**: reads r14[0] (head), r14[+0x14] compare against r11. Reads r14[+8] (r9). Uses r13 as pool constant. Loop traversal with boundary checks. Large entity linked-list traversal or array scan. |
| 25 | FUN_0603FC60 | 0x0603FC60 | 0x84 = 132B | Yes | -- | Entity processor |
| 26 | FUN_0603FCE4 | 0x0603FCE4 | 0x5C = 92B | Yes | -- | Entity processor |
| 27 | FUN_0603FD40 | 0x0603FD40 | 0x104 = 260B | Yes | -- | Entity processor |
| 28 | FUN_0603FE44 | 0x0603FE44 | 0x1E = 30B | No | -- | **DMA wrapper A**: pushes stack args, calls FUN_0603FD40 with r4=0. Stack cleanup. Thin wrapper. |
| 29 | FUN_0603FE62 | 0x0603FE62 | 0x1E = 30B | No | -- | **DMA wrapper B**: identical to FE44 but calls FUN_0603FD40 with r4=1. Thin wrapper. |
| 30 | FUN_0603FE80 | 0x0603FE80 | 0xBA = 186B | No | vdp_hardware.s | **Runtime DMA handler**: pushes r13/r14, stack -16. Accesses 0x25FE00A4 (SCU DMA controller status), 0x06000348. Reads/writes SCU DMA registers. Waits for DMA completion. Hardware DMA transfer. |
| 31 | FUN_0603FF3A | 0x0603FF3A | 0x62 = 98B | No | -- | **Entity conditional copy**: tests r5 (null check). If non-null: conditional byte compare at r0+r5. Uses r13, r14 as loop vars. Entity data copy with validation. |
| 32 | FUN_0603FF9C | 0x0603FF9C | 0x70 = 112B | Yes | -- | Entity processor |

**Summary**: 32 functions. 22 have C source. 1 documented in vdp_hardware.s (FE80). 9 undocumented (F238, F244, F2EC, F354, F948, F974, F9BC, FAE4, FE44, FE62, FF3A), all now categorized.

---

## RANGE 11: 0x06040xxx-0x06046xxx (71 functions) -- Event Queue System

All documented in event_queue.s. 70 functions in 0x0604_xxxx plus FUN_06046E48.

| # | Function | Addr | Size | Has C | ASM Doc | Category |
|---|----------|------|------|-------|---------|----------|
| 1 | FUN_0604000C | 0x0604000C | 0x04 = 4B | Yes | event_queue.s | Error code return stub |
| 2 | FUN_06040010 | 0x06040010 | 0xC6 = 198B | No | event_queue.s | Validation dispatcher (17+ branches) |
| 3 | FUN_060400D6 | 0x060400D6 | 0x122 = 290B | Yes | event_queue.s | Object initialization |
| 4 | FUN_060401F8 | 0x060401F8 | 0x04 = 4B | Yes | event_queue.s | Status code stub |
| 5 | FUN_060401FC | 0x060401FC | 0xC0 = 192B | No | -- | Validation body (fall-through from 1F8) |
| 6 | FUN_060402BC | 0x060402BC | 0x27E = 638B | No | -- | **Large validator**: multi-branch validation, all converging to exit. Status codes {-23..-1, 0..6}. |
| 7 | FUN_0604053A | 0x0604053A | 0x7E = 126B | No | -- | Validation chain |
| 8 | FUN_060405B8 | 0x060405B8 | 0xB0 = 176B | Yes | event_queue.s | Object setup |
| 9 | FUN_06040668 | 0x06040668 | 0x18 = 24B | No | -- | Small helper |
| 10 | FUN_06040680 | 0x06040680 | 0x34 = 52B | Yes | -- | Object field accessor |
| 11 | FUN_060406B4 | 0x060406B4 | 0x08 = 8B | No | -- | Tiny stub |
| 12 | FUN_060406BC | 0x060406BC | 0x68 = 104B | No | -- | Object setup helper |
| 13 | FUN_06040724 | 0x06040724 | 0x58 = 88B | No | -- | Object helper |
| 14 | FUN_0604077C | 0x0604077C | 0x100 = 256B | Yes | event_queue.s | Object setup (field init) |
| 15 | FUN_0604087C | 0x0604087C | 0x34 = 52B | No | -- | Object helper |
| 16 | FUN_060408B0 | 0x060408B0 | 0xA4 = 164B | Yes | -- | Object processor |
| 17 | FUN_06040954 | 0x06040954 | 0x10 = 16B | Yes | -- | Small helper |
| 18 | FUN_06040964 | 0x06040964 | 0x18 = 24B | Yes | -- | Small helper |
| 19 | FUN_0604097C | 0x0604097C | 0x04 = 4B | No | -- | Tiny stub |
| 20 | FUN_06040980 | 0x06040980 | 0x48 = 72B | No | -- | State check |
| 21 | FUN_060409C8 | 0x060409C8 | 0x1E = 30B | No | -- | Helper |
| 22 | FUN_060409E6 | 0x060409E6 | 0x112 = 274B | Yes | -- | State processor |
| 23 | FUN_06040AF8 | 0x06040AF8 | 0x3C = 60B | No | -- | Helper |
| 24 | FUN_06040B34 | 0x06040B34 | 0x5A = 90B | No | -- | Helper |
| 25 | FUN_06040B8E | 0x06040B8E | 0x02 = 2B | No | -- | Tiny stub (rts+nop) |
| 26 | FUN_06040B90 | 0x06040B90 | 0x80 = 128B | No | -- | Object processor |
| 27 | FUN_06040C10 | 0x06040C10 | 0x4C = 76B | Yes | -- | Object helper |
| 28 | FUN_06040C5C | 0x06040C5C | 0x04 = 4B | No | -- | Tiny stub |
| 29 | FUN_06040C60 | 0x06040C60 | 0x38 = 56B | No | -- | Object helper |
| 30 | FUN_06040C98 | 0x06040C98 | 0x27E = 638B | Yes | -- | Large object processor |
| 31 | FUN_06040F16 | 0x06040F16 | 0x06 = 6B | Yes | -- | Tiny helper |
| 32 | FUN_06040F1C | 0x06040F1C | 0x66 = 102B | No | -- | Helper |
| 33 | FUN_06040F82 | 0x06040F82 | 0xB2 = 178B | Yes | -- | Object processor |
| 34 | FUN_06041034 | 0x06041034 | 0x96 = 150B | Yes | event_queue.s | Buffer slot allocation |
| 35 | FUN_060410CA | 0x060410CA | 0x5E = 94B | No | -- | Queue helper |
| 36 | FUN_06041128 | 0x06041128 | 0x58 = 88B | Yes | event_queue.s | Queue validator |
| 37 | FUN_06041180 | 0x06041180 | 0x20 = 32B | Yes | event_queue.s | Queue helper |
| 38 | FUN_060411A0 | 0x060411A0 | 0x64 = 100B | Yes | event_queue.s | Command enqueue |
| 39 | FUN_06041204 | 0x06041204 | 0x54 = 84B | Yes | -- | State transition |
| 40 | FUN_06041258 | 0x06041258 | 0x5A = 90B | Yes | -- | State transition |
| 41 | FUN_060412B2 | 0x060412B2 | 0x7E = 126B | Yes | -- | State transition |
| 42 | FUN_06041330 | 0x06041330 | 0x1E = 30B | Yes | -- | State helper |
| 43 | FUN_0604134E | 0x0604134E | 0x34 = 52B | Yes | -- | State helper |
| 44 | FUN_06041382 | 0x06041382 | 0x8C = 140B | No | -- | State transition |
| 45 | FUN_0604140E | 0x0604140E | 0x62 = 98B | No | -- | State transition |
| 46 | FUN_06041470 | 0x06041470 | 0x60 = 96B | Yes | -- | State handler |
| 47 | FUN_060414D0 | 0x060414D0 | 0xF8 = 248B | Yes | -- | State handler |
| 48 | FUN_060415C8 | 0x060415C8 | 0x80 = 128B | Yes | -- | State handler |
| 49 | FUN_06041648 | 0x06041648 | 0x50 = 80B | Yes | -- | State handler |
| 50 | FUN_06041698 | 0x06041698 | 0x10 = 16B | Yes | -- | State helper |
| 51 | FUN_060416A8 | 0x060416A8 | 0x17E = 382B | No | -- | **Large state handler**: multi-condition dispatch |
| 52 | FUN_06041826 | 0x06041826 | 0x66 = 102B | Yes | -- | State handler |
| 53 | FUN_0604188C | 0x0604188C | 0x32 = 50B | Yes | -- | State handler |
| 54 | FUN_060418BE | 0x060418BE | 0x1E2 = 482B | Yes | -- | State handler |
| 55 | FUN_06041AA0 | 0x06041AA0 | 0x9C = 156B | Yes | -- | State handler |
| 56 | FUN_06041B3C | 0x06041B3C | 0x18C = 396B | Yes | -- | Validation dispatcher |
| 57 | FUN_06041CC8 | 0x06041CC8 | 0xAC = 172B | Yes | event_queue.s | State transition handler |
| 58 | FUN_06041D6C | 0x06041D6C | 0x08 = 8B | Yes | -- | Small helper |
| 59 | FUN_06041D74 | 0x06041D74 | 0x174 = 372B | No | event_queue.s | **Major state update**: checks offset +0x68, reads 0x5E field, calls FUN_06034C68/060349B6. Multiple error paths. |
| 60 | FUN_06041EE8 | 0x06041EE8 | 0x1A0 = 416B | Yes | -- | State processor |
| 61 | FUN_06042088 | 0x06042088 | 0xAC = 172B | Yes | event_queue.s | Conditional state processor |
| 62 | FUN_06042134 | 0x06042134 | 0x1BC = 444B | Yes | -- | State processor |
| 63 | FUN_060422F0 | 0x060422F0 | 0xB0 = 176B | Yes | event_queue.s | Validator dispatcher |
| 64 | FUN_060423A0 | 0x060423A0 | 0x2C = 44B | Yes | event_queue.s | Bulk structure init |
| 65 | FUN_060423CC | 0x060423CC | 0x4C = 76B | Yes | -- | Helper |
| 66 | FUN_06042418 | 0x06042418 | 0x40 = 64B | No | -- | State helper |
| 67 | FUN_06042458 | 0x06042458 | 0x1DC = 476B | No | -- | **Large state processor** |
| 68 | FUN_06042634 | 0x06042634 | 0x12 = 18B | No | -- | State helper |
| 69 | FUN_06042646 | 0x06042646 | 0x7A6 = 1958B | No | -- | **VERY LARGE event processor**: major event dispatch and processing |
| 70 | FUN_060429EC | 0x060429EC | 0x90 = 144B | Yes | -- | Palette/color system (writes to 0x25F00000 VDP2 Color RAM) |
| 71 | FUN_06046E48 | 0x06046E48 | ~478B | -- | -- | **Data table / jump table**: not standard code. Contains embedded data words (0x4F81, 0x4FE1, etc.), mova patterns. Likely a lookup table used by the event system. |

**Summary**: 71 functions. 51 have C source. All documented in event_queue.s (bulk). 20 without C source are validators, stubs, and state handlers within the documented subsystem. The largest unmapped is FUN_06042646 (1958B) -- a major event processor.

---

## GRAND TOTALS

| Range | Functions | Has C | ASM Doc | Fully Unmapped |
|-------|-----------|-------|---------|----------------|
| 0x06007xxx | 13 | 8 | 3 | 5 |
| 0x06008xxx | 25 | 9 | 18 | 3 |
| 0x0600Fxxx | 18 | 3 | 18 | 0 |
| 0x06010-011 | 29 | 23 | 29 | 0 |
| 0x06012-013 | 40 | 31 | 10 | 9 |
| 0x06038-039 | 23 | 17 | ~10 | 3 |
| 0x0603A-0603B | 55 | 29 | 0 | 26 |
| 0x0603C-0603D | 19 | 14 | 3 | 3 |
| 0x0603E | 7 | 5 | 0 | 2 |
| 0x0603F | 32 | 22 | 1 | 9 |
| 0x06040-046 | 71 | 51 | 70 | 0 |
| **TOTAL** | **332** | **212** | **162** | **60** |

"Fully unmapped" = no C source AND no individual asm/*.s documentation.

### By Category (60 unmapped functions):

| Category | Count | Key Examples |
|----------|-------|-------------|
| Entity/object helpers | 26 | B118, B11C, B130, B168, B290, B324, B392, etc. |
| Entity system (0x0603F) | 9 | F238, F244, F2EC, F354, F948, F974, F9BC, FAE4, FF3A |
| Rendering pipeline | 7 | 72E6, 7370, 747C, 7CEC, 7D8E, 7E08, E050, E5BC |
| State/game init | 3 | 893C, 8CD0, 8E48 |
| Data table/config | 3 | C10C, D7B0, DB28 |
| CD/DMA helpers | 4 | 12AC4, 12AFA, FE44, FE62 |
| Subsystem dispatchers | 5 | 138BE, 13948, 13A74, 13B04, 13C20 |
| SMPC peripheral | 1 | 3990E |
| DMA/transfer wrapper | 2 | FE44, FE62 |

### HIGH Priority Unmapped (>500B or critical path):

| Function | Size | Category |
|----------|------|----------|
| FUN_0603990E | 1806B | SMPC INTBACK response handler (peripheral input) |
| FUN_0603E050 | 1388B | 3D scene renderer pass A |
| FUN_0603E5BC | 1296B | 3D scene renderer pass B |
| FUN_06007E08 | ~502B | Large sprite/polygon renderer |
| FUN_0603D7B0 | 572B | Data table multi-field configurator |
| FUN_0603DB28 | 724B | Data table multi-mode processor |
| FUN_0603FAE4 | 380B | Entity linked-list traversal |
