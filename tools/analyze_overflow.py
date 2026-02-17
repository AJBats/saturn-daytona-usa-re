#!/usr/bin/env python3
"""Analyze overflow named functions to find redirect opportunities."""
import re, os, glob

SRC_DIR = "reimpl/src"

# The 38 overflow named functions - those with known FUN_ from OTHER_NAMED_MAP
overflow_funcs = {
    "track_object_placement":       None,
    "asset_table_init":             None,
    "vdp1_texture_config":          None,
    "palette_fade_update":          None,
    "vdp2_mega_init":               None,
    "dma_channel_level_set":        None,
    "race_result_sequence":         None,
    "hud_sprite_vertex_project":    None,
    "vdp1_sprite_list_build":       None,
    "scene_tile_render_near":       "FUN_06006868",
    "cd_session_open":              None,
    "select_confirm_display":       None,
    "camera_view_select":           None,
    "cd_session_skip_poll":         None,
    "cd_command_queue_process":     None,
    "framebuffer_vsync_poll":       None,
    "podium_object_render_static":  None,
    "vdp1_cmd_table_init":          "FUN_06002594",
    "dma_mem_transfer":             None,
    "cd_session_create":            "FUN_060407A0",
    "vdp2_get_vram_bank":           None,
    "vdp2_vram_write":              None,
    "cd_session_state_reset":       None,
    "cd_tray_command":              None,
    "camera_phase_dispatch":        "FUN_0601228A",
    "vdp2_bitmap_load":             "FUN_06036E1C",
    "camera_fov_interpolate":       "FUN_060122F4",
    "car_palette_load_primary":     "FUN_060039C8",
    "sound_channels_reset":         None,
    "subsystem_slot_dma":           "FUN_06010A5C",
    "vdp_display_list_fill":        None,
    "background_rotation_wobble":   "FUN_06013E12",
    "vdp1_regs_clear":              None,
    "sound_channels_stop":          None,
    "vdp2_pattern_table_clear":     None,
    "finish_line_display":          None,
    "car_collision_response":       None,
    "hw_settle_delay":              "FUN_06002280",
}

# Find FUN_ addresses from aliases and comments in source
for cfile in glob.glob(os.path.join(SRC_DIR, "*.c")):
    with open(cfile, "r") as f:
        content = f.read()
    basename = os.path.basename(cfile)

    # Method 1: alias declarations
    for m in re.finditer(r'(FUN_[0-9A-Fa-f]+)\s*\)\s*__attribute__\s*\(\s*\(alias\s*\(\s*"(\w+)"\s*\)', content):
        fun = m.group(1).upper()
        name = m.group(2)
        if name in overflow_funcs and overflow_funcs[name] is None:
            overflow_funcs[name] = fun

    # Method 2: comments like /* --- FUN_XXXXXXXX ... */
    for m in re.finditer(r'/\*\s*---\s*(FUN_[0-9A-Fa-f]+)\b', content):
        fun = m.group(1).upper()
        pos = m.end()
        next_def = re.search(r'(?:void|int|unsigned|short|char)\s+(\w+)\s*\(', content[pos:pos+500])
        if next_def:
            name = next_def.group(1)
            if name in overflow_funcs and overflow_funcs[name] is None:
                overflow_funcs[name] = fun

    # Method 3: comments like /* FUN_XXXXXXXX: description */
    for m in re.finditer(r'/\*\s*(FUN_[0-9A-Fa-f]+)\s*[-—:]', content):
        fun = m.group(1).upper()
        pos = m.end()
        next_def = re.search(r'(?:void|int|unsigned|short|char)\s+(\w+)\s*\(', content[pos:pos+500])
        if next_def:
            name = next_def.group(1)
            if name in overflow_funcs and overflow_funcs[name] is None:
                overflow_funcs[name] = fun

    # Method 4: Look at same-name FUN_ in close proximity
    for name in overflow_funcs:
        if overflow_funcs[name] is not None:
            continue
        # Check if function is defined in this file
        func_pattern = rf'(?:void|int|unsigned|short|char)\s+{re.escape(name)}\s*\('
        func_m = re.search(func_pattern, content)
        if not func_m:
            continue
        # Look for FUN_ addresses within 2000 chars before the definition
        before = content[max(0, func_m.start()-2000):func_m.start()]
        funs_before = re.findall(r'(FUN_[0-9A-Fa-f]+)', before)
        # Also look in comment on the function itself
        line_start = content.rfind('\n', 0, func_m.start()) + 1
        func_line = content[line_start:func_m.end()+100]
        funs_inline = re.findall(r'(FUN_[0-9A-Fa-f]+)', func_line)

        if funs_inline:
            overflow_funcs[name] = funs_inline[-1].upper()

