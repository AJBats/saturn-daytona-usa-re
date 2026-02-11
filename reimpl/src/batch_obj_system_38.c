#include "game.h"

extern int DAT_06038106;
extern int DAT_06038108;
extern int DAT_0603881a;
extern int DAT_06038932;
extern int DAT_060389f2;
extern int DAT_06038a9a;
extern int DAT_06038a9e;
extern int DAT_06038cc8;
extern int DAT_06038cca;
extern int DAT_06038cce;
extern int DAT_06038cd0;
extern int DAT_06038cd2;
extern int DAT_06038cd4;
extern int DAT_06038cd6;
extern int DAT_06038e1a;
extern int DAT_06038efa;
extern int DAT_06038efc;
extern int DAT_0603918c;
extern int DAT_0603918e;
extern int DAT_060392e6;
extern int DAT_060395b6;
extern int DAT_060397f4;
extern int DAT_060397f6;
extern int DAT_060397f8;
extern void FUN_060388c0();
extern void FUN_06038a48();
extern void FUN_06038ac8();
extern unsigned short FUN_0603931c();
extern void FUN_060393fc();
extern void FUN_060394f0();
extern int FUN_0603a6c0();
extern int FUN_0603a72c();
extern int FUN_0603a766();
extern int PTR_DAT_060388b4;
extern int PTR_DAT_06038934;
extern int PTR_DAT_06038e20;
extern int PTR_DAT_06039190;
extern int PTR_DAT_0603923c;
extern int PTR_DAT_060392e8;

void FUN_0603806c(param_1)
    char *param_1;
{

  char *puVar1;

  int uVar2;

  char *puVar3;

  int extraout_r3 = 0;

  int uVar4;

  unsigned int uVar5;

  int iVar6;

  int iVar7;

  char *puVar8;

  int *piVar9;

  int local_30 [8];

  char local_10 [4];

  puVar1 = (char *)0x00010000;

  puVar8 = local_10;

  iVar7 = 0x200;

  uVar4 = 0;

  param_1[2] = 0;

  param_1[1] = 0;

  *param_1 = 0;

  param_1[3] = 0;

  *(int *)(param_1 + 8) = 0;

  *(int *)(param_1 + 0xc) = 0;

  param_1[4] = 0;

  uVar5 = 0;

  do {

    if ((uVar5 & 0xffff) < 0x40) {

      *(int *)(param_1 + ((uVar5 & 0xffff) << 2) + (int)DAT_06038108) = uVar4;

    }

    iVar6 = (int)(short)((short)uVar5 * 0xc);

    *(int *)(param_1 + iVar6 + 0x10) = uVar4;

    *(char **)(puVar8 + -0x14) = puVar8 + -0x14;

    (*(int(*)())0x06035BC8)();

    *(int *)(puVar8 + -0x18) = 0;

    *(int *)(puVar8 + -0x1c) = 0x40F00000;

    puVar3 = puVar8 + -0xc;

    piVar9 = (int *)(puVar8 + -0x20);

    puVar8 = puVar8 + -0x20;

    *piVar9 = (int)puVar3;

    (*(int(*)())0x060359E4)();

    uVar2 = (*(int(*)())0x060357B8)();

    uVar5 = uVar5 + 1;

    *(int *)(extraout_r3 + 4) = uVar2;

    *(char **)(param_1 + iVar6 + 0x18) = puVar1;

  } while ((int)(uVar5 & 0xffff) < iVar7);

  return;

}

