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
extern int FUN_0601a80c();
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

void FUN_060185d8()
{

  char *puVar1;

  if (*(int *)0x06083254 == '\x03') {

    (*(int(*)())0x06026DBC)();

    (*(int(*)())0x06026E2E)(*(int *)0x06048140,*(int *)(0x06048140 + 4),

               *(int *)(0x06048140 + 8));

    (*(int(*)())0x06026EDE)((int)DAT_06018660);

    puVar1 = (char *)0x00200000;

    (*(int(*)())0x06031D8C)(0x00200000 + (int)0x000BABE0,0x178);

    (*(int(*)())0x06031A28)(puVar1 + (int)0x000BBD80,(int)*(short *)0x06089E98,

               (int)PTR_DAT_06018664);

    (*(int(*)())0x06026DF8)();

    return;

  }

  return;

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

void FUN_06018a3c()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  int iVar4;

  int iVar5;

  int uVar6;

  int local_30;

  char uStack_2c;

  char uStack_2b;

  int uStack_28;

  char uStack_24;

  char uStack_23;

  char uStack_20;

  puVar1 = (char *)0x0607EAD8;

  if (*(int *)0x06078868 < 10) {

    *(int *)0x0607867C = 0;

    *(int *)0x06083255 = 0;

  }

  else {

    if (*(int *)0x06078868 < 0xc) {

      *(int *)0x0607867C = 0;

    }

    else {

      *(int *)0x0607867C = 1;

    }

    *(int *)0x06083255 = 1;

  }

  if (*(int *)0x0605AD08 == 0) {

    (*(int(*)())0x0600736C)();

    (*(int(*)())0x06012DB4)(*(int *)puVar1);

    (*(int(*)())(*(int *)(0x0605D1BC + *(int *)((int)(int)puVar1 << 2))))();

    (*(int(*)())0x06012D7C)(*(int *)puVar1);

    if (*(int *)0x06078635 == '\0') {

      (*(int(*)())0x06012E7C)();

    }

    if (*(short *)0x0607ED8C == 0) {

      (*(int(*)())0x06018FF8)();

    }

  }

  if (*(short *)0x0607ED8C != 0) {

    (*(int(*)())0x06018FF8)();

  }

  if ((GAME_STATE_BIT & (int)DAT_06018b8e) == 0) {

    uVar6 = 0;

    iVar5 = 3;

  }

  else {

    if (*(int *)0x0605AB18 == '\0') {

      if (COURSE_SELECT == 2) {

        (*(int(*)())0x06018E1E)((unsigned char)*(int *)0x06078648 + 6);

        local_30 = 2;

        uStack_2c = 6;

        uStack_2b = 1;

        uStack_28 = 2;

        uStack_24 = 9;

        uStack_23 = 99;

        uStack_20 = 0x8f;

        (*(int(*)())0x06034D1C)(&local_30);

      }

      else {

        (*(int(*)())0x06018DDC)((unsigned char)*(int *)0x06078648 + 6,(unsigned char)*(int *)0x06078648 + 6,0xf);

      }

      goto LAB_06018bd8;

    }

    uVar6 = 0xf;

    iVar5 = (int)(char)((int *)0x0605D23C)[(unsigned char)*(int *)0x06078648];

  }

  (*(int(*)())0x06018DDC)(iVar5,iVar5,uVar6);

LAB_06018bd8:

  *(int *)0x0607EBE4 = 0;

  iVar4 = *(int *)((int)(int)puVar1 << 1);

  *(unsigned int *)0x0607EA9C = (unsigned int)*(unsigned short *)(0x0604806C + iVar4);

  *(char **)0x0607EB84 = 0x060D5840;

  *(char **)0x0607EB88 = 0x060C6000;

  *(char **)0x06063F3C = 0x0604800C + *(int *)((int)(int)puVar1 << 3);

  iVar5 = (*(int(*)())0x06035280)();

  *(int *)0x06063F18 = iVar5 + -1;

  *(int *)0x060786AC = 0;

  *(int *)0x06063F1C = 1;

  *(int *)0x06063F20 = 0;

  *(int *)0x06063F24 = 0;

  *(int *)0x06086034 = 0;

  puVar2 = (char *)0x06063F28;

  iVar5 = (int)(char)((char)COURSE_SELECT * '\x06');

  *(unsigned int *)0x06063F28 = (unsigned int)*(unsigned short *)(0x0604805A + iVar4 + iVar5);

  *(unsigned int *)0x0607EA98 = (unsigned int)*(unsigned short *)(0x06048072 + iVar4);

  *(unsigned int *)0x0607EAA0 = (unsigned int)*(unsigned short *)(0x06048024 + iVar4);

  puVar3 = (char *)0x0607EAAC;

  *(unsigned int *)0x0607EAAC = (unsigned int)*(unsigned short *)(0x0604802A + iVar4 + iVar5);

  *(unsigned int *)puVar3 =

       *(int *)puVar3 +

       (unsigned int)*(unsigned short *)

              (0x0604803C + iVar4 + (char)((char)*(int *)0x0605AD0C * '\x06')) *

       *(int *)puVar2;

  (*(int(*)())0x0602761E)(0x25C00220 + *(int *)(0x06059FFC << 3),0x0605CDDC,0xa0);

  (*(int(*)())0x060149E0)();

  (*(int(*)())0x060148FC)();

  (*(int(*)())0x06026CE0)();

  VBLANK_OUT_COUNTER = 0;

  (*(int(*)())0x0600A026)();

  *(int *)0x0605AD08 = 0;

  *(char **)0x0607E944 = 0x06078900;

  (*(int(*)())0x06010994)();

  (*(int(*)())0x060038D4)();

  (*(int(*)())0x060039C8)();

  (*(int(*)())(*(int *)(0x0605D1CC + *(int *)((int)(int)puVar1 << 2))))();

  (*(int(*)())0x060032D4)();

  (*(int(*)())0x06003430)();

  (*(int(*)())0x06014994)();

  (*(int(*)())0x06021128)();

  return;

}

