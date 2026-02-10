#include "game.h"

extern int DAT_0600a10c;
extern int DAT_0600a110;
extern int DAT_0600a112;
extern int DAT_0600a224;
extern int DAT_0600a226;
extern int DAT_0600a2d8;
extern int DAT_0600a2da;
extern int DAT_0600a2dc;
extern int DAT_0600a2de;
extern int DAT_0600a854;
extern int DAT_0600a856;
extern int DAT_0600a99a;
extern int DAT_0600aa7e;
extern int DAT_0600b100;
extern int DAT_0600b102;
extern int DAT_0600b104;
extern int DAT_0600b106;
extern int DAT_0600b47a;
extern int DAT_0600b47c;
extern int DAT_0600b47e;
extern int DAT_0600b630;
extern int DAT_0600b632;
extern int DAT_0600b634;
extern int DAT_0600b636;
extern int DAT_0600b838;
extern int DAT_0600b83a;
extern int DAT_0600b83c;
extern int DAT_0600b83e;
extern int DAT_0600b840;
extern int DAT_0600b842;
extern int DAT_0600b90e;
extern int DAT_0600bab0;
extern int DAT_0600bab2;
extern int DAT_0600bab4;
extern int DAT_0600bab6;
extern int DAT_0600bab8;
extern int DAT_0600baba;
extern int DAT_0600bc2c;
extern int DAT_0600bc2e;
extern int DAT_0600bcee;
extern int DAT_0600bdac;
extern int DAT_0600bdae;
extern int DAT_0600bf3c;
extern int DAT_0600bfe2;
extern int DAT_0600bfe4;
extern int DAT_0600bfe6;
extern int DAT_0600c090;
extern void FUN_0600a76c();
extern void FUN_0600aa98();
extern void FUN_0600ac44();
extern unsigned int FUN_0600b6a0();
extern void FUN_0600bf70();
extern int FUN_0600c3a8();
extern int FUN_06031A28();
extern int FUN_06031D8C();
extern int PTR_DAT_0600a900;
extern int PTR_DAT_0600a99c;
extern int PTR_DAT_0600aa80;
extern int PTR_DAT_0600b480;
extern int PTR_DAT_0600b638;
extern int PTR_DAT_0600b844;
extern int PTR_DAT_0600babc;
extern int PTR_DAT_0600bb8c;
extern int PTR_DAT_0600bc30;
extern int PTR_DAT_0600be4c;
extern short DAT_0600a36c;
extern short DAT_0600a36e;
extern short DAT_0600a370;
extern short DAT_0600a372;

void FUN_0600a026()
{

  char *puVar1;

  puVar1 = (char *)0x0602853E;

  (*(int(*)())0x0602853E)(0);

  (*(int(*)())puVar1)(4);

  (*(int(*)())puVar1)(8);

  (*(int(*)())puVar1)(0xc);

  (*(int(*)())0x06028560)();

  puVar1 = (char *)0x06014884;

  (*(int(*)())0x06014884)(4,0);

  (*(int(*)())puVar1)(8,0);

  (*(int(*)())puVar1)(0x10,0);

  (*(int(*)())puVar1)(0x20,0);

  return;

}

void FUN_0600a084()
{
  register int func asm("r3") = 0x06014884;
  int val = *(int *)(CAR_PTR_TARGET + (int)DAT_0600a10c);
  int iVar1;

  if (val < 2) {
    (*(void(*)())func)(0x10, 0, 0);
    return;
  }

  iVar1 = val << 15;
  if ((FRAME_COUNTER & 1) != 0) {
    iVar1 = val * -0x8000;
  }
  (*(void(*)())func)(0x10, iVar1, 0);
}

void FUN_0600a0c0()
{
  register int func1 asm("r3") = 0x06026CE0;
  register int ptrAddr asm("r2") = 0x06063F5C;

  (*(int(*)())0x06038BD4)(0x100, 0);
  (*(int(*)())func1)();
  VBLANK_OUT_COUNTER = 0;
  (*(int(*)())0x06039250)(ptrAddr);
  (*(int(*)())0x060393FC)(0, 0, 0, (int)DAT_0600a112, (int)DAT_0600a110);
  VDP1_CMD_BASE_PTR = 0;
  **(short **)ptrAddr = (short)0x8000;
  (*(int(*)())func1)();
  VBLANK_OUT_COUNTER = 0;
}

void FUN_0600a140()
{

  char *puVar1;

  int *puVar2;

  int *puVar3;

  *(int *)0x25C00000 = 0x80000000;

  puVar1 = (char *)0x00010000;

  puVar3 = (int *)0x25C80000;

  do {

    puVar1 = puVar1 + -2;

    puVar2 = puVar3 + 1;

    *puVar3 = 0;

    puVar3 = puVar3 + 2;

    *puVar2 = 0;

  } while (puVar1 != (char *)0x0);

  VBL_DISABLE_FLAG = 0;

  (*(int(*)())0x06026CE0)();

  VBLANK_OUT_COUNTER = 0;

  puVar1 = (char *)0x00010000;

  puVar3 = (int *)0x25C80000;

  do {

    puVar1 = puVar1 + -2;

    puVar2 = puVar3 + 1;

    *puVar3 = 0;

    puVar3 = puVar3 + 2;

    *puVar2 = 0;

  } while (puVar1 != (char *)0x0);

  VBL_DISABLE_FLAG = 0;

  (*(int(*)())0x06026CE0)();

  VBLANK_OUT_COUNTER = 0;

  return;

}

unsigned int FUN_0600a1b8()
{
  register char *base asm("r2") = (char *)0x0607ED90;
  unsigned int uVar2;

  if (*(char *)0x06078635 != 0 ||
     ((uVar2 = *(unsigned short *)0x0607ED8C) == 0 &&
      (uVar2 = COURSE_SELECT) == 0)) {
    base[0] = (char)*(short *)0x06063F44;
    base[1] = (char)*(int *)0x06078868;
    uVar2 = *(unsigned int *)0x0607EAB8 & 0xff;
    base[2] = (char)uVar2;
  }
  return uVar2;
}

int FUN_0600a1f6()
{

  int iVar1;

  if (CAR_COUNT == 0) {

    iVar1 = 0;

    if (*(int *)0x0607EBCC == (int)DAT_0600a224) {

      PHASE_FLAG = 3;

    }

    else if (*(int *)0x0607EBCC == 0xa8) {

      PHASE_FLAG = 4;

    }

  }

  else {

    iVar1 = CAR_COUNT;

    if (iVar1 == 1) {

      if (*(int *)0x0607EBCC == (int)DAT_0600a2d8) {

        PHASE_FLAG = 3;

      }

      else if (*(int *)0x0607EBCC == 0x271) {

        PHASE_FLAG = 4;

      }

    }

    else if (*(int *)0x0607EBCC == (int)DAT_0600a2dc) {

      PHASE_FLAG = 3;

    }

    else if (*(int *)0x0607EBCC == 0x190) {

      PHASE_FLAG = 4;

    }

  }

  return iVar1;

}