# Find all source files for each named function
named_files = {}
for cfile in glob.glob(os.path.join(SRC_DIR, "*.c")):
    with open(cfile, "r") as f:
        content = f.read()
    for name in overflow_funcs:
        pattern = rf'(?:void|int|unsigned|short|char)\s+{re.escape(name)}\s*\('
        if re.search(pattern, content):
            named_files[name] = os.path.basename(cfile)

# Check if each FUN_ has an active definition (C or ASM)
fun_defs = {}
for cfile in glob.glob(os.path.join(SRC_DIR, "*.c")):
    with open(cfile, "r") as f:
        content = f.read()
    basename = os.path.basename(cfile)

    # Split into #if 0 / active sections
    lines = content.split('\n')
    in_if0 = 0
    for line in lines:
        stripped = line.strip()
        if stripped.startswith('#if 0'):
            in_if0 += 1
        elif stripped.startswith('#endif') and in_if0 > 0:
            in_if0 -= 1
        elif in_if0 == 0:
            # Check for FUN_ function definitions with asm volatile (ASM imports)
            m = re.match(r'(?:void|int|unsigned|short|char)\s+(FUN_[0-9A-Fa-f]+)\s*\(', stripped)
            if m:
                fun = m.group(1).upper()
                if fun not in fun_defs:
                    fun_defs[fun] = ("C", basename)
            # Check for asm volatile with .byte (ASM imports)
            if 'asm volatile' in stripped or 'asm __volatile__' in stripped:
                # Look back for function name
                pass  # Too complex line-by-line, use whole-file scan below

# Better ASM detection: scan for functions containing .byte blocks
for cfile in glob.glob(os.path.join(SRC_DIR, "*.c")):
    with open(cfile, "r") as f:
        content = f.read()
    basename = os.path.basename(cfile)

    # Find active FUN_ definitions with .byte content (ASM imports)
    for m in re.finditer(r'void\s+(FUN_[0-9A-Fa-f]+)\s*\(\s*void\s*\)\s*\{', content):
        fun = m.group(1).upper()
        pos = m.end()
        # Check if inside #if 0
        before = content[:m.start()]
        depth = 0
        for line in before.split('\n'):
            s = line.strip()
            if s.startswith('#if 0'):
                depth += 1
            elif s.startswith('#endif') and depth > 0:
                depth -= 1
        if depth > 0:
            continue  # Inside #if 0

        # Check body for .byte (ASM import signature)
        body_end = content.find('}', pos)
        if body_end > 0:
            body = content[pos:body_end]
            if '.byte' in body:
                fun_defs[fun] = ("ASM", basename)

# Report
print("=== Overflow Named Functions Analysis ===\n")
print(f"{'Function':<40s}  {'Source':<30s}  {'FUN_ Address':<16s}  {'FUN_ Def':<10s}  {'FUN_ File'}")
print("-" * 140)

known = 0
unknown = 0
can_redirect = 0
needs_capture = 0

for name in sorted(overflow_funcs, key=lambda x: x):
    fun = overflow_funcs[name]
    src = named_files.get(name, "?")
    if fun:
        defn = fun_defs.get(fun, ("NONE", "?"))
        known += 1
        if defn[0] in ("ASM", "C"):
            can_redirect += 1
            marker = "REDIRECT"
        else:
            needs_capture += 1
            marker = "CAPTURE"
        print(f"  {name:<40s}  {src:<30s}  {fun:<16s}  {defn[0]:<10s}  {defn[1]:<30s}  -> {marker}")
    else:
        unknown += 1
        print(f"  {name:<40s}  {src:<30s}  {'???':<16s}  {'???':<10s}  {'?':<30s}  -> UNKNOWN")

print(f"\nKnown FUN_ addr: {known}, Unknown: {unknown}")
print(f"Can redirect (has FUN_ def): {can_redirect}")
print(f"Needs section capture (no FUN_ def): {needs_capture}")
