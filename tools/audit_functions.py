#!/usr/bin/env python3
"""audit_functions.py -- Validate reimpl function coverage against original aprog.s.

Single-command sanity check: are all 1234 functions accounted for?
Compares compiled ELF section sizes against original function slot sizes
derived from aprog.s label addresses.

Usage:
    python tools/audit_functions.py                # Full report
    python tools/audit_functions.py --summary      # Quick summary
    python tools/audit_functions.py --stubs        # List all stub functions
    python tools/audit_functions.py --overflow     # List all overflowing functions
    python tools/audit_functions.py --gaps         # Top 30 biggest gaps
    python tools/audit_functions.py --json         # Machine-readable JSON
    python tools/audit_functions.py --dashboard    # Update dashboard/function_audit.md
"""

import argparse
import json
import os
import re
import subprocess
import sys
from collections import OrderedDict

PROJDIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
APROG_S = os.path.join(PROJDIR, "build", "aprog.s")
ELF = os.path.join(PROJDIR, "reimpl", "build", "daytona.elf")
OBJDUMP = os.path.join(PROJDIR, "tools", "sh-elf", "bin", "sh-elf-objdump")
DASHBOARD = os.path.join(PROJDIR, "dashboard", "function_audit.md")

# Known data regions mislabeled as functions by the disassembler.
# These are large data tables (parameter tables, lookup tables, strings)
# that live at the tail of the binary. Their "slot" extends to end-of-binary
# and would distort deficit calculations.
DATA_REGIONS = {
    "FUN_06046E48",  # 116KB data tail: param tables, LUTs, strings
}

# Convert Windows path to WSL path
def wsl_path(p):
    p = p.replace("\\", "/")
    # D:/foo -> /mnt/d/foo
    if len(p) >= 2 and p[1] == ":":
        return "/mnt/" + p[0].lower() + p[2:]
    return p


def get_original_functions():
    """Extract all FUN_ labels from aprog.s with their addresses, compute slot sizes."""
    funcs = []
    with open(APROG_S, "r") as f:
        for line in f:
            m = re.match(r'^(FUN_[0-9a-fA-F]+):', line)
            if m:
                name = m.group(1).upper()
                addr = int(name.replace("FUN_", ""), 16)
                funcs.append((addr, name))

    funcs.sort()

    # Compute slot sizes (distance to next function)
    slots = OrderedDict()
    for i, (addr, name) in enumerate(funcs):
        if i + 1 < len(funcs):
            next_addr = funcs[i + 1][0]
            slot_size = next_addr - addr
        else:
            # Last function -- slot extends to end of binary
            # aprog.s covers 0x06003000 to 0x06063690
            slot_size = 0x06063690 - addr
        slots[name] = {"addr": addr, "slot_size": slot_size}

    return slots


def get_elf_sections():
    """Get compiled section sizes from reimpl ELF via objdump."""
    if not os.path.exists(ELF):
        print(f"ERROR: ELF not found: {ELF}", file=sys.stderr)
        print("Run 'cd reimpl && make' first.", file=sys.stderr)
        sys.exit(1)

    result = subprocess.run(
        ["wsl", "-d", "Ubuntu", "-e", "bash", "-c",
         f'"{wsl_path(OBJDUMP)}" -h "{wsl_path(ELF)}" | tr -d "\\r"'],
        capture_output=True, text=True
    )

    sections = {}
    for line in result.stdout.splitlines():
        line = line.strip()
        # Match: IDX .func_FUN_XXXXXXXX SIZE ADDR ...
        m = re.match(r'\d+\s+\.func_(FUN_[0-9A-Fa-f]+)\s+([0-9a-f]+)\s+([0-9a-f]+)', line)
        if m:
            name = m.group(1).upper()
            size = int(m.group(2), 16)
            sections[name] = size

    return sections


