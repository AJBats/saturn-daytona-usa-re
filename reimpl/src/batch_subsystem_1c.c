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
extern int FUN_0601d5f4();
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

int FUN_0601c3e4()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  int uVar6;

  int iVar7;

  int iVar8;

  puVar5 = (char *)0x0605DF56;

  puVar4 = (char *)0x0605DF57;

  puVar3 = (char *)0x0608A52C;

  puVar2 = (char *)0x00008000;

  puVar1 = (char *)0x0605DF44;

  iVar8 = CAR_PTR_TARGET;

  if ((*(int *)0x06063E1C == 0) || (*(int *)0x06063E20 == 0)) {

    (*(int(*)())0x06034F78)();

    (*(int(*)())0x06034F78)();

    (*(int(*)())0x06034F78)();

    uVar6 = (*(int(*)())0x06034F78)();

  }

  else {

    if ((*(unsigned char *)(iVar8 + 3) & 0x40) != 0) {

      *(short *)0x0605DF4E = 8;

      (*(int(*)())0x06034F78)();

    }

    if (((int)*(char *)(iVar8 + 3) & 0x80U) != 0) {

      *(short *)0x0605DF50 = 8;

      (*(int(*)())0x06034F78)();

    }

    if ((*(unsigned char *)(iVar8 + 2) & 1) != 0) {

      *(short *)0x0605DF52 = 8;

      (*(int(*)())0x06034F78)();

    }

    if ((*(unsigned char *)(iVar8 + 2) & 2) != 0) {

      *(short *)0x0605DF54 = 8;

      (*(int(*)())0x06034F78)();

    }

    if (*(short *)0x0605DF4E == 0) {

      if (*(short *)0x0605DF50 == 0) {

        if (*(short *)0x0605DF52 == 0) {

          if (*(short *)0x0605DF54 != 0) {

            (*(int(*)())0x06027080)();

            (*(int(*)())0x060270F2)(0xFFFE9DF4,puVar2,0x00013333);

            (*(int(*)())0x060271A2)((int)DAT_0601c844);

            iVar7 = ((unsigned char)*puVar4 + 0x12) << 2;

            (*(int(*)())0x06032158)(*(int *)(0x0606212C + iVar7),

                       *(int *)(0x060621D8 + iVar7));

            iVar7 = ((unsigned char)*puVar4 + 0x12) << 2;

            (*(int(*)())0x06031DF4)(*(int *)(0x060620D8 + iVar7),*(short *)0x06089E9C,

                       *(int *)(0x06062180 + iVar7));

            *(int *)puVar3 = *(int *)puVar3 + -0x30;

            *puVar4 = *puVar4 + '\x01';

            if (2 < (unsigned char)*puVar4) {

              *puVar4 = 0;

            }

            *(short *)0x0605DF54 = *(short *)0x0605DF54 + -1;

          }

        }

        else {

          (*(int(*)())0x06027080)();

          (*(int(*)())0x060270F2)(0x0001620C,puVar2,0x00013333);

          (*(int(*)())0x060271A2)((int)DAT_0601c77c);

          iVar7 = ((unsigned char)*puVar5 + 0x12) << 2;

          (*(int(*)())0x06032158)(*(int *)(0x0606212C + iVar7),

                     *(int *)(0x060621D8 + iVar7));

          iVar7 = ((unsigned char)*puVar5 + 0x12) << 2;

          (*(int(*)())0x06031DF4)(*(int *)(0x060620D8 + iVar7),*(short *)0x06089E9C,

                     *(int *)(0x06062180 + iVar7));

          *(int *)puVar3 = *(int *)puVar3 + -0x30;

          *puVar5 = *puVar5 + '\x01';

          if (2 < (unsigned char)*puVar5) {

            *puVar5 = 0;

          }

          *(short *)0x0605DF52 = *(short *)0x0605DF52 + -1;

        }

      }

      else {

        (*(int(*)())0x06027080)();

        if ((*(int *)0x06063E1C == 1) && (*(int *)0x06063E20 == 1)) {

          (*(int(*)())0x060270F2)(0xFFFEB78E,puVar2,0xFFFE4000);

          (*(int(*)())0x06027124)((int)DAT_0601c5fa,(int)DAT_0601c5fa);

        }

        else {

          (*(int(*)())0x060270F2)(0xFFFEB78E,puVar2,0xFFFF0000);

        }

        (*(int(*)())0x060271A2)((int)DAT_0601c6c0);

        iVar7 = ((unsigned char)*puVar4 + 0x12) << 2;

        (*(int(*)())0x06032158)(*(int *)(0x0606212C + iVar7),

                   *(int *)(0x060621D8 + iVar7));

        iVar7 = ((unsigned char)*puVar4 + 0x12) << 2;

        (*(int(*)())0x06031DF4)(*(int *)(0x060620D8 + iVar7),*(short *)0x06089E9C,

                   *(int *)(0x06062180 + iVar7));

        *(int *)puVar3 = *(int *)puVar3 + -0x30;

        *puVar4 = *puVar4 + '\x01';

        if (2 < (unsigned char)*puVar4) {

          *puVar4 = 0;

        }

        *(short *)0x0605DF50 = *(short *)0x0605DF50 + -1;

      }

    }

    else {

      (*(int(*)())0x06027080)();

      if ((*(int *)0x06063E1C == 1) && (*(int *)0x06063E20 == 1)) {

        (*(int(*)())0x060270F2)(0x00014872,puVar2,0xFFFE4000);

        (*(int(*)())0x06027124)((int)DAT_0601c510,(int)DAT_0601c510);

      }

      else {

        (*(int(*)())0x060270F2)(0x00014872,puVar2,0xFFFF0000);

      }

      (*(int(*)())0x060271A2)((int)DAT_0601c5f8);

      iVar7 = ((unsigned char)*puVar5 + 0x12) << 2;

      (*(int(*)())0x06032158)(*(int *)(0x0606212C + iVar7),*(int *)(0x060621D8 + iVar7)

                );

      iVar7 = ((unsigned char)*puVar5 + 0x12) << 2;

      (*(int(*)())0x06031DF4)(*(int *)(0x060620D8 + iVar7),*(short *)0x06089E9C,

                 *(int *)(0x06062180 + iVar7));

      *(int *)puVar3 = *(int *)puVar3 + -0x30;

      *puVar5 = *puVar5 + '\x01';

      if (2 < (unsigned char)*puVar5) {

        *puVar5 = 0;

      }

      *(short *)0x0605DF4E = *(short *)0x0605DF4E + -1;

    }

    if (*(int *)0x06059F30 == 0) {

      uVar6 = 0;

    }

    else {

      if ((*(short *)(iVar8 + DAT_0601c93c) == 0) && (*(short *)(iVar8 + DAT_0601c93e) == 0)) {

        *(short *)puVar1 = 0;

      }

      if ((*(short *)(iVar8 + DAT_0601c93c) != 0) ||

         (uVar6 = 0, *(short *)(iVar8 + DAT_0601c93e) != 0)) {

        (*(int(*)())0x06027080)();

        (*(int(*)())0x060270F2)(*(int *)0x06044670,

                   *(int *)(0x06044670 + 4) + -13107,

                   0xFFFF6000 - *(int *)(0x06044670 + 8));

        (*(int(*)())0x060271A2)(puVar2);

        iVar8 = (*(short *)(0x0605DF46 + *(short *)((int)(int)puVar1 << 1)) + 0xe) << 2;

        (*(int(*)())0x06032158)(*(int *)(0x0606212C + iVar8),

                   *(int *)(0x060621D8 + iVar8));

        iVar8 = (*(short *)(0x0605DF46 + *(short *)((int)(int)puVar1 << 1)) + 0xe) << 2;

        uVar6 = (*(int(*)())0x06031DF4)(*(int *)(0x060620D8 + iVar8),*(short *)0x06089E9C

                           ,*(int *)(0x06062180 + iVar8));

        *(int *)puVar3 = *(int *)puVar3 + -0x30;

        *(short *)puVar1 = *(short *)puVar1 + 1;

        if (3 < *(short *)puVar1) {

          *(short *)puVar1 = 0;

        }

      }

    }

  }

  return uVar6;

}

