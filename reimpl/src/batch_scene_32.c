#include "game.h"

extern char flag_060322fc;
extern int DAT_06031e30;
extern int DAT_06031eee;
extern int DAT_06031fc4;
extern int DAT_06032048;
extern int DAT_0603204a;
extern int DAT_06032102;
extern int DAT_06032104;
extern int DAT_06032106;
extern int FUN_060322e8();
extern int FUN_06032304();
extern char * FUN_0603253c();
extern int FUN_06032584();
extern int FUN_0603268c();
extern void FUN_06032d90();
extern void FUN_06032e18();
extern int FUN_06032e6c();
extern unsigned int FUN_06032ea4();
extern int FUN_0603307c();
extern int FUN_060330a0();
extern int FUN_0603316c();
extern long long FUN_06033188();
extern long long FUN_0603320c();
extern long long FUN_06033278();
extern int FUN_06033330();
extern int FUN_06033470();
extern int FUN_06033504();
extern void FUN_06033520();
extern int FUN_06033550();
extern int FUN_060335f4();
extern int FUN_06033648();
extern int FUN_060336c8();
extern int FUN_060336f2();
extern int FUN_06033700();
extern void FUN_060337fc();
extern int FUN_06033f54();
extern int FUN_06034000();
extern int FUN_06034168();
extern int FUN_0603449c();
extern int FUN_06034560();
extern int FUN_0603458c();
extern int FUN_06034640();
extern int FUN_060346c0();
extern int PTR_DAT_06031ea8;
extern int PTR_DAT_06031f30;
extern int PTR_DAT_06031f74;
extern int PTR_DAT_0603204c;
extern int PTR_DAT_06033344;
extern int PTR_DAT_060333b0;
extern int counter_06032300;

unsigned int FUN_060320e6()
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

  uVar2 = (unsigned int)DAT_06032102;

  uVar16 = in_sr & 0xfffffffe;

  uVar18 = uVar16 | (int)uVar2 < in_r1;

  if (((unsigned char)uVar18 & 1) != 1) {

    uVar2 = (unsigned int)DAT_06032104;

    uVar18 = uVar16 | in_r1 < (int)uVar2;

    if (((unsigned char)uVar18 & 1) != 1) {

      uVar2 = (unsigned int)DAT_06032106;

      uVar18 = uVar16 | (int)uVar2 < in_r2;

      if (((unsigned char)uVar18 & 1) != 1) {

        uVar2 = (unsigned int)DAT_06032104;

        uVar18 = uVar16 | in_r2 < (int)uVar2;

        if (((unsigned char)uVar18 & 1) != 1) {

          return uVar2;

        }

      }

    }

  }

LAB_060320be:

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

    puVar15 = (unsigned int *)(int)DAT_06031e30;

    puVar10 = (unsigned int *)(0x060961A8 + (unsigned int)*(unsigned short *)(puVar13 + -2) * 0xc);

    uVar6 = puVar10[2];

    uVar18 = uVar16 | 0 < (int)uVar6;

  } while (((unsigned char)uVar18 & 1) != 1);

  puVar15[4] = (int)PTR_DAT_06031ea8;

  *puVar15 = uVar6;

  puVar15[5] = 0;

  *unaff_r13 = uVar6;

  puVar1 = (char *)0x06032138;

  if ((puVar13[-3] & 0x80000) == 0) {

    puVar14 = *(unsigned int **)0x0608A52C;

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

    *(unsigned int *)0x06032138 = uVar18 << 0x10 | uVar9 >> 0x10;

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

    if (((unsigned char)uVar16 & 1) != 1) goto LAB_060320be;

  }

  uVar2 = puVar10[1];

  uVar18 = *puVar10;

  uVar6 = puVar15[7];

  piVar11 = (int *)(0x060961A8 + (unsigned int)*(unsigned short *)((int)puVar13 + -6) * 0xc);

  uVar7 = piVar11[2];

  puVar15[4] = (int)DAT_06031eee;

  *puVar15 = uVar7;

  puVar15[5] = 0;

  *unaff_r11 = (unsigned int)((unsigned long long)((long long)(int)uVar6 * (long long)(int)uVar18) >> 0x20);

  unaff_r11[1] = (unsigned int)((unsigned long long)((long long)(int)uVar6 * (long long)(int)-uVar2) >> 0x20);

  puVar10 = unaff_r11;

  uVar2 = FUN_060320e6();

  uVar18 = uVar16 & 0xfffffffe | (unsigned int)(0 < (int)extraout_r3);

  if (((unsigned char)uVar18 & 1) == 1) {

    unaff_r13[1] = extraout_r3;

    puVar14 = puVar10 + 2;

    iVar5 = piVar11[1];

    iVar3 = *piVar11;

    uVar2 = puVar15[7];

    piVar11 = (int *)(0x060961A8 + (unsigned int)*(unsigned short *)(puVar13 + -1) * 0xc);

    uVar16 = piVar11[2];

    puVar15[4] = (int)PTR_DAT_06031f30;

    *puVar15 = uVar16;

    puVar15[5] = 0;

    *puVar14 = (unsigned int)((unsigned long long)((long long)(int)uVar2 * (long long)iVar3) >> 0x20);

    puVar10[3] = (unsigned int)((unsigned long long)((long long)(int)uVar2 * (long long)-iVar5) >> 0x20);

    uVar2 = FUN_060320e6();

    uVar18 = uVar18 & 0xfffffffe | (unsigned int)(0 < (int)extraout_r3_00);

    if (((unsigned char)uVar18 & 1) == 1) {

      unaff_r13[2] = extraout_r3_00;

      puVar10 = puVar14 + 2;

      iVar5 = piVar11[1];

      iVar3 = *piVar11;

      uVar2 = puVar15[7];

      piVar11 = (int *)(0x060961A8 + (unsigned int)*(unsigned short *)((int)puVar13 + -2) * 0xc);

      uVar16 = piVar11[2];

      puVar15[4] = (int)PTR_DAT_06031f74;

      *puVar15 = uVar16;

      puVar15[5] = 0;

      *puVar10 = (unsigned int)((unsigned long long)((long long)(int)uVar2 * (long long)iVar3) >> 0x20);

      puVar14[3] = (unsigned int)((unsigned long long)((long long)(int)uVar2 * (long long)-iVar5) >> 0x20);

      uVar2 = FUN_060320e6();

      uVar18 = uVar18 & 0xfffffffe | (unsigned int)(0 < (int)extraout_r3_01);

      if (((unsigned char)uVar18 & 1) == 1) {

        unaff_r13[3] = extraout_r3_01;

        iVar3 = piVar11[1];

        uVar16 = puVar15[7];

        puVar10[2] = (unsigned int)((unsigned long long)((long long)(int)uVar16 * (long long)*piVar11) >> 0x20);

        puVar10[3] = (unsigned int)((unsigned long long)((long long)(int)uVar16 * (long long)-iVar3) >> 0x20);

        FUN_060320e6();

        puVar1 = (char *)0x0608AC20;

        iVar3 = *(int *)0x060620D4;

        iVar5 = (int)DAT_06031fc4;

        uVar2 = *unaff_r11;

        uVar16 = unaff_r11[2];

        uVar7 = unaff_r11[4];

        uVar6 = unaff_r11[6];

        uVar18 = uVar18 & 0xfffffffe;

        if ((((iVar5 <= (int)uVar2) || (iVar5 <= (int)uVar16)) || (iVar5 <= (int)uVar7)) ||

           (iVar5 <= (int)uVar6)) {

          iVar5 = (int)DAT_06032048;

          uVar17 = uVar18 | (int)uVar2 < iVar5;

          if (((((unsigned char)uVar17 & 1) == 1) ||

              (uVar17 = uVar18 | (int)uVar16 < iVar5, ((unsigned char)uVar17 & 1) == 1)) ||

             ((uVar17 = uVar18 | (int)uVar7 < iVar5, ((unsigned char)uVar17 & 1) == 1 ||

              (uVar17 = uVar18 | (int)uVar6 < iVar5, uVar18 = uVar17, ((unsigned char)uVar17 & 1) != 1)))) {

            iVar5 = (int)DAT_0603204a;

            uVar4 = unaff_r11[1];

            uVar8 = unaff_r11[3];

            uVar9 = unaff_r11[5];

            uVar12 = unaff_r11[7];

            uVar18 = uVar17 & 0xfffffffe;

            if (((iVar5 <= (int)uVar4) || (iVar5 <= (int)uVar8)) ||

               ((iVar5 <= (int)uVar9 ||

                (uVar18 = uVar18 | (int)uVar12 < iVar5, ((unsigned char)uVar18 & 1) != 1)))) {

              iVar5 = (int)PTR_DAT_0603204c;

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

                uVar18 = (*(int(*)())(*(int *)(0x06032144 + ((int)*(short *)(puVar13 + -3) & 7U) << 2)))(unaff_r13[1],unaff_r13[2],unaff_r13[3]);

                return uVar18;

              }

            }

          }

        }

      }

    }

  }

  goto LAB_060320be;

}

