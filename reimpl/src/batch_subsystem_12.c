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
extern void camera_phase_dispatch();
extern void camera_fov_interpolate();
extern void camera_vibration_apply();
extern int FUN_06012400();
extern void background_render_pipeline();
extern void camera_sweep_render();
extern void attract_sound_dispatch();
extern void save_validate_retry();
extern int FUN_06012c3c();
extern int FUN_06013c58();
extern int PTR_DAT_060137c4;
extern int PTR_DAT_06013cd4;
extern short DAT_060123de;
extern short DAT_060123e0;
extern short DAT_060123e2;
extern short DAT_06012586;

/* scu_interrupt_priorities_alt -- Configure alternate SCU interrupt priority map.
 * Used during attract/demo mode (different from race-mode priorities).
 * HBlank-IN highest (7), VBlank-IN lowest (1). */
void scu_interrupt_priorities_alt(void)
{
    void (*scu_int_config)(int, int) = (void (*)(int, int))0x06038BD4;

    scu_int_config(0x10,  7);   /* HBlank-IN:  priority 7 (highest) */
    scu_int_config(0x08,  6);   /* VBlank-OUT: priority 6 */
    scu_int_config(0x100, 5);   /* Timer 0:    priority 5 */
    scu_int_config(0x20,  3);   /* Timer 1:    priority 3 */
    scu_int_config(0x04,  1);   /* VBlank-IN:  priority 1 (lowest) */
}
void FUN_06012050(void) __attribute__((alias("scu_interrupt_priorities_alt")));

/* camera_view_init -- Initialize camera view parameters for 3D scene.
 * Configures two view parameter blocks (FOV, far-plane), sets initial
 * camera angle, and starts intro timer. Multi-player calls phase dispatch. */
void camera_view_init(void)
{
    *(int *)0x06078636 = 1;                   /* enable camera system */
    *(int *)0x060788F8 = 0;
    (*(int(*)())0x06014884)(0x20, 0, 0);      /* perspective setup */

    /* View block A: FOV=0x80000 (8.0), far=0xF3333 (15.2) */
    *(int *)0x060788B4 = 0;
    *(int *)0x060788B8 = 0x00080000;
    *(int *)0x060788BC = 0x000F3333;

    /* View block B: FOV=0x20000 (2.0), far=0x53333 (5.2) */
    *(int *)0x060788C0 = 0;
    *(int *)0x060788C4 = 0x00080000 >> 2;
    *(int *)0x060788C8 = 0x00053333;

    (*(int(*)())0x06035168)();                /* cd_sync */
    (*(int(*)())0x06035168)();
    (*(int(*)())0x06035168)();

    *(short *)0x060788B0 = DAT_0601214e;      /* initial camera angle */
    *(short *)0x060788B2 = 0;
    *(int *)0x060788F0 = 0;

    if (CAR_COUNT == 0) {
        *(int *)0x060788AC = 0x3C;            /* 60-frame intro timer */
        *(int *)0x060788F4 = 0;
    } else {
        *(int *)0x060788AC = 1;               /* 1-frame timer */
        *(int *)0x060788F4 = 0x14;            /* 20-frame delay */
        camera_phase_dispatch();
    }
}
void FUN_060120c8(void) __attribute__((alias("camera_view_init")));

/* camera_sequence_timer -- Step the camera intro sequence by timer phases.
 *   < 20: DMA course data + camera sweep
 *   == 20: trigger sound, load 3 overlay blocks
 *   21..40: camera vibration + zoom
 *   > 40: disable camera, play end sound */
void camera_sequence_timer(void)
{
    int *timer = (int *)0x060788AC;
    *timer += 1;

    if (*timer < 0x14) {
        (*(int(*)())0x06028400)(8, *(int *)0x06063AF0, 0x390,
                   0x0000B000 + *(int *)(0x06063AF0 + 4));
        camera_sweep_render();
        return;
    }

    if (*timer == 0x14) {
        (*(int(*)())0x0601D5F4)(0, 0xAE110EFF);     /* trigger sound */
        (*(int(*)())0x060284AE)(8, 0x390, 0x90, 0x0605ACF0);
        (*(int(*)())0x060284AE)(8, 0x490, 0x90, 0x0605ACF0);
        (*(int(*)())0x060283E0)(8, 0x590, 0x0000E000, 0x0605ACF0);
        return;
    }

    if (*timer > 0x28) {
        *(int *)0x06078636 = 0;                      /* disable camera */
        (*(int(*)())0x0601D5F4)(0, 0xAE110FFF);      /* end sound */
        return;
    }

    if (*timer > 0x14) {
        camera_vibration_apply();
        FUN_06012400();                               /* camera zoom */
        return;
    }
}
#if 0 /* FUN_060121A8 -- replaced by ASM import of original bytes */
void FUN_060121a8(void) __attribute__((alias("camera_sequence_timer")));
#endif

