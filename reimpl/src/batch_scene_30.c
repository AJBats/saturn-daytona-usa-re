#include "game.h"

extern int DAT_060303b6;
extern int DAT_06030402;
extern int DAT_0603045e;
extern int DAT_060304ac;
extern int DAT_060304ae;
extern int DAT_060304f0;
extern int DAT_060304f2;
extern int DAT_0603056a;
extern int DAT_06030588;
extern int DAT_060305ae;
extern int DAT_060305b0;
extern int DAT_06030602;
extern int DAT_06030604;
extern int DAT_0603063a;
extern int DAT_06030680;
extern int DAT_060306c8;
extern int DAT_06030714;
extern int DAT_06030716;
extern int DAT_06030742;
extern int DAT_06030a3e;
extern int DAT_06030a40;
extern int DAT_06030a42;
extern int DAT_06030a44;
extern int DAT_06030a46;
extern int DAT_06030b24;
extern int DAT_06030b26;
extern int DAT_06030b28;
extern int DAT_06030b2a;
extern int DAT_06030bc2;
extern int DAT_06030be0;
extern int DAT_06030be2;
extern int DAT_06030c00;
extern int DAT_06030c02;
extern int DAT_06030c20;
extern int DAT_06030c22;
extern int DAT_06030c40;
extern int DAT_06030c42;
extern int DAT_06030cca;
extern int DAT_06030d22;
extern int DAT_06030da2;
extern int DAT_06030eae;
extern int DAT_060310b8;
extern int DAT_0603112e;
extern int DAT_06031130;
extern int DAT_06031132;
extern int DAT_06031188;
extern int DAT_0603118a;
extern int DAT_060311b6;
extern int DAT_06031208;
extern int DAT_0603120a;
extern int DAT_0603129c;
extern int DAT_0603129e;
extern int DAT_0603135c;
extern int DAT_0603143a;
extern int DAT_06031496;
extern int DAT_06031516;
extern int DAT_0603156a;
extern int DAT_060315b0;
extern int DAT_060315be;
extern int DAT_060315ce;
extern int DAT_0603162a;
extern int DAT_0603162c;
extern int DAT_0603162e;
extern int DAT_06031750;
extern int DAT_0603178c;
extern int DAT_060317c6;
extern int DAT_060318e4;
extern int DAT_06031918;
extern int DAT_0603196c;
extern int DAT_06031a64;
extern int DAT_06031b22;
extern int DAT_06031bf8;
extern int DAT_06031c7c;
extern int DAT_06031c7e;
extern int DAT_06031d36;
extern int DAT_06031d38;
extern int DAT_06031d3a;
extern int DAT_06031e30;
extern int DAT_06031eee;
extern int DAT_06031fc4;
extern int DAT_06032048;
extern int DAT_0603204a;
extern void FUN_0603072e();
extern void FUN_06030a9c();
extern void FUN_06030b68();
extern void FUN_06030dfe();
extern void FUN_06031340();
extern int FUN_0603136e();
extern unsigned int FUN_06031d1a();
extern int FUN_060320e6();
extern int PTR_DAT_06030318;
extern int PTR_DAT_060303b8;
extern int PTR_DAT_06030404;
extern int PTR_DAT_060304b0;
extern int PTR_DAT_0603056c;
extern int PTR_DAT_06030598;
extern int PTR_DAT_06030b2c;
extern int PTR_DAT_06031234;
extern int PTR_DAT_060312a0;
extern int PTR_DAT_0603156c;
extern int PTR_DAT_06031adc;
extern int PTR_DAT_06031b64;
extern int PTR_DAT_06031ba8;
extern int PTR_DAT_06031c80;
extern int PTR_DAT_06031ea8;
extern int PTR_DAT_06031f30;
extern int PTR_DAT_06031f74;
extern int PTR_DAT_0603204c;

void FUN_060302c6()
{

  unsigned short uVar1;

  char *puVar2;

  int iVar3;

  unsigned int uVar4;

  short sVar6;

  int iVar5;

  int uVar7;

  int iVar8;

  int iVar9;

  unsigned char bVar10;

  puVar2 = (char *)0x0607ED88;

  iVar3 = CAR_PTR_TARGET;

  if (*(short *)0x0607ED8C != 0) {

    iVar8 = *(int *)0x0607ED88;

    bVar10 = ((int *)0x0607ED90)[iVar8];

    *(unsigned short *)(DAT_060304ac + iVar3) = bVar10 & 3;

    *(int *)puVar2 = iVar8 + 2;

    uVar7 = 1;

    if ((bVar10 & 0x80) == 0) {

      uVar7 = 0x38;

      iVar8 = *(int *)(DAT_060304f0 + iVar3) + -2;

      if (iVar8 < 0x38) {

        iVar8 = 0x38;

      }

      *(int *)(DAT_060304f0 + iVar3) = iVar8;

      *(int *)(0x0000006C + iVar3) = 0;

    }

    else {

      iVar8 = (int)DAT_060304ae;

      *(int *)(iVar8 + iVar3) = 1;

      iVar8 = iVar8 + 8;

      iVar5 = *(int *)(iVar8 + iVar3);

      if (iVar5 <= PTR_DAT_060304b0) {

        iVar5 = iVar5 + 4;

      }

      *(int *)(iVar8 + iVar3) = iVar5;

    }

    if ((bVar10 & 0x40) == 0) {

      iVar8 = *(int *)(0x00000090 + iVar3);

      *(int *)(0x0000008C + iVar3) = iVar8;

      iVar8 = iVar8 + -5;

      if (iVar8 < 0x38) {

        iVar8 = 0x38;

      }

      *(int *)(0x00000090 + iVar3) = iVar8;

      *(int *)(0x00000088 + iVar3) = 0;

    }

    else {

      *(int *)(0x00000088 + iVar3) = uVar7;

      iVar8 = 0x00000090;

      iVar5 = *(int *)(0x00000090 + iVar3);

      iVar9 = 0xb8;

      *(int *)(0x0000008C + iVar3) = iVar5;

      if (iVar5 <= iVar9) {

        iVar5 = iVar5 + 5;

      }

      *(int *)(iVar8 + iVar3) = iVar5;

    }

    return;

  }

  uVar4 = (unsigned int)*(unsigned short *)0x06063D9A;

  iVar8 = (int)PTR_DAT_06030318;

  if (*(short *)0x0608188A < 1) {

    if ((uVar4 & (int)*(short *)0x06081896) == 0) {

      if ((uVar4 & (int)*(short *)0x06081894) == 0) {

        if ((uVar4 & (int)*(short *)0x06081892) == 0) {

          if ((uVar4 & (int)*(short *)0x06081890) != 0) {

            *(short *)(iVar8 + iVar3) = 0;

          }

        }

        else {

          *(short *)(iVar8 + iVar3) = 1;

        }

      }

      else {

        *(short *)(iVar8 + iVar3) = 2;

      }

    }

    else {

      *(short *)(iVar8 + iVar3) = 3;

    }

  }

  else if ((uVar4 & (int)*(short *)0x0608188A) == 0) {

    if ((uVar4 & (int)*(short *)0x06081888) != 0) {

      sVar6 = *(short *)(iVar8 + iVar3);

      if (sVar6 != 3) {

        sVar6 = sVar6 + 1;

      }

      *(short *)(iVar8 + iVar3) = sVar6;

    }

  }

  else {

    sVar6 = *(short *)(iVar8 + iVar3);

    if (sVar6 != 0) {

      sVar6 = sVar6 + -1;

    }

    *(short *)(iVar8 + iVar3) = sVar6;

  }

  bVar10 = (unsigned char)*(short *)(iVar8 + iVar3);

  uVar1 = *(unsigned short *)0x06063D98;

  uVar7 = 1;

  if ((uVar1 & *(unsigned short *)0x0608188C) == 0) {

    uVar7 = 0x38;

    iVar8 = *(int *)(DAT_06030402 + iVar3) + -2;

    if (iVar8 < 0x39) {

      iVar8 = 0x38;

    }

    *(int *)(DAT_06030402 + iVar3) = iVar8;

    *(int *)(0x0000006C + iVar3) = 0;

  }

  else {

    bVar10 = bVar10 | 0x80;

    iVar8 = (int)DAT_060303b6;

    *(int *)(iVar8 + iVar3) = 1;

    iVar8 = iVar8 + 8;

    iVar5 = *(int *)(iVar8 + iVar3);

    if (iVar5 <= PTR_DAT_060303b8) {

      iVar5 = iVar5 + 4;

    }

    *(int *)(iVar8 + iVar3) = iVar5;

  }

  if ((uVar1 & *(unsigned short *)0x0608188E) == 0) {

    iVar8 = *(int *)(0x00000090 + iVar3);

    *(int *)(0x0000008C + iVar3) = iVar8;

    iVar8 = iVar8 + -5;

    if (iVar8 < 0x38) {

      iVar8 = 0x38;

    }

    *(int *)(0x00000090 + iVar3) = iVar8;

    *(int *)(0x00000088 + iVar3) = 0;

  }

  else {

    bVar10 = bVar10 | 0x40;

    *(int *)(0x00000088 + iVar3) = uVar7;

    iVar8 = 0x00000090;

    iVar5 = *(int *)(0x00000090 + iVar3);

    iVar9 = 0xb8;

    *(int *)(0x0000008C + iVar3) = iVar5;

    if (iVar5 <= iVar9) {

      iVar5 = iVar5 + 5;

    }

    *(int *)(iVar8 + iVar3) = iVar5;

  }

  puVar2 = (char *)0x0607ED88;

  iVar8 = *(int *)0x0607ED88;

  ((int *)0x0607ED90)[iVar8] = bVar10;

  iVar3 = iVar8 + 2;

  if ((int)DAT_0603045e <= iVar8 + 2) {

    iVar3 = iVar8;

  }

  *(int *)puVar2 = iVar3;

  return;

}

/* wheel_surface_contact_dispatch -- detect which wheels contact surface and apply heading correction */
void FUN_0603053c(param_1)
    short param_1;
{
  char *front_ref;
  unsigned int *wheel_flags;
  int heading_offset;
  unsigned int heading_delta;
  short ref_heading;
  int ref_position;
  unsigned int all_contact;
  char *surface_ref;
  unsigned char contact_mask;
  int wheel_index;
  int car_ptr;

  *(short *)0x06030FBE = param_1;
  car_ptr = CAR_PTR_CURRENT;
  wheel_flags = (unsigned int *)(DAT_0603056a + car_ptr); /* 4 wheel collision flags */
  heading_delta = wheel_flags[2];

  /* Check: any wheel has ground contact (0x80) AND not all grounded (0x01) */
  if (((0x80 & (*wheel_flags | wheel_flags[1] | heading_delta | wheel_flags[3])) != 0) &&
     (all_contact = wheel_flags[3] & heading_delta & wheel_flags[1] & *wheel_flags, (0x1 & all_contact) == 0)) {

    if ((0x80 & all_contact) != 0) {
      /* All 4 wheels on surface — use rear reference */
      FUN_06030a9c(0,heading_delta,*(int *)(0x06063EC4 + 0x10));
      return;
    }

    if (((int)DAT_060305ae & all_contact) == 0) {
      /* Build per-wheel contact bitmask: FL=1, FR=2, RL=4, RR=8 */
      heading_delta = (unsigned int)DAT_06030602; /* surface contact flag */
      contact_mask = (heading_delta & *wheel_flags) != 0;
      if ((heading_delta & wheel_flags[1]) != 0) {
        contact_mask = contact_mask + 2;
      }
      if ((heading_delta & wheel_flags[2]) != 0) {
        contact_mask = contact_mask + 4;
      }
      if ((heading_delta & wheel_flags[3]) != 0) {
        contact_mask = contact_mask + 8;
      }

      *(int *)(DAT_06030604 + car_ptr) = 8; /* set contact response mode */
      front_ref = (char *)0x06063E9C;  /* front surface reference */
      surface_ref = (char *)0x06063EC4; /* rear surface reference */

      if (contact_mask == 3) {
        /* Front pair (FL+FR) — heading from front reference with half-turn bias */
        heading_offset = (int)DAT_06030680;
        heading_delta = (*(int *)(car_ptr + 0x30) + 0x8000) - (*(int *)(0x06063E9C + 0x10) + heading_offset);
        ref_heading = (short)*(int *)(0x06063E9C + 0x10);
        if ((int)heading_delta < 0) {
          heading_delta = -heading_delta;
        }
        if ((heading_offset <= (int)(heading_delta & 0xffff)) && ((int)(heading_delta & 0xffff) <= heading_offset * 3)) {
          ref_heading = ref_heading + (DAT_06030680 << 1);
        }
        *(short *)0x06030FBC = ref_heading + DAT_06030680;
        FUN_06030b68(0,*(int *)(front_ref + 0x10));
        return;
      }

      if (contact_mask == 0xc) {
        /* Rear pair (RL+RR) — heading from rear reference */
        heading_offset = (int)DAT_0603063a;
        heading_delta = *(int *)(car_ptr + 0x30) - (*(int *)(0x06063EC4 + 0x10) + heading_offset);
        ref_heading = (short)*(int *)(0x06063EC4 + 0x10);
        if ((int)heading_delta < 0) {
          heading_delta = -heading_delta;
        }
        if ((heading_offset <= (int)(heading_delta & 0xffff)) && ((int)(heading_delta & 0xffff) <= heading_offset * 3)) {
          ref_heading = ref_heading + (DAT_0603063a << 1);
        }
        *(short *)0x06030FBC = ref_heading + DAT_0603063a;
        FUN_06030b68(2,*(int *)(surface_ref + 0x10));
        return;
      }

      if (((contact_mask & 5) != 5) && (((contact_mask & 5) == 0 || ((contact_mask & 10) != 0)))) {
        /* Lateral pair — left side (0x06063EB0) or right side (0x06063ED8) */
        wheel_index = 1;
        surface_ref = (char *)0x06063EB0; /* left surface reference */
        if ((contact_mask & 2) == 0) {
          wheel_index = 3;
          surface_ref = (char *)0x06063ED8; /* right surface reference */
        }
        heading_offset = (int)DAT_060306c8;
        ref_position = *(int *)(surface_ref + 0x10);
        heading_delta = *(int *)(car_ptr + 0x30) - ref_position;
        if ((int)heading_delta < 0) {
          heading_delta = -heading_delta;
        }
        if ((heading_offset <= (int)(heading_delta & 0xffff)) && ((int)(heading_delta & 0xffff) <= heading_offset * 3)) {
          ref_position = ref_position + (heading_offset << 1);
        }
        *(short *)0x06030FBC = (short)ref_position + DAT_060306c8;
        FUN_06030b68(wheel_index,*(int *)(surface_ref + 0x10));
        return;
      }

      /* Diagonal pair — front-left (0x06063E9C) or front-right (0x06063EC4) */
      wheel_index = 0;
      surface_ref = (char *)0x06063E9C;
      if ((contact_mask & 1) == 0) {
        wheel_index = 2;
        surface_ref = (char *)0x06063EC4;
      }
      heading_offset = (int)DAT_06030714;
      ref_position = *(int *)(surface_ref + 0x10);
      heading_delta = *(int *)(car_ptr + 0x30) - ref_position;
      if ((int)heading_delta < 0) {
        heading_delta = -heading_delta;
      }
      if ((heading_offset <= (int)(heading_delta & 0xffff)) && ((int)(heading_delta & 0xffff) <= heading_offset * 3)) {
        ref_position = ref_position + (heading_offset << 1);
      }
      *(short *)0x06030FBC = (short)ref_position + DAT_06030716;
      FUN_06030b68(wheel_index,*(int *)(surface_ref + 0x10));
      return;
    }

    /* All flags set — mark full contact */
    *(short *)(car_ptr + DAT_060305b0) = 0xf;
  }

  return;
}

void FUN_0603072e(param_1, param_2)
    int param_1;
    int param_2;
{

  int unaff_r14 = 0;

  if (param_2 == *(int *)(DAT_06030742 + unaff_r14)) {

    return;

  }

  *(int *)(DAT_06030742 + unaff_r14) = param_2;

  (*(int(*)())(*(int *)(0x06030F1C + (param_1 << 2))))();

  return;

}

/* collision_timer_decrement -- Decrement collision invulnerability timer.
 * Car +0x250 is the collision timer. When it reaches 0:
 * sets DAT_06030a40 to 0xFFFF0000 (max negative = full recovery),
 * and if bit 21 of car +0x160 (flags) is set, restores position
 * from checkpoint backup (DAT_06030a46 → DAT_06030a44, +0x30 → +0x28). */
int FUN_06030a06()
{
  int car = CAR_PTR_CURRENT;
  int timer;

  if ((*(short *)(car + 0x250) != 0) &&
     (timer = *(short *)(car + 0x250) + -1, *(short *)(car + 0x250) = (short)timer, timer == 0)) {
    *(int *)(DAT_06030a40 + car) = 0xFFFF0000; /* full recovery */
    if (((unsigned int)0x00200000 & *(unsigned int *)(car + 0x160)) != 0) {
      /* restore from checkpoint backup */
      *(int *)(car + (int)DAT_06030a44) = *(int *)(DAT_06030a46 + car);
      *(int *)(car + 0x28) = *(int *)(car + 0x30);
      return (int)DAT_06030a44;
    }
    return 0x160;
  }
  return 0x250;
}

void FUN_06030a9c(param_1, param_2, param_3, param_4)
    int param_1;
    int param_2;
    short param_3;
    int param_4;
{

  long long lVar1;

  int iVar2;

  unsigned int *puVar3;

  int iVar4;

  unsigned int uVar5;

  unsigned int uVar6;

  unsigned int uVar7;

  unsigned int *unaff_r14;

  uVar5 = unaff_r14[10];

  iVar4 = (int)(short)((short)uVar5 - param_3);

  if (iVar4 < 1) {

    iVar4 = iVar4 + (unsigned int)DAT_06030b24;

  }

  if ((int)(unsigned int)(DAT_06030b24 >> 1) < iVar4) {

    iVar4 = iVar4 + (unsigned int)(DAT_06030b24 >> 1) * -2;

  }

  iVar4 = iVar4 + (iVar4 >> 2);

  iVar2 = (int)DAT_06030b26;

  *(int *)((int)unaff_r14 + iVar2) = iVar4;

  *(unsigned int *)((int)unaff_r14 + iVar2 + -4) = uVar5 - iVar4;

  *(short *)((int)unaff_r14 + iVar2 + 4) = DAT_06030b28;

  *(int *)0x0607866D = 0xf;

  *(int *)0x06089595 = 1;

  *(unsigned int *)((int)unaff_r14 + (int)DAT_06030b2a) =

       *(unsigned int *)((int)unaff_r14 + (int)DAT_06030b2a) | (int)PTR_DAT_06030b2c;

  puVar3 = (unsigned int *)(0x060A6000 + *(short *)(param_4 + 0xe) * 0x34);

  uVar6 = puVar3[4];

  uVar7 = puVar3[5];

  uVar5 = (unsigned int)0x01000000 & *puVar3;

  if (*(short *)0x06030FBE == 0) {

    (*(int(*)())0x06008460)();

  }

  else {

    *unaff_r14 = *unaff_r14 | 0x08000000;

  }

  *(short *)0x06030FBC = 0xf;

  if (uVar6 == 0) {

    FUN_06030dfe();

    return;

  }

  if (uVar5 != 0) {

    (*(int(*)())0x0602755C)(-uVar7,uVar6);

    FUN_06030dfe();

    return;

  }

  lVar1 = (long long)(int)-uVar6 * (long long)(int)(unaff_r14[6] + uVar7);

  iVar4 = (int)((unsigned long long)lVar1 >> 0x20);

  uVar5 = (unsigned int)lVar1;

  if ((iVar4 < DAT_06030da2) && (-(int)DAT_06030da2 < iVar4)) {

    lVar1 = (long long)(int)-uVar6 * (long long)(int)-uVar6;

    (*(int(*)())0x0602755C)(unaff_r14[4] + (iVar4 << 0x10 | uVar5 >> 0x10),

               ((int)((unsigned long long)lVar1 >> 0x20) << 0x10 | (unsigned int)lVar1 >> 0x10) + 0x10000);

  }

  else {

    lVar1 = (long long)(int)-uVar6 * (long long)(int)-uVar6;

    (*(int(*)())0x0602755C)(((int)unaff_r14[4] >> 8) + (uVar5 >> 0x18 | iVar4 << 8),

               ((int)((unsigned long long)lVar1 >> 0x20) << 0x10 | (unsigned int)lVar1 >> 0x10) + 0x10000);

  }

  FUN_06030dfe();

  return;

}

