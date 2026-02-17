#!/usr/bin/env python3
"""Find FUN_ addresses for named overflow functions using batch file context.

For each named function in the overflow, this tool:
1. Finds the function's position in its batch source file
2. Identifies the FUN_ functions immediately before and after it
3. The named function's address must be between those FUN_ addresses
4. Looks at aprog_syms.txt for all FUN_ addresses in that range
5. Reports candidates (optionally with size matching)
"""
import re, os, glob, sys

SRC_DIR = "reimpl/src"
SYMS_FILE = "build/aprog_syms.txt"
MAP_FILE = "reimpl/build/daytona.map"

# Functions we need addresses for (name -> batch file)
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
    """Load FUN_ addresses from aprog_syms.txt."""
    syms = {}
    with open(SYMS_FILE) as f:
        for line in f:
            m = re.match(r'(FUN_[0-9A-Fa-f]+)\s*=\s*0x([0-9A-Fa-f]+)', line)
            if m:
                name = m.group(1).upper()
                addr = int(m.group(2), 16)
                syms[name] = addr
    return syms


def load_orig_sizes():
    """Load original function sizes from aprog_syms.txt (addr gaps)."""
    syms = load_syms()
    sorted_addrs = sorted(syms.values())
    sizes = {}
    for i, addr in enumerate(sorted_addrs):
        if i + 1 < len(sorted_addrs):
            sizes[addr] = sorted_addrs[i + 1] - addr
        else:
            sizes[addr] = 0
    return sizes


def load_overflow_sizes():
    """Load compiled overflow function sizes from map file."""
    sizes = {}
    with open(MAP_FILE) as f:
        lines = f.readlines()
    in_overflow = False
    for i, line in enumerate(lines):
        if line.startswith('.text.overflow'):
            in_overflow = True
            continue
        if in_overflow:
            if re.match(r'^[^ ]', line) and not line.strip().startswith('*') and not line.strip().startswith('.text'):
                break
            m = re.match(r'\s+\.text\.(\S+)\s*$', line.rstrip())
            if m:
                secname = m.group(1)
                if i + 1 < len(lines):
                    m2 = re.match(r'\s+0x([0-9a-f]+)\s+0x([0-9a-f]+)', lines[i+1])
                    if m2:
                        size = int(m2.group(2), 16)
                        if size > 0:
                            sizes[secname] = size
            m3 = re.match(r'\s+\.text\.(\S+)\s+0x([0-9a-f]+)\s+0x([0-9a-f]+)', line.rstrip())
            if m3:
                size = int(m3.group(3), 16)
                if size > 0:
                    sizes[m3.group(1)] = size
    return sizes


def find_surrounding_funs(filepath, funcname):
    """Find FUN_ addresses of functions immediately before and after the named function."""
    with open(filepath) as f:
        content = f.read()

    # Find all function definitions (FUN_ and named) with their line positions
    func_defs = []
    for m in re.finditer(
        r'(?:void|int|unsigned\s+\w*|short|char)\s+(FUN_[0-9A-Fa-f]+|[a-z_][a-z0-9_]+)\s*\(',
        content
    ):
        name = m.group(1)
        pos = m.start()
        # Check if inside #if 0
        before = content[:pos]
        depth = 0
        for line in before.split('\n'):
            s = line.strip()
            if s.startswith('#if 0'):
                depth += 1
            elif s.startswith('#endif') and depth > 0:
                depth -= 1
        func_defs.append((name, pos, depth == 0))

    # Find our target function
    target_idx = None
    for i, (name, pos, active) in enumerate(func_defs):
        if name == funcname and active:
            target_idx = i
            break

    if target_idx is None:
        return None, None

    # Find nearest FUN_ before
    fun_before = None
    for i in range(target_idx - 1, -1, -1):
        name = func_defs[i][0]
        if name.startswith('FUN_') and func_defs[i][2]:  # active
            fun_before = name.upper()
            break

    # Find nearest FUN_ after
    fun_after = None
    for i in range(target_idx + 1, len(func_defs)):
        name = func_defs[i][0]
        if name.startswith('FUN_') and func_defs[i][2]:  # active
            fun_after = name.upper()
            break

    return fun_before, fun_after


