#include "game.h"

extern int DAT_0601207a;
extern int DAT_0601214e;
extern int DAT_06012218;
extern int DAT_0601221a;
extern int DAT_0601221c;
extern int DAT_0601221e;
extern int DAT_060126a2;
extern int DAT_060126a4;
extern int DAT_06012884;
extern int DAT_06012886;
extern int DAT_06012888;
extern int DAT_0601288a;
extern int DAT_0601288c;
extern int DAT_0601288e;
extern int DAT_06012890;
extern int DAT_0601299a;
extern int DAT_0601299c;
extern int DAT_0601299e;
extern int DAT_060129a0;
extern int DAT_060129a2;
extern int DAT_060129a4;
extern int DAT_060129a6;
extern int DAT_06012a92;
extern int DAT_06012a94;
extern int DAT_06012a96;
extern int DAT_06012a98;
extern int DAT_06012a9a;
extern int DAT_06012a9c;
extern int DAT_06012a9e;
extern int DAT_06012aa0;
extern int DAT_06012c66;
extern int DAT_06013050;
extern int DAT_06013052;
extern int DAT_06013054;
extern int DAT_06013056;
extern int DAT_06013058;
extern int DAT_0601305a;
extern int DAT_0601305c;
extern int DAT_0601305e;
extern int DAT_06013060;
extern int DAT_06013062;
extern int DAT_06013064;
extern int DAT_06013066;
extern int DAT_06013068;
extern int DAT_060131b4;
extern int DAT_060131b6;
extern int DAT_060131b8;
extern int DAT_060131ba;
extern int DAT_060131bc;
extern int DAT_060131be;
extern int DAT_060131c0;
extern int DAT_060131c2;
extern int DAT_060131c4;
extern int DAT_060131c6;
extern int DAT_060131c8;
extern int DAT_060131ca;
extern int DAT_060131cc;
extern int DAT_060131ce;
extern int DAT_060131d0;
extern int DAT_060131d2;
extern int DAT_060131d4;
extern int DAT_060131d6;
extern int DAT_060131d8;
extern int DAT_060131da;
extern int DAT_060131dc;
extern int DAT_060131de;
extern int DAT_060131e0;
extern int DAT_060131e2;
extern int DAT_060131e4;
extern int DAT_060131e6;
extern int DAT_060131e8;
extern int DAT_060131ea;
extern int DAT_060131ec;
extern int DAT_060131ee;
extern int DAT_060131f0;
extern int DAT_060131f2;
extern int DAT_060131f4;
extern int DAT_060131f6;
extern int DAT_060131f8;
extern int DAT_060132f2;
extern int DAT_060132f4;
extern int DAT_060132f6;
extern int DAT_060132f8;
extern int DAT_060132fa;
extern int DAT_060132fc;
extern int DAT_060132fe;
extern int DAT_06013300;
extern int DAT_06013302;
extern int DAT_06013304;
extern int DAT_06013306;
extern int DAT_06013308;
extern int DAT_0601330a;
extern int DAT_0601330c;
extern int DAT_0601330e;
extern int DAT_06013310;
extern int DAT_06013312;
extern int DAT_06013314;
extern int DAT_06013316;
extern int DAT_06013318;
extern int DAT_0601331a;
extern int DAT_0601331c;
extern int DAT_0601331e;
extern int DAT_06013320;
extern int DAT_06013322;
extern int DAT_06013324;
extern int DAT_06013326;
extern int DAT_06013328;
extern int DAT_0601332a;
extern int DAT_0601332c;
extern int DAT_0601332e;
extern int DAT_06013440;
extern int DAT_06013442;
extern int DAT_06013444;
extern int DAT_06013446;
extern int DAT_06013448;
extern int DAT_0601344a;
extern int DAT_0601344c;
extern int DAT_0601344e;
extern int DAT_06013560;
extern int DAT_06013562;
extern int DAT_06013682;
extern int DAT_06013684;
extern int DAT_06013686;
extern int DAT_06013688;
extern int DAT_0601368a;
extern int DAT_0601368c;
extern int DAT_0601368e;
extern int DAT_06013690;
extern int DAT_06013692;
extern int DAT_06013694;
extern int DAT_06013696;
extern int DAT_06013698;
extern int DAT_0601369a;
extern int DAT_0601369c;
extern int DAT_0601369e;
extern int DAT_060136a0;
extern int DAT_060136a2;
extern int DAT_060136a4;
extern int DAT_060136a6;
extern int DAT_060136a8;
extern int DAT_060136aa;
extern int DAT_060136ac;
extern int DAT_060136ae;
extern int DAT_060136b0;
extern int DAT_060136b2;
extern int DAT_060136b4;
extern int DAT_060136b6;
extern int DAT_060136b8;
extern int DAT_060136ba;
extern int DAT_060136bc;
extern int DAT_060136be;
extern int DAT_060136c0;
extern int DAT_060136c2;
extern int DAT_060137b0;
extern int DAT_060137b2;
extern int DAT_060137b4;
extern int DAT_060137b6;
extern int DAT_060137b8;
extern int DAT_060137ba;
extern int DAT_060137bc;
extern int DAT_060137be;
extern int DAT_060137c0;
extern int DAT_060137c2;
extern int DAT_060138d6;
extern int DAT_060138d8;
extern int DAT_060138da;
extern int DAT_06013cca;
extern int DAT_06013ccc;
extern int DAT_06013cce;
extern int DAT_06013cd0;
extern int DAT_06013cd2;
extern int DAT_06013dc6;
extern int DAT_06013dc8;
extern int DAT_06013dca;
extern int DAT_06013dcc;
extern int DAT_06013dce;
extern int DAT_06013dd0;
extern int DAT_06013dd2;
extern int DAT_06013dd4;
extern int DAT_06013dd6;
extern int DAT_06013f46;
extern int DAT_06013f48;
extern int DAT_06013f4a;
extern int DAT_06013f4c;
extern int DAT_06014080;
extern int DAT_06014082;
extern int DAT_06014084;
extern int DAT_06014086;
extern void FUN_0601228a();
extern void FUN_060122f4();
extern void FUN_06012344();
extern int FUN_06012400();
extern void FUN_0601250c();
extern void FUN_060125d0();
extern void FUN_06012710();
extern void FUN_06012b58();
extern int FUN_06012c3c();
extern int FUN_06013c58();
extern int PTR_DAT_060137c4;
extern int PTR_DAT_06013cd4;
extern short DAT_060123de;
extern short DAT_060123e0;
extern short DAT_060123e2;
extern short DAT_06012586;

