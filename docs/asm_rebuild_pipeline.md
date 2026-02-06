# ASM-Based Rebuild Pipeline

This document describes the pipeline for rebuilding the APROG.BIN binary using inline assembly in C files compiled through our patched GCC 2.6.3.

## Overview

The pipeline validates our entire toolchain by:
1. Extracting function bytes from the original binary
2. Embedding them in C files as inline assembly with `.byte` directives
3. Compiling through GCC with `.naked` marker to suppress prologue/epilogue
4. Assembling and linking at correct addresses
5. Producing a byte-identical binary

## Key Components

### `.naked` Marker (GCC Patch 24)

A special inline asm marker that tells the compiler to suppress function epilogue:

```c
void FUN_XXXXXXXX()
{
    __asm__ volatile (
        ".byte 0xNN, 0xNN\n"
        ".byte 0xNN, 0xNN\n"
        /* ... more bytes ... */
        "! .naked\n"  /* <-- this suppresses rts/nop */
    );
}
```

The `! .naked` is an SH assembler comment (using `!` prefix) that the compiler detects in `final.c` to set the `naked_asm_seen` flag.

### Scripts

| Script | Purpose |
|--------|---------|
| `tools/gen_asm_funcs.py` | Generates C files with inline asm for all 1234 functions |
| `tools/gen_combined_asm.py` | Generates a single combined .s file (for testing) |
| `tools/build_compiler_pipeline.sh` | Full pipeline: compile -> assemble -> link |
| `tools/build_disc_from_bin.sh` | Injects rebuilt binary into disc image |

## Pipeline Steps

### Step 1: Generate C Files

```bash
python3 tools/gen_asm_funcs.py
```

This creates 1234 C files in `build/gen/` containing inline asm for each function.

### Step 2: Build via Compiler Pipeline

```bash
MSYS_NO_PATHCONV=1 wsl -d Ubuntu -- bash tools/build_compiler_pipeline.sh
```

This:
1. Compiles all C files to assembly using `cc1`
2. Creates a combined assembly file with `.org` directives for address placement
3. Fills gaps between functions with original binary data
4. Assembles with `sh-elf-as`
5. Links with `sh-elf-ld` using a linker script
6. Extracts binary with `sh-elf-objcopy`
7. Compares with original

### Step 3: Build Disc Image

```bash
MSYS_NO_PATHCONV=1 wsl -d Ubuntu -- bash tools/build_disc_from_bin.sh
```

This injects the rebuilt binary into the original disc image at the APROG.BIN offset (0x4F670).

## Output Files

| Path | Description |
|------|-------------|
| `build/gen/*.c` | Generated C files with inline asm |
| `build/compiler_rebuilt/aprog_rebuilt.bin` | Rebuilt binary (should match original) |
| `build/disc/rebuilt_disc/Track 01.bin` | Disc data track with rebuilt binary |
| `build/disc/rebuilt_disc/daytona_rebuilt.cue` | CUE sheet for Mednafen |

## Validation Results

- **Binary comparison**: IDENTICAL to original (394,896 bytes)
- **Functions compiled**: 1234/1234 (100%)
- **Pipeline validated**: Yes

## Next Steps

This pipeline proves we can:
1. Pass original code through GCC without modification
2. Produce byte-identical output

The next step is to integrate real C decompilations:
1. For functions that already PASS the opcode test, use the C source
2. For functions that FAIL, use the inline asm fallback
3. Gradually replace asm fallbacks as more functions are decompiled correctly
