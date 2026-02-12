#include "game.h"

extern int DAT_0601207a;
extern int DAT_0601214e;
extern int DAT_06012218;
extern int DAT_0601221a;
extern int DAT_0601221c;
extern int DAT_0601221e;
extern int DAT_060126a2;
extern int DAT_060126a4;
extern int DAT_06012884;
extern int DAT_06012886;
extern int DAT_06012888;
extern int DAT_0601288a;
extern int DAT_0601288c;
extern int DAT_0601288e;
extern int DAT_06012890;
extern int DAT_0601299a;
extern int DAT_0601299c;
extern int DAT_0601299e;
extern int DAT_060129a0;
extern int DAT_060129a2;
extern int DAT_060129a4;
extern int DAT_060129a6;
extern int DAT_06012a92;
extern int DAT_06012a94;
extern int DAT_06012a96;
extern int DAT_06012a98;
extern int DAT_06012a9a;
extern int DAT_06012a9c;
extern int DAT_06012a9e;
extern int DAT_06012aa0;
extern int DAT_06012c66;
extern int DAT_06013050;
extern int DAT_06013052;
extern int DAT_06013054;
extern int DAT_06013056;
extern int DAT_06013058;
extern int DAT_0601305a;
extern int DAT_0601305c;
extern int DAT_0601305e;
extern int DAT_06013060;
extern int DAT_06013062;
extern int DAT_06013064;
extern int DAT_06013066;
extern int DAT_06013068;
extern int DAT_060131b4;
extern int DAT_060131b6;
extern int DAT_060131b8;
extern int DAT_060131ba;
extern int DAT_060131bc;
extern int DAT_060131be;
extern int DAT_060131c0;
extern int DAT_060131c2;
extern int DAT_060131c4;
extern int DAT_060131c6;
extern int DAT_060131c8;
extern int DAT_060131ca;
extern int DAT_060131cc;
extern int DAT_060131ce;
extern int DAT_060131d0;
extern int DAT_060131d2;
extern int DAT_060131d4;
extern int DAT_060131d6;
extern int DAT_060131d8;
extern int DAT_060131da;
extern int DAT_060131dc;
extern int DAT_060131de;
extern int DAT_060131e0;
extern int DAT_060131e2;
extern int DAT_060131e4;
extern int DAT_060131e6;
extern int DAT_060131e8;
extern int DAT_060131ea;
extern int DAT_060131ec;
extern int DAT_060131ee;
extern int DAT_060131f0;
extern int DAT_060131f2;
extern int DAT_060131f4;
extern int DAT_060131f6;
extern int DAT_060131f8;
extern int DAT_060132f2;
extern int DAT_060132f4;
extern int DAT_060132f6;
extern int DAT_060132f8;
extern int DAT_060132fa;
extern int DAT_060132fc;
extern int DAT_060132fe;
extern int DAT_06013300;
extern int DAT_06013302;
extern int DAT_06013304;
extern int DAT_06013306;
extern int DAT_06013308;
extern int DAT_0601330a;
extern int DAT_0601330c;
extern int DAT_0601330e;
extern int DAT_06013310;
extern int DAT_06013312;
extern int DAT_06013314;
extern int DAT_06013316;
extern int DAT_06013318;
extern int DAT_0601331a;
extern int DAT_0601331c;
extern int DAT_0601331e;
extern int DAT_06013320;
extern int DAT_06013322;
extern int DAT_06013324;
extern int DAT_06013326;
extern int DAT_06013328;
extern int DAT_0601332a;
extern int DAT_0601332c;
extern int DAT_0601332e;
extern int DAT_06013440;
extern int DAT_06013442;
extern int DAT_06013444;
extern int DAT_06013446;
extern int DAT_06013448;
extern int DAT_0601344a;
extern int DAT_0601344c;
extern int DAT_0601344e;
extern int DAT_06013560;
extern int DAT_06013562;
extern int DAT_06013682;
extern int DAT_06013684;
extern int DAT_06013686;
extern int DAT_06013688;
extern int DAT_0601368a;
extern int DAT_0601368c;
extern int DAT_0601368e;
extern int DAT_06013690;
extern int DAT_06013692;
extern int DAT_06013694;
extern int DAT_06013696;
extern int DAT_06013698;
extern int DAT_0601369a;
extern int DAT_0601369c;
extern int DAT_0601369e;
extern int DAT_060136a0;
extern int DAT_060136a2;
extern int DAT_060136a4;
extern int DAT_060136a6;
extern int DAT_060136a8;
extern int DAT_060136aa;
extern int DAT_060136ac;
extern int DAT_060136ae;
extern int DAT_060136b0;
extern int DAT_060136b2;
extern int DAT_060136b4;
extern int DAT_060136b6;
extern int DAT_060136b8;
extern int DAT_060136ba;
extern int DAT_060136bc;
extern int DAT_060136be;
extern int DAT_060136c0;
extern int DAT_060136c2;
extern int DAT_060137b0;
extern int DAT_060137b2;
extern int DAT_060137b4;
extern int DAT_060137b6;
extern int DAT_060137b8;
extern int DAT_060137ba;
extern int DAT_060137bc;
extern int DAT_060137be;
extern int DAT_060137c0;
extern int DAT_060137c2;
extern int DAT_060138d6;
extern int DAT_060138d8;
extern int DAT_060138da;
extern int DAT_06013cca;
extern int DAT_06013ccc;
extern int DAT_06013cce;
extern int DAT_06013cd0;
extern int DAT_06013cd2;
extern int DAT_06013dc6;
extern int DAT_06013dc8;
extern int DAT_06013dca;
extern int DAT_06013dcc;
extern int DAT_06013dce;
extern int DAT_06013dd0;
extern int DAT_06013dd2;
extern int DAT_06013dd4;
extern int DAT_06013dd6;
extern int DAT_06013f46;
extern int DAT_06013f48;
extern int DAT_06013f4a;
extern int DAT_06013f4c;
extern int DAT_06014080;
extern int DAT_06014082;
extern int DAT_06014084;
extern int DAT_06014086;
extern void FUN_0601228a();
extern void FUN_060122f4();
extern void FUN_06012344();
extern int FUN_06012400();
extern void FUN_0601250c();
extern void FUN_060125d0();
extern void FUN_06012710();
extern void FUN_06012b58();
extern int FUN_06012c3c();
extern int FUN_06013c58();
extern int PTR_DAT_060137c4;
extern int PTR_DAT_06013cd4;
extern short DAT_060123de;
extern short DAT_060123e0;
extern short DAT_060123e2;
extern short DAT_06012586;

/* peripheral_config_alt -- Configure alternate SCU interrupt priorities.
 * Calls SCU interrupt config at 0x06038BD4 with (mask, priority) pairs.
 * Different priority mapping from FUN_06019324 (subsystem 18). */
void FUN_06012050(void)
{
    register void (*scu_int_config)() = (void (*)())0x06038BD4;

    scu_int_config(0x10, 7);   /* HBlank-IN: priority 7 */
    scu_int_config(8, 6);      /* VBlank-OUT: priority 6 */
    scu_int_config(0x100, 5);  /* timer 0: priority 5 */
    scu_int_config(0x20, 3);   /* timer 1: priority 3 */
    scu_int_config(4, 1);      /* VBlank-IN: priority 1 */
}

/* camera_view_init -- Initialize camera view parameters for 3D scene.
 * Sets camera enabled flag (0x06078636), clears mode counter, calls
 * perspective setup (0x06014884). Configures two view parameter blocks
 * at 0x060788B4 and 0x060788C0 (FOV, near/far plane). Calls CD sync
 * (0x06035168) 3 times. Sets initial camera angle from DAT_0601214e.
 * For single-player (CAR_COUNT==0): 60-frame timer, no delay.
 * For multi-player: 1-frame timer, 20-frame delay, calls FUN_0601228a. */
