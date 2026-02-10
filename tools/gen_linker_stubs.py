#!/usr/bin/env python3
"""Generate linker stubs for all undefined references.

Runs make, parses undefined reference errors, generates stub definitions.
"""

import os
import re
import subprocess
import sys

PROJ = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
REIMPL_DIR = os.path.join(PROJ, "reimpl", "src")
STUB_FILE = os.path.join(REIMPL_DIR, "linker_stubs.c")

def get_undefined_refs():
    """Run make and collect undefined references."""
    cmd = 'wsl -d Ubuntu -- bash -c "cd /mnt/d/Projects/SaturnReverseTest/reimpl && make 2>&1"'
    result = subprocess.run(cmd, shell=True, capture_output=True, text=True, timeout=120)
    output = result.stdout + result.stderr

    undefs = set()
    for line in output.split('\n'):
        m = re.search(r"undefined reference to `([^']+)'", line)
        if m:
            undefs.add(m.group(1))
    return sorted(undefs)

def get_defined_symbols():
    """Get all symbols already defined in reimpl source."""
    defined = set()
    for fname in os.listdir(REIMPL_DIR):
        if not fname.endswith('.c'):
            continue
        if fname == 'linker_stubs.c':
            continue
        filepath = os.path.join(REIMPL_DIR, fname)
        with open(filepath, 'r', errors='replace') as f:
            content = f.read()
        # Find function definitions (not externs)
        for m in re.finditer(r'^(?!extern\b).*\b(FUN_[0-9A-Fa-f]+)\s*\(', content, re.MULTILINE):
            defined.add(m.group(1))
        # Find DAT/PTR definitions
        for m in re.finditer(r'^(?:int|short|char)\s+(DAT_[0-9A-Fa-f]+|PTR_DAT_[0-9A-Fa-f]+)\s*[=;]', content, re.MULTILINE):
            defined.add(m.group(1))
    return defined

def main():
    print("Building to find undefined references...")
    undefs = get_undefined_refs()
    print(f"Found {len(undefs)} undefined symbols")

    # Read existing stubs if any
    existing_stubs = set()
    if os.path.exists(STUB_FILE):
        with open(STUB_FILE, 'r') as f:
            content = f.read()
        for m in re.finditer(r'\b(FUN_[0-9A-Fa-f]+|DAT_[0-9A-Fa-f]+|PTR_DAT_[0-9A-Fa-f]+|CONCAT\d+)\b', content):
            existing_stubs.add(m.group(1))

    # Generate stubs
    lines = []
    fun_stubs = []
    dat_stubs = []
    special_stubs = []

    for sym in undefs:
        if sym in existing_stubs:
            continue

        if sym.startswith('FUN_'):
            fun_stubs.append(f'int {sym}() {{ return 0; }}')
        elif sym.startswith('DAT_') or sym.startswith('PTR_DAT_'):
            dat_stubs.append(f'int {sym} = 0;')
        elif sym.startswith('CONCAT'):
            # Ghidra's CONCAT macro - implement as simple concatenation
            special_stubs.append(f'long long {sym}(int hi, int lo) {{ return ((long long)hi << 32) | (unsigned int)lo; }}')
        else:
            # Unknown symbol type
            dat_stubs.append(f'int {sym} = 0;')

    # Read existing file or start fresh
    if os.path.exists(STUB_FILE):
        with open(STUB_FILE, 'r') as f:
            existing = f.read()
    else:
        existing = ""

    # Append new stubs
    new_stubs = []
    if dat_stubs:
        new_stubs.extend(dat_stubs)
    if fun_stubs:
        new_stubs.extend(fun_stubs)
    if special_stubs:
        new_stubs.extend(special_stubs)

    if new_stubs:
        with open(STUB_FILE, 'w', newline='\n') as f:
            if existing:
                f.write(existing.rstrip('\n') + '\n')
            f.write('\n'.join(new_stubs) + '\n')
        print(f"Added {len(new_stubs)} stubs to {os.path.basename(STUB_FILE)}")
    else:
        print("No new stubs needed")

if __name__ == "__main__":
    main()
