#!/usr/bin/env python3
"""
Phase B4 consumer map: scan Ghidra decompiled C files for car struct access.

Scans ghidra_reference/FUN_*.c for references to:
  - car_base: 0x06078900 (car struct array base)
  - car_ptr:  0x0607E940 (current-car pointer)

For each function, extracts:
  - Which reference(s) it uses
  - Struct offsets accessed (numeric literals after base/ptr dereference)
  - Access direction: READ vs WRITE

Outputs a markdown table to consumer_map.md.
"""

import os
import re
import sys
from collections import defaultdict
from pathlib import Path

# Project root
SCRIPT_DIR = Path(__file__).parent
PROJECT_ROOT = SCRIPT_DIR.parent.parent
GHIDRA_DIR = PROJECT_ROOT / "ghidra_reference"
OUTPUT_FILE = SCRIPT_DIR / "consumer_map.md"

# Addresses we're looking for
CAR_BASE = "6078900"
CAR_PTR_UPPER = "607E940"
CAR_PTR_LOWER = "607e940"


def find_matching_files():
    """Find all FUN_*.c files referencing car_base or car_ptr."""
    results = []
    for f in sorted(GHIDRA_DIR.glob("FUN_*.c")):
        text = f.read_text(encoding="utf-8", errors="replace")
        has_base = CAR_BASE.lower() in text.lower()
        has_ptr = CAR_PTR_UPPER.lower() in text.lower()
        if has_base or has_ptr:
            results.append((f, has_base, has_ptr))
    return results


def extract_offsets_from_line(line, context_lines=None):
    """Extract struct offsets from a line that accesses the car struct.

    Looks for patterns like:
      + 0xNN)
      + NN)
      + (int)DAT_* forms (symbolic offsets - we record as DAT_*)
      [N] array indexing (record as index*4)
    after a car base/ptr reference or variable derived from one.
    """
    offsets = set()

    # Direct numeric hex offsets: + 0xNN, + 0XNN
    for m in re.finditer(r'\+\s*0x([0-9a-fA-F]+)', line):
        val = int(m.group(1), 16)
        # Filter out obviously non-struct offsets (too large for car struct 0x268)
        if val <= 0x300:
            offsets.add(f"0x{val:02X}")

    # Direct numeric decimal offsets: + NN) where NN is small
    for m in re.finditer(r'\+\s+(\d+)\s*\)', line):
        val = int(m.group(1))
        if 0 < val <= 0x300:
            offsets.add(f"0x{val:02X}")

    # Array indexing: [N] where N is small constant
    for m in re.finditer(r'\[(\d+)\]', line):
        val = int(m.group(1))
        if 0 < val <= 0x9A:  # max index for 0x268/4
            offsets.add(f"0x{val * 4:02X}")

    # Symbolic offsets: (int)DAT_XXXXXXXX or DAT_XXXXXXXX
    for m in re.finditer(r'DAT_([0-9a-fA-F]{8})', line):
        offsets.add(f"DAT_{m.group(1)}")

    # Symbolic offsets: PTR_DAT_XXXXXXXX
    for m in re.finditer(r'PTR_DAT_([0-9a-fA-F]{8})', line):
        offsets.add(f"PTR_{m.group(1)}")

    return offsets


