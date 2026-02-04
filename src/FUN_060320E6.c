extern int DAT_06031e30;

extern int DAT_06031eee;

extern int DAT_06031fc4;

extern int DAT_06032048;

extern int DAT_0603204a;

extern int DAT_06032102;

extern int DAT_06032104;

extern int DAT_06032106;

extern int PTR_DAT_06031ea8;

extern int PTR_DAT_06031ea8;

extern int PTR_DAT_06031f30;

extern int PTR_DAT_06031f30;

extern int PTR_DAT_06031f74;

extern int PTR_DAT_06031f74;

extern int PTR_DAT_0603204c;

extern int PTR_DAT_0603204c;

unsigned int FUN_060320e6()
{

  char *puVar1;

  unsigned int uVar2;

  int iVar3;

  unsigned int uVar4;

  int in_r1;

  int iVar5;

  int in_r2;

  unsigned int uVar6;

  unsigned int uVar7;

  unsigned int extraout_r3;

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

  char unaff_r10;

  unsigned int *unaff_r11;

  unsigned int *puVar15;

  unsigned int *unaff_r13;

  int unaff_r14;

  unsigned int uVar16;

  unsigned int uVar17;

  unsigned int in_sr;

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

  puVar1 = 0x06032138;

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

    uVar8 = uVar4 + uVar17 * 0x10000;

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

    uVar12 = uVar9 + uVar4 * 0x10000;

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

    uVar9 = uVar8 + uVar4 * 0x10000;

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

    uVar12 = uVar8 + uVar4 * 0x10000;

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

    uVar9 = uVar8 + uVar4 * 0x10000;

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

    uVar12 = uVar8 + uVar4 * 0x10000;

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

    uVar9 = uVar8 + uVar4 * 0x10000;

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

    uVar12 = uVar8 + uVar4 * 0x10000;

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

    uVar9 = uVar8 + uVar4 * 0x10000;

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

    uVar8 = uVar4 + uVar17 * 0x10000;

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

    uVar12 = uVar9 + uVar4 * 0x10000;

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

    uVar9 = uVar8 + uVar4 * 0x10000;

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

        puVar1 = 0x0608AC20;

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

                uVar18 = (**(void **)(0x06032144 + ((int)*(short *)(puVar13 + -3) & 7U) * 4))

                                   (unaff_r13[1],unaff_r13[2],unaff_r13[3]);

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