void FUN_060120c8(void)
{
  *(int *)0x06078636 = 1;                   /* enable camera system */
  *(int *)0x060788F8 = 0;
  (*(int(*)())0x06014884)(0x20, 0, 0);      /* perspective setup */

  /* View parameter block A: FOV=0x80000, far=0xF3333 */
  *(int *)0x060788B4 = 0;
  *(int *)0x060788B8 = 0x00080000;
  *(int *)0x060788BC = 0x000F3333;

  /* View parameter block B: FOV=0x20000, far=0x53333 */
  *(int *)0x060788C0 = 0;
  *(int *)0x060788C4 = 0x00080000 >> 2;
  *(int *)0x060788C8 = 0x00053333;

  (*(int(*)())0x06035168)();                /* CD sync */
  (*(int(*)())0x06035168)();
  (*(int(*)())0x06035168)();

  *(short *)0x060788B0 = DAT_0601214e;     /* initial camera angle */
  *(short *)0x060788B2 = 0;
  *(int *)0x060788F0 = 0;

  if (CAR_COUNT == 0) {
    *(int *)0x060788AC = 0x3c;              /* 60-frame timer */
    *(int *)0x060788F4 = 0;
  } else {
    *(int *)0x060788AC = 1;                 /* 1-frame timer */
    *(int *)0x060788F4 = 0x14;             /* 20-frame delay */
    FUN_0601228a();
  }
}

/* camera_sequence_timer -- Step the camera intro sequence by timer phases.
 * Timer at 0x060788AC increments each frame:
 *   < 0x14: DMA course data, run camera sweep (FUN_060125d0)
 *   == 0x14: play sound 0xAE110EFF, load 3 DMA overlay blocks
 *   0x15..0x28: run camera pan + zoom (FUN_06012344/FUN_06012400)
 *   > 0x28: disable camera (0x06078636=0), play end sound 0xAE110FFF */
void FUN_060121a8(void)
{
  int *timer = (int *)0x060788AC;
  *timer = *timer + 1;

  if (*timer < 0x14) {
    (*(int(*)())0x06028400)(8, *(int *)0x06063AF0, 0x390,
               0x0000B000 + *(int *)(0x06063AF0 + 4));
    FUN_060125d0();
    return;
  }

  if (*timer == 0x14) {
    (*(int(*)())0x0601D5F4)(0, 0xAE110EFF);     /* trigger sound */
    (*(int(*)())0x060284AE)(8, 0x390, 0x90, 0x0605ACF0);
    (*(int(*)())0x060284AE)(8, 0x490, 0x90, 0x0605ACF0);
    (*(int(*)())0x060283E0)(8, 0x590, 0x0000E000, 0x0605ACF0);
    return;
  }

  if (0x28 < *timer) {
    *(int *)0x06078636 = 0;                      /* disable camera */
    (*(int(*)())0x0601D5F4)(0, 0xAE110FFF);      /* end sound */
    return;
  }

  if (0x14 < *timer) {
    FUN_06012344();                               /* camera pan */
    FUN_06012400();                               /* camera zoom */
    return;
  }
}

/* camera_phase_dispatch -- Dispatch camera sub-routines based on countdown.
 * Countdown timer at 0x0607EBCC selects camera behavior phase:
 *   > 0x6D (109): full camera motion + overlay + DMA (attract sequence)
 *   > 99:  clear camera rotation, overlay + DMA
 *   > 0x27 (39): clear camera rotation, sweep + DMA
 *   <= 39: reset timer=1, transition to GAME_STATE=0x10, enable camera */
void FUN_0601228a(void)
{
  int countdown = *(int *)0x0607EBCC;

  if (0x6d < countdown) {
    FUN_060122f4();             /* camera rotation animation */
    FUN_0601250c();             /* overlay render */
    FUN_06012710();             /* DMA transfer */
    return;
  }
  if (99 < countdown) {
    *(short *)0x060788B2 = 0;   /* clear camera rotation */
    FUN_0601250c();
    FUN_06012710();
    return;
  }
  if (0x27 < countdown) {
    *(short *)0x060788B2 = 0;
    FUN_060125d0();             /* camera sweep */
    FUN_06012710();
    return;
  }

  *(int *)0x0607EBCC = 1;       /* reset countdown */
  GAME_STATE = 0x10;             /* transition to next state */
  *(int *)0x06078636 = 1;       /* enable camera system */
}

/* camera_fov_interpolate -- Animate camera FOV and far-plane toward targets.
 * Camera params at 0x060788B4: [0]=pos, [1]=FOV, [2]=far_plane.
 * Decays FOV by 0x2999/frame (min 0x20000), far-plane by 0x4000/frame
 * (min 0x4CCCC). Rotates camera heading at 0x060788B2 by +0x1800/frame. */
void FUN_060122f4()
{
  volatile int *cam = (volatile int *)0x060788B4;
  cam[1] = cam[1] - 0x2999;           /* decay FOV */
  cam[2] = cam[2] - 0x4000;           /* decay far-plane */
  if (!(cam[1] >= 0x00020000)) {
    cam[1] = 0x00020000;              /* clamp FOV minimum */
  }
  if (!(cam[2] >= 0x0004CCCC)) {
    cam[2] = 0x0004CCCC;              /* clamp far-plane minimum */
  }
  *(short *)0x060788B2 = *(short *)0x060788B2 + 0x1800;  /* rotate heading */
}

/* camera_vibration_apply -- Apply camera vibration to 4 view matrix rows.
 * Computes 3 sinusoidal offsets from half-heading (0x060788AC >> 1) using
 * fixed-point multiply (0x06027552) with frequency constants (DAT_060123de-e2).
 * Applies cross-axis perturbations to 4 consecutive 3-vectors at
 * 0x060788C0, 0x060788CC, 0x060788D8, 0x060788E4 (view frustum corners).
 * CD time delta (0x06034FE0) affects row 3 Y-axis. */
void FUN_06012344(void)
{
    register int (*fpmul)() asm("r3") = (int(*)())0x06027552;  /* fixed-point multiply */
    int sin_a, sin_b, sin_c;
    int *row;
    int half_heading;
    int heading = *(int *)0x060788AC;

    half_heading = ((int)(heading + (unsigned int)(heading < 0)) >> 1) << 0x10;

    sin_a = (*fpmul)(half_heading, (int)DAT_060123de);
    sin_b = (*fpmul)(half_heading, (int)DAT_060123e0);
    sin_c = (*fpmul)(half_heading, (int)DAT_060123e2);

    /* Row 0: 0x060788C0 */
    row = (int *)0x060788C0;
    row[0] = row[0] + sin_a * -2;
    row[1] = row[1] + sin_b;
    row[2] = row[2] + sin_c;

    /* Row 1: 0x060788CC */
    row = (int *)0x060788CC;
    row[0] = row[0] - sin_b;
    row[1] = row[1] - sin_a;
    row[2] = row[2] - sin_a;

    /* Row 2: 0x060788D8 (Y adjusted by CD time delta) */
    row = (int *)0x060788D8;
    row[0] = row[0] + (sin_a << 1);
    sin_a = (*(int(*)())0x06034FE0)();  /* cd_time_delta */
    row[1] = row[1] - sin_a;
    row[2] = row[2] - sin_c;

    /* Row 3: 0x060788E4 */
    row = (int *)0x060788E4;
    row[0] = row[0] + sin_b;
    row[1] = row[1] + sin_b;
    row[2] = row[2] + sin_c;
}

