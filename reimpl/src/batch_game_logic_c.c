#include "game.h"

extern char flag_0607887F;
extern int DAT_0600e0ea;
extern int DAT_0600e2ba;
extern int DAT_0600e2bc;
extern int DAT_0600e2be;
extern int DAT_0600e2c0;
extern int DAT_0600e2c2;
extern int DAT_0600e2c4;
extern int DAT_0600e2c6;
extern int DAT_0600e2c8;
extern int DAT_0600e2ca;
extern int DAT_0600e3e8;
extern int DAT_0600e3ea;
extern int DAT_0600e3ec;
extern int DAT_0600e3ee;
extern int DAT_0600e3f0;
extern int DAT_0600e3f2;
extern int DAT_0600e3f4;
extern int DAT_0600e3f6;
extern int DAT_0600e456;
extern int DAT_0600e522;
extern int DAT_0600e69c;
extern int DAT_0600e69e;
extern int DAT_0600e86c;
extern int DAT_0600e86e;
extern int DAT_0600e870;
extern int DAT_0600e872;
extern int DAT_0600e91e;
extern int DAT_0600e920;
extern int DAT_0600e922;
extern int DAT_0600e9e2;
extern int DAT_0600e9e4;
extern int DAT_0600e9e6;
extern int DAT_0600e9e8;
extern int DAT_0600e9ea;
extern int DAT_0600ea76;
extern int DAT_0600eafa;
extern int DAT_0600ed60;
extern int DAT_0600ed62;
extern int DAT_0600ed64;
extern int DAT_0600ed66;
extern int DAT_0600ed68;
extern int DAT_0600ed6a;
extern int DAT_0600ed6c;
extern int DAT_0600ed6e;
extern int DAT_0600ed70;
extern int DAT_0600ed72;
extern int DAT_0600ed74;
extern int DAT_0600ed76;
extern int DAT_0600ed78;
extern int DAT_0600ed7a;
extern int DAT_0600ed7c;
extern int DAT_0600ed7e;
extern int DAT_0600ed80;
extern int DAT_0600eeba;
extern int DAT_0600eebc;
extern int DAT_0600eebe;
extern int DAT_0600eec0;
extern int DAT_0600eec2;
extern int DAT_0600eec4;
extern int DAT_0600eec6;
extern int DAT_0600eec8;
extern int DAT_0600eeca;
extern int DAT_0600eecc;
extern int DAT_0600eece;
extern int DAT_0600eed0;
extern int DAT_0600eed2;
extern int DAT_0600eed4;
extern int DAT_0600eed6;
extern int DAT_0600eed8;
extern int DAT_0600eeda;
extern int DAT_0600eedc;
extern int DAT_0600eede;
extern int DAT_0600eee0;
extern int DAT_0600eee2;
extern int DAT_0600eee4;
extern int DAT_0600eee6;
extern int DAT_0600eee8;
extern int DAT_0600eeea;
extern int DAT_0600eeec;
extern int DAT_0600eeee;
extern int DAT_0600eef0;
extern int DAT_0600eef2;
extern int DAT_0600eef4;
extern int DAT_0600eef6;
extern int DAT_0600eef8;
extern int DAT_0600eefa;
extern int DAT_0600eefc;
extern int DAT_0600eefe;
extern int DAT_0600effc;
extern int DAT_0600effe;
extern int DAT_0600f000;
extern int DAT_0600f002;
extern int DAT_0600f004;
extern int DAT_0600f006;
extern int DAT_0600f008;
extern int DAT_0600f00a;
extern int DAT_0600f00c;
extern int DAT_0600f00e;
extern int DAT_0600f010;
extern int DAT_0600f012;
extern int DAT_0600f014;
extern int DAT_0600f016;
extern int DAT_0600f018;
extern int DAT_0600f01a;
extern int DAT_0600f01c;
extern int DAT_0600f01e;
extern int DAT_0600f020;
extern int DAT_0600f022;
extern int DAT_0600f024;
extern int DAT_0600f026;
extern int DAT_0600f028;
extern int DAT_0600f02a;
extern int DAT_0600f02c;
extern int DAT_0600f02e;
extern int DAT_0600f030;
extern int DAT_0600f032;
extern int DAT_0600f034;
extern int DAT_0600f036;
extern int DAT_0600f14c;
extern int DAT_0600f14e;
extern int DAT_0600f150;
extern int DAT_0600f152;
extern int DAT_0600f26a;
extern int DAT_0600f26c;
extern int DAT_0600f26e;
extern int DAT_0600f270;
extern int DAT_0600f272;
extern int DAT_0600f274;
extern int DAT_0600f276;
extern int DAT_0600f278;
extern int DAT_0600f342;
extern int DAT_0600f344;
extern int DAT_0600f346;
extern int DAT_0600f348;
extern int DAT_0600f34a;
extern int DAT_0600f462;
extern int DAT_0600f612;
extern int DAT_0600f614;
extern int DAT_0600f616;
extern int DAT_0600f618;
extern int DAT_0600f61a;
extern int DAT_06010042;
extern int DAT_06010044;
extern int DAT_06010046;
extern int DAT_060100f2;
extern int DAT_060100f4;
extern unsigned int FUN_0600e0c0();
extern void FUN_0600e71a();
extern void FUN_0600e7c8();
extern int FUN_0600e906();
extern void FUN_0600ea18();
extern unsigned int FUN_0600ffd0();
extern int FUN_060100a4();
extern int PTR_DAT_0600e3f8;
extern int PTR_DAT_0600e458;
extern int PTR_DAT_0600e874;
extern int PTR_DAT_0600e924;
extern int PTR_DAT_0600e9ec;
extern int PTR_DAT_0600ea78;
extern int PTR_DAT_0600eafc;
extern int PTR_DAT_0600f154;
extern int PTR_DAT_0600f34c;
extern int PTR_DAT_0600f520;
extern int func_06011094();
extern int func_060114AC();
extern short DAT_0600e79c;
extern short DAT_0600e79e;
extern short DAT_0600ebd8;
extern short counter_0607887C;