/* peripheral_config_alt -- Configure alternate SCU interrupt priorities.
 * Calls SCU interrupt config at 0x06038BD4 with (mask, priority) pairs.
 * Different priority mapping from FUN_06019324 (subsystem 18). */
void FUN_06012050(void)
{
    register void (*scu_int_config)() = (void (*)())0x06038BD4;

    scu_int_config(0x10, 7);   /* HBlank-IN: priority 7 */
    scu_int_config(8, 6);      /* VBlank-OUT: priority 6 */
    scu_int_config(0x100, 5);  /* timer 0: priority 5 */
    scu_int_config(0x20, 3);   /* timer 1: priority 3 */
    scu_int_config(4, 1);      /* VBlank-IN: priority 1 */
}

void FUN_060120c8()
{

  char *puVar1;

  char *puVar2;

  *(int *)0x06078636 = 1;

  *(int *)0x060788F8 = 0;

  (*(int(*)())0x06014884)(0x20,0,0);

  puVar1 = (char *)0x060788B4;

  *(int *)0x060788B4 = 0;

  puVar2 = (char *)0x00080000;

  *(char **)(puVar1 + 4) = 0x00080000;

  *(char **)(puVar1 + 8) = 0x000F3333;

  puVar1 = (char *)0x060788C0;

  *(int *)0x060788C0 = 0;

  *(unsigned int *)(puVar1 + 4) = (unsigned int)puVar2 >> 2;

  *(char **)(puVar1 + 8) = 0x00053333;

  (*(int(*)())0x06035168)();

  (*(int(*)())0x06035168)();

  (*(int(*)())0x06035168)();

  *(short *)0x060788B0 = DAT_0601214e;

  *(short *)0x060788B2 = 0;

  *(int *)0x060788F0 = 0;

  puVar1 = (char *)0x060788F4;

  if (CAR_COUNT == 0) {

    *(int *)0x060788AC = 0x3c;

    *(int *)puVar1 = 0;

    return;

  }

  *(int *)0x060788AC = 1;

  *(int *)puVar1 = (char *)0x14;

  FUN_0601228a();

  return;

}

void FUN_060121a8()
{

  char *puVar1;

  int iVar2;

  puVar1 = (char *)0x060788AC;

  iVar2 = *(int *)0x060788AC;

  *(int *)0x060788AC = iVar2 + 1;

  if (iVar2 + 1 < 0x14) {

    (*(int(*)())0x06028400)(8,*(int *)0x06063AF0,0x390,

               0x0000B000 + *(int *)(0x06063AF0 + 4));

    FUN_060125d0();

  }

  if (*(int *)puVar1 == 0x14) {

    (*(int(*)())0x0601D5F4)(0,0xAE110EFF);

    puVar1 = (char *)0x0605ACF0;

    (*(int(*)())0x060284AE)(8,0x390,0x90,0x0605ACF0);

    (*(int(*)())0x060284AE)(8,0x490,0x90,puVar1);

    (*(int(*)())0x060283E0)(8,0x590,0x0000E000,puVar1);

    return;

  }

  if (0x28 < *(int *)puVar1) {

    *(int *)0x06078636 = 0;

    (*(int(*)())0x0601D5F4)(0,0xAE110FFF);

    return;

  }

  if (0x14 < *(int *)puVar1) {

    FUN_06012344();

    FUN_06012400();

    return;

  }

  return;

}

void FUN_0601228a()
{

  if (0x6d < *(int *)0x0607EBCC) {

    FUN_060122f4();

    FUN_0601250c();

    FUN_06012710();

    return;

  }

  if (99 < *(int *)0x0607EBCC) {

    *(short *)0x060788B2 = 0;

    FUN_0601250c();

    FUN_06012710();

    return;

  }

  if (0x27 < *(int *)0x0607EBCC) {

    *(short *)0x060788B2 = 0;

    FUN_060125d0();

    FUN_06012710();

    return;

  }

  *(int *)0x0607EBCC = 1;

  GAME_STATE = 0x10;

  *(int *)0x06078636 = 1;

  return;

}

void FUN_060122f4()
{
  volatile int *base;
  short sub1, sub2, add_val;
  int limit1, limit2;
  short *pw;

  base = (volatile int *)0x060788B4;
  sub1 = 0x2999;
  base[1] = base[1] - sub1;

  sub2 = 0x4000;
  base[2] = base[2] - sub2;

  limit1 = 0x00020000;
  if (!(base[1] >= limit1)) {
    base[1] = limit1;
  }

  limit2 = 0x0004CCCC;
  if (!(base[2] >= limit2)) {
    base[2] = limit2;
  }

  pw = (short *)0x060788B2;
  add_val = 0x1800;
  *pw = *pw + add_val;
}

void FUN_06012344()
{
  register int (*func)() asm("r3") = (int(*)())0x06027552;
  int iVar1;
  int iVar2;
  int *p;
  int iVar4;
  int tmp;

  tmp = *(int *)0x060788AC;
  iVar4 = ((int)(tmp + (unsigned int)(tmp < 0)) >> 1) << 0x10;

  iVar1 = (*func)(iVar4, (int)DAT_060123de);
  iVar2 = (*func)(iVar4, (int)DAT_060123e0);
  iVar4 = (*func)(iVar4, (int)DAT_060123e2);

  p = (int *)0x060788C0;
  p[0] = p[0] + iVar1 * -2;
  p[1] = p[1] + iVar2;
  p[2] = p[2] + iVar4;

  p = (int *)0x060788CC;
  p[0] = p[0] - iVar2;
  p[1] = p[1] - iVar1;
  p[2] = p[2] - iVar1;

  p = (int *)0x060788D8;
  p[0] = p[0] + (iVar1 << 1);
  iVar1 = (*(int(*)())0x06034FE0)();
  p[1] = p[1] - iVar1;
  p[2] = p[2] - iVar4;

  p = (int *)0x060788E4;
  p[0] = p[0] + iVar2;
  p[1] = p[1] + iVar2;
  p[2] = p[2] + iVar4;
}

/* background_render_pipeline -- Full background rendering pipeline.
 * Initializes render state, sets camera position from 0x060788B4-BC,
 * configures render params, applies extra effect if STATE_COUNTDOWN > 99.
 * Then sets up sound BGM tempo and position for last car (CAR_COUNT-1). */