/* background_render_pipeline -- Full background rendering pipeline.
 * Initializes render state, sets camera position from 0x060788B4-BC,
 * configures render params, applies extra effect if STATE_COUNTDOWN > 99.
 * Then sets up sound BGM tempo and position for last car (CAR_COUNT-1). */
void FUN_0601250c(void)
{
    int idx;

    (*(int(*)())0x06026DBC)();   /* render state init */
    (*(int(*)())0x06026E0C)();   /* render param init */

    (*(int(*)())0x06026E2E)(*(int *)0x060788B4, *(int *)0x060788B8, *(int *)0x060788BC);

    (*(int(*)())0x06026F2A)((int)*(short *)0x060788B2);
    (*(int(*)())0x06026EDE)(0);
    (*(int(*)())0x06026E94)(0);

    if (STATE_COUNTDOWN > 99) {
        (*(int(*)())0x06026E94)((int)DAT_06012586);
    }

    idx = (CAR_COUNT - 1) << 2;

    (*(int(*)())0x06031D8C)(*(int *)(0x0606354C + idx), *(int *)0x06063558);
    (*(int(*)())0x06031A28)(*(int *)(0x06063544 + idx), (int)*(short *)0x06089EA0, *(int *)0x06063554);

    (*(int(*)())0x06026DF8)();   /* render finalize */
}

/* bg_sweep_render -- Render background with camera sweep and heading interpolation.
 * Sets up matrix pipeline from camera params at 0x060788B4,
 * applies heading rotation, renders sky dome via VDP1 draw (0x06028400).
 * Interpolates heading toward target (0x0605AC94), then renders
 * background mesh/texture for last car slot. */
void FUN_060125d0()
{
  int course_idx;
  int course_x2;
  int *sprite_pair;
  unsigned short auStack_14[6];
  short *heading = (short *)0x060788B0;
  (*(int(*)())0x06035228)();                          /* cd_sync */
  (*(int(*)())0x06026DBC)();                          /* matrix_push */
  (*(int(*)())0x06026E0C)();                          /* matrix_identity */
  (*(int(*)())0x06026E2E)(*(int *)0x060788B4, *(int *)(0x060788B4 + 4),
             *(int *)(0x060788B4 + 8));               /* matrix_translate */
  (*(int(*)())0x06026F2A)((int)*(short *)0x060788B2); /* matrix_rotate_heading */
  course_idx = (*(int(*)())0x06034FE0)();             /* get_course_index */
  course_x2 = (course_idx << 1);
  sprite_pair = (int *)(0x06063750 + (unsigned int)auStack_14[course_idx] * 8);
  (*(int(*)())0x06028400)(8, *sprite_pair, 0x390,
             0x0000B000 + sprite_pair[1], sprite_pair, course_x2, course_idx);
  if (*heading != *(short *)(0x0605AC94 + course_x2)) {
    *heading = *heading - DAT_060126a4;  /* interpolate toward target */
  }
  (*(int(*)())0x06026EDE)(0);                         /* matrix_scale_y(0) */
  (*(int(*)())0x06026E94)((int)*heading);             /* matrix_scale_x(heading) */
  (*(int(*)())0x06031D8C)(*(int *)(0x0606354C + (CAR_COUNT + -1) << 2),
             *(int *)0x06063558);                     /* mesh_submit */
  (*(int(*)())0x06031A28)(*(int *)(0x06063544 + (CAR_COUNT + -1) << 2),
             (int)*(short *)0x06089EA0, *(int *)0x06063554);  /* texture_submit */
  (*(int(*)())0x06026DF8)();                          /* matrix_pop */
  return;
}

/* attract_sound_dispatch -- Play sound cues at specific countdown thresholds.
 * Reads countdown timer at 0x0607EBCC and dispatches SCSP commands:
 *   40 (0x28): play "5" voice + engine sfx, set timer display
 *   60 (0x3C): play "4" voice
 *   80 (0x50): play "3" voice
 *   100: play "2" voice, enable camera mode, store car heading
 * After threshold check, if countdown > 110 and CD idle, play start jingle. */
void FUN_06012710()
{
  int countdown = *(int *)0x0607EBCC;
  int snd_code;
  void (*snd_cmd)(int, int) = (void (*)(int, int))0x0601D5F4;
  if (countdown == 0x28) {
    snd_cmd(0, 0xAE1125FF);     /* "5" voice */
    snd_cmd(0, 0xAE1116FF);     /* engine sfx */
    *(short *)0x06086056 = 0x3c;
    *(int *)0x0608605A = 1;
  } else {
    snd_code = 0xAE1124FF;      /* "4" voice (countdown == 0x3C) */
    if ((countdown != 0x3c) && (snd_code = 0xAE1123FF, countdown != 0x50)) {
      if (countdown != 100) goto LAB_0601277a;
      *(int *)0x06078654 = 1;   /* enable camera mode */
      *(int *)0x06063EF0 = *(int *)(CAR_PTR_TARGET + 0x30);  /* store heading */
      snd_code = 0xAE1122FF;    /* "2" voice */
    }
    snd_cmd(0, snd_code);
    snd_cmd(0, 0xAE1115FF);     /* common sound */
  }
LAB_0601277a:
  if (0x6e < *(int *)0x0607EBCC && (*(int(*)())0x06035C2C)() == 0) {
    snd_cmd(0, 0xAE110CFF);     /* start jingle */
  }
  return;
}

/* race_result_sequence -- multi-phase race finish presentation and podium sequence.
 *   Phase 0: fade-in overlay sprites (background + label).
 *   Phase 1: wait for car checkpoint 0x52 → show "1st PLACE" banner + sound 0xAE1122FF.
 *   Phase 2: wait for checkpoint 0x58 → show 2nd sprite, enable zoom, sound 0xAE1123FF.
 *   Phase 3: wait for checkpoint 0x5D → show 3rd sprite, sound 0xAE1124FF.
 *   Phase 4: wait for checkpoint 0x61 → final result, sound 0xAE1125FF, start position timer.
 *   Phase 0x13: end sequence — render HUD overlays, disable camera, clear render state.
 *   Scrolls victory lap speed counter at 0x060788F8 by +0x4CCCC per frame. */