void FUN_06038300()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  unsigned int uVar5;

  unsigned short uVar6;

  unsigned short uVar7;

  (*(int(*)())0x06038F34)();

  puVar1 = (char *)0x060A4C60;

  *(int *)0x060A4C60 = 0;

  *(int *)(puVar1 + 4) = 0;

  puVar1 = (char *)0x060A4C68;

  *(int *)0x060A4C68 = 0;

  *(int *)(puVar1 + 4) = 0;

  puVar1 = (char *)0x060A4C78;

  *(int *)0x060A4C78 = 0;

  *(int *)(puVar1 + 4) = 0;

  puVar1 = (char *)0x060A4C40;

  *(short *)0x060A4C40 = 0;

  *(short *)(puVar1 + 2) = 0;

  puVar1 = (char *)0x060A4C54;

  *(short *)0x060A4C54 = 0;

  *(short *)(puVar1 + 2) = 0;

  puVar1 = (char *)0x060A4C44;

  *(int *)0x060A4C44 = 0;

  *(int *)(puVar1 + 4) = 0;

  puVar1 = (char *)0x060A4C4C;

  *(int *)0x060A4C4C = 0;

  puVar2 = (char *)0x0603C104;

  *(int *)(puVar1 + 4) = 0;

  (*(int(*)())puVar2)();

  puVar3 = (char *)0x060A3DB0;

  puVar2 = (char *)0x060A3D88;

  puVar1 = (char *)0x0000FFFF;

  *(char **)0x060A3D84 = 0x25F80000;

  puVar4 = (char *)0x00008000;

  *(short *)puVar2 = (short)0x00008000;

  *(short *)(puVar2 + 2) = 0;

  *(short *)(puVar2 + 6) = 0;

  *(short *)(puVar2 + 0xc) = 0;

  *(short *)(puVar2 + 0xe) = (short)((unsigned int)puVar4 >> 2);

  uVar7 = 0;

  do {

    uVar5 = (unsigned int)uVar7;

    uVar7 = uVar7 + 1;

    *(short *)(puVar2 + (uVar5 << 1) + 0x10) = (short)puVar1;

  } while (uVar7 < 8);

  *(short *)(puVar2 + 0x20) = 0;

  *(short *)(puVar2 + 0x22) = 0;

  *(short *)(puVar2 + 0x24) = 0;

  *(short *)(puVar2 + 0x26) = 0;

  *(short *)puVar3 = 0;

  *(short *)(puVar3 + 2) = 0;

  *(short *)(puVar3 + 4) = 0;

  *(short *)(puVar3 + 6) = 0;

  *(short *)(puVar3 + 8) = 0;

  *(short *)(puVar3 + 10) = 0;

  *(short *)(puVar3 + 0xc) = 0;

  *(short *)(puVar3 + 0xe) = 0;

  *(short *)(puVar3 + 0x10) = 0;

  *(short *)(puVar3 + 0x12) = 0;

  uVar6 = 0;

  *(short *)(puVar3 + 0x14) = 0;

  *(short *)(puVar3 + 0x16) = 0;

  uVar7 = uVar6;

  do {

    uVar5 = (unsigned int)uVar7;

    uVar7 = uVar7 + 1;

    *(short *)(puVar3 + (uVar5 << 1) + 0x18) = 0;

  } while (uVar7 < 8);

  do {

    uVar5 = (unsigned int)uVar6;

    uVar6 = uVar6 + 1;

    *(short *)(puVar3 + (uVar5 << 1) + 0x28) = 0;

    puVar1 = (char *)0x060A3DF8;

  } while (uVar6 < 0x10);

  *(int *)0x060A3DF8 = 0;

  *(int *)(puVar1 + 4) = 0;

  puVar2 = (char *)0x00010000;

  *(char **)(puVar1 + 8) = 0x00010000;

  *(char **)(puVar1 + 0xc) = puVar2;

  *(int *)(puVar1 + 0x10) = 0;

  *(int *)(puVar1 + 0x14) = 0;

  *(char **)(puVar1 + 0x18) = puVar2;

  *(char **)(puVar1 + 0x1c) = puVar2;

  *(short *)(puVar1 + 0x20) = 0;

  *(short *)(puVar1 + 0x22) = 0;

  *(short *)(puVar1 + 0x24) = 0;

  *(short *)(puVar1 + 0x26) = 0;

  *(short *)(puVar1 + 0x28) = 0;

  *(short *)(puVar1 + 0x2a) = 0;

  *(int *)(puVar1 + 0x2c) = 0;

  *(int *)(puVar1 + 0x30) = 0;

  *(int *)(puVar1 + 0x34) = 0;

  *(int *)(puVar1 + 0x38) = 0;

  *(int *)(puVar1 + 0x3c) = 0;

  puVar1 = (char *)0x060A3E38;

  *(short *)0x060A3E38 = 0;

  *(short *)(puVar1 + 2) = 0;

  *(short *)(puVar1 + 4) = 0;

  *(short *)(puVar1 + 6) = 0;

  *(short *)(puVar1 + 8) = 0;

  *(short *)(puVar1 + 10) = 0;

  *(int *)(puVar1 + 0xc) = 0;

  puVar1 = (char *)0x060A3E48;

  *(short *)0x060A3E48 = 0;

  *(short *)(puVar1 + 2) = 0;

  *(short *)(puVar1 + 4) = 0;

  *(short *)(puVar1 + 6) = 0;

  *(short *)(puVar1 + 8) = 0;

  *(short *)(puVar1 + 10) = 0;

  *(short *)(puVar1 + 0xc) = 0;

  *(short *)(puVar1 + 0xe) = 0;

  *(short *)(puVar1 + 0x10) = 0;

  *(short *)(puVar1 + 0x12) = 0;

  *(short *)(puVar1 + 0x14) = 0;

  *(short *)(puVar1 + 0x16) = 0;

  *(int *)(puVar1 + 0x18) = 0;

  *(int *)(puVar1 + 0x1c) = 0;

  if (VDP1_BATCH_FLAG == 0) {

    VDP1_BATCH_FLAG = 1;

  }

  return;

}

void FUN_0603850c(param_1)
    int param_1;
{

  if (VDP1_BATCH_FLAG == 1) {

    VDP1_BATCH_FLAG = 0;

  }

  *(int *)0x060635A8 = param_1;

  return;

}

/* vdp1_batch_request -- Request VDP1 batch processing if not already queued */
void FUN_06038520(void)
{
    if (VDP1_BATCH_FLAG == 0) {
        VDP1_BATCH_FLAG = 1;
    }
}