void FUN_0601c978()
{

  char *puVar1;

  char *puVar2;

  int iVar3;

  short *puVar4;

  short *puVar5;

  puVar1 = (char *)0x06086028;

  *(int *)0x0608602C = 0;

  *(int *)0x06086030 = 0;

  puVar2 = (char *)0x060149E0;

  *(short *)puVar1 = DAT_0601ca3a;

  (*(int(*)())puVar2)();

  (*(int(*)())0x060148FC)();

  (*(int(*)())0x06026CE0)();

  VBLANK_OUT_COUNTER = 0;

  (*(int(*)())0x0600A026)();

  *(int *)0x0608601C = (int)DAT_0601ca3c;

  *(int *)0x06086020 = 0;

  *(int *)0x06086024 = 0;

  iVar3 = 0x20;

  puVar5 = (short *)0x25F00200;

  do {

    iVar3 = iVar3 + -2;

    *puVar5 = *(short *)puVar1;

    puVar4 = puVar5 + 1;

    puVar5 = puVar5 + 2;

    *puVar4 = *(short *)puVar1;

  } while (iVar3 != 0);

  iVar3 = 0x20;

  puVar5 = (short *)0x25F00400;

  do {

    iVar3 = iVar3 + -2;

    *puVar5 = *(short *)puVar1;

    puVar4 = puVar5 + 1;

    puVar5 = puVar5 + 2;

    *puVar4 = *(short *)puVar1;

  } while (iVar3 != 0);

  (*(int(*)())0x0602766C)(0x25F00000,0x0604880C,0x40);

  (*(int(*)())0x0600511E)(0x25E70E40,0x00014000,0,9);

  (*(int(*)())0x0600511E)(0x25E7B168,0x00016BC0,0,9);

  (*(int(*)())0x06028400)(4,*(int *)0x06063958,0x518,

             *(int *)(0x06063958 + 4),0x06063958);

  (*(int(*)())0x06028400)(0,*(int *)0x06063960,0x518,

             *(int *)(0x06063960 + 4),0x06063960);

  puVar1 = (char *)0x06038BD4;

  (*(int(*)())0x06038BD4)(0x100,0);

  (*(int(*)())puVar1)(4,1);

  (*(int(*)())puVar1)(8,2);

  (*(int(*)())puVar1)(0x10,0);

  (*(int(*)())puVar1)(0x20,0);

  (*(int(*)())0x06036E90)(0x25F00FFE,1,0x06086028);

  INPUT_STATE = INPUT_STATE | 0x40000000;

  (*(int(*)())0x06026CE0)();

  VBLANK_OUT_COUNTER = 0;

  return;

}