void FUN_06030b68(param_1, param_2, param_3, param_4)
    int param_1;
    short param_2;
    int param_3;
    int param_4;
{

  int bVar1;

  long long lVar2;

  int bVar3;

  unsigned int *puVar4;

  short sVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  unsigned int uVar9;

  int iVar10;

  unsigned int uVar11;

  unsigned int uVar12;

  unsigned int *unaff_r14;

  iVar8 = (int)(short)(param_2 - (short)unaff_r14[10]);

  if (((int)0x00001000 < iVar8) && (iVar8 < (int)0x00006FFF)) {

    FUN_0603072e();

    return;

  }

  if ((iVar8 < -(int)0x00001000) && (-(int)0x00006FFF < iVar8)) {

    FUN_0603072e();

    return;

  }

  *(int *)0x06089595 = 1;

  *(short *)(0x150 + (int)unaff_r14) = 4;

  if (param_1 == 0) {

    *unaff_r14 = *unaff_r14 | 0x40;

    *(int *)((int)unaff_r14 + 0x260) = 0;

    sVar5 = *(short *)(0x06063E9C + 0xe);

    iVar8 = *(int *)(0x06063E9C + 0x10);

LAB_06030c48:

    if (*(int *)0x0602FD9B == '\0') {

      *(int *)0x0602FD9B = 5;

    }

    iVar7 = unaff_r14[10] - iVar8;

    if (iVar7 < 0) {

      iVar7 = -iVar7;

    }

    iVar10 = (int)DAT_06030cca;

    iVar6 = iVar8;

    if ((iVar10 <= iVar7) && (iVar7 <= iVar10 * 3)) {

      iVar6 = iVar8 + (iVar10 << 1);

    }

    unaff_r14[0xc] = (int)(short)iVar6;

    unaff_r14[10] = (int)(short)iVar6;

    puVar4 = (unsigned int *)(0x060A6000 + sVar5 * 0x34);

    uVar11 = puVar4[4];

    uVar12 = puVar4[5];

  }

  else {

    if (param_1 == 1) {

      *unaff_r14 = *unaff_r14 | 0x80;

      *(int *)((int)unaff_r14 + 0x260) = 2;

      sVar5 = *(short *)(0x06063EB0 + 0xe);

      iVar8 = *(int *)(0x06063EB0 + 0x10);

    }

    else {

      if (param_1 == 2) {

        *unaff_r14 = *unaff_r14 | 0x100;

        *(int *)((int)unaff_r14 + 0x260) = 1;

        sVar5 = *(short *)(0x06063EC4 + 0xe);

        iVar8 = *(int *)(0x06063EC4 + 0x10);

        goto LAB_06030c48;

      }

      *unaff_r14 = *unaff_r14 | 0x200;

      *(int *)((int)unaff_r14 + 0x260) = 3;

      sVar5 = *(short *)(0x06063ED8 + 0xe);

      iVar8 = *(int *)(0x06063ED8 + 0x10);

    }

    if (*(int *)0x0602FD9C == '\0') {

      *(int *)0x0602FD9C = 5;

    }

    iVar7 = unaff_r14[10] - iVar8;

    if (iVar7 < 0) {

      iVar7 = -iVar7;

    }

    iVar10 = (int)DAT_06030d22;

    iVar6 = iVar8;

    if ((iVar10 <= iVar7) && (iVar7 <= iVar10 * 3)) {

      iVar6 = iVar8 + (iVar10 << 1);

    }

    unaff_r14[0xc] = (int)(short)iVar6;

    unaff_r14[10] = (int)(short)iVar6;

    puVar4 = (unsigned int *)(0x060A6000 + sVar5 * 0x34);

    uVar11 = puVar4[4];

    uVar12 = puVar4[5];

  }

  bVar3 = (*puVar4 & 0x1000000) == 0;

  iVar7 = ((int)((unsigned long long)((long long)(int)unaff_r14[4] * (long long)(int)uVar11) >> 0x20) << 0x10 |

          (unsigned int)((long long)(int)unaff_r14[4] * (long long)(int)uVar11) >> 0x10) + uVar12;

  if (bVar3) {

    iVar7 = iVar7 + unaff_r14[6];

  }

  uVar9 = (unsigned int)(iVar7 < 1);

  bVar1 = uVar9 != (*puVar4 >> 8 & 1);

  if (uVar11 == 0) {

    iVar8 = unaff_r14[6] + uVar12;

    if (iVar8 < 1) {

      iVar8 = -iVar8;

    }

    FUN_06030dfe(bVar1,iVar8);

    return;

  }

  if (!bVar3) {

    (*(int(*)())0x0602755C)(-uVar12,uVar11);

    FUN_06030dfe();

    return;

  }

  lVar2 = (long long)(int)-uVar11 * (long long)(int)(unaff_r14[6] + uVar12);

  iVar7 = (int)((unsigned long long)lVar2 >> 0x20);

  uVar12 = (unsigned int)lVar2;

  if ((iVar7 < DAT_06030da2) && (-(int)DAT_06030da2 < iVar7)) {

    lVar2 = (long long)(int)-uVar11 * (long long)(int)-uVar11;

    (*(int(*)())0x0602755C)(unaff_r14[4] + (iVar7 << 0x10 | uVar12 >> 0x10),

               ((int)((unsigned long long)lVar2 >> 0x20) << 0x10 | (unsigned int)lVar2 >> 0x10) + 0x10000,uVar9,

               param_4,bVar1,0,iVar8);

  }

  else {

    lVar2 = (long long)(int)-uVar11 * (long long)(int)-uVar11;

    (*(int(*)())0x0602755C)(((int)unaff_r14[4] >> 8) + (uVar12 >> 0x18 | iVar7 << 8),

               ((int)((unsigned long long)lVar2 >> 0x20) << 0x10 | (unsigned int)lVar2 >> 0x10) + 0x10000);

  }

  FUN_06030dfe();

  return;

}

void FUN_06030dfe(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7)
{

  short sVar1;

  long long lVar2;

  int iVar3;

  int iVar4;

  char *puVar5;

  int extraout_r3 = 0;

  int extraout_r3_00;

  char *puVar6;

  int iVar7;

  int iVar8;

  int unaff_r14 = 0;

  puVar6 = (char *)0x00038000;

  sVar1 = *(short *)0x06030FBC;

  puVar5 = (char *)0x00013333;

  if (param_6 != 0) {

    iVar3 = (*(int(*)())0x06027348)(*(int *)(unaff_r14 + 0x30) - param_7);

    if (iVar3 < 0) {

      iVar3 = -iVar3;

    }

    puVar5 = (char *)

             ((int)((unsigned long long)((long long)(int)puVar6 * (long long)iVar3) >> 0x20) << 0x10 |

             (unsigned int)((long long)(int)puVar6 * (long long)iVar3) >> 0x10);

    param_5 = extraout_r3;

  }

  if (param_5 < 1) {

    puVar5 = puVar5 + param_2;

  }

  else {

    puVar5 = puVar5 + -param_2;

    if ((int)puVar5 < 1) {

      return;

    }

  }

  iVar7 = *(int *)(unaff_r14 + 0x10);

  iVar8 = *(int *)(unaff_r14 + 0x18);

  *(int *)(unaff_r14 + 0x38) = iVar7;

  *(int *)(unaff_r14 + 0x3c) = iVar8;

  iVar3 = (*(int(*)())0x06027344)();

  iVar4 = (*(int(*)())0x06027348)(-(int)sVar1);

  *(unsigned int *)(unaff_r14 + 0x10) =

       iVar7 + ((int)((unsigned long long)((long long)extraout_r3_00 * (long long)iVar4) >> 0x20) << 0x10 |

               (unsigned int)((long long)extraout_r3_00 * (long long)iVar4) >> 0x10);

  *(unsigned int *)(unaff_r14 + 0x18) =

       iVar8 + ((int)((unsigned long long)((long long)(int)puVar5 * (long long)iVar3) >> 0x20) << 0x10 |

               (unsigned int)((long long)(int)puVar5 * (long long)iVar3) >> 0x10);

  puVar6 = (char *)0x0000C000;

  if ((*(short *)(DAT_06030eae + unaff_r14) < 8) &&

     (puVar6 = (char *)0x0000DEB8, 5 < *(short *)(DAT_06030eae + unaff_r14))) {

    puVar6 = (char *)0x0000FAE1;

  }

  lVar2 = (long long)(int)puVar6 * (long long)*(int *)(unaff_r14 + 0xc);

  *(unsigned int *)(unaff_r14 + 0xc) = (int)((unsigned long long)lVar2 >> 0x20) << 0x10 | (unsigned int)lVar2 >> 0x10;

  return;

}

int FUN_06030fc0(param_1, param_2, param_3)
    unsigned int *param_1;
    unsigned int *param_2;
    char *param_3;
{

  int bVar1;

  long long lVar2;

  int in_r0 = 0;

  int iVar3;

  short sVar5;

  int iVar4;

  unsigned int uVar6;

  int extraout_r1 = 0;

  int iVar7;

  int extraout_r2 = 0;

  char *extraout_r2_00;

  int extraout_r3 = 0;

  int extraout_r3_00;

  unsigned int uVar8;

  char *pcVar9;

  int iVar10;

  unsigned int uVar11;

  char *puVar12;

  int in_pr;

  long long uVar13;

  if ((int)param_2[3] < (int)param_1[3]) {

    sVar5 = (*(int(*)())0x0602744C)(param_2[4] - param_1[4],param_2[6] - param_1[6]);

    iVar3 = (int)-sVar5;

    sVar5 = (*(int(*)())0x0602744C)(param_2[0xe] - param_1[0xe],param_2[0xf] - param_1[0xf],param_1[0xe],

                       param_1[0xf],in_pr,in_r0);

    uVar8 = (unsigned int)DAT_060310b8;

    uVar6 = param_1[0xc] - ((unsigned int)(unsigned short)-sVar5 | uVar8 << 1);

    if ((int)uVar6 < 1) {

      uVar6 = -uVar6;

    }

    uVar6 = (unsigned int)((uVar6 & 0xffff) < uVar8);

    FUN_06031340();

    iVar7 = extraout_r1;

    if (extraout_r1 >= (int)uVar8) {

      iVar7 = extraout_r1 - uVar8;

    }

    uVar11 = (unsigned int)(extraout_r1 < (int)uVar8);

    bVar1 = uVar11 != uVar6;

    uVar13 = (*(int(*)())0x06027348)(iVar7);

    iVar7 = (int)uVar13;

    uVar6 = extraout_r2 - iVar3 & 0xffff;

    if ((int)uVar8 <= (int)uVar6) {

      uVar6 = uVar6 - uVar8;

    }

    uVar8 = (unsigned int)((unsigned long long)uVar13 >> 0x29);

    iVar10 = 0;

    if ((10 < uVar8) && (uVar8 < 0x37)) {

      iVar10 = 1;

    }

    if (((bVar1) && (uVar11 = (unsigned int)(uVar11 == 0), iVar10 != 0)) ||

       (param_3 = (char *)

                  ((*(int *)(0x0605BCC8 + (uVar8 << 2)) - (int)param_3) +

                  *(int *)(0x0605BCC8 + (uVar6 >> 9) << 2)), 0 < (int)param_3)) {

      uVar6 = param_1[10] - param_2[10] & 0xffff;

      if (((int)DAT_0603112e < (int)uVar6) && ((int)uVar6 < DAT_0603112e * 3)) {

        if ((int)0x00042AAA < (int)(param_1[3] + param_2[3])) {

          *param_2 = *param_2 | 0x08000000;

          (*(int(*)())0x06008460)();

          *(int *)((int)param_1 + (int)DAT_06031130) = (int)DAT_06031132;

        }

      }

      else {

        puVar12 = (int *)0x00042AAA;

        if ((int)0x00042AAA < (int)(param_1[3] - param_2[3])) {

          *param_2 = *param_2 | 0x08000000;

          (*(int(*)())0x06008460)();

          *(int *)((int)param_1 + (int)DAT_06031188) = (int)DAT_0603118a;

          puVar12 = extraout_r2_00;

        }

        if ((iVar10 == 0) && ((int)((unsigned int)puVar12 >> 1) <= (int)(param_1[3] - param_2[3]))) {

          puVar12 = (int *)0x20000000;

          if (uVar11 != 0) {

            puVar12 = (char *)((unsigned int)0x20000000 >> 1);

          }

          *param_1 = *param_1 | (unsigned int)puVar12;

        }

        else {

          uVar6 = param_1[10] - iVar3 & 0xffff;

          if (((int)uVar6 <= (int)DAT_060311b6) || (DAT_060311b6 * 3 <= (int)uVar6)) {

            if (iVar10 != 0) {

              param_2[0xc] = param_1[0xc];

              *(int *)(0x208 + (int)param_2) = 8;

            }

            iVar4 = (*(int(*)())0x06027344)(uVar6);

            lVar2 = (long long)(int)(param_1[3] - param_2[3] >> 2) * (long long)iVar4;

            iVar4 = (int)((int)((unsigned long long)lVar2 >> 0x20) << 0x10 | (unsigned int)lVar2 >> 0x10) >> 1;

            *(unsigned int *)((int)DAT_0603120a + (int)param_2) = param_2[3] + iVar4;

            param_1[3] = param_1[3] - iVar4;

          }

        }

      }

      if (iVar10 == 0) {

        if (*(int *)0x0602FD9A == '\0') {

          *(int *)0x0602FD9A = 3;

        }

      }

      else {

        if (uVar11 == 0) {

          uVar6 = 0x80;

          pcVar9 = 0x0602FD98 + 1;

          if (*(short *)0x06031A24 != 0) {

            uVar6 = (unsigned int)PTR_DAT_06031234;

          }

        }

        else {

          uVar6 = 0x40;

          pcVar9 = (char *)0x0602FD98;

          if (*(short *)0x06031A24 != 0) {

            uVar6 = (unsigned int)DAT_0603129c;

          }

        }

        *param_1 = *param_1 | uVar6;

        if (*pcVar9 == '\0') {

          *pcVar9 = '\x03';

        }

        iVar3 = (int)DAT_0603129e;

        if (uVar11 == 0) {

          iVar3 = iVar3 * 3;

        }

        iVar3 = (param_1[0xc] & 0xffff) + iVar3;

        param_3 = (char *)

                  ((int)((unsigned long long)((long long)(int)param_3 * (long long)iVar7) >> 0x20) << 0x10 |

                  (unsigned int)((long long)(int)param_3 * (long long)iVar7) >> 0x10);

        if (bVar1) {

          param_3 = param_3 + (int)0x0000D999;

        }

      }

      if (*(short *)((int)PTR_DAT_060312a0 + (int)param_1) < 8) {

        if (*(short *)((int)PTR_DAT_060312a0 + (int)param_1) < 6) {

          puVar12 = (char *)((unsigned int)param_3 >> 2) + ((unsigned int)param_3 >> 1);

          param_3 = (char *)((unsigned int)param_3 >> 2);

        }

        else {

          puVar12 = param_3;

          param_3 = (char *)0x0;

        }

      }

      else {

        puVar12 = (char *)0x0;

      }

      uVar6 = param_2[4];

      uVar8 = param_2[6];

      param_2[0xe] = uVar6;

      param_2[0xf] = uVar8;

      iVar7 = (*(int(*)())0x06027344)(-iVar3);

      iVar10 = (*(int(*)())0x06027348)(-iVar3);

      param_2[4] = uVar6 + ((int)((unsigned long long)((long long)extraout_r3 * (long long)iVar10) >> 0x20) <<

                            0x10 | (unsigned int)((long long)extraout_r3 * (long long)iVar10) >> 0x10);

      param_2[6] = uVar8 + ((int)((unsigned long long)((long long)(int)puVar12 * (long long)iVar7) >> 0x20) <<

                            0x10 | (unsigned int)((long long)(int)puVar12 * (long long)iVar7) >> 0x10);

      puVar12 = 0x00008000 + iVar3;

      uVar6 = param_1[4];

      uVar8 = param_1[6];

      param_1[0xe] = uVar6;

      param_1[0xf] = uVar8;

      iVar3 = (*(int(*)())0x06027344)(-(int)puVar12);

      iVar7 = (*(int(*)())0x06027348)(-(int)puVar12);

      param_1[4] = uVar6 + ((int)((unsigned long long)((long long)extraout_r3_00 * (long long)iVar7) >> 0x20)

                            << 0x10 | (unsigned int)((long long)extraout_r3_00 * (long long)iVar7) >> 0x10);

      param_1[6] = uVar8 + ((int)((unsigned long long)((long long)(int)param_3 * (long long)iVar3) >> 0x20) <<

                            0x10 | (unsigned int)((long long)(int)param_3 * (long long)iVar3) >> 0x10);

    }

    return iVar7;

  }

  iVar3 = FUN_0603136e(param_1,param_2,param_2[4],param_2[6]);

  return iVar3;

}

void FUN_06031340()
{

  int in_r1 = 0;

  unsigned int uVar1;

  short *puVar2;

  uVar1 = (unsigned int)DAT_0603135c;

  puVar2 = (short *)((uVar1 << 1));

  if (((uVar1 & 0x80000000) == 0) &&

     (puVar2 = (short *)0x06031A24, in_r1 < (int)(uVar1 * 3))) {

    *(short *)0x06031A24 = 1;

  }

  else {

    *puVar2 = 0;

  }

  return;

}