int FUN_0600a294()
{
  register short *dest asm("r4") = (short *)0x0605A016;
  register int *src asm("r5") = (int *)0x0607EBCC;
  register short v3 asm("r7") = 3;
  register short v4 asm("r6") = 4;
  int iVar1;
  int cmp;

  iVar1 = CAR_COUNT;
  if (iVar1 == 1) {
    cmp = *src;
    if (cmp == 0x371) {
      *dest = v3;
    }
    else if (cmp == 0x352) {
      *dest = v4;
    }
  }
  else if (iVar1 == 2) {
    cmp = *src;
    if (cmp == 0x3ab) {
      *dest = v3;
    }
    else if (cmp == 0x398) {
      *dest = v4;
    }
    else if (cmp == (int)DAT_0600a36c) {
      *dest = v3;
    }
    else if (cmp == (int)DAT_0600a36e) {
      *dest = v4;
    }
    else if (cmp == (int)DAT_0600a370) {
      *dest = v3;
    }
    else if (cmp == (int)DAT_0600a372) {
      *dest = v4;
    }
  }
  return iVar1;
}

int FUN_0600a33c()
{
  register int iVar1 asm("r0");
  register short *dest asm("r2") = (short *)0x0605A016;

  iVar1 = *(int *)0x06063E1C;

  if (iVar1 == 0) {
    *dest = 5;
  }
  else if (iVar1 == 1) {
    *dest = 6;
  }
  else if (iVar1 == 2) {
    *dest = 7;
  }
  else if (iVar1 == 3) {
    *dest = 8;
  }

  return iVar1;
}

void FUN_0600a474(param_1, param_2, param_3, param_4)
    int param_1;
    int param_2;
    int param_3;
    int param_4;
{

  int iVar1;

  iVar1 = (param_1 << 2);

  (*(int(*)())0x06031D8C)(*(int *)(0x06062874 + iVar1),*(int *)(0x060628C8 + iVar1),

             param_3,param_4,param_1);

  (*(int(*)())0x06031A28)(*(int *)(0x06062820 + iVar1),(int)*(short *)0x06089E9E,

             *(int *)(0x0606291C + iVar1));

  return;

}

void FUN_0600a4aa()
{

  FUN_06031D8C(*(int *)0x06062130, *(int *)0x060621DC);

  FUN_06031A28(*(int *)0x060620DC, *(short *)0x06089E44, *(int *)0x06062184);

  return;

}

int FUN_0600a4ca(param_1)
    int param_1;
{

  char *puVar1;

  char *puVar2;

  int iVar3;

  char *puVar4;

  int uVar5;

  puVar2 = (int *)0x060634DC;

  puVar4 = (char *)0x06089E44;

  puVar1 = (char *)0x06031A28;

  iVar3 = CAR_COUNT;

  if (iVar3 == 0) {

    iVar3 = (param_1 << 2);

    (*(int(*)())0x06031D8C)(*(int *)(0x06063488 + iVar3),*(int *)(0x060634F8 + iVar3));

    uVar5 = *(int *)(puVar2 + iVar3);

    iVar3 = (int)*(short *)(puVar4 + 0x54);

    puVar4 = (char *)0x06063434;

  }

  else if (iVar3 == 1) {

    iVar3 = (param_1 << 2);

    (*(int(*)())0x06031D8C)(*(int *)(0x060634A4 + iVar3),*(int *)(0x060634F8 + iVar3));

    uVar5 = *(int *)(puVar2 + iVar3);

    iVar3 = (int)*(short *)(puVar4 + 0x54);

    puVar4 = (char *)0x06063450;

  }

  else {

    if (iVar3 != 2) {

      return iVar3;

    }

    iVar3 = (param_1 << 2);

    (*(int(*)())0x06031D8C)(*(int *)(0x060634C0 + iVar3),*(int *)(0x060634F8 + iVar3));

    uVar5 = *(int *)(puVar2 + iVar3);

    iVar3 = (int)*(short *)(puVar4 + 0x54);

    puVar4 = (char *)0x0606346C;

  }

  iVar3 = (*(int(*)())puVar1)(*(int *)(puVar4 + (param_1 << 2)),iVar3,uVar5);

  return iVar3;

}

void FUN_0600a5b2(param_1, param_2, param_3, param_4)
    int param_1;
    int param_2;
    int param_3;
    int param_4;
{

  int iVar1;

  iVar1 = (param_1 << 2);

  (*(int(*)())0x06031D8C)(*(int *)(0x06063520 + iVar1),*(int *)(0x06063538 + iVar1),

             param_3,param_4,param_1);

  (*(int(*)())0x06031A28)(*(int *)(0x06063514 + iVar1),(int)*(short *)0x06089E98,

             *(int *)(0x0606352C + iVar1));

  return;

}

void FUN_0600a76c()
{

  char *puVar1;

  char *puVar2;

  int iVar3;

  char *pcVar4;

  puVar2 = (int *)0x00008000;

  puVar1 = (char *)0x0608A52C;

  pcVar4 = *(char **)0x0607EB8C;

  if (pcVar4[1] != '\0') {

    (*(int(*)())0x06027080)();

    (*(int(*)())0x060270F2)(*(int *)0x06044640 + (int)DAT_0600a856,

               *(int *)(0x06044640 + 4) + -13107,

               *(int *)(0x06044640 + 8) + 0xFFFF0F5D);

    (*(int(*)())0x06027124)(puVar2,puVar2,puVar2);

    iVar3 = (*pcVar4 + 0xe) << 2;

    (*(int(*)())0x06032158)(*(int *)(0x0606212C + iVar3),*(int *)(0x060621D8 + iVar3));

    iVar3 = (*pcVar4 + 0xe) << 2;

    (*(int(*)())0x06031DF4)(*(int *)(0x060620D8 + iVar3),*(short *)0x06089E9C,

               *(int *)(0x06062180 + iVar3));

    *(int *)puVar1 = *(int *)puVar1 + -0x30;

  }

  if (pcVar4[4] != '\0') {

    (*(int(*)())0x06027080)();

    (*(int(*)())0x060270F2)(*(int *)0x06044670,*(int *)(0x06044670 + 4) + -13107,

               0xFFFDB334 - *(int *)(0x06044670 + 8));

    (*(int(*)())0x06027124)(puVar2,puVar2,puVar2);

    iVar3 = (pcVar4[3] + 0xe) << 2;

    (*(int(*)())0x06032158)(*(int *)(0x0606212C + iVar3),*(int *)(0x060621D8 + iVar3));

    iVar3 = (pcVar4[3] + 0xe) << 2;

    (*(int(*)())0x06031DF4)(*(int *)(0x060620D8 + iVar3),*(short *)0x06089E9C,

               *(int *)(0x06062180 + iVar3));

    *(int *)puVar1 = *(int *)puVar1 + -0x30;

  }

  return;

}