int race_result_sequence()
{
  char *scroll_speed = (char *)0x060788F8;     /* victory lap scroll counter */
  char *vdp1_draw_off = (int *)0x060284AE;     /* VDP1 draw with offset */
  char *phase_counter = (char *)0x060788F4;    /* current sequence phase */
  char *sprite_table = (char *)0x06063750;
  char *vdp1_draw = (char *)0x06028400;        /* VDP1 sprite draw */
  char *hud_dest = (char *)0x0605ACDD;         /* HUD sprite destination */
  char *sound_dispatch = (char *)0x0601D5F4;   /* SCSP command dispatcher */
  char *vdp1_wide = (char *)0x060283E0;        /* VDP1 wide sprite draw */
  int car_checkpoint;
  int phase;
  int result;
  int *sprite_entry;
  int *btn_sprite;
  int tile_offset = 0x90;
  *(int *)0x0605B714 = *(int *)0x060788F8;     /* sync scroll display */
  INPUT_STATE = INPUT_STATE | 0x80;
  *(char **)scroll_speed = 0x0004CCCC + *(int *)scroll_speed; /* advance scroll */
  car_checkpoint = *(int *)(CAR_PTR_TARGET + (int)DAT_06012884);
  phase = *(int *)0x060788F4;
  if (phase == 0) {
    /* Phase 0: fade-in overlay */
    (*(int(*)())0x06028400)(0xc, *(int *)(0x06063750 + DAT_06012888), 0x880,
               *(int *)((int)(0x06063750 + DAT_06012888) + 4));
    result = (*(int(*)())vdp1_draw)(0xc, *(int *)(sprite_table + DAT_0601288c), (int)DAT_0601288e,
                              *(int *)((int)(sprite_table + DAT_0601288c) + 4));
    *(int *)phase_counter = *(int *)phase_counter + 1;
  } else if (phase == 1) {
    /* Phase 1: wait for checkpoint 0x52 → show 1st place */
    if (car_checkpoint == 0x52) {
      *(int *)0x060788F4 = *(int *)0x060788F4 + 1;
      (*(int(*)())vdp1_wide)(8, (int)DAT_0601299e, 0x0000F000, hud_dest);
      (*(int(*)())vdp1_wide)(8, (int)DAT_060129a0, 0x0000F000, hud_dest);
      (*(int(*)())vdp1_wide)(8, (int)DAT_060129a2, 0x0000F000, hud_dest);
      (*(int(*)())vdp1_draw)(8, *(int *)(sprite_table + 0x78), (int)DAT_060129a6,
                        *(int *)(sprite_table + 0x7c) + (int)DAT_060129a4);
      result = (*(int(*)())sound_dispatch)(0, 0xAE1122FF); /* SCSP: 1st place fanfare */
    } else {
      /* Pulsing button prompt while waiting */
      if (((*(unsigned short *)0x06063D98 & *(unsigned short *)0x0608188C) == 0) &&
         (*(short *)0x0607ED8C == 0)) {
        btn_sprite = (int *)(0x06063750 + DAT_0601299a);
        result = btn_sprite[1] + (int)DAT_0601299c;
      } else {
        btn_sprite = (int *)(0x06063750 + tile_offset);
        result = btn_sprite[1] + (int)DAT_06012890;
      }
      result = (*(int(*)())0x06028400)(8, *btn_sprite, (int)DAT_0601299e, result);
    }
  } else if (phase == 2) {
    /* Phase 2: checkpoint 0x58 → show 2nd, enable zoom */
    if (car_checkpoint == 0x58) {
      sprite_entry = (int *)(0x06063750 + 0x70);
      *(int *)0x060788F4 = *(int *)0x060788F4 + 1;
      (*(int(*)())vdp1_draw)(8, *sprite_entry, (int)DAT_060129a6,
                        *(int *)(sprite_table + 0x74) + (int)DAT_060129a4);
      *(int *)0x06078654 = 1;                  /* enable zoom */
      *(int *)0x06063EF0 = *(int *)(CAR_PTR_TARGET + 0x30);
      result = (*(int(*)())sound_dispatch)(0, 0xAE1123FF); /* SCSP: 2nd place */
    }
  } else if (phase == 3) {
    /* Phase 3: checkpoint 0x5D → show 3rd */
    if (car_checkpoint == 0x5d) {
      sprite_entry = (int *)(0x06063750 + 0x68);
      *(int *)0x060788F4 = *(int *)0x060788F4 + 1;
      (*(int(*)())vdp1_draw)(8, *sprite_entry, (int)DAT_060129a6,
                        *(int *)(sprite_table + 0x6c) + (int)DAT_060129a4);
      result = (*(int(*)())sound_dispatch)(0, 0xAE1124FF); /* SCSP: 3rd place */
    }
  } else if (phase == 4) {
    /* Phase 4: checkpoint 0x61 → final result */
    if (car_checkpoint == 0x61) {
      *(int *)0x060788F4 = *(int *)0x060788F4 + 1;
      (*(int(*)())vdp1_draw)(8, *(int *)(sprite_table + DAT_06012a92), 0x520,
                        *(int *)((int)(sprite_table + DAT_06012a92) + 4) + (int)DAT_06012a94);
      result = (*(int(*)())sound_dispatch)(0, 0xAE1125FF); /* SCSP: result fanfare */
      *(short *)0x06086056 = 0x14;             /* position sound timer */
      *(int *)0x0608605A = 1;                  /* enable finish sequence */
    }
  } else if (phase == 0x13) {
    /* Phase 0x13: end sequence — render final HUD overlays */
    (*(int(*)())0x060284AE)(8, 0x520, tile_offset, 0x0605ACDD);
    (*(int(*)())vdp1_draw_off)(8, 0x620, tile_offset, hud_dest);
    (*(int(*)())vdp1_draw_off)(8, 0x720, tile_offset, hud_dest);
    (*(int(*)())vdp1_wide)(8, 0x820, 0x0000F000, hud_dest);
    (*(int(*)())vdp1_draw_off)(0xc, 0x880, tile_offset, 0x0605AC9C);
    result = (*(int(*)())vdp1_draw_off)(0xc, 0x980, tile_offset, 0x0605AC9C);
    *(int *)0x0605B714 = 0;                    /* clear scroll state */
    *(int *)0x06078636 = 0;                    /* disable camera */
  } else {
    /* Default: auto-advance to next phase */
    *(int *)0x060788F4 = *(int *)0x060788F4 + 1;
    result = phase;
  }
  return result;
}

/* save_validate_retry -- Validate save data with retry loop.
 * Sets up save descriptor at 0x06084360 (type=1, size=0x50, buf=0x0608436C).
 * Retries BIOS read (0x0603AC1C) up to 5 times against device at 0x06083274.
 * If retry count < 3: sets error flag at 0x06084AEC.
 * Otherwise validates checksum via 0x0603AE08. */
void FUN_06012b58()
{
  int result = -1;
  int retry = 0;
  char *error_flag;
  /* set up save descriptor */
  *(int *)0x06084360 = 1;             /* descriptor type */
  *(int *)(0x06084360 + 8) = 0x0608436C;  /* buffer pointer */
  *(int *)(0x06084360 + 4) = 0x50;    /* data size */
  while (error_flag = (char *)0x06084AEC, retry = retry + 1, retry < 5) {
    result = (*(int(*)())0x0603AC1C)(5, (char *)0x06083274, (char *)0x06084360);
  }
  if (result < 3) {
    *(int *)0x06084AEC = 1;           /* insufficient retries — error */
  } else {
    result = (*(int(*)())0x0603AE08)(0x060448C8);  /* checksum validate */
    if (result < 0) {
      *error_flag = 1;                /* checksum failed */
    } else {
      *error_flag = 0;                /* save valid */
    }
  }
  return;
}

/* save_screen_display -- renders save overlay, waits for BIOS completion, validates save.
 *   Draws "NOW SAVING" sprite (0x060283E0) with tile DAT_06012c66, copies 0x24 bytes
 *   via word DMA (0x0602761E) to display buffer. Polls BIOS callback (0x06018EAC)
 *   until status bit 0 is set. Then draws completion sprite and calls save_validate_retry. */
void save_screen_display()
{
  char *bios_poll = (char *)0x06018EAC;        /* BIOS status polling function */
  unsigned int status;
  int tile_id;
  tile_id = (int)DAT_06012c66;
  /* Draw "NOW SAVING" overlay sprite */
  (*(int(*)())0x060283E0)(8, tile_id, 0x0000E000, 0x060448D4);
  (*(int(*)())0x0602761E)(*(int *)0x060612B4 + tile_id, 0x060612C4 + tile_id, 0x24); /* word DMA */
  (*(int(*)())0x06034C48)();                   /* initiate save operation */
  do {
    status = (*(int(*)())bios_poll)();
  } while ((status & 0xf) != 1);              /* wait for BIOS save complete */
  /* Draw completion sprite */
  (*(int(*)())0x060283E0)(8, tile_id, 0x0000E000, 0x0605ACCA);
  (*(int(*)())0x0602761E)(*(int *)0x060612B4 + tile_id, 0x060612C4 + tile_id, 0x24);
  FUN_06012b58();                              /* validate saved data */
  return;
}