int FUN_0603136e(param_1, param_2, param_3, param_4)
    int param_1;
    int param_2;
    int param_3;
    int param_4;
{

  char cVar1;

  int bVar2;

  long long lVar3;

  int in_r0 = 0;

  short sVar5;

  int iVar4;

  unsigned int uVar6;

  int extraout_r1 = 0;

  int iVar7;

  int extraout_r2 = 0;

  int extraout_r3 = 0;

  int extraout_r3_00;

  unsigned int uVar8;

  char *pcVar9;

  int iVar10;

  int unaff_r8 = 0;

  unsigned int uVar11;

  int unaff_r9 = 0;

  int iVar12;

  char *puVar13;

  char *unaff_r12;

  unsigned int *unaff_r13;

  unsigned int *unaff_r14;

  int in_pr;

  long long uVar14;

  int iVar15;

  char *puVar16;

  sVar5 = (*(int(*)())0x0602744C)(unaff_r8 - param_3,unaff_r9 - param_4);

  iVar12 = (int)-sVar5;

  sVar5 = (*(int(*)())0x0602744C)(unaff_r14[0xe] - unaff_r13[0xe],unaff_r14[0xf] - unaff_r13[0xf],unaff_r13[0xe],

                     unaff_r13[0xf],in_pr,in_r0);

  uVar8 = (unsigned int)DAT_0603143a;

  uVar6 = (int)(short)unaff_r13[0xc] - ((unsigned int)(unsigned short)-sVar5 | uVar8 << 1);

  if ((int)uVar6 < 1) {

    uVar6 = -uVar6;

  }

  uVar6 = (unsigned int)((uVar6 & 0xffff) < uVar8);

  FUN_06031340();

  iVar7 = extraout_r1;

  if (extraout_r1 >= (int)uVar8) {

    iVar7 = extraout_r1 - uVar8;

  }

  uVar11 = (unsigned int)(extraout_r1 < (int)uVar8);

  bVar2 = uVar11 != uVar6;

  uVar14 = (*(int(*)())0x06027348)(iVar7);

  iVar7 = (int)uVar14;

  uVar6 = extraout_r2 - iVar12 & 0xffff;

  if ((int)uVar8 <= (int)uVar6) {

    uVar6 = uVar6 - uVar8;

  }

  uVar8 = (unsigned int)((unsigned long long)uVar14 >> 0x29);

  iVar10 = 0;

  if ((10 < uVar8) && (uVar8 < 0x37)) {

    iVar10 = 1;

  }

  if (((bVar2) && (uVar11 = (unsigned int)(uVar11 == 0), iVar10 != 0)) ||

     (unaff_r12 = (char *)

                  ((*(int *)(0x0605BCC8 + (uVar8 << 2)) - (int)unaff_r12) +

                  *(int *)(0x0605BCC8 + (uVar6 >> 9) << 2)), 0 < (int)unaff_r12)) {

    uVar6 = unaff_r14[10] - unaff_r13[10] & 0xffff;

    if (((int)DAT_06031496 < (int)uVar6) && ((int)uVar6 < DAT_06031496 * 3)) {

      iVar15 = 1;

      if ((int)0x00042AAA < (int)(unaff_r14[3] + unaff_r13[3])) {

        *unaff_r13 = *unaff_r13 | 0x08000000;

      }

    }

    else {

      iVar15 = 0;

      if ((int)0x00042AAA < (int)(unaff_r13[3] - unaff_r14[3])) {

        *unaff_r13 = *unaff_r13 | 0x08000000;

      }

      else if ((iVar10 == 0) &&

              ((int)((unsigned int)0x00042AAA >> 1) <= (int)(unaff_r13[3] - unaff_r14[3]))) {

        puVar13 = (char *)0x20000000;

        if (uVar11 != 0) {

          puVar13 = (char *)((unsigned int)0x20000000 >> 1);

        }

        *unaff_r13 = *unaff_r13 | (unsigned int)puVar13;

      }

      else {

        uVar6 = unaff_r13[10] - iVar12 & 0xffff;

        if (((int)uVar6 <= (int)DAT_06031516) || (DAT_06031516 * 3 <= (int)uVar6)) {

          if (iVar10 != 0) {

            unaff_r14[0xc] = unaff_r13[8];

            *(int *)(0x208 + (int)unaff_r13) = 8;

          }

          iVar4 = (*(int(*)())0x06027344)(uVar6);

          lVar3 = (long long)(int)(unaff_r13[3] - unaff_r14[3]) * (long long)iVar4;

          iVar4 = (int)((int)((unsigned long long)lVar3 >> 0x20) << 0x10 | (unsigned int)lVar3 >> 0x10) >> 1;

          unaff_r14[3] = unaff_r14[3] + iVar4;

          *(unsigned int *)((int)PTR_DAT_0603156c + (int)unaff_r13) = unaff_r13[3] - iVar4;

        }

      }

    }

    if (iVar10 == 0) {

      if (*(int *)0x0602FD9A == '\0') {

        *(int *)0x0602FD9A = 3;

      }

    }

    else {

      sVar5 = *(short *)0x06031A24;

      pcVar9 = (char *)0x0602FD98;

      if (iVar15 == 0) {

        if (uVar11 == 0) {

          uVar6 = (unsigned int)DAT_0603162a;

          if (sVar5 != 0) {

            uVar6 = 0x40;

          }

        }

        else {

          uVar6 = (unsigned int)DAT_060315ce;

          pcVar9 = 0x0602FD98 + 1;

          if (sVar5 != 0) {

            uVar6 = 0x80;

          }

        }

      }

      else if (uVar11 == 0) {

        uVar6 = 0x80;

        pcVar9 = 0x0602FD98 + 1;

        if (sVar5 != 0) {

          uVar6 = (unsigned int)DAT_060315b0;

        }

      }

      else {

        uVar6 = 0x40;

        if (sVar5 != 0) {

          uVar6 = (unsigned int)DAT_060315be;

        }

      }

      cVar1 = *pcVar9;

      *unaff_r14 = *unaff_r14 | uVar6;

      if (cVar1 == '\0') {

        *pcVar9 = '\x03';

      }

      iVar12 = (int)DAT_0603162c;

      if (uVar11 == 0) {

        iVar12 = iVar12 * 3;

      }

      iVar12 = (unaff_r13[0xc] & 0xffff) + iVar12;

      unaff_r12 = (char *)

                  ((int)((unsigned long long)((long long)(int)unaff_r12 * (long long)iVar7) >> 0x20) << 0x10 |

                  (unsigned int)((long long)(int)unaff_r12 * (long long)iVar7) >> 0x10);

      if (bVar2) {

        unaff_r12 = unaff_r12 + (int)0x0000D999;

      }

    }

    if (*(short *)((int)DAT_0603162e + (int)unaff_r14) < 8) {

      if (*(short *)((int)DAT_0603162e + (int)unaff_r14) < 6) {

        puVar13 = (char *)((unsigned int)unaff_r12 >> 2);

        puVar16 = (char *)((unsigned int)unaff_r12 >> 2) + ((unsigned int)unaff_r12 >> 1);

      }

      else {

        puVar13 = (char *)0x0;

        puVar16 = unaff_r12;

      }

    }

    else {

      puVar16 = (char *)0x0;

      puVar13 = unaff_r12;

    }

    uVar6 = unaff_r14[4];

    uVar8 = unaff_r14[6];

    unaff_r14[0xe] = uVar6;

    unaff_r14[0xf] = uVar8;

    iVar7 = (*(int(*)())0x06027344)(-iVar12);

    iVar10 = (*(int(*)())0x06027348)(-iVar12);

    unaff_r14[4] = uVar6 + ((int)((unsigned long long)((long long)extraout_r3 * (long long)iVar10) >> 0x20) <<

                            0x10 | (unsigned int)((long long)extraout_r3 * (long long)iVar10) >> 0x10);

    unaff_r14[6] = uVar8 + ((int)((unsigned long long)((long long)(int)puVar13 * (long long)iVar7) >> 0x20) <<

                            0x10 | (unsigned int)((long long)(int)puVar13 * (long long)iVar7) >> 0x10);

    puVar13 = 0x00008000 + iVar12;

    uVar6 = unaff_r13[4];

    uVar8 = unaff_r13[6];

    unaff_r13[0xe] = uVar6;

    unaff_r13[0xf] = uVar8;

    iVar12 = (*(int(*)())0x06027344)(-(int)puVar13);

    iVar7 = (*(int(*)())0x06027348)(-(int)puVar13);

    unaff_r13[4] = uVar6 + ((int)((unsigned long long)((long long)extraout_r3_00 * (long long)iVar7) >> 0x20)

                            << 0x10 | (unsigned int)((long long)extraout_r3_00 * (long long)iVar7) >> 0x10);

    unaff_r13[6] = uVar8 + ((int)((unsigned long long)

                                  ((long long)(int)(puVar16 + ((unsigned int)puVar16 >> 1)) *

                                  (long long)iVar12) >> 0x20) << 0x10 |

                           (unsigned int)((long long)(int)(puVar16 + ((unsigned int)puVar16 >> 1)) * (long long)iVar12

                                 ) >> 0x10);

  }

  return iVar7;

}

int FUN_060316c4(param_1, param_2, param_3)
    unsigned int *param_1;
    unsigned int *param_2;
    int param_3;
{

  long long lVar1;

  int in_r0 = 0;

  short sVar4;

  int iVar2;

  int iVar3;

  unsigned int uVar5;

  unsigned int uVar6;

  int extraout_r3 = 0;

  int extraout_r3_00;

  int extraout_r3_01;

  int extraout_r3_02;

  unsigned int uVar7;

  int iVar8;

  char *puVar9;

  if ((int)param_2[3] < (int)param_1[3]) {

    sVar4 = (*(int(*)())0x0602744C)(param_2[4] - param_1[4],param_2[6] - param_1[6]);

    iVar8 = (int)-sVar4;

    uVar5 = param_1[8] - iVar8 & 0xffff;

    if (DAT_06031750 <= uVar5) {

      uVar5 = uVar5 - DAT_06031750;

    }

    uVar7 = param_2[8] - iVar8 & 0xffff;

    if (DAT_06031750 <= uVar7) {

      uVar7 = uVar7 - DAT_06031750;

    }

    uVar5 = (*(int *)(0x0605BCC8 + (uVar5 >> 9) << 2) - param_3) +

            *(int *)(0x0605BCC8 + (uVar7 >> 9) << 2);

    if (0 < (int)uVar5) {

      uVar7 = param_1[10] - param_2[10] & 0xffff;

      if (((int)DAT_0603178c < (int)uVar7) && ((int)uVar7 < DAT_0603178c * 3)) {

        if ((int)0x0001638E < (int)(param_1[3] + param_2[3])) {

          *param_2 = *param_2 | 0x08000000;

        }

      }

      else {

        if ((int)0x0001638E < (int)(param_1[3] - param_2[3])) {

          *param_2 = *param_2 | 0x08000000;

        }

        uVar7 = param_1[10] - iVar8 & 0xffff;

        if (((int)uVar7 <= (int)DAT_060317c6) || (DAT_060317c6 * 3 <= (int)uVar7)) {

          param_2[8] = param_1[8];

          iVar2 = (*(int(*)())0x06027344)(uVar7);

          lVar1 = (long long)(int)(param_1[3] - param_2[3]) * (long long)iVar2;

          uVar7 = (int)((unsigned long long)lVar1 >> 0x20) << 0x10 | (unsigned int)lVar1 >> 0x10;

          param_2[3] = param_2[3] + uVar7;

          param_1[3] = param_1[3] - uVar7;

        }

      }

      uVar5 = uVar5 >> 1;

      uVar7 = param_2[4];

      uVar6 = param_2[6];

      param_2[0xe] = uVar7;

      param_2[0xf] = uVar6;

      iVar2 = (*(int(*)())0x06027344)(-iVar8);

      iVar3 = (*(int(*)())0x06027348)(-iVar8);

      param_2[4] = uVar7 + ((int)((unsigned long long)((long long)extraout_r3 * (long long)iVar3) >> 0x20) <<

                            0x10 | (unsigned int)((long long)extraout_r3 * (long long)iVar3) >> 0x10);

      lVar1 = (long long)(int)uVar5 * (long long)iVar2;

      param_2[6] = uVar6 + ((int)((unsigned long long)lVar1 >> 0x20) << 0x10 | (unsigned int)lVar1 >> 0x10);

      puVar9 = 0x00008000 + iVar8;

      uVar7 = param_1[4];

      uVar6 = param_1[6];

      param_1[0xe] = uVar7;

      param_1[0xf] = uVar6;

      iVar8 = (*(int(*)())0x06027344)(-(int)puVar9);

      in_r0 = (*(int(*)())0x06027348)(-(int)puVar9);

      param_1[4] = uVar7 + ((int)((unsigned long long)((long long)extraout_r3_00 * (long long)in_r0) >> 0x20)

                            << 0x10 | (unsigned int)((long long)extraout_r3_00 * (long long)in_r0) >> 0x10);

      lVar1 = (long long)(int)uVar5 * (long long)iVar8;

      param_1[6] = uVar6 + ((int)((unsigned long long)lVar1 >> 0x20) << 0x10 | (unsigned int)lVar1 >> 0x10);

    }

  }

  else {

    sVar4 = (*(int(*)())0x0602744C)(param_1[4] - param_2[4],param_1[6] - param_2[6]);

    iVar8 = (int)-sVar4;

    uVar7 = (unsigned int)DAT_060318e4;

    uVar5 = param_1[8] - iVar8 & 0xffff;

    if (uVar7 <= uVar5) {

      uVar5 = uVar5 - uVar7;

    }

    uVar6 = param_2[8] - iVar8 & 0xffff;

    if (uVar7 <= uVar6) {

      uVar6 = uVar6 - uVar7;

    }

    uVar5 = (*(int *)(0x0605BCC8 + (uVar5 >> 9) << 2) - param_3) +

            *(int *)(0x0605BCC8 + (uVar6 >> 9) << 2);

    if (0 < (int)uVar5) {

      uVar7 = param_1[10] - param_2[10] & 0xffff;

      if (((int)DAT_06031918 < (int)uVar7) && ((int)uVar7 < DAT_06031918 * 3)) {

        if ((int)0x0001638E < (int)(param_1[3] + param_2[3])) {

          uVar7 = *param_1 | 0x08000000;

          *param_2 = *param_2 | 0x08000000;

          *param_1 = uVar7;

        }

      }

      else {

        if ((int)0x0001638E < (int)(param_2[3] - param_1[3])) {

          uVar7 = *param_1 | 0x08000000;

          *param_2 = *param_2 | 0x08000000;

          *param_1 = uVar7;

        }

        uVar7 = param_2[10] - iVar8 & 0xffff;

        if (((int)uVar7 <= (int)DAT_0603196c) || (DAT_0603196c * 3 <= (int)uVar7)) {

          uVar6 = param_2[8];

          param_1[8] = uVar6;

          param_1[10] = uVar6;

          iVar2 = (*(int(*)())0x06027344)(uVar7);

          lVar1 = (long long)(int)(param_2[3] - param_1[3]) * (long long)iVar2;

          uVar7 = (int)((unsigned long long)lVar1 >> 0x20) << 0x10 | (unsigned int)lVar1 >> 0x10;

          param_1[3] = param_1[3] + uVar7;

          param_2[3] = param_2[3] - uVar7;

        }

      }

      uVar5 = uVar5 >> 1;

      uVar7 = param_1[4];

      uVar6 = param_1[6];

      param_1[0xe] = uVar7;

      param_1[0xf] = uVar6;

      iVar2 = (*(int(*)())0x06027344)(-iVar8);

      iVar3 = (*(int(*)())0x06027348)(-iVar8);

      param_1[4] = uVar7 + ((int)((unsigned long long)((long long)extraout_r3_01 * (long long)iVar3) >> 0x20)

                            << 0x10 | (unsigned int)((long long)extraout_r3_01 * (long long)iVar3) >> 0x10);

      lVar1 = (long long)(int)uVar5 * (long long)iVar2;

      param_1[6] = uVar6 + ((int)((unsigned long long)lVar1 >> 0x20) << 0x10 | (unsigned int)lVar1 >> 0x10);

      puVar9 = 0x00008000 + iVar8;

      uVar7 = param_2[4];

      uVar6 = param_2[6];

      param_2[0xe] = uVar7;

      param_2[0xf] = uVar6;

      iVar8 = (*(int(*)())0x06027344)(-(int)puVar9);

      in_r0 = (*(int(*)())0x06027348)(-(int)puVar9);

      param_2[4] = uVar7 + ((int)((unsigned long long)((long long)extraout_r3_02 * (long long)in_r0) >> 0x20)

                            << 0x10 | (unsigned int)((long long)extraout_r3_02 * (long long)in_r0) >> 0x10);

      lVar1 = (long long)(int)uVar5 * (long long)iVar8;

      param_2[6] = uVar6 + ((int)((unsigned long long)lVar1 >> 0x20) << 0x10 | (unsigned int)lVar1 >> 0x10);

    }

  }

  return in_r0;

}