def main():
    syms = load_syms()
    orig_sizes = load_orig_sizes()
    overflow_sizes = load_overflow_sizes()

    print("=== Finding FUN_ Addresses for Overflow Named Functions ===\n")

    results = []

    for funcname, batchfile in sorted(OVERFLOW_FUNCS.items()):
        filepath = os.path.join(SRC_DIR, batchfile)
        if not os.path.exists(filepath):
            print("  %-35s FILE NOT FOUND: %s" % (funcname, batchfile))
            continue

        fun_before, fun_after = find_surrounding_funs(filepath, funcname)
        compiled_size = overflow_sizes.get(funcname, 0)

        addr_before = syms.get(fun_before, 0) if fun_before else 0
        addr_after = syms.get(fun_after, 0) if fun_after else 0xFFFFFFFF

        # Find candidate FUN_ addresses in range
        candidates = []
        for fname, faddr in syms.items():
            if addr_before < faddr < addr_after:
                orig_size = orig_sizes.get(faddr, 0)
                size_ratio = compiled_size / orig_size if orig_size > 0 else 0
                candidates.append((fname, faddr, orig_size, size_ratio))

        # Sort by size similarity (ratio closest to 1.0)
        candidates.sort(key=lambda c: abs(c[3] - 1.0) if c[3] > 0 else 999)

        before_str = "%s (0x%08X)" % (fun_before, addr_before) if fun_before else "???"
        after_str = "%s (0x%08X)" % (fun_after, addr_after) if fun_after else "???"

        print("%-35s  compiled=%4dB  range: %s .. %s" % (
            funcname, compiled_size, before_str, after_str))

        if candidates:
            for fname, faddr, orig_size, ratio in candidates[:5]:
                conf = "HIGH" if 0.5 < ratio < 2.0 else "LOW"
                print("    -> %s (0x%08X)  orig=%4dB  ratio=%.2f  [%s]" % (
                    fname, faddr, orig_size, ratio, conf))
            # Best match
            best = candidates[0]
            results.append((funcname, best[0], best[1], best[2], compiled_size, best[3]))
        else:
            print("    -> NO CANDIDATES in range")
            results.append((funcname, None, 0, 0, compiled_size, 0))

        print()

    # Summary
    print("\n=== SUMMARY ===\n")
    high_conf = [(n, f, a, o, c, r) for n, f, a, o, c, r in results if f and 0.5 < r < 2.0]
    low_conf = [(n, f, a, o, c, r) for n, f, a, o, c, r in results if f and not (0.5 < r < 2.0)]
    no_match = [(n, f, a, o, c, r) for n, f, a, o, c, r in results if not f]

    print("HIGH confidence matches (%d):" % len(high_conf))
    for n, f, a, o, c, r in sorted(high_conf, key=lambda x: -x[4]):
        print("  %-35s -> %s  (orig=%dB, compiled=%dB, ratio=%.2f)" % (n, f, o, c, r))

    print("\nLOW confidence matches (%d):" % len(low_conf))
    for n, f, a, o, c, r in sorted(low_conf, key=lambda x: -x[4]):
        print("  %-35s -> %s  (orig=%dB, compiled=%dB, ratio=%.2f)" % (n, f, o, c, r))

    print("\nNO match (%d):" % len(no_match))
    for n, f, a, o, c, r in no_match:
        print("  %-35s" % n)

    # Output as dict for redirect_named_to_asm.py
    if high_conf:
        print("\n\n=== For redirect_named_to_asm.py OTHER_NAMED_MAP ===\n")
        for n, f, a, o, c, r in sorted(high_conf, key=lambda x: x[2]):
            print("    '%s': '%s',  # orig=%dB compiled=%dB ratio=%.2f" % (n, f, o, c, r))


if __name__ == '__main__':
    main()
