#include "game.h"

extern int DAT_0600c2a6;
extern int DAT_0600c36a;
extern int DAT_0600c36c;
extern int DAT_0600c36e;
extern int DAT_0600c370;
extern int DAT_0600c372;
extern int DAT_0600c416;
extern int DAT_0600c418;
extern int DAT_0600c41a;
extern int DAT_0600c616;
extern int DAT_0600c6f6;
extern int DAT_0600c6f8;
extern int DAT_0600c6fa;
extern int DAT_0600c6fc;
extern int DAT_0600c6fe;
extern int DAT_0600c700;
extern int DAT_0600c702;
extern int DAT_0600c7be;
extern int DAT_0600c7c0;
extern int DAT_0600c8b6;
extern int DAT_0600c8b8;
extern int DAT_0600c8ba;
extern int DAT_0600c8bc;
extern int DAT_0600c8be;
extern int DAT_0600c8c0;
extern int DAT_0600c8c2;
extern int DAT_0600c962;
extern int DAT_0600c964;
extern int DAT_0600c9e4;
extern int DAT_0600c9e6;
extern int DAT_0600cac0;
extern int DAT_0600cac2;
extern int DAT_0600cb84;
extern int DAT_0600cb86;
extern int DAT_0600cc2a;
extern int DAT_0600ccf6;
extern int DAT_0600ccf8;
extern int DAT_0600ccfa;
extern int DAT_0600cdbc;
extern int DAT_0600cdbe;
extern int DAT_0600cdc0;
extern int DAT_0600cdc2;
extern int DAT_0600ce8e;
extern int DAT_0600cf3a;
extern int DAT_0600cf40;
extern int DAT_0600cf42;
extern int DAT_0600cfe2;
extern int DAT_0600cfe4;
extern int DAT_0600cfe6;
extern int DAT_0600d0aa;
extern int DAT_0600d0ac;
extern int DAT_0600d0ae;
extern int DAT_0600d0b0;
extern int DAT_0600d0b2;
extern int DAT_0600d0b4;
extern int DAT_0600d0b6;
extern int DAT_0600d112;
extern int DAT_0600d114;
extern int DAT_0600d116;
extern int DAT_0600d118;
extern int DAT_0600d11a;
extern int DAT_0600d192;
extern int DAT_0600d1fa;
extern int DAT_0600d1fc;
extern int DAT_0600d1fe;
extern int DAT_0600d200;
extern int DAT_0600d202;
extern int DAT_0600d204;
extern int DAT_0600d206;
extern int DAT_0600d26a;
extern int DAT_0600d26c;
extern int DAT_0600d26e;
extern int DAT_0600d270;
extern int DAT_0600d272;
extern int DAT_0600d4a6;
extern int DAT_0600d534;
extern int DAT_0600d536;
extern int DAT_0600d5d6;
extern int DAT_0600d6ba;
extern int DAT_0600d76a;
extern int DAT_0600d82a;
extern int DAT_0600d82c;
extern int DAT_0600d82e;
extern int DAT_0600d894;
extern int DAT_0600d896;
extern int DAT_0600d996;
extern int DAT_0600d998;
extern int DAT_0600d99a;
extern int DAT_0600db40;
extern int DAT_0600db44;
extern int DAT_0600db46;
extern int DAT_0600dbda;
extern int DAT_0600dbdc;
extern int DAT_0600dbde;
extern int DAT_0600dc98;
extern int DAT_0600dc9a;
extern int DAT_0600dc9c;
extern int DAT_0600dc9e;
extern int DAT_0600dd62;
extern int DAT_0600de1e;
extern int DAT_0600deb2;
extern void FUN_0600c7d4();
extern int FUN_0600c8cc();
extern void FUN_0600c928();
extern int FUN_0600c970();
extern void FUN_0600ca96();
extern void FUN_0600cc38();
extern int * FUN_0600cd40();
extern int FUN_0600cdd0();
extern unsigned int FUN_0600cf58();
extern int FUN_0600d0b8();
extern int FUN_0600d12c();
extern int FUN_0600d210();
extern void FUN_0600d37c();
extern void FUN_0600d3c4();
extern void FUN_0600d50c();
extern int FUN_0600d84c();
extern int FUN_0600d8a4();
extern int FUN_0600d92c();
extern void FUN_0600d9bc();
extern unsigned int FUN_0600db9e();
extern void FUN_0600dc74();
extern int FUN_0600dcc8();
extern int FUN_0600e0c0();
extern int FUN_0600e410();
extern int FUN_0600e47c();
extern int FUN_0600e4f2();
extern int FUN_0600e99c();
extern int PTR_DAT_0600c2a8;
extern int PTR_DAT_0600c374;
extern int PTR_DAT_0600c618;
extern int PTR_DAT_0600cb88;
extern int PTR_DAT_0600cfe8;
extern int PTR_DAT_0600d11c;
extern int PTR_DAT_0600d194;
extern int PTR_DAT_0600d208;
extern int PTR_DAT_0600d274;
extern int PTR_DAT_0600d304;
extern int PTR_DAT_0600d408;
extern int PTR_DAT_0600d770;
extern int PTR_DAT_0600d99c;
extern short DAT_0600c590;
extern short DAT_0600c594;
extern short DAT_0600c596;
extern short DAT_0600c598;
extern short DAT_0600c59a;
extern short DAT_0600ce86;
extern short DAT_0600ce88;
extern short DAT_0600ce8a;
extern short DAT_0600ce8c;
extern short DAT_0600d404;
extern short DAT_0600d406;
extern short PTR_DAT_0600c59c;

/* render_frame_basic -- Basic render frame for single-player race replay.
 * Copies primary render state to secondary (+0x30 block), runs main rendering
 * pipeline (camera, world tiles, objects), waits for VDP1 completion,
 * then restores secondary state. */
void FUN_0600c218(void)
{
    unsigned short ready_mask = PTR_DAT_0600c2a8;
    unsigned char *vdp_status = (unsigned char *)-495;  /* VDP1 status port */
    int saved = OBJ_STATE_SECONDARY;

    OBJ_STATE_SECONDARY = saved + 0x30;
    (*(int(*)())0x06027630)(saved + 0x30, OBJ_STATE_PRIMARY, 0x30);  /* memcpy render state */

    (*(int(*)())0x0600D31C)();                /* camera update */
    *(int *)0x06063574 = 0x0600C286;          /* set render callback */
    *(short *)0x21000000 = (short)0x0000FFFF; /* SCU DMA trigger */
    (*(int(*)())0x060058FA)();                /* HUD sprites */
    (*(int(*)())0x06006868)();                /* world tile rendering */
    (*(int(*)())0x0601BDEC)();                /* object rendering */

    /* Wait for VDP1 draw completion */
    do { } while ((*vdp_status & ready_mask) != ready_mask);
    *vdp_status = *vdp_status & 0xf;

    (*(int(*)())0x0603C000)();                /* finalize frame */
    OBJ_STATE_SECONDARY -= 0x30;
}

/* heading_expand_and_zone_update -- Expand heading value and update zone timers.
 * Writes CAR_HEADING_EXP (+0x68 << 5) to projected fields (+0xE0, +0xE4).
 * Decrements two zone timers if positive.
 * Then checks zone conditions to set 18-frame countdown timers at +0x172/+0x174. */
int FUN_0600c302(void)
{
    int base = CAR_PTR_TARGET;
    int expanded = *(int *)(base + CAR_HEADING_EXP) << 5;

    *(int *)(base + CAR_PROJECTED_B) = expanded;
    *(int *)(base + CAR_PROJECTED_A) = expanded;

    /* Decrement zone timers */
    if (0 < *(short *)(base + DAT_0600c36a))
        *(short *)(base + DAT_0600c36a) -= 1;
    if (0 < *(short *)(base + DAT_0600c36c))
        *(short *)(base + DAT_0600c36c) -= 1;

    /* Zone state checks */
    if (*(short *)(base + DAT_0600c36e) != 0)
        return (int)*(short *)(base + DAT_0600c36e);

    if ((int)DAT_0600c370 <= *(int *)(base + CAR_HEADING_EXP)) {
        *(short *)(base + CAR_TIMER_172) = 0x12;
        *(short *)(base + CAR_TIMER_174) = 0;
        return CAR_TIMER_174;
    }

    if (*(int *)(base + DAT_0600c372) < (int)PTR_DAT_0600c374)
        return (int)DAT_0600c372;

    if (0x9b < *(int *)(base + CAR_HEADING_EXP) &&
        *(int *)(base + CAR_HEADING_EXP) < (int)DAT_0600c418) {
        *(short *)(base + CAR_TIMER_172) = 0;
        *(short *)(base + CAR_TIMER_174) = 0x12;
        return CAR_TIMER_174;
    }

    return CAR_HEADING_EXP;
}

unsigned short FUN_0600c3a8(param_1)
    unsigned short param_1;
{

  char *puVar1;

  unsigned short uVar2;

  int iVar3;

  short uVar4;

  puVar1 = (int *)0x06063E20;

  if ((char *)(unsigned int)*(unsigned short *)0x0607865E == 0x00008000) {

    if ((param_1 & *(unsigned short *)0x06078656) == 0) {

      if ((param_1 & *(unsigned short *)0x06078658) == 0) {

        if ((param_1 & *(unsigned short *)0x0607865A) == 0) {

          if ((param_1 & *(unsigned short *)0x0607865C) != 0) {

            *(int *)0x06063E20 = 3;

          }

        }

        else {

          *(int *)0x06063E20 = 2;

        }

      }

      else if (*(int *)0x06083255 == '\0') {

        *(int *)0x06063E20 = 1;

      }

    }

    else {

      *(int *)0x06063E20 = 0;

    }

  }

  else if (((param_1 & *(unsigned short *)0x0607865E) == 0) || (*(int *)0x06063E20 == 0)) {

    if (((param_1 & *(unsigned short *)0x06078660) != 0) &&

       (*(unsigned int *)0x06063E20 < (unsigned int)(int)(char)*(int *)0x06078662)) {

      if ((*(int *)0x06083255 == '\0') || (*(int *)0x06063E20 != 0)) {

        *(int *)0x06063E20 = *(int *)0x06063E20 + 1;

      }

      else {

        *(int *)0x06063E20 = *(int *)0x06063E20 + 2;

      }

    }

  }

  else {

    if ((*(int *)0x06083255 == '\0') || (*(int *)0x06063E20 != 2)) {

      iVar3 = *(int *)0x06063E20 + -1;

    }

    else {

      iVar3 = *(int *)0x06063E20 + -2;

    }

    *(int *)0x06063E20 = iVar3;

  }

  uVar2 = (unsigned short)(unsigned char)*(int *)0x06078635;

  if ((uVar2 == 0) && (uVar2 = *(unsigned short *)0x0607ED8C, uVar2 != 0)) {

    if ((unsigned int)(*(int *)0x06063E1C + *(int *)puVar1) < 7) {

      uVar4 = 4;

    }

    else {

      uVar4 = 3;

    }

    PHASE_FLAG = uVar4;

  }

  return uVar2;

}

