# Sawyer Elevation — Function Naming & Reimplementation

How to elevate functions from Ghidra junk names to human-readable code.
This is the core workflow of the Sawyer pipeline.

---

## Elevation Levels

| Level | What it is | Instructions | Pool entries | Example |
|-------|-----------|-------------|-------------|---------|
| **L2** | Byte-perfect ASM | `.byte` blobs | `.4byte SYMBOL` | `retail/cdb_wait_scdq.s` |
| **L3** | Real ASM source | SH-2 mnemonics + symbolic `mov.l` | labeled pool entries | `src/game_update_loop.s` |
| **L4** | C reimplementation | C source | compiler-managed | `src/cdb_wait_scdq.c` |

L2 is the starting point for all functions. L3 and L4 are where we're going.

**L2 is relocatable but opaque.** You can move it, but you can't read it.
**L3 is relocatable and readable.** Full SH-2 mnemonics with symbolic pool labels.
The entire translation unit is consolidated into a single section so the assembler
can resolve all `mov.l @(disp,PC)` and branch instructions internally.
**L4 is relocatable and modifiable.** You can change the behavior.

---

## Naming Convention

Every function has up to three identifiers. They serve different purposes:

| Identifier | Purpose | Convention | Example |
|-----------|---------|-----------|---------|
| **Filename** | Human navigation, build system stem | Human name | `cdb_wait_scdq.s` |
| **Section name** | Linker placement (sort key) | Original address | `.section .text.FUN_060423CC` |
| **Symbol/label** | Code references | Human name | `.global cdb_wait_scdq` |

**Why the section name stays `FUN_`**: The retail linker script (`sega.ld`) uses
`*(SORT_BY_NAME(.text.FUN_*))` to place sections in address order. Since `FUN_`
names are hex addresses, alphabetical sort = address order. If you rename the
section, it falls out of the sort and lands at the wrong address. The section
name is plumbing — it doesn't appear in the final binary.

**Why the symbol gets the real name**: Symbols are what humans and other code
reference. When FUN_0603B290.s says `.4byte cdb_wait_scdq`, that's the linker
resolving a symbol. Making symbols readable makes the whole codebase readable
incrementally — callers start referencing real names even before they're
renamed themselves.

---

## Elevation Procedures

### Naming Only (any level)

Give a function a real name without changing its level. This is the simplest
elevation and can be done to any function at any time.

**Prerequisites**: Understand what the function does (read its code, check
Sawyer annotations in `asm/*.s`, trace callers).

**Steps**:

1. **Choose a name.** Use `module_verb_noun` style. Examples:
   - `cdb_wait_scdq` — CD block, wait for SCDQ
   - `vdp1_flush_sprites` — VDP1, flush sprite commands
   - `car_update_physics` — car module, update physics

2. **Find all references.**
   ```
   grep -r FUN_XXXXXXXX reimpl/
   ```
   This finds: the .s file itself, callers' `.4byte` entries, sega.ld PROVIDE.
   The linker will catch anything you miss (undefined symbol error).

3. **Rename the file.**
   - `retail/FUN_XXXXXXXX.s` → `retail/new_name.s`
   - If `src/FUN_XXXXXXXX.c` exists → `src/new_name.c`

4. **Update inside the retail .s file.**
   ```asm
   .section .text.FUN_XXXXXXXX        /* KEEP — sort key for linker */
   .global new_name                    /* CHANGE — human name */
   .type new_name, @function
   new_name:                           /* CHANGE — human name */
   ```

5. **Update inside the src .c file** (if exists).
   ```c
   void new_name(void) { ... }
   ```
   No alias needed — the retail .s isn't linked when a .c override exists.

6. **Update all callers.** In each caller's constant pool:
   ```asm
   .4byte new_name                     /* was: .4byte FUN_XXXXXXXX */
   ```

7. **Update sega.ld.** Change the PROVIDE entry:
   ```
   PROVIDE(new_name = new_name + 0x0);  /* was: PROVIDE(FUN_XXXXXXXX = ...) */
   ```
   Check `free.ld` too (usually no entry, but verify with grep).

8. **Validate.**
   ```bash
   make -C reimpl clean && make -C reimpl validate   # MUST say PASS
   make -C reimpl clean && make -C reimpl disc       # free build, test in emulator
   ```
   If validate fails: you missed a reference or changed the section name.
   If free build fails: unrelated issue (the rename is cosmetic).

