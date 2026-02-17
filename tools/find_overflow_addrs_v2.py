#!/usr/bin/env python3
"""Find FUN_ addresses for overflow functions using batch file address range + size matching.

V2: Uses batch file hex suffix to determine address range, checks for existing C defs."""
import re, os, glob

SRC_DIR = "reimpl/src"
SYMS_FILE = "build/aprog_syms.txt"
MAP_FILE = "reimpl/build/daytona.map"

# Extract address range from batch file name
# batch_rendering_20.c -> 0x06020000-0x06022000
# batch_system_low.c -> special case (below range)
BATCH_RANGES = {
    "batch_rendering_20.c":     (0x06020000, 0x06024000),
    "batch_rendering_22.c":     (0x06022000, 0x06026000),
    "batch_system_low.c":       (0x06002000, 0x06006000),
    "batch_cd_system_34.c":     (0x06034000, 0x06036000),
    "batch_cd_system_36.c":     (0x06036000, 0x06038000),
    "batch_obj_system_38.c":    (0x06038000, 0x0603A000),
    "batch_obj_system_3a.c":    (0x0603A000, 0x0603C000),
    "batch_obj_system_3c.c":    (0x0603C000, 0x0603E000),
    "batch_obj_system_3e.c":    (0x0603E000, 0x06040000),
    "batch_subsystem_10.c":     (0x06010000, 0x06012000),
    "batch_subsystem_12.c":     (0x06012000, 0x06016000),
    "batch_subsystem_14.c":     (0x06014000, 0x06016000),
    "batch_subsystem_16.c":     (0x06016000, 0x06018000),
    "batch_subsystem_18.c":     (0x06018000, 0x0601A000),
    "batch_subsystem_1a.c":     (0x0601A000, 0x0601E000),
    "batch_subsystem_1c.c":     (0x0601C000, 0x0601E000),
    "batch_subsystem_1e.c":     (0x0601E000, 0x06020000),
    "batch_render_pipe_2a.c":   (0x0602A000, 0x06030000),
    "batch_render_pipe_2e.c":   (0x0602E000, 0x06030000),
    "batch_session_40.c":       (0x06040000, 0x06044000),
    "batch_session_42.c":       (0x06042000, 0x06046000),
    "batch_vdp_cmd_28.c":       (0x06028000, 0x0602A000),
    "batch_state_machine.c":    (0x06008000, 0x0600A000),
    "batch_game_core.c":        (0x06005000, 0x06008000),
    "batch_game_init.c":        (0x06004000, 0x06006000),
    "batch_game_logic_a.c":     (0x0600A000, 0x0600D000),
    "batch_game_logic_b.c":     (0x0600C000, 0x06010000),
    "batch_game_logic_c.c":     (0x0600D000, 0x06010000),
    "batch_math_util_26.c":     (0x06026000, 0x06028000),
    "batch_scene_30.c":         (0x06030000, 0x06034000),
    "batch_scene_32.c":         (0x06032000, 0x06034000),
    # ASM files have broad ranges
    "asm_game_logic.c":         (0x06006000, 0x06012000),
    "asm_scene_cd_obj.c":       (0x06030000, 0x06040000),
}

OVERFLOW_FUNCS = {
    "track_object_placement":       "batch_rendering_20.c",
    "asset_table_init":             "batch_system_low.c",
    "vdp1_texture_config":          "batch_cd_system_36.c",
    "palette_fade_update":          "batch_obj_system_3c.c",
    "vdp2_mega_init":               "batch_system_low.c",
    "dma_channel_level_set":        "batch_obj_system_3c.c",
    "race_result_sequence":         "batch_subsystem_12.c",
    "hud_sprite_vertex_project":    "batch_subsystem_16.c",
    "vdp1_sprite_list_build":       "batch_render_pipe_2a.c",
    "cd_session_open":              "batch_session_40.c",
    "select_confirm_display":       "batch_subsystem_1a.c",
    "camera_view_select":           "batch_game_logic_b.c",
    "cd_session_skip_poll":         "batch_session_40.c",
    "cd_command_queue_process":     "batch_session_40.c",
    "framebuffer_vsync_poll":       "batch_obj_system_38.c",
    "podium_object_render_static":  "batch_subsystem_12.c",
    "dma_mem_transfer":             "batch_vdp_cmd_28.c",
    "cd_session_state_reset":       "batch_session_42.c",
    "cd_tray_command":              "batch_cd_system_34.c",
    "vdp2_get_vram_bank":           "batch_session_42.c",
    "vdp2_vram_write":              "batch_session_42.c",
    "vdp_display_list_fill":        "batch_vdp_cmd_28.c",
    "sound_channels_reset":         "batch_state_machine.c",
    "sound_channels_stop":          "batch_subsystem_18.c",
    "vdp2_pattern_table_clear":     "batch_vdp_cmd_28.c",
    "finish_line_display":          "asm_game_logic.c",
    "car_collision_response":       "asm_scene_cd_obj.c",
}