void FUN_0601caee()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  char *puVar6;

  int iVar7;

  int *puVar8;

  int local_48;

  int local_44;

  char *local_40 [3];

  int local_34;

  int local_30;

  char *local_2c [3];

  char local_20 [4];

  puVar6 = (char *)0x0608601C;

  puVar5 = (char *)0x06086024;

  puVar4 = (char *)0x0602766C;

  puVar3 = (char *)0x25F00400;

  puVar2 = (char *)0x25F00200;

  puVar1 = (char *)0x06086020;

  *(int *)0x0608601C = *(int *)0x0608601C + -1;

  puVar8 = (int *)local_20;

  if (((*(unsigned short *)0x06063D98 & DAT_0601cb48) != 0) &&

     (puVar8 = (int *)local_20, *(int *)0x06086024 == 0)) {

    local_2c[0] = (char *)local_2c;

    (*(int(*)())0x060358EC)();

    local_30 = 0;

    local_34 = 0x40680000;

    iVar7 = (*(int(*)())0x06035844)();

    if (iVar7 == 0) {

      local_40[0] = (char *)local_40;

      (*(int(*)())0x060358EC)();

      local_44 = 0;

      puVar8 = &local_48;

      local_48 = 0x40568000;

      iVar7 = (*(int(*)())0x06035844)();

      if (iVar7 == 0) {

        *(int *)puVar5 = 3;

      }

      else {

        *(int *)puVar5 = 2;

        puVar8 = &local_48;

      }

    }

    else {

      *(int *)puVar5 = 1;

      puVar8 = &local_34;

    }

  }

  FUN_0601d12c();

  if (*(int *)puVar5 == 0) {

    *(char **)((int)puVar8 + -0xc) = (char *)((int)puVar8 + -0xc);

    (*(int(*)())0x060358EC)();

    *(int *)((int)puVar8 + -0x10) = 0;

    *(int *)((int)puVar8 + -0x14) = 0x40726000;

    iVar7 = (*(int(*)())0x06035844)();

    if (iVar7 != 0) goto LAB_0601cda4;

    *(char **)((int)puVar8 + -0x20) = (char *)((int)puVar8 + -0x20);

    (*(int(*)())0x060358EC)();

    *(int *)((int)puVar8 + -0x24) = 0;

    *(int *)((int)puVar8 + -0x28) = 0x406D4000;

    iVar7 = (*(int(*)())0x06035844)();

    if (iVar7 != 0) {

      FUN_0601cdc0();

      goto LAB_0601cda4;

    }

    *(char **)((int)puVar8 + -0x34) = (char *)((int)puVar8 + -0x34);

    (*(int(*)())0x060358EC)();

    *(int *)((int)puVar8 + -0x38) = 0;

    *(int *)((int)puVar8 + -0x3c) = 0x406D4000;

    iVar7 = (*(int(*)())0x06035B34)();

    if (iVar7 == 0) {

      *(int *)puVar1 = 0;

    }

    *(char **)((int)puVar8 + -0x48) = (char *)((int)puVar8 + -0x48);

    (*(int(*)())0x060358EC)();

    *(int *)((int)puVar8 + -0x4c) = 0;

    *(int *)((int)puVar8 + -0x50) = 0x40680000;

    iVar7 = (*(int(*)())0x06035844)();

    if (iVar7 != 0) {

      FUN_0601cefc();

      goto LAB_0601cda4;

    }

    *(char **)((int)puVar8 + -0x5c) = (char *)((int)puVar8 + -0x5c);

    (*(int(*)())0x060358EC)();

    *(int *)((int)puVar8 + -0x60) = 0;

    *(int *)((int)puVar8 + -100) = 0x40680000;

    iVar7 = (*(int(*)())0x06035B34)();

    if (iVar7 == 0) {

      FUN_0601d014();

      goto LAB_0601cda4;

    }

    *(char **)((int)puVar8 + -0x70) = (char *)((int)puVar8 + -0x70);

    (*(int(*)())0x060358EC)();

    *(int *)((int)puVar8 + -0x74) = 0;

    *(int *)((int)puVar8 + -0x78) = 0x40608000;

    iVar7 = (*(int(*)())0x06035844)();

    if (iVar7 != 0) {

      FUN_0601cdc0();

      goto LAB_0601cda4;

    }

    *(char **)((int)puVar8 + -0x84) = (char *)((int)puVar8 + -0x84);

    (*(int(*)())0x060358EC)();

    *(int *)((int)puVar8 + -0x88) = 0;

    *(int *)((int)puVar8 + -0x8c) = 0x40608000;

    iVar7 = (*(int(*)())0x06035B34)();

    if (iVar7 == 0) {

      *(int *)puVar1 = 0;

    }

    *(char **)((int)puVar8 + -0x98) = (char *)((int)puVar8 + -0x98);

    (*(int(*)())0x060358EC)();

    *(int *)((int)puVar8 + -0x9c) = 0;

    *(int *)((int)puVar8 + -0xa0) = 0x40568000;

    iVar7 = (*(int(*)())0x06035844)();

    if (iVar7 != 0) {

      FUN_0601cefc();

      goto LAB_0601cda4;

    }

    *(char **)((int)puVar8 + -0xac) = (char *)((int)puVar8 + -0xac);

    (*(int(*)())0x060358EC)();

    *(int *)((int)puVar8 + -0xb0) = 0;

    *(int *)((int)puVar8 + -0xb4) = 0x40568000;

    iVar7 = (*(int(*)())0x06035B34)();

    if (iVar7 == 0) {

      FUN_0601d074();

      goto LAB_0601cda4;

    }

    *(char **)((int)puVar8 + -0xc0) = (char *)((int)puVar8 + -0xc0);

    (*(int(*)())0x060358EC)();

    *(int *)((int)puVar8 + -0xc4) = 0;

    *(int *)((int)puVar8 + -200) = 0x403E0000;

    iVar7 = (*(int(*)())0x06035844)();

    if (iVar7 != 0) {

      FUN_0601cdc0();

      goto LAB_0601cda4;

    }

    *(char **)((int)puVar8 + -0xd4) = (char *)((int)puVar8 + -0xd4);

    (*(int(*)())0x060358EC)();

    *(int *)((int)puVar8 + -0xd8) = 0;

    *(int *)((int)puVar8 + -0xdc) = 0x403E0000;

    iVar7 = (*(int(*)())0x06035B34)();

    if (iVar7 == 0) {

      *(int *)puVar1 = 0;

    }

    if (0 < *(int *)puVar6) {

      FUN_0601cefc();

      goto LAB_0601cda4;

    }

  }

  else {

    if (*(int *)puVar5 == 1) {

      (*(int(*)())puVar4)(puVar2,0x0604880C,0x20);

      (*(int(*)())puVar4)(puVar3,0x0604882C,0x20);

    }

    if (*(int *)puVar5 == 2) {

      FUN_0601d014();

      (*(int(*)())puVar4)(puVar2,0x0604884C,0x20);

      (*(int(*)())puVar4)(puVar3,0x0604886C,0x20);

    }

    if (*(int *)puVar5 == 3) {

      (*(int(*)())puVar4)(puVar2,0x0605D17C,0x20);

      (*(int(*)())puVar4)(puVar3,0x0605D19C,0x20);

    }

  }

  GAME_STATE = 2;