void FUN_06032158(param_1, param_2)
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

  puVar7 = (unsigned int *)OBJ_STATE_SECONDARY;

  piVar6 = (int *)0x060961A8;

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

char * FUN_060321c0()
{

  char uVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  int iVar5;

  int iVar6;

  iVar5 = 0;

  do {

    iVar6 = *(int *)(0x060623B0 + (iVar5 << 2));

    *(char *)(iVar6 + 0x000002DC) = (char)iVar5;

    FUN_06032d90();

    *(short *)(iVar6 + 0x0000000E) = (short)0x00000004;

    FUN_06032e18(0x00000000);

    puVar4 = *(char **)(0x06062464 + (iVar5 << 2));

    puVar3 = (char *)(0x000002DE + iVar6);

    iVar6 = 0x0000000D;

    do {

      uVar1 = *puVar4;

      puVar4 = puVar4 + 1;

      *puVar3 = uVar1;

      puVar3 = puVar3 + 1;

      iVar6 = iVar6 + -1;

    } while (iVar6 != 0);

    iVar5 = iVar5 + 1;

  } while (iVar5 <= 0x00000005);

  *(int *)0x06082A20 = 0;

  *(int *)0x06082A24 = 0;

  puVar2 = (int *)0x06082A25;

  *(int *)0x06082A25 = 0;

  return puVar2;

}

/* scene_update_all_layers -- Update all 6 scene layers, then advance frame counter.
 * Calls FUN_06032304 for layers 0-5, then scene_frame_counter. */
int FUN_0603226c(void)
{
    FUN_06032304(0);
    FUN_06032304(1);
    FUN_06032304(2);
    FUN_06032304(3);
    FUN_06032304(4);
    FUN_06032304(5);

    return FUN_060322e8();
}

/* scene_frame_counter -- Increment scene frame counter when scene is active */
int FUN_060322e8(void)
{
    if (flag_060322fc != 0) {
        counter_06032300++;
    }
}

/* scene_layer_update -- Update a single scene layer by index.
 * Reads layer state from table at 0x060623B0[param_1].
 * If command queue head matches current frame (0x06082A20):
 *   advance queue pointer (+0x2D8) by 3 ints, dispatch via jump table.
 * If layer flag (+0x2DC) == 0: full init (palette + geometry + transform).
 * If layer flag has bit 2: init + return after geometry commit.
 * Otherwise: commit geometry + finalize. */
int FUN_06032304(int param_1)
{
  int uVar1;
  int *piVar2;
  int iVar3;
  int iVar4 = *(int *)(0x060623B0 + (param_1 << 2));

  piVar2 = *(int **)(iVar4 + 0x000002D8);   /* command queue head */
  iVar3 = piVar2[1];                          /* command type */

  if (*piVar2 == *(int *)0x06082A20) {
    *(int **)(iVar4 + 0x000002D8) = piVar2 + 3;  /* advance queue */
    uVar1 = (*(int(*)())(*(int *)(0x06032334 + (iVar3 << 2))))();
    return uVar1;
  }

  if (*(unsigned char *)(iVar4 + 0x000002DC) == 0) {
    FUN_06032e6c();              /* palette setup */
    FUN_0603253c();              /* geometry setup */
    FUN_0603268c();              /* transform setup */
  } else if ((*(unsigned char *)(iVar4 + 0x000002DC) & 4) != 0) {
    FUN_06032e6c();
    FUN_0603253c();
    FUN_0603268c();
    uVar1 = FUN_06032584();      /* geometry commit */
    return uVar1;
  }

  FUN_06032584();
  uVar1 = FUN_06032ea4();        /* finalize */
  return uVar1;
}

char * FUN_0603253c()
{

  char *puVar1;

  unsigned int uVar2;

  int unaff_r14 = 0;

  if (*(int *)0x06082A24 == '\0') {

    return 0x06082A24;

  }

  uVar2 = 0x00000001;

  if ((0x00000002 & (int)*(short *)(unaff_r14 + 0x0000000E)) != 0) {

    uVar2 = 0xFFFFFFFF;

  }

  if ((0x00000001 & (int)*(short *)(unaff_r14 + 0x0000000E)) != 0) {

    uVar2 = 0x00000000;

  }

  puVar1 = (char *)0x000002C4;

  *(unsigned int *)(0x000002C4 + unaff_r14) = *(int *)(0x000002C4 + unaff_r14) + uVar2;

  return puVar1;

}

int FUN_06032584()
{

  char *puVar1;

  int uVar2;

  int iVar3;

  int iVar4;

  char *unaff_r14;

  (*(int(*)())0x06026DBC)();

  (*(int(*)())0x06026E2E)(*(int *)(unaff_r14 + 0x00000000),*(int *)(unaff_r14 + 0x00000004),

             *(int *)(unaff_r14 + 0x00000008));

  (*(int(*)())0x06026EDE)((int)*(short *)(unaff_r14 + 0x0000000C));

  puVar1 = unaff_r14;

  if (((unsigned int)0xFFFFFFFC & (int)(char)unaff_r14[0x000002DC]) == 0) {

    puVar1 = (char *)0x06081898;

  }

  *(char **)(unaff_r14 + 0x000002D4) = puVar1 + 0x00000054;

  iVar4 = 0x0000000D;

  do {

    iVar3 = iVar4;

    (*(int(*)())0x06026DBC)();

    (*(int(*)())0x06026F72)(*(int *)(unaff_r14 + 0x000002D4));

    (*(int(*)())0x0600A474)((int)(char)unaff_r14[(0x0000000D - iVar3) + 0x000002DE]);

    *(int *)(unaff_r14 + 0x000002D4) = *(int *)(unaff_r14 + 0x000002D4) + 0x00000030;

    (*(int(*)())0x06026DF8)();

    iVar4 = iVar4 + -1;

  } while (iVar4 != 0);

  uVar2 = (*(int(*)())0x06026DF8)();

  return uVar2;

}

