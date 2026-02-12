void smpc_intback_trigger(void) { }
void FUN_060389A6(void) __attribute__((alias("smpc_intback_trigger")));
extern void FUN_06020c3c(void);
extern void FUN_06020c3c(void);
void FUN_06020C3C(void) { FUN_06020c3c(); }
/* cd_status_read / FUN_06018EAC: moved to cd_command.c */
/* FUN_06009FFC: moved to batch_state_machine.c as sound_channels_reset */
void cd_frame_sync_advance(void) { }
void FUN_06012B58(void) __attribute__((alias("cd_frame_sync_advance")));
/* FUN_0600A1B8: moved to game_state_utils.c */
void FUN_060072E6(void) { }
void FUN_06007370(void) { }
void FUN_0600747C(void) { }
void FUN_06007CEC(void) { }
void FUN_06007D8E(void) { }
void FUN_06007E08(void) { }

/* FUN_060033E6: moved to render_setup.c */
extern void FUN_060053ac(int, int, int);
extern void FUN_060053ac(int, int, int);
void FUN_060053AC(int r4, int r5, int r6) { FUN_060053ac(r4, r5, r6); }
void FUN_060055BC(void) { }
void perspective_project(void) __attribute__((alias("FUN_060055BC")));
extern void FUN_060078dc(void);
extern void FUN_060078dc(void);
void FUN_060078DC(void) { FUN_060078dc(); }
void frame_end_display_commit(void) __attribute__((alias("FUN_060078DC")));
/* FUN_0600A084: moved to render_setup.c */
/* FUN_0600A0C0: moved to vdp_state_init.c */
/* FUN_0600A33C: moved to game_state_utils.c */
/* FUN_0600A914: moved to collision.c */
extern void FUN_0600bb94(void);
extern void FUN_0600bb94(void);
void FUN_0600BB94(void) { FUN_0600bb94(); }
void multi_mode_camera(void) __attribute__((alias("FUN_0600BB94")));
extern void FUN_0600bffc(void);
extern void FUN_0600bffc(void);
void FUN_0600BFFC(void) { FUN_0600bffc(); }
void hud_racing_state_init(void) __attribute__((alias("FUN_0600BFFC")));
/* FUN_0600C302: moved to car_iteration.c */
/* FUN_0600DE54: moved to car_iteration.c */
/* FUN_0600DE70: moved to car_iteration.c */
/* FUN_0600EB14: moved to race_init.c */
extern void FUN_06010a5c(int);
extern void FUN_06010a5c(int);
void FUN_06010A5C(int arg) { FUN_06010a5c(arg); }
extern void FUN_060120c8(void);
extern void FUN_060120c8(void);
void FUN_060120C8(void) { FUN_060120c8(); }
extern void FUN_060121a8(void);
extern void FUN_060121a8(void);
void FUN_060121A8(void) { FUN_060121a8(); }
extern void FUN_06018a3c(void);
extern void FUN_06018a3c(void);
void FUN_06018A3C(void) { FUN_06018a3c(); }
/* FUN_06018E70: moved to cd_command.c */
/* FUN_060192CA: moved to batch_subsystem_18.c as sound_channels_stop */
void FUN_0601D5F4(int r4, int r5) { (void)r4; (void)r5; }
void sound_cmd_dispatch(int r4, int r5) __attribute__((alias("FUN_0601D5F4")));
void FUN_0601D9B0(void) { }
void FUN_0601DBB8(void) { }
void replay_camera_controller(void) __attribute__((alias("FUN_0601DBB8")));
extern void FUN_0601de50(void);
extern void FUN_0601de50(void);
void FUN_0601DE50(void) { FUN_0601de50(); }
extern void FUN_0601e100(void);
extern void FUN_0601e100(void);
void FUN_0601E100(void) { FUN_0601e100(); }
extern void FUN_0601f784(void);
extern void FUN_0601f784(void);
void FUN_0601F784(void) { FUN_0601f784(); }
extern void FUN_060268b0(int);
extern void FUN_060268b0(int);
void FUN_060268B0(int arg) { FUN_060268b0(arg); }
/* FUN_06026CE0: moved to render_setup.c */
void FUN_060283E0(int r4, int r5, int r6, int r7) { (void)r4; (void)r5; (void)r6; (void)r7; }
extern void FUN_0602eff0(void);
extern void FUN_0602eff0(void);
void FUN_0602EFF0(void) { FUN_0602eff0(); }
void rendering_pass1_camera(void) __attribute__((alias("FUN_0602EFF0")));
extern void FUN_0602f0e8(void);
extern void FUN_0602f0e8(void);
void FUN_0602F0E8(void) { FUN_0602f0e8(); }
void perspective_projection_3d(void) __attribute__((alias("FUN_0602F0E8")));
extern void FUN_0602f7ea(void);
extern void FUN_0602f7ea(void);
void FUN_0602F7EA(void) { FUN_0602f7ea(); }
void sprite_transform(void) __attribute__((alias("FUN_0602F7EA")));
void FUN_060302C6(void) { }
void engine_sound_generator(void) __attribute__((alias("FUN_060302C6")));
extern void FUN_060321c0(void);
extern void FUN_060321c0(void);
void FUN_060321C0(void) { FUN_060321c0(); }
extern void FUN_06033aac(void);
extern void FUN_06033aac(void);
void FUN_06033AAC(void) { FUN_06033aac(); }
extern void FUN_06033bc8(void);
extern void FUN_06033bc8(void);
void FUN_06033BC8(void) { FUN_06033bc8(); }
void FUN_06034900(void) { }

