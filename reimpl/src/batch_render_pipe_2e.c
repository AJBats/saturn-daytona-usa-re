#include "game.h"

extern int DAT_0602e460;
extern int DAT_0602e51a;
extern int DAT_0602e51c;
extern int DAT_0602e51e;
extern int DAT_0602e520;
extern int DAT_0602e522;
extern int DAT_0602e5a2;
extern int DAT_0602e5a4;
extern int DAT_0602e5a6;
extern int DAT_0602e80a;
extern int DAT_0602efe6;
extern int DAT_0602f01e;
extern int DAT_0602f064;
extern int DAT_0602f066;
extern int DAT_0602f11e;
extern int DAT_0602f120;
extern int DAT_0602f122;
extern int DAT_0602f124;
extern int DAT_0602f126;
extern int DAT_0602f128;
extern int DAT_0602f12a;
extern int DAT_0602f15a;
extern int DAT_0602f15c;
extern int DAT_0602f15e;
extern int DAT_0602f160;
extern int DAT_0602f162;
extern int DAT_0602f1ba;
extern int DAT_0602f1bc;
extern int DAT_0602f1be;
extern int DAT_0602f1f2;
extern int DAT_0602f24c;
extern int DAT_0602f24e;
extern int DAT_0602f464;
extern int DAT_0602f466;
extern int DAT_0602f4aa;
extern int DAT_0602f51a;
extern int DAT_0602f51c;
extern int DAT_0602f51e;
extern int DAT_0602f5b4;
extern int DAT_0602f5e8;
extern int DAT_0602f5ea;
extern int DAT_0602f6e0;
extern int DAT_0602f6e2;
extern int DAT_0602f6e4;
extern int DAT_0602f6e6;
extern int DAT_0602f6e8;
extern int DAT_0602f6ea;
extern int DAT_0602f6ec;
extern int DAT_0602f6ee;
extern int DAT_0602f6f0;
extern int DAT_0602f6f2;
extern int DAT_0602f6f4;
extern int DAT_0602f6f6;
extern int DAT_0602f786;
extern int DAT_0602f788;
extern int DAT_0602f78a;
extern int DAT_0602f7e4;
extern int DAT_0602f7e6;
extern int DAT_0602f7e8;
extern int DAT_0602f842;
extern int DAT_0602f844;
extern int DAT_0602f890;
extern int DAT_0602f8f0;
extern int DAT_0602f8f2;
extern int DAT_0602f97e;
extern int DAT_0602f980;
extern int DAT_0602f982;
extern int DAT_0602fb3c;
extern int DAT_0602fba8;
extern int DAT_0602fbca;
extern int DAT_0602fc6e;
extern int DAT_0602fc70;
extern int DAT_0602fc72;
extern int DAT_0602fc74;
extern int DAT_0602fc76;
extern int DAT_0602fc9c;
extern int DAT_0602fc9e;
extern int DAT_0602fd1a;
extern int DAT_06083264;
extern int DAT_06083268;
extern int FUN_0602d924();
extern int FUN_0602eccc();
extern int FUN_0602f71c();
extern int PTR_DAT_0602e524;
extern int PTR_DAT_0602e5a8;
extern int PTR_DAT_0602efe8;
extern int PTR_DAT_0602f0e0;
extern int PTR_DAT_0602f250;
extern int PTR_DAT_0602f26e;
extern int PTR_DAT_0602f468;
extern int PTR_DAT_0602f4ac;
extern int PTR_DAT_0602fa60;
extern int PTR_DAT_0602fb10;
extern int PTR_DAT_0602fc14;
extern int PTR_DAT_0602fcb8;
extern int PTR_DAT_0602fcdc;
extern void FUN_0602f4b4();
extern void FUN_0602f474();
extern void FUN_0602f3ec();
extern void FUN_0602ecf2();
extern void FUN_0602e610();
extern void FUN_0602e5e4();
extern void FUN_0602e4bc();
extern void FUN_0602e450();







/* car_angle_trig_compute -- Compute sin/cos for car rotation angle.
 * Implicit r0 = car object pointer. Reads angle at obj+0x24,
 * calls trig function at 0x06027358 with angle and two car-relative
 * offsets (DAT_0602efe6, PTR_DAT_0602efe8). */
void FUN_0602efcc()
{
  int in_r0 = 0;

  (*(int(*)())0x06027358)(*(int *)(in_r0 + 0x24),DAT_0602efe6 + in_r0,PTR_DAT_0602efe8 + in_r0);
  return;
}

/* car_physics_division_chain -- Chain three SH-2 hardware divisions for car physics.
 * Uses target car pointer. First division: param_2 / car+DAT_0602f01e.
 * Stores result at car+DAT_0602f064, saves previous value at car+DAT_0602f066.
 * Chains two more divisions, storing results at car+extraout_r3 offsets.
 * Uses FUN_0602eccc (sh2_divide_start) for hardware division pipelining. */
int FUN_0602eff0(param_1, param_2)
    int param_1;
    int param_2;
{
  int iVar1;
  int uVar2;
  int iVar3;
  int extraout_r1 = 0;
  int extraout_r1_00;
  int extraout_r3 = 0;
  int uVar4;

  iVar1 = CAR_PTR_TARGET;
  uVar2 = FUN_0602eccc(0,param_2,*(int *)(DAT_0602f01e + iVar1),0);
  iVar3 = (int)DAT_0602f066;
  uVar4 = *(int *)(DAT_0602f064 + iVar1);
  *(int *)(DAT_0602f064 + iVar1) = uVar2;
  *(int *)(iVar3 + iVar1) = uVar4;
  FUN_0602eccc();
  *(int *)(extraout_r3 + iVar1) = extraout_r1;
  FUN_0602eccc();
  *(int *)(PTR_DAT_0602f0e0 + iVar1) = extraout_r1_00;
  return iVar1;
}

