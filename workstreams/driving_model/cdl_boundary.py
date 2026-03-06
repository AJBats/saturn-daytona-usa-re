#!/usr/bin/env python3
"""CDL Boundary Analysis — racing vs menu diff.

Compares CDL coverage reports from racing and menu captures to identify
functions that execute ONLY during racing (driving model candidates).

Usage:
    python workstreams/driving_model/cdl_boundary.py \
        build/cdl_racing.csv build/cdl_menu.csv \
        [--min-code 2] [--output workstreams/driving_model/function_set.md]
"""
import argparse
import csv
import sys


def load_cdl_csv(path):
    """Load CDL CSV, skipping the summary header lines."""
    funcs = {}
    with open(path) as f:
        # Skip until we find the CSV header
        for line in f:
            if line.startswith("addr,"):
                break
        reader = csv.DictReader(f, fieldnames=[
            "addr", "name", "size", "code_bytes", "code_pct",
            "read_bytes", "write_bytes"
        ])
        for row in reader:
            addr = row["addr"]
            funcs[addr] = {
                "name": row["name"],
                "size": int(row["size"]),
                "code": int(row["code_bytes"]),
                "code_pct": float(row["code_pct"]),
                "read": int(row["read_bytes"]),
                "write": int(row["write_bytes"]),
            }
    return funcs


