#!/usr/bin/env python3
"""L2 Pass: Rename FUN_XXXXXXXX functions to meaningful names.

Scans all .c files in reimpl/src/ and renames function references
based on names derived from annotated ASM analysis.

Usage:
    python3 tools/l2_rename_funcs.py [--dry-run] [--file FILENAME]
"""

import os
import re
import sys

PROJ = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
REIMPL_DIR = os.path.join(PROJ, "reimpl", "src")

# Function naming map derived from annotated ASM files.
# Format: "FUN_XXXXXXXX" -> "new_name"
# Only includes functions with clear enough descriptions to name.
#
# Sources: vblank_system.s, system_init.s, vdp_hardware.s, sound_driver.s,
#          math_helpers.s, collision.s, car_collision.s, player_physics.s,
#          force_system.s, force_tables.s, lap_counting.s, ai_behavior.s,
#          ai_physics_pipeline.s, rendering.s, scene_camera.s, etc.

FUNC_NAMES = {
    # === VBlank / Frame Timing (vblank_system.s) ===
    "FUN_06006F3C": "vblank_in_handler",
    "FUN_06007268": "vblank_out_handler",
    "FUN_0600A392": "per_frame_setup",

    # === System Init (system_init.s) ===
    "FUN_06003218": "sound_timer_init",
    "FUN_06003274": "vdp_init_dispatcher",
    "FUN_0600330A": "vdp_advanced_init",
    "FUN_06003466": "vdp2_data_transfer_course0",
    "FUN_060034D4": "vdp2_data_transfer_course1",
    "FUN_06003508": "vdp2_data_transfer_course2",
    "FUN_06003578": "vdp2_mega_init",
    "FUN_06003A3C": "master_init_dispatcher",
    "FUN_06004670": "obj_template_init",
    "FUN_06004A98": "global_engine_init",
    "FUN_06004F14": "obj_transform_cache",
    "FUN_06004F28": "obj_position_update",
    "FUN_0600508C": "obj_coord_setter",

    # === Math Utilities (system_init.s, math_helpers.s) ===
    "FUN_06005120": "hw_render_dispatcher",
    "FUN_06005198": "display_list_process",
    "FUN_06005294": "vec3_angle_calc",
    "FUN_060052F8": "math_sqrt",
    "FUN_06005300": "math_atan2_xz",
    "FUN_06005380": "math_atan2_zx",
    "FUN_06005494": "obj_state_writer",
    "FUN_0600553C": "sprite_frame_select",
    "FUN_060055BC": "perspective_project",

    # === VDP Hardware (vdp_hardware.s) ===
    "FUN_0600A140": "vdp1_init_vram",
    "FUN_06014A04": "vdp1_buffer_addr_update",
    "FUN_06014A74": "vdp1_buffer_flip",
    "FUN_06014884": "vdp2_scroll_update",
    "FUN_06014868": "vdp2_scroll_setup",
    "FUN_06026CA4": "vdp2_register_setup",
    "FUN_0603931C": "vdp1_polygon_setup",
    "FUN_0603836C": "vdp2_secondary_config",
    "FUN_06038F78": "vdp1_display_list_cmd",
    "FUN_06039050": "vdp1_vblank_cmd",

    # === Color/Palette (vdp_hardware.s) ===
    "FUN_060038D4": "palette_init",
    "FUN_0600EC78": "palette_update_runtime",
    "FUN_0601938C": "palette_dynamic_effects",

    # === SCU DMA (vdp_hardware.s, math_helpers.s) ===
    "FUN_0602766C": "scu_dma_transfer",
    "FUN_0602761E": "mem_copy_word_idx",
    "FUN_06027630": "dma_alt_transfer",
    "FUN_06028654": "dma_mem_transfer",
    "FUN_0603FE80": "scu_dma_runtime",

    # === Math (math_helpers.s) ===
    "FUN_0602755C": "math_div64_unprotected",
    "FUN_0602ECCC": "math_div32_protected",
    "FUN_06027358": "math_sin_cos",

    # === Sound (sound_driver.s) ===
    "FUN_0601D5F4": "sound_cmd_dispatch",
    "FUN_0601D6B2": "sound_direct_write",
    "FUN_0601D6D4": "sound_chan_a_handler",
    "FUN_0601D6F8": "sound_chan_b_handler",
    "FUN_0601D72C": "sound_chan_c_handler",
    "FUN_0601D778": "sound_direct_pass",
    "FUN_0601D79C": "sound_chan_d_handler",
    "FUN_0601DB84": "sound_mailbox_wait",

    # === Collision (collision.s, car_collision.s, collision_response.s) ===
    "FUN_060316D0": "car_collision_response",
    "FUN_060316D0": "car_collision_response",

    # === Player Physics (player_physics.s) ===
    "FUN_06008640": "steering_physics_update",

    # === Force System (force_system.s, force_tables.s) ===

    # === Lap Counting (lap_counting.s) ===

    # === AI (ai_behavior.s, ai_physics_pipeline.s) ===

    # === Rendering (rendering.s, scene_renderer.s, vertex_pipeline.s) ===
    "FUN_0602EEB8": "per_car_render_pipeline",
    "FUN_06027CA4": "scene_3d_renderer",

    # === SMPC / Input (input_smpc.s) ===
    "FUN_060389A6": "smpc_intback_trigger",

    # === CD Block ===
    "FUN_06018EAC": "cd_status_read",
    "FUN_060349C4": "cd_register_double_read",

    # === Game Loop (vblank_system.s, state_handlers.s) ===
    "FUN_06009FFC": "scu_interrupt_reconfig",
    "FUN_06012B58": "cd_frame_sync_advance",
    "FUN_06012CF4": "game_subsystem_init",
    "FUN_06012E6A": "game_subsystem_init2",
    "FUN_06018EE4": "cd_system_init",
    "FUN_0601F936": "render_system_init",
    "FUN_0601492C": "vdp_system_init_a",
    "FUN_060149E0": "vdp_system_init_b",

    # === Pre-Race States (pre_race_states.s) ===
    "FUN_06034E58": "menu_system_init",
    "FUN_0603BF7C": "course_system_init",

    # === Object Management ===
    "FUN_06005174": "object_system_init",
    "FUN_06026CE0": "vdp1_texture_palette_init",
}


