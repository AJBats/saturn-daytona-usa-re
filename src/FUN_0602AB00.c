extern int DAT_0602a97e;

extern int DAT_0602aa12;

extern int DAT_0602aa14;

extern int DAT_0602aa16;

extern int DAT_0602ab36;

extern int DAT_0602ab38;

extern int DAT_0602ab8c;

extern int DAT_0602ab90;

extern int DAT_0602ab94;

extern int PTR_DAT_0602a87c;

extern int PTR_DAT_0602a87c;

extern int FUN_0602aaa0();
extern int FUN_0602ab3a();

unsigned int FUN_0602ab00()
{

  unsigned int uVar1;

  unsigned int uVar2;

  unsigned int uVar3;

  char *puVar4;

  char *puVar5;

  unsigned int uVar6;

  unsigned int extraout_r1;

  int in_r1;

  unsigned int extraout_r2;

  int in_r2;

  unsigned int extraout_r3;

  unsigned int extraout_r3_00;

  unsigned int extraout_r3_01;

  unsigned int extraout_r3_02;

  unsigned int extraout_r3_03;

  int iVar7;

  int in_r3;

  unsigned int *puVar8;

  unsigned int *puVar9;

  int iVar10;

  unsigned int *puVar11;

  int iVar12;

  unsigned int uVar13;

  unsigned int *puVar14;

  unsigned int *unaff_r8;

  int unaff_r9;

  int *unaff_r11;

  int iVar15;

  int iVar16;

  int *unaff_r12;

  char unaff_r13;

  unsigned int uVar17;

  unsigned int in_sr;

  unsigned int uVar18;

  int iVar19;

  int iVar20;

  unsigned int uVar21;

  unsigned int uVar22;

  unsigned int uVar23;

  int in_stack_00000000;

  uVar6 = (unsigned int)DAT_0602ab36;

  puVar8 = *(unsigned int **)(uVar6 + 0x1c);

  iVar19 = (int)((unsigned long long)((long long)(int)puVar8 * (long long)in_r1) >> 0x20);

  iVar20 = (int)((unsigned long long)((long long)(int)puVar8 * (long long)-in_r2) >> 0x20);

  *unaff_r11 = iVar19;

  unaff_r11[1] = iVar20;

  uVar13 = (unsigned int)DAT_0602ab38;

  uVar17 = in_sr & 0xfffffffe;

  uVar18 = uVar17 | (int)uVar13 < iVar19;

  if (((unsigned char)uVar18 & 1) != 1) {

    uVar6 = -uVar13;

    uVar18 = uVar17 | iVar19 < (int)uVar6;

    if (((((unsigned char)uVar18 & 1) != 1) &&

        (uVar18 = uVar17 | iVar20 < (int)uVar6, ((unsigned char)uVar18 & 1) != 1)) &&

       (uVar18 = uVar17 | (int)(uVar13 >> 1) < iVar20, ((unsigned char)uVar18 & 1) != 1)) {

      *unaff_r12 = unaff_r9;

      unaff_r12[1] = iVar19;

      unaff_r12[2] = iVar20;

      unaff_r12[3] = in_r3;

      return uVar6;

    }

  }

LAB_0602aa74:

  do {

    puVar14 = unaff_r8;

    puVar4 = 0x0602AB68;

    in_stack_00000000 = in_stack_00000000 + -1;

    uVar18 = uVar18 & 0xfffffffe;

    if (in_stack_00000000 == 0) {

      return uVar6;

    }

    unaff_r8 = puVar14 + -6;

    uVar17 = uVar18 | *(short *)0x0605BE36 == 0;

  } while ((((unsigned char)uVar17 & 1) != 1) &&

          (uVar6 = (unsigned int)*(short *)((int)puVar14 + -10), uVar17 = uVar18,

          (int)PTR_DAT_0602a87c == uVar6));

  puVar11 = *(unsigned int **)0x06089EDC;

  puVar9 = (unsigned int *)0x0602AB88;

  FUN_0602aaa0(puVar8);

  *puVar9 = extraout_r1;

  puVar9[1] = extraout_r2;

  puVar9[2] = extraout_r3;

  puVar5 = 0x0602AB98;

  uVar18 = uVar17 & 0xfffffffe;

  if ((puVar14[-3] & 0x80000) == 0) {

    uVar13 = *puVar11;

    uVar6 = *unaff_r8;

    uVar3 = uVar13 ^ uVar6;

    if ((int)uVar13 < 0) {

      uVar13 = -uVar13;

    }

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    uVar2 = (uVar6 & 0xffff) * (uVar13 & 0xffff);

    iVar20 = (uVar6 >> 0x10) * (uVar13 & 0xffff);

    iVar19 = 0;

    uVar1 = iVar20 + (uVar6 & 0xffff) * (uVar13 >> 0x10);

    if (iVar20 != 0) {

      iVar19 = 0x10000;

    }

    uVar21 = uVar2 + uVar1 * 0x10000;

    uVar6 = iVar19 + (unsigned int)(uVar21 < uVar2) + (uVar1 >> 0x10) + (uVar6 >> 0x10) * (uVar13 >> 0x10);

    if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

      uVar6 = ~uVar6;

      if (uVar21 == 0) {

        uVar6 = uVar6 + 1;

      }

      else {

        uVar21 = ~uVar21 + 1;

      }

    }

    if (((unsigned char)(uVar17 >> 1) & 1) == 1) {

      if ((int)uVar6 < -0x8000) {

        uVar6 = 0xffff8000;

        uVar21 = 0;

      }

      if (0x7fff < (int)uVar6) {

        uVar6 = 0x7fff;

        uVar21 = 0xffffffff;

      }

      uVar6 = uVar6 & 0xffff;

    }

    uVar3 = puVar11[1];

    uVar13 = puVar14[-5];

    uVar1 = uVar3 ^ uVar13;

    if ((int)uVar3 < 0) {

      uVar3 = -uVar3;

    }

    if ((int)uVar13 < 0) {

      uVar13 = -uVar13;

    }

    uVar23 = (uVar13 & 0xffff) * (uVar3 & 0xffff);

    iVar20 = (uVar13 >> 0x10) * (uVar3 & 0xffff);

    iVar19 = 0;

    uVar2 = iVar20 + (uVar13 & 0xffff) * (uVar3 >> 0x10);

    if (iVar20 != 0) {

      iVar19 = 0x10000;

    }

    uVar22 = uVar23 + uVar2 * 0x10000;

    uVar13 = iVar19 + (unsigned int)(uVar22 < uVar23) + (uVar2 >> 0x10) + (uVar13 >> 0x10) * (uVar3 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

      uVar13 = ~uVar13;

      if (uVar22 == 0) {

        uVar13 = uVar13 + 1;

      }

      else {

        uVar22 = ~uVar22 + 1;

      }

    }

    if (((unsigned char)(uVar17 >> 1) & 1) == 1) {

      uVar22 = uVar21 + uVar22;

      uVar6 = uVar13 + (uVar22 < uVar21) + (uVar6 & 0xffff);

      if ((int)uVar6 < -0x8000) {

        uVar6 = 0xffff8000;

        uVar22 = 0;

      }

      if (0x7fff < (int)uVar6) {

        uVar6 = 0x7fff;

        uVar22 = 0xffffffff;

      }

      uVar6 = uVar6 & 0xffff;

    }

    else {

      uVar22 = uVar21 + uVar22;

      uVar6 = uVar13 + (uVar22 < uVar21) + uVar6;

    }

    uVar3 = puVar11[2];

    uVar13 = puVar14[-4];

    uVar1 = uVar3 ^ uVar13;

    if ((int)uVar3 < 0) {

      uVar3 = -uVar3;

    }

    if ((int)uVar13 < 0) {

      uVar13 = -uVar13;

    }

    uVar21 = (uVar13 & 0xffff) * (uVar3 & 0xffff);

    iVar20 = (uVar13 >> 0x10) * (uVar3 & 0xffff);

    iVar19 = 0;

    uVar2 = iVar20 + (uVar13 & 0xffff) * (uVar3 >> 0x10);

    if (iVar20 != 0) {

      iVar19 = 0x10000;

    }

    uVar23 = uVar21 + uVar2 * 0x10000;

    uVar13 = iVar19 + (unsigned int)(uVar23 < uVar21) + (uVar2 >> 0x10) + (uVar13 >> 0x10) * (uVar3 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

      uVar13 = ~uVar13;

      if (uVar23 == 0) {

        uVar13 = uVar13 + 1;

      }

      else {

        uVar23 = ~uVar23 + 1;

      }

    }

    if (((unsigned char)(uVar17 >> 1) & 1) == 1) {

      uVar23 = uVar22 + uVar23;

      uVar6 = uVar13 + (uVar23 < uVar22) + (uVar6 & 0xffff);

      if ((int)uVar6 < -0x8000) {

        uVar6 = 0xffff8000;

        uVar23 = 0;

      }

      if (0x7fff < (int)uVar6) {

        uVar6 = 0x7fff;

        uVar23 = 0xffffffff;

      }

      uVar6 = uVar6 & 0xffff;

    }

    else {

      uVar23 = uVar22 + uVar23;

      uVar6 = uVar13 + (uVar23 < uVar22) + uVar6;

    }

    uVar3 = puVar11[3];

    uVar13 = *unaff_r8;

    uVar1 = uVar3 ^ uVar13;

    if ((int)uVar3 < 0) {

      uVar3 = -uVar3;

    }

    if ((int)uVar13 < 0) {

      uVar13 = -uVar13;

    }

    uVar21 = (uVar13 & 0xffff) * (uVar3 & 0xffff);

    iVar20 = (uVar13 >> 0x10) * (uVar3 & 0xffff);

    iVar19 = 0;

    uVar2 = iVar20 + (uVar13 & 0xffff) * (uVar3 >> 0x10);

    if (iVar20 != 0) {

      iVar19 = 0x10000;

    }

    uVar22 = uVar21 + uVar2 * 0x10000;

    uVar13 = iVar19 + (unsigned int)(uVar22 < uVar21) + (uVar2 >> 0x10) + (uVar13 >> 0x10) * (uVar3 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

      uVar13 = ~uVar13;

      if (uVar22 == 0) {

        uVar13 = uVar13 + 1;

      }

      else {

        uVar22 = ~uVar22 + 1;

      }

    }

    if (((unsigned char)(uVar17 >> 1) & 1) == 1) {

      if ((int)uVar13 < -0x8000) {

        uVar13 = 0xffff8000;

        uVar22 = 0;

      }

      if (0x7fff < (int)uVar13) {

        uVar13 = 0x7fff;

        uVar22 = 0xffffffff;

      }

      uVar13 = uVar13 & 0xffff;

    }

    *(unsigned int *)0x0602AB98 = uVar6 << 0x10 | uVar23 >> 0x10;

    uVar3 = puVar11[4];

    uVar6 = puVar14[-5];

    uVar1 = uVar3 ^ uVar6;

    if ((int)uVar3 < 0) {

      uVar3 = -uVar3;

    }

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    uVar21 = (uVar6 & 0xffff) * (uVar3 & 0xffff);

    iVar20 = (uVar6 >> 0x10) * (uVar3 & 0xffff);

    iVar19 = 0;

    uVar2 = iVar20 + (uVar6 & 0xffff) * (uVar3 >> 0x10);

    if (iVar20 != 0) {

      iVar19 = 0x10000;

    }

    uVar23 = uVar21 + uVar2 * 0x10000;

    uVar6 = iVar19 + (unsigned int)(uVar23 < uVar21) + (uVar2 >> 0x10) + (uVar6 >> 0x10) * (uVar3 >> 0x10);

    if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

      uVar6 = ~uVar6;

      if (uVar23 == 0) {

        uVar6 = uVar6 + 1;

      }

      else {

        uVar23 = ~uVar23 + 1;

      }

    }

    if (((unsigned char)(uVar17 >> 1) & 1) == 1) {

      uVar23 = uVar22 + uVar23;

      uVar13 = uVar6 + (uVar23 < uVar22) + (uVar13 & 0xffff);

      if ((int)uVar13 < -0x8000) {

        uVar13 = 0xffff8000;

        uVar23 = 0;

      }

      if (0x7fff < (int)uVar13) {

        uVar13 = 0x7fff;

        uVar23 = 0xffffffff;

      }

      uVar13 = uVar13 & 0xffff;

    }

    else {

      uVar23 = uVar22 + uVar23;

      uVar13 = uVar6 + (uVar23 < uVar22) + uVar13;

    }

    uVar3 = puVar11[5];

    uVar6 = puVar14[-4];

    uVar1 = uVar3 ^ uVar6;

    if ((int)uVar3 < 0) {

      uVar3 = -uVar3;

    }

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    uVar21 = (uVar6 & 0xffff) * (uVar3 & 0xffff);

    iVar20 = (uVar6 >> 0x10) * (uVar3 & 0xffff);

    iVar19 = 0;

    uVar2 = iVar20 + (uVar6 & 0xffff) * (uVar3 >> 0x10);

    if (iVar20 != 0) {

      iVar19 = 0x10000;

    }

    uVar22 = uVar21 + uVar2 * 0x10000;

    uVar6 = iVar19 + (unsigned int)(uVar22 < uVar21) + (uVar2 >> 0x10) + (uVar6 >> 0x10) * (uVar3 >> 0x10);

    if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

      uVar6 = ~uVar6;

      if (uVar22 == 0) {

        uVar6 = uVar6 + 1;

      }

      else {

        uVar22 = ~uVar22 + 1;

      }

    }

    if (((unsigned char)(uVar17 >> 1) & 1) == 1) {

      uVar22 = uVar23 + uVar22;

      uVar13 = uVar6 + (uVar22 < uVar23) + (uVar13 & 0xffff);

      if ((int)uVar13 < -0x8000) {

        uVar13 = 0xffff8000;

        uVar22 = 0;

      }

      if (0x7fff < (int)uVar13) {

        uVar13 = 0x7fff;

        uVar22 = 0xffffffff;

      }

      uVar13 = uVar13 & 0xffff;

    }

    else {

      uVar22 = uVar23 + uVar22;

      uVar13 = uVar6 + (uVar22 < uVar23) + uVar13;

    }

    uVar3 = puVar11[6];

    uVar6 = *unaff_r8;

    uVar1 = uVar3 ^ uVar6;

    if ((int)uVar3 < 0) {

      uVar3 = -uVar3;

    }

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    uVar21 = (uVar6 & 0xffff) * (uVar3 & 0xffff);

    iVar20 = (uVar6 >> 0x10) * (uVar3 & 0xffff);

    iVar19 = 0;

    uVar2 = iVar20 + (uVar6 & 0xffff) * (uVar3 >> 0x10);

    if (iVar20 != 0) {

      iVar19 = 0x10000;

    }

    uVar23 = uVar21 + uVar2 * 0x10000;

    uVar6 = iVar19 + (unsigned int)(uVar23 < uVar21) + (uVar2 >> 0x10) + (uVar6 >> 0x10) * (uVar3 >> 0x10);

    if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

      uVar6 = ~uVar6;

      if (uVar23 == 0) {

        uVar6 = uVar6 + 1;

      }

      else {

        uVar23 = ~uVar23 + 1;

      }

    }

    if (((unsigned char)(uVar17 >> 1) & 1) == 1) {

      if ((int)uVar6 < -0x8000) {

        uVar6 = 0xffff8000;

        uVar23 = 0;

      }

      if (0x7fff < (int)uVar6) {

        uVar6 = 0x7fff;

        uVar23 = 0xffffffff;

      }

      uVar6 = uVar6 & 0xffff;

    }

    *(unsigned int *)(puVar5 + 4) = uVar13 << 0x10 | uVar22 >> 0x10;

    uVar3 = puVar11[7];

    uVar13 = puVar14[-5];

    uVar1 = uVar3 ^ uVar13;

    if ((int)uVar3 < 0) {

      uVar3 = -uVar3;

    }

    if ((int)uVar13 < 0) {

      uVar13 = -uVar13;

    }

    uVar21 = (uVar13 & 0xffff) * (uVar3 & 0xffff);

    iVar20 = (uVar13 >> 0x10) * (uVar3 & 0xffff);

    iVar19 = 0;

    uVar2 = iVar20 + (uVar13 & 0xffff) * (uVar3 >> 0x10);

    if (iVar20 != 0) {

      iVar19 = 0x10000;

    }

    uVar22 = uVar21 + uVar2 * 0x10000;

    uVar13 = iVar19 + (unsigned int)(uVar22 < uVar21) + (uVar2 >> 0x10) + (uVar13 >> 0x10) * (uVar3 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

      uVar13 = ~uVar13;

      if (uVar22 == 0) {

        uVar13 = uVar13 + 1;

      }

      else {

        uVar22 = ~uVar22 + 1;

      }

    }

    if (((unsigned char)(uVar17 >> 1) & 1) == 1) {

      uVar22 = uVar23 + uVar22;

      uVar6 = uVar13 + (uVar22 < uVar23) + (uVar6 & 0xffff);

      if ((int)uVar6 < -0x8000) {

        uVar6 = 0xffff8000;

        uVar22 = 0;

      }

      if (0x7fff < (int)uVar6) {

        uVar6 = 0x7fff;

        uVar22 = 0xffffffff;

      }

      uVar6 = uVar6 & 0xffff;

    }

    else {

      uVar22 = uVar23 + uVar22;

      uVar6 = uVar13 + (uVar22 < uVar23) + uVar6;

    }

    uVar3 = puVar11[8];

    uVar13 = puVar14[-4];

    puVar8 = puVar14 + -3;

    uVar1 = uVar3 ^ uVar13;

    if ((int)uVar3 < 0) {

      uVar3 = -uVar3;

    }

    if ((int)uVar13 < 0) {

      uVar13 = -uVar13;

    }

    uVar21 = (uVar13 & 0xffff) * (uVar3 & 0xffff);

    iVar20 = (uVar13 >> 0x10) * (uVar3 & 0xffff);

    iVar19 = 0;

    uVar2 = iVar20 + (uVar13 & 0xffff) * (uVar3 >> 0x10);

    if (iVar20 != 0) {

      iVar19 = 0x10000;

    }

    uVar23 = uVar21 + uVar2 * 0x10000;

    uVar13 = iVar19 + (unsigned int)(uVar23 < uVar21) + (uVar2 >> 0x10) + (uVar13 >> 0x10) * (uVar3 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

      uVar13 = ~uVar13;

      if (uVar23 == 0) {

        uVar13 = uVar13 + 1;

      }

      else {

        uVar23 = ~uVar23 + 1;

      }

    }

    if (((unsigned char)(uVar17 >> 1) & 1) == 1) {

      uVar23 = uVar22 + uVar23;

      uVar6 = uVar13 + (uVar23 < uVar22) + (uVar6 & 0xffff);

      if ((int)uVar6 < -0x8000) {

        uVar6 = 0xffff8000;

        uVar23 = 0;

      }

      if (0x7fff < (int)uVar6) {

        uVar6 = 0x7fff;

        uVar23 = 0xffffffff;

      }

      uVar6 = uVar6 & 0xffff;

    }

    else {

      uVar23 = uVar22 + uVar23;

      uVar6 = uVar13 + (uVar23 < uVar22) + uVar6;

    }

    *(unsigned int *)(puVar5 + 8) = uVar6 << 0x10 | uVar23 >> 0x10;

    uVar13 = *(unsigned int *)puVar5;

    uVar6 = *puVar9;

    uVar3 = uVar13 ^ uVar6;

    if ((int)uVar13 < 0) {

      uVar13 = -uVar13;

    }

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    uVar2 = (uVar6 & 0xffff) * (uVar13 & 0xffff);

    iVar20 = (uVar6 >> 0x10) * (uVar13 & 0xffff);

    iVar19 = 0;

    uVar1 = iVar20 + (uVar6 & 0xffff) * (uVar13 >> 0x10);

    if (iVar20 != 0) {

      iVar19 = 0x10000;

    }

    uVar21 = uVar2 + uVar1 * 0x10000;

    uVar6 = iVar19 + (unsigned int)(uVar21 < uVar2) + (uVar1 >> 0x10) + (uVar6 >> 0x10) * (uVar13 >> 0x10);

    if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

      uVar6 = ~uVar6;

      if (uVar21 == 0) {

        uVar6 = uVar6 + 1;

      }

      else {

        uVar21 = ~uVar21 + 1;

      }

    }

    if (((unsigned char)(uVar17 >> 1) & 1) == 1) {

      if ((int)uVar6 < -0x8000) {

        uVar6 = 0xffff8000;

        uVar21 = 0;

      }

      if (0x7fff < (int)uVar6) {

        uVar6 = 0x7fff;

        uVar21 = 0xffffffff;

      }

      uVar6 = uVar6 & 0xffff;

    }

    uVar3 = *(unsigned int *)(puVar5 + 4);

    uVar13 = puVar9[1];

    uVar1 = uVar3 ^ uVar13;

    if ((int)uVar3 < 0) {

      uVar3 = -uVar3;

    }

    if ((int)uVar13 < 0) {

      uVar13 = -uVar13;

    }

    uVar23 = (uVar13 & 0xffff) * (uVar3 & 0xffff);

    iVar20 = (uVar13 >> 0x10) * (uVar3 & 0xffff);

    iVar19 = 0;

    uVar2 = iVar20 + (uVar13 & 0xffff) * (uVar3 >> 0x10);

    if (iVar20 != 0) {

      iVar19 = 0x10000;

    }

    uVar22 = uVar23 + uVar2 * 0x10000;

    uVar13 = iVar19 + (unsigned int)(uVar22 < uVar23) + (uVar2 >> 0x10) + (uVar13 >> 0x10) * (uVar3 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

      uVar13 = ~uVar13;

      if (uVar22 == 0) {

        uVar13 = uVar13 + 1;

      }

      else {

        uVar22 = ~uVar22 + 1;

      }

    }

    if (((unsigned char)(uVar17 >> 1) & 1) == 1) {

      uVar22 = uVar21 + uVar22;

      uVar6 = uVar13 + (uVar22 < uVar21) + (uVar6 & 0xffff);

      if ((int)uVar6 < -0x8000) {

        uVar6 = 0xffff8000;

        uVar22 = 0;

      }

      if (0x7fff < (int)uVar6) {

        uVar6 = 0x7fff;

        uVar22 = 0xffffffff;

      }

      uVar6 = uVar6 & 0xffff;

    }

    else {

      uVar22 = uVar21 + uVar22;

      uVar6 = uVar13 + (uVar22 < uVar21) + uVar6;

    }

    uVar3 = *(unsigned int *)(puVar5 + 8);

    uVar13 = puVar9[2];

    uVar1 = uVar3 ^ uVar13;

    if ((int)uVar3 < 0) {

      uVar3 = -uVar3;

    }

    if ((int)uVar13 < 0) {

      uVar13 = -uVar13;

    }

    uVar21 = (uVar13 & 0xffff) * (uVar3 & 0xffff);

    iVar20 = (uVar13 >> 0x10) * (uVar3 & 0xffff);

    iVar19 = 0;

    uVar2 = iVar20 + (uVar13 & 0xffff) * (uVar3 >> 0x10);

    if (iVar20 != 0) {

      iVar19 = 0x10000;

    }

    uVar23 = uVar21 + uVar2 * 0x10000;

    uVar13 = iVar19 + (unsigned int)(uVar23 < uVar21) + (uVar2 >> 0x10) + (uVar13 >> 0x10) * (uVar3 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

      uVar13 = ~uVar13;

      if (uVar23 == 0) {

        uVar13 = uVar13 + 1;

      }

      else {

        uVar23 = ~uVar23 + 1;

      }

    }

    if (((unsigned char)(uVar17 >> 1) & 1) == 1) {

      uVar23 = uVar22 + uVar23;

      uVar6 = uVar13 + (uVar23 < uVar22) + (uVar6 & 0xffff);

      if ((int)uVar6 < -0x8000) {

        uVar6 = 0xffff8000;

        uVar23 = 0;

      }

      if (0x7fff < (int)uVar6) {

        uVar6 = 0x7fff;

        uVar23 = 0xffffffff;

      }

      uVar6 = uVar6 & 0xffff;

    }

    else {

      uVar23 = uVar22 + uVar23;

      uVar6 = uVar13 + (uVar23 < uVar22) + uVar6;

    }

    uVar6 = uVar6 << 0x10 | uVar23 >> 0x10;

    uVar18 = uVar18 | 0 < (int)uVar6;

    if (((unsigned char)uVar18 & 1) != 1) goto LAB_0602aa74;

  }

  FUN_0602ab3a();

  *puVar9 = extraout_r3_00;

  puVar9 = puVar9 + 1;

  FUN_0602ab00();

  FUN_0602ab3a();

  FUN_0602aaa0();

  *puVar9 = extraout_r3_01;

  puVar9 = puVar9 + 1;

  FUN_0602ab00();

  FUN_0602ab3a();

  FUN_0602aaa0();

  *puVar9 = extraout_r3_02;

  puVar9 = puVar9 + 1;

  FUN_0602ab00();

  FUN_0602ab3a();

  FUN_0602aaa0();

  *puVar9 = extraout_r3_03;

  FUN_0602ab00();

  puVar5 = 0x0608AC20;

  uVar17 = *(unsigned int *)0x060620D0 & 0xffff;

  iVar15 = (int)DAT_0602a97e;

  uVar6 = *(unsigned int *)(puVar4 + -0x20);

  iVar19 = *(int *)(puVar4 + -0x18);

  puVar8 = *(unsigned int **)(puVar4 + -0x10);

  iVar20 = *(int *)(puVar4 + -8);

  uVar18 = uVar18 & 0xfffffffe;

  if (((iVar15 <= (int)uVar6) || (iVar15 <= iVar19)) ||

     ((iVar15 <= (int)puVar8 || (iVar15 <= iVar20)))) {

    iVar15 = (int)DAT_0602aa12;

    uVar13 = uVar18 | (int)uVar6 < iVar15;

    if ((((((unsigned char)uVar13 & 1) == 1) || (uVar13 = uVar18 | iVar19 < iVar15, ((unsigned char)uVar13 & 1) == 1))

        || (uVar13 = uVar18 | (int)puVar8 < iVar15, ((unsigned char)uVar13 & 1) == 1)) ||

       (uVar18 = uVar18 | iVar20 < iVar15, uVar13 = uVar18, ((unsigned char)uVar18 & 1) != 1)) {

      iVar16 = (int)DAT_0602aa14;

      iVar15 = *(int *)(puVar4 + -0x1c);

      iVar7 = *(int *)(puVar4 + -0x14);

      iVar10 = *(int *)(puVar4 + -0xc);

      iVar12 = *(int *)(puVar4 + -4);

      uVar18 = uVar13 & 0xfffffffe;

      if (((iVar16 <= iVar15) || (iVar16 <= iVar7)) ||

         ((iVar16 <= iVar10 || (uVar18 = uVar18 | iVar12 < iVar16, ((unsigned char)uVar18 & 1) != 1)))) {

        iVar16 = (int)DAT_0602aa16;

        uVar18 = uVar18 & 0xfffffffe;

        if (((iVar15 < iVar16) || (iVar7 < iVar16)) || ((iVar10 < iVar16 || (iVar12 < iVar16)))) {

          *(short *)(0x0608AC20 + uVar17 * 0x18 + 0x16) = (short)iVar12;

          *(short *)(puVar5 + uVar17 * 0x18 + 0x14) = (short)iVar20;

          *(short *)(puVar5 + uVar17 * 0x18 + 0x12) = (short)iVar10;

          *(short *)(puVar5 + uVar17 * 0x18 + 0x10) = (short)puVar8;

          *(short *)(puVar5 + uVar17 * 0x18 + 0xe) = (short)iVar7;

          *(short *)(puVar5 + uVar17 * 0x18 + 0xc) = (short)iVar19;

          *(short *)(puVar5 + uVar17 * 0x18 + 10) = (short)iVar15;

          *(short *)(puVar5 + uVar17 * 0x18 + 8) = (short)uVar6;

          *(short *)(puVar5 + uVar17 * 0x18 + 6) = *(short *)((int)puVar14 + -10);

          puVar5[uVar17 * 0x18 + 4] = (unsigned char)((unsigned int)(int)*(short *)(puVar14 + -3) >> 4) & 0xf;

          puVar5[uVar17 * 0x18 + 5] = unaff_r13;

          uVar18 = (**(void **)(0x0602ABA4 + ((int)*(short *)(puVar14 + -3) & 7U) * 4))

                             (DAT_0602ab8c,DAT_0602ab90,DAT_0602ab94);

          return uVar18;

        }

      }

    }

  }

  goto LAB_0602aa74;

}