/* bg_tilemap_load -- Load background tilemap for a course.
 * param_1: course index (1/2/default). Selects tilemap descriptor
 * from table at 0x060448E8 stride 0x0C, loads to VDP2 VRAM at 0x200000. */
void FUN_06012d7c(int param_1)
{
    if (param_1 == 1)
        FUN_06012c3c(0x060448E8, 0x00200000);
    else if (param_1 == 2)
        FUN_06012c3c(0x060448F4, 0x00200000);
    else
        FUN_06012c3c(0x06044900, 0x00200000);
}

/* bg_tilemap_and_pattern_load -- Load background tilemap + pattern pair.
 * param_1: course index (1/2/default). Loads tilemap to VDP2 VRAM 0x200000
 * and pattern to 0x240000. Course descriptors at 0x0604490C stride 0x10. */
void FUN_06012db4(int param_1)
{
  if (param_1 == 1) {
    FUN_06012c3c(0x0604490C, 0x00200000);
    FUN_06012c3c(0x0604491C, 0x00240000);
  } else if (param_1 == 2) {
    FUN_06012c3c(0x06044928, 0x00200000);
    FUN_06012c3c(0x06044938, 0x00240000);
  } else {
    FUN_06012c3c(0x06044944, 0x00200000);
    FUN_06012c3c(0x06044954, 0x00240000);
  }
}

/* bg_pattern_load -- Load background pattern data for a course.
 * param_1: course index (1/2/default). Selects pattern descriptor
 * from table at 0x0604496C stride 0x0C, loads to VDP2 VRAM at 0x2A8000. */
void FUN_06012e08(int param_1)
{
    if (param_1 == 1)
        FUN_06012c3c(0x0604496C, 0x002A8000);
    else if (param_1 == 2)
        FUN_06012c3c(0x06044978, 0x002A8000);
    else
        FUN_06012c3c(0x06044984, 0x002A8000);
}

/* scene_objects_init -- Load and initialize scene objects for a course.
 * Sets up memory regions (0x06084FA8/FAC/FB0), calls VDP and render
 * init functions, then loads numbered object resources (1..N) via
 * resource loader at 0x06007658.
 *
 * Scene setup variant B (946 instructions). Three parallel variants:
 *   FUN_0600EC78 = variant A, FUN_06012F80 = variant B (this),
 *   FUN_0602382C = variant C (largest).
 * Each variant loads a different course's object set.
 *
 * Called from race_state_handlers.c and state_init_handlers.c. */
