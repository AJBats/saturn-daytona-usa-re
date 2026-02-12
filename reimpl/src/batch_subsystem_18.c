#include "game.h"

extern int DAT_06018212;
extern int DAT_06018214;
extern int DAT_06018216;
extern int DAT_06018218;
extern int DAT_0601821a;
extern int DAT_060182f2;
extern int DAT_060183ec;
extern int DAT_060183ee;
extern int DAT_060183f0;
extern int DAT_060183f2;
extern int DAT_06018504;
extern int DAT_06018506;
extern int DAT_060185a0;
extern int DAT_060185a2;
extern int DAT_06018660;
extern int DAT_06018662;
extern int DAT_06018b8e;
extern int DAT_06018cc6;
extern int DAT_060193c4;
extern int DAT_060193c6;
extern int DAT_060195ac;
extern int DAT_060195ae;
extern int DAT_06019694;
extern int DAT_06019696;
extern int DAT_06019762;
extern int DAT_06019864;
extern int DAT_06019b22;
extern int DAT_06019bfc;
extern void FUN_06018320();
extern void FUN_060185d8();
extern void FUN_060192e8();
extern void FUN_06019324();
extern void FUN_0601938c();
extern void FUN_06019928();
extern int FUN_06019bc8();
extern int FUN_06019db8();
extern int FUN_06019fb2();
extern int FUN_0601a65e();
extern void course_select_display_update();
extern int cd_register_double_read();
extern int FUN_06034DEA();
extern int PTR_DAT_060185a4;
extern int PTR_DAT_06018664;
extern int PTR_DAT_060195b0;
extern int PTR_DAT_06019764;
extern int PTR_DAT_06019a24;
extern int PTR_DAT_06019b24;
extern short PTR_DAT_060182f4;

/* hud_position_ticker -- Animate HUD position/lap indicator sprites.
 * Increments frame counter at 0x0605BE2C. For first 6 frames, slides
 * two sprite slots (position/lap) by +0x90 each tick. After 6 frames,
 * snaps to final positions and resets counter.
 * On final lap: uses sprite set at 0x06089E28, otherwise 0x06089E2C.
 * Dispatches to start_banner_state or FUN_060185d8 based on GAME_STATE_BIT. */
void FUN_06018166()
{
  int is_final_lap;
  int sprite_value;
  int slot_a_off = (int)DAT_06018212;
  int slot_b_off = (int)DAT_06018216;
  int car = CAR_PTR_TARGET;
  char *sprite_table = (char *)0x060684EC;    /* HUD sprite index table */
  char *vdp_slots = (char *)0x06063F64;       /* VDP1 sprite slot array */
  short *frame_counter = (short *)0x0605BE2C;
  *frame_counter = *frame_counter + 1;
  is_final_lap = *(unsigned int *)(car + DAT_06018214) < *(int *)0x06063F28 - 1U;
  if (is_final_lap) {
    sprite_value = *(int *)0x06089E28;  /* final lap sprite */
  } else {
    sprite_value = *(int *)0x06089E2C;  /* normal lap sprite */
  }
  if (*frame_counter < 6) {
    /* slide-in animation: add 0x90 per frame */
    *(int *)(vdp_slots + ((unsigned int)*(unsigned short *)(sprite_table + slot_a_off) << 3)) =
         *(int *)(vdp_slots + ((unsigned int)*(unsigned short *)(sprite_table + slot_a_off) << 3)) + 0x90;
    *(int *)(vdp_slots + ((unsigned int)*(unsigned short *)(sprite_table + slot_b_off) << 3)) =
         *(int *)(vdp_slots + ((unsigned int)*(unsigned short *)(sprite_table + slot_b_off) << 3)) + 0x90;
  } else {
    /* snap to final position, reset counter */
    *(int *)(vdp_slots + ((unsigned int)*(unsigned short *)(sprite_table + slot_a_off) << 3)) = sprite_value;
    *(int *)(vdp_slots + ((unsigned int)*(unsigned short *)(sprite_table + slot_b_off) << 3)) =
         *(int *)0x06089E30;
    *frame_counter = 0;
  }
  if (is_final_lap) {
    *(short *)(vdp_slots + ((unsigned int)*(unsigned short *)(sprite_table + slot_a_off) << 3) + 6) = DAT_060182f2;
  } else {
    *(short *)(vdp_slots + ((unsigned int)*(unsigned short *)(sprite_table + slot_a_off) << 3) + 6) = DAT_0601821a;
  }
  if ((GAME_STATE_BIT & (unsigned int)0x00800000) != 0) {
    FUN_060185d8();
    return;
  }
  FUN_06018320();
  return;
}

unsigned int track_calculation()
{
  unsigned int uVar3;
  unsigned short *puVar4;
  unsigned int uVar5;

  uVar3 = (unsigned int)*(unsigned short *)0x0605BE1C;
  uVar5 = (unsigned int)*(unsigned short *)0x06063D9A;

  if ((uVar3 == 0) && (uVar5 != 0)) {
    puVar4 = (unsigned short *)0x0605BE1E;

    uVar3 = (*(int(*)())0x06035280)();

    if ((uVar3 & uVar5) == 0) {
      *puVar4 = 0;
      uVar3 = 0;
    }
    else {
      *puVar4 = *puVar4 + 1;
      uVar3 = (unsigned int)*puVar4;

      if (uVar3 == 7) {
        int idx;
        *puVar4 = 0;
        *(short *)0x0605BE1C = 1;

        idx = (unsigned int)*(unsigned short *)0x06069BB6 << 3;
        *(int *)(0x06063F64 + idx) = *(int *)0x06089E3C;
        uVar3 = (unsigned int)PTR_DAT_060182f4;
        *(short *)(0x06063F64 + idx + 6) = PTR_DAT_060182f4;
      }
    }
  }

  return uVar3;
}

/* start_banner_state -- START banner scaling/display state machine.
 * Checks if player car is in start zone (position between DAT_060183ee..DAT_060183f0).
 * When in zone: detects button press (bit 0x40 toggle), manages 6-state
 * animation sequence controlling scale_x (puVar6+0) and scale_y (puVar6+4)
 * with thresholds 0x8000, 0x10000, 0x18000, 0x20000.
 * Then renders banner via primary matrix pipeline + mesh/texture.
 * When outside zone: resets all state to zero. */