void FUN_0601250c(void)
{
    int idx;

    (*(int(*)())0x06026DBC)();   /* render state init */
    (*(int(*)())0x06026E0C)();   /* render param init */

    (*(int(*)())0x06026E2E)(*(int *)0x060788B4, *(int *)0x060788B8, *(int *)0x060788BC);

    (*(int(*)())0x06026F2A)((int)*(short *)0x060788B2);
    (*(int(*)())0x06026EDE)(0);
    (*(int(*)())0x06026E94)(0);

    if (STATE_COUNTDOWN > 99) {
        (*(int(*)())0x06026E94)((int)DAT_06012586);
    }

    idx = (CAR_COUNT - 1) << 2;

    (*(int(*)())0x06031D8C)(*(int *)(0x0606354C + idx), *(int *)0x06063558);
    (*(int(*)())0x06031A28)(*(int *)(0x06063544 + idx), (int)*(short *)0x06089EA0, *(int *)0x06063554);

    (*(int(*)())0x06026DF8)();   /* render finalize */
}

void FUN_060125d0()
{

  char *puVar1;

  int iVar2;

  int iVar3;

  int *puVar4;

  unsigned short auStack_14 [6];

  puVar1 = (char *)0x060788B0;

  (*(int(*)())0x06035228)();

  (*(int(*)())0x06026DBC)();

  (*(int(*)())0x06026E0C)();

  (*(int(*)())0x06026E2E)(*(int *)0x060788B4,*(int *)(0x060788B4 + 4),

             *(int *)(0x060788B4 + 8));

  (*(int(*)())0x06026F2A)((int)*(short *)0x060788B2);

  iVar2 = (*(int(*)())0x06034FE0)();

  iVar3 = (iVar2 << 1);

  puVar4 = (int *)(0x06063750 + (unsigned int)auStack_14[iVar2] * 8);

  (*(int(*)())0x06028400)(8,*puVar4,0x390,0x0000B000 + puVar4[1],puVar4,iVar3,iVar2);

  if (*(short *)puVar1 != *(short *)(0x0605AC94 + iVar3)) {

    *(short *)puVar1 = *(short *)puVar1 - DAT_060126a4;

  }

  (*(int(*)())0x06026EDE)(0);

  (*(int(*)())0x06026E94)((int)*(short *)puVar1);

  (*(int(*)())0x06031D8C)(*(int *)(0x0606354C + (CAR_COUNT + -1) << 2),

             *(int *)0x06063558);

  (*(int(*)())0x06031A28)(*(int *)(0x06063544 + (CAR_COUNT + -1) << 2),

             (int)*(short *)0x06089EA0,*(int *)0x06063554);

  (*(int(*)())0x06026DF8)();

  return;

}

void FUN_06012710()
{

  char *puVar1;

  char *puVar2;

  int uVar3;

  int iVar4;

  int uVar5;

  uVar3 = 0xAE1115FF;

  puVar2 = (char *)0x0601D5F4;

  puVar1 = (char *)0x0607EBCC;

  iVar4 = *(int *)0x0607EBCC;

  if (iVar4 == 0x28) {

    (*(int(*)())0x0601D5F4)(0,0xAE1125FF);

    (*(int(*)())puVar2)(0,0xAE1116FF);

    *(short *)0x06086056 = 0x3c;

    *(int *)0x0608605A = 1;

  }

  else {

    uVar5 = 0xAE1124FF;

    if ((iVar4 != 0x3c) && (uVar5 = 0xAE1123FF, iVar4 != 0x50)) {

      if (iVar4 != 100) goto LAB_0601277a;

      *(int *)0x06078654 = 1;

      *(int *)0x06063EF0 = *(int *)(CAR_PTR_TARGET + 0x30);

      uVar5 = 0xAE1122FF;

    }

    (*(int(*)())puVar2)(0,uVar5);

    (*(int(*)())puVar2)(0,uVar3);

  }

LAB_0601277a:

  iVar4 = (*(int(*)())0x06035C2C)();

  if (0x6e < *(int *)puVar1 && iVar4 == 0) {

    (*(int(*)())puVar2)(0,0xAE110CFF);

  }

  return;

}