/* camera_distance_update -- Update camera distance/acceleration for current car.
 * Decrements cooldown timer, then computes target acceleration from speed
 * curve tables, clamping to [-4014, half_max]. Accumulates into CAR_ACCEL,
 * clamps to non-negative, and divides by fixed constant for speed update. */
void FUN_0600c4f8(void)
{
    register int (*func)() asm("r3") = (int(*)())0x06027552;
    register int base asm("r14") = CAR_PTR_CURRENT;
    short extraout_var;
    int uVar2;
    int iVar3;
    int iVar4;
    int iVar5;

    if (0 < *(short *)(base + DAT_0600c590)) {
        *(short *)(base + DAT_0600c590) = *(short *)(base + DAT_0600c590) + -1;
    }
    if ((GAME_STATE_BIT & (unsigned int)0x00008000) == 0) {
        iVar5 = -4014;
        if ((*(int *)(base + DAT_0600c594) < 1) && (*(int *)(base + DAT_0600c596) == 0)) {
            iVar3 = *(int *)(base + CAR_SPEED) << 2;
            uVar2 = (*func)(0xFEC00000 + (*(int *)(0x060477EC + iVar3) - *(int *)(0x060454CC + iVar3)), 1);
            iVar3 = (*func)(uVar2, *(int *)(base + DAT_0600c59a));
            iVar4 = *(int *)(base + PTR_DAT_0600c59c) - *(int *)(base + CAR_ACCEL);
            if (iVar4 < iVar5) {
                *(int *)(base + DAT_0600c598) = iVar5;
            } else if (iVar3 >> 1 < iVar4) {
                *(int *)(base + DAT_0600c598) = iVar3 >> 1;
            } else {
                *(int *)(base + DAT_0600c598) = iVar4;
            }
        } else {
            *(int *)(base + DAT_0600c598) = iVar5;
        }
        iVar5 = *(int *)(base + CAR_ACCEL) + *(int *)(base + DAT_0600c598);
        if (iVar5 < 1) {
            *(int *)(base + CAR_ACCEL) = 0;
        } else {
            *(int *)(base + CAR_ACCEL) = iVar5;
        }
        (*func)(*(int *)(base + CAR_ACCEL), 0x00480000);
        *(int *)(base + CAR_SPEED) = (int)extraout_var;
    }
}

/* ai_car_physics_update -- AI car main physics loop: collision, friction, heading, movement.
 * Decides between collision recovery, friction braking, or normal movement,
 * then updates heading and applies position delta via sin/cos or 3D path. */
void FUN_0600c5d6()
{
  char *lerp_fn;
  char *friction_ctr;
  char *track_data;
  int track_seg;
  int result;
  int track_off;
  int car_ptr;
  char temp_vec [8];
  track_data = (char *)0x06078680;
  friction_ctr = (char *)0x0607EBDC;
  lerp_fn = (int *)0x06027552;
  car_ptr = CAR_PTR_CURRENT;
  track_seg = FUN_0600cd40();
  track_off = track_seg + 0x18;
  /* Collision/recovery path */
  if (((*(short *)0x06087804 == 2) || (0 < *(int *)(car_ptr + DAT_0600c616))) ||
     (0 < *(int *)(car_ptr + PTR_DAT_0600c618))) {
    FUN_0600ca96(track_data);
  }
  /* Normal driving path */
  else if ((((*(unsigned char *)(CAR_PTR_TARGET + 3) & 8) == 0) &&
           (*(int *)(car_ptr + DAT_0600c6f6) < 1)) && ((*(unsigned char *)(car_ptr + DAT_0600c6f8) & 0x20) == 0))
  {
    /* Speed decision when friction counter is low enough */
    if ((*(int *)friction_ctr < 0xb) && (*(int *)(car_ptr + DAT_0600c6fa) < 0x66)) {
      FUN_0600cf58(track_off);
    }
    if (*(int *)(car_ptr + DAT_0600c6fa) < 1) {
      FUN_0600cc38(track_off,track_data);   /* normal movement */
    }
    else {
      *(int *)(car_ptr + DAT_0600c6fa) = *(int *)(car_ptr + DAT_0600c6fa) + -2;
      FUN_0600ca96(track_data);             /* friction braking */
      *(int *)friction_ctr = *(int *)friction_ctr + 1;
    }
  }
  else {
    FUN_0600cc38(track_off,track_data);
  }
  /* Mode 3: interpolate track parameter */
  if (*(short *)0x06087804 == 3) {
    result = (*(int(*)())lerp_fn)(*(int *)(track_seg + 0x20),*(int *)(car_ptr + DAT_0600c6fc));
    *(int *)(DAT_0600c6fe + car_ptr) = result;
  }
  /* Update heading */
  FUN_0600c8cc(car_ptr,track_data);
  /* Apply position delta */
  if ((**(unsigned int **)0x0607E940 & (unsigned int)0x00E00000) == 0) {
    /* Simple 2D: sin/cos heading → X/Z movement */
    *(int *)(car_ptr + 0x20) = (int)*(short *)(track_data + 0xe);
    (*(int(*)())0x06027358)(-*(int *)(car_ptr + 0x28),DAT_0600c702 + car_ptr,DAT_0600c700 + car_ptr);
    track_seg = (*(int(*)())lerp_fn)(*(int *)(car_ptr + 0xc),*(int *)(car_ptr + DAT_0600c702));
    *(int *)(car_ptr + 0x10) = *(int *)(car_ptr + 0x10) + track_seg;
    track_seg = (*(int(*)())lerp_fn)(*(int *)(car_ptr + 0xc),*(int *)(car_ptr + DAT_0600c700));
    *(int *)(car_ptr + 0x18) = *(int *)(car_ptr + 0x18) + track_seg;
    *(int *)(car_ptr + 0x14) = 0;             /* Y = 0 (ground) */
  }
  else {
    /* 3D path: height lookup via world_to_tile_index */
    FUN_0600c928(car_ptr);
    FUN_0600c7d4(car_ptr,track_data);
    result = (*(int(*)())0x06006838)(*(int *)(car_ptr + 0x10),*(int *)(car_ptr + 0x18))
    ;
    (*(int(*)())0x06027EDE)(result,car_ptr + 0x10,temp_vec);
  }
  return;
}

/* ai_heading_and_move -- AI car heading/movement update (simplified pipeline).
 * Advances checkpoint, looks up track spline, adjusts heading (or forces
 * fixed heading in segment range 0x2E-0x3B), applies friction, then
 * interpolates heading and moves car along resulting vector.
 * Ends with world_to_tile_index height lookup. */
void FUN_0600c74e(void)
{
    int uVar2;
    int iVar3;
    char auStack_10[8];
    int *spline_ptr = (int *)0x06078680;
    iVar3 = CAR_PTR_CURRENT;
    FUN_0600cd40();
    FUN_0600ca96(spline_ptr);
    if ((*(int *)(iVar3 + DAT_0600c7be) < 0x2e) || (0x3b < *(int *)(iVar3 + DAT_0600c7be))) {
        FUN_0600c8cc(iVar3, spline_ptr);
    } else {
        *(int *)(iVar3 + CAR_HEADING2) = (int)DAT_0600c7c0;
    }
    *(int *)(iVar3 + CAR_HEADING) = *(int *)(iVar3 + CAR_HEADING2);
    if (*(int *)(iVar3 + CAR_SUBTYPE) == 0) {
        FUN_0600c970(iVar3);
    }
    FUN_0600c928(iVar3);
    FUN_0600c7d4(iVar3, spline_ptr);
    uVar2 = (*(int(*)())0x06006838)(*(int *)(iVar3 + CAR_X), *(int *)(iVar3 + CAR_Z));
    (*(int(*)())0x06027EDE)(uVar2, iVar3 + CAR_X, auStack_10);
}

/* heading_interpolate_and_move -- Interpolate heading toward target based on speed,
 * then move car along heading vector.
 * Speed brackets: >0x118 = >>3, >0xFA = >>2, >threshold = >>1, else full delta.
 * Backs up heading, blends X/Z rotations with track normals,
 * saves pre-collision position, applies heading drift correction,
 * then computes sin/cos movement from CAR_ACCEL and heading. */
void FUN_0600c7d4(int param_1, int param_2)
{
    int iVar1;
    short delta;

    *(int *)(param_1 + DAT_0600c8b6) = *(int *)(param_1 + CAR_HEADING);

    delta = (short)*(int *)(param_1 + CAR_HEADING2) - (short)*(int *)(param_1 + CAR_HEADING);

    /* Scale heading delta by speed bracket */
    if (0x118 < *(int *)(param_1 + CAR_SPEED))
        delta = delta >> 3;
    else if (0xfa < *(int *)(param_1 + CAR_SPEED))
        delta = delta >> 2;
    else if ((int)DAT_0600c8bc < *(int *)(param_1 + CAR_SPEED))
        delta = delta >> 1;

    delta = (short)*(int *)(param_1 + CAR_HEADING) + delta;
    *(int *)(param_1 + CAR_HEADING) = (int)delta;

    /* Compute tertiary heading with drift correction */
    *(int *)(param_1 + CAR_HEADING3) =
        (int)(short)((delta - (short)*(int *)(param_1 + DAT_0600c8be)) -
                    *(short *)(param_2 + 0x12));

    /* Blend X/Z rotations with track normal */
    *(int *)(param_1 + CAR_ROT_X) =
        (int)(short)(*(short *)(param_2 + 0xc) + (short)*(int *)(param_1 + CAR_ROT_X)) >> 1;
    *(int *)(param_1 + CAR_ROT_Z) =
        (int)(short)(*(short *)(param_2 + 0x10) + (short)*(int *)(param_1 + CAR_ROT_Z)) >> 1;

    /* Save pre-collision position */
    *(int *)(param_1 + CAR_PRE_COLL_X) = *(int *)(param_1 + CAR_X);
    *(int *)(param_1 + CAR_PRE_COLL_Z) = *(int *)(param_1 + CAR_Z);

    /* Apply heading drift correction */
    *(int *)(param_1 + CAR_HEADING) =
        (int)(short)((short)*(int *)(param_1 + CAR_HEADING) +
                    (short)(-(int)*(short *)(param_2 + 0x12) >> 2));

    /* Compute sin/cos of heading, multiply by accel to get X/Z velocity */
    (*(int(*)())0x06027358)(-*(int *)(param_1 + CAR_HEADING2), DAT_0600c8c2 + param_1, DAT_0600c8c0 + param_1);

    iVar1 = (*(int(*)())0x06027552)(*(int *)(param_1 + CAR_ACCEL), *(int *)(param_1 + DAT_0600c8c2));
    *(int *)(param_1 + CAR_X) += iVar1;

    iVar1 = (*(int(*)())0x06027552)(*(int *)(param_1 + CAR_ACCEL), *(int *)(param_1 + DAT_0600c8c0));
    *(int *)(param_1 + CAR_Z) += iVar1;
}