void scene_objects_init()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  int *piVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  *(char **)0x06084FA8 = 0x06084B28;

  *(char **)0x06084FAC = 0x06084CA8;

  *(char **)0x06084FB0 = 0x06084E28;

  (*(int(*)())0x060149E0)();

  (*(int(*)())0x06026CE0)();

  (*(int(*)())0x06039250)(0x06063F5C);

  (*(int(*)())0x060393FC)(0,0,0,(int)DAT_06013052,(int)DAT_06013050);

  VDP1_CMD_BASE_PTR = 0;

  **(short **)0x06063F5C = (short)0x00008000;

  puVar1 = (char *)0x0602853E;

  (*(int(*)())0x0602853E)(0);

  (*(int(*)())puVar1)(4);

  (*(int(*)())puVar1)(8);

  (*(int(*)())puVar1)(0xc);

  (*(int(*)())(BIOS_FUNC_0344))(0xffffffff,0x83);

  (*(int(*)())0x06012E00)();

  (*(int(*)())(BIOS_FUNC_0344))(-132,0);

  *(int *)0x0606A4F4 = 0;

  *(int *)0x0606A4EC = (int)DAT_06013058;

  puVar1 = (char *)0x06089E44;

  *(short *)(0x06089E44 + 6) = 2;

  *(short *)puVar1 = 0;

  puVar3 = (char *)0x002A0000;

  puVar2 = (char *)0x06007658;

  iVar7 = 0x108;

  (*(int(*)())0x06007658)(1,iVar7,0,0x002A0000 + DAT_0601305c);

  (*(int(*)())puVar2)(2,0x810,0,puVar3 + DAT_0601305e);

  (*(int(*)())puVar2)(3,(int)DAT_06013064,0,puVar3 + DAT_06013062);

  (*(int(*)())puVar2)(4,(int)DAT_06013068,0,puVar3 + DAT_06013066);

  (*(int(*)())puVar2)(5,0x519,0,puVar3 + DAT_060131b4);

  (*(int(*)())puVar2)(6,(int)DAT_060131ba,0,puVar3 + DAT_060131b8);

  (*(int(*)())puVar2)(7,0x738,4,puVar3 + DAT_060131bc);

  (*(int(*)())puVar2)(8,0x738,4,puVar3 + DAT_060131c0);

  (*(int(*)())puVar2)(9,0x208,0,puVar3 + DAT_060131c2);

  (*(int(*)())puVar2)(10,0xa28,0x3c,puVar3 + DAT_060131c6);

  (*(int(*)())puVar2)(0x10,0x228,8,puVar3 + DAT_060131ca);

  (*(int(*)())puVar2)(0x11,0x428,8,puVar3 + DAT_060131ce);

  (*(int(*)())puVar2)(0x12,0x418,8,puVar3 + DAT_060131d2);

  (*(int(*)())puVar2)(0x13,0x820,8,puVar3 + DAT_060131d6);

  (*(int(*)())puVar2)(0x14,0x518,8,puVar3 + DAT_060131da);

  (*(int(*)())puVar2)(0x15,0x518,8,puVar3 + DAT_060131de);

  (*(int(*)())puVar2)(0x16,0x508,0xc,puVar3 + DAT_060131e0);

  (*(int(*)())puVar2)(0x17,0xd10,8,puVar3 + DAT_060131e4);

  (*(int(*)())puVar2)(0x18,(int)DAT_060131ea,0x1c,puVar3 + DAT_060131e8);

  iVar5 = 0x348;

  (*(int(*)())puVar2)(0x19,iVar5,0x10,puVar3 + DAT_060131ee);

  (*(int(*)())puVar2)(0x1a,iVar5,0x10,puVar3 + DAT_060131f0);

  (*(int(*)())puVar2)(0x1b,iVar5,0x10,puVar3 + DAT_060131f2);

  iVar6 = 0x630;

  (*(int(*)())puVar2)(0x1c,iVar6,0x1c,puVar3 + DAT_060131f6);

  (*(int(*)())puVar2)(0x1d,0xa28,0x10,puVar3 + DAT_060131f8);

  (*(int(*)())puVar2)(0x1e,0xc08,0x18,puVar3 + DAT_060132f2);

  (*(int(*)())puVar2)(0x1f,0xc10,0x18,puVar3 + DAT_060132f6);

  iVar5 = 0x308;

  (*(int(*)())puVar2)(0x20,iVar5,0xc,puVar3 + DAT_060132fc);

  (*(int(*)())puVar2)(0x21,0x410,0xc,puVar3 + DAT_060132fe);

  (*(int(*)())puVar2)(0x22,iVar5,0xc,puVar3 + DAT_06013302);

  (*(int(*)())puVar2)(0x23,iVar5,0xc,puVar3 + DAT_06013304);

  (*(int(*)())puVar2)(0x24,0x410,0xc,puVar3 + DAT_06013306);

  (*(int(*)())puVar2)(0x25,(int)DAT_0601330a,0x14,puVar3 + DAT_06013308);

  (*(int(*)())puVar2)(0x26,(int)DAT_0601330a,0x14,puVar3 + DAT_0601330c);

  (*(int(*)())puVar2)(0x27,0x610,0xc,puVar3 + DAT_0601330e);

  (*(int(*)())puVar2)(0x28,0x510,0x14,puVar3 + DAT_06013312);

  iVar5 = 0x310;

  (*(int(*)())puVar2)(0x29,iVar5,0x14,puVar3 + DAT_06013318);

  (*(int(*)())puVar2)(0x2a,(int)DAT_0601331c,0x14,puVar3 + DAT_0601331a);

  (*(int(*)())puVar2)(0x2b,(int)DAT_06013320,0x14,puVar3 + DAT_0601331e);

  (*(int(*)())puVar2)(0x2c,0x110,0xc,puVar3 + DAT_06013322);

  (*(int(*)())puVar2)(0x2d,0x110,0xc,puVar3 + DAT_06013326);

  (*(int(*)())puVar2)(0x2e,0x510,0x14,puVar3 + DAT_06013328);

  (*(int(*)())puVar2)(0x2f,iVar5,0x14,puVar3 + DAT_0601332a);

  (*(int(*)())puVar2)(0x30,(int)DAT_0601331c,0x14,puVar3 + DAT_0601332c);

  (*(int(*)())puVar2)(0x31,(int)DAT_06013320,0x14,puVar3 + DAT_0601332e);

  (*(int(*)())puVar2)(0x32,iVar7,0x14,puVar3 + DAT_06013440);

  (*(int(*)())puVar2)(0x33,iVar7,0x14,puVar3 + DAT_06013442);

  (*(int(*)())puVar2)(0x34,iVar7,0x14,puVar3 + DAT_06013444);

  (*(int(*)())puVar2)(0x35,iVar7,0x14,puVar3 + DAT_06013446);

  (*(int(*)())puVar2)(0x36,iVar7,0x10,puVar3 + DAT_06013448);

  (*(int(*)())puVar2)(0x37,iVar7,0x1c,puVar3 + DAT_0601344a);

  (*(int(*)())puVar2)(0x38,iVar7,8,puVar3 + DAT_0601344c);

  (*(int(*)())puVar2)(0x39,iVar7,0x10,puVar3 + DAT_0601344e);

  *(short *)(puVar1 + 2) = 1;

  puVar1 = (char *)0x06007540;

  (*(int(*)())0x06007540)(0x41,1,0);

  (*(int(*)())puVar1)(0x42,2,0);

  (*(int(*)())puVar1)(0x43,3,0);

  (*(int(*)())puVar1)(0x44,4,0);

  (*(int(*)())puVar1)(0x45,5,0);

  (*(int(*)())puVar1)(0x46,6,0);

  (*(int(*)())puVar1)(0x47,7,4);

  (*(int(*)())puVar1)(0x48,8,4);

  (*(int(*)())puVar1)(0x49,9,0);

  (*(int(*)())puVar1)(0x4a,10,0x3c);

  (*(int(*)())puVar1)(0x50,0x10,0x20);

  (*(int(*)())puVar1)(0x51,0x11,0x20);

  (*(int(*)())puVar1)(0x52,0x12,0x20);

  (*(int(*)())puVar1)(0x53,0x13,0x20);

  (*(int(*)())puVar1)(0x54,0x14,0x20);

  (*(int(*)())puVar1)(0x55,0x15,0x20);

  (*(int(*)())puVar1)(0x56,0x16,0x24);

  (*(int(*)())puVar1)(0x57,0x17,0x20);

  (*(int(*)())puVar1)(0x58,0x18,0x34);

  (*(int(*)())puVar1)(0x59,0x19,0x28);

  (*(int(*)())puVar1)(0x5a,0x1a,0x28);

  (*(int(*)())puVar1)(0x5b,0x1b,0x28);

  (*(int(*)())puVar1)(0x5c,0x1c,0x34);

  (*(int(*)())puVar1)(0x5d,0x1d,0x28);

  (*(int(*)())puVar1)(0x5e,0x1e,0x30);

  (*(int(*)())puVar1)(0x5f,0x1f,0x30);

  (*(int(*)())puVar1)(0x60,0x20,0x24);

  (*(int(*)())puVar1)(0x61,0x21,0x24);

  (*(int(*)())puVar1)(0x62,0x22,0x24);

  (*(int(*)())puVar1)(99,0x23,0x24);

  (*(int(*)())puVar1)(100,0x24);

  (*(int(*)())puVar1)(0x65,0x25,0x2c);

  (*(int(*)())puVar1)(0x66,0x26,0x2c);

  (*(int(*)())puVar1)(0x67,0x27,0x24);

  (*(int(*)())puVar1)(0x68,0x28,0x2c);

  (*(int(*)())puVar1)(0x69,0x29,0x2c);

  (*(int(*)())puVar1)(0x6a,0x2a,0x2c);

  (*(int(*)())puVar1)(0x6b,0x2b,0x2c);

  (*(int(*)())puVar1)(0x6c,0x2c,0x24);

  (*(int(*)())puVar1)(0x6d,0x2d,0x24);

  (*(int(*)())puVar1)(0x6e,0x2e,0x2c);

  (*(int(*)())puVar1)(0x6f,0x2f,0x2c);

  (*(int(*)())puVar1)(0x70,0x30,0x2c);

  (*(int(*)())puVar1)(0x71,0x31,0x2c);

  (*(int(*)())puVar1)(0x72,0x32,0x2c);

  (*(int(*)())puVar1)(0x73,0x33,0x2c);

  (*(int(*)())puVar1)(0x74,0x34,0x2c);

  (*(int(*)())puVar1)(0x75,0x35,0x2c);

  (*(int(*)())puVar1)(0x76,0x36,0x28);

  (*(int(*)())puVar1)(0x77,0x37,0x34);

  (*(int(*)())puVar1)(0x78,0x38,0x20);

  (*(int(*)())puVar1)(0x79,0x39,0x28);

  iVar7 = 0x730;

  (*(int(*)())puVar2)(0x8a,iVar7,0x74,puVar3 + DAT_06013562);

  (*(int(*)())puVar2)(0x8b,iVar6,0x74,puVar3 + DAT_06013682);

  (*(int(*)())puVar2)(0x8c,iVar6,0x74,puVar3 + DAT_06013684);

  (*(int(*)())puVar2)(0x8d,iVar7,0x74,puVar3 + DAT_06013686);

  (*(int(*)())puVar2)(0x8e,iVar6,0x74,puVar3 + DAT_06013688);

  (*(int(*)())puVar2)(0x8f,iVar6,0x74,puVar3 + DAT_0601368a);

  (*(int(*)())puVar2)(0x90,iVar6,0x74,puVar3 + DAT_0601368c);

  (*(int(*)())puVar2)(0x91,0x830,0x74,puVar3 + DAT_0601368e);

  (*(int(*)())puVar2)(0x92,0x430,0x74,puVar3 + DAT_06013694);

  (*(int(*)())puVar2)(0x93,0x540,0x74,puVar3 + DAT_0601369a);

  (*(int(*)())puVar2)(0x94,iVar6,0x74,puVar3 + DAT_060136a0);

  (*(int(*)())puVar2)((int)DAT_060136a6,0x530,0x74,puVar3 + DAT_060136a2);

  (*(int(*)())puVar2)((int)DAT_060136aa,0x830,0x74,puVar3 + DAT_060136a8);

  (*(int(*)())puVar2)(0x97,iVar7,0x74,puVar3 + DAT_060136ac);

  (*(int(*)())puVar2)(0x98,iVar7,0x74,puVar3 + DAT_060136ae);

  (*(int(*)())puVar2)(0x99,iVar6,0x74,puVar3 + DAT_060136b0);

  (*(int(*)())puVar2)(0x9a,0x840,0x74,puVar3 + DAT_060136b2);

  (*(int(*)())puVar2)(0x9b,iVar6,0x74,puVar3 + DAT_060136b8);

  (*(int(*)())puVar2)((int)DAT_060136bc,0x530,0x74,puVar3 + DAT_060136ba);

  (*(int(*)())puVar2)(0x9d,iVar6,0x74,puVar3 + DAT_060136be);

  (*(int(*)())puVar2)(0x9e,iVar7,0x74,puVar3 + DAT_060136c0);

  (*(int(*)())puVar2)(0x9f,iVar6,0x74,puVar3 + DAT_060136c2);

  (*(int(*)())puVar2)(0xa0,0x930,0x74,puVar3 + DAT_060137b0);

  (*(int(*)())puVar2)(0xa1,iVar7,0x74,puVar3 + DAT_060137b6);

  (*(int(*)())puVar2)(0xa2,iVar6,0x74,puVar3 + DAT_060137b8);

  (*(int(*)())puVar2)(0xa3,iVar7,0x74,puVar3 + DAT_060137ba);

  (*(int(*)())puVar2)(0xa4,iVar6,0x74,puVar3 + DAT_060137bc);

  (*(int(*)())puVar2)(0xa5,iVar6,0x74,puVar3 + DAT_060137be);

  (*(int(*)())puVar2)(0xa6,iVar7,0x74,puVar3 + DAT_060137c0);

  (*(int(*)())puVar2)(0xa7,iVar5,0x70,puVar3 + DAT_060137c2);

  puVar1 = (char *)0x0602761E;

  (*(int(*)())0x0602761E)(0x25F00000,0x0604878C,0x20);

  (*(int(*)())puVar1)(0x25F00600,0x0604814C,0x60);

  (*(int(*)())puVar1)(0x25F00660,0x0604848C,0x40);

  (*(int(*)())puVar1)(0x25F006A0,0x060484CC,0x40);

  puVar2 = (char *)0x060485AC;

  (*(int(*)())puVar1)(0x25F006E0,0x060485AC,0x40);

  (*(int(*)())puVar1)(0x25F004E0,puVar2,0x40);

  (*(int(*)())puVar1)(0x25F00720,0x0605CD9C,0x20);

  puVar1 = (char *)0x06038BD4;

  (*(int(*)())0x06038BD4)(0x10,4);

  (*(int(*)())puVar1)(0x100,5);

  (*(int(*)())puVar1)(8,6);

  iVar5 = CAR_COUNT;

  *(int *)0x06084B00 = *(int *)(0x0605AD14 + (iVar5 << 2));

  *(int *)0x06084B1C = *(int *)(0x0605AD20 + (iVar5 << 2));

  FUN_06013c58();

  puVar1 = (char *)0x06084B08;

  *(int *)0x06084B08 = 0xf;

  *(int *)0x06084B0C = 0xf;

  *(int *)0x06084B18 = 0;

  *(int *)0x06084B20 = 0x50;

  *(short *)0x06084AF0 = DAT_060138d6;

  *(int *)0x0607EBCC = (int)DAT_060138d8;

  *(int *)0x06084AF2 = 0;

  puVar2 = (char *)0x06084B14;

  *(int *)0x06084B14 = 0;

  puVar2[1] = 0;

  puVar2[2] = 0;

  puVar2[3] = 0;

  piVar4 = (int *)(0x0605AD5C + *(int *)((int)(int)puVar1 << 5));

  *(short *)0x06084AF8 = *(short *)(piVar4 + 6);

  *(int *)0x06084AFC = *piVar4 + (int)DAT_060138da;

  *(short *)0x0605AAA0 = 0;

  (*(int(*)())0x0601D5F4)(0,0xAB1100FF);

  (*(int(*)())0x060149CC)();

  (*(int(*)())0x06026CE0)();

  return;

}