unsigned short FUN_0600a8bc()
{

  char *puVar1;

  unsigned short uVar2;

  int iVar3;

  puVar1 = (char *)0x06063F46;

  iVar3 = CAR_PTR_CURRENT;

  if (*(int *)(iVar3 + 0xc) == 0) {

    *(short *)0x06063F46 = 0;

    uVar2 = 0;

  }

  else {

    if (*(int *)(iVar3 + 8) < 100) {

      *(short *)0x06063F46 = *(short *)0x06063F46 + 1;

    }

    else if (*(int *)(iVar3 + 8) < 0xc8) {

      *(short *)0x06063F46 = *(short *)0x06063F46 + 2;

    }

    else {

      *(short *)0x06063F46 = *(short *)0x06063F46 + 4;

    }

    uVar2 = *(unsigned short *)puVar1 & 0xf;

    *(unsigned short *)puVar1 = uVar2;

  }

  return uVar2;

}

int FUN_0600a914()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  unsigned int uVar8;

  unsigned int uVar9;

  int iVar10;

  int iVar11;

  unsigned int *puVar12;

  puVar3 = (char *)0x06078900;

  puVar2 = (int *)0x0607EA98;

  puVar1 = (char *)0x0004B333;

  iVar11 = 0x268;

  iVar5 = DEMO_MODE_FLAG;

  if (iVar5 == 0) {

    for (uVar8 = 1; puVar4 = 0x0607E940, uVar8 < *(int *)puVar2 - 1U; uVar8 = uVar8 + 1) {

      puVar12 = (unsigned int *)(puVar3 + uVar8 * iVar11);

      *(unsigned int **)0x0607E940 = puVar12;

      uVar9 = uVar8;

      if ((*puVar12 & (unsigned int)0x00E00000) != 0) {

        while (uVar9 = uVar9 + 1, uVar9 < *(unsigned int *)puVar2) {

          iVar6 = uVar9 * iVar11;

          iVar5 = (int)PTR_DAT_0600a99c;

          iVar10 = *(int *)((int)puVar12 + iVar5) - *(int *)(puVar3 + iVar5 + iVar6);

          if ((iVar10 < 0x15) && (-0x15 < iVar10)) {

            iVar10 = *(int *)(puVar3 + iVar6 + 0x10) - puVar12[4];

            iVar7 = *(int *)(puVar3 + iVar6 + 0x18) - puVar12[6];

            if (iVar10 < 0) {

              iVar10 = -iVar10;

            }

            if (iVar7 < 0) {

              iVar7 = -iVar7;

            }

            if (iVar7 < iVar10) {

              iVar7 = iVar7 >> 2;

            }

            else {

              iVar10 = iVar10 >> 2;

            }

            if ((iVar10 + iVar7 < (int)puVar1) &&

               (iVar5 = (int)DAT_0600aa7e, *(int *)(puVar3 + iVar5 + iVar6) < (int)0x00010000)

               ) {

              iVar5 = (*(int(*)())0x060316C4)(puVar12);

            }

          }

        }

      }

    }

    *(char **)0x0607E940 = puVar3;

    iVar10 = *(int *)puVar4;

    for (uVar8 = 1; uVar8 < *(unsigned int *)puVar2; uVar8 = uVar8 + 1) {

      puVar12 = (unsigned int *)(puVar3 + uVar8 * iVar11);

      if ((*puVar12 & (unsigned int)0x00E00000) != 0) {

        iVar5 = (int)PTR_DAT_0600aa80;

        iVar6 = *(int *)(iVar10 + iVar5) - *(int *)((int)puVar12 + iVar5);

        if ((iVar6 < 0x15) && (-0x15 < iVar6)) {

          iVar6 = puVar12[4] - *(int *)(iVar10 + 0x10);

          iVar7 = puVar12[6] - *(int *)(iVar10 + 0x18);

          if (iVar6 < 0) {

            iVar6 = -iVar6;

          }

          if (iVar7 < 0) {

            iVar7 = -iVar7;

          }

          if (iVar7 < iVar6) {

            iVar7 = iVar7 >> 2;

          }

          else {

            iVar6 = iVar6 >> 2;

          }

          if ((iVar6 + iVar7 < (int)puVar1) &&

             (iVar5 = (int)DAT_0600aa7e, *(int *)((int)puVar12 + iVar5) < (int)0x00010000)) {

            iVar5 = (*(int(*)())0x06030FC0)(iVar10,puVar12);

          }

        }

      }

    }

  }

  return iVar5;

}

void FUN_0600aa98(param_1, param_2)
    int param_1;
    int param_2;
{

  unsigned char bVar1;

  unsigned char bVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  int iVar6;

  int iVar7;

  short *psVar8;

  unsigned char *pbVar9;

  int iVar10;

  pbVar9 = 0x0605A1D5 + (param_2 << 2);

  bVar2 = pbVar9[3];

  iVar6 = *(int *)(param_1 + 0x48);

  iVar7 = *(int *)(param_1 + 0x40) << 1;

  bVar1 = *pbVar9;

  (*(int(*)())0x06026DBC)();

  (*(int(*)())0x06026E2E)(*(int *)0x06044640,*(int *)(0x06044640 + 4),

             -*(int *)(0x06044640 + 8));

  (*(int(*)())0x06026EDE)(iVar7);

  (*(int(*)())0x06026E94)(-iVar6);

  puVar3 = (char *)0x0606212C;

  iVar10 = (unsigned int)(bVar1 << 2);

  (*(int(*)())0x06031D8C)(*(int *)(0x0606212C + iVar10),*(int *)(0x060621D8 + iVar10));

  puVar4 = (char *)0x060620D8;

  psVar8 = (short *)(0x06089E44 + (unsigned int)(bVar2 << 1));

  (*(int(*)())0x06031A28)(*(int *)(0x060620D8 + iVar10),(int)*psVar8,

             *(int *)(0x06062180 + iVar10));

  puVar5 = (char *)0x06089EDC;

  OBJ_STATE_PRIMARY = OBJ_STATE_PRIMARY + -0x30;

  bVar1 = pbVar9[1];

  (*(int(*)())0x06026DBC)();

  (*(int(*)())0x06026E2E)(*(int *)0x0604464C,*(int *)(0x0604464C + 4),

             -*(int *)(0x0604464C + 8));

  (*(int(*)())0x06026EDE)(iVar7);

  (*(int(*)())0x06026E94)(-iVar6);

  iVar6 = (unsigned int)(bVar1 << 2);

  (*(int(*)())0x06031D8C)(*(int *)(puVar3 + iVar6),*(int *)(0x060621D8 + iVar6));

  (*(int(*)())0x06031A28)(*(int *)(puVar4 + iVar6),(int)*psVar8,*(int *)(0x06062180 + iVar6))

  ;

  *(int *)puVar5 = *(int *)puVar5 + -0x30;

  iVar6 = *(int *)(param_1 + 0x50);

  bVar1 = pbVar9[2];

  (*(int(*)())0x06026DBC)();

  (*(int(*)())0x06026E2E)(*(int *)0x06044670,*(int *)(0x06044670 + 4),

             -*(int *)(0x06044670 + 8));

  (*(int(*)())0x06026E94)(-iVar6);

  iVar6 = (unsigned int)(bVar1 << 2);

  (*(int(*)())0x06031D8C)(*(int *)(puVar3 + iVar6),*(int *)(0x060621D8 + iVar6));

  (*(int(*)())0x06031A28)(*(int *)(puVar4 + iVar6),(int)*psVar8,*(int *)(0x06062180 + iVar6))

  ;

  *(int *)puVar5 = *(int *)puVar5 + -0x30;

  return;

}