void FUN_060284AE(int r4, int r5, int r6, int r7) { (void)r4; (void)r5; (void)r6; (void)r7; }
void FUN_0602834A(int r4, int r5, int r6, int r7) { (void)r4; (void)r5; (void)r6; (void)r7; }
extern void FUN_06018ddc(int);
extern void FUN_06018ddc(int);
void FUN_06018DDC(int arg) { FUN_06018ddc(arg); }
extern void FUN_06014a04(void);
extern void FUN_06014a04(void);
void FUN_06014A04(void) { FUN_06014a04(); }
/* FUN_0600DF66: moved to car_iteration.c */
extern void FUN_0601df88(void);
extern void FUN_0601df88(void);
void FUN_0601DF88(void) { FUN_0601df88(); }
/* FUN_0602853E: moved to batch_vdp_cmd_28.c as vdp_display_list_fill */
void FUN_06014884(int r4, int r5, int r6) { (void)r4; (void)r5; (void)r6; }
/* FUN_060032D4: moved to vdp_sprite_init.c */
extern void FUN_0600a294(void);
extern void FUN_0600a294(void);
void FUN_0600A294(void) { FUN_0600a294(); }
/* FUN_0601FD74: moved to mode_dispatch.c */
/* FUN_0600DE40: moved to car_iteration.c */
extern void FUN_06033ea8(void);
extern void FUN_06033ea8(void);
void FUN_06033EA8(void) { FUN_06033ea8(); }
extern void FUN_06014a74(void);
extern void FUN_06014a74(void);
void FUN_06014A74(void) { FUN_06014a74(); }
extern void FUN_06014d2c(void);
extern void FUN_06014d2c(void);
void FUN_06014D2C(void) { FUN_06014d2c(); }
extern void FUN_060190b8(void);
extern void FUN_060190b8(void);
void FUN_060190B8(void) { FUN_060190b8(); }
/* FUN_06012F80: moved to batch_subsystem_12.c as scene_objects_init */
extern void FUN_0601389e(void);
extern void FUN_0601389e(void);
void FUN_0601389E(void) { FUN_0601389e(); }
/* FUN_0600DFD0: moved to visual_physics_update.c */
extern void FUN_0600c218(void);
extern void FUN_0600c218(void);
void FUN_0600C218(void) { FUN_0600c218(); }
/* FUN_0600E060: moved to visual_physics_update.c */
/* FUN_0601F8C0: moved to mode_transition.c */
/* FUN_0601F900: moved to mode_transition.c */
/* FUN_060149E0: moved to render_setup.c */