/* background_update -- Per-frame background processing.
 * 1. Dispatch through background mode vtable (indexed by 0x06084AF2)
 * 2. Update background scroll/animation with fixed-point parameters
 * 3. Commit frame display (frame_end_display_commit) */
void FUN_0601389e(void)
{
    (*(int(*)())(*(int *)(0x0605B6B8 + (unsigned int)(unsigned char)*(int *)(0x06084AF2 << 2))))();
    (*(int(*)())0x06011AF4)(0, 0x00960000, 0x00010000, 0x00010000, 0x00008000, 0x00010000, 0);
    (*(int(*)())0x060078DC)();  /* frame_end_display_commit */
}

/* race_results_hud_display -- Render the race results screen HUD.
 * Draws background sprites, formats race/lap times, shows finishing
 * position with rank number and trophy sprite. Handles both single
 * and multiplayer result layouts via mode flags at 0x06085FF4/FF8. */
int race_results_hud_display()
{
    short sprite_sel;
    int time_str;
    unsigned int rank;
    unsigned int rank_clamped;
    int y_offset = (int)DAT_06013ccc;
    char *sprite_table = (char *)0x06063750;   /* sprite data table */
    char *car_base = (char *)0x06078900;       /* car struct base */

    (*(int(*)())0x0602853E)(4);                /* set_draw_priority(4) */
    (*(int(*)())0x0602853E)(0xc);              /* set_draw_priority(12) */
    (*(int(*)())0x06028560)();                 /* draw_flush */

    /* Background panel sprite */
    (*(int(*)())0x06028400)(8, *(int *)(sprite_table + DAT_06013cca), 0,
                          *(int *)((int)(sprite_table + DAT_06013cca) + 4));

    (*(int(*)())0x0602853E)(4);                /* set_draw_priority(4) */

    /* Race time label sprite */
    (*(int(*)())0x06028400)(4, *(int *)(sprite_table + DAT_06013cce), 0x18,
                          *(int *)((int)(sprite_table + DAT_06013cce) + 4) + y_offset);
    /* Lap time label sprite */
    (*(int(*)())0x06028400)(4, *(int *)(sprite_table + DAT_06013cd0), 0xcb0,
                          *(int *)((int)(sprite_table + DAT_06013cd0) + 4) + y_offset);

    /* Select best lap or default sprite based on VS mode flag */
    sprite_sel = DAT_06013dc6;
    if (*(int *)0x06085FF4 == '\0') {          /* not VS mode */
        sprite_sel = PTR_DAT_06013cd4;
    }
    (*(int(*)())0x06028400)(4, *(int *)(sprite_table + sprite_sel), (int)DAT_06013dc8,
                          *(int *)((int)(sprite_table + sprite_sel) + 4) + y_offset);

    /* Clear race/lap/best time digit displays */
    (*(int(*)())0x06014884)(8, 0);             /* format_time_display(RACE, 0) */
    (*(int(*)())0x06014884)(0x10, 0);          /* format_time_display(LAP, 0) */
    (*(int(*)())0x06014884)(0x20, 0);          /* format_time_display(BEST, 0) */

    /* Format and draw total race time */
    time_str = (*(int(*)())0x06005DD4)(*(int *)(car_base + DAT_06013dca));
    (*(int(*)())0x060284AE)(0xc, (int)DAT_06013dce, (int)DAT_06013dcc, time_str);

    /* Format and draw best lap time (capped at 9:59.99 = 0x927BF frames) */
    car_base = (char *)0x000927BF;
    if (*(char **)0x060786A4 <= (char *)0x000927BF) {
        car_base = *(char **)0x060786A4;       /* use actual best if under cap */
    }
    time_str = (*(int(*)())0x06005DD4)(car_base);
    (*(int(*)())0x060284AE)(0xc, 0xc98, (int)DAT_06013dcc, time_str);

    /* Single-player: draw "GOAL" banner */
    if (*(int *)0x06085FF8 == '\0') {
        time_str = (*(int(*)())0x060283E0)(0xc, (int)DAT_06013dd6, 0x0000F000, 0x06044A58);
        return time_str;
    }

    /* Multiplayer: draw rank number (1st/2nd/3rd etc.) */
    (*(int(*)())0x06028430)(0xc, (int)DAT_06013dd2, 0x30, (unsigned char)*(int *)0x06086012 + 1);

    /* Draw trophy sprite for rank (clamp to 3 max) */
    rank = (unsigned int)(unsigned char)*(int *)0x06086012;
    rank_clamped = rank;
    if (2 < rank) {
        rank_clamped = 3;
    }
    if (2 < rank) {
        rank = 3;
    }
    time_str = (*(int(*)())0x06028400)(0xc, *(int *)(sprite_table + ((rank + 0x48) << 3)), (int)DAT_06013dd4,
                                     *(int *)(sprite_table + ((rank_clamped + 0x48) << 3) + 4));
    return time_str;
}

