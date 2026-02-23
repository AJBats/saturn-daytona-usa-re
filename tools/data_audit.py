#!/usr/bin/env python3
"""Audit data entries across all L3 source files.

Scans reimpl/src/*.s for literal pool entries (.4byte 0x..., .2byte 0x...)
and categorizes them by value range. Reports summary statistics and
per-file breakdowns.

Usage:
    python tools/data_audit.py
    python tools/data_audit.py --top 20
    python tools/data_audit.py --detail <tu_name>
"""

import argparse
import re
from pathlib import Path

PROJ = Path(__file__).resolve().parent.parent
SRC_DIR = PROJ / "reimpl" / "src"

# Saturn memory map ranges for classification
CATEGORIES = [
    ("WRAM_HIGH_ptr",   lambda v: 0x06000000 <= v <= 0x060FFFFF),
    ("WRAM_HIGH_ct",    lambda v: 0x26000000 <= v <= 0x260FFFFF),  # cache-through
    ("WRAM_LOW_ptr",    lambda v: 0x00200000 <= v <= 0x002FFFFF),
    ("VDP1_VRAM",       lambda v: 0x05C00000 <= v <= 0x05CFFFFF),
    ("VDP1_reg",        lambda v: 0x05D00000 <= v <= 0x05D0FFFF),
    ("VDP2_VRAM",       lambda v: 0x05E00000 <= v <= 0x05EFFFFF),
    ("VDP2_CRAM",       lambda v: 0x05F00000 <= v <= 0x05F00FFF),
    ("VDP2_reg",        lambda v: 0x05F80000 <= v <= 0x05F8FFFF),
    ("SCU_reg",         lambda v: 0x25FE0000 <= v <= 0x25FEFFFF),
    ("SCSP_reg",        lambda v: 0x25B00000 <= v <= 0x25B00FFF),
    ("SCSP_slot",       lambda v: 0x25B00000 <= v <= 0x25B003FF),
    ("Sound_RAM",       lambda v: 0x25A00000 <= v <= 0x25A7FFFF),
    ("SMPC_reg",        lambda v: 0x20100000 <= v <= 0x201000FF),
    # BIOS_ROM omitted — values in 0x00000000-0x0007FFFF are almost always
    # small constants or fixed-point, not BIOS function pointers.
    ("Backup_RAM",      lambda v: 0x00180000 <= v <= 0x0018FFFF),
    ("CD_block",        lambda v: 0x05800000 <= v <= 0x058FFFFF),
    ("SH2_periph",      lambda v: 0xFFFFFE00 <= v <= 0xFFFFFFFF),
    ("MINIT",           lambda v: v == 0x01000000),
    ("SINIT",           lambda v: v == 0x01800000),
    ("zero",            lambda v: v == 0),
    ("fixpt_pos",       lambda v: 0x00010000 <= v <= 0x04FFFFFF and v & 0xFFFF == 0),
    ("fixpt_neg",       lambda v: 0xFB000000 <= v <= 0xFFFF0000 and v & 0xFFFF == 0),
    ("fixpt_frac",      lambda v: 0x00000001 <= v <= 0x0000FFFF),  # possibly 0.x fraction
    ("small_int",       lambda v: 0x00010000 <= v <= 0x000FFFFF),  # small integer or 16.16
    ("neg_const",       lambda v: v >= 0xFFFF0000),
]


def classify_value(val):
    """Classify a 32-bit value into a category."""
    for name, test in CATEGORIES:
        if test(val):
            return name
    return "other"


def classify_word(val):
    """Classify a 16-bit value."""
    if val == 0:
        return "zero"
    if val == 0xFFFF:
        return "ffff_sentinel"
    if val <= 0x00FF:
        return "small_byte"
    if val >= 0xFF00:
        return "neg_byte"
    return "word_const"


def scan_file(path):
    """Scan an L3 file and extract all literal pool entries."""
    entries = []
    lines = path.read_text(encoding="utf-8", errors="replace").splitlines()

    # Pattern: .L_pool_XXXXXXXX: or .L_wpool_XXXXXXXX:
    pool_label_re = re.compile(r'^\.L_(w?pool_[0-9A-Fa-f]{8}):')
    # Pattern: .4byte  0xNNNNNNNN
    fourbyte_re = re.compile(r'^\s+\.4byte\s+0x([0-9A-Fa-f]{8})')
    # Pattern: .2byte  0xNNNN
    twobyte_re = re.compile(r'^\s+\.2byte\s+0x([0-9A-Fa-f]{4})')
    # Pattern: .4byte  symbol_name (already annotated)
    sym_re = re.compile(r'^\s+\.4byte\s+([a-zA-Z_]\w+)')
    # Pattern: .word 0xNNNN /* UNKNOWN */
    unknown_re = re.compile(r'^\s+\.word\s+0x([0-9A-Fa-f]{4})\s+/\*\s*UNKNOWN\s*\*/')

    current_label = None
    for i, line in enumerate(lines):
        m = pool_label_re.match(line)
        if m:
            current_label = m.group(1)
            continue

        m = fourbyte_re.match(line)
        if m:
            val = int(m.group(1), 16)
            cat = classify_value(val)
            entries.append({
                "type": ".4byte",
                "value": val,
                "category": cat,
                "label": current_label,
                "line": i + 1,
                "has_comment": "/*" in line,
            })
            current_label = None
            continue

        m = twobyte_re.match(line)
        if m:
            val = int(m.group(1), 16)
            cat = classify_word(val)
            entries.append({
                "type": ".2byte",
                "value": val,
                "category": cat,
                "label": current_label,
                "line": i + 1,
                "has_comment": "/*" in line,
            })
            current_label = None
            continue

        m = unknown_re.match(line)
        if m:
            val = int(m.group(1), 16)
            entries.append({
                "type": ".word_unk",
                "value": val,
                "category": "unknown_word",
                "label": None,
                "line": i + 1,
                "has_comment": True,
            })
            continue

        m = sym_re.match(line)
        if m:
            entries.append({
                "type": ".4byte_sym",
                "value": m.group(1),
                "category": "symbol_ref",
                "label": current_label,
                "line": i + 1,
                "has_comment": "/*" in line,
            })
            current_label = None
            continue

        # Reset label if we hit a non-data line
        if not line.strip().startswith("."):
            current_label = None

    return entries