def main():
    parser = argparse.ArgumentParser(description="CDL boundary analysis")
    parser.add_argument("racing_csv", help="Racing CDL CSV")
    parser.add_argument("menu_csv", help="Menu CDL CSV")
    parser.add_argument("--min-code", type=int, default=2,
                        help="Min code bytes to count as exercised (default: 2)")
    parser.add_argument("--output", default="",
                        help="Output markdown file path")
    args = parser.parse_args()

    racing = load_cdl_csv(args.racing_csv)
    menu = load_cdl_csv(args.menu_csv)

    racing_only = []
    shared = []
    menu_only = []

    for addr in racing:
        r = racing[addr]
        m = menu.get(addr, {"code": 0})
        r_has_code = r["code"] >= args.min_code
        m_has_code = m["code"] >= args.min_code if isinstance(m, dict) else False

        if r_has_code and not m_has_code:
            racing_only.append((addr, r))
        elif r_has_code and m_has_code:
            shared.append((addr, r))

    for addr in menu:
        m = menu[addr]
        r = racing.get(addr, {"code": 0})
        m_has_code = m["code"] >= args.min_code
        r_has_code = r["code"] >= args.min_code if isinstance(r, dict) else False

        if m_has_code and not r_has_code:
            menu_only.append((addr, m))

    # Sort by address
    racing_only.sort(key=lambda x: x[0])
    shared.sort(key=lambda x: x[0])
    menu_only.sort(key=lambda x: x[0])

    # Summary
    print(f"=== CDL Boundary Analysis ===")
    print(f"Racing CDL: {args.racing_csv}")
    print(f"Menu CDL:   {args.menu_csv}")
    print(f"Min code threshold: {args.min_code} bytes")
    print()
    print(f"RACING_ONLY: {len(racing_only)} functions (execute during racing but NOT menu)")
    print(f"SHARED:      {len(shared)} functions (execute during BOTH)")
    print(f"MENU_ONLY:   {len(menu_only)} functions (execute during menu but NOT racing)")
    print()

    # Total code bytes
    racing_only_bytes = sum(r["code"] for _, r in racing_only)
    shared_bytes = sum(r["code"] for _, r in shared)
    print(f"Racing-only code bytes: {racing_only_bytes:,}")
    print(f"Shared code bytes:      {shared_bytes:,}")
    print()

    # Find contiguous blocks in racing-only
    print("=== Contiguous Racing-Only Blocks ===")
    if racing_only:
        blocks = []
        block_start = racing_only[0]
        block_end = racing_only[0]
        block_funcs = [racing_only[0]]

        for i in range(1, len(racing_only)):
            addr = racing_only[i][0]
            prev_addr = racing_only[i-1][0]
            prev_size = racing_only[i-1][1]["size"]
            # Check if this function is within 256 bytes of the previous one's end
            prev_end = int(prev_addr, 16) + prev_size
            curr_start = int(addr, 16)
            if curr_start - prev_end <= 256:
                block_end = racing_only[i]
                block_funcs.append(racing_only[i])
            else:
                blocks.append((block_start, block_end, block_funcs))
                block_start = racing_only[i]
                block_end = racing_only[i]
                block_funcs = [racing_only[i]]

        blocks.append((block_start, block_end, block_funcs))

        for start, end, funcs in blocks:
            start_addr = int(start[0], 16)
            end_addr = int(end[0], 16) + end[1]["size"]
            span = end_addr - start_addr
            code_bytes = sum(f["code"] for _, f in funcs)
            print(f"  {start[0]}-0x{end_addr:08X} ({span:,} bytes, {len(funcs)} functions, {code_bytes} code bytes)")
            if len(funcs) <= 8:
                for addr, f in funcs:
                    print(f"    {addr} {f['name']:<40} {f['code']:>4} code bytes")
    print()

    # Print racing-only list
    print("=== RACING_ONLY Functions ===")
    print(f"{'Address':<12} {'Name':<44} {'Size':>6} {'Code':>6} {'Cov%':>6}")
    print("-" * 80)
    for addr, r in racing_only:
        print(f"{addr:<12} {r['name']:<44} {r['size']:>6} {r['code']:>6} {r['code_pct']:>5.1f}%")

    print()
    print("=== SHARED Functions ===")
    print(f"{'Address':<12} {'Name':<44} {'Size':>6} {'Code':>6} {'Cov%':>6}")
    print("-" * 80)
    for addr, r in shared:
        print(f"{addr:<12} {r['name']:<44} {r['size']:>6} {r['code']:>6} {r['code_pct']:>5.1f}%")

    # Write markdown output if requested
    if args.output:
        with open(args.output, "w") as f:
            f.write("# Driving Model Function Set (CDL-Validated)\n\n")
            f.write("Generated by `cdl_boundary.py` from empirical CDL captures.\n")
            f.write("CDL records which bytes the CPU executed during racing vs menu idle.\n\n")
            f.write(f"- **Racing capture**: 300 frames at rolling start\n")
            f.write(f"- **Menu capture**: 300 frames at mode select (idle)\n")
            f.write(f"- **Threshold**: {args.min_code}+ code bytes = exercised\n\n")
            f.write(f"## Summary\n\n")
            f.write(f"| Category | Functions | Code Bytes |\n")
            f.write(f"|----------|-----------|------------|\n")
            f.write(f"| RACING_ONLY | {len(racing_only)} | {racing_only_bytes:,} |\n")
            f.write(f"| SHARED | {len(shared)} | {shared_bytes:,} |\n")
            f.write(f"| MENU_ONLY | {len(menu_only)} | — |\n\n")
            f.write(f"## RACING_ONLY ({len(racing_only)} functions)\n\n")
            f.write(f"These execute during racing but NOT during menu idle.\n")
            f.write(f"This is the driving model + racing-specific code.\n\n")
            f.write(f"| Address | Name | Size | Code Bytes | Coverage |\n")
            f.write(f"|---------|------|------|------------|----------|\n")
            for addr, r in racing_only:
                f.write(f"| {addr} | {r['name']} | {r['size']} | {r['code']} | {r['code_pct']:.1f}% |\n")
            f.write(f"\n## SHARED ({len(shared)} functions)\n\n")
            f.write(f"These execute during both racing and menu — system/utility code.\n\n")
            f.write(f"| Address | Name | Size | Code Bytes | Coverage |\n")
            f.write(f"|---------|------|------|------------|----------|\n")
            for addr, r in shared:
                f.write(f"| {addr} | {r['name']} | {r['size']} | {r['code']} | {r['code_pct']:.1f}% |\n")
        print(f"\nMarkdown written to {args.output}")

    return 0


if __name__ == "__main__":
    sys.exit(main())