/* car_angle_smooth_decay -- Smooth car angle field, decay rotation at +0xD0 toward zero. */
int FUN_0602f0e8()
{
  int car_ptr;
  int angle_off;
  int delta;
  car_ptr = CAR_PTR_TARGET;
  /* Exponential smoothing of angle field */
  *(int *)(DAT_0602f120 + car_ptr) =
       *(int *)(DAT_0602f11e + car_ptr) << 8 + *(int *)(DAT_0602f120 + car_ptr) >> 1;
  if ((*(int *)(DAT_0602f122 + car_ptr) == 0) && (*(int *)(DAT_0602f124 + car_ptr) == 0)) {
    /* No active rotation — copy default values */
    *(int *)(0x00000084 + car_ptr) = *(int *)(DAT_0602f126 + car_ptr);
    *(int *)(DAT_0602f12a + car_ptr) = *(int *)(DAT_0602f128 + car_ptr);
    return car_ptr;
  }
  /* Active rotation — reset and decay */
  *(short *)(DAT_0602f15a + car_ptr) = 0;
  delta = (int)DAT_0602f15c;
  *(int *)(DAT_0602f15e + car_ptr) = delta;
  *(int *)(DAT_0602f160 + car_ptr) = delta;
  angle_off = 0xd0;
  delta = 0x0000071C;                        /* decay step */
  if (-1 < *(int *)(angle_off + car_ptr)) {
    delta = -0x0000071C;                     /* negate for positive angles */
  }
  delta = *(int *)(angle_off + car_ptr) + delta;
  if (-1 < delta) {
    *(int *)(angle_off + car_ptr) = 0;       /* clamped to zero */
    return car_ptr;
  }
  *(int *)(angle_off + car_ptr) = delta;
  return car_ptr;
}

/* car_gear_ratio_update -- Update gear ratio and speed limits per gear.
 * Implicit r0 = car object pointer. Reads rotation field at obj+0xD8,
 * decays toward zero. Reads current gear index at obj+DAT_0602f1bc,
 * compares speed against gear-specific thresholds from tables at
 * 0x060477AC/0x0604779C (shift up/down). Adjusts gear index and
 * scales speed ratio from table at 0x060477CC. Clamps final speed
 * against per-gear range from table at 0x0602F3CC (8 bytes/entry). */
void FUN_0602f17c()
{
  short gear_index;
  int car = 0; /* implicit r0 = car pointer */
  unsigned int scaled_speed;
  int gear_off;
  int rotation;
  int speed_delta;
  int gear_idx_shifted;

  /* Asymmetric decay of gear rotation toward zero (positive: -2+1=-1, negative: +1) */
  rotation = *(int *)(car + CAR_GEAR_ROTATION);
  speed_delta = 0;
  if (rotation != 0) {
    if (-1 < rotation) {
      rotation = rotation + -2;
    }
    speed_delta = rotation + 1;
  }
  *(int *)(car + CAR_GEAR_ROTATION) = speed_delta;

  /* Read current gear index, compute table offset */
  gear_off = CAR_ZONE_TIMER;
  gear_idx_shifted = *(short *)(car + CAR_ZONE_TIMER) << 2;

  if ((*(int *)(car + CAR_SPEED) == 0) ||
     (*(int *)(car + CAR_DRIVE_SPEED) <= *(int *)(0x060477AC + gear_idx_shifted))) {
    /* Check downshift threshold */
    if (*(int *)(car + CAR_DRIVE_SPEED) <= *(int *)(0x0604779C + gear_idx_shifted)) {
      *(int *)(car + CAR_GEAR_ROTATION) = 0xfffffffb;
      speed_delta = *(short *)(car + CAR_ZONE_TIMER) + -1;
      *(short *)(car + CAR_ZONE_TIMER) = (short)speed_delta;
      /* Scale drive speed by gear ratio for downshift */
      scaled_speed = (*(int(*)())0x0602755C)(*(int *)(car + CAR_DRIVE_SPEED) << 0x10,
                         *(int *)(0x060477CC + (speed_delta << 2)));
      *(unsigned int *)(car + CAR_DRIVE_SPEED) = scaled_speed >> 0x10;
    }
  }
  else {
    /* Upshift: set rotation to +5, increment gear index */
    *(int *)(car + CAR_GEAR_ROTATION) = 5;
    gear_index = *(short *)(car + CAR_ZONE_TIMER);
    *(short *)(car + CAR_ZONE_TIMER) = gear_index + 1;
    /* Scale drive speed by gear ratio for upshift */
    *(unsigned int *)(car + CAR_DRIVE_SPEED) =
         (unsigned int)((unsigned long long)
                ((long long)(*(int *)(car + CAR_DRIVE_SPEED) << 0x10) *
                (long long)*(int *)(0x060477CC + (gear_index << 2))) >> 0x20) & 0xffff;
  }

  /* Compute effective speed: drive_speed + drag_offset - projected_B */
  speed_delta = (*(int *)(car + CAR_DRIVE_SPEED) + *(int *)(car + CAR_DRAG_FLAG)) -
          *(int *)(car + CAR_PROJECTED_B);
  /* Clamp to per-gear range from table at 0x0602F3CC (8 bytes/entry: min, max) */
  gear_idx_shifted = *(int *)(0x0602F3CC + *(short *)(car + CAR_ZONE_TIMER) << 3);
  gear_off = *(int *)((int)(0x0602F3CC + *(short *)(car + CAR_ZONE_TIMER) << 3) + 4);
  if ((gear_idx_shifted < speed_delta) && (gear_idx_shifted = speed_delta, gear_off < speed_delta)) {
    gear_idx_shifted = gear_off;
  }
  *(int *)(car + CAR_PROJECTED_B) = *(int *)(car + CAR_PROJECTED_B) + gear_idx_shifted;
  return;
}




