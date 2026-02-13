#include "game.h"

extern char flag_060322fc;
extern int DAT_06031e30;
extern int DAT_06031eee;
extern int DAT_06031fc4;
extern int DAT_06032048;
extern int DAT_0603204a;
extern int DAT_06032102;
extern int DAT_06032104;
extern int DAT_06032106;
extern int FUN_060322e8();
extern int FUN_06032304();
extern char * FUN_0603253c();
extern int FUN_06032584();
extern int FUN_0603268c();
extern void FUN_06032d90();
extern void FUN_06032e18();
extern int FUN_06032e6c();
extern unsigned int FUN_06032ea4();
extern int FUN_0603307c();
extern int FUN_060330a0();
extern int FUN_0603316c();
extern long long FUN_06033188();
extern long long FUN_0603320c();
extern long long FUN_06033278();
extern int FUN_06033330();
extern int FUN_06033470();
extern int FUN_06033504();
extern void FUN_06033520();
extern int FUN_06033550();
extern int FUN_060335f4();
extern int FUN_06033648();
extern int FUN_060336c8();
extern int FUN_060336f2();
extern int FUN_06033700();
extern void FUN_060337fc();
extern int FUN_06033f54();
extern int FUN_06034000();
extern int FUN_06034168();
extern int FUN_0603449c();
extern int FUN_06034560();
extern int FUN_0603458c();
extern int FUN_06034640();
extern int FUN_060346c0();
extern int PTR_DAT_06031ea8;
extern int PTR_DAT_06031f30;
extern int PTR_DAT_06031f74;
extern int PTR_DAT_0603204c;
extern int PTR_DAT_06033344;
extern int PTR_DAT_060333b0;
extern void FUN_060333d8();
extern void FUN_06033354();
extern void FUN_06032158();
extern void FUN_060320e6();
extern int counter_06032300;



/* scene_object_table_init -- Initialize 6 scene objects with slot IDs and 13-byte name strings. */
char * FUN_060321c0()
{
  char ch;
  char *state_ptr;
  char *dst;
  char *src;
  int slot_idx;
  int obj_ptr;
  slot_idx = 0;
  do {
    obj_ptr = *(int *)(0x060623B0 + (slot_idx << 2));  /* object pointer table */
    *(char *)(obj_ptr + 0x000002DC) = (char)slot_idx;   /* store slot index */
    FUN_06032d90();
    *(short *)(obj_ptr + 0x0000000E) = (short)0x00000004;  /* state = 4 */
    FUN_06032e18(0x00000000);
    /* Copy 13-byte name string from name table to object+0x2DE */
    src = *(char **)(0x06062464 + (slot_idx << 2));
    dst = (char *)(0x000002DE + obj_ptr);
    obj_ptr = 0x0000000D;  /* 13 bytes to copy */
    do {
      ch = *src;
      src = src + 1;
      *dst = ch;
      dst = dst + 1;
      obj_ptr = obj_ptr + -1;
    } while (obj_ptr != 0);
    slot_idx = slot_idx + 1;
  } while (slot_idx <= 0x00000005);
  /* Clear scene state globals */
  *(int *)0x06082A20 = 0;
  *(int *)0x06082A24 = 0;
  state_ptr = (int *)0x06082A25;
  *(int *)0x06082A25 = 0;
  return state_ptr;
}

/* scene_update_all_layers -- Update all 6 scene layers, then advance frame counter.
 * Calls FUN_06032304 for layers 0-5, then scene_frame_counter. */
int FUN_0603226c(void)
{
    FUN_06032304(0);
    FUN_06032304(1);
    FUN_06032304(2);
    FUN_06032304(3);
    FUN_06032304(4);
    FUN_06032304(5);

    return FUN_060322e8();
}



/* scene_frame_step_direction -- Determine animation step direction.
 * Implicit r14 = scene object pointer.
 * If scene system inactive (0x06082A24 == 0), returns immediately.
 * Reads flags at obj+0x0E: bit1 = reverse (-1), bit0 = pause (0), default = forward (+1).
 * Adds step value to frame counter at obj+0x2C4. */
char * FUN_0603253c()
{
  char *puVar1;
  unsigned int uVar2;
  int unaff_r14 = 0;

  if (*(int *)0x06082A24 == '\0') {
    return 0x06082A24;
  }
  uVar2 = 0x00000001;
  if ((0x00000002 & (int)*(short *)(unaff_r14 + 0x0000000E)) != 0) {
    uVar2 = 0xFFFFFFFF;
  }
  if ((0x00000001 & (int)*(short *)(unaff_r14 + 0x0000000E)) != 0) {
    uVar2 = 0x00000000;
  }
  puVar1 = (char *)0x000002C4;
  *(unsigned int *)(0x000002C4 + unaff_r14) = *(int *)(0x000002C4 + unaff_r14) + uVar2;
  return puVar1;
}