int FUN_060127e0()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  char *puVar6;

  char *puVar7;

  int iVar8;

  int iVar9;

  int *puVar10;

  int iVar11;

  int *local_24;

  puVar1 = (char *)0x060788F8;

  *(int *)0x0605B714 = *(int *)0x060788F8;

  INPUT_STATE = INPUT_STATE | 0x80;

  *(char **)puVar1 = 0x0004CCCC + *(int *)puVar1;

  puVar7 = (int *)0x060284AE;

  puVar6 = (char *)0x060788F4;

  puVar5 = (char *)0x06063750;

  puVar4 = (char *)0x06028400;

  puVar3 = (char *)0x0605ACDD;

  puVar2 = (char *)0x0601D5F4;

  puVar1 = (char *)0x060283E0;

  iVar9 = *(int *)(CAR_PTR_TARGET + (int)DAT_06012884);

  iVar11 = 0x90;

  iVar8 = *(int *)0x060788F4;

  if (iVar8 == 0) {

    (*(int(*)())0x06028400)(0xc,*(int *)(0x06063750 + DAT_06012888),0x880,

               *(int *)((int)(0x06063750 + DAT_06012888) + 4));

    iVar9 = (*(int(*)())puVar4)(0xc,*(int *)(puVar5 + DAT_0601288c),(int)DAT_0601288e,

                              *(int *)((int)(puVar5 + DAT_0601288c) + 4));

    *(int *)puVar6 = *(int *)puVar6 + 1;

  }

  else if (iVar8 == 1) {

    if (iVar9 == 0x52) {

      *(int *)0x060788F4 = *(int *)0x060788F4 + 1;

      (*(int(*)())puVar1)(8,(int)DAT_0601299e,0x0000F000,puVar3);

      (*(int(*)())puVar1)(8,(int)DAT_060129a0,0x0000F000,puVar3);

      (*(int(*)())puVar1)(8,(int)DAT_060129a2,0x0000F000,puVar3);

      (*(int(*)())puVar4)(8,*(int *)(puVar5 + 0x78),(int)DAT_060129a6,

                        *(int *)(puVar5 + 0x7c) + (int)DAT_060129a4);

      iVar9 = (*(int(*)())puVar2)(0,0xAE1122FF);

    }

    else {

      if (((*(unsigned short *)0x06063D98 & *(unsigned short *)0x0608188C) == 0) &&

         (*(short *)0x0607ED8C == 0)) {

        local_24 = (int *)(0x06063750 + DAT_0601299a);

        iVar9 = local_24[1] + (int)DAT_0601299c;

      }

      else {

        local_24 = (int *)(0x06063750 + iVar11);

        iVar9 = local_24[1] + (int)DAT_06012890;

      }

      iVar9 = (*(int(*)())0x06028400)(8,*local_24,(int)DAT_0601299e,iVar9);

    }

  }

  else if (iVar8 == 2) {

    if (iVar9 == 0x58) {

      puVar10 = (int *)(0x06063750 + 0x70);

      *(int *)0x060788F4 = *(int *)0x060788F4 + 1;

      (*(int(*)())puVar4)(8,*puVar10,(int)DAT_060129a6,*(int *)(puVar5 + 0x74) + (int)DAT_060129a4);

      *(int *)0x06078654 = 1;

      *(int *)0x06063EF0 = *(int *)(CAR_PTR_TARGET + 0x30);

      iVar9 = (*(int(*)())puVar2)(0,0xAE1123FF);

    }

  }

  else if (iVar8 == 3) {

    if (iVar9 == 0x5d) {

      puVar10 = (int *)(0x06063750 + 0x68);

      *(int *)0x060788F4 = *(int *)0x060788F4 + 1;

      (*(int(*)())puVar4)(8,*puVar10,(int)DAT_060129a6,*(int *)(puVar5 + 0x6c) + (int)DAT_060129a4);

      iVar9 = (*(int(*)())puVar2)(0,0xAE1124FF);

    }

  }

  else if (iVar8 == 4) {

    if (iVar9 == 0x61) {

      *(int *)0x060788F4 = *(int *)0x060788F4 + 1;

      (*(int(*)())puVar4)(8,*(int *)(puVar5 + DAT_06012a92),0x520,

                        *(int *)((int)(puVar5 + DAT_06012a92) + 4) + (int)DAT_06012a94);

      iVar9 = (*(int(*)())puVar2)(0,0xAE1125FF);

      *(short *)0x06086056 = 0x14;

      *(int *)0x0608605A = 1;

    }

  }

  else if (iVar8 == 0x13) {

    (*(int(*)())0x060284AE)(8,0x520,iVar11,0x0605ACDD);

    (*(int(*)())puVar7)(8,0x620,iVar11,puVar3);

    (*(int(*)())puVar7)(8,0x720,iVar11,puVar3);

    (*(int(*)())puVar1)(8,0x820,0x0000F000,puVar3);

    (*(int(*)())puVar7)(0xc,0x880,iVar11,0x0605AC9C);

    iVar9 = (*(int(*)())puVar7)(0xc,0x980,iVar11,0x0605AC9C);

    *(int *)0x0605B714 = 0;

    *(int *)0x06078636 = 0;

  }

  else {

    *(int *)0x060788F4 = *(int *)0x060788F4 + 1;

    iVar9 = iVar8;

  }

  return iVar9;

}

void FUN_06012b58()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  int iVar4;

  int iVar5;

  puVar2 = (char *)0x06084360;

  puVar1 = (char *)0x0603AC1C;

  iVar4 = -1;

  *(int *)0x06084360 = 1;

  *(char **)(puVar2 + 8) = 0x0608436C;

  *(int *)(puVar2 + 4) = 0x50;

  puVar2 = (char *)0x06083274;

  iVar5 = 0;

  while (puVar3 = 0x06084AEC, iVar5 = iVar5 + 1, iVar5 < 5) {

    iVar4 = (*(int(*)())puVar1)(5,puVar2,0x06084360);

  }

  if (iVar4 < 3) {

    *(int *)0x06084AEC = 1;

  }

  else {

    iVar4 = (*(int(*)())0x0603AE08)(0x060448C8);

    if (iVar4 < 0) {

      *puVar3 = 1;

    }

    else {

      *puVar3 = 0;

    }

  }

  return;

}

void FUN_06012bdc()
{

  char *puVar1;

  unsigned int uVar2;

  int iVar3;

  puVar1 = (char *)0x06018EAC;

  iVar3 = (int)DAT_06012c66;

  (*(int(*)())0x060283E0)(8,iVar3,0x0000E000,0x060448D4);

  (*(int(*)())0x0602761E)(*(int *)0x060612B4 + iVar3,0x060612C4 + iVar3,0x24);

  (*(int(*)())0x06034C48)();

  do {

    uVar2 = (*(int(*)())puVar1)();

  } while ((uVar2 & 0xf) != 1);

  (*(int(*)())0x060283E0)(8,iVar3,0x0000E000,0x0605ACCA);

  (*(int(*)())0x0602761E)(*(int *)0x060612B4 + iVar3,0x060612C4 + iVar3,0x24);

  FUN_06012b58();

  return;

}

/* bg_tilemap_load -- Load background tilemap for a course.
 * param_1: course index (1/2/default). Selects tilemap descriptor
 * from table at 0x060448E8 stride 0x0C, loads to VDP2 VRAM at 0x200000. */
void FUN_06012d7c(int param_1)
{
    if (param_1 == 1)
        FUN_06012c3c(0x060448E8, 0x00200000);
    else if (param_1 == 2)
        FUN_06012c3c(0x060448F4, 0x00200000);
    else
        FUN_06012c3c(0x06044900, 0x00200000);
}

void FUN_06012db4(param_1)
    int param_1;
{

  char *puVar1;

  puVar1 = (char *)0x00240000;

  if (param_1 == 1) {

    FUN_06012c3c(0x0604490C,0x00200000);

    FUN_06012c3c(0x0604491C,puVar1);

    return;

  }

  if (param_1 == 2) {

    FUN_06012c3c(0x06044928,0x00200000);

    FUN_06012c3c(0x06044938,puVar1);

    return;

  }

  FUN_06012c3c(0x06044944,0x00200000);

  FUN_06012c3c(0x06044954,puVar1);

  return;

}

/* bg_pattern_load -- Load background pattern data for a course.
 * param_1: course index (1/2/default). Selects pattern descriptor
 * from table at 0x0604496C stride 0x0C, loads to VDP2 VRAM at 0x2A8000. */
void FUN_06012e08(int param_1)
{
    if (param_1 == 1)
        FUN_06012c3c(0x0604496C, 0x002A8000);
    else if (param_1 == 2)
        FUN_06012c3c(0x06044978, 0x002A8000);
    else
        FUN_06012c3c(0x06044984, 0x002A8000);
}

