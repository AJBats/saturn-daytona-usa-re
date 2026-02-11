void smpc_intback_trigger(void) { }
void FUN_060389A6(void) __attribute__((alias("smpc_intback_trigger")));
void FUN_06020C3C(void) { }
/* cd_status_read / FUN_06018EAC: moved to cd_command.c */
void scu_interrupt_reconfig(void) { }
void FUN_06009FFC(void) __attribute__((alias("scu_interrupt_reconfig")));
void cd_frame_sync_advance(void) { }
void FUN_06012B58(void) __attribute__((alias("cd_frame_sync_advance")));
void FUN_0600A1B8(void) { }
void FUN_060072E6(void) { }
void FUN_06007370(void) { }
void FUN_0600747C(void) { }
void FUN_06007CEC(void) { }
void FUN_06007D8E(void) { }
void FUN_06007E08(void) { }

void FUN_060033E6(void) { }
void FUN_060053AC(int r4, int r5, int r6) { (void)r4; (void)r5; (void)r6; }
void FUN_060055BC(void) { }
void perspective_project(void) __attribute__((alias("FUN_060055BC")));
void FUN_060078DC(void) { }
void frame_end_display_commit(void) __attribute__((alias("FUN_060078DC")));
void FUN_0600A084(void) { }
/* FUN_0600A0C0: moved to vdp_state_init.c */
void FUN_0600A33C(void) { }
/* FUN_0600A914: moved to collision.c */
void FUN_0600BB94(void) { }
void multi_mode_camera(void) __attribute__((alias("FUN_0600BB94")));
void FUN_0600BFFC(void) { }
void hud_racing_state_init(void) __attribute__((alias("FUN_0600BFFC")));
/* FUN_0600C302: moved to car_iteration.c */
/* FUN_0600DE54: moved to car_iteration.c */
/* FUN_0600DE70: moved to car_iteration.c */
/* FUN_0600EB14: moved to race_init.c */
void FUN_06010A5C(int arg) { (void)arg; }
void FUN_060120C8(void) { }
void FUN_060121A8(void) { }
void FUN_06018A3C(void) { }
/* FUN_06018E70: moved to cd_command.c */
void FUN_060192CA(void) { }
void FUN_0601D5F4(int r4, int r5) { (void)r4; (void)r5; }
void sound_cmd_dispatch(int r4, int r5) __attribute__((alias("FUN_0601D5F4")));
void FUN_0601D9B0(void) { }
void FUN_0601DBB8(void) { }
void replay_camera_controller(void) __attribute__((alias("FUN_0601DBB8")));
void FUN_0601DE50(void) { }
void FUN_0601E100(void) { }
void FUN_0601F784(void) { }
void FUN_060268B0(int arg) { (void)arg; }
void FUN_06026CE0(void) { }
void FUN_060283E0(int r4, int r5, int r6, int r7) { (void)r4; (void)r5; (void)r6; (void)r7; }
void FUN_0602EFF0(void) { }
void rendering_pass1_camera(void) __attribute__((alias("FUN_0602EFF0")));
void FUN_0602F0E8(void) { }
void perspective_projection_3d(void) __attribute__((alias("FUN_0602F0E8")));
void FUN_0602F7EA(void) { }
void sprite_transform(void) __attribute__((alias("FUN_0602F7EA")));
void FUN_060302C6(void) { }
void engine_sound_generator(void) __attribute__((alias("FUN_060302C6")));
void FUN_060321C0(void) { }
void FUN_06033AAC(void) { }
void FUN_06033BC8(void) { }
void FUN_06034900(void) { }

void FUN_060284AE(int r4, int r5, int r6, int r7) { (void)r4; (void)r5; (void)r6; (void)r7; }
void FUN_0602834A(int r4, int r5, int r6, int r7) { (void)r4; (void)r5; (void)r6; (void)r7; }
void FUN_06018DDC(int arg) { (void)arg; }
void FUN_06014A04(void) { }
/* FUN_0600DF66: moved to car_iteration.c */
void FUN_0601DF88(void) { }
void FUN_0602853E(int arg) { (void)arg; }
void FUN_06014884(int r4, int r5, int r6) { (void)r4; (void)r5; (void)r6; }
/* FUN_060032D4: moved to vdp_sprite_init.c */
void FUN_0600A294(void) { }
/* FUN_0601FD74: moved to mode_dispatch.c */
/* FUN_0600DE40: moved to car_iteration.c */
void FUN_06033EA8(void) { }
void FUN_06014A74(void) { }
void FUN_06014D2C(void) { }
void FUN_060190B8(void) { }
void FUN_06012F80(void) { }
void FUN_0601389E(void) { }
/* FUN_0600DFD0: moved to visual_physics_update.c */
void FUN_0600C218(void) { }
/* FUN_0600E060: moved to visual_physics_update.c */
int FUN_0601F8C0(void) { return 0; }
int FUN_0601F900(void) { return 0; }
void FUN_060149E0(void) { }

void FUN_0601C978(void) { }
void FUN_0601CAEE(void) { }
void FUN_0600A140(void) { }
void FUN_0600330A(void) { }
void FUN_0601AE80(void) { }
void FUN_0600A1F6(void) { }
void FUN_0600338C(int r4, int r5) { (void)r4; (void)r5; }
void FUN_0601AEB6(void) { }
void FUN_0601D2DC(void) { }
/* FUN_0601B074: moved to display_region_init.c */
void FUN_06018FF8(void) { }
void FUN_0601D3C0(void) { }
void FUN_060193F4(void) { }
void FUN_060196A4(void) { }
void FUN_0601950C(void) { }
void FUN_060198E0(void) { }
void FUN_06019A48(void) { }
void FUN_0601B160(void) { }
int  FUN_0601B418(void) { return 0; }
void FUN_06018FA4(void) { }
void FUN_0600EC78(void) { }
void FUN_0600F424(void) { }

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
void FUN_06027EDE(int r4, int r5, int r6) { (void)r4; (void)r5; (void)r6; }
/* FUN_06034F78: moved to bitfield_utils.c */