void FUN_06018320()
{
  char anim_phase;
  unsigned short btn_raw, btn_edge;
  int scale_step;
  char *in_zone_flag = (char *)0x0605BE33;
  char *prev_zone = (char *)0x0605BE34;
  char *scale_data = (char *)0x06085FC0;  /* scale_x at +0, scale_y at +4 */
  char *anim_state = (char *)0x0605BE32;
  char *car_ptr_base = (char *)0x0607E940;
  char *display_flag = (char *)0x0605BE35;
  *(int *)0x0605BE34 = *(int *)0x0605BE33;
  if (((int)DAT_060183ee <= *(int *)(*(int *)car_ptr_base + (int)DAT_060183ec)) &&
     (*(int *)(*(int *)car_ptr_base + (int)DAT_060183ec) <= (int)DAT_060183f0)) {
    /* player car is in start zone */
    *in_zone_flag = 1;
    btn_raw = *(unsigned short *)0x06063D98 & 0x40;   /* controller input */
    btn_edge = (*(unsigned short *)0x0605BE30 ^ btn_raw) & btn_raw;
    *(unsigned short *)0x0605BE30 = btn_raw;
    if (*(int *)0x0605DE3C == '\0') {
      if ((((*(unsigned char *)(*(int *)car_ptr_base + 3) & 8) == 0 & (*in_zone_flag ^ *prev_zone)) != 0) &&
         ((*(unsigned int *)0x0605A010 & 0x3f) == 0)) {
        *display_flag = 1;
      }
    } else {
      *display_flag = 1;
    }
    if (*(int *)0x06085FF4 == '\0') {
      /* normal mode: 3-state scale animation */
      if ((*(int *)(*(int *)car_ptr_base + 8) == 0) && (btn_edge != 0)) {
        scale_step = (int)DAT_060183f2;
        if (*anim_state == '\0') {
          /* state 0: grow scale_y until 0x10000 */
          *(int *)scale_data = 0;
          scale_step = *(int *)(scale_data + 4) + scale_step;
          *(int *)(scale_data + 4) = scale_step;
          if ((int)0x00010000 <= scale_step) {
            *(int *)scale_data = 0x00008000;
            *(int *)(scale_data + 4) = 0x00008000;
            *anim_state = *anim_state + '\x01';
          }
        } else if (*anim_state == '\x01') {
          /* state 1: grow scale_y until 0x18000 */
          *(int *)scale_data = 0x00008000;
          scale_step = *(int *)(scale_data + 4) + scale_step;
          *(int *)(scale_data + 4) = scale_step;
          if ((int)0x00018000 <= scale_step) {
            *(int *)scale_data = 0;
            *(int *)(scale_data + 4) = 0;
            *anim_state = *anim_state + '\x01';
          }
        } else {
          /* state 2+: hold at zero */
          *(int *)scale_data = 0;
          *(int *)(scale_data + 4) = 0;
        }
      }
    } else {
      /* alternate mode: 6-state scale animation */
      anim_phase = *anim_state;
      if (anim_phase == '\0') {
        *(int *)scale_data = 0;
        *(int *)(scale_data + 4) = 0;
        if ((*(int *)(*(int *)car_ptr_base + 8) == 0) && (btn_edge != 0)) {
          *anim_state = *anim_state + '\x01';
        }
      } else if (anim_phase == '\x01') {
        /* grow scale_y by 0x100 until 0x10000 */
        scale_step = *(int *)(scale_data + 4) + 0x100;
        *(int *)(scale_data + 4) = scale_step;
        if ((int)0x00010000 <= scale_step) {
          *(int *)(scale_data + 4) = 0x00010000;
          *anim_state = *anim_state + '\x01';
        }
      } else if (anim_phase == '\x02') {
        /* grow scale_x by 0x200 until 0x8000 */
        scale_step = *(int *)scale_data + 0x200;
        *(int *)scale_data = scale_step;
        if ((int)0x00008000 <= scale_step) {
          *(int *)scale_data = 0x00008000;
          *anim_state = *anim_state + '\x01';
        }
      } else if (anim_phase == '\x03') {
        /* grow scale_y by 0x100 until 0x20000 */
        scale_step = *(int *)(scale_data + 4) + 0x100;
        *(int *)(scale_data + 4) = scale_step;
        if ((int)0x00020000 <= scale_step) {
          *(int *)(scale_data + 4) = 0x00020000;
          *anim_state = *anim_state + '\x01';
        }
      } else if (anim_phase == '\x04') {
        /* grow scale_x by 0x200 until 0x10000 then reset */
        scale_step = *(int *)scale_data + 0x200;
        *(int *)scale_data = scale_step;
        if ((int)0x00010000 <= scale_step) {
          *(int *)scale_data = 0;
          *anim_state = *anim_state + '\x01';
        }
      } else {
        /* state 5+: hold at zero */
        *(int *)scale_data = 0;
        *(int *)(scale_data + 4) = 0;
      }
    }
    if (*display_flag != '\0') {
      *(int *)scale_data = 0x00008000;
      *(int *)(scale_data + 4) = 0x00008000;
    }
    /* render banner via primary matrix pipeline */
    (*(int(*)())0x06026DBC)();                          /* matrix_push */
    (*(int(*)())0x06026E2E)(*(int *)0x06048140, *(int *)(0x06048140 + 4),
               *(int *)(0x06048140 + 8));               /* matrix_translate */
    (*(int(*)())0x06026EDE)(*(int *)(scale_data + 4) + (int)DAT_060185a0);  /* matrix_scale_y */
    (*(int(*)())0x06026E94)(*(int *)scale_data);        /* matrix_scale_x */
    (*(int(*)())0x06031D8C)(0x00200000 + (int)0x000BABE0, 0x178);  /* mesh_submit */
    (*(int(*)())0x06031A28)((char *)0x00200000 + (int)0x000BBD80,
               (int)*(short *)0x06089E98, (int)PTR_DAT_060185a4);  /* texture_submit */
    (*(int(*)())0x06026DF8)();                          /* matrix_pop */
    return;
  }
  /* outside start zone: reset all state */
  *(int *)scale_data = 0;
  *(int *)(scale_data + 4) = 0;
  *in_zone_flag = 0;
  *display_flag = 0;
  *anim_state = 0;
  return;
}

/* scene_object_render_state3 -- Render scene overlay object in game state 3.
 * Guards on state flag (0x06083254 == 3). Pushes matrix, sets position from
 * table at 0x06048140, applies rotation (DAT_06018660), renders texture
 * from ROM offsets 0x002BABE0 (tiles) and 0x002BBD80 (palette), pops matrix. */
void FUN_060185d8(void)
{
    if (*(int *)0x06083254 == '\x03') {
        (*(int(*)())0x06026DBC)();  /* matrix_push */
        (*(int(*)())0x06026E2E)(*(int *)0x06048140, *(int *)(0x06048140 + 4),
                   *(int *)(0x06048140 + 8));  /* set_position */
        (*(int(*)())0x06026EDE)((int)DAT_06018660);  /* set_rotation */
        (*(int(*)())0x06031D8C)(0x00200000 + (int)0x000BABE0, 0x178);  /* texture_select */
        (*(int(*)())0x06031A28)((char *)0x00200000 + (int)0x000BBD80,
                   (int)*(short *)0x06089E98, (int)PTR_DAT_06018664);  /* palette_draw */
        (*(int(*)())0x06026DF8)();  /* matrix_pop */
    }
}

/* hud_state_reset -- Reset course-specific HUD state registers.
 * Dispatches on CAR_COUNT (course index 0/1/2):
 *   Course 0: clears 8 registers at 0x0605BE20..0x0605BE38
 *   Course 1: clears 4 registers at 0x0605BE1C..0x0605BE38
 *   Course 2: clears 2 registers at 0x0605BE36..0x0605BE38
 * Returns CAR_COUNT (or 0 for course 0). */