/* camera_phase_dispatch -- Dispatch camera sub-routines based on countdown.
 *   > 109: FOV animation + background render + attract sound
 *   > 99: clear rotation, background render + attract sound
 *   > 39: clear rotation, camera sweep + attract sound
 *   <= 39: reset countdown, transition to GAME_STATE=0x10 */
void camera_phase_dispatch(void)
{
    int countdown = *(int *)0x0607EBCC;

    if (countdown > 0x6D) {
        camera_fov_interpolate();
        background_render_pipeline();
        attract_sound_dispatch();
        return;
    }
    if (countdown > 99) {
        *(short *)0x060788B2 = 0;   /* clear camera rotation */
        background_render_pipeline();
        attract_sound_dispatch();
        return;
    }
    if (countdown > 0x27) {
        *(short *)0x060788B2 = 0;
        camera_sweep_render();
        attract_sound_dispatch();
        return;
    }

    *(int *)0x0607EBCC = 1;         /* reset countdown */
    GAME_STATE = 0x10;               /* transition to next state */
    *(int *)0x06078636 = 1;         /* enable camera system */
}
void FUN_0601228a(void) __attribute__((alias("camera_phase_dispatch")));

/* camera_fov_interpolate -- Animate camera FOV and far-plane during intro.
 * Camera params array at 0x060788B4: [0]=unused, [1]=FOV, [2]=far_plane.
 * Each frame: FOV shrinks by 0x2999 (min 0x20000 = 2.0 fixed-point),
 * far-plane shrinks by 0x4000 (min 0x4CCCC = 4.8 fixed-point).
 * Camera heading rotates 0x1800 per frame (~33 degrees). */
void camera_fov_interpolate(void)
{
    volatile int *cam = (volatile int *)0x060788B4;

    cam[1] -= 0x2999;
    cam[2] -= 0x4000;
    if (cam[1] < 0x20000)
        cam[1] = 0x20000;
    if (cam[2] < 0x4CCCC)
        cam[2] = 0x4CCCC;

    *(short *)0x060788B2 += 0x1800;
}
void FUN_060122f4(void) __attribute__((alias("camera_fov_interpolate")));

/* camera_vibration_apply -- Apply sinusoidal vibration to the 4×3 view matrix.
 * Computes 3 frequency offsets from half-heading, perturbs 4 matrix rows
 * at 0x060788C0..E4 (view frustum corners). Row 2 Y uses CD time delta. */