/* background_rotation_wobble -- Apply periodic rotation to background.
 * Uses low 5 bits of FRAME_COUNTER to create a wobble effect.
 * Only applies rotation when counter > 16, scaling by <<12 for angle. */
void FUN_06013e12(void)
{
    unsigned short phase = (unsigned short)FRAME_COUNTER & 0x1F;
    if (phase > 0x10) {
        (*(int(*)())0x06026EDE)((int)(short)(phase << 12));  /* heading_rotation */
    }
}

/* podium_object_animate -- Render animated 3D podium objects.
 * Iterates through object transform table at 0x0605AD5C, applying
 * animated position/rotation/scale from animation phase. Each entry
 * is 32 bytes with position, rotation angles, and scale factor.
 * Uses matrix stack for per-object local transforms. */
int podium_object_animate()
{
    int temp;
    int x_pos, z_pos;
    int y_base;
    int render_result;
    int obj_index = 0;
    int *table_end = (int *)(0x0605AD5C + DAT_06013f46);
    int *obj = (int *)0x0605AD5C;              /* object transform table */
    unsigned int anim_phase;                    /* animation interpolation */

    (*(int(*)())0x06026E0C)();                 /* matrix_identity_load */

    do {
        anim_phase = (unsigned int)*(unsigned short *)0x06084AF6;

        (*(int(*)())0x06026DBC)();             /* matrix_push */

        /* Global Y translation (animated bounce) */
        temp = (*(int(*)())0x06027552)(anim_phase * 0x00010000, (int)DAT_06013f48, 0x00010000);
        (*(int(*)())0x06026E2E)(0, DAT_06013f4a + temp, 0x00010000);  /* translate(0, y, 1.0) */

        /* Pre-tilt rotation */
        (*(int(*)())0x06026F2A)((int)*(short *)(obj + 6));  /* rotate_z(tilt_angle) */

        /* Animated X/Y/Z position */
        x_pos = (*(int(*)())0x06027552)(obj[1], anim_phase * 0x00010000);  /* fmul(x, phase) */
        temp = (*(int(*)())0x06027552)(obj[2], anim_phase * 0x00010000);   /* fmul(elevation, phase) */
        y_base = *obj;
        z_pos = (*(int(*)())0x06027552)(obj[3], anim_phase * 0x00010000);  /* fmul(z, phase) */
        (*(int(*)())0x06026E2E)(x_pos, y_base - temp, z_pos);             /* translate(x, y-elev, z) */

        /* Undo tilt, apply per-object rotations */
        (*(int(*)())0x06026F2A)(-(int)*(short *)(obj + 6));                /* rotate_z(-tilt) */
        (*(int(*)())0x06026E94)((int)*(short *)((int)obj + 0x1a) * anim_phase);  /* rotate_x(pitch) */
        (*(int(*)())0x06026EDE)((int)*(short *)(obj + 7) * anim_phase);          /* rotate_y(heading) */
        (*(int(*)())0x06026F2A)((int)*(short *)((int)obj + 0x1e) * anim_phase);  /* rotate_z(roll) */

        /* Animated uniform scale */
        temp = (*(int(*)())0x06027552)(obj[4], anim_phase * 0x00010000);   /* fmul(scale, phase) */
        temp = DAT_06013f4c + temp;
        (*(int(*)())0x06026E60)(temp, temp, temp);  /* scale(s, s, s) */

        /* Set texture and render mesh */
        (*(int(*)())0x06031D8C)(*(int *)(0x06062338 + obj_index), 4);      /* obj_set_texture */
        render_result = (*(int(*)())0x06031A28)(*(int *)(0x060622C0 + obj_index), (int)*(short *)0x06089E4A, 1);

        obj = obj + 8;                         /* next entry (32 bytes) */
        OBJ_STATE_PRIMARY = OBJ_STATE_PRIMARY + -0x30;  /* decrement render slot */
        obj_index = obj_index + 4;
    } while (obj < table_end);

    return render_result;
}

/* podium_object_render_static -- Render podium objects without animation.
 * Simpler variant of podium_object_animate: uses fixed Y offset and
 * constant scale factor instead of phase-interpolated values.
 * Iterates the same 32-byte transform table at 0x0605AD5C. */
void podium_object_render_static()
{
    int scale;
    int obj_index = 0;
    int *table_end = (int *)(0x0605AD5C + DAT_06014080);
    int *obj = (int *)0x0605AD5C;              /* object transform table */
    unsigned int anim_phase;

    (*(int(*)())0x06026E0C)();                 /* matrix_identity_load */

    do {
        anim_phase = (unsigned int)*(unsigned short *)0x06084AF6;

        (*(int(*)())0x06026DBC)();             /* matrix_push */

        /* Fixed Y translation (no animated bounce) */
        (*(int(*)())0x06026E2E)(0, (int)DAT_06014082, 0x00010000);  /* translate(0, y_offset, 1.0) */

        /* Tilt rotation around object center */
        (*(int(*)())0x06026F2A)((int)*(short *)(obj + 6));   /* rotate_z(tilt) */
        (*(int(*)())0x06026E2E)(0, *obj);                     /* translate(0, y_base) */
        (*(int(*)())0x06026F2A)(-(int)*(short *)(obj + 6));  /* rotate_z(-tilt) */

        /* Animated uniform scale */
        scale = (*(int(*)())0x06027552)((int)DAT_06014084, anim_phase * 0x00010000);
        scale = DAT_06014086 + scale;
        (*(int(*)())0x06026E60)(scale, scale, scale);  /* scale(s, s, s) */

        /* Set texture and render mesh */
        (*(int(*)())0x06031D8C)(*(int *)(0x06062338 + obj_index), 4);      /* obj_set_texture */
        (*(int(*)())0x06031A28)(*(int *)(0x060622C0 + obj_index), (int)*(short *)0x06089E4A, 1);

        obj = obj + 8;                         /* next entry (32 bytes) */
        *(int *)0x06089EDC = *(int *)0x06089EDC + -0x30;  /* decrement render slot */
        obj_index = obj_index + 4;
    } while (obj < table_end);

    return;
}
