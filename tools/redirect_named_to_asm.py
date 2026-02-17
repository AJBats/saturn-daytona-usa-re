#!/usr/bin/env python3
"""redirect_named_to_asm.py -- Redirect named C functions to their FUN_ ASM imports.

For functions that have:
  1. A named C implementation (e.g., state_0_handler in pre_race_state_handlers.c)
  2. An ASM byte import for the corresponding FUN_ address

This tool:
  1. Wraps the C implementation in #if 0 (preserves it for reference)
  2. Adds PROVIDE(_named = _FUN_XXXXXXXX) to the linker script

This eliminates the C code from the binary (reducing overflow) while the
named symbol still resolves via the linker PROVIDE alias.

Usage:
  python redirect_named_to_asm.py --scan     # Show what would be redirected
  python redirect_named_to_asm.py --apply    # Apply redirections
"""

import re
import os
import glob
import sys

PROJ = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SRC_DIR = os.path.join(PROJ, 'reimpl', 'src')
LD_FILE = os.path.join(PROJ, 'reimpl', 'saturn_fixed.ld')

# State handler address map (from main.c jump table comments)
STATE_HANDLER_MAP = {
    'state_0_handler':  'FUN_060088CC',
    'state_1_handler':  'FUN_0600890A',
    'state_2_handler':  'FUN_06008938',
    'state_3_handler':  'FUN_06008A18',
    'state_4_handler':  'FUN_06008CCC',
    'state_5_handler':  'FUN_06008D74',
    'state_6_handler':  'FUN_06008B04',
    'state_7_handler':  'FUN_06008B34',
    'state_8_handler':  'FUN_06008B78',
    'state_9_handler':  'FUN_06008B9C',
    'state_10_handler': 'FUN_06008BD8',
    'state_11_handler': 'FUN_06008BFC',
    'state_12_handler': 'FUN_06008E00',
    'state_13_handler': 'FUN_06008E48',
    'state_14_handler': 'FUN_06008EBC',
    'state_15_handler': 'FUN_06009098',
    'state_16_handler': 'FUN_06009290',
    'state_17_handler': 'FUN_060092D0',
    'state_18_handler': 'FUN_060096DC',
    'state_19_handler': 'FUN_06009788',
    'state_20_handler': 'FUN_06009A60',
    'state_21_handler': 'FUN_06009C48',
    'state_22_handler': 'FUN_06009E60',
    'state_23_handler': 'FUN_06009F10',
    'state_24_handler': 'FUN_06009CFC',
    'state_25_handler': 'FUN_06009D4E',
    'state_26_handler': 'FUN_06009DD0',
    'state_27_handler': 'FUN_06009E02',
    'state_28_handler': 'FUN_06009508',
    'state_29_handler': 'FUN_0600955E',
    'state_30_handler': 'FUN_06008C14',
    'state_31_handler': 'FUN_06008C76',
}

