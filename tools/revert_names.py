#!/usr/bin/env python3
"""Revert non-VERIFIED semantic function names back to FUN_* names.

Reads the linker map to build semantic_name -> FUN_XXXXXXXX mapping,
then does a global find-and-replace across all source files and linker
scripts, and renames files.

Usage:
    python tools/revert_names.py [--dry-run]
"""

import re
import os
import sys
from pathlib import Path

REIMPL = Path("reimpl")
MAP_FILE = REIMPL / "build" / "daytona.map"

# VERIFIED symbols that keep their semantic names
VERIFIED_SYMBOLS = {
    "steering_input_dispatch",
    "mode_select_handler",
    "controller_input_update",
    "circuit_confirm_handler",
}

# VERIFIED filenames that won't be renamed (stems, no extension)
VERIFIED_FILES = {
    "steering_input_dispatch",
    "mode_select_handler",
    "controller_input_update",
    "circuit_confirm_handler",
    "game_update_loop",
}

# Prefixes that are already correct — skip these
SKIP_PREFIXES = ("FUN_", "sym_", "DAT_", "__", ".")

# Individual names to skip (not function renames)
SKIP_NAMES = {"_start", "start", "g_pad_state"}


def parse_map_file():
    """Parse daytona.map to get symbol_name -> runtime_address.

    Only includes symbols in the code range (0x06003000..0x06064000).
    """
    name_to_addr = {}
    with open(MAP_FILE) as f:
        for line in f:
            # Format: "                0xADDRESS                symbol_name"
            # Must be an indented line with exactly an address and a name
            m = re.match(r'^\s+0x([0-9a-fA-F]+)\s+([a-zA-Z_]\w*)\s*$', line)
            if m:
                addr = int(m.group(1), 16)
                name = m.group(2)
                if 0x06003000 <= addr < 0x06070000:
                    name_to_addr[name] = addr
    return name_to_addr


def parse_section_names():
    """Parse all .s files to get primary function -> section FUN address.

    Returns {filename_stem: section_fun_name} for files in src/ and retail/.
    """
    section_map = {}
    for d in [REIMPL / "src", REIMPL / "retail",
              REIMPL / "src" / "mods",
              REIMPL / "src" / "mods" / "re_tests"]:
        if not d.exists():
            continue
        for f in d.glob("*.s"):
            with open(f) as fh:
                for line in fh:
                    m = re.match(r'\s*\.section\s+\.text\.(FUN_[0-9A-F]{8})', line)
                    if m:
                        section_map[f.stem] = m.group(1)
                        break
    return section_map


def is_semantic_name(name):
    """Return True if name is a semantic (renamed) function name."""
    if name in SKIP_NAMES:
        return False
    if name in VERIFIED_SYMBOLS:
        return False
    for prefix in SKIP_PREFIXES:
        if name.startswith(prefix):
            return False
    # Must start with a lowercase letter (semantic names are lowercase)
    if not name[0].islower():
        return False
    return True


def build_mapping():
    """Build the complete semantic_name -> FUN_XXXXXXXX mapping.

    Symbol names use map_addr - 4 (consistent 4-byte offset from _start
    alignment fill). Section names are only used for cross-validation of
    primary functions — sub-functions in consolidated TUs have section
    names belonging to the TU's primary function, not their own address.
    """
    map_addrs = parse_map_file()
    section_names = parse_section_names()
    mapping = {}

    # For each symbol in the map file, check if it's a semantic name
    for name, runtime_addr in map_addrs.items():
        if not is_semantic_name(name):
            continue
        # FUN name = runtime_address - 4 (consistent offset from _start fill)
        fun_addr = runtime_addr - 4
        fun_name = f"FUN_{fun_addr:08X}"
        mapping[name] = fun_name

    # Cross-validate primary functions: for single-function files, the
    # section name should match the map-derived name. Mismatches indicate
    # consolidated TUs where the stem is a sub-function (expected).
    mismatches = 0
    for stem, section_fun in section_names.items():
        if stem in mapping and mapping[stem] != section_fun:
            mismatches += 1
    if mismatches:
        print(f"  ({mismatches} consolidated TU sub-functions detected "
              f"— section name differs from map-derived name, as expected)")

    return mapping, section_names