void FUN_06012f80()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  int *piVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  *(char **)0x06084FA8 = 0x06084B28;

  *(char **)0x06084FAC = 0x06084CA8;

  *(char **)0x06084FB0 = 0x06084E28;

  (*(int(*)())0x060149E0)();

  (*(int(*)())0x06026CE0)();

  (*(int(*)())0x06039250)(0x06063F5C);

  (*(int(*)())0x060393FC)(0,0,0,(int)DAT_06013052,(int)DAT_06013050);

  VDP1_CMD_BASE_PTR = 0;

  **(short **)0x06063F5C = (short)0x00008000;

  puVar1 = (char *)0x0602853E;

  (*(int(*)())0x0602853E)(0);

  (*(int(*)())puVar1)(4);

  (*(int(*)())puVar1)(8);

  (*(int(*)())puVar1)(0xc);

  (*(int(*)())(BIOS_FUNC_0344))(0xffffffff,0x83);

  (*(int(*)())0x06012E00)();

  (*(int(*)())(BIOS_FUNC_0344))(-132,0);

  *(int *)0x0606A4F4 = 0;

  *(int *)0x0606A4EC = (int)DAT_06013058;

  puVar1 = (char *)0x06089E44;

  *(short *)(0x06089E44 + 6) = 2;

  *(short *)puVar1 = 0;

  puVar3 = (char *)0x002A0000;

  puVar2 = (char *)0x06007658;

  iVar7 = 0x108;

  (*(int(*)())0x06007658)(1,iVar7,0,0x002A0000 + DAT_0601305c);

  (*(int(*)())puVar2)(2,0x810,0,puVar3 + DAT_0601305e);

  (*(int(*)())puVar2)(3,(int)DAT_06013064,0,puVar3 + DAT_06013062);

  (*(int(*)())puVar2)(4,(int)DAT_06013068,0,puVar3 + DAT_06013066);

  (*(int(*)())puVar2)(5,0x519,0,puVar3 + DAT_060131b4);

  (*(int(*)())puVar2)(6,(int)DAT_060131ba,0,puVar3 + DAT_060131b8);

  (*(int(*)())puVar2)(7,0x738,4,puVar3 + DAT_060131bc);

  (*(int(*)())puVar2)(8,0x738,4,puVar3 + DAT_060131c0);

  (*(int(*)())puVar2)(9,0x208,0,puVar3 + DAT_060131c2);

  (*(int(*)())puVar2)(10,0xa28,0x3c,puVar3 + DAT_060131c6);

  (*(int(*)())puVar2)(0x10,0x228,8,puVar3 + DAT_060131ca);

  (*(int(*)())puVar2)(0x11,0x428,8,puVar3 + DAT_060131ce);

  (*(int(*)())puVar2)(0x12,0x418,8,puVar3 + DAT_060131d2);

  (*(int(*)())puVar2)(0x13,0x820,8,puVar3 + DAT_060131d6);

  (*(int(*)())puVar2)(0x14,0x518,8,puVar3 + DAT_060131da);

  (*(int(*)())puVar2)(0x15,0x518,8,puVar3 + DAT_060131de);

  (*(int(*)())puVar2)(0x16,0x508,0xc,puVar3 + DAT_060131e0);

  (*(int(*)())puVar2)(0x17,0xd10,8,puVar3 + DAT_060131e4);

  (*(int(*)())puVar2)(0x18,(int)DAT_060131ea,0x1c,puVar3 + DAT_060131e8);

  iVar5 = 0x348;

  (*(int(*)())puVar2)(0x19,iVar5,0x10,puVar3 + DAT_060131ee);

  (*(int(*)())puVar2)(0x1a,iVar5,0x10,puVar3 + DAT_060131f0);

  (*(int(*)())puVar2)(0x1b,iVar5,0x10,puVar3 + DAT_060131f2);

  iVar6 = 0x630;

  (*(int(*)())puVar2)(0x1c,iVar6,0x1c,puVar3 + DAT_060131f6);

  (*(int(*)())puVar2)(0x1d,0xa28,0x10,puVar3 + DAT_060131f8);

  (*(int(*)())puVar2)(0x1e,0xc08,0x18,puVar3 + DAT_060132f2);

  (*(int(*)())puVar2)(0x1f,0xc10,0x18,puVar3 + DAT_060132f6);

  iVar5 = 0x308;

  (*(int(*)())puVar2)(0x20,iVar5,0xc,puVar3 + DAT_060132fc);

  (*(int(*)())puVar2)(0x21,0x410,0xc,puVar3 + DAT_060132fe);

  (*(int(*)())puVar2)(0x22,iVar5,0xc,puVar3 + DAT_06013302);

  (*(int(*)())puVar2)(0x23,iVar5,0xc,puVar3 + DAT_06013304);

  (*(int(*)())puVar2)(0x24,0x410,0xc,puVar3 + DAT_06013306);

  (*(int(*)())puVar2)(0x25,(int)DAT_0601330a,0x14,puVar3 + DAT_06013308);

  (*(int(*)())puVar2)(0x26,(int)DAT_0601330a,0x14,puVar3 + DAT_0601330c);

  (*(int(*)())puVar2)(0x27,0x610,0xc,puVar3 + DAT_0601330e);

  (*(int(*)())puVar2)(0x28,0x510,0x14,puVar3 + DAT_06013312);

  iVar5 = 0x310;

  (*(int(*)())puVar2)(0x29,iVar5,0x14,puVar3 + DAT_06013318);

  (*(int(*)())puVar2)(0x2a,(int)DAT_0601331c,0x14,puVar3 + DAT_0601331a);

  (*(int(*)())puVar2)(0x2b,(int)DAT_06013320,0x14,puVar3 + DAT_0601331e);

  (*(int(*)())puVar2)(0x2c,0x110,0xc,puVar3 + DAT_06013322);

  (*(int(*)())puVar2)(0x2d,0x110,0xc,puVar3 + DAT_06013326);

  (*(int(*)())puVar2)(0x2e,0x510,0x14,puVar3 + DAT_06013328);

  (*(int(*)())puVar2)(0x2f,iVar5,0x14,puVar3 + DAT_0601332a);

  (*(int(*)())puVar2)(0x30,(int)DAT_0601331c,0x14,puVar3 + DAT_0601332c);

  (*(int(*)())puVar2)(0x31,(int)DAT_06013320,0x14,puVar3 + DAT_0601332e);

  (*(int(*)())puVar2)(0x32,iVar7,0x14,puVar3 + DAT_06013440);

  (*(int(*)())puVar2)(0x33,iVar7,0x14,puVar3 + DAT_06013442);

  (*(int(*)())puVar2)(0x34,iVar7,0x14,puVar3 + DAT_06013444);

  (*(int(*)())puVar2)(0x35,iVar7,0x14,puVar3 + DAT_06013446);

  (*(int(*)())puVar2)(0x36,iVar7,0x10,puVar3 + DAT_06013448);

  (*(int(*)())puVar2)(0x37,iVar7,0x1c,puVar3 + DAT_0601344a);

  (*(int(*)())puVar2)(0x38,iVar7,8,puVar3 + DAT_0601344c);

  (*(int(*)())puVar2)(0x39,iVar7,0x10,puVar3 + DAT_0601344e);

  *(short *)(puVar1 + 2) = 1;

  puVar1 = (char *)0x06007540;

  (*(int(*)())0x06007540)(0x41,1,0);

  (*(int(*)())puVar1)(0x42,2,0);

  (*(int(*)())puVar1)(0x43,3,0);

  (*(int(*)())puVar1)(0x44,4,0);

  (*(int(*)())puVar1)(0x45,5,0);

  (*(int(*)())puVar1)(0x46,6,0);

  (*(int(*)())puVar1)(0x47,7,4);

  (*(int(*)())puVar1)(0x48,8,4);

  (*(int(*)())puVar1)(0x49,9,0);

  (*(int(*)())puVar1)(0x4a,10,0x3c);

  (*(int(*)())puVar1)(0x50,0x10,0x20);

  (*(int(*)())puVar1)(0x51,0x11,0x20);

  (*(int(*)())puVar1)(0x52,0x12,0x20);

  (*(int(*)())puVar1)(0x53,0x13,0x20);

  (*(int(*)())puVar1)(0x54,0x14,0x20);

  (*(int(*)())puVar1)(0x55,0x15,0x20);

  (*(int(*)())puVar1)(0x56,0x16,0x24);

  (*(int(*)())puVar1)(0x57,0x17,0x20);

  (*(int(*)())puVar1)(0x58,0x18,0x34);

  (*(int(*)())puVar1)(0x59,0x19,0x28);

  (*(int(*)())puVar1)(0x5a,0x1a,0x28);

  (*(int(*)())puVar1)(0x5b,0x1b,0x28);

  (*(int(*)())puVar1)(0x5c,0x1c,0x34);

  (*(int(*)())puVar1)(0x5d,0x1d,0x28);

  (*(int(*)())puVar1)(0x5e,0x1e,0x30);

  (*(int(*)())puVar1)(0x5f,0x1f,0x30);

  (*(int(*)())puVar1)(0x60,0x20,0x24);

  (*(int(*)())puVar1)(0x61,0x21,0x24);

  (*(int(*)())puVar1)(0x62,0x22,0x24);

  (*(int(*)())puVar1)(99,0x23,0x24);

  (*(int(*)())puVar1)(100,0x24);

  (*(int(*)())puVar1)(0x65,0x25,0x2c);

  (*(int(*)())puVar1)(0x66,0x26,0x2c);

  (*(int(*)())puVar1)(0x67,0x27,0x24);

  (*(int(*)())puVar1)(0x68,0x28,0x2c);

  (*(int(*)())puVar1)(0x69,0x29,0x2c);

  (*(int(*)())puVar1)(0x6a,0x2a,0x2c);

  (*(int(*)())puVar1)(0x6b,0x2b,0x2c);

  (*(int(*)())puVar1)(0x6c,0x2c,0x24);

  (*(int(*)())puVar1)(0x6d,0x2d,0x24);

  (*(int(*)())puVar1)(0x6e,0x2e,0x2c);

  (*(int(*)())puVar1)(0x6f,0x2f,0x2c);

  (*(int(*)())puVar1)(0x70,0x30,0x2c);

  (*(int(*)())puVar1)(0x71,0x31,0x2c);

  (*(int(*)())puVar1)(0x72,0x32,0x2c);

  (*(int(*)())puVar1)(0x73,0x33,0x2c);

  (*(int(*)())puVar1)(0x74,0x34,0x2c);

  (*(int(*)())puVar1)(0x75,0x35,0x2c);

  (*(int(*)())puVar1)(0x76,0x36,0x28);

  (*(int(*)())puVar1)(0x77,0x37,0x34);

  (*(int(*)())puVar1)(0x78,0x38,0x20);

  (*(int(*)())puVar1)(0x79,0x39,0x28);

  iVar7 = 0x730;

  (*(int(*)())puVar2)(0x8a,iVar7,0x74,puVar3 + DAT_06013562);

  (*(int(*)())puVar2)(0x8b,iVar6,0x74,puVar3 + DAT_06013682);

  (*(int(*)())puVar2)(0x8c,iVar6,0x74,puVar3 + DAT_06013684);

  (*(int(*)())puVar2)(0x8d,iVar7,0x74,puVar3 + DAT_06013686);

  (*(int(*)())puVar2)(0x8e,iVar6,0x74,puVar3 + DAT_06013688);

  (*(int(*)())puVar2)(0x8f,iVar6,0x74,puVar3 + DAT_0601368a);

  (*(int(*)())puVar2)(0x90,iVar6,0x74,puVar3 + DAT_0601368c);

  (*(int(*)())puVar2)(0x91,0x830,0x74,puVar3 + DAT_0601368e);

  (*(int(*)())puVar2)(0x92,0x430,0x74,puVar3 + DAT_06013694);

  (*(int(*)())puVar2)(0x93,0x540,0x74,puVar3 + DAT_0601369a);

  (*(int(*)())puVar2)(0x94,iVar6,0x74,puVar3 + DAT_060136a0);

  (*(int(*)())puVar2)((int)DAT_060136a6,0x530,0x74,puVar3 + DAT_060136a2);

  (*(int(*)())puVar2)((int)DAT_060136aa,0x830,0x74,puVar3 + DAT_060136a8);

  (*(int(*)())puVar2)(0x97,iVar7,0x74,puVar3 + DAT_060136ac);

  (*(int(*)())puVar2)(0x98,iVar7,0x74,puVar3 + DAT_060136ae);

  (*(int(*)())puVar2)(0x99,iVar6,0x74,puVar3 + DAT_060136b0);

  (*(int(*)())puVar2)(0x9a,0x840,0x74,puVar3 + DAT_060136b2);

  (*(int(*)())puVar2)(0x9b,iVar6,0x74,puVar3 + DAT_060136b8);

  (*(int(*)())puVar2)((int)DAT_060136bc,0x530,0x74,puVar3 + DAT_060136ba);

  (*(int(*)())puVar2)(0x9d,iVar6,0x74,puVar3 + DAT_060136be);

  (*(int(*)())puVar2)(0x9e,iVar7,0x74,puVar3 + DAT_060136c0);

  (*(int(*)())puVar2)(0x9f,iVar6,0x74,puVar3 + DAT_060136c2);

  (*(int(*)())puVar2)(0xa0,0x930,0x74,puVar3 + DAT_060137b0);

  (*(int(*)())puVar2)(0xa1,iVar7,0x74,puVar3 + DAT_060137b6);

  (*(int(*)())puVar2)(0xa2,iVar6,0x74,puVar3 + DAT_060137b8);

  (*(int(*)())puVar2)(0xa3,iVar7,0x74,puVar3 + DAT_060137ba);

  (*(int(*)())puVar2)(0xa4,iVar6,0x74,puVar3 + DAT_060137bc);

  (*(int(*)())puVar2)(0xa5,iVar6,0x74,puVar3 + DAT_060137be);

  (*(int(*)())puVar2)(0xa6,iVar7,0x74,puVar3 + DAT_060137c0);

  (*(int(*)())puVar2)(0xa7,iVar5,0x70,puVar3 + DAT_060137c2);

  puVar1 = (char *)0x0602761E;

  (*(int(*)())0x0602761E)(0x25F00000,0x0604878C,0x20);

  (*(int(*)())puVar1)(0x25F00600,0x0604814C,0x60);

  (*(int(*)())puVar1)(0x25F00660,0x0604848C,0x40);

  (*(int(*)())puVar1)(0x25F006A0,0x060484CC,0x40);

  puVar2 = (char *)0x060485AC;

  (*(int(*)())puVar1)(0x25F006E0,0x060485AC,0x40);

  (*(int(*)())puVar1)(0x25F004E0,puVar2,0x40);

  (*(int(*)())puVar1)(0x25F00720,0x0605CD9C,0x20);

  puVar1 = (char *)0x06038BD4;

  (*(int(*)())0x06038BD4)(0x10,4);

  (*(int(*)())puVar1)(0x100,5);

  (*(int(*)())puVar1)(8,6);

  iVar5 = CAR_COUNT;

  *(int *)0x06084B00 = *(int *)(0x0605AD14 + (iVar5 << 2));

  *(int *)0x06084B1C = *(int *)(0x0605AD20 + (iVar5 << 2));

  FUN_06013c58();

  puVar1 = (char *)0x06084B08;

  *(int *)0x06084B08 = 0xf;

  *(int *)0x06084B0C = 0xf;

  *(int *)0x06084B18 = 0;

  *(int *)0x06084B20 = 0x50;

  *(short *)0x06084AF0 = DAT_060138d6;

  *(int *)0x0607EBCC = (int)DAT_060138d8;

  *(int *)0x06084AF2 = 0;

  puVar2 = (char *)0x06084B14;

  *(int *)0x06084B14 = 0;

  puVar2[1] = 0;

  puVar2[2] = 0;

  puVar2[3] = 0;

  piVar4 = (int *)(0x0605AD5C + *(int *)((int)(int)puVar1 << 5));

  *(short *)0x06084AF8 = *(short *)(piVar4 + 6);

  *(int *)0x06084AFC = *piVar4 + (int)DAT_060138da;

  *(short *)0x0605AAA0 = 0;

  (*(int(*)())0x0601D5F4)(0,0xAB1100FF);

  (*(int(*)())0x060149CC)();

  (*(int(*)())0x06026CE0)();

  return;

}