LAB_0601cda4:

  (*(int(*)())0x06026CE0)();

  VBLANK_OUT_COUNTER = 0;

  return;

}

void FUN_0601cdc0()
{

  short sVar1;

  short uVar2;

  char *puVar3;

  int iVar4;

  short local_74 [2];

  short asStack_70 [2];

  short asStack_6c [2];

  short *puStack_68;

  short *psStack_64;

  short local_60 [16];

  char auStack_40 [40];

  puVar3 = (char *)0x06086020;

  if (*(int *)0x06086020 < 0x12) {

    sVar1 = *(short *)(0x0605DF58 + *(int *)(0x06086020 << 1));

    puStack_68 = (short *)0x25F00000;

    psStack_64 = local_60;

    for (iVar4 = 0; iVar4 < 0x20; iVar4 = iVar4 + 1) {

      uVar2 = *puStack_68;

      puStack_68 = puStack_68 + 1;

      FUN_0601d0bc(uVar2,local_74,asStack_70,asStack_6c);

      local_74[0] = (*(int(*)())0x06034FE0)(sVar1 * 0x1d);

      asStack_70[0] = (*(int(*)())0x06034FE0)();

      asStack_6c[0] = (*(int(*)())0x06034FE0)();

      *psStack_64 = asStack_6c[0] * 0x400 + asStack_70[0] * 0x20 + local_74[0];

      psStack_64 = psStack_64 + 1;

    }

    (*(int(*)())0x0602766C)(0x25F00200,local_60,0x20);

    (*(int(*)())0x0602766C)(0x25F00400,auStack_40,0x20);

  }

  *(int *)puVar3 = *(int *)puVar3 + 1;

  return;

}

void FUN_0601cefc()
{

  short uVar1;

  char *puVar2;

  int iVar3;

  short local_74 [2];

  short asStack_70 [2];

  short asStack_6c [2];

  short *puStack_68;

  int iStack_64;

  short *psStack_60;

  short local_5c [16];

  char auStack_3c [40];

  puVar2 = (char *)0x06086020;

  if (*(int *)0x06086020 < 0x12) {

    iStack_64 = 100 - *(short *)(0x0605DF58 + *(int *)(0x06086020 << 1));

    puStack_68 = (short *)0x25F00000;

    psStack_60 = local_5c;

    for (iVar3 = 0; iVar3 < 0x20; iVar3 = iVar3 + 1) {

      uVar1 = *puStack_68;

      puStack_68 = puStack_68 + 1;

      FUN_0601d0bc(uVar1,local_74,asStack_70,asStack_6c);

      local_74[0] = (*(int(*)())0x06034FE0)(iStack_64 * 0x1d);

      asStack_70[0] = (*(int(*)())0x06034FE0)();

      asStack_6c[0] = (*(int(*)())0x06034FE0)();

      *psStack_60 = asStack_6c[0] * 0x400 + asStack_70[0] * 0x20 + local_74[0];

      psStack_60 = psStack_60 + 1;

    }

    (*(int(*)())0x0602766C)(0x25F00200,local_5c,0x20);

    (*(int(*)())0x0602766C)(0x25F00400,auStack_3c,0x20);

  }

  *(int *)puVar2 = *(int *)puVar2 + 1;

  return;

}

void FUN_0601d014()
{

  (*(int(*)())0x0602766C)(0x25F00000,0x0604884C,0x40);

  (*(int(*)())0x06028400)(4,*(int *)0x06063968,0x518,

             *(int *)(0x06063968 + 4),0x06063968);

  (*(int(*)())0x06028400)(0,*(int *)0x06063970,0x518,

             *(int *)(0x06063970 + 4),0x06063970);

  *(int *)0x06086020 = 0;

  return;

}

void FUN_0601d074()
{

  (*(int(*)())0x0602853E)(4);

  (*(int(*)())0x0602766C)(0x25F00000,0x0605D17C,0x40);

  (*(int(*)())0x06028400)(4,*(int *)0x06063CF8,0x518,

             *(int *)(0x06063CF8 + 4),0x06063CF8);

  (*(int(*)())0x06028400)(0,*(int *)0x06063D00,0x518,

             *(int *)(0x06063D00 + 4),0x06063D00);

  *(int *)0x06086020 = 0;

  return;

}