int FUN_0603268c()
{

  char *puVar1;

  int *puVar2;

  int uVar3;

  int in_r7 = 0;

  int *puVar4;

  int unaff_r14 = 0;

  int in_pr;

  puVar1 = (char *)0x060623C8;

  (*(int(*)())0x06026DBC)();

  (*(int(*)())0x06026E0C)();

  puVar4 = *(int **)0x06089EDC;

  (*(int(*)())0x06026E2E)(*(int *)(unaff_r14 + 0x00000010),*(int *)(unaff_r14 + 0x00000014),

             *(int *)(unaff_r14 + 0x00000018),in_r7,in_pr);

  (*(int(*)())0x06026EDE)((int)*(short *)(unaff_r14 + 0x0000001E));

  (*(int(*)())0x06026E94)((int)*(short *)(unaff_r14 + 0x0000001C));

  (*(int(*)())0x06026F2A)((int)*(short *)(unaff_r14 + 0x00000020));

  puVar2 = (int *)(0x00000054 + unaff_r14);

  *puVar2 = *puVar4;

  puVar2[1] = puVar4[1];

  puVar2[2] = puVar4[2];

  puVar2[3] = puVar4[3];

  puVar2[4] = puVar4[4];

  puVar2[5] = puVar4[5];

  puVar2[6] = puVar4[6];

  puVar2[7] = puVar4[7];

  puVar2[8] = puVar4[8];

  puVar2[9] = puVar4[9];

  puVar2[10] = puVar4[10];

  puVar2[0xb] = puVar4[0xb];

  (*(int(*)())0x06026DBC)();

  puVar4 = *(int **)0x06089EDC;

  puVar2 = (int *)(puVar1 + 0x0000000C);

  (*(int(*)())0x06026E2E)(*puVar2,puVar2[1],puVar2[2],in_r7,in_pr);

  (*(int(*)())0x06026E94)((int)*(short *)(unaff_r14 + 0x00000022));

  (*(int(*)())0x06026F2A)((int)*(short *)(unaff_r14 + 0x00000026));

  (*(int(*)())0x06026EDE)((int)*(short *)(unaff_r14 + 0x00000024));

  puVar2 = (int *)(0x00000084 + unaff_r14);

  *puVar2 = *puVar4;

  puVar2[1] = puVar4[1];

  puVar2[2] = puVar4[2];

  puVar2[3] = puVar4[3];

  puVar2[4] = puVar4[4];

  puVar2[5] = puVar4[5];

  puVar2[6] = puVar4[6];

  puVar2[7] = puVar4[7];

  puVar2[8] = puVar4[8];

  puVar2[9] = puVar4[9];

  puVar2[10] = puVar4[10];

  puVar2[0xb] = puVar4[0xb];

  (*(int(*)())0x06026DBC)();

  puVar4 = *(int **)0x06089EDC;

  puVar2 = (int *)(puVar1 + 0x00000018);

  (*(int(*)())0x06026E2E)(*puVar2,puVar2[1],puVar2[2],in_r7,in_pr);

  (*(int(*)())0x06026E94)((int)*(short *)(unaff_r14 + 0x00000028));

  (*(int(*)())0x06026F2A)((int)*(short *)(unaff_r14 + 0x0000002C));

  (*(int(*)())0x06026EDE)((int)*(short *)(unaff_r14 + 0x0000002A));

  puVar2 = (int *)(0x000000B4 + unaff_r14);

  *puVar2 = *puVar4;

  puVar2[1] = puVar4[1];

  puVar2[2] = puVar4[2];

  puVar2[3] = puVar4[3];

  puVar2[4] = puVar4[4];

  puVar2[5] = puVar4[5];

  puVar2[6] = puVar4[6];

  puVar2[7] = puVar4[7];

  puVar2[8] = puVar4[8];

  puVar2[9] = puVar4[9];

  puVar2[10] = puVar4[10];

  puVar2[0xb] = puVar4[0xb];

  puVar2 = (int *)(puVar1 + 0x00000024);

  (*(int(*)())0x06026E2E)(*puVar2,puVar2[1],puVar2[2],in_r7,in_pr);

  (*(int(*)())0x06026F2A)((int)*(short *)(unaff_r14 + 0x0000002E));

  puVar2 = (int *)(0x000000E4 + unaff_r14);

  *puVar2 = *puVar4;

  puVar2[1] = puVar4[1];

  puVar2[2] = puVar4[2];

  puVar2[3] = puVar4[3];

  puVar2[4] = puVar4[4];

  puVar2[5] = puVar4[5];

  puVar2[6] = puVar4[6];

  puVar2[7] = puVar4[7];

  puVar2[8] = puVar4[8];

  puVar2[9] = puVar4[9];

  puVar2[10] = puVar4[10];

  puVar2[0xb] = puVar4[0xb];

  puVar2 = (int *)(puVar1 + 0x00000030);

  (*(int(*)())0x06026E2E)(*puVar2,puVar2[1],puVar2[2],in_r7,in_pr);

  (*(int(*)())0x06026F2A)((int)*(short *)(unaff_r14 + 0x00000030));

  puVar2 = (int *)(0x00000114 + unaff_r14);

  *puVar2 = *puVar4;

  puVar2[1] = puVar4[1];

  puVar2[2] = puVar4[2];

  puVar2[3] = puVar4[3];

  puVar2[4] = puVar4[4];

  puVar2[5] = puVar4[5];

  puVar2[6] = puVar4[6];

  puVar2[7] = puVar4[7];

  puVar2[8] = puVar4[8];

  puVar2[9] = puVar4[9];

  puVar2[10] = puVar4[10];

  puVar2[0xb] = puVar4[0xb];

  (*(int(*)())0x06026DF8)();

  puVar4 = *(int **)0x06089EDC;

  puVar2 = (int *)(puVar1 + 0x0000003C);

  (*(int(*)())0x06026E2E)(*puVar2,puVar2[1],puVar2[2],in_r7,in_pr);

  (*(int(*)())0x06026E94)((int)*(short *)(unaff_r14 + 0x00000032));

  (*(int(*)())0x06026F2A)((int)*(short *)(unaff_r14 + 0x00000036));

  (*(int(*)())0x06026EDE)((int)*(short *)(unaff_r14 + 0x00000034));

  puVar2 = (int *)(0x00000144 + unaff_r14);

  *puVar2 = *puVar4;

  puVar2[1] = puVar4[1];

  puVar2[2] = puVar4[2];

  puVar2[3] = puVar4[3];

  puVar2[4] = puVar4[4];

  puVar2[5] = puVar4[5];

  puVar2[6] = puVar4[6];

  puVar2[7] = puVar4[7];

  puVar2[8] = puVar4[8];

  puVar2[9] = puVar4[9];

  puVar2[10] = puVar4[10];

  puVar2[0xb] = puVar4[0xb];

  puVar2 = (int *)(puVar1 + 0x00000048);

  (*(int(*)())0x06026E2E)(*puVar2,puVar2[1],puVar2[2],in_r7,in_pr);

  (*(int(*)())0x06026F2A)((int)*(short *)(unaff_r14 + 0x00000038));

  puVar2 = (int *)(0x00000174 + unaff_r14);

  *puVar2 = *puVar4;

  puVar2[1] = puVar4[1];

  puVar2[2] = puVar4[2];

  puVar2[3] = puVar4[3];

  puVar2[4] = puVar4[4];

  puVar2[5] = puVar4[5];

  puVar2[6] = puVar4[6];

  puVar2[7] = puVar4[7];

  puVar2[8] = puVar4[8];

  puVar2[9] = puVar4[9];

  puVar2[10] = puVar4[10];

  puVar2[0xb] = puVar4[0xb];

  puVar2 = (int *)(puVar1 + 0x00000054);

  (*(int(*)())0x06026E2E)(*puVar2,puVar2[1],puVar2[2],in_r7,in_pr);

  (*(int(*)())0x06026F2A)((int)*(short *)(unaff_r14 + 0x0000003A));

  puVar2 = (int *)(0x000001A4 + unaff_r14);

  *puVar2 = *puVar4;

  puVar2[1] = puVar4[1];

  puVar2[2] = puVar4[2];

  puVar2[3] = puVar4[3];

  puVar2[4] = puVar4[4];

  puVar2[5] = puVar4[5];

  puVar2[6] = puVar4[6];

  puVar2[7] = puVar4[7];

  puVar2[8] = puVar4[8];

  puVar2[9] = puVar4[9];

  puVar2[10] = puVar4[10];

  puVar2[0xb] = puVar4[0xb];

  (*(int(*)())0x06026DF8)();

  puVar4 = *(int **)0x06089EDC;

  puVar2 = (int *)(puVar1 + 0x00000060);

  (*(int(*)())0x06026E2E)(*puVar2,puVar2[1],puVar2[2],in_r7,in_pr);

  (*(int(*)())0x06026E94)((int)*(short *)(unaff_r14 + 0x0000003C));

  (*(int(*)())0x06026F2A)((int)*(short *)(unaff_r14 + 0x00000040));

  (*(int(*)())0x06026EDE)((int)*(short *)(unaff_r14 + 0x0000003E));

  puVar2 = (int *)(0x000001D4 + unaff_r14);

  *puVar2 = *puVar4;

  puVar2[1] = puVar4[1];

  puVar2[2] = puVar4[2];

  puVar2[3] = puVar4[3];

  puVar2[4] = puVar4[4];

  puVar2[5] = puVar4[5];

  puVar2[6] = puVar4[6];

  puVar2[7] = puVar4[7];

  puVar2[8] = puVar4[8];

  puVar2[9] = puVar4[9];

  puVar2[10] = puVar4[10];

  puVar2[0xb] = puVar4[0xb];

  (*(int(*)())0x06026DBC)();

  puVar4 = *(int **)0x06089EDC;

  puVar2 = (int *)(puVar1 + 0x0000006C);

  (*(int(*)())0x06026E2E)(*puVar2,puVar2[1],puVar2[2],in_r7,in_pr);

  (*(int(*)())0x06026E94)((int)*(short *)(unaff_r14 + 0x00000042));

  (*(int(*)())0x06026F2A)((int)*(short *)(unaff_r14 + 0x00000046));

  (*(int(*)())0x06026EDE)((int)*(short *)(unaff_r14 + 0x00000044));

  puVar2 = (int *)(0x00000204 + unaff_r14);

  *puVar2 = *puVar4;

  puVar2[1] = puVar4[1];

  puVar2[2] = puVar4[2];

  puVar2[3] = puVar4[3];

  puVar2[4] = puVar4[4];

  puVar2[5] = puVar4[5];

  puVar2[6] = puVar4[6];

  puVar2[7] = puVar4[7];

  puVar2[8] = puVar4[8];

  puVar2[9] = puVar4[9];

  puVar2[10] = puVar4[10];

  puVar2[0xb] = puVar4[0xb];

  puVar2 = (int *)(puVar1 + 0x00000078);

  (*(int(*)())0x06026E2E)(*puVar2,puVar2[1],puVar2[2],in_r7,in_pr);

  (*(int(*)())0x06026F2A)((int)*(short *)(unaff_r14 + 0x00000048));

  puVar2 = (int *)(0x00000234 + unaff_r14);

  *puVar2 = *puVar4;

  puVar2[1] = puVar4[1];

  puVar2[2] = puVar4[2];

  puVar2[3] = puVar4[3];

  puVar2[4] = puVar4[4];

  puVar2[5] = puVar4[5];

  puVar2[6] = puVar4[6];

  puVar2[7] = puVar4[7];

  puVar2[8] = puVar4[8];

  puVar2[9] = puVar4[9];

  puVar2[10] = puVar4[10];

  puVar2[0xb] = puVar4[0xb];

  (*(int(*)())0x06026DF8)();

  puVar4 = *(int **)0x06089EDC;

  puVar2 = (int *)(puVar1 + 0x00000084);

  (*(int(*)())0x06026E2E)(*puVar2,puVar2[1],puVar2[2],in_r7,in_pr);

  (*(int(*)())0x06026E94)((int)*(short *)(unaff_r14 + 0x0000004A));

  (*(int(*)())0x06026F2A)((int)*(short *)(unaff_r14 + 0x0000004E));

  (*(int(*)())0x06026EDE)((int)*(short *)(unaff_r14 + 0x0000004C));

  puVar2 = (int *)(0x00000264 + unaff_r14);

  *puVar2 = *puVar4;

  puVar2[1] = puVar4[1];

  puVar2[2] = puVar4[2];

  puVar2[3] = puVar4[3];

  puVar2[4] = puVar4[4];

  puVar2[5] = puVar4[5];

  puVar2[6] = puVar4[6];

  puVar2[7] = puVar4[7];

  puVar2[8] = puVar4[8];

  puVar2[9] = puVar4[9];

  puVar2[10] = puVar4[10];

  puVar2[0xb] = puVar4[0xb];

  puVar2 = (int *)(puVar1 + 0x00000090);

  (*(int(*)())0x06026E2E)(*puVar2,puVar2[1],puVar2[2],in_r7,in_pr);

  (*(int(*)())0x06026F2A)((int)*(short *)(unaff_r14 + 0x00000050));

  puVar2 = (int *)(0x00000294 + unaff_r14);

  *puVar2 = *puVar4;

  puVar2[1] = puVar4[1];

  puVar2[2] = puVar4[2];

  puVar2[3] = puVar4[3];

  puVar2[4] = puVar4[4];

  puVar2[5] = puVar4[5];

  puVar2[6] = puVar4[6];

  puVar2[7] = puVar4[7];

  puVar2[8] = puVar4[8];

  puVar2[9] = puVar4[9];

  puVar2[10] = puVar4[10];

  puVar2[0xb] = puVar4[0xb];

  uVar3 = (*(int(*)())0x06026DF8)();

  return uVar3;

}