def rename_in_content(content, old_name, new_name):
    """Replace all occurrences of old_name with new_name in content.

    Only replaces standalone identifiers (not partial matches).
    """
    pattern = r'\b' + re.escape(old_name) + r'\b'
    new_content = re.sub(pattern, new_name, content)
    count = len(re.findall(pattern, content))
    return new_content, count


def process_file(filepath, dry_run=False):
    """Process a single file, renaming functions."""
    with open(filepath, 'r', errors='replace') as f:
        original = f.read()

    content = original
    total = 0
    details = []

    for old_name, new_name in FUNC_NAMES.items():
        content, count = rename_in_content(content, old_name, new_name)
        if count > 0:
            total += count
            details.append(f"  {old_name} -> {new_name}: {count}")

    if total > 0 and not dry_run:
        with open(filepath, 'w', newline='\n') as f:
            f.write(content)

    return total, details


def main():
    dry_run = '--dry-run' in sys.argv
    target_file = None
    if '--file' in sys.argv:
        idx = sys.argv.index('--file')
        if idx + 1 < len(sys.argv):
            target_file = sys.argv[idx + 1]

    total_all = 0
    files_changed = 0

    for fname in sorted(os.listdir(REIMPL_DIR)):
        if not fname.endswith('.c'):
            continue
        if target_file and fname != target_file:
            continue

        filepath = os.path.join(REIMPL_DIR, fname)
        count, details = process_file(filepath, dry_run)

        if count > 0:
            total_all += count
            files_changed += 1
            action = "would rename" if dry_run else "renamed"
            print(f"{fname}: {action} {count} references")
            for d in details:
                print(d)
            print()

    mode = "[DRY RUN] " if dry_run else ""
    print(f"{mode}Total: {total_all} renames across {files_changed} files")


if __name__ == "__main__":
    main()