void FUN_0601d12c()
{

  char *puVar1;

  int iVar2;

  puVar1 = (char *)0x0608602C;

  iVar2 = *(int *)0x0608602C;

  if ((iVar2 == 0) && ((*(unsigned short *)0x06063D9A & DAT_0601d18c) != 0)) {

    *(int *)0x0608602C = *(int *)0x0608602C + 1;

  }

  else if ((*(int *)0x0608602C == 1) && ((*(unsigned short *)0x06063D9A & DAT_0601d18c) != 0)) {

    *(int *)0x0608602C = *(int *)0x0608602C + 1;

  }

  else if ((*(int *)0x0608602C == 2) && ((*(unsigned short *)0x06063D9A & DAT_0601d18e) != 0)) {

    *(int *)0x0608602C = *(int *)0x0608602C + 1;

  }

  else if ((*(int *)0x0608602C == 3) && ((*(unsigned short *)0x06063D9A & DAT_0601d24c) != 0)) {

    *(int *)0x0608602C = *(int *)0x0608602C + 1;

  }

  else if ((*(int *)0x0608602C == 4) && ((*(unsigned short *)0x06063D9A & DAT_0601d24e) != 0)) {

    *(int *)0x0608602C = *(int *)0x0608602C + 1;

  }

  else if ((*(int *)0x0608602C == 5) &&

          (((unsigned int)*(unsigned short *)0x06063D9A & (unsigned int)0x00008000) != 0)) {

    *(int *)0x0608602C = *(int *)0x0608602C + 1;

  }

  else if ((*(int *)0x0608602C == 6) && ((*(unsigned short *)0x06063D9A & DAT_0601d24e) != 0)) {

    *(int *)0x0608602C = *(int *)0x0608602C + 1;

  }

  else if ((*(int *)0x0608602C == 7) &&

          (((unsigned int)*(unsigned short *)0x06063D9A & (unsigned int)0x00008000) != 0)) {

    *(int *)0x0608602C = *(int *)0x0608602C + 1;

  }

  else if ((*(int *)0x0608602C == 8) &&

          ((*(unsigned short *)0x06063D9A & PTR_DAT_0601d250) != 0)) {

    *(int *)0x0608602C = *(int *)0x0608602C + 1;

  }

  else if ((*(int *)0x0608602C == 9) && ((*(unsigned short *)0x06063D9A & DAT_0601d2c6) != 0)) {

    *(int *)0x0608602C = *(int *)0x0608602C + 1;

  }

  else if ((*(int *)0x0608602C == 10) &&

          ((*(unsigned short *)0x06063D9A & PTR_DAT_0601d2c8) != 0)) {

    *(int *)0x0608602C = *(int *)0x0608602C + 1;

  }

  if ((*(int *)puVar1 == iVar2) && (*(short *)0x06063D9A != 0)) {

    *(int *)puVar1 = 0;

  }

  if (*(int *)puVar1 == 0xb) {

    *(int *)0x06086030 = 1;

    *(int *)puVar1 = 0;

    (*(int(*)())0x0601D5F4)(0,0xAE1146FF);

    return;

  }

  return;

}

void FUN_0601d2dc()
{

  char *puVar1;

  char *puVar2;

  (*(int(*)())0x060149E0)();

  puVar1 = (char *)0x06038BD4;

  (*(int(*)())0x06038BD4)(0x100,0);

  (*(int(*)())puVar1)(4,0);

  (*(int(*)())puVar1)(8,0);

  (*(int(*)())puVar1)(0x10,6);

  (*(int(*)())puVar1)(0x20,7);

  (*(int(*)())0x0600A026)();

  (*(int(*)())0x0600511E)(0x25E6F9C4,0x00017700,0,8);

  puVar2 = (char *)0x0604842C;

  puVar1 = (char *)0x0602766C;

  (*(int(*)())0x0602766C)(0x25F00600,0x0604842C,0x40);

  (*(int(*)())puVar1)(0x25F00660,0x0604888C,0x60);

  (*(int(*)())puVar1)(0x25F00000,puVar2,0x60);

  (*(int(*)())0x06028654)(0x25E759EC,0x06094FA8);

  puVar1 = (char *)0x06095F48;

  (*(int(*)())0x06028654)(0x25E75DDC,0x06095F48);

  (*(int(*)())0x06028400)(8,puVar1,0,(int)DAT_0601d36c);

  *(int *)0x0607887F = 0;

  (*(int(*)())0x060149CC)();

  return;

}

void FUN_0601d3c0()
{

  char *puVar1;

  puVar1 = (char *)0x0605AB16;

  if ((*(int *)0x06086024 == 0) && ((*(unsigned short *)0x06063D9A & DAT_0601d444) != 0)) {

    if ((char *)(unsigned int)*(unsigned short *)0x06063D98 == 0x0000AAA8) {

      *(int *)0x0605AB16 = *(int *)0x0605AB16 | 7;

    }

    if ((unsigned int)*(unsigned short *)0x06063D98 == (int)DAT_0601d446) {

      *puVar1 = *puVar1 | 7;

      *(int *)0x0605AB17 = *(int *)0x0605AB17 | 7;

    }

    (*(int(*)())0x06014884)(0x20,0);

    (*(int(*)())0x06028400)(0xc,0x06094FA8,0);

    *(int *)0x0607EBCC = 0xc;

    *(int *)0x0607887F = 4;

    *(int *)0x06086024 = 1;

  }

  (*(int(*)())(*(int *)(0x0605DF80 + (unsigned int)(unsigned char)*(int *)(0x0607887F << 2))))();

  return;

}

void FUN_0601d57c(param_1)
    unsigned short param_1;
{
  register char *dest asm("r2") = (char *)0x0605AAA6;
  register char *src asm("r3") = (char *)0x06094FAC;
  unsigned short uVar3;
  int srcOff;
  int destOff;

  uVar3 = 0;
  do {
    destOff = uVar3 << 2;
    srcOff = uVar3 * 0x58 + (param_1 << 1);
    uVar3 = uVar3 + 1;

    *(short *)(dest + destOff) = *(short *)(src + srcOff);
    *(short *)(dest + destOff + 2) = *(short *)(src + srcOff + 2);
  } while (uVar3 < 0x1c);

  (*(void(*)())0x06028400)(0xc, 0x0605AAA2, (param_1 & 0x3f) << 1, 0);
}