/* car_speed_to_rpm_convert -- Convert car speed to engine RPM for display.
 * Implicit r0 = car struct pointer.
 * Clamps speed from DAT_0602f5ea to range [0, 0x2134]. Looks up RPM curve
 * from table (DAT_0602f6e2, indexed by speed>>7). Interpolates between table
 * entries using fractional part. Stores computed RPM values. */
void FUN_0602f5b6()
{
  long long lVar1;
  long long lVar2;
  int in_r0 = 0;
  int iVar3;
  unsigned int uVar4;
  char *puVar5;
  char *puVar6;
  int iVar7;

  puVar5 = *(char **)(DAT_0602f5ea + in_r0);
  puVar6 = (char *)0x00000000;
  if (((int)0x00000000 < (int)puVar5) && (puVar6 = puVar5, (int)0x00002134 <= (int)puVar5))
  {
    puVar6 = (char *)0x00002134;
  }
  lVar1 = (long long)*(int *)(*(int *)(DAT_0602f6e2 + in_r0) + ((unsigned int)puVar6 >> 7) << 2) *
          (long long)*(int *)(0x060477BC + *(short *)(DAT_0602f6e0 + in_r0) << 2);
  lVar1 = (long long)
          (int)(((int)((unsigned long long)
                       ((long long)*(int *)(0x06045AEC + *(int *)(DAT_0602f5e8 + in_r0) << 2) *
                       (long long)(int)0x00016666) >> 0x20) << 0x10 |
                (unsigned int)((long long)*(int *)(0x06045AEC + *(int *)(DAT_0602f5e8 + in_r0) << 2) *
                      (long long)(int)0x00016666) >> 0x10) - (int)0x00006666) *
          (long long)(int)((int)((unsigned long long)lVar1 >> 0x20) << 0x10 | (unsigned int)lVar1 >> 0x10);
  iVar3 = (*(int(*)())0x0602755C)(*(int *)(DAT_0602f6e4 + in_r0) << 0x10,0x00019999);
  *(unsigned int *)(DAT_0602f6e6 + in_r0) =
       ((int)((unsigned long long)lVar1 >> 0x20) << 0x10 | (unsigned int)lVar1 >> 0x10) - iVar3;
  lVar1 = (long long)*(int *)(0x06045AEC + *(int *)(DAT_0602f6e8 + in_r0) << 2) *
          (long long)*(int *)(0x06045AEC + *(int *)(DAT_0602f6e8 + in_r0) << 2);
  uVar4 = (int)((unsigned long long)lVar1 >> 0x20) << 0x10 | (unsigned int)lVar1 >> 0x10;
  lVar1 = (long long)0x0B400000 * (long long)(int)uVar4;
  lVar2 = (long long)(int)0x07800000 * (long long)(int)uVar4;
  *(unsigned int *)(DAT_0602f6ea + in_r0) = (int)((unsigned long long)lVar1 >> 0x20) << 0x10 | (unsigned int)lVar1 >> 0x10;
  *(unsigned int *)(DAT_0602f6ec + in_r0) = (int)((unsigned long long)lVar2 >> 0x20) << 0x10 | (unsigned int)lVar2 >> 0x10;
  iVar3 = *(int *)(DAT_0602f6ee + in_r0);
  if (0 < iVar3) {
    iVar3 = iVar3 >> 1;
  }
  puVar6 = (char *)0x06400000;
  iVar3 = (*(int(*)())0x06027348)(iVar3);
  iVar7 = (int)((unsigned long long)((long long)(int)puVar6 * (long long)iVar3) >> 0x20);
  *(int *)(DAT_0602f6f0 + in_r0) =
       (int)(iVar7 << 0x10 | (unsigned int)((long long)(int)puVar6 * (long long)iVar3) >> 0x10) >> 1;
  uVar4 = *(unsigned int *)(0x060454CC + *(int *)(in_r0 + 8) << 2);
  if (0 < *(short *)(DAT_0602f6f2 + in_r0)) {
    iVar7 = (int)((unsigned long long)((long long)(int)uVar4 * (long long)(int)DAT_0602f6f4) >> 0x20);
    uVar4 = iVar7 << 0x10 | (unsigned int)((long long)(int)uVar4 * (long long)(int)DAT_0602f6f4) >> 0x10;
  }
  iVar3 = FUN_0602f71c();
  *(int *)(DAT_0602f6f6 + iVar3) = (int)(uVar4 + iVar7) >> 1;
  return;
}

/* wheel_surface_type_classify -- Classify wheel surface type from contact flags.
 * Implicit r0 = car object pointer. Reads 4 wheel collision flag words at
 * obj+DAT_0602f788, checks each against mask DAT_0602f786 for surface contact.
 * Counts contacting wheels (0-4). If zero → no surface. Otherwise checks
 * combined flags for airborne (bit 0x10) and speed category (DAT_0602f78a)
 * to determine surface type. Always returns 0 in current L1 form. */