int FUN_06018634()
{
  int course = CAR_COUNT;
  if (course == 0) {
    *(short *)0x0605BE24 = 0;
    *(short *)0x0605BE22 = 0;
    *(short *)0x0605BE20 = 0;
    *(short *)0x0605BE2A = 0;
    *(short *)0x0605BE26 = 0;
    *(short *)0x0605BE28 = 0;
    *(short *)0x0605BE36 = 0;
    *(short *)0x0605BE38 = 0;
    return 0;
  }
  if (course == 1) {
    *(short *)0x0605BE1C = 0;
    *(short *)0x0605BE1E = 0;
    course = 0;
    *(short *)0x0605BE36 = 0;
  } else {
    if (course != 2) {
      return course;
    }
    *(short *)0x0605BE36 = 0;
    course = 2;
  }
  *(short *)0x0605BE38 = 0;
  return course;
}

/* race_scene_init -- initialize racing scene with course geometry, textures, and subsystems */
void FUN_06018a3c()
{
  char *track_index_ptr;
  char *segment_count_ptr;
  char *total_segments_ptr;
  int table_offset;
  int course_offset;
  int palette_mask;
  int cd_cmd_buf;
  char cd_cmd_type;
  char cd_cmd_flag;
  int cd_subcmd;
  char cd_timeout_lo;
  char cd_timeout_hi;
  char cd_end_marker;

  track_index_ptr = (char *)0x0607EAD8; /* current track index */

  /* Set track complexity flags based on track index */
  if (*(int *)0x06078868 < 10) {
    *(int *)0x0607867C = 0; /* extra_geometry_flag */
    *(int *)0x06083255 = 0; /* extended_track_flag */
  }
  else {
    if (*(int *)0x06078868 < 0xc) {
      *(int *)0x0607867C = 0;
    }
    else {
      *(int *)0x0607867C = 1; /* enable extra geometry for tracks >= 12 */
    }
    *(int *)0x06083255 = 1; /* enable extended track for tracks >= 10 */
  }

  /* Run rendering subsystem chain if not in skip mode */
  if (*(int *)0x0605AD08 == 0) {
    (*(int(*)())0x0600736C)();        /* car_array_init */
    (*(int(*)())0x06012DB4)(*(int *)track_index_ptr); /* track_geometry_load */
    (*(int(*)())(*(int *)(0x0605D1BC + *(int *)((int)(int)track_index_ptr << 2))))(); /* track_type_dispatch */
    (*(int(*)())0x06012D7C)(*(int *)track_index_ptr); /* track_collision_load */
    if (*(int *)0x06078635 == '\0') {
      (*(int(*)())0x06012E7C)();      /* scenery_object_load */
    }
    if (*(short *)0x0607ED8C == 0) {
      (*(int(*)())0x06018FF8)();      /* music_init */
    }
  }

  if (*(short *)0x0607ED8C != 0) {
    (*(int(*)())0x06018FF8)();        /* music_init (force if flag set) */
  }

  /* Course-specific palette/texture setup */
  if ((GAME_STATE_BIT & (int)DAT_06018b8e) == 0) {
    palette_mask = 0;
    course_offset = 3;
  }
  else {
    if (*(int *)0x0605AB18 == '\0') {
      if (COURSE_SELECT == 2) {
        /* Course 2 (expert): build CD command for special asset load */
        (*(int(*)())0x06018E1E)((unsigned char)*(int *)0x06078648 + 6);
        cd_cmd_buf = 2;
        cd_cmd_type = 6;
        cd_cmd_flag = 1;
        cd_subcmd = 2;
        cd_timeout_lo = 9;
        cd_timeout_hi = 99;
        cd_end_marker = 0x8f;
        (*(int(*)())0x06034D1C)(&cd_cmd_buf); /* cd_command_dispatch */
      }
      else {
        (*(int(*)())0x06018DDC)((unsigned char)*(int *)0x06078648 + 6,(unsigned char)*(int *)0x06078648 + 6,0xf);
      }
      goto LAB_06018bd8;
    }
    palette_mask = 0xf;
    course_offset = (int)(char)((int *)0x0605D23C)[(unsigned char)*(int *)0x06078648];
  }

  (*(int(*)())0x06018DDC)(course_offset,course_offset,palette_mask);

LAB_06018bd8:
  *(int *)0x0607EBE4 = 0;
  table_offset = *(int *)((int)(int)track_index_ptr << 1);

  /* Load track geometry parameters from ROM tables at 0x0604800C */
  *(unsigned int *)0x0607EA9C = (unsigned int)*(unsigned short *)(0x0604806C + table_offset); /* polygon_count */
  *(char **)0x0607EB84 = 0x060D5840; /* texture_base_a */
  *(char **)0x0607EB88 = 0x060C6000; /* texture_base_b */
  *(char **)0x06063F3C = 0x0604800C + *(int *)((int)(int)track_index_ptr << 3); /* track_segment_table */

  course_offset = (*(int(*)())0x06035280)(); /* cd_get_track_segment_count */
  *(int *)0x06063F18 = course_offset + -1; /* max_segment_index */
  *(int *)0x060786AC = 0;   /* render_segment_start */
  *(int *)0x06063F1C = 1;   /* render_direction */
  *(int *)0x06063F20 = 0;   /* render_wrap_flag */
  *(int *)0x06063F24 = 0;   /* render_lod_bias */
  *(int *)0x06086034 = 0;   /* scenery_counter */

  segment_count_ptr = (char *)0x06063F28;
  course_offset = (int)(char)((char)COURSE_SELECT * '\x06'); /* course * 6 table stride */
  *(unsigned int *)0x06063F28 = (unsigned int)*(unsigned short *)(0x0604805A + table_offset + course_offset); /* road_segment_count */
  *(unsigned int *)0x0607EA98 = (unsigned int)*(unsigned short *)(0x06048072 + table_offset); /* track_width */
  *(unsigned int *)0x0607EAA0 = (unsigned int)*(unsigned short *)(0x06048024 + table_offset); /* track_height */

  total_segments_ptr = (char *)0x0607EAAC;
  *(unsigned int *)0x0607EAAC = (unsigned int)*(unsigned short *)(0x0604802A + table_offset + course_offset); /* total_road_polygons */
  *(unsigned int *)total_segments_ptr =
       *(int *)total_segments_ptr +
       (unsigned int)*(unsigned short *)
              (0x0604803C + table_offset + (char)((char)*(int *)0x0605AD0C * '\x06')) *
       *(int *)segment_count_ptr;

  /* DMA copy VDP1 command table */
  (*(int(*)())0x0602761E)(0x25C00220 + *(int *)(0x06059FFC << 3),0x0605CDDC,0xa0);

  /* Initialize rendering subsystems */
  (*(int(*)())0x060149E0)(); /* vdp1_sprite_table_init */
  (*(int(*)())0x060148FC)(); /* vdp1_palette_init */
  (*(int(*)())0x06026CE0)(); /* matrix_pipeline_init */
  VBLANK_OUT_COUNTER = 0;

  /* Initialize game subsystems */
  (*(int(*)())0x0600A026)(); /* car_physics_init */
  *(int *)0x0605AD08 = 0;   /* clear skip flag */
  *(char **)0x0607E944 = 0x06078900; /* car_array_base = 0x06078900 */

  (*(int(*)())0x06010994)(); /* selection_screen_init */
  (*(int(*)())0x060038D4)(); /* input_init */
  (*(int(*)())0x060039C8)(); /* timer_init */
  (*(int(*)())(*(int *)(0x0605D1CC + *(int *)((int)(int)track_index_ptr << 2))))(); /* course_specific_init */
  (*(int(*)())0x060032D4)(); /* hud_init */
  (*(int(*)())0x06003430)(); /* camera_init */
  (*(int(*)())0x06014994)(); /* collision_map_init */
  (*(int(*)())0x06021128)(); /* track_sprite_init */

  return;
}

