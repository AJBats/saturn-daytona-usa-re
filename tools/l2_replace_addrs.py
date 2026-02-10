#!/usr/bin/env python3
"""L2 Pass: Replace hardcoded addresses with named defines.

Scans all batch_*.c files in reimpl/src/ and replaces raw hex addresses
with the corresponding #define names from saturn.h and game.h.

This is a mechanical transformation -- it does not change logic, only
replaces magic numbers with readable names.

Usage:
    python3 tools/l2_replace_addrs.py [--dry-run] [--file FILENAME]
"""

import os
import re
import sys
from collections import OrderedDict

PROJ = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
REIMPL_DIR = os.path.join(PROJ, "reimpl", "src")

HW_REGISTER_MAP = OrderedDict([
    ("0x25D00000", "VDP1_TVMR"),
    ("0x25D00002", "VDP1_FBCR"),
    ("0x25D00004", "VDP1_PTMR"),
    ("0x25D00006", "VDP1_EWDR"),
    ("0x25D00008", "VDP1_EWLR"),
    ("0x25D0000A", "VDP1_EWRR"),
    ("0x25D0000a", "VDP1_EWRR"),
    ("0x25D0000C", "VDP1_ENDR"),
    ("0x25D0000c", "VDP1_ENDR"),
    ("0x25D00010", "VDP1_EDSR"),
    ("0x25D00012", "VDP1_LOPR"),
    ("0x25D00014", "VDP1_COPR"),
    ("0x25D00016", "VDP1_MODR"),

    ("0x25F80000", "VDP2_TVMD"),
    ("0x25F80002", "VDP2_EXTEN"),
    ("0x25F80004", "VDP2_TVSTAT"),
    ("0x25F80006", "VDP2_VRSIZE"),
    ("0x25F8000E", "VDP2_RAMCTL"),
    ("0x25F8000e", "VDP2_RAMCTL"),
    ("0x25F80020", "VDP2_BGON"),
    ("0x25F80028", "VDP2_CHCTLA"),
    ("0x25F8002A", "VDP2_CHCTLB"),
    ("0x25F8002a", "VDP2_CHCTLB"),
    ("0x25F800AC", "VDP2_BKTAU"),
    ("0x25F800ac", "VDP2_BKTAU"),
    ("0x25F800AE", "VDP2_BKTAL"),
    ("0x25F800ae", "VDP2_BKTAL"),
    ("0x25F800E0", "VDP2_SPCTL"),
    ("0x25F800e0", "VDP2_SPCTL"),
    ("0x25F800F0", "VDP2_PRINA"),
    ("0x25F800f0", "VDP2_PRINA"),
    ("0x25F800F2", "VDP2_PRINB"),
    ("0x25F800f2", "VDP2_PRINB"),

    ("0x25FE0000", "SCU_D0R"),
    ("0x25FE0004", "SCU_D0W"),
    ("0x25FE0008", "SCU_D0C"),
    ("0x25FE000C", "SCU_D0AD"),
    ("0x25FE000c", "SCU_D0AD"),
    ("0x25FE0010", "SCU_D0EN"),
    ("0x25FE0014", "SCU_D0MD"),
    ("0x25FE007C", "SCU_DSTA"),
    ("0x25FE007c", "SCU_DSTA"),
    ("0x25FE00A0", "SCU_IMS"),
    ("0x25FE00a0", "SCU_IMS"),
    ("0x25FE00A4", "SCU_IST"),
    ("0x25FE00a4", "SCU_IST"),

    ("0x20100001", "SMPC_IREG0"),
    ("0x20100003", "SMPC_IREG1"),
    ("0x2010001F", "SMPC_COMREG"),
    ("0x2010001f", "SMPC_COMREG"),
    ("0x20100021", "SMPC_OREG0"),
    ("0x20100063", "SMPC_SF"),

    ("0x25B00400", "SCSP_MVOL"),

    ("0x25890008", "CD_HIRQREQ"),
    ("0x2589000C", "CD_HIRQMSK"),
    ("0x2589000c", "CD_HIRQMSK"),
    ("0x25890018", "CD_CR1"),
    ("0x2589001C", "CD_CR2"),
    ("0x2589001c", "CD_CR2"),
    ("0x25890020", "CD_CR3"),
    ("0x25890024", "CD_CR4"),

    ("0xFFFFFE10", "SH2_TIER"),
    ("0xFFFFFe10", "SH2_TIER"),
    ("0xfffffe10", "SH2_TIER"),
    ("0xFFFFFE11", "SH2_FTCSR"),
    ("0xfffffe11", "SH2_FTCSR"),
    ("0xFFFFFEE2", "SH2_IPRA"),
    ("0xfffffee2", "SH2_IPRA"),
    ("0xFFFFFF00", "SH2_DVSR"),
    ("0xffffff00", "SH2_DVSR"),
    ("0xFFFFFF04", "SH2_DVDNT"),
    ("0xffffff04", "SH2_DVDNT"),
    ("0xFFFFFF10", "SH2_DVDNTH"),
    ("0xffffff10", "SH2_DVDNTH"),
    ("0xFFFFFF14", "SH2_DVDNTL"),
    ("0xffffff14", "SH2_DVDNTL"),
    ("0xFFFFFF18", "SH2_DVDNTH_R"),
    ("0xffffff18", "SH2_DVDNTH_R"),
    ("0xFFFFFF1C", "SH2_DVDNTL_R"),
    ("0xffffff1c", "SH2_DVDNTL_R"),
])