def classify_line_access(line):
    """Determine if a line is a READ, WRITE, or neither for the car struct.

    WRITE patterns (assignment to dereferenced car pointer/base):
      *(type *)(base + offset) = ...
      *(type *)(ptr_var + offset) = ...
      *ptr_var = ...   (when ptr_var is derived from car)

    READ patterns:
      ... = *(type *)(base + offset)
      ... *(type *)(base + offset) ... (used in expression)
      function_call(*(type *)(base + offset))

    Returns: set of {'READ', 'WRITE'} or empty set
    """
    accesses = set()

    # Pattern: *(type *)(expr) = value  -- this is a WRITE
    # We look for the deref being on the LEFT side of =
    # Ghidra format: *(int *)(addr + offset) = value
    # Also: **(type **)addr = value  (write through double deref)
    write_patterns = [
        # *(type *)(expr + offset) = ...
        r'\*\s*\([^)]*\*\)\s*\([^)]*(?:6078900|607[eE]940|puVar|iVar|base)[^)]*\)\s*=',
        # *(type *)(*(int *)ptr + offset) = ...
        r'\*\s*\([^)]*\*\)\s*\(\*\s*\([^)]*\*\)\s*(?:0x)?(?:6078900|607[eE]940|puVar)[^)]*\)\s*=',
        # **(type **)addr = ...  (clearing flag byte via double deref)
        r'\*\*\s*\([^)]*\*\*\)\s*(?:0x)?(?:6078900|607[eE]940|puVar)',
        # Direct: *(short *)(*(int *)puVar + offset) = ...
        r'\*\s*\([^)]*\*\)\s*\(\*\s*\([^)]*\*\)[^)]*\+[^)]*\)\s*=',
    ]

    read_patterns = [
        # *(type *)(expr + offset)  used in expression (not at start of assignment)
        r'(?<!=\s)\*\s*\([^)]*\*\)\s*\([^)]*(?:6078900|607[eE]940|puVar|iVar|base)[^)]*\)',
        # *(int *)ptr  (reading the pointer itself)
        r'\*\s*\([^)]*\*\)\s*(?:0x)?0?(?:6078900|607[eE]940)',
        # puVar25[N]  (array access read)
        r'puVar\d+\[\d+\]',
    ]

    # Check writes first (more specific)
    for pat in write_patterns:
        if re.search(pat, line):
            accesses.add("WRITE")
            break

    # Check reads
    for pat in read_patterns:
        if re.search(pat, line):
            accesses.add("READ")
            break

    return accesses


def analyze_function(filepath):
    """Analyze a single Ghidra C file for car struct access patterns.

    Returns dict with:
      - func_name: str
      - ref_sources: set of {'car_base', 'car_ptr'}
      - offsets: set of offset strings
      - access_types: set of {'READ', 'WRITE'}
      - read_offsets: set of offsets that are read
      - write_offsets: set of offsets that are written
    """
    text = filepath.read_text(encoding="utf-8", errors="replace")
    lines = text.split("\n")
    func_name = filepath.stem  # FUN_XXXXXXXX

    ref_sources = set()
    all_offsets = set()
    access_types = set()
    read_offsets = set()
    write_offsets = set()

    text_lower = text.lower()
    if CAR_BASE.lower() in text_lower:
        ref_sources.add("car_base")
    if CAR_PTR_UPPER.lower() in text_lower:
        ref_sources.add("car_ptr")

    # Track which local variables are derived from car_base or car_ptr
    # so we can trace offset accesses through them.
    car_derived_vars = set()

    for i, line in enumerate(lines):
        line_lower = line.lower()

        # Check if this line involves car struct at all
        has_car_ref = (
            CAR_BASE.lower() in line_lower
            or CAR_PTR_UPPER.lower() in line_lower
        )

        # Also check for variables known to be derived from car pointers
        has_derived = any(
            re.search(r'\b' + re.escape(v) + r'\b', line) for v in car_derived_vars
        ) if car_derived_vars else False

        if not has_car_ref and not has_derived:
            continue

        # Track variable assignments from car addresses
        # Pattern 1: direct assignment: iVar9 = *(int *)0x0607E940;
        #            puVar1 = 0x06078900;
        #            base = *(int *)0x0607E940;
        # Pattern 2: register form: register int base asm("r14") = *(int *)0x0607E940;
        # Pattern 3: computed base: puVar25 = (unsigned int *)(0x06078900 + expr);
        assign_match = re.match(
            r'\s*(?:register\s+\w+\s+)?(\w+)\s*(?:asm\([^)]*\)\s*)?=\s*'
            r'(?:\*\s*\([^)]*\*\)\s*)?(?:\([^)]*\*\)\s*\(?\s*)?'
            r'(?:0x)?0?(?:6078900|607[eE]940)',
            line
        )
        if assign_match:
            car_derived_vars.add(assign_match.group(1))

        # Extract offsets from this line
        line_offsets = extract_offsets_from_line(line)
        all_offsets.update(line_offsets)

        # Determine read/write direction
        # A line with = where the car-struct deref is on the LEFT is a WRITE
        # Otherwise it's a READ

        # Simple heuristic: if line has form *(type*)(car_expr) = value, it's a WRITE
        # We use a broader approach: split on '=' and check which side has the car ref

        stripped = line.strip()
        if not stripped or stripped.startswith("//") or stripped.startswith("/*"):
            continue

        # Check for writes: *(type *)(base/ptr + offset) = ...
        # The key pattern is: deref on left side of =
        is_write = False
        is_read = False

        # Find all = that are assignments (not == comparisons, not != etc.)
        # Split into potential assignment
        eq_parts = re.split(r'(?<![!=<>])=(?!=)', stripped)
        if len(eq_parts) >= 2:
            lhs = eq_parts[0]
            rhs = "=".join(eq_parts[1:])

            # Build pattern for matching car references including derived vars
            car_ref_alts = [r'6078900', r'607[eE]940']
            for v in car_derived_vars:
                car_ref_alts.append(r'\b' + re.escape(v) + r'\b')
            car_ref_pat = '(?:' + '|'.join(car_ref_alts) + ')'

            # Check if LHS has a car struct dereference (write target)
            lhs_has_car = bool(re.search(car_ref_pat, lhs))

            # Check if LHS is a deref write (starts with * or has *(type*))
            lhs_is_deref = bool(re.search(r'\*\s*\(', lhs)) or bool(re.search(r'\*\*', lhs))

            if lhs_has_car and lhs_is_deref:
                is_write = True
                write_offsets.update(line_offsets)

            # Check if RHS references car struct (read)
            rhs_has_car = bool(re.search(car_ref_pat, rhs))

            if rhs_has_car:
                is_read = True
                read_offsets.update(line_offsets)

            # LHS assignment to a local var from car struct is a READ of the struct
            if not lhs_is_deref and rhs_has_car:
                is_read = True
                read_offsets.update(line_offsets)

        # Lines without = but with car ref are reads (conditionals, function args, etc.)
        if len(eq_parts) < 2 and (has_car_ref or has_derived):
            is_read = True
            read_offsets.update(line_offsets)

        if is_write:
            access_types.add("WRITE")
        if is_read:
            access_types.add("READ")

    # If we found offsets but couldn't determine direction, mark as READ
    # (conservative: reading is the safe default for consumers)
    if all_offsets and not access_types:
        access_types.add("READ")

    return {
        "func_name": func_name,
        "ref_sources": ref_sources,
        "offsets": all_offsets,
        "access_types": access_types,
        "read_offsets": read_offsets,
        "write_offsets": write_offsets,
    }