void camera_vibration_apply(void)
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
/* FUN_06012344 -- original binary (188 bytes) */
__asm__(
    ".section .text.FUN_06012344, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_06012344\n"
    ".type _FUN_06012344, @function\n"
    "_FUN_06012344:\n"
    ".byte 0x2F, 0xE6, 0xE3, 0x00, 0x2F, 0xD6, 0x2F, 0xC6, 0x2F, 0xB6, 0x4F, 0x22, 0xDC, 0x24, 0xDB, 0x25\n"  /* 0x06012344 */
    ".byte 0x95, 0x43, 0x6C, 0xC2, 0x33, 0xC7, 0x3C, 0x3E, 0x4C, 0x21, 0x4C, 0x28, 0x4B, 0x0B, 0x64, 0xC3\n"  /* 0x06012354 */
    ".byte 0x6D, 0x03, 0x95, 0x3B, 0x4B, 0x0B, 0x64, 0xC3, 0x6E, 0x03, 0x95, 0x38, 0x4B, 0x0B, 0x64, 0xC3\n"  /* 0x06012364 */
    ".byte 0x64, 0x03, 0x65, 0xD3, 0xD6, 0x1C, 0x61, 0x43, 0x45, 0x00, 0x62, 0x62, 0x32, 0x58, 0x26, 0x22\n"  /* 0x06012374 */
    ".byte 0x53, 0x61, 0x33, 0xEC, 0x16, 0x31, 0x52, 0x62, 0x32, 0x4C, 0x16, 0x22, 0xD6, 0x17, 0x63, 0x62\n"  /* 0x06012384 */
    ".byte 0x33, 0xE8, 0x26, 0x32, 0x52, 0x61, 0x32, 0xD8, 0x16, 0x21, 0x53, 0x62, 0x33, 0xD8, 0x16, 0x32\n"  /* 0x06012394 */
    ".byte 0xD6, 0x13, 0x62, 0x62, 0x32, 0x5C, 0x26, 0x22, 0xD3, 0x12, 0x43, 0x0B, 0xE0, 0x04, 0x52, 0x61\n"  /* 0x060123A4 */
    ".byte 0x32, 0x08, 0x16, 0x21, 0x53, 0x62, 0x33, 0x48, 0x16, 0x32, 0xD5, 0x0F, 0x62, 0x52, 0x32, 0xEC\n"  /* 0x060123B4 */
    ".byte 0x25, 0x22, 0x53, 0x51, 0x33, 0xEC, 0x15, 0x31, 0x52, 0x52, 0x32, 0x4C, 0x15, 0x22, 0x4F, 0x26\n"  /* 0x060123C4 */
    ".byte 0x6B, 0xF6, 0x6C, 0xF6, 0x6D, 0xF6, 0x00, 0x0B, 0x6E, 0xF6, 0x07, 0xAE, 0x17, 0x0A, 0x26, 0x66\n"  /* 0x060123D4 */
    ".byte 0x06, 0x07, 0x88, 0xAC, 0x06, 0x02, 0x75, 0x52, 0x06, 0x07, 0x88, 0xC0, 0x06, 0x07, 0x88, 0xCC\n"  /* 0x060123E4 */
    ".byte 0x06, 0x07, 0x88, 0xD8, 0x06, 0x03, 0x4F, 0xE0, 0x06, 0x07, 0x88, 0xE4\n"  /* 0x060123F4 */
);

/* background_render_pipeline -- Full background rendering pipeline.
 * Sets camera from view params, applies extra tilt if countdown > 99,
 * renders mesh/texture for last car slot, then finalizes. */
void background_render_pipeline(void)
{
    int idx;

    (*(int(*)())0x06026DBC)();   /* matrix_push */
    (*(int(*)())0x06026E0C)();   /* matrix_identity */
    (*(int(*)())0x06026E2E)(*(int *)0x060788B4, *(int *)0x060788B8, *(int *)0x060788BC);
    (*(int(*)())0x06026F2A)((int)*(short *)0x060788B2);  /* rotate_heading */
    (*(int(*)())0x06026EDE)(0);  /* rotate_y(0) */
    (*(int(*)())0x06026E94)(0);  /* rotate_x(0) */
    if (STATE_COUNTDOWN > 99)
        (*(int(*)())0x06026E94)((int)DAT_06012586);      /* extra tilt */

    idx = (CAR_COUNT - 1) << 2;
    (*(int(*)())0x06031D8C)(*(int *)(0x0606354C + idx), *(int *)0x06063558);    /* mesh_submit */
    (*(int(*)())0x06031A28)(*(int *)(0x06063544 + idx),
                 (int)*(short *)0x06089EA0, *(int *)0x06063554);                /* texture_submit */
    (*(int(*)())0x06026DF8)();   /* matrix_pop */
}
void FUN_0601250c(void) __attribute__((alias("background_render_pipeline")));

/* camera_sweep_render -- Render background with camera sweep and heading interpolation.
 * Sets up matrix from camera params, renders sky dome, interpolates
 * heading toward target angle, then renders mesh/texture for last car slot. */
void camera_sweep_render()
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
void FUN_060125d0() __attribute__((alias("camera_sweep_render")));

/* attract_sound_dispatch -- Play countdown voice cues at specific thresholds.
 *   40: "5" + engine sfx, 60: "4", 80: "3", 100: "2" + enable camera.
 *   After thresholds, if countdown > 110 and CD idle, play start jingle. */
void attract_sound_dispatch()
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
void FUN_06012710() __attribute__((alias("attract_sound_dispatch")));

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
 * Retries BIOS read up to 5 times, then validates checksum. */