GAME_RAM_MAP = OrderedDict([
    ("0x06078900", "CAR_ARRAY_BASE"),
    ("0x0607E940", "CAR_PTR_CURRENT"),
    ("0x0607e940", "CAR_PTR_CURRENT"),
    ("0x0607E944", "CAR_PTR_TARGET"),
    ("0x0607e944", "CAR_PTR_TARGET"),
    ("0x0607EAD8", "CAR_COUNT"),
    ("0x0607ead8", "CAR_COUNT"),
    ("0x0607EAE0", "DEMO_MODE_FLAG"),
    ("0x0607eae0", "DEMO_MODE_FLAG"),

    ("0x0605AD10", "GAME_STATE"),
    ("0x0605ad10", "GAME_STATE"),
    ("0x0607EBC0", "GAME_STATE_COPY"),
    ("0x0607ebc0", "GAME_STATE_COPY"),
    ("0x0607EBC4", "GAME_STATE_BIT"),
    ("0x0607ebc4", "GAME_STATE_BIT"),
    ("0x0607EBC8", "FRAME_COUNTER"),
    ("0x0607ebc8", "FRAME_COUNTER"),
    ("0x0607EBD0", "GAME_STATE_VAR"),
    ("0x0607ebd0", "GAME_STATE_VAR"),

    ("0x0607864C", "VBLANK_COUNTER"),
    ("0x0607864c", "VBLANK_COUNTER"),
    ("0x06059F44", "VBLANK_OUT_COUNTER"),
    ("0x06059f44", "VBLANK_OUT_COUNTER"),
    ("0x06059F54", "VBLANK_PHASE"),
    ("0x06059f54", "VBLANK_PHASE"),
    ("0x060635B4", "FB_STATE"),
    ("0x060635b4", "FB_STATE"),
    ("0x060635C0", "FRAME_SEC_COUNTER"),
    ("0x060635c0", "FRAME_SEC_COUNTER"),
    ("0x060635C4", "FRAME_READY_FLAG"),
    ("0x060635c4", "FRAME_READY_FLAG"),
    ("0x0605A00C", "VBL_DISABLE_FLAG"),
    ("0x0605a00c", "VBL_DISABLE_FLAG"),
    ("0x060A4C90", "TVMR_SHADOW"),
    ("0x060a4c90", "TVMR_SHADOW"),
    ("0x060A4C92", "FBCR_SHADOW"),
    ("0x060a4c92", "FBCR_SHADOW"),

    ("0x0605B6D8", "INPUT_STATE"),
    ("0x0605b6d8", "INPUT_STATE"),

    ("0x0605AD00", "COURSE_SELECT"),
    ("0x0605ad00", "COURSE_SELECT"),
    ("0x0605A016", "PHASE_FLAG"),
    ("0x0605a016", "PHASE_FLAG"),
    ("0x0605A008", "VDP1_CMD_BASE_PTR"),
    ("0x0605a008", "VDP1_CMD_BASE_PTR"),
    ("0x060635AC", "VDP1_BATCH_FLAG"),
    ("0x060635ac", "VDP1_BATCH_FLAG"),
    ("0x060635DE", "PALETTE_BANK_SEL"),
    ("0x060635de", "PALETTE_BANK_SEL"),

    ("0x06086050", "SOUND_TIMEOUT_FLAG"),
    ("0x0608604C", "SOUND_CMD_MIRROR"),
    ("0x0608604c", "SOUND_CMD_MIRROR"),
    ("0x0605DF94", "SOUND_CHAN_STATE"),
    ("0x0605df94", "SOUND_CHAN_STATE"),

    ("0x06094A30", "RENDER_STATE_A"),
    ("0x06094a30", "RENDER_STATE_A"),
    ("0x06094AB0", "RENDER_STATE_B"),
    ("0x06094ab0", "RENDER_STATE_B"),

    ("0x06089EDC", "OBJ_STATE_PRIMARY"),
    ("0x06089edc", "OBJ_STATE_PRIMARY"),
    ("0x0608A52C", "OBJ_STATE_SECONDARY"),
    ("0x0608a52c", "OBJ_STATE_SECONDARY"),

    ("0x060A5400", "CD_SESSION_BASE"),
    ("0x060a5400", "CD_SESSION_BASE"),
    ("0x060A4D14", "CD_STATE_A"),
    ("0x060a4d14", "CD_STATE_A"),

    ("0x0607EBE0", "FORCE_GEAR_CAR_PTR"),
    ("0x0607ebe0", "FORCE_GEAR_CAR_PTR"),
    ("0x0607EBEC", "FORCE_SETUP_COUNT"),
    ("0x0607ebec", "FORCE_SETUP_COUNT"),

    ("0x06063F58", "FB_STATE_VAR"),
    ("0x06063f58", "FB_STATE_VAR"),
])