void FUN_0600e060()
{

  char *puVar1;

  int uVar2;

  int iVar3;

  iVar3 = CAR_PTR_TARGET;

  *(short *)0x060786CA = (short)(*(int *)0x0607EA98 >> 1);

  CAR_PTR_CURRENT = iVar3;

  *(char **)0x0607E948 = 0x06078B68;

  (*(int(*)())0x0602DC18)();

  uVar2 = (*(int(*)())0x06006838)(*(int *)(iVar3 + 0x10),*(int *)(iVar3 + 0x18));

  *(int *)0x060786B8 = uVar2;

  (*(int(*)())0x06005ECC)();

  puVar1 = (char *)0x06027CA4;

  (*(int(*)())0x06027CA4)(0x06063EB0,0);

  (*(int(*)())puVar1)(0x06063E9C,1);

  (*(int(*)())puVar1)(0x06063ED8,2);

  (*(int(*)())puVar1)(0x06063EC4,3);

  (*(int(*)())0x06033020)(iVar3 + 0x14);

  FUN_0600e0c0();

  return;

}

unsigned int FUN_0600e0c0()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  char *puVar6;

  unsigned int uVar7;

  int iVar8;

  unsigned int uVar9;

  puVar5 = (char *)0x00008000;

  puVar4 = (char *)0x06078900;

  puVar3 = (char *)0x0607EBC4;

  puVar2 = (char *)0x06027CA4;

  puVar1 = (char *)0x0607E940;

  iVar8 = 0x268;

  uVar7 = DEMO_MODE_FLAG;

  if (uVar7 == 0) {

    for (uVar9 = 1; puVar6 = 0x06030A06, uVar9 < *(unsigned int *)0x0607EA98; uVar9 = uVar9 + 1)

    {

      *(char **)puVar1 = puVar4 + uVar9 * iVar8;

      (*(int(*)())puVar6)();

      (*(int(*)())0x06030EE0)();

      if ((*(unsigned int *)puVar3 & (unsigned int)puVar5) == 0) {

        FUN_0600e71a();

        uVar7 = (unsigned int)*(char *)(*(int *)puVar1 + 1);

        if ((uVar7 & 0x80) != 0) {

          (*(int(*)())0x060061C8)();

          (*(int(*)())puVar2)(0x06063EB0,0);

          (*(int(*)())puVar2)(0x06063E9C,1);

          (*(int(*)())puVar2)(0x06063ED8,2);

          (*(int(*)())puVar2)(0x06063EC4,3);

          uVar7 = (*(int(*)())0x0603053C)(1);

        }

      }

      else {

        uVar7 = FUN_0600e906();

      }

    }

  }

  return uVar7;

}

void FUN_0600e1d4()
{

  unsigned short uVar1;

  char *puVar2;

  char *puVar3;

  int iVar4;

  int uVar5;

  int iVar6;

  unsigned int uVar7;

  int *puVar8;

  int iVar9;

  char auStack_1c [8];

  puVar3 = (char *)0x06078680;

  puVar2 = (char *)0x0607EAD8;

  iVar9 = CAR_PTR_CURRENT;

  *(int *)(iVar9 + DAT_0600e2ba) = 0;

  puVar8 = (int *)(0x06047DE4 + *(int *)(iVar9 + 4) * 0xc);

  uVar1 = *(unsigned short *)((int)puVar8 + 6);

  iVar4 = 0x1f0;

  *(unsigned int *)(iVar9 + iVar4) = (unsigned int)uVar1;

  *(unsigned int *)(iVar9 + iVar4 + -8) = (unsigned int)uVar1;

  uVar5 = (*(int(*)())0x06035C2C)();

  *(int *)(DAT_0600e2be + iVar9) = uVar5;

  *(int *)(iVar9 + DAT_0600e2c0) =

       *(int *)(0x06085FD0 + (unsigned int)*(unsigned short *)(puVar8 + 1) << 2);

  *(unsigned int *)(iVar9 + DAT_0600e2c2) = (unsigned int)*(unsigned short *)(puVar8 + 2);

  uVar7 = (unsigned int)((unsigned char *)0x06047DD0)

                      [*(int *)0x0605AD04 + (int)(char)((char)*(int *)puVar2 * '\x05')]

          + COURSE_SELECT;

  if (*(int *)0x06086030 != '\0') {

    uVar7 = (unsigned int)(unsigned char)((int *)0x06047DDF)[*(int *)puVar2];

  }

  uVar5 = (*(int(*)())0x06027552)(*(int *)(0x06047D8C + (uVar7 << 2)),*puVar8);

  *(int *)(DAT_0600e2c4 + iVar9) = uVar5;

  uVar5 = (*(int(*)())0x06027552)(*(int *)(iVar9 + DAT_0600e2c4),0x372f);

  *(int *)(DAT_0600e2c8 + iVar9) = uVar5;

  if (*(int *)(iVar9 + DAT_0600e2be) <

      (int)(*(int *)0x0607EA9C + (unsigned int)(*(int *)0x0607EA9C < 0)) >> 1) {

    *(int *)(iVar9 + DAT_0600e2ca) = 0;

  }

  else {

    *(int *)(iVar9 + DAT_0600e3e8) = 0xffffffff;

  }

  *(int *)(iVar9 + DAT_0600e3ea + -8) = *(int *)(iVar9 + DAT_0600e3ea);

  uVar7 = *(unsigned int *)(iVar9 + 4) & 1;

  if (*(int *)puVar2 == 0) {

    if (uVar7 == 0) {

      *(int *)(iVar9 + DAT_0600e3ec + 0x7c) = 0x180;

      *(char **)(iVar9 + 0xc) = 0x00042000;

      iVar6 = (int)DAT_0600e3f4;

      iVar4 = (int)DAT_0600e3f2;

      *(int *)(iVar9 + iVar4) = iVar6;

      *(int *)(iVar9 + iVar4 + -4) = iVar6;

    }

    else {

      *(int *)(iVar9 + DAT_0600e3f0) = 0x580;

      *(char **)(iVar9 + 0xc) = 0x00042E38;

    }

  }

  else {

    if (uVar7 == 0) {

      *(int *)(iVar9 + DAT_0600e3f0) = 0x580;

    }

    else {

      *(int *)(iVar9 + DAT_0600e3ec + 0x7c) = 0x180;

    }

    iVar4 = (int)DAT_0600e3f2;

    *(int *)(iVar9 + iVar4) = 0;

    *(int *)(iVar9 + iVar4 + -4) = 0;

  }

  *(int *)(iVar9 + DAT_0600e3f0 + -4) = *(int *)(iVar9 + DAT_0600e3f0);

  (*(int(*)())0x0600CA96)(puVar3);

  *(int *)(iVar9 + 0x10) = *(int *)puVar3;

  *(int *)(iVar9 + 0x18) = *(int *)(puVar3 + 8);

  if ((*(int *)(iVar9 + 4) == 0) && (*(int *)puVar2 == 2)) {

    *(short *)(puVar3 + 0xe) = DAT_0600e3f6;

  }

  uVar5 = (*(int(*)())0x06006838)(*(int *)(iVar9 + 0x10),*(int *)(iVar9 + 0x18));

  (*(int(*)())0x06027EDE)(uVar5,iVar9 + 0x10,auStack_1c);

  *(int *)(iVar9 + 0x1c) = (int)*(short *)(puVar3 + 0xc);

  *(int *)(iVar9 + 0x20) = (int)*(short *)(puVar3 + 0xe);

  *(int *)(iVar9 + 0x24) = (int)*(short *)(puVar3 + 0x10);

  *(int *)(iVar9 + 0x30) = *(int *)(iVar9 + 0x20);

  *(int *)(iVar9 + 0x34) = *(int *)(iVar9 + 0x20);

  *(int *)(iVar9 + 0x28) = *(int *)(iVar9 + 0x20);

  *(int *)(iVar9 + PTR_DAT_0600e3f8) = *(int *)(iVar9 + 0x20);

  return;

}