/* cd_command_build_type2 -- Build and send a CD command type 2 buffer.
 * Constructs a command buffer on stack with fixed fields (cmd=2, flag=1,
 * subcmd=2, timeout=99) and caller-supplied parameters. Dispatches
 * via CD command handler at 0x06034D1C. */
int FUN_06018ddc(param_1, param_2, param_3)
    char param_1;
    char param_2;
    char param_3;
{
    int result;
    int cmd_buf[2];     /* 8-byte command buffer on stack */
    char cmd_params[8]; /* parameter bytes */

    /* Build command buffer */
    cmd_buf[0] = 2;            /* command type */
    ((char *)cmd_buf)[5] = 1;  /* flag byte */
    cmd_buf[1] = 2;            /* sub-command */
    cmd_params[1] = 99;        /* timeout */
    ((char *)cmd_buf)[4] = param_1;  /* user param 1 */
    cmd_params[0] = param_2;         /* user param 2 */
    cmd_params[4] = param_3;         /* user param 3 */

    result = (*(int(*)())0x06034D1C)(cmd_buf);  /* cd_command_dispatch */
    return result;
}

/* cd_command_send_type2 -- Send CD command type 2 with parameter.
 * Builds a 3-word command buffer: {cmd=2, flag=1, param=param_1}
 * and dispatches via CD command handler at 0x06034DEA. */
int FUN_06018e1e(char param_1)
{
    int buf[2];
    char *bytes = (char *)buf;

    buf[0] = 2;       /* command type */
    bytes[5] = 1;     /* flag byte */
    bytes[4] = param_1; /* parameter */

    return (*(int(*)())0x06034DEA)(buf);
}

int
FUN_06018e70()
{
    int buf[2];
    buf[0] = 3;
    return FUN_06034DEA(buf);
}

int
FUN_06018eac()
{
    char buf[16];
    cd_register_double_read(buf);
    return buf[0] & 0x1f;
}

/* scsp_load_driver_a -- Load sound driver bank A into SCSP RAM.
 * Sends stop+init commands to sound channel 0xF, waits for SCSP ready,
 * calls loader at 0x06012EDC, clears SCSP register, re-sends stop. */
void FUN_06018fa4(void)
{
    void (*snd_cmd)(int, int) = (void (*)(int, int))0x0601D5F4;

    SOUND_TIMEOUT_FLAG = 0;
    snd_cmd(0xf, 0xAE0001FF);   /* stop */
    snd_cmd(0xf, 0xAE0005FF);   /* init */
    FUN_060192e8();              /* busy-wait timeout */

    if (SOUND_TIMEOUT_FLAG == 0) {
        (*(int(*)())0x06012EDC)();
        *(short *)0x25A02DBE = 0;  /* clear SCSP control */
    }
    snd_cmd(0xf, 0xAE0001FF);   /* stop */
}

/* scsp_load_driver_b -- Load sound driver bank B into SCSP RAM.
 * Same pattern as _a but calls loader at 0x06012EBC and sends
 * master volume command (0xAE0600FF) before final stop. */
void FUN_06018ff8(void)
{
    void (*snd_cmd)(int, int) = (void (*)(int, int))0x0601D5F4;

    SOUND_TIMEOUT_FLAG = 0;
    snd_cmd(0xf, 0xAE0001FF);
    snd_cmd(0xf, 0xAE0005FF);
    FUN_060192e8();

    if (SOUND_TIMEOUT_FLAG == 0) {
        (*(int(*)())0x06012EBC)();
        *(short *)0x25A02DBE = 0;
    }
    snd_cmd(0xf, 0xAE0600FF);   /* master volume */
    snd_cmd(0xf, 0xAE0001FF);   /* stop */
}

/* scsp_load_driver_c -- Load sound driver bank C into SCSP RAM.
 * Calls loader at 0x06012F10, sends stop then master volume after. */
/* scsp_load_driver_c -- Load sound driver bank C into SCSP RAM.
 * Stops sound channel 0xF, waits for busy timeout via FUN_060192e8,
 * calls loader at 0x06012F10, clears SCSP register, restores volume. */
void FUN_06019058(void)
{
    void (*snd_cmd)(int, int) = (void (*)(int, int))0x0601D5F4;

    SOUND_TIMEOUT_FLAG = 0;
    snd_cmd(0xf, 0xAE0001FF);   /* stop */
    snd_cmd(0xf, 0xAE0005FF);   /* init */
    FUN_060192e8();              /* wait for sound CPU ready */

    if (SOUND_TIMEOUT_FLAG == 0) {
        (*(int(*)())0x06012F10)();       /* load bank C data */
        *(short *)0x25A02DBE = 0;        /* clear SCSP status */
    }
    snd_cmd(0xf, 0xAE0001FF);   /* stop */
    snd_cmd(0xf, 0xAE0600FF);   /* master volume restore */
}

/* scsp_load_driver_d -- Load sound driver bank D into SCSP RAM.
 * Calls loader at 0x06012F20. */
void FUN_060190b8(void)
{
    void (*snd_cmd)(int, int) = (void (*)(int, int))0x0601D5F4;

    SOUND_TIMEOUT_FLAG = 0;
    snd_cmd(0xf, 0xAE0001FF);
    snd_cmd(0xf, 0xAE0005FF);
    FUN_060192e8();

    if (SOUND_TIMEOUT_FLAG == 0) {
        (*(int(*)())0x06012F20)();
        *(short *)0x25A02DBE = 0;
    }
    snd_cmd(0xf, 0xAE0001FF);
}

/* scsp_load_driver_e -- Load sound driver bank E into SCSP RAM.
 * Calls loader at 0x06012F50. */
void FUN_060190f4(void)
{
    void (*snd_cmd)(int, int) = (void (*)(int, int))0x0601D5F4;

    SOUND_TIMEOUT_FLAG = 0;
    snd_cmd(0xf, 0xAE0001FF);
    snd_cmd(0xf, 0xAE0005FF);
    FUN_060192e8();

    if (SOUND_TIMEOUT_FLAG == 0) {
        (*(int(*)())0x06012F50)();
        *(short *)0x25A02DBE = 0;
    }
    snd_cmd(0xf, 0xAE0001FF);
}

/* scsp_load_driver_f -- Load sound driver bank F into SCSP RAM.
 * Calls loader at 0x06012F58. */
void FUN_0601914c(void)
{
    void (*snd_cmd)(int, int) = (void (*)(int, int))0x0601D5F4;

    SOUND_TIMEOUT_FLAG = 0;
    snd_cmd(0xf, 0xAE0001FF);
    snd_cmd(0xf, 0xAE0005FF);
    FUN_060192e8();

    if (SOUND_TIMEOUT_FLAG == 0) {
        (*(int(*)())0x06012F58)();
        *(short *)0x25A02DBE = 0;
    }
    snd_cmd(0xf, 0xAE0001FF);
}

/* scsp_load_driver_g -- Load sound driver bank G into SCSP RAM.
 * Calls loader at 0x06012F60. */