/* scene_wind_smoothing -- Smooth wind effect value toward target.
 * If wind enable bit (0x06082A25 & 1) is set, target is 0x3333 (fixed-point);
 * otherwise target is 0. Moves current value (0x06082A28) halfway toward
 * target each frame (exponential decay), adds result to param_1 accumulator.
 * Returns pointer to wind state at 0x06082A28. */
char * FUN_06033020(param_1)
    int *param_1;
{
    int target = 0x00003333;     /* wind target intensity */
    int current;
    int smoothed;

    if ((0x00000001 & (int)(char)*(int *)0x06082A25) == 0) {
        target = 0;              /* wind disabled */
    }

    smoothed = *(int *)0x06082A28 + ((target - *(int *)0x06082A28) >> 1);  /* half-step */
    *(int *)0x06082A28 = smoothed;  /* update current */
    *param_1 = *param_1 + smoothed; /* accumulate */

    return (char *)0x06082A28;
}

/* scene_palette_check -- Check if scene palette is loaded.
 * If palette state (indirect ptr at 0x06033864) < 1, load palette
 * via DMA and initialize scene rendering. Returns palette state. */
int FUN_0603307c(void)
{
    int state = **(int **)0x06033864;
    if (state < 1) {
        FUN_06033330();         /* scene_dma_load_palette */
        state = FUN_060330a0(); /* scene render init */
    }
    return state;
}


















/* track_object_table_init -- Initialize 45 track objects from definition table at 0x060631BC.
 * Copies position (16.16 fixed-point), type, flags from 14-byte source entries
 * into 44-byte object slots at 0x06082A7C, then links 2 active object pointers. */
long long FUN_06033aac()
{
  int unused;
  short *src_entry;
  int *link_ptr;
  int *link_table;
  char *obj_base;
  unsigned int idx;
  int link_idx;
  int offset;
  idx = 0;
  do {
    obj_base = (char *)0x06082A7C;
    offset = (0x0000002C & 0xffff) * (idx & 0xffff);  /* stride 0x2C per object */
    ((int *)0x06082A7C)[0x00000000 + offset] = (char)idx;  /* slot index */
    obj_base[0x00000010 + offset] = 0;   /* clear flags */
    obj_base[0x00000011 + offset] = 0;
    obj_base[0x00000026 + offset] = 0;
    obj_base[0x00000028 + offset] = 0;
    /* Read 14-byte source entry */
    src_entry = (short *)(0x060631BC + (0x0000000E & 0xffff) * (idx & 0xffff));
    /* Copy 4 position shorts → 16.16 fixed-point ints */
    *(int *)(obj_base + 0x00000014 + offset) = (int)*src_entry << 0x10;
    *(int *)(obj_base + 0x00000018 + offset) = (int)src_entry[1] << 0x10;
    *(int *)(obj_base + 0x0000001C + offset) = (int)src_entry[2] << 0x10;
    *(int *)(obj_base + 0x00000020 + offset) = (int)src_entry[3] << 0x10;
    /* Copy type and attribute fields */
    *(short *)(obj_base + 0x00000002 + offset) = src_entry[4];
    *(short *)(obj_base + 0x00000012 + offset) = src_entry[5];
    *(short *)(obj_base + 0x00000024 + offset) = (short)*(char *)(src_entry + 6) << 8;
    obj_base[0x00000001 + offset] = *(char *)((int)src_entry + 0xd);
    idx = idx + 1;
  } while ((int)idx < 0x0000002D);
  *(int *)0x06083254 = 0;
  *(int *)0x06083250 = 0;
  /* Link 2 active object pointers */
  offset = 0x00000014;
  link_idx = 0;
  link_table = (int *)0x060631AC;
  obj_base = (char *)0x0607EB94;
  do {
    link_ptr = (int *)*link_table;
    link_table = link_table + 1;
    *link_ptr = obj_base;
    unused = 0x00000006;
    obj_base[0x00000006] = (char)link_idx;
    obj_base = obj_base + offset;
    link_idx = link_idx + 1;
  } while (link_idx < 2);
  return CONCAT44(src_entry + 7,unused);
}

/* track_scenery_lod_update -- Load track scenery objects based on checkpoint position.
 * Reads car checkpoint at +0x1EC and enables scenery groups by range:
 *   Zone 1 (0xDC-0xEC): objects 0-2 (roadside structures)
 *   Zone 2 (0xED-0x104): objects 5-24 (mid-track scenery, 20 objects)
 *   Zone 3 (0x1B8-0x1E0): objects 25-44 (far scenery, progressive in demo mode)
 * In demo mode, zone 3 progressively loads objects based on timer at 0x06083250
 * with thresholds at 0x13B (4 more), 0x276 (5 more), 0x3B1 (10 more).
 * Timer caps at 0xEC4, resets when leaving zone 3. */