int FUN_06018ddc(param_1, param_2, param_3)
    char param_1;
    char param_2;
    char param_3;
{

  int uVar1;

  int local_18;

  char uStack_14;

  char uStack_13;

  int uStack_10;

  char uStack_c;

  char uStack_b;

  char uStack_8;

  local_18 = 2;

  uStack_13 = 1;

  uStack_10 = 2;

  uStack_b = 99;

  uStack_14 = param_1;

  uStack_c = param_2;

  uStack_8 = param_3;

  uVar1 = (*(int(*)())0x06034D1C)(&local_18);

  return uVar1;

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

/* sound_channels_off -- Mute sound channels 1, 3, 2 via sound_cmd_dispatch.
 * Called during sound system shutdown/reset. */
extern void sound_cmd_dispatch(int channel, int command);

void FUN_060192ca(void)
{
    sound_cmd_dispatch(1, 0);
    sound_cmd_dispatch(3, 0);
    sound_cmd_dispatch(2, 0);
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

void FUN_060193f4()
{

  char *puVar1;

  char *puVar2;

  *(int *)0x06085FF0 = 0;

  *(int *)0x0605D245 = 0;

  *(int *)0x06085FF1 = 1;

  *(int *)0x06085FF2 = 0;

  *(int *)0x06085FF3 = 0;

  *(int *)0x06085FF5 = 0;

  (*(int(*)())0x0601D5F4)(0xf,0xAE0003FF);

  puVar2 = (char *)0x06026CE0;

  puVar1 = (char *)0x0605B6D8;

  INPUT_STATE = INPUT_STATE | 0x80000000;

  (*(int(*)())puVar2)();

  (*(int(*)())0x06026CE0)();

  FUN_0601938c();

  (*(int(*)())0x0601A73E)();

  (*(int(*)())0x0600511E)(0x25E76174,0x00014000,0,9);

  (*(int(*)())0x0600511E)(0x25E761FC,0x00017700,0,8);

  puVar2 = (char *)0x06014884;

  (*(int(*)())0x06014884)(8,0);

  (*(int(*)())puVar2)(0x10,0);

  (*(int(*)())puVar2)(0x20,0);

  (*(int(*)())0x0602853E)(4);

  (*(int(*)())0x0602853E)(0xc);

  puVar2 = (char *)0x06028560;

  *(unsigned int *)puVar1 = *(unsigned int *)puVar1 | 4;

  (*(int(*)())puVar2)();

  (*(int(*)())0x06028400)(4,*(int *)0x06063AF8,0,0x0000A000 + *(int *)(0x06063AF8 + 4),

             0x06063AF8);

  FUN_06019324();

  return;

}

unsigned int FUN_0601950c()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  char *puVar6;

  unsigned int uVar7;

  int *puVar8;

  char cVar9;

  puVar5 = (char *)0x06049AEC;

  puVar4 = (char *)0x0605D244;

  puVar3 = (char *)0x06063750;

  puVar2 = (char *)0x06028400;

  puVar1 = (char *)0x06049AF4;

  if (*(int *)0x06085FF1 != '\0') {

    (*(int(*)())0x06028400)(0xc,*(int *)(0x06063750 + DAT_060195ac),0x14,

               *(int *)((int)(0x06063750 + DAT_060195ac) + 4) + (int)DAT_060195ae);

    cVar9 = '\0';

    do {

      if (cVar9 != *puVar4) {

        puVar8 = (int *)(puVar3 + ((unsigned int)*(unsigned short *)(puVar1 + (cVar9 << 1)) << 3));

        (*(int(*)())puVar2)(0xc,*puVar8,

                          ((unsigned int)(unsigned char)(puVar5 + (cVar9 << 1))[1] * 0x40 +

                          (unsigned int)(unsigned char)puVar5[(cVar9 << 1)]) << 1,puVar8[1] + (int)PTR_DAT_060195b0

                         );

      }

      cVar9 = cVar9 + '\x01';

      *(int *)0x06085FF1 = 0;

    } while (cVar9 < '\x04');

  }

  puVar6 = (char *)0x0605D242;

  uVar7 = (unsigned int)(unsigned char)*(int *)0x06085FF5;

  if (uVar7 == 0) {

    if ((unsigned char)*(int *)0x0605D242 < 0x10) {

      puVar8 = (int *)(puVar3 + ((unsigned int)*(unsigned short *)(puVar1 + (char)(*puVar4 << 1)) << 3));

      uVar7 = (*(int(*)())puVar2)(0xc,*puVar8,

                                ((unsigned int)(unsigned char)(puVar5 + (char)(*puVar4 << 1))[1] * 0x40 +

                                (unsigned int)(unsigned char)puVar5[(char)(*puVar4 << 1)]) << 1,

                                puVar8[1] + (int)DAT_06019694);

    }

    else {

      (*(int(*)())0x060284AE)(0xc,((unsigned int)(unsigned char)(puVar5 + (char)(*puVar4 << 1))[1] * 0x40 +

                     (unsigned int)(unsigned char)puVar5[(char)(*puVar4 << 1)]) << 1,0x90,

                 *(int *)0x0605D4EC);

      uVar7 = (*(int(*)())0x060284AE)(0xc,(((unsigned char)(puVar5 + (char)(*puVar4 << 1))[1] + 2) << 6 +

                             (unsigned int)(unsigned char)puVar5[(char)(*puVar4 << 1)]) << 1,0x90,

                         *(int *)0x0605D4EC);

      if (0x1e < (unsigned char)*puVar6) {

        *puVar6 = 0;

      }

    }

  }

  return uVar7;

}

void FUN_060196a4()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  puVar3 = (char *)0x0605D244;

  puVar2 = (char *)0x0605D242;

  puVar1 = (char *)0x06085FF1;

  (*(int(*)())0x06026110)();

  if ((*(unsigned short *)(0x06063D98 + 2) & DAT_06019762) != 0) {

    (*(int(*)())0x06028400)(0xc,*(int *)

                    (0x06063750 + (unsigned int)*(unsigned short *)(0x06049AF4 + (char)(*puVar3 << 1)) << 3)

               ,((unsigned int)(unsigned char)((char *)(0x06049AEC + (char)(*puVar3 << 1)))[1] * 0x40 +

                (unsigned int)(unsigned char)((int *)0x06049AEC)[(char)(*puVar3 << 1)]) << 1,

               *(int *)((int)(0x06063750 +

                             (unsigned int)*(unsigned short *)(0x06049AF4 + (char)(*puVar3 << 1)) << 3) + 4) +

               (int)(short)PTR_DAT_06019764);

    if ('\x01' < (char)*puVar3) {

      *puVar3 = 0;

    }

    VBLANK_OUT_COUNTER = 0;

    *puVar2 = 0;

    GAME_STATE = 4;

    *puVar1 = 1;

    *(int *)0x06085FF5 = 1;

    return;

  }

  if ((*(unsigned short *)(0x06063D98 + 2) & PTR_DAT_06019764) == 0) {

    if ((*(unsigned short *)(0x06063D98 + 2) & DAT_06019864) != 0) {

      *puVar1 = 1;

      *puVar2 = 5;

      *puVar3 = *puVar3 + -1;

      if ((char)*puVar3 < '\0') {

        *puVar3 = 3;

      }

    }

  }

  else {

    *puVar1 = 1;

    *puVar2 = 5;

    *puVar3 = *puVar3 + '\x01';

    if ('\x03' < (char)*puVar3) {

      *puVar3 = 0;

    }

  }

  *(int *)0x0605D243 = *(int *)0x0605D243 + '\x01';

  *puVar2 = *puVar2 + '\x01';

  (*(int(*)())(*(int *)((char)(*puVar3 << 2) + 0x0605D250)))();

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
    FUN_0601a80c();                  /* display setup */
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

void FUN_06019a48()
{

  char *puVar1;

  char *puVar2;

  int iVar3;

  puVar2 = (char *)0x06085FF0;

  puVar1 = (char *)0x06085FF1;

  if (*(int *)0x06085FF3 == '\0') {

    iVar3 = 0x90;

    if (((unsigned int)*(unsigned short *)(0x06063D98 + 2) & iVar3 + 0x70U) == 0) {

      if ((*(unsigned short *)(0x06063D98 + 2) & PTR_DAT_06019b24) == 0) {

        if ((*(unsigned short *)(0x06063D98 + 2) & DAT_06019bfc) != 0) {

          (*(int(*)())0x060284AE)(0xc,((unsigned int)(unsigned char)((char *)(0x06049AFC + (char)*(int *)(0x06085FF0 << 1)))[1] * 0x40 +

                         (unsigned int)(unsigned char)((int *)0x06049AFC)[(char)*(int *)(0x06085FF0 << 1)]) << 1,iVar3,

                     *(int *)0x0605D4F0);

          *puVar2 = *puVar2 + -1;

          if ((char)*puVar2 < '\0') {

            *puVar2 = 7;

          }

          *puVar1 = 1;

        }

      }

      else {

        (*(int(*)())0x060284AE)(0xc,((unsigned int)(unsigned char)((char *)(0x06049AFC + (char)*(int *)(0x06085FF0 << 1)))[1] * 0x40 +

                       (unsigned int)(unsigned char)((int *)0x06049AFC)[(char)*(int *)(0x06085FF0 << 1)]) << 1,iVar3,

                   *(int *)0x0605D4F0);

        *puVar2 = *puVar2 + '\x01';

        if ('\a' < (char)*puVar2) {

          *puVar2 = 0;

        }

        *puVar1 = 1;

      }

    }

    else {

      (*(int(*)())0x060284AE)(0xc,((unsigned int)(unsigned char)((char *)(0x06049AFC + (char)*(int *)(0x06085FF0 << 1)))[1] * 0x40 +

                     (unsigned int)(unsigned char)((int *)0x06049AFC)[(char)*(int *)(0x06085FF0 << 1)]) << 1,iVar3,

                 *(int *)0x0605D4F0);

      if (*puVar2 == '\a') {

        GAME_STATE = 7;

      }

      else {

        *puVar2 = 7;

        *puVar1 = 1;

        VBLANK_OUT_COUNTER = 0;

        (*(int(*)())0x06026CE0)();

      }

    }

  }

  *(int *)0x0605D243 = *(int *)0x0605D243 + '\x01';

  *(int *)0x0605D242 = *(int *)0x0605D242 + '\x01';

  (*(int(*)())(*(int *)(0x0605D260 + (char)(*puVar2 << 2))))();

  return;

}

int FUN_06019bc8()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  int uVar4;

  int iVar5;

  unsigned char bVar6;

  puVar3 = (char *)0x06028400;

  puVar2 = (char *)0x06049B12;

  puVar1 = (char *)0x0605D242;

  if (*(int *)0x06085FF0 == '\0') {

    bVar6 = 0;

    do {

      if ((unsigned int)bVar6 == COURSE_SELECT) {

        if ((unsigned char)*puVar1 < 8) {

          iVar5 = 6;

        }

        else {

          iVar5 = 7;

          if (0x10 < (unsigned char)*puVar1) {

            *puVar1 = 0;

          }

        }

      }

      else {

        iVar5 = 3;

      }

      uVar4 = (*(int(*)())puVar3)(0xc,*(int *)

                                     (0x06063750 +

                                     (unsigned int)*(unsigned short *)(puVar2 + (unsigned int)(bVar6 << 1)) << 3),

                                ((unsigned int)(unsigned char)((char *)(0x06049B0C + (unsigned int)(bVar6 << 1)))[1] * 0x40 +

                                (unsigned int)(unsigned char)((int *)0x06049B0C)[(unsigned int)(bVar6 << 1)]) << 1,

                                (iVar5 << 12) +

                                *(int *)((int)(0x06063750 +

                                              (unsigned int)*(unsigned short *)(puVar2 + (unsigned int)(bVar6 << 1)) << 3) + 4))

      ;

      bVar6 = bVar6 + 1;

    } while (bVar6 < 3);

  }

  else {

    bVar6 = 0;

    do {

      if ((unsigned int)bVar6 == COURSE_SELECT) {

        iVar5 = 6;

      }

      else {

        iVar5 = 5;

      }

      uVar4 = (*(int(*)())puVar3)(0xc,*(int *)

                                     (0x06063750 +

                                     (unsigned int)*(unsigned short *)(puVar2 + (unsigned int)(bVar6 << 1)) << 3),

                                ((unsigned int)(unsigned char)((char *)(0x06049B0C + (unsigned int)(bVar6 << 1)))[1] * 0x40 +

                                (unsigned int)(unsigned char)((int *)0x06049B0C)[(unsigned int)(bVar6 << 1)]) << 1,

                                (iVar5 << 12) +

                                *(int *)((int)(0x06063750 +

                                              (unsigned int)*(unsigned short *)(puVar2 + (unsigned int)(bVar6 << 1)) << 3) + 4))

      ;

      bVar6 = bVar6 + 1;

    } while (bVar6 < 3);

  }

  return uVar4;

}