void FUN_0600ac44(param_1, param_2)
    int param_1;
    int param_2;
{

  unsigned char bVar1;

  unsigned char bVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  int iVar6;

  int iVar7;

  short *puVar8;

  unsigned char *pbVar9;

  int iVar10;

  pbVar9 = 0x0605A1D5 + (param_2 << 2);

  bVar2 = pbVar9[3];

  iVar6 = *(int *)(param_1 + 0x48);

  iVar7 = *(int *)(param_1 + 0x40) << 1;

  bVar1 = *pbVar9;

  (*(int(*)())0x06027080)();

  (*(int(*)())0x060270F2)(*(int *)0x06044640,*(int *)(0x06044640 + 4),

             -*(int *)(0x06044640 + 8));

  (*(int(*)())0x060271A2)(iVar7);

  (*(int(*)())0x06027158)(-iVar6);

  puVar3 = (char *)0x0606212C;

  iVar10 = (unsigned int)(bVar1 << 2);

  (*(int(*)())0x06032158)(*(int *)(0x0606212C + iVar10),*(int *)(0x060621D8 + iVar10));

  puVar4 = (char *)0x060620D8;

  puVar8 = (short *)(0x06089E44 + (unsigned int)(bVar2 << 1));

  (*(int(*)())0x06031DF4)(*(int *)(0x060620D8 + iVar10),*puVar8,

             *(int *)(0x06062180 + iVar10));

  puVar5 = (char *)0x0608A52C;

  OBJ_STATE_SECONDARY = OBJ_STATE_SECONDARY + -0x30;

  bVar1 = pbVar9[1];

  (*(int(*)())0x06027080)();

  (*(int(*)())0x060270F2)(*(int *)0x0604464C,*(int *)(0x0604464C + 4),

             -*(int *)(0x0604464C + 8));

  (*(int(*)())0x060271A2)(iVar7);

  (*(int(*)())0x06027158)(-iVar6);

  iVar6 = (unsigned int)(bVar1 << 2);

  (*(int(*)())0x06032158)(*(int *)(puVar3 + iVar6),*(int *)(0x060621D8 + iVar6));

  (*(int(*)())0x06031DF4)(*(int *)(puVar4 + iVar6),*puVar8,*(int *)(0x06062180 + iVar6));

  *(int *)puVar5 = *(int *)puVar5 + -0x30;

  iVar6 = *(int *)(param_1 + 0x50);

  bVar1 = pbVar9[2];

  (*(int(*)())0x06027080)();

  (*(int(*)())0x060270F2)(*(int *)0x06044670,*(int *)(0x06044670 + 4),

             -*(int *)(0x06044670 + 8));

  (*(int(*)())0x06027158)(-iVar6);

  iVar6 = (unsigned int)(bVar1 << 2);

  (*(int(*)())0x06032158)(*(int *)(puVar3 + iVar6),*(int *)(0x060621D8 + iVar6));

  (*(int(*)())0x06031DF4)(*(int *)(puVar4 + iVar6),*puVar8,*(int *)(0x06062180 + iVar6))

  ;

  *(int *)puVar5 = *(int *)puVar5 + -0x30;

  return;

}

void FUN_0600afb2()
{

  char *puVar1;

  char *puVar2;

  int iVar3;

  int iVar4;

  puVar2 = (int *)0x06027158;

  puVar1 = (char *)0x06063F46;

  iVar4 = CAR_PTR_TARGET;

  CAR_PTR_CURRENT = iVar4;

  (*(int(*)())0x06027080)();

  (*(int(*)())0x060270F2)(*(int *)(iVar4 + 0x10),*(int *)(iVar4 + 0x14),

             *(int *)(iVar4 + 0x18));

  (*(int(*)())0x060271A2)(0x00008000 + *(int *)(iVar4 + 0x20));

  (*(int(*)())0x060271EE)(-*(int *)(iVar4 + 0x24));

  if ((GAME_STATE_BIT & (unsigned int)0x00800008) == 0) {

    iVar3 = (*(int *)0x06078668 - *(int *)(iVar4 + 0x1c)) +

            *(int *)(0x0605BDCC + (unsigned int)*(unsigned short *)((int)(int)puVar1 << 2));

  }

  else {

    iVar3 = *(int *)(0x0605BDCC + (unsigned int)*(unsigned short *)((int)(int)puVar1 << 2)) - *(int *)(iVar4 + 0x1c);

  }

  (*(int(*)())puVar2)(iVar3);

  (*(int(*)())0x060271A2)(*(int *)(iVar4 + DAT_0600b100) + *(int *)(iVar4 + DAT_0600b100 + -0xc));

  if (*(int *)0x06059F30 != 0) {

    (*(int(*)())0x06032158)(*(int *)0x0606213C,*(int *)0x060621E8);

    (*(int(*)())0x06031DF4)(*(int *)0x060620E8,*(short *)0x06089E44,

               *(int *)0x06062190);

    (*(int(*)())0x060270F2)(0,*(int *)(iVar4 + DAT_0600b102));

    (*(int(*)())0x060271EE)(*(int *)(iVar4 + DAT_0600b104));

    (*(int(*)())puVar2)(*(int *)(iVar4 + DAT_0600b106));

    if ((*(int *)0x06082A25 & 2) == 0) {

      FUN_0600ac44(iVar4,0);

    }

    iVar3 = 0;

    if ((*(unsigned char *)(iVar4 + 1) & 1) == 0) {

      iVar4 = *(int *)0x06083258;

    }

    else {

      iVar3 = 0xd;

      iVar4 = (int)(char)((int *)0x06044740)[*(unsigned short *)puVar1] + *(int *)0x06083258;

    }

    (*(int(*)())puVar2)(iVar4);

    iVar3 = (iVar3 << 2);

    (*(int(*)())0x06032158)(*(int *)(0x0606212C + iVar3),*(int *)(0x060621D8 + iVar3));

    (*(int(*)())0x06031DF4)(*(int *)(0x060620D8 + iVar3),*(short *)0x06089E44,

               *(int *)(0x06062180 + iVar3));

  }

  if ((GAME_STATE_BIT & (unsigned int)0x20020000) != 0) {

    (*(int(*)())0x0601C3E4)();

  }

  OBJ_STATE_SECONDARY = OBJ_STATE_SECONDARY + -0x30;

  return;

}