def classify(name, slot_size, compiled_size):
    """Classify a function's health."""
    if name in DATA_REGIONS:
        return "data_region"
    if compiled_size <= 4:
        return "stub_4"
    if slot_size == 0:
        return "unknown"

    ratio = compiled_size / slot_size
    if compiled_size <= 12:
        return "stub_asm"  # inline asm stub (12 bytes = section overhead)
    if ratio < 0.25:
        return "tiny"
    if ratio < 0.50:
        return "small"
    if ratio < 0.90:
        return "medium"
    if ratio <= 1.10:
        return "good"
    return "overflow"


def build_report(slots, sections):
    """Build a per-function report."""
    report = []
    for name, info in slots.items():
        slot_size = info["slot_size"]
        addr = info["addr"]
        compiled = sections.get(name, 0)
        status = classify(name, slot_size, compiled)
        deficit = max(0, slot_size - compiled)
        overflow = max(0, compiled - slot_size) if slot_size > 0 else 0
        fill_pct = (compiled / slot_size * 100) if slot_size > 0 else 0

        report.append({
            "name": name,
            "addr": addr,
            "slot_size": slot_size,
            "compiled_size": compiled,
            "status": status,
            "deficit": deficit,
            "overflow_bytes": overflow,
            "fill_pct": fill_pct,
        })

    return report


def print_summary(report):
    """Print summary statistics."""
    total = len(report)
    by_status = {}
    for r in report:
        s = r["status"]
        if s not in by_status:
            by_status[s] = {"count": 0, "deficit": 0, "overflow": 0}
        by_status[s]["count"] += 1
        by_status[s]["deficit"] += r["deficit"]
        by_status[s]["overflow"] += r["overflow_bytes"]

    total_slot = sum(r["slot_size"] for r in report)
    total_compiled = sum(r["compiled_size"] for r in report)
    total_deficit = sum(r["deficit"] for r in report)
    total_overflow = sum(r["overflow_bytes"] for r in report)
    healthy = by_status.get("good", {}).get("count", 0)

    print("=" * 60)
    print("FUNCTION AUDIT REPORT")
    print("=" * 60)
    print()
    print(f"Total functions:     {total}")
    print(f"Original slot total: {total_slot:,} bytes")
    print(f"Compiled total:      {total_compiled:,} bytes")
    print(f"Net deficit:         {total_deficit:,} bytes")
    print(f"Net overflow:        {total_overflow:,} bytes")
    print(f"Healthy (90-110%%):   {healthy}/{total} ({healthy/total*100:.0f}%)")
    print()

    status_labels = {
        "good": "Good (90-110%)",
        "medium": "Medium (50-90%)",
        "small": "Small (25-50%)",
        "tiny": "Tiny (<25%)",
        "stub_asm": "ASM Stub (12B)",
        "stub_4": "RTS Stub (4B)",
        "overflow": "Overflow (>110%)",
        "data_region": "Data Region",
        "unknown": "Unknown",
    }

    print(f"{'Status':<20} {'Count':>6} {'Deficit':>10} {'Overflow':>10}")
    print("-" * 50)
    for key in ["good", "medium", "small", "tiny", "stub_asm", "stub_4", "overflow", "data_region", "unknown"]:
        if key in by_status:
            b = by_status[key]
            label = status_labels.get(key, key)
            print(f"{label:<20} {b['count']:>6} {b['deficit']:>9,}B {b['overflow']:>9,}B")

    # Exclude data regions from scoring
    data_count = by_status.get("data_region", {}).get("count", 0)
    code_total = total - data_count

    print()
    print(f"Coverage score: {healthy}/{code_total} code functions healthy ({healthy/code_total*100:.1f}%)")

    # Count stubs
    stub_count = by_status.get("stub_asm", {}).get("count", 0) + by_status.get("stub_4", {}).get("count", 0)
    overflow_count = by_status.get("overflow", {}).get("count", 0)
    print(f"Stubs remaining: {stub_count}")
    print(f"Overflows: {overflow_count}")
    if data_count:
        print(f"Data regions (excluded): {data_count}")