void FUN_06019188(void)
{
    void (*snd_cmd)(int, int) = (void (*)(int, int))0x0601D5F4;

    SOUND_TIMEOUT_FLAG = 0;
    snd_cmd(0xf, 0xAE0001FF);
    snd_cmd(0xf, 0xAE0005FF);
    FUN_060192e8();

    if (SOUND_TIMEOUT_FLAG == 0) {
        (*(int(*)())0x06012F60)();
        *(short *)0x25A02DBE = 0;
    }
    snd_cmd(0xf, 0xAE0001FF);
}

/* scsp_dma_load -- Load sound data via DMA into SCSP RAM at 0x25A03000.
 * Source: 0x00200000, size: 0x0006D000 (445KB). */
void FUN_060191e0(void)
{
    void (*snd_cmd)(int, int) = (void (*)(int, int))0x0601D5F4;

    SOUND_TIMEOUT_FLAG = 0;
    snd_cmd(0xf, 0xAE0001FF);
    snd_cmd(0xf, 0xAE0005FF);
    FUN_060192e8();

    if (SOUND_TIMEOUT_FLAG == 0) {
        (*(int(*)())0x0602760C)(0x25A03000, 0x00200000, 0x0006D000);
        *(short *)0x25A02DBE = 0;
    }
    snd_cmd(0xf, 0xAE0001FF);
}

/* scsp_dma_load_alt -- Load alternate sound data via DMA into SCSP RAM.
 * Source: 0x0026D000, size: 0x0006D000 (445KB). Same dest as scsp_dma_load. */
void FUN_06019248(void)
{
    void (*snd_cmd)(int, int) = (void (*)(int, int))0x0601D5F4;

    SOUND_TIMEOUT_FLAG = 0;
    snd_cmd(0xf, 0xAE0001FF);
    snd_cmd(0xf, 0xAE0005FF);
    FUN_060192e8();

    if (SOUND_TIMEOUT_FLAG == 0) {
        (*(int(*)())0x0602760C)(0x25A03000, 0x0026D000, 0x0006D000);
        *(short *)0x25A02DBE = 0;
    }
    snd_cmd(0xf, 0xAE0001FF);
}

/* scsp_ram_clear -- Zero all 512KB of SCSP work RAM (0x25A00000-0x25A7FFFF).
 * This is the Saturn's 68000 sound CPU work RAM area. */
void FUN_060192b4(void)
{
    char *cnt = (char *)0x0007FFFF;
    char *dest = (char *)0x25A00000;

    do {
        cnt--;
        *dest = 0;
        dest++;
    } while (cnt != (char *)0x0);
}

/* sound_channels_stop -- Stop sound channels 1-3.
 * Sends stop command (data=0) to channels 1, 3, 2.
 * Lighter version of sound_channels_reset (no SCSP slot writes).
 * Called during race state transitions (states 15, 16). */
extern void sound_cmd_dispatch(int channel, int command);

void sound_channels_stop(void)
{
    sound_cmd_dispatch(1, 0);  /* stop channel 1 */
    sound_cmd_dispatch(3, 0);  /* stop channel 3 */
    sound_cmd_dispatch(2, 0);  /* stop channel 2 */
}

/* sound_mailbox_timeout -- Busy-wait ~100k iterations then set timeout flag.
 * Called when SCSP sound mailbox doesn't respond in time. */
void FUN_060192e8(void)
{
    register unsigned int cnt asm("r1") = 100000;
    do {
        cnt--;
    } while (cnt != 0);
    SOUND_TIMEOUT_FLAG = 1;
}

/* peripheral_config_setup -- Configure peripheral interrupt priorities.
 * Calls SCU interrupt config function at 0x06038BD4 with (mask, priority) pairs.
 * Sets bit 30 of INPUT_STATE to signal peripheral system ready. */
void FUN_06019324(void)
{
    register void (*scu_int_config)() = (void (*)())0x06038BD4;

    scu_int_config(0x100, 1);  /* timer 0: priority 1 */
    scu_int_config(4);         /* VBlank-IN: default */
    scu_int_config(8, 5);      /* VBlank-OUT: priority 5 */
    scu_int_config(0x10, 6);   /* HBlank-IN: priority 6 */
    scu_int_config(0x20, 7);   /* timer 1: priority 7 */
    scu_int_config(1, 0);      /* level 0 DMA: priority 0 */

    INPUT_STATE = INPUT_STATE | 0x40000000;
}

/* sound_vdp2_scroll_setup -- DMA-copy 5 scroll plane data blocks to VDP2 VRAM.
 * Loads sound system visualization data (waveform/spectrum display).
 *   0x25F00540: color data (0x20 bytes)
 *   0x25F00000: pattern names (0x20 bytes)
 *   0x25F00600: cell data (0x20 bytes)
 *   0x25F00620: animation cells (0xE0 bytes)
 *   0x25F00780: palette data (0x80 bytes) */
void FUN_0601938c(void)
{
    register int dma_copy asm("r3") = 0x0602761E;
    (*(int(*)())dma_copy)(0x25F00540, 0x0605CE9C, 0x20);
    (*(int(*)())dma_copy)(0x25F00000, 0x0605CD9C, 0x20);
    (*(int(*)())dma_copy)(0x25F00600, 0x0605CF9C, 0x20);
    (*(int(*)())dma_copy)(0x25F00620, 0x0605CEBC, 0xE0);
    (*(int(*)())dma_copy)(0x25F00780, 0x06049DC4, 0x80);
}

/* scene_state_init_flush -- Reset state flags, flush render pipeline, load VDP2 scroll data. */
void FUN_060193f4()
{
  char *render_flags;
  char *scu_int_clear;
  /* Clear scene state flags */
  *(int *)0x06085FF0 = 0;
  *(int *)0x0605D245 = 0;
  *(int *)0x06085FF1 = 1;
  *(int *)0x06085FF2 = 0;
  *(int *)0x06085FF3 = 0;
  *(int *)0x06085FF5 = 0;
  /* Sound command: stop/reset */
  (*(int(*)())0x0601D5F4)(0xf,0xAE0003FF);
  scu_int_clear = (char *)0x06026CE0;
  render_flags = (char *)0x0605B6D8;
  INPUT_STATE = INPUT_STATE | 0x80000000;  /* disable input processing */
  /* Flush render pipeline (twice) */
  (*(int(*)())scu_int_clear)();
  (*(int(*)())0x06026CE0)();
  /* DMA copy VDP register blocks */
  FUN_0601938c();
  (*(int(*)())0x0601A73E)();
  /* Load VDP2 scroll plane data */
  (*(int(*)())0x0600511E)(0x25E76174,0x00014000,0,9);   /* scroll plane A */
  (*(int(*)())0x0600511E)(0x25E761FC,0x00017700,0,8);   /* scroll plane B */
  /* Clear SCU interrupt masks */
  scu_int_clear = (char *)0x06014884;
  (*(int(*)())0x06014884)(8,0);
  (*(int(*)())scu_int_clear)(0x10,0);
  (*(int(*)())scu_int_clear)(0x20,0);
  /* VDP1 command list setup */
  (*(int(*)())0x0602853E)(4);
  (*(int(*)())0x0602853E)(0xc);
  scu_int_clear = (char *)0x06028560;
  *(unsigned int *)render_flags = *(unsigned int *)render_flags | 4;  /* enable render flag */
  (*(int(*)())scu_int_clear)();  /* flush VDP1 commands */
  /* Render initial scene object */
  (*(int(*)())0x06028400)(4,*(int *)0x06063AF8,0,0x0000A000 + *(int *)(0x06063AF8 + 4),
             0x06063AF8);
  FUN_06019324();
  return;
}