void FUN_06032d90()
{

  int *piVar1;

  int *piVar2;

  int unaff_r14 = 0;

  piVar2 = (int *)(0x060624A4 + (0x0000000C & 0xffff) * (CAR_COUNT & 0xffff)

                  );

  piVar1 = (int *)(*(int *)(0x060624F8 + *(int *)(0x0607EAD8 << 2)) +

                  *(char *)(unaff_r14 + 0x000002DC) << 4);

  *(int *)(unaff_r14 + 0x00000000) = *piVar1 + *piVar2;

  *(int *)(unaff_r14 + 0x00000004) = piVar1[1] + piVar2[1];

  *(int *)(unaff_r14 + 0x00000008) = piVar1[2] + piVar2[2];

  *(short *)(unaff_r14 + 0x0000000C) = *(short *)(piVar1 + 3);

  *(char *)(unaff_r14 + 0x000002DD) = *(char *)((int)piVar1 + 0xe);

  *(int *)(unaff_r14 + 0x000002D8) =

       *(int *)(0x06062624 + *(char *)(unaff_r14 + 0x000002DD) << 2);

  return;

}

void FUN_06032e18(param_1)
    int param_1;
{

  int iVar1;

  int iVar2;

  int unaff_r14 = 0;

  *(int *)(unaff_r14 + 0x000002D0) = param_1;

  iVar2 = *(int *)((int)(0x060627F8 + (param_1 << 3)) + 4);

  *(int *)(unaff_r14 + 0x000002CC) = *(int *)(0x060627F8 + (param_1 << 3));

  *(int *)(unaff_r14 + 0x000002C8) = iVar2;

  iVar1 = 0x00000001;

  if ((0x00000002 & (int)*(short *)(unaff_r14 + 0x0000000E)) != 0) {

    iVar1 = iVar2 + -1;

  }

  *(int *)(unaff_r14 + 0x000002C4) = iVar1;

  return;

}

