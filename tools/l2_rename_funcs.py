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
    # === VBlank / Frame Timing (vblank_system.s, frame_timing.s) ===
    "FUN_06006F3C": "vblank_in_handler",
    "FUN_06007268": "vblank_out_handler",
    "FUN_0600A392": "per_frame_setup",
    "FUN_060078DC": "frame_end_display_commit",
    "FUN_06007BCC": "vdp1_sprite_command_builder",

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
    "FUN_06005788": "background_layer_init",
    "FUN_0600579C": "vdp_mode_setup_disp",
    "FUN_060058FA": "frame_dispatcher",
    "FUN_06005928": "animation_frame_counter",
    "FUN_06005A22": "input_event_handler",
    "FUN_06005AE8": "display_compositor",
    "FUN_06005C98": "world_camera_state_upd",
    "FUN_06005DD4": "animation_frame_transform",

    # === Subsystem Updates (subsystem_updates.s) ===
    "FUN_06005ECC": "segment_position_tracking",
    "FUN_060061C8": "pre_render_transform_setup",

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
    "FUN_060276CC": "spring_damper_physics",

    # === Car Array / Object Init (object_management.s) ===
    "FUN_0600629C": "car_array_init_loop",
    "FUN_0600EB14": "race_init_master",
    "FUN_0600E1D4": "per_car_type_init",
    "FUN_0600DE70": "per_frame_car_iteration",
    "FUN_0600E4F2": "per_car_frame_update",
    "FUN_0600E410": "per_car_update_simplified",
    "FUN_0600DF66": "update_mode_dispatcher",
    "FUN_0600DE40": "race_countdown_update",
    "FUN_0600DE54": "vs_mode_update",
    "FUN_0600E0C0": "per_car_update_loop",
    "FUN_0600E99C": "preupdate_camera_ai",
    "FUN_0600C302": "car_state_finalize",

    # === Force System (force_system.s, force_tables.s) ===
    "FUN_060081F4": "gas_force_apply",
    "FUN_060085B8": "brake_force_apply",
    "FUN_06008640": "steering_physics_update",
    "FUN_060086C0": "force_table_apply",
    "FUN_06008730": "speed_force_timer",
    "FUN_06008318": "gear_shift_handler",

    # === Race States (race_states.s, state_handlers.s) ===
    "FUN_06008EBC": "state_14_first_frame_race",
    "FUN_06009098": "state_15_main_race_loop",
    "FUN_06009290": "state_16_post_countdown",
    "FUN_060092D0": "state_17_post_lap_results",
    "FUN_060096DC": "state_18_time_extension_setup",
    "FUN_06009788": "state_19_time_extension",
    "FUN_06009A60": "state_20_race_completion",
    "FUN_06009CFC": "state_24_post_race_init",
    "FUN_06009D4E": "state_25_post_race_display",
    "FUN_06009508": "state_28_abort_processing",
    "FUN_0600955E": "state_29_post_race_menu",

    # === Collision (collision.s, car_collision.s, collision_response.s) ===
    "FUN_060316D0": "car_collision_response",
    "FUN_06031700": "collision_helper_first_car",
    "FUN_06031898": "collision_helper_second_car",
    "FUN_060316C4": "collision_response_entry",
    "FUN_0600C5D6": "player_collision_detect",
    "FUN_0600CA96": "course_correction_gentle",
    "FUN_0600CC38": "heading_update_strong",
    "FUN_0600CD40": "track_relative_position",
    "FUN_0600CF58": "collision_response_dispatcher",
    "FUN_0600D12C": "collision_response_passive",
    "FUN_0600D210": "collision_response_aggressive",
    "FUN_0600D0B8": "collision_simple",
    "FUN_0600C928": "speed_reduction_collision",
    "FUN_0600C970": "speed_boost_course_table",
    "FUN_0600A914": "car_collision_proximity",

    # === Player Physics (player_physics.s, speed_position.s) ===
    "FUN_0600E71A": "player_physics_orchestrator",
    "FUN_0600C4F8": "speed_curve_calc",
    "FUN_0600CEBA": "track_segment_advance",
    "FUN_0600E906": "ai_car_physics",
    "FUN_0600D266": "friction_stub_noop",
    "FUN_0600EA18": "velocity_calculation",

    # === Lap Counting (lap_counting.s) ===
    "FUN_0600D780": "checkpoint_change_detect",
    "FUN_0600D9BC": "lap_completion_flag",
    "FUN_0600D92C": "lap_timing_record",
    "FUN_0600DA7C": "finish_line_proximity",
    "FUN_0600DBA0": "finish_line_display",

    # === Camera / Scene (scene_camera.s, race_orchestration.s) ===
    "FUN_0600AA98": "scene_renderer_type_a",
    "FUN_0600AC44": "scene_renderer_type_b",
    "FUN_0600ADD4": "camera_car_transform_setup",
    "FUN_0600AFB2": "camera_tracking_transform",
    "FUN_0600B1A0": "course_specific_renderer",
    "FUN_0600B340": "primary_scene_renderer",
    "FUN_0600B4D2": "camera_position_lerping",
    "FUN_0600B6A0": "cs0_object_loop",
    "FUN_0600B914": "main_object_loop",
    "FUN_0600BB94": "multi_mode_camera",
    "FUN_0600BF70": "camera_heading_tracker",
    "FUN_0600BFFC": "hud_racing_state_init",
    "FUN_0600C010": "race_state_machine",
    "FUN_0600C170": "race_utility_calc",
    "FUN_0600C218": "secondary_hud_frame_setup",
    "FUN_0600C3A8": "controller_input_decoder",
    "FUN_0600CB90": "race_position_interp",
    "FUN_0600CDD0": "race_heading_calc",
    "FUN_0600D31C": "physics_calc_dispatcher",
    "FUN_0600D41C": "vehicle_state_physics",
    "FUN_0600D50C": "main_rendering_batch",
    "FUN_0600DD88": "per_object_audio_distance",
    "FUN_0600E7C8": "per_frame_race_orchestrator",
    "FUN_0600F424": "game_state_dispatcher",
    "FUN_0600F870": "race_countdown_timer",
    "FUN_0600FFD0": "hud_race_display",

    # === AI (ai_behavior.s) ===
    "FUN_0600C74E": "ai_main_processing",
    "FUN_06027EDE": "ai_car_sprite_render",

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
    "FUN_0601D7D0": "display_notification_sound",
    "FUN_0603072E": "sound_state_dispatcher",
    "FUN_06030B68": "sound_event_handler",

    # === Engine Sound (engine_sound.s) ===
    "FUN_0600A8BC": "audio_phase_ticker",
    "FUN_060302C6": "engine_sound_generator",

    # === HUD / Menu Display (menu_display.s) ===
    "FUN_0603268C": "race_hud_orchestrator",
    "FUN_06030FC0": "speed_position_display",
    "FUN_0603136E": "timer_display",
    "FUN_06030EE0": "lap_counter_display",
    "FUN_0601E2B4": "hud_overlay_renderer",
    "FUN_0601E4D4": "hud_state_machine",
    "FUN_06018DDC": "handler_dispatcher",

    # === Rendering Pipeline (rendering.s, render_pipeline.s) ===
    "FUN_0602EEB8": "per_car_render_pipeline",
    "FUN_06027CA4": "scene_3d_renderer",
    "FUN_0602EFF0": "rendering_pass1_camera",
    "FUN_0602DB22": "per_frame_command_reset",
    "FUN_06021450": "track_object_placement",
    "FUN_0602382C": "scene_setup_master",
    "FUN_06022140": "scene_processing_stage",
    "FUN_06022820": "object_render_list_builder",
    "FUN_06022AE0": "object_render_processor",
    "FUN_0602304C": "render_batch_processor",
    "FUN_06023290": "projection_manager",
    "FUN_06025070": "scene_finalization_a",
    "FUN_06025148": "scene_finalization_b",
    "FUN_0603DDFC": "master_game_state_machine",

    # === VDP1 Commands (render_pipeline.s) ===
    "FUN_0602D08A": "vdp1_sprite_command_gen",
    "FUN_0602D43C": "vdp1_polygon_command_gen",
    "FUN_0602CDF6": "vdp1_command_list_mgr",
    "FUN_0602CCEC": "vdp1_attribute_setup",
    "FUN_0602CA84": "vdp1_coordinate_setup",
    "FUN_0602C884": "vdp1_texture_setup",
    "FUN_0602C8E2": "vdp1_color_setup",
    "FUN_06037660": "vdp1_command_builder",
    "FUN_060370E4": "texture_management",

    # === Scene Graph (render_pipeline.s) ===
    "FUN_0602B9EC": "scene_graph_walker",
    "FUN_0602F99C": "sprite_batch_renderer",
    "FUN_0602DC18": "sprite_animation_engine",
    "FUN_0602F7EA": "sprite_transform",
    "FUN_06020E74": "object_state_manager",
    "FUN_06020366": "object_creation",
    "FUN_06020414": "object_destruction",
    "FUN_060204B4": "object_list_iterator",
    "FUN_0602052C": "object_visibility_test",
    "FUN_060200A4": "race_start_init_render",

    # === Vertex Pipeline (vertex_pipeline.s) ===
    "FUN_0602ECF2": "physics_integration_disp",
    "FUN_0602F0E8": "perspective_projection_3d",
    "FUN_0602F3EC": "fixed_point_mac_core",
    "FUN_0602F474": "lighting_intensity_select",
    "FUN_0602F4B4": "distance_fog_attenuation",
    "FUN_0602F5B6": "material_color_blending",
    "FUN_0602F7BC": "animation_timer_decrements",

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

    # === Replay / Camera (replay_camera.s) ===
    "FUN_0601DBB8": "replay_camera_controller",
    "FUN_0601C3E4": "master_control_dispatcher",

    # === Track Geometry (track_geometry.s) ===
    "FUN_06016CDC": "track_segment_init",
    "FUN_06016DD8": "track_vertex_array_builder",
    "FUN_06017814": "track_geometry_processor",
    "FUN_06017CEC": "track_state_machine_anim",
    "FUN_060173AC": "geometry_pipeline_coord",
    "FUN_06015EB8": "vdp2_layer_init",
    "FUN_06018278": "track_calculation",
    "FUN_06034900": "terrain_data_lookup",
    "FUN_06034AEE": "track_intersection_test",
    "FUN_06034B54": "mesh_boundary_check",
    "FUN_06034B9A": "road_segment_query",

    # === Course Physics (track_geometry.s) ===
    "FUN_06019BC8": "course_0_car_physics_init",
    "FUN_06019DB8": "course_1_car_physics_init",
    "FUN_06019FB2": "course_2_car_physics_init",
    "FUN_0601A3F4": "car_physics_finalize",
    "FUN_0601A940": "course_init_pipeline",
    "FUN_0601A80C": "course_data_loader",

    # === Object Management ===
    "FUN_06005174": "object_system_init",
    "FUN_06026CE0": "vdp1_texture_palette_init",
}


def rename_in_content(content, old_name, new_name):
    """Replace all occurrences of old_name with new_name in content.

    Only replaces standalone identifiers (not partial matches).
    Skips alias declarations to avoid self-referencing aliases.
    """
    pattern = r'\b' + re.escape(old_name) + r'\b'
    lines = content.split('\n')
    count = 0
    new_lines = []
    for line in lines:
        if '__attribute__((alias' in line:
            new_lines.append(line)
            continue
        matches = len(re.findall(pattern, line))
        if matches > 0:
            count += matches
            line = re.sub(pattern, new_name, line)
        new_lines.append(line)
    return '\n'.join(new_lines), count


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