/* scene_selection_render -- Render 4 selectable menu items with blinking highlight.
 * Draws unselected items normally, selected item blinks when anim counter >= 0x10. */
unsigned int FUN_0601950c()
{
  char *sprite_dims;
  char *selection_idx;
  char *obj_table;
  char *vdp_render;
  char *sprite_ids;
  char *anim_counter;
  unsigned int result;
  int *obj_entry;
  char item;
  sprite_dims = (char *)0x06049AEC;
  selection_idx = (char *)0x0605D244;
  obj_table = (char *)0x06063750;
  vdp_render = (char *)0x06028400;
  sprite_ids = (char *)0x06049AF4;
  if (*(int *)0x06085FF1 != '\0') {
    /* Render background/frame object */
    (*(int(*)())0x06028400)(0xc,*(int *)(0x06063750 + DAT_060195ac),0x14,
               *(int *)((int)(0x06063750 + DAT_060195ac) + 4) + (int)DAT_060195ae);
    /* Render 4 items, skip currently selected one */
    item = '\0';
    do {
      if (item != *selection_idx) {
        obj_entry = (int *)(obj_table + ((unsigned int)*(unsigned short *)(sprite_ids + (item << 1)) << 3));
        (*(int(*)())vdp_render)(0xc,*obj_entry,
                          ((unsigned int)(unsigned char)(sprite_dims + (item << 1))[1] * 0x40 +
                          (unsigned int)(unsigned char)sprite_dims[(item << 1)]) << 1,obj_entry[1] + (int)PTR_DAT_060195b0
                         );
      }
      item = item + '\x01';
      *(int *)0x06085FF1 = 0;   /* clear dirty flag */
    } while (item < '\x04');
  }
  /* Render selected item with blink effect */
  anim_counter = (char *)0x0605D242;
  result = (unsigned int)(unsigned char)*(int *)0x06085FF5;
  if (result == 0) {
    if ((unsigned char)*(int *)0x0605D242 < 0x10) {
      /* Normal render of selected item */
      obj_entry = (int *)(obj_table + ((unsigned int)*(unsigned short *)(sprite_ids + (char)(*selection_idx << 1)) << 3));
      result = (*(int(*)())vdp_render)(0xc,*obj_entry,
                                ((unsigned int)(unsigned char)(sprite_dims + (char)(*selection_idx << 1))[1] * 0x40 +
                                (unsigned int)(unsigned char)sprite_dims[(char)(*selection_idx << 1)]) << 1,
                                obj_entry[1] + (int)DAT_06019694);
    }
    else {
      /* Blink phase: render as split sprite pair */
      (*(int(*)())0x060284AE)(0xc,((unsigned int)(unsigned char)(sprite_dims + (char)(*selection_idx << 1))[1] * 0x40 +
                     (unsigned int)(unsigned char)sprite_dims[(char)(*selection_idx << 1)]) << 1,0x90,
                 *(int *)0x0605D4EC);
      result = (*(int(*)())0x060284AE)(0xc,(((unsigned char)(sprite_dims + (char)(*selection_idx << 1))[1] + 2) << 6 +
                             (unsigned int)(unsigned char)sprite_dims[(char)(*selection_idx << 1)]) << 1,0x90,
                         *(int *)0x0605D4EC);
      if (0x1e < (unsigned char)*anim_counter) {
        *anim_counter = 0;           /* reset blink cycle */
      }
    }
  }
  return result;
}

/* scene_selection_input -- Handle input for 4-option selection menu.
 * Start/Accept confirms, Left/Right cycles through options 0-3,
 * dispatches to per-option handler via jump table at 0x0605D250. */
void FUN_060196a4()
{
  char *dirty_flag;
  char *anim_counter;
  char *selection_idx;
  selection_idx = (char *)0x0605D244;
  anim_counter = (char *)0x0605D242;
  dirty_flag = (char *)0x06085FF1;
  (*(int(*)())0x06026110)();    /* poll input */
  /* Start/Accept button pressed */
  if ((*(unsigned short *)(0x06063D98 + 2) & DAT_06019762) != 0) {
    /* Render confirmed selection */
    (*(int(*)())0x06028400)(0xc,*(int *)
                    (0x06063750 + (unsigned int)*(unsigned short *)(0x06049AF4 + (char)(*selection_idx << 1)) << 3)
               ,((unsigned int)(unsigned char)((char *)(0x06049AEC + (char)(*selection_idx << 1)))[1] * 0x40 +
                (unsigned int)(unsigned char)((int *)0x06049AEC)[(char)(*selection_idx << 1)]) << 1,
               *(int *)((int)(0x06063750 +
                             (unsigned int)*(unsigned short *)(0x06049AF4 + (char)(*selection_idx << 1)) << 3) + 4) +
               (int)(short)PTR_DAT_06019764);
    if ('\x01' < (char)*selection_idx) {
      *selection_idx = 0;       /* clamp to valid range */
    }
    VBLANK_OUT_COUNTER = 0;
    *anim_counter = 0;
    GAME_STATE = 4;             /* transition to next state */
    *dirty_flag = 1;
    *(int *)0x06085FF5 = 1;
    return;
  }
  /* Right/Down button: increment selection */
  if ((*(unsigned short *)(0x06063D98 + 2) & PTR_DAT_06019764) == 0) {
    /* Left/Up button: decrement selection */
    if ((*(unsigned short *)(0x06063D98 + 2) & DAT_06019864) != 0) {
      *dirty_flag = 1;
      *anim_counter = 5;
      *selection_idx = *selection_idx + -1;
      if ((char)*selection_idx < '\0') {
        *selection_idx = 3;     /* wrap to last option */
      }
    }
  }
  else {
    *dirty_flag = 1;
    *anim_counter = 5;
    *selection_idx = *selection_idx + '\x01';
    if ('\x03' < (char)*selection_idx) {
      *selection_idx = 0;       /* wrap to first option */
    }
  }
  /* Advance frame and animation counters */
  *(int *)0x0605D243 = *(int *)0x0605D243 + '\x01';
  *anim_counter = *anim_counter + '\x01';
  /* Dispatch to per-option handler */
  (*(int(*)())(*(int *)((char)(*selection_idx << 2) + 0x0605D250)))();
  return;
}

/* subsystem_setup_init -- Initialize sound/display subsystem for game mode.
 * Configures VDP sprite slot (0xC), resets VDP sprite system,
 * sets sound subsystem flags (active=1, channel=1, volume=0xFF),
 * then runs subsystem data init, display setup, and cursor init. */
void FUN_060198e0(void)
{
    (*(int(*)())0x0602853E)(0xC);    /* VDP sprite slot config */
    (*(int(*)())0x06028560)();       /* VDP sprite system reset */
    *(int *)0x06085FF1 = 1;          /* sound subsystem active */
    *(int *)0x06085FF6 = 1;          /* sound channel active */
    *(int *)0x06085FF7 = 0xFF;       /* volume = max */
    FUN_06019928();                  /* subsystem data init */
    course_select_display_update();  /* display setup */
    (*(int(*)())0x0601A940)();       /* cursor/selection init */
}