BIOS_MAP = OrderedDict([
    ("0x06000300", "BIOS_FUNC_0300"),
    ("0x06000310", "BIOS_FUNC_0310"),
    ("0x06000320", "BIOS_FUNC_0320"),
    ("0x06000344", "BIOS_FUNC_0344"),
])

SOUND_RAM_MAP = OrderedDict([
    ("0x25A02C20", "SCSP_MAILBOX"),
    ("0x25a02c20", "SCSP_MAILBOX"),
])


def replace_in_cast(content, addr_str, define_name):
    """Replace *(type *)ADDR patterns with define_name.

    Handles:
      *(int *)0x25F80000       -> VDP2_TVMD
      *(volatile int *)0x25F80000 -> VDP2_TVMD
      *(short *)0x25F80000     -> VDP2_TVMD
      *(volatile unsigned short *)0x25F80000 -> VDP2_TVMD
    """
    count = 0

    type_pattern = r'\*\s*\(\s*(?:volatile\s+)?(?:unsigned\s+)?(?:int|short|char)\s*\*\s*\)\s*'
    pattern = type_pattern + re.escape(addr_str)

    matches = list(re.finditer(pattern, content))
    if matches:
        for m in reversed(matches):
            content = content[:m.start()] + define_name + content[m.end():]
            count += 1

    return content, count


def replace_ptr_cast(content, addr_str, define_name):
    """Replace (type *)ADDR pointer casts that aren't dereferenced.

    Handles:
      (int *)0x06078900        -> (int *)CAR_ARRAY_BASE
      (char *)0x060A5400       -> (char *)CD_SESSION_BASE
    """
    count = 0
    type_pattern = r'\(\s*(?:volatile\s+)?(?:unsigned\s+)?(?:int|short|char)\s*\*\s*\)\s*'
    pattern = r'(?<!\*\s)' + type_pattern + re.escape(addr_str)

    for m in re.finditer(pattern, content):
        start = m.start()
        if start > 0 and content[start-1] == '*':
            continue

    pattern2 = type_pattern + re.escape(addr_str)
    for m in list(re.finditer(pattern2, content)):
        pass

    return content, count


def process_file(filepath, dry_run=False):
    """Process a single C source file, replacing addresses with defines."""
    with open(filepath, 'r', errors='replace') as f:
        original = f.read()

    content = original
    total_replacements = 0
    details = []

    all_maps = [
        ("HW Register", HW_REGISTER_MAP),
        ("Game RAM", GAME_RAM_MAP),
        ("BIOS", BIOS_MAP),
        ("Sound RAM", SOUND_RAM_MAP),
    ]

    for category, addr_map in all_maps:
        for addr_str, define_name in addr_map.items():
            content, count = replace_in_cast(content, addr_str, define_name)
            if count > 0:
                total_replacements += count
                details.append(f"  {addr_str} -> {define_name}: {count}")

    if total_replacements > 0 and not dry_run:
        with open(filepath, 'w', newline='\n') as f:
            f.write(content)

    return total_replacements, details


def needs_include(content, header):
    """Check if a file needs a #include for the given header."""
    return f'#include "{header}"' not in content


def add_include(filepath, header):
    """Add #include at the top of the file (after any existing includes)."""
    with open(filepath, 'r', errors='replace') as f:
        content = f.read()

    if f'#include "{header}"' in content:
        return

    lines = content.split('\n')
    insert_at = 0
    for i, line in enumerate(lines):
        if line.startswith('#include'):
            insert_at = i + 1
        elif line.startswith('extern') or line.startswith('int ') or line.startswith('void '):
            break

    if insert_at == 0:
        insert_at = 0

    lines.insert(insert_at, f'#include "{header}"')
    with open(filepath, 'w', newline='\n') as f:
        f.write('\n'.join(lines))


def main():
    dry_run = '--dry-run' in sys.argv
    target_file = None
    if '--file' in sys.argv:
        idx = sys.argv.index('--file')
        if idx + 1 < len(sys.argv):
            target_file = sys.argv[idx + 1]

    total_all = 0
    files_changed = 0

    source_files = sorted(os.listdir(REIMPL_DIR))
    for fname in source_files:
        if not fname.endswith('.c'):
            continue
        if not fname.startswith('batch_'):
            continue
        if target_file and fname != target_file:
            continue

        filepath = os.path.join(REIMPL_DIR, fname)
        count, details = process_file(filepath, dry_run)

        if count > 0:
            total_all += count
            files_changed += 1
            action = "would replace" if dry_run else "replaced"
            print(f"{fname}: {action} {count} addresses")
            for d in details:
                print(d)
            print()

    mode = "[DRY RUN] " if dry_run else ""
    print(f"{mode}Total: {total_all} replacements across {files_changed} files")


if __name__ == "__main__":
    main()