void FUN_0600e410()
{

  short extraout_var;

  int iVar1;

  iVar1 = CAR_PTR_TARGET;

  CAR_PTR_CURRENT = iVar1;

  (*(int(*)())0x060081F4)();

  (*(int(*)())0x060085B8)();

  (*(int(*)())0x06030A06)();

  (*(int(*)())0x06030EE0)();

  FUN_0600e71a();

  (*(int(*)())0x06027552)(*(int *)(iVar1 + 0xc),0x066505B3);

  *(int *)(DAT_0600e456 + iVar1) = (int)extraout_var;

  *(int *)(PTR_DAT_0600e458 + iVar1) = (int)extraout_var;

  return;

}

void FUN_0600e47c()
{

  char *puVar1;

  int uVar2;

  int iVar3;

  iVar3 = CAR_PTR_TARGET;

  CAR_PTR_CURRENT = iVar3;

  (*(int(*)())0x0600A8BC)();

  (*(int(*)())0x060081F4)();

  (*(int(*)())0x060085B8)();

  (*(int(*)())0x06030A06)();

  (*(int(*)())0x06030EE0)();

  FUN_0600e7c8();

  uVar2 = (*(int(*)())0x06006838)(*(int *)(iVar3 + 0x10),*(int *)(iVar3 + 0x18));

  *(int *)0x060786B8 = uVar2;

  (*(int(*)())0x06005ECC)();

  puVar1 = (char *)0x06027CA4;

  (*(int(*)())0x06027CA4)(0x06063EB0,0);

  (*(int(*)())puVar1)(0x06063E9C,1);

  (*(int(*)())puVar1)(0x06063ED8,2);

  (*(int(*)())puVar1)(0x06063EC4,3);

  (*(int(*)())0x0600DA7C)();

  (*(int(*)())0x0600CE66)();

  (*(int(*)())0x0603053C)(0);

  (*(int(*)())0x0600D780)(0);

  return;

}

void FUN_0600e4f2()
{

  int bVar1;

  char *puVar2;

  char *puVar3;

  int uVar4;

  int iVar5;

  char *puVar6;

  puVar2 = (char *)0x060786BC;

  *(short *)0x06063F44 = *(short *)0x06063D9E;

  puVar6 = *(char **)0x0607E944;

  *(char **)0x0607E940 = puVar6;

  bVar1 = puVar6 != 0x06078900;

  *(char **)0x0607E948 = 0x06078900 + DAT_0600e522;

  (*(int(*)())0x060081F4)();

  (*(int(*)())0x060085B8)();

  (*(int(*)())0x06030A06)();

  (*(int(*)())0x06030EE0)();

  if ((*(int *)puVar2 < 1) || (*(int *)0x06078635 != '\0')) {

    (*(int(*)())0x0602ECF2)();

    uVar4 = (*(int(*)())0x06006838)(*(int *)(puVar6 + 0x10),*(int *)(puVar6 + 0x18));

    *(int *)0x060786B8 = uVar4;

    (*(int(*)())0x06005ECC)();

    puVar3 = (char *)0x06027CA4;

    (*(int(*)())0x06027CA4)(0x06063EB0,0);

    (*(int(*)())puVar3)(0x06063E9C,1);

    (*(int(*)())puVar3)(0x06063ED8,2);

    (*(int(*)())puVar3)(0x06063EC4,3);

  }

  else {

    *(int *)puVar2 = *(int *)puVar2 + -1;

    *(int *)(puVar6 + 0x10) = *(int *)(puVar6 + 0x10) + *(int *)0x060786C0;

    *(int *)(puVar6 + 0x18) = *(int *)(puVar6 + 0x18) + *(int *)0x060786C4;

    iVar5 = *(int *)(puVar6 + 0x20) + (int)*(short *)0x060786C8;

    *(int *)(puVar6 + 0x20) = iVar5;

    *(int *)(puVar6 + 0x30) = iVar5;

    *(int *)(puVar6 + 0x28) = iVar5;

    *(int *)0x06063EF0 = iVar5;

    uVar4 = (*(int(*)())0x06006838)(*(int *)(puVar6 + 0x10),*(int *)(puVar6 + 0x18));

    *(int *)0x060786B8 = uVar4;

    (*(int(*)())0x06005ECC)();

  }

  *(int *)(puVar6 + DAT_0600e69c) = *(int *)(puVar6 + 0x20);

  if (!bVar1) {

    (*(int(*)())0x0600DB64)();

  }

  (*(int(*)())0x0600DA7C)();

  (*(int(*)())0x0600CE66)();

  (*(int(*)())0x0603053C)(0);

  (*(int(*)())0x0600D780)(bVar1);

  puVar3 = (char *)0x0600C994;

  iVar5 = 0x228;

  *(int *)(puVar6 + iVar5 + -0x34) =

       *(int *)(puVar6 + iVar5) * *(int *)0x0607EA9C + *(int *)(puVar6 + iVar5 + -0x3c);

  (*(int(*)())puVar3)();

  if ((*(int *)puVar2 < 1) && (*(int *)0x06078635 == '\0')) {

    FUN_0600ea18(puVar6);

  }

  if ((*(int *)0x06078635 == '\0') && (*(int *)0x06083255 == '\0')) {

    (*(int(*)())0x0602D9F0)();

    return;

  }

  return;

}

