#include "game.h"

extern int DAT_0601c510;
extern int DAT_0601c5f8;
extern int DAT_0601c5fa;
extern int DAT_0601c6c0;
extern int DAT_0601c77c;
extern int DAT_0601c844;
extern int DAT_0601c93c;
extern int DAT_0601c93e;
extern int DAT_0601c940;
extern int DAT_0601ca3a;
extern int DAT_0601ca3c;
extern int DAT_0601ca3e;
extern int DAT_0601cb48;
extern int DAT_0601d056;
extern int DAT_0601d0f2;
extern int DAT_0601d18c;
extern int DAT_0601d18e;
extern int DAT_0601d24c;
extern int DAT_0601d24e;
extern int DAT_0601d2c6;
extern int DAT_0601d36a;
extern int DAT_0601d36c;
extern int DAT_0601d444;
extern int DAT_0601d446;
extern int DAT_0601d974;
extern int DAT_0601d976;
extern int DAT_0601dd30;
extern int DAT_0601dd34;
extern int DAT_0601dd38;
extern int DAT_0601dd3a;
extern int DAT_0601de24;
extern int DAT_0601de26;
extern int DAT_0601df14;
extern int DAT_0601df16;
extern int DAT_0601df18;
extern int DAT_0601df1a;
extern int DAT_0601df1c;
extern int DAT_0601df1e;
extern int DAT_0601df7a;
extern int DAT_0601e022;
extern int DAT_0601e024;
extern int DAT_0601e026;
extern int DAT_0601e028;
extern int DAT_0601e02a;
extern int DAT_0601e02c;
extern int DAT_0601e02e;
extern int DAT_0601e0e2;
extern int DAT_0601e0e4;
extern int DAT_0601e0e6;
extern void FUN_0601cdc0();
extern void FUN_0601cefc();
extern void FUN_0601d014();
extern void FUN_0601d074();
extern int FUN_0601d0bc();
extern void FUN_0601d12c();
extern int scsp_command_dispatch();
extern int FUN_0601db84();
extern int FUN_0601ddf6();
extern int FUN_0601e26c();
extern int PTR_DAT_0601ca40;
extern int PTR_DAT_0601d250;
extern int PTR_DAT_0601d2c8;
extern int PTR_DAT_0601d884;
extern int PTR_DAT_0601da3c;
extern int PTR_DAT_0601df20;
extern int PTR_DAT_0601e030;

/* tire_skid_particle_render -- Render tire smoke/skid effects for 4 wheels.
 * Checks car state flags at CAR_PTR_TARGET+2/+3 for skid triggers:
 *   byte+3 bit 0x40 = front-left, bit 0x80 = front-right
 *   byte+2 bit 0x01 = rear-left, bit 0x02 = rear-right
 * Each wheel has an 8-frame timer at 0x0605DF4E/50/52/54 that counts down.
 * Priority order: FL > FR > RL > RR (only one rendered per frame).
 * Each effect uses matrix pipeline: reset (0x06027080), translate (0x060270F2),
 * rotate (0x060271A2), then renders 3D model via 0x06032158/0x06031DF4.
 * Animation cycles through 3 frames (mod 3) at 0x0605DF56/57.
 * In 2-player mode (both 0x06063E1C/20 == 1), uses different depth scale.
 * Also renders steering indicator when car has lateral velocity
 * (offsets at DAT_0601c93c/93e), position from 0x06044670.
 * Sprite budget at 0x0608A52C decremented by 0x30 per effect. */