/* car_heading_adjust -- Smoothly adjust car heading towards target.
 * Computes angle from car X,Z to target X,Z via atan2 (0x0602744C).
 * Clamps heading change per frame to DAT_0600c962 / 0xFA00 limits.
 * Updates CAR_HEADING2 (+0x28). Returns computed angle. */
int FUN_0600c8cc(int param_1, int *param_2)
{
    int angle;
    short delta;

    angle = (*(int(*)())0x0602744C)(
        *param_2 - *(int *)(param_1 + CAR_X),
        param_2[2] - *(int *)(param_1 + CAR_Z));

    delta = (short)-angle - (short)*(int *)(param_1 + CAR_HEADING2);

    if (DAT_0600c962 < delta) {
        *(int *)(param_1 + CAR_HEADING2) =
            (int)(short)((short)*(int *)(param_1 + CAR_HEADING2) + DAT_0600c962);
    } else if (delta < DAT_0600c964) {
        *(int *)(param_1 + CAR_HEADING2) =
            (int)(short)((short)*(int *)(param_1 + CAR_HEADING2) + (short)0x0000FA00);
    } else {
        *(int *)(param_1 + CAR_HEADING2) = -angle;
    }

    return angle;
}

/* car_friction_decel -- Apply friction deceleration based on speed.
 * Computes friction from CAR_ACCEL: (accel >> 9) * 0xFFFF >> 8, clamped to 0x2000.
 * Subtracts from CAR_COLL_SPEED (+0x48) and copies to CAR_SPEED_COPY (+0x50). */
void FUN_0600c928(int param_1)
{
    unsigned int max_friction = 0x2000;
    unsigned int friction = (int)((*(unsigned int *)(param_1 + CAR_ACCEL) >> 9 & 0xffff) * 0xffff) >> 8 & 0xffff;

    if ((int)friction < (int)max_friction)
        max_friction = friction;

    int result = *(int *)(param_1 + CAR_COLL_SPEED) - max_friction;
    *(int *)(param_1 + CAR_COLL_SPEED) = result;
    *(int *)(param_1 + CAR_SPEED_COPY) = result;
}

/* car_speed_curve_apply -- Apply speed curve adjustment from lookup table.
 * Reads checkpoint param (+0x1EC) from car struct; if in range 0x45-0x62,
 * adds speed delta from table at 0x0605A1E0 to CAR_ACCEL (+0x0C).
 * Table is indexed by (checkpoint_param - 0x45). */
int FUN_0600c970(int param_1)
{
    int checkpoint_param = *(int *)(param_1 + CAR_CHECKPOINT_PARAM);

    if (checkpoint_param > 0x44 && checkpoint_param < 99) {
        *(int *)(param_1 + CAR_ACCEL) +=
            (int)*(short *)(0x0605A1E0 + ((checkpoint_param - 0x45) << 1));
    }

    return CAR_CHECKPOINT_PARAM;
}

/* track_boundary_nearest_angle -- Find nearest track boundary angle for AI steering.
 * Samples 8 track boundary point pairs at next checkpoint, computes atan2 angles,
 * finds minimum deviation from track heading, stores best-match index in car struct. */
void FUN_0600c994()
{
  short heading_bias;
  unsigned short angle_step;
  char *atan2_fn;
  char *spline_data;
  short angle;
  int spline_off;
  unsigned int min_dist;
  unsigned short step_acc;
  unsigned int dist;
  int *boundary_pt;
  int car_ptr;
  unsigned short best_index;
  short *angle_ptr;
  short angle_array [8];
  short angle_end [2];
  spline_data = (char *)0x0607EB88;
  atan2_fn = (char *)0x0602744C;
  angle_step = DAT_0600c9e6;
  car_ptr = CAR_PTR_TARGET;
  /* Get next checkpoint spline data */
  spline_off = *(int *)(car_ptr + DAT_0600c9e4) + 1;
  heading_bias = *(short *)(((spline_off << 3) + 3) << 4 + *(int *)0x0607EB88 + 10);
  spline_off = (spline_off << 7);
  /* Compute angles to 8 boundary point pairs */
  for (angle_ptr = angle_array; angle_ptr < angle_end; angle_ptr = angle_ptr + 2) {
    boundary_pt = (int *)(*(int *)spline_data + spline_off);
    angle = (*(int(*)())atan2_fn)(*boundary_pt - *(int *)(car_ptr + 0x10),
                              boundary_pt[1] - *(int *)(car_ptr + 0x18));
    *angle_ptr = -angle;
    boundary_pt = (int *)(*(int *)spline_data + spline_off + 0x10);
    angle = (*(int(*)())atan2_fn)(*boundary_pt - *(int *)(car_ptr + 0x10),
                              boundary_pt[1] - *(int *)(car_ptr + 0x18));
    angle_ptr[1] = -angle;
    spline_off = spline_off + 0x20;
  }
  /* Find angle closest to heading (minimum absolute deviation) */
  heading_bias = heading_bias * -4;
  min_dist = (unsigned int)(short)(angle_array[0] + heading_bias);
  if ((int)min_dist < 0) {
    min_dist = -min_dist;
  }
  min_dist = min_dist & 0xffff;
  best_index = 0;
  angle_ptr = angle_array;
  step_acc = angle_step;
  while (angle_ptr = angle_ptr + 1, angle_ptr < angle_end) {
    dist = (unsigned int)(short)(*angle_ptr + heading_bias);
    if ((int)dist < 0) {
      dist = -dist;
    }
    if ((int)dist < (int)min_dist) {
      min_dist = dist & 0xffff;
      best_index = step_acc;
    }
    step_acc = step_acc + angle_step;
  }
  *(unsigned int *)(car_ptr + DAT_0600cac0) = (unsigned int)best_index;
  return;
}

/* track_spline_smooth -- Sample track spline with smoothing interpolation.
 * Computes position delta from DAT_0600cac2 history. Small deltas (<8)
 * snap directly; larger deltas adjust smoothing accumulator at DAT_0600cb84
 * by +/-4. Extracts fractional (6-bit sub-segment) and segment index
 * from accumulator. If fractional==0 or segment>6, samples exact point;
 * otherwise blends between adjacent points with weighted average.
 * Writes position and rotation data to param_1 output buffer. */
void FUN_0600ca96(param_1)
    int *param_1;
{
    int car = CAR_PTR_CURRENT;
    int *spline_pt;
    int delta = *(int *)(car + DAT_0600cac2) - *(int *)(car + DAT_0600cac2 + 4);

    /* Update smoothing accumulator */
    if ((delta < 8) && (-8 < delta)) {
        *(int *)(car + DAT_0600cac2 + 4) = *(int *)(car + DAT_0600cac2);
    } else if (delta < 1) {
        *(int *)(car + DAT_0600cb84) = *(int *)(car + DAT_0600cb84) + -4;
    } else {
        *(int *)(car + DAT_0600cb84) = *(int *)(car + DAT_0600cb84) + 4;
    }

    /* Extract fractional and segment index */
    unsigned int frac = (*(unsigned int *)(car + DAT_0600cb84) & (int)DAT_0600cb86 & 0xffff) >> 6;
    unsigned int seg  = (*(unsigned int *)(car + DAT_0600cb84) & 0xffff) >> 8;

    if ((frac == 0) || (6 < seg)) {
        /* Exact point sample */
        spline_pt = (int *)((seg + *(int *)(car + PTR_DAT_0600cb88) << 3) << 4 +
                     *(int *)0x0607EB88);
        *param_1 = *spline_pt;
        param_1[2] = spline_pt[1];
    } else {
        /* Weighted blend between adjacent points */
        int base_idx = seg + *(int *)(car + PTR_DAT_0600cb88) << 3;
        spline_pt = (int *)((base_idx << 4) + *(int *)0x0607EB88);
        int *next_pt = (int *)((base_idx + 1) << 4 + *(int *)0x0607EB88);
        *param_1 = (int)(*spline_pt * (4 - frac) + *next_pt * frac) >> 2;
        param_1[2] = (int)(spline_pt[1] * (4 - frac) + next_pt[1] * frac) >> 2;
    }

    /* Copy rotation data */
    *(short *)(param_1 + 3) = *(short *)(spline_pt + 2);
    *(short *)((int)param_1 + 0xe) = *(short *)((int)spline_pt + 10) << 2;
    *(short *)(param_1 + 4) = *(short *)(spline_pt + 3);
    *(short *)((int)param_1 + 0x12) = 0;
}

/* track_spline_sample -- Sample track spline at given parameter.
 * Even param_2: reads exact track point from spline table (0x0607EB88).
 * Odd param_2: interpolates between two adjacent points (average).
 * Spline index offset from car's +0x1F8 field, base at 0x0607EB88.
 * Writes X, Z position and rotation data into param_1 output buffer. */
void FUN_0600cb90(param_1, param_2)
    int *param_1;
    unsigned int param_2;
{
    int *spline_pt;

    if ((param_2 & 1) == 0) {
        /* Exact point */
        spline_pt = (int *)(((*(unsigned int *)(CAR_PTR_CURRENT + 0x1f8) >> 8) +
                     ((param_2 & 0xffff) >> 1) << 3) << 4 + *(int *)0x0607EB88);
        *param_1 = *spline_pt;
        param_1[2] = spline_pt[1];
    } else {
        /* Interpolate between two points */
        unsigned int next_idx = ((param_2 & 0xffff) >> 1) + 1;
        if (*(unsigned int *)0x0607EA9C < next_idx) {
            next_idx = 0;                        /* wrap around */
        }
        unsigned int base_off = *(unsigned int *)(CAR_PTR_CURRENT + 0x1f8) >> 8;
        spline_pt = (int *)((base_off + ((param_2 & 0xffff) >> 1) << 3) << 4 + *(int *)0x0607EB88);
        int *next_pt = (int *)((base_off + (next_idx << 3)) << 4 + *(int *)0x0607EB88);
        *param_1 = *spline_pt + *next_pt >> 1;
        param_1[2] = spline_pt[1] + next_pt[1] >> 1;
    }

    /* Copy rotation data */
    *(short *)(param_1 + 3) = *(short *)(spline_pt + 2);
    *(short *)((int)param_1 + 0xe) = *(short *)((int)spline_pt + 10) << 2;
    *(short *)(param_1 + 4) = *(short *)(spline_pt + 3);
    *(short *)((int)param_1 + 0x12) = 0;
}

