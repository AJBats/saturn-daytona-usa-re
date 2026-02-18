#!/usr/bin/env python3
"""Verify every pool entry in every function is correctly relocated.

Compares production binary vs free-layout binary. Every 4-byte value in the
binary that looks like an address should either:
- Shift by exactly +4 (in-binary address)
- Stay the same (outside binary / _start range)
"""

import struct
import re
import os

def main():
    proj = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

    with open(os.path.join(proj, 'build', 'aprog.bin'), 'rb') as f:
        prod = f.read()
    with open(os.path.join(proj, 'reimpl', 'build', 'APROG.BIN'), 'rb') as f:
        free = f.read()

    # Load function boundaries
    syms = []
    with open(os.path.join(proj, 'build', 'aprog_syms.txt')) as f:
        for line in f:
            m = re.match(r'FUN_([0-9A-Fa-f]+)\s*=\s*0x([0-9A-Fa-f]+)', line)
            if m:
                syms.append(int(m.group(2), 16))
    syms.sort()

    BINARY_START = 0x06003000
    FUN_START = 0x060030FC  # First FUN_ address

    # Scan every 4-byte aligned position in the binary
    anomalies = []
    stats = {'shifted': 0, 'static_below': 0, 'static_above': 0, 'non_addr': 0, 'anomaly': 0}

    # Start scanning from FUN_ area (offset 0xFC)
    for prod_off in range(0xFC, len(prod) - 3, 4):
        free_off = prod_off + 4  # Everything after _start shifts by 4

        if free_off + 3 >= len(free):
            break

        prod_val = struct.unpack('>I', prod[prod_off:prod_off + 4])[0]
        free_val = struct.unpack('>I', free[free_off:free_off + 4])[0]

        # Only check values that look like addresses in work RAM high
        if not (0x06000000 <= prod_val < 0x06100000):
            stats['non_addr'] += 1
            continue

        diff = free_val - prod_val

        if FUN_START <= prod_val < BINARY_START + len(prod):
            # In-binary address: should shift +4
            if diff == 4:
                stats['shifted'] += 1
            elif diff == 0:
                # This is an address in the binary that DIDN'T shift!
                anomalies.append((prod_off, prod_val, free_val, 'IN_BINARY_NOT_SHIFTED'))
                stats['anomaly'] += 1
            else:
                anomalies.append((prod_off, prod_val, free_val, 'WRONG_SHIFT_%d' % diff))
                stats['anomaly'] += 1
        elif prod_val < FUN_START:
            # Below binary / _start range: should stay same
            if diff == 0:
                stats['static_below'] += 1
            else:
                anomalies.append((prod_off, prod_val, free_val, 'BELOW_BINARY_SHIFTED'))
                stats['anomaly'] += 1
        else:
            # Above binary (runtime data): should stay same
            if diff == 0:
                stats['static_above'] += 1
            else:
                anomalies.append((prod_off, prod_val, free_val, 'ABOVE_BINARY_SHIFTED'))
                stats['anomaly'] += 1

    print("=== Pool Entry Verification ===")
    print("Prod binary: %d bytes" % len(prod))
    print("Free binary: %d bytes" % len(free))
    print()
    print("4-byte values in 0x0600xxxx-0x060Fxxxx range:")
    print("  Correctly shifted +4 (in-binary):  %d" % stats['shifted'])
    print("  Correctly static (below binary):   %d" % stats['static_below'])
    print("  Correctly static (above binary):   %d" % stats['static_above'])
    print("  Non-address values skipped:        %d" % stats['non_addr'])
    print("  ANOMALIES:                         %d" % stats['anomaly'])
    print()

    if anomalies:
        print("!!! ANOMALIES FOUND !!!")
        # Find which function each anomaly belongs to
        for prod_off, prod_val, free_val, kind in anomalies[:50]:
            addr = BINARY_START + prod_off
            # Find parent function
            parent = None
            for i, s in enumerate(syms):
                if s <= addr:
                    parent = s
                else:
                    break
            print("  offset 0x%05X (addr 0x%08X, in FUN_%08X): prod=0x%08X free=0x%08X [%s]" % (
                prod_off, addr, parent or 0, prod_val, free_val, kind))
        if len(anomalies) > 50:
            print("  ... and %d more" % (len(anomalies) - 50))
    else:
        print("PASS: All pool entries correctly relocated!")

if __name__ == '__main__':
    main()
