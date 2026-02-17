#!/usr/bin/env python3
"""find_stale_addresses.py - Find stale code-range addresses in the free-layout binary."""
import struct, re, os

ORIG_PATH = "d:/Projects/SaturnReverseTest/build/aprog.bin"
FREE_PATH = "d:/Projects/SaturnReverseTest/reimpl/build/APROG.BIN"
SYMS_PATH = "d:/Projects/SaturnReverseTest/build/aprog_syms.txt"

CODE_LO = 0x06003000
CODE_HI = 0x06060000
BASE_ADDR = 0x06003000
SHIFT = 4

with open(ORIG_PATH, "rb") as f:
    orig = f.read()
with open(FREE_PATH, "rb") as f:
    free = f.read()

print("Original binary: {:,} bytes ({})".format(len(orig), ORIG_PATH))
print("Free-layout binary: {:,} bytes ({})".format(len(free), FREE_PATH))
print("Size difference: {:+,} bytes (expected +4)".format(len(free) - len(orig)))
print()

symbols = []
with open(SYMS_PATH, "r") as f:
    for line in f:
        line = line.strip()
        m = re.match(r"(\w+)\s*=\s*0x([0-9A-Fa-f]+)\s*;", line)
        if m:
            symbols.append((int(m.group(2), 16), m.group(1)))
symbols.sort(key=lambda x: x[0])

def find_function(addr):
    best = None
    for sym_addr, sym_name in symbols:
        if sym_addr <= addr:
            best = (sym_addr, sym_name)
        else:
            break
    if best:
        return "{} (0x{:08X})".format(best[1], best[0])
    return "unknown"

def is_code_range(val):
    return CODE_LO <= val < CODE_HI

def read_u32be(data, offset):
    if offset + 4 > len(data):
        return None
    return struct.unpack(">I", data[offset:offset+4])[0]

sep = "=" * 80

# ===== PART 1: _start pool region (0x60 to 0xFB) =====
print(sep)
print("PART 1: _start pool region (offsets 0x60-0xFB)")
print("  Code-range pool entries should be original_value + 4 in free-layout")
print(sep)

pool_start = 0x60
pool_end = 0xFC
pool_stale = []
pool_correct = []
pool_non_code = []

for off in range(pool_start, pool_end, 4):
    orig_val = read_u32be(orig, off)
    free_val = read_u32be(free, off)
    if orig_val is None or free_val is None:
        continue
    if is_code_range(orig_val):
        expected = orig_val + SHIFT
        if free_val == orig_val:
            pool_stale.append((off, orig_val, free_val))
        elif free_val == expected:
            pool_correct.append((off, orig_val, free_val))
        else:
            print("  [UNEXPECTED] Pool offset 0x{:04X}: orig=0x{:08X}, free=0x{:08X}, expected=0x{:08X}".format(
                off, orig_val, free_val, expected))
    else:
        pool_non_code.append((off, orig_val, free_val))

print()
print("  Pool entries (4-byte aligned, 0x60-0xFB):")
print("    Code-range entries correctly shifted (+4): {}".format(len(pool_correct)))
print("    Code-range entries STALE (not shifted):    {}".format(len(pool_stale)))
print("    Non-code-range entries:                    {}".format(len(pool_non_code)))

if pool_stale:
    print()
    print("  STALE pool entries:")
    for off, oval, fval in pool_stale:
        mem_addr = BASE_ADDR + off
        func = find_function(oval)
        print("    Offset 0x{:04X} (mem 0x{:08X}): value=0x{:08X} -> {}".format(off, mem_addr, oval, func))

if pool_correct:
    print()
    print("  Correctly shifted pool entries:")
    for off, oval, fval in pool_correct:
        print("    Offset 0x{:04X}: 0x{:08X} -> 0x{:08X} (+4 OK)".format(off, oval, fval))

print()

# ===== PART 2: Shifted region - 4-byte-aligned scan =====
print(sep)
print("PART 2: Shifted region (free offset >= 0x100) - 4-byte aligned")
print("  Comparing free[i] vs orig[i-4]; stale if identical and in code range")
print(sep)

stale_4 = []
shifted_correct_4 = 0
total_code_range_4 = 0

scan_start_free = 0x100
scan_end_free = min(len(free), len(orig) + SHIFT)

for fi in range(scan_start_free, scan_end_free - 3, 4):
    oi = fi - SHIFT
    if oi < 0 or oi + 4 > len(orig):
        continue
    free_val = read_u32be(free, fi)
    orig_val = read_u32be(orig, oi)
    if free_val is None or orig_val is None:
        continue
    if is_code_range(orig_val):
        total_code_range_4 += 1
        expected = orig_val + SHIFT
        if free_val == orig_val:
            stale_4.append((oi, fi, orig_val))
        elif free_val == expected:
            shifted_correct_4 += 1