def sort_offsets(offsets):
    """Sort offsets: numeric first (by value), then symbolic."""
    numeric = []
    symbolic = []
    for o in offsets:
        if o.startswith("0x"):
            try:
                numeric.append((int(o, 16), o))
            except ValueError:
                symbolic.append(o)
        else:
            symbolic.append(o)
    numeric.sort()
    symbolic.sort()
    return [o for _, o in numeric] + symbolic


def get_address_range(func_name):
    """Extract 0x0600xxxx range group from function name."""
    m = re.match(r'FUN_060(\d)', func_name)
    if m:
        return f"0x060{m.group(1)}xxxx"
    return "other"


def generate_markdown(results):
    """Generate the consumer_map.md output."""
    lines = []
    lines.append("# Car Struct Consumer Map (Phase B4)")
    lines.append("")
    lines.append("Auto-generated by `parse_consumers.py`. Data extracted from Ghidra decompiled C files.")
    lines.append("")
    lines.append("References tracked:")
    lines.append("- **car_base**: `0x06078900` (car struct array base, stride `0x268`)")
    lines.append("- **car_ptr**: `0x0607E940` (current-car pointer)")
    lines.append("")

    # Summary statistics
    readers = [r for r in results if r["access_types"] == {"READ"}]
    writers = [r for r in results if r["access_types"] == {"WRITE"}]
    both = [r for r in results if "READ" in r["access_types"] and "WRITE" in r["access_types"]]

    lines.append(f"**Total functions**: {len(results)}")
    lines.append(f"| Category | Count |")
    lines.append(f"|----------|-------|")
    lines.append(f"| Pure READ | {len(readers)} |")
    lines.append(f"| Pure WRITE | {len(writers)} |")
    lines.append(f"| READ+WRITE | {len(both)} |")
    lines.append("")

    # Group by address range
    range_groups = defaultdict(list)
    for r in results:
        range_groups[get_address_range(r["func_name"])].append(r)

    # Full summary table grouped by range
    lines.append("---")
    lines.append("")
    lines.append("## Full Summary Table")
    lines.append("")

    for addr_range in sorted(range_groups.keys()):
        group = range_groups[addr_range]
        lines.append(f"### {addr_range}")
        lines.append("")
        lines.append("| Function | Access | Source | Offsets |")
        lines.append("|----------|--------|--------|---------|")

        for r in sorted(group, key=lambda x: x["func_name"]):
            access = "+".join(sorted(r["access_types"]))
            source = "+".join(sorted(r["ref_sources"]))
            offsets_sorted = sort_offsets(r["offsets"])
            offsets_str = ", ".join(offsets_sorted) if offsets_sorted else "(none extracted)"
            # Truncate very long offset lists
            if len(offsets_str) > 120:
                offsets_str = offsets_str[:117] + "..."
            lines.append(f"| `{r['func_name']}` | {access} | {source} | {offsets_str} |")

        lines.append("")

    # Pure consumers (READ only) - boundary outputs
    lines.append("---")
    lines.append("")
    lines.append("## Pure Consumers (READ only)")
    lines.append("")
    lines.append("These functions only READ from the car struct. They are boundary **outputs** --")
    lines.append("they consume driving model state but do not modify it.")
    lines.append("")

    if readers:
        lines.append("| Function | Source | Read Offsets |")
        lines.append("|----------|--------|-------------|")
        for r in sorted(readers, key=lambda x: x["func_name"]):
            source = "+".join(sorted(r["ref_sources"]))
            offsets_sorted = sort_offsets(r["read_offsets"] or r["offsets"])
            offsets_str = ", ".join(offsets_sorted) if offsets_sorted else "(none extracted)"
            if len(offsets_str) > 120:
                offsets_str = offsets_str[:117] + "..."
            lines.append(f"| `{r['func_name']}` | {source} | {offsets_str} |")
        lines.append("")
    else:
        lines.append("(none found)")
        lines.append("")

    # Pure producers (WRITE only) - boundary inputs
    lines.append("---")
    lines.append("")
    lines.append("## Pure Producers (WRITE only)")
    lines.append("")
    lines.append("These functions only WRITE to the car struct. They are boundary **inputs** --")
    lines.append("they produce driving model state without reading it.")
    lines.append("")

    if writers:
        lines.append("| Function | Source | Write Offsets |")
        lines.append("|----------|--------|--------------|")
        for r in sorted(writers, key=lambda x: x["func_name"]):
            source = "+".join(sorted(r["ref_sources"]))
            offsets_sorted = sort_offsets(r["write_offsets"] or r["offsets"])
            offsets_str = ", ".join(offsets_sorted) if offsets_sorted else "(none extracted)"
            if len(offsets_str) > 120:
                offsets_str = offsets_str[:117] + "..."
            lines.append(f"| `{r['func_name']}` | {source} | {offsets_str} |")
        lines.append("")
        lines.append("**Note:** Most \"pure WRITE\" functions follow a dispatcher pattern: they write")
        lines.append("`*(int *)0x0607E940 = *(int *)0x0607E944` (setting car_ptr from a secondary")
        lines.append("car pointer at `0x0607E944`) then call sub-functions and read car fields")
        lines.append("through the secondary pointer. Since `0x0607E944` is outside our tracked")
        lines.append("scope, these reads are not captured. These are likely **dispatch/orchestrator**")
        lines.append("functions rather than true data producers.")
        lines.append("")
    else:
        lines.append("(none found)")
        lines.append("")

    # Read+Write (internal to driving model)
    lines.append("---")
    lines.append("")
    lines.append("## Read+Write (Internal)")
    lines.append("")
    lines.append("These functions both READ and WRITE the car struct. They are **internal** to")
    lines.append("the driving model -- they transform state in place.")
    lines.append("")

    if both:
        lines.append("| Function | Source | Read Offsets | Write Offsets |")
        lines.append("|----------|--------|-------------|--------------|")
        for r in sorted(both, key=lambda x: x["func_name"]):
            source = "+".join(sorted(r["ref_sources"]))
            r_offsets = sort_offsets(r["read_offsets"])
            w_offsets = sort_offsets(r["write_offsets"])
            r_str = ", ".join(r_offsets) if r_offsets else "(none extracted)"
            w_str = ", ".join(w_offsets) if w_offsets else "(none extracted)"
            if len(r_str) > 80:
                r_str = r_str[:77] + "..."
            if len(w_str) > 80:
                w_str = w_str[:77] + "..."
            lines.append(f"| `{r['func_name']}` | {source} | {r_str} | {w_str} |")
        lines.append("")
    else:
        lines.append("(none found)")
        lines.append("")

    # Offset frequency table
    lines.append("---")
    lines.append("")
    lines.append("## Offset Frequency")
    lines.append("")
    lines.append("How often each struct offset is accessed across all functions.")
    lines.append("Only numeric offsets shown (symbolic DAT_/PTR_ offsets are unresolved).")
    lines.append("")

    offset_read_count = defaultdict(int)
    offset_write_count = defaultdict(int)
    for r in results:
        for o in r.get("read_offsets", set()):
            if o.startswith("0x"):
                offset_read_count[o] += 1
        for o in r.get("write_offsets", set()):
            if o.startswith("0x"):
                offset_write_count[o] += 1

    all_counted = set(offset_read_count.keys()) | set(offset_write_count.keys())
    if all_counted:
        lines.append("| Offset | Read Count | Write Count | Total |")
        lines.append("|--------|-----------|------------|-------|")
        for o in sort_offsets(all_counted):
            rc = offset_read_count.get(o, 0)
            wc = offset_write_count.get(o, 0)
            lines.append(f"| {o} | {rc} | {wc} | {rc + wc} |")
        lines.append("")

    # Symbolic offset list
    all_symbolic = set()
    for r in results:
        for o in r["offsets"]:
            if not o.startswith("0x"):
                all_symbolic.add(o)

    if all_symbolic:
        lines.append("---")
        lines.append("")
        lines.append("## Unresolved Symbolic Offsets")
        lines.append("")
        lines.append("These offsets reference pool constants (DAT_/PTR_ symbols) whose values")
        lines.append("are not known from the C decompilation alone. They need cross-referencing")
        lines.append("with the binary or Ghidra to resolve to numeric values.")
        lines.append("")
        for s in sorted(all_symbolic):
            # Find which functions use this symbolic offset
            users = [r["func_name"] for r in results if s in r["offsets"]]
            lines.append(f"- `{s}` -- used by: {', '.join(f'`{u}`' for u in users)}")
        lines.append("")

    return "\n".join(lines)