void save_validate_retry()
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
void FUN_06012b58() __attribute__((alias("save_validate_retry")));

/* save_screen_display -- Render "NOW SAVING" overlay, poll BIOS for
 *   completion, then validate saved data. */
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
  save_validate_retry();                        /* validate saved data */
  return;
}

/* bg_tilemap_load -- Load background tilemap for a course.
 * Selects tilemap descriptor by course index, loads to VDP2 VRAM 0x200000. */
void bg_tilemap_load(int param_1)
{
    if (param_1 == 1)
        FUN_06012c3c(0x060448E8, 0x00200000);
    else if (param_1 == 2)
        FUN_06012c3c(0x060448F4, 0x00200000);
    else
        FUN_06012c3c(0x06044900, 0x00200000);
}
void FUN_06012d7c(int param_1) __attribute__((alias("bg_tilemap_load")));

/* bg_tilemap_and_pattern_load -- Load background tilemap + pattern pair.
 * Loads tilemap to VDP2 VRAM 0x200000 and pattern to 0x240000. */
void bg_tilemap_and_pattern_load(int param_1)
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
#if 0 /* FUN_06012DB4 -- replaced by ASM import of original bytes */
void FUN_06012db4(int param_1) __attribute__((alias("bg_tilemap_and_pattern_load")));
#endif

/* bg_pattern_load -- Load background pattern data for a course.
 * Selects pattern descriptor by course index, loads to VDP2 VRAM 0x2A8000. */
void bg_pattern_load(int param_1)
{
    if (param_1 == 1)
        FUN_06012c3c(0x0604496C, 0x002A8000);
    else if (param_1 == 2)
        FUN_06012c3c(0x06044978, 0x002A8000);
    else
        FUN_06012c3c(0x06044984, 0x002A8000);
}
void FUN_06012e08(int param_1) __attribute__((alias("bg_pattern_load")));

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
void hud_render_frame(void)
{
    (*(int(*)())(*(int *)(0x0605B6B8 + (unsigned int)(unsigned char)*(int *)(0x06084AF2 << 2))))();
    (*(int(*)())0x06011AF4)(0, 0x00960000, 0x00010000, 0x00010000, 0x00008000, 0x00010000, 0);
    (*(int(*)())0x060078DC)();  /* frame_end_display_commit */
}
#if 0 /* FUN_0601389E -- replaced by ASM import of original bytes */
void FUN_0601389e(void) __attribute__((alias("hud_render_frame")));

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
#endif

/* background_rotation_wobble -- Apply periodic rotation to background.
 * Uses low 5 bits of FRAME_COUNTER, applies rotation when phase > 16. */
void background_rotation_wobble(void)
{
    unsigned short phase = (unsigned short)FRAME_COUNTER & 0x1F;
    if (phase > 0x10) {
        (*(int(*)())0x06026EDE)((int)(short)(phase << 12));  /* heading_rotation */
    }
}
void FUN_06013e12(void) __attribute__((alias("background_rotation_wobble")));

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

/* --- FUN_060127E0 (L1 import from src/FUN_060127E0.c) --- */