int tire_skid_particle_render()
{
  char *steer_anim_ptr;
  char *depth_scale;
  char *sprite_budget;
  char *anim_frame_ptr;
  char *anim_alt_ptr;
  int result;
  int model_idx;
  int car_ptr;
  anim_alt_ptr = (char *)0x0605DF56;                        /* rear wheel anim frame */
  anim_frame_ptr = (char *)0x0605DF57;                      /* front wheel anim frame */
  sprite_budget = (char *)0x0608A52C;                       /* sprite budget counter */
  depth_scale = (char *)0x00008000;                         /* fixed-point 0.5 */
  steer_anim_ptr = (char *)0x0605DF44;                      /* steering indicator frame */
  car_ptr = CAR_PTR_TARGET;
  if ((*(int *)0x06063E1C == 0) || (*(int *)0x06063E20 == 0)) {
    /* no players active — consume 4 random seeds */
    (*(int(*)())0x06034F78)();                               /* random_next */
    (*(int(*)())0x06034F78)();
    (*(int(*)())0x06034F78)();
    result = (*(int(*)())0x06034F78)();
  }
  else {
    /* check each wheel's skid flag, set 8-frame timer */
    if ((*(unsigned char *)(car_ptr + 3) & 0x40) != 0) {
      *(short *)0x0605DF4E = 8;                              /* FL skid timer */
      (*(int(*)())0x06034F78)();                             /* random_next */
    }
    if (((int)*(char *)(car_ptr + 3) & 0x80U) != 0) {
      *(short *)0x0605DF50 = 8;                              /* FR skid timer */
      (*(int(*)())0x06034F78)();
    }
    if ((*(unsigned char *)(car_ptr + 2) & 1) != 0) {
      *(short *)0x0605DF52 = 8;                              /* RL skid timer */
      (*(int(*)())0x06034F78)();
    }
    if ((*(unsigned char *)(car_ptr + 2) & 2) != 0) {
      *(short *)0x0605DF54 = 8;                              /* RR skid timer */
      (*(int(*)())0x06034F78)();
    }
    /* render highest-priority active effect (FL > FR > RL > RR) */
    if (*(short *)0x0605DF4E == 0) {
      if (*(short *)0x0605DF50 == 0) {
        if (*(short *)0x0605DF52 == 0) {
          if (*(short *)0x0605DF54 != 0) {
            /* rear-right skid effect */
            (*(int(*)())0x06027080)();                       /* matrix_reset */
            (*(int(*)())0x060270F2)(0xFFFE9DF4,depth_scale,0x00013333);  /* translate: RR position */
            (*(int(*)())0x060271A2)((int)DAT_0601c844);      /* rotate: RR angle */
            model_idx = ((unsigned char)*anim_frame_ptr + 0x12) << 2;
            (*(int(*)())0x06032158)(*(int *)(0x0606212C + model_idx),  /* model_set_texture */
                       *(int *)(0x060621D8 + model_idx));
            model_idx = ((unsigned char)*anim_frame_ptr + 0x12) << 2;
            (*(int(*)())0x06031DF4)(*(int *)(0x060620D8 + model_idx),*(short *)0x06089E9C,  /* model_render */
                       *(int *)(0x06062180 + model_idx));
            *(int *)sprite_budget = *(int *)sprite_budget + -0x30;
            *anim_frame_ptr = *anim_frame_ptr + '\x01';
            if (2 < (unsigned char)*anim_frame_ptr) {
              *anim_frame_ptr = 0;                           /* wrap anim frame (mod 3) */
            }
            *(short *)0x0605DF54 = *(short *)0x0605DF54 + -1;
          }
        }
        else {
          /* rear-left skid effect */
          (*(int(*)())0x06027080)();                         /* matrix_reset */
          (*(int(*)())0x060270F2)(0x0001620C,depth_scale,0x00013333);  /* translate: RL position */
          (*(int(*)())0x060271A2)((int)DAT_0601c77c);        /* rotate: RL angle */
          model_idx = ((unsigned char)*anim_alt_ptr + 0x12) << 2;
          (*(int(*)())0x06032158)(*(int *)(0x0606212C + model_idx),
                     *(int *)(0x060621D8 + model_idx));
          model_idx = ((unsigned char)*anim_alt_ptr + 0x12) << 2;
          (*(int(*)())0x06031DF4)(*(int *)(0x060620D8 + model_idx),*(short *)0x06089E9C,
                     *(int *)(0x06062180 + model_idx));
          *(int *)sprite_budget = *(int *)sprite_budget + -0x30;
          *anim_alt_ptr = *anim_alt_ptr + '\x01';
          if (2 < (unsigned char)*anim_alt_ptr) {
            *anim_alt_ptr = 0;
          }
          *(short *)0x0605DF52 = *(short *)0x0605DF52 + -1;
        }
      }
      else {
        /* front-right skid effect */
        (*(int(*)())0x06027080)();                           /* matrix_reset */
        if ((*(int *)0x06063E1C == 1) && (*(int *)0x06063E20 == 1)) {
          (*(int(*)())0x060270F2)(0xFFFEB78E,depth_scale,0xFFFE4000);  /* 2P mode: deeper Z */
          (*(int(*)())0x06027124)((int)DAT_0601c5fa,(int)DAT_0601c5fa);  /* scale for 2P */
        }
        else {
          (*(int(*)())0x060270F2)(0xFFFEB78E,depth_scale,0xFFFF0000);  /* 1P mode */
        }
        (*(int(*)())0x060271A2)((int)DAT_0601c6c0);          /* rotate: FR angle */
        model_idx = ((unsigned char)*anim_frame_ptr + 0x12) << 2;
        (*(int(*)())0x06032158)(*(int *)(0x0606212C + model_idx),
                   *(int *)(0x060621D8 + model_idx));
        model_idx = ((unsigned char)*anim_frame_ptr + 0x12) << 2;
        (*(int(*)())0x06031DF4)(*(int *)(0x060620D8 + model_idx),*(short *)0x06089E9C,
                   *(int *)(0x06062180 + model_idx));
        *(int *)sprite_budget = *(int *)sprite_budget + -0x30;
        *anim_frame_ptr = *anim_frame_ptr + '\x01';
        if (2 < (unsigned char)*anim_frame_ptr) {
          *anim_frame_ptr = 0;
        }
        *(short *)0x0605DF50 = *(short *)0x0605DF50 + -1;
      }
    }
    else {
      /* front-left skid effect (highest priority) */
      (*(int(*)())0x06027080)();                             /* matrix_reset */
      if ((*(int *)0x06063E1C == 1) && (*(int *)0x06063E20 == 1)) {
        (*(int(*)())0x060270F2)(0x00014872,depth_scale,0xFFFE4000);  /* 2P mode */
        (*(int(*)())0x06027124)((int)DAT_0601c510,(int)DAT_0601c510);  /* scale for 2P */
      }
      else {
        (*(int(*)())0x060270F2)(0x00014872,depth_scale,0xFFFF0000);  /* 1P mode */
      }
      (*(int(*)())0x060271A2)((int)DAT_0601c5f8);            /* rotate: FL angle */
      model_idx = ((unsigned char)*anim_alt_ptr + 0x12) << 2;
      (*(int(*)())0x06032158)(*(int *)(0x0606212C + model_idx),*(int *)(0x060621D8 + model_idx));
      model_idx = ((unsigned char)*anim_alt_ptr + 0x12) << 2;
      (*(int(*)())0x06031DF4)(*(int *)(0x060620D8 + model_idx),*(short *)0x06089E9C,
                 *(int *)(0x06062180 + model_idx));
      *(int *)sprite_budget = *(int *)sprite_budget + -0x30;
      *anim_alt_ptr = *anim_alt_ptr + '\x01';
      if (2 < (unsigned char)*anim_alt_ptr) {
        *anim_alt_ptr = 0;
      }
      *(short *)0x0605DF4E = *(short *)0x0605DF4E + -1;
    }
    /* steering/wheel alignment indicator */
    if (*(int *)0x06059F30 == 0) {
      result = 0;
    }
    else {
      if ((*(short *)(car_ptr + DAT_0601c93c) == 0) && (*(short *)(car_ptr + DAT_0601c93e) == 0)) {
        *(short *)steer_anim_ptr = 0;                        /* reset steer anim when no lateral vel */
      }
      if ((*(short *)(car_ptr + DAT_0601c93c) != 0) ||
         (result = 0, *(short *)(car_ptr + DAT_0601c93e) != 0)) {
        (*(int(*)())0x06027080)();                           /* matrix_reset */
        (*(int(*)())0x060270F2)(*(int *)0x06044670,          /* steer indicator position X */
                   *(int *)(0x06044670 + 4) + -13107,        /* position Y - offset */
                   0xFFFF6000 - *(int *)(0x06044670 + 8));   /* position Z (behind car) */
        (*(int(*)())0x060271A2)(depth_scale);                /* rotate */
        car_ptr = (*(short *)(0x0605DF46 + *(short *)((int)(int)steer_anim_ptr << 1)) + 0xe) << 2;
        (*(int(*)())0x06032158)(*(int *)(0x0606212C + car_ptr),  /* model_set_texture */
                   *(int *)(0x060621D8 + car_ptr));
        car_ptr = (*(short *)(0x0605DF46 + *(short *)((int)(int)steer_anim_ptr << 1)) + 0xe) << 2;
        result = (*(int(*)())0x06031DF4)(*(int *)(0x060620D8 + car_ptr),*(short *)0x06089E9C  /* model_render */
                           ,*(int *)(0x06062180 + car_ptr));
        *(int *)sprite_budget = *(int *)sprite_budget + -0x30;
        *(short *)steer_anim_ptr = *(short *)steer_anim_ptr + 1;
        if (3 < *(short *)steer_anim_ptr) {
          *(short *)steer_anim_ptr = 0;                      /* wrap steer anim (mod 4) */
        }
      }
    }
  }
  return result;
}

/* results_screen_init -- Initialize results/record display screen.
 * Clears display counters (0x0608602C, 0x06086030), sets initial
 * palette color (DAT_0601ca3a), calls HUD setup (0x060149E0) and
 * VDP sync (0x06026CE0). Fills VDP2 CRAM banks A (0x25F00200) and
 * B (0x25F00400) with base color. Loads race palette from 0x0604880C,
 * two tile banks via CD (0x0600511E), two VDP1 sprite overlays.
 * Configures 5 CD audio channels (0x06038BD4), enables palette
 * interrupt (0x06036E90), sets INPUT_STATE display flag, re-syncs VDP. */
void FUN_0601c978()
{
  int count;
  short *cram_ptr;
  short *next;

  *(int *)0x0608602C = 0;                               /* clear display counter A */
  *(int *)0x06086030 = 0;                               /* clear display counter B */
  *(short *)0x06086028 = DAT_0601ca3a;                  /* base palette color */
  (*(int(*)())0x060149E0)();                             /* HUD layout setup */
  (*(int(*)())0x060148FC)();                             /* HUD state reset */
  (*(int(*)())0x06026CE0)();                             /* VDP vsync */
  VBLANK_OUT_COUNTER = 0;
  (*(int(*)())0x0600A026)();                             /* timing reset */
  *(int *)0x0608601C = (int)DAT_0601ca3c;               /* display mode */
  *(int *)0x06086020 = 0;                               /* fade step counter */
  *(int *)0x06086024 = 0;                               /* animation counter */
  /* fill VDP2 CRAM bank A (0x25F00200) with base color */
  count = 0x20;
  cram_ptr = (short *)0x25F00200;
  do {
    count = count + -2;
    *cram_ptr = *(short *)0x06086028;
    next = cram_ptr + 1;
    cram_ptr = cram_ptr + 2;
    *next = *(short *)0x06086028;
  } while (count != 0);
  /* fill VDP2 CRAM bank B (0x25F00400) with base color */
  count = 0x20;
  cram_ptr = (short *)0x25F00400;
  do {
    count = count + -2;
    *cram_ptr = *(short *)0x06086028;
    next = cram_ptr + 1;
    cram_ptr = cram_ptr + 2;
    *next = *(short *)0x06086028;
  } while (count != 0);
  (*(int(*)())0x0602766C)(0x25F00000, 0x0604880C, 0x40); /* DMA race palette */
  (*(int(*)())0x0600511E)(0x25E70E40, 0x00014000, 0, 9); /* load tile bank A from CD */
  (*(int(*)())0x0600511E)(0x25E7B168, 0x00016BC0, 0, 9); /* load tile bank B from CD */
  /* VDP1 sprite overlays for results screen */
  (*(int(*)())0x06028400)(4, *(int *)0x06063958, 0x518,
             *(int *)(0x06063958 + 4), 0x06063958);
  (*(int(*)())0x06028400)(0, *(int *)0x06063960, 0x518,
             *(int *)(0x06063960 + 4), 0x06063960);
  /* CD audio channel configuration */
  (*(int(*)())0x06038BD4)(0x100, 0);                     /* master volume */
  (*(int(*)())0x06038BD4)(4, 1);                         /* channel 1 */
  (*(int(*)())0x06038BD4)(8, 2);                         /* channel 2 */
  (*(int(*)())0x06038BD4)(0x10, 0);                      /* channel 3 */
  (*(int(*)())0x06038BD4)(0x20, 0);                      /* channel 4 */
  (*(int(*)())0x06036E90)(0x25F00FFE, 1, 0x06086028);    /* palette interrupt enable */
  INPUT_STATE = INPUT_STATE | 0x40000000;                /* set display active flag */
  (*(int(*)())0x06026CE0)();                             /* VDP vsync */
  VBLANK_OUT_COUNTER = 0;
}