void FUN_0603853c(param_1, param_2, param_3)
    int param_1;
    int param_2;
    int param_3;
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  int iVar5;

  short uVar6;

  puVar4 = (char *)0x060A3EE8;

  puVar3 = (char *)0x060A3E68;

  puVar2 = (char *)0x060A3DF8;

  puVar1 = (char *)0x060A4C78;

  iVar5 = *(int *)0x060635A8;

  if (iVar5 == 1) {

    *(int *)(0x060A3E68 + 0x44) = param_1;

    *(int *)(puVar3 + 0x48) = param_2;

    if ((*(int *)0x060A4C44 == 0) ||

       ((*(int *)0x060A4C4C != 0 && (*(int *)0x060A4C70 != 0)))) {

      *(int *)puVar1 = 0;

    }

    else {

      *(int *)puVar1 = param_3;

    }

    if (*(int *)puVar1 != 0) {

      (*(int(*)())0x0603DDFC)(0,0);

      return;

    }

  }

  else if (iVar5 == 2) {

    *(int *)(0x060A3EE8 + 0x44) = param_1;

    *(int *)(puVar4 + 0x48) = param_2;

    if ((*(int *)0x060A4C48 == 0) ||

       ((*(int *)0x060A4C50 != 0 && (*(int *)0x060A4C74 != 0)))) {

      *(int *)(puVar1 + 4) = 0;

    }

    else {

      *(int *)(puVar1 + 4) = param_3;

    }

    if (*(int *)(puVar1 + 4) != 0) {

      (*(int(*)())0x0603DDFC)(0,0);

      return;

    }

  }

  else if (iVar5 == 4) {

    *(int *)0x060A3DF8 = param_1;

    *(int *)(puVar2 + 4) = param_2;

  }

  else if (iVar5 == 8) {

    *(int *)(0x060A3DF8 + 0x10) = param_1;

    *(int *)(puVar2 + 0x14) = param_2;

  }

  else {

    uVar6 = (short)((unsigned int)param_1 >> 0x10);

    if (iVar5 == 0x10) {

      *(short *)(0x060A3DF8 + 0x20) = uVar6;

      iVar5 = 0x22;

    }

    else {

      if (iVar5 != 0x20) {

        return;

      }

      *(short *)(0x060A3DF8 + 0x24) = uVar6;

      iVar5 = 0x26;

    }

    *(short *)(puVar2 + iVar5) = (short)((unsigned int)param_2 >> 0x10);

  }

  return;

}

int FUN_06038642(param_1, param_2, param_3)
    int param_1;
    int param_2;
    int param_3;
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  int iVar5;

  short sVar6;

  short sVar7;

  puVar4 = (char *)0x060A3EE8;

  puVar3 = (char *)0x060A3E68;

  puVar2 = (char *)0x060A3DF8;

  puVar1 = (char *)0x060A4C78;

  iVar5 = *(int *)0x060635A8;

  if (iVar5 == 1) {

    *(int *)(0x060A3E68 + 0x44) = *(int *)(0x060A3E68 + 0x44) + param_1;

    *(int *)(puVar3 + 0x48) = *(int *)(puVar3 + 0x48) + param_2;

    if ((*(int *)0x060A4C44 == 0) ||

       ((*(int *)0x060A4C4C != 0 && (*(int *)0x060A4C70 != 0)))) {

      *(int *)puVar1 = 0;

    }

    else {

      *(int *)puVar1 = *(int *)puVar1 + param_3;

    }

    iVar5 = 0;

    if (*(int *)puVar1 != 0) {

      iVar5 = (*(int(*)())0x0603DDFC)(0,0);

      return iVar5;

    }

  }

  else if (iVar5 == 2) {

    *(int *)(0x060A3EE8 + 0x44) = *(int *)(0x060A3EE8 + 0x44) + param_1;

    *(int *)(puVar4 + 0x48) = *(int *)(puVar4 + 0x48) + param_2;

    if ((*(int *)0x060A4C48 == 0) ||

       ((*(int *)0x060A4C50 != 0 && (*(int *)0x060A4C74 != 0)))) {

      *(int *)(puVar1 + 4) = 0;

    }

    else {

      *(int *)(puVar1 + 4) = *(int *)(puVar1 + 4) + param_3;

    }

    iVar5 = 0;

    if (*(int *)(puVar1 + 4) != 0) {

      iVar5 = (*(int(*)())0x0603DDFC)(0,0);

      return iVar5;

    }

  }

  else if (iVar5 == 4) {

    *(int *)0x060A3DF8 = *(int *)0x060A3DF8 + param_1;

    *(int *)(puVar2 + 4) = *(int *)(puVar2 + 4) + param_2;

  }

  else if (iVar5 == 8) {

    *(int *)(0x060A3DF8 + 0x10) = *(int *)(0x060A3DF8 + 0x10) + param_1;

    *(int *)(puVar2 + 0x14) = *(int *)(puVar2 + 0x14) + param_2;

  }

  else {

    sVar6 = (short)((unsigned int)param_1 >> 0x10);

    sVar7 = (short)((unsigned int)param_2 >> 0x10);

    if (iVar5 == 0x10) {

      *(short *)(0x060A3DF8 + 0x20) = *(short *)(0x060A3DF8 + 0x20) + sVar6;

      *(short *)(puVar2 + 0x22) = *(short *)(puVar2 + 0x22) + sVar7;

      iVar5 = 0x22;

    }

    else if (iVar5 == 0x20) {

      *(short *)(0x060A3DF8 + 0x24) = *(short *)(0x060A3DF8 + 0x24) + sVar6;

      *(short *)(puVar2 + 0x26) = *(short *)(puVar2 + 0x26) + sVar7;

      iVar5 = 0x26;

    }

  }

  return iVar5;

}