int FUN_060127e0()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  char *puVar6;

  char *puVar7;

  int iVar8;

  int iVar9;

  int *puVar10;

  int iVar11;

  int *local_24;

  puVar1 = (char *)0x060788F8;

  *(int *)0x0605B714 = *(int *)0x060788F8;

  *(unsigned int *)0x0605B6D8 = *(unsigned int *)0x0605B6D8 | 0x80;

  *(char **)puVar1 = 0x0004CCCC + *(int *)puVar1;

  puVar7 = (char *)0x060284AE;

  puVar6 = (char *)0x060788F4;

  puVar5 = (char *)0x06063750;

  puVar4 = (char *)0x06028400;

  puVar3 = (char *)0x0605ACDD;

  puVar2 = (char *)0x0601D5F4;

  puVar1 = (char *)0x060283E0;

  iVar9 = *(int *)(*(int *)0x0607E944 + (int)DAT_06012884);

  iVar11 = 0x90;

  iVar8 = *(int *)0x060788F4;

  if (iVar8 == 0) {

    (*(int(*)())0x06028400)(0xc,*(int *)(0x06063750 + DAT_06012888),0x880,

               *(int *)((int)(0x06063750 + DAT_06012888) + 4));

    iVar9 = (*(int(*)())puVar4)(0xc,*(int *)(puVar5 + DAT_0601288c),(int)DAT_0601288e,

                              *(int *)((int)(puVar5 + DAT_0601288c) + 4));

    *(int *)puVar6 = *(int *)puVar6 + 1;

  }

  else if (iVar8 == 1) {

    if (iVar9 == 0x52) {

      *(int *)0x060788F4 = *(int *)0x060788F4 + 1;

      (*(int(*)())puVar1)(8,(int)DAT_0601299e,0x0000F000,puVar3);

      (*(int(*)())puVar1)(8,(int)DAT_060129a0,0x0000F000,puVar3);

      (*(int(*)())puVar1)(8,(int)DAT_060129a2,0x0000F000,puVar3);

      (*(int(*)())puVar4)(8,*(int *)(puVar5 + 0x78),(int)DAT_060129a6,

                        *(int *)(puVar5 + 0x7c) + (int)DAT_060129a4);

      iVar9 = (*(int(*)())puVar2)(0,0xAE1122FF);

    }

    else {

      if (((*(unsigned short *)0x06063D98 & *(unsigned short *)0x0608188C) == 0) &&

         (*(short *)0x0607ED8C == 0)) {

        local_24 = (int *)(0x06063750 + DAT_0601299a);

        iVar9 = local_24[1] + (int)DAT_0601299c;

      }

      else {

        local_24 = (int *)(0x06063750 + iVar11);

        iVar9 = local_24[1] + (int)DAT_06012890;

      }

      iVar9 = (*(int(*)())0x06028400)(8,*local_24,(int)DAT_0601299e,iVar9);

    }

  }

  else if (iVar8 == 2) {

    if (iVar9 == 0x58) {

      puVar10 = (int *)(0x06063750 + 0x70);

      *(int *)0x060788F4 = *(int *)0x060788F4 + 1;

      (*(int(*)())puVar4)(8,*puVar10,(int)DAT_060129a6,*(int *)(puVar5 + 0x74) + (int)DAT_060129a4);

      *(int *)0x06078654 = 1;

      *(int *)0x06063EF0 = *(int *)(*(int *)0x0607E944 + 0x30);

      iVar9 = (*(int(*)())puVar2)(0,0xAE1123FF);

    }

  }

  else if (iVar8 == 3) {

    if (iVar9 == 0x5d) {

      puVar10 = (int *)(0x06063750 + 0x68);

      *(int *)0x060788F4 = *(int *)0x060788F4 + 1;

      (*(int(*)())puVar4)(8,*puVar10,(int)DAT_060129a6,*(int *)(puVar5 + 0x6c) + (int)DAT_060129a4);

      iVar9 = (*(int(*)())puVar2)(0,0xAE1124FF);

    }

  }

  else if (iVar8 == 4) {

    if (iVar9 == 0x61) {

      *(int *)0x060788F4 = *(int *)0x060788F4 + 1;

      (*(int(*)())puVar4)(8,*(int *)(puVar5 + DAT_06012a92),0x520,

                        *(int *)((int)(puVar5 + DAT_06012a92) + 4) + (int)DAT_06012a94);

      iVar9 = (*(int(*)())puVar2)(0,0xAE1125FF);

      *(short *)0x06086056 = 0x14;

      *(int *)0x0608605A = 1;

    }

  }

  else if (iVar8 == 0x13) {

    (*(int(*)())0x060284AE)(8,0x520,iVar11,0x0605ACDD);

    (*(int(*)())puVar7)(8,0x620,iVar11,puVar3);

    (*(int(*)())puVar7)(8,0x720,iVar11,puVar3);

    (*(int(*)())puVar1)(8,0x820,0x0000F000,puVar3);

    (*(int(*)())puVar7)(0xc,0x880,iVar11,0x0605AC9C);

    iVar9 = (*(int(*)())puVar7)(0xc,0x980,iVar11,0x0605AC9C);

    *(int *)0x0605B714 = 0;

    *(int *)0x06078636 = 0;

  }

  else {

    *(int *)0x060788F4 = *(int *)0x060788F4 + 1;

    iVar9 = iVar8;

  }

  return iVar9;

}