/* track_spline_smooth_ext -- Sample track spline from external AI descriptor.
 * Like track_spline_smooth but reads spline parameter from param_1 +0x14
 * and copies rotation data from param_1 descriptor. Delta smoothing uses
 * DAT_0600ccf6 history, step size +/-8. Output written to param_2. */
void FUN_0600cc38(param_1, param_2)
    int param_1;
    int *param_2;
{
    int *spline_pt;
    int car = CAR_PTR_CURRENT;
    int delta = *(int *)(car + DAT_0600ccf6) - *(int *)(car + DAT_0600ccf6 + 4);

    /* Update smoothing accumulator (step +/-8) */
    if ((delta < 8) && (-8 < delta)) {
        *(int *)(car + DAT_0600ccf6 + 4) = *(int *)(car + DAT_0600ccf6);
    } else if (delta < 1) {
        *(int *)(car + DAT_0600ccf8) = *(int *)(car + DAT_0600ccf8) + -8;
    } else {
        *(int *)(car + DAT_0600ccf8) = *(int *)(car + DAT_0600ccf8) + 8;
    }

    /* Read spline parameter from AI descriptor */
    *(int *)(car + DAT_0600ccf6) = (int)*(short *)(param_1 + 0x14);
    unsigned int frac = (unsigned int)((*(unsigned short *)(param_1 + 0x14) & 0xff) >> 6);
    unsigned int seg  = (unsigned int)(*(unsigned short *)(param_1 + 0x14) >> 8);

    if ((frac == 0) || (6 < seg)) {
        /* Exact point sample */
        spline_pt = (int *)((seg + *(int *)(car + DAT_0600cdbc) << 3) << 4 + *(int *)0x0607EB88);
        *param_2 = *spline_pt;
        param_2[2] = spline_pt[1];
    } else {
        /* Weighted blend between adjacent points */
        int base_idx = seg + *(int *)(car + DAT_0600ccfa) << 3;
        spline_pt = (int *)((base_idx << 4) + *(int *)0x0607EB88);
        int *next_pt = (int *)((base_idx + 1) << 4 + *(int *)0x0607EB88);
        *param_2 = (int)(*spline_pt * (4 - frac) + *next_pt * frac) >> 2;
        param_2[2] = (int)(spline_pt[1] * (4 - frac) + next_pt[1] * frac) >> 2;
    }

    /* Copy rotation data from AI descriptor */
    *(short *)(param_2 + 3) = *(short *)(param_1 + 0xc);
    *(short *)((int)param_2 + 0xe) = *(short *)(param_1 + 0xe) << 2;
    *(short *)(param_2 + 4) = *(short *)(param_1 + 0x10);
    *(short *)((int)param_2 + 0x12) = *(short *)(param_1 + 0x12);
}

int * FUN_0600cd40()
{

  short sVar1;

  int iVar2;

  int *piVar3;

  int iVar4;

  iVar4 = CAR_PTR_CURRENT;

  piVar3 = (int *)(*(int *)(iVar4 + DAT_0600cdbe) * 0x18 + *(int *)(iVar4 + DAT_0600cdbe + -4));

  *(unsigned int *)(iVar4 + DAT_0600cdc0) = (unsigned int)*(unsigned short *)((int)piVar3 + 0x16);

  sVar1 = (*(int(*)())0x0602744C)(*(int *)(iVar4 + 0x10) - *piVar3,piVar3[1] - *(int *)(iVar4 + 0x18));

  iVar2 = (int)sVar1 + *(short *)((int)piVar3 + 0xe) * -4;

  if (iVar2 < 0) {

    iVar2 = *(short *)((int)piVar3 + 0xe) << 2 - (int)sVar1;

  }

  if (DAT_0600cdc2 < iVar2) {

    iVar2 = (int)DAT_0600cdbe;

    *(int *)(iVar4 + iVar2) = *(int *)(iVar4 + iVar2) + 1;

    if (*(int *)0x0607EA9C < *(int *)(iVar4 + iVar2)) {

      *(int *)(iVar4 + DAT_0600cdbe) = 0;

    }

  }

  return piVar3;

}

/* checkpoint_advance_alt -- Alternate checkpoint advancement using angular detection.
 * Looks up segment data from car's current checkpoint index, extracts
 * segment width, computes angle to next checkpoint waypoint via atan2,
 * and advances checkpoint if angular deviation exceeds threshold. */
int FUN_0600cdd0(void)
{
    register int base asm("r2") = CAR_PTR_CURRENT;
    int iVar1;
    short sVar2;
    int iVar3;
    int *piVar4;
    int iVar5;

    iVar5 = *(int *)(base + (int)DAT_0600ce86) * 0x18 + *(int *)(base + (int)DAT_0600ce86 - 4);
    iVar1 = (int)DAT_0600ce88;
    *(unsigned int *)(base + iVar1) = (unsigned int)*(unsigned short *)(iVar5 + 0x16);
    iVar1 = *(int *)(base + iVar1 + 0x60);
    if (iVar1 == 0) {
        iVar1 = *(int *)0x0607EA9C;
    } else {
        iVar1 = iVar1 - 1;
    }
    piVar4 = (int *)(iVar1 * 0x18 + *(int *)(base + (int)DAT_0600ce8a));
    sVar2 = (*(int(*)())0x0602744C)(*piVar4 - *(int *)(base + CAR_X), *(int *)(base + CAR_Z) - piVar4[1]);
    iVar3 = (int)sVar2 + *(short *)(iVar5 + 0xe) * -4;
    if (iVar3 < 0) {
        iVar3 = (*(short *)(iVar5 + 0xe) << 2) - (int)sVar2;
    }
    if ((int)DAT_0600ce8c < iVar3) {
        *(int *)(base + (int)DAT_0600ce86) = iVar1;
    }
    return iVar5;
}

/* lap_checkpoint_update -- Update checkpoint/lap state for current car.
 * Backs up previous checkpoint, dispatches to normal (FUN_0600cd40) or
 * special (FUN_0600cdd0) based on collision flag (byte +3 bit 3).
 * Then looks up track segment data from segment table. */
void FUN_0600ce66(void)
{
    register int base asm("r2") = CAR_PTR_CURRENT;

    /* Backup previous checkpoint value */
    *(int *)(base + DAT_0600ce8e + 4) = *(int *)(base + DAT_0600ce8e);

    if ((*(unsigned char *)(base + 3) & 8) == 0) {
        FUN_0600cd40();   /* normal checkpoint processing */
    } else {
        FUN_0600cdd0();   /* special/collision checkpoint */
    }

    /* Look up track segment data from segment table */
    *(unsigned int *)(base + DAT_0600cf3a + 0x68) =
        (unsigned int)*(unsigned short *)((*(int *)(base + DAT_0600cf3a) << 2) + *(int *)0x0607EB84);
}

/* checkpoint_progress_track -- Track checkpoint crossing progress.
 * Saves previous checkpoint value, reads new from track lookup table
 * (0x0607EB84). Computes delta between current and prior positions.
 * If delta is positive and exceeds (total_checkpoints - 16), increments
 * lap counter at +0x228, records time delta (GAME_STATE_VAR - split),
 * and stores frame counter from 0x0607EBD0. */
int FUN_0600ceba()
{
    int off = (int)DAT_0600cf3a;
    int car = CAR_PTR_CURRENT;
    int track_tbl = *(int *)0x0607EB84;

    /* Shift checkpoint history */
    *(int *)(car + off + 0x6c) = *(int *)(car + off + 0x68);
    *(unsigned int *)(car + off + 0x68) =
        (unsigned int)*(unsigned short *)(*(int *)(car + off) << 2 + track_tbl);

    (*(int(*)())0x06035228)();
    (*(int(*)())0x06035228)();

    int prev_off = DAT_0600cf40 + -4;
    int delta = (int)(short)((short)*(int *)(car + DAT_0600cf40) -
                             (short)*(int *)(car + prev_off));

    if ((0 < delta) && (*(int *)0x0607EA9C + -0x10 < delta)) {
        prev_off = 0x228;
        int lap_count = *(int *)(car + prev_off) + 1;
        *(int *)(car + prev_off) = lap_count;
        *(int *)(car + prev_off + -0xc) = lap_count;
        *(int *)(car + prev_off + -8) = GAME_STATE_VAR - *(int *)(car + prev_off + 4);
        prev_off = prev_off + 4;
        *(int *)(car + prev_off) = *(int *)0x0607EBD0;
    }
    return prev_off;
}

/* ai_speed_decision -- AI speed adjustment decision tree.
 * Evaluates relative positions and speeds of current vs target car,
 * decides whether to accelerate, decelerate, or attempt overtake.
 * Sets speed preset (0x300/0x400) and step size (0x80) at car+0x1F8/+0x204. */