/* results_screen_update -- Update results screen with save data and palette transitions.
 * Decrements display timer at 0x0608601C each frame. On button press
 * (0x06063D98 & DAT_0601cb48), probes backup RAM for save data at
 * cascading size thresholds (0x40680000, 0x40568000) via backup_init
 * (0x060358EC) and backup_read (0x06035844). Sets transition state
 * at 0x06086024 (1=large found, 2=medium found, 3=both found).
 * Calls FUN_0601d12c for rendering, then either:
 *   - State 0: tries deeper save probes (0x40726000, 0x406D4000, etc.)
 *     with cascading fallbacks to different handlers
 *   - State 1/2/3: loads palette tables via DMA (0x0602766C) to
 *     VDP2 CRAM banks A (0x25F00200) and B (0x25F00400)
 * Ends by setting GAME_STATE=2 (return to menu), then VDP vsync. */
void results_screen_update()
{
  char *fade_step_ptr;
  char *cram_bank_a;
  char *cram_bank_b;
  char *dma_copy_fn;
  char *transition_state;
  char *display_timer;
  int save_result;
  int *save_ctx;
  int save_buf_c;
  int save_pad_c;
  char *save_desc_c[3];
  int save_buf_b;
  int save_pad_b;
  char *save_desc_b[3];
  char save_base[4];
  display_timer = (char *)0x0608601C;                       /* results display countdown */
  transition_state = (char *)0x06086024;                    /* palette transition state */
  dma_copy_fn = (char *)0x0602766C;                         /* DMA block copy */
  cram_bank_b = (char *)0x25F00400;                         /* VDP2 CRAM bank B */
  cram_bank_a = (char *)0x25F00200;                         /* VDP2 CRAM bank A */
  fade_step_ptr = (char *)0x06086020;                       /* fade step counter */
  *(int *)0x0608601C = *(int *)0x0608601C + -1;             /* decrement display timer */
  save_ctx = (int *)save_base;
  /* check for button press to trigger save probe */
  if (((*(unsigned short *)0x06063D98 & DAT_0601cb48) != 0) &&
     (save_ctx = (int *)save_base, *(int *)0x06086024 == 0)) {
    /* probe backup RAM at size 0x40680000 (large) */
    save_desc_b[0] = (char *)save_desc_b;
    (*(int(*)())0x060358EC)();                               /* backup_init */
    save_pad_b = 0;
    save_buf_b = 0x40680000;
    save_result = (*(int(*)())0x06035844)();                 /* backup_read */
    if (save_result == 0) {
      /* large save not found, try medium (0x40568000) */
      save_desc_c[0] = (char *)save_desc_c;
      (*(int(*)())0x060358EC)();                             /* backup_init */
      save_pad_c = 0;
      save_ctx = &save_buf_c;
      save_buf_c = 0x40568000;
      save_result = (*(int(*)())0x06035844)();               /* backup_read */
      if (save_result == 0) {
        *(int *)transition_state = 3;                        /* both sizes found */
      }
      else {
        *(int *)transition_state = 2;                        /* only medium found */
        save_ctx = &save_buf_c;
      }
    }
    else {
      *(int *)transition_state = 1;                          /* large found */
      save_ctx = &save_buf_b;
    }
  }
  FUN_0601d12c();                                            /* render results display */
  if (*(int *)transition_state == 0) {
    /* no button pressed — try deeper save probes with cascading sizes */
    /* probe 1: size 0x40726000 */
    *(char **)((int)save_ctx + -0xc) = (char *)((int)save_ctx + -0xc);
    (*(int(*)())0x060358EC)();                               /* backup_init */
    *(int *)((int)save_ctx + -0x10) = 0;
    *(int *)((int)save_ctx + -0x14) = 0x40726000;
    save_result = (*(int(*)())0x06035844)();                 /* backup_read */
    if (save_result != 0) goto LAB_0601cda4;
    /* probe 2: size 0x406D4000 */
    *(char **)((int)save_ctx + -0x20) = (char *)((int)save_ctx + -0x20);
    (*(int(*)())0x060358EC)();
    *(int *)((int)save_ctx + -0x24) = 0;
    *(int *)((int)save_ctx + -0x28) = 0x406D4000;
    save_result = (*(int(*)())0x06035844)();
    if (save_result != 0) {
      FUN_0601cdc0();                                        /* fallback handler A */
      goto LAB_0601cda4;
    }
    /* probe 3: verify size 0x406D4000 */
    *(char **)((int)save_ctx + -0x34) = (char *)((int)save_ctx + -0x34);
    (*(int(*)())0x060358EC)();
    *(int *)((int)save_ctx + -0x38) = 0;
    *(int *)((int)save_ctx + -0x3c) = 0x406D4000;
    save_result = (*(int(*)())0x06035B34)();                 /* backup_verify */
    if (save_result == 0) {
      *(int *)fade_step_ptr = 0;                             /* reset fade step */
    }
    /* probe 4: size 0x40680000 */
    *(char **)((int)save_ctx + -0x48) = (char *)((int)save_ctx + -0x48);
    (*(int(*)())0x060358EC)();
    *(int *)((int)save_ctx + -0x4c) = 0;
    *(int *)((int)save_ctx + -0x50) = 0x40680000;
    save_result = (*(int(*)())0x06035844)();
    if (save_result != 0) {
      FUN_0601cefc();                                        /* fallback handler B */
      goto LAB_0601cda4;
    }
    /* probe 5: verify size 0x40680000 */
    *(char **)((int)save_ctx + -0x5c) = (char *)((int)save_ctx + -0x5c);
    (*(int(*)())0x060358EC)();
    *(int *)((int)save_ctx + -0x60) = 0;
    *(int *)((int)save_ctx + -100) = 0x40680000;
    save_result = (*(int(*)())0x06035B34)();
    if (save_result == 0) {
      FUN_0601d014();                                        /* transition handler A */
      goto LAB_0601cda4;
    }
    /* probe 6: size 0x40608000 */
    *(char **)((int)save_ctx + -0x70) = (char *)((int)save_ctx + -0x70);
    (*(int(*)())0x060358EC)();
    *(int *)((int)save_ctx + -0x74) = 0;
    *(int *)((int)save_ctx + -0x78) = 0x40608000;
    save_result = (*(int(*)())0x06035844)();
    if (save_result != 0) {
      FUN_0601cdc0();                                        /* fallback handler A */
      goto LAB_0601cda4;
    }
    /* probe 7: verify size 0x40608000 */
    *(char **)((int)save_ctx + -0x84) = (char *)((int)save_ctx + -0x84);
    (*(int(*)())0x060358EC)();
    *(int *)((int)save_ctx + -0x88) = 0;
    *(int *)((int)save_ctx + -0x8c) = 0x40608000;
    save_result = (*(int(*)())0x06035B34)();
    if (save_result == 0) {
      *(int *)fade_step_ptr = 0;                             /* reset fade step */
    }
    /* probe 8: size 0x40568000 */
    *(char **)((int)save_ctx + -0x98) = (char *)((int)save_ctx + -0x98);
    (*(int(*)())0x060358EC)();
    *(int *)((int)save_ctx + -0x9c) = 0;
    *(int *)((int)save_ctx + -0xa0) = 0x40568000;
    save_result = (*(int(*)())0x06035844)();
    if (save_result != 0) {
      FUN_0601cefc();                                        /* fallback handler B */
      goto LAB_0601cda4;
    }
    /* probe 9: verify size 0x40568000 */
    *(char **)((int)save_ctx + -0xac) = (char *)((int)save_ctx + -0xac);
    (*(int(*)())0x060358EC)();
    *(int *)((int)save_ctx + -0xb0) = 0;
    *(int *)((int)save_ctx + -0xb4) = 0x40568000;
    save_result = (*(int(*)())0x06035B34)();
    if (save_result == 0) {
      FUN_0601d074();                                        /* transition handler B */
      goto LAB_0601cda4;
    }
    /* probe 10: size 0x403E0000 (smallest) */
    *(char **)((int)save_ctx + -0xc0) = (char *)((int)save_ctx + -0xc0);
    (*(int(*)())0x060358EC)();
    *(int *)((int)save_ctx + -0xc4) = 0;
    *(int *)((int)save_ctx + -200) = 0x403E0000;
    save_result = (*(int(*)())0x06035844)();
    if (save_result != 0) {
      FUN_0601cdc0();                                        /* fallback handler A */
      goto LAB_0601cda4;
    }
    /* probe 11: verify size 0x403E0000 */
    *(char **)((int)save_ctx + -0xd4) = (char *)((int)save_ctx + -0xd4);
    (*(int(*)())0x060358EC)();
    *(int *)((int)save_ctx + -0xd8) = 0;
    *(int *)((int)save_ctx + -0xdc) = 0x403E0000;
    save_result = (*(int(*)())0x06035B34)();
    if (save_result == 0) {
      *(int *)fade_step_ptr = 0;                             /* reset fade step */
    }
    /* if display timer still positive, apply fade and exit early */
    if (0 < *(int *)display_timer) {
      FUN_0601cefc();                                        /* fallback handler B */
      goto LAB_0601cda4;
    }
  }
  else {
    /* palette DMA based on transition state */
    if (*(int *)transition_state == 1) {
      (*(int(*)())dma_copy_fn)(cram_bank_a,0x0604880C,0x20);  /* palette set A → CRAM bank A */
      (*(int(*)())dma_copy_fn)(cram_bank_b,0x0604882C,0x20);  /* palette set A → CRAM bank B */
    }
    if (*(int *)transition_state == 2) {
      FUN_0601d014();                                        /* transition handler A */
      (*(int(*)())dma_copy_fn)(cram_bank_a,0x0604884C,0x20);  /* palette set B → CRAM bank A */
      (*(int(*)())dma_copy_fn)(cram_bank_b,0x0604886C,0x20);  /* palette set B → CRAM bank B */
    }
    if (*(int *)transition_state == 3) {
      (*(int(*)())dma_copy_fn)(cram_bank_a,0x0605D17C,0x20);  /* palette set C → CRAM bank A */
      (*(int(*)())dma_copy_fn)(cram_bank_b,0x0605D19C,0x20);  /* palette set C → CRAM bank B */
    }
  }
  GAME_STATE = 2;                                           /* return to menu */
LAB_0601cda4:
  (*(int(*)())0x06026CE0)();                                 /* VDP vsync */
  VBLANK_OUT_COUNTER = 0;
  return;
}