int FUN_0601d5f4(param_1, param_2)
    int param_1;
    unsigned int param_2;
{

  int iVar1;

  int iVar2;

  iVar1 = SOUND_TIMEOUT_FLAG;

  if (SOUND_TIMEOUT_FLAG == 0) {

    iVar1 = param_1;

    if (param_1 == 0) {

      if ((param_2 & 0xA0000000) == 0xA0000000) {

        iVar1 = FUN_0601db84();

        SCSP_MAILBOX = param_2;

        SOUND_CMD_MIRROR = param_2;

      }

    }

    else {

      if (param_1 == 1) {

        iVar2 = 0xA07000FF + (param_2 << 8);

        iVar1 = 1;

        if (SOUND_CHAN_STATE != iVar2) {

          iVar1 = FUN_0601db84();

          SOUND_CHAN_STATE = iVar2;

          SOUND_CMD_MIRROR = iVar2;

          SCSP_MAILBOX = iVar2;

        }

        return iVar1;

      }

      if (param_1 == 2) {

        iVar2 = 0xA17000FF + (param_2 << 8);

        iVar1 = 2;

        if (*(int *)0x0605DF98 != iVar2) {

          iVar1 = FUN_0601db84();

          *(int *)0x0605DF98 = iVar2;

          SOUND_CMD_MIRROR = iVar2;

          SCSP_MAILBOX = iVar2;

        }

        return iVar1;

      }

      if (param_1 == 3) {

        iVar2 = 0xA27000FF + (param_2 << 8);

        iVar1 = 3;

        if (*(int *)0x0605DF9C != iVar2) {

          iVar1 = FUN_0601db84();

          *(int *)0x0605DF9C = iVar2;

          SOUND_CMD_MIRROR = iVar2;

          SCSP_MAILBOX = iVar2;

        }

        return iVar1;

      }

      if (param_1 == 4) {

        iVar1 = 4;

        if (*(unsigned int *)0x0605DFA4 != param_2) {

          iVar1 = FUN_0601db84();

          *(unsigned int *)0x0605DFA4 = param_2;

          SOUND_CMD_MIRROR = param_2;

          SCSP_MAILBOX = param_2;

        }

        return iVar1;

      }

      if (param_1 == 5) {

        iVar2 = 0xA37000FF + (param_2 << 8);

        iVar1 = 5;

        if (*(int *)0x0605DFA8 != iVar2) {

          iVar1 = FUN_0601db84();

          *(int *)0x0605DFA8 = iVar2;

          SOUND_CMD_MIRROR = iVar2;

          SCSP_MAILBOX = iVar2;

        }

        return iVar1;

      }

      if ((param_1 == 0xf) && ((param_2 & 0xA0000000) == 0xA0000000)) {

        iVar1 = FUN_0601db84();

        SCSP_MAILBOX = param_2;

        SOUND_CMD_MIRROR = param_2;

      }

    }

  }

  return iVar1;

}

int FUN_0601d7d0()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  int uVar5;

  int iVar6;

  int iVar7;

  puVar4 = (char *)0x06086058;

  puVar3 = (char *)0x06087060;

  puVar2 = (char *)0x0607EAD8;

  puVar1 = (char *)0x06086054;

  iVar7 = *(int *)(0x0604A50C +

                  *(int *)(0x0605AD00 << 2) +

                  (int)(char)((char)CAR_COUNT * '\f'));

  iVar6 = CAR_PTR_TARGET;

  if (*(int *)0x06085FF4 == '\0') {

    if ((CAR_COUNT == 0) && (iVar7 - *(int *)(iVar6 + PTR_DAT_0601d884) < 9)) {

      if ((*(int *)0x06087060 == '\0') && (COURSE_SELECT != 0)) {

        *(int *)0x06087060 = 1;

        *(short *)puVar4 = 0;

      }

      else {

        *(short *)0x06086058 = *(short *)0x06086058 + 1;

      }

    }

    if ((*(int *)puVar2 == 1) && (iVar7 - *(int *)(iVar6 + DAT_0601d974) < 5)) {

      if ((*puVar3 == '\0') && (COURSE_SELECT != 0)) {

        *puVar3 = 1;

      }

      else {

        *(short *)puVar4 = *(short *)puVar4 + 1;

      }

    }

    if ((*(int *)puVar2 == 2) && (iVar7 - *(int *)(iVar6 + DAT_0601d974) < 3)) {

      if ((*puVar3 == '\0') && (COURSE_SELECT != 0)) {

        *puVar3 = 1;

      }

      else {

        *(short *)puVar4 = *(short *)puVar4 + 1;

      }

    }

    puVar2 = (char *)0x06086056;

    if ((int)(iVar7 + (unsigned int)(iVar7 < 0)) >> 1 < *(int *)(iVar6 + DAT_0601d974) + 1) {

      if ((*(int *)(iVar6 + DAT_0601d974) == *(int *)0x06063F28 + -1) &&

         (*(int *)0x06086034 == 0)) {

        uVar5 = FUN_0601d5f4(0,0xAE1121FF);

        *(short *)puVar2 = (char *)0x50;

        *(short *)puVar1 = (char *)0x50;

        *(int *)0x06086034 = 1;

      }

      else {

        uVar5 = FUN_0601d5f4(0,0xAE1127FF);

        *(short *)puVar1 = PTR_DAT_0601da3c;

        *(short *)puVar2 = (char *)0x14;

      }

    }

    else {

      uVar5 = FUN_0601d5f4(0,0xAE1126FF);

      *(short *)puVar1 = DAT_0601d976;

      *(short *)puVar2 = (char *)0x14;

    }

  }

  else {

    if ((*(int *)(iVar6 + PTR_DAT_0601d884) != *(int *)0x06063F28 + -1) ||

       (*(int *)0x06086034 != 0)) {

      uVar5 = FUN_0601d5f4(0,0xAE1146FF);

      return uVar5;

    }

    uVar5 = FUN_0601d5f4(0,0xAE1121FF);

    *(short *)puVar1 = (char *)0x50;

    *(int *)0x06086034 = 1;

  }

  return uVar5;

}