unsigned int FUN_0600cf58()
{
  unsigned int result;
  unsigned int target_pos_ratio;
  unsigned int current_pos_ratio;
  int step_size;
  int target_car;
  int current_car;
  unsigned char decision_flags;
  step_size = 0x80;
  current_car = CAR_PTR_CURRENT;
  target_car = CAR_PTR_TARGET;
  if ((*(unsigned int *)(current_car + 4) != 0) && ((int)DAT_0600cfe4 < *(int *)(current_car + 8))) {
    /* Car flags check: need certain bits set */
    if ((**(unsigned int **)0x0607E940 & (unsigned int)0x00C00000) == 0) {
      return *(unsigned int *)(current_car + 4);
    }
    (*(int(*)())0x06035168)();         /* update AI state */
    if (*(int *)(current_car + DAT_0600cfe6) == 0) {
      result = FUN_0600d0b8();         /* default speed calc */
      return result;
    }
    result = (unsigned int)(char)decision_flags;
    /* Decision flag bit 1: speed matching */
    if ((result & 2) != 0) {
      if (*(int *)(current_car + 8) <= *(int *)(target_car + 8)) {
        /* Target is faster — copy speed state and set step */
        target_car = (int)PTR_DAT_0600cfe8;
        *(int *)(current_car + target_car + -4) = *(int *)(current_car + target_car);
        *(int *)(current_car + target_car + 8U) = step_size;
        return target_car + 8U;
      }
      result = FUN_0600d12c();         /* gradual adjust */
    }
    if (*(int *)(target_car + 8) < *(int *)(current_car + 8)) {
      return result;                   /* already faster than target */
    }
    /* Decision flag bit 0: overtake/positioning logic */
    if ((decision_flags & 1) != 0) {
      if (*(int *)(current_car + DAT_0600d0aa) == 2) {
        /* Aggressive overtake at high speed */
        if ((0xaf0 < *(int *)(target_car + 8)) && (*(int *)(current_car + DAT_0600d0ae) < 10)) {
          result = FUN_0600d210();     /* overtake maneuver */
          return result;
        }
        result = FUN_0600d12c();
        return result;
      }
      if (*(unsigned int *)(current_car + DAT_0600d0aa) != 1) {
        return *(unsigned int *)(current_car + DAT_0600d0aa);
      }
      /* Position-based speed preset selection */
      result = (unsigned int)DAT_0600d0b0;
      target_pos_ratio = *(int *)(target_car + result) >> 8;
      current_pos_ratio = *(int *)(current_car + result) >> 8;
      if ((target_pos_ratio < 2) && (current_pos_ratio < 3)) {
        target_car = 0x1f8;
        *(int *)(current_car + target_car) = 0x300;  /* moderate speed */
        result = target_car + 0xc;
        *(int *)(current_car + result) = step_size;
        return result;
      }
      if (target_pos_ratio < 6) {
        return result;
      }
      if (current_pos_ratio < 5) {
        return result;
      }
      target_car = 0x1f8;
      *(int *)(current_car + target_car) = 0x400;    /* high speed */
      result = target_car + 0xc;
      *(int *)(current_car + result) = step_size;
      return result;
    }
    FUN_0600d12c();
  }
  result = *(unsigned int *)(current_car + 4);
  if (result == 0) {
    result = FUN_0600d12c();
  }
  return result;
}

/* ai_speed_target_adjust -- Adjust AI car's speed target relative to player.
 * Only active if car flags have bits 22-23 set. Compares AI and player
 * positions (DAT_0600d114 offset). If AI is behind, adds +0x200; if ahead,
 * subtracts 0x200. Clamps result to 0..0x800 range and stores at +0x1F8.
 * Also stores step size (0x200) at PTR_DAT_0600d11c. */
int FUN_0600d0b8()
{
    int step = 0x200;
    unsigned int *player_car = *(unsigned int **)0x0607E940;
    int ai_car = CAR_PTR_TARGET;

    if ((*player_car & (unsigned int)0x00C00000) != 0) {
        int adjusted;
        if (*(int *)(ai_car + DAT_0600d114) < *(int *)((int)player_car + (int)DAT_0600d114)) {
            adjusted = *(int *)(ai_car + DAT_0600d114) + step;
        } else {
            adjusted = *(int *)(ai_car + DAT_0600d114) + -512;
        }
        /* Clamp to 0..0x800 */
        if (adjusted < 0) {
            *(int *)((int)player_car + 0x1f8) = 0;
        } else if (DAT_0600d11a < adjusted) {
            *(int *)((int)player_car + 0x1f8) = 0x800;
        } else {
            *(int *)((int)player_car + 0x1f8) = adjusted;
        }
        *(int *)((int)player_car + (int)PTR_DAT_0600d11c) = step;
    }
    return 0;
}

/* ai_follow_target_select -- Select and follow closest AI target.
 * Checks primary target (car + DAT_0600d192) and secondary (PTR_DAT_0600d194).
 * If secondary exists and is within 0x80000 distance, uses it; else primary.
 * If primary distance >= 0xF0000, returns (too far). Within range, adjusts
 * AI position by +/-0x300 toward target, clamps to 0..0x800. Sets follow
 * flag at PTR_DAT_0600d208 = 0x100 and stores target ref at +0x30. */
int FUN_0600d12c()
{
    int car = CAR_PTR_CURRENT;
    int primary = *(int *)(car + DAT_0600d192);
    int target = *(int *)(car + PTR_DAT_0600d194);
    int distance;

    if (target == 0) {
        /* No secondary: compute distance to primary */
        distance = ((*(int *)(primary + 0x10) - *(int *)(car + 0x10)) +
                    *(int *)(primary + 0x18)) - *(int *)(car + 0x18);
    } else {
        /* Secondary exists: check if close enough */
        if (((*(int *)(target + 0x10) - *(int *)(car + 0x10)) +
             *(int *)(target + 0x18)) - *(int *)(car + 0x18) < (int)0x00080000)
            goto LAB_0600d1a4;
        /* Secondary too far: fall back to primary */
        distance = ((*(int *)(primary + 0x10) - *(int *)(car + 0x10)) +
                    *(int *)(primary + 0x18)) - *(int *)(car + 0x18);
    }

    target = primary;
    if ((int)0x000F0000 <= distance) {
        return (int)PTR_DAT_0600d194;              /* primary too far — bail */
    }

LAB_0600d1a4:
    ;
    int pos_off = (int)DAT_0600d1fa;
    int car2 = CAR_PTR_CURRENT;
    int target_pos = *(int *)(target + pos_off);
    int pos_delta = target_pos - *(int *)(car2 + pos_off);

    if ((DAT_0600d1fc <= pos_delta) && (pos_delta <= DAT_0600d1fe)) {
        int adjust = 0x300;
        if (DAT_0600d200 < target_pos) {
            adjust = -adjust;
        }
        target_pos = target_pos + adjust;
        if (target_pos < 0) {
            *(int *)(car2 + DAT_0600d202) = 0;
        } else if (DAT_0600d204 < target_pos) {
            *(int *)(car2 + DAT_0600d202) = 0x800;
        } else {
            *(int *)(car2 + DAT_0600d202) = target_pos;
        }
        pos_off = (int)PTR_DAT_0600d208;
        *(int *)(car2 + pos_off) = 0x100;          /* set follow mode flag */
        pos_off = pos_off + 0x30;
        *(int *)(car2 + pos_off) = target;
    }

    return pos_off;
}

/* ai_position_approach -- Adjust AI car's position toward target within bounds.
 * Computes position delta between target and current car. If delta is
 * within threshold range (DAT_0600d26c..DAT_0600d26e), applies +/-16
 * nudge toward target. Clamps result to 0..0x800 and stores at
 * DAT_0600d270. Sets approach step at PTR_DAT_0600d274 = 0x40. */
int FUN_0600d210()
{
    int pos_off = (int)DAT_0600d26a;
    int car = CAR_PTR_CURRENT;
    int target_pos = *(int *)(CAR_PTR_TARGET + pos_off);
    int delta = target_pos - *(int *)(car + pos_off);
    int result = pos_off;

    if ((DAT_0600d26c <= delta) && (delta <= DAT_0600d26e)) {
        /* Apply directional nudge */
        if (target_pos < *(int *)(car + DAT_0600d26a)) {
            target_pos = target_pos + -0x10;
        } else {
            target_pos = target_pos + 0x10;
        }
        /* Clamp to 0..0x800 */
        if (target_pos < 0) {
            *(int *)(car + DAT_0600d270) = 0;
        } else if (DAT_0600d272 < target_pos) {
            *(int *)(car + DAT_0600d270) = 0x800;
        } else {
            *(int *)(car + DAT_0600d270) = target_pos;
        }
        result = (int)PTR_DAT_0600d274;
        *(int *)(car + result) = 0x40;
    }
    return result;
}

/* nop_d266 -- Placeholder / stripped function (no-op). */
void FUN_0600d266(void)
{
    return;
}

/* ranking_table_init -- Initialize car ranking pointer tables.
 * Clears two 40-entry ranking arrays at 0x0607E94C and 0x0607E9EC,
 * plus 3-word summary at 0x0607EA8C. Then fills both arrays with
 * pointers to car slots (CAR_ARRAY_BASE) in reverse order based
 * on total car count (0x0607EA98). CAR_STRUCT_SIZE=0x268 per slot. */
void FUN_0600d280(void)
{
  int car_count = *(int *)0x0607EA98;
  int *rank_a = (int *)0x0607E94C;         /* ranking table A */
  int *rank_b = (int *)0x0607E9EC;         /* ranking table B */
  unsigned int i;

  /* Clear both 40-entry tables */
  for (i = 0; i < 0x28; i += 2) {
    rank_a[i] = 0;  rank_a[i + 1] = 0;
  }
  for (i = 0; i < 0x28; i += 2) {
    rank_b[i] = 0;  rank_b[i + 1] = 0;
  }
  *(int *)0x0607EA8C = 0;
  *(int *)0x0607EA90 = 0;
  *(int *)0x0607EA94 = 0;

  /* Fill with car pointers in reverse order */
  for (i = 1; i <= (unsigned int)car_count; i++) {
    rank_a[i - 1] = CAR_ARRAY_BASE + (car_count - i) * CAR_STRUCT_SIZE;
  }
  for (i = 1; i <= (unsigned int)car_count; i++) {
    rank_b[i - 1] = CAR_ARRAY_BASE + (car_count - i) * CAR_STRUCT_SIZE;
  }
}

/* ranking_update -- Update car ranking/positioning system.
 * Skips ranking sort (FUN_0600d37c) in VS mode (bit 21 = 2-player).
 * Always runs ranking display (FUN_0600d3c4) and position update (FUN_0600d50c). */
void FUN_0600d31c(void)
{
    if ((GAME_STATE_BIT & 0x00200000) == 0) {
        FUN_0600d37c();   /* ranking sort (single-player only) */
    }
    FUN_0600d3c4();       /* ranking display */
    FUN_0600d50c();       /* position update */
}

/* ranking_compare_two -- Compare velocity projection of car 0 vs car 1.
 * Only runs when GAME_STATE_BIT bit 21 is clear (not VS mode).
 * Compares CAR_VEL_PROJ (+0x1F4): the faster car gets CAR_LAP_DELTA=1,
 * the slower gets 0. Used for 2-player position tracking. */
void FUN_0600d336(void)
{
    int car0 = CAR_ARRAY_BASE;
    int car1 = car0 + CAR_STRUCT_SIZE;

    if ((GAME_STATE_BIT & 0x00200000) == 0) {
        if (*(int *)(car0 + CAR_VEL_PROJ) < *(int *)(car1 + CAR_VEL_PROJ)) {
            *(int *)(car0 + CAR_LAP_DELTA) = 1;
            *(int *)(car1 + CAR_LAP_DELTA) = 0;
        } else {
            *(int *)(car0 + CAR_LAP_DELTA) = 0;
            *(int *)(car1 + CAR_LAP_DELTA) = 1;
        }
    }
}

