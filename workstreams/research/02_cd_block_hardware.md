# Saturn CD Block Hardware Reference

## Physical Addresses

```
Base:     0x25890000 (cache-through mirror of 0x05890000)
DATATRNS: 0x25898000  Data Transfer FIFO (16-bit)
HIRQREQ:  0x25890008  Interrupt Factor Register (16-bit) ← KEY REGISTER
HIRQMSK:  0x2589000C  Interrupt Mask Register (16-bit)
CR1:      0x25890018  Command/Response Register 1 (16-bit)
CR2:      0x2589001C  Command/Response Register 2
CR3:      0x25890020  Command/Response Register 3
CR4:      0x25890024  Command/Response Register 4
```

## HIRQ Register (0x25890008)

Write behavior: Only 0 clears a bit. Writing 1 has no effect.

| Bit | Name | Description |
|-----|------|-------------|
| 0   | CMOK | Command OK — next command can be issued |
| 1   | DRDY | Data Ready |
| 2   | CSCT | 1 Sector Stored |
| 3   | BFUL | Buffer Full |
| 4   | PEND | Play End |
| 5   | DCHG | Disc Change |
| 6   | ESEL | Selector Set End |
| 7   | EHST | Host I/O End |
| 8   | ECPY | Copy/Move End |
| 9   | EFLS | File System End |
| **10** | **SCDQ** | **Subcode Q data renewed ← THE CRITICAL BIT** |
| 11-13 | MPED/MPCM/MPST | MPEG-related |

## SCDQ: When It Fires

**Real Saturn hardware**: SCDQ fires when new subcode Q data is read from
the spinning disc. Sub-Q is embedded in every sector. **SCDQ only fires
when the disc is actively reading sectors (PLAY or SEEK state).**
In PAUSE or STANDBY state, the disc is NOT reading → SCDQ does NOT fire.

**Mednafen emulation**: `PeriodicIdleCounter` in `cdb.cpp` fires SCDQ
unconditionally every ~474,940 SH-2 cycles (~16.7ms at 28.6MHz) regardless
of drive state. This is a known inaccuracy.

Timing: `PeriodicIdleCounter_Reload = 187065 << 32`, `CDB_ClockRatio ≈ 1.694e9`
Period: ~474,940 SH-2 cycles ≈ 16.7ms ≈ 1 NTSC frame.

## CD Drive Status Codes (CR1[15:8])

| Value | Name | Description |
|-------|------|-------------|
| 0x00 | BUSY | State change in progress |
| 0x01 | PAUSE | Temporarily stopped (disc may be buffered) |
| 0x02 | STANDBY | Drive stopped |
| 0x03 | PLAY | CD reading sectors actively |
| 0x04 | SEEK | Seeking to new position |
| 0x05 | SCAN | Scanning (fast forward/reverse) |
| 0x06 | OPEN | Tray open |
| 0x07 | NODISC | No disc |
| 0x08 | RETRY | Read retry |
| 0x09 | ERROR | Error occurred |
| 0x0A | FATAL | Fatal error, hard reset needed |

## Command Issue Protocol

1. Wait for CMOK (bit 0) in HIRQREQ = 1
2. Write command to CR1-CR4
3. Wait for CMOK to return = 1 (response ready)
4. Read response from CR1-CR4

Max 30 commands per 6.7ms, 60 per 16.7ms.

Periodic response update rates:
- 1x speed: 13.3ms
- 2x speed: 6.7ms
- Stopped: 16.7ms

## How the Game Reads HIRQ

**sym_06035C4E** (3 instructions, sub-label of FUN_06035C08):
```asm
sym_06035C4E:
    mov.l @(pool_at_0x06035C78), R0   ; R0 = 0x25890008 (HIRQ address)
    rts
    mov.w @R0, R0   ; delay slot: R0 = HIRQ value (16-bit, sign-extended)
```

The pool at 0x06035C78 contains literal bytes `25 89 00 08` = 0x25890008.
In the free build (+4 shift), the pool moves to 0x06035C7C but still contains
the same bytes (hardware address doesn't change). The read is correct in both.

## The SCDQ Poll Function (FUN_060423CC)

The SCDQ poll loop:
```
Entry: load R12 = sym_06035C4E (HIRQ reader)
       load R11 = FUN_06035C54 (SCDQ ack)
       load R14 = 0x0400 (SCDQ mask)
       load R13 = 0x0000FBFF (~SCDQ, ack argument)
[loop:]
  jsr @R12              ; call sym_06035C4E → HIRQ in R0
  extu.w R0, R0         ; zero-extend
  and R14, R0           ; R0 = HIRQ & 0x0400
  tst R0, R0            ; T = (SCDQ not set)
  bt loop               ; if SCDQ=0 → loop
  jsr @R11              ; call FUN_06035C54(~0x0400) → ack SCDQ
  bra exit
```

**Note**: This function loops FOREVER if SCDQ never fires. On real hardware
with disc in PAUSE state: SCDQ never fires → infinite loop → black screen.

## FUN_06035C54: SCDQ Acknowledge

```c
// Reads HIRQ, ORs into shadow register at 0x06063590,
// sets bit 0, writes ~0x0400 back to HIRQ (clears SCDQ bit)
```

## Disc Layout (FADs)

```
FAD = LBA + 150  (FAD = Frame Address)

FAD 0x0096 = LBA 0   = start of data track (IP.BIN area)
FAD 0x00AB = LBA 21  = APROG.BIN start (193 sectors = FAD 0x00AB-0x016C)
FAD 0x016C = LBA 214 = COURSE0.BIN start
FAD 0x0762 = LBA 1740 = TABLE.BIN (14 sectors, FAD 0x0762-0x076F)
FAD 0x0770 = LBA 1754 = SCROLL.BIN start (immediately after TABLE.BIN)
FAD 0x0811 = LBA 1931 = SOUNDS.BIN area
```

TABLE.BIN end FAD = 0x0762 + 14 = **0x0770** = exactly where SCROLL.BIN starts.
This adjacency is the root cause of the timing race (see `03_bugs_found.md`).