/* background_update -- Per-frame background processing.
 * 1. Dispatch through background mode vtable (indexed by 0x06084AF2)
 * 2. Update background scroll/animation with fixed-point parameters
 * 3. Commit frame display (frame_end_display_commit) */
void FUN_0601389e(void)
{
    (*(int(*)())(*(int *)(0x0605B6B8 + (unsigned int)(unsigned char)*(int *)(0x06084AF2 << 2))))();
    (*(int(*)())0x06011AF4)(0, 0x00960000, 0x00010000, 0x00010000, 0x00008000, 0x00010000, 0);
    (*(int(*)())0x060078DC)();  /* frame_end_display_commit */
}

int FUN_06013c58()
{

  short sVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  int uVar5;

  char *puVar6;

  unsigned int uVar7;

  int iVar8;

  unsigned int uVar9;

  puVar4 = (char *)0x0602853E;

  puVar6 = (char *)0x06078900;

  puVar3 = (char *)0x06063750;

  puVar2 = (char *)0x06028400;

  (*(int(*)())0x0602853E)(4);

  (*(int(*)())puVar4)(0xc);

  (*(int(*)())0x06028560)();

  (*(int(*)())puVar2)(8,*(int *)(puVar3 + DAT_06013cca),0,

                    *(int *)((int)(puVar3 + DAT_06013cca) + 4));

  (*(int(*)())puVar4)(4);

  iVar8 = (int)DAT_06013ccc;

  (*(int(*)())puVar2)(4,*(int *)(puVar3 + DAT_06013cce),0x18,

                    *(int *)((int)(puVar3 + DAT_06013cce) + 4) + iVar8);

  (*(int(*)())puVar2)(4,*(int *)(puVar3 + DAT_06013cd0),0xcb0,

                    *(int *)((int)(puVar3 + DAT_06013cd0) + 4) + iVar8);

  sVar1 = DAT_06013dc6;

  if (*(int *)0x06085FF4 == '\0') {

    sVar1 = PTR_DAT_06013cd4;

  }

  (*(int(*)())puVar2)(4,*(int *)(puVar3 + sVar1),(int)DAT_06013dc8,

                    *(int *)((int)(puVar3 + sVar1) + 4) + iVar8);

  puVar4 = (char *)0x06014884;

  (*(int(*)())0x06014884)(8,0);

  (*(int(*)())puVar4)(0x10,0);

  (*(int(*)())puVar4)(0x20,0);

  puVar4 = (char *)0x06005DD4;

  uVar5 = (*(int(*)())0x06005DD4)(*(int *)(puVar6 + DAT_06013dca));

  (*(int(*)())0x060284AE)(0xc,(int)DAT_06013dce,(int)DAT_06013dcc,uVar5);

  puVar6 = (char *)0x000927BF;

  if (*(char **)0x060786A4 <= 0x000927BF) {

    puVar6 = *(char **)0x060786A4;

  }

  uVar5 = (*(int(*)())puVar4)(puVar6);

  (*(int(*)())0x060284AE)(0xc,0xc98,(int)DAT_06013dcc,uVar5);

  if (*(int *)0x06085FF8 == '\0') {

    uVar5 = (*(int(*)())0x060283E0)(0xc,(int)DAT_06013dd6,0x0000F000,0x06044A58);

    return uVar5;

  }

  (*(int(*)())0x06028430)(0xc,(int)DAT_06013dd2,0x30,(unsigned char)*(int *)0x06086012 + 1);

  uVar9 = (unsigned int)(unsigned char)*(int *)0x06086012;

  uVar7 = uVar9;

  if (2 < uVar9) {

    uVar7 = 3;

  }

  if (2 < uVar9) {

    uVar9 = 3;

  }

  uVar5 = (*(int(*)())puVar2)(0xc,*(int *)(puVar3 + ((uVar9 + 0x48) << 3)),(int)DAT_06013dd4,

                            *(int *)(puVar3 + ((uVar7 + 0x48) << 3) + 4));

  return uVar5;

}