/* ranking_sort_bubble -- Single-pass bubble sort of car pointers by velocity.
 * Car pointer array at 0x0607E94C, count from CAR_ITERATION_BASE.
 * Compares field at DAT_0600d404 offset (velocity projection).
 * Writes final rank to DAT_0600d406 offset in each car struct. */
void FUN_0600d37c(void)
{
    register int *car_ptrs asm("r4") = (int *)0x0607E94C;
    register unsigned int count asm("r5") = *(unsigned int *)0x0607EA98;
    register int rank asm("r12") = 0;
    int cur_val, next_val;

    cur_val = *(int *)(*car_ptrs + (int)DAT_0600d404);

    while (count > 1) {
        next_val = *(int *)(car_ptrs[1] + (int)DAT_0600d404);
        if (cur_val < next_val) {
            int tmp = *car_ptrs;
            *car_ptrs = car_ptrs[1];
            car_ptrs[1] = tmp;
        } else {
            next_val = cur_val;
        }
        cur_val = *car_ptrs++;
        *(int *)(cur_val + DAT_0600d406) = rank++;
        cur_val = next_val;
        count--;
    }

    *(int *)(*car_ptrs + (int)DAT_0600d406) = rank;
}

void FUN_0600d3c4()
{

  int *puVar1;

  char *puVar2;

  char *puVar3;

  int iVar4;

  unsigned int uVar5;

  int uVar6;

  unsigned int uVar7;

  int *piVar8;

  int *piVar9;

  unsigned int uVar10;

  int *puVar11;

  int *puVar12;

  puVar12 = (int *)0x0607E9EC;

  if (*(unsigned int *)(*(int *)0x0607E9EC + (int)PTR_DAT_0600d408) < *(unsigned int *)0x060786B4)

  {

    for (uVar7 = 1;

        (uVar10 = uVar7, puVar1 = (int *)0x0607EA8C,

        puVar11 = (int *)0x0607E9EC,

        *(unsigned int *)(*(int *)(0x0607E9EC + (uVar7 << 2)) + (int)DAT_0600d4a6) <

        *(unsigned int *)0x060786B4 && (uVar7 < 3)); uVar7 = uVar7 + 1) {

    }

    for (; uVar10 != 0; uVar10 = uVar10 - 1) {

      *puVar1 = *puVar11;

      puVar1 = puVar1 + 1;

      puVar11 = puVar11 + 1;

    }

    for (uVar10 = *(int *)0x0607EA98 - uVar7; puVar1 = (int *)0x0607EA8C,

        1 < uVar10; uVar10 = uVar10 - 1) {

      uVar6 = *puVar11;

      puVar11 = puVar11 + 1;

      *puVar12 = uVar6;

      puVar12 = puVar12 + 1;

    }

    for (; uVar7 != 0; uVar7 = uVar7 - 1) {

      *puVar12 = *puVar1;

      puVar12 = puVar12 + 1;

      puVar1 = puVar1 + 1;

    }

  }

  else {

    uVar7 = *(unsigned int *)(*(int *)0x0607E9EC + (int)PTR_DAT_0600d408);

    piVar9 = (int *)0x0607E9EC;

    for (uVar10 = *(unsigned int *)0x0607EA98; 1 < uVar10; uVar10 = uVar10 - 1) {

      uVar5 = *(unsigned int *)(piVar9[1] + (int)PTR_DAT_0600d408);

      if (uVar7 < uVar5) {

        iVar4 = *piVar9;

        *piVar9 = piVar9[1];

        piVar9[1] = iVar4;

        uVar5 = uVar7;

      }

      piVar9 = piVar9 + 1;

      uVar7 = uVar5;

    }

  }

  puVar3 = (char *)0x0607EA98;

  puVar2 = (char *)0x0607E9EC;

  piVar8 = (int *)(0x0607E9EC + 4);

  piVar9 = piVar8;

  for (uVar7 = 1; uVar7 < *(int *)puVar3 - 1U; uVar7 = uVar7 + 1) {

    iVar4 = 0x238;

    *(int *)(*piVar9 + iVar4) = piVar9[-1];

    *(int *)(*piVar9 + iVar4 + 4) = piVar9[1];

    piVar9 = piVar9 + 1;

  }

  *(int *)(*(int *)puVar2 + 0x238) = *piVar9;

  iVar4 = (int)DAT_0600d536;

  *(int *)(*(int *)puVar2 + iVar4) = *piVar8;

  *(int *)(*piVar9 + iVar4 + -4) = piVar9[-1];

  *(int *)(*piVar9 + iVar4) = *(int *)puVar2;

  *(int *)0x060786B4 = *(int *)(*piVar9 + iVar4 + -0x50);

  return;

}

void FUN_0600d50c()
{

  char *puVar1;

  int iVar2;

  int iVar3;

  char *puVar4;

  unsigned int uVar5;

  int *piVar6;

  int iVar7;

  int iVar8;

  int iVar9;

  int local_30;

  int iStack_2c;

  int iStack_28;

  int iStack_24;

  puVar1 = (int *)0x0607EA98;

  puVar4 = (char *)0x0607E944;

  *(int *)0x0607EBDC = 0;

  iStack_28 = 0;

  iVar8 = 0;

  piVar6 = (int *)0x0607E94C;

  for (uVar5 = 0; uVar5 < *(unsigned int *)puVar1; uVar5 = uVar5 + 1) {

    iVar3 = *piVar6;

    piVar6 = piVar6 + 1;

    *(int *)(iVar3 + DAT_0600d5d6) = 0;

    (*(int(*)())0x06034F78)();

    (*(int(*)())0x06034F78)();

    (*(int(*)())0x06034F78)();

    (*(int(*)())0x06034F78)();

    (*(int(*)())0x06034F78)();

  }

  iVar3 = *(int *)puVar4;

  if ((GAME_STATE_BIT & 0x10060000) == 0) {

    (*(int(*)())0x06027358)(*(int *)0x06063EF0,&local_30,&iStack_2c);

    local_30 = (*(int(*)())0x06027552)(-local_30,0x00070000);

    iStack_2c = (*(int(*)())0x06027552)(iStack_2c,0x00070000);

    local_30 = local_30 + *(int *)0x06063DF8;

    iStack_2c = iStack_2c + *(int *)(0x06063DF8 + 8);

  }

  else {

    (*(int(*)())0x06027358)(*(int *)(*(int *)puVar4 + 0x20),&local_30,&iStack_2c);

    local_30 = (*(int(*)())0x06027552)(-local_30,0x00050000);

    iStack_2c = (*(int(*)())0x06027552)(iStack_2c,0x00050000);

    local_30 = local_30 + *(int *)(*(int *)puVar4 + 0x10);

    iStack_2c = iStack_2c + *(int *)(*(int *)puVar4 + 0x18);

  }

  iVar9 = iVar3;

  for (uVar5 = *(unsigned int *)puVar1; 1 < uVar5; uVar5 = uVar5 - 1) {

    iVar2 = 0x238;

    iVar3 = *(int *)(iVar3 + iVar2);

    iVar9 = *(int *)(iVar9 + iVar2 + 4);

    *(unsigned int *)(iVar3 + iVar2 + -0x20) = uVar5;

    *(unsigned int *)(iVar9 + iVar2 + -0x20) = uVar5;

    iVar2 = local_30 - *(int *)(iVar3 + 0x10);

    if (iVar2 < 0) {

      iVar2 = *(int *)(iVar3 + 0x10) - local_30;

    }

    iStack_24 = *(int *)(iVar3 + 0x18);

    iVar7 = iStack_2c - iStack_24;

    if (iVar7 < 0) {

      iVar7 = iStack_24 - iStack_2c;

    }

    iVar2 = iVar2 + iVar7;

    if ((iVar2 < (int)0x000C0000) && (iStack_28 < 3)) {

      (*(int(*)())0x06034F78)();

      iStack_28 = iStack_28 + 1;

    }

    else if ((iVar2 < (int)0x00230000) && (iVar8 < 7)) {

      (*(int(*)())0x06034F78)();

      iVar8 = iVar8 + 1;

    }

    else if (iVar2 < (int)0x00780000) {

      (*(int(*)())0x06034F78)();

    }

  }

  (*(int(*)())0x06034F78)();

  iVar8 = *(int *)(*(int *)puVar4 + (int)DAT_0600d76a);

  puVar4 = (char *)0x06078B68;

  for (uVar5 = 1; uVar5 < *(unsigned int *)puVar1; uVar5 = uVar5 + 1) {

    iVar3 = *(int *)(puVar4 + DAT_0600d76a) - iVar8;

    (*(int(*)())0x06034F78)();

    (*(int(*)())0x06034F78)();

    if ((iVar3 < 3) && (0 < iVar3)) {

      (*(int(*)())0x06034F78)();

    }

    if ((iVar3 < 1) && (-2 < iVar3)) {

      (*(int(*)())0x06034F78)();

    }

    puVar4 = puVar4 + PTR_DAT_0600d770;

  }

  return;

}

/* checkpoint_crossing_handler -- Handle checkpoint transitions for car.
 * Computes delta between current and previous checkpoint IDs.
 * Delta < -1: forward lap wrap (increment lap at +0x228, trigger complete).
 * Delta -1..+1: normal crossing (validate position, scan collisions).
 * Delta > +1: backward crossing (decrement lap, check halfway).
 * Sets 0x0605DE3C = 0 (forward) or 1 (backward) on lap completion. */