void FUN_06038794(param_1, param_2)
    char *param_1;
    char *param_2;
{

  char *puVar1;

  char *puVar2;

  short sVar3;

  int iVar4;

  char *puVar5;

  char *puVar6;

  char *puVar7;

  puVar2 = (char *)0x00010000;

  puVar1 = (char *)0x0603C0A0;

  puVar5 = (char *)(int)DAT_0603881a;

  iVar4 = *(int *)0x060635A8;

  puVar6 = param_2;

  puVar7 = param_1;

  if ((iVar4 != 1) && (iVar4 != 2)) {

    if ((iVar4 != 4) && (iVar4 != 8)) goto LAB_06038802;

    puVar7 = (char *)0x00FF0000;

    if ((((int)param_1 <= (int)0x00FF0000) && (puVar7 = puVar5, (int)puVar5 <= (int)param_1))

       && (puVar7 = param_1, param_1 == (char *)0x0)) {

      puVar7 = (char *)0x00010000;

    }

    puVar6 = (char *)0x00FF0000;

    if ((((int)param_2 <= (int)0x00FF0000) && (puVar6 = puVar5, (int)puVar5 <= (int)param_2))

       && (puVar6 = param_2, param_2 == (char *)0x0)) {

      puVar6 = (char *)0x00010000;

    }

  }

  param_1 = (char *)(*(int(*)())0x0603C0A0)(0x00010000,puVar7);

  param_2 = (char *)(*(int(*)())puVar1)(puVar2,puVar6);

LAB_06038802:

  sVar3 = PTR_DAT_060388b4;

  puVar6 = (char *)0x060A3DF8;

  puVar2 = (char *)0x060A3E68;

  puVar1 = (char *)0x060A3E38;

  iVar4 = *(int *)0x060635A8;

  if (iVar4 == 1) {

    *(char **)(0x060A3E68 + 0x4c) = param_1;

    *(char **)(puVar2 + 0x50) = param_2;

    if ((*(unsigned short *)(puVar1 + 4) & 0xff) != 0) {

      (*(int(*)())0x0603DDFC)(0,0);

      return;

    }

  }

  else if (iVar4 == 2) {

    *(char **)(0x060A3E68 + PTR_DAT_060388b4 + 0x4c) = param_1;

    *(char **)(puVar2 + sVar3 + 0x50) = param_2;

    if (((unsigned int)*(unsigned short *)(puVar1 + 4) & (unsigned int)0x0000FF00) != 0) {

      (*(int(*)())0x0603DDFC)(0,0);

      return;

    }

  }

  else if (iVar4 == 4) {

    *(char **)(0x060A3DF8 + 8) = param_1;

    *(char **)(puVar6 + 0xc) = param_2;

  }

  else if (iVar4 == 8) {

    *(char **)(0x060A3DF8 + 0x18) = param_1;

    *(char **)(puVar6 + 0x1c) = param_2;

  }

  return;

}

void FUN_060388c0()
{

  char *puVar1;

  puVar1 = (char *)0x060A4C40;

  if ((*(short *)0x060A4C40 != 0) && (*(int *)0x060A4C44 != 0)) {

    FUN_06038a48(*(int *)0x060A4C44,0x060A3F68,*(int *)0x060A4C38 << 1);

    *(short *)puVar1 = 0;

  }

  if ((*(short *)(puVar1 + 2) != 0) && (*(int *)0x060A4C48 != 0)) {

    FUN_06038a48(*(int *)0x060A4C48,0x060A45D0,*(int *)0x060A4C3C << 1);

    *(short *)(puVar1 + 2) = 0;

  }

  if (*(int *)0x060635B2 == 1) {

    FUN_06038a48(*(int *)0x060A4C5C,0x060A3E68,0x80);

  }

  else if (*(int *)0x060635B2 == 2) {

    FUN_06038a48(*(int *)0x060A4C5C,0x060A3E68,0x100);

  }

  puVar1 = (char *)0x060A3D84;

  FUN_06038a48(*(int *)0x060A3D84,0x060A3D88,0x28);

  FUN_06038a48(*(int *)puVar1 + 0x28,0x060A3DB0,0x48);

  FUN_06038a48(*(int *)puVar1 + 0x70,0x060A3DF8,0x40);

  FUN_06038a48(*(int *)puVar1 + (int)0x00B000C0,0x060A3E38,0x10);

  FUN_06038a48(*(int *)puVar1 + 0xc0,0x060A3E48,0x20);

  return;

}

void FUN_060389a6()
{

  char *puVar1;

  puVar1 = (char *)0x060635AC;

  if (VDP1_BATCH_FLAG == 1) {

    FUN_060388c0();

  }

  else {

    if (VDP1_BATCH_FLAG != 2) goto LAB_06038a42;

    FUN_06038a48(*(int *)0x060A3D70,*(int *)0x060A3D74,

                 (unsigned int)*(unsigned short *)0x060635A0 * 0xc);

    FUN_06038a48(*(int *)0x060A3D78,*(int *)0x060A3D7C,

                 (unsigned int)*(unsigned short *)0x060635A2 << 2);

    FUN_060388c0();

  }

  *(short *)puVar1 = 0;

LAB_06038a42:

  FUN_06038ac8();

  return;

}

void FUN_06038a48(param_1, param_2, param_3)
    short *param_1;
    short *param_2;
    unsigned int param_3;
{

  unsigned int uVar1;

  

  uVar1 = 0;

  if (param_3 >> 1 != 0) {

    do {

      uVar1 = uVar1 + 1;

      *param_1 = *param_2;

      param_1 = param_1 + 1;

      param_2 = param_2 + 1;

    } while (uVar1 < param_3 >> 1);

  }

  return;

}

unsigned int FUN_06038a64(param_1)
    unsigned int param_1;
{

  unsigned short uVar1;

  if (param_1 == 0) {

    uVar1 = *(unsigned short *)(0x060A3D88 + 0xe) & DAT_06038a9a;

  }

  else if (param_1 == 1) {

    uVar1 = *(unsigned short *)(0x060A3D88 + 0xe) & DAT_06038a9a | 0x10002000;

  }

  else {

    if (param_1 != 2) goto LAB_06038ab0;

    uVar1 = *(unsigned short *)(0x060A3D88 + 0xe) & DAT_06038a9a | DAT_06038a9e;

  }

  param_1 = (unsigned int)uVar1;

  *(unsigned short *)(0x060A3D88 + 0xe) = uVar1;

LAB_06038ab0:

  if (VDP1_BATCH_FLAG == 0) {

    VDP1_BATCH_FLAG = 1;

  }

  return param_1;

}