int FUN_06032e6c()
{

  int iVar1;

  int *puVar2;

  int *puVar3;

  int iVar4;

  int uVar5;

  int unaff_r14 = 0;

  iVar1 = 0x000002CC;

  puVar2 = (int *)

           (*(int *)(unaff_r14 + 0x000002CC) +

           (int)(short)0x00000044 * (int)(short)*(int *)(unaff_r14 + 0x000002C4));

  puVar3 = (int *)(0x00000010 + unaff_r14);

  iVar4 = 0x00000011;

  do {

    uVar5 = *puVar2;

    puVar2 = puVar2 + 1;

    *puVar3 = uVar5;

    puVar3 = puVar3 + 1;

    iVar4 = iVar4 + -1;

  } while (iVar4 != 0);

  return iVar1;

}

unsigned int FUN_06032ea4()
{

  unsigned int uVar1;

  int in_r7 = 0;

  int unaff_r14 = 0;

  int in_pr;

  if ((0x0000001C & (int)*(short *)(unaff_r14 + 0x0000000E)) == 0) {

    return 0x0000001C;

  }

  (*(int(*)())0x06026DBC)();

  (*(int(*)())0x06026E2E)(*(int *)(unaff_r14 + 0x00000000),*(int *)(unaff_r14 + 0x00000004),

             *(int *)(unaff_r14 + 0x00000008),in_r7,in_pr);

  (*(int(*)())0x06026EDE)((int)*(short *)(unaff_r14 + 0x0000000C));

  uVar1 = (unsigned int)*(short *)(unaff_r14 + 0x0000000E);

  if ((0x00000004 & uVar1) != 0) {

    (*(int(*)())0x06026DBC)();

    (*(int(*)())0x06026E2E)(*(int *)0x060624C8,*(int *)(0x060624C8 + 4),

               *(int *)(0x060624C8 + 8),in_r7,in_pr);

    (*(int(*)())0x06026F2A)(*(int *)(0x060624C8 + 0xc));

    (*(int(*)())0x0600A4AA)();

    (*(int(*)())0x06026DF8)();

  }

  if ((0x00000008 & uVar1) != 0) {

    (*(int(*)())0x06026DBC)();

    (*(int(*)())0x06026E2E)(*(int *)(0x060624C8 + 0x10),*(int *)(0x060624C8 + 0x14),

               *(int *)(0x060624C8 + 0x18),in_r7,in_pr);

    (*(int(*)())0x06026F2A)(*(int *)(0x060624C8 + 0x1c));

    (*(int(*)())0x0600A4AA)();

    (*(int(*)())0x06026DF8)();

  }

  if ((0x00000010 & uVar1) != 0) {

    (*(int(*)())0x06026DBC)();

    (*(int(*)())0x06026E2E)(*(int *)(0x060624C8 + 0x20),*(int *)(0x060624C8 + 0x24),

               *(int *)(0x060624C8 + 0x28),in_r7,in_pr);

    (*(int(*)())0x0600A474)(0x00000000);

    (*(int(*)())0x06026DF8)();

  }

  uVar1 = (*(int(*)())0x06026DF8)();

  return uVar1;

}

char * FUN_06033020(param_1)
    int *param_1;
{

  char *puVar1;

  int iVar2;

  char *puVar3;

  puVar1 = (char *)0x06082A28;

  puVar3 = (char *)0x00003333;

  if ((0x00000001 & (int)(char)*(int *)0x06082A25) == 0) {

    puVar3 = (char *)0x0;

  }

  iVar2 = *(int *)0x06082A28 + ((int)puVar3 - *(int *)0x06082A28 >> 1);

  *(int *)0x06082A28 = iVar2;

  *param_1 = *param_1 + iVar2;

  return puVar1;

}

/* scene_palette_check -- Check if scene palette is loaded.
 * If palette state (indirect ptr at 0x06033864) < 1, load palette
 * via DMA and initialize scene rendering. Returns palette state. */
int FUN_0603307c(void)
{
    int state = **(int **)0x06033864;
    if (state < 1) {
        FUN_06033330();         /* scene_dma_load_palette */
        state = FUN_060330a0(); /* scene render init */
    }
    return state;
}

int FUN_060330a0()
{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  int iVar9;

  iVar4 = FUN_0603316c();

  iVar3 = 0x00000268;

  iVar2 = 0x00000018;

  iVar1 = 0x00000010;

  iVar8 = *(int *)(0x00000010 + iVar4);

  iVar9 = *(int *)(0x00000018 + iVar4);

  iVar4 = iVar4 + 0x00000268;

  iVar5 = **(int **)0x0603386C + -1;

  do {

    iVar6 = iVar8 - *(int *)(iVar1 + iVar4);

    iVar7 = iVar9 - *(int *)(iVar2 + iVar4);

    iVar6 = iVar6 + (iVar6 >> 1);

    if (iVar6 < 0) {

      iVar6 = -iVar6;

    }

    if (iVar6 <= (int)0x00220000) {

      iVar6 = iVar7;

      if (iVar7 < 0) {

        iVar6 = -iVar7;

      }

      if (iVar6 <= (int)0x001A0000) {

        FUN_0603316c(iVar7);

        FUN_06033188();

        FUN_0603320c(0x0000FFFF);

      }

    }

    iVar4 = iVar4 + iVar3;

    iVar5 = iVar5 + -1;

  } while (0 < iVar5);

  return iVar4;

}