void FUN_0600b340()
{

  char *puVar1;

  int iVar2;

  char *unaff_r11;

  int iVar3;

  char *puVar4;

  char *unaff_r12;

  char *puVar5;

  char *puVar6;

  char *unaff_r13;

  char *puVar7;

  int iVar8;

  iVar3 = *(int *)0x0607EB8C;

  iVar8 = CAR_PTR_TARGET;

  CAR_PTR_CURRENT = iVar8;

  iVar2 = CAR_COUNT;

  puVar5 = (char *)0x06063434;

  puVar7 = (int *)0x06063488;

  if (((iVar2 != 0) && (puVar5 = 0x06063450, puVar7 = 0x060634A4, iVar2 != 1)) &&

     (puVar5 = unaff_r12, puVar7 = unaff_r13, iVar2 == 2)) {

    puVar5 = (char *)0x0606346C;

    puVar7 = (int *)0x060634C0;

  }

  (*(int(*)())0x06027080)();

  (*(int(*)())0x060270F2)(*(int *)(iVar8 + 0x10),*(int *)(iVar8 + 0x14),

             *(int *)(iVar8 + 0x18));

  (*(int(*)())0x060271A2)(*(int *)(iVar8 + 0x20));

  (*(int(*)())0x060271EE)(*(int *)(iVar8 + 0x24));

  (*(int(*)())0x06027158)(*(int *)(iVar8 + 0x1c));

  (*(int(*)())0x060271A2)(*(int *)(iVar8 + DAT_0600b47a) + *(int *)(iVar8 + DAT_0600b47a + -0xc));

  if (*(int *)0x06059F30 != 0) {

    (*(int(*)())0x06032158)(*(int *)(puVar7 + 0x18),*(int *)0x06063510);

    puVar4 = (char *)0x06089E98;

    (*(int(*)())0x06031DF4)(*(int *)(puVar5 + 0x18),*(short *)0x06089E98,

               *(int *)0x060634F4);

    (*(int(*)())0x060270F2)(0,*(int *)(iVar8 + DAT_0600b47c));

    (*(int(*)())0x060271EE)(*(int *)(iVar8 + DAT_0600b47e));

    (*(int(*)())0x06027158)(*(int *)(iVar8 + PTR_DAT_0600b480) + *(int *)0x06083258)

    ;

    iVar2 = *(int *)(iVar3 + 0xc) << 2;

    (*(int(*)())0x06032158)(*(int *)(puVar7 + iVar2),*(int *)(0x060634F8 + iVar2));

    iVar2 = *(int *)(iVar3 + 0xc) << 2;

    (*(int(*)())0x06031DF4)(*(int *)(puVar5 + iVar2),*(short *)puVar4,

               *(int *)(0x060634DC + iVar2));

    FUN_0600a76c();

  }

  OBJ_STATE_SECONDARY = OBJ_STATE_SECONDARY + -0x30;

  if (*(int *)0x0607867C == '\0') {

    return;

  }

  iVar3 = *(int *)0x0607EB8C;

  iVar8 = CAR_PTR_TARGET;

  CAR_PTR_CURRENT = iVar8;

  puVar7 = (int *)0x06078670;

  puVar5 = (char *)0x00008000;

  iVar2 = CAR_COUNT;

  puVar4 = (char *)0x06063434;

  puVar6 = (int *)0x06063488;

  if (((iVar2 != 0) && (puVar4 = 0x06063450, puVar6 = 0x060634A4, iVar2 != 1)) &&

     (puVar4 = unaff_r11, puVar6 = unaff_r12, iVar2 == 2)) {

    puVar4 = (char *)0x0606346C;

    puVar6 = (int *)0x060634C0;

  }

  *(int *)0x06078670 =

       *(int *)0x06078670 +

       ((int)(0x00008000 + (*(int *)(iVar8 + 0x10) - *(int *)0x06078670) +

             ((int)(0x00008000 + (*(int *)(iVar8 + 0x10) - *(int *)0x06078670)) < 0)) >>

       1);

  iVar2 = *(int *)(iVar8 + 0x14) - *(int *)(puVar7 + 4);

  *(int *)(puVar7 + 4) = *(int *)(puVar7 + 4) + ((int)(iVar2 + (unsigned int)(iVar2 < 0)) >> 1);

  puVar1 = (char *)0x06027080;

  iVar2 = (*(int *)(iVar8 + 0x18) - *(int *)(puVar7 + 8)) + (int)DAT_0600b630;

  *(int *)(puVar7 + 8) = *(int *)(puVar7 + 8) + ((int)(iVar2 + (unsigned int)(iVar2 < 0)) >> 1);

  (*(int(*)())puVar1)();

  (*(int(*)())0x060270F2)(*(int *)puVar7,*(int *)(puVar7 + 4),*(int *)(puVar7 + 8));

  (*(int(*)())0x060271A2)(*(int *)(iVar8 + 0x20));

  (*(int(*)())0x060271EE)(*(int *)(iVar8 + 0x24));

  (*(int(*)())0x06027158)(*(int *)(iVar8 + 0x1c));

  (*(int(*)())0x060271A2)(*(int *)(iVar8 + DAT_0600b632) + *(int *)(iVar8 + DAT_0600b632 + -0xc));

  if (*(int *)0x06059F30 != 0) {

    (*(int(*)())0x06027124)(puVar5,puVar5,puVar5);

    (*(int(*)())0x06032158)(*(int *)(puVar6 + 0x18),*(int *)0x06063510);

    puVar5 = (char *)0x06089E98;

    (*(int(*)())0x06031DF4)(*(int *)(puVar4 + 0x18),*(short *)0x06089E98,

               *(int *)0x060634F4);

    (*(int(*)())0x060270F2)(0,*(int *)(iVar8 + DAT_0600b634));

    (*(int(*)())0x060271EE)(*(int *)(iVar8 + DAT_0600b636));

    (*(int(*)())0x06027158)(*(int *)(iVar8 + PTR_DAT_0600b638) + *(int *)0x06083258)

    ;

    iVar2 = *(int *)(iVar3 + 0xc) << 2;

    (*(int(*)())0x06032158)(*(int *)(puVar6 + iVar2),*(int *)(0x060634F8 + iVar2));

    iVar2 = *(int *)(iVar3 + 0xc) << 2;

    (*(int(*)())0x06031DF4)(*(int *)(puVar4 + iVar2),*(short *)puVar5,

               *(int *)(0x060634DC + iVar2));

  }

  OBJ_STATE_SECONDARY = OBJ_STATE_SECONDARY + -0x30;

  return;

}