void FUN_06038ac8()
{

  char *puVar1;

  puVar1 = (char *)0x060A4D58;

  (*(int(*)())0x0603C728)();

  if (((int)(char)*puVar1 & 0x80U) != 0) {

    FUN_06038a48(*(int *)0x0606360C,0x060A4D18,0x10);

    (*(int(*)())0x06034F78)();

  }

  if ((*puVar1 & 0x40) != 0) {

    FUN_06038a48(*(int *)0x06063610,0x060A4D28,8);

    (*(int(*)())0x06034F78)();

  }

  if ((*puVar1 & 0x20) != 0) {

    FUN_06038a48(*(int *)0x06063614,0x060A4D30,6);

    (*(int(*)())0x06034F78)();

  }

  if ((*puVar1 & 0x10) != 0) {

    FUN_06038a48(*(int *)0x06063618,0x060A4D36,8);

    (*(int(*)())0x06034F78)();

  }

  if ((*puVar1 & 8) != 0) {

    FUN_06038a48(*(int *)0x0606361C,0x060A4D3E,8);

    (*(int(*)())0x06034F78)();

  }

  if ((*puVar1 & 4) != 0) {

    FUN_06038a48(*(int *)0x06063620,0x060A4D46,0x10);

    (*(int(*)())0x06034F78)();

  }

  return;

}

void FUN_06038bd4(param_1, param_2)
    unsigned int param_1;
    unsigned int param_2;
{

  unsigned short uVar1;

  unsigned short uVar2;

  unsigned short uVar3;

  char *puVar4;

  char *puVar5;

  char *puVar6;

  short uVar7;

  unsigned short *puVar8;

  unsigned int uVar9;

  puVar6 = (char *)0x060A4D30;

  puVar5 = (char *)0x0000F0FF;

  puVar4 = (char *)0x0000FF00;

  uVar3 = DAT_06038cc8;

  uVar9 = 1;

  param_2 = param_2 & 0xff;

  uVar1 = (unsigned short)0x0000FFF0;

  puVar8 = (unsigned short *)0x060A4D28;

  if ((0x100 & param_1) != 0) {

    (*(int(*)())0x06034F78)();

    *puVar8 = *puVar8 & uVar1 | (unsigned short)param_2;

  }

  uVar2 = (unsigned short)puVar5;

  if ((0x200 & param_1) != 0) {

    (*(int(*)())0x06034F78)();

    *puVar8 = *puVar8 & uVar2 | (unsigned short)((param_2 & 0xffff) << 8);

  }

  if ((0x400 & param_1) != 0) {

    (*(int(*)())0x06034F78)();

    puVar8[1] = puVar8[1] & uVar1 | (unsigned short)param_2;

  }

  if ((0x800 & param_1) != 0) {

    (*(int(*)())0x06034F78)();

    puVar8[1] = puVar8[1] & uVar2 | (unsigned short)((param_2 & 0xff) << 8);

  }

  if (((int)DAT_06038cd4 & param_1) != 0) {

    (*(int(*)())0x06034F78)();

    puVar8[2] = puVar8[2] & uVar1 | (unsigned short)param_2;

  }

  if (((int)DAT_06038cd6 & param_1) != 0) {

    (*(int(*)())0x06034F78)();

    puVar8[2] = puVar8[2] & uVar2 | (unsigned short)((param_2 & 0xff) << 8);

  }

  if (((int)DAT_06038e1a & param_1) != 0) {

    (*(int(*)())0x06034F78)();

    puVar8[3] = puVar8[3] & uVar1 | (unsigned short)param_2;

  }

  if (((unsigned int)0x00008000 & param_1) != 0) {

    (*(int(*)())0x06034F78)();

    puVar8[3] = puVar8[3] & uVar2 | (unsigned short)((param_2 & 0xff) << 8);

  }

  uVar1 = (unsigned short)puVar4;

  if ((param_1 & 4) != 0) {

    (*(int(*)())0x06034F78)();

    *(unsigned short *)puVar6 = *(unsigned short *)puVar6 & uVar1 | (unsigned short)param_2;

  }

  if ((param_1 & 2) != 0) {

    (*(int(*)())0x06034F78)();

    *(unsigned short *)puVar6 = *(unsigned short *)puVar6 & uVar1 | (unsigned short)param_2;

  }

  if ((param_1 & 8) != 0) {

    (*(int(*)())0x06034F78)();

    *(unsigned short *)puVar6 = *(unsigned short *)puVar6 & uVar3 | (unsigned short)((param_2 & 0xffff) << 8);

  }

  if ((0x80 & param_1) != 0) {

    (*(int(*)())0x06034F78)();

    *(unsigned short *)puVar6 = *(unsigned short *)puVar6 & uVar3 | (unsigned short)((param_2 & 0xffff) << 8);

  }

  if ((param_1 & 0x10) != 0) {

    (*(int(*)())0x06034F78)();

    *(unsigned short *)(puVar6 + 2) = *(unsigned short *)(puVar6 + 2) & uVar1 | (unsigned short)param_2;

  }

  uVar7 = (short)param_2;

  if ((param_1 & 0x20) != 0) {

    (*(int(*)())0x06034F78)();

    uVar7 = (short)param_2;

    *(unsigned short *)(puVar6 + 2) = *(unsigned short *)(puVar6 + 2) & uVar3 | (unsigned short)((param_2 & 0xff) << 8);

  }

  if ((param_1 & uVar9) != 0) {

    (*(int(*)())0x06034F78)();

    *(short *)(puVar6 + 4) = uVar7;

  }

  return;

}