unsigned int FUN_06031a28(param_1, param_2, param_3)
    int param_1;
    char param_2;
    int param_3;
{

  unsigned int uVar1;

  char *puVar2;

  char *puVar3;

  unsigned int uVar4;

  int iVar5;

  int iVar6;

  unsigned int uVar7;

  int extraout_r3 = 0;

  int extraout_r3_00;

  int extraout_r3_01;

  int iVar8;

  unsigned int uVar9;

  int iVar10;

  char *puVar11;

  int *puVar12;

  int *puVar13;

  int iVar14;

  int iVar15;

  unsigned int *puVar16;

  int *piVar17;

  int iVar18;

  unsigned int *puVar19;

  unsigned int *puVar21;

  unsigned int *puVar22;

  int iVar23;

  int iVar24;

  unsigned int in_sr = 0;

  unsigned int uVar25;

  unsigned int uVar26;

  unsigned int uVar27;

  unsigned int uVar28;

  unsigned int uVar29;

  unsigned int *puVar20;

  puVar3 = (char *)0x06031D3C;

  puVar2 = (char *)0x06031D5C;

  puVar19 = (unsigned int *)(param_1 + param_3 * 0x18);

  do {

    puVar20 = puVar19 + -6;

    uVar4 = (unsigned int)(short)*(unsigned short *)(puVar19 + -2);

    puVar22 = (unsigned int *)-256;

    puVar16 = (unsigned int *)(0x06094FA8 + (unsigned int)*(unsigned short *)(puVar19 + -2) * 0xc);

    uVar7 = puVar16[2];

    uVar26 = in_sr & 0xfffffffe;

    uVar25 = uVar26 | 0 < (int)uVar7;

    if (((unsigned char)uVar25 & 1) == 1) {

      puVar22[4] = 0xa0;

      *puVar22 = uVar7;

      puVar22[5] = 0;

      *(unsigned int *)puVar2 = uVar7;

      puVar11 = (char *)0x06031D6C;

      if ((puVar19[-3] & 0x80000) == 0) {

        puVar21 = *(unsigned int **)0x06089EDC;

        uVar4 = *puVar21;

        uVar25 = *puVar20;

        uVar7 = uVar4 ^ uVar25;

        if ((int)uVar4 < 0) {

          uVar4 = -uVar4;

        }

        if ((int)uVar25 < 0) {

          uVar25 = -uVar25;

        }

        uVar1 = (uVar25 & 0xffff) * (uVar4 & 0xffff);

        iVar6 = (uVar25 >> 0x10) * (uVar4 & 0xffff);

        iVar5 = 0;

        uVar9 = iVar6 + (uVar25 & 0xffff) * (uVar4 >> 0x10);

        if (iVar6 != 0) {

          iVar5 = 0x10000;

        }

        uVar27 = uVar1 + (uVar9 << 16);

        uVar25 = iVar5 + (unsigned int)(uVar27 < uVar1) + (uVar9 >> 0x10) +

                 (uVar25 >> 0x10) * (uVar4 >> 0x10);

        if ((int)-(unsigned int)((int)uVar7 < 0) < 0) {

          uVar25 = ~uVar25;

          if (uVar27 == 0) {

            uVar25 = uVar25 + 1;

          }

          else {

            uVar27 = ~uVar27 + 1;

          }

        }

        if (((unsigned char)(in_sr >> 1) & 1) == 1) {

          if ((int)uVar25 < -0x8000) {

            uVar25 = 0xffff8000;

            uVar27 = 0;

          }

          if (0x7fff < (int)uVar25) {

            uVar25 = 0x7fff;

            uVar27 = 0xffffffff;

          }

          uVar25 = uVar25 & 0xffff;

        }

        uVar7 = puVar21[1];

        uVar4 = puVar19[-5];

        uVar9 = uVar7 ^ uVar4;

        if ((int)uVar7 < 0) {

          uVar7 = -uVar7;

        }

        if ((int)uVar4 < 0) {

          uVar4 = -uVar4;

        }

        uVar29 = (uVar4 & 0xffff) * (uVar7 & 0xffff);

        iVar6 = (uVar4 >> 0x10) * (uVar7 & 0xffff);

        iVar5 = 0;

        uVar1 = iVar6 + (uVar4 & 0xffff) * (uVar7 >> 0x10);

        if (iVar6 != 0) {

          iVar5 = 0x10000;

        }

        uVar28 = uVar29 + (uVar1 << 16);

        uVar4 = iVar5 + (unsigned int)(uVar28 < uVar29) + (uVar1 >> 0x10) +

                (uVar4 >> 0x10) * (uVar7 >> 0x10);

        if ((int)-(unsigned int)((int)uVar9 < 0) < 0) {

          uVar4 = ~uVar4;

          if (uVar28 == 0) {

            uVar4 = uVar4 + 1;

          }

          else {

            uVar28 = ~uVar28 + 1;

          }

        }

        if (((unsigned char)(in_sr >> 1) & 1) == 1) {

          uVar28 = uVar27 + uVar28;

          uVar25 = uVar4 + (uVar28 < uVar27) + (uVar25 & 0xffff);

          if ((int)uVar25 < -0x8000) {

            uVar25 = 0xffff8000;

            uVar28 = 0;

          }

          if (0x7fff < (int)uVar25) {

            uVar25 = 0x7fff;

            uVar28 = 0xffffffff;

          }

          uVar25 = uVar25 & 0xffff;

        }

        else {

          uVar28 = uVar27 + uVar28;

          uVar25 = uVar4 + (uVar28 < uVar27) + uVar25;

        }

        uVar7 = puVar21[2];

        uVar4 = puVar19[-4];

        uVar9 = uVar7 ^ uVar4;

        if ((int)uVar7 < 0) {

          uVar7 = -uVar7;

        }

        if ((int)uVar4 < 0) {

          uVar4 = -uVar4;

        }

        uVar27 = (uVar4 & 0xffff) * (uVar7 & 0xffff);

        iVar6 = (uVar4 >> 0x10) * (uVar7 & 0xffff);

        iVar5 = 0;

        uVar1 = iVar6 + (uVar4 & 0xffff) * (uVar7 >> 0x10);

        if (iVar6 != 0) {

          iVar5 = 0x10000;

        }

        uVar29 = uVar27 + (uVar1 << 16);

        uVar4 = iVar5 + (unsigned int)(uVar29 < uVar27) + (uVar1 >> 0x10) +

                (uVar4 >> 0x10) * (uVar7 >> 0x10);

        if ((int)-(unsigned int)((int)uVar9 < 0) < 0) {

          uVar4 = ~uVar4;

          if (uVar29 == 0) {

            uVar4 = uVar4 + 1;

          }

          else {

            uVar29 = ~uVar29 + 1;

          }

        }

        if (((unsigned char)(in_sr >> 1) & 1) == 1) {

          uVar29 = uVar28 + uVar29;

          uVar25 = uVar4 + (uVar29 < uVar28) + (uVar25 & 0xffff);

          if ((int)uVar25 < -0x8000) {

            uVar25 = 0xffff8000;

            uVar29 = 0;

          }

          if (0x7fff < (int)uVar25) {

            uVar25 = 0x7fff;

            uVar29 = 0xffffffff;

          }

          uVar25 = uVar25 & 0xffff;

        }

        else {

          uVar29 = uVar28 + uVar29;

          uVar25 = uVar4 + (uVar29 < uVar28) + uVar25;

        }

        uVar7 = puVar21[3];

        uVar4 = *puVar20;

        uVar9 = uVar7 ^ uVar4;

        if ((int)uVar7 < 0) {

          uVar7 = -uVar7;

        }

        if ((int)uVar4 < 0) {

          uVar4 = -uVar4;

        }

        uVar27 = (uVar4 & 0xffff) * (uVar7 & 0xffff);

        iVar6 = (uVar4 >> 0x10) * (uVar7 & 0xffff);

        iVar5 = 0;

        uVar1 = iVar6 + (uVar4 & 0xffff) * (uVar7 >> 0x10);

        if (iVar6 != 0) {

          iVar5 = 0x10000;

        }

        uVar28 = uVar27 + (uVar1 << 16);

        uVar4 = iVar5 + (unsigned int)(uVar28 < uVar27) + (uVar1 >> 0x10) +

                (uVar4 >> 0x10) * (uVar7 >> 0x10);

        if ((int)-(unsigned int)((int)uVar9 < 0) < 0) {

          uVar4 = ~uVar4;

          if (uVar28 == 0) {

            uVar4 = uVar4 + 1;

          }

          else {

            uVar28 = ~uVar28 + 1;

          }

        }

        if (((unsigned char)(in_sr >> 1) & 1) == 1) {

          if ((int)uVar4 < -0x8000) {

            uVar4 = 0xffff8000;

            uVar28 = 0;

          }

          if (0x7fff < (int)uVar4) {

            uVar4 = 0x7fff;

            uVar28 = 0xffffffff;

          }

          uVar4 = uVar4 & 0xffff;

        }

        *(unsigned int *)0x06031D6C = uVar25 << 0x10 | uVar29 >> 0x10;

        uVar7 = puVar21[4];

        uVar25 = puVar19[-5];

        uVar9 = uVar7 ^ uVar25;

        if ((int)uVar7 < 0) {

          uVar7 = -uVar7;

        }

        if ((int)uVar25 < 0) {

          uVar25 = -uVar25;

        }

        uVar27 = (uVar25 & 0xffff) * (uVar7 & 0xffff);

        iVar6 = (uVar25 >> 0x10) * (uVar7 & 0xffff);

        iVar5 = 0;

        uVar1 = iVar6 + (uVar25 & 0xffff) * (uVar7 >> 0x10);

        if (iVar6 != 0) {

          iVar5 = 0x10000;

        }

        uVar29 = uVar27 + (uVar1 << 16);

        uVar25 = iVar5 + (unsigned int)(uVar29 < uVar27) + (uVar1 >> 0x10) +

                 (uVar25 >> 0x10) * (uVar7 >> 0x10);

        if ((int)-(unsigned int)((int)uVar9 < 0) < 0) {

          uVar25 = ~uVar25;

          if (uVar29 == 0) {

            uVar25 = uVar25 + 1;

          }

          else {

            uVar29 = ~uVar29 + 1;

          }

        }

        if (((unsigned char)(in_sr >> 1) & 1) == 1) {

          uVar29 = uVar28 + uVar29;

          uVar4 = uVar25 + (uVar29 < uVar28) + (uVar4 & 0xffff);

          if ((int)uVar4 < -0x8000) {

            uVar4 = 0xffff8000;

            uVar29 = 0;

          }

          if (0x7fff < (int)uVar4) {

            uVar4 = 0x7fff;

            uVar29 = 0xffffffff;

          }

          uVar4 = uVar4 & 0xffff;

        }

        else {

          uVar29 = uVar28 + uVar29;

          uVar4 = uVar25 + (uVar29 < uVar28) + uVar4;

        }

        uVar7 = puVar21[5];

        uVar25 = puVar19[-4];

        uVar9 = uVar7 ^ uVar25;

        if ((int)uVar7 < 0) {

          uVar7 = -uVar7;

        }

        if ((int)uVar25 < 0) {

          uVar25 = -uVar25;

        }

        uVar27 = (uVar25 & 0xffff) * (uVar7 & 0xffff);

        iVar6 = (uVar25 >> 0x10) * (uVar7 & 0xffff);

        iVar5 = 0;

        uVar1 = iVar6 + (uVar25 & 0xffff) * (uVar7 >> 0x10);

        if (iVar6 != 0) {

          iVar5 = 0x10000;

        }

        uVar28 = uVar27 + (uVar1 << 16);

        uVar25 = iVar5 + (unsigned int)(uVar28 < uVar27) + (uVar1 >> 0x10) +

                 (uVar25 >> 0x10) * (uVar7 >> 0x10);

        if ((int)-(unsigned int)((int)uVar9 < 0) < 0) {

          uVar25 = ~uVar25;

          if (uVar28 == 0) {

            uVar25 = uVar25 + 1;

          }

          else {

            uVar28 = ~uVar28 + 1;

          }

        }

        if (((unsigned char)(in_sr >> 1) & 1) == 1) {

          uVar28 = uVar29 + uVar28;

          uVar4 = uVar25 + (uVar28 < uVar29) + (uVar4 & 0xffff);

          if ((int)uVar4 < -0x8000) {

            uVar4 = 0xffff8000;

            uVar28 = 0;

          }

          if (0x7fff < (int)uVar4) {

            uVar4 = 0x7fff;

            uVar28 = 0xffffffff;

          }

          uVar4 = uVar4 & 0xffff;

        }

        else {

          uVar28 = uVar29 + uVar28;

          uVar4 = uVar25 + (uVar28 < uVar29) + uVar4;

        }

        uVar7 = puVar21[6];

        uVar25 = *puVar20;

        uVar9 = uVar7 ^ uVar25;

        if ((int)uVar7 < 0) {

          uVar7 = -uVar7;

        }

        if ((int)uVar25 < 0) {

          uVar25 = -uVar25;

        }

        uVar27 = (uVar25 & 0xffff) * (uVar7 & 0xffff);

        iVar6 = (uVar25 >> 0x10) * (uVar7 & 0xffff);

        iVar5 = 0;

        uVar1 = iVar6 + (uVar25 & 0xffff) * (uVar7 >> 0x10);

        if (iVar6 != 0) {

          iVar5 = 0x10000;

        }

        uVar29 = uVar27 + (uVar1 << 16);

        uVar25 = iVar5 + (unsigned int)(uVar29 < uVar27) + (uVar1 >> 0x10) +

                 (uVar25 >> 0x10) * (uVar7 >> 0x10);

        if ((int)-(unsigned int)((int)uVar9 < 0) < 0) {

          uVar25 = ~uVar25;

          if (uVar29 == 0) {

            uVar25 = uVar25 + 1;

          }

          else {

            uVar29 = ~uVar29 + 1;

          }

        }

        if (((unsigned char)(in_sr >> 1) & 1) == 1) {

          if ((int)uVar25 < -0x8000) {

            uVar25 = 0xffff8000;

            uVar29 = 0;

          }

          if (0x7fff < (int)uVar25) {

            uVar25 = 0x7fff;

            uVar29 = 0xffffffff;

          }

          uVar25 = uVar25 & 0xffff;

        }

        *(unsigned int *)(puVar11 + 4) = uVar4 << 0x10 | uVar28 >> 0x10;

        uVar7 = puVar21[7];

        uVar4 = puVar19[-5];

        uVar9 = uVar7 ^ uVar4;

        if ((int)uVar7 < 0) {

          uVar7 = -uVar7;

        }

        if ((int)uVar4 < 0) {

          uVar4 = -uVar4;

        }

        uVar27 = (uVar4 & 0xffff) * (uVar7 & 0xffff);

        iVar6 = (uVar4 >> 0x10) * (uVar7 & 0xffff);

        iVar5 = 0;

        uVar1 = iVar6 + (uVar4 & 0xffff) * (uVar7 >> 0x10);

        if (iVar6 != 0) {

          iVar5 = 0x10000;

        }

        uVar28 = uVar27 + (uVar1 << 16);

        uVar4 = iVar5 + (unsigned int)(uVar28 < uVar27) + (uVar1 >> 0x10) +

                (uVar4 >> 0x10) * (uVar7 >> 0x10);

        if ((int)-(unsigned int)((int)uVar9 < 0) < 0) {

          uVar4 = ~uVar4;

          if (uVar28 == 0) {

            uVar4 = uVar4 + 1;

          }

          else {

            uVar28 = ~uVar28 + 1;

          }

        }

        if (((unsigned char)(in_sr >> 1) & 1) == 1) {

          uVar28 = uVar29 + uVar28;

          uVar25 = uVar4 + (uVar28 < uVar29) + (uVar25 & 0xffff);

          if ((int)uVar25 < -0x8000) {

            uVar25 = 0xffff8000;

            uVar28 = 0;

          }

          if (0x7fff < (int)uVar25) {

            uVar25 = 0x7fff;

            uVar28 = 0xffffffff;

          }

          uVar25 = uVar25 & 0xffff;

        }

        else {

          uVar28 = uVar29 + uVar28;

          uVar25 = uVar4 + (uVar28 < uVar29) + uVar25;

        }

        uVar7 = puVar21[8];

        uVar4 = puVar19[-4];

        uVar9 = uVar7 ^ uVar4;

        if ((int)uVar7 < 0) {

          uVar7 = -uVar7;

        }

        if ((int)uVar4 < 0) {

          uVar4 = -uVar4;

        }

        uVar27 = (uVar4 & 0xffff) * (uVar7 & 0xffff);

        iVar6 = (uVar4 >> 0x10) * (uVar7 & 0xffff);

        iVar5 = 0;

        uVar1 = iVar6 + (uVar4 & 0xffff) * (uVar7 >> 0x10);

        if (iVar6 != 0) {

          iVar5 = 0x10000;

        }

        uVar29 = uVar27 + (uVar1 << 16);

        uVar4 = iVar5 + (unsigned int)(uVar29 < uVar27) + (uVar1 >> 0x10) +

                (uVar4 >> 0x10) * (uVar7 >> 0x10);

        if ((int)-(unsigned int)((int)uVar9 < 0) < 0) {

          uVar4 = ~uVar4;

          if (uVar29 == 0) {

            uVar4 = uVar4 + 1;

          }

          else {

            uVar29 = ~uVar29 + 1;

          }

        }

        if (((unsigned char)(in_sr >> 1) & 1) == 1) {

          uVar29 = uVar28 + uVar29;

          uVar25 = uVar4 + (uVar29 < uVar28) + (uVar25 & 0xffff);

          if ((int)uVar25 < -0x8000) {

            uVar25 = 0xffff8000;

            uVar29 = 0;

          }

          if (0x7fff < (int)uVar25) {

            uVar25 = 0x7fff;

            uVar29 = 0xffffffff;

          }

          uVar25 = uVar25 & 0xffff;

        }

        else {

          uVar29 = uVar28 + uVar29;

          uVar25 = uVar4 + (uVar29 < uVar28) + uVar25;

        }

        *(unsigned int *)(puVar11 + 8) = uVar25 << 0x10 | uVar29 >> 0x10;

        uVar4 = *(unsigned int *)puVar11;

        uVar25 = *puVar16;

        uVar7 = uVar4 ^ uVar25;

        if ((int)uVar4 < 0) {

          uVar4 = -uVar4;

        }

        if ((int)uVar25 < 0) {

          uVar25 = -uVar25;

        }

        uVar1 = (uVar25 & 0xffff) * (uVar4 & 0xffff);

        iVar6 = (uVar25 >> 0x10) * (uVar4 & 0xffff);

        iVar5 = 0;

        uVar9 = iVar6 + (uVar25 & 0xffff) * (uVar4 >> 0x10);

        if (iVar6 != 0) {

          iVar5 = 0x10000;

        }

        uVar27 = uVar1 + (uVar9 << 16);

        uVar25 = iVar5 + (unsigned int)(uVar27 < uVar1) + (uVar9 >> 0x10) +

                 (uVar25 >> 0x10) * (uVar4 >> 0x10);

        if ((int)-(unsigned int)((int)uVar7 < 0) < 0) {

          uVar25 = ~uVar25;

          if (uVar27 == 0) {

            uVar25 = uVar25 + 1;

          }

          else {

            uVar27 = ~uVar27 + 1;

          }

        }

        if (((unsigned char)(in_sr >> 1) & 1) == 1) {

          if ((int)uVar25 < -0x8000) {

            uVar25 = 0xffff8000;

            uVar27 = 0;

          }

          if (0x7fff < (int)uVar25) {

            uVar25 = 0x7fff;

            uVar27 = 0xffffffff;

          }

          uVar25 = uVar25 & 0xffff;

        }

        uVar7 = *(unsigned int *)(puVar11 + 4);

        uVar4 = puVar16[1];

        uVar9 = uVar7 ^ uVar4;

        if ((int)uVar7 < 0) {

          uVar7 = -uVar7;

        }

        if ((int)uVar4 < 0) {

          uVar4 = -uVar4;

        }

        uVar29 = (uVar4 & 0xffff) * (uVar7 & 0xffff);

        iVar6 = (uVar4 >> 0x10) * (uVar7 & 0xffff);

        iVar5 = 0;

        uVar1 = iVar6 + (uVar4 & 0xffff) * (uVar7 >> 0x10);

        if (iVar6 != 0) {

          iVar5 = 0x10000;

        }

        uVar28 = uVar29 + (uVar1 << 16);

        uVar4 = iVar5 + (unsigned int)(uVar28 < uVar29) + (uVar1 >> 0x10) +

                (uVar4 >> 0x10) * (uVar7 >> 0x10);

        if ((int)-(unsigned int)((int)uVar9 < 0) < 0) {

          uVar4 = ~uVar4;

          if (uVar28 == 0) {

            uVar4 = uVar4 + 1;

          }

          else {

            uVar28 = ~uVar28 + 1;

          }

        }

        if (((unsigned char)(in_sr >> 1) & 1) == 1) {

          uVar28 = uVar27 + uVar28;

          uVar25 = uVar4 + (uVar28 < uVar27) + (uVar25 & 0xffff);

          if ((int)uVar25 < -0x8000) {

            uVar25 = 0xffff8000;

            uVar28 = 0;

          }

          if (0x7fff < (int)uVar25) {

            uVar25 = 0x7fff;

            uVar28 = 0xffffffff;

          }

          uVar25 = uVar25 & 0xffff;

        }

        else {

          uVar28 = uVar27 + uVar28;

          uVar25 = uVar4 + (uVar28 < uVar27) + uVar25;

        }

        uVar7 = *(unsigned int *)(puVar11 + 8);

        uVar4 = puVar16[2];

        uVar9 = uVar7 ^ uVar4;

        if ((int)uVar7 < 0) {

          uVar7 = -uVar7;

        }

        if ((int)uVar4 < 0) {

          uVar4 = -uVar4;

        }

        uVar27 = (uVar4 & 0xffff) * (uVar7 & 0xffff);

        iVar6 = (uVar4 >> 0x10) * (uVar7 & 0xffff);

        iVar5 = 0;

        uVar1 = iVar6 + (uVar4 & 0xffff) * (uVar7 >> 0x10);

        if (iVar6 != 0) {

          iVar5 = 0x10000;

        }

        uVar29 = uVar27 + (uVar1 << 16);

        uVar4 = iVar5 + (unsigned int)(uVar29 < uVar27) + (uVar1 >> 0x10) +

                (uVar4 >> 0x10) * (uVar7 >> 0x10);

        if ((int)-(unsigned int)((int)uVar9 < 0) < 0) {

          uVar4 = ~uVar4;

          if (uVar29 == 0) {

            uVar4 = uVar4 + 1;

          }

          else {

            uVar29 = ~uVar29 + 1;

          }

        }

        if (((unsigned char)(in_sr >> 1) & 1) == 1) {

          uVar29 = uVar28 + uVar29;

          uVar25 = uVar4 + (uVar29 < uVar28) + (uVar25 & 0xffff);

          if ((int)uVar25 < -0x8000) {

            uVar25 = 0xffff8000;

            uVar29 = 0;

          }

          if (0x7fff < (int)uVar25) {

            uVar25 = 0x7fff;

            uVar29 = 0xffffffff;

          }

          uVar25 = uVar25 & 0xffff;

        }

        else {

          uVar29 = uVar28 + uVar29;

          uVar25 = uVar4 + (uVar29 < uVar28) + uVar25;

        }

        uVar4 = uVar25 << 0x10 | uVar29 >> 0x10;

        uVar26 = uVar26 | 0 < (int)uVar4;

        uVar25 = uVar26;

        if (((unsigned char)uVar26 & 1) != 1) goto LAB_06031cf2;

      }

      uVar4 = puVar16[1];

      uVar25 = *puVar16;

      uVar9 = puVar22[7];

      piVar17 = (int *)(0x06094FA8 + (unsigned int)*(unsigned short *)((int)puVar19 + -6) * 0xc);

      uVar7 = piVar17[2];

      puVar22[4] = 0xa0;

      *puVar22 = uVar7;

      puVar22[5] = 0;

      *(int *)puVar3 = (int)((unsigned long long)((long long)(int)uVar9 * (long long)(int)uVar25) >> 0x20);

      *(int *)(puVar3 + 4) =

           (int)((unsigned long long)((long long)(int)uVar9 * (long long)(int)-uVar4) >> 0x20);

      puVar11 = puVar3;

      uVar4 = FUN_06031d1a();

      uVar25 = uVar26 & 0xfffffffe | (unsigned int)(0 < extraout_r3);

      if (((unsigned char)uVar25 & 1) == 1) {

        *(int *)(puVar2 + 4) = extraout_r3;

        puVar12 = (int *)(puVar11 + 8);

        iVar6 = piVar17[1];

        iVar5 = *piVar17;

        uVar4 = puVar22[7];

        piVar17 = (int *)(0x06094FA8 + (unsigned int)*(unsigned short *)(puVar19 + -1) * 0xc);

        uVar26 = piVar17[2];

        puVar22[4] = 0xa0;

        *puVar22 = uVar26;

        puVar22[5] = 0;

        *puVar12 = (int)((unsigned long long)((long long)(int)uVar4 * (long long)iVar5) >> 0x20);

        *(int *)(puVar11 + 0xc) =

             (int)((unsigned long long)((long long)(int)uVar4 * (long long)-iVar6) >> 0x20);

        uVar4 = FUN_06031d1a();

        uVar25 = uVar25 & 0xfffffffe | (unsigned int)(0 < extraout_r3_00);

        if (((unsigned char)uVar25 & 1) == 1) {

          *(int *)(puVar2 + 8) = extraout_r3_00;

          puVar13 = puVar12 + 2;

          iVar6 = piVar17[1];

          iVar5 = *piVar17;

          uVar4 = puVar22[7];

          piVar17 = (int *)(0x06094FA8 + (unsigned int)*(unsigned short *)((int)puVar19 + -2) * 0xc);

          uVar26 = piVar17[2];

          puVar22[4] = 0xa0;

          *puVar22 = uVar26;

          puVar22[5] = 0;

          *puVar13 = (int)((unsigned long long)((long long)(int)uVar4 * (long long)iVar5) >> 0x20);

          puVar12[3] = (int)((unsigned long long)((long long)(int)uVar4 * (long long)-iVar6) >> 0x20);

          uVar4 = FUN_06031d1a();

          uVar25 = uVar25 & 0xfffffffe | (unsigned int)(0 < extraout_r3_01);

          if (((unsigned char)uVar25 & 1) == 1) {

            *(int *)(puVar2 + 0xc) = extraout_r3_01;

            iVar5 = piVar17[1];

            uVar26 = puVar22[7];

            puVar13[2] = (int)((unsigned long long)((long long)(int)uVar26 * (long long)*piVar17) >> 0x20);

            puVar13[3] = (int)((unsigned long long)((long long)(int)uVar26 * (long long)-iVar5) >> 0x20);

            FUN_06031d1a();

            puVar11 = (char *)0x0608AC20;

            iVar5 = *(int *)0x060620D0;

            iVar23 = -176;

            uVar4 = *(unsigned int *)puVar3;

            iVar6 = *(int *)(puVar3 + 8);

            iVar10 = *(int *)(puVar3 + 0x10);

            iVar15 = *(int *)(puVar3 + 0x18);

            uVar25 = uVar25 & 0xfffffffe;

            if ((((iVar23 <= (int)uVar4) || (iVar23 <= iVar6)) || (iVar23 <= iVar10)) ||

               (iVar23 <= iVar15)) {

              iVar23 = 0xb0;

              uVar26 = uVar25 | (int)uVar4 < iVar23;

              if (((((unsigned char)uVar26 & 1) == 1) ||

                  (uVar26 = uVar25 | iVar6 < iVar23, ((unsigned char)uVar26 & 1) == 1)) ||

                 ((uVar26 = uVar25 | iVar10 < iVar23, ((unsigned char)uVar26 & 1) == 1 ||

                  (uVar26 = uVar25 | iVar15 < iVar23, uVar25 = uVar26, ((unsigned char)uVar26 & 1) != 1)))) {

                iVar24 = -127;

                iVar23 = *(int *)(puVar3 + 4);

                iVar8 = *(int *)(puVar3 + 0xc);

                iVar14 = *(int *)(puVar3 + 0x14);

                iVar18 = *(int *)(puVar3 + 0x1c);

                uVar25 = uVar26 & 0xfffffffe;

                if (((iVar24 <= iVar23) || (iVar24 <= iVar8)) ||

                   ((iVar24 <= iVar14 ||

                    (uVar25 = uVar25 | iVar18 < iVar24, ((unsigned char)uVar25 & 1) != 1)))) {

                  iVar24 = 0x51;

                  if ((((iVar23 < iVar24) || (iVar8 < iVar24)) || (iVar14 < iVar24)) ||

                     (uVar25 = uVar25 & 0xfffffffe, iVar18 < iVar24)) {

                    *(short *)(0x0608AC20 + iVar5 * 0x18 + 0x16) = (short)iVar18;

                    *(short *)(puVar11 + iVar5 * 0x18 + 0x14) = (short)iVar15;

                    *(short *)(puVar11 + iVar5 * 0x18 + 0x12) = (short)iVar14;

                    *(short *)(puVar11 + iVar5 * 0x18 + 0x10) = (short)iVar10;

                    *(short *)(puVar11 + iVar5 * 0x18 + 0xe) = (short)iVar8;

                    *(short *)(puVar11 + iVar5 * 0x18 + 0xc) = (short)iVar6;

                    *(short *)(puVar11 + iVar5 * 0x18 + 10) = (short)iVar23;

                    *(short *)(puVar11 + iVar5 * 0x18 + 8) = (short)uVar4;

                    *(short *)(puVar11 + iVar5 * 0x18 + 6) =

                         *(short *)((int)puVar19 + -10);

                    puVar11[iVar5 * 0x18 + 4] =

                         (unsigned char)((unsigned int)(int)*(short *)(puVar19 + -3) >> 4) & 0xf;

                    puVar11[iVar5 * 0x18 + 5] = param_2;

                    uVar25 = (*(int(*)())(*(int *)(0x06031D78 +

                                         ((int)*(short *)(puVar19 + -3) & 7U) << 2)))(*(int *)(puVar2 + 4),*(int *)(puVar2 + 8),

                                        *(int *)(puVar2 + 0xc));

                    return uVar25;

                  }

                }

              }

            }

          }

        }

      }

    }

LAB_06031cf2:

    param_3 = param_3 + -1;

    in_sr = uVar25 & 0xfffffffe | (unsigned int)(param_3 == 0);

    puVar19 = puVar20;

    if (((unsigned char)in_sr & 1) == 1) {

      return uVar4;

    }

  } while( 1 );

}

