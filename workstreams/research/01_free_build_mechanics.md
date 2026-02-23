# Free Build Mechanics: The +4 Shift

## Goal

Produce a binary where game functions can change size without breaking the
binary. The approach: insert a 4-byte pad at the start of the code section
so all functions shift by +4. Symbolized pool entries (`.4byte SYMBOL`) update
automatically via the linker. This is validated by testing.

## The Binary Layout

```
Address       | Content                     | Notes
0x06003000    | startup (_start.s)          | 0xFC bytes, fixed in both builds
0x06003100    | FUN_ code (production)      | SORT_BY_NAME, packed
0x06003104    | FUN_ code (free build)      | +4 bytes later = the shift
0x06063690    | BSS start                   | runtime data, not in binary
```

Production binary: 394,896 bytes
Free build binary: 394,900 bytes (+4 bytes from the padding)

## The Linker Scripts

**sawyer.ld** (production):
```ld
. = 0x06003000;
.text : {
    *(.text.startup)
    *(SORT_BY_NAME(.text.FUN_*))
}
```
All `PROVIDE(FUN_xxx = FUN_xxx + 0x0)` — identity, no shift.

**sawyer_free.ld** (free build):
```ld
. = 0x06003000;
.text : {
    *(.text.startup)
    . = . + 4;   /* THE SHIFT */
    *(SORT_BY_NAME(.text.FUN_*))
}
```
`PROVIDE()` statements for `FUN_*` are REMOVED — functions define their own
`.global` labels which get relocated by the linker to the new +4 addresses.

## What Shifts and What Doesn't

| Category | Shifts? | Why |
|----------|---------|-----|
| `FUN_*` code sections | YES (+4) | .global labels in .s files |
| `sym_*` code sub-labels | YES (+4) | .global labels in .s files |
| `sym_*` data labels (PROVIDE) | NO | Fixed addresses in linker script |
| `DAT_*` labels (PROVIDE) | NO | Fixed addresses in linker script |
| Hardware registers | NO | Physical hardware addresses |
| Pool entries `.4byte SYMBOL` | YES | Linker resolves symbol to new addr |
| Pool entries `.byte 0x06, ...` | NO | Raw bytes, linker can't relocate |
| `sym_060A5400` (PROVIDE) | NO | Hardcoded to 0x060A5400 in both |

## Pool Entry Patterns

**Correct (relocatable)**:
```asm
.4byte FUN_060423CC    ; linker puts 0x060423D0 in free build
.4byte sym_06035C4E    ; linker puts 0x06035C52 in free build
```

**Potentially wrong (raw bytes)**:
```asm
.byte 0x06, 0x04, 0x23, 0xCC   ; stays 0x060423CC even in free build!
```

## Finding Unrelocated Entries: find_unrelocated.py

`tools/find_unrelocated.py` scans the production and free binaries looking for
4-byte values in the code range [0x06003100, 0x06063690) that didn't shift +4.

Result after full audit: **15 potential hits, all false positives**:
- Values like `0x0601FFFF` = two adjacent 2-byte fields (0x0601 + 0xFFFF)
- Values like `0x06010001` = packed game-internal identifiers (not code addresses)
- No genuine unrelocated function pointers were found

The reimpl source correctly uses `.4byte SYMBOL` everywhere meaningful.

## Build Commands

```bash
# Production (byte-identical validation)
make -C reimpl
make -C reimpl validate       # must pass = PASS: byte-identical to original

# Free build with all bypasses (known-working on Mednafen)
make -C reimpl LDSCRIPT=sawyer_free.ld ICF_FIX=1 SCDQ_FIX=1 CD_FIX=0
make -C reimpl disc           # inject into disc image (NO rebuild)

# Free build for CD fix testing
make -C reimpl LDSCRIPT=sawyer_free.ld ICF_FIX=1 SCDQ_FIX=0 CD_FIX=1
make -C reimpl disc

# SAFE combined build+inject
make -C reimpl free-disc      # ALWAYS uses SCDQ_FIX=1 ICF_FIX=1
```

**Critical**: `make disc` does NOT rebuild. It only injects whatever binary
is already in `build/APROG.BIN`. The `.build_config` file records what was
built. Always verify before injecting.

## ICF_FIX=1

Patches `FUN_0600C010.s` to NOP out the `bf -7` secondary-CPU wait loop.
The secondary SH-2 crashes (hits panic trap 0x06028296) due to wrong init data
state. Without ICF_FIX, the primary hangs forever waiting for SINIT.
This is a separate bug from SCDQ/CD. **Always required for free build testing.**

## SCDQ_FIX=1

Replaces `FUN_060423CC` with a C implementation that times out after 1000
poll iterations and force-acknowledges SCDQ. This is a WORKAROUND for the
timing issue described in `03_bugs_found.md`. Prevents the TABLE.BIN race
by shortening the gap between disc operations.

## Disc Image

Location: `build/disc/rebuilt_disc/daytona_rebuilt.cue`
Track 01.bin: ~47MB, contains all disc data with APROG.BIN replaced
Production APROG.BIN: `build/disc/files/APROG.BIN` (never modified)