/* car_physics_update -- Per-frame car physics pipeline.
 * Runs 5 physics subsystems, processes steering correction timer,
 * and computes velocity projection for ranking:
 *   CAR_VEL_PROJ = CAR_RANKING * speed_scale + CAR_CHECKPOINT_PARAM */
void FUN_0600e71a(void)
{
    register int base asm("r14") = CAR_PTR_CURRENT;
    int tmp;

    (*(void(*)())0x06008318)();  /* collision detect */
    (*(void(*)())0x06008640)();  /* collision response */
    (*(void(*)())0x0600D266)();  /* nop (stripped) */
    (*(void(*)())0x0600C4F8)();  /* speed/accel update */
    (*(void(*)())0x0600C5D6)();  /* heading update */

    tmp = *(int *)(base + DAT_0600e79c);
    if (tmp > 0) {
        tmp--;
        *(int *)(base + DAT_0600e79c) = tmp;
        if (tmp == 0) {
            int idx = *(int *)(base + DAT_0600e79e);
            int tbl = *(int *)(base + DAT_0600e79e + -4);
            *(int *)(base + CAR_TARGET_HDG) = (int)*(short *)(idx * 0x18 + tbl + 0x14);
            *(int *)(base + CAR_STEER_CORRECT) = 0x400;
        }
    }

    (*(void(*)())0x0600CEBA)();  /* lap counting */

    *(int *)(base + CAR_VEL_PROJ) =
        *(int *)(base + CAR_RANKING) * *(int *)0x0607EA9C + *(int *)(base + CAR_CHECKPOINT_PARAM);
}

void FUN_0600e7c8()
{

  short extraout_var;

  int iVar1;

  int iVar2;

  int iVar3;

  iVar3 = CAR_PTR_CURRENT;

  (*(int(*)())0x06008318)();

  (*(int(*)())0x06008640)();

  (*(int(*)())0x0600D266)();

  (*(int(*)())0x0600C4F8)();

  (*(int(*)())0x0602D88E)();

  if (*(int *)0x06083261 == '\x01') {

    iVar1 = (int)(short)((short)((*(int *)(iVar3 + DAT_0600e86c) - *(int *)(iVar3 + 0x28)) << 16

                                >> 0x12) + (short)*(int *)(iVar3 + 0x28));

    *(int *)(iVar3 + 0x30) = iVar1;

    *(int *)(iVar3 + 0x28) = iVar1;

  }

  else if (*(int *)0x06083261 == '\x02') {

    iVar1 = (int)DAT_0600e86c;

    iVar2 = (int)(short)((short)((int)(0x00008000 +

                                      (*(int *)(iVar3 + iVar1) - *(int *)(iVar3 + 0x28))) << 16

                                >> 0x11) + (short)*(int *)(iVar3 + 0x28));

    *(int *)(iVar3 + 0x30) = iVar2;

    *(int *)(iVar3 + 0x28) = iVar2;

    if ((*(int *)(iVar3 + iVar1 + -0x54) != 0) &&

       (iVar1 = *(int *)(iVar3 + DAT_0600e86e) + -1, *(int *)(iVar3 + DAT_0600e86e) = iVar1,

       iVar1 == 0)) {

      iVar1 = 0x1f8;

      *(int *)(iVar3 + iVar1) =

           (int)*(short *)(*(int *)(iVar3 + DAT_0600e870) * 0x18 +

                           *(int *)(iVar3 + DAT_0600e870 + -4) + 0x14);

      *(int *)(iVar3 + iVar1 + 0xc) = 0x400;

    }

  }

  (*(int(*)())0x0600CEBA)();

  iVar1 = 0x228;

  *(int *)(iVar3 + iVar1 + -0x34) =

       *(int *)(iVar3 + iVar1) * *(int *)0x0607EA9C + *(int *)(iVar3 + iVar1 + -0x3c);

  *(int *)(iVar3 + DAT_0600e920) =

       (int)*(short *)(*(int *)(iVar3 + iVar1 + -0x44) * 0x18 + *(int *)(iVar3 + iVar1 + -0x48) +

                      0x14);

  if ((GAME_STATE_BIT & (unsigned int)0x00200000) != 0) {

    (*(int(*)())0x06027552)(*(int *)(iVar3 + 0xc),0x066505B3);

    *(int *)(DAT_0600e922 + iVar3) = (int)extraout_var;

    *(int *)(PTR_DAT_0600e924 + iVar3) = (int)extraout_var;

  }

  return;

}

int FUN_0600e906()
{

  char *puVar1;

  short extraout_var;

  int iVar2;

  int iVar3;

  iVar3 = CAR_PTR_CURRENT;

  if (CAR_COUNT == 0) {

    (*(int(*)())0x0600D266)();

    (*(int(*)())0x0600C74E)();

    (*(int(*)())0x06027552)(*(int *)(iVar3 + 0xc),0x00480000);

    *(int *)(iVar3 + 8) = (int)extraout_var;

    puVar1 = (char *)0x0600CEBA;

    *(int *)(iVar3 + 0x30) = *(int *)(iVar3 + 0x20);

    (*(int(*)())puVar1)();

    iVar2 = 0x228;

    *(int *)(iVar3 + iVar2 + -0x34) =

         *(int *)(iVar3 + iVar2) * *(int *)0x0607EA9C + *(int *)(iVar3 + iVar2 + -0x3c);

    if (*(int *)(iVar3 + iVar2 + -0x3c) == 0) {

      iVar2 = (int)DAT_0600e9e4;

      *(int *)(iVar3 + iVar2) = 0;

      *(int *)(iVar3 + iVar2 + -0x18) = 0x200;

    }

  }

  else {

    *(int *)(iVar3 + 0xc) = 0;

  }

  return 0;

}

