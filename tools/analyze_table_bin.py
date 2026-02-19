#!/usr/bin/env python3
"""Analyze TABLE.BIN structure — find sections, entry patterns, potential offsets."""

import struct
import sys

path = sys.argv[1] if len(sys.argv) > 1 else "build/disc/files/TABLE.BIN"

with open(path, "rb") as f:
    data = f.read()

print(f"File: {path}")
print(f"Size: {len(data)} bytes (0x{len(data):X})")
print()

# --- Pass 1: Read as 16-bit big-endian values ---
n16 = len(data) // 2
vals16 = struct.unpack(f">{n16}H", data[:n16*2])

# Find where monotonic increase breaks
print("=== 16-bit big-endian analysis ===")
prev = vals16[0]
breaks = []
for i in range(1, n16):
    if vals16[i] < prev:
        breaks.append((i, prev, vals16[i]))
    prev = vals16[i]

if breaks:
    print(f"Monotonic breaks at {len(breaks)} points:")
    for idx, prev_v, cur_v in breaks[:20]:
        print(f"  entry[{idx}] (offset 0x{idx*2:04X}): 0x{prev_v:04X} -> 0x{cur_v:04X}")
else:
    print(f"ALL {n16} entries are monotonically increasing")
    print(f"  First: 0x{vals16[0]:04X}")
    print(f"  Last:  0x{vals16[-1]:04X}")

# --- Stride analysis ---
print()
print("=== Stride (delta between consecutive entries) ===")
deltas = [vals16[i] - vals16[i-1] for i in range(1, min(n16, 100))]
print(f"  First 100 deltas: min={min(deltas)}, max={max(deltas)}, avg={sum(deltas)/len(deltas):.1f}")

# Check if stride changes over the file
for start in [0, n16//4, n16//2, 3*n16//4]:
    end = min(start + 100, n16)
    if end <= start + 1:
        continue
    d = [vals16[i] - vals16[i-1] for i in range(start+1, end)]
    print(f"  Entries [{start}-{end}] (offset 0x{start*2:04X}): "
          f"min={min(d)}, max={max(d)}, avg={sum(d)/len(d):.1f}")

# --- Pass 2: Read as 32-bit big-endian values ---
n32 = len(data) // 4
vals32 = struct.unpack(f">{n32}I", data[:n32*4])

print()
print("=== 32-bit big-endian analysis ===")
# Look for 0x0600xxxx addresses (APROG.BIN range)
aprog_refs = []
for i, v in enumerate(vals32):
    if 0x06003000 <= v <= 0x06063690:
        aprog_refs.append((i, v))

if aprog_refs:
    print(f"Found {len(aprog_refs)} potential APROG.BIN address references:")
    for idx, v in aprog_refs[:30]:
        print(f"  offset 0x{idx*4:04X}: 0x{v:08X}")
else:
    print("No direct 0x0600xxxx addresses found (expected)")

# Look for values that could be offsets from 0x06003000
print()
print("=== Offset hypothesis: value + 0x06003000 ===")
offset_refs = []
for i, v in enumerate(vals16):
    target = v + 0x06003000
    if 0x06003000 <= target <= 0x06063690:
        # Only flag interesting ones (not trivially all of them since low values will match)
        pass  # all small values would match, not useful

# Better: check if 32-bit values could be offsets
print("32-bit values as offsets from 0x06003000:")
for i, v in enumerate(vals32):
    target = v + 0x06003000
    if 0x06003000 <= target <= 0x060FFFFF:
        if v > 0x1000:  # skip trivially small
            offset_refs.append((i*4, v, target))
if offset_refs:
    for off, val, target in offset_refs[:20]:
        print(f"  offset 0x{off:04X}: value 0x{val:08X} -> target 0x{target:08X}")
else:
    print("  None found")

# --- Pass 3: Look for section boundaries ---
print()
print("=== Section boundary scan ===")
# Look for runs of identical high bytes
prev_hi = data[0]
section_starts = [0]
for i in range(2, len(data), 2):
    hi = data[i]
    if hi != prev_hi and abs(hi - prev_hi) > 1:
        section_starts.append(i)
    prev_hi = hi

if len(section_starts) > 1:
    print(f"Potential section boundaries: {len(section_starts)}")
    for s in section_starts[:20]:
        print(f"  offset 0x{s:04X}: bytes {data[s]:02X} {data[s+1]:02X}")

# --- Pass 4: Look for 0xFFFF pattern ---
print()
print("=== 0xFFFF pattern scan ===")
ffff_start = None
for i in range(0, len(data) - 1, 2):
    w = (data[i] << 8) | data[i+1]
    if w == 0xFFFF and ffff_start is None:
        ffff_start = i
    elif w != 0xFFFF and ffff_start is not None:
        # Check if it was a run
        if i - ffff_start >= 4:
            pass  # could be interleaved FFFF
        ffff_start = None

# More targeted: find where FFFF appears as every-other-16bit-word
print("Scanning for FFFF xxxx 32-bit pattern:")
ffff_pattern_start = None
for i in range(0, len(data) - 3, 4):
    hi_word = (data[i] << 8) | data[i+1]
    if hi_word == 0xFFFF:
        if ffff_pattern_start is None:
            ffff_pattern_start = i
    else:
        if ffff_pattern_start is not None and i - ffff_pattern_start >= 16:
            print(f"  Run of FFFF xxxx from 0x{ffff_pattern_start:04X} to 0x{i:04X} "
                  f"({(i - ffff_pattern_start)//4} entries)")
        ffff_pattern_start = None

if ffff_pattern_start is not None:
    end = len(data)
    print(f"  Run of FFFF xxxx from 0x{ffff_pattern_start:04X} to 0x{end:04X} "
          f"({(end - ffff_pattern_start)//4} entries)")
    # Show values
    print("  First 10 values in FFFF section:")
    for j in range(ffff_pattern_start, min(ffff_pattern_start + 40, len(data)), 4):
        v32 = struct.unpack(">I", data[j:j+4])[0]
        v_signed = struct.unpack(">i", data[j:j+4])[0]
        print(f"    0x{j:04X}: 0x{v32:08X} (signed: {v_signed})")

# --- Pass 5: value range histogram ---
print()
print("=== Value range summary ===")
print(f"16-bit range: 0x{min(vals16):04X} to 0x{max(vals16):04X}")
print(f"Max 16-bit value: {max(vals16)} = 0x{max(vals16):04X}")
print(f"If offsets into SCROLL.BIN ({327736} bytes = 0x{327736:X}): "
      f"{'YES fits' if max(vals16) < 327736 else 'NO overflow'}")
print(f"Total 16-bit entries: {n16}")