def main():
    matching_files = find_matching_files()
    print(f"Found {len(matching_files)} files referencing car struct addresses")

    results = []
    for filepath, has_base, has_ptr in matching_files:
        info = analyze_function(filepath)
        results.append(info)

    # Print summary to stdout
    readers = [r for r in results if r["access_types"] == {"READ"}]
    writers = [r for r in results if r["access_types"] == {"WRITE"}]
    both = [r for r in results if "READ" in r["access_types"] and "WRITE" in r["access_types"]]

    print(f"  Pure READ:  {len(readers)}")
    print(f"  Pure WRITE: {len(writers)}")
    print(f"  READ+WRITE: {len(both)}")
    print()

    # Count unique offsets
    all_offsets = set()
    for r in results:
        all_offsets.update(r["offsets"])
    numeric_offsets = [o for o in all_offsets if o.startswith("0x")]
    symbolic_offsets = [o for o in all_offsets if not o.startswith("0x")]
    print(f"  Unique numeric offsets: {len(numeric_offsets)}")
    print(f"  Unique symbolic offsets: {len(symbolic_offsets)}")

    # Generate and write markdown
    md = generate_markdown(results)
    OUTPUT_FILE.write_text(md, encoding="utf-8")
    print(f"\nWrote {OUTPUT_FILE}")


if __name__ == "__main__":
    main()