unsigned int FUN_0600b6a0()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  unsigned int uVar5;

  int *puVar6;

  int *puVar7;

  int *puVar8;

  int *puVar9;

  short *psVar10;

  int *puVar11;

  int *puVar12;

  int *puVar13;

  int *puVar14;

  int *puVar15;

  int *puVar16;

  int *puVar17;

  int *puVar18;

  int *puVar19;

  int *puVar20;

  int *puVar21;

  int *puVar22;

  unsigned int uVar23;

  unsigned int uVar24;

  unsigned int *puVar25;

  puVar4 = (char *)0x06031A28;

  puVar3 = (char *)0x06031D8C;

  puVar2 = (int *)0x06089E44;

  puVar1 = (char *)0x06089EDC;

  uVar5 = DEMO_MODE_FLAG;

  if (uVar5 == 0) {

    puVar14 = (int *)(0x060621D8 + 0x28);

    puVar9 = (int *)(0x0606212C + 0x28);

    puVar15 = (int *)(0x06062180 + 0x28);

    psVar10 = (short *)(0x06089E44 + 4);

    puVar16 = (int *)(0x060620D8 + 0x28);

    puVar11 = (int *)(0x060621D8 + 0x2c);

    puVar6 = (int *)(0x0606212C + 0x2c);

    puVar17 = (int *)(0x06062180 + 0x2c);

    puVar12 = (int *)(0x060620D8 + 0x2c);

    puVar7 = (int *)(0x060621D8 + 0x30);

    puVar18 = (int *)(0x0606212C + 0x30);

    puVar13 = (int *)(0x06062180 + 0x30);

    puVar8 = (int *)(0x060620D8 + 0x30);

    uVar5 = 0x40;

    puVar20 = (int *)(0x060621D8 + 0x18);

    puVar21 = (int *)(0x0606212C + 0x18);

    puVar19 = (int *)(0x06062180 + 0x18);

    puVar22 = (int *)(0x060620D8 + 0x18);

    for (uVar24 = 1; uVar24 < (unsigned int)(int)*(short *)0x06078664; uVar24 = uVar24 + 1) {

      puVar25 = (unsigned int *)(0x06078900 + uVar24 * 0x268);

      if ((*puVar25 & (unsigned int)0x00E00000) != 0) {

        (*(int(*)())0x06026DBC)();

        (*(int(*)())0x06026E2E)(puVar25[4],puVar25[5] + *(int *)((int)puVar25 + (int)DAT_0600b83a),puVar25[6]);

        (*(int(*)())0x06026EDE)(0x00008000 + puVar25[8]);

        (*(int(*)())0x06026F2A)(-puVar25[9]);

        (*(int(*)())0x06026E94)(-puVar25[7]);

        if (*(int *)((int)puVar25 + (int)DAT_0600b83c) + *(int *)((int)puVar25 + 0xb8)

            != 0) {

          (*(int(*)())0x06026EDE)(-*(int *)((int)puVar25 + DAT_0600b840 + -0xc) -

                     *(int *)((int)puVar25 + 0x1d8));

          (*(int(*)())0x06026F2A)(-*(int *)((int)puVar25 + 0x1d0));

          (*(int(*)())0x06026E94)(-*(int *)((int)puVar25 + 0x1c8));

        }

        uVar23 = (unsigned int)(unsigned char)((int *)0x06047FC4)[uVar24];

        if (((*puVar25 & 0x400000) == 0) &&

           (*(int *)0x06063E1C + *(int *)0x06063E20 != 8)) {

          if ((*puVar25 & 0x200000) == 0) {

            uVar5 = (unsigned int)*(char *)((int)puVar25 + 1);

            if ((uVar5 & 0x80) != 0) {

              if (*(int *)((int)puVar25 + (int)DAT_0600b90e) < 1) {

                (*(int(*)())puVar3)(*puVar9,*puVar14);

                (*(int(*)())puVar4)(*puVar16,(int)*psVar10,*puVar15);

              }

              FUN_0600aa98(puVar25,1);

              (*(int(*)())puVar3)(*puVar21,*puVar20);

              uVar5 = (*(int(*)())puVar4)(*puVar22,(int)*(short *)(puVar2 + (uVar23 << 1)),*puVar19);

            }

          }

          else {

            (*(int(*)())puVar3)(*puVar18,*puVar7);

            uVar5 = (*(int(*)())puVar4)(*puVar8,(int)*(short *)(puVar2 + (uVar23 << 1)),*puVar13);

          }

        }

        else {

          if (*(int *)((int)puVar25 + (int)DAT_0600b83c) < 1) {

            (*(int(*)())puVar3)(*puVar9,*puVar14);

            (*(int(*)())puVar4)(*puVar16,(int)*psVar10,*puVar15);

          }

          (*(int(*)())puVar3)(*puVar6,*puVar11);

          uVar5 = (*(int(*)())puVar4)(*puVar12,(int)*(short *)(puVar2 + (uVar23 << 1)),*puVar17);

        }

        *(int *)puVar1 = *(int *)puVar1 + -0x30;

      }

    }

  }

  return uVar5;

}