int FUN_0600d780(param_1)
    int param_1;
{
    int *lap_total = (int *)0x0607EA9C;
    int *checkpoint_flags = (int *)0x06063F1C;
    int car = CAR_PTR_CURRENT;
    int cur_cp = *(int *)(car + DAT_0600d82a);
    int prev_off = DAT_0600d82a + 4;
    int delta = cur_cp - *(int *)(car + prev_off);
    int result;

    if (cur_cp != *(int *)(car + prev_off)) {
        if (delta < -1) {
            /* Forward lap wrap: crossed start going forward */
            result = 0x228;
            *(int *)(car + result) = *(int *)(car + result) + 1;
            result = result + -0x40;
            if ((*(int *)(car + result) == *lap_total) && (param_1 == 0)) {
                *(int *)(car + DAT_0600d82e) = 0;
                *checkpoint_flags = *(int *)0x06063F18;
                FUN_0600d9bc(0);
                result = FUN_0600d92c();
                *(int *)0x0605DE3C = 0;            /* forward direction */
            }
        } else if (delta < 2) {
            /* Normal crossing: adjacent checkpoint */
            if (param_1 == 0) {
                FUN_0600d84c();
                result = FUN_0600d8a4(0);
                return result;
            }
        } else {
            /* Backward crossing: crossed start going backward */
            result = 0x228;
            *(int *)(car + result) = *(int *)(car + result) + -1;
            int half = *lap_total;
            result = result + -0x40;
            if (((int)(half + (unsigned int)(half < 0)) >> 1 <= *(int *)(car + result)) && (param_1 == 0)) {
                *(int *)(car + DAT_0600d82e) = 0;
                *checkpoint_flags = *(int *)0x06063F18;
                FUN_0600d9bc(0);
                result = FUN_0600d92c();
                *(int *)0x0605DE3C = 1;            /* backward direction */
            }
        }
    }

    return result;
}

/* checkpoint_position_validate -- Validate checkpoint crossing position.
 * Computes delta between current and previous checkpoint index. If delta
 * is 1..15 (normal forward progress), stores checkpoint. Otherwise checks
 * if position matches halfway or halfway+2 (for lap counter logic).
 * On match, stores position and updates render offset (0x06063F20). */
int FUN_0600d84c()
{
    int car = CAR_PTR_CURRENT;
    int cur_cp = *(int *)(car + DAT_0600d894);
    int prev_off = DAT_0600d894 + -4;
    int delta = cur_cp - *(int *)(car + prev_off);
    int result;

    if ((delta < 1) || (0xf < delta)) {
        /* Not normal forward: check halfway point */
        int halfway = (int)(*(int *)0x0607EA9C + (unsigned int)(*(int *)0x0607EA9C < 0)) >> 1;
        if ((cur_cp == halfway) || (cur_cp == halfway + 2)) {
            result = 0x1e8;
            *(int *)(car + result) = cur_cp;
            result = result + 0x40;
            *(int *)0x06063F20 = *(int *)(car + result);
        }
    } else {
        /* Normal forward progress */
        result = 0x1e8;
        *(int *)(car + result) = cur_cp;
    }
    return result;
}

/* checkpoint_collision_scan -- Scan checkpoint objects for player collision.
 * Iterates through checkpoint object array at 0x06063F3C. For each entry,
 * compares object ID against car's checkpoint field (+0x1EC). If match
 * and param_1==0, calls FUN_0600d9bc to process crossing. If car flag
 * byte+3 bit 3 is set, marks collision flag at 0x060786AC. */
int FUN_0600d8a4(param_1)
    int param_1;
{
    char *cp_list_ptr = (char *)0x06063F3C;     /* checkpoint object list */
    char *coll_flag   = (char *)0x060786AC;     /* collision detected flag */
    char *car_ptr     = (char *)0x0607E940;     /* current car pointer */
    char *car_ptr2    = (int *)0x0607E944;      /* secondary car pointer */
    unsigned int idx = 0;
    unsigned int count = **(unsigned int **)0x06063F3C;

    if (count != 0) {
        do {
            if (((*(int *)((idx << 2) + *(int *)(*(int *)cp_list_ptr + 4)) ==
                  *(int *)(*(int *)car_ptr + 0x01EC)) && (param_1 == 0)) &&
                (FUN_0600d9bc(idx + 1), (*(unsigned char *)(*(int *)car_ptr2 + 3) & 8) != 0)) {
                *(int *)coll_flag = 1;
            }
            idx = idx + 1;
        } while (idx < count);
    }
}

/* lap_complete_update -- Process lap completion for current car.
 * If checkpoint count exceeds total-1, sets race finish flag (0x0607EBF4=3)
 * and increments car's lap counter. Resets lap timer (0x0607EAC0=0x28),
 * calls FUN_0600dcc8 for lap-end processing. Computes lap time delta from
 * 0x060786B0, stores per-lap time in array at 0x0607EBF8, and tracks
 * best lap time at PTR_DAT_0600d99c. */
int FUN_0600d92c()
{
    int car = CAR_PTR_CURRENT;

    /* Check if all checkpoints completed */
    if (*(int *)0x06063F28 - 1U < *(unsigned int *)(car + DAT_0600d996)) {
        *(int *)0x0607EBF4 = 3;                 /* race complete flag */
        *(int *)(car + DAT_0600d998) = *(int *)(car + DAT_0600d998) + 1;
    }

    *(int *)0x0607EAC0 = 0x28;                  /* reset lap timer */
    FUN_0600dcc8();

    /* Compute lap time delta */
    int time_off = (int)DAT_0600d99a;
    int cur_time = *(int *)0x060786B0;
    int prev_time = *(int *)(car + time_off);
    *(int *)(car + time_off) = *(int *)0x060786B0;
    int lap_time = cur_time - prev_time;
    *(int *)0x060786A4 = *(int *)(car + time_off);
    *(int *)(car + time_off + -0xc) = lap_time;

    /* Store per-lap time */
    *(int *)(0x0607EBF8 + (*(int *)(car + time_off + -0x10) + -1) << 2) = lap_time;

    /* Update best lap time */
    int best = *(int *)(car + time_off + 0x14);
    if ((lap_time < best) || (best == 0)) {
        *(int *)(car + PTR_DAT_0600d99c) = lap_time;
    }
    return 0;
}

/* race_progress_track -- Track race progress via CD sector reads and lap changes.
 * If param_1==0 (player car): monitors lap field (car+0x228) for changes,
 * increments lap counter (0x06063F24), stores to car+0x21C. Resets CD read
 * flag (0x06063F1C) when lap count reaches threshold (0x06063F28).
 * Then checks CD sector availability (0x06035280), issues CD read (0x06034F78),
 * increments sector counter (car+0x230). For multi-car races, calls
 * 0x0600dd88 for AI progress if car flag bit 3 not set. */
void FUN_0600d9bc(param_1)
    int param_1;
{
    register int *cd_read_flag asm("r14") = (int *)0x06063F1C;
    register int car asm("r5") = CAR_PTR_CURRENT;
    unsigned int sector_mask;

    if (param_1 == 0) {
        if (*(int *)0x06063F18 == *cd_read_flag) {
            if (*(int *)(car + 0x228) != *(int *)0x06063F20) {
                *(int *)0x06063F20 = *(int *)(car + 0x228);  /* save current lap */
                int lap_count = *(int *)0x06063F24;
                *(int *)0x06063F24 = lap_count + 1;
                *(int *)(car + 0x21C) = lap_count + 1;  /* write to car struct */
                if ((unsigned int)*(int *)0x06063F24 < *(unsigned int *)0x06063F28) {
                    *cd_read_flag = 0;  /* reset for next sector batch */
                }
            }
        }
    }

    sector_mask = (*(int(*)())0x06035280)();  /* cd_sector_available */
    if (((unsigned int)*cd_read_flag & sector_mask) == 0) {
        *cd_read_flag = *cd_read_flag | sector_mask;
        (*(int(*)())0x06034F78)();  /* cd_read_sector */
        *(int *)(car + 0x230) = *(int *)(car + 0x230) + 1;  /* increment sector count */
        if (CAR_COUNT != 0) {
            if (param_1 != 0) {
                if ((*(unsigned char *)(car + 3) & 8) == 0) {
                    (*(void(*)())0x0600dd88)();  /* ai_progress_update */
                    return;
                }
            }
        }
    }
}

void FUN_0600da7c()
{

  short sVar1;

  char *puVar2;

  unsigned int uVar3;

  int iVar4;

  short *puVar5;

  short *psVar6;

  short uVar7;

  unsigned int uVar8;

  puVar2 = (char *)0x0607869A;

  iVar4 = CAR_PTR_CURRENT;

  uVar7 = 1;

  if (*(int *)(iVar4 + DAT_0600db40) != 0) {

    if (*(short *)0x0607869A != 0) {

      psVar6 = (short *)0x06078698;

      (*(int(*)())0x06034F78)();

      *psVar6 = *psVar6 + 1;

      FUN_0600db9e();

      return;

    }

    return;

  }

  sVar1 = *(short *)(*(int *)(iVar4 + DAT_0600db44) * 0x18 + *(int *)(iVar4 + DAT_0600db44 + -4) +

                    0xe);

  uVar3 = (unsigned int)(unsigned short)((short)*(int *)(iVar4 + 0x28) + sVar1 * -4);

  uVar8 = *(int *)(iVar4 + 0x20) + sVar1 * -4 & 0xffff;

  if (((((int)DAT_0600db46 <= (int)uVar3) && ((int)uVar3 <= (int)0x0000C000)) &&

      ((int)DAT_0600db46 <= (int)uVar8)) && ((int)uVar8 <= (int)0x0000C000)) {

    psVar6 = (short *)0x06078698;

    (*(int(*)())0x06034F78)();

    *psVar6 = *psVar6 + 1;

    *(short *)puVar2 = uVar7;

    FUN_0600db9e();

    return;

  }

  uVar7 = 0;

  puVar5 = (short *)0x06078698;

  (*(int(*)())0x06034F78)();

  *puVar5 = uVar7;

  *(short *)puVar2 = uVar7;

  FUN_0600dc74();

  return;

}

/* car_item_pickup_check -- Check if car has picked up an item (flag bit 2).
 * If car flag byte +2 has bit 2 set: clears it, increments pickup counter
 * at DAT_0600dbda, resets pickup timer (0x0607EABC=0x28), adds score
 * from 0x0607EAA0 to total at 0x0607EAAC, and calls sound handler
 * (0x0601D7D0). Returns car flag byte otherwise. */
unsigned int FUN_0600db64()
{
    int car = CAR_PTR_CURRENT;

    if (((int)*(char *)(car + 2) & 4U) != 0) {
        *(unsigned char *)(car + 2) = *(unsigned char *)(car + 2) & 0xfb;
        *(int *)(car + DAT_0600dbda) = *(int *)(car + DAT_0600dbda) + 1;
        *(int *)0x0607EABC = 0x28;
        *(int *)0x0607EAAC = *(int *)0x0607EAAC + *(int *)0x0607EAA0;
        return (*(int(*)())0x0601D7D0)();
    }
    return (int)*(char *)(car + 2);
}

/* checkpoint_vdp_render -- Render checkpoint crossing VDP sprites.
 * On first 4 frames of 8-frame cycle, draws sprites via FUN_06028400
 * using course-specific tile data (0x060637F8 or 0x06063808).
 * On frames 4-7, clears sprites (FUN_0600dc74). Every 64 frames,
 * plays checkpoint sound (0xAE1138FF/0xAE1139FF) and cycles animation
 * counter at 0x060786A8 (resets after 7 cycles). */