# Other named functions with known FUN_ addresses
# Includes init functions + all discovered removed-alias mappings
OTHER_NAMED_MAP = {
    # Init chain functions
    'system_init':            'FUN_060030FC',
    'course_system_init':     'FUN_0603BF7C',
    'game_subsystem_init':    'FUN_06012CF4',
    'game_subsystem_init2':   'FUN_06012E6A',
    'cd_system_init':         'FUN_06018EE4',
    'object_system_init':     'FUN_06005174',
    'per_frame_setup':        'FUN_060032D4',

    # VDP/display functions
    'vdp_system_init_b':      'FUN_060149CC',
    'vdp2_scroll_setup':      'FUN_06004A98',
    'vdp2_scroll_update':     'FUN_060055BC',
    'vdp_system_init_a':      'FUN_0601492C',
    'vdp1_texture_palette_init': 'FUN_06026CE0',
    'cd_status_read':         'FUN_06018EAC',
    'scu_dma_transfer':       'FUN_0602766C',

    # batch_game_init.c
    'obj_template_init':      'FUN_06004670',
    'display_list_process':   'FUN_06005198',
    'animation_frame_counter':'FUN_06005928',
    'background_layer_init':  'FUN_06005788',

    # batch_state_machine.c
    'gear_shift_handler':     'FUN_06008318',
    'steering_physics_update':'FUN_06008640',

    # batch_subsystem_10.c
    'sound_bank_load':        'FUN_06010B54',

    # batch_subsystem_12.c
    'scu_interrupt_priorities_alt': 'FUN_06012050',
    'camera_view_init':       'FUN_060120C8',
    'camera_sequence_timer':  'FUN_060121A8',
    'attract_sound_dispatch': 'FUN_06012710',
    'background_render_pipeline': 'FUN_0601250C',
    'camera_sweep_render':    'FUN_060125D0',
    'save_validate_retry':    'FUN_06012B58',
    'save_screen_display':    'FUN_06012BDC',
    'bg_tilemap_load':        'FUN_06012D7C',
    'bg_tilemap_and_pattern_load': 'FUN_06012DB4',
    'bg_pattern_load':        'FUN_06012E08',
    'hud_render_frame':       'FUN_0601389E',

    # batch_subsystem_16.c
    'track_geometry_processor':'FUN_06017814',

    # batch_subsystem_18.c
    'track_calculation':      'FUN_06018278',

    # batch_subsystem_1a.c
    'menu_item_highlight':    'FUN_0601B6DC',
    'dual_column_selector':   'FUN_0601B7F4',

    # batch_subsystem_1c.c
    'tire_skid_particle_render': 'FUN_0601C3E4',
    'results_screen_update':  'FUN_0601CAEE',
    'race_position_sound':    'FUN_0601D7D0',
    'position_sound_sequencer':'FUN_0601D9B0',
    'lap_time_record_display':'FUN_0601DBB8',

    # batch_subsystem_1e.c
    'menu_vdp_palette_setup': 'FUN_0601E100',
    'input_state_copy':       'FUN_0601E26C',
    'backup_device_enumerate':'FUN_0601E37C',
    'backup_device_open':     'FUN_0601E488',
    'bios_sound_poll':        'FUN_0601E6A4',
    'backup_mem_write':       'FUN_0601E764',
    'backup_mem_read':        'FUN_0601E810',
    'save_data_load_or_create':'FUN_0601E958',
    'cd_track_validate':      'FUN_0601EAA0',
    'cd_track_play_if_active':'FUN_0601EB1C',
    'cdda_replay_check':      'FUN_0601F40C',
    'bcd_timestamp_decode':   'FUN_0601F4B4',
    'save_score_check_update':'FUN_0601F5E0',
    'save_data_write_validate':'FUN_0601F784',
    'cdda_buffer_select':     'FUN_0601F87A',
    'standings_screen_render':'FUN_0601F9CC',
    'mode_transition_vdp_reset':'FUN_0601FD20',
    'replay_car_state_load':  'FUN_0601FE20',
    'car_replay_state_init':  'FUN_0601FEC0',

    # batch_rendering_20.c
    'object_creation':        'FUN_06020366',
    'object_destruction':     'FUN_06020414',

    # batch_rendering_22.c
    'sprite_char_table_init': 'FUN_0600EC78',
    'scene_finalization_a':   'FUN_06025070',
    'scene_finalization_b':   'FUN_06025148',
    'menu_scroll_a_update':   'FUN_060256CC',
    'menu_scroll_b_update':   'FUN_06025BF4',

    # batch_render_pipe_2e.c
    'race_sfx_update':        'FUN_0602F99C',

    # batch_obj_system_38.c
    'vdp2_subsystem_init':    'FUN_06038300',
    'vdp2_scroll_offset':     'FUN_0603853C',

    # batch_obj_system_3a.c
    'cd_command_packet_decode':'FUN_0603A0B0',

    # batch_obj_system_3c.c
    'scu_dma_subsystem_init': 'FUN_0603C104',
    'dma_register_state_clear':'FUN_0603CD5C',

    # batch_system_low.c
    'vdp2_cram_load':         'FUN_060038D4',

    # batch_session_42.c
    'cd_poll_status_ready':   'FUN_06040C98',

    # --- Discovered via size-matching analysis (overflow reduction) ---

    # batch_cd_system_34.c
    'terrain_data_lookup':    'FUN_06034AEE',

    # batch_cd_system_36.c
    'vdp2_tv_mode_config':    'FUN_06036F0C',
    'vdp1_command_builder':   'FUN_060370E4',

    # batch_game_core.c
    'scene_tile_render_near': 'FUN_06006868',

    # batch_game_init.c
    'vec3_angle_calc':        'FUN_06005294',

    # batch_math_util_26.c
    'math_sin_cos':           'FUN_0602745C',

    # batch_obj_system_3a.c
    'cd_seek_to_offset':      'FUN_0603B93C',

    # batch_obj_system_3e.c
    'scroll_plane_angle_accumulate': 'FUN_0603EACC',
    'cd_directory_entry_search':'FUN_0603F2EC',
    'cd_init_and_read_toc':   'FUN_0603F244',
    'cd_parse_dir_entry':     'FUN_0603F538',
    'cd_buf_request_read':    'FUN_0603FF9C',
    'cd_stream_advance':      'FUN_0603FAE4',

    # batch_obj_system_38.c
    'display_mode_init':      'FUN_0603950C',
    'vdp2_priority_set':      'FUN_06038BD4',

    # batch_rendering_22.c
    'scene_processing_stage': 'FUN_06016DD8',

    # batch_state_machine.c
    'speed_force_timer':      'FUN_0600955E',

    # batch_subsystem_1a.c
    'course_select_display_update': 'FUN_06019928',
    'sound_mode_select':      'FUN_06018DDC',

    # batch_subsystem_1c.c
    'scsp_command_dispatch':  'FUN_0601D5F4',

    # batch_subsystem_12.c
    'scene_objects_init':     'FUN_06012F80',
    'camera_vibration_apply': 'FUN_06012344',
    'race_results_hud_display':'FUN_06013C58',
    'podium_object_animate':  'FUN_06013948',

    # batch_session_40.c
    'cd_command_enqueue':     'FUN_06041034',
    'cd_dma_transfer_poll':   'FUN_06041B3C',
    'cd_file_transfer_enqueue':'FUN_060414D0',
    'cd_read_buffer_setup':   'FUN_060408B0',
    'cd_seek_position':       'FUN_060409E6',
    'cd_session_play_poll':   'FUN_060416A8',
    'cd_track_context_init':  'FUN_06040010',
    'replay_input_process':   'FUN_06031898',
    'slot_free':              'FUN_06041180',
    'slot_set_field3c':       'FUN_06041D6C',

    # batch_session_42.c
    'cd_session_read_step':   'FUN_06042088',
    'cd_file_info_extract':   'FUN_06040B90',
    'cd_session_file_batch':  'FUN_06041D74',

    # batch_subsystem_1e.c
    'backup_mem_format':      'FUN_0601E26C',

    # vblank_handlers.c
    'vblank_in_handler':      'FUN_0601CAEE',

    # batch_obj_system_3a.c
    'display_config_copy':    'FUN_0603AFDC',
}