int FUN_06019db8()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  int uVar4;

  int iVar5;

  unsigned char bVar6;

  puVar3 = (char *)0x0605D242;

  puVar2 = (char *)0x06028400;

  puVar1 = (char *)0x06049B2C;

  if (*(int *)0x06085FF0 == '\x01') {

    bVar6 = 0;

    do {

      if ((unsigned int)bVar6 == *(unsigned int *)0x0605AD0C) {

        if ((unsigned char)*puVar3 < 8) {

          iVar5 = 6;

        }

        else {

          iVar5 = 7;

          if (0x10 < (unsigned char)*puVar3) {

            *puVar3 = 0;

          }

        }

      }

      else {

        iVar5 = 3;

      }

      uVar4 = (*(int(*)())puVar2)(0xc,*(int *)

                                     (0x06063750 +

                                     (unsigned int)*(unsigned short *)(puVar1 + (unsigned int)(bVar6 << 1)) << 3),

                                ((unsigned int)(unsigned char)((char *)(0x06049B18 + (unsigned int)(bVar6 << 1)))[1] * 0x40 +

                                (unsigned int)(unsigned char)((int *)0x06049B18)[(unsigned int)(bVar6 << 1)]) << 1,

                                (iVar5 << 12) +

                                *(int *)((int)(0x06063750 +

                                              (unsigned int)*(unsigned short *)(puVar1 + (unsigned int)(bVar6 << 1)) << 3) + 4))

      ;

      bVar6 = bVar6 + 1;

    } while (bVar6 < 5);

  }

  else {

    bVar6 = 0;

    do {

      if ((unsigned int)bVar6 == *(unsigned int *)0x0605AD0C) {

        iVar5 = 6;

      }

      else {

        iVar5 = 5;

      }

      uVar4 = (*(int(*)())puVar2)(0xc,*(int *)

                                     (0x06063750 +

                                     (unsigned int)*(unsigned short *)(puVar1 + (unsigned int)(bVar6 << 1)) << 3),

                                ((unsigned int)(unsigned char)((char *)(0x06049B18 + (unsigned int)(bVar6 << 1)))[1] * 0x40 +

                                (unsigned int)(unsigned char)((int *)0x06049B18)[(unsigned int)(bVar6 << 1)]) << 1,

                                (iVar5 << 12) +

                                *(int *)((int)(0x06063750 +

                                              (unsigned int)*(unsigned short *)(puVar1 + (unsigned int)(bVar6 << 1)) << 3) + 4))

      ;

      bVar6 = bVar6 + 1;

    } while (bVar6 < 5);

  }

  return uVar4;

}