/* --- FUN_06012CF4 (L1 import from src/FUN_06012CF4.c) --- */

void FUN_06012cf4()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  int iVar4;

  int in_r7;

  int iVar5;

  int uVar6;

  puVar2 = (char *)0x0600026C;

  puVar1 = (char *)0x0603AC1C;

  uVar6 = 0xffffffff;

  iVar5 = 0;

  *(int *)0x06084AEC = 0;

  puVar3 = (char *)0x06084360;

  *(int *)0x06084360 = 1;

  *(char **)(puVar3 + 8) = 0x0608436C;

  *(int *)(puVar3 + 4) = 0x50;

  puVar3 = (char *)0x06083274;

  do {

    iVar4 = (*(int(*)())puVar1)(5,puVar3,0x06084360,in_r7,uVar6);

    iVar5 = iVar5 + 1;

    if (4 < iVar5) {

      (*(int(*)())(*(int *)puVar2))();

    }

  } while (iVar4 < 3);

  return;

}

/* --- FUN_06012E6A (L1 import from src/FUN_06012E6A.c) --- */

void FUN_06012e6a()
{

  FUN_06012c3c(0x0604499C,0x002F0000);

  FUN_06012c3c(0x060449A8,0x060F8000);

  return;

}

/* --- FUN_06012F80 (L1 import from src/FUN_06012F80.c) --- */

void FUN_06012f80()
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

  *(int *)0x0605A008 = 0;

  **(short **)0x06063F5C = (short)0x00008000;

  puVar1 = (char *)0x0602853E;

  (*(int(*)())0x0602853E)(0);

  (*(int(*)())puVar1)(4);

  (*(int(*)())puVar1)(8);

  (*(int(*)())puVar1)(0xc);

  (*(int(*)())(*(int *)0x06000344))(0xffffffff,0x83);

  (*(int(*)())0x06012E00)();

  (*(int(*)())(*(int *)0x06000344))(-132,0);

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

  iVar5 = *(int *)0x0607EAD8;

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

/* --- FUN_06013E3C (L1 import from src/FUN_06013E3C.c) --- */

int FUN_06013e3c()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  int iVar6;

  int uVar7;

  int uVar8;

  int iVar9;

  int *piVar10;

  int iVar11;

  int *piVar12;

  puVar4 = (char *)0x00010000;

  puVar3 = (char *)0x06084AF6;

  puVar2 = (char *)0x06027552;

  puVar1 = (char *)0x06026F2A;

  (*(int(*)())0x06026E0C)();

  puVar5 = (char *)0x06089E4A;

  iVar11 = 0;

  piVar10 = (int *)(0x0605AD5C + DAT_06013f46);

  piVar12 = (int *)0x0605AD5C;

  do {

    (*(int(*)())0x06026DBC)();

    iVar6 = (*(int(*)())puVar2)((unsigned int)*(unsigned short *)puVar3 * (int)puVar4,(int)DAT_06013f48,puVar4);

    (*(int(*)())0x06026E2E)(0,DAT_06013f4a + iVar6,puVar4);

    (*(int(*)())puVar1)((int)*(short *)(piVar12 + 6));

    uVar7 = (*(int(*)())puVar2)(piVar12[1],(unsigned int)*(unsigned short *)puVar3 * (int)puVar4);

    iVar6 = (*(int(*)())puVar2)(piVar12[2],(unsigned int)*(unsigned short *)puVar3 * (int)puVar4);

    iVar9 = *piVar12;

    uVar8 = (*(int(*)())puVar2)(piVar12[3],(unsigned int)*(unsigned short *)puVar3 * (int)puVar4);

    (*(int(*)())0x06026E2E)(uVar7,iVar9 - iVar6,uVar8);

    (*(int(*)())puVar1)(-(int)*(short *)(piVar12 + 6));

    (*(int(*)())0x06026E94)((int)*(short *)((int)piVar12 + 0x1a) * (unsigned int)*(unsigned short *)puVar3);

    (*(int(*)())0x06026EDE)((int)*(short *)(piVar12 + 7) * (unsigned int)*(unsigned short *)puVar3);

    (*(int(*)())puVar1)((int)*(short *)((int)piVar12 + 0x1e) * (unsigned int)*(unsigned short *)puVar3);

    iVar6 = (*(int(*)())puVar2)(piVar12[4],(unsigned int)*(unsigned short *)puVar3 * (int)puVar4);

    iVar6 = DAT_06013f4c + iVar6;

    (*(int(*)())0x06026E60)(iVar6,iVar6,iVar6);

    (*(int(*)())0x06031D8C)(*(int *)(0x06062338 + iVar11),4);

    uVar7 = (*(int(*)())0x06031A28)(*(int *)(0x060622C0 + iVar11),(int)*(short *)puVar5,1);

    piVar12 = piVar12 + 8;

    *(int *)0x06089EDC = *(int *)0x06089EDC + -0x30;

    iVar11 = iVar11 + 4;

  } while (piVar12 < piVar10);

  return uVar7;

}