int FUN_06033bc8()
{
  int timer;
  int in_zone;
  int checkpoint = *(int *)(0x000001EC + CAR_PTR_TARGET);
  /* Zone 1: checkpoint 0xDC-0xEC — roadside structures */
  if ((checkpoint < 0x000000DC) || (0x000000EC < checkpoint)) {
    in_zone = 0;
  }
  else {
    in_zone = 1;
  }
  if (in_zone) {
    (*(int(*)())0x06033F54)(0);
    (*(int(*)())0x06033F54)(1);
    (*(int(*)())0x06033F54)(2);
  }
  else {
    (*(int(*)())0x0603446C)();           /* fallback: unload zone 1 objects */
  }
  /* Zone 2: checkpoint 0xED-0x104 — mid-track scenery (20 objects) */
  checkpoint = *(int *)(0x000001EC + CAR_PTR_TARGET);
  if ((checkpoint < 0x000000ED) || (0x00000104 < checkpoint)) {
    in_zone = 0;
  }
  else {
    in_zone = 1;
  }
  if (in_zone) {
    FUN_06033f54(5);
    FUN_06033f54(6);
    FUN_06033f54(7);
    FUN_06033f54(8);
    FUN_06033f54(9);
    FUN_06033f54(10);
    FUN_06033f54(0xb);
    FUN_06033f54(0xc);
    FUN_06033f54(0xd);
    FUN_06033f54(0xe);
    FUN_06033f54(0xf);
    FUN_06033f54(0x10);
    FUN_06033f54(0x11);
    FUN_06033f54(0x12);
    FUN_06033f54(0x13);
    FUN_06033f54(0x14);
    FUN_06033f54(0x15);
    FUN_06033f54(0x16);
    FUN_06033f54(0x17);
    FUN_06033f54(0x18);
  }
  /* Zone 3: checkpoint 0x1B8-0x1E0 — far scenery (progressive in demo) */
  checkpoint = *(int *)(0x000001EC + CAR_PTR_TARGET);
  if ((checkpoint < 0x000001B8) || (0x000001E0 < checkpoint)) {
    in_zone = 0;
  }
  else {
    in_zone = 1;
  }
  if (in_zone) {
    if (DEMO_MODE_FLAG == 0) {
      timer = 0;
    }
    else {
      /* Demo mode: progressively reveal objects based on timer */
      FUN_06033f54(0x00000019);          /* always load first far object */
      timer = *(int *)0x06083250;
      if (0x0000013B <= timer) {         /* tier 1: 4 more objects */
        FUN_06033f54(0x0000001A);
        FUN_06033f54(0x0000001B);
        FUN_06033f54(0x0000001C);
        FUN_06033f54(0x0000001D);
        if (0x00000276 <= timer) {       /* tier 2: 5 more objects */
          FUN_06033f54(0x1e);
          FUN_06033f54(0x1f);
          FUN_06033f54(0x20);
          FUN_06033f54(0x21);
          FUN_06033f54(0x22);
          if (0x000003B1 <= timer) {     /* tier 3: 10 more objects */
            FUN_06033f54(0x23);
            FUN_06033f54(0x24);
            FUN_06033f54(0x25);
            FUN_06033f54(0x26);
            FUN_06033f54(0x27);
            FUN_06033f54(0x28);
            FUN_06033f54(0x29);
            FUN_06033f54(0x2a);
            FUN_06033f54(0x2b);
            FUN_06033f54(0x2c);
          }
        }
      }
      /* Increment timer, cap at 0xEC4 */
      timer = *(int *)0x06083250 + 1;
      if (0x00000EC4 <= *(int *)0x06083250 + 1) {
        timer = 0x00000EC4;
      }
      *(int *)0x06083250 = timer;
    }
  }
  else {
    timer = 0;
    *(int *)0x06083250 = 0;              /* reset timer when leaving zone */
  }
  return timer;
}

/* scene_object_state_advance -- Advance scene object loading state machine.
 * Increments state counter at 0x06083254 when vsync flag (0x06063E08) == 1.
 * State 1: initialize 4 object slots (0, 1, 2, 4) via FUN_06033F54.
 * State 2: batch-load remaining slots 6..24 via FUN_06033f54. */
int FUN_06033ea8()
{
    int state;

    if (*(short *)0x06063E08 == 1) {
        *(int *)0x06083254 = *(int *)0x06083254 + '\x01';
    }

    if (*(int *)0x06083254 == '\x01') {
        /* State 1: init primary object slots */
        (*(int(*)())0x06033F54)(0x00000000);
        (*(int(*)())0x06033F54)(0x00000001);
        (*(int(*)())0x06033F54)(0x00000002);
        (*(int(*)())0x06033F54)(0x00000004);
    }

    state = (int)(char)*(int *)0x06083254;
    int slot = 0x00000006;
    if ((char)*(int *)0x06083254 == 2) {
        /* State 2: load remaining slots 6 through 24 */
        do {
            FUN_06033f54();
            slot = slot + 1;
            state = 0x00000019;
        } while (slot < 0x00000019);
    }

    return state;
}

