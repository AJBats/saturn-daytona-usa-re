#include "game.h"

extern int DAT_06026336;
extern int DAT_060263c2;
extern int DAT_06026462;
extern int DAT_060264ee;
extern int DAT_06026728;
extern int DAT_0602672a;
extern int DAT_0602672c;
extern int DAT_0602672e;
extern int DAT_06026848;
extern int DAT_0602684a;
extern int DAT_060268a6;
extern int DAT_06026922;
extern int DAT_06027d26;
extern int DAT_06027de2;
extern int DAT_06027e18;
extern int DAT_06027e98;
extern int DAT_06027e9a;
extern int DAT_06027f56;
extern int DAT_0602805c;
extern unsigned int FUN_06026362();
extern unsigned int FUN_0602648e();
extern void FUN_06026ca4();
extern void FUN_06027358();
extern int PTR_DAT_06026668;
extern int PTR_DAT_0602684c;
extern int PTR_DAT_06026cd4;
extern int PTR_DAT_06027da0;
extern int PTR_DAT_06027fc0;
extern int PTR_DAT_06027ffc;
extern int PTR_DAT_0602802c;
extern short DAT_06026576;
extern short DAT_06026578;

unsigned int FUN_06026110()
{

  short sVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  unsigned int uVar6;

  unsigned int uVar7;

  unsigned int uVar8;

  unsigned short uVar9;

  puVar5 = (int *)0x06060D7C;

  puVar4 = (char *)0x060610BC;

  puVar3 = (char *)0x0606107C;

  puVar2 = (int *)0x06060F2C;

  *(int *)0x06061198 = 0;

  *(int *)0x06061199 = 0;

  uVar6 = (unsigned int)*(int *)0x06060D78;

  if (uVar6 == 0) {

    *(int *)0x06060D78 = 1;

    uVar7 = 0;

    do {

      uVar8 = uVar7 & 0xff;

      uVar7 = uVar7 + 1;

      uVar9 = 0;

      **(short **)(puVar4 + (uVar8 * 0xc & 0xff)) = 0;

      **(short **)((int)(puVar4 + (uVar8 * 0xc & 0xff)) + 4) = 0;

    } while ((uVar7 & 0xffff) < 0xe);

    do {

      if (**(short **)(puVar5 + (unsigned int)(uVar9 << 3)) != 0) break;

      uVar9 = uVar9 + 1;

    } while (uVar9 < 0xe);

    if (uVar9 < 0xe) {

      uVar6 = (*(int(*)())0x06025070)();

    }

    else {

      for (uVar7 = 0; (uVar7 & 0xffff) < 0xe; uVar7 = uVar7 + 1) {

        uVar9 = 0;

        do {

          sVar1 = *(short *)(puVar4 + ((uVar7 & 0xff) * 0xc & 0xff) + 8);

          if (*(short *)(puVar2 + (unsigned int)(uVar9 << 3) + 6) == sVar1) {

            sVar1 = *(short *)(puVar2 + (unsigned int)(uVar9 << 3) + 4);

            **(short **)(puVar5 + ((uVar7 & 0xffff) << 3)) = sVar1;

          }

          uVar6 = (unsigned int)sVar1;

          uVar9 = uVar9 + 1;

        } while (uVar9 < 10);

      }

    }

    uVar9 = 0;

    do {

      if (**(short **)(puVar5 + (unsigned int)(uVar9 << 3) + 4) != 0) break;

      uVar9 = uVar9 + 1;

    } while (uVar9 < 0xe);

    if (uVar9 < 0xe) {

      uVar6 = (*(int(*)())0x06025148)();

      return uVar6;

    }

    for (uVar7 = 0; (uVar7 & 0xffff) < 0xe; uVar7 = uVar7 + 1) {

      uVar9 = 0;

      do {

        sVar1 = *(short *)(puVar4 + ((uVar7 & 0xff) * 0xc & 0xff) + 8);

        if (*(short *)(puVar3 + (unsigned int)(uVar9 << 3) + 6) == sVar1) {

          sVar1 = *(short *)(puVar3 + (unsigned int)(uVar9 << 3) + 4);

          **(short **)(puVar5 + (((uVar7 & 0xffff) << 3) + 4)) = sVar1;

        }

        uVar6 = (unsigned int)sVar1;

        uVar9 = uVar9 + 1;

      } while (uVar9 < 8);

    }

  }

  return uVar6;

}

unsigned int FUN_060262c0(param_1)
    unsigned int param_1;
{

  unsigned short uVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  unsigned int uVar5;

  short uVar6;

  unsigned short uVar7;

  puVar4 = (char *)0x06089ED4;

  puVar3 = (char *)0x06089ED6;

  puVar2 = (int *)0x06060F2C;

  uVar5 = 0;

  *(short *)0x06089ED6 = 0;

  *(short *)puVar4 = 0;

  uVar7 = 0;

  do {

    if (9 < uVar7) {

      return uVar5;

    }

    if ((uVar7 == param_1) ||

       (uVar5 = (unsigned int)*(unsigned short *)(puVar2 + (unsigned int)(uVar7 << 3) + 6) - 0x8a, 0xb < uVar5))

    goto LAB_06026350;

    uVar1 = ((int *)0x06026338)[uVar5];

    switch(uVar5) {

    case 0:

    case 1:

      uVar6 = 1;

      break;

    case 2:

    case 3:

      uVar6 = 1;

      goto LAB_0602630a;

    default:

      uVar6 = 2;

      break;

    case 8:

    case 9:

    case 10:

    case 0xb:

      uVar6 = 2;

LAB_0602630a:

      *(short *)puVar4 = uVar6;

      uVar5 = (int)(short)uVar1;

      goto LAB_06026350;

    }

    *(short *)puVar3 = uVar6;

    uVar5 = (int)(short)uVar1;

LAB_06026350:

    uVar7 = uVar7 + 1;

  } while( 1 );

}

unsigned int FUN_06026362()
{

  unsigned short uVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  unsigned int uVar6;

  short uVar7;

  unsigned short uVar8;

  puVar5 = (int *)0x00008000;

  puVar4 = (char *)0x06060D34;

  puVar3 = (char *)0x06060D2A;

  puVar2 = (int *)0x06060F2C;

  uVar8 = 0;

  do {

    uVar6 = (unsigned int)*(unsigned short *)(puVar2 + (unsigned int)(uVar8 << 3) + 6) - 0x8a;

    if (0xb < uVar6) goto LAB_060263dc;

    uVar1 = ((int *)0x060263c4)[uVar6];

    uVar7 = SUB42(puVar5,0);

    switch(uVar6) {

    case 0:

    case 1:

      uVar7 = 0;

      break;

    case 2:

    case 3:

      uVar7 = 0;

      goto LAB_06026394;

    default:

      break;

    case 8:

    case 9:

    case 10:

    case 0xb:

LAB_06026394:

      *(short *)puVar4 = uVar7;

      uVar6 = (int)(short)uVar1;

      goto LAB_060263dc;

    }

    *(short *)puVar3 = uVar7;

    uVar6 = (int)(short)uVar1;

LAB_060263dc:

    uVar8 = uVar8 + 1;

    if (9 < uVar8) {

      return uVar6;

    }

  } while( 1 );

}

unsigned int FUN_060263ec(param_1)
    unsigned int param_1;
{

  unsigned short uVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  unsigned int uVar5;

  short uVar6;

  unsigned short uVar7;

  puVar4 = (char *)0x06089ED4;

  puVar3 = (char *)0x06089ED6;

  puVar2 = (int *)0x0606107C;

  uVar5 = 0;

  *(short *)0x06089ED6 = 0;

  *(short *)puVar4 = 0;

  uVar7 = 0;

  do {

    if (7 < uVar7) {

      return uVar5;

    }

    if ((uVar7 == param_1) ||

       (uVar5 = (unsigned int)*(unsigned short *)(puVar2 + (unsigned int)(uVar7 << 3) + 6) - 0x8a, 0xb < uVar5))

    goto LAB_0602647c;

    uVar1 = ((int *)0x06026464)[uVar5];

    switch(uVar5) {

    case 0:

    case 1:

      uVar6 = 1;

      break;

    case 2:

    case 3:

      uVar6 = 1;

      goto LAB_06026436;

    default:

      uVar6 = 2;

      break;

    case 8:

    case 9:

    case 10:

    case 0xb:

      uVar6 = 2;

LAB_06026436:

      *(short *)puVar4 = uVar6;

      uVar5 = (int)(short)uVar1;

      goto LAB_0602647c;

    }

    *(short *)puVar3 = uVar6;

    uVar5 = (int)(short)uVar1;

LAB_0602647c:

    uVar7 = uVar7 + 1;

  } while( 1 );

}

unsigned int FUN_0602648e()
{
  unsigned short uVar1;
  unsigned int uVar6;
  short uVar7;
  unsigned short uVar8;

  uVar8 = 0;

  do {
    uVar6 = (unsigned int)*(unsigned short *)(0x0606107C + (unsigned int)(uVar8 << 3) + 6) - 0x8a;

    if (0xb < uVar6) goto LAB_06026508;

    uVar1 = ((int *)0x060264f0)[uVar6];
    uVar7 = (short)0x8000;

    switch(uVar6) {
    case 0:
    case 1:
      uVar7 = 0;
      break;
    case 2:
    case 3:
      uVar7 = 0;
      goto LAB_060264c0;
    default:
      break;
    case 8:
    case 9:
    case 10:
    case 0xb:
LAB_060264c0:
      *(short *)0x06060D34 = uVar7;
      uVar6 = (int)(short)uVar1;
      goto LAB_06026508;
    }

    *(short *)0x06060D2A = uVar7;
    uVar6 = (int)(short)uVar1;

LAB_06026508:
    uVar8 = uVar8 + 1;

    if (7 < uVar8) {
      return uVar6;
    }
  } while( 1 );
}

void FUN_06026518(param_1)
    unsigned int param_1;
{
  register int func1 asm("r3") = 0x060284AE;
  register int func2 asm("r2") = 0x06028400;

  if ((param_1 & 4) != 0) {
    (*(int(*)())func1)(8, 0x2a0, 0x90, 0x06059128);
    (*(void(*)())func1)(8, (int)DAT_06026576, 0x90, 0x06059128);
    return;
  }

  (*(int(*)())func2)(8, *(int *)0x06063B80, 0x2a0,
             *(int *)0x06063B84 + (int)DAT_06026578, 0x06063B80);

  (*(void(*)())func2)(8, *(int *)0x06063B88, (int)DAT_06026576,
             *(int *)0x06063B8C + (int)DAT_06026578);
}

void FUN_06026590(param_1, param_2)
    char param_1;
    unsigned int param_2;
{

  short *puVar1;

  unsigned short *puVar2;

  unsigned int uVar3;

  int *puVar4;

  int *puVar5;

  int iVar6;

  int *puVar7;

  int *puVar8;

  int iVar9;

  int *piVar10;

  puVar4 = (int *)0x060610BC;

  iVar9 = 0xa8;

  if ((param_2 & 0xffff) == iVar9 + 1U) {

    puVar7 = (int *)(0x060610BC + iVar9);

    puVar8 = (int *)0x060610BC;

    do {

      puVar1 = (short *)*puVar8;

      *(short *)puVar8[1] = 0;

      *puVar1 = 0;

      puVar1 = (short *)puVar8[3];

      puVar5 = puVar8 + 4;

      puVar8 = puVar8 + 6;

      *(short *)*puVar5 = 0;

      *puVar1 = 0;

    } while (puVar8 < puVar7);

    if (param_1 == '\x04') {

      FUN_06026362();

    }

    iVar6 = 0;

    piVar10 = (int *)(0x06061170 + (param_1 << 2));

    for (uVar3 = 0; uVar3 < 0x50; uVar3 = uVar3 + 8) {

      if (*(int *)(*piVar10 + uVar3) != 0) {

        puVar8 = (int *)(*piVar10 + iVar6);

        puVar2 = (unsigned short *)*puVar8;

        *puVar2 = *puVar2 | *(unsigned short *)(puVar8 + 1);

      }

      iVar6 = iVar6 + 8;

    }

  }

  else {

    puVar7 = (int *)(0x060610BC + iVar9);

    puVar8 = (int *)0x060610BC;

    do {

      puVar1 = (short *)*puVar8;

      *(short *)puVar8[1] = 0;

      *puVar1 = 0;

      puVar1 = (short *)puVar8[3];

      puVar5 = puVar8 + 4;

      puVar8 = puVar8 + 6;

      *(short *)*puVar5 = 0;

      *puVar1 = 0;

    } while (puVar8 < puVar7);

    if (param_1 == '\x04') {

      FUN_0602648e();

    }

    iVar6 = 0;

    piVar10 = (int *)(0x06061184 + (param_1 << 2));

    for (uVar3 = 0; uVar3 < 0x40; uVar3 = uVar3 + 8) {

      if (*(int *)(*piVar10 + uVar3) != 0) {

        puVar8 = (int *)(*piVar10 + iVar6);

        puVar2 = (unsigned short *)*puVar8;

        *puVar2 = *puVar2 | *(unsigned short *)(puVar8 + 1);

      }

      iVar6 = iVar6 + 8;

    }

  }

  if (param_1 == '\x04') {

    puVar8 = (int *)((int)puVar4 + iVar9);

    do {

      puVar5 = puVar4 + 3;

      *(short *)*puVar4 = *(short *)puVar4[1];

      puVar7 = puVar4 + 4;

      puVar4 = puVar4 + 6;

      *(short *)*puVar5 = *(short *)*puVar7;

    } while (puVar4 < puVar8);

  }

  return;

}