print()
print("  4-byte-aligned scan results:")
print("    Total code-range values in original:      {:,}".format(total_code_range_4))
print("    Correctly shifted (+4):                    {:,}".format(shifted_correct_4))
print("    STALE (identical, not shifted):            {:,}".format(len(stale_4)))
print("    Other (different value):                   {:,}".format(total_code_range_4 - shifted_correct_4 - len(stale_4)))

if stale_4:
    print()
    print("  Stale 4-byte-aligned values:")
    for oi, fi, val in stale_4[:200]:
        mem_orig = BASE_ADDR + oi
        mem_free = BASE_ADDR + fi
        containing = find_function(mem_orig)
        target_fn = find_function(val)
        print("    orig_off=0x{:06X} (mem 0x{:08X}) | free_off=0x{:06X} (mem 0x{:08X}) | value=0x{:08X} -> target: {} | in: {}".format(
            oi, mem_orig, fi, mem_free, val, target_fn, containing))
    if len(stale_4) > 200:
        print("    ... and {} more".format(len(stale_4) - 200))

print()

# ===== PART 3: 2-byte-aligned (not 4-byte-aligned) scan =====
print(sep)
print("PART 3: Shifted region - 2-byte aligned (not 4-byte aligned)")
print("  Checking odd half-word boundaries for stale code-range addresses")
print(sep)

stale_2 = []

for fi in range(scan_start_free + 2, scan_end_free - 3, 4):
    oi = fi - SHIFT
    if oi < 0 or oi + 4 > len(orig):
        continue
    free_val = read_u32be(free, fi)
    orig_val = read_u32be(orig, oi)
    if free_val is None or orig_val is None:
        continue
    if is_code_range(orig_val) and free_val == orig_val:
        stale_2.append((oi, fi, orig_val))

print()
print("  2-byte-aligned (not 4-byte-aligned) stale values: {:,}".format(len(stale_2)))

if stale_2:
    for oi, fi, val in stale_2[:200]:
        mem_orig = BASE_ADDR + oi
        mem_free = BASE_ADDR + fi
        containing = find_function(mem_orig)
        target_fn = find_function(val)
        print("    orig_off=0x{:06X} (mem 0x{:08X}) | free_off=0x{:06X} (mem 0x{:08X}) | value=0x{:08X} -> target: {} | in: {}".format(
            oi, mem_orig, fi, mem_free, val, target_fn, containing))
    if len(stale_2) > 200:
        print("    ... and {} more".format(len(stale_2) - 200))

print()

# ===== PART 4: Padding verification =====
print(sep)
print("PART 4: Padding verification")
print(sep)

padding = free[0xFC:0x100]
print("  Padding bytes at free[0xFC:0x100]: {}".format(padding.hex()))
if all(b == 0 for b in padding):
    print("  Padding is all zeros (as expected)")
else:
    print("  WARNING: Padding is NOT all zeros!")

print()

# ===== PART 5: Byte-for-byte comparison =====
print(sep)
print("PART 5: Byte-for-byte comparison of shifted region")
print(sep)

mismatches = 0
first_mismatches = []
for fi in range(scan_start_free, scan_end_free):
    oi = fi - SHIFT
    if oi < 0 or oi >= len(orig):
        continue
    if free[fi] != orig[oi]:
        mismatches += 1
        if len(first_mismatches) < 20:
            first_mismatches.append((oi, fi, orig[oi], free[fi]))

print("  Total byte mismatches (free[i] vs orig[i-4]): {:,}".format(mismatches))
if first_mismatches:
    print("  First {} mismatches:".format(len(first_mismatches)))
    for oi, fi, ob, fb in first_mismatches:
        mem = BASE_ADDR + oi
        func = find_function(mem)
        print("    orig[0x{:06X}]=0x{:02X} vs free[0x{:06X}]=0x{:02X} (mem 0x{:08X}, {})".format(
            oi, ob, fi, fb, mem, func))
print()

# ===== SUMMARY =====
print(sep)
print("SUMMARY")
print(sep)
total_stale = len(pool_stale) + len(stale_4) + len(stale_2)
print("  Pool stale entries:           {}".format(len(pool_stale)))
print("  4-byte-aligned stale values:  {}".format(len(stale_4)))
print("  2-byte-aligned stale values:  {}".format(len(stale_2)))
print("  TOTAL STALE VALUES:           {}".format(total_stale))
print()
if total_stale == 0:
    print("  All code-range addresses appear to be correctly shifted!")
else:
    print("  {} addresses need to be fixed (shifted by +4).".format(total_stale))