unsigned int FUN_0601d9b0()
{

  short sVar1;

  unsigned short uVar2;

  char *puVar3;

  int uVar4;

  char *puVar5;

  unsigned int uVar6;

  short uVar7;

  puVar3 = (char *)0x06086054;

  if ((int)(char)*(int *)0x06085FF4 != 0) {

    return (int)(char)*(int *)0x06085FF4;

  }

  if (((*(short *)0x06086056 == 0) || (*(int *)0x0608605A == '\x01')) ||

     (sVar1 = *(short *)0x06086056, *(short *)0x06086056 = sVar1 + -1,

     uVar4 = 0xAE112BFF, sVar1 != 1)) goto LAB_0601db20;

  if (CAR_COUNT != 0) {

    if (CAR_COUNT == 1) {

      sVar1 = *(short *)0x06086058;

      if (sVar1 == 1) {

        *(short *)0x06086056 = 0;

        FUN_0601d5f4(0,uVar4);

      }

      else if (sVar1 == 3) {

        *(short *)0x06086056 = 0;

        FUN_0601d5f4(0,uVar4);

      }

      else {

        if (sVar1 != 6) {

          *(short *)puVar3 = 100;

          goto LAB_0601db20;

        }

        *(short *)0x06086056 = 0;

        FUN_0601d5f4(0,0xAE112DFF);

      }

      *(short *)puVar3 = (char *)0x28;

    }

    else if ((CAR_COUNT == 2) && (*(short *)0x06086058 == 8)) {

      *(short *)0x06086056 = 0;

      FUN_0601d5f4(0,0xAE112FFF);

      *(short *)puVar3 = (char *)0x28;

    }

    goto LAB_0601db20;

  }

  sVar1 = *(short *)0x06086058;

  if (sVar1 == 1) {

    *(short *)0x06086056 = 0;

    FUN_0601d5f4(0,0xAE1129FF);

LAB_0601da72:

    uVar7 = 0x28;

  }

  else {

    if (sVar1 == 2) {

      *(short *)0x06086056 = 0;

      FUN_0601d5f4(0,uVar4);

      goto LAB_0601da72;

    }

    if (sVar1 == 3) {

      *(short *)0x06086056 = 0;

      FUN_0601d5f4(0,0xAE112AFF);

      uVar7 = 0x14;

    }

    else {

      if (sVar1 == 4) {

        *(short *)0x06086056 = 0;

        FUN_0601d5f4(0,uVar4);

        goto LAB_0601da72;

      }

      if (sVar1 == 5) {

        *(short *)0x06086056 = 0;

        FUN_0601d5f4(0,0xAE112CFF);

        uVar7 = 0x14;

      }

      else {

        if (sVar1 != 6) {

          *(short *)puVar3 = 100;

          goto LAB_0601db20;

        }

        *(short *)0x06086056 = 0;

        FUN_0601d5f4(0,uVar4);

        uVar7 = 0x28;

      }

    }

  }

  *(short *)puVar3 = uVar7;

LAB_0601db20:

  puVar5 = (char *)0x0608605A;

  uVar6 = (unsigned int)(unsigned char)*(int *)0x0608605A;

  if (uVar6 == 1) {

    uVar2 = *(unsigned short *)0x06086056;

    *(unsigned short *)0x06086056 = uVar2 - 1;

    uVar6 = (unsigned int)uVar2;

    if (uVar6 == 1) {

      *puVar5 = 0;

      *(short *)0x06086056 = 0;

      *(short *)puVar3 = (char *)0x28;

      uVar6 = FUN_0601d5f4(0,0xAE1120FF);

      return uVar6;

    }

  }

  return uVar6;

}

int FUN_0601db84()
{
  register int *dest asm("r7") = (int *)0x06086050;
  register int *src asm("r6") = (int *)0x25A02C20;
  register int val asm("r5") = 1;
  register int count asm("r4") = 0x000186A0;

L:
  if (--count == 0) {
    *dest = val;
  }
  else if (*src != 0) goto L;
}

int FUN_0601dbb8()
{

  char cVar1;

  short sVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  char *puVar6;

  char *puVar7;

  char *puVar8;

  char *puVar9;

  int uVar10;

  int iVar11;

  char *puVar12;

  puVar8 = (char *)0x06087070;

  puVar7 = (char *)0x06087068;

  puVar6 = (char *)0x06087074;

  puVar5 = (char *)0x06028400;

  puVar4 = (char *)0x0608706C;

  puVar3 = (char *)0x00009000;

  if (*(int *)0x060786AC != 0) {

    uVar10 = FUN_0601ddf6();

    return uVar10;

  }

  if ((((unsigned int)(*(int *)0x06087068 == '\0') & *(unsigned int *)0x0607EBF4) != 0) ||

     (((unsigned int)((((int *)0x06078900)[3] & 8) == 0) &

      (unsigned int)(*(int *)0x06087068 == '\0') & *(unsigned int *)0x0607EABC) != 0)) {

    *(int *)0x06087068 = 1;

    *(short *)0x0608706A = DAT_0601dd30;

    *(int *)0x0605DFED = 0;

    *(int *)puVar8 = *(int *)0x060786A0;

    puVar12 = (char *)0x0605DDB4;

    *(int *)puVar6 = 3;

    puVar9 = (char *)0x0605DDD4;

    if (CAR_COUNT == 2) {

      *(int *)puVar6 = 6;

      puVar12 = puVar9;

    }

    iVar11 = (*(int(*)())0x060350B0)();

    *(int *)puVar4 = *(int *)(puVar12 + (iVar11 << 2));

    *(int *)0x0608707C = 9;

    if (*(unsigned int *)puVar8 < *(unsigned int *)puVar4) {

      *(int *)0x0608707C = 10;

      *(int *)puVar4 = *(int *)puVar8;

      iVar11 = (*(int(*)())0x060350B0)();

      *(int *)(puVar12 + (iVar11 << 2)) = *(int *)puVar8;

    }

  }

  if (*puVar7 == '\0') {

    uVar10 = 0;

  }

  else {

    cVar1 = *(int *)0x0605DFED;

    *(int *)0x0605DFED = cVar1 + 0x30U;

    puVar6 = (char *)0x060639F8;

    if ((short)(unsigned short)(unsigned char)(cVar1 + 0x30U) < DAT_0601dd34) {

      iVar11 = (*(int(*)())0x060350B0)();

      (*(int(*)())puVar5)(8,0x0605E008 + iVar11 * 0xe);

      puVar12 = (char *)0x060639E0;

      (*(int(*)())puVar5)(8,*(int *)0x060639D8,0x842,

                        *(int *)(0x060639E0 + 4) + (unsigned int)(unsigned char)*(int *)(0x0608707C << 12));

      (*(int(*)())puVar5)(8,*(int *)puVar12,0x942,puVar3 + *(int *)(puVar12 + 4));

      FUN_0601e26c(*(int *)puVar4);

      (*(int(*)())puVar5)(8,0x0605DFF4,(int)DAT_0601de24,puVar3 + *(int *)(puVar6 + 4));

      if (*(char **)puVar8 < 0x000927BF) {

        FUN_0601e26c(*(int *)puVar8);

      }

      else {

        FUN_0601e26c(0x000927BF);

      }

      uVar10 = (*(int(*)())puVar5)(8,0x0605DFF4,(int)DAT_0601de26,

                                 puVar3 + *(int *)(0x060639F8 + 4));

    }

    else {

      uVar10 = FUN_0601ddf6();

    }

    sVar2 = *(short *)0x0608706A;

    *(short *)0x0608706A = sVar2 + -1;

    if ((short)(sVar2 + -1) == 0) {

      *puVar7 = 0;

      uVar10 = FUN_0601ddf6();

      return uVar10;

    }

  }

  return uVar10;

}