void FUN_06038e54(param_1)
    unsigned short param_1;
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  unsigned int uVar6;

  puVar5 = (char *)0x060635B8;

  puVar4 = (char *)0x060635B4;

  puVar3 = (char *)0x25D00002;

  puVar2 = (char *)0x060A4C92;

  puVar1 = (char *)0x060635BC;

  if ((char *)(unsigned int)param_1 == 0x0000FFFF) {

    FB_STATE = 2;

    *(int *)puVar5 = 0;

    *(unsigned short *)puVar3 = *(unsigned short *)puVar2 | 3;

    *(unsigned int *)puVar1 = (unsigned int)param_1;

  }

  else if ((char *)(unsigned int)param_1 == 0x0000FFFE) {

    FB_STATE = 3;

    *(int *)puVar5 = 0;

    *(unsigned short *)puVar3 = *(unsigned short *)puVar2 | 3;

    *(unsigned int *)puVar1 = (unsigned int)param_1;

  }

  else {

    if ((param_1 & DAT_06038efa) == 0) {

      *(int *)0x060635B8 = 1;

    }

    else {

      *(int *)0x060635B8 = 0;

    }

    uVar6 = (unsigned int)(param_1 & DAT_06038efc);

    if (uVar6 == 0) {

      *(short *)puVar4 = 0;

    }

    else {

      *(unsigned short *)puVar4 = (unsigned short)(uVar6 != 1);

    }

    *(unsigned int *)puVar1 = uVar6;

    if (*(short *)puVar4 == 0) {

      *(short *)puVar3 = *(short *)puVar2;

    }

    else {

      *(unsigned short *)puVar3 = *(unsigned short *)puVar2 | 3;

    }

  }

  return;

}

void FUN_06038f34()
{

  FB_STATE = 0;

  *(int *)0x060635B8 = 1;

  *(int *)0x060635BC = 0;

  FRAME_SEC_COUNTER = 0;

  FRAME_READY_FLAG = 0;

  *(int *)0x060635C8 = 0;

  return;

}

unsigned int FUN_06039100(unsigned int param_1,int param_2,unsigned int param_3,int param_4,short param_5,short param_6,short param_7,short param_8)
{

  char *puVar1;

  unsigned int uVar2;

  short *psVar3;

  short *psVar4;

  int iVar5;

  int uVar6;

  int iVar7;

  char *puVar8;

  char uStack_24;

  puVar8 = (char *)0x060A3E48;

  puVar1 = (char *)0x0603EDC4;

  param_1 = param_1 & 0xff;

  if (param_1 == 0) {

    *(int *)(0x060A3E48 + 0x18) = 0;

    psVar3 = (short *)(puVar8 + 4);

    uStack_24 = 2;

    iVar5 = (int)DAT_0603918c;

    uVar6 = 1;

    iVar7 = iVar5 + 1;

    psVar4 = (short *)puVar8;

  }

  else {

    if (param_1 != 1) {

      return param_1;

    }

    *(int *)(0x060A3E48 + 0x1c) = 0;

    psVar3 = (short *)(puVar8 + 0xc);

    uStack_24 = 8;

    iVar5 = (int)DAT_0603918e;

    uVar6 = 4;

    iVar7 = iVar5 + 4;

    psVar4 = (short *)(puVar8 + 8);

  }

  puVar8 = puVar8 + 0x10;

  if (0x160 < (int)(unsigned int)*(unsigned short *)0x060635AE) {

    *psVar4 = param_5;

    *psVar3 = param_7;

  }

  else {

    *psVar4 = param_5 << 1;

    *psVar3 = param_7 << 1;

  }

  psVar4[1] = param_6;

  psVar3[1] = param_8;

  if (param_2 != 0 || param_3 != 0) {

    (*(int(*)())puVar1)(param_2,param_3,puVar8,0x80,0x7f);

  }

  if (param_4 != 0 || param_3 != 0) {

    (*(int(*)())puVar1)(param_4,param_3,puVar8,uVar6,iVar7);

  }

  uVar2 = (*(int(*)())puVar1)(param_3,0xffffffff,puVar8,uStack_24,iVar5);

  if ((param_3 & (unsigned int)0x00010000) == 0) {

    *(short *)0x060A3E38 = *(short *)0x060A4C80;

  }

  else {

    *(short *)0x060A3E38 = 3;

  }

  if (VDP1_BATCH_FLAG == 0) {

    VDP1_BATCH_FLAG = 1;

  }

  return uVar2;

}

unsigned int FUN_06039250(param_1)
    int *param_1;
{

  char *puVar1;

  unsigned int uVar2;

  unsigned int in_sr = 0;

  unsigned int uVar3;

  uVar3 = in_sr & -241 & 0xfff0fff | 0xf0;

  FUN_060394f0(0);

  FUN_0603931c(0,0,0);

  VDP1_FBCR = FBCR_SHADOW;

  VDP1_PTMR = 2;

  VDP1_EWDR = (short)0x00008000;

  VDP1_EWLR = 0;

  VDP1_EWRR = (short)0x0000FFFF;

  FUN_060393fc(0x00008000,0,0,*(int *)0x060A4C88 - 1U & 0xffff,

               *(int *)0x060A4C8C - 1U & 0xffff);

  puVar1 = (char *)0x25C00000;

  *param_1 = (int)0x25C00000;

  *puVar1 = (char)PTR_DAT_060392e8;

  *(char *)(*param_1 + 1) = 0;

  uVar2 = (unsigned int)DAT_060392e6;

  *(int *)0x060635CC = 1;

  return (in_sr >> 4 & 0xf) << 4 | uVar3 & uVar2;

}