/* palette_fade_out -- Fade VDP2 palette to black.
 * Reads 32 palette entries from VDP2 CRAM (0x25F00000),
 * decomposes each RGB555 color, attenuates R/G/B by step
 * from fade table at 0x0605DF58, recomposes and DMA-writes
 * back. Step counter at 0x06086020, max 0x12 frames. */
void FUN_0601cdc0()
{
  short fade_factor;
  short rgb555;
  int i;
  short red[2];
  short green[2];
  short blue[2];
  short *src_palette;
  short *dst_ptr;
  short faded_palette[16];
  char faded_palette_b[40];

  if (*(int *)0x06086020 < 0x12) {                     /* fade not complete */
    fade_factor = *(short *)(0x0605DF58 + *(int *)(0x06086020 << 1)); /* fade table lookup */
    src_palette = (short *)0x25F00000;                  /* VDP2 CRAM base */
    dst_ptr = faded_palette;
    for (i = 0; i < 0x20; i = i + 1) {
      rgb555 = *src_palette;
      src_palette = src_palette + 1;
      FUN_0601d0bc(rgb555, red, green, blue);           /* decompose RGB555 */
      red[0] = (*(int(*)())0x06034FE0)(fade_factor * 0x1d);   /* attenuate R */
      green[0] = (*(int(*)())0x06034FE0)();             /* attenuate G */
      blue[0] = (*(int(*)())0x06034FE0)();              /* attenuate B */
      *dst_ptr = blue[0] * 0x400 + green[0] * 0x20 + red[0]; /* recompose RGB555 */
      dst_ptr = dst_ptr + 1;
    }
    (*(int(*)())0x0602766C)(0x25F00200, faded_palette, 0x20);  /* DMA palette bank A */
    (*(int(*)())0x0602766C)(0x25F00400, faded_palette_b, 0x20); /* DMA palette bank B */
  }
  *(int *)0x06086020 = *(int *)0x06086020 + 1;         /* advance fade step */
}

/* palette_fade_in -- Fade VDP2 palette from black to full color.
 * Inverse of palette_fade_out: uses (100 - step) as blend factor
 * so colors ramp from black toward original values. Same RGB555
 * decompose/recompose and DMA pattern. */
void FUN_0601cefc()
{
  short rgb555;
  int i;
  short red[2];
  short green[2];
  short blue[2];
  short *src_palette;
  int inv_fade_factor;
  short *dst_ptr;
  short faded_palette[16];
  char faded_palette_b[40];

  if (*(int *)0x06086020 < 0x12) {                     /* fade not complete */
    inv_fade_factor = 100 - *(short *)(0x0605DF58 + *(int *)(0x06086020 << 1)); /* inverted fade */
    src_palette = (short *)0x25F00000;                  /* VDP2 CRAM base */
    dst_ptr = faded_palette;
    for (i = 0; i < 0x20; i = i + 1) {
      rgb555 = *src_palette;
      src_palette = src_palette + 1;
      FUN_0601d0bc(rgb555, red, green, blue);           /* decompose RGB555 */
      red[0] = (*(int(*)())0x06034FE0)(inv_fade_factor * 0x1d);  /* blend R */
      green[0] = (*(int(*)())0x06034FE0)();             /* blend G */
      blue[0] = (*(int(*)())0x06034FE0)();              /* blend B */
      *dst_ptr = blue[0] * 0x400 + green[0] * 0x20 + red[0]; /* recompose RGB555 */
      dst_ptr = dst_ptr + 1;
    }
    (*(int(*)())0x0602766C)(0x25F00200, faded_palette, 0x20);  /* DMA palette bank A */
    (*(int(*)())0x0602766C)(0x25F00400, faded_palette_b, 0x20); /* DMA palette bank B */
  }
  *(int *)0x06086020 = *(int *)0x06086020 + 1;         /* advance fade step */
}

/* timer_display_init -- Initialize timer/countdown VDP display.
 * DMA-copies timer font data to VDP2 VRAM (0x25F00000),
 * sets up 2 VDP1 sprite commands for minutes and seconds digits,
 * clears timer display state. */
void FUN_0601d014(void)
{
    (*(int(*)())0x0602766C)(0x25F00000, 0x0604884C, 0x40);   /* DMA font data */
    (*(int(*)())0x06028400)(4, *(int *)0x06063968, 0x518,
        *(int *)(0x06063968 + 4), 0x06063968);                /* minutes sprite */
    (*(int(*)())0x06028400)(0, *(int *)0x06063970, 0x518,
        *(int *)(0x06063970 + 4), 0x06063970);                /* seconds sprite */
    *(int *)0x06086020 = 0;                                    /* reset display state */
}

/* countdown_display_init -- Initialize countdown timer display.
 * Sets VDP sprite slot (4), DMA-copies countdown font data (0x40 bytes),
 * builds 2 VDP1 sprite commands for countdown digits, clears state. */