unsigned int FUN_0600db9e()
{
    int *anim_counter = (int *)0x060786A8;
    unsigned int result;

    if ((*(unsigned short *)0x06078698 & 7) < 4) {
        /* First 4 frames: draw checkpoint sprites */
        if (*(int *)0x06078644 == 1) {
            (*(int(*)())0x06028400)(8, *(int *)0x060637F8, 0xac0,
                       *(int *)(0x060637F8 + 4) + (int)DAT_0600dbdc, 0x060637F8);
        } else {
            (*(int(*)())0x06028400)(8, *(int *)0x06063808, (int)DAT_0600dc9a,
                       *(int *)(0x06063808 + 4) + (int)DAT_0600dc98, 0x06063808);
        }
    } else {
        FUN_0600dc74();                            /* clear checkpoint sprites */
    }

    result = (unsigned int)*(unsigned short *)0x06078698;

    /* Every 64 frames: play sound and cycle animation */
    if ((*(unsigned short *)0x06078698 & 0x3f) == 0) {
        int count = *anim_counter;
        *(unsigned int *)anim_counter = count + 1U;
        if (count + 1U < 7) {
            result = (*(int(*)())0x0601D5F4)(0, 0xAE1138FF);
        } else {
            int sound_id = 0xAE1138FF;
            if (*(int *)0x06078644 == 1) {
                sound_id = 0xAE1139FF;             /* alternate course sound */
            }
            result = (*(int(*)())0x0601D5F4)(0, sound_id);
            *(short *)0x06086054 = 0x28;           /* animation timer reset */
            *anim_counter = 0;
        }
    }

    return result;
}

/* checkpoint_vdp_clear -- Clear two VDP sprite entries for checkpoint display.
 * Calls VDP attribute setter (FUN_060284AE) twice with different tile IDs
 * to blank out checkpoint crossing indicator sprites. */
void FUN_0600dc74(void)
{
    register int dest asm("r0") = 0x0605ACE8;
    register int vdp_attr_set asm("r3") = 0x060284AE;
    (*(int(*)())vdp_attr_set)(8, (int)DAT_0600dc9c, 0x60, dest);
    (*(int(*)())vdp_attr_set)(8, (int)DAT_0600dc9e, 0x60, dest);
}

/* race_distance_compute -- Compute car's distance to next checkpoint.
 * Reads checkpoint position from track data (stride 0x18, indexed by
 * 0x0607EA9C). Computes absolute X and Z deltas from car position,
 * divides sum via 0x06034FE0 to get distance. Stores at 0x0607869C.
 * Computes speed estimate (GAME_STATE_VAR*5 - distance) at 0x060786B0.
 * For multiplayer (CAR_COUNT!=0), also stores speed delta. */
int FUN_0600dcc8()
{
    int car = CAR_PTR_CURRENT;
    int *cp_pos = (int *)(*(int *)0x0607EA9C * 0x18 + *(int *)(car + DAT_0600dd62));

    /* Compute absolute distance to checkpoint */
    int cp_x = *cp_pos;
    int dx = cp_x - *(int *)(car + 0x10);
    if (dx < 0) {
        dx = *(int *)(car + 0x10) - cp_x;
    }
    int cp_z = cp_pos[1];
    int dz = cp_z - *(int *)(car + 0x18);
    if (dz < 0) {
        dz = *(int *)(car + 0x18) - cp_z;
    }

    int dist = (*(int(*)())0x06034FE0)(car, dx + dz);
    *(int *)0x0607869C = dist;
    *(int *)0x060786B0 = GAME_STATE_VAR * 5 - dist;

    int count = CAR_COUNT;
    if (count != 0) {
        *(int *)0x060786A0 = *(int *)0x060786B0 - *(int *)0x0605A21C;
        *(int *)0x0605A21C = *(int *)0x060786B0;
    }
    return count;
}

/* race_distance_compute_indexed -- Compute distance to indexed checkpoint object.
 * Like race_distance_compute but uses checkpoint list (0x06063F3C) to
 * look up checkpoint object by param_1 index. Computes absolute X/Z
 * distance, stores result and speed estimate. Always stores speed delta
 * (unlike FUN_0600dcc8 which gates on CAR_COUNT). */
void FUN_0600dd88(param_1)
    int param_1;
{
    int car = CAR_PTR_CURRENT;
    int *cp_pos = (int *)(*(int *)(car + DAT_0600de1e) +
                  *(int *)((param_1 + -1) << 2 + *(int *)(*(int *)0x06063F3C + 4)) * 0x18);

    int cp_x = *cp_pos;
    int dx = cp_x - *(int *)(car + 0x10);
    if (dx < 0) {
        dx = *(int *)(car + 0x10) - cp_x;
    }
    int cp_z = cp_pos[1];
    int dz = cp_z - *(int *)(car + 0x18);
    if (dz < 0) {
        dz = *(int *)(car + 0x18) - cp_z;
    }

    int dist = (*(int(*)())0x06034FE0)(dx + dz);
    *(int *)0x0607869C = dist;
    int speed = GAME_STATE_VAR * 5 - dist;
    *(int *)0x060786B0 = speed;
    *(int *)0x060786A0 = speed - *(int *)0x0605A21C;
    *(int *)0x0605A21C = *(int *)0x060786B0;
}

/* player_car_iteration -- Per-frame player car update entry point.
 * Sets half car count, then runs physics + per-car loop. */
void FUN_0600de40(void)
{
    HALF_CAR_COUNT = (short)(CAR_ITERATION_BASE >> 1);
    FUN_0600e410();   /* physics_entry */
    FUN_0600e0c0();   /* per_car_loop */
}

/* camera_car_iteration -- Per-frame camera target car update.
 * Same half-car-count setup, but switches current car to target
 * and runs camera setup instead of physics. */
void FUN_0600de54(void)
{
    HALF_CAR_COUNT = (short)(CAR_ITERATION_BASE >> 1);
    CAR_PTR_CURRENT = CAR_PTR_TARGET;
    FUN_0600e99c();   /* camera_setup */
    FUN_0600e0c0();   /* per_car_loop */
}

/* race_frame_render_all -- Main per-frame race rendering loop.
 * Queries car count via FUN_06035340, stores at 0x060786CA.
 * Iterates each car slot: sets mode flags at 0x0607EAE4/0x0607ED8C,
 * configures car pointers at 0x0607E940/0x0607E944, calls FUN_0600e4f2.
 * After loop: post-render (0x0600A8BC), dispatch to FUN_0602F7EA or
 * FUN_06034900 based on 0x06083255, then FUN_0602F99C and FUN_0600e0c0. */
void FUN_0600de70()
{
    short *ranking_ptr = (short *)0x0607ED88;
    char *mode_flag = (char *)0x0607EAE4;
    char *active_flag = (char *)0x0607ED8C;
    char *car_target = (char *)0x0607E940;
    int *car_source = (int *)0x0607E944;
    short car_count = (*(int(*)())0x06035340)();
    *(short *)0x060786CA = car_count;
    char *base_car = (char *)0x06078900;           /* CAR_ARRAY_BASE */
    int saved_state = *(int *)0x06063EF0;
    char *first_car = (char *)(0x06078900 + DAT_0600deb2);
    unsigned short i;

    for (i = 0; i < (unsigned char)*(int *)0x06078634; i = i + 1) {
        if (*(int *)0x06078635 == '\0') {
            if (*(int *)mode_flag == 0) {
                *(int *)mode_flag = 1;
            }
        } else if (i == 0) {
            *(short *)active_flag = 1;
            *(char **)car_source = first_car;
            *(char **)car_target = first_car;
        } else {
            *(short *)active_flag = 0;
            *(int *)ranking_ptr = *(int *)ranking_ptr + -2;
            *(char **)car_source = base_car;
            *(int *)0x06063EF0 = saved_state;
            *(int *)car_target = *(int *)car_source;
        }
        FUN_0600e4f2();                            /* per-car render */
    }

    (*(int(*)())0x0600A8BC)();                     /* post-render cleanup */
    if (*(int *)0x06083255 == '\0') {
        (*(int(*)())0x0602F7EA)();                 /* normal render path */
    } else {
        (*(int(*)())0x06034900)();                 /* alternate render path */
    }
    (*(int(*)())0x0602F99C)();                     /* final render pass */
    FUN_0600e0c0();                                /* per-car cleanup */
}

/* replay_render_dispatch -- Dispatch replay rendering based on replay mode.
 * Sets half-car-count, then dispatches to FUN_0600e410 (mode 0) or
 * FUN_0600e47c (mode 1/2) based on replay state at 0x06083261.
 * Always finishes with per-car loop (FUN_0600e0c0). */
void FUN_0600df66(void)
{
    char mode = *(int *)0x06083261;
    *(short *)0x060786CA = (short)(*(int *)0x0607EA98 >> 1);
    if (mode == '\0') {
        FUN_0600e410();
    } else if (mode == '\x01') {
        FUN_0600e47c();
    } else if (mode == '\x02') {
        FUN_0600e47c();
    }
    FUN_0600e0c0();
}

/* visual_physics_full_update -- Full visual physics update for target car.
 * Sets up car pointers, computes half-car-count and tile index,
 * runs wheel transform, updates 4 render transform buffers via FUN_06027CA4,
 * then runs per-car loop. */
void FUN_0600dfd0(void)
{
    register int buffer_update asm("r3") = 0x06027CA4;
    int car = CAR_PTR_TARGET;

    HALF_CAR_COUNT = (short)(CAR_ITERATION_BASE >> 1);
    CAR_PTR_CURRENT = car;
    *(int *)0x0607E948 = 0x06078B68;  /* secondary car pointer */

    (*(int(*)())0x0602DB00)();        /* pre-render setup */
    int tile_idx = (*(int(*)())0x06006838)(*(int *)(car + CAR_X), *(int *)(car + CAR_Z));
    *(int *)0x060786B8 = tile_idx;
    (*(int(*)())0x06005ECC)();        /* wheel_transform */

    /* Update 4 render transform buffers */
    (*(int(*)())buffer_update)(0x06063EB0, 0);
    (*(int(*)())buffer_update)(0x06063E9C, 1);
    (*(int(*)())buffer_update)(0x06063ED8, 2);
    (*(int(*)())buffer_update)(0x06063EC4, 3);
    FUN_0600e0c0();                   /* per_car_loop */
}