int FUN_060266cc()
{

  unsigned short uVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  int uVar6;

  int iVar7;

  int iVar8;

  int iVar9;

  puVar4 = (char *)0x06089EDA;

  puVar3 = (char *)0x060284AE;

  puVar2 = (int *)0x06059128;

  iVar9 = 0x90;

  iVar7 = (int)DAT_0602672a;

  (*(int(*)())0x060284AE)(8,iVar7,iVar9,0x0605912C);

  iVar8 = (int)DAT_0602672c;

  (*(int(*)())puVar3)(8,iVar8,iVar9,0x06059134);

  puVar5 = (int *)0x06061198;

  uVar1 = *(unsigned short *)0x06063D9A;

  if (uVar1 != 0) {

    if ((uVar1 & DAT_0602672e) != 0) {

      *(unsigned short *)0x06089ED8 = (unsigned short)(*(short *)puVar4 == 0x12);

      *puVar5 = 6;

      (*(int(*)())puVar3)(8,((unsigned int)*(unsigned short *)((int)(int)puVar4 << 6) + 0x11) << 1,iVar9,puVar2);

      (*(int(*)())puVar3)(8,iVar7,iVar9,0x0605913C);

      uVar6 = (*(int(*)())puVar3)(8,iVar8,iVar9,0x06059144);

      return uVar6;

    }

    if ((unsigned int)uVar1 == 0x100) {

      *(short *)0x06089ED8 = 0;

      *puVar5 = 6;

      (*(int(*)())puVar3)(8,((unsigned int)*(unsigned short *)((int)(int)puVar4 << 6) + 0x11) << 1,iVar9,puVar2);

      (*(int(*)())puVar3)(8,iVar7,iVar9,0x0605913C);

      uVar6 = (*(int(*)())puVar3)(8,iVar8,iVar9,0x06059144);

      return uVar6;

    }

    if ((unsigned int)uVar1 == (int)DAT_0602684a) {

      (*(int(*)())puVar3)(8,((unsigned int)*(unsigned short *)((int)(int)puVar4 << 6) + 0x11) << 1,iVar9,puVar2);

      *(short *)puVar4 = *(short *)puVar4 + -2;

    }

    if ((unsigned int)uVar1 == (int)PTR_DAT_0602684c) {

      (*(int(*)())puVar3)(8,((unsigned int)*(unsigned short *)((int)(int)puVar4 << 6) + 0x11) << 1,iVar9,puVar2);

      *(short *)puVar4 = *(short *)puVar4 + 2;

    }

    if (0x14 < *(unsigned short *)puVar4) {

      *(short *)puVar4 = (char *)0x12;

    }

    if (*(unsigned short *)puVar4 < 0x12) {

      *(short *)puVar4 = (char *)0x14;

    }

  }

  if ((*(unsigned short *)0x06089EC6 & 4) != 0) {

    uVar6 = (*(int(*)())puVar3)(8,((unsigned int)*(unsigned short *)((int)(int)puVar4 << 6) + 0x11) << 1,iVar9,puVar2);

    return uVar6;

  }

  uVar6 = (*(int(*)())0x06028400)(8,*(int *)0x06063B88,((unsigned int)*(unsigned short *)((int)(int)puVar4 << 6) + 0x11) << 1,

                     *(int *)(0x06063B88 + 4) + (int)DAT_060268a6);

  return uVar6;

}

void FUN_060268b0(param_1)
    short param_1;
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  int iVar6;

  int iVar7;

  puVar5 = (int *)0x06061238;

  puVar4 = (char *)0x0606123A;

  puVar3 = (char *)0x0607864C;

  puVar2 = (int *)0x0606123C;

  puVar1 = (int *)0x060283E0;

  iVar7 = (int)DAT_06026922;

  if (param_1 == 0) {

    iVar6 = CAR_COUNT;

    if (iVar6 == 0) {

      if (*(short *)0x06061238 < 0x36) {

        if ((unsigned int)(*(short *)(0x060597B8 + *(short *)(0x06061238 << 1)) * 3) <=

            VBLANK_COUNTER) {

          *(short *)0x06061238 = *(short *)0x06061238 + 1;

          *(short *)puVar4 = 0;

          (*(int(*)())puVar1)(0xc,iVar7,0x0000F000,0x06059826);

          *(short *)puVar2 = 1;

        }

      }

      else if ((*(short *)0x06061238 == 0x36) &&

              ((unsigned int)(*(short *)(0x060597B8 + *(short *)(0x06061238 << 1)) * 3) <=

               VBLANK_COUNTER)) {

        (*(int(*)())0x060283E0)(0xc,iVar7,0x0000F000,0x06059826);

        *(short *)puVar5 = 0;

        *(short *)puVar4 = 0;

        *(short *)0x0606123E = 1;

      }

      if (*(short *)puVar2 != 0) {

        (*(int(*)())puVar1)(0xc,iVar7,0x0000F000,

                          *(int *)

                           (0x060611FC + (char)((int *)0x060591BA)[*(short *)puVar5 + -1] * 4));

      }

      *(short *)puVar2 = 0;

      if (0 < *(short *)puVar5) {

        while ((((unsigned int)(((int)*(short *)(0x060597B8 + (*(short *)puVar5 + -1) << 1) +

                        (int)((char *)0x060595D8)

                                   [(int)*(short *)puVar4 +

                                    (char)((int *)0x060591BA)[*(short *)puVar5 + -1] * 0x20]) * 3) <=

                 *(unsigned int *)puVar3 &&

                (((char *)0x060595D8)

                       [(int)*(short *)puVar4 + (char)((int *)0x060591BA)[*(short *)puVar5 + -1] * 0x20

                       ] != -1)) && (*(short *)puVar4 < 0x20))) {

          FUN_06026ca4(*(int *)

                        (0x060611FC + (char)((int *)0x060591BA)[*(short *)puVar5 + -1] * 4),

                       (int)*(short *)puVar4);

          *(short *)puVar4 = *(short *)puVar4 + 1;

        }

      }

    }

    else if (iVar6 == 1) {

      if (*(short *)0x06061238 < 0x3a) {

        if ((unsigned int)(*(short *)(0x060591F0 + *(short *)(0x06061238 << 1)) * 3) <=

            VBLANK_COUNTER) {

          *(short *)0x06061238 = *(short *)0x06061238 + 1;

          *(short *)puVar4 = 0;

          (*(int(*)())puVar1)(0xc,iVar7,0x0000F000,0x06059826);

          *(short *)puVar2 = 1;

        }

      }

      else if ((*(short *)0x06061238 == 0x3a) &&

              ((unsigned int)(*(short *)(0x060591F0 + *(short *)(0x06061238 << 1)) * 3) <=

               VBLANK_COUNTER)) {

        (*(int(*)())0x060283E0)(0xc,iVar7,0x0000F000,0x06059826);

        *(short *)puVar5 = 0;

        *(short *)puVar4 = 0;

        *(short *)0x0606123E = 1;

      }

      if (*(short *)puVar2 != 0) {

        (*(int(*)())puVar1)(0xc,iVar7,0x0000F000,

                          *(int *)

                           (0x0606119C + (char)((int *)0x0605914C)[*(short *)puVar5 + -1] * 4));

      }

      *(short *)puVar2 = 0;

      if (0 < *(short *)puVar5) {

        while ((((unsigned int)(((int)*(short *)(0x060591F0 + (*(short *)puVar5 + -1) << 1) +

                        (int)((char *)0x06059266)

                                   [(int)*(short *)puVar4 +

                                    (int)(short)((char)((int *)0x0605914C)[*(short *)puVar5 + -1] *

                                                0x24)]) * 3) <= *(unsigned int *)puVar3 &&

                (((char *)0x06059266)

                       [(int)*(short *)puVar4 +

                        (int)(short)((char)((int *)0x0605914C)[*(short *)puVar5 + -1] * 0x24)] != -1))

               && (*(short *)puVar4 < 0x24))) {

          FUN_06026ca4(*(int *)

                        (0x0606119C + (char)((int *)0x0605914C)[*(short *)puVar5 + -1] * 4),

                       (int)*(short *)puVar4);

          *(short *)puVar4 = *(short *)puVar4 + 1;

        }

      }

    }

    else if (iVar6 == 2) {

      if (*(short *)0x06061238 < 0x34) {

        if ((unsigned int)(*(short *)(0x0605956E + *(short *)(0x06061238 << 1)) * 3) <=

            VBLANK_COUNTER) {

          *(short *)0x06061238 = *(short *)0x06061238 + 1;

          *(short *)puVar4 = 0;

          (*(int(*)())puVar1)(0xc,iVar7,0x0000F000,0x06059826);

          *(short *)puVar2 = 1;

        }

      }

      else if ((*(short *)0x06061238 == 0x34) &&

              ((unsigned int)(*(short *)(0x0605956E + *(short *)(0x06061238 << 1)) * 3) <=

               VBLANK_COUNTER)) {

        (*(int(*)())0x060283E0)(0xc,iVar7,0x0000F000,0x06059826);

        *(short *)puVar5 = 0;

        *(short *)puVar4 = 0;

        *(short *)0x0606123E = 1;

      }

      if (*(short *)puVar2 != 0) {

        (*(int(*)())puVar1)(0xc,iVar7,0x0000F000,

                          *(int *)

                           (0x060611DC + (char)((int *)0x06059186)[*(short *)puVar5 + -1] * 4));

      }

      *(short *)puVar2 = 0;

      if (0 < *(short *)puVar5) {

        while ((((unsigned int)(((int)*(short *)(0x0605956E + (*(short *)puVar5 + -1) << 1) +

                        (int)((char *)0x060594A6)

                                   [(int)*(short *)puVar4 +

                                    (((int)(char)((int *)0x06059186)[*(short *)puVar5 + -1] & 0xffffU)

                                     * 0x19 & 0xff)]) * 3) <= *(unsigned int *)puVar3 &&

                (((char *)0x060594A6)

                       [(int)*(short *)puVar4 +

                        (((int)(char)((int *)0x06059186)[*(short *)puVar5 + -1] & 0xffffU) * 0x19 &

                        0xff)] != -1)) && (*(short *)puVar4 < 0x19))) {

          FUN_06026ca4(*(int *)

                        (0x060611DC + (char)((int *)0x06059186)[*(short *)puVar5 + -1] * 4),

                       (int)*(short *)puVar4);

          *(short *)puVar4 = *(short *)puVar4 + 1;

        }

      }

    }

    if (*(short *)0x0606123E != 0) {

      *(int *)puVar3 = 0;

      *(short *)0x0606123E = 0;

    }

  }

  else {

    *(short *)0x0606123C = 0;

    *(short *)puVar4 = 0;

    *(short *)puVar5 = 0;

    *(short *)0x0606123E = 0;

    *(int *)puVar3 = 0;

  }

  return;

}

void FUN_06026ca4(param_1, param_2)
    int param_1;
    short param_2;
{

  char local_c;

  char uStack_b;

  local_c = *(char *)(param_1 + param_2);

  uStack_b = 0;

  (*(int(*)())0x060283E0)(0xc,((int)param_2 + (int)PTR_DAT_06026cd4) << 1,0x0000E000,&local_c);

  return;

}

void FUN_06026dbc()
{

  int *puVar1;

  puVar1 = *(int **)0x06089EDC;

  *(int **)0x06089EDC = puVar1 + 0xc;

  puVar1[0xc] = *puVar1;

  puVar1[0xd] = puVar1[1];

  puVar1[0xe] = puVar1[2];

  puVar1[0xf] = puVar1[3];

  puVar1[0x10] = puVar1[4];

  puVar1[0x11] = puVar1[5];

  puVar1[0x12] = puVar1[6];

  puVar1[0x13] = puVar1[7];

  puVar1[0x14] = puVar1[8];

  puVar1[0x15] = puVar1[9];

  puVar1[0x16] = puVar1[10];

  puVar1[0x17] = puVar1[0xb];

  return;

}

void FUN_06026e02()
{

  int *puVar1;

  char *puVar2;

  puVar1 = (int *)0x06089EE0;

  *(int **)0x06089EDC = 0x06089EE0;

  puVar2 = (int *)0x00010000;

  puVar1[1] = 0;

  *puVar1 = puVar2;

  puVar1[2] = 0;

  puVar1[3] = 0;

  puVar1[4] = puVar2;

  puVar1[5] = 0;

  puVar1[6] = 0;

  puVar1[7] = 0;

  puVar1[8] = puVar2;

  puVar1[9] = 0;

  puVar1[10] = 0;

  puVar1[0xb] = 0;

  return;

}

void FUN_06026e0c()
{

  char *puVar1;

  int *puVar2;

  

  puVar1 = (int *)0x00010000;

  puVar2 = *(int **)0x06089EDC;

  puVar2[1] = 0;

  *puVar2 = puVar1;

  puVar2[2] = 0;

  puVar2[3] = 0;

  puVar2[4] = puVar1;

  puVar2[5] = 0;

  puVar2[6] = 0;

  puVar2[7] = 0;

  puVar2[8] = puVar1;

  puVar2[9] = 0;

  puVar2[10] = 0;

  puVar2[0xb] = 0;

  return;

}