def load_syms():
    syms = {}
    with open(SYMS_FILE) as f:
        for line in f:
            m = re.match(r'(FUN_[0-9A-Fa-f]+)\s*=\s*0x([0-9A-Fa-f]+)', line)
            if m:
                syms[m.group(1).upper()] = int(m.group(2), 16)
    return syms


def load_orig_sizes(syms):
    sorted_addrs = sorted(syms.values())
    sizes = {}
    for i, addr in enumerate(sorted_addrs):
        if i + 1 < len(sorted_addrs):
            sizes[addr] = sorted_addrs[i + 1] - addr
    return sizes


def load_overflow_sizes():
    sizes = {}
    with open(MAP_FILE) as f:
        lines = f.readlines()
    in_overflow = False
    for i, line in enumerate(lines):
        if line.startswith('.text.overflow'):
            in_overflow = True
            continue
        if in_overflow and re.match(r'^[^ ]', line) and not line.strip().startswith('*') and not line.strip().startswith('.text'):
            break
        if in_overflow:
            m = re.match(r'\s+\.text\.(\S+)\s+0x([0-9a-f]+)\s+0x([0-9a-f]+)', line.rstrip())
            if m:
                size = int(m.group(3), 16)
                if size > 0:
                    sizes[m.group(1)] = size
    return sizes


def find_existing_c_defs():
    """Find FUN_ addresses that already have C definitions (not available for redirect)."""
    existing = set()
    for fname in sorted(os.listdir(SRC_DIR)):
        if not fname.endswith('.c'):
            continue
        with open(os.path.join(SRC_DIR, fname)) as f:
            content = f.read()
        # Find active FUN_ definitions
        lines = content.split('\n')
        depth = 0
        for line in lines:
            s = line.strip()
            if s.startswith('#if 0'):
                depth += 1
            elif s.startswith('#endif') and depth > 0:
                depth -= 1
            elif depth == 0:
                m = re.match(r'(?:void|int|unsigned\s*\w*|short|char)\s+(FUN_[0-9A-Fa-f]+)\s*\(', s)
                if m:
                    existing.add(m.group(1).upper())
    return existing


def find_asm_imports():
    """Find FUN_ addresses that have ASM byte imports."""
    asm_funs = set()
    for fname in sorted(os.listdir(SRC_DIR)):
        if not fname.endswith('.c'):
            continue
        with open(os.path.join(SRC_DIR, fname)) as f:
            content = f.read()
        for m in re.finditer(r'void\s+(FUN_[0-9A-Fa-f]+)\s*\(\s*void\s*\)\s*\{', content):
            fun = m.group(1).upper()
            pos = m.end()
            # Check body for .byte
            body_end = content.find('}', pos)
            if body_end > 0:
                body = content[pos:body_end]
                if '.byte' in body:
                    # Check if active
                    before = content[:m.start()]
                    depth = 0
                    for line in before.split('\n'):
                        s = line.strip()
                        if s.startswith('#if 0'):
                            depth += 1
                        elif s.startswith('#endif') and depth > 0:
                            depth -= 1
                    if depth == 0:
                        asm_funs.add(fun)
    return asm_funs


