#!/usr/bin/env python3
"""Extract assembly from aprog.s for small untested functions"""
import subprocess
import os
import re

APROG = "/mnt/d/Projects/SaturnReverseTest/build/aprog.s"

# Target functions - small ones with proper endings
targets = [
    "FUN_06032530", "FUN_06033338", "FUN_060333A4", "FUN_060348E6",
    "FUN_0602EFDA", "FUN_06033FF4", "FUN_060336AC",
    "FUN_060323B2", "FUN_060323E4", "FUN_0603242A", "FUN_06032504",
    "FUN_06033F90", "FUN_06033FC8",
    "FUN_060359D2", "FUN_060359DA",
    "FUN_0601A5F8", "FUN_0602E450",
    "FUN_0602DC30", "FUN_0602E826", "FUN_0602E84A", "FUN_0602E870",
    "FUN_0602E892", "FUN_0602E69E", "FUN_0602E73A",
    "FUN_06018634",
    "FUN_060344FC",
    "FUN_06032656", "FUN_06032D0E", "FUN_06032FD4",
    "FUN_06033614", "FUN_060337C6",
    "FUN_06035C08",
]

# Read aprog.s once
with open(APROG) as f:
    lines = f.read().replace('\r', '').split('\n')

# Find all function labels
func_lines = {}
for i, line in enumerate(lines):
    if line.startswith('FUN_') and line.endswith(':'):
        func_lines[line[:-1]] = i

for target in sorted(targets):
    if target not in func_lines:
        continue
    start = func_lines[target]
    # Find next function label
    end = start + 40
    for i in range(start + 1, min(start + 40, len(lines))):
        if lines[i].startswith('FUN_') and lines[i].endswith(':'):
            end = i
            break

    print(f"=== {target} ({end - start - 1} lines) ===")
    for i in range(start, end):
        print(f"  {lines[i]}")
    print()