unsigned int FUN_0600b914()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  unsigned int uVar5;

  int *puVar6;

  int *puVar7;

  int *puVar8;

  int *puVar9;

  short *puVar10;

  int *puVar11;

  int *puVar12;

  int *puVar13;

  int *puVar14;

  int *puVar15;

  int *puVar16;

  int *puVar17;

  int *puVar18;

  int *puVar19;

  int *puVar20;

  int *puVar21;

  int *puVar22;

  unsigned int uVar23;

  unsigned int uVar24;

  unsigned int *puVar25;

  puVar4 = (char *)0x06031DF4;

  puVar3 = (char *)0x06032158;

  puVar2 = (int *)0x06089E44;

  puVar1 = (char *)0x0608A52C;

  uVar5 = DEMO_MODE_FLAG;

  if (uVar5 == 0) {

    puVar14 = (int *)(0x060621D8 + 0x28);

    puVar9 = (int *)(0x0606212C + 0x28);

    puVar15 = (int *)(0x06062180 + 0x28);

    puVar10 = (short *)(0x06089E44 + 4);

    puVar16 = (int *)(0x060620D8 + 0x28);

    puVar11 = (int *)(0x060621D8 + 0x2c);

    puVar6 = (int *)(0x0606212C + 0x2c);

    puVar17 = (int *)(0x06062180 + 0x2c);

    puVar12 = (int *)(0x060620D8 + 0x2c);

    puVar7 = (int *)(0x060621D8 + 0x30);

    puVar18 = (int *)(0x0606212C + 0x30);

    puVar13 = (int *)(0x06062180 + 0x30);

    puVar8 = (int *)(0x060620D8 + 0x30);

    uVar5 = 0x40;

    puVar20 = (int *)(0x060621D8 + 0x18);

    puVar21 = (int *)(0x0606212C + 0x18);

    puVar19 = (int *)(0x06062180 + 0x18);

    puVar22 = (int *)(0x060620D8 + 0x18);

    for (uVar24 = (unsigned int)*(short *)0x06078664; uVar24 < *(unsigned int *)0x0607EA98;

        uVar24 = uVar24 + 1) {

      puVar25 = (unsigned int *)(0x06078900 + uVar24 * 0x268);

      if ((*puVar25 & (unsigned int)0x00E00000) != 0) {

        (*(int(*)())0x06027080)();

        (*(int(*)())0x060270F2)(puVar25[4],puVar25[5] + *(int *)((int)puVar25 + (int)DAT_0600bab2),puVar25[6]);

        (*(int(*)())0x060271A2)(0x00008000 + puVar25[8]);

        (*(int(*)())0x060271EE)(-puVar25[9]);

        (*(int(*)())0x06027158)(-puVar25[7]);

        if (*(int *)((int)puVar25 + (int)DAT_0600bab4) + *(int *)((int)puVar25 + 0xb8)

            != 0) {

          (*(int(*)())0x060271A2)(-*(int *)((int)puVar25 + DAT_0600bab8 + -0xc) -

                     *(int *)((int)puVar25 + 0x1d8));

          (*(int(*)())0x060271EE)(-*(int *)((int)puVar25 + 0x1d0));

          (*(int(*)())0x06027158)(-*(int *)((int)puVar25 + 0x1c8));

        }

        uVar23 = (unsigned int)(unsigned char)((int *)0x06047FC4)[uVar24];

        if (((*puVar25 & 0x400000) == 0) &&

           (*(int *)0x06063E1C + *(int *)0x06063E20 != 8)) {

          if ((*puVar25 & 0x200000) == 0) {

            uVar5 = (unsigned int)*(char *)((int)puVar25 + 1);

            if ((uVar5 & 0x80) != 0) {

              if (*(int *)((int)puVar25 + (int)PTR_DAT_0600bb8c) < 1) {

                (*(int(*)())puVar3)(*puVar9,*puVar14);

                (*(int(*)())puVar4)(*puVar16,*puVar10,*puVar15);

              }

              FUN_0600ac44(puVar25,1);

              (*(int(*)())puVar3)(*puVar21,*puVar20);

              uVar5 = (*(int(*)())puVar4)(*puVar22,*(short *)(puVar2 + (uVar23 << 1)),*puVar19);

            }

          }

          else {

            (*(int(*)())puVar3)(*puVar18,*puVar7);

            uVar5 = (*(int(*)())puVar4)(*puVar8,*(short *)(puVar2 + (uVar23 << 1)),*puVar13);

          }

        }

        else {

          if (*(int *)((int)puVar25 + (int)DAT_0600bab4) < 1) {

            (*(int(*)())puVar3)(*puVar9,*puVar14);

            (*(int(*)())puVar4)(*puVar16,*puVar10,*puVar15);

          }

          (*(int(*)())puVar3)(*puVar6,*puVar11);

          uVar5 = (*(int(*)())puVar4)(*puVar12,*(short *)(puVar2 + (uVar23 << 1)),*puVar17);

        }

        *(int *)puVar1 = *(int *)puVar1 + -0x30;

      }

    }

  }

  return uVar5;

}