unsigned int FUN_06031d1a()
{

  char *puVar1;

  unsigned int uVar2;

  int iVar3;

  unsigned int uVar4;

  int in_r1 = 0;

  int iVar5;

  int in_r2 = 0;

  unsigned int uVar6;

  unsigned int uVar7;

  unsigned int extraout_r3 = 0;

  unsigned int extraout_r3_00;

  unsigned int extraout_r3_01;

  unsigned int uVar8;

  unsigned int uVar9;

  unsigned int *puVar10;

  int *piVar11;

  unsigned int uVar12;

  unsigned int *puVar13;

  unsigned int *unaff_r8;

  unsigned int *puVar14;

  char unaff_r10 = 0;

  unsigned int *unaff_r11;

  unsigned int *puVar15;

  unsigned int *unaff_r13;

  int unaff_r14 = 0;

  unsigned int uVar16;

  unsigned int uVar17;

  unsigned int in_sr = 0;

  unsigned int uVar18;

  uVar2 = (unsigned int)DAT_06031d36;

  uVar16 = in_sr & 0xfffffffe;

  uVar18 = uVar16 | (int)uVar2 < in_r1;

  if (((unsigned char)uVar18 & 1) != 1) {

    uVar2 = (unsigned int)DAT_06031d38;

    uVar18 = uVar16 | in_r1 < (int)uVar2;

    if (((unsigned char)uVar18 & 1) != 1) {

      uVar2 = (unsigned int)DAT_06031d3a;

      uVar18 = uVar16 | (int)uVar2 < in_r2;

      if (((unsigned char)uVar18 & 1) != 1) {

        uVar2 = (unsigned int)DAT_06031d38;

        uVar18 = uVar16 | in_r2 < (int)uVar2;

        if (((unsigned char)uVar18 & 1) != 1) {

          return uVar2;

        }

      }

    }

  }

LAB_06031cf2:

  do {

    uVar7 = uVar18;

    puVar13 = unaff_r8;

    unaff_r14 = unaff_r14 + -1;

    uVar16 = uVar7 & 0xfffffffe;

    if (unaff_r14 == 0) {

      return uVar2;

    }

    unaff_r8 = puVar13 + -6;

    uVar2 = (unsigned int)(short)*(unsigned short *)(puVar13 + -2);

    puVar15 = (unsigned int *)(int)DAT_06031a64;

    puVar10 = (unsigned int *)(0x06094FA8 + (unsigned int)*(unsigned short *)(puVar13 + -2) * 0xc);

    uVar6 = puVar10[2];

    uVar18 = uVar16 | 0 < (int)uVar6;

  } while (((unsigned char)uVar18 & 1) != 1);

  puVar15[4] = (int)PTR_DAT_06031adc;

  *puVar15 = uVar6;

  puVar15[5] = 0;

  *unaff_r13 = uVar6;

  puVar1 = (char *)0x06031D6C;

  if ((puVar13[-3] & 0x80000) == 0) {

    puVar14 = *(unsigned int **)0x06089EDC;

    uVar2 = *puVar14;

    uVar18 = *unaff_r8;

    uVar6 = uVar2 ^ uVar18;

    if ((int)uVar2 < 0) {

      uVar2 = -uVar2;

    }

    if ((int)uVar18 < 0) {

      uVar18 = -uVar18;

    }

    uVar4 = (uVar18 & 0xffff) * (uVar2 & 0xffff);

    iVar5 = (uVar18 >> 0x10) * (uVar2 & 0xffff);

    iVar3 = 0;

    uVar17 = iVar5 + (uVar18 & 0xffff) * (uVar2 >> 0x10);

    if (iVar5 != 0) {

      iVar3 = 0x10000;

    }

    uVar8 = uVar4 + (uVar17 << 16);

    uVar18 = iVar3 + (unsigned int)(uVar8 < uVar4) + (uVar17 >> 0x10) + (uVar18 >> 0x10) * (uVar2 >> 0x10);

    if ((int)-(unsigned int)((int)uVar6 < 0) < 0) {

      uVar18 = ~uVar18;

      if (uVar8 == 0) {

        uVar18 = uVar18 + 1;

      }

      else {

        uVar8 = ~uVar8 + 1;

      }

    }

    if (((unsigned char)(uVar7 >> 1) & 1) == 1) {

      if ((int)uVar18 < -0x8000) {

        uVar18 = 0xffff8000;

        uVar8 = 0;

      }

      if (0x7fff < (int)uVar18) {

        uVar18 = 0x7fff;

        uVar8 = 0xffffffff;

      }

      uVar18 = uVar18 & 0xffff;

    }

    uVar6 = puVar14[1];

    uVar2 = puVar13[-5];

    uVar17 = uVar6 ^ uVar2;

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    if ((int)uVar2 < 0) {

      uVar2 = -uVar2;

    }

    uVar9 = (uVar2 & 0xffff) * (uVar6 & 0xffff);

    iVar5 = (uVar2 >> 0x10) * (uVar6 & 0xffff);

    iVar3 = 0;

    uVar4 = iVar5 + (uVar2 & 0xffff) * (uVar6 >> 0x10);

    if (iVar5 != 0) {

      iVar3 = 0x10000;

    }

    uVar12 = uVar9 + (uVar4 << 16);

    uVar2 = iVar3 + (unsigned int)(uVar12 < uVar9) + (uVar4 >> 0x10) + (uVar2 >> 0x10) * (uVar6 >> 0x10);

    if ((int)-(unsigned int)((int)uVar17 < 0) < 0) {

      uVar2 = ~uVar2;

      if (uVar12 == 0) {

        uVar2 = uVar2 + 1;

      }

      else {

        uVar12 = ~uVar12 + 1;

      }

    }

    if (((unsigned char)(uVar7 >> 1) & 1) == 1) {

      uVar12 = uVar8 + uVar12;

      uVar18 = uVar2 + (uVar12 < uVar8) + (uVar18 & 0xffff);

      if ((int)uVar18 < -0x8000) {

        uVar18 = 0xffff8000;

        uVar12 = 0;

      }

      if (0x7fff < (int)uVar18) {

        uVar18 = 0x7fff;

        uVar12 = 0xffffffff;

      }

      uVar18 = uVar18 & 0xffff;

    }

    else {

      uVar12 = uVar8 + uVar12;

      uVar18 = uVar2 + (uVar12 < uVar8) + uVar18;

    }

    uVar6 = puVar14[2];

    uVar2 = puVar13[-4];

    uVar17 = uVar6 ^ uVar2;

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    if ((int)uVar2 < 0) {

      uVar2 = -uVar2;

    }

    uVar8 = (uVar2 & 0xffff) * (uVar6 & 0xffff);

    iVar5 = (uVar2 >> 0x10) * (uVar6 & 0xffff);

    iVar3 = 0;

    uVar4 = iVar5 + (uVar2 & 0xffff) * (uVar6 >> 0x10);

    if (iVar5 != 0) {

      iVar3 = 0x10000;

    }

    uVar9 = uVar8 + (uVar4 << 16);

    uVar2 = iVar3 + (unsigned int)(uVar9 < uVar8) + (uVar4 >> 0x10) + (uVar2 >> 0x10) * (uVar6 >> 0x10);

    if ((int)-(unsigned int)((int)uVar17 < 0) < 0) {

      uVar2 = ~uVar2;

      if (uVar9 == 0) {

        uVar2 = uVar2 + 1;

      }

      else {

        uVar9 = ~uVar9 + 1;

      }

    }

    if (((unsigned char)(uVar7 >> 1) & 1) == 1) {

      uVar9 = uVar12 + uVar9;

      uVar18 = uVar2 + (uVar9 < uVar12) + (uVar18 & 0xffff);

      if ((int)uVar18 < -0x8000) {

        uVar18 = 0xffff8000;

        uVar9 = 0;

      }

      if (0x7fff < (int)uVar18) {

        uVar18 = 0x7fff;

        uVar9 = 0xffffffff;

      }

      uVar18 = uVar18 & 0xffff;

    }

    else {

      uVar9 = uVar12 + uVar9;

      uVar18 = uVar2 + (uVar9 < uVar12) + uVar18;

    }

    uVar6 = puVar14[3];

    uVar2 = *unaff_r8;

    uVar17 = uVar6 ^ uVar2;

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    if ((int)uVar2 < 0) {

      uVar2 = -uVar2;

    }

    uVar8 = (uVar2 & 0xffff) * (uVar6 & 0xffff);

    iVar5 = (uVar2 >> 0x10) * (uVar6 & 0xffff);

    iVar3 = 0;

    uVar4 = iVar5 + (uVar2 & 0xffff) * (uVar6 >> 0x10);

    if (iVar5 != 0) {

      iVar3 = 0x10000;

    }

    uVar12 = uVar8 + (uVar4 << 16);

    uVar2 = iVar3 + (unsigned int)(uVar12 < uVar8) + (uVar4 >> 0x10) + (uVar2 >> 0x10) * (uVar6 >> 0x10);

    if ((int)-(unsigned int)((int)uVar17 < 0) < 0) {

      uVar2 = ~uVar2;

      if (uVar12 == 0) {

        uVar2 = uVar2 + 1;

      }

      else {

        uVar12 = ~uVar12 + 1;

      }

    }

    if (((unsigned char)(uVar7 >> 1) & 1) == 1) {

      if ((int)uVar2 < -0x8000) {

        uVar2 = 0xffff8000;

        uVar12 = 0;

      }

      if (0x7fff < (int)uVar2) {

        uVar2 = 0x7fff;

        uVar12 = 0xffffffff;

      }

      uVar2 = uVar2 & 0xffff;

    }

    *(unsigned int *)0x06031D6C = uVar18 << 0x10 | uVar9 >> 0x10;

    uVar6 = puVar14[4];

    uVar18 = puVar13[-5];

    uVar17 = uVar6 ^ uVar18;

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    if ((int)uVar18 < 0) {

      uVar18 = -uVar18;

    }

    uVar8 = (uVar18 & 0xffff) * (uVar6 & 0xffff);

    iVar5 = (uVar18 >> 0x10) * (uVar6 & 0xffff);

    iVar3 = 0;

    uVar4 = iVar5 + (uVar18 & 0xffff) * (uVar6 >> 0x10);

    if (iVar5 != 0) {

      iVar3 = 0x10000;

    }

    uVar9 = uVar8 + (uVar4 << 16);

    uVar18 = iVar3 + (unsigned int)(uVar9 < uVar8) + (uVar4 >> 0x10) + (uVar18 >> 0x10) * (uVar6 >> 0x10);

    if ((int)-(unsigned int)((int)uVar17 < 0) < 0) {

      uVar18 = ~uVar18;

      if (uVar9 == 0) {

        uVar18 = uVar18 + 1;

      }

      else {

        uVar9 = ~uVar9 + 1;

      }

    }

    if (((unsigned char)(uVar7 >> 1) & 1) == 1) {

      uVar9 = uVar12 + uVar9;

      uVar2 = uVar18 + (uVar9 < uVar12) + (uVar2 & 0xffff);

      if ((int)uVar2 < -0x8000) {

        uVar2 = 0xffff8000;

        uVar9 = 0;

      }

      if (0x7fff < (int)uVar2) {

        uVar2 = 0x7fff;

        uVar9 = 0xffffffff;

      }

      uVar2 = uVar2 & 0xffff;

    }

    else {

      uVar9 = uVar12 + uVar9;

      uVar2 = uVar18 + (uVar9 < uVar12) + uVar2;

    }

    uVar6 = puVar14[5];

    uVar18 = puVar13[-4];

    uVar17 = uVar6 ^ uVar18;

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    if ((int)uVar18 < 0) {

      uVar18 = -uVar18;

    }

    uVar8 = (uVar18 & 0xffff) * (uVar6 & 0xffff);

    iVar5 = (uVar18 >> 0x10) * (uVar6 & 0xffff);

    iVar3 = 0;

    uVar4 = iVar5 + (uVar18 & 0xffff) * (uVar6 >> 0x10);

    if (iVar5 != 0) {

      iVar3 = 0x10000;

    }

    uVar12 = uVar8 + (uVar4 << 16);

    uVar18 = iVar3 + (unsigned int)(uVar12 < uVar8) + (uVar4 >> 0x10) + (uVar18 >> 0x10) * (uVar6 >> 0x10);

    if ((int)-(unsigned int)((int)uVar17 < 0) < 0) {

      uVar18 = ~uVar18;

      if (uVar12 == 0) {

        uVar18 = uVar18 + 1;

      }

      else {

        uVar12 = ~uVar12 + 1;

      }

    }

    if (((unsigned char)(uVar7 >> 1) & 1) == 1) {

      uVar12 = uVar9 + uVar12;

      uVar2 = uVar18 + (uVar12 < uVar9) + (uVar2 & 0xffff);

      if ((int)uVar2 < -0x8000) {

        uVar2 = 0xffff8000;

        uVar12 = 0;

      }

      if (0x7fff < (int)uVar2) {

        uVar2 = 0x7fff;

        uVar12 = 0xffffffff;

      }

      uVar2 = uVar2 & 0xffff;

    }

    else {

      uVar12 = uVar9 + uVar12;

      uVar2 = uVar18 + (uVar12 < uVar9) + uVar2;

    }

    uVar6 = puVar14[6];

    uVar18 = *unaff_r8;

    uVar17 = uVar6 ^ uVar18;

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    if ((int)uVar18 < 0) {

      uVar18 = -uVar18;

    }

    uVar8 = (uVar18 & 0xffff) * (uVar6 & 0xffff);

    iVar5 = (uVar18 >> 0x10) * (uVar6 & 0xffff);

    iVar3 = 0;

    uVar4 = iVar5 + (uVar18 & 0xffff) * (uVar6 >> 0x10);

    if (iVar5 != 0) {

      iVar3 = 0x10000;

    }

    uVar9 = uVar8 + (uVar4 << 16);

    uVar18 = iVar3 + (unsigned int)(uVar9 < uVar8) + (uVar4 >> 0x10) + (uVar18 >> 0x10) * (uVar6 >> 0x10);

    if ((int)-(unsigned int)((int)uVar17 < 0) < 0) {

      uVar18 = ~uVar18;

      if (uVar9 == 0) {

        uVar18 = uVar18 + 1;

      }

      else {

        uVar9 = ~uVar9 + 1;

      }

    }

    if (((unsigned char)(uVar7 >> 1) & 1) == 1) {

      if ((int)uVar18 < -0x8000) {

        uVar18 = 0xffff8000;

        uVar9 = 0;

      }

      if (0x7fff < (int)uVar18) {

        uVar18 = 0x7fff;

        uVar9 = 0xffffffff;

      }

      uVar18 = uVar18 & 0xffff;

    }

    *(unsigned int *)(puVar1 + 4) = uVar2 << 0x10 | uVar12 >> 0x10;

    uVar6 = puVar14[7];

    uVar2 = puVar13[-5];

    uVar17 = uVar6 ^ uVar2;

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    if ((int)uVar2 < 0) {

      uVar2 = -uVar2;

    }

    uVar8 = (uVar2 & 0xffff) * (uVar6 & 0xffff);

    iVar5 = (uVar2 >> 0x10) * (uVar6 & 0xffff);

    iVar3 = 0;

    uVar4 = iVar5 + (uVar2 & 0xffff) * (uVar6 >> 0x10);

    if (iVar5 != 0) {

      iVar3 = 0x10000;

    }

    uVar12 = uVar8 + (uVar4 << 16);

    uVar2 = iVar3 + (unsigned int)(uVar12 < uVar8) + (uVar4 >> 0x10) + (uVar2 >> 0x10) * (uVar6 >> 0x10);

    if ((int)-(unsigned int)((int)uVar17 < 0) < 0) {

      uVar2 = ~uVar2;

      if (uVar12 == 0) {

        uVar2 = uVar2 + 1;

      }

      else {

        uVar12 = ~uVar12 + 1;

      }

    }

    if (((unsigned char)(uVar7 >> 1) & 1) == 1) {

      uVar12 = uVar9 + uVar12;

      uVar18 = uVar2 + (uVar12 < uVar9) + (uVar18 & 0xffff);

      if ((int)uVar18 < -0x8000) {

        uVar18 = 0xffff8000;

        uVar12 = 0;

      }

      if (0x7fff < (int)uVar18) {

        uVar18 = 0x7fff;

        uVar12 = 0xffffffff;

      }

      uVar18 = uVar18 & 0xffff;

    }

    else {

      uVar12 = uVar9 + uVar12;

      uVar18 = uVar2 + (uVar12 < uVar9) + uVar18;

    }

    uVar6 = puVar14[8];

    uVar2 = puVar13[-4];

    uVar17 = uVar6 ^ uVar2;

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    if ((int)uVar2 < 0) {

      uVar2 = -uVar2;

    }

    uVar8 = (uVar2 & 0xffff) * (uVar6 & 0xffff);

    iVar5 = (uVar2 >> 0x10) * (uVar6 & 0xffff);

    iVar3 = 0;

    uVar4 = iVar5 + (uVar2 & 0xffff) * (uVar6 >> 0x10);

    if (iVar5 != 0) {

      iVar3 = 0x10000;

    }

    uVar9 = uVar8 + (uVar4 << 16);

    uVar2 = iVar3 + (unsigned int)(uVar9 < uVar8) + (uVar4 >> 0x10) + (uVar2 >> 0x10) * (uVar6 >> 0x10);

    if ((int)-(unsigned int)((int)uVar17 < 0) < 0) {

      uVar2 = ~uVar2;

      if (uVar9 == 0) {

        uVar2 = uVar2 + 1;

      }

      else {

        uVar9 = ~uVar9 + 1;

      }

    }

    if (((unsigned char)(uVar7 >> 1) & 1) == 1) {

      uVar9 = uVar12 + uVar9;

      uVar18 = uVar2 + (uVar9 < uVar12) + (uVar18 & 0xffff);

      if ((int)uVar18 < -0x8000) {

        uVar18 = 0xffff8000;

        uVar9 = 0;

      }

      if (0x7fff < (int)uVar18) {

        uVar18 = 0x7fff;

        uVar9 = 0xffffffff;

      }

      uVar18 = uVar18 & 0xffff;

    }

    else {

      uVar9 = uVar12 + uVar9;

      uVar18 = uVar2 + (uVar9 < uVar12) + uVar18;

    }

    *(unsigned int *)(puVar1 + 8) = uVar18 << 0x10 | uVar9 >> 0x10;

    uVar2 = *(unsigned int *)puVar1;

    uVar18 = *puVar10;

    uVar6 = uVar2 ^ uVar18;

    if ((int)uVar2 < 0) {

      uVar2 = -uVar2;

    }

    if ((int)uVar18 < 0) {

      uVar18 = -uVar18;

    }

    uVar4 = (uVar18 & 0xffff) * (uVar2 & 0xffff);

    iVar5 = (uVar18 >> 0x10) * (uVar2 & 0xffff);

    iVar3 = 0;

    uVar17 = iVar5 + (uVar18 & 0xffff) * (uVar2 >> 0x10);

    if (iVar5 != 0) {

      iVar3 = 0x10000;

    }

    uVar8 = uVar4 + (uVar17 << 16);

    uVar18 = iVar3 + (unsigned int)(uVar8 < uVar4) + (uVar17 >> 0x10) + (uVar18 >> 0x10) * (uVar2 >> 0x10);

    if ((int)-(unsigned int)((int)uVar6 < 0) < 0) {

      uVar18 = ~uVar18;

      if (uVar8 == 0) {

        uVar18 = uVar18 + 1;

      }

      else {

        uVar8 = ~uVar8 + 1;

      }

    }

    if (((unsigned char)(uVar7 >> 1) & 1) == 1) {

      if ((int)uVar18 < -0x8000) {

        uVar18 = 0xffff8000;

        uVar8 = 0;

      }

      if (0x7fff < (int)uVar18) {

        uVar18 = 0x7fff;

        uVar8 = 0xffffffff;

      }

      uVar18 = uVar18 & 0xffff;

    }

    uVar6 = *(unsigned int *)(puVar1 + 4);

    uVar2 = puVar10[1];

    uVar17 = uVar6 ^ uVar2;

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    if ((int)uVar2 < 0) {

      uVar2 = -uVar2;

    }

    uVar9 = (uVar2 & 0xffff) * (uVar6 & 0xffff);

    iVar5 = (uVar2 >> 0x10) * (uVar6 & 0xffff);

    iVar3 = 0;

    uVar4 = iVar5 + (uVar2 & 0xffff) * (uVar6 >> 0x10);

    if (iVar5 != 0) {

      iVar3 = 0x10000;

    }

    uVar12 = uVar9 + (uVar4 << 16);

    uVar2 = iVar3 + (unsigned int)(uVar12 < uVar9) + (uVar4 >> 0x10) + (uVar2 >> 0x10) * (uVar6 >> 0x10);

    if ((int)-(unsigned int)((int)uVar17 < 0) < 0) {

      uVar2 = ~uVar2;

      if (uVar12 == 0) {

        uVar2 = uVar2 + 1;

      }

      else {

        uVar12 = ~uVar12 + 1;

      }

    }

    if (((unsigned char)(uVar7 >> 1) & 1) == 1) {

      uVar12 = uVar8 + uVar12;

      uVar18 = uVar2 + (uVar12 < uVar8) + (uVar18 & 0xffff);

      if ((int)uVar18 < -0x8000) {

        uVar18 = 0xffff8000;

        uVar12 = 0;

      }

      if (0x7fff < (int)uVar18) {

        uVar18 = 0x7fff;

        uVar12 = 0xffffffff;

      }

      uVar18 = uVar18 & 0xffff;

    }

    else {

      uVar12 = uVar8 + uVar12;

      uVar18 = uVar2 + (uVar12 < uVar8) + uVar18;

    }

    uVar6 = *(unsigned int *)(puVar1 + 8);

    uVar2 = puVar10[2];

    uVar17 = uVar6 ^ uVar2;

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    if ((int)uVar2 < 0) {

      uVar2 = -uVar2;

    }

    uVar8 = (uVar2 & 0xffff) * (uVar6 & 0xffff);

    iVar5 = (uVar2 >> 0x10) * (uVar6 & 0xffff);

    iVar3 = 0;

    uVar4 = iVar5 + (uVar2 & 0xffff) * (uVar6 >> 0x10);

    if (iVar5 != 0) {

      iVar3 = 0x10000;

    }

    uVar9 = uVar8 + (uVar4 << 16);

    uVar2 = iVar3 + (unsigned int)(uVar9 < uVar8) + (uVar4 >> 0x10) + (uVar2 >> 0x10) * (uVar6 >> 0x10);

    if ((int)-(unsigned int)((int)uVar17 < 0) < 0) {

      uVar2 = ~uVar2;

      if (uVar9 == 0) {

        uVar2 = uVar2 + 1;

      }

      else {

        uVar9 = ~uVar9 + 1;

      }

    }

    if (((unsigned char)(uVar7 >> 1) & 1) == 1) {

      uVar9 = uVar12 + uVar9;

      uVar18 = uVar2 + (uVar9 < uVar12) + (uVar18 & 0xffff);

      if ((int)uVar18 < -0x8000) {

        uVar18 = 0xffff8000;

        uVar9 = 0;

      }

      if (0x7fff < (int)uVar18) {

        uVar18 = 0x7fff;

        uVar9 = 0xffffffff;

      }

      uVar18 = uVar18 & 0xffff;

    }

    else {

      uVar9 = uVar12 + uVar9;

      uVar18 = uVar2 + (uVar9 < uVar12) + uVar18;

    }

    uVar2 = uVar18 << 0x10 | uVar9 >> 0x10;

    uVar16 = uVar16 | 0 < (int)uVar2;

    uVar18 = uVar16;

    if (((unsigned char)uVar16 & 1) != 1) goto LAB_06031cf2;

  }

  uVar2 = puVar10[1];

  uVar18 = *puVar10;

  uVar6 = puVar15[7];

  piVar11 = (int *)(0x06094FA8 + (unsigned int)*(unsigned short *)((int)puVar13 + -6) * 0xc);

  uVar7 = piVar11[2];

  puVar15[4] = (int)DAT_06031b22;

  *puVar15 = uVar7;

  puVar15[5] = 0;

  *unaff_r11 = (unsigned int)((unsigned long long)((long long)(int)uVar6 * (long long)(int)uVar18) >> 0x20);

  unaff_r11[1] = (unsigned int)((unsigned long long)((long long)(int)uVar6 * (long long)(int)-uVar2) >> 0x20);

  puVar10 = unaff_r11;

  uVar2 = FUN_06031d1a();

  uVar18 = uVar16 & 0xfffffffe | (unsigned int)(0 < (int)extraout_r3);

  if (((unsigned char)uVar18 & 1) == 1) {

    unaff_r13[1] = extraout_r3;

    puVar14 = puVar10 + 2;

    iVar5 = piVar11[1];

    iVar3 = *piVar11;

    uVar2 = puVar15[7];

    piVar11 = (int *)(0x06094FA8 + (unsigned int)*(unsigned short *)(puVar13 + -1) * 0xc);

    uVar16 = piVar11[2];

    puVar15[4] = (int)PTR_DAT_06031b64;

    *puVar15 = uVar16;

    puVar15[5] = 0;

    *puVar14 = (unsigned int)((unsigned long long)((long long)(int)uVar2 * (long long)iVar3) >> 0x20);

    puVar10[3] = (unsigned int)((unsigned long long)((long long)(int)uVar2 * (long long)-iVar5) >> 0x20);

    uVar2 = FUN_06031d1a();

    uVar18 = uVar18 & 0xfffffffe | (unsigned int)(0 < (int)extraout_r3_00);

    if (((unsigned char)uVar18 & 1) == 1) {

      unaff_r13[2] = extraout_r3_00;

      puVar10 = puVar14 + 2;

      iVar5 = piVar11[1];

      iVar3 = *piVar11;

      uVar2 = puVar15[7];

      piVar11 = (int *)(0x06094FA8 + (unsigned int)*(unsigned short *)((int)puVar13 + -2) * 0xc);

      uVar16 = piVar11[2];

      puVar15[4] = (int)PTR_DAT_06031ba8;

      *puVar15 = uVar16;

      puVar15[5] = 0;

      *puVar10 = (unsigned int)((unsigned long long)((long long)(int)uVar2 * (long long)iVar3) >> 0x20);

      puVar14[3] = (unsigned int)((unsigned long long)((long long)(int)uVar2 * (long long)-iVar5) >> 0x20);

      uVar2 = FUN_06031d1a();

      uVar18 = uVar18 & 0xfffffffe | (unsigned int)(0 < (int)extraout_r3_01);

      if (((unsigned char)uVar18 & 1) == 1) {

        unaff_r13[3] = extraout_r3_01;

        iVar3 = piVar11[1];

        uVar16 = puVar15[7];

        puVar10[2] = (unsigned int)((unsigned long long)((long long)(int)uVar16 * (long long)*piVar11) >> 0x20);

        puVar10[3] = (unsigned int)((unsigned long long)((long long)(int)uVar16 * (long long)-iVar3) >> 0x20);

        FUN_06031d1a();

        puVar1 = (char *)0x0608AC20;

        iVar3 = *(int *)0x060620D0;

        iVar5 = (int)DAT_06031bf8;

        uVar2 = *unaff_r11;

        uVar16 = unaff_r11[2];

        uVar7 = unaff_r11[4];

        uVar6 = unaff_r11[6];

        uVar18 = uVar18 & 0xfffffffe;

        if ((((iVar5 <= (int)uVar2) || (iVar5 <= (int)uVar16)) || (iVar5 <= (int)uVar7)) ||

           (iVar5 <= (int)uVar6)) {

          iVar5 = (int)DAT_06031c7c;

          uVar17 = uVar18 | (int)uVar2 < iVar5;

          if (((((unsigned char)uVar17 & 1) == 1) ||

              (uVar17 = uVar18 | (int)uVar16 < iVar5, ((unsigned char)uVar17 & 1) == 1)) ||

             ((uVar17 = uVar18 | (int)uVar7 < iVar5, ((unsigned char)uVar17 & 1) == 1 ||

              (uVar17 = uVar18 | (int)uVar6 < iVar5, uVar18 = uVar17, ((unsigned char)uVar17 & 1) != 1)))) {

            iVar5 = (int)DAT_06031c7e;

            uVar4 = unaff_r11[1];

            uVar8 = unaff_r11[3];

            uVar9 = unaff_r11[5];

            uVar12 = unaff_r11[7];

            uVar18 = uVar17 & 0xfffffffe;

            if (((iVar5 <= (int)uVar4) || (iVar5 <= (int)uVar8)) ||

               ((iVar5 <= (int)uVar9 ||

                (uVar18 = uVar18 | (int)uVar12 < iVar5, ((unsigned char)uVar18 & 1) != 1)))) {

              iVar5 = (int)PTR_DAT_06031c80;

              if (((((int)uVar4 < iVar5) || ((int)uVar8 < iVar5)) || ((int)uVar9 < iVar5)) ||

                 (uVar18 = uVar18 & 0xfffffffe, (int)uVar12 < iVar5)) {

                *(short *)(0x0608AC20 + iVar3 * 0x18 + 0x16) = (short)uVar12;

                *(short *)(puVar1 + iVar3 * 0x18 + 0x14) = (short)uVar6;

                *(short *)(puVar1 + iVar3 * 0x18 + 0x12) = (short)uVar9;

                *(short *)(puVar1 + iVar3 * 0x18 + 0x10) = (short)uVar7;

                *(short *)(puVar1 + iVar3 * 0x18 + 0xe) = (short)uVar8;

                *(short *)(puVar1 + iVar3 * 0x18 + 0xc) = (short)uVar16;

                *(short *)(puVar1 + iVar3 * 0x18 + 10) = (short)uVar4;

                *(short *)(puVar1 + iVar3 * 0x18 + 8) = (short)uVar2;

                *(short *)(puVar1 + iVar3 * 0x18 + 6) = *(short *)((int)puVar13 + -10);

                puVar1[iVar3 * 0x18 + 4] = (unsigned char)((unsigned int)(int)*(short *)(puVar13 + -3) >> 4) & 0xf;

                puVar1[iVar3 * 0x18 + 5] = unaff_r10;

                uVar18 = (*(int(*)())(*(int *)(0x06031D78 + ((int)*(short *)(puVar13 + -3) & 7U) << 2)))(unaff_r13[1],unaff_r13[2],unaff_r13[3]);

                return uVar18;

              }

            }

          }

        }

      }

    }

  }

  goto LAB_06031cf2;

}