/* scene_stub_316c -- Stub returning 0 (unused scene function). */
int FUN_0603316c(void)
{
    return 0;
}

long long FUN_06033188(param_1, param_2, param_3)
    int param_1;
    int param_2;
    unsigned int param_3;
{

  int in_r0 = 0;

  int extraout_r2 = 0;

  int extraout_r2_00;

  int iVar1;

  long long uVar2;

  (*(int(*)())0x06027358)(param_3 & (unsigned int)0x0000FFFF,0x0606318C,0x06063190);

  (*(int(*)())0x06027552)(extraout_r2);

  uVar2 = (*(int(*)())0x06027552)(extraout_r2_00);

  iVar1 = (int)uVar2;

  uVar2 = (*(int(*)())0x06027552)((int)((unsigned long long)uVar2 >> 0x20));

  (*(int(*)())0x06027552)((int)((unsigned long long)uVar2 >> 0x20));

  return CONCAT44((int)uVar2 - iVar1,in_r0);

}

long long FUN_0603320c()
{

  int in_r0 = 0;

  unsigned int uVar1;

  int extraout_r1 = 0;

  char *pcVar2;

  char *extraout_r3;

  char *puVar3;

  int iVar4;

  int iVar5;

  pcVar2 = 0x0603390C + in_r0 * 0x18;

  iVar4 = 6;

  puVar3 = (char *)((in_r0 << 3));

  do {

    iVar5 = 4;

    do {

      uVar1 = FUN_06033278(puVar3,(unsigned int)(int)*pcVar2 >> 4);

      FUN_06033278(0x00010000,uVar1 & 0xf);

      iVar5 = iVar5 + -1;

      pcVar2 = extraout_r3;

      puVar3 = (char *)0x00010000;

    } while (0 < iVar5);

    iVar4 = iVar4 + -1;

  } while (0 < iVar4);

  return CONCAT44(0x00010000 + 0xFFF80000 + extraout_r1,0x00010000);

}

long long FUN_06033278(param_1, param_2)
    int param_1;
    int param_2;
{

  int in_r0 = 0;

  int in_r1 = 0;

  char *puVar1;

  unsigned int uVar2;

  int in_r2 = 0;

  char *puVar3;

  unsigned int uVar4;

  unsigned char bVar5;

  unsigned int idx;

  if (param_2 != 0) {

    puVar1 = (char *)(0x00240000 + in_r1);

    puVar3 = (char *)(0x001C0000 + in_r2);

    if (((((int)0x00040000 <= (int)puVar1) && ((int)0x00040000 <= (int)puVar3)) &&

        ((int)puVar1 <= (int)0x00460000)) && ((int)puVar3 <= (int)0x00360000)) {

      if (((unsigned int)0x00008000 & (unsigned int)puVar3) != 0) {

        puVar3 = puVar3 + (int)0x00010000;

      }

      if (((unsigned int)0x00008000 & (unsigned int)puVar1) != 0) {

        puVar1 = puVar1 + (int)0x00010000;

      }

      uVar4 = (unsigned int)(short)((unsigned int)puVar3 >> 0x10);

      uVar2 = (unsigned int)(short)((unsigned int)puVar1 >> 0x10);

      bVar5 = 0xf0;

      if ((uVar2 & 1) == 0) {

        bVar5 = 0xf;

        param_2 = param_2 << 4;

      }

      idx = (uVar4 & 0xf8) * 0x24 + ((uVar4 & 7) << 2) + ((uVar2 & 0xf8) << 2) + ((uVar2 & 7) >> 1);

      ((unsigned char *)0x060629AC)[idx] =
           (((unsigned char *)0x060629AC)[idx] & bVar5) | (unsigned char)param_2;

    }

  }

  return CONCAT44(in_r1,in_r0);

}

/* scene_dma_load_palette -- DMA-copy scene color palette (0x7E0 bytes).
 * Copies from ROM palette data (0x060430CE) to VDP2 CRAM (0x060629AC). */
int FUN_06033330(void)
{
    return (*(int(*)())0x0602761E)(0x060629AC, 0x060430CE, 0x7E0);

}

int FUN_06033354()
{

  short sVar1;

  char *puVar2;

  char *puVar3;

  int uVar4;

  int iVar5;

  char *puVar6;

  char *puVar7;

  char *puVar8;

  short *psVar9;

  int in_pr;

  short *psVar10;

  puVar8 = (char *)0x060338DC;

  if (0 < **(int **)0x06033868) {

    puVar8 = (char *)0x060338E8;

  }

  iVar5 = 6;

  puVar6 = (char *)0x06062D95;

  do {

    puVar7 = puVar8 + 1;

    *puVar6 = *puVar8;

    puVar8 = puVar8 + 2;

    puVar6[1] = *puVar7;

    puVar3 = (char *)0x060629AC;

    puVar2 = (int *)0x060430CE;

    puVar6 = puVar6 + 4;

    iVar5 = iVar5 + -1;

  } while (iVar5 != 0);

  iVar5 = 6;

  psVar9 = (short *)0x060338F4;

  do {

    sVar1 = *psVar9;

    psVar10 = psVar9 + 1;

    psVar9 = psVar9 + 2;

    (*(int(*)())0x0602761E)(puVar3 + sVar1,puVar2 + sVar1,(int)*psVar10,iVar5,in_pr);

    iVar5 = iVar5 + -1;

  } while (0 < iVar5);

  uVar4 = (*(int(*)())0x0602761E)(0x25E03700,0x060629AC,0x7e0,iVar5,in_pr);

  return uVar4;

}

int FUN_060333d8(param_1, param_2, param_3, param_4)
    int param_1;
    int param_2;
    int param_3;
    int param_4;
{

  char *puVar1;

  int uVar2;

  int in_pr;

  puVar1 = (char *)0x060629AA;

  *(short *)0x060629AA = 8;

  *(short *)(puVar1 + -2) = 2;

  FUN_06033550();

  *(short *)0x0606299A = 8;

  FUN_06033648();

  FUN_06033470();

  if (('\0' < **(char **)0x06033880) || (**(int **)0x06033864 < 1)) {

    FUN_06033700(param_1,param_2,0x0606298C,param_4,in_pr);

  }

  FUN_06033700(param_1,param_2,0x0606299C,param_4,in_pr);

  uVar2 = FUN_0603307c();

  return uVar2;

}