void FUN_0601d074(void)
{
    (*(int(*)())0x0602853E)(4);                                /* VDP sprite slot config */
    (*(int(*)())0x0602766C)(0x25F00000, 0x0605D17C, 0x40);    /* DMA font data */
    (*(int(*)())0x06028400)(4, *(int *)0x06063CF8, 0x518,
        *(int *)(0x06063CF8 + 4), 0x06063CF8);                /* countdown digit 1 */
    (*(int(*)())0x06028400)(0, *(int *)0x06063D00, 0x518,
        *(int *)(0x06063D00 + 4), 0x06063D00);                /* countdown digit 2 */
    *(int *)0x06086020 = 0;                                    /* reset state */
}

/* cheat_code_input_check -- Detect 11-step cheat code button sequence.
 * Reads controller input at 0x06063D9A, advances step counter at 0x0608602C
 * when the expected button mask matches. If wrong input on any step, resets.
 * Steps 0-1: DAT_0601d18c, step 2: DAT_0601d18e, step 3: DAT_0601d24c,
 * steps 4,6: DAT_0601d24e, steps 5,7: 0x8000, step 8: PTR_DAT_0601d250,
 * step 9: DAT_0601d2c6, step 10: PTR_DAT_0601d2c8.
 * On completion (step 11): set unlock flag (0x06086030=1), play sound 0xAE1146FF. */
void FUN_0601d12c(void)
{
  int *step = (int *)0x0608602C;
  int prev_step = *step;
  unsigned short input = *(unsigned short *)0x06063D9A;

  if ((*step == 0) && ((input & DAT_0601d18c) != 0)) {
    *step = *step + 1;
  } else if ((*step == 1) && ((input & DAT_0601d18c) != 0)) {
    *step = *step + 1;
  } else if ((*step == 2) && ((input & DAT_0601d18e) != 0)) {
    *step = *step + 1;
  } else if ((*step == 3) && ((input & DAT_0601d24c) != 0)) {
    *step = *step + 1;
  } else if ((*step == 4) && ((input & DAT_0601d24e) != 0)) {
    *step = *step + 1;
  } else if ((*step == 5) && (((unsigned int)input & 0x00008000) != 0)) {
    *step = *step + 1;
  } else if ((*step == 6) && ((input & DAT_0601d24e) != 0)) {
    *step = *step + 1;
  } else if ((*step == 7) && (((unsigned int)input & 0x00008000) != 0)) {
    *step = *step + 1;
  } else if ((*step == 8) && ((input & PTR_DAT_0601d250) != 0)) {
    *step = *step + 1;
  } else if ((*step == 9) && ((input & DAT_0601d2c6) != 0)) {
    *step = *step + 1;
  } else if ((*step == 10) && ((input & PTR_DAT_0601d2c8) != 0)) {
    *step = *step + 1;
  }

  if ((*step == prev_step) && (*(short *)0x06063D9A != 0)) {
    *step = 0;                               /* wrong input — reset */
  }
  if (*step == 0xb) {
    *(int *)0x06086030 = 1;                  /* cheat unlocked */
    *step = 0;
    (*(int(*)())0x0601D5F4)(0, 0xAE1146FF); /* confirmation sound */
  }
}

/* service_subsystem_init -- Initialize service/test mode subsystem.
 * Disables interrupts (0x060149E0), configures SCU interrupt priorities
 * (timer0=0, VBlank-IN=0, VBlank-OUT=0, HBlank-IN=6, timer1=7),
 * initializes VDP state (0x0600A026), configures VDP2 scroll (0x0600511E).
 * DMA-copies 3 font/sprite tables to VDP1 VRAM, loads 2 sprite tables
 * to VDP2 VRAM, sets game mode to 0, re-enables interrupts. */
void FUN_0601d2dc(void)
{
  void (*scu_int_config)(int, int) = (void (*)(int, int))0x06038BD4;
  void (*dma_copy)(int, int, int) = (void (*)(int, int, int))0x0602766C;

  (*(int(*)())0x060149E0)();                  /* disable interrupts */

  scu_int_config(0x100, 0);                   /* timer 0: off */
  scu_int_config(4, 0);                       /* VBlank-IN: off */
  scu_int_config(8, 0);                       /* VBlank-OUT: off */
  scu_int_config(0x10, 6);                    /* HBlank-IN: priority 6 */
  scu_int_config(0x20, 7);                    /* timer 1: priority 7 */

  (*(int(*)())0x0600A026)();                  /* VDP state init */
  (*(int(*)())0x0600511E)(0x25E6F9C4, 0x00017700, 0, 8);  /* VDP2 scroll config */

  dma_copy(0x25F00600, 0x0604842C, 0x40);    /* font table A */
  dma_copy(0x25F00660, 0x0604888C, 0x60);    /* font table B */
  dma_copy(0x25F00000, 0x0604842C, 0x60);    /* font table C */

  (*(int(*)())0x06028654)(0x25E759EC, 0x06094FA8);   /* sprite table A → VDP2 */
  (*(int(*)())0x06028654)(0x25E75DDC, 0x06095F48);   /* sprite table B → VDP2 */
  (*(int(*)())0x06028400)(8, 0x06095F48, 0, (int)DAT_0601d36c);

  *(int *)0x0607887F = 0;                     /* game mode = 0 */
  (*(int(*)())0x060149CC)();                  /* re-enable interrupts */
}

/* service_mode_start -- Handle service mode entry and dispatch.
 * On first entry (0x06086024==0) with start button (DAT_0601d444):
 *   - Check for special controller patterns (0xAAA8 → unlock courses,
 *     DAT_0601d446 → unlock all courses + characters)
 *   - Initialize perspective (0x06014884), DMA sprite table, set timer=0xC
 *   - Set game mode to 4, mark as entered (0x06086024=1)
 * Always dispatches to game mode handler via vtable at 0x0605DF80. */
void FUN_0601d3c0(void)
{
  char *unlock_flags = (char *)0x0605AB16;

  if ((*(int *)0x06086024 == 0) && ((*(unsigned short *)0x06063D9A & DAT_0601d444) != 0)) {
    if ((unsigned int)*(unsigned short *)0x06063D98 == 0x0000AAA8) {
      *(int *)0x0605AB16 = *(int *)0x0605AB16 | 7;    /* unlock courses */
    }
    if ((unsigned int)*(unsigned short *)0x06063D98 == (int)DAT_0601d446) {
      *unlock_flags = *unlock_flags | 7;               /* unlock courses */
      *(int *)0x0605AB17 = *(int *)0x0605AB17 | 7;    /* unlock characters */
    }
    (*(int(*)())0x06014884)(0x20, 0);                  /* perspective init */
    (*(int(*)())0x06028400)(0xc, 0x06094FA8, 0);       /* DMA sprite table */
    *(int *)0x0607EBCC = 0xc;                          /* countdown timer */
    *(int *)0x0607887F = 4;                            /* game mode = 4 */
    *(int *)0x06086024 = 1;                            /* mark entered */
  }

  (*(int(*)())(*(int *)(0x0605DF80 + (unsigned int)(unsigned char)*(int *)(0x0607887F << 2))))();
}

/* hud_sprite_table_copy -- Copy 28 sprite entries from source table to HUD buffer.
 * Source at 0x06094FAC has 0x58-byte stride; dest at 0x0605AAA6 has 4-byte stride.
 * param_1 selects column offset (<<1). Issues VDP1 command after copy. */
void FUN_0601d57c(unsigned short param_1)
{
    register char *dest asm("r2") = (char *)0x0605AAA6;
    register char *src asm("r3") = (char *)0x06094FAC;
    unsigned short i = 0;

    do {
        int dest_off = i << 2;
        int src_off = i * 0x58 + (param_1 << 1);
        i++;
        *(short *)(dest + dest_off)     = *(short *)(src + src_off);
        *(short *)(dest + dest_off + 2) = *(short *)(src + src_off + 2);
    } while (i < 0x1c);

    (*(void(*)())0x06028400)(0xc, 0x0605AAA2, (param_1 & 0x3f) << 1, 0);
}