# Functions to SKIP: their FUN_ has no independent definition (only the alias provides it)
# These need their C code + alias to remain active.
SKIP_REDIRECT = {
    'scu_dma_transfer',    # FUN_0602766C only defined via alias in scu_dma.c
    'cdda_buffer_select',  # FUN_0601f87a only defined via alias in batch_subsystem_1e.c
    'vdp1_cmd_table_init', # FUN_06002594 only defined via alias in batch_system_low.c
}


def find_asm_imports():
    """Find all FUN_ addresses that have ASM byte imports (active, not in #if 0)."""
    asm_funs = set()
    for cfile in glob.glob(os.path.join(SRC_DIR, '*.c')):
        with open(cfile, 'r') as f:
            content = f.read()
        # Find .global _FUN_XXXXXX in inline asm blocks
        for m in re.finditer(r'\.global\s+_FUN_([0-9a-fA-F]{6,8})', content):
            addr = m.group(1).upper()
            # Check if this is inside #if 0 ... #endif
            pos = m.start()
            before = content[:pos]
            if0_count = len(re.findall(r'#if\s+0', before))
            endif_count = len(re.findall(r'#endif', before))
            if if0_count <= endif_count:
                asm_funs.add(f'FUN_{addr}')
    return asm_funs


def find_fun_c_defs():
    """Find FUN_ addresses that have C function definitions (not ASM, not in #if 0)."""
    c_defs = set()
    for cfile in glob.glob(os.path.join(SRC_DIR, '*.c')):
        with open(cfile, 'r') as f:
            content = f.read()
        # Simple: find function defs like `void FUN_XXXXXXXX(` or `int FUN_XXXXXXXX(`
        for m in re.finditer(
            r'^(?:void|int|unsigned|short|char|long)[\s\*]+(FUN_[0-9a-fA-F]{6,8})\s*\(',
            content, re.MULTILINE
        ):
            pos = m.start()
            before = content[:pos]
            if0_count = len(re.findall(r'#if\s+0', before))
            endif_count = len(re.findall(r'#endif', before))
            if if0_count <= endif_count:
                c_defs.add(m.group(1).upper())
    return c_defs


