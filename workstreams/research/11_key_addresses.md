# Key Addresses Reference

## Production vs Free Build Address Shift

All `FUN_*` and code `sym_*` symbols shift +4 in the free build.
Example: `FUN_060423CC` (production) → `0x060423D0` (free build).

## Critical Functions

| Name | Prod Address | Free +4 | Role |
|------|-------------|---------|------|
| FUN_060030FC | 0x060030FC | 0x06003100 | Primary init (called from startup) |
| FUN_0600C010 | 0x0600C010 | 0x0600C014 | ICF synchronization (primary wait for secondary) |
| FUN_0600C170 | 0x0600C170 | 0x0600C174 | Secondary SH-2 per-frame callback (CRASHES) |
| FUN_06034F08 | 0x06034F08 | 0x06034F0C | Secondary SH-2 ICF poll loop |
| FUN_0603B21C | 0x0603B21C | 0x0603B220 | CD retry wrapper loop |
| FUN_0603B424 | 0x0603B424 | 0x0603B428 | CD command state machine ← KEY |
| FUN_060423CC | 0x060423CC | 0x060423D0 | SCDQ poll loop ← KEY |
| FUN_060423A0 | 0x060423A0 | 0x060423A4 | Bulk structure initialization |
| FUN_060422F0 | 0x060422F0 | 0x060422F4 | Validator (calls sym_06035C4E) |
| sym_06035C4E | 0x06035C4E | 0x06035C52 | HIRQ reader (3 insns: load addr + read) |
| FUN_06035C54 | 0x06035C54 | 0x06035C58 | SCDQ acknowledge |
| FUN_06035C08 | 0x06035C08 | 0x06035C0C | String handler (contains sym_06035C4E) |
| FUN_0603BD1C | 0x0603BD1C | 0x0603BD20 | Issues Get Sector Number command |
| FUN_0603BDAC | 0x0603BDAC | 0x0603BDB0 | Query: returns 5 when sectors ready |
| FUN_0603BF22 | 0x0603BF22 | 0x0603BF26 | GetBufSize (accessed via +0x38 offset) |

## CD Block Hardware Registers (NEVER shift)

```
0x25890008  HIRQ register         ← game reads this to check SCDQ
0x2589000C  HIRQ Mask
0x25890018  CR1 (command/response 1)
0x2589001C  CR2
0x25890020  CR3
0x25890024  CR4
0x25898000  Data Transfer FIFO
```

## Critical Data Addresses

| Address | Content | Notes |
|---------|---------|-------|
| 0x060A5400 | Pointer to game state struct | FIXED (PROVIDE in linker script) |
| 0x06063574 | Secondary SH-2 callback pointer | Set by primary init → FUN_0600C170 |
| 0x06083255 | Primary sound enable byte | |
| 0x06078635 | Controls FUN_0600C010 branch | |
| 0x0607EBC4 | Button/input state word | |
| 0x0607E944 | Car struct pointer | |
| 0x06059CA4 | CD command buffer A (3 bytes) | |
| 0x06059CA7 | CD command buffer B (3 bytes) | |
| 0x06059CB0 | CD SCSI command FIFO (8 bytes) | |
| 0x06063590 | SMPC status shadow register | Accumulated HIRQ bits |
| 0x06082A7C | Object slot array (5×0x2C=44 bytes each) | AI/game objects |
| 0x06089EDC | Pointer to active object state table | |

## Disc FAD Reference

```
FAD = Logical Block Address + 150

0x0096 = LBA 0    = data track start (IP.BIN area)
0x00AB = LBA 21   = APROG.BIN start (193 sectors → 0x016C)
0x016C = LBA 214  = COURSE0.BIN
0x0240 = LBA 240  = COURSE1.BIN
0x0130 = LBA 304  = COURSE2.BIN
0x0257 = LBA 371  = CS0_LINE.BIN
0x02B1 = LBA 389  = CS1_LINE.BIN
0x02DE = LBA 430  = CS2_LINE.BIN
0x020F = LBA 511  = POLYGON.BIN
0x0234 = LBA 524  = TEX_PL.BIN
0x025F = LBA 543  = TEX_C0.BIN
0x0294 = LBA 630  = TEX_C1.BIN
0x02F5 = LBA 749  = TEX_C2.BIN
0x0368 = LBA 872  = CS0POLY.BIN
0x03F9 = LBA 1017 = CS1POLY.BIN
0x0532 = LBA 1326 = CS2POLY.BIN
0x06DE = LBA 1740 = TABLE.BIN   (14 sectors → 0x076F)
0x06EC = LBA 1754 = SCROLL.BIN  ← immediately after TABLE.BIN
0x0789 = LBA 1931 = SOUNDS.BIN
0x079F = LBA 1935 = GAMED.BIN
```

**KEY**: TABLE.BIN ends at FAD 0x076F. SCROLL.BIN starts at FAD 0x0770.
When the game plays to FAD 0x0770 (TABLE.BIN + 1 sector overshoot),
the disc is at the start of SCROLL.BIN. This is the root of the timing race.

## ICF Sync Addresses (SH-2 FRT input capture)

```
0x01000000  Write → sets secondary SH-2 ICF flag (MINIT)
0x01800000  Write → sets primary SH-2 ICF flag (SINIT)
```

In Mednafen `ss.cpp`:
```c
const unsigned c = ((A >> 23) & 1) ^ 1;  // 01000000→secondary, 01800000→primary
CPU[c].SetFTI(true);
CPU[c].SetFTI(false);
```

## State Machine Positions

### ICF sync (FUN_0600C010):

```
Primary writes MINIT (0x01000000) at: PC=0x0600C0F0 (prod) / 0x0600C0F4 (free)
Primary polls FTCSR bit7 at: 0x0600C11C-0x0600C124 (prod) / +0x0C128 (free)
ICF_FIX NOPs: the bf -7 at line 127 of FUN_0600C010.s
Secondary polls FTCSR at: 0x06034F3A (prod) / 0x06034F3E (free)
Secondary callback: 0x06063574 points to FUN_0600C170 (prod) / FUN_0600C174 (free)
Secondary panic trap: 0x06028296 / 0x0602829A (free) = SETT; BT $ halt pattern
```

### SCDQ poll positions (in free build):

```
FUN_060423D0 (entry)
+0x12: JSR @R12         ; calls sym_06035C52 (free = HIRQ reader)
+0x14: NOP
+0x16: extu.w R0, R0   ; zero-extend HIRQ
+0x18: and R14, R0      ; R0 &= 0x0400
+0x1A: tst R0, R0       ; T = (SCDQ not set)
+0x1C: bt +3            ; if T: branch to BRA (loop back)
+0x1E: JSR @R11         ; ack SCDQ
```

Test 4 stuck PC `0x060423E6` = free base `0x060423D0` + `0x16` = extu.w step.
Test 6 stuck PC `0x060423EA` = free base + `0x1A` = tst step.
Both = inside poll loop, confirming SCDQ never set.