unsigned short FUN_0603931c(param_1, param_2, param_3)
    unsigned short param_1;
    unsigned short param_2;
    short param_3;
{

  char *puVar1;

  short *psVar2;

  puVar1 = (char *)0x060A4C8C;

  TVMR_SHADOW = param_1 & 7;

  VDP1_TVMR = param_1 & 7;

  if (7 < param_2) {

    param_2 = 0;

  }

  psVar2 = (short *)(0x060635E0 + (unsigned int)(param_2 << 2));

  *(int *)0x060A4C88 = (int)*psVar2;

  *(int *)puVar1 = (int)psVar2[1];

  if (param_3 == 1) {

    *(int *)puVar1 = *(int *)(int)puVar1 << 1;

  }

  if ((param_1 == 1) || (param_1 == 3)) {

    PALETTE_BANK_SEL = 1;

  }

  else {

    PALETTE_BANK_SEL = 0;

  }

  if (param_3 == 0) {

    *(short *)0x060A4C94 = 0;

  }

  else {

    *(short *)0x060A4C94 = 8;

  }

  *(short *)0x060A4C96 = 0;

  return param_1;

}

void FUN_060393fc(param_1, param_2, param_3, param_4, param_5)
    short param_1;
    unsigned short param_2;
    unsigned short param_3;
    short param_4;
    unsigned short param_5;
{

  unsigned short uVar1;

  *(short *)0x060635D4 = param_1;

  *(unsigned short *)0x060635D6 = param_2;

  *(unsigned short *)0x060635D8 = param_3;

  *(short *)0x060635DA = param_4;

  *(unsigned short *)0x060635DC = param_5;

  VDP1_EWDR = param_1;

  if (PALETTE_BANK_SEL == 0) {

    param_2 = param_2 >> 3;

  }

  else {

    param_2 = param_2 >> 4;

  }

  if (*(short *)0x060A4C94 != 0) {

    param_3 = param_3 >> 1;

  }

  *(unsigned short *)0x060635D0 = (param_2 << 9) + param_3;

  VDP1_EWLR = *(short *)0x060635D0;

  if (PALETTE_BANK_SEL == 0) {

    uVar1 = (unsigned short)(param_4 + 1U) >> 3;

  }

  else {

    uVar1 = (unsigned short)(param_4 + 1U) >> 4;

  }

  if (*(short *)0x060A4C94 != 0) {

    param_5 = param_5 >> 1;

  }

  *(unsigned short *)0x060635D2 = (uVar1 << 9) + param_5;

  VDP1_EWRR = *(short *)0x060635D2;

  return;

}

void FUN_060394f0(param_1)
    int param_1;
{

  if (param_1 == 0) {

    FBCR_SHADOW = 0;

  }

  else {

    FBCR_SHADOW = 0x10;

  }

  return;

}