/* camera_setup -- Initialize camera for target car.
 * Runs camera pre-setup (FUN_0600e906). If no active cars (car_count==0),
 * computes speed-based camera distance via FUN_06027552 (mul/div helper).
 * If camera tracking not yet initialized, clears camera state. */
void FUN_0600e99c(void)
{
    register int base asm("r2") = CAR_PTR_TARGET;

    FUN_0600e906();   /* camera pre-setup */

    if (CAR_COUNT == 0) {
        int dist = (*(int(*)())0x06027552)(*(int *)(base + CAR_ACCEL), 0x066505B3);
        *(int *)(base + DAT_0600e9e8) = dist;
        *(int *)(base + DAT_0600e9ea) = dist;
    }

    if (*(int *)(base + PTR_DAT_0600e9ec) == 0) {
        *(int *)0x0607EAD0 = 0;            /* clear camera active flag */
        *(int *)(base + CAR_RANKING) = 0;
        *(int *)(base + CAR_WAYPOINT) = 0;
    }
}

void FUN_0600ea18(param_1)
    int param_1;
{

  short sVar1;

  char *puVar2;

  int iVar3;

  int iVar4;

  int uVar5;

  unsigned int *puVar6;

  int *piVar7;

  unsigned int uVar8;

  int iVar9;

  int iVar10;

  puVar2 = (char *)0x0605A228;

  puVar6 = (unsigned int *)(DAT_0600ea76 + param_1);

  uVar8 = puVar6[1] | puVar6[2] | puVar6[3] | *puVar6;

  if ((uVar8 != 0) && ((puVar6[3] & *puVar6 & puVar6[2] & puVar6[1] & 0x80) == 0)) {

    if ((uVar8 & 0x33) == 0) {

      iVar3 = *(int *)0x0605A228;

      *(int *)0x0605A228 = iVar3 + 1;

      if (0xa0 <= iVar3 + 1) {

        *(int *)puVar2 = 0;

        goto LAB_0600ea80;

      }

    }

    else {

      *(int *)0x0605A228 = 0;

    }

    return;

  }

  *(int *)0x0605A228 = 0;

LAB_0600ea80:

  iVar3 = *(int *)(param_1 + 0x10);

  piVar7 = (int *)((*(int *)(param_1 + DAT_0600eafa) << 3 + 3) << 4 + *(int *)0x0607EB88);

  iVar9 = *piVar7;

  iVar10 = piVar7[1];

  iVar4 = *(int *)(param_1 + 0x18);

  sVar1 = *(short *)((int)piVar7 + 10);

  uVar5 = *(int *)(param_1 + 0x30);

  *(int *)0x060786BC = 0x10;

  *(int *)0x060786C0 = iVar9 - iVar3 >> 4;

  *(int *)0x060786C4 = iVar10 - iVar4 >> 4;

  *(short *)0x060786C8 = (short)((sVar1 << 2) - (short)uVar5) >> 4;

  *(int *)(param_1 + 0xc) = 0;

  *(int *)(param_1 + 8) = 0;

  iVar3 = 0xe0;

  *(int *)(param_1 + iVar3) = 0;

  *(int *)(param_1 + iVar3 + 4) = 0;

  *(int *)(param_1 + iVar3 + 0x40) = 1;

  *(int *)(param_1 + iVar3 + 0x44) = 1;

  *(int *)(param_1 + iVar3 + 0x48) = 1;

  *(int *)(param_1 + iVar3 + 0x4c) = 1;

  return;

}

void FUN_0600eb14()
{
  register int *ptr asm("r4") = (int *)0x06078900;
  register unsigned int cnt asm("r5") = 0;
  register int zero asm("r6") = 0;
  unsigned int limit = (unsigned int)DAT_0600ebd8;

  do {
    *ptr++ = zero;
    cnt++;
  } while (cnt < limit);

  (*(void(*)())0x06026E02)();
  (*(void(*)())0x060270C6)();
  (*(void(*)())0x0600629C)();

  *(int *)0x06078A20 = 1;
  *(int *)0x06078A24 = 1;
  *(int *)0x06078A28 = 1;
  *(int *)0x06078A2C = 1;

  *(short *)0x06063F46 = zero;
  *(int *)0x0607EAE4 = zero;
  *(int *)0x0607EAE8 = zero;
  *(int *)0x0607EAEC = zero;
  GAME_STATE_VAR = zero;
  *(int *)0x0607EBF4 = zero;
  *(int *)0x06078654 = 5;
  *(int *)0x0605A1C4 = zero;
  *(int *)0x06082A30 = zero;
  *(int *)0x0607EABC = zero;
  *(int *)0x0607EAC0 = zero;
  *(int *)0x06083260 = zero;
  *(int *)0x06082A26 = zero;
  *(int *)0x060788FC = zero;
  *(int *)0x06082A38 = zero;
  *(int *)0x06083261 = zero;
  *(int *)0x0608325C = zero;
  *(int *)0x06083258 = zero;
  *(int *)0x0605A21C = zero;
  *(short *)0x06086058 = zero;
  *(int *)0x0608605A = zero;
  *(int *)0x0605DE3C = zero;
  *(int *)0x060786A8 = zero;
  *(int *)0x060786BC = zero;
  *(int *)0x06085FCC = zero;
  *(int *)0x06087060 = zero;

  *(short *)0x0602FD98 = zero;
  *(short *)0x0602FD9A = zero;
  *(short *)0x0602FD9C = zero;
  *(short *)0x0602FD9E = zero;
  *(short *)0x0602FDA0 = zero;

  (*(void(*)())0x06021450)();
  (*(void(*)())0x06018634)();
}