int FUN_0602f71c()
{
  short sVar1;
  int in_r0 = 0;
  unsigned int *puVar2;
  unsigned int uVar3;
  unsigned char bVar4;

  uVar3 = (unsigned int)DAT_0602f786;
  puVar2 = (unsigned int *)(DAT_0602f788 + in_r0);
  bVar4 = (uVar3 & *puVar2) != 0;
  if ((uVar3 & puVar2[1]) != 0) {
    bVar4 = bVar4 + 1;
  }
  if ((uVar3 & puVar2[2]) != 0) {
    bVar4 = bVar4 + 1;
  }
  if ((uVar3 & puVar2[3]) != 0) {
    bVar4 = bVar4 + 1;
  }
  if (bVar4 == 0) {
    return 0;
  }
  if ((((*puVar2 | puVar2[1] | puVar2[2] | puVar2[3]) & 0x10) == 0) &&
     (sVar1 = *(short *)(DAT_0602f78a + in_r0), sVar1 < 10)) {
    if (7 < sVar1) {
      return 0;
    }
    if ((sVar1 != 4) && (sVar1 != 5)) {
      if (bVar4 < 3) {
        return 0;
      }
      return 0;
    }
  }
  return 0;
}

/* car_cooldown_timers_tick -- Decrement car cooldown timers each frame.
 * Implicit r0 = car object pointer. Decrements three independent timers
 * at obj+DAT_0602f7e4 (short), obj+DAT_0602f7e6 (short), and
 * obj+DAT_0602f7e8 (int) toward zero, stopping at zero. Used for
 * collision immunity, sound cooldown, and effect duration tracking. */
void FUN_0602f7bc()
{
  short timer;
  int car = 0; /* implicit r0 = car pointer */
  int general_timer;

  /* Decrement slide/drift timer */
  timer = *(short *)(car + CAR_SLIDE_TIMER);
  if (timer != 0) {
    *(short *)(car + CAR_SLIDE_TIMER) = timer + -1;
  }
  /* Decrement spin event timer */
  timer = *(short *)(car + CAR_SPIN_TIMER);
  if (timer != 0) {
    *(short *)(car + CAR_SPIN_TIMER) = timer + -1;
  }
  /* Decrement general timer */
  general_timer = *(int *)(car + CAR_GENERAL_TIMER);
  if (general_timer != 0) {
    *(int *)(car + CAR_GENERAL_TIMER) = general_timer + -1;
  }
  return;
}

/* car_sound_effects_update -- Update car sound effects based on game state.
 * Checks checkpoint position against music trigger zones per course.
 * Computes engine volume from RPM (clamped 1-127), sends to SCSP channel 1.
 * Triggers collision/surface sounds on specific car states.
 * Computes tire screech volume from lateral velocity (>>10, max 7).
 * SCSP command function at 0x0601D5F4, sound IDs use 0xAExxxxFF format. */
void FUN_0602f7ea()
{
  char cooldown_val;
  short surface_type;
  char *scsp_cmd;       /* 0x0601D5F4 — SCSP command sender */
  char *cooldown_ptr;
  short *trigger_range;
  int trigger_count;
  int sound_id;
  unsigned int screech_level;
  unsigned int *player_car;
  scsp_cmd = (char *)0x0601D5F4;
  player_car = *(unsigned int **)0x0607E944;
  /* Check checkpoint-based music triggers for current course */
  trigger_count = (int)*(short *)(0x0602FD3C + *(int *)(0x0607EAD8 << 2));
  if (trigger_count != 0) {
    trigger_range = (short *)(0x0602FD48 +
                      *(short *)((int)(0x0602FD3C + *(int *)(0x0607EAD8 << 2)) + 2));
    do {
      /* Check if car checkpoint is within trigger range */
      if (((int)*trigger_range <= *(int *)((int)DAT_0602f842 + (int)player_car)) &&
         (*(int *)((int)DAT_0602f842 + (int)player_car) <= (int)trigger_range[1])) {
        /* In range and speed > 0x100000: trigger zone music */
        if (0x100000 < (int)player_car[5]) {
          if (((int)DAT_0602f844 & *player_car) == 0) {
            *player_car = *player_car | (int)DAT_0602f844;
            (*(int(*)())scsp_cmd)(4,0xAE0601FF);  /* zone music ON */
          }
        }
        goto LAB_0602f87c;
      }
      trigger_count = trigger_count + -1;
      trigger_range = trigger_range + 2;
    } while (trigger_count != 0);
    /* Left all trigger zones: stop zone music */
    if (((int)DAT_0602f890 & *player_car) != 0) {
      *player_car = *player_car & ~(int)DAT_0602f890;
      (*(int(*)())scsp_cmd)(4,0xAE0600FF);         /* zone music OFF */
    }
  }
LAB_0602f87c:
  /* Engine volume from RPM (channel 1) */
  trigger_count = FUN_0602eccc();
  if (trigger_count < 2) {
    trigger_count = 1;                              /* minimum volume */
  }
  else if (0x7e < trigger_count) {
    trigger_count = 0x7f;                           /* maximum volume */
  }
  (*(int(*)())scsp_cmd)(1,trigger_count);
  /* Collision/surface sounds (channel 0) */
  if ((*(int *)((int)DAT_0602f8f0 + (int)player_car) == 0) &&
     (surface_type = *(short *)((int)DAT_0602f8f2 + (int)player_car), surface_type != 0)) {
    if (surface_type == 10) {
      sound_id = 0xAE111EFF;                        /* gravel surface */
      if (*(int *)0x0605D241 != '\0') {
        sound_id = 0xAE1142FF;                      /* alternate gravel */
      }
    }
    else {
      if (surface_type != 3) goto LAB_0602f910;
      sound_id = 0xAE111CFF;                        /* grass surface */
      if (*(int *)0x0605D241 != '\0') {
        sound_id = 0xAE1140FF;                      /* alternate grass */
      }
    }
    (*(int(*)())scsp_cmd)(0,sound_id);
  }
LAB_0602f910:
  /* Braking sound when car state == 0x2C */
  if (*(int *)(0xb8 + (int)player_car) == 0x2c) {
    sound_id = 0xAE111BFF;                          /* brake screech */
    if (*(int *)0x0605D241 != '\0') {
      sound_id = 0xAE113FFF;                        /* alternate brake */
    }
    (*(int(*)())scsp_cmd)(0,sound_id);
  }
  /* Crash sound with cooldown timer (channel 3) */
  cooldown_ptr = (char *)0x0602FD9F;
  cooldown_val = *(int *)0x0602FD9F;
  if (cooldown_val == '\0') {
LAB_0602f93e:
    if ((player_car[3] == 0) || (*(int *)((int)player_car + (int)DAT_0602f980) < 0xc9)) goto LAB_0602f95a;
    *cooldown_ptr = 10;                             /* reset cooldown to 10 frames */
    sound_id = 1;
  }
  else {
    sound_id = 0;
    *(int *)0x0602FD9F = cooldown_val + -1;         /* decrement cooldown */
    if (cooldown_val != '\x01') goto LAB_0602f93e;
  }
  (*(int(*)())scsp_cmd)(3,sound_id);
LAB_0602f95a:
  /* Tire screech volume from lateral velocity (channel 2) */
  screech_level = *(unsigned int *)((int)player_car + (int)DAT_0602f982);
  if ((int)screech_level < 0) {
    screech_level = -screech_level;
  }
  screech_level = screech_level >> 10;
  if (7 < screech_level) {
    screech_level = 7;                              /* max screech level */
  }
  (*(int(*)())scsp_cmd)(2,screech_level);
  return;
}