void FUN_0600bb94()
{

  char cVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  char *puVar6;

  int iVar7;

  char *puVar8;

  int iVar9;

  int local_28;

  int aiStack_24 [2];

  puVar8 = (char *)0x06063E24;

  puVar6 = (int *)0x06063EEC;

  puVar5 = (char *)0x06063EF8;

  puVar4 = (char *)0x06063E30;

  puVar3 = (char *)0x06063E28;

  puVar2 = (int *)0x06038520;

  iVar9 = CAR_PTR_TARGET;

  iVar7 = (int)DAT_0600bc2c;

  cVar1 = *(int *)0x06078654;

  if (cVar1 != '\0') {

    if (cVar1 == '\x01') {

      if (*(int *)0x0605A1C4 == 0) {

        if (*(unsigned int *)0x06063E20 < 2) {

          *(int *)(0x06063EEC + 4) = *(int *)(iVar9 + 0x20) + *(int *)(iVar9 + DAT_0600bc2e);

        }

        FUN_0600c3a8((int)*(short *)0x06063D9A);

      }

    }

    else if (cVar1 == '\x04') {

      if (*(int *)(iVar9 + DAT_0600bcee) == 0) {

        *(int *)0x06063E20 = 2;

      }

      else if (*(int *)(iVar9 + DAT_0600bcee) < 0x31) {

        if (*(int *)(iVar9 + DAT_0600bcee) < 0x29) {

          if (*(int *)(iVar9 + DAT_0600bcee) < 0x11) {

            if (*(int *)(iVar9 + DAT_0600bcee) < 9) {

              if ((*(int *)(iVar9 + DAT_0600bdac) == 8) || (*(int *)(iVar9 + DAT_0600bdac) == 7)) {

                *(int *)0x06063E1C = 2;

                *(int *)0x06059F30 = 1;

                (*(int(*)())0x06038BD4)(8,0);

                *(char **)puVar8 = (char *)0x00058000;

                *(char **)0x06063E34 = 0x0000F300;

                *(char **)puVar3 = (char *)0x006E0000;

                *(char **)0x06063E2C = 0x00100000;

                *(int *)puVar4 = 0;

              }

            }

            else {

              *(int *)0x06063E24 = *(int *)0x06063E24 + iVar7;

            }

          }

        }

        else {

          *(int *)0x06063E24 = *(int *)0x06063E24 - iVar7;

        }

      }

      iVar7 = (int)DAT_0600bdae;

      *(int *)(puVar6 + 4) = *(int *)(iVar9 + 0x20) - *(int *)(iVar9 + iVar7);

      *(int *)(iVar9 + iVar7) =

           *(int *)(iVar9 + iVar7) + ((int)0x00008000 - *(int *)(iVar9 + iVar7) >> 4);

    }

    else if (cVar1 == '\x06') {

      *(int *)0x06063E20 = 3;

    }

    else if (cVar1 == '\a') {

      if (*(int *)(iVar9 + PTR_DAT_0600bc30) < 0x31) {

        if (*(int *)(iVar9 + PTR_DAT_0600bc30) < 0x29) {

          if (*(int *)(iVar9 + PTR_DAT_0600bc30) < 0x11) {

            if (*(int *)(iVar9 + PTR_DAT_0600bc30) < 9) {

              if ((*(int *)(iVar9 + DAT_0600bcee) == 8) || (*(int *)(iVar9 + DAT_0600bcee) == 7)) {

                *(int *)0x06063E1C = 2;

                *(int *)0x06059F30 = 1;

                (*(int(*)())0x06038BD4)(8,0);

                *(char **)puVar8 = (char *)0x00058000;

                *(char **)0x06063E34 = 0x0000F300;

                *(char **)puVar3 = (char *)0x006E0000;

                *(char **)0x06063E2C = 0x00100000;

                *(int *)puVar4 = 0;

              }

            }

            else {

              *(int *)0x06063E24 = *(int *)0x06063E24 + iVar7;

            }

          }

        }

        else {

          *(int *)0x06063E24 = *(int *)0x06063E24 - iVar7;

        }

      }

      FUN_0600c3a8((int)*(short *)0x06063D9A);

    }

  }

  if (*(int *)0x06078663 == '\0') {

    puVar8 = (char *)(*(int *)(puVar6 + 4) * -0x400 + 0xFFA00000);

  }

  else {

    puVar8 = 0x01A00000 + *(int *)(puVar6 + 4) << 10;

  }

  if (*(int *)0x06082A30 == 0) {

    if (*(int *)(iVar9 + PTR_DAT_0600be4c) == 0) {

      (*(int(*)())0x060064F2)();

    }

    else {

      iVar7 = (int)DAT_0600bf3c;

      *(int *)0x06063F04 = iVar7;

      *(int *)0x06063F08 = iVar7;

    }

    (*(int(*)())0x0603850C)(4);

    (*(int(*)())0x0603853C)(puVar8,*(int *)puVar3,0);

    (*(int(*)())puVar2)();

    iVar7 = *(int *)(iVar9 + 0x1c) << 8;

    if (iVar7 < 0) {

      iVar7 = *(int *)(iVar9 + 0x1c) << 9;

    }

    (*(int(*)())0x0603850C)(8);

    (*(int(*)())0x0603853C)(0,*(int *)(0x0605BDCC + (*(unsigned short *)0x06063F46 & 0xc) << 2) << 9 +

                 *(int *)0x06063E2C + iVar7);

    (*(int(*)())puVar2)();

    (*(int(*)())0x06020E74)();

    (*(int(*)())0x06027358)(*(int *)(puVar6 + 4),&local_28,aiStack_24);

    *(int *)puVar5 = *(int *)(iVar9 + 0x10) - local_28;

    *(int *)(puVar5 + 4) = *(int *)(iVar9 + 0x14) + *(int *)puVar4;

    *(int *)(puVar5 + 8) = *(int *)(iVar9 + 0x18) + aiStack_24[0];

    FUN_0600bf70();

    iVar7 = (*(int(*)())0x06027344)(*(int *)(puVar6 + 4) - *(int *)(iVar9 + 0x20));

    *(int *)0x06078668 = -(iVar7 >> 7);

    iVar7 = (*(int(*)())0x06027552)(*(int *)(iVar9 + 0x24),iVar7);

    *(int *)(puVar6 + 8) = iVar7 + *(int *)(puVar6 + 8) >> 1;

  }

  else {

    (*(int(*)())0x0603850C)(4);

    (*(int(*)())0x0603853C)(puVar8,*(int *)puVar3,0);

    (*(int(*)())puVar2)();

    (*(int(*)())0x06027358)(*(int *)(puVar6 + 4),&local_28,aiStack_24);

    *(int *)puVar5 = (*(int *)(iVar9 + 0x10) - local_28) + *(int *)0x06082A70;

    *(int *)(puVar5 + 4) = *(int *)(iVar9 + 0x14) + *(int *)puVar4;

    *(int *)(puVar5 + 8) = *(int *)(iVar9 + 0x18) + aiStack_24[0] + *(int *)0x06082A78;

  }

  return;

}

void FUN_0600bf70()
{

  short sVar1;

  sVar1 = (short)((int)(short)*(int *)(CAR_PTR_TARGET + 0x1c) * (int)DAT_0600bfe2

                 >> 10) + (short)*(int *)0x06063E34;

  if (*(int *)0x06063E1C == *(int *)0x06063E20) {

    *(int *)0x06063EEC =

         (int)(short)*(int *)0x06063EEC * 0x320 +

         (int)sVar1 * 0xe0 >> 10;

  }

  else {

    *(int *)0x06063EEC = (int)sVar1;

  }

  return;

}

void FUN_0600bffc()
{

  int bVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  int iVar5;

  unsigned char *pbVar6;

  puVar4 = (char *)0x0605A1DD;

  puVar3 = (char *)0x0608A52C;

  puVar2 = (int *)0x0607EBC4;

  pbVar6 = (unsigned char *)-495;

  bVar1 = 0;

  if (*(int *)0x06083255 != '\0') {

    (*(int(*)())0x06034708)(*(int *)0x0607EB8C);

  }

  if ((*(unsigned int *)puVar2 & (unsigned int)0x02000000) == 0) {

    if (*(int *)0x06078635 == '\0') {

      (*(int(*)())0x0600D31C)();

    }

    else {

      (*(int(*)())0x0600D336)();

    }

  }

  if ((*(char **)puVar2 == 0x00020000) && (DEMO_MODE_FLAG == 0)) {

    (*(int(*)())0x0602E610)();

  }

  iVar5 = *(int *)puVar3;

  *(int *)puVar3 = iVar5 + 0x30;

  (*(int(*)())0x06027630)(iVar5 + 0x30,OBJ_STATE_PRIMARY,0x30);

  if (*(int *)0x06059F30 == 0) {

    *(short *)0x06078664 = (short)(*(int *)0x0607EA98 >> 1);

  }

  else {

    *(unsigned short *)0x06078664 = (unsigned short)(unsigned char)*puVar4;

  }

  *(char **)0x06063574 = 0x0600C170;

  *(short *)0x21000000 = (short)0x0000FFFF;

  if ((*(unsigned int *)puVar2 & (unsigned int)0x02800008) == 0) {

    (*(int(*)())0x060058FA)();

  }

  (*(int(*)())0x06006868)();

  FUN_0600b6a0();

  if (*(char **)puVar2 != 0x02000000) {

    (*(int(*)())0x0601BDEC)();

  }

  while ((*pbVar6 & 0x80) != 0x80) {

    bVar1 = 1;

  }

  *pbVar6 = *pbVar6 & 0xf;

  if (bVar1) {

    if ((int)(unsigned int)(unsigned char)*puVar4 < *(int *)0x0607EA98) {

      *puVar4 = *puVar4 + '\x01';

    }

  }

  else if (1 < (unsigned char)*puVar4) {

    *puVar4 = *puVar4 + -1;

  }

  (*(int(*)())0x0603C000)();

  *(int *)puVar3 = *(int *)puVar3 + -0x30;

  return;

}