void FUN_0600ec78()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  (*(int(*)())0x0600A140)();

  puVar1 = (char *)0x06063F5C;

  iVar5 = *(int *)(0x06059FFC << 3) + *(int *)0x06063F5C;

  iVar4 = iVar5 + 0x40;

  *(int *)0x06078884 = iVar4;

  iVar6 = 0xc0;

  *(int *)0x06078880 = iVar4 + iVar6;

  puVar2 = (char *)0x06078888;

  *(int *)0x06078888 = iVar5 + DAT_0600ed62;

  *(int *)(puVar2 + 4) = *(int *)puVar2 + 0x20;

  *(int *)(puVar2 + 8) = *(int *)puVar2 + 0x40;

  *(int *)0x0606A4F4 = 0;

  *(int *)0x0606A4EC = (int)DAT_0600ed64;

  (*(int(*)())(BIOS_FUNC_0344))(0xffffffff,0x83);

  (*(int(*)())0x06012E00)();

  (*(int(*)())(BIOS_FUNC_0344))(-132,0);

  (*(int(*)())0x0602766C)(*(int *)puVar1,0x0605A018,0x60);

  VDP1_CMD_BASE_PTR = 3;

  *(short *)(*(int *)puVar1 + 0x60) = (short)0x00008000;

  *(short *)0x06089E44 = 0;

  puVar2 = (char *)0x002A0000;

  puVar1 = (char *)0x06007658;

  iVar5 = 0x108;

  (*(int(*)())0x06007658)(1,iVar5,0,0x002A0000 + DAT_0600ed6c);

  (*(int(*)())puVar1)(2,0x810,0,puVar2 + DAT_0600ed6e);

  (*(int(*)())puVar1)(3,(int)DAT_0600ed74,0,puVar2 + DAT_0600ed72);

  (*(int(*)())puVar1)(4,(int)DAT_0600ed78,0,puVar2 + DAT_0600ed76);

  (*(int(*)())puVar1)(5,0x519,0,puVar2 + DAT_0600ed7a);

  (*(int(*)())puVar1)(6,(int)DAT_0600ed80,0,puVar2 + DAT_0600ed7e);

  (*(int(*)())puVar1)(7,0x738,4,puVar2 + DAT_0600eeba);

  (*(int(*)())puVar1)(8,0x738,4,puVar2 + DAT_0600eebe);

  (*(int(*)())puVar1)(9,0x208,0,puVar2 + DAT_0600eec0);

  (*(int(*)())puVar1)(10,0xa28,0x3c,puVar2 + DAT_0600eec4);

  (*(int(*)())puVar1)(0x10,0x228,8,puVar2 + DAT_0600eec8);

  (*(int(*)())puVar1)(0x11,0x428,8,puVar2 + DAT_0600eecc);

  (*(int(*)())puVar1)(0x12,0x418,8,puVar2 + DAT_0600eed0);

  (*(int(*)())puVar1)(0x13,0x820,8,puVar2 + DAT_0600eed4);

  (*(int(*)())puVar1)(0x14,0x518,8,puVar2 + DAT_0600eed8);

  (*(int(*)())puVar1)(0x15,0x518,8,puVar2 + DAT_0600eedc);

  (*(int(*)())puVar1)(0x16,0x508,0xc,puVar2 + DAT_0600eede);

  (*(int(*)())puVar1)(0x17,0xd10,8,puVar2 + DAT_0600eee2);

  (*(int(*)())puVar1)(0x18,(int)DAT_0600eee8,0x1c,puVar2 + DAT_0600eee6);

  iVar4 = 0x348;

  (*(int(*)())puVar1)(0x19,iVar4,0x10,puVar2 + DAT_0600eeec);

  (*(int(*)())puVar1)(0x1a,iVar4,0x10,puVar2 + DAT_0600eeee);

  (*(int(*)())puVar1)(0x1b,iVar4,0x10,puVar2 + DAT_0600eef0);

  (*(int(*)())puVar1)(0x1c,0x630,0x1c,puVar2 + DAT_0600eef2);

  (*(int(*)())puVar1)(0x1d,0xa28,0x10,puVar2 + DAT_0600eef6);

  (*(int(*)())puVar1)(0x1e,0xc08,0x18,puVar2 + DAT_0600eef8);

  (*(int(*)())puVar1)(0x1f,0xc10,0x18,puVar2 + DAT_0600eefc);

  iVar4 = 0x308;

  (*(int(*)())puVar1)(0x20,iVar4,0xc,puVar2 + DAT_0600effe);

  (*(int(*)())puVar1)(0x21,0x410,0xc,puVar2 + DAT_0600f000);

  (*(int(*)())puVar1)(0x22,iVar4,0xc,puVar2 + DAT_0600f004);

  (*(int(*)())puVar1)(0x23,iVar4,0xc,puVar2 + DAT_0600f006);

  (*(int(*)())puVar1)(0x24,0x410,0xc,puVar2 + DAT_0600f008);

  (*(int(*)())puVar1)(0x25,(int)DAT_0600f00c,0x14,puVar2 + DAT_0600f00a);

  (*(int(*)())puVar1)(0x26,(int)DAT_0600f00c,0x14,puVar2 + DAT_0600f00e);

  (*(int(*)())puVar1)(0x27,0x610,0xc,puVar2 + DAT_0600f010);

  (*(int(*)())puVar1)(0x28,0x510,0x14,puVar2 + DAT_0600f014);

  (*(int(*)())puVar1)(0x29,0x310,0x14,puVar2 + DAT_0600f018);

  (*(int(*)())puVar1)(0x2a,(int)DAT_0600f01e,0x14,puVar2 + DAT_0600f01c);

  (*(int(*)())puVar1)(0x2b,(int)DAT_0600f022,0x14,puVar2 + DAT_0600f020);

  (*(int(*)())puVar1)(0x2c,0x110,0xc,puVar2 + DAT_0600f024);

  (*(int(*)())puVar1)(0x2d,0x110,0xc,puVar2 + DAT_0600f028);

  (*(int(*)())puVar1)(0x2e,0x510,0x14,puVar2 + DAT_0600f02a);

  (*(int(*)())puVar1)(0x2f,0x310,0x14,puVar2 + DAT_0600f02c);

  (*(int(*)())puVar1)(0x30,(int)DAT_0600f01e,0x14,puVar2 + DAT_0600f02e);

  (*(int(*)())puVar1)(0x31,(int)DAT_0600f022,0x14,puVar2 + DAT_0600f030);

  (*(int(*)())puVar1)(0x32,iVar5,0x14,puVar2 + DAT_0600f032);

  (*(int(*)())puVar1)(0x33,iVar5,0x14,puVar2 + DAT_0600f034);

  (*(int(*)())puVar1)(0x34,iVar5,0x14,puVar2 + DAT_0600f036);

  (*(int(*)())puVar1)(0x35,iVar5,0x14,puVar2 + DAT_0600f14c);

  (*(int(*)())puVar1)(0x36,iVar5,0x10,puVar2 + DAT_0600f14e);

  (*(int(*)())puVar1)(0x37,iVar5,0x1c,puVar2 + DAT_0600f150);

  (*(int(*)())puVar1)(0x38,iVar5,8,puVar2 + DAT_0600f152);

  (*(int(*)())puVar1)(0x39,iVar5,0x10,puVar2 + PTR_DAT_0600f154);

  *(short *)0x06089E46 = 1;

  puVar3 = (char *)0x06007540;

  (*(int(*)())0x06007540)(0x41,1,0);

  (*(int(*)())puVar3)(0x42,2,0);

  (*(int(*)())puVar3)(0x43,3,0);

  (*(int(*)())puVar3)(0x44,4,0);

  (*(int(*)())puVar3)(0x45,5,0);

  (*(int(*)())puVar3)(0x46,6,0);

  (*(int(*)())puVar3)(0x47,7,4);

  (*(int(*)())puVar3)(0x48,8,4);

  (*(int(*)())puVar3)(0x49,9,0);

  (*(int(*)())puVar3)(0x4a,10,0x3c);

  (*(int(*)())puVar3)(0x50,0x10,0x20);

  (*(int(*)())puVar3)(0x51,0x11,0x20);

  (*(int(*)())puVar3)(0x52,0x12,0x20);

  (*(int(*)())puVar3)(0x53,0x13,0x20);

  (*(int(*)())puVar3)(0x54,0x14,0x20);

  (*(int(*)())puVar3)(0x55,0x15,0x20);

  (*(int(*)())puVar3)(0x56,0x16,0x24);

  (*(int(*)())puVar3)(0x57,0x17,0x20);

  (*(int(*)())puVar3)(0x58,0x18,0x34);

  (*(int(*)())puVar3)(0x59,0x19,0x28);

  (*(int(*)())puVar3)(0x5a,0x1a,0x28);

  (*(int(*)())puVar3)(0x5b,0x1b,0x28);

  (*(int(*)())puVar3)(0x5c,0x1c,0x34);

  (*(int(*)())puVar3)(0x5d,0x1d,0x28);

  (*(int(*)())puVar3)(0x5e,0x1e,0x30);

  (*(int(*)())puVar3)(0x5f,0x1f,0x30);

  (*(int(*)())puVar3)(0x60,0x20,0x24);

  (*(int(*)())puVar3)(0x61,0x21,0x24);

  (*(int(*)())puVar3)(0x62,0x22,0x24);

  (*(int(*)())puVar3)(99,0x23,0x24);

  (*(int(*)())puVar3)(100,0x24);

  (*(int(*)())puVar3)(0x65,0x25,0x2c);

  (*(int(*)())puVar3)(0x66,0x26,0x2c);

  (*(int(*)())puVar3)(0x67,0x27,0x24);

  (*(int(*)())puVar3)(0x68,0x28,0x2c);

  (*(int(*)())puVar3)(0x69,0x29,0x2c);

  (*(int(*)())puVar3)(0x6a,0x2a,0x2c);

  (*(int(*)())puVar3)(0x6b,0x2b,0x2c);

  (*(int(*)())puVar3)(0x6c,0x2c,0x24);

  (*(int(*)())puVar3)(0x6d,0x2d,0x24);

  (*(int(*)())puVar3)(0x6e,0x2e,0x2c);

  (*(int(*)())puVar3)(0x6f,0x2f,0x2c);

  (*(int(*)())puVar3)(0x70,0x30,0x2c);

  (*(int(*)())puVar3)(0x71,0x31,0x2c);

  (*(int(*)())puVar3)(0x72,0x32,0x2c);

  (*(int(*)())puVar3)(0x73,0x33,0x2c);

  (*(int(*)())puVar3)(0x74,0x34,0x2c);

  (*(int(*)())puVar3)(0x75,0x35,0x2c);

  (*(int(*)())puVar3)(0x76,0x36,0x28);

  (*(int(*)())puVar3)(0x77,0x37,0x34);

  (*(int(*)())puVar3)(0x78,0x38,0x20);

  (*(int(*)())puVar3)(0x79,0x39,0x28);

  iVar4 = 0xb40;

  (*(int(*)())puVar1)(0x101,iVar4,0x78,puVar2 + DAT_0600f26c);

  (*(int(*)())puVar1)((int)DAT_0600f272,iVar4,0x7c,puVar2 + DAT_0600f270);

  iVar5 = 0x80;

  (*(int(*)())puVar1)(0x103,iVar4,iVar5,puVar2 + DAT_0600f276);

  (*(int(*)())puVar3)((int)DAT_0600f344,DAT_0600f342 + 0x7d);

  (*(int(*)())puVar3)((int)DAT_0600f348,DAT_0600f346 + 0x7a);

  (*(int(*)())puVar3)((int)PTR_DAT_0600f34c,DAT_0600f34a + 0x77);

  puVar1 = (char *)0x06086028;

  *(short *)0x06086028 = (short)0x00008000;

  (*(int(*)())0x06036E90)(0x25F00FFE,1,puVar1);

  (*(int(*)())0x060149E0)();

  (*(int(*)())0x0600A026)();

  (*(int(*)())0x0601D2DC)();

  puVar2 = (char *)0x060484EC;

  puVar1 = (char *)0x0602761E;

  (*(int(*)())0x0602761E)(0x25F00060,0x060484EC,iVar6);

  (*(int(*)())puVar1)(0x25F00460,puVar2,iVar6);

  puVar2 = (char *)0x0604870C;

  (*(int(*)())puVar1)(0x25F00520,0x0604870C,0x20);

  (*(int(*)())puVar1)(0x25F00540,puVar2,0x20);

  puVar2 = (char *)0x0604842C;

  (*(int(*)())puVar1)(0x25F001A0,0x0604842C,0x40);

  (*(int(*)())puVar1)(0x25F007A0,puVar2,0x40);

  puVar2 = (char *)0x0604846C;

  (*(int(*)())puVar1)(0x25F001E0,0x0604846C,0x20);

  (*(int(*)())puVar1)(0x25F007E0,puVar2,0x20);

  (*(int(*)())puVar1)(0x25F005A0,0x0605CA5C,0x40);

  puVar2 = (char *)0x0604814C;

  (*(int(*)())puVar1)(0x25F00000,0x0604814C,0x60);

  (*(int(*)())puVar1)(0x25F00600,puVar2,0x60);

  (*(int(*)())puVar1)(0x25F006A0,0x060484CC,0x20);

  puVar2 = (char *)0x060487AC;

  (*(int(*)())puVar1)(0x25F00120,0x060487AC,iVar5);

  (*(int(*)())puVar1)(0x25F00720,puVar2,iVar5);

  puVar2 = (char *)0x060487CC;

  (*(int(*)())puVar1)(0x25F00680,0x060487CC,0x20);

  (*(int(*)())puVar1)(0x25F00140,puVar2,0x20);

  puVar2 = (char *)0x060483EC;

  (*(int(*)())puVar1)(0x25F000C0,0x060483EC,0x20);

  (*(int(*)())puVar1)(0x25F006C0,puVar2,0x20);

  *(short *)0x0605AAA0 = 0;

  *(int *)0x0607887F = 0;

  puVar1 = (char *)0x06026CE0;

  INPUT_STATE = INPUT_STATE | 0x40000000;

  (*(int(*)())puVar1)();

  VBLANK_OUT_COUNTER = 0;

  return;

}

