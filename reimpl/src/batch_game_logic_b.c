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

void FUN_0600c5d6()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  int iVar4;

  int uVar5;

  int iVar6;

  int iVar7;

  char auStack_1c [8];

  puVar3 = (char *)0x06078680;

  puVar2 = (char *)0x0607EBDC;

  puVar1 = (int *)0x06027552;

  iVar7 = CAR_PTR_CURRENT;

  iVar4 = FUN_0600cd40();

  iVar6 = iVar4 + 0x18;

  if (((*(short *)0x06087804 == 2) || (0 < *(int *)(iVar7 + DAT_0600c616))) ||

     (0 < *(int *)(iVar7 + PTR_DAT_0600c618))) {

    FUN_0600ca96(puVar3);

  }

  else if ((((*(unsigned char *)(CAR_PTR_TARGET + 3) & 8) == 0) &&

           (*(int *)(iVar7 + DAT_0600c6f6) < 1)) && ((*(unsigned char *)(iVar7 + DAT_0600c6f8) & 0x20) == 0))

  {

    if ((*(int *)puVar2 < 0xb) && (*(int *)(iVar7 + DAT_0600c6fa) < 0x66)) {

      FUN_0600cf58(iVar6);

    }

    if (*(int *)(iVar7 + DAT_0600c6fa) < 1) {

      FUN_0600cc38(iVar6,puVar3);

    }

    else {

      *(int *)(iVar7 + DAT_0600c6fa) = *(int *)(iVar7 + DAT_0600c6fa) + -2;

      FUN_0600ca96(puVar3);

      *(int *)puVar2 = *(int *)puVar2 + 1;

    }

  }

  else {

    FUN_0600cc38(iVar6,puVar3);

  }

  if (*(short *)0x06087804 == 3) {

    uVar5 = (*(int(*)())puVar1)(*(int *)(iVar4 + 0x20),*(int *)(iVar7 + DAT_0600c6fc));

    *(int *)(DAT_0600c6fe + iVar7) = uVar5;

  }

  FUN_0600c8cc(iVar7,puVar3);

  if ((**(unsigned int **)0x0607E940 & (unsigned int)0x00E00000) == 0) {

    *(int *)(iVar7 + 0x20) = (int)*(short *)(puVar3 + 0xe);

    (*(int(*)())0x06027358)(-*(int *)(iVar7 + 0x28),DAT_0600c702 + iVar7,DAT_0600c700 + iVar7);

    iVar4 = (*(int(*)())puVar1)(*(int *)(iVar7 + 0xc),*(int *)(iVar7 + DAT_0600c702));

    *(int *)(iVar7 + 0x10) = *(int *)(iVar7 + 0x10) + iVar4;

    iVar4 = (*(int(*)())puVar1)(*(int *)(iVar7 + 0xc),*(int *)(iVar7 + DAT_0600c700));

    *(int *)(iVar7 + 0x18) = *(int *)(iVar7 + 0x18) + iVar4;

    *(int *)(iVar7 + 0x14) = 0;

  }

  else {

    FUN_0600c928(iVar7);

    FUN_0600c7d4(iVar7,puVar3);

    uVar5 = (*(int(*)())0x06006838)(*(int *)(iVar7 + 0x10),*(int *)(iVar7 + 0x18))

    ;

    (*(int(*)())0x06027EDE)(uVar5,iVar7 + 0x10,auStack_1c);

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

void FUN_0600c994()
{

  short sVar1;

  unsigned short uVar2;

  char *puVar3;

  char *puVar4;

  short sVar5;

  int iVar6;

  unsigned int uVar7;

  unsigned short uVar8;

  unsigned int uVar9;

  int *piVar10;

  int iVar11;

  unsigned short uVar12;

  short *psVar13;

  short local_30 [8];

  short local_20 [2];

  puVar4 = (char *)0x0607EB88;

  puVar3 = (char *)0x0602744C;

  uVar2 = DAT_0600c9e6;

  iVar11 = CAR_PTR_TARGET;

  iVar6 = *(int *)(iVar11 + DAT_0600c9e4) + 1;

  sVar1 = *(short *)(((iVar6 << 3) + 3) << 4 + *(int *)0x0607EB88 + 10);

  iVar6 = (iVar6 << 7);

  for (psVar13 = local_30; psVar13 < local_20; psVar13 = psVar13 + 2) {

    piVar10 = (int *)(*(int *)puVar4 + iVar6);

    sVar5 = (*(int(*)())puVar3)(*piVar10 - *(int *)(iVar11 + 0x10),

                              piVar10[1] - *(int *)(iVar11 + 0x18));

    *psVar13 = -sVar5;

    piVar10 = (int *)(*(int *)puVar4 + iVar6 + 0x10);

    sVar5 = (*(int(*)())puVar3)(*piVar10 - *(int *)(iVar11 + 0x10),

                              piVar10[1] - *(int *)(iVar11 + 0x18));

    psVar13[1] = -sVar5;

    iVar6 = iVar6 + 0x20;

  }

  sVar1 = sVar1 * -4;

  uVar7 = (unsigned int)(short)(local_30[0] + sVar1);

  if ((int)uVar7 < 0) {

    uVar7 = -uVar7;

  }

  uVar7 = uVar7 & 0xffff;

  uVar12 = 0;

  psVar13 = local_30;

  uVar8 = uVar2;

  while (psVar13 = psVar13 + 1, psVar13 < local_20) {

    uVar9 = (unsigned int)(short)(*psVar13 + sVar1);

    if ((int)uVar9 < 0) {

      uVar9 = -uVar9;

    }

    if ((int)uVar9 < (int)uVar7) {

      uVar7 = uVar9 & 0xffff;

      uVar12 = uVar8;

    }

    uVar8 = uVar8 + uVar2;

  }

  *(unsigned int *)(iVar11 + DAT_0600cac0) = (unsigned int)uVar12;

  return;

}

void FUN_0600ca96(param_1)
    int *param_1;
{

  int iVar1;

  int *piVar2;

  int iVar3;

  unsigned int uVar4;

  int *piVar5;

  unsigned int uVar6;

  iVar1 = CAR_PTR_CURRENT;

  iVar3 = *(int *)(iVar1 + DAT_0600cac2) - *(int *)(iVar1 + DAT_0600cac2 + 4);

  if ((iVar3 < 8) && (-8 < iVar3)) {

    *(int *)(iVar1 + DAT_0600cac2 + 4) = *(int *)(iVar1 + DAT_0600cac2);

  }

  else if (iVar3 < 1) {

    *(int *)(iVar1 + DAT_0600cb84) = *(int *)(iVar1 + DAT_0600cb84) + -4;

  }

  else {

    *(int *)(iVar1 + DAT_0600cb84) = *(int *)(iVar1 + DAT_0600cb84) + 4;

  }

  uVar6 = (*(unsigned int *)(iVar1 + DAT_0600cb84) & (int)DAT_0600cb86 & 0xffff) >> 6;

  uVar4 = (*(unsigned int *)(iVar1 + DAT_0600cb84) & 0xffff) >> 8;

  if ((uVar6 == 0) || (6 < uVar4)) {

    piVar2 = (int *)((uVar4 + *(int *)(iVar1 + PTR_DAT_0600cb88) << 3) << 4 +

                    *(int *)0x0607EB88);

    *param_1 = *piVar2;

    param_1[2] = piVar2[1];

  }

  else {

    iVar1 = uVar4 + *(int *)(iVar1 + PTR_DAT_0600cb88) << 3;

    piVar2 = (int *)((iVar1 << 4) + *(int *)0x0607EB88);

    piVar5 = (int *)((iVar1 + 1) << 4 + *(int *)0x0607EB88);

    *param_1 = (int)(*piVar2 * (4 - uVar6) + *piVar5 * uVar6) >> 2;

    param_1[2] = (int)(piVar2[1] * (4 - uVar6) + piVar5[1] * uVar6) >> 2;

  }

  *(short *)(param_1 + 3) = *(short *)(piVar2 + 2);

  *(short *)((int)param_1 + 0xe) = *(short *)((int)piVar2 + 10) << 2;

  *(short *)(param_1 + 4) = *(short *)(piVar2 + 3);

  *(short *)((int)param_1 + 0x12) = 0;

  return;

}

void FUN_0600cb90(param_1, param_2)
    int *param_1;
    unsigned int param_2;
{

  unsigned int uVar1;

  int *piVar2;

  unsigned int uVar3;

  int *piVar4;

  if ((param_2 & 1) == 0) {

    piVar2 = (int *)(((*(unsigned int *)(CAR_PTR_CURRENT + 0x1f8) >> 8) +

                     ((param_2 & 0xffff) >> 1) << 3) << 4 + *(int *)0x0607EB88);

    *param_1 = *piVar2;

    param_1[2] = piVar2[1];

  }

  else {

    uVar3 = ((param_2 & 0xffff) >> 1) + 1;

    if (*(unsigned int *)0x0607EA9C < uVar3) {

      uVar3 = 0;

    }

    uVar1 = *(unsigned int *)(CAR_PTR_CURRENT + 0x1f8) >> 8;

    piVar2 = (int *)((uVar1 + ((param_2 & 0xffff) >> 1) << 3) << 4 + *(int *)0x0607EB88);

    piVar4 = (int *)((uVar1 + (uVar3 << 3)) << 4 + *(int *)0x0607EB88);

    *param_1 = *piVar2 + *piVar4 >> 1;

    param_1[2] = piVar2[1] + piVar4[1] >> 1;

  }

  *(short *)(param_1 + 3) = *(short *)(piVar2 + 2);

  *(short *)((int)param_1 + 0xe) = *(short *)((int)piVar2 + 10) << 2;

  *(short *)(param_1 + 4) = *(short *)(piVar2 + 3);

  *(short *)((int)param_1 + 0x12) = 0;

  return;

}

void FUN_0600cc38(param_1, param_2)
    int param_1;
    int *param_2;
{

  int *piVar1;

  int iVar2;

  int *piVar3;

  int iVar4;

  unsigned int uVar5;

  unsigned int uVar6;

  iVar2 = CAR_PTR_CURRENT;

  iVar4 = *(int *)(iVar2 + DAT_0600ccf6) - *(int *)(iVar2 + DAT_0600ccf6 + 4);

  if ((iVar4 < 8) && (-8 < iVar4)) {

    *(int *)(iVar2 + DAT_0600ccf6 + 4) = *(int *)(iVar2 + DAT_0600ccf6);

  }

  else if (iVar4 < 1) {

    *(int *)(iVar2 + DAT_0600ccf8) = *(int *)(iVar2 + DAT_0600ccf8) + -8;

  }

  else {

    *(int *)(iVar2 + DAT_0600ccf8) = *(int *)(iVar2 + DAT_0600ccf8) + 8;

  }

  *(int *)(iVar2 + DAT_0600ccf6) = (int)*(short *)(param_1 + 0x14);

  uVar6 = (unsigned int)((*(unsigned short *)(param_1 + 0x14) & 0xff) >> 6);

  uVar5 = (unsigned int)(*(unsigned short *)(param_1 + 0x14) >> 8);

  if ((uVar6 == 0) || (6 < uVar5)) {

    piVar1 = (int *)((uVar5 + *(int *)(iVar2 + DAT_0600cdbc) << 3) << 4 + *(int *)0x0607EB88)

    ;

    *param_2 = *piVar1;

    param_2[2] = piVar1[1];

  }

  else {

    iVar2 = uVar5 + *(int *)(iVar2 + DAT_0600ccfa) << 3;

    piVar1 = (int *)((iVar2 << 4) + *(int *)0x0607EB88);

    piVar3 = (int *)((iVar2 + 1) << 4 + *(int *)0x0607EB88);

    *param_2 = (int)(*piVar1 * (4 - uVar6) + *piVar3 * uVar6) >> 2;

    param_2[2] = (int)(piVar1[1] * (4 - uVar6) + piVar3[1] * uVar6) >> 2;

  }

  *(short *)(param_2 + 3) = *(short *)(param_1 + 0xc);

  *(short *)((int)param_2 + 0xe) = *(short *)(param_1 + 0xe) << 2;

  *(short *)(param_2 + 4) = *(short *)(param_1 + 0x10);

  *(short *)((int)param_2 + 0x12) = *(short *)(param_1 + 0x12);

  return;

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

int FUN_0600ceba()
{

  char *puVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  iVar2 = (int)DAT_0600cf3a;

  iVar4 = CAR_PTR_CURRENT;

  iVar3 = *(int *)0x0607EB84;

  *(int *)(iVar4 + iVar2 + 0x6c) = *(int *)(iVar4 + iVar2 + 0x68);

  *(unsigned int *)(iVar4 + iVar2 + 0x68) = (unsigned int)*(unsigned short *)(*(int *)(iVar4 + iVar2) << 2 + iVar3);

  (*(int(*)())0x06035228)();

  (*(int(*)())0x06035228)();

  iVar2 = DAT_0600cf40 + -4;

  iVar3 = (int)(short)((short)*(int *)(iVar4 + DAT_0600cf40) -

                      (short)*(int *)(iVar4 + iVar2));

  if ((0 < iVar3) && (*(int *)0x0607EA9C + -0x10 < iVar3)) {

    iVar2 = 0x228;

    iVar3 = *(int *)(iVar4 + iVar2) + 1;

    *(int *)(iVar4 + iVar2) = iVar3;

    *(int *)(iVar4 + iVar2 + -0xc) = iVar3;

    puVar1 = (int *)0x0607EBD0;

    *(int *)(iVar4 + iVar2 + -8) = GAME_STATE_VAR - *(int *)(iVar4 + iVar2 + 4);

    iVar2 = iVar2 + 4;

    *(int *)(iVar4 + iVar2) = *(int *)puVar1;

  }

  return iVar2;

}

unsigned int FUN_0600cf58()
{

  unsigned int uVar1;

  unsigned int uVar2;

  unsigned int uVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  unsigned char local_18;

  iVar4 = 0x80;

  iVar6 = CAR_PTR_CURRENT;

  iVar5 = CAR_PTR_TARGET;

  if ((*(unsigned int *)(iVar6 + 4) != 0) && ((int)DAT_0600cfe4 < *(int *)(iVar6 + 8))) {

    if ((**(unsigned int **)0x0607E940 & (unsigned int)0x00C00000) == 0) {

      return *(unsigned int *)(iVar6 + 4);

    }

    (*(int(*)())0x06035168)();

    if (*(int *)(iVar6 + DAT_0600cfe6) == 0) {

      uVar1 = FUN_0600d0b8();

      return uVar1;

    }

    uVar1 = (unsigned int)(char)local_18;

    if ((uVar1 & 2) != 0) {

      if (*(int *)(iVar6 + 8) <= *(int *)(iVar5 + 8)) {

        iVar5 = (int)PTR_DAT_0600cfe8;

        *(int *)(iVar6 + iVar5 + -4) = *(int *)(iVar6 + iVar5);

        *(int *)(iVar6 + iVar5 + 8U) = iVar4;

        return iVar5 + 8U;

      }

      uVar1 = FUN_0600d12c();

    }

    if (*(int *)(iVar5 + 8) < *(int *)(iVar6 + 8)) {

      return uVar1;

    }

    if ((local_18 & 1) != 0) {

      if (*(int *)(iVar6 + DAT_0600d0aa) == 2) {

        if ((0xaf0 < *(int *)(iVar5 + 8)) && (*(int *)(iVar6 + DAT_0600d0ae) < 10)) {

          uVar1 = FUN_0600d210();

          return uVar1;

        }

        uVar1 = FUN_0600d12c();

        return uVar1;

      }

      if (*(unsigned int *)(iVar6 + DAT_0600d0aa) != 1) {

        return *(unsigned int *)(iVar6 + DAT_0600d0aa);

      }

      uVar1 = (unsigned int)DAT_0600d0b0;

      uVar2 = *(int *)(iVar5 + uVar1) >> 8;

      uVar3 = *(int *)(iVar6 + uVar1) >> 8;

      if ((uVar2 < 2) && (uVar3 < 3)) {

        iVar5 = 0x1f8;

        *(int *)(iVar6 + iVar5) = 0x300;

        uVar1 = iVar5 + 0xc;

        *(int *)(iVar6 + uVar1) = iVar4;

        return uVar1;

      }

      if (uVar2 < 6) {

        return uVar1;

      }

      if (uVar3 < 5) {

        return uVar1;

      }

      iVar5 = 0x1f8;

      *(int *)(iVar6 + iVar5) = 0x400;

      uVar1 = iVar5 + 0xc;

      *(int *)(iVar6 + uVar1) = iVar4;

      return uVar1;

    }

    FUN_0600d12c();

  }

  uVar1 = *(unsigned int *)(iVar6 + 4);

  if (uVar1 == 0) {

    uVar1 = FUN_0600d12c();

  }

  return uVar1;

}

int FUN_0600d0b8()
{

  int iVar1;

  unsigned int *puVar2;

  int iVar3;

  iVar3 = 0x200;

  puVar2 = *(unsigned int **)0x0607E940;

  iVar1 = CAR_PTR_TARGET;

  if ((*puVar2 & (unsigned int)0x00C00000) != 0) {

    if (*(int *)(iVar1 + DAT_0600d114) < *(int *)((int)puVar2 + (int)DAT_0600d114)) {

      iVar1 = *(int *)(iVar1 + DAT_0600d114) + iVar3;

    }

    else {

      iVar1 = *(int *)(iVar1 + DAT_0600d114) + -512;

    }

    if (iVar1 < 0) {

      *(int *)((int)puVar2 + 0x1f8) = 0;

    }

    else if (DAT_0600d11a < iVar1) {

      *(int *)((int)puVar2 + 0x1f8) = 0x800;

    }

    else {

      *(int *)((int)puVar2 + 0x1f8) = iVar1;

    }

    *(int *)((int)puVar2 + (int)PTR_DAT_0600d11c) = iVar3;

  }

  return 0;

}

int FUN_0600d12c()
{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  iVar2 = CAR_PTR_CURRENT;

  iVar1 = *(int *)(iVar2 + DAT_0600d192);

  iVar5 = *(int *)(iVar2 + PTR_DAT_0600d194);

  if (iVar5 == 0) {

    iVar2 = ((*(int *)(iVar1 + 0x10) - *(int *)(iVar2 + 0x10)) + *(int *)(iVar1 + 0x18)) -

            *(int *)(iVar2 + 0x18);

  }

  else {

    if (((*(int *)(iVar5 + 0x10) - *(int *)(iVar2 + 0x10)) + *(int *)(iVar5 + 0x18)) -

        *(int *)(iVar2 + 0x18) < (int)0x00080000) goto LAB_0600d1a4;

    iVar2 = ((*(int *)(iVar1 + 0x10) - *(int *)(iVar2 + 0x10)) + *(int *)(iVar1 + 0x18)) -

            *(int *)(iVar2 + 0x18);

  }

  iVar5 = iVar1;

  if ((int)0x000F0000 <= iVar2) {

    return (int)PTR_DAT_0600d194;

  }

LAB_0600d1a4:

  iVar1 = (int)DAT_0600d1fa;

  iVar3 = CAR_PTR_CURRENT;

  iVar2 = *(int *)(iVar5 + iVar1);

  iVar4 = iVar2 - *(int *)(iVar3 + iVar1);

  if ((DAT_0600d1fc <= iVar4) && (iVar4 <= DAT_0600d1fe)) {

    iVar1 = 0x300;

    if (DAT_0600d200 < iVar2) {

      iVar1 = -iVar1;

    }

    iVar2 = iVar2 + iVar1;

    if (iVar2 < 0) {

      *(int *)(iVar3 + DAT_0600d202) = 0;

    }

    else if (DAT_0600d204 < iVar2) {

      *(int *)(iVar3 + DAT_0600d202) = 0x800;

    }

    else {

      *(int *)(iVar3 + DAT_0600d202) = iVar2;

    }

    iVar1 = (int)PTR_DAT_0600d208;

    *(int *)(iVar3 + iVar1) = 0x100;

    iVar1 = iVar1 + 0x30;

    *(int *)(iVar3 + iVar1) = iVar5;

  }

  return iVar1;

}

int FUN_0600d210()
{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  iVar1 = (int)DAT_0600d26a;

  iVar3 = CAR_PTR_CURRENT;

  iVar2 = *(int *)(CAR_PTR_TARGET + iVar1);

  iVar4 = iVar2 - *(int *)(iVar3 + iVar1);

  if ((DAT_0600d26c <= iVar4) && (iVar4 <= DAT_0600d26e)) {

    if (iVar2 < *(int *)(iVar3 + DAT_0600d26a)) {

      iVar2 = iVar2 + -0x10;

    }

    else {

      iVar2 = iVar2 + 0x10;

    }

    if (iVar2 < 0) {

      *(int *)(iVar3 + DAT_0600d270) = 0;

    }

    else if (DAT_0600d272 < iVar2) {

      *(int *)(iVar3 + DAT_0600d270) = 0x800;

    }

    else {

      *(int *)(iVar3 + DAT_0600d270) = iVar2;

    }

    iVar1 = (int)PTR_DAT_0600d274;

    *(int *)(iVar3 + iVar1) = 0x40;

  }

  return iVar1;

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

int FUN_0600d780(param_1)
    int param_1;
{

  char *puVar1;

  char *puVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  puVar2 = (char *)0x0607EA9C;

  puVar1 = (int *)0x06063F1C;

  iVar4 = CAR_PTR_CURRENT;

  iVar5 = *(int *)(iVar4 + DAT_0600d82a);

  iVar3 = DAT_0600d82a + 4;

  iVar6 = iVar5 - *(int *)(iVar4 + iVar3);

  if (iVar5 != *(int *)(iVar4 + iVar3)) {

    if (iVar6 < -1) {

      iVar3 = 0x228;

      *(int *)(iVar4 + iVar3) = *(int *)(iVar4 + iVar3) + 1;

      iVar3 = iVar3 + -0x40;

      if ((*(int *)(iVar4 + iVar3) == *(int *)puVar2) && (param_1 == 0)) {

        *(int *)(iVar4 + DAT_0600d82e) = 0;

        *(int *)puVar1 = *(int *)0x06063F18;

        FUN_0600d9bc(0);

        iVar3 = FUN_0600d92c();

        *(int *)0x0605DE3C = 0;

      }

    }

    else if (iVar6 < 2) {

      if (param_1 == 0) {

        FUN_0600d84c();

        iVar3 = FUN_0600d8a4(0);

        return iVar3;

      }

    }

    else {

      iVar3 = 0x228;

      *(int *)(iVar4 + iVar3) = *(int *)(iVar4 + iVar3) + -1;

      iVar5 = *(int *)puVar2;

      iVar3 = iVar3 + -0x40;

      if (((int)(iVar5 + (unsigned int)(iVar5 < 0)) >> 1 <= *(int *)(iVar4 + iVar3)) && (param_1 == 0)) {

        *(int *)(iVar4 + DAT_0600d82e) = 0;

        *(int *)puVar1 = *(int *)0x06063F18;

        FUN_0600d9bc(0);

        iVar3 = FUN_0600d92c();

        *(int *)0x0605DE3C = 1;

      }

    }

  }

  return iVar3;

}

int FUN_0600d84c()
{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  iVar2 = CAR_PTR_CURRENT;

  iVar3 = *(int *)(iVar2 + DAT_0600d894);

  iVar1 = DAT_0600d894 + -4;

  iVar4 = iVar3 - *(int *)(iVar2 + iVar1);

  if ((iVar4 < 1) || (0xf < iVar4)) {

    iVar4 = (int)(*(int *)0x0607EA9C + (unsigned int)(*(int *)0x0607EA9C < 0)) >> 1;

    if ((iVar3 == iVar4) || (iVar3 == iVar4 + 2)) {

      iVar1 = 0x1e8;

      *(int *)(iVar2 + iVar1) = iVar3;

      iVar1 = iVar1 + 0x40;

      *(int *)0x06063F20 = *(int *)(iVar2 + iVar1);

    }

  }

  else {

    iVar1 = 0x1e8;

    *(int *)(iVar2 + iVar1) = iVar3;

  }

  return iVar1;

}

int FUN_0600d8a4(param_1)
    int param_1;
{
  char *puVar1;
  char *puVar2;
  char *puVar3;
  char *puVar4;
  unsigned int uVar5;
  unsigned int uVar6;

  puVar4 = (char *)0x06063F3C;
  puVar3 = (char *)0x060786AC;
  puVar2 = (char *)0x0607E940;
  puVar1 = (int *)0x0607E944;
  uVar6 = 0;
  uVar5 = **(unsigned int **)0x06063F3C;

  if (uVar5 != 0) {
    do {
      if (((*(int *)((uVar6 << 2) + *(int *)(*(int *)puVar4 + 4)) ==
            *(int *)(*(int *)puVar2 + 0x01EC)) && (param_1 == 0)) &&
         (FUN_0600d9bc(uVar6 + 1), (*(unsigned char *)(*(int *)puVar1 + 3) & 8) != 0)) {
        *(int *)puVar3 = 1;
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < uVar5);
  }
}

int FUN_0600d92c()
{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  iVar4 = CAR_PTR_CURRENT;

  if (*(int *)0x06063F28 - 1U < *(unsigned int *)(iVar4 + DAT_0600d996)) {

    *(int *)0x0607EBF4 = 3;

    *(int *)(iVar4 + DAT_0600d998) = *(int *)(iVar4 + DAT_0600d998) + 1;

  }

  *(int *)0x0607EAC0 = 0x28;

  FUN_0600dcc8();

  iVar1 = (int)DAT_0600d99a;

  iVar3 = *(int *)0x060786B0;

  iVar2 = *(int *)(iVar4 + iVar1);

  *(int *)(iVar4 + iVar1) = *(int *)0x060786B0;

  iVar3 = iVar3 - iVar2;

  *(int *)0x060786A4 = *(int *)(iVar4 + iVar1);

  *(int *)(iVar4 + iVar1 + -0xc) = iVar3;

  *(int *)(0x0607EBF8 + (*(int *)(iVar4 + iVar1 + -0x10) + -1) << 2) = iVar3;

  iVar1 = *(int *)(iVar4 + iVar1 + 0x14);

  if ((iVar3 < iVar1) || (iVar1 == 0)) {

    *(int *)(iVar4 + PTR_DAT_0600d99c) = iVar3;

  }

  return 0;

}

void FUN_0600d9bc(param_1)
    int param_1;
{
  register int *puVar1 asm("r14") = (int *)0x06063F1C;
  register int base asm("r5") = CAR_PTR_CURRENT;
  unsigned int uVar4;
  int offset;
  int iVar5;

  if (param_1 == 0) {
    if (*(int *)0x06063F18 == *puVar1) {
      offset = 0x228;
      if (*(int *)(base + offset) != *(int *)0x06063F20) {
        *(int *)0x06063F20 = *(int *)(base + offset);
        iVar5 = *(int *)0x06063F24;
        *(int *)0x06063F24 = iVar5 + 1;
        *(int *)(base + offset + -0xc) = iVar5 + 1;
        if ((unsigned int)*(int *)0x06063F24 < *(unsigned int *)0x06063F28) {
          *puVar1 = 0;
        }
      }
    }
  }

  uVar4 = (*(int(*)())0x06035280)();
  if (((unsigned int)*puVar1 & uVar4) == 0) {
    *puVar1 = *puVar1 | uVar4;
    (*(int(*)())0x06034F78)();
    *(int *)(base + 0x230) = *(int *)(base + 0x230) + 1;
    if (CAR_COUNT != 0) {
      if (param_1 != 0) {
        if ((*(unsigned char *)(base + 3) & 8) == 0) {
          (*(void(*)())0x0600dd88)();
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

unsigned int FUN_0600db64()
{

  char *puVar1;

  unsigned int uVar2;

  int iVar3;

  iVar3 = CAR_PTR_CURRENT;

  if (((int)*(char *)(iVar3 + 2) & 4U) != 0) {

    *(unsigned char *)(iVar3 + 2) = *(unsigned char *)(iVar3 + 2) & 0xfb;

    *(int *)(iVar3 + DAT_0600dbda) = *(int *)(iVar3 + DAT_0600dbda) + 1;

    *(int *)0x0607EABC = 0x28;

    puVar1 = (int *)0x0601D7D0;

    *(int *)0x0607EAAC = *(int *)0x0607EAAC + *(int *)0x0607EAA0;

    uVar2 = (*(int(*)())puVar1)();

    return uVar2;

  }

  return (int)*(char *)(iVar3 + 2);

}

unsigned int FUN_0600db9e()
{

  char *puVar1;

  unsigned int uVar2;

  int iVar3;

  int uVar4;

  puVar1 = (int *)0x060786A8;

  if ((*(unsigned short *)0x06078698 & 7) < 4) {

    if (*(int *)0x06078644 == 1) {

      (*(int(*)())0x06028400)(8,*(int *)0x060637F8,0xac0,

                 *(int *)(0x060637F8 + 4) + (int)DAT_0600dbdc,0x060637F8);

    }

    else {

      (*(int(*)())0x06028400)(8,*(int *)0x06063808,(int)DAT_0600dc9a,

                 *(int *)(0x06063808 + 4) + (int)DAT_0600dc98,0x06063808);

    }

  }

  else {

    FUN_0600dc74();

  }

  uVar2 = (unsigned int)*(unsigned short *)0x06078698;

  if ((*(unsigned short *)0x06078698 & 0x3f) == 0) {

    iVar3 = *(int *)puVar1;

    *(unsigned int *)puVar1 = iVar3 + 1U;

    if (iVar3 + 1U < 7) {

      uVar2 = (*(int(*)())0x0601D5F4)(0,0xAE1138FF);

    }

    else {

      uVar4 = 0xAE1138FF;

      if (*(int *)0x06078644 == 1) {

        uVar4 = 0xAE1139FF;

      }

      uVar2 = (*(int(*)())0x0601D5F4)(0,uVar4);

      *(short *)0x06086054 = 0x28;

      *(int *)puVar1 = 0;

    }

  }

  return uVar2;

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

int FUN_0600dcc8()
{

  char *puVar1;

  char *puVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int *piVar6;

  int iVar7;

  iVar5 = CAR_PTR_CURRENT;

  piVar6 = (int *)(*(int *)0x0607EA9C * 0x18 + *(int *)(iVar5 + DAT_0600dd62));

  iVar3 = *piVar6;

  iVar7 = iVar3 - *(int *)(iVar5 + 0x10);

  if (iVar7 < 0) {

    iVar7 = *(int *)(iVar5 + 0x10) - iVar3;

  }

  iVar4 = piVar6[1];

  iVar3 = iVar4 - *(int *)(iVar5 + 0x18);

  if (iVar3 < 0) {

    iVar3 = *(int *)(iVar5 + 0x18) - iVar4;

  }

  piVar6 = (int *)0x0607869C;

  iVar3 = (*(int(*)())0x06034FE0)(iVar5,iVar7 + iVar3);

  *piVar6 = iVar3;

  puVar1 = (int *)0x060786B0;

  *(int *)0x060786B0 = GAME_STATE_VAR * 5 - iVar3;

  puVar2 = (char *)0x0605A21C;

  iVar3 = CAR_COUNT;

  if (iVar3 != 0) {

    *(int *)0x060786A0 = *(int *)puVar1 - *(int *)0x0605A21C;

    *(int *)puVar2 = *(int *)puVar1;

  }

  return iVar3;

}

void FUN_0600dd88(param_1)
    int param_1;
{

  char *puVar1;

  char *puVar2;

  int iVar3;

  int iVar4;

  int *piVar5;

  int iVar6;

  int iVar7;

  iVar6 = CAR_PTR_CURRENT;

  piVar5 = (int *)(*(int *)(iVar6 + DAT_0600de1e) +

                  *(int *)((param_1 + -1) << 2 + *(int *)(*(int *)0x06063F3C + 4)) * 0x18);

  iVar7 = *piVar5;

  iVar3 = iVar7 - *(int *)(iVar6 + 0x10);

  if (iVar3 < 0) {

    iVar3 = *(int *)(iVar6 + 0x10) - iVar7;

  }

  iVar4 = piVar5[1];

  iVar7 = iVar4 - *(int *)(iVar6 + 0x18);

  if (iVar7 < 0) {

    iVar7 = *(int *)(iVar6 + 0x18) - iVar4;

  }

  piVar5 = (int *)0x0607869C;

  iVar3 = (*(int(*)())0x06034FE0)(iVar3 + iVar7);

  *piVar5 = iVar3;

  puVar1 = (int *)0x060786B0;

  iVar3 = GAME_STATE_VAR * 5 - iVar3;

  *(int *)0x060786B0 = iVar3;

  puVar2 = (char *)0x0605A21C;

  *(int *)0x060786A0 = iVar3 - *(int *)0x0605A21C;

  *(int *)puVar2 = *(int *)puVar1;

  return;

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

void FUN_0600de70()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  char *puVar6;

  short uVar7;

  int uVar8;

  char *puVar9;

  unsigned short uVar10;

  puVar5 = (short *)0x0607ED88;

  puVar4 = (char *)0x0607EAE4;

  puVar3 = (char *)0x0607ED8C;

  puVar2 = (char *)0x0607E940;

  puVar1 = (int *)0x0607E944;

  uVar7 = (*(int(*)())0x06035340)();

  *(short *)0x060786CA = uVar7;

  puVar6 = (char *)0x06078900;

  uVar8 = *(int *)0x06063EF0;

  puVar9 = 0x06078900 + DAT_0600deb2;

  for (uVar10 = 0; uVar10 < (unsigned char)*(int *)0x06078634; uVar10 = uVar10 + 1) {

    if (*(int *)0x06078635 == '\0') {

      if (*(int *)puVar4 == 0) {

        *(int *)puVar4 = 1;

      }

    }

    else if (uVar10 == 0) {

      *(short *)puVar3 = 1;

      *(char **)puVar1 = puVar9;

      *(char **)puVar2 = puVar9;

    }

    else {

      *(short *)puVar3 = 0;

      *(int *)puVar5 = *(int *)puVar5 + -2;

      *(char **)puVar1 = puVar6;

      *(int *)0x06063EF0 = uVar8;

      *(int *)puVar2 = *(int *)puVar1;

    }

    FUN_0600e4f2();

  }

  (*(int(*)())0x0600A8BC)();

  if (*(int *)0x06083255 == '\0') {

    (*(int(*)())0x0602F7EA)();

  }

  else {

    (*(int(*)())0x06034900)();

  }

  (*(int(*)())0x0602F99C)();

  FUN_0600e0c0();

  return;

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
