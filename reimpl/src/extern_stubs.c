/* extern_stubs.c -- Stub implementations for external dependencies
 *
 * Functions referenced by translated code but not yet translated themselves.
 * As each function gets a real implementation, remove its stub from here.
 */

/* FUN_06012C3C: moved to cd_io_retry.c */
void FUN_0603F3F6(void) { }
void FUN_06034D1C(void) { }
/* FUN_06041648: moved to cd_status.c */
/* FUN_06014F34: moved to sequence_player.c */
/* FUN_0601712C: moved to slot_dispatch.c */
/* FUN_06035F04: moved to cd_command_exec.c */
int FUN_06035D5A(void) { return 0; }
int FUN_06035FEC(int a, int b) { (void)a; (void)b; return 0; }
void FUN_0603FA1A(int *a, int b) { (void)a; (void)b; }
/* FUN_0603B93C: moved to callback_dispatch.c */
/* FUN_06020DEE: moved to slot_clear.c */
/* FUN_06038120: moved to vdp_polygon_setup.c */
/* FUN_06027378: moved to atan.c */
void FUN_06012450(int a, int b) { (void)a; (void)b; }

/* Game loop dependencies (from car_iteration.c) */
/* FUN_0600E0C0: moved to per_car_loop.c */
/* FUN_0600E410: moved to physics_entry.c */
/* FUN_0600E47C: moved to physics_entry.c */
/* FUN_0600E99C: moved to camera_setup.c */
/* FUN_0600E4F2: moved to physics_entry.c */
/* FUN_0600A8BC: moved to speed_counter.c */
/* FUN_0602F99C: moved to batch_render_pipe_2e.c as race_sfx_update */

/* Physics entry dependencies (from physics_entry.c) */
/* FUN_060081F4: moved to gear_shift.c */
/* FUN_0600E7C8: moved to alt_physics.c */
/* FUN_0602D88E: moved to misc_physics_step.c */
/* FUN_06006838: already in batch_game_core.c */
/* FUN_06005ECC: moved to wheel_transform.c */
/* FUN_0600DA7C: moved to checkpoint_detect.c */
/* FUN_0600DBA0: moved to checkpoint_continue.c */
/* FUN_0600DC74: moved to checkpoint_clear.c */
/* FUN_0600CE66: moved to lap_counting.c */
/* FUN_0600D780: already in lap_counting.c */

/* Per-car loop dependencies (from per_car_loop.c) */
/* FUN_06030A06: moved to timer_update.c */
/* FUN_06030EE0: moved to timer_update.c */
/* FUN_060061C8: moved to car_position_update.c */
/* FUN_06026DBC: moved to transform_stack.c */
/* FUN_06026E0C: moved to transform_stack.c */
/* FUN_06026EDE: moved to heading_rotation.c */
/* FUN_06026FFC: moved to matrix_transform.c */
void FUN_06027CA4(int buffer, int index) { (void)buffer; (void)index; }
void FUN_0603053C(int arg) { (void)arg; }

/* Race init dependencies (from race_init.c) */
/* FUN_06026E02: moved to transform_stack.c */
/* FUN_060270C6: moved to transform_stack.c */
/* FUN_0600629C: moved to car_table_init.c */
void FUN_06021450(void) { }

/* E4F2 dependencies (from physics_entry.c) */
void FUN_0602ECF2(void) { }
/* FUN_0600DB64: moved to lap_counting.c */
/* FUN_0600EA18: moved to road_recovery.c */
/* FUN_0602D9F0: moved to special_trigger.c */
/* FUN_0600C994: moved to road_segment_find.c */

/* Lap counting system dependencies (from lap_counting.c) */
/* FUN_0600CDD0: moved to lap_counting.c */
/* FUN_0600DD88: moved to lap_counting.c */
/* FUN_0600DCC8: moved to lap_counting.c */
/* FUN_0601D7D0: moved to lap_announce.c */

/* CD I/O dependencies (from cd_io_retry.c) */
void FUN_06012BDC(void) { }
int  FUN_0603AE08(int command) { (void)command; return 0; }
int  FUN_0603B1B6(int handle, int zero, int dest, int flag) { (void)handle; (void)zero; (void)dest; (void)flag; return 0; }

/* CD subsystem init dependencies (from stubs.c / game_subsystem_init) */
int  FUN_0603AC1C(int mode, int src, int config) { (void)mode; (void)src; (void)config; return 3; }

/* CD command dependencies (from cd_command.c) */
void FUN_060349C4(int *result_buf) { (void)result_buf; }

/* VDP state init dependencies (from vdp_state_init.c) */
void FUN_06038BD4(int mode, int param) { (void)mode; (void)param; }
void FUN_060393FC(int r4, int r5, int r6, int r7, int stack_arg) { (void)r4; (void)r5; (void)r6; (void)r7; (void)stack_arg; }

/* Visual physics update dependencies (from visual_physics_update.c) */
void FUN_0602DB00(void) { }
void FUN_0602DC18(void) { }

/* VDP data decompressor (ASM-only, saves r0-r14) */
void FUN_06028654(int param_1, int param_2) { (void)param_1; (void)param_2; }

/* Channel rendering processor (ASM-only, heavy register save) */
void FUN_06020366(int param_1) { (void)param_1; }

/* Ghidra phantom sub-functions (mid-function offsets, not real entry points) */
int FUN_0603ec40(int a) { (void)a; return 0; }
int FUN_06013c58(void) { return 0; }