def find_named_function_files():
    """Find which files contain named function definitions (not in #if 0)."""
    func_files = {}  # name -> (filepath, line_num)

    for cfile in sorted(glob.glob(os.path.join(SRC_DIR, '*.c'))):
        with open(cfile, 'r') as f:
            lines = f.readlines()

        in_if0 = 0
        for i, line in enumerate(lines):
            stripped = line.strip()
            if stripped.startswith('#if 0'):
                in_if0 += 1
            elif stripped.startswith('#endif') and in_if0 > 0:
                in_if0 -= 1

            if in_if0 > 0:
                continue

            # Match function definitions — handle multi-word types and pointer returns
            # Examples: void foo(), int bar(), unsigned int baz(), char * qux()
            m = re.match(
                r'^(?:void|int|unsigned\s+int|unsigned\s+char|unsigned\s+short|unsigned|'
                r'short|char|long|signed)[\s\*]+(\w+)\s*\(',
                line
            )
            if m:
                name = m.group(1)
                if not name.startswith('FUN_'):
                    func_files[name] = (cfile, i + 1)

    return func_files


def find_already_redirected():
    """Find functions already wrapped with redirect markers in #if 0 blocks.

    Returns set of function names that have been previously redirected.
    """
    redirected = set()
    for cfile in glob.glob(os.path.join(SRC_DIR, '*.c')):
        with open(cfile, 'r') as f:
            content = f.read()
        for m in re.finditer(
            r'#if\s+0\s*/\*\s*(\w+)\s+--\s+redirected\s+to\s+ASM\s+import\s+via\s+linker\s+PROVIDE',
            content
        ):
            redirected.add(m.group(1))
    return redirected


def wrap_function_in_if0(filepath, func_name):
    """Wrap a function definition in #if 0 ... #endif.

    Returns (modified_content, success).
    """
    with open(filepath, 'r') as f:
        content = f.read()

    # Check if already wrapped
    if re.search(rf'#if\s+0\s*/\*\s*{re.escape(func_name)}\s+--\s+redirected', content):
        return content, False  # already done

    # Find the function definition line (signature may not have { on same line)
    sig_pattern = re.compile(
        rf'^((?:void|int|unsigned\s+\w+|unsigned|short|char|long|signed)[\s\*]+'
        rf'{re.escape(func_name)}\s*\([^)]*\))',
        re.MULTILINE
    )
    m = sig_pattern.search(content)
    if not m:
        return content, False

    # Check if already in #if 0
    pos = m.start()
    before = content[:pos]
    if0_count = len(re.findall(r'#if\s+0', before))
    endif_count = len(re.findall(r'#endif', before))
    if if0_count > endif_count:
        return content, False  # already in #if 0

    # Find the opening brace (may be several lines after the signature due to
    # K&R parameter declarations or comment lines)
    func_start = m.start()
    brace_start = content.find('{', m.end())
    if brace_start == -1:
        return content, False
    brace_count = 0
    end = brace_start
    for i in range(brace_start, len(content)):
        if content[i] == '{':
            brace_count += 1
        elif content[i] == '}':
            brace_count -= 1
            if brace_count == 0:
                end = i + 1
                break

    # Get the full function text
    func_text = content[func_start:end]

    # Build replacement: wrap in #if 0
    replacement = (
        f'#if 0 /* {func_name} -- redirected to ASM import via linker PROVIDE */\n'
        f'{func_text}\n'
        f'#endif /* {func_name} */'
    )

    new_content = content[:func_start] + replacement + content[end:]
    return new_content, True


def add_provides_to_linker_script(provides):
    """Add PROVIDE aliases to the linker script.

    Args:
        provides: list of (named_sym, fun_sym) tuples
    """
    with open(LD_FILE, 'r') as f:
        content = f.read()

    # Check if PROVIDE section already exists -- remove it for clean replacement
    if '/* Named function PROVIDE aliases' in content:
        content = re.sub(
            r'\n    /\* Named function PROVIDE aliases.*?(?=\n\n    /\* Overflow|\n    /\* Overflow)',
            '', content, flags=re.DOTALL
        )
    # Also remove any standalone PROVIDE/comment lines left from previous runs
    content = re.sub(
        r'    /\* scu_dma_transfer:.*?\*/\n', '', content
    )

    # Build PROVIDE block
    provide_lines = []
    provide_lines.append('')
    provide_lines.append('    /* Named function PROVIDE aliases -- auto-generated')
    provide_lines.append('     * Maps named C symbols to their FUN_ ASM import addresses.')
    provide_lines.append('     * Active only when the named C function is wrapped in #if 0.')
    provide_lines.append('     */')
    for named, fun in sorted(provides, key=lambda x: x[1]):
        provide_lines.append(f'    PROVIDE(_{named} = _{fun});')

    provide_block = '\n'.join(provide_lines) + '\n'

    # Insert before the overflow section
    overflow_marker = '    /* Overflow area for C functions'
    if overflow_marker in content:
        content = content.replace(overflow_marker, provide_block + '\n' + overflow_marker)
    else:
        print("  WARNING: Could not find overflow section marker in linker script")
        return content

    return content