/* sound_test_render -- Render sound test channel display when dirty flag set.
 * When 0x06085FF1 == 1: renders 8 channel indicator sprites via VDP1
 * command dispatcher (0x060284AE). Highlights selected channel at
 * 0x06085FF0 with priority 0xC. Calls 4 sub-renderers for additional
 * display elements (FUN_06019bc8..FUN_0601a65e). Clears dirty flag. */
void FUN_06019928()
{
  char *vdp_cmd = (char *)0x060284AE;      /* VDP1 command dispatcher */
  char *tile_map = (char *)0x06049AFC;      /* tile coordinate LUT */
  char *sprite_table = (char *)0x0605D294;  /* sprite descriptor table */
  unsigned char ch;
  char *selection = (char *)0x06085FF0;     /* current channel selection index */
  if (*(int *)0x06085FF1 == '\x01') {
    INPUT_STATE = INPUT_STATE | 4;
    /* render 8 channel indicators (normal priority 8) */
    ch = 0;
    do {
      (*(int(*)())vdp_cmd)(8,
          ((unsigned int)(unsigned char)(tile_map + (unsigned int)(ch << 1))[1] * 0x40 +
           (unsigned int)(unsigned char)tile_map[(unsigned int)(ch << 1)]) << 1,
          0x90, *(int *)(sprite_table + (unsigned int)(ch << 2)));
      ch = ch + 1;
    } while (ch < 8);
    /* highlight selected channel (priority 0xC) */
    (*(int(*)())vdp_cmd)(0xc,
        ((unsigned int)(unsigned char)(tile_map + (char)*(int *)(0x06085FF0 << 1))[1] * 0x40 +
         (unsigned int)(unsigned char)tile_map[(char)*(int *)(0x06085FF0 << 1)]) << 1,
        0x90, *(int *)(sprite_table + (char)*(int *)(0x06085FF0 << 2)));
    /* highlight selected channel label */
    (*(int(*)())vdp_cmd)(0xc,
        ((unsigned int)(unsigned char)tile_map[(char)(*selection << 1) + 1] * 0x40 + 1) << 1,
        0x90, 0x06049E44);
    /* render channel 6 extra indicator if not selected */
    if (*selection != '\x06') {
      (*(int(*)())vdp_cmd)(0xc,
          ((unsigned int)(unsigned char)tile_map[0xd] * 0x40 +
           (unsigned int)(unsigned char)tile_map[0xc] + 0xd) << 1,
          0x90, *(int *)0x0605D4F0, tile_map);
    }
    FUN_06019bc8();   /* volume display render */
    FUN_06019db8();   /* frequency display render */
    FUN_06019fb2();   /* waveform display render */
    FUN_0601a65e();   /* envelope display render */
    *(int *)0x06085FF1 = 0;  /* clear dirty flag */
  }
  return;
}

/* options_menu_input -- Handle input for 8-option settings/sound-test menu.
 * Start/Accept confirms (transitions to state 7 or selects option 7),
 * Right/Left cycles through options 0-7, dispatches via jump table at 0x0605D260. */
void FUN_06019a48()
{
  char *dirty_flag;
  char *selection_idx;
  int sprite_size;
  selection_idx = (char *)0x06085FF0;
  dirty_flag = (char *)0x06085FF1;
  if (*(int *)0x06085FF3 == '\0') {
    sprite_size = 0x90;
    /* Start/Accept button */
    if (((unsigned int)*(unsigned short *)(0x06063D98 + 2) & sprite_size + 0x70U) == 0) {
      /* Right/Down button */
      if ((*(unsigned short *)(0x06063D98 + 2) & PTR_DAT_06019b24) == 0) {
        /* Left/Up button */
        if ((*(unsigned short *)(0x06063D98 + 2) & DAT_06019bfc) != 0) {
          (*(int(*)())0x060284AE)(0xc,((unsigned int)(unsigned char)((char *)(0x06049AFC + (char)*(int *)(0x06085FF0 << 1)))[1] * 0x40 +
                         (unsigned int)(unsigned char)((int *)0x06049AFC)[(char)*(int *)(0x06085FF0 << 1)]) << 1,sprite_size,
                     *(int *)0x0605D4F0);
          *selection_idx = *selection_idx + -1;
          if ((char)*selection_idx < '\0') {
            *selection_idx = 7;   /* wrap to last option */
          }
          *dirty_flag = 1;
        }
      }
      else {
        (*(int(*)())0x060284AE)(0xc,((unsigned int)(unsigned char)((char *)(0x06049AFC + (char)*(int *)(0x06085FF0 << 1)))[1] * 0x40 +
                       (unsigned int)(unsigned char)((int *)0x06049AFC)[(char)*(int *)(0x06085FF0 << 1)]) << 1,sprite_size,
                   *(int *)0x0605D4F0);
        *selection_idx = *selection_idx + '\x01';
        if ('\a' < (char)*selection_idx) {
          *selection_idx = 0;     /* wrap to first option */
        }
        *dirty_flag = 1;
      }
    }
    else {
      /* Start/Accept: confirm selection */
      (*(int(*)())0x060284AE)(0xc,((unsigned int)(unsigned char)((char *)(0x06049AFC + (char)*(int *)(0x06085FF0 << 1)))[1] * 0x40 +
                     (unsigned int)(unsigned char)((int *)0x06049AFC)[(char)*(int *)(0x06085FF0 << 1)]) << 1,sprite_size,
                 *(int *)0x0605D4F0);
      if (*selection_idx == '\a') {
        GAME_STATE = 7;           /* exit to state 7 */
      }
      else {
        *selection_idx = 7;
        *dirty_flag = 1;
        VBLANK_OUT_COUNTER = 0;
        (*(int(*)())0x06026CE0)();  /* flush render */
      }
    }
  }
  /* Advance frame and animation counters */
  *(int *)0x0605D243 = *(int *)0x0605D243 + '\x01';
  *(int *)0x0605D242 = *(int *)0x0605D242 + '\x01';
  /* Dispatch to per-option handler */
  (*(int(*)())(*(int *)(0x0605D260 + (char)(*selection_idx << 2))))();
  return;
}

/* volume_display_render -- Render 3 volume level indicators with highlight/blink.
 * Active item (matching COURSE_SELECT) blinks when anim counter >= 8,
 * priority: 3=dim, 5=inactive, 6=selected, 7=blink. */