def print_stubs(report):
    """Print all stub functions sorted by wasted bytes."""
    stubs = [r for r in report if r["status"] in ("stub_4", "stub_asm")]
    stubs.sort(key=lambda r: r["deficit"], reverse=True)
    print(f"\n{'='*60}")
    print(f"STUB FUNCTIONS ({len(stubs)} total, {sum(r['deficit'] for r in stubs):,} bytes missing)")
    print(f"{'='*60}\n")
    print(f"{'Function':<20} {'Slot':>6} {'Compiled':>8} {'Missing':>8}")
    print("-" * 45)
    for r in stubs:
        print(f"{r['name']:<20} {r['slot_size']:>6} {r['compiled_size']:>8} {r['deficit']:>8}")


def print_overflow(report):
    """Print all overflowing functions."""
    overflows = [r for r in report if r["status"] == "overflow"]
    overflows.sort(key=lambda r: r["overflow_bytes"], reverse=True)
    print(f"\n{'='*60}")
    print(f"OVERFLOW FUNCTIONS ({len(overflows)} total, {sum(r['overflow_bytes'] for r in overflows):,} bytes over)")
    print(f"{'='*60}\n")
    print(f"{'Function':<20} {'Slot':>6} {'Compiled':>8} {'Over':>6} {'Fill%':>6}")
    print("-" * 50)
    for r in overflows:
        print(f"{r['name']:<20} {r['slot_size']:>6} {r['compiled_size']:>8} {r['overflow_bytes']:>6} {r['fill_pct']:>5.0f}%")


def print_gaps(report, limit=30):
    """Print top N biggest gaps (most wasted space)."""
    gapped = [r for r in report if r["deficit"] > 0]
    gapped.sort(key=lambda r: r["deficit"], reverse=True)
    print(f"\n{'='*60}")
    print(f"TOP {limit} BIGGEST GAPS")
    print(f"{'='*60}\n")
    print(f"{'Function':<20} {'Slot':>6} {'Compiled':>8} {'Gap':>6} {'Fill%':>6}")
    print("-" * 50)
    for r in gapped[:limit]:
        print(f"{r['name']:<20} {r['slot_size']:>6} {r['compiled_size']:>8} {r['deficit']:>6} {r['fill_pct']:>5.0f}%")


def print_json(report):
    """Print machine-readable JSON."""
    output = {
        "total_functions": len(report),
        "total_slot_bytes": sum(r["slot_size"] for r in report),
        "total_compiled_bytes": sum(r["compiled_size"] for r in report),
        "total_deficit": sum(r["deficit"] for r in report),
        "total_overflow": sum(r["overflow_bytes"] for r in report),
        "healthy_count": sum(1 for r in report if r["status"] == "good"),
        "stub_count": sum(1 for r in report if r["status"] in ("stub_4", "stub_asm")),
        "overflow_count": sum(1 for r in report if r["status"] == "overflow"),
        "functions": report,
    }
    print(json.dumps(output, indent=2))