void FUN_0603950c(char param_1,short param_2,char param_3,char param_4,int param_5,int param_6)
{

  char cVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  char *puVar6;

  char *puVar7;

  char *puVar8;

  unsigned short uVar9;

  int iVar10;

  puVar8 = (char *)0x20100079;

  puVar7 = (char *)0x060A4CB0;

  puVar6 = (char *)0x060A4CAC;

  puVar5 = (char *)0x060A4CC0;

  puVar4 = (char *)0x06063602;

  puVar3 = (char *)0x060A4CBC;

  puVar2 = (char *)0x060A4CAE;

  *(int *)0x20100079 = 0;

  puVar8[2] = 0;

  puVar8[6] = 0;

  puVar8[4] = 0;

  (*(int(*)())(BIOS_FUNC_0300))(0x47,0x0603990E);

  (*(int(*)())(BIOS_FUNC_0344))(-129,0);

  puVar8 = (char *)0x060A4CAA;

  *(int *)0x060A4CAA = param_1;

  cVar1 = *puVar8;

  if (cVar1 == '\0') {

    *puVar4 = 1;

    puVar4[1] = 0;

    *(int *)0x060A4CA8 = 0;

    (*(int(*)())0x0603A72C)();

    return;

  }

  if (cVar1 == '\x01') {

    *puVar4 = 0;

    puVar4[1] = 8;

  }

  else if (cVar1 == '\x02') {

    *puVar4 = 1;

    puVar4[1] = 8;

    *(int *)0x060A4CD8 = 0;

  }

  *puVar2 = param_4;

  *(short *)puVar6 = param_2;

  *(int *)0x060A4CAB = param_6;

  *(int *)0x060A4CAF = param_3;

  *(int *)puVar7 = param_5;

  *(int *)0x060A4CB8 = 0;

  if (0xf < (unsigned char)*puVar2) {

    puVar4[1] = puVar4[1] | 0x50;

  }

  puVar4 = (char *)0x060A4CD9;

  *(char **)0x060A4CE8 = 0x060A4CD9;

  *(char **)0x060A4C98 = puVar4 + 7;

  *(int *)puVar3 = *(int *)puVar7;

  puVar4 = (char *)0x060A4CC8;

  uVar9 = (unsigned short)(unsigned char)*(int *)0x060A4CAF;

  if (uVar9 == 0) {

    *(unsigned int *)puVar5 = (unsigned int)*(unsigned short *)puVar6 * 6 + *(int *)puVar7;

    *(unsigned int *)puVar4 = (unsigned int)*(unsigned short *)puVar6 * 0xc + *(int *)puVar7;

  }

  else if (uVar9 == 0x10) {

    *(unsigned int *)puVar5 = (unsigned int)*(unsigned short *)puVar6 * 0x12 + *(int *)puVar7;

    *(unsigned int *)puVar4 = (unsigned int)*(unsigned short *)puVar6 * 0x24 + *(int *)puVar7;

  }

  else if (uVar9 == 0x20) {

    *(unsigned int *)puVar5 = (unsigned int)*(unsigned short *)puVar6 * 0x12 + *(int *)puVar7;

    *(unsigned int *)puVar4 = (unsigned int)*(unsigned short *)puVar6 * 0x24 + *(int *)puVar7;

  }

  else if (uVar9 == 0x30) {

    *(unsigned int *)puVar5 = (unsigned int)*(unsigned short *)puVar6 * 10 + *(int *)puVar7;

    *(unsigned int *)puVar4 = (unsigned int)*(unsigned short *)puVar6 * 0x14 + *(int *)puVar7;

  }

  else if (uVar9 == DAT_060397f4) {

    *(unsigned int *)puVar5 = (unsigned int)*(unsigned short *)puVar6 * 3 + *(int *)puVar7;

    *(unsigned int *)puVar4 = (unsigned int)*(unsigned short *)puVar6 * 6 + *(int *)puVar7;

  }

  else if (uVar9 == DAT_060397f6) {

    *(unsigned int *)puVar5 = (unsigned int)*(unsigned short *)puVar6 * 6 + *(int *)puVar7;

    *(unsigned int *)puVar4 = (unsigned int)*(unsigned short *)puVar6 * 0xc + *(int *)puVar7;

  }

  else if (uVar9 == DAT_060397f8) {

    iVar10 = ((unsigned char)*puVar2 + 1) * (unsigned int)*(unsigned short *)puVar6;

    *(int *)puVar5 = *(int *)puVar7 + iVar10;

    *(int *)puVar4 = (iVar10 << 1) + *(int *)puVar7;

  }

  *(int *)0x060A4CB4 = 0;

  (*(int(*)())0x0603A766)();

  puVar2 = (char *)0x060A4CC4;

  *(int *)0x060A4CC4 = *(int *)puVar5;

  *(int *)puVar5 = *(int *)puVar3;

  *(int *)puVar3 = *(int *)puVar2;

  *(int *)0x060A4CB4 = 0;

  (*(int(*)())0x0603A766)();

  FUN_0603a6c0();

  FUN_0603a72c();

  return;

}

int FUN_06039808(param_1)
    int *param_1;
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  int uVar4;

  int iVar5;

  puVar2 = (char *)0x06063608;

  puVar1 = (char *)0x06063601;

  if ((*(int *)0x060A4CAA == '\x01') || (*(int *)0x060A4CAA == '\x02')) {

    if ((*(int *)0x20100061 & 0x10) == 0x10) {

      iVar5 = *(int *)0x06063608;

      *(int *)0x06063608 = iVar5 + 1;

      if (2 < iVar5 + 1) {

        *puVar1 = 1;

        *(int *)puVar2 = *(int *)puVar2 + -1;

      }

    }

    else {

      *(int *)0x06063601 = 0;

      *(int *)puVar2 = 0;

    }

    if ((int)(unsigned int)(unsigned char)*(int *)0x060A4CAB <= *(int *)0x060A4CB8) {

      *(int *)0x060A4CB8 = 0;

      puVar1 = (char *)0x06063600;

      if (*(int *)0x060A4CB4 < (int)(unsigned int)*(unsigned short *)0x060A4CAC) {

        *(int *)0x06063600 = *(int *)0x06063600 + '\x01';

        if (2 < (unsigned char)*puVar1) {

          FUN_0603a766();

          *puVar1 = *puVar1 + -1;

        }

      }

      else {

        *(int *)0x06063600 = 0;

      }

      puVar2 = (char *)0x060A4CC4;

      puVar1 = (char *)0x060A4CE8;

      *(int *)0x060A4CC4 = *(int *)0x060A4CE8;

      puVar3 = (char *)0x060A4C98;

      *(int *)puVar1 = *(int *)0x060A4C98;

      *(int *)puVar3 = *(int *)puVar2;

      puVar1 = (char *)0x060A4CC0;

      *(int *)puVar2 = *(int *)0x060A4CC0;

      puVar3 = (char *)0x060A4CBC;

      *(int *)puVar1 = *(int *)0x060A4CBC;

      uVar4 = *(int *)puVar2;

      *(int *)puVar3 = uVar4;

      *param_1 = uVar4;

      FUN_0603a6c0();

      uVar4 = FUN_0603a72c();

      return uVar4;

    }

    *(int *)0x060A4CB8 = *(int *)0x060A4CB8 + 1;

    uVar4 = 0;

  }

  else {

    *param_1 = 0;

    uVar4 = 1;

  }

  return uVar4;

}

void FUN_06039fe8()
{

  if ((0x20100061 <= *(char **)0x060A4CEC) &&

     ((*(int *)0x20100061 & 0x20) == 0x20)) {

    *(int *)0x060A4CF4 = 2;

  }

  return;

}