/* scsp_command_dispatch -- routes sound commands to SCSP mailbox by channel.
 *   param_1 = channel (0=direct, 1-5=tracked channels, 0xF=direct bypass)
 *   param_2 = sound command or track ID (shifted into 0xAn7000FF format for ch 1-5)
 *   Channels 1-5 build command word 0xAn7000FF + (param_2 << 8) and skip if unchanged.
 *   Channel 0 and 0xF send raw command if it has 0xA0000000 signature.
 *   Channel 4 sends param_2 directly without encoding.
 *   Returns channel number on success, SOUND_TIMEOUT_FLAG on timeout. */
int scsp_command_dispatch(param_1, param_2)
    int param_1;
    unsigned int param_2;
{
  int result;
  int cmd_word;
  result = SOUND_TIMEOUT_FLAG;
  if (SOUND_TIMEOUT_FLAG == 0) {
    result = param_1;
    if (param_1 == 0) {
      /* Channel 0: direct SCSP command (must have 0xA0 signature) */
      if ((param_2 & 0xA0000000) == 0xA0000000) {
        result = FUN_0601db84();             /* wait for SCSP mailbox ready */
        SCSP_MAILBOX = param_2;
        SOUND_CMD_MIRROR = param_2;
      }
    } else {
      if (param_1 == 1) {
        /* Channel 1: BGM / main music (0xA07000FF base) */
        cmd_word = 0xA07000FF + (param_2 << 8);
        result = 1;
        if (SOUND_CHAN_STATE != cmd_word) {
          result = FUN_0601db84();
          SOUND_CHAN_STATE = cmd_word;
          SOUND_CMD_MIRROR = cmd_word;
          SCSP_MAILBOX = cmd_word;
        }
        return result;
      }
      if (param_1 == 2) {
        /* Channel 2: secondary audio (0xA17000FF base) */
        cmd_word = 0xA17000FF + (param_2 << 8);
        result = 2;
        if (*(int *)0x0605DF98 != cmd_word) {
          result = FUN_0601db84();
          *(int *)0x0605DF98 = cmd_word;     /* channel 2 state */
          SOUND_CMD_MIRROR = cmd_word;
          SCSP_MAILBOX = cmd_word;
        }
        return result;
      }
      if (param_1 == 3) {
        /* Channel 3: tertiary audio (0xA27000FF base) */
        cmd_word = 0xA27000FF + (param_2 << 8);
        result = 3;
        if (*(int *)0x0605DF9C != cmd_word) {
          result = FUN_0601db84();
          *(int *)0x0605DF9C = cmd_word;     /* channel 3 state */
          SOUND_CMD_MIRROR = cmd_word;
          SCSP_MAILBOX = cmd_word;
        }
        return result;
      }
      if (param_1 == 4) {
        /* Channel 4: raw command pass-through */
        result = 4;
        if (*(unsigned int *)0x0605DFA4 != param_2) {
          result = FUN_0601db84();
          *(unsigned int *)0x0605DFA4 = param_2; /* channel 4 state */
          SOUND_CMD_MIRROR = param_2;
          SCSP_MAILBOX = param_2;
        }
        return result;
      }
      if (param_1 == 5) {
        /* Channel 5: effect audio (0xA37000FF base) */
        cmd_word = 0xA37000FF + (param_2 << 8);
        result = 5;
        if (*(int *)0x0605DFA8 != cmd_word) {
          result = FUN_0601db84();
          *(int *)0x0605DFA8 = cmd_word;     /* channel 5 state */
          SOUND_CMD_MIRROR = cmd_word;
          SCSP_MAILBOX = cmd_word;
        }
        return result;
      }
      if ((param_1 == 0xf) && ((param_2 & 0xA0000000) == 0xA0000000)) {
        /* Channel 0xF: direct bypass (same as channel 0) */
        result = FUN_0601db84();
        SCSP_MAILBOX = param_2;
        SOUND_CMD_MIRROR = param_2;
      }
    }
  }
  return result;
}

/* race_position_sound -- dispatches SCSP sound cues based on race checkpoint progress
 *   Monitors player checkpoint position relative to course total, triggers
 *   final-lap fanfare and position approach sounds via SCSP command dispatcher.
 *   Sound codes: 0xAE1121FF=final lap, 0xAE1127FF=approach far, 0xAE1126FF=approach near, 0xAE1146FF=generic
 */
int race_position_sound()
{
  char *delay_timer = (char *)0x06086058;       /* sound delay timer (short) */
  char *final_lap_flag = (char *)0x06087060;    /* final lap triggered flag */
  char *lap_state = (char *)0x0607EAD8;         /* race lap state (1=lap2, 2=lap3) */
  char *delay_counter = (char *)0x06086054;     /* sound delay counter (short) */
  int result;
  int car_base;
  int total_ckpts;
  total_ckpts = *(int *)(0x0604A50C +           /* checkpoint count for current course */
                  *(int *)(0x0605AD00 << 2) +
                  (int)(char)((char)CAR_COUNT * '\f'));
  car_base = CAR_PTR_TARGET;
  if (*(int *)0x06085FF4 == '\0') {
    /* Normal race — not on final stretch */
    if ((CAR_COUNT == 0) && (total_ckpts - *(int *)(car_base + PTR_DAT_0601d884) < 9)) {
      /* Player within 9 checkpoints of finish */
      if ((*(int *)0x06087060 == '\0') && (COURSE_SELECT != 0)) {
        *(int *)0x06087060 = 1;
        *(short *)delay_timer = 0;
      } else {
        *(short *)0x06086058 = *(short *)0x06086058 + 1;
      }
    }
    if ((*(int *)lap_state == 1) && (total_ckpts - *(int *)(car_base + DAT_0601d974) < 5)) {
      /* Lap 2: within 5 checkpoints of lap end */
      if ((*final_lap_flag == '\0') && (COURSE_SELECT != 0)) {
        *final_lap_flag = 1;
      } else {
        *(short *)delay_timer = *(short *)delay_timer + 1;
      }
    }
    if ((*(int *)lap_state == 2) && (total_ckpts - *(int *)(car_base + DAT_0601d974) < 3)) {
      /* Lap 3: within 3 checkpoints of lap end */
      if ((*final_lap_flag == '\0') && (COURSE_SELECT != 0)) {
        *final_lap_flag = 1;
      } else {
        *(short *)delay_timer = *(short *)delay_timer + 1;
      }
    }
    lap_state = (char *)0x06086056;             /* repurpose as sound interval ptr */
    if ((int)(total_ckpts + (unsigned int)(total_ckpts < 0)) >> 1 < *(int *)(car_base + DAT_0601d974) + 1) {
      /* Past halfway through course */
      if ((*(int *)(car_base + DAT_0601d974) == *(int *)0x06063F28 + -1) &&
         (*(int *)0x06086034 == 0)) {
        /* At final checkpoint — FINAL LAP fanfare */
        result = scsp_command_dispatch(0,0xAE1121FF);    /* SCSP: final lap fanfare */
        *(short *)lap_state = (char *)0x50;
        *(short *)delay_counter = (char *)0x50;
        *(int *)0x06086034 = 1;                 /* mark final lap sound played */
      } else {
        result = scsp_command_dispatch(0,0xAE1127FF);    /* SCSP: approach sound (far) */
        *(short *)delay_counter = PTR_DAT_0601da3c;
        *(short *)lap_state = (char *)0x14;
      }
    } else {
      result = scsp_command_dispatch(0,0xAE1126FF);      /* SCSP: approach sound (near) */
      *(short *)delay_counter = DAT_0601d976;
      *(short *)lap_state = (char *)0x14;
    }
  } else {
    /* Final lap active or race complete */
    if ((*(int *)(car_base + PTR_DAT_0601d884) != *(int *)0x06063F28 + -1) ||
       (*(int *)0x06086034 != 0)) {
      result = scsp_command_dispatch(0,0xAE1146FF);      /* SCSP: generic position cue */
      return result;
    }
    result = scsp_command_dispatch(0,0xAE1121FF);        /* SCSP: final lap fanfare */
    *(short *)delay_counter = (char *)0x50;
    *(int *)0x06086034 = 1;                     /* mark final lap sound played */
  }
  return result;
}