9. **Commit.**
   ```
   rename FUN_XXXXXXXX → new_name (short description)
   ```

### L2 → L3 (Byte Blobs → Real Mnemonics)

Convert a translation unit from `.byte` blobs to SH-2 assembly mnemonics.
L3 operates at the **TU level**, not individual functions. The retail file
keeps `.byte` blobs (consolidated into one multi-section file), and a new
src file is generated with decoded mnemonics in a single section.

**Result**: Two files per TU:
- `retail/<tu_name>.s` — consolidated multi-section, `.byte` blobs (retail build)
- `src/<tu_name>.s` — single-section, SH-2 mnemonics with symbolic pools (free build)

**Prerequisites**: The functions in the TU should already be named (see above).
You need TU boundaries — identified by cross-section `mov.l` pool sharing and
BSR/BRA branches between functions.

**Steps**:

1. **Identify TU boundaries.** Look for cross-section pool references —
   functions that share constant pool entries or have BSR/BRA branches
   between them belong to the same TU. The function before the start and
   after the end must be fully self-contained (no pool refs or branches
   crossing the boundary). Use `asm/*.s` annotations to trace references.

2. **Consolidate retail files.** Merge individual `.s` files into one.
   For batch processing (many TUs at once):
   ```bash
   python tools/batch_l3_modules.py --consolidate-only   # phase 1 only
   python tools/batch_l3_modules.py                       # consolidate + L3
   ```
   For a single TU:
   ```bash
   python tools/consolidate_tu.py <tu_name> <start_addr> <end_addr> --description "..."
   ```
   Use `--dry-run` first to review. This produces `retail/<tu_name>.s` —
   a multi-section file where each function retains its own
   `.section .text.FUN_XXXXXXXX` directive. Individual files are deleted
   automatically. (Elevation file deletions don't require the safe word.)

4. **Generate the L3 src file.** Decode instructions automatically:
   ```bash
   python tools/generate_l3_tu.py <tu_name>
   ```
   This reads the consolidated retail file, decodes all `.byte` pairs
   to SH-2 mnemonics, and writes `src/<tu_name>.s` as a single section.
   Pool entries stay symbolic (`.4byte SYMBOL`), BSR/BRA stay as `.byte`
   pairs (assembler can't generate 12-bit PC-relative relocations for
   external symbols).

5. **Validate.** Run full 3-class validation:
   ```bash
   python tools/validate_build.py
   ```
   - Retail must be **byte-identical** (the retail file is still `.byte`
     blobs, so this should always pass)
   - Free build must boot to menu
   - Free+4shift must boot to menu (validates relocation)

   L3 uplifts are **size-neutral** — the free binary size doesn't change.

6. **If the generator has a bug**, fix `tools/generate_l3_tu.py` (or
   `tools/sh2_decode.py`) and regenerate. Never hand-edit L3 output —
   the generator is the source of truth. See `.claude/rules/l3-uplift.md`.

### L2/L3 → L4 (ASM → C Reimplementation)

Replace the function entirely with C source code.

**Prerequisites**: Full understanding of the function's behavior. Read the
L3 mnemonics (or disassemble L2), understand the algorithm, identify all
inputs/outputs/side effects.

**Steps**:

1. **Create `src/new_name.c`.** The filename stem must match the retail .s
   file stem (this is how the Makefile knows to override).

2. **Write the C function.** Match the original behavior exactly:
   - Same function signature (check callers for argument passing)
   - Same side effects (memory writes, register state)
   - Same return value

3. **Declare externs for callees.** Functions this code calls:
   ```c
   extern int sym_06035C4E(void);      /* cdb_get_hirq */
   extern void FUN_06035C54(int);      /* cdb_ack_hirq */
   ```
   Use real names where known, FUN_/sym_ names where not.

4. **Compiler flags matter.** The Makefile uses `-m2 -Os -nostdlib
   -ffreestanding -ffunction-sections -fno-leading-underscore`. The C
   function compiles into `.text.new_name` section. In the free build,
   this overrides the retail .s automatically.

5. **Validate retail.** `make validate` — must still PASS. The retail build
   ignores `src/` entirely (`REIMPL_C=` is emptied), so your .c file
   can't break it. But verify anyway.

6. **Test free build.** `make disc` — boot in Mednafen. If the game
   breaks, your C has a bug. The retail .s is the ground truth.

7. **Add a comment header.** Include:
   - Real function name and one-line description
   - Original address (`0x060423CC`)
   - Any behavioral notes (bugs found, deviations from retail)

---

## Key Rules

1. **Section name stays `FUN_XXXXXXXX`.** Always. It's a sort key, not a name.

2. **The linker is your safety net.** If you miss a reference during rename,
   the build fails with an undefined symbol. You cannot silently leave stale
   references — the linker catches them.

3. **`make validate` is the byte-identical test.** Run it after every rename.
   If it passes, your change was purely cosmetic. If it fails, you broke
   something (probably changed the section name).

4. **No aliases.** Don't use `__attribute__((alias(...)))` or dual labels.
   Rename everything cleanly. Stale references should fail loudly, not
   resolve silently through aliases.

5. **Incremental is fine.** You can name one function while its callers still
   have `FUN_` names. The caller's `.4byte cdb_wait_scdq` works even though
   the caller itself is still called `FUN_0603B290`. Names propagate
   incrementally as you understand more functions.

6. **Sub-labels (`sym_`, `DAT_`) rename the same way.** Same process, just
   smaller scope. Update the PROVIDE in the linker script, update all
   `.4byte` references, keep the section name unchanged.

---

## File Locations

| What | Where |
|------|-------|
| Retail ASM (L2) | `reimpl/retail/*.s` |
| Reimplemented (L3 ASM or L4 C) | `reimpl/src/*.{s,c}` |
| Retail linker script | `reimpl/sega.ld` |
| Free linker script | `reimpl/free.ld` |
| Sawyer annotations (reference) | `asm/*.s` |
| Archived Ghidra lifts (starting material) | `reimpl/src_c_archive/` |
| Build output | `reimpl/build/` |

## Commit Criteria

**Nothing gets committed without passing all three validation classes.**

Run the full suite after every elevation:
```bash
python tools/validate_build.py
```

This runs:
1. **Retail binary match** — `make -C reimpl validate` (byte-identical to original)
2. **Free build boot** — `make -C reimpl disc`, boot WSL Mednafen to menu
3. **Free+4shift boot** — `make -C reimpl disc-4shift`, boot to menu

Each boot test takes 3 frame-precise screenshots (attract, title, menu) and
compares against golden baselines using 4 image comparison methods:
- **phash** — perceptual hash (Hamming distance <= 10)
- **histogram** — color distribution correlation (>= 0.85)
- **pixels** — 5 spot-check locations (>= 3 of 5 within tolerance)
- **rmse** — root mean square pixel error (<= 25)

All 4 methods must pass on all 3 screenshots for each boot class.
Menu has dual golden baselines (ARCADE MODE blink on/off) — passes if
either variant matches on all 4 methods.

## Automation Tools

| Tool | Purpose | Usage |
|------|---------|-------|
| `tools/validate_build.py` | Full 3-class validation | `python tools/validate_build.py` |
| `tools/test_boot_auto.py` | Single-disc 3-stage boot test | `python tools/test_boot_auto.py rebuilt` |
| `tools/capture_input_trace.py` | Record driven session for new golden traces | `python tools/capture_input_trace.py rebuilt` |
| `tools/compare_screenshot.py` | Screenshot comparison (4 methods) | `python tools/compare_screenshot.py test.png golden.png` |
| `tools/module_scanner.py` | Find function module boundaries | `python tools/module_scanner.py` |
| `tools/generate_l3_tu.py` | Decode retail `.byte` blobs → L3 mnemonics | `python tools/generate_l3_tu.py <tu_name>` |
| `tools/batch_l3_modules.py` | Batch consolidate + L3 for all multi-function TUs | `python tools/batch_l3_modules.py` |
| `tools/test_asm_modules.sh` | WSL assembly test for all L3 src files | `wsl -- bash tools/test_asm_modules.sh` |
| `tools/consolidate_tu.py` | Consolidate individual retail files into one TU | `python tools/consolidate_tu.py <name> <start> <end>` |

### Golden Baselines

Stored in `build/screenshots/golden_*.png` (poked through `.gitignore`).
Captured from a driven vanilla session with frame-precise input tracing.
To re-record: use `capture_input_trace.py`, play through to menu taking
screenshots with P key, note frame numbers from trace output.

## Other Commands

```bash
make -C reimpl validate          # retail byte-identical check
make -C reimpl disc              # free build + inject into disc
make -C reimpl disc-4shift       # free +4 shift build + inject
make -C reimpl clean             # wipe build/ (do before switching configs)
make -C reimpl info              # show current config + reimplemented stems
```