int FUN_06019bc8()
{
  char *anim_counter;
  char *sprite_ids;
  char *vdp_render;
  int result;
  int priority;
  unsigned char item;
  vdp_render = (char *)0x06028400;
  sprite_ids = (char *)0x06049B12;
  anim_counter = (char *)0x0605D242;
  if (*(int *)0x06085FF0 == '\0') {
    /* Active selection on this row — blink selected item */
    item = 0;
    do {
      if ((unsigned int)item == COURSE_SELECT) {
        if ((unsigned char)*anim_counter < 8) {
          priority = 6;                /* highlight */
        }
        else {
          priority = 7;               /* blink phase */
          if (0x10 < (unsigned char)*anim_counter) {
            *anim_counter = 0;        /* reset blink cycle */
          }
        }
      }
      else {
        priority = 3;                  /* dim unselected */
      }
      result = (*(int(*)())vdp_render)(0xc,*(int *)
                                     (0x06063750 +
                                     (unsigned int)*(unsigned short *)(sprite_ids + (unsigned int)(item << 1)) << 3),
                                ((unsigned int)(unsigned char)((char *)(0x06049B0C + (unsigned int)(item << 1)))[1] * 0x40 +
                                (unsigned int)(unsigned char)((int *)0x06049B0C)[(unsigned int)(item << 1)]) << 1,
                                (priority << 12) +
                                *(int *)((int)(0x06063750 +
                                              (unsigned int)*(unsigned short *)(sprite_ids + (unsigned int)(item << 1)) << 3) + 4))
      ;
      item = item + 1;
    } while (item < 3);
  }
  else {
    /* Inactive row — static display */
    item = 0;
    do {
      if ((unsigned int)item == COURSE_SELECT) {
        priority = 6;                  /* selected */
      }
      else {
        priority = 5;                  /* inactive */
      }
      result = (*(int(*)())vdp_render)(0xc,*(int *)
                                     (0x06063750 +
                                     (unsigned int)*(unsigned short *)(sprite_ids + (unsigned int)(item << 1)) << 3),
                                ((unsigned int)(unsigned char)((char *)(0x06049B0C + (unsigned int)(item << 1)))[1] * 0x40 +
                                (unsigned int)(unsigned char)((int *)0x06049B0C)[(unsigned int)(item << 1)]) << 1,
                                (priority << 12) +
                                *(int *)((int)(0x06063750 +
                                              (unsigned int)*(unsigned short *)(sprite_ids + (unsigned int)(item << 1)) << 3) + 4))
      ;
      item = item + 1;
    } while (item < 3);
  }
  return result;
}

/* frequency_display_render -- Render 5 frequency/mode indicators with highlight/blink.
 * Active item (matching selection at 0x0605AD0C) blinks when anim counter >= 8,
 * priority: 3=dim, 5=inactive, 6=selected, 7=blink. */
int FUN_06019db8()
{
  char *sprite_ids;
  char *vdp_render;
  char *anim_counter;
  int result;
  int priority;
  unsigned char item;
  anim_counter = (char *)0x0605D242;
  vdp_render = (char *)0x06028400;
  sprite_ids = (char *)0x06049B2C;
  if (*(int *)0x06085FF0 == '\x01') {
    /* Active selection on this row — blink selected item */
    item = 0;
    do {
      if ((unsigned int)item == *(unsigned int *)0x0605AD0C) {
        if ((unsigned char)*anim_counter < 8) {
          priority = 6;                /* highlight */
        }
        else {
          priority = 7;               /* blink phase */
          if (0x10 < (unsigned char)*anim_counter) {
            *anim_counter = 0;        /* reset blink cycle */
          }
        }
      }
      else {
        priority = 3;                  /* dim unselected */
      }
      result = (*(int(*)())vdp_render)(0xc,*(int *)
                                     (0x06063750 +
                                     (unsigned int)*(unsigned short *)(sprite_ids + (unsigned int)(item << 1)) << 3),
                                ((unsigned int)(unsigned char)((char *)(0x06049B18 + (unsigned int)(item << 1)))[1] * 0x40 +
                                (unsigned int)(unsigned char)((int *)0x06049B18)[(unsigned int)(item << 1)]) << 1,
                                (priority << 12) +
                                *(int *)((int)(0x06063750 +
                                              (unsigned int)*(unsigned short *)(sprite_ids + (unsigned int)(item << 1)) << 3) + 4))
      ;
      item = item + 1;
    } while (item < 5);
  }
  else {
    /* Inactive row — static display */
    item = 0;
    do {
      if ((unsigned int)item == *(unsigned int *)0x0605AD0C) {
        priority = 6;                  /* selected */
      }
      else {
        priority = 5;                  /* inactive */
      }
      result = (*(int(*)())vdp_render)(0xc,*(int *)
                                     (0x06063750 +
                                     (unsigned int)*(unsigned short *)(sprite_ids + (unsigned int)(item << 1)) << 3),
                                ((unsigned int)(unsigned char)((char *)(0x06049B18 + (unsigned int)(item << 1)))[1] * 0x40 +
                                (unsigned int)(unsigned char)((int *)0x06049B18)[(unsigned int)(item << 1)]) << 1,
                                (priority << 12) +
                                *(int *)((int)(0x06063750 +
                                              (unsigned int)*(unsigned short *)(sprite_ids + (unsigned int)(item << 1)) << 3) + 4))
      ;
      item = item + 1;
    } while (item < 5);
  }
  return result;
}

/* waveform_display_render -- Render 5 waveform/balance indicators with highlight/blink.
 * Active when selection row == 2. Compares against selection at 0x0605AD04,
 * priority: 3=dim, 5=inactive, 6=selected, 7=blink. */
int FUN_06019fb2()
{
  char *sprite_ids;
  char *vdp_render;
  char *anim_counter;
  int result;
  int priority;
  unsigned char item;
  anim_counter = (char *)0x0605D242;
  vdp_render = (char *)0x06028400;
  sprite_ids = (char *)0x06049B2C;
  if (*(int *)0x06085FF0 == '\x02') {
    /* Active selection on this row — blink selected item */
    item = 0;
    do {
      if ((unsigned int)item == *(unsigned int *)0x0605AD04) {
        if ((unsigned char)*anim_counter < 8) {
          priority = 6;                /* highlight */
        }
        else {
          priority = 7;               /* blink phase */
          if (0x10 < (unsigned char)*anim_counter) {
            *anim_counter = 0;        /* reset blink cycle */
          }
        }
      }
      else {
        priority = 3;                  /* dim unselected */
      }
      result = (*(int(*)())vdp_render)(0xc,*(int *)
                                     (0x06063750 +
                                     (unsigned int)*(unsigned short *)(sprite_ids + (unsigned int)(item << 1)) << 3),
                                ((unsigned int)(unsigned char)((char *)(0x06049B22 + (unsigned int)(item << 1)))[1] * 0x40 +
                                (unsigned int)(unsigned char)((int *)0x06049B22)[(unsigned int)(item << 1)]) << 1,
                                (priority << 12) +
                                *(int *)((int)(0x06063750 +
                                              (unsigned int)*(unsigned short *)(sprite_ids + (unsigned int)(item << 1)) << 3) + 4))
      ;
      item = item + 1;
    } while (item < 5);
  }
  else {
    /* Inactive row — static display */
    item = 0;
    do {
      if ((unsigned int)item == *(unsigned int *)0x0605AD04) {
        priority = 6;                  /* selected */
      }
      else {
        priority = 5;                  /* inactive */
      }
      result = (*(int(*)())vdp_render)(0xc,*(int *)
                                     (0x06063750 +
                                     (unsigned int)*(unsigned short *)(sprite_ids + (unsigned int)(item << 1)) << 3),
                                ((unsigned int)(unsigned char)((char *)(0x06049B22 + (unsigned int)(item << 1)))[1] * 0x40 +
                                (unsigned int)(unsigned char)((int *)0x06049B22)[(unsigned int)(item << 1)]) << 1,
                                (priority << 12) +
                                *(int *)((int)(0x06063750 +
                                              (unsigned int)*(unsigned short *)(sprite_ids + (unsigned int)(item << 1)) << 3) + 4))
      ;
      item = item + 1;
    } while (item < 5);
  }
  return result;
}