/* position_sound_sequencer -- sequences race position announcement sounds per checkpoint.
 *   Checks race-end flag at 0x06085FF4. Maps checkpoint counter (0x06086058)
 *   to position-specific SCSP cues for player (CAR_COUNT=0), 2nd car (=1), 3rd car (=2).
 *   Player positions: 1st=0xAE1129FF, 2nd/4th/6th=0xAE112BFF, 3rd=0xAE112AFF, 5th=0xAE112CFF.
 *   2nd car: 1st/3rd=0xAE112BFF, 6th=0xAE112DFF. 3rd car: 8th=0xAE112FFF.
 *   Sound interval timer at 0x06086056, delay counter at 0x06086054.
 *   Finish sequence flag at 0x0608605A triggers final 0xAE1120FF cue. */
unsigned int position_sound_sequencer()
{
  short interval_timer;
  unsigned short finish_timer;
  char *delay_counter = (char *)0x06086054;    /* sound delay counter */
  int default_cue;
  char *finish_flag;
  unsigned int result;
  short next_delay;
  if ((int)(char)*(int *)0x06085FF4 != 0) {
    return (int)(char)*(int *)0x06085FF4;      /* race ended — return status */
  }
  if (((*(short *)0x06086056 == 0) || (*(int *)0x0608605A == '\x01')) ||
     (interval_timer = *(short *)0x06086056, *(short *)0x06086056 = interval_timer + -1,
     default_cue = 0xAE112BFF, interval_timer != 1)) goto LAB_0601db20;
  if (CAR_COUNT != 0) {
    if (CAR_COUNT == 1) {
      /* 2nd car position sounds */
      interval_timer = *(short *)0x06086058;   /* checkpoint counter */
      if (interval_timer == 1) {
        *(short *)0x06086056 = 0;
        scsp_command_dispatch(0, default_cue); /* SCSP: 2nd place */
      } else if (interval_timer == 3) {
        *(short *)0x06086056 = 0;
        scsp_command_dispatch(0, default_cue); /* SCSP: 2nd place (alt) */
      } else {
        if (interval_timer != 6) {
          *(short *)delay_counter = 100;       /* not a trigger point — wait */
          goto LAB_0601db20;
        }
        *(short *)0x06086056 = 0;
        scsp_command_dispatch(0, 0xAE112DFF);  /* SCSP: 6th place (2nd car) */
      }
      *(short *)delay_counter = (char *)0x28;
    } else if ((CAR_COUNT == 2) && (*(short *)0x06086058 == 8)) {
      /* 3rd car: only triggers at checkpoint 8 */
      *(short *)0x06086056 = 0;
      scsp_command_dispatch(0, 0xAE112FFF);    /* SCSP: position (3rd car) */
      *(short *)delay_counter = (char *)0x28;
    }
    goto LAB_0601db20;
  }
  /* Player car (CAR_COUNT == 0) position sounds */
  interval_timer = *(short *)0x06086058;
  if (interval_timer == 1) {
    *(short *)0x06086056 = 0;
    scsp_command_dispatch(0, 0xAE1129FF);      /* SCSP: 1st place */
LAB_0601da72:
    next_delay = 0x28;
  } else {
    if (interval_timer == 2) {
      *(short *)0x06086056 = 0;
      scsp_command_dispatch(0, default_cue);   /* SCSP: 2nd place */
      goto LAB_0601da72;
    }
    if (interval_timer == 3) {
      *(short *)0x06086056 = 0;
      scsp_command_dispatch(0, 0xAE112AFF);    /* SCSP: 3rd place */
      next_delay = 0x14;
    } else {
      if (interval_timer == 4) {
        *(short *)0x06086056 = 0;
        scsp_command_dispatch(0, default_cue); /* SCSP: 4th place */
        goto LAB_0601da72;
      }
      if (interval_timer == 5) {
        *(short *)0x06086056 = 0;
        scsp_command_dispatch(0, 0xAE112CFF);  /* SCSP: 5th place */
        next_delay = 0x14;
      } else {
        if (interval_timer != 6) {
          *(short *)delay_counter = 100;
          goto LAB_0601db20;
        }
        *(short *)0x06086056 = 0;
        scsp_command_dispatch(0, default_cue); /* SCSP: 6th place */
        next_delay = 0x28;
      }
    }
  }
  *(short *)delay_counter = next_delay;
LAB_0601db20:
  /* Finish sequence: countdown to final announcement */
  finish_flag = (char *)0x0608605A;
  result = (unsigned int)(unsigned char)*(int *)0x0608605A;
  if (result == 1) {
    finish_timer = *(unsigned short *)0x06086056;
    *(unsigned short *)0x06086056 = finish_timer - 1;
    result = (unsigned int)finish_timer;
    if (result == 1) {
      *finish_flag = 0;
      *(short *)0x06086056 = 0;
      *(short *)delay_counter = (char *)0x28;
      result = scsp_command_dispatch(0, 0xAE1120FF); /* SCSP: finish announcement */
      return result;
    }
  }
  return result;
}


/* lap_time_record_display -- shows lap completion time and checks for new record.
 *   Triggers on race completion flags (0x0607EBF4, 0x0607EABC).
 *   Stores current lap time from 0x060786A0 into record buffer at 0x06087070.
 *   Compares with best time from record table (0x0605DDB4 or 0x0605DDD4 for 2P).
 *   Renders time display sprites via VDP1 draw (0x06028400) with animation.
 *   Timer at 0x0608706A counts down display duration; 0x0605DFED controls animation phase.
 *   Falls through to hud_sprite_setup (FUN_0601ddf6) on completion or race end. */
int lap_time_record_display()
{
  char anim_phase;
  short display_timer;
  char *sprite_priority = (char *)0x00009000;
  char *record_time = (char *)0x06087070;      /* stored lap time for comparison */
  char *display_active = (char *)0x06087068;   /* display active flag */
  char *record_source = (char *)0x06087074;    /* record table index (3 or 6) */
  char *vdp1_draw = (char *)0x06028400;        /* VDP1 sprite draw */
  char *best_time = (char *)0x0608706C;        /* best time from record table */
  int result;
  int idx;
  char *record_table;
  if (*(int *)0x060786AC != 0) {
    /* Race already ended — just show HUD */
    result = FUN_0601ddf6();
    return result;
  }
  if ((((unsigned int)(*(int *)0x06087068 == '\0') & *(unsigned int *)0x0607EBF4) != 0) ||
     (((unsigned int)((((int *)0x06078900)[3] & 8) == 0) &
      (unsigned int)(*(int *)0x06087068 == '\0') & *(unsigned int *)0x0607EABC) != 0)) {
    /* Lap just completed — initialize record display */
    *(int *)0x06087068 = 1;
    *(short *)0x0608706A = DAT_0601dd30;       /* display duration timer */
    *(int *)0x0605DFED = 0;                    /* reset animation phase */
    *(int *)record_time = *(int *)0x060786A0;  /* store current lap time */
    record_table = (char *)0x0605DDB4;         /* 1P record table */
    *(int *)record_source = 3;
    char *record_table_2p = (char *)0x0605DDD4;
    if (CAR_COUNT == 2) {
      *(int *)record_source = 6;               /* 2P record table offset */
      record_table = record_table_2p;
    }
    idx = (*(int(*)())0x060350B0)();            /* get course index */
    *(int *)best_time = *(int *)(record_table + (idx << 2));
    *(int *)0x0608707C = 9;                    /* sprite tile base */
    if (*(unsigned int *)record_time < *(unsigned int *)best_time) {
      /* New record! */
      *(int *)0x0608707C = 10;                 /* alternate tile for record */
      *(int *)best_time = *(int *)record_time;
      idx = (*(int(*)())0x060350B0)();
      *(int *)(record_table + (idx << 2)) = *(int *)record_time;
    }
  }
  if (*display_active == '\0') {
    result = 0;
  } else {
    /* Animate time display */
    anim_phase = *(int *)0x0605DFED;
    *(int *)0x0605DFED = anim_phase + 0x30U;
    record_source = (char *)0x060639F8;        /* sprite data table */
    if ((short)(unsigned short)(unsigned char)(anim_phase + 0x30U) < DAT_0601dd34) {
      /* Normal display — render time sprites */
      idx = (*(int(*)())0x060350B0)();
      (*(int(*)())vdp1_draw)(8, 0x0605E008 + idx * 0xe);
      record_table = (char *)0x060639E0;       /* sprite position table */
      (*(int(*)())vdp1_draw)(8, *(int *)0x060639D8, 0x842,
                        *(int *)(0x060639E0 + 4) + (unsigned int)(unsigned char)*(int *)(0x0608707C << 12));
      (*(int(*)())vdp1_draw)(8, *(int *)record_table, 0x942, sprite_priority + *(int *)(record_table + 4));
      FUN_0601e26c(*(int *)best_time);         /* format best time */
      (*(int(*)())vdp1_draw)(8, 0x0605DFF4, (int)DAT_0601de24, sprite_priority + *(int *)(record_source + 4));
      if (*(char **)record_time < 0x000927BF) {
        FUN_0601e26c(*(int *)record_time);     /* format current time */
      } else {
        FUN_0601e26c(0x000927BF);              /* clamp to 9:59.99 */
      }
      result = (*(int(*)())vdp1_draw)(8, 0x0605DFF4, (int)DAT_0601de26,
                                 sprite_priority + *(int *)(0x060639F8 + 4));
    } else {
      /* Animation overflow — show HUD sprites */
      result = FUN_0601ddf6();
    }
    display_timer = *(short *)0x0608706A;
    *(short *)0x0608706A = display_timer + -1;
    if ((short)(display_timer + -1) == 0) {
      /* Display timer expired — hide */
      *display_active = 0;
      result = FUN_0601ddf6();
      return result;
    }
  }
  return result;
}