def collect_files():
    """Collect all files that need text replacement."""
    files = []
    # Source and retail .s files
    for d in [REIMPL / "src", REIMPL / "retail"]:
        files.extend(d.glob("*.s"))
    # Mods
    for d in [REIMPL / "src" / "mods", REIMPL / "src" / "mods" / "re_tests"]:
        if d.exists():
            files.extend(d.glob("*.s"))
            files.extend(d.glob("*.c"))
    # Linker scripts
    files.append(REIMPL / "free.ld")
    files.append(REIMPL / "sega.ld")
    return [f for f in files if f.exists()]


def apply_replacements(mapping, dry_run=False):
    """Replace all semantic names with FUN_* names in all files."""
    files = collect_files()

    # Sort mapping by length (longest first) to avoid partial replacements
    # e.g., "ai_brake_zone_adjust" before "ai_brake_zone"
    sorted_names = sorted(mapping.keys(), key=len, reverse=True)

    # Build a single regex pattern for efficiency
    pattern = re.compile(r'\b(' + '|'.join(re.escape(n) for n in sorted_names) + r')\b')

    total_replacements = 0
    files_modified = 0

    for fpath in files:
        with open(fpath, 'r') as f:
            content = f.read()

        new_content = pattern.sub(lambda m: mapping[m.group(1)], content)

        if new_content != content:
            count = sum(1 for _ in pattern.finditer(content))
            files_modified += 1
            total_replacements += count
            if dry_run:
                # Show sample replacements
                for m in list(pattern.finditer(content))[:3]:
                    old = m.group(1)
                    print(f"  {fpath.name}: {old} -> {mapping[old]}")
                if count > 3:
                    print(f"  {fpath.name}: ... and {count - 3} more")
            else:
                with open(fpath, 'w') as f:
                    f.write(new_content)

    return files_modified, total_replacements


def rename_files(mapping, section_names, dry_run=False):
    """Rename semantic-named files back to FUN_* names.

    Uses section names for the new filename (primary function of the TU),
    NOT the symbol mapping (which gives individual sub-function addresses
    for consolidated TUs).
    """
    renames = []

    for d in [REIMPL / "src", REIMPL / "retail",
              REIMPL / "src" / "mods",
              REIMPL / "src" / "mods" / "re_tests"]:
        if not d.exists():
            continue
        for f in sorted(d.iterdir()):
            stem = f.stem
            ext = f.suffix
            if stem in VERIFIED_FILES:
                continue
            # Use section name for file rename (primary function of TU)
            if stem in section_names:
                new_name = section_names[stem] + ext
            elif stem in mapping:
                # Fallback for files without sections (e.g., .c files)
                new_name = mapping[stem] + ext
            else:
                continue
            new_path = f.parent / new_name
            if new_path != f:
                renames.append((f, new_path))

    if dry_run:
        for old, new in renames[:20]:
            print(f"  {old.parent.name}/{old.name} -> {new.name}")
        if len(renames) > 20:
            print(f"  ... and {len(renames) - 20} more renames")
    else:
        for old, new in renames:
            old.rename(new)

    return len(renames)


def main():
    dry_run = "--dry-run" in sys.argv

    os.chdir(Path(__file__).resolve().parent.parent)

    if not MAP_FILE.exists():
        print(f"ERROR: Map file not found: {MAP_FILE}")
        print("Run 'make -C reimpl' first to generate it.")
        sys.exit(1)

    print("Building semantic -> FUN_* mapping...")
    mapping, section_names = build_mapping()
    print(f"  Found {len(mapping)} semantic names to revert")

    if not mapping:
        print("Nothing to do.")
        return

    # Show some examples
    examples = list(mapping.items())[:10]
    for old, new in examples:
        print(f"    {old} -> {new}")
    if len(mapping) > 10:
        print(f"    ... and {len(mapping) - 10} more")

    print()
    if dry_run:
        print("=== DRY RUN (no changes) ===")

    print("Replacing names in source files and linker scripts...")
    files_modified, total_replacements = apply_replacements(mapping, dry_run)
    print(f"  {files_modified} files modified, {total_replacements} replacements")

    print("Renaming files...")
    num_renames = rename_files(mapping, section_names, dry_run)
    print(f"  {num_renames} files renamed")

    if dry_run:
        print()
        print("Re-run without --dry-run to apply changes.")
    else:
        print()
        print("Done. Run 'python tools/validate_build.py' to verify.")


if __name__ == "__main__":
    main()