int FUN_0601ddf6()
{
  register int ptr asm("r0") = 0x0605ACE3;
  register int func1 asm("r3") = 0x060284AE;

  (*(int(*)())func1)(8, 0x7c2, 0x90, ptr);
  (*(int(*)())func1)(8, 0x8c2, 0x90, ptr);
  (*(void(*)())0x060283E0)(8, 0x9c2, 0xE000, ptr);
}

int FUN_0601de50()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  int uVar5;

  int *puVar6;

  if ((char *)(GAME_STATE_VAR * 5) < 0x000927BF) {

    FUN_0601e26c();

  }

  else {

    FUN_0601e26c(0x000927BF);

  }

  puVar2 = (char *)0x06028400;

  puVar1 = (char *)0x06063750;

  (*(int(*)())0x06028400)(8,0x0605DFF4,(int)DAT_0601df16,

             0x00009000 + *(int *)(0x06063750 + DAT_0601df14));

  puVar3 = (char *)0x06078900;

  uVar5 = 0;

  if (*(unsigned int *)(0x06078900 + DAT_0601df18) < *(unsigned int *)0x06086008 &&

      *(int *)(0x06078900 + DAT_0601df1a) != 0) {

    *(int *)

     (*(int *)(0x0605DE24 + (*(int *)(0x0607EAD8 << 1) + DEMO_MODE_FLAG) << 2) + 4

     ) = *(int *)(0x06078900 + DAT_0601df18);

    puVar6 = (int *)(puVar1 + DAT_0601df1c);

    (*(int(*)())puVar2)(8,*puVar6,0x3c2,0x0000A000 + puVar6[1]);

    puVar4 = (char *)0x0605DFEC;

    *(int *)0x0605DFEC = *(int *)0x0605DFEC + '@';

    if ((char)*puVar4 < '\0') {

      uVar5 = (*(int(*)())0x060283E0)(8,0x442,0x0000E000,0x0605ACE3);

      return uVar5;

    }

    FUN_0601e26c(*(int *)(puVar3 + DAT_0601df18));

    uVar5 = (*(int(*)())puVar2)(8,0x0605DFF4,(int)PTR_DAT_0601df20,

                              0x0000A000 + *(int *)(puVar1 + DAT_0601df14));

  }

  return uVar5;

}

int FUN_0601df88()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  char *puVar6;

  int uVar7;

  int iVar8;

  puVar5 = (char *)0x06028400;

  puVar4 = (char *)0x0607863C;

  puVar3 = (char *)0x06063750;

  puVar2 = (char *)0x000927BF;

  puVar1 = (char *)0x0000A000;

  iVar8 = 0x2a8;

  if (*(unsigned int *)(0x06078900 + iVar8 + -0x68) < *(unsigned int *)0x06086008) {

    (*(int(*)())0x06028400)(8,*(int *)(0x06063750 + DAT_0601e024),0x3c2,

               0x0000A000 + *(int *)((int)(0x06063750 + DAT_0601e024) + 4));

    FUN_0601e26c(*(int *)(0x06078900 + DAT_0601e028));

    (*(int(*)())puVar5)(8,0x0605DFF4,(int)DAT_0601e02a,puVar1 + *(int *)(puVar3 + iVar8 + 4));

  }

  FUN_0601e26c(*(int *)puVar4);

  uVar7 = (*(int(*)())puVar5)(8,0x0605DFF4,(int)DAT_0601e02c,

                            0x00009000 + *(int *)(puVar3 + iVar8 + 4));

  if (*(unsigned int *)puVar4 < *(unsigned int *)0x06086004) {

    (*(int(*)())puVar5)(8,*(int *)(puVar3 + DAT_0601e02e),0x4c2,

                      puVar1 + *(int *)((int)(puVar3 + DAT_0601e02e) + 4));

    if (*(char **)puVar4 < puVar2) {

      FUN_0601e26c(*(int *)puVar4);

    }

    else {

      FUN_0601e26c(puVar2);

    }

    (*(int(*)())puVar5)(8,0x0605DFF4,(int)DAT_0601e0e2,

                      0x00009000 + *(int *)(puVar3 + iVar8 + 4));

    puVar6 = (char *)0x0605DFEC;

    *(int *)0x0605DFEC = *(int *)0x0605DFEC + '@';

    if ((char)*puVar6 < '\0') {

      uVar7 = (*(int(*)())0x060283E0)(8,0x542,0x0000E000,0x0605ACE3);

      return uVar7;

    }

    if (*(char **)puVar4 < puVar2) {

      FUN_0601e26c(*(int *)puVar4);

    }

    else {

      FUN_0601e26c(puVar2);

    }

    uVar7 = (*(int(*)())puVar5)(8,0x0605DFF4,(int)DAT_0601e0e4,

                              puVar1 + *(int *)(puVar3 + iVar8 + 4));

  }

  return uVar7;

}