/* background_rotation_wobble -- Apply periodic rotation to background.
 * Uses low 5 bits of FRAME_COUNTER to create a wobble effect.
 * Only applies rotation when counter > 16, scaling by <<12 for angle. */
void FUN_06013e12(void)
{
    unsigned short phase = (unsigned short)FRAME_COUNTER & 0x1F;
    if (phase > 0x10) {
        (*(int(*)())0x06026EDE)((int)(short)(phase << 12));  /* heading_rotation */
    }
}

int FUN_06013e3c()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  int iVar6;

  int uVar7;

  int uVar8;

  int iVar9;

  int *piVar10;

  int iVar11;

  int *piVar12;

  puVar4 = (char *)0x00010000;

  puVar3 = (char *)0x06084AF6;

  puVar2 = (char *)0x06027552;

  puVar1 = (char *)0x06026F2A;

  (*(int(*)())0x06026E0C)();

  puVar5 = (char *)0x06089E4A;

  iVar11 = 0;

  piVar10 = (int *)(0x0605AD5C + DAT_06013f46);

  piVar12 = (int *)0x0605AD5C;

  do {

    (*(int(*)())0x06026DBC)();

    iVar6 = (*(int(*)())puVar2)((unsigned int)*(unsigned short *)puVar3 * (int)puVar4,(int)DAT_06013f48,puVar4);

    (*(int(*)())0x06026E2E)(0,DAT_06013f4a + iVar6,puVar4);

    (*(int(*)())puVar1)((int)*(short *)(piVar12 + 6));

    uVar7 = (*(int(*)())puVar2)(piVar12[1],(unsigned int)*(unsigned short *)puVar3 * (int)puVar4);

    iVar6 = (*(int(*)())puVar2)(piVar12[2],(unsigned int)*(unsigned short *)puVar3 * (int)puVar4);

    iVar9 = *piVar12;

    uVar8 = (*(int(*)())puVar2)(piVar12[3],(unsigned int)*(unsigned short *)puVar3 * (int)puVar4);

    (*(int(*)())0x06026E2E)(uVar7,iVar9 - iVar6,uVar8);

    (*(int(*)())puVar1)(-(int)*(short *)(piVar12 + 6));

    (*(int(*)())0x06026E94)((int)*(short *)((int)piVar12 + 0x1a) * (unsigned int)*(unsigned short *)puVar3);

    (*(int(*)())0x06026EDE)((int)*(short *)(piVar12 + 7) * (unsigned int)*(unsigned short *)puVar3);

    (*(int(*)())puVar1)((int)*(short *)((int)piVar12 + 0x1e) * (unsigned int)*(unsigned short *)puVar3);

    iVar6 = (*(int(*)())puVar2)(piVar12[4],(unsigned int)*(unsigned short *)puVar3 * (int)puVar4);

    iVar6 = DAT_06013f4c + iVar6;

    (*(int(*)())0x06026E60)(iVar6,iVar6,iVar6);

    (*(int(*)())0x06031D8C)(*(int *)(0x06062338 + iVar11),4);

    uVar7 = (*(int(*)())0x06031A28)(*(int *)(0x060622C0 + iVar11),(int)*(short *)puVar5,1);

    piVar12 = piVar12 + 8;

    OBJ_STATE_PRIMARY = OBJ_STATE_PRIMARY + -0x30;

    iVar11 = iVar11 + 4;

  } while (piVar12 < piVar10);

  return uVar7;

}