int FUN_06033470()
{

  short sVar1;

  short sVar2;

  char *puVar3;

  short sVar5;

  int uVar4;

  short *psVar6;

  short sVar7;

  puVar3 = (char *)0x06062970;

  psVar6 = (short *)(0x060338C4 + **(int **)(0x06033874 << 3));

  sVar1 = *psVar6;

  sVar2 = psVar6[1];

  *(int *)0x06062970 = 0;

  puVar3[4] = 1;

  puVar3[5] = (char)(**(unsigned int **)0x0603387C >> 6);

  *(short *)(puVar3 + 6) = 0xe;

  sVar5 = sVar1;

  sVar7 = psVar6[2] + sVar1;

  if ('\0' < **(char **)0x06033884) {

    sVar5 = psVar6[2] + sVar1;

    sVar7 = sVar1;

  }

  *(short *)(puVar3 + 8) = sVar5;

  *(short *)(puVar3 + 0x14) = sVar5;

  *(short *)(puVar3 + 0xc) = sVar7;

  *(short *)(puVar3 + 0x10) = sVar7;

  *(short *)(puVar3 + 10) = sVar2;

  *(short *)(puVar3 + 0xe) = sVar2;

  sVar1 = psVar6[3];

  *(short *)(puVar3 + 0x12) = sVar1 + sVar2;

  *(short *)(puVar3 + 0x16) = sVar1 + sVar2;

  (*(int(*)())0x060280F8)(puVar3,*(int *)0x060785FC);

  uVar4 = FUN_06033504();

  return uVar4;

}

void FUN_06033520()
{

  char *puVar1;

  int uVar2;

  short in_r2 = 0;

  puVar1 = (char *)0x06062970;

  *(short *)(0x06062970 + 6) = in_r2;

  uVar2 = 0x00000000;

  *(int *)puVar1 = (char *)0x00000000;

  puVar1[4] = (char)uVar2 + '\x01';

  puVar1[5] = (char)(*(unsigned int *)0x0605B734 >> 6);

  FUN_060337fc(puVar1 + 0x16);

  return;

}

int FUN_06033550()
{

  int in_r0 = 0;

  int iVar1;

  int iVar2;

  int iVar3;

  int in_r1 = 0;

  int iVar4;

  int extraout_r2 = 0;

  int extraout_r2_00;

  int extraout_r3 = 0;

  int in_r7 = 0;

  long long uVar5;

  *(int *)(in_r1 + -4) =

       *(int *)(0x06033630 + *(int *)(0x0607EAD8 << 2)) -

       (*(int *)(0x00000020 + in_r0) + *(int *)(0x000001D8 + in_r0) +

       *(int *)(0x000001CC + in_r0));

  iVar1 = FUN_060335f4();

  iVar1 = (*(int(*)())0x06027552)(*(int *)(0x00000010 + iVar1));

  iVar2 = (*(int(*)())0x06027552)(extraout_r3,in_r7);

  iVar3 = (*(int(*)())0x06027552)(extraout_r2);

  uVar5 = (*(int(*)())0x06027552)(extraout_r2_00,in_r7);

  iVar4 = (int)((unsigned long long)uVar5 >> 0x20);

  *(int *)(iVar4 + -4) = iVar1 - (int)uVar5;

  *(int *)(iVar4 + -8) = iVar2 + iVar3;

  return in_r0;

}

/* scene_car_count_lookup -- Look up scene parameter by car count, then
 * chain-call two trig/projection helpers with the result.
 * Table at 0x0603363C is indexed by CAR_COUNT. */
int FUN_060335f4(int param_1, int param_2, int param_3)
{
    register int p2 asm("r2") = param_2;
    register int p3 asm("r1") = param_3;
    int table_val = *(int *)(0x0603363C + (CAR_COUNT << 2));
    int intermediate = (*(int(*)())0x06027348)();
    return (*(int(*)())0x06027344)(table_val, p2, p3, intermediate);
}

int FUN_06033648()
{

  int in_r0 = 0;

  int iVar1;

  int extraout_r2 = 0;

  short sVar2;

  unsigned int uVar3;

  int iVar4;

  unsigned int in_sr = 0;

  long long uVar5;

  FUN_060336f2();

  if ((in_sr & 1) == 0) {

    if (0 < DEMO_MODE_FLAG) {

      return in_r0;

    }

    iVar4 = **(int **)0x0603386C + -1;

  }

  else {

    iVar4 = 1;

  }

  uVar3 = (unsigned int)(*(int *)(0x00000224 + in_r0) == 0);

  uVar5 = FUN_060336c8();

  iVar1 = (int)uVar5;

  do {

    iVar1 = iVar1 + 0x00000268;

    if (*(unsigned int *)(extraout_r2 + iVar1) == uVar3) break;

    iVar4 = iVar4 + -1;

  } while (0 < iVar4);

  sVar2 = 6;

  if (((char)*(int *)0x06078635 < '\x01') && ((int)uVar3 < 2)) {

    sVar2 = (short)(uVar3 << 2) + 6;

  }

  *(short *)((int)((unsigned long long)uVar5 >> 0x20) + -2) = sVar2;

  FUN_06033550();

  return in_r0;

}

int FUN_060336c8()
{

  int in_r0 = 0;

  return in_r0;

}

int FUN_060336f2()
{

  int in_r0 = 0;

  return in_r0;

}

int FUN_06033700(param_1, param_2, param_3)
    int param_1;
    int param_2;
    int *param_3;
{

  short sVar1;

  short extraout_var;

  short extraout_var_00;

  int in_r0 = 0;

  short *psVar2;

  int iVar3;

  int iVar4;

  int uVar5;

  int uVar6;

  int iVar7;

  int in_pr;

  uVar6 = *param_3;

  sVar1 = *(short *)((int)param_3 + 0xe);

  iVar3 = *(int *)(0x0607EAD8 << 4);

  uVar5 = *(int *)(0x06033894 + iVar3 + 8);

  (*(int(*)())0x0602755C)(param_3[1],*(int *)(0x06033894 + iVar3 + 0xc),param_3 + 4);

  (*(int(*)())0x0602755C)(uVar6,uVar5);

  iVar7 = (int)extraout_var_00;

  if ('\0' < (char)*(int *)0x06078663) {

    iVar7 = -iVar7;

  }

  psVar2 = (short *)(0x06033894 + iVar3);

  iVar7 = *psVar2 - iVar7;

  iVar3 = (int)psVar2[1] - (int)extraout_var;

  if ('\0' < (char)*(int *)0x06078663) {

    iVar7 = iVar7 + psVar2[2];

    iVar3 = iVar3 + psVar2[3];

  }

  iVar4 = -(int)sVar1;

  FUN_06033520(iVar4,iVar7 + iVar4,iVar3 + iVar4,iVar7 + sVar1,in_pr,param_3);

  (*(int(*)())0x060280F8)(0x06062970,*(int *)0x060785FC);

  FUN_06033504();

  return in_r0;

}

void FUN_060337fc()
{

  int in_r0 = 0;

  (*(int(*)())(*(int *)(0x0603380C + (in_r0 << 2))))();

  return;

}