def main():
    parser = argparse.ArgumentParser(description="Audit L3 data entries")
    parser.add_argument("--top", type=int, default=10,
                        help="Show top N files by literal count")
    parser.add_argument("--detail", type=str, default=None,
                        help="Show detail for a specific TU")
    args = parser.parse_args()

    files = sorted(SRC_DIR.glob("*.s"))
    print(f"Scanning {len(files)} L3 files...\n")

    all_entries = {}
    category_totals = {}

    for f in files:
        entries = scan_file(f)
        name = f.stem
        all_entries[name] = entries
        for e in entries:
            cat = e["category"]
            category_totals[cat] = category_totals.get(cat, 0) + 1

    # Summary
    total = sum(len(e) for e in all_entries.values())
    literals = sum(len([x for x in e if x["type"] in (".4byte", ".2byte")])
                   for e in all_entries.values())
    symbols = sum(len([x for x in e if x["type"] == ".4byte_sym"])
                  for e in all_entries.values())
    unknowns = sum(len([x for x in e if x["type"] == ".word_unk"])
                   for e in all_entries.values())
    commented = sum(len([x for x in e if x["has_comment"] and x["type"] != ".word_unk"])
                    for e in all_entries.values())

    print("=" * 60)
    print("DATA ENTRY SUMMARY")
    print("=" * 60)
    print(f"  Total entries:        {total:,}")
    print(f"  Symbol references:    {symbols:,} (already named)")
    print(f"  Literal values:       {literals:,} (need annotation)")
    print(f"  UNKNOWN words:        {unknowns:,}")
    print(f"  Already commented:    {commented:,}")
    print()

    # Category breakdown
    print("CATEGORY BREAKDOWN")
    print("-" * 60)
    for cat, count in sorted(category_totals.items(), key=lambda x: -x[1]):
        pct = count / total * 100
        print(f"  {cat:20s}  {count:5d}  ({pct:5.1f}%)")
    print()

    # Top files by literal count
    print(f"TOP {args.top} FILES BY LITERAL COUNT")
    print("-" * 60)
    file_lits = [(name, len([x for x in entries if x["type"] in (".4byte", ".2byte")]))
                 for name, entries in all_entries.items()]
    file_lits.sort(key=lambda x: -x[1])
    for name, count in file_lits[:args.top]:
        print(f"  {name:40s}  {count:5d}")
    print()

    # Hardware register entries (immediately classifiable)
    hw_cats = {"VDP1_reg", "VDP2_reg", "SCU_reg", "SCSP_reg", "SCSP_slot",
               "SMPC_reg", "SH2_periph", "CD_block"}
    hw_count = sum(v for k, v in category_totals.items() if k in hw_cats)
    print(f"HARDWARE REGISTER ENTRIES: {hw_count}")
    print("  (These can be annotated immediately from the memory map)")
    print()

    # Fixed-point entries
    fp_count = category_totals.get("fixpt_pos", 0) + category_totals.get("fixpt_neg", 0)
    print(f"FIXED-POINT CONSTANTS: {fp_count}")
    print("  (16.16 format — value = hex >> 16)")
    print()

    # Detail mode
    if args.detail:
        name = args.detail
        if name not in all_entries:
            print(f"ERROR: {name} not found")
            return
        entries = all_entries[name]
        print(f"DETAIL: {name}")
        print("-" * 60)
        for e in entries:
            if e["type"] == ".4byte_sym":
                val_str = e["value"]
            elif e["type"] == ".4byte":
                val_str = f"0x{e['value']:08X}"
            elif e["type"] in (".2byte", ".word_unk"):
                val_str = f"0x{e['value']:04X}"
            else:
                val_str = str(e["value"])
            label = e["label"] or "(no label)"
            cmt = " [commented]" if e["has_comment"] else ""
            print(f"  L{e['line']:4d}  {e['type']:12s}  {val_str:20s}  "
                  f"{e['category']:20s}  {label}{cmt}")


if __name__ == "__main__":
    main()