int FUN_06019fb2()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  int uVar4;

  int iVar5;

  unsigned char bVar6;

  puVar3 = (char *)0x0605D242;

  puVar2 = (char *)0x06028400;

  puVar1 = (char *)0x06049B2C;

  if (*(int *)0x06085FF0 == '\x02') {

    bVar6 = 0;

    do {

      if ((unsigned int)bVar6 == *(unsigned int *)0x0605AD04) {

        if ((unsigned char)*puVar3 < 8) {

          iVar5 = 6;

        }

        else {

          iVar5 = 7;

          if (0x10 < (unsigned char)*puVar3) {

            *puVar3 = 0;

          }

        }

      }

      else {

        iVar5 = 3;

      }

      uVar4 = (*(int(*)())puVar2)(0xc,*(int *)

                                     (0x06063750 +

                                     (unsigned int)*(unsigned short *)(puVar1 + (unsigned int)(bVar6 << 1)) << 3),

                                ((unsigned int)(unsigned char)((char *)(0x06049B22 + (unsigned int)(bVar6 << 1)))[1] * 0x40 +

                                (unsigned int)(unsigned char)((int *)0x06049B22)[(unsigned int)(bVar6 << 1)]) << 1,

                                (iVar5 << 12) +

                                *(int *)((int)(0x06063750 +

                                              (unsigned int)*(unsigned short *)(puVar1 + (unsigned int)(bVar6 << 1)) << 3) + 4))

      ;

      bVar6 = bVar6 + 1;

    } while (bVar6 < 5);

  }

  else {

    bVar6 = 0;

    do {

      if ((unsigned int)bVar6 == *(unsigned int *)0x0605AD04) {

        iVar5 = 6;

      }

      else {

        iVar5 = 5;

      }

      uVar4 = (*(int(*)())puVar2)(0xc,*(int *)

                                     (0x06063750 +

                                     (unsigned int)*(unsigned short *)(puVar1 + (unsigned int)(bVar6 << 1)) << 3),

                                ((unsigned int)(unsigned char)((char *)(0x06049B22 + (unsigned int)(bVar6 << 1)))[1] * 0x40 +

                                (unsigned int)(unsigned char)((int *)0x06049B22)[(unsigned int)(bVar6 << 1)]) << 1,

                                (iVar5 << 12) +

                                *(int *)((int)(0x06063750 +

                                              (unsigned int)*(unsigned short *)(puVar1 + (unsigned int)(bVar6 << 1)) << 3) + 4))

      ;

      bVar6 = bVar6 + 1;

    } while (bVar6 < 5);

  }

  return uVar4;

}