/* race_sfx_update -- Race sound effects trigger system.
 * Per-frame update that triggers SCSP sound commands based on race state:
 *   - Countdown timers: tire screech (0xAE1103/04), engine rev (0xAE1110-13)
 *   - Idle engine: start (0xAE1119) / stop (0xAE111A/3E) based on car speed
 *   - Proximity: overtake warning (0xAE1135), closing (0xAE113A/1130)
 *   - Gear shift sound (0xAE1132), engine rev (0xAE1137)
 *   - Track-section sounds, high-speed (0xAE112C), wall impact (0xAE112E)
 *
 * All sounds dispatched via sound_cmd_dispatch (0x0601D5F4) to SCSP slot 0x11.
 * Sound timer state at 0x0602FD98-0x0602FDA1.
 * Global cooldown at 0x06086054 (short, decremented each frame).
 *
 * Called from car_iteration.c per-frame loop. */
unsigned int race_sfx_update()
{

  int uVar1;

  char *puVar2;

  char *puVar3;

  int iVar4;

  unsigned int uVar5;

  char cVar6;

  unsigned int *puVar7;

  int iVar8;

  int uVar9;

  int iVar10;

  short *psVar11;

  unsigned int *puVar12;

  puVar3 = (char *)0x0602FD98;

  puVar2 = (char *)0x0601D5F4;

  puVar12 = *(unsigned int **)0x0607E944;

  if (((char)*(int *)0x0602FD98 != 0) &&

     (iVar4 = (char)*(int *)0x0602FD98 + -1, *(int *)0x0602FD98 = (char)iVar4, iVar4 == 2)) {

    (*(int(*)())puVar2)(0,0xAE1103FF);

  }

  if (((char)puVar3[1] != 0) && (iVar4 = (char)puVar3[1] + -1, puVar3[1] = (char)iVar4, iVar4 == 2))

  {

    (*(int(*)())puVar2)(0,0xAE1104FF);

  }

  if (((char)puVar3[2] != 0) && (iVar4 = (char)puVar3[2] + -1, puVar3[2] = (char)iVar4, iVar4 == 2))

  {

    (*(int(*)())puVar2)(0,0xAE1104FF);

  }

  uVar1 = 0xAE1112FF;

  uVar9 = 0xAE1110FF;

  if ((char)*(int *)0x0602FD9B == 0) {

    if ((char)((int *)0x0602FD9B)[1] == 0) goto LAB_0602fa42;

    iVar4 = (char)((int *)0x0602FD9B)[1] + -1;

    ((int *)0x0602FD9B)[1] = (char)iVar4;

    uVar9 = uVar1;

    uVar1 = 0xAE1113FF;

  }

  else {

    iVar4 = (char)*(int *)0x0602FD9B + -1;

    *(int *)0x0602FD9B = (char)iVar4;

    uVar1 = 0xAE1111FF;

  }

  if ((iVar4 == 4) || (uVar9 = uVar1, iVar4 == 0)) {

    (*(int(*)())puVar2)(0,uVar9);

  }

LAB_0602fa42:

  puVar3 = (char *)0x0602FD9D;

  uVar5 = CAR_COUNT;

  if (uVar5 == 0) {

    cVar6 = *(int *)0x0602FD9D;

    uVar5 = (unsigned int)(char)((int *)0x0602FD9D)[1];

    if ((int)uVar5 < 1) {

      if ((*(int *)((int)PTR_DAT_0602fa60 + (int)puVar12) == 0) ||

         (0x1e < *(int *)((int)PTR_DAT_0602fa60 + (int)puVar12))) {

        if (cVar6 != '\0') {

          uVar9 = 0xAE111AFF;

          if (*(int *)0x0605D241 != '\0') {

            uVar9 = 0xAE113EFF;

          }

          uVar5 = (*(int(*)())puVar2)(0,uVar9);

          cVar6 = '\0';

        }

      }

      else {

        (*(int(*)())puVar2)(0,0xAE1119FF);

        uVar5 = 0x14;

        cVar6 = '\x01';

      }

    }

    else {

      uVar5 = uVar5 - 1;

    }

    *puVar3 = cVar6;

    puVar3[1] = (char)uVar5;

  }

  puVar3 = (char *)0x06086054;

  if (*(short *)0x06086054 == 0) {

    uVar5 = *puVar12;

    if ((uVar5 & 8) == 0) {

      if (DEMO_MODE_FLAG == 0) {

        iVar8 = *(int *)0x0607EA98 + -1;

        puVar7 = *(unsigned int **)0x0607E948;

        iVar4 = 0;

        iVar10 = 0;

        while( 1 ) {

          for (; (0x01800000 == (char *)(*puVar7 & (unsigned int)0x01800000) ||

                 (0x01400000 == (char *)(*puVar7 & (unsigned int)0x01400000)));

              puVar7 = (unsigned int *)((int)puVar7 + 0x268)) {

            iVar4 = iVar4 + 1;

            if (iVar4 == 2) {

              if (*(int *)0x0602FDA1 == '\0') {

                if ((int)puVar7[3] <= (int)puVar12[3]) {

                  *(int *)0x0602FDA1 = 10;

                  uVar5 = (*(int(*)())puVar2)(0,0xAE1135FF);

                  *(short *)puVar3 = (char *)0x3c;

                  return uVar5;

                }

              }

              else {

                *(int *)0x0602FDA1 = *(int *)0x0602FDA1 + -1;

              }

              goto LAB_0602fbb4;

            }

            iVar8 = iVar8 + -1;

            if (iVar8 == 0) goto LAB_0602fb6c;

          }

          if (0x02C00000 == (char *)(*puVar7 & (unsigned int)0x02C00000)) {

            iVar10 = iVar10 + 1;

          }

          iVar8 = iVar8 + -1;

          if (iVar8 == 0) break;

          puVar7 = (unsigned int *)((int)puVar7 + 0x268);

        }

LAB_0602fb6c:

        if (0 < iVar10) {

          if (*(int *)0x0602FDA0 == '\0') {

            if (-1 < (int)(puVar7[3] - puVar12[3])) {

              uVar9 = 0xAE113AFF;

              if ((int)(unsigned int)DAT_0602fba8 <= (int)(puVar7[3] - puVar12[3])) {

                uVar9 = 0xAE1130FF;

              }

              *(int *)0x0602FDA0 = 3;

              uVar5 = (*(int(*)())puVar2)(0,uVar9);

              *(short *)puVar3 = (char *)0x3c;

              return uVar5;

            }

          }

          else {

            *(int *)0x0602FDA0 = *(int *)0x0602FDA0 + -1;

          }

        }

      }

LAB_0602fbb4:

      if (*(int *)((int)puVar12 + (int)DAT_0602fbca) == 1) {

        uVar5 = (*(int(*)())puVar2)(0,0xAE1132FF);

        *(short *)puVar3 = (char *)0x3c;

      }

      else if ((int)(char)*(int *)0x0602FD9B + (int)(char)((int *)0x0602FD9B)[1]

               == 1) {

        uVar5 = (*(int(*)())puVar2)(0,0xAE1137FF);

        *(short *)puVar3 = (char *)0x3c;

      }

      else {

        iVar4 = (int)*(short *)(0x0602FD54 + *(int *)(0x0607EAD8 << 2));

        for (psVar11 = (short *)(0x0602FD60 +

                                *(short *)((int)(0x0602FD54 + *(int *)(0x0607EAD8 << 2)) +

                                          2));

            *(int *)((int)puVar12 + (int)PTR_DAT_0602fc14) != (int)*psVar11;

            psVar11 = psVar11 + 2) {

          iVar4 = iVar4 + -1;

          if (iVar4 == 0) goto LAB_0602fcc0;

        }

        iVar4 = (int)psVar11[1];

        if (iVar4 == 2) {

          if (((int)DAT_0602fc9c <= (int)puVar12[2]) &&

             (0x17ff < *(int *)((int)puVar12 + (int)DAT_0602fc9e))) {

            uVar5 = (*(int(*)())puVar2)(0,0xAE1136FF);

            *(short *)puVar3 = (char *)0x3c;

            return uVar5;

          }

        }

        else if (iVar4 == 3) {

          if ((int)PTR_DAT_0602fcb8 <= (int)puVar12[2]) {

            uVar5 = (*(int(*)())puVar2)(0,0xAE112CFF);

            *(short *)puVar3 = (char *)0x3c;

            return uVar5;

          }

        }

        else if ((*(int *)((int)DAT_0602fc74 + (int)puVar12) +

                  *(int *)((int)DAT_0602fc72 + (int)puVar12) +

                  (int)*(short *)((int)DAT_0602fc70 + (int)puVar12) +

                  (int)*(short *)((int)DAT_0602fc6e + (int)puVar12) == 0) &&

                ((*(unsigned int *)((int)DAT_0602fc76 + (int)puVar12) & 1) != 0)) {

          uVar5 = (*(int(*)())puVar2)(0,*(int *)(0x0602FD30 + (iVar4 << 2)));

          *(short *)puVar3 = (char *)0x3c;

          return uVar5;

        }

LAB_0602fcc0:

        if ((*(int *)((int)puVar12 + (int)PTR_DAT_0602fcdc) == 1) &&

           ((int)0x00028000 < (int)puVar12[3])) {

          uVar5 = (*(int(*)())puVar2)(0,0xAE1131FF);

          *(short *)puVar3 = (char *)0x3c;

        }

        else {

          uVar5 = CAR_COUNT;

          if ((uVar5 == 1) &&

             (((*(int *)((int)DAT_0602fd1a + (int)puVar12) == 0xe0 ||

               (*(int *)((int)DAT_0602fd1a + (int)puVar12) == 0xe1)) &&

              (uVar5 = puVar12[5], 0xa0000 < (int)uVar5)))) {

            uVar5 = (*(int(*)())puVar2)(0,0xAE112EFF);

            *(short *)puVar3 = (char *)0x3c;

          }

        }

      }

    }

  }

  else {

    *(short *)0x06086054 = *(short *)0x06086054 + -1;

  }

  return uVar5;

}