def update_dashboard(report):
    """Generate dashboard/function_audit.md."""
    total = len(report)
    healthy = sum(1 for r in report if r["status"] == "good")
    stubs = sum(1 for r in report if r["status"] in ("stub_4", "stub_asm"))
    overflows = sum(1 for r in report if r["status"] == "overflow")
    total_deficit = sum(r["deficit"] for r in report)
    total_compiled = sum(r["compiled_size"] for r in report)

    by_status = {}
    for r in report:
        s = r["status"]
        if s not in by_status:
            by_status[s] = {"count": 0, "deficit": 0}
        by_status[s]["count"] += 1
        by_status[s]["deficit"] += r["deficit"]

    lines = []
    lines.append("# Function Audit Dashboard")
    lines.append("")
    lines.append(f"**{healthy}/{total} functions healthy ({healthy/total*100:.1f}%)** | "
                 f"{stubs} stubs | {overflows} overflows | "
                 f"{total_deficit:,}B deficit")
    lines.append("")
    lines.append("## Distribution")
    lines.append("")
    lines.append("| Status | Count | Deficit |")
    lines.append("|--------|------:|--------:|")

    labels = [
        ("good", "Good (90-110%)"),
        ("medium", "Medium (50-90%)"),
        ("small", "Small (25-50%)"),
        ("tiny", "Tiny (<25%)"),
        ("stub_asm", "ASM Stub"),
        ("stub_4", "RTS Stub"),
        ("overflow", "Overflow"),
    ]
    for key, label in labels:
        if key in by_status:
            b = by_status[key]
            lines.append(f"| {label} | {b['count']} | {b['deficit']:,}B |")

    lines.append("")
    lines.append("## Top 20 Gaps")
    lines.append("")
    lines.append("| Function | Slot | Compiled | Gap | Fill |")
    lines.append("|----------|-----:|---------:|----:|-----:|")

    gapped = sorted(report, key=lambda r: r["deficit"], reverse=True)
    for r in gapped[:20]:
        lines.append(f"| {r['name']} | {r['slot_size']} | {r['compiled_size']} | "
                     f"{r['deficit']} | {r['fill_pct']:.0f}% |")

    lines.append("")
    lines.append("## Top 20 Overflows")
    lines.append("")
    lines.append("| Function | Slot | Compiled | Over | Fill |")
    lines.append("|----------|-----:|---------:|-----:|-----:|")

    overflowed = sorted(report, key=lambda r: r["overflow_bytes"], reverse=True)
    for r in overflowed[:20]:
        if r["overflow_bytes"] > 0:
            lines.append(f"| {r['name']} | {r['slot_size']} | {r['compiled_size']} | "
                         f"+{r['overflow_bytes']} | {r['fill_pct']:.0f}% |")

    lines.append("")
    lines.append(f"*Generated by `tools/audit_functions.py --dashboard`*")
    lines.append("")

    os.makedirs(os.path.dirname(DASHBOARD), exist_ok=True)
    with open(DASHBOARD, "w", newline="\n") as f:
        f.write("\n".join(lines))

    print(f"Dashboard updated: {DASHBOARD}")


def main():
    parser = argparse.ArgumentParser(description="Audit reimpl function coverage")
    parser.add_argument("--summary", action="store_true", help="Quick summary only")
    parser.add_argument("--stubs", action="store_true", help="List all stub functions")
    parser.add_argument("--overflow", action="store_true", help="List all overflows")
    parser.add_argument("--gaps", action="store_true", help="Top 30 biggest gaps")
    parser.add_argument("--json", action="store_true", help="Machine-readable JSON")
    parser.add_argument("--dashboard", action="store_true", help="Update dashboard")
    parser.add_argument("--all", action="store_true", help="Full report (all sections)")
    args = parser.parse_args()

    # Default to summary if no flags
    if not any([args.summary, args.stubs, args.overflow, args.gaps, args.json, args.dashboard, args.all]):
        args.summary = True

    print("Reading original function layout from aprog.s...", file=sys.stderr)
    slots = get_original_functions()
    print(f"  {len(slots)} functions found", file=sys.stderr)

    print("Reading compiled sections from ELF...", file=sys.stderr)
    sections = get_elf_sections()
    print(f"  {len(sections)} sections found", file=sys.stderr)

    # Check for functions in aprog.s but missing from ELF
    missing = set(slots.keys()) - set(sections.keys())
    if missing:
        print(f"\n  WARNING: {len(missing)} functions in aprog.s but MISSING from ELF:", file=sys.stderr)
        for m in sorted(missing)[:10]:
            print(f"    {m}", file=sys.stderr)
        if len(missing) > 10:
            print(f"    ... and {len(missing) - 10} more", file=sys.stderr)

    print("", file=sys.stderr)

    report = build_report(slots, sections)

    if args.json:
        print_json(report)
        return

    if args.dashboard:
        update_dashboard(report)
        # Also print summary
        print_summary(report)
        return

    if args.all:
        print_summary(report)
        print_stubs(report)
        print_overflow(report)
        print_gaps(report)
        return

    if args.summary:
        print_summary(report)

    if args.stubs:
        print_stubs(report)

    if args.overflow:
        print_overflow(report)

    if args.gaps:
        print_gaps(report)


if __name__ == "__main__":
    main()