/* --- FUN_06013FC4 (L1 import from src/FUN_06013FC4.c) --- */

void FUN_06013fc4()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  int iVar6;

  int *puVar7;

  int iVar8;

  int *puVar9;

  puVar4 = (char *)0x00010000;

  puVar3 = (char *)0x06026E2E;

  puVar2 = (char *)0x06089EDC;

  puVar1 = (char *)0x06026F2A;

  (*(int(*)())0x06026E0C)();

  puVar5 = (char *)0x06089E4A;

  iVar8 = 0;

  puVar7 = (int *)(0x0605AD5C + DAT_06014080);

  puVar9 = (int *)0x0605AD5C;

  do {

    (*(int(*)())0x06026DBC)();

    (*(int(*)())puVar3)(0,(int)DAT_06014082,puVar4);

    (*(int(*)())puVar1)((int)*(short *)(puVar9 + 6));

    (*(int(*)())puVar3)(0,*puVar9);

    (*(int(*)())puVar1)(-(int)*(short *)(puVar9 + 6));

    iVar6 = (*(int(*)())0x06027552)((int)DAT_06014084,(unsigned int)*(unsigned short *)0x06084AF6 * (int)puVar4);

    iVar6 = DAT_06014086 + iVar6;

    (*(int(*)())0x06026E60)(iVar6,iVar6,iVar6);

    (*(int(*)())0x06031D8C)(*(int *)(0x06062338 + iVar8),4);

    (*(int(*)())0x06031A28)(*(int *)(0x060622C0 + iVar8),(int)*(short *)puVar5,1);

    puVar9 = puVar9 + 8;

    *(int *)puVar2 = *(int *)puVar2 + -0x30;

    iVar8 = iVar8 + 4;

  } while (puVar9 < puVar7);

  return;

}

/* FUN_06012DB4 -- original binary (84 bytes) */
__asm__(
    ".section .text.FUN_06012DB4, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_06012DB4\n"
    ".type _FUN_06012DB4, @function\n"
    "_FUN_06012DB4:\n"
    ".byte 0x2F, 0xE6, 0x60, 0x43, 0x2F, 0xD6, 0x4F, 0x22, 0xDD, 0x17, 0xDE, 0x18, 0x88, 0x01, 0x8B, 0x08\n"  /* 0x06012DB4 */
    ".byte 0xD4, 0x17, 0xBF, 0x39, 0x65, 0xD3, 0x65, 0xE3, 0xD4, 0x16, 0x4F, 0x26, 0x6D, 0xF6, 0xAF, 0x33\n"  /* 0x06012DC4 */
    ".byte 0x6E, 0xF6, 0x60, 0x43, 0x88, 0x02, 0x8B, 0x08, 0xD4, 0x13, 0xBF, 0x2D, 0x65, 0xD3, 0x65, 0xE3\n"  /* 0x06012DD4 */
    ".byte 0xD4, 0x12, 0x4F, 0x26, 0x6D, 0xF6, 0xAF, 0x27, 0x6E, 0xF6, 0xD4, 0x11, 0xBF, 0x24, 0x65, 0xD3\n"  /* 0x06012DE4 */
    ".byte 0x65, 0xE3, 0xD4, 0x10, 0x4F, 0x26, 0x6D, 0xF6, 0xAF, 0x1E, 0x6E, 0xF6, 0xD5, 0x0E, 0xD4, 0x0F\n"  /* 0x06012DF4 */
    ".byte 0xAF, 0x1A, 0x00, 0x09\n"  /* 0x06012E04 */
);