def scan():
    """Scan and report what can be redirected.

    Includes both:
    - Functions with active C definitions that CAN be redirected
    - Functions already redirected (in #if 0 with redirect marker)
    """
    asm_imports = find_asm_imports()
    fun_c_defs = find_fun_c_defs()
    func_files = find_named_function_files()
    already_redirected = find_already_redirected()

    print(f"Found {len(asm_imports)} FUN_ ASM imports")
    print(f"Found {len(fun_c_defs)} FUN_ C definitions")
    print(f"Found {len(func_files)} named function definitions (active)")
    print(f"Found {len(already_redirected)} already-redirected functions")
    print()

    provides = []

    # Check state handlers
    print("=== State Handlers ===")
    for name, fun in sorted(STATE_HANDLER_MAP.items()):
        has_asm = fun in asm_imports
        has_c_def = fun in fun_c_defs
        has_named_def = name in func_files
        is_redirected = name in already_redirected

        if is_redirected:
            print(f"  DONE {name} -> {fun} (already redirected)")
            provides.append((name, fun))
        elif has_named_def and (has_asm or has_c_def):
            file_info = func_files[name]
            print(f"  OK  {name} -> {fun} [{os.path.basename(file_info[0])}:{file_info[1]}]"
                  f" asm={has_asm} c={has_c_def}")
            provides.append((name, fun))
        else:
            reasons = []
            if not has_named_def:
                reasons.append("no named C def")
            if not has_asm and not has_c_def:
                reasons.append(f"no FUN_ def for {fun}")
            print(f"  SKIP {name} -> {fun} ({', '.join(reasons)})")

    state_count = sum(1 for n, _ in provides if n.startswith('state_'))
    print(f"\nCan redirect: {state_count}/{len(STATE_HANDLER_MAP)} state handlers")

    # Check other named functions
    print("\n=== Other Named Functions ===")
    other_count = 0
    for name, fun in sorted(OTHER_NAMED_MAP.items()):
        if name in SKIP_REDIRECT:
            print(f"  SKIP {name} -> {fun} (in SKIP_REDIRECT list)")
            continue

        has_asm = fun in asm_imports
        has_c_def = fun in fun_c_defs
        has_named_def = name in func_files
        is_redirected = name in already_redirected

        if is_redirected:
            print(f"  DONE {name} -> {fun} (already redirected)")
            provides.append((name, fun))
            other_count += 1
        elif has_named_def and (has_asm or has_c_def):
            file_info = func_files[name]
            print(f"  OK  {name} -> {fun} [{os.path.basename(file_info[0])}:{file_info[1]}]"
                  f" asm={has_asm} c={has_c_def}")
            provides.append((name, fun))
            other_count += 1
        else:
            reasons = []
            if not has_named_def:
                reasons.append("no named C def")
            if not has_asm and not has_c_def:
                reasons.append(f"no FUN_ def for {fun}")
            print(f"  SKIP {name} -> {fun} ({', '.join(reasons)})")

    print(f"\nCan redirect: {other_count}/{len(OTHER_NAMED_MAP)} named functions")
    print(f"\nTotal redirectable: {len(provides)}")

    return provides


def apply(provides):
    """Apply redirections: wrap C code in #if 0 and add PROVIDE aliases."""
    func_files = find_named_function_files()

    # Group by file for efficiency
    files_modified = set()

    print("\n=== Wrapping C code in #if 0 ===")
    for named, fun in provides:
        if named not in func_files:
            print(f"  SKIP {named} -- not found in source")
            continue

        filepath = func_files[named][0]
        with open(filepath, 'r') as f:
            content = f.read()

        new_content, changed = wrap_function_in_if0(filepath, named)
        if changed:
            with open(filepath, 'w', newline='\n') as f:
                f.write(new_content)
            print(f"  Wrapped {named} in {os.path.basename(filepath)}")
            files_modified.add(filepath)
        else:
            print(f"  SKIP {named} -- already wrapped or not found")

    print(f"\nModified {len(files_modified)} source files")

    # Add PROVIDE aliases to linker script
    print("\n=== Adding PROVIDE aliases to linker script ===")
    new_ld = add_provides_to_linker_script(provides)
    with open(LD_FILE, 'w', newline='\n') as f:
        f.write(new_ld)
    print(f"  Added {len(provides)} PROVIDE aliases to {os.path.basename(LD_FILE)}")


if __name__ == '__main__':
    if '--apply' in sys.argv:
        provides = scan()
        if provides:
            apply(provides)
        else:
            print("Nothing to redirect!")
    else:
        scan()