void FUN_0600f424()
{

  unsigned short uVar1;

  char *puVar2;

  char *puVar3;

  int uVar4;

  int iVar5;

  puVar2 = (char *)0x0607887F;

  if (((unsigned char)*(int *)0x0607887F < 5) || (*(int *)0x0607887F == 9)) {

    if (*(int *)0x0607887F == '\t') {

      uVar4 = (*(int(*)())0x06034FE0)();

      (*(int(*)())0x06028430)(0xc,0x148,0x18,uVar4);

    }

    else {

      uVar4 = (*(int(*)())0x06034FE0)();

      (*(int(*)())0x06028430)(8,0x148,0x18,uVar4);

    }

  }

  if (((9 < (unsigned char)*puVar2) && ((char *)(unsigned int)*(unsigned short *)0x0607865E == 0x00008000))

     && (*(int *)0x0605AB18 == '\0')) {

    uVar1 = *(unsigned short *)0x06063D98;

    if ((uVar1 & *(unsigned short *)0x06078656) == 0) {

      if ((uVar1 & *(unsigned short *)0x06078658) == 0) {

        if ((uVar1 & *(unsigned short *)0x0607865A) == 0) {

          if ((uVar1 & *(unsigned short *)0x0607865C) != 0) {

            *(int *)0x06078648 = 3;

          }

        }

        else {

          *(int *)0x06078648 = 2;

        }

      }

      else {

        *(int *)0x06078648 = 1;

      }

    }

    else {

      *(int *)0x06078648 = 0;

    }

  }

  puVar3 = (char *)0x0605ACE4;

  if (((unsigned char)*puVar2 < 0xc) && (8 < (unsigned char)*puVar2)) {

    iVar5 = (int)DAT_0600f612;

    if (DEMO_MODE_FLAG == 0) {

      (*(int(*)())0x060284AE)(0xc,iVar5,0x90,0x0605ACE4);

      (*(int(*)())0x060284AE)(0xc,(int)DAT_0600f618,0x90,puVar3);

      (*(int(*)())0x060283E0)(0xc,(int)DAT_0600f61a,0,puVar3);

    }

    else if (*(int *)0x06078644 == 1) {

      (*(int(*)())0x06028400)(0xc,*(int *)0x06063848,iVar5,

                 *(int *)(0x06063848 + 4) + (int)DAT_0600f614,0x06063848);

    }

    else {

      (*(int(*)())0x06028400)(0xc,*(int *)0x06063850,iVar5,

                 *(int *)(0x06063850 + 4) + (int)DAT_0600f614,0x06063850);

    }

  }

  (*(int(*)())0x06026DBC)();

  (*(int(*)())(*(int *)(0x0605AC2C + ((unsigned int)(unsigned char)(*puVar2) << 2))))();

  FUN_0600ffd0();

  OBJ_STATE_PRIMARY = OBJ_STATE_PRIMARY + -0x30;

  (*(int(*)())0x060078DC)();

  return;

}