/* hud_sprite_setup -- Configure 3 HUD sprite entries for lap/timer display.
 * Sets VDP sprite attributes for tiles 0x7C2, 0x8C2, 0x9C2 at dest 0x0605ACE3.
 * Third sprite uses FUN_060283E0 (wide sprite variant, 0xE000 size). */
int FUN_0601ddf6(void)
{
    register int dest asm("r0") = 0x0605ACE3;
    register int vdp_attr_set asm("r3") = 0x060284AE;
    (*(int(*)())vdp_attr_set)(8, 0x7C2, 0x90, dest);
    (*(int(*)())vdp_attr_set)(8, 0x8C2, 0x90, dest);
    (*(void(*)())0x060283E0)(8, 0x9C2, 0xE000, dest);
}

/* lap_record_notify -- Display lap time and "NEW RECORD" indicator.
 * Renders current lap time via FUN_0601e26c (clamped to 9:59.99),
 * draws time digits sprite. If lap time beats stored record at
 * car struct +DAT_0601df18, updates high score table and shows
 * "NEW RECORD" banner with animation counter at 0x0605DFEC. */
int FUN_0601de50()
{
  int result;
  int *sprite_data;

  if ((char *)(GAME_STATE_VAR * 5) < 0x000927BF) {     /* time within display range */
    FUN_0601e26c();                                     /* render current time */
  } else {
    FUN_0601e26c(0x000927BF);                           /* clamp to 9:59.99 max */
  }
  (*(int(*)())0x06028400)(8, 0x0605DFF4, (int)DAT_0601df16,  /* draw lap time digits */
             0x00009000 + *(int *)(0x06063750 + DAT_0601df14));
  result = 0;
  if (*(unsigned int *)(0x06078900 + DAT_0601df18) < *(unsigned int *)0x06086008 &&
      *(int *)(0x06078900 + DAT_0601df1a) != 0) {      /* new record beaten */
    *(int *)
     (*(int *)(0x0605DE24 + (*(int *)(0x0607EAD8 << 1) + DEMO_MODE_FLAG) << 2) + 4
     ) = *(int *)(0x06078900 + DAT_0601df18);           /* update high score table */
    sprite_data = (int *)(0x06063750 + DAT_0601df1c);
    (*(int(*)())0x06028400)(8, *sprite_data, 0x3c2,     /* draw record time sprite */
               0x0000A000 + sprite_data[1]);
    *(int *)0x0605DFEC = *(int *)0x0605DFEC + '@';      /* advance animation counter */
    if ((char)*(int *)0x0605DFEC < '\0') {              /* animation overflow → show banner */
      result = (*(int(*)())0x060283E0)(8, 0x442, 0x0000E000, 0x0605ACE3); /* "NEW RECORD" sprite */
      return result;
    }
    FUN_0601e26c(*(int *)(0x06078900 + DAT_0601df18));  /* render record time */
    result = (*(int(*)())0x06028400)(8, 0x0605DFF4, (int)PTR_DAT_0601df20,
                              0x0000A000 + *(int *)(0x06063750 + DAT_0601df14));
  }
  return result;
}

/* race_time_display -- Show total race time with best-time comparison.
 * Renders current total time and best lap time from car struct.
 * If current time beats stored best at 0x0607863C vs 0x06086004,
 * shows "NEW RECORD" banner with animation counter at 0x0605DFEC.
 * Uses sprite renderer at 0x06028400, time formatter FUN_0601e26c. */
int FUN_0601df88()
{
  int result;
  int car_offset;

  car_offset = 0x2a8;
  /* --- lap split time display --- */
  if (*(unsigned int *)(0x06078900 + car_offset + -0x68) < *(unsigned int *)0x06086008) {
    (*(int(*)())0x06028400)(8, *(int *)(0x06063750 + DAT_0601e024), 0x3c2,  /* split label sprite */
               0x0000A000 + *(int *)((int)(0x06063750 + DAT_0601e024) + 4));
    FUN_0601e26c(*(int *)(0x06078900 + DAT_0601e028));  /* render split time */
    (*(int(*)())0x06028400)(8, 0x0605DFF4, (int)DAT_0601e02a,  /* split time digits */
               0x0000A000 + *(int *)(0x06063750 + car_offset + 4));
  }
  /* --- total time display --- */
  FUN_0601e26c(*(int *)0x0607863C);                     /* render total time */
  result = (*(int(*)())0x06028400)(8, 0x0605DFF4, (int)DAT_0601e02c,  /* total time digits */
                            0x00009000 + *(int *)(0x06063750 + car_offset + 4));
  /* --- best time comparison --- */
  if (*(unsigned int *)0x0607863C < *(unsigned int *)0x06086004) {  /* beat best time */
    (*(int(*)())0x06028400)(8, *(int *)(0x06063750 + DAT_0601e02e), 0x4c2,  /* best time label */
                      0x0000A000 + *(int *)((int)(0x06063750 + DAT_0601e02e) + 4));
    if (*(unsigned int *)0x0607863C < 0x000927BF) {     /* within displayable range */
      FUN_0601e26c(*(int *)0x0607863C);                 /* render best time */
    } else {
      FUN_0601e26c(0x000927BF);                         /* clamp to 9:59.99 */
    }
    (*(int(*)())0x06028400)(8, 0x0605DFF4, (int)DAT_0601e0e2,  /* best time digits row 1 */
                      0x00009000 + *(int *)(0x06063750 + car_offset + 4));
    *(int *)0x0605DFEC = *(int *)0x0605DFEC + '@';      /* advance animation counter */
    if ((char)*(int *)0x0605DFEC < '\0') {              /* animation overflow → show banner */
      result = (*(int(*)())0x060283E0)(8, 0x542, 0x0000E000, 0x0605ACE3); /* "NEW RECORD" sprite */
      return result;
    }
    if (*(unsigned int *)0x0607863C < 0x000927BF) {     /* within displayable range */
      FUN_0601e26c(*(int *)0x0607863C);                 /* render best time again */
    } else {
      FUN_0601e26c(0x000927BF);                         /* clamp to 9:59.99 */
    }
    result = (*(int(*)())0x06028400)(8, 0x0605DFF4, (int)DAT_0601e0e4,  /* best time digits row 2 */
                              0x0000A000 + *(int *)(0x06063750 + car_offset + 4));
  }
  return result;
}