long long FUN_06033aac()
{

  int iVar1;

  short *psVar2;

  int *puVar3;

  int *puVar4;

  char *puVar5;

  unsigned int uVar6;

  int iVar7;

  int iVar8;

  uVar6 = 0;

  do {

    puVar5 = (char *)0x06082A7C;

    iVar8 = (0x0000002C & 0xffff) * (uVar6 & 0xffff);

    ((int *)0x06082A7C)[0x00000000 + iVar8] = (char)uVar6;

    puVar5[0x00000010 + iVar8] = 0;

    puVar5[0x00000011 + iVar8] = 0;

    puVar5[0x00000026 + iVar8] = 0;

    puVar5[0x00000028 + iVar8] = 0;

    psVar2 = (short *)(0x060631BC + (0x0000000E & 0xffff) * (uVar6 & 0xffff));

    *(int *)(puVar5 + 0x00000014 + iVar8) = (int)*psVar2 << 0x10;

    *(int *)(puVar5 + 0x00000018 + iVar8) = (int)psVar2[1] << 0x10;

    *(int *)(puVar5 + 0x0000001C + iVar8) = (int)psVar2[2] << 0x10;

    *(int *)(puVar5 + 0x00000020 + iVar8) = (int)psVar2[3] << 0x10;

    *(short *)(puVar5 + 0x00000002 + iVar8) = psVar2[4];

    *(short *)(puVar5 + 0x00000012 + iVar8) = psVar2[5];

    *(short *)(puVar5 + 0x00000024 + iVar8) = (short)*(char *)(psVar2 + 6) << 8;

    puVar5[0x00000001 + iVar8] = *(char *)((int)psVar2 + 0xd);

    uVar6 = uVar6 + 1;

  } while ((int)uVar6 < 0x0000002D);

  *(int *)0x06083254 = 0;

  *(int *)0x06083250 = 0;

  iVar8 = 0x00000014;

  iVar7 = 0;

  puVar4 = (int *)0x060631AC;

  puVar5 = (char *)0x0607EB94;

  do {

    puVar3 = (int *)*puVar4;

    puVar4 = puVar4 + 1;

    *puVar3 = puVar5;

    iVar1 = 0x00000006;

    puVar5[0x00000006] = (char)iVar7;

    puVar5 = puVar5 + iVar8;

    iVar7 = iVar7 + 1;

  } while (iVar7 < 2);

  return CONCAT44(psVar2 + 7,iVar1);

}

int FUN_06033bc8()
{

  int iVar1;

  int bVar2;

  if ((*(int *)(0x000001EC + CAR_PTR_TARGET) < 0x000000DC) ||

     (0x000000EC < *(int *)(0x000001EC + CAR_PTR_TARGET))) {

    bVar2 = 0;

  }

  else {

    bVar2 = 1;

  }

  if (bVar2) {

    (*(int(*)())0x06033F54)(0);

    (*(int(*)())0x06033F54)(1);

    (*(int(*)())0x06033F54)(2);

  }

  else {

    (*(int(*)())0x0603446C)();

  }

  if ((*(int *)(0x000001EC + CAR_PTR_TARGET) < 0x000000ED) ||

     (0x00000104 < *(int *)(0x000001EC + CAR_PTR_TARGET))) {

    bVar2 = 0;

  }

  else {

    bVar2 = 1;

  }

  if (bVar2) {

    FUN_06033f54(5);

    FUN_06033f54(6);

    FUN_06033f54(7);

    FUN_06033f54(8);

    FUN_06033f54(9);

    FUN_06033f54(10);

    FUN_06033f54(0xb);

    FUN_06033f54(0xc);

    FUN_06033f54(0xd);

    FUN_06033f54(0xe);

    FUN_06033f54(0xf);

    FUN_06033f54(0x10);

    FUN_06033f54(0x11);

    FUN_06033f54(0x12);

    FUN_06033f54(0x13);

    FUN_06033f54(0x14);

    FUN_06033f54(0x15);

    FUN_06033f54(0x16);

    FUN_06033f54(0x17);

    FUN_06033f54(0x18);

  }

  if ((*(int *)(0x000001EC + CAR_PTR_TARGET) < 0x000001B8) ||

     (0x000001E0 < *(int *)(0x000001EC + CAR_PTR_TARGET))) {

    bVar2 = 0;

  }

  else {

    bVar2 = 1;

  }

  if (bVar2) {

    if (DEMO_MODE_FLAG == 0) {

      iVar1 = 0;

    }

    else {

      FUN_06033f54(0x00000019);

      iVar1 = *(int *)0x06083250;

      if (0x0000013B <= iVar1) {

        FUN_06033f54(0x0000001A);

        FUN_06033f54(0x0000001B);

        FUN_06033f54(0x0000001C);

        FUN_06033f54(0x0000001D);

        if (0x00000276 <= iVar1) {

          FUN_06033f54(0x1e);

          FUN_06033f54(0x1f);

          FUN_06033f54(0x20);

          FUN_06033f54(0x21);

          FUN_06033f54(0x22);

          if (0x000003B1 <= iVar1) {

            FUN_06033f54(0x23);

            FUN_06033f54(0x24);

            FUN_06033f54(0x25);

            FUN_06033f54(0x26);

            FUN_06033f54(0x27);

            FUN_06033f54(0x28);

            FUN_06033f54(0x29);

            FUN_06033f54(0x2a);

            FUN_06033f54(0x2b);

            FUN_06033f54(0x2c);

          }

        }

      }

      iVar1 = *(int *)0x06083250 + 1;

      if (0x00000EC4 <= *(int *)0x06083250 + 1) {

        iVar1 = 0x00000EC4;

      }

      *(int *)0x06083250 = iVar1;

    }

  }

  else {

    iVar1 = 0;

    *(int *)0x06083250 = 0;

  }

  return iVar1;

}

int FUN_06033ea8()
{

  int iVar1;

  int iVar2;

  if (*(short *)0x06063E08 == 1) {

    *(int *)0x06083254 = *(int *)0x06083254 + '\x01';

  }

  if (*(int *)0x06083254 == '\x01') {

    (*(int(*)())0x06033F54)(0x00000000);

    (*(int(*)())0x06033F54)(0x00000001);

    (*(int(*)())0x06033F54)(0x00000002);

    (*(int(*)())0x06033F54)(0x00000004);

  }

  iVar1 = (int)(char)*(int *)0x06083254;

  iVar2 = 0x00000006;

  if ((char)*(int *)0x06083254 == 2) {

    do {

      FUN_06033f54();

      iVar2 = iVar2 + 1;

      iVar1 = 0x00000019;

    } while (iVar2 < 0x00000019);

  }

  return iVar1;

}

int FUN_06033f54(param_1)
    unsigned short param_1;
{

  char cVar1;

  int uVar2;

  int iVar3;

  iVar3 = (0x0000002C & 0xffff) * (unsigned int)param_1;

  if ((((int *)0x06082A7C)[0x00000001 + iVar3] == '\x01') ||

     (((int *)0x06082A7C)[0x00000001 + iVar3] == '\x04')) {

LAB_06033f80:

    FUN_06034000();

    FUN_06034168();

    uVar2 = FUN_060346c0();

  }

  else {

    cVar1 = ((int *)0x06082A7C)[0x00000026 + iVar3];

    if (cVar1 == '\0') {

      FUN_0603449c();

      FUN_06034000();

      FUN_06034168();

      uVar2 = FUN_060346c0();

      return uVar2;

    }

    if (cVar1 == '\x01') {

      FUN_06034560();

    }

    else if (cVar1 != '\x02') goto LAB_06033f80;

    FUN_0603449c();

    FUN_0603458c();

    FUN_06034640();

    uVar2 = FUN_060346c0();

  }

  return uVar2;

}