/* subsystem_countdown_step -- Run subsystem handlers then decrement countdown.
 * When countdown reaches 0, sets mode flag to 4 (transition). */
void FUN_0600f870(void)
{
    short val;
    func_060114AC(0);
    func_06011094();
    val = counter_0607887C;
    counter_0607887C = val - 1;
    if ((short)(val - 1) <= 0) {
        flag_0607887F = 4;
    }
}

unsigned int FUN_0600ffd0()
{

  short sVar1;

  char *puVar2;

  char *puVar3;

  int uVar4;

  int iVar5;

  unsigned int uVar6;

  puVar3 = (char *)0x0607887F;

  puVar2 = (char *)0x060284AE;

  iVar5 = 0x90;

  uVar6 = 0;

  do {

    FUN_060100a4(uVar6);

    uVar6 = uVar6 + 1;

  } while ((uVar6 & 0xff) < 3);

  if (*(int *)0x06078663 == '\0') {

    if (*(int *)0x0605AA98 != 0) {

      *(int *)0x0605AA98 = *(int *)0x0605AA98 + -1;

    }

    uVar6 = (unsigned int)(unsigned char)*puVar3;

    if ((uVar6 < 5) || (uVar6 == 9)) {

      if (*puVar3 == '\t') {

        uVar4 = 0xc;

        sVar1 = DAT_06010044;

      }

      else {

        uVar4 = 8;

        sVar1 = DAT_06010046;

      }

      uVar6 = (*(int(*)())puVar2)(uVar4,(int)sVar1,iVar5,0x0605ACE4);

    }

  }

  else {

    if (*(int *)0x0605AA98 != 0xc) {

      *(int *)0x0605AA98 = *(int *)0x0605AA98 + 1;

    }

    uVar6 = (unsigned int)(unsigned char)*puVar3;

    if ((uVar6 < 5) || (uVar6 == 9)) {

      if (*puVar3 == '\t') {

        uVar4 = 0xc;

        sVar1 = DAT_060100f2;

      }

      else {

        uVar4 = 8;

        sVar1 = DAT_060100f4;

      }

      uVar6 = (*(int(*)())puVar2)(uVar4,(int)sVar1,iVar5,0x0605AB19);

    }

  }

  return uVar6;

}