def main():
    syms = load_syms()
    orig_sizes = load_orig_sizes(syms)
    overflow_sizes = load_overflow_sizes()
    existing_defs = find_existing_c_defs()
    asm_imports = find_asm_imports()

    print("=== Finding FUN_ Addresses (V2 - batch range + size matching) ===\n")

    results = []

    for funcname in sorted(OVERFLOW_FUNCS, key=lambda x: -overflow_sizes.get(x, 0)):
        batchfile = OVERFLOW_FUNCS[funcname]
        compiled_size = overflow_sizes.get(funcname, 0)

        # Get address range from batch file name
        addr_range = BATCH_RANGES.get(batchfile)
        if not addr_range:
            print("  %-35s  compiled=%4dB  NO RANGE for %s" % (funcname, compiled_size, batchfile))
            results.append((funcname, None, 0, 0, compiled_size, 0, False))
            continue

        lo, hi = addr_range

        # Find candidates in range
        candidates = []
        for fname, faddr in syms.items():
            if lo <= faddr < hi:
                orig_size = orig_sizes.get(faddr, 0)
                if orig_size == 0:
                    continue
                size_ratio = compiled_size / orig_size if orig_size > 0 else 0
                has_c_def = fname in existing_defs
                has_asm = fname in asm_imports
                candidates.append((fname, faddr, orig_size, size_ratio, has_c_def, has_asm))

        # Sort by size similarity
        candidates.sort(key=lambda c: abs(c[3] - 1.0) if c[3] > 0 else 999)

        print("%-35s  compiled=%4dB  range=0x%08X-0x%08X  (%s)" % (
            funcname, compiled_size, lo, hi, batchfile))

        shown = 0
        best = None
        for fname, faddr, orig_size, ratio, has_c, has_asm in candidates:
            if shown >= 5:
                break
            avail = "ASM" if has_asm else ("C-def" if has_c else "AVAIL")
            conf = "EXACT" if abs(ratio - 1.0) < 0.05 else "HIGH" if 0.5 < ratio < 2.0 else "LOW"
            print("    -> %s (0x%08X)  orig=%4dB  ratio=%.2f  [%s]  %s" % (
                fname, faddr, orig_size, ratio, conf, avail))
            if best is None and 0.5 < ratio < 2.0:
                best = (fname, faddr, orig_size, ratio, has_asm)
            shown += 1

        if not candidates:
            print("    -> NO CANDIDATES in range")

        if best:
            results.append((funcname, best[0], best[1], best[2], compiled_size, best[3], best[4]))
        else:
            results.append((funcname, None, 0, 0, compiled_size, 0, False))

        print()

    # Summary
    print("\n=== SUMMARY ===\n")
    good = [(n, f, a, o, c, r, asm) for n, f, a, o, c, r, asm in results if f and abs(r - 1.0) < 0.3]
    ok = [(n, f, a, o, c, r, asm) for n, f, a, o, c, r, asm in results if f and abs(r - 1.0) >= 0.3]
    no = [(n, f, a, o, c, r, asm) for n, f, a, o, c, r, asm in results if not f]

    if good:
        print("GOOD matches (ratio 0.7-1.3):")
        for n, f, a, o, c, r, asm in good:
            asm_str = " [HAS ASM]" if asm else ""
            print("  %-35s -> %s  (orig=%dB compiled=%dB ratio=%.2f)%s" % (n, f, o, c, r, asm_str))

    if ok:
        print("\nACCEPTABLE matches (ratio 0.5-2.0):")
        for n, f, a, o, c, r, asm in ok:
            print("  %-35s -> %s  (orig=%dB compiled=%dB ratio=%.2f)" % (n, f, o, c, r))

    if no:
        print("\nNO match found:")
        for n, *_ in no:
            print("  %-35s" % n)

    # Dict output
    if good:
        print("\n\n=== For gen_fixed_layout.py / redirect_named_to_asm.py ===\n")
        for n, f, a, o, c, r, asm in sorted(good, key=lambda x: x[2]):
            print("    '%s': '%s',  # orig=%dB compiled=%dB ratio=%.2f" % (n, f, o, c, r))


if __name__ == '__main__':
    main()