extern void FUN_0601c978(void);
extern void FUN_0601c978(void);
void FUN_0601C978(void) { FUN_0601c978(); }
void FUN_0601CAEE(void) { }
/* FUN_0600A140: moved to vdp1_clear.c */
extern void FUN_0600330a(void);
extern void FUN_0600330a(void);
void FUN_0600330A(void) { FUN_0600330a(); }
extern void FUN_0601ae80(void);
extern void FUN_0601ae80(void);
void FUN_0601AE80(void) { FUN_0601ae80(); }
extern void FUN_0600a1f6(void);
extern void FUN_0600a1f6(void);
void FUN_0600A1F6(void) { FUN_0600a1f6(); }
extern void FUN_0600338c(int, int);
extern void FUN_0600338c(int, int);
void FUN_0600338C(int r4, int r5) { FUN_0600338c(r4, r5); }
/* FUN_0601AEB6: moved to mode_dispatch.c */
extern void FUN_0601d2dc(void);
extern void FUN_0601d2dc(void);
void FUN_0601D2DC(void) { FUN_0601d2dc(); }
/* FUN_0601B074: moved to display_region_init.c */
/* FUN_06018FF8: moved to sound_init.c */
extern void FUN_0601d3c0(void);
extern void FUN_0601d3c0(void);
void FUN_0601D3C0(void) { FUN_0601d3c0(); }
extern void FUN_060193f4(void);
extern void FUN_060193f4(void);
void FUN_060193F4(void) { FUN_060193f4(); }
extern void FUN_060196a4(void);
extern void FUN_060196a4(void);
void FUN_060196A4(void) { FUN_060196a4(); }
extern void FUN_0601950c(void);
extern void FUN_0601950c(void);
void FUN_0601950C(void) { FUN_0601950c(); }
/* FUN_060198E0: moved to subsystem_setup.c */
extern void FUN_06019a48(void);
extern void FUN_06019a48(void);
void FUN_06019A48(void) { FUN_06019a48(); }
extern void FUN_0601b160(void);
extern void FUN_0601b160(void);
void FUN_0601B160(void) { FUN_0601b160(); }
extern int FUN_0601b418(void);
extern int FUN_0601b418(void);
int FUN_0601B418(void) { return FUN_0601b418(); }
extern void FUN_06018fa4(void);
extern void FUN_06018fa4(void);
void FUN_06018FA4(void) { FUN_06018fa4(); }
extern void FUN_0600ec78(void);
extern void FUN_0600ec78(void);
void FUN_0600EC78(void) { FUN_0600ec78(); }
extern void FUN_0600f424(void);
extern void FUN_0600f424(void);
void FUN_0600F424(void) { FUN_0600f424(); }

/* Physics helper stubs -- called by player_physics.c hand translations */
/* FUN_06008640: moved to force_system.c */
/* FUN_0600CD40: moved to lap_counting.c */
/* FUN_0600CA96: moved to course_correction.c */
/* FUN_0600CC38: moved to course_correction.c */
/* FUN_0600C8CC: moved to physics_helpers.c */
/* FUN_0600CF58: moved to collision_response.c */
/* FUN_0600C928: moved to physics_helpers.c */
/* FUN_0600C7D4: moved to physics_helpers.c */
/* FUN_06027358: moved to trig_tables.c */
extern void FUN_06027ede(int, int, int);
extern void FUN_06027ede(int, int, int);
void FUN_06027EDE(int r4, int r5, int r6) { FUN_06027ede(r4, r5, r6); }
/* FUN_06034F78: moved to bitfield_utils.c */