void FUN_06013fc4()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  int iVar6;

  int *puVar7;

  int iVar8;

  int *puVar9;

  puVar4 = (char *)0x00010000;

  puVar3 = (char *)0x06026E2E;

  puVar2 = (char *)0x06089EDC;

  puVar1 = (char *)0x06026F2A;

  (*(int(*)())0x06026E0C)();

  puVar5 = (char *)0x06089E4A;

  iVar8 = 0;

  puVar7 = (int *)(0x0605AD5C + DAT_06014080);

  puVar9 = (int *)0x0605AD5C;

  do {

    (*(int(*)())0x06026DBC)();

    (*(int(*)())puVar3)(0,(int)DAT_06014082,puVar4);

    (*(int(*)())puVar1)((int)*(short *)(puVar9 + 6));

    (*(int(*)())puVar3)(0,*puVar9);

    (*(int(*)())puVar1)(-(int)*(short *)(puVar9 + 6));

    iVar6 = (*(int(*)())0x06027552)((int)DAT_06014084,(unsigned int)*(unsigned short *)0x06084AF6 * (int)puVar4);

    iVar6 = DAT_06014086 + iVar6;

    (*(int(*)())0x06026E60)(iVar6,iVar6,iVar6);

    (*(int(*)())0x06031D8C)(*(int *)(0x06062338 + iVar8),4);

    (*(int(*)())0x06031A28)(*(int *)(0x060622C0 + iVar8),(int)*(short *)puVar5,1);

    puVar9 = puVar9 + 8;

    *(int *)puVar2 = *(int *)puVar2 + -0x30;

    iVar8 = iVar8 + 4;

  } while (puVar9 < puVar7);

  return;

}