char * FUN_06026e2e(param_1, param_2, param_3)
    int param_1;
    int param_2;
    int param_3;
{

  unsigned int uVar1;

  int iVar2;

  unsigned int uVar3;

  int iVar4;

  unsigned int uVar5;

  unsigned int uVar6;

  char *puVar7;

  char *puVar8;

  int iVar9;

  unsigned int *puVar10;

  unsigned int *puVar11;

  unsigned int in_sr = 0;

  unsigned int uVar12;

  unsigned int uVar13;

  unsigned int uVar14;

  unsigned int uVar15;

  puVar8 = (char *)0x0608A4E0;

  puVar7 = (int *)0x06089EDC;

  *(int *)0x0608A4E0 = param_1;

  *(int *)(puVar8 + 4) = param_2;

  *(int *)(puVar8 + 8) = param_3;

  puVar10 = *(unsigned int **)puVar7;

  iVar9 = 3;

  puVar11 = puVar10 + 9;

  do {

    uVar5 = *(unsigned int *)puVar8;

    uVar12 = *puVar10;

    uVar6 = uVar5 ^ uVar12;

    if ((int)uVar5 < 0) {

      uVar5 = -uVar5;

    }

    if ((int)uVar12 < 0) {

      uVar12 = -uVar12;

    }

    uVar3 = (uVar12 & 0xffff) * (uVar5 & 0xffff);

    iVar4 = (uVar12 >> 0x10) * (uVar5 & 0xffff);

    iVar2 = 0;

    uVar1 = iVar4 + (uVar12 & 0xffff) * (uVar5 >> 0x10);

    if (iVar4 != 0) {

      iVar2 = 0x10000;

    }

    uVar13 = uVar3 + (uVar1 << 16);

    uVar12 = iVar2 + (unsigned int)(uVar13 < uVar3) + (uVar1 >> 0x10) + (uVar12 >> 0x10) * (uVar5 >> 0x10);

    if ((int)-(unsigned int)((int)uVar6 < 0) < 0) {

      uVar12 = ~uVar12;

      if (uVar13 == 0) {

        uVar12 = uVar12 + 1;

      }

      else {

        uVar13 = ~uVar13 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      if ((int)uVar12 < -0x8000) {

        uVar12 = 0xffff8000;

        uVar13 = 0;

      }

      if (0x7fff < (int)uVar12) {

        uVar12 = 0x7fff;

        uVar13 = 0xffffffff;

      }

      uVar12 = uVar12 & 0xffff;

    }

    uVar6 = *(unsigned int *)(puVar8 + 4);

    uVar5 = puVar10[1];

    uVar1 = uVar6 ^ uVar5;

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    if ((int)uVar5 < 0) {

      uVar5 = -uVar5;

    }

    uVar15 = (uVar5 & 0xffff) * (uVar6 & 0xffff);

    iVar4 = (uVar5 >> 0x10) * (uVar6 & 0xffff);

    iVar2 = 0;

    uVar3 = iVar4 + (uVar5 & 0xffff) * (uVar6 >> 0x10);

    if (iVar4 != 0) {

      iVar2 = 0x10000;

    }

    uVar14 = uVar15 + (uVar3 << 16);

    uVar5 = iVar2 + (unsigned int)(uVar14 < uVar15) + (uVar3 >> 0x10) + (uVar5 >> 0x10) * (uVar6 >> 0x10);

    if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

      uVar5 = ~uVar5;

      if (uVar14 == 0) {

        uVar5 = uVar5 + 1;

      }

      else {

        uVar14 = ~uVar14 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      uVar14 = uVar13 + uVar14;

      uVar12 = uVar5 + (uVar14 < uVar13) + (uVar12 & 0xffff);

      if ((int)uVar12 < -0x8000) {

        uVar12 = 0xffff8000;

        uVar14 = 0;

      }

      if (0x7fff < (int)uVar12) {

        uVar12 = 0x7fff;

        uVar14 = 0xffffffff;

      }

      uVar12 = uVar12 & 0xffff;

    }

    else {

      uVar14 = uVar13 + uVar14;

      uVar12 = uVar5 + (uVar14 < uVar13) + uVar12;

    }

    uVar6 = *(unsigned int *)(puVar8 + 8);

    uVar5 = puVar10[2];

    puVar10 = puVar10 + 3;

    uVar1 = uVar6 ^ uVar5;

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    if ((int)uVar5 < 0) {

      uVar5 = -uVar5;

    }

    uVar13 = (uVar5 & 0xffff) * (uVar6 & 0xffff);

    iVar4 = (uVar5 >> 0x10) * (uVar6 & 0xffff);

    iVar2 = 0;

    uVar3 = iVar4 + (uVar5 & 0xffff) * (uVar6 >> 0x10);

    if (iVar4 != 0) {

      iVar2 = 0x10000;

    }

    uVar15 = uVar13 + (uVar3 << 16);

    uVar5 = iVar2 + (unsigned int)(uVar15 < uVar13) + (uVar3 >> 0x10) + (uVar5 >> 0x10) * (uVar6 >> 0x10);

    if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

      uVar5 = ~uVar5;

      if (uVar15 == 0) {

        uVar5 = uVar5 + 1;

      }

      else {

        uVar15 = ~uVar15 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      uVar15 = uVar14 + uVar15;

      uVar12 = uVar5 + (uVar15 < uVar14) + (uVar12 & 0xffff);

      if ((int)uVar12 < -0x8000) {

        uVar12 = 0xffff8000;

        uVar15 = 0;

      }

      if (0x7fff < (int)uVar12) {

        uVar12 = 0x7fff;

        uVar15 = 0xffffffff;

      }

      uVar12 = uVar12 & 0xffff;

    }

    else {

      uVar15 = uVar14 + uVar15;

      uVar12 = uVar5 + (uVar15 < uVar14) + uVar12;

    }

    iVar9 = iVar9 + -1;

    in_sr = in_sr & 0xfffffffe;

    *puVar11 = (uVar12 << 0x10 | uVar15 >> 0x10) + *puVar11;

    puVar11 = puVar11 + 1;

  } while (iVar9 != 0);

  return puVar8;

}

unsigned int FUN_06026e60(param_1, param_2, param_3)
    int param_1;
    int param_2;
    int param_3;
{

  long long lVar1;

  unsigned int uVar2;

  int iVar3;

  unsigned int *puVar4;

  puVar4 = *(unsigned int **)0x06089EDC;

  iVar3 = 3;

  do {

    *puVar4 = (int)((unsigned long long)((long long)param_1 * (long long)(int)*puVar4) >> 0x20) << 0x10 |

              (unsigned int)((long long)param_1 * (long long)(int)*puVar4) >> 0x10;

    uVar2 = puVar4[6];

    lVar1 = (long long)param_3 * (long long)(int)uVar2;

    puVar4[3] = (int)((unsigned long long)((long long)param_2 * (long long)(int)puVar4[3]) >> 0x20) << 0x10 |

                (unsigned int)((long long)param_2 * (long long)(int)puVar4[3]) >> 0x10;

    iVar3 = iVar3 + -1;

    puVar4[6] = (int)((unsigned long long)lVar1 >> 0x20) << 0x10 | (unsigned int)lVar1 >> 0x10;

    puVar4 = puVar4 + 1;

  } while (iVar3 != 0);

  return uVar2;

}

unsigned int FUN_06026e94()
{

  unsigned int uVar1;

  int iVar2;

  unsigned int uVar3;

  unsigned int uVar4;

  int iVar5;

  unsigned int uVar6;

  char *puVar7;

  int iVar8;

  unsigned int *puVar9;

  int *piVar10;

  unsigned int *puVar11;

  unsigned int in_sr = 0;

  unsigned int uVar12;

  unsigned int uVar13;

  unsigned int uVar14;

  unsigned int uVar15;

  unsigned int uVar16;

  unsigned int uVar17;

  piVar10 = (int *)(0x0608A4E0 + 8);

  puVar11 = (unsigned int *)0x0608A4E0;

  FUN_06027358();

  puVar11[1] = -*piVar10;

  puVar7 = (int *)0x06089EDC;

  puVar11[3] = *puVar11;

  iVar8 = 3;

  puVar9 = (unsigned int *)(*(int *)puVar7 + 4);

  do {

    uVar13 = *puVar9;

    uVar12 = *puVar11;

    uVar6 = uVar13 ^ uVar12;

    if ((int)uVar13 < 0) {

      uVar13 = -uVar13;

    }

    if ((int)uVar12 < 0) {

      uVar12 = -uVar12;

    }

    uVar3 = (uVar12 & 0xffff) * (uVar13 & 0xffff);

    iVar5 = (uVar12 >> 0x10) * (uVar13 & 0xffff);

    iVar2 = 0;

    uVar1 = iVar5 + (uVar12 & 0xffff) * (uVar13 >> 0x10);

    if (iVar5 != 0) {

      iVar2 = 0x10000;

    }

    uVar14 = uVar3 + (uVar1 << 16);

    uVar12 = iVar2 + (unsigned int)(uVar14 < uVar3) + (uVar1 >> 0x10) + (uVar12 >> 0x10) * (uVar13 >> 0x10);

    if ((int)-(unsigned int)((int)uVar6 < 0) < 0) {

      uVar12 = ~uVar12;

      if (uVar14 == 0) {

        uVar12 = uVar12 + 1;

      }

      else {

        uVar14 = ~uVar14 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      if ((int)uVar12 < -0x8000) {

        uVar12 = 0xffff8000;

        uVar14 = 0;

      }

      if (0x7fff < (int)uVar12) {

        uVar12 = 0x7fff;

        uVar14 = 0xffffffff;

      }

      uVar12 = uVar12 & 0xffff;

    }

    uVar6 = puVar9[1];

    uVar13 = puVar11[1];

    uVar1 = uVar6 ^ uVar13;

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    if ((int)uVar13 < 0) {

      uVar13 = -uVar13;

    }

    uVar16 = (uVar13 & 0xffff) * (uVar6 & 0xffff);

    iVar5 = (uVar13 >> 0x10) * (uVar6 & 0xffff);

    iVar2 = 0;

    uVar3 = iVar5 + (uVar13 & 0xffff) * (uVar6 >> 0x10);

    if (iVar5 != 0) {

      iVar2 = 0x10000;

    }

    uVar15 = uVar16 + (uVar3 << 16);

    uVar13 = iVar2 + (unsigned int)(uVar15 < uVar16) + (uVar3 >> 0x10) + (uVar13 >> 0x10) * (uVar6 >> 0x10);

    if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

      uVar13 = ~uVar13;

      if (uVar15 == 0) {

        uVar13 = uVar13 + 1;

      }

      else {

        uVar15 = ~uVar15 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      uVar15 = uVar14 + uVar15;

      uVar12 = uVar13 + (uVar15 < uVar14) + (uVar12 & 0xffff);

      if ((int)uVar12 < -0x8000) {

        uVar12 = 0xffff8000;

        uVar15 = 0;

      }

      if (0x7fff < (int)uVar12) {

        uVar12 = 0x7fff;

        uVar15 = 0xffffffff;

      }

      uVar12 = uVar12 & 0xffff;

    }

    else {

      uVar15 = uVar14 + uVar15;

      uVar12 = uVar13 + (uVar15 < uVar14) + uVar12;

    }

    uVar6 = *puVar9;

    uVar13 = puVar11[2];

    uVar1 = uVar6 ^ uVar13;

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    if ((int)uVar13 < 0) {

      uVar13 = -uVar13;

    }

    uVar14 = (uVar13 & 0xffff) * (uVar6 & 0xffff);

    iVar5 = (uVar13 >> 0x10) * (uVar6 & 0xffff);

    iVar2 = 0;

    uVar3 = iVar5 + (uVar13 & 0xffff) * (uVar6 >> 0x10);

    if (iVar5 != 0) {

      iVar2 = 0x10000;

    }

    uVar16 = uVar14 + (uVar3 << 16);

    uVar13 = iVar2 + (unsigned int)(uVar16 < uVar14) + (uVar3 >> 0x10) + (uVar13 >> 0x10) * (uVar6 >> 0x10);

    if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

      uVar13 = ~uVar13;

      if (uVar16 == 0) {

        uVar13 = uVar13 + 1;

      }

      else {

        uVar16 = ~uVar16 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      if ((int)uVar13 < -0x8000) {

        uVar13 = 0xffff8000;

        uVar16 = 0;

      }

      if (0x7fff < (int)uVar13) {

        uVar13 = 0x7fff;

        uVar16 = 0xffffffff;

      }

      uVar13 = uVar13 & 0xffff;

    }

    uVar1 = puVar9[1];

    uVar6 = puVar11[3];

    uVar3 = uVar1 ^ uVar6;

    if ((int)uVar1 < 0) {

      uVar1 = -uVar1;

    }

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    uVar4 = (uVar6 & 0xffff) * (uVar1 & 0xffff);

    iVar5 = (uVar6 >> 0x10) * (uVar1 & 0xffff);

    iVar2 = 0;

    uVar14 = iVar5 + (uVar6 & 0xffff) * (uVar1 >> 0x10);

    if (iVar5 != 0) {

      iVar2 = 0x10000;

    }

    uVar17 = uVar4 + (uVar14 << 16);

    uVar6 = iVar2 + (unsigned int)(uVar17 < uVar4) + (uVar14 >> 0x10) + (uVar6 >> 0x10) * (uVar1 >> 0x10);

    if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

      uVar6 = ~uVar6;

      if (uVar17 == 0) {

        uVar6 = uVar6 + 1;

      }

      else {

        uVar17 = ~uVar17 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      uVar17 = uVar16 + uVar17;

      uVar6 = uVar6 + (uVar17 < uVar16) + (uVar13 & 0xffff);

      if ((int)uVar6 < -0x8000) {

        uVar6 = 0xffff8000;

        uVar17 = 0;

      }

      if (0x7fff < (int)uVar6) {

        uVar6 = 0x7fff;

        uVar17 = 0xffffffff;

      }

      uVar13 = uVar6 & 0xffff | uVar13 & 0xffff0000;

    }

    else {

      uVar17 = uVar16 + uVar17;

      uVar13 = uVar6 + (uVar17 < uVar16) + uVar13;

    }

    *puVar9 = uVar12 << 0x10 | uVar15 >> 0x10;

    iVar8 = iVar8 + -1;

    in_sr = in_sr & 0xfffffffe;

    puVar9[1] = uVar13 << 0x10 | uVar17 >> 0x10;

    puVar9 = puVar9 + 3;

  } while (iVar8 != 0);

  return uVar13;

}

unsigned int FUN_06026ede()
{

  unsigned int uVar1;

  int iVar2;

  unsigned int uVar3;

  unsigned int uVar4;

  int iVar5;

  unsigned int uVar6;

  char *puVar7;

  int iVar8;

  unsigned int *puVar9;

  int *piVar10;

  unsigned int *puVar11;

  unsigned int in_sr = 0;

  unsigned int uVar12;

  unsigned int uVar13;

  unsigned int uVar14;

  unsigned int uVar15;

  unsigned int uVar16;

  unsigned int uVar17;

  piVar10 = (int *)(0x0608A4E0 + 4);

  puVar11 = (unsigned int *)0x0608A4E0;

  FUN_06027358();

  puVar11[2] = -*piVar10;

  puVar7 = (int *)0x06089EDC;

  puVar11[3] = *puVar11;

  puVar9 = *(unsigned int **)puVar7;

  iVar8 = 3;

  do {

    uVar13 = *puVar9;

    uVar12 = *puVar11;

    uVar6 = uVar13 ^ uVar12;

    if ((int)uVar13 < 0) {

      uVar13 = -uVar13;

    }

    if ((int)uVar12 < 0) {

      uVar12 = -uVar12;

    }

    uVar3 = (uVar12 & 0xffff) * (uVar13 & 0xffff);

    iVar5 = (uVar12 >> 0x10) * (uVar13 & 0xffff);

    iVar2 = 0;

    uVar1 = iVar5 + (uVar12 & 0xffff) * (uVar13 >> 0x10);

    if (iVar5 != 0) {

      iVar2 = 0x10000;

    }

    uVar14 = uVar3 + (uVar1 << 16);

    uVar12 = iVar2 + (unsigned int)(uVar14 < uVar3) + (uVar1 >> 0x10) + (uVar12 >> 0x10) * (uVar13 >> 0x10);

    if ((int)-(unsigned int)((int)uVar6 < 0) < 0) {

      uVar12 = ~uVar12;

      if (uVar14 == 0) {

        uVar12 = uVar12 + 1;

      }

      else {

        uVar14 = ~uVar14 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      if ((int)uVar12 < -0x8000) {

        uVar12 = 0xffff8000;

        uVar14 = 0;

      }

      if (0x7fff < (int)uVar12) {

        uVar12 = 0x7fff;

        uVar14 = 0xffffffff;

      }

      uVar12 = uVar12 & 0xffff;

    }

    uVar6 = puVar9[2];

    uVar13 = puVar11[1];

    uVar1 = uVar6 ^ uVar13;

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    if ((int)uVar13 < 0) {

      uVar13 = -uVar13;

    }

    uVar16 = (uVar13 & 0xffff) * (uVar6 & 0xffff);

    iVar5 = (uVar13 >> 0x10) * (uVar6 & 0xffff);

    iVar2 = 0;

    uVar3 = iVar5 + (uVar13 & 0xffff) * (uVar6 >> 0x10);

    if (iVar5 != 0) {

      iVar2 = 0x10000;

    }

    uVar15 = uVar16 + (uVar3 << 16);

    uVar13 = iVar2 + (unsigned int)(uVar15 < uVar16) + (uVar3 >> 0x10) + (uVar13 >> 0x10) * (uVar6 >> 0x10);

    if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

      uVar13 = ~uVar13;

      if (uVar15 == 0) {

        uVar13 = uVar13 + 1;

      }

      else {

        uVar15 = ~uVar15 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      uVar15 = uVar14 + uVar15;

      uVar12 = uVar13 + (uVar15 < uVar14) + (uVar12 & 0xffff);

      if ((int)uVar12 < -0x8000) {

        uVar12 = 0xffff8000;

        uVar15 = 0;

      }

      if (0x7fff < (int)uVar12) {

        uVar12 = 0x7fff;

        uVar15 = 0xffffffff;

      }

      uVar12 = uVar12 & 0xffff;

    }

    else {

      uVar15 = uVar14 + uVar15;

      uVar12 = uVar13 + (uVar15 < uVar14) + uVar12;

    }

    uVar6 = *puVar9;

    uVar13 = puVar11[2];

    uVar1 = uVar6 ^ uVar13;

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    if ((int)uVar13 < 0) {

      uVar13 = -uVar13;

    }

    uVar14 = (uVar13 & 0xffff) * (uVar6 & 0xffff);

    iVar5 = (uVar13 >> 0x10) * (uVar6 & 0xffff);

    iVar2 = 0;

    uVar3 = iVar5 + (uVar13 & 0xffff) * (uVar6 >> 0x10);

    if (iVar5 != 0) {

      iVar2 = 0x10000;

    }

    uVar16 = uVar14 + (uVar3 << 16);

    uVar13 = iVar2 + (unsigned int)(uVar16 < uVar14) + (uVar3 >> 0x10) + (uVar13 >> 0x10) * (uVar6 >> 0x10);

    if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

      uVar13 = ~uVar13;

      if (uVar16 == 0) {

        uVar13 = uVar13 + 1;

      }

      else {

        uVar16 = ~uVar16 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      if ((int)uVar13 < -0x8000) {

        uVar13 = 0xffff8000;

        uVar16 = 0;

      }

      if (0x7fff < (int)uVar13) {

        uVar13 = 0x7fff;

        uVar16 = 0xffffffff;

      }

      uVar13 = uVar13 & 0xffff;

    }

    uVar1 = puVar9[2];

    uVar6 = puVar11[3];

    uVar3 = uVar1 ^ uVar6;

    if ((int)uVar1 < 0) {

      uVar1 = -uVar1;

    }

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    uVar4 = (uVar6 & 0xffff) * (uVar1 & 0xffff);

    iVar5 = (uVar6 >> 0x10) * (uVar1 & 0xffff);

    iVar2 = 0;

    uVar14 = iVar5 + (uVar6 & 0xffff) * (uVar1 >> 0x10);

    if (iVar5 != 0) {

      iVar2 = 0x10000;

    }

    uVar17 = uVar4 + (uVar14 << 16);

    uVar6 = iVar2 + (unsigned int)(uVar17 < uVar4) + (uVar14 >> 0x10) + (uVar6 >> 0x10) * (uVar1 >> 0x10);

    if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

      uVar6 = ~uVar6;

      if (uVar17 == 0) {

        uVar6 = uVar6 + 1;

      }

      else {

        uVar17 = ~uVar17 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      uVar17 = uVar16 + uVar17;

      uVar6 = uVar6 + (uVar17 < uVar16) + (uVar13 & 0xffff);

      if ((int)uVar6 < -0x8000) {

        uVar6 = 0xffff8000;

        uVar17 = 0;

      }

      if (0x7fff < (int)uVar6) {

        uVar6 = 0x7fff;

        uVar17 = 0xffffffff;

      }

      uVar13 = uVar6 & 0xffff | uVar13 & 0xffff0000;

    }

    else {

      uVar17 = uVar16 + uVar17;

      uVar13 = uVar6 + (uVar17 < uVar16) + uVar13;

    }

    *puVar9 = uVar12 << 0x10 | uVar15 >> 0x10;

    iVar8 = iVar8 + -1;

    in_sr = in_sr & 0xfffffffe;

    puVar9[2] = uVar13 << 0x10 | uVar17 >> 0x10;

    puVar9 = puVar9 + 3;

  } while (iVar8 != 0);

  return uVar13;

}

unsigned int FUN_06026f2a()
{

  unsigned int uVar1;

  int iVar2;

  unsigned int uVar3;

  unsigned int uVar4;

  int iVar5;

  unsigned int uVar6;

  char *puVar7;

  int iVar8;

  unsigned int *puVar9;

  int *piVar10;

  unsigned int *puVar11;

  unsigned int in_sr = 0;

  unsigned int uVar12;

  unsigned int uVar13;

  unsigned int uVar14;

  unsigned int uVar15;

  unsigned int uVar16;

  unsigned int uVar17;

  piVar10 = (int *)(0x0608A4E0 + 8);

  puVar11 = (unsigned int *)0x0608A4E0;

  FUN_06027358();

  puVar11[1] = -*piVar10;

  puVar7 = (int *)0x06089EDC;

  puVar11[3] = *puVar11;

  puVar9 = *(unsigned int **)puVar7;

  iVar8 = 3;

  do {

    uVar13 = *puVar9;

    uVar12 = *puVar11;

    uVar6 = uVar13 ^ uVar12;

    if ((int)uVar13 < 0) {

      uVar13 = -uVar13;

    }

    if ((int)uVar12 < 0) {

      uVar12 = -uVar12;

    }

    uVar3 = (uVar12 & 0xffff) * (uVar13 & 0xffff);

    iVar5 = (uVar12 >> 0x10) * (uVar13 & 0xffff);

    iVar2 = 0;

    uVar1 = iVar5 + (uVar12 & 0xffff) * (uVar13 >> 0x10);

    if (iVar5 != 0) {

      iVar2 = 0x10000;

    }

    uVar14 = uVar3 + (uVar1 << 16);

    uVar12 = iVar2 + (unsigned int)(uVar14 < uVar3) + (uVar1 >> 0x10) + (uVar12 >> 0x10) * (uVar13 >> 0x10);

    if ((int)-(unsigned int)((int)uVar6 < 0) < 0) {

      uVar12 = ~uVar12;

      if (uVar14 == 0) {

        uVar12 = uVar12 + 1;

      }

      else {

        uVar14 = ~uVar14 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      if ((int)uVar12 < -0x8000) {

        uVar12 = 0xffff8000;

        uVar14 = 0;

      }

      if (0x7fff < (int)uVar12) {

        uVar12 = 0x7fff;

        uVar14 = 0xffffffff;

      }

      uVar12 = uVar12 & 0xffff;

    }

    uVar6 = puVar9[1];

    uVar13 = puVar11[1];

    uVar1 = uVar6 ^ uVar13;

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    if ((int)uVar13 < 0) {

      uVar13 = -uVar13;

    }

    uVar16 = (uVar13 & 0xffff) * (uVar6 & 0xffff);

    iVar5 = (uVar13 >> 0x10) * (uVar6 & 0xffff);

    iVar2 = 0;

    uVar3 = iVar5 + (uVar13 & 0xffff) * (uVar6 >> 0x10);

    if (iVar5 != 0) {

      iVar2 = 0x10000;

    }

    uVar15 = uVar16 + (uVar3 << 16);

    uVar13 = iVar2 + (unsigned int)(uVar15 < uVar16) + (uVar3 >> 0x10) + (uVar13 >> 0x10) * (uVar6 >> 0x10);

    if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

      uVar13 = ~uVar13;

      if (uVar15 == 0) {

        uVar13 = uVar13 + 1;

      }

      else {

        uVar15 = ~uVar15 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      uVar15 = uVar14 + uVar15;

      uVar12 = uVar13 + (uVar15 < uVar14) + (uVar12 & 0xffff);

      if ((int)uVar12 < -0x8000) {

        uVar12 = 0xffff8000;

        uVar15 = 0;

      }

      if (0x7fff < (int)uVar12) {

        uVar12 = 0x7fff;

        uVar15 = 0xffffffff;

      }

      uVar12 = uVar12 & 0xffff;

    }

    else {

      uVar15 = uVar14 + uVar15;

      uVar12 = uVar13 + (uVar15 < uVar14) + uVar12;

    }

    uVar6 = *puVar9;

    uVar13 = puVar11[2];

    uVar1 = uVar6 ^ uVar13;

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    if ((int)uVar13 < 0) {

      uVar13 = -uVar13;

    }

    uVar14 = (uVar13 & 0xffff) * (uVar6 & 0xffff);

    iVar5 = (uVar13 >> 0x10) * (uVar6 & 0xffff);

    iVar2 = 0;

    uVar3 = iVar5 + (uVar13 & 0xffff) * (uVar6 >> 0x10);

    if (iVar5 != 0) {

      iVar2 = 0x10000;

    }

    uVar16 = uVar14 + (uVar3 << 16);

    uVar13 = iVar2 + (unsigned int)(uVar16 < uVar14) + (uVar3 >> 0x10) + (uVar13 >> 0x10) * (uVar6 >> 0x10);

    if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

      uVar13 = ~uVar13;

      if (uVar16 == 0) {

        uVar13 = uVar13 + 1;

      }

      else {

        uVar16 = ~uVar16 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      if ((int)uVar13 < -0x8000) {

        uVar13 = 0xffff8000;

        uVar16 = 0;

      }

      if (0x7fff < (int)uVar13) {

        uVar13 = 0x7fff;

        uVar16 = 0xffffffff;

      }

      uVar13 = uVar13 & 0xffff;

    }

    uVar1 = puVar9[1];

    uVar6 = puVar11[3];

    uVar3 = uVar1 ^ uVar6;

    if ((int)uVar1 < 0) {

      uVar1 = -uVar1;

    }

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    uVar4 = (uVar6 & 0xffff) * (uVar1 & 0xffff);

    iVar5 = (uVar6 >> 0x10) * (uVar1 & 0xffff);

    iVar2 = 0;

    uVar14 = iVar5 + (uVar6 & 0xffff) * (uVar1 >> 0x10);

    if (iVar5 != 0) {

      iVar2 = 0x10000;

    }

    uVar17 = uVar4 + (uVar14 << 16);

    uVar6 = iVar2 + (unsigned int)(uVar17 < uVar4) + (uVar14 >> 0x10) + (uVar6 >> 0x10) * (uVar1 >> 0x10);

    if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

      uVar6 = ~uVar6;

      if (uVar17 == 0) {

        uVar6 = uVar6 + 1;

      }

      else {

        uVar17 = ~uVar17 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      uVar17 = uVar16 + uVar17;

      uVar6 = uVar6 + (uVar17 < uVar16) + (uVar13 & 0xffff);

      if ((int)uVar6 < -0x8000) {

        uVar6 = 0xffff8000;

        uVar17 = 0;

      }

      if (0x7fff < (int)uVar6) {

        uVar6 = 0x7fff;

        uVar17 = 0xffffffff;

      }

      uVar13 = uVar6 & 0xffff | uVar13 & 0xffff0000;

    }

    else {

      uVar17 = uVar16 + uVar17;

      uVar13 = uVar6 + (uVar17 < uVar16) + uVar13;

    }

    *puVar9 = uVar12 << 0x10 | uVar15 >> 0x10;

    iVar8 = iVar8 + -1;

    in_sr = in_sr & 0xfffffffe;

    puVar9[1] = uVar13 << 0x10 | uVar17 >> 0x10;

    puVar9 = puVar9 + 3;

  } while (iVar8 != 0);

  return uVar13;

}

void FUN_06026f72(param_1)
    unsigned int *param_1;
{

  int iVar1;

  unsigned int uVar2;

  int iVar3;

  unsigned int *puVar4;

  unsigned int uVar5;

  int iVar6;

  unsigned int uVar7;

  int iVar8;

  unsigned int uVar9;

  unsigned int *puVar10;

  unsigned int uVar11;

  unsigned int *puVar12;

  unsigned int *puVar13;

  unsigned int uVar14;

  unsigned int *puVar15;

  unsigned int *puVar16;

  unsigned int in_sr = 0;

  unsigned int uVar17;

  unsigned int uVar18;

  unsigned int uVar19;

  iVar8 = 3;

  puVar4 = *(unsigned int **)0x06089EDC;

  puVar15 = (unsigned int *)0x0608A4F0;

  do {

    puVar12 = puVar4;

    iVar6 = 3;

    do {

      uVar11 = in_sr;

      puVar10 = param_1;

      uVar7 = *puVar12;

      uVar5 = *puVar10;

      uVar9 = uVar7 ^ uVar5;

      if ((int)uVar7 < 0) {

        uVar7 = -uVar7;

      }

      if ((int)uVar5 < 0) {

        uVar5 = -uVar5;

      }

      uVar2 = (uVar5 & 0xffff) * (uVar7 & 0xffff);

      iVar3 = (uVar5 >> 0x10) * (uVar7 & 0xffff);

      iVar1 = 0;

      uVar14 = iVar3 + (uVar5 & 0xffff) * (uVar7 >> 0x10);

      if (iVar3 != 0) {

        iVar1 = 0x10000;

      }

      uVar17 = uVar2 + (uVar14 << 16);

      uVar5 = iVar1 + (unsigned int)(uVar17 < uVar2) + (uVar14 >> 0x10) + (uVar5 >> 0x10) * (uVar7 >> 0x10);

      if ((int)-(unsigned int)((int)uVar9 < 0) < 0) {

        uVar5 = ~uVar5;

        if (uVar17 == 0) {

          uVar5 = uVar5 + 1;

        }

        else {

          uVar17 = ~uVar17 + 1;

        }

      }

      if (((unsigned char)(uVar11 >> 1) & 1) == 1) {

        if ((int)uVar5 < -0x8000) {

          uVar5 = 0xffff8000;

          uVar17 = 0;

        }

        if (0x7fff < (int)uVar5) {

          uVar5 = 0x7fff;

          uVar17 = 0xffffffff;

        }

        uVar5 = uVar5 & 0xffff;

      }

      uVar9 = puVar12[1];

      uVar7 = puVar10[3];

      uVar14 = uVar9 ^ uVar7;

      if ((int)uVar9 < 0) {

        uVar9 = -uVar9;

      }

      if ((int)uVar7 < 0) {

        uVar7 = -uVar7;

      }

      uVar19 = (uVar7 & 0xffff) * (uVar9 & 0xffff);

      iVar3 = (uVar7 >> 0x10) * (uVar9 & 0xffff);

      iVar1 = 0;

      uVar2 = iVar3 + (uVar7 & 0xffff) * (uVar9 >> 0x10);

      if (iVar3 != 0) {

        iVar1 = 0x10000;

      }

      uVar18 = uVar19 + (uVar2 << 16);

      uVar7 = iVar1 + (unsigned int)(uVar18 < uVar19) + (uVar2 >> 0x10) + (uVar7 >> 0x10) * (uVar9 >> 0x10);

      if ((int)-(unsigned int)((int)uVar14 < 0) < 0) {

        uVar7 = ~uVar7;

        if (uVar18 == 0) {

          uVar7 = uVar7 + 1;

        }

        else {

          uVar18 = ~uVar18 + 1;

        }

      }

      if (((unsigned char)(uVar11 >> 1) & 1) == 1) {

        uVar18 = uVar17 + uVar18;

        uVar5 = uVar7 + (uVar18 < uVar17) + (uVar5 & 0xffff);

        if ((int)uVar5 < -0x8000) {

          uVar5 = 0xffff8000;

          uVar18 = 0;

        }

        if (0x7fff < (int)uVar5) {

          uVar5 = 0x7fff;

          uVar18 = 0xffffffff;

        }

        uVar5 = uVar5 & 0xffff;

      }

      else {

        uVar18 = uVar17 + uVar18;

        uVar5 = uVar7 + (uVar18 < uVar17) + uVar5;

      }

      iVar6 = iVar6 + -1;

      in_sr = uVar11 & 0xfffffffe;

      uVar9 = puVar12[2];

      uVar7 = puVar10[6];

      uVar14 = uVar9 ^ uVar7;

      if ((int)uVar9 < 0) {

        uVar9 = -uVar9;

      }

      if ((int)uVar7 < 0) {

        uVar7 = -uVar7;

      }

      uVar17 = (uVar7 & 0xffff) * (uVar9 & 0xffff);

      iVar3 = (uVar7 >> 0x10) * (uVar9 & 0xffff);

      iVar1 = 0;

      uVar2 = iVar3 + (uVar7 & 0xffff) * (uVar9 >> 0x10);

      if (iVar3 != 0) {

        iVar1 = 0x10000;

      }

      uVar19 = uVar17 + (uVar2 << 16);

      uVar7 = iVar1 + (unsigned int)(uVar19 < uVar17) + (uVar2 >> 0x10) + (uVar7 >> 0x10) * (uVar9 >> 0x10);

      if ((int)-(unsigned int)((int)uVar14 < 0) < 0) {

        uVar7 = ~uVar7;

        if (uVar19 == 0) {

          uVar7 = uVar7 + 1;

        }

        else {

          uVar19 = ~uVar19 + 1;

        }

      }

      if (((unsigned char)(uVar11 >> 1) & 1) == 1) {

        uVar19 = uVar18 + uVar19;

        uVar5 = uVar7 + (uVar19 < uVar18) + (uVar5 & 0xffff);

        if ((int)uVar5 < -0x8000) {

          uVar5 = 0xffff8000;

          uVar19 = 0;

        }

        if (0x7fff < (int)uVar5) {

          uVar5 = 0x7fff;

          uVar19 = 0xffffffff;

        }

        uVar5 = uVar5 & 0xffff;

      }

      else {

        uVar19 = uVar18 + uVar19;

        uVar5 = uVar7 + (uVar19 < uVar18) + uVar5;

      }

      *puVar15 = uVar5 << 0x10 | uVar19 >> 0x10;

      puVar15 = puVar15 + 1;

      param_1 = puVar10 + 1;

    } while (iVar6 != 0);

    param_1 = puVar10 + -2;

    iVar8 = iVar8 + -1;

    puVar4 = puVar12 + 3;

  } while (iVar8 != 0);

  puVar13 = puVar12 + -6;

  iVar8 = 3;

  do {

    puVar16 = puVar4;

    puVar12 = puVar15;

    uVar7 = *puVar13;

    uVar5 = puVar10[7];

    uVar9 = uVar7 ^ uVar5;

    if ((int)uVar7 < 0) {

      uVar7 = -uVar7;

    }

    if ((int)uVar5 < 0) {

      uVar5 = -uVar5;

    }

    uVar2 = (uVar5 & 0xffff) * (uVar7 & 0xffff);

    iVar1 = (uVar5 >> 0x10) * (uVar7 & 0xffff);

    iVar6 = 0;

    uVar14 = iVar1 + (uVar5 & 0xffff) * (uVar7 >> 0x10);

    if (iVar1 != 0) {

      iVar6 = 0x10000;

    }

    uVar17 = uVar2 + (uVar14 << 16);

    uVar5 = iVar6 + (unsigned int)(uVar17 < uVar2) + (uVar14 >> 0x10) + (uVar5 >> 0x10) * (uVar7 >> 0x10);

    if ((int)-(unsigned int)((int)uVar9 < 0) < 0) {

      uVar5 = ~uVar5;

      if (uVar17 == 0) {

        uVar5 = uVar5 + 1;

      }

      else {

        uVar17 = ~uVar17 + 1;

      }

    }

    if (((unsigned char)(uVar11 >> 1) & 1) == 1) {

      if ((int)uVar5 < -0x8000) {

        uVar5 = 0xffff8000;

        uVar17 = 0;

      }

      if (0x7fff < (int)uVar5) {

        uVar5 = 0x7fff;

        uVar17 = 0xffffffff;

      }

      uVar5 = uVar5 & 0xffff;

    }

    uVar9 = puVar13[1];

    uVar7 = puVar10[8];

    uVar14 = uVar9 ^ uVar7;

    if ((int)uVar9 < 0) {

      uVar9 = -uVar9;

    }

    if ((int)uVar7 < 0) {

      uVar7 = -uVar7;

    }

    uVar19 = (uVar7 & 0xffff) * (uVar9 & 0xffff);

    iVar1 = (uVar7 >> 0x10) * (uVar9 & 0xffff);

    iVar6 = 0;

    uVar2 = iVar1 + (uVar7 & 0xffff) * (uVar9 >> 0x10);

    if (iVar1 != 0) {

      iVar6 = 0x10000;

    }

    uVar18 = uVar19 + (uVar2 << 16);

    uVar7 = iVar6 + (unsigned int)(uVar18 < uVar19) + (uVar2 >> 0x10) + (uVar7 >> 0x10) * (uVar9 >> 0x10);

    if ((int)-(unsigned int)((int)uVar14 < 0) < 0) {

      uVar7 = ~uVar7;

      if (uVar18 == 0) {

        uVar7 = uVar7 + 1;

      }

      else {

        uVar18 = ~uVar18 + 1;

      }

    }

    if (((unsigned char)(uVar11 >> 1) & 1) == 1) {

      uVar18 = uVar17 + uVar18;

      uVar5 = uVar7 + (uVar18 < uVar17) + (uVar5 & 0xffff);

      if ((int)uVar5 < -0x8000) {

        uVar5 = 0xffff8000;

        uVar18 = 0;

      }

      if (0x7fff < (int)uVar5) {

        uVar5 = 0x7fff;

        uVar18 = 0xffffffff;

      }

      uVar5 = uVar5 & 0xffff;

    }

    else {

      uVar18 = uVar17 + uVar18;

      uVar5 = uVar7 + (uVar18 < uVar17) + uVar5;

    }

    iVar8 = iVar8 + -1;

    uVar9 = puVar13[2];

    puVar13 = puVar13 + 3;

    uVar7 = puVar10[9];

    uVar14 = uVar9 ^ uVar7;

    if ((int)uVar9 < 0) {

      uVar9 = -uVar9;

    }

    if ((int)uVar7 < 0) {

      uVar7 = -uVar7;

    }

    uVar17 = (uVar7 & 0xffff) * (uVar9 & 0xffff);

    iVar1 = (uVar7 >> 0x10) * (uVar9 & 0xffff);

    iVar6 = 0;

    uVar2 = iVar1 + (uVar7 & 0xffff) * (uVar9 >> 0x10);

    if (iVar1 != 0) {

      iVar6 = 0x10000;

    }

    uVar19 = uVar17 + (uVar2 << 16);

    uVar7 = iVar6 + (unsigned int)(uVar19 < uVar17) + (uVar2 >> 0x10) + (uVar7 >> 0x10) * (uVar9 >> 0x10);

    if ((int)-(unsigned int)((int)uVar14 < 0) < 0) {

      uVar7 = ~uVar7;

      if (uVar19 == 0) {

        uVar7 = uVar7 + 1;

      }

      else {

        uVar19 = ~uVar19 + 1;

      }

    }

    if (((unsigned char)(uVar11 >> 1) & 1) == 1) {

      uVar19 = uVar18 + uVar19;

      uVar5 = uVar7 + (uVar19 < uVar18) + (uVar5 & 0xffff);

      if ((int)uVar5 < -0x8000) {

        uVar5 = 0xffff8000;

        uVar19 = 0;

      }

      if (0x7fff < (int)uVar5) {

        uVar5 = 0x7fff;

        uVar19 = 0xffffffff;

      }

      uVar5 = uVar5 & 0xffff;

    }

    else {

      uVar19 = uVar18 + uVar19;

      uVar5 = uVar7 + (uVar19 < uVar18) + uVar5;

    }

    *puVar12 = (uVar5 << 0x10 | uVar19 >> 0x10) + *puVar16;

    puVar15 = puVar12 + 1;

    puVar4 = puVar16 + 1;

  } while (iVar8 != 0);

  uVar5 = puVar12[-10];

  uVar7 = puVar12[-9];

  uVar9 = puVar12[-8];

  uVar11 = puVar12[-7];

  uVar14 = puVar12[-6];

  puVar16[-0xb] = puVar12[-0xb];

  puVar16[-10] = uVar5;

  puVar16[-9] = uVar7;

  puVar16[-8] = uVar9;

  puVar16[-7] = uVar11;

  puVar16[-6] = uVar14;

  uVar5 = puVar12[-4];

  uVar7 = puVar12[-3];

  uVar9 = puVar12[-2];

  uVar11 = puVar12[-1];

  uVar14 = *puVar12;

  puVar16[-5] = puVar12[-5];

  puVar16[-4] = uVar5;

  puVar16[-3] = uVar7;

  puVar16[-2] = uVar9;

  puVar16[-1] = uVar11;

  *puVar16 = uVar14;

  return;

}

void FUN_06026ffc(param_1, param_2)
    unsigned int *param_1;
    int *param_2;
{

  unsigned int uVar1;

  unsigned int uVar2;

  int iVar3;

  unsigned int uVar4;

  unsigned int uVar5;

  int *piVar6;

  unsigned int uVar7;

  int iVar8;

  int iVar9;

  unsigned int *puVar10;

  unsigned int *puVar11;

  int *piVar12;

  unsigned int in_sr = 0;

  unsigned int uVar13;

  unsigned int uVar14;

  unsigned int uVar15;

  unsigned int uVar16;

  puVar10 = *(unsigned int **)0x06089EDC;

  puVar11 = puVar10 + 9;

  iVar9 = 3;

  piVar6 = (int *)0x0608A520;

  do {

    piVar12 = piVar6;

    uVar4 = *puVar10;

    uVar13 = *param_1;

    uVar5 = uVar4 ^ uVar13;

    if ((int)uVar4 < 0) {

      uVar4 = -uVar4;

    }

    if ((int)uVar13 < 0) {

      uVar13 = -uVar13;

    }

    uVar7 = (uVar13 & 0xffff) * (uVar4 & 0xffff);

    iVar3 = (uVar13 >> 0x10) * (uVar4 & 0xffff);

    iVar8 = 0;

    uVar1 = iVar3 + (uVar13 & 0xffff) * (uVar4 >> 0x10);

    if (iVar3 != 0) {

      iVar8 = 0x10000;

    }

    uVar14 = uVar7 + (uVar1 << 16);

    uVar13 = iVar8 + (unsigned int)(uVar14 < uVar7) + (uVar1 >> 0x10) + (uVar13 >> 0x10) * (uVar4 >> 0x10);

    if ((int)-(unsigned int)((int)uVar5 < 0) < 0) {

      uVar13 = ~uVar13;

      if (uVar14 == 0) {

        uVar13 = uVar13 + 1;

      }

      else {

        uVar14 = ~uVar14 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      if ((int)uVar13 < -0x8000) {

        uVar13 = 0xffff8000;

        uVar14 = 0;

      }

      if (0x7fff < (int)uVar13) {

        uVar13 = 0x7fff;

        uVar14 = 0xffffffff;

      }

      uVar13 = uVar13 & 0xffff;

    }

    uVar5 = puVar10[1];

    uVar4 = param_1[1];

    uVar1 = uVar5 ^ uVar4;

    if ((int)uVar5 < 0) {

      uVar5 = -uVar5;

    }

    if ((int)uVar4 < 0) {

      uVar4 = -uVar4;

    }

    uVar2 = (uVar4 & 0xffff) * (uVar5 & 0xffff);

    iVar3 = (uVar4 >> 0x10) * (uVar5 & 0xffff);

    iVar8 = 0;

    uVar7 = iVar3 + (uVar4 & 0xffff) * (uVar5 >> 0x10);

    if (iVar3 != 0) {

      iVar8 = 0x10000;

    }

    uVar15 = uVar2 + (uVar7 << 16);

    uVar4 = iVar8 + (unsigned int)(uVar15 < uVar2) + (uVar7 >> 0x10) + (uVar4 >> 0x10) * (uVar5 >> 0x10);

    if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

      uVar4 = ~uVar4;

      if (uVar15 == 0) {

        uVar4 = uVar4 + 1;

      }

      else {

        uVar15 = ~uVar15 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      uVar15 = uVar14 + uVar15;

      uVar13 = uVar4 + (uVar15 < uVar14) + (uVar13 & 0xffff);

      if ((int)uVar13 < -0x8000) {

        uVar13 = 0xffff8000;

        uVar15 = 0;

      }

      if (0x7fff < (int)uVar13) {

        uVar13 = 0x7fff;

        uVar15 = 0xffffffff;

      }

      uVar13 = uVar13 & 0xffff;

    }

    else {

      uVar15 = uVar14 + uVar15;

      uVar13 = uVar4 + (uVar15 < uVar14) + uVar13;

    }

    uVar7 = *puVar11;

    puVar11 = puVar11 + 1;

    uVar5 = puVar10[2];

    puVar10 = puVar10 + 3;

    uVar4 = param_1[2];

    uVar1 = uVar5 ^ uVar4;

    if ((int)uVar5 < 0) {

      uVar5 = -uVar5;

    }

    if ((int)uVar4 < 0) {

      uVar4 = -uVar4;

    }

    uVar2 = (uVar4 & 0xffff) * (uVar5 & 0xffff);

    iVar3 = (uVar4 >> 0x10) * (uVar5 & 0xffff);

    iVar8 = 0;

    uVar14 = iVar3 + (uVar4 & 0xffff) * (uVar5 >> 0x10);

    if (iVar3 != 0) {

      iVar8 = 0x10000;

    }

    uVar16 = uVar2 + (uVar14 << 16);

    uVar4 = iVar8 + (unsigned int)(uVar16 < uVar2) + (uVar14 >> 0x10) + (uVar4 >> 0x10) * (uVar5 >> 0x10);

    if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

      uVar4 = ~uVar4;

      if (uVar16 == 0) {

        uVar4 = uVar4 + 1;

      }

      else {

        uVar16 = ~uVar16 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      uVar16 = uVar15 + uVar16;

      uVar13 = uVar4 + (uVar16 < uVar15) + (uVar13 & 0xffff);

      if ((int)uVar13 < -0x8000) {

        uVar13 = 0xffff8000;

        uVar16 = 0;

      }

      if (0x7fff < (int)uVar13) {

        uVar13 = 0x7fff;

        uVar16 = 0xffffffff;

      }

      uVar13 = uVar13 & 0xffff;

    }

    else {

      uVar16 = uVar15 + uVar16;

      uVar13 = uVar4 + (uVar16 < uVar15) + uVar13;

    }

    iVar9 = iVar9 + -1;

    in_sr = in_sr & 0xfffffffe;

    *piVar12 = (uVar13 << 0x10 | uVar16 >> 0x10) + uVar7;

    piVar6 = piVar12 + 1;

  } while (iVar9 != 0);

  iVar9 = piVar12[-1];

  iVar8 = *piVar12;

  *param_2 = piVar12[-2];

  param_2[1] = iVar9;

  param_2[2] = iVar8;

  return;

}

void FUN_06027080()
{

  int *puVar1;

  puVar1 = *(int **)0x0608A52C;

  *(int **)0x0608A52C = puVar1 + 0xc;

  puVar1[0xc] = *puVar1;

  puVar1[0xd] = puVar1[1];

  puVar1[0xe] = puVar1[2];

  puVar1[0xf] = puVar1[3];

  puVar1[0x10] = puVar1[4];

  puVar1[0x11] = puVar1[5];

  puVar1[0x12] = puVar1[6];

  puVar1[0x13] = puVar1[7];

  puVar1[0x14] = puVar1[8];

  puVar1[0x15] = puVar1[9];

  puVar1[0x16] = puVar1[10];

  puVar1[0x17] = puVar1[0xb];

  return;

}

void FUN_060270c6()
{

  int *puVar1;

  char *puVar2;

  puVar1 = (int *)0x0608A530;

  *(int **)0x0608A52C = 0x0608A530;

  puVar2 = (int *)0x00010000;

  puVar1[1] = 0;

  *puVar1 = puVar2;

  puVar1[2] = 0;

  puVar1[3] = 0;

  puVar1[4] = puVar2;

  puVar1[5] = 0;

  puVar1[6] = 0;

  puVar1[7] = 0;

  puVar1[8] = puVar2;

  puVar1[9] = 0;

  puVar1[10] = 0;

  puVar1[0xb] = 0;

  return;

}

void FUN_060270d0()
{

  char *puVar1;

  int *puVar2;

  

  puVar1 = (int *)0x00010000;

  puVar2 = *(int **)0x0608A52C;

  puVar2[1] = 0;

  *puVar2 = puVar1;

  puVar2[2] = 0;

  puVar2[3] = 0;

  puVar2[4] = puVar1;

  puVar2[5] = 0;

  puVar2[6] = 0;

  puVar2[7] = 0;

  puVar2[8] = puVar1;

  puVar2[9] = 0;

  puVar2[10] = 0;

  puVar2[0xb] = 0;

  return;

}

char * FUN_060270f2(param_1, param_2, param_3)
    int param_1;
    int param_2;
    int param_3;
{

  unsigned int uVar1;

  int iVar2;

  unsigned int uVar3;

  int iVar4;

  unsigned int uVar5;

  unsigned int uVar6;

  char *puVar7;

  char *puVar8;

  int iVar9;

  unsigned int *puVar10;

  unsigned int *puVar11;

  unsigned int in_sr = 0;

  unsigned int uVar12;

  unsigned int uVar13;

  unsigned int uVar14;

  unsigned int uVar15;

  puVar8 = (char *)0x0608A6B0;

  puVar7 = (int *)0x0608A52C;

  *(int *)0x0608A6B0 = param_1;

  *(int *)(puVar8 + 4) = param_2;

  *(int *)(puVar8 + 8) = param_3;

  puVar10 = *(unsigned int **)puVar7;

  iVar9 = 3;

  puVar11 = puVar10 + 9;

  do {

    uVar5 = *(unsigned int *)puVar8;

    uVar12 = *puVar10;

    uVar6 = uVar5 ^ uVar12;

    if ((int)uVar5 < 0) {

      uVar5 = -uVar5;

    }

    if ((int)uVar12 < 0) {

      uVar12 = -uVar12;

    }

    uVar3 = (uVar12 & 0xffff) * (uVar5 & 0xffff);

    iVar4 = (uVar12 >> 0x10) * (uVar5 & 0xffff);

    iVar2 = 0;

    uVar1 = iVar4 + (uVar12 & 0xffff) * (uVar5 >> 0x10);

    if (iVar4 != 0) {

      iVar2 = 0x10000;

    }

    uVar13 = uVar3 + (uVar1 << 16);

    uVar12 = iVar2 + (unsigned int)(uVar13 < uVar3) + (uVar1 >> 0x10) + (uVar12 >> 0x10) * (uVar5 >> 0x10);

    if ((int)-(unsigned int)((int)uVar6 < 0) < 0) {

      uVar12 = ~uVar12;

      if (uVar13 == 0) {

        uVar12 = uVar12 + 1;

      }

      else {

        uVar13 = ~uVar13 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      if ((int)uVar12 < -0x8000) {

        uVar12 = 0xffff8000;

        uVar13 = 0;

      }

      if (0x7fff < (int)uVar12) {

        uVar12 = 0x7fff;

        uVar13 = 0xffffffff;

      }

      uVar12 = uVar12 & 0xffff;

    }

    uVar6 = *(unsigned int *)(puVar8 + 4);

    uVar5 = puVar10[1];

    uVar1 = uVar6 ^ uVar5;

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    if ((int)uVar5 < 0) {

      uVar5 = -uVar5;

    }

    uVar15 = (uVar5 & 0xffff) * (uVar6 & 0xffff);

    iVar4 = (uVar5 >> 0x10) * (uVar6 & 0xffff);

    iVar2 = 0;

    uVar3 = iVar4 + (uVar5 & 0xffff) * (uVar6 >> 0x10);

    if (iVar4 != 0) {

      iVar2 = 0x10000;

    }

    uVar14 = uVar15 + (uVar3 << 16);

    uVar5 = iVar2 + (unsigned int)(uVar14 < uVar15) + (uVar3 >> 0x10) + (uVar5 >> 0x10) * (uVar6 >> 0x10);

    if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

      uVar5 = ~uVar5;

      if (uVar14 == 0) {

        uVar5 = uVar5 + 1;

      }

      else {

        uVar14 = ~uVar14 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      uVar14 = uVar13 + uVar14;

      uVar12 = uVar5 + (uVar14 < uVar13) + (uVar12 & 0xffff);

      if ((int)uVar12 < -0x8000) {

        uVar12 = 0xffff8000;

        uVar14 = 0;

      }

      if (0x7fff < (int)uVar12) {

        uVar12 = 0x7fff;

        uVar14 = 0xffffffff;

      }

      uVar12 = uVar12 & 0xffff;

    }

    else {

      uVar14 = uVar13 + uVar14;

      uVar12 = uVar5 + (uVar14 < uVar13) + uVar12;

    }

    uVar6 = *(unsigned int *)(puVar8 + 8);

    uVar5 = puVar10[2];

    puVar10 = puVar10 + 3;

    uVar1 = uVar6 ^ uVar5;

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    if ((int)uVar5 < 0) {

      uVar5 = -uVar5;

    }

    uVar13 = (uVar5 & 0xffff) * (uVar6 & 0xffff);

    iVar4 = (uVar5 >> 0x10) * (uVar6 & 0xffff);

    iVar2 = 0;

    uVar3 = iVar4 + (uVar5 & 0xffff) * (uVar6 >> 0x10);

    if (iVar4 != 0) {

      iVar2 = 0x10000;

    }

    uVar15 = uVar13 + (uVar3 << 16);

    uVar5 = iVar2 + (unsigned int)(uVar15 < uVar13) + (uVar3 >> 0x10) + (uVar5 >> 0x10) * (uVar6 >> 0x10);

    if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

      uVar5 = ~uVar5;

      if (uVar15 == 0) {

        uVar5 = uVar5 + 1;

      }

      else {

        uVar15 = ~uVar15 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      uVar15 = uVar14 + uVar15;

      uVar12 = uVar5 + (uVar15 < uVar14) + (uVar12 & 0xffff);

      if ((int)uVar12 < -0x8000) {

        uVar12 = 0xffff8000;

        uVar15 = 0;

      }

      if (0x7fff < (int)uVar12) {

        uVar12 = 0x7fff;

        uVar15 = 0xffffffff;

      }

      uVar12 = uVar12 & 0xffff;

    }

    else {

      uVar15 = uVar14 + uVar15;

      uVar12 = uVar5 + (uVar15 < uVar14) + uVar12;

    }

    iVar9 = iVar9 + -1;

    in_sr = in_sr & 0xfffffffe;

    *puVar11 = (uVar12 << 0x10 | uVar15 >> 0x10) + *puVar11;

    puVar11 = puVar11 + 1;

  } while (iVar9 != 0);

  return puVar8;

}

unsigned int FUN_06027124(param_1, param_2, param_3)
    int param_1;
    int param_2;
    int param_3;
{

  long long lVar1;

  unsigned int uVar2;

  int iVar3;

  unsigned int *puVar4;

  puVar4 = *(unsigned int **)0x0608A52C;

  iVar3 = 3;

  do {

    *puVar4 = (int)((unsigned long long)((long long)param_1 * (long long)(int)*puVar4) >> 0x20) << 0x10 |

              (unsigned int)((long long)param_1 * (long long)(int)*puVar4) >> 0x10;

    uVar2 = puVar4[6];

    lVar1 = (long long)param_3 * (long long)(int)uVar2;

    puVar4[3] = (int)((unsigned long long)((long long)param_2 * (long long)(int)puVar4[3]) >> 0x20) << 0x10 |

                (unsigned int)((long long)param_2 * (long long)(int)puVar4[3]) >> 0x10;

    iVar3 = iVar3 + -1;

    puVar4[6] = (int)((unsigned long long)lVar1 >> 0x20) << 0x10 | (unsigned int)lVar1 >> 0x10;

    puVar4 = puVar4 + 1;

  } while (iVar3 != 0);

  return uVar2;

}

unsigned int FUN_06027158()
{

  unsigned int uVar1;

  int iVar2;

  unsigned int uVar3;

  unsigned int uVar4;

  int iVar5;

  unsigned int uVar6;

  char *puVar7;

  int iVar8;

  unsigned int *puVar9;

  int *piVar10;

  unsigned int *puVar11;

  unsigned int in_sr = 0;

  unsigned int uVar12;

  unsigned int uVar13;

  unsigned int uVar14;

  unsigned int uVar15;

  unsigned int uVar16;

  unsigned int uVar17;

  piVar10 = (int *)(0x0608A6B0 + 8);

  puVar11 = (unsigned int *)0x0608A6B0;

  FUN_06027358();

  puVar11[1] = -*piVar10;

  puVar7 = (int *)0x0608A52C;

  puVar11[3] = *puVar11;

  iVar8 = 3;

  puVar9 = (unsigned int *)(*(int *)puVar7 + 4);

  do {

    uVar13 = *puVar9;

    uVar12 = *puVar11;

    uVar6 = uVar13 ^ uVar12;

    if ((int)uVar13 < 0) {

      uVar13 = -uVar13;

    }

    if ((int)uVar12 < 0) {

      uVar12 = -uVar12;

    }

    uVar3 = (uVar12 & 0xffff) * (uVar13 & 0xffff);

    iVar5 = (uVar12 >> 0x10) * (uVar13 & 0xffff);

    iVar2 = 0;

    uVar1 = iVar5 + (uVar12 & 0xffff) * (uVar13 >> 0x10);

    if (iVar5 != 0) {

      iVar2 = 0x10000;

    }

    uVar14 = uVar3 + (uVar1 << 16);

    uVar12 = iVar2 + (unsigned int)(uVar14 < uVar3) + (uVar1 >> 0x10) + (uVar12 >> 0x10) * (uVar13 >> 0x10);

    if ((int)-(unsigned int)((int)uVar6 < 0) < 0) {

      uVar12 = ~uVar12;

      if (uVar14 == 0) {

        uVar12 = uVar12 + 1;

      }

      else {

        uVar14 = ~uVar14 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      if ((int)uVar12 < -0x8000) {

        uVar12 = 0xffff8000;

        uVar14 = 0;

      }

      if (0x7fff < (int)uVar12) {

        uVar12 = 0x7fff;

        uVar14 = 0xffffffff;

      }

      uVar12 = uVar12 & 0xffff;

    }

    uVar6 = puVar9[1];

    uVar13 = puVar11[1];

    uVar1 = uVar6 ^ uVar13;

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    if ((int)uVar13 < 0) {

      uVar13 = -uVar13;

    }

    uVar16 = (uVar13 & 0xffff) * (uVar6 & 0xffff);

    iVar5 = (uVar13 >> 0x10) * (uVar6 & 0xffff);

    iVar2 = 0;

    uVar3 = iVar5 + (uVar13 & 0xffff) * (uVar6 >> 0x10);

    if (iVar5 != 0) {

      iVar2 = 0x10000;

    }

    uVar15 = uVar16 + (uVar3 << 16);

    uVar13 = iVar2 + (unsigned int)(uVar15 < uVar16) + (uVar3 >> 0x10) + (uVar13 >> 0x10) * (uVar6 >> 0x10);

    if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

      uVar13 = ~uVar13;

      if (uVar15 == 0) {

        uVar13 = uVar13 + 1;

      }

      else {

        uVar15 = ~uVar15 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      uVar15 = uVar14 + uVar15;

      uVar12 = uVar13 + (uVar15 < uVar14) + (uVar12 & 0xffff);

      if ((int)uVar12 < -0x8000) {

        uVar12 = 0xffff8000;

        uVar15 = 0;

      }

      if (0x7fff < (int)uVar12) {

        uVar12 = 0x7fff;

        uVar15 = 0xffffffff;

      }

      uVar12 = uVar12 & 0xffff;

    }

    else {

      uVar15 = uVar14 + uVar15;

      uVar12 = uVar13 + (uVar15 < uVar14) + uVar12;

    }

    uVar6 = *puVar9;

    uVar13 = puVar11[2];

    uVar1 = uVar6 ^ uVar13;

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    if ((int)uVar13 < 0) {

      uVar13 = -uVar13;

    }

    uVar14 = (uVar13 & 0xffff) * (uVar6 & 0xffff);

    iVar5 = (uVar13 >> 0x10) * (uVar6 & 0xffff);

    iVar2 = 0;

    uVar3 = iVar5 + (uVar13 & 0xffff) * (uVar6 >> 0x10);

    if (iVar5 != 0) {

      iVar2 = 0x10000;

    }

    uVar16 = uVar14 + (uVar3 << 16);

    uVar13 = iVar2 + (unsigned int)(uVar16 < uVar14) + (uVar3 >> 0x10) + (uVar13 >> 0x10) * (uVar6 >> 0x10);

    if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

      uVar13 = ~uVar13;

      if (uVar16 == 0) {

        uVar13 = uVar13 + 1;

      }

      else {

        uVar16 = ~uVar16 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      if ((int)uVar13 < -0x8000) {

        uVar13 = 0xffff8000;

        uVar16 = 0;

      }

      if (0x7fff < (int)uVar13) {

        uVar13 = 0x7fff;

        uVar16 = 0xffffffff;

      }

      uVar13 = uVar13 & 0xffff;

    }

    uVar1 = puVar9[1];

    uVar6 = puVar11[3];

    uVar3 = uVar1 ^ uVar6;

    if ((int)uVar1 < 0) {

      uVar1 = -uVar1;

    }

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    uVar4 = (uVar6 & 0xffff) * (uVar1 & 0xffff);

    iVar5 = (uVar6 >> 0x10) * (uVar1 & 0xffff);

    iVar2 = 0;

    uVar14 = iVar5 + (uVar6 & 0xffff) * (uVar1 >> 0x10);

    if (iVar5 != 0) {

      iVar2 = 0x10000;

    }

    uVar17 = uVar4 + (uVar14 << 16);

    uVar6 = iVar2 + (unsigned int)(uVar17 < uVar4) + (uVar14 >> 0x10) + (uVar6 >> 0x10) * (uVar1 >> 0x10);

    if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

      uVar6 = ~uVar6;

      if (uVar17 == 0) {

        uVar6 = uVar6 + 1;

      }

      else {

        uVar17 = ~uVar17 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      uVar17 = uVar16 + uVar17;

      uVar6 = uVar6 + (uVar17 < uVar16) + (uVar13 & 0xffff);

      if ((int)uVar6 < -0x8000) {

        uVar6 = 0xffff8000;

        uVar17 = 0;

      }

      if (0x7fff < (int)uVar6) {

        uVar6 = 0x7fff;

        uVar17 = 0xffffffff;

      }

      uVar13 = uVar6 & 0xffff | uVar13 & 0xffff0000;

    }

    else {

      uVar17 = uVar16 + uVar17;

      uVar13 = uVar6 + (uVar17 < uVar16) + uVar13;

    }

    *puVar9 = uVar12 << 0x10 | uVar15 >> 0x10;

    iVar8 = iVar8 + -1;

    in_sr = in_sr & 0xfffffffe;

    puVar9[1] = uVar13 << 0x10 | uVar17 >> 0x10;

    puVar9 = puVar9 + 3;

  } while (iVar8 != 0);

  return uVar13;

}

unsigned int FUN_060271a2()
{

  unsigned int uVar1;

  int iVar2;

  unsigned int uVar3;

  unsigned int uVar4;

  int iVar5;

  unsigned int uVar6;

  char *puVar7;

  int iVar8;

  unsigned int *puVar9;

  int *piVar10;

  unsigned int *puVar11;

  unsigned int in_sr = 0;

  unsigned int uVar12;

  unsigned int uVar13;

  unsigned int uVar14;

  unsigned int uVar15;

  unsigned int uVar16;

  unsigned int uVar17;

  piVar10 = (int *)(0x0608A6B0 + 4);

  puVar11 = (unsigned int *)0x0608A6B0;

  FUN_06027358();

  puVar11[2] = -*piVar10;

  puVar7 = (int *)0x0608A52C;

  puVar11[3] = *puVar11;

  puVar9 = *(unsigned int **)puVar7;

  iVar8 = 3;

  do {

    uVar13 = *puVar9;

    uVar12 = *puVar11;

    uVar6 = uVar13 ^ uVar12;

    if ((int)uVar13 < 0) {

      uVar13 = -uVar13;

    }

    if ((int)uVar12 < 0) {

      uVar12 = -uVar12;

    }

    uVar3 = (uVar12 & 0xffff) * (uVar13 & 0xffff);

    iVar5 = (uVar12 >> 0x10) * (uVar13 & 0xffff);

    iVar2 = 0;

    uVar1 = iVar5 + (uVar12 & 0xffff) * (uVar13 >> 0x10);

    if (iVar5 != 0) {

      iVar2 = 0x10000;

    }

    uVar14 = uVar3 + (uVar1 << 16);

    uVar12 = iVar2 + (unsigned int)(uVar14 < uVar3) + (uVar1 >> 0x10) + (uVar12 >> 0x10) * (uVar13 >> 0x10);

    if ((int)-(unsigned int)((int)uVar6 < 0) < 0) {

      uVar12 = ~uVar12;

      if (uVar14 == 0) {

        uVar12 = uVar12 + 1;

      }

      else {

        uVar14 = ~uVar14 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      if ((int)uVar12 < -0x8000) {

        uVar12 = 0xffff8000;

        uVar14 = 0;

      }

      if (0x7fff < (int)uVar12) {

        uVar12 = 0x7fff;

        uVar14 = 0xffffffff;

      }

      uVar12 = uVar12 & 0xffff;

    }

    uVar6 = puVar9[2];

    uVar13 = puVar11[1];

    uVar1 = uVar6 ^ uVar13;

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    if ((int)uVar13 < 0) {

      uVar13 = -uVar13;

    }

    uVar16 = (uVar13 & 0xffff) * (uVar6 & 0xffff);

    iVar5 = (uVar13 >> 0x10) * (uVar6 & 0xffff);

    iVar2 = 0;

    uVar3 = iVar5 + (uVar13 & 0xffff) * (uVar6 >> 0x10);

    if (iVar5 != 0) {

      iVar2 = 0x10000;

    }

    uVar15 = uVar16 + (uVar3 << 16);

    uVar13 = iVar2 + (unsigned int)(uVar15 < uVar16) + (uVar3 >> 0x10) + (uVar13 >> 0x10) * (uVar6 >> 0x10);

    if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

      uVar13 = ~uVar13;

      if (uVar15 == 0) {

        uVar13 = uVar13 + 1;

      }

      else {

        uVar15 = ~uVar15 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      uVar15 = uVar14 + uVar15;

      uVar12 = uVar13 + (uVar15 < uVar14) + (uVar12 & 0xffff);

      if ((int)uVar12 < -0x8000) {

        uVar12 = 0xffff8000;

        uVar15 = 0;

      }

      if (0x7fff < (int)uVar12) {

        uVar12 = 0x7fff;

        uVar15 = 0xffffffff;

      }

      uVar12 = uVar12 & 0xffff;

    }

    else {

      uVar15 = uVar14 + uVar15;

      uVar12 = uVar13 + (uVar15 < uVar14) + uVar12;

    }

    uVar6 = *puVar9;

    uVar13 = puVar11[2];

    uVar1 = uVar6 ^ uVar13;

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    if ((int)uVar13 < 0) {

      uVar13 = -uVar13;

    }

    uVar14 = (uVar13 & 0xffff) * (uVar6 & 0xffff);

    iVar5 = (uVar13 >> 0x10) * (uVar6 & 0xffff);

    iVar2 = 0;

    uVar3 = iVar5 + (uVar13 & 0xffff) * (uVar6 >> 0x10);

    if (iVar5 != 0) {

      iVar2 = 0x10000;

    }

    uVar16 = uVar14 + (uVar3 << 16);

    uVar13 = iVar2 + (unsigned int)(uVar16 < uVar14) + (uVar3 >> 0x10) + (uVar13 >> 0x10) * (uVar6 >> 0x10);

    if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

      uVar13 = ~uVar13;

      if (uVar16 == 0) {

        uVar13 = uVar13 + 1;

      }

      else {

        uVar16 = ~uVar16 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      if ((int)uVar13 < -0x8000) {

        uVar13 = 0xffff8000;

        uVar16 = 0;

      }

      if (0x7fff < (int)uVar13) {

        uVar13 = 0x7fff;

        uVar16 = 0xffffffff;

      }

      uVar13 = uVar13 & 0xffff;

    }

    uVar1 = puVar9[2];

    uVar6 = puVar11[3];

    uVar3 = uVar1 ^ uVar6;

    if ((int)uVar1 < 0) {

      uVar1 = -uVar1;

    }

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    uVar4 = (uVar6 & 0xffff) * (uVar1 & 0xffff);

    iVar5 = (uVar6 >> 0x10) * (uVar1 & 0xffff);

    iVar2 = 0;

    uVar14 = iVar5 + (uVar6 & 0xffff) * (uVar1 >> 0x10);

    if (iVar5 != 0) {

      iVar2 = 0x10000;

    }

    uVar17 = uVar4 + (uVar14 << 16);

    uVar6 = iVar2 + (unsigned int)(uVar17 < uVar4) + (uVar14 >> 0x10) + (uVar6 >> 0x10) * (uVar1 >> 0x10);

    if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

      uVar6 = ~uVar6;

      if (uVar17 == 0) {

        uVar6 = uVar6 + 1;

      }

      else {

        uVar17 = ~uVar17 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      uVar17 = uVar16 + uVar17;

      uVar6 = uVar6 + (uVar17 < uVar16) + (uVar13 & 0xffff);

      if ((int)uVar6 < -0x8000) {

        uVar6 = 0xffff8000;

        uVar17 = 0;

      }

      if (0x7fff < (int)uVar6) {

        uVar6 = 0x7fff;

        uVar17 = 0xffffffff;

      }

      uVar13 = uVar6 & 0xffff | uVar13 & 0xffff0000;

    }

    else {

      uVar17 = uVar16 + uVar17;

      uVar13 = uVar6 + (uVar17 < uVar16) + uVar13;

    }

    *puVar9 = uVar12 << 0x10 | uVar15 >> 0x10;

    iVar8 = iVar8 + -1;

    in_sr = in_sr & 0xfffffffe;

    puVar9[2] = uVar13 << 0x10 | uVar17 >> 0x10;

    puVar9 = puVar9 + 3;

  } while (iVar8 != 0);

  return uVar13;

}

unsigned int FUN_060271ee()
{

  unsigned int uVar1;

  int iVar2;

  unsigned int uVar3;

  unsigned int uVar4;

  int iVar5;

  unsigned int uVar6;

  char *puVar7;

  int iVar8;

  unsigned int *puVar9;

  int *piVar10;

  unsigned int *puVar11;

  unsigned int in_sr = 0;

  unsigned int uVar12;

  unsigned int uVar13;

  unsigned int uVar14;

  unsigned int uVar15;

  unsigned int uVar16;

  unsigned int uVar17;

  piVar10 = (int *)(0x0608A6B0 + 8);

  puVar11 = (unsigned int *)0x0608A6B0;

  FUN_06027358();

  puVar11[1] = -*piVar10;

  puVar7 = (int *)0x0608A52C;

  puVar11[3] = *puVar11;

  puVar9 = *(unsigned int **)puVar7;

  iVar8 = 3;

  do {

    uVar13 = *puVar9;

    uVar12 = *puVar11;

    uVar6 = uVar13 ^ uVar12;

    if ((int)uVar13 < 0) {

      uVar13 = -uVar13;

    }

    if ((int)uVar12 < 0) {

      uVar12 = -uVar12;

    }

    uVar3 = (uVar12 & 0xffff) * (uVar13 & 0xffff);

    iVar5 = (uVar12 >> 0x10) * (uVar13 & 0xffff);

    iVar2 = 0;

    uVar1 = iVar5 + (uVar12 & 0xffff) * (uVar13 >> 0x10);

    if (iVar5 != 0) {

      iVar2 = 0x10000;

    }

    uVar14 = uVar3 + (uVar1 << 16);

    uVar12 = iVar2 + (unsigned int)(uVar14 < uVar3) + (uVar1 >> 0x10) + (uVar12 >> 0x10) * (uVar13 >> 0x10);

    if ((int)-(unsigned int)((int)uVar6 < 0) < 0) {

      uVar12 = ~uVar12;

      if (uVar14 == 0) {

        uVar12 = uVar12 + 1;

      }

      else {

        uVar14 = ~uVar14 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      if ((int)uVar12 < -0x8000) {

        uVar12 = 0xffff8000;

        uVar14 = 0;

      }

      if (0x7fff < (int)uVar12) {

        uVar12 = 0x7fff;

        uVar14 = 0xffffffff;

      }

      uVar12 = uVar12 & 0xffff;

    }

    uVar6 = puVar9[1];

    uVar13 = puVar11[1];

    uVar1 = uVar6 ^ uVar13;

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    if ((int)uVar13 < 0) {

      uVar13 = -uVar13;

    }

    uVar16 = (uVar13 & 0xffff) * (uVar6 & 0xffff);

    iVar5 = (uVar13 >> 0x10) * (uVar6 & 0xffff);

    iVar2 = 0;

    uVar3 = iVar5 + (uVar13 & 0xffff) * (uVar6 >> 0x10);

    if (iVar5 != 0) {

      iVar2 = 0x10000;

    }

    uVar15 = uVar16 + (uVar3 << 16);

    uVar13 = iVar2 + (unsigned int)(uVar15 < uVar16) + (uVar3 >> 0x10) + (uVar13 >> 0x10) * (uVar6 >> 0x10);

    if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

      uVar13 = ~uVar13;

      if (uVar15 == 0) {

        uVar13 = uVar13 + 1;

      }

      else {

        uVar15 = ~uVar15 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      uVar15 = uVar14 + uVar15;

      uVar12 = uVar13 + (uVar15 < uVar14) + (uVar12 & 0xffff);

      if ((int)uVar12 < -0x8000) {

        uVar12 = 0xffff8000;

        uVar15 = 0;

      }

      if (0x7fff < (int)uVar12) {

        uVar12 = 0x7fff;

        uVar15 = 0xffffffff;

      }

      uVar12 = uVar12 & 0xffff;

    }

    else {

      uVar15 = uVar14 + uVar15;

      uVar12 = uVar13 + (uVar15 < uVar14) + uVar12;

    }

    uVar6 = *puVar9;

    uVar13 = puVar11[2];

    uVar1 = uVar6 ^ uVar13;

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    if ((int)uVar13 < 0) {

      uVar13 = -uVar13;

    }

    uVar14 = (uVar13 & 0xffff) * (uVar6 & 0xffff);

    iVar5 = (uVar13 >> 0x10) * (uVar6 & 0xffff);

    iVar2 = 0;

    uVar3 = iVar5 + (uVar13 & 0xffff) * (uVar6 >> 0x10);

    if (iVar5 != 0) {

      iVar2 = 0x10000;

    }

    uVar16 = uVar14 + (uVar3 << 16);

    uVar13 = iVar2 + (unsigned int)(uVar16 < uVar14) + (uVar3 >> 0x10) + (uVar13 >> 0x10) * (uVar6 >> 0x10);

    if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

      uVar13 = ~uVar13;

      if (uVar16 == 0) {

        uVar13 = uVar13 + 1;

      }

      else {

        uVar16 = ~uVar16 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      if ((int)uVar13 < -0x8000) {

        uVar13 = 0xffff8000;

        uVar16 = 0;

      }

      if (0x7fff < (int)uVar13) {

        uVar13 = 0x7fff;

        uVar16 = 0xffffffff;

      }

      uVar13 = uVar13 & 0xffff;

    }

    uVar1 = puVar9[1];

    uVar6 = puVar11[3];

    uVar3 = uVar1 ^ uVar6;

    if ((int)uVar1 < 0) {

      uVar1 = -uVar1;

    }

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    uVar4 = (uVar6 & 0xffff) * (uVar1 & 0xffff);

    iVar5 = (uVar6 >> 0x10) * (uVar1 & 0xffff);

    iVar2 = 0;

    uVar14 = iVar5 + (uVar6 & 0xffff) * (uVar1 >> 0x10);

    if (iVar5 != 0) {

      iVar2 = 0x10000;

    }

    uVar17 = uVar4 + (uVar14 << 16);

    uVar6 = iVar2 + (unsigned int)(uVar17 < uVar4) + (uVar14 >> 0x10) + (uVar6 >> 0x10) * (uVar1 >> 0x10);

    if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

      uVar6 = ~uVar6;

      if (uVar17 == 0) {

        uVar6 = uVar6 + 1;

      }

      else {

        uVar17 = ~uVar17 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      uVar17 = uVar16 + uVar17;

      uVar6 = uVar6 + (uVar17 < uVar16) + (uVar13 & 0xffff);

      if ((int)uVar6 < -0x8000) {

        uVar6 = 0xffff8000;

        uVar17 = 0;

      }

      if (0x7fff < (int)uVar6) {

        uVar6 = 0x7fff;

        uVar17 = 0xffffffff;

      }

      uVar13 = uVar6 & 0xffff | uVar13 & 0xffff0000;

    }

    else {

      uVar17 = uVar16 + uVar17;

      uVar13 = uVar6 + (uVar17 < uVar16) + uVar13;

    }

    *puVar9 = uVar12 << 0x10 | uVar15 >> 0x10;

    iVar8 = iVar8 + -1;

    in_sr = in_sr & 0xfffffffe;

    puVar9[1] = uVar13 << 0x10 | uVar17 >> 0x10;

    puVar9 = puVar9 + 3;

  } while (iVar8 != 0);

  return uVar13;

}

void FUN_06027358(param_1, param_2, param_3)
    int param_1;
    int *param_2;
    int *param_3;
{

  char *puVar1;

  unsigned int uVar2;

  int iVar3;

  puVar1 = (int *)0x002F2F20;

  iVar3 = 0x4000;

  uVar2 = 0x3FFC;

  *param_2 = *(int *)(0x002F2F20 + (param_1 + 8U >> 2 & uVar2));

  *param_3 = *(int *)(puVar1 + (iVar3 + param_1 + 8U >> 2 & uVar2));

  return;

}

void FUN_06027ca4(param_1, param_2)
    unsigned int *param_1;
    int param_2;
{

  short sVar1;

  unsigned int *puVar2;

  short uVar3;

  unsigned int *puVar4;

  short *psVar5;

  unsigned int uVar6;

  int iVar7;

  unsigned int uVar8;

  int iVar9;

  char *puVar10;

  puVar4 = (unsigned int *)(((unsigned int)(0x04000000 + *param_1) >> 0x15) +

                   (0x03FFFFFF - param_1[2] >> 0x15) << 6);

  if (CAR_COUNT == 2) {

    iVar9 = 0;

    psVar5 = (short *)0x06061270;

    while( 1 ) {

      sVar1 = *psVar5;

      psVar5 = psVar5 + 1;

      if ((unsigned int *)(int)sVar1 == (unsigned int *)0x0) break;

      if (puVar4 == (unsigned int *)(int)sVar1) {

        if (*(int *)(CAR_PTR_CURRENT + (int)DAT_06027d26) < 0x47) {

          sVar1 = *(short *)(0x06061240 + (iVar9 << 1));

          iVar9 = (int)*(short *)((int)(0x06061240 + (iVar9 << 1)) + 2);

          *(short *)0x06063F50 = sVar1;

          puVar10 = (char *)(int)sVar1;

          goto LAB_06027d36;

        }

        break;

      }

      iVar9 = iVar9 + 2;

    }

    iVar9 = 0;

    puVar10 = (char *)0x0607EAD8;

LAB_06027d36:

    if (iVar9 != 0) goto LAB_06027d50;

  }

  puVar10 = (char *)(unsigned int)*(unsigned short *)(0x060C2000 + (int)((int)(int)puVar4 << 2));

  iVar9 = (int)(short)*(unsigned short *)((int)(0x060C2000 + (int)((int)(int)puVar4 << 2)) + 2);

LAB_06027d50:

  do {

    if (iVar9 < 1) {

      uVar6 = 0;

      uVar8 = 0;

LAB_06027e6a:

      *(short *)(param_1 + 3) = (short)uVar6;

      if (uVar8 == 0) {

        iVar9 = CAR_PTR_CURRENT;

      }

      else {

        sVar1 = *(short *)(puVar4 + 0xc);

        param_1[4] = (int)sVar1;

        uVar3 = (*(int(*)())0x0602ECCC)();

        *(short *)((int)param_1 + 0xe) = uVar3;

        iVar9 = CAR_PTR_CURRENT;

        if (param_2 < 1) {

          *(int *)(DAT_06027e9a + iVar9) = (int)sVar1;

        }

      }

      *(unsigned int *)((unsigned int)*(unsigned short *)(0x0606128A + (param_2 << 1)) + iVar9) = uVar6;

      return;

    }

    puVar2 = (unsigned int *)(0x060A6000 + *(short *)(puVar10 + (int)0x060BF000) * 0x34);

    uVar6 = *puVar2;

    iVar7 = ((int)((unsigned long long)((long long)(int)*param_1 * (long long)(int)puVar2[4]) >> 0x20) << 0x10

            | (unsigned int)((long long)(int)*param_1 * (long long)(int)puVar2[4]) >> 0x10) + puVar2[5];

    if ((uVar6 & 0x1000000) == 0) {

      iVar7 = iVar7 + param_1[2];

    }

    if ((0x100 & uVar6) == 0) {

      if (iVar7 < 0) {

        puVar10 = puVar10 + 2;

        iVar9 = iVar9 + -1;

        goto LAB_06027d50;

      }

LAB_06027db6:

      iVar7 = ((int)((unsigned long long)((long long)(int)*param_1 * (long long)(int)puVar2[6]) >> 0x20) <<

               0x10 | (unsigned int)((long long)(int)*param_1 * (long long)(int)puVar2[6]) >> 0x10) +

              puVar2[7];

      if ((uVar6 & 0x2000000) == 0) {

        iVar7 = iVar7 + param_1[2];

      }

      puVar4 = param_1;

      if ((0x200 & uVar6) == 0) {

        if (iVar7 < 0) {

          puVar10 = puVar10 + 2;

          iVar9 = iVar9 + -1;

          goto LAB_06027d50;

        }

      }

      else if (0 < iVar7) {

        puVar10 = puVar10 + 2;

        iVar9 = iVar9 + -1;

        goto LAB_06027d50;

      }

      iVar7 = ((int)((unsigned long long)((long long)(int)*param_1 * (long long)(int)puVar2[8]) >> 0x20) <<

               0x10 | (unsigned int)((long long)(int)*param_1 * (long long)(int)puVar2[8]) >> 0x10) +

              puVar2[9];

      if ((uVar6 & 0x4000000) == 0) {

        iVar7 = iVar7 + param_1[2];

      }

      if ((0x400 & uVar6) == 0) {

        if (iVar7 < 0) {

          puVar10 = puVar10 + 2;

          iVar9 = iVar9 + -1;

          goto LAB_06027d50;

        }

      }

      else if (0 < iVar7) {

        puVar10 = puVar10 + 2;

        iVar9 = iVar9 + -1;

        goto LAB_06027d50;

      }

      iVar7 = ((int)((unsigned long long)((long long)(int)*param_1 * (long long)(int)puVar2[10]) >> 0x20) <<

               0x10 | (unsigned int)((long long)(int)*param_1 * (long long)(int)puVar2[10]) >> 0x10) +

              puVar2[0xb];

      if ((uVar6 & 0x8000000) == 0) {

        iVar7 = iVar7 + param_1[2];

      }

      if ((0x00000800 & uVar6) == 0) {

        if (iVar7 < 0) {

          puVar10 = puVar10 + 2;

          iVar9 = iVar9 + -1;

          goto LAB_06027d50;

        }

      }

      else if (0 < iVar7) {

        puVar10 = puVar10 + 2;

        iVar9 = iVar9 + -1;

        goto LAB_06027d50;

      }

      puVar4 = (unsigned int *)(0x060A6000 + *(short *)(puVar10 + (int)0x060BF000) * 0x34);

      uVar8 = (unsigned int)DAT_06027e98;

      uVar6 = *puVar4 & uVar8;

      goto LAB_06027e6a;

    }

    if (iVar7 < 1) goto LAB_06027db6;

    puVar10 = puVar10 + 2;

    iVar9 = iVar9 + -1;

  } while( 1 );

}

unsigned int FUN_06027ede(param_1, param_2, param_3)
    int param_1;
    int *param_2;
    short *param_3;
{

  short sVar1;

  long long lVar2;

  long long lVar3;

  char *puVar4;

  char *puVar5;

  unsigned int uVar6;

  short *psVar7;

  int iVar8;

  unsigned int uVar9;

  unsigned int *puVar10;

  int iVar11;

  unsigned int uVar12;

  int iVar13;

  int iVar14;

  int iVar15;

  puVar5 = (int *)0x060BF000;

  puVar4 = (char *)0x060C2000;

  iVar15 = *param_2;

  iVar14 = param_2[2];

  if (CAR_COUNT == 2) {

    iVar11 = 0;

    psVar7 = (short *)0x06061270;

    while( 1 ) {

      sVar1 = *psVar7;

      psVar7 = psVar7 + 1;

      if (sVar1 == 0) break;

      if (param_1 == sVar1) {

        if (*(int *)(CAR_PTR_CURRENT + (int)DAT_06027f56) < 0x47) {

          iVar13 = (int)*(short *)((int)(0x06061240 + (iVar11 << 1)) + 2);

          *(short *)0x06063F50 = *(short *)(0x06061240 + (iVar11 << 1));

          goto LAB_06027f66;

        }

        break;

      }

      iVar11 = iVar11 + 2;

    }

    iVar13 = 0;

LAB_06027f66:

    if (iVar13 == 0) {

      iVar13 = (int)*(short *)(puVar4 + (((param_1 << 1) + 1) << 1));

      uVar12 = (unsigned int)(int)*(short *)(puVar4 + (param_1 << 2)) >> 1;

    }

    else {

      uVar12 = (unsigned int)(int)*(short *)0x06063F50 >> 1;

    }

  }

  else {

    iVar13 = (int)*(short *)(0x060C2000 + ((param_1 << 1) + 1) << 1);

    uVar12 = (unsigned int)(int)*(short *)(0x060C2000 + (param_1 << 2)) >> 1;

  }

  iVar11 = 0;

  do {

    puVar10 = (unsigned int *)(0x060A6000 +

                      (unsigned int)*(unsigned short *)(puVar5 + (uVar12 << 1)) * (0x00000034 & 0xffff));

    uVar9 = *puVar10;

    iVar8 = ((int)((unsigned long long)((long long)(int)puVar10[4] * (long long)iVar15) >> 0x20) << 0x10 |

            (unsigned int)((long long)(int)puVar10[4] * (long long)iVar15) >> 0x10) + puVar10[5];

    if ((uVar9 & (unsigned int)0x01000000) == 0) {

      iVar8 = iVar8 + iVar14;

    }

    uVar6 = (unsigned int)PTR_DAT_06027fc0;

    if ((uVar6 & uVar9) != 0) {

      iVar8 = -iVar8;

    }

    if (-1 < iVar8) {

      iVar8 = ((int)((unsigned long long)((long long)(int)puVar10[6] * (long long)iVar15) >> 0x20) << 0x10 |

              (unsigned int)((long long)(int)puVar10[6] * (long long)iVar15) >> 0x10) + puVar10[7];

      if (((unsigned int)0x02000000 & uVar9) == 0) {

        iVar8 = iVar8 + iVar14;

      }

      uVar6 = (unsigned int)PTR_DAT_06027ffc;

      if ((uVar6 & uVar9) != 0) {

        iVar8 = -iVar8;

      }

      if (-1 < iVar8) {

        iVar8 = ((int)((unsigned long long)((long long)(int)puVar10[8] * (long long)iVar15) >> 0x20) << 0x10 |

                (unsigned int)((long long)(int)puVar10[8] * (long long)iVar15) >> 0x10) + puVar10[9];

        if (((unsigned int)0x04000000 & uVar9) == 0) {

          iVar8 = iVar8 + iVar14;

        }

        uVar6 = (unsigned int)PTR_DAT_0602802c;

        if ((uVar6 & uVar9) != 0) {

          iVar8 = -iVar8;

        }

        if (-1 < iVar8) {

          iVar8 = ((int)((unsigned long long)((long long)(int)puVar10[10] * (long long)iVar15) >> 0x20) << 0x10

                  | (unsigned int)((long long)(int)puVar10[10] * (long long)iVar15) >> 0x10) + puVar10[0xb];

          if ((0x08000000 & uVar9) == 0) {

            iVar8 = iVar8 + iVar14;

          }

          uVar6 = (unsigned int)DAT_0602805c;

          if ((uVar6 & uVar9) != 0) {

            iVar8 = -iVar8;

          }

          if (-1 < iVar8) break;

        }

      }

    }

    iVar11 = iVar11 + 1;

    uVar12 = uVar12 + 1;

  } while (iVar11 < iVar13);

  if ((param_3 != (short *)0x0) && (iVar13 != iVar11)) {

    lVar2 = (long long)*(int *)((int)puVar10 + 0x00000004) * (long long)iVar15;

    lVar3 = (long long)*(int *)((int)puVar10 + 0x00000008) * (long long)iVar14;

    param_2[1] = ((int)((unsigned long long)lVar2 >> 0x20) << 0x10 | (unsigned int)lVar2 >> 0x10) +

                 ((int)((unsigned long long)lVar3 >> 0x20) << 0x10 | (unsigned int)lVar3 >> 0x10) +

                 *(int *)((int)puVar10 + 0x0000000C);

    uVar6 = (uVar12 << 1);

    *param_3 = *(short *)(puVar5 + uVar6);

  }

  return uVar6;

}
