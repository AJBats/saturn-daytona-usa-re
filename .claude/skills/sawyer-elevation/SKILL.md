# Sawyer Elevation — Function Naming & Reimplementation

How to elevate functions from Ghidra junk names to human-readable code.
This is the core workflow of the Sawyer pipeline.

---

## Elevation Levels

| Level | What it is | Instructions | Pool entries | Example |
|-------|-----------|-------------|-------------|---------|
| **L2** | Byte-perfect ASM | `.byte` blobs | `.4byte SYMBOL` | `retail/cdb_wait_scdq.s` |
| **L3** | Real ASM source | SH-2 mnemonics | `.4byte SYMBOL` | (not yet done) |
| **L4** | C reimplementation | C source | compiler-managed | `src/cdb_wait_scdq.c` |

L2 is what we have for all 1,259 functions today. L3 and L4 are where we're going.

**L2 is relocatable but opaque.** You can move it, but you can't read it.
**L3 is relocatable and readable.** You can understand the logic.
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

Convert `.byte` instruction pairs to SH-2 assembly mnemonics. The function
stays in `retail/`, the pool entries stay symbolic.

**Prerequisites**: Name the function first (see above). You need to understand
it to write correct mnemonics.

**Steps**:

1. **Disassemble the bytes.** Use the Sawyer annotations (`asm/*.s`) as
   reference, or disassemble manually using the SH-2 instruction set
   (see `platform-saturn-sh2` skill).

2. **Replace `.byte` pairs with mnemonics.** One instruction at a time:
   ```asm
   /* Before (L2) */
   .byte 0x2F, 0xE6         /* opaque */

   /* After (L3) */
   mov.l  r14, @-r15        /* push r14 */
   ```

3. **Keep the constant pool as-is.** The `.4byte SYMBOL` entries and literal
   `.byte` constants don't change.

4. **Validate.** `make validate` — but note: L3 conversion may NOT be
   byte-identical if the assembler chooses different encodings for
   ambiguous mnemonics. If validate fails, compare with `objdump -d`
   to find the differences and fix them.

5. **Boot test.** `make disc` and test in Mednafen. L3 is validated by
   behavior, not bytes.

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

## Validation Commands

```bash
make -C reimpl validate          # retail byte-identical check
make -C reimpl disc              # free build + inject into disc
make -C reimpl clean             # wipe build/ (do before switching configs)
make -C reimpl info              # show current config + reimplemented stems
```

## Boot Test

```powershell
powershell -ExecutionPolicy Bypass -File tools\test_boot.ps1 -Cue rebuilt
```