void FUN_06031d8c(param_1, param_2)
    unsigned int *param_1;
    int param_2;
{

  unsigned int uVar1;

  int iVar2;

  int iVar3;

  unsigned int uVar4;

  unsigned int uVar5;

  int *piVar6;

  unsigned int *puVar7;

  unsigned int in_sr = 0;

  unsigned int uVar8;

  unsigned int uVar9;

  unsigned int uVar10;

  unsigned int uVar11;

  unsigned int uVar12;

  unsigned int uVar13;

  unsigned int uVar14;

  unsigned int uVar15;

  unsigned int uVar16;

  unsigned int uVar17;

  unsigned int uVar18;

  puVar7 = (unsigned int *)OBJ_STATE_PRIMARY;

  piVar6 = (int *)0x06094FA8;

  do {

    uVar9 = *puVar7;

    uVar8 = *param_1;

    uVar10 = uVar9 ^ uVar8;

    if ((int)uVar9 < 0) {

      uVar9 = -uVar9;

    }

    if ((int)uVar8 < 0) {

      uVar8 = -uVar8;

    }

    uVar4 = (uVar8 & 0xffff) * (uVar9 & 0xffff);

    iVar3 = (uVar8 >> 0x10) * (uVar9 & 0xffff);

    iVar2 = 0;

    uVar1 = iVar3 + (uVar8 & 0xffff) * (uVar9 >> 0x10);

    if (iVar3 != 0) {

      iVar2 = 0x10000;

    }

    uVar11 = uVar4 + (uVar1 << 16);

    uVar8 = iVar2 + (unsigned int)(uVar11 < uVar4) + (uVar1 >> 0x10) + (uVar8 >> 0x10) * (uVar9 >> 0x10);

    if ((int)-(unsigned int)((int)uVar10 < 0) < 0) {

      uVar8 = ~uVar8;

      if (uVar11 == 0) {

        uVar8 = uVar8 + 1;

      }

      else {

        uVar11 = ~uVar11 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      if ((int)uVar8 < -0x8000) {

        uVar8 = 0xffff8000;

        uVar11 = 0;

      }

      if (0x7fff < (int)uVar8) {

        uVar8 = 0x7fff;

        uVar11 = 0xffffffff;

      }

      uVar8 = uVar8 & 0xffff;

    }

    uVar10 = puVar7[1];

    uVar9 = param_1[1];

    uVar1 = uVar10 ^ uVar9;

    if ((int)uVar10 < 0) {

      uVar10 = -uVar10;

    }

    if ((int)uVar9 < 0) {

      uVar9 = -uVar9;

    }

    uVar5 = (uVar9 & 0xffff) * (uVar10 & 0xffff);

    iVar3 = (uVar9 >> 0x10) * (uVar10 & 0xffff);

    iVar2 = 0;

    uVar4 = iVar3 + (uVar9 & 0xffff) * (uVar10 >> 0x10);

    if (iVar3 != 0) {

      iVar2 = 0x10000;

    }

    uVar13 = uVar5 + (uVar4 << 16);

    uVar9 = iVar2 + (unsigned int)(uVar13 < uVar5) + (uVar4 >> 0x10) + (uVar9 >> 0x10) * (uVar10 >> 0x10);

    if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

      uVar9 = ~uVar9;

      if (uVar13 == 0) {

        uVar9 = uVar9 + 1;

      }

      else {

        uVar13 = ~uVar13 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      uVar13 = uVar11 + uVar13;

      uVar8 = uVar9 + (uVar13 < uVar11) + (uVar8 & 0xffff);

      if ((int)uVar8 < -0x8000) {

        uVar8 = 0xffff8000;

        uVar13 = 0;

      }

      if (0x7fff < (int)uVar8) {

        uVar8 = 0x7fff;

        uVar13 = 0xffffffff;

      }

      uVar8 = uVar8 & 0xffff;

    }

    else {

      uVar13 = uVar11 + uVar13;

      uVar8 = uVar9 + (uVar13 < uVar11) + uVar8;

    }

    uVar4 = puVar7[9];

    uVar10 = puVar7[2];

    uVar9 = param_1[2];

    uVar1 = uVar10 ^ uVar9;

    if ((int)uVar10 < 0) {

      uVar10 = -uVar10;

    }

    if ((int)uVar9 < 0) {

      uVar9 = -uVar9;

    }

    uVar5 = (uVar9 & 0xffff) * (uVar10 & 0xffff);

    iVar3 = (uVar9 >> 0x10) * (uVar10 & 0xffff);

    iVar2 = 0;

    uVar11 = iVar3 + (uVar9 & 0xffff) * (uVar10 >> 0x10);

    if (iVar3 != 0) {

      iVar2 = 0x10000;

    }

    uVar12 = uVar5 + (uVar11 << 16);

    uVar9 = iVar2 + (unsigned int)(uVar12 < uVar5) + (uVar11 >> 0x10) + (uVar9 >> 0x10) * (uVar10 >> 0x10);

    if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

      uVar9 = ~uVar9;

      if (uVar12 == 0) {

        uVar9 = uVar9 + 1;

      }

      else {

        uVar12 = ~uVar12 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      uVar12 = uVar13 + uVar12;

      uVar8 = uVar9 + (uVar12 < uVar13) + (uVar8 & 0xffff);

      if ((int)uVar8 < -0x8000) {

        uVar8 = 0xffff8000;

        uVar12 = 0;

      }

      if (0x7fff < (int)uVar8) {

        uVar8 = 0x7fff;

        uVar12 = 0xffffffff;

      }

      uVar8 = uVar8 & 0xffff;

    }

    else {

      uVar12 = uVar13 + uVar12;

      uVar8 = uVar9 + (uVar12 < uVar13) + uVar8;

    }

    uVar10 = puVar7[3];

    uVar9 = *param_1;

    uVar1 = uVar10 ^ uVar9;

    if ((int)uVar10 < 0) {

      uVar10 = -uVar10;

    }

    if ((int)uVar9 < 0) {

      uVar9 = -uVar9;

    }

    uVar5 = (uVar9 & 0xffff) * (uVar10 & 0xffff);

    iVar3 = (uVar9 >> 0x10) * (uVar10 & 0xffff);

    iVar2 = 0;

    uVar11 = iVar3 + (uVar9 & 0xffff) * (uVar10 >> 0x10);

    if (iVar3 != 0) {

      iVar2 = 0x10000;

    }

    uVar13 = uVar5 + (uVar11 << 16);

    uVar9 = iVar2 + (unsigned int)(uVar13 < uVar5) + (uVar11 >> 0x10) + (uVar9 >> 0x10) * (uVar10 >> 0x10);

    if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

      uVar9 = ~uVar9;

      if (uVar13 == 0) {

        uVar9 = uVar9 + 1;

      }

      else {

        uVar13 = ~uVar13 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      if ((int)uVar9 < -0x8000) {

        uVar9 = 0xffff8000;

        uVar13 = 0;

      }

      if (0x7fff < (int)uVar9) {

        uVar9 = 0x7fff;

        uVar13 = 0xffffffff;

      }

      uVar9 = uVar9 & 0xffff;

    }

    uVar1 = puVar7[4];

    uVar10 = param_1[1];

    uVar11 = uVar1 ^ uVar10;

    if ((int)uVar1 < 0) {

      uVar1 = -uVar1;

    }

    if ((int)uVar10 < 0) {

      uVar10 = -uVar10;

    }

    uVar15 = (uVar10 & 0xffff) * (uVar1 & 0xffff);

    iVar3 = (uVar10 >> 0x10) * (uVar1 & 0xffff);

    iVar2 = 0;

    uVar5 = iVar3 + (uVar10 & 0xffff) * (uVar1 >> 0x10);

    if (iVar3 != 0) {

      iVar2 = 0x10000;

    }

    uVar14 = uVar15 + (uVar5 << 16);

    uVar10 = iVar2 + (unsigned int)(uVar14 < uVar15) + (uVar5 >> 0x10) + (uVar10 >> 0x10) * (uVar1 >> 0x10);

    if ((int)-(unsigned int)((int)uVar11 < 0) < 0) {

      uVar10 = ~uVar10;

      if (uVar14 == 0) {

        uVar10 = uVar10 + 1;

      }

      else {

        uVar14 = ~uVar14 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      uVar14 = uVar13 + uVar14;

      uVar9 = uVar10 + (uVar14 < uVar13) + (uVar9 & 0xffff);

      if ((int)uVar9 < -0x8000) {

        uVar9 = 0xffff8000;

        uVar14 = 0;

      }

      if (0x7fff < (int)uVar9) {

        uVar9 = 0x7fff;

        uVar14 = 0xffffffff;

      }

      uVar9 = uVar9 & 0xffff;

    }

    else {

      uVar14 = uVar13 + uVar14;

      uVar9 = uVar10 + (uVar14 < uVar13) + uVar9;

    }

    uVar1 = puVar7[5];

    uVar10 = param_1[2];

    uVar11 = uVar1 ^ uVar10;

    if ((int)uVar1 < 0) {

      uVar1 = -uVar1;

    }

    if ((int)uVar10 < 0) {

      uVar10 = -uVar10;

    }

    uVar13 = (uVar10 & 0xffff) * (uVar1 & 0xffff);

    iVar3 = (uVar10 >> 0x10) * (uVar1 & 0xffff);

    iVar2 = 0;

    uVar5 = iVar3 + (uVar10 & 0xffff) * (uVar1 >> 0x10);

    if (iVar3 != 0) {

      iVar2 = 0x10000;

    }

    uVar15 = uVar13 + (uVar5 << 16);

    uVar10 = iVar2 + (unsigned int)(uVar15 < uVar13) + (uVar5 >> 0x10) + (uVar10 >> 0x10) * (uVar1 >> 0x10);

    if ((int)-(unsigned int)((int)uVar11 < 0) < 0) {

      uVar10 = ~uVar10;

      if (uVar15 == 0) {

        uVar10 = uVar10 + 1;

      }

      else {

        uVar15 = ~uVar15 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      uVar15 = uVar14 + uVar15;

      uVar9 = uVar10 + (uVar15 < uVar14) + (uVar9 & 0xffff);

      if ((int)uVar9 < -0x8000) {

        uVar9 = 0xffff8000;

        uVar15 = 0;

      }

      if (0x7fff < (int)uVar9) {

        uVar9 = 0x7fff;

        uVar15 = 0xffffffff;

      }

      uVar9 = uVar9 & 0xffff;

    }

    else {

      uVar15 = uVar14 + uVar15;

      uVar9 = uVar10 + (uVar15 < uVar14) + uVar9;

    }

    uVar5 = puVar7[10];

    uVar1 = puVar7[6];

    uVar10 = *param_1;

    uVar11 = uVar1 ^ uVar10;

    if ((int)uVar1 < 0) {

      uVar1 = -uVar1;

    }

    if ((int)uVar10 < 0) {

      uVar10 = -uVar10;

    }

    uVar14 = (uVar10 & 0xffff) * (uVar1 & 0xffff);

    iVar3 = (uVar10 >> 0x10) * (uVar1 & 0xffff);

    iVar2 = 0;

    uVar13 = iVar3 + (uVar10 & 0xffff) * (uVar1 >> 0x10);

    if (iVar3 != 0) {

      iVar2 = 0x10000;

    }

    uVar16 = uVar14 + (uVar13 << 16);

    uVar10 = iVar2 + (unsigned int)(uVar16 < uVar14) + (uVar13 >> 0x10) + (uVar10 >> 0x10) * (uVar1 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar11 < 0) < 0) {

      uVar10 = ~uVar10;

      if (uVar16 == 0) {

        uVar10 = uVar10 + 1;

      }

      else {

        uVar16 = ~uVar16 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      if ((int)uVar10 < -0x8000) {

        uVar10 = 0xffff8000;

        uVar16 = 0;

      }

      if (0x7fff < (int)uVar10) {

        uVar10 = 0x7fff;

        uVar16 = 0xffffffff;

      }

      uVar10 = uVar10 & 0xffff;

    }

    uVar11 = puVar7[7];

    uVar1 = param_1[1];

    uVar13 = uVar11 ^ uVar1;

    if ((int)uVar11 < 0) {

      uVar11 = -uVar11;

    }

    if ((int)uVar1 < 0) {

      uVar1 = -uVar1;

    }

    uVar18 = (uVar1 & 0xffff) * (uVar11 & 0xffff);

    iVar3 = (uVar1 >> 0x10) * (uVar11 & 0xffff);

    iVar2 = 0;

    uVar14 = iVar3 + (uVar1 & 0xffff) * (uVar11 >> 0x10);

    if (iVar3 != 0) {

      iVar2 = 0x10000;

    }

    uVar17 = uVar18 + (uVar14 << 16);

    uVar1 = iVar2 + (unsigned int)(uVar17 < uVar18) + (uVar14 >> 0x10) + (uVar1 >> 0x10) * (uVar11 >> 0x10);

    if ((int)-(unsigned int)((int)uVar13 < 0) < 0) {

      uVar1 = ~uVar1;

      if (uVar17 == 0) {

        uVar1 = uVar1 + 1;

      }

      else {

        uVar17 = ~uVar17 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      uVar17 = uVar16 + uVar17;

      uVar10 = uVar1 + (uVar17 < uVar16) + (uVar10 & 0xffff);

      if ((int)uVar10 < -0x8000) {

        uVar10 = 0xffff8000;

        uVar17 = 0;

      }

      if (0x7fff < (int)uVar10) {

        uVar10 = 0x7fff;

        uVar17 = 0xffffffff;

      }

      uVar10 = uVar10 & 0xffff;

    }

    else {

      uVar17 = uVar16 + uVar17;

      uVar10 = uVar1 + (uVar17 < uVar16) + uVar10;

    }

    param_2 = param_2 + -1;

    uVar11 = puVar7[8];

    uVar1 = param_1[2];

    param_1 = param_1 + 3;

    uVar13 = uVar11 ^ uVar1;

    if ((int)uVar11 < 0) {

      uVar11 = -uVar11;

    }

    if ((int)uVar1 < 0) {

      uVar1 = -uVar1;

    }

    uVar16 = (uVar1 & 0xffff) * (uVar11 & 0xffff);

    iVar3 = (uVar1 >> 0x10) * (uVar11 & 0xffff);

    iVar2 = 0;

    uVar14 = iVar3 + (uVar1 & 0xffff) * (uVar11 >> 0x10);

    if (iVar3 != 0) {

      iVar2 = 0x10000;

    }

    uVar18 = uVar16 + (uVar14 << 16);

    uVar1 = iVar2 + (unsigned int)(uVar18 < uVar16) + (uVar14 >> 0x10) + (uVar1 >> 0x10) * (uVar11 >> 0x10);

    if ((int)-(unsigned int)((int)uVar13 < 0) < 0) {

      uVar1 = ~uVar1;

      if (uVar18 == 0) {

        uVar1 = uVar1 + 1;

      }

      else {

        uVar18 = ~uVar18 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      uVar18 = uVar17 + uVar18;

      uVar10 = uVar1 + (uVar18 < uVar17) + (uVar10 & 0xffff);

      if ((int)uVar10 < -0x8000) {

        uVar10 = 0xffff8000;

        uVar18 = 0;

      }

      if (0x7fff < (int)uVar10) {

        uVar10 = 0x7fff;

        uVar18 = 0xffffffff;

      }

      uVar10 = uVar10 & 0xffff;

    }

    else {

      uVar18 = uVar17 + uVar18;

      uVar10 = uVar1 + (uVar18 < uVar17) + uVar10;

    }

    piVar6[2] = (uVar10 << 0x10 | uVar18 >> 0x10) + puVar7[0xb];

    *piVar6 = (uVar8 << 0x10 | uVar12 >> 0x10) + uVar4;

    piVar6[1] = (uVar9 << 0x10 | uVar15 >> 0x10) + uVar5;

    piVar6 = piVar6 + 3;

    in_sr = in_sr & 0xfffffffe;

  } while (param_2 != 0);

  return;

}

unsigned int FUN_06031df4(param_1, param_2, param_3)
    int param_1;
    char param_2;
    int param_3;
{

  unsigned int uVar1;

  char *puVar2;

  char *puVar3;

  unsigned int uVar4;

  int iVar5;

  int iVar6;

  unsigned int uVar7;

  int extraout_r3 = 0;

  int extraout_r3_00;

  int extraout_r3_01;

  int iVar8;

  unsigned int uVar9;

  int iVar10;

  char *puVar11;

  int *puVar12;

  int *puVar13;

  int iVar14;

  int iVar15;

  unsigned int *puVar16;

  int *piVar17;

  int iVar18;

  unsigned int *puVar19;

  unsigned int *puVar21;

  unsigned int *puVar22;

  int iVar23;

  int iVar24;

  unsigned int in_sr = 0;

  unsigned int uVar25;

  unsigned int uVar26;

  unsigned int uVar27;

  unsigned int uVar28;

  unsigned int uVar29;

  unsigned int *puVar20;

  puVar3 = (char *)0x06032108;

  puVar2 = (char *)0x06032128;

  puVar19 = (unsigned int *)(param_1 + param_3 * 0x18);

  do {

    puVar20 = puVar19 + -6;

    uVar4 = (unsigned int)(short)*(unsigned short *)(puVar19 + -2);

    puVar22 = (unsigned int *)-256;

    puVar16 = (unsigned int *)(0x060961A8 + (unsigned int)*(unsigned short *)(puVar19 + -2) * 0xc);

    uVar7 = puVar16[2];

    uVar26 = in_sr & 0xfffffffe;

    uVar25 = uVar26 | 0 < (int)uVar7;

    if (((unsigned char)uVar25 & 1) == 1) {

      puVar22[4] = 0xa0;

      *puVar22 = uVar7;

      puVar22[5] = 0;

      *(unsigned int *)puVar2 = uVar7;

      puVar11 = (char *)0x06032138;

      if ((puVar19[-3] & 0x80000) == 0) {

        puVar21 = *(unsigned int **)0x0608A52C;

        uVar4 = *puVar21;

        uVar25 = *puVar20;

        uVar7 = uVar4 ^ uVar25;

        if ((int)uVar4 < 0) {

          uVar4 = -uVar4;

        }

        if ((int)uVar25 < 0) {

          uVar25 = -uVar25;

        }

        uVar1 = (uVar25 & 0xffff) * (uVar4 & 0xffff);

        iVar6 = (uVar25 >> 0x10) * (uVar4 & 0xffff);

        iVar5 = 0;

        uVar9 = iVar6 + (uVar25 & 0xffff) * (uVar4 >> 0x10);

        if (iVar6 != 0) {

          iVar5 = 0x10000;

        }

        uVar27 = uVar1 + (uVar9 << 16);

        uVar25 = iVar5 + (unsigned int)(uVar27 < uVar1) + (uVar9 >> 0x10) +

                 (uVar25 >> 0x10) * (uVar4 >> 0x10);

        if ((int)-(unsigned int)((int)uVar7 < 0) < 0) {

          uVar25 = ~uVar25;

          if (uVar27 == 0) {

            uVar25 = uVar25 + 1;

          }

          else {

            uVar27 = ~uVar27 + 1;

          }

        }

        if (((unsigned char)(in_sr >> 1) & 1) == 1) {

          if ((int)uVar25 < -0x8000) {

            uVar25 = 0xffff8000;

            uVar27 = 0;

          }

          if (0x7fff < (int)uVar25) {

            uVar25 = 0x7fff;

            uVar27 = 0xffffffff;

          }

          uVar25 = uVar25 & 0xffff;

        }

        uVar7 = puVar21[1];

        uVar4 = puVar19[-5];

        uVar9 = uVar7 ^ uVar4;

        if ((int)uVar7 < 0) {

          uVar7 = -uVar7;

        }

        if ((int)uVar4 < 0) {

          uVar4 = -uVar4;

        }

        uVar29 = (uVar4 & 0xffff) * (uVar7 & 0xffff);

        iVar6 = (uVar4 >> 0x10) * (uVar7 & 0xffff);

        iVar5 = 0;

        uVar1 = iVar6 + (uVar4 & 0xffff) * (uVar7 >> 0x10);

        if (iVar6 != 0) {

          iVar5 = 0x10000;

        }

        uVar28 = uVar29 + (uVar1 << 16);

        uVar4 = iVar5 + (unsigned int)(uVar28 < uVar29) + (uVar1 >> 0x10) +

                (uVar4 >> 0x10) * (uVar7 >> 0x10);

        if ((int)-(unsigned int)((int)uVar9 < 0) < 0) {

          uVar4 = ~uVar4;

          if (uVar28 == 0) {

            uVar4 = uVar4 + 1;

          }

          else {

            uVar28 = ~uVar28 + 1;

          }

        }

        if (((unsigned char)(in_sr >> 1) & 1) == 1) {

          uVar28 = uVar27 + uVar28;

          uVar25 = uVar4 + (uVar28 < uVar27) + (uVar25 & 0xffff);

          if ((int)uVar25 < -0x8000) {

            uVar25 = 0xffff8000;

            uVar28 = 0;

          }

          if (0x7fff < (int)uVar25) {

            uVar25 = 0x7fff;

            uVar28 = 0xffffffff;

          }

          uVar25 = uVar25 & 0xffff;

        }

        else {

          uVar28 = uVar27 + uVar28;

          uVar25 = uVar4 + (uVar28 < uVar27) + uVar25;

        }

        uVar7 = puVar21[2];

        uVar4 = puVar19[-4];

        uVar9 = uVar7 ^ uVar4;

        if ((int)uVar7 < 0) {

          uVar7 = -uVar7;

        }

        if ((int)uVar4 < 0) {

          uVar4 = -uVar4;

        }

        uVar27 = (uVar4 & 0xffff) * (uVar7 & 0xffff);

        iVar6 = (uVar4 >> 0x10) * (uVar7 & 0xffff);

        iVar5 = 0;

        uVar1 = iVar6 + (uVar4 & 0xffff) * (uVar7 >> 0x10);

        if (iVar6 != 0) {

          iVar5 = 0x10000;

        }

        uVar29 = uVar27 + (uVar1 << 16);

        uVar4 = iVar5 + (unsigned int)(uVar29 < uVar27) + (uVar1 >> 0x10) +

                (uVar4 >> 0x10) * (uVar7 >> 0x10);

        if ((int)-(unsigned int)((int)uVar9 < 0) < 0) {

          uVar4 = ~uVar4;

          if (uVar29 == 0) {

            uVar4 = uVar4 + 1;

          }

          else {

            uVar29 = ~uVar29 + 1;

          }

        }

        if (((unsigned char)(in_sr >> 1) & 1) == 1) {

          uVar29 = uVar28 + uVar29;

          uVar25 = uVar4 + (uVar29 < uVar28) + (uVar25 & 0xffff);

          if ((int)uVar25 < -0x8000) {

            uVar25 = 0xffff8000;

            uVar29 = 0;

          }

          if (0x7fff < (int)uVar25) {

            uVar25 = 0x7fff;

            uVar29 = 0xffffffff;

          }

          uVar25 = uVar25 & 0xffff;

        }

        else {

          uVar29 = uVar28 + uVar29;

          uVar25 = uVar4 + (uVar29 < uVar28) + uVar25;

        }

        uVar7 = puVar21[3];

        uVar4 = *puVar20;

        uVar9 = uVar7 ^ uVar4;

        if ((int)uVar7 < 0) {

          uVar7 = -uVar7;

        }

        if ((int)uVar4 < 0) {

          uVar4 = -uVar4;

        }

        uVar27 = (uVar4 & 0xffff) * (uVar7 & 0xffff);

        iVar6 = (uVar4 >> 0x10) * (uVar7 & 0xffff);

        iVar5 = 0;

        uVar1 = iVar6 + (uVar4 & 0xffff) * (uVar7 >> 0x10);

        if (iVar6 != 0) {

          iVar5 = 0x10000;

        }

        uVar28 = uVar27 + (uVar1 << 16);

        uVar4 = iVar5 + (unsigned int)(uVar28 < uVar27) + (uVar1 >> 0x10) +

                (uVar4 >> 0x10) * (uVar7 >> 0x10);

        if ((int)-(unsigned int)((int)uVar9 < 0) < 0) {

          uVar4 = ~uVar4;

          if (uVar28 == 0) {

            uVar4 = uVar4 + 1;

          }

          else {

            uVar28 = ~uVar28 + 1;

          }

        }

        if (((unsigned char)(in_sr >> 1) & 1) == 1) {

          if ((int)uVar4 < -0x8000) {

            uVar4 = 0xffff8000;

            uVar28 = 0;

          }

          if (0x7fff < (int)uVar4) {

            uVar4 = 0x7fff;

            uVar28 = 0xffffffff;

          }

          uVar4 = uVar4 & 0xffff;

        }

        *(unsigned int *)0x06032138 = uVar25 << 0x10 | uVar29 >> 0x10;

        uVar7 = puVar21[4];

        uVar25 = puVar19[-5];

        uVar9 = uVar7 ^ uVar25;

        if ((int)uVar7 < 0) {

          uVar7 = -uVar7;

        }

        if ((int)uVar25 < 0) {

          uVar25 = -uVar25;

        }

        uVar27 = (uVar25 & 0xffff) * (uVar7 & 0xffff);

        iVar6 = (uVar25 >> 0x10) * (uVar7 & 0xffff);

        iVar5 = 0;

        uVar1 = iVar6 + (uVar25 & 0xffff) * (uVar7 >> 0x10);

        if (iVar6 != 0) {

          iVar5 = 0x10000;

        }

        uVar29 = uVar27 + (uVar1 << 16);

        uVar25 = iVar5 + (unsigned int)(uVar29 < uVar27) + (uVar1 >> 0x10) +

                 (uVar25 >> 0x10) * (uVar7 >> 0x10);

        if ((int)-(unsigned int)((int)uVar9 < 0) < 0) {

          uVar25 = ~uVar25;

          if (uVar29 == 0) {

            uVar25 = uVar25 + 1;

          }

          else {

            uVar29 = ~uVar29 + 1;

          }

        }

        if (((unsigned char)(in_sr >> 1) & 1) == 1) {

          uVar29 = uVar28 + uVar29;

          uVar4 = uVar25 + (uVar29 < uVar28) + (uVar4 & 0xffff);

          if ((int)uVar4 < -0x8000) {

            uVar4 = 0xffff8000;

            uVar29 = 0;

          }

          if (0x7fff < (int)uVar4) {

            uVar4 = 0x7fff;

            uVar29 = 0xffffffff;

          }

          uVar4 = uVar4 & 0xffff;

        }

        else {

          uVar29 = uVar28 + uVar29;

          uVar4 = uVar25 + (uVar29 < uVar28) + uVar4;

        }

        uVar7 = puVar21[5];

        uVar25 = puVar19[-4];

        uVar9 = uVar7 ^ uVar25;

        if ((int)uVar7 < 0) {

          uVar7 = -uVar7;

        }

        if ((int)uVar25 < 0) {

          uVar25 = -uVar25;

        }

        uVar27 = (uVar25 & 0xffff) * (uVar7 & 0xffff);

        iVar6 = (uVar25 >> 0x10) * (uVar7 & 0xffff);

        iVar5 = 0;

        uVar1 = iVar6 + (uVar25 & 0xffff) * (uVar7 >> 0x10);

        if (iVar6 != 0) {

          iVar5 = 0x10000;

        }

        uVar28 = uVar27 + (uVar1 << 16);

        uVar25 = iVar5 + (unsigned int)(uVar28 < uVar27) + (uVar1 >> 0x10) +

                 (uVar25 >> 0x10) * (uVar7 >> 0x10);

        if ((int)-(unsigned int)((int)uVar9 < 0) < 0) {

          uVar25 = ~uVar25;

          if (uVar28 == 0) {

            uVar25 = uVar25 + 1;

          }

          else {

            uVar28 = ~uVar28 + 1;

          }

        }

        if (((unsigned char)(in_sr >> 1) & 1) == 1) {

          uVar28 = uVar29 + uVar28;

          uVar4 = uVar25 + (uVar28 < uVar29) + (uVar4 & 0xffff);

          if ((int)uVar4 < -0x8000) {

            uVar4 = 0xffff8000;

            uVar28 = 0;

          }

          if (0x7fff < (int)uVar4) {

            uVar4 = 0x7fff;

            uVar28 = 0xffffffff;

          }

          uVar4 = uVar4 & 0xffff;

        }

        else {

          uVar28 = uVar29 + uVar28;

          uVar4 = uVar25 + (uVar28 < uVar29) + uVar4;

        }

        uVar7 = puVar21[6];

        uVar25 = *puVar20;

        uVar9 = uVar7 ^ uVar25;

        if ((int)uVar7 < 0) {

          uVar7 = -uVar7;

        }

        if ((int)uVar25 < 0) {

          uVar25 = -uVar25;

        }

        uVar27 = (uVar25 & 0xffff) * (uVar7 & 0xffff);

        iVar6 = (uVar25 >> 0x10) * (uVar7 & 0xffff);

        iVar5 = 0;

        uVar1 = iVar6 + (uVar25 & 0xffff) * (uVar7 >> 0x10);

        if (iVar6 != 0) {

          iVar5 = 0x10000;

        }

        uVar29 = uVar27 + (uVar1 << 16);

        uVar25 = iVar5 + (unsigned int)(uVar29 < uVar27) + (uVar1 >> 0x10) +

                 (uVar25 >> 0x10) * (uVar7 >> 0x10);

        if ((int)-(unsigned int)((int)uVar9 < 0) < 0) {

          uVar25 = ~uVar25;

          if (uVar29 == 0) {

            uVar25 = uVar25 + 1;

          }

          else {

            uVar29 = ~uVar29 + 1;

          }

        }

        if (((unsigned char)(in_sr >> 1) & 1) == 1) {

          if ((int)uVar25 < -0x8000) {

            uVar25 = 0xffff8000;

            uVar29 = 0;

          }

          if (0x7fff < (int)uVar25) {

            uVar25 = 0x7fff;

            uVar29 = 0xffffffff;

          }

          uVar25 = uVar25 & 0xffff;

        }

        *(unsigned int *)(puVar11 + 4) = uVar4 << 0x10 | uVar28 >> 0x10;

        uVar7 = puVar21[7];

        uVar4 = puVar19[-5];

        uVar9 = uVar7 ^ uVar4;

        if ((int)uVar7 < 0) {

          uVar7 = -uVar7;

        }

        if ((int)uVar4 < 0) {

          uVar4 = -uVar4;

        }

        uVar27 = (uVar4 & 0xffff) * (uVar7 & 0xffff);

        iVar6 = (uVar4 >> 0x10) * (uVar7 & 0xffff);

        iVar5 = 0;

        uVar1 = iVar6 + (uVar4 & 0xffff) * (uVar7 >> 0x10);

        if (iVar6 != 0) {

          iVar5 = 0x10000;

        }

        uVar28 = uVar27 + (uVar1 << 16);

        uVar4 = iVar5 + (unsigned int)(uVar28 < uVar27) + (uVar1 >> 0x10) +

                (uVar4 >> 0x10) * (uVar7 >> 0x10);

        if ((int)-(unsigned int)((int)uVar9 < 0) < 0) {

          uVar4 = ~uVar4;

          if (uVar28 == 0) {

            uVar4 = uVar4 + 1;

          }

          else {

            uVar28 = ~uVar28 + 1;

          }

        }

        if (((unsigned char)(in_sr >> 1) & 1) == 1) {

          uVar28 = uVar29 + uVar28;

          uVar25 = uVar4 + (uVar28 < uVar29) + (uVar25 & 0xffff);

          if ((int)uVar25 < -0x8000) {

            uVar25 = 0xffff8000;

            uVar28 = 0;

          }

          if (0x7fff < (int)uVar25) {

            uVar25 = 0x7fff;

            uVar28 = 0xffffffff;

          }

          uVar25 = uVar25 & 0xffff;

        }

        else {

          uVar28 = uVar29 + uVar28;

          uVar25 = uVar4 + (uVar28 < uVar29) + uVar25;

        }

        uVar7 = puVar21[8];

        uVar4 = puVar19[-4];

        uVar9 = uVar7 ^ uVar4;

        if ((int)uVar7 < 0) {

          uVar7 = -uVar7;

        }

        if ((int)uVar4 < 0) {

          uVar4 = -uVar4;

        }

        uVar27 = (uVar4 & 0xffff) * (uVar7 & 0xffff);

        iVar6 = (uVar4 >> 0x10) * (uVar7 & 0xffff);

        iVar5 = 0;

        uVar1 = iVar6 + (uVar4 & 0xffff) * (uVar7 >> 0x10);

        if (iVar6 != 0) {

          iVar5 = 0x10000;

        }

        uVar29 = uVar27 + (uVar1 << 16);

        uVar4 = iVar5 + (unsigned int)(uVar29 < uVar27) + (uVar1 >> 0x10) +

                (uVar4 >> 0x10) * (uVar7 >> 0x10);

        if ((int)-(unsigned int)((int)uVar9 < 0) < 0) {

          uVar4 = ~uVar4;

          if (uVar29 == 0) {

            uVar4 = uVar4 + 1;

          }

          else {

            uVar29 = ~uVar29 + 1;

          }

        }

        if (((unsigned char)(in_sr >> 1) & 1) == 1) {

          uVar29 = uVar28 + uVar29;

          uVar25 = uVar4 + (uVar29 < uVar28) + (uVar25 & 0xffff);

          if ((int)uVar25 < -0x8000) {

            uVar25 = 0xffff8000;

            uVar29 = 0;

          }

          if (0x7fff < (int)uVar25) {

            uVar25 = 0x7fff;

            uVar29 = 0xffffffff;

          }

          uVar25 = uVar25 & 0xffff;

        }

        else {

          uVar29 = uVar28 + uVar29;

          uVar25 = uVar4 + (uVar29 < uVar28) + uVar25;

        }

        *(unsigned int *)(puVar11 + 8) = uVar25 << 0x10 | uVar29 >> 0x10;

        uVar4 = *(unsigned int *)puVar11;

        uVar25 = *puVar16;

        uVar7 = uVar4 ^ uVar25;

        if ((int)uVar4 < 0) {

          uVar4 = -uVar4;

        }

        if ((int)uVar25 < 0) {

          uVar25 = -uVar25;

        }

        uVar1 = (uVar25 & 0xffff) * (uVar4 & 0xffff);

        iVar6 = (uVar25 >> 0x10) * (uVar4 & 0xffff);

        iVar5 = 0;

        uVar9 = iVar6 + (uVar25 & 0xffff) * (uVar4 >> 0x10);

        if (iVar6 != 0) {

          iVar5 = 0x10000;

        }

        uVar27 = uVar1 + (uVar9 << 16);

        uVar25 = iVar5 + (unsigned int)(uVar27 < uVar1) + (uVar9 >> 0x10) +

                 (uVar25 >> 0x10) * (uVar4 >> 0x10);

        if ((int)-(unsigned int)((int)uVar7 < 0) < 0) {

          uVar25 = ~uVar25;

          if (uVar27 == 0) {

            uVar25 = uVar25 + 1;

          }

          else {

            uVar27 = ~uVar27 + 1;

          }

        }

        if (((unsigned char)(in_sr >> 1) & 1) == 1) {

          if ((int)uVar25 < -0x8000) {

            uVar25 = 0xffff8000;

            uVar27 = 0;

          }

          if (0x7fff < (int)uVar25) {

            uVar25 = 0x7fff;

            uVar27 = 0xffffffff;

          }

          uVar25 = uVar25 & 0xffff;

        }

        uVar7 = *(unsigned int *)(puVar11 + 4);

        uVar4 = puVar16[1];

        uVar9 = uVar7 ^ uVar4;

        if ((int)uVar7 < 0) {

          uVar7 = -uVar7;

        }

        if ((int)uVar4 < 0) {

          uVar4 = -uVar4;

        }

        uVar29 = (uVar4 & 0xffff) * (uVar7 & 0xffff);

        iVar6 = (uVar4 >> 0x10) * (uVar7 & 0xffff);

        iVar5 = 0;

        uVar1 = iVar6 + (uVar4 & 0xffff) * (uVar7 >> 0x10);

        if (iVar6 != 0) {

          iVar5 = 0x10000;

        }

        uVar28 = uVar29 + (uVar1 << 16);

        uVar4 = iVar5 + (unsigned int)(uVar28 < uVar29) + (uVar1 >> 0x10) +

                (uVar4 >> 0x10) * (uVar7 >> 0x10);

        if ((int)-(unsigned int)((int)uVar9 < 0) < 0) {

          uVar4 = ~uVar4;

          if (uVar28 == 0) {

            uVar4 = uVar4 + 1;

          }

          else {

            uVar28 = ~uVar28 + 1;

          }

        }

        if (((unsigned char)(in_sr >> 1) & 1) == 1) {

          uVar28 = uVar27 + uVar28;

          uVar25 = uVar4 + (uVar28 < uVar27) + (uVar25 & 0xffff);

          if ((int)uVar25 < -0x8000) {

            uVar25 = 0xffff8000;

            uVar28 = 0;

          }

          if (0x7fff < (int)uVar25) {

            uVar25 = 0x7fff;

            uVar28 = 0xffffffff;

          }

          uVar25 = uVar25 & 0xffff;

        }

        else {

          uVar28 = uVar27 + uVar28;

          uVar25 = uVar4 + (uVar28 < uVar27) + uVar25;

        }

        uVar7 = *(unsigned int *)(puVar11 + 8);

        uVar4 = puVar16[2];

        uVar9 = uVar7 ^ uVar4;

        if ((int)uVar7 < 0) {

          uVar7 = -uVar7;

        }

        if ((int)uVar4 < 0) {

          uVar4 = -uVar4;

        }

        uVar27 = (uVar4 & 0xffff) * (uVar7 & 0xffff);

        iVar6 = (uVar4 >> 0x10) * (uVar7 & 0xffff);

        iVar5 = 0;

        uVar1 = iVar6 + (uVar4 & 0xffff) * (uVar7 >> 0x10);

        if (iVar6 != 0) {

          iVar5 = 0x10000;

        }

        uVar29 = uVar27 + (uVar1 << 16);

        uVar4 = iVar5 + (unsigned int)(uVar29 < uVar27) + (uVar1 >> 0x10) +

                (uVar4 >> 0x10) * (uVar7 >> 0x10);

        if ((int)-(unsigned int)((int)uVar9 < 0) < 0) {

          uVar4 = ~uVar4;

          if (uVar29 == 0) {

            uVar4 = uVar4 + 1;

          }

          else {

            uVar29 = ~uVar29 + 1;

          }

        }

        if (((unsigned char)(in_sr >> 1) & 1) == 1) {

          uVar29 = uVar28 + uVar29;

          uVar25 = uVar4 + (uVar29 < uVar28) + (uVar25 & 0xffff);

          if ((int)uVar25 < -0x8000) {

            uVar25 = 0xffff8000;

            uVar29 = 0;

          }

          if (0x7fff < (int)uVar25) {

            uVar25 = 0x7fff;

            uVar29 = 0xffffffff;

          }

          uVar25 = uVar25 & 0xffff;

        }

        else {

          uVar29 = uVar28 + uVar29;

          uVar25 = uVar4 + (uVar29 < uVar28) + uVar25;

        }

        uVar4 = uVar25 << 0x10 | uVar29 >> 0x10;

        uVar26 = uVar26 | 0 < (int)uVar4;

        uVar25 = uVar26;

        if (((unsigned char)uVar26 & 1) != 1) goto LAB_060320be;

      }

      uVar4 = puVar16[1];

      uVar25 = *puVar16;

      uVar9 = puVar22[7];

      piVar17 = (int *)(0x060961A8 + (unsigned int)*(unsigned short *)((int)puVar19 + -6) * 0xc);

      uVar7 = piVar17[2];

      puVar22[4] = 0xa0;

      *puVar22 = uVar7;

      puVar22[5] = 0;

      *(int *)puVar3 = (int)((unsigned long long)((long long)(int)uVar9 * (long long)(int)uVar25) >> 0x20);

      *(int *)(puVar3 + 4) =

           (int)((unsigned long long)((long long)(int)uVar9 * (long long)(int)-uVar4) >> 0x20);

      puVar11 = puVar3;

      uVar4 = FUN_060320e6();

      uVar25 = uVar26 & 0xfffffffe | (unsigned int)(0 < extraout_r3);

      if (((unsigned char)uVar25 & 1) == 1) {

        *(int *)(puVar2 + 4) = extraout_r3;

        puVar12 = (int *)(puVar11 + 8);

        iVar6 = piVar17[1];

        iVar5 = *piVar17;

        uVar4 = puVar22[7];

        piVar17 = (int *)(0x060961A8 + (unsigned int)*(unsigned short *)(puVar19 + -1) * 0xc);

        uVar26 = piVar17[2];

        puVar22[4] = 0xa0;

        *puVar22 = uVar26;

        puVar22[5] = 0;

        *puVar12 = (int)((unsigned long long)((long long)(int)uVar4 * (long long)iVar5) >> 0x20);

        *(int *)(puVar11 + 0xc) =

             (int)((unsigned long long)((long long)(int)uVar4 * (long long)-iVar6) >> 0x20);

        uVar4 = FUN_060320e6();

        uVar25 = uVar25 & 0xfffffffe | (unsigned int)(0 < extraout_r3_00);

        if (((unsigned char)uVar25 & 1) == 1) {

          *(int *)(puVar2 + 8) = extraout_r3_00;

          puVar13 = puVar12 + 2;

          iVar6 = piVar17[1];

          iVar5 = *piVar17;

          uVar4 = puVar22[7];

          piVar17 = (int *)(0x060961A8 + (unsigned int)*(unsigned short *)((int)puVar19 + -2) * 0xc);

          uVar26 = piVar17[2];

          puVar22[4] = 0xa0;

          *puVar22 = uVar26;

          puVar22[5] = 0;

          *puVar13 = (int)((unsigned long long)((long long)(int)uVar4 * (long long)iVar5) >> 0x20);

          puVar12[3] = (int)((unsigned long long)((long long)(int)uVar4 * (long long)-iVar6) >> 0x20);

          uVar4 = FUN_060320e6();

          uVar25 = uVar25 & 0xfffffffe | (unsigned int)(0 < extraout_r3_01);

          if (((unsigned char)uVar25 & 1) == 1) {

            *(int *)(puVar2 + 0xc) = extraout_r3_01;

            iVar5 = piVar17[1];

            uVar26 = puVar22[7];

            puVar13[2] = (int)((unsigned long long)((long long)(int)uVar26 * (long long)*piVar17) >> 0x20);

            puVar13[3] = (int)((unsigned long long)((long long)(int)uVar26 * (long long)-iVar5) >> 0x20);

            FUN_060320e6();

            puVar11 = (char *)0x0608AC20;

            iVar5 = *(int *)0x060620D4;

            iVar23 = -176;

            uVar4 = *(unsigned int *)puVar3;

            iVar6 = *(int *)(puVar3 + 8);

            iVar10 = *(int *)(puVar3 + 0x10);

            iVar15 = *(int *)(puVar3 + 0x18);

            uVar25 = uVar25 & 0xfffffffe;

            if ((((iVar23 <= (int)uVar4) || (iVar23 <= iVar6)) || (iVar23 <= iVar10)) ||

               (iVar23 <= iVar15)) {

              iVar23 = 0xb0;

              uVar26 = uVar25 | (int)uVar4 < iVar23;

              if (((((unsigned char)uVar26 & 1) == 1) ||

                  (uVar26 = uVar25 | iVar6 < iVar23, ((unsigned char)uVar26 & 1) == 1)) ||

                 ((uVar26 = uVar25 | iVar10 < iVar23, ((unsigned char)uVar26 & 1) == 1 ||

                  (uVar26 = uVar25 | iVar15 < iVar23, uVar25 = uVar26, ((unsigned char)uVar26 & 1) != 1)))) {

                iVar24 = -127;

                iVar23 = *(int *)(puVar3 + 4);

                iVar8 = *(int *)(puVar3 + 0xc);

                iVar14 = *(int *)(puVar3 + 0x14);

                iVar18 = *(int *)(puVar3 + 0x1c);

                uVar25 = uVar26 & 0xfffffffe;

                if (((iVar24 <= iVar23) || (iVar24 <= iVar8)) ||

                   ((iVar24 <= iVar14 ||

                    (uVar25 = uVar25 | iVar18 < iVar24, ((unsigned char)uVar25 & 1) != 1)))) {

                  iVar24 = 0x51;

                  if ((((iVar23 < iVar24) || (iVar8 < iVar24)) || (iVar14 < iVar24)) ||

                     (uVar25 = uVar25 & 0xfffffffe, iVar18 < iVar24)) {

                    *(short *)(0x0608AC20 + iVar5 * 0x18 + 0x16) = (short)iVar18;

                    *(short *)(puVar11 + iVar5 * 0x18 + 0x14) = (short)iVar15;

                    *(short *)(puVar11 + iVar5 * 0x18 + 0x12) = (short)iVar14;

                    *(short *)(puVar11 + iVar5 * 0x18 + 0x10) = (short)iVar10;

                    *(short *)(puVar11 + iVar5 * 0x18 + 0xe) = (short)iVar8;

                    *(short *)(puVar11 + iVar5 * 0x18 + 0xc) = (short)iVar6;

                    *(short *)(puVar11 + iVar5 * 0x18 + 10) = (short)iVar23;

                    *(short *)(puVar11 + iVar5 * 0x18 + 8) = (short)uVar4;

                    *(short *)(puVar11 + iVar5 * 0x18 + 6) =

                         *(short *)((int)puVar19 + -10);

                    puVar11[iVar5 * 0x18 + 4] =

                         (unsigned char)((unsigned int)(int)*(short *)(puVar19 + -3) >> 4) & 0xf;

                    puVar11[iVar5 * 0x18 + 5] = param_2;

                    uVar25 = (*(int(*)())(*(int *)(0x06032144 +

                                         ((int)*(short *)(puVar19 + -3) & 7U) << 2)))(*(int *)(puVar2 + 4),*(int *)(puVar2 + 8),

                                        *(int *)(puVar2 + 0xc));

                    return uVar25;

                  }

                }

              }

            }

          }

        }

      }

    }

LAB_060320be:

    param_3 = param_3 + -1;

    in_sr = uVar25 & 0xfffffffe | (unsigned int)(param_3 == 0);

    puVar19 = puVar20;

    if (((unsigned char)in_sr & 1) == 1) {

      return uVar4;

    }

  } while( 1 );

}