/* --- FUN_0602F99C (L1 import from src/FUN_0602F99C.c) --- */

unsigned int FUN_0602f99c()
{

  int uVar1;

  char *puVar2;

  char *puVar3;

  int iVar4;

  unsigned int uVar5;

  char cVar6;

  unsigned int *puVar7;

  int iVar8;

  int uVar9;

  int iVar10;

  short *psVar11;

  unsigned int *puVar12;

  puVar3 = (char *)0x0602FD98;

  puVar2 = (char *)0x0601D5F4;

  puVar12 = *(unsigned int **)0x0607E944;

  if (((char)*(int *)0x0602FD98 != 0) &&

     (iVar4 = (char)*(int *)0x0602FD98 + -1, *(int *)0x0602FD98 = (char)iVar4, iVar4 == 2)) {

    (*(int(*)())puVar2)(0,0xAE1103FF);

  }

  if (((char)puVar3[1] != 0) && (iVar4 = (char)puVar3[1] + -1, puVar3[1] = (char)iVar4, iVar4 == 2))

  {

    (*(int(*)())puVar2)(0,0xAE1104FF);

  }

  if (((char)puVar3[2] != 0) && (iVar4 = (char)puVar3[2] + -1, puVar3[2] = (char)iVar4, iVar4 == 2))

  {

    (*(int(*)())puVar2)(0,0xAE1104FF);

  }

  uVar1 = 0xAE1112FF;

  uVar9 = 0xAE1110FF;

  if ((char)*(int *)0x0602FD9B == 0) {

    if ((char)((int *)0x0602FD9B)[1] == 0) goto LAB_0602fa42;

    iVar4 = (char)((int *)0x0602FD9B)[1] + -1;

    ((int *)0x0602FD9B)[1] = (char)iVar4;

    uVar9 = uVar1;

    uVar1 = 0xAE1113FF;

  }

  else {

    iVar4 = (char)*(int *)0x0602FD9B + -1;

    *(int *)0x0602FD9B = (char)iVar4;

    uVar1 = 0xAE1111FF;

  }

  if ((iVar4 == 4) || (uVar9 = uVar1, iVar4 == 0)) {

    (*(int(*)())puVar2)(0,uVar9);

  }

LAB_0602fa42:

  puVar3 = (char *)0x0602FD9D;

  uVar5 = *(unsigned int *)0x0607EAD8;

  if (uVar5 == 0) {

    cVar6 = *(int *)0x0602FD9D;

    uVar5 = (unsigned int)(char)((int *)0x0602FD9D)[1];

    if ((int)uVar5 < 1) {

      if ((*(int *)((int)PTR_DAT_0602fa60 + (int)puVar12) == 0) ||

         (0x1e < *(int *)((int)PTR_DAT_0602fa60 + (int)puVar12))) {

        if (cVar6 != '\0') {

          uVar9 = 0xAE111AFF;

          if (*(int *)0x0605D241 != '\0') {

            uVar9 = 0xAE113EFF;

          }

          uVar5 = (*(int(*)())puVar2)(0,uVar9);

          cVar6 = '\0';

        }

      }

      else {

        (*(int(*)())puVar2)(0,0xAE1119FF);

        uVar5 = 0x14;

        cVar6 = '\x01';

      }

    }

    else {

      uVar5 = uVar5 - 1;

    }

    *puVar3 = cVar6;

    puVar3[1] = (char)uVar5;

  }

  puVar3 = (char *)0x06086054;

  if (*(short *)0x06086054 == 0) {

    uVar5 = *puVar12;

    if ((uVar5 & 8) == 0) {

      if (*(int *)0x0607EAE0 == 0) {

        iVar8 = *(int *)0x0607EA98 + -1;

        puVar7 = *(unsigned int **)0x0607E948;

        iVar4 = 0;

        iVar10 = 0;

        while( 1 ) {

          for (; (0x01800000 == (char *)(*puVar7 & (unsigned int)0x01800000) ||

                 (0x01400000 == (char *)(*puVar7 & (unsigned int)0x01400000)));

              puVar7 = (unsigned int *)((int)puVar7 + 0x268)) {

            iVar4 = iVar4 + 1;

            if (iVar4 == 2) {

              if (*(int *)0x0602FDA1 == '\0') {

                if ((int)puVar7[3] <= (int)puVar12[3]) {

                  *(int *)0x0602FDA1 = 10;

                  uVar5 = (*(int(*)())puVar2)(0,0xAE1135FF);

                  *(short *)puVar3 = (char *)0x3c;

                  return uVar5;

                }

              }

              else {

                *(int *)0x0602FDA1 = *(int *)0x0602FDA1 + -1;

              }

              goto LAB_0602fbb4;

            }

            iVar8 = iVar8 + -1;

            if (iVar8 == 0) goto LAB_0602fb6c;

          }

          if (0x02C00000 == (char *)(*puVar7 & (unsigned int)0x02C00000)) {

            iVar10 = iVar10 + 1;

          }

          iVar8 = iVar8 + -1;

          if (iVar8 == 0) break;

          puVar7 = (unsigned int *)((int)puVar7 + 0x268);

        }

LAB_0602fb6c:

        if (0 < iVar10) {

          if (*(int *)0x0602FDA0 == '\0') {

            if (-1 < (int)(puVar7[3] - puVar12[3])) {

              uVar9 = 0xAE113AFF;

              if ((int)(unsigned int)DAT_0602fba8 <= (int)(puVar7[3] - puVar12[3])) {

                uVar9 = 0xAE1130FF;

              }

              *(int *)0x0602FDA0 = 3;

              uVar5 = (*(int(*)())puVar2)(0,uVar9);

              *(short *)puVar3 = (char *)0x3c;

              return uVar5;

            }

          }

          else {

            *(int *)0x0602FDA0 = *(int *)0x0602FDA0 + -1;

          }

        }

      }

LAB_0602fbb4:

      if (*(int *)((int)puVar12 + (int)DAT_0602fbca) == 1) {

        uVar5 = (*(int(*)())puVar2)(0,0xAE1132FF);

        *(short *)puVar3 = (char *)0x3c;

      }

      else if ((int)(char)*(int *)0x0602FD9B + (int)(char)((int *)0x0602FD9B)[1]

               == 1) {

        uVar5 = (*(int(*)())puVar2)(0,0xAE1137FF);

        *(short *)puVar3 = (char *)0x3c;

      }

      else {

        iVar4 = (int)*(short *)(0x0602FD54 + *(int *)(0x0607EAD8 << 2));

        for (psVar11 = (short *)(0x0602FD60 +

                                *(short *)((int)(0x0602FD54 + *(int *)(0x0607EAD8 << 2)) +

                                          2));

            *(int *)((int)puVar12 + (int)PTR_DAT_0602fc14) != (int)*psVar11;

            psVar11 = psVar11 + 2) {

          iVar4 = iVar4 + -1;

          if (iVar4 == 0) goto LAB_0602fcc0;

        }

        iVar4 = (int)psVar11[1];

        if (iVar4 == 2) {

          if (((int)DAT_0602fc9c <= (int)puVar12[2]) &&

             (0x17ff < *(int *)((int)puVar12 + (int)DAT_0602fc9e))) {

            uVar5 = (*(int(*)())puVar2)(0,0xAE1136FF);

            *(short *)puVar3 = (char *)0x3c;

            return uVar5;

          }

        }

        else if (iVar4 == 3) {

          if ((int)PTR_DAT_0602fcb8 <= (int)puVar12[2]) {

            uVar5 = (*(int(*)())puVar2)(0,0xAE112CFF);

            *(short *)puVar3 = (char *)0x3c;

            return uVar5;

          }

        }

        else if ((*(int *)((int)DAT_0602fc74 + (int)puVar12) +

                  *(int *)((int)DAT_0602fc72 + (int)puVar12) +

                  (int)*(short *)((int)DAT_0602fc70 + (int)puVar12) +

                  (int)*(short *)((int)DAT_0602fc6e + (int)puVar12) == 0) &&

                ((*(unsigned int *)((int)DAT_0602fc76 + (int)puVar12) & 1) != 0)) {

          uVar5 = (*(int(*)())puVar2)(0,*(int *)(0x0602FD30 + (iVar4 << 2)));

          *(short *)puVar3 = (char *)0x3c;

          return uVar5;

        }

LAB_0602fcc0:

        if ((*(int *)((int)puVar12 + (int)PTR_DAT_0602fcdc) == 1) &&

           ((int)0x00028000 < (int)puVar12[3])) {

          uVar5 = (*(int(*)())puVar2)(0,0xAE1131FF);

          *(short *)puVar3 = (char *)0x3c;

        }

        else {

          uVar5 = *(unsigned int *)0x0607EAD8;

          if ((uVar5 == 1) &&

             (((*(int *)((int)DAT_0602fd1a + (int)puVar12) == 0xe0 ||

               (*(int *)((int)DAT_0602fd1a + (int)puVar12) == 0xe1)) &&

              (uVar5 = puVar12[5], 0xa0000 < (int)uVar5)))) {

            uVar5 = (*(int(*)())puVar2)(0,0xAE112EFF);

            *(short *)puVar3 = (char *)0x3c;

          }

        }

      }

    }

  }

  else {

    *(short *)0x06086054 = *(short *)0x06086054 + -1;

  }

  return uVar5;

}
