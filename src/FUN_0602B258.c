extern int DAT_0602b082;

extern int DAT_0602b116;

extern int DAT_0602b118;

extern int DAT_0602b11a;

extern int DAT_0602b290;

extern int DAT_0602b292;

extern int DAT_0602b294;

extern int DAT_0602b296;

extern int DAT_0602b2ec;

extern int DAT_0602b2f0;

extern int DAT_0602b2f4;

extern void FUN_0602b1d6();
extern void FUN_0602b298();

void FUN_0602b258()
{

  unsigned int uVar1;

  unsigned int uVar2;

  unsigned int uVar3;

  char *puVar4;

  char *puVar5;

  int in_r0;

  unsigned int extraout_r1;

  int in_r1;

  unsigned int extraout_r2;

  int in_r2;

  unsigned int extraout_r3;

  unsigned int extraout_r3_00;

  unsigned int extraout_r3_01;

  unsigned int extraout_r3_02;

  unsigned int extraout_r3_03;

  int iVar6;

  int in_r3;

  int iVar7;

  unsigned int *puVar8;

  int iVar9;

  unsigned int *puVar10;

  int iVar11;

  int iVar12;

  unsigned int *puVar13;

  unsigned int *unaff_r8;

  int *unaff_r11;

  int iVar14;

  int iVar15;

  int *unaff_r12;

  char unaff_r13;

  unsigned int uVar16;

  unsigned int uVar17;

  unsigned int in_sr;

  unsigned int uVar18;

  unsigned int uVar19;

  int iVar20;

  int iVar21;

  unsigned int uVar22;

  unsigned int uVar23;

  unsigned int uVar24;

  int in_stack_00000000;

  iVar20 = (int)((unsigned long long)((long long)*(int *)(DAT_0602b290 + 0x1c) * (long long)in_r1) >> 0x20);

  iVar21 = (int)((unsigned long long)((long long)*(int *)(DAT_0602b290 + 0x1c) * (long long)-in_r2) >> 0x20);

  *unaff_r11 = iVar20;

  unaff_r11[1] = iVar21;

  uVar17 = in_sr & 0xfffffffe;

  uVar18 = uVar17 | DAT_0602b292 < iVar20;

  if ((((((unsigned char)uVar18 & 1) != 1) &&

       (uVar18 = uVar17 | iVar20 < DAT_0602b294, ((unsigned char)uVar18 & 1) != 1)) &&

      (uVar18 = uVar17 | DAT_0602b296 < iVar21, ((unsigned char)uVar18 & 1) != 1)) &&

     (uVar18 = uVar17 | iVar21 < DAT_0602b294, ((unsigned char)uVar18 & 1) != 1)) {

    *unaff_r12 = in_r0;

    unaff_r12[1] = iVar20;

    unaff_r12[2] = iVar21;

    unaff_r12[3] = in_r3;

    return;

  }

LAB_0602b19e:

  do {

    puVar13 = unaff_r8;

    puVar4 = 0x0602B2C8;

    in_stack_00000000 = in_stack_00000000 + -1;

    uVar17 = uVar18 & 0xfffffffe | (unsigned int)(in_stack_00000000 == 0);

    if (((unsigned char)uVar17 & 1) == 1) {

      return;

    }

    unaff_r8 = puVar13 + -6;

    puVar10 = *(unsigned int **)0x06089EDC;

    puVar8 = (unsigned int *)0x0602B2E8;

    FUN_0602b1d6(*(short *)(puVar13 + -2));

    *puVar8 = extraout_r1;

    puVar8[1] = extraout_r2;

    puVar8[2] = extraout_r3;

    *(unsigned int *)0x0602B310 = extraout_r2;

    puVar5 = 0x0602B2F8;

    uVar18 = uVar17 & 0xfffffffe;

    if ((puVar13[-3] & 0x80000) == 0) {

      uVar19 = *puVar10;

      uVar16 = *unaff_r8;

      uVar3 = uVar19 ^ uVar16;

      if ((int)uVar19 < 0) {

        uVar19 = -uVar19;

      }

      if ((int)uVar16 < 0) {

        uVar16 = -uVar16;

      }

      uVar2 = (uVar16 & 0xffff) * (uVar19 & 0xffff);

      iVar21 = (uVar16 >> 0x10) * (uVar19 & 0xffff);

      iVar20 = 0;

      uVar1 = iVar21 + (uVar16 & 0xffff) * (uVar19 >> 0x10);

      if (iVar21 != 0) {

        iVar20 = 0x10000;

      }

      uVar22 = uVar2 + uVar1 * 0x10000;

      uVar16 = iVar20 + (unsigned int)(uVar22 < uVar2) + (uVar1 >> 0x10) +

               (uVar16 >> 0x10) * (uVar19 >> 0x10);

      if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

        uVar16 = ~uVar16;

        if (uVar22 == 0) {

          uVar16 = uVar16 + 1;

        }

        else {

          uVar22 = ~uVar22 + 1;

        }

      }

      if (((unsigned char)(uVar17 >> 1) & 1) == 1) {

        if ((int)uVar16 < -0x8000) {

          uVar16 = 0xffff8000;

          uVar22 = 0;

        }

        if (0x7fff < (int)uVar16) {

          uVar16 = 0x7fff;

          uVar22 = 0xffffffff;

        }

        uVar16 = uVar16 & 0xffff;

      }

      uVar3 = puVar10[1];

      uVar19 = puVar13[-5];

      uVar1 = uVar3 ^ uVar19;

      if ((int)uVar3 < 0) {

        uVar3 = -uVar3;

      }

      if ((int)uVar19 < 0) {

        uVar19 = -uVar19;

      }

      uVar24 = (uVar19 & 0xffff) * (uVar3 & 0xffff);

      iVar21 = (uVar19 >> 0x10) * (uVar3 & 0xffff);

      iVar20 = 0;

      uVar2 = iVar21 + (uVar19 & 0xffff) * (uVar3 >> 0x10);

      if (iVar21 != 0) {

        iVar20 = 0x10000;

      }

      uVar23 = uVar24 + uVar2 * 0x10000;

      uVar19 = iVar20 + (unsigned int)(uVar23 < uVar24) + (uVar2 >> 0x10) +

               (uVar19 >> 0x10) * (uVar3 >> 0x10);

      if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

        uVar19 = ~uVar19;

        if (uVar23 == 0) {

          uVar19 = uVar19 + 1;

        }

        else {

          uVar23 = ~uVar23 + 1;

        }

      }

      if (((unsigned char)(uVar17 >> 1) & 1) == 1) {

        uVar23 = uVar22 + uVar23;

        uVar16 = uVar19 + (uVar23 < uVar22) + (uVar16 & 0xffff);

        if ((int)uVar16 < -0x8000) {

          uVar16 = 0xffff8000;

          uVar23 = 0;

        }

        if (0x7fff < (int)uVar16) {

          uVar16 = 0x7fff;

          uVar23 = 0xffffffff;

        }

        uVar16 = uVar16 & 0xffff;

      }

      else {

        uVar23 = uVar22 + uVar23;

        uVar16 = uVar19 + (uVar23 < uVar22) + uVar16;

      }

      uVar3 = puVar10[2];

      uVar19 = puVar13[-4];

      uVar1 = uVar3 ^ uVar19;

      if ((int)uVar3 < 0) {

        uVar3 = -uVar3;

      }

      if ((int)uVar19 < 0) {

        uVar19 = -uVar19;

      }

      uVar22 = (uVar19 & 0xffff) * (uVar3 & 0xffff);

      iVar21 = (uVar19 >> 0x10) * (uVar3 & 0xffff);

      iVar20 = 0;

      uVar2 = iVar21 + (uVar19 & 0xffff) * (uVar3 >> 0x10);

      if (iVar21 != 0) {

        iVar20 = 0x10000;

      }

      uVar24 = uVar22 + uVar2 * 0x10000;

      uVar19 = iVar20 + (unsigned int)(uVar24 < uVar22) + (uVar2 >> 0x10) +

               (uVar19 >> 0x10) * (uVar3 >> 0x10);

      if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

        uVar19 = ~uVar19;

        if (uVar24 == 0) {

          uVar19 = uVar19 + 1;

        }

        else {

          uVar24 = ~uVar24 + 1;

        }

      }

      if (((unsigned char)(uVar17 >> 1) & 1) == 1) {

        uVar24 = uVar23 + uVar24;

        uVar16 = uVar19 + (uVar24 < uVar23) + (uVar16 & 0xffff);

        if ((int)uVar16 < -0x8000) {

          uVar16 = 0xffff8000;

          uVar24 = 0;

        }

        if (0x7fff < (int)uVar16) {

          uVar16 = 0x7fff;

          uVar24 = 0xffffffff;

        }

        uVar16 = uVar16 & 0xffff;

      }

      else {

        uVar24 = uVar23 + uVar24;

        uVar16 = uVar19 + (uVar24 < uVar23) + uVar16;

      }

      uVar3 = puVar10[3];

      uVar19 = *unaff_r8;

      uVar1 = uVar3 ^ uVar19;

      if ((int)uVar3 < 0) {

        uVar3 = -uVar3;

      }

      if ((int)uVar19 < 0) {

        uVar19 = -uVar19;

      }

      uVar22 = (uVar19 & 0xffff) * (uVar3 & 0xffff);

      iVar21 = (uVar19 >> 0x10) * (uVar3 & 0xffff);

      iVar20 = 0;

      uVar2 = iVar21 + (uVar19 & 0xffff) * (uVar3 >> 0x10);

      if (iVar21 != 0) {

        iVar20 = 0x10000;

      }

      uVar23 = uVar22 + uVar2 * 0x10000;

      uVar19 = iVar20 + (unsigned int)(uVar23 < uVar22) + (uVar2 >> 0x10) +

               (uVar19 >> 0x10) * (uVar3 >> 0x10);

      if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

        uVar19 = ~uVar19;

        if (uVar23 == 0) {

          uVar19 = uVar19 + 1;

        }

        else {

          uVar23 = ~uVar23 + 1;

        }

      }

      if (((unsigned char)(uVar17 >> 1) & 1) == 1) {

        if ((int)uVar19 < -0x8000) {

          uVar19 = 0xffff8000;

          uVar23 = 0;

        }

        if (0x7fff < (int)uVar19) {

          uVar19 = 0x7fff;

          uVar23 = 0xffffffff;

        }

        uVar19 = uVar19 & 0xffff;

      }

      *(unsigned int *)0x0602B2F8 = uVar16 << 0x10 | uVar24 >> 0x10;

      uVar3 = puVar10[4];

      uVar16 = puVar13[-5];

      uVar1 = uVar3 ^ uVar16;

      if ((int)uVar3 < 0) {

        uVar3 = -uVar3;

      }

      if ((int)uVar16 < 0) {

        uVar16 = -uVar16;

      }

      uVar22 = (uVar16 & 0xffff) * (uVar3 & 0xffff);

      iVar21 = (uVar16 >> 0x10) * (uVar3 & 0xffff);

      iVar20 = 0;

      uVar2 = iVar21 + (uVar16 & 0xffff) * (uVar3 >> 0x10);

      if (iVar21 != 0) {

        iVar20 = 0x10000;

      }

      uVar24 = uVar22 + uVar2 * 0x10000;

      uVar16 = iVar20 + (unsigned int)(uVar24 < uVar22) + (uVar2 >> 0x10) +

               (uVar16 >> 0x10) * (uVar3 >> 0x10);

      if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

        uVar16 = ~uVar16;

        if (uVar24 == 0) {

          uVar16 = uVar16 + 1;

        }

        else {

          uVar24 = ~uVar24 + 1;

        }

      }

      if (((unsigned char)(uVar17 >> 1) & 1) == 1) {

        uVar24 = uVar23 + uVar24;

        uVar19 = uVar16 + (uVar24 < uVar23) + (uVar19 & 0xffff);

        if ((int)uVar19 < -0x8000) {

          uVar19 = 0xffff8000;

          uVar24 = 0;

        }

        if (0x7fff < (int)uVar19) {

          uVar19 = 0x7fff;

          uVar24 = 0xffffffff;

        }

        uVar19 = uVar19 & 0xffff;

      }

      else {

        uVar24 = uVar23 + uVar24;

        uVar19 = uVar16 + (uVar24 < uVar23) + uVar19;

      }

      uVar3 = puVar10[5];

      uVar16 = puVar13[-4];

      uVar1 = uVar3 ^ uVar16;

      if ((int)uVar3 < 0) {

        uVar3 = -uVar3;

      }

      if ((int)uVar16 < 0) {

        uVar16 = -uVar16;

      }

      uVar22 = (uVar16 & 0xffff) * (uVar3 & 0xffff);

      iVar21 = (uVar16 >> 0x10) * (uVar3 & 0xffff);

      iVar20 = 0;

      uVar2 = iVar21 + (uVar16 & 0xffff) * (uVar3 >> 0x10);

      if (iVar21 != 0) {

        iVar20 = 0x10000;

      }

      uVar23 = uVar22 + uVar2 * 0x10000;

      uVar16 = iVar20 + (unsigned int)(uVar23 < uVar22) + (uVar2 >> 0x10) +

               (uVar16 >> 0x10) * (uVar3 >> 0x10);

      if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

        uVar16 = ~uVar16;

        if (uVar23 == 0) {

          uVar16 = uVar16 + 1;

        }

        else {

          uVar23 = ~uVar23 + 1;

        }

      }

      if (((unsigned char)(uVar17 >> 1) & 1) == 1) {

        uVar23 = uVar24 + uVar23;

        uVar19 = uVar16 + (uVar23 < uVar24) + (uVar19 & 0xffff);

        if ((int)uVar19 < -0x8000) {

          uVar19 = 0xffff8000;

          uVar23 = 0;

        }

        if (0x7fff < (int)uVar19) {

          uVar19 = 0x7fff;

          uVar23 = 0xffffffff;

        }

        uVar19 = uVar19 & 0xffff;

      }

      else {

        uVar23 = uVar24 + uVar23;

        uVar19 = uVar16 + (uVar23 < uVar24) + uVar19;

      }

      uVar3 = puVar10[6];

      uVar16 = *unaff_r8;

      uVar1 = uVar3 ^ uVar16;

      if ((int)uVar3 < 0) {

        uVar3 = -uVar3;

      }

      if ((int)uVar16 < 0) {

        uVar16 = -uVar16;

      }

      uVar22 = (uVar16 & 0xffff) * (uVar3 & 0xffff);

      iVar21 = (uVar16 >> 0x10) * (uVar3 & 0xffff);

      iVar20 = 0;

      uVar2 = iVar21 + (uVar16 & 0xffff) * (uVar3 >> 0x10);

      if (iVar21 != 0) {

        iVar20 = 0x10000;

      }

      uVar24 = uVar22 + uVar2 * 0x10000;

      uVar16 = iVar20 + (unsigned int)(uVar24 < uVar22) + (uVar2 >> 0x10) +

               (uVar16 >> 0x10) * (uVar3 >> 0x10);

      if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

        uVar16 = ~uVar16;

        if (uVar24 == 0) {

          uVar16 = uVar16 + 1;

        }

        else {

          uVar24 = ~uVar24 + 1;

        }

      }

      if (((unsigned char)(uVar17 >> 1) & 1) == 1) {

        if ((int)uVar16 < -0x8000) {

          uVar16 = 0xffff8000;

          uVar24 = 0;

        }

        if (0x7fff < (int)uVar16) {

          uVar16 = 0x7fff;

          uVar24 = 0xffffffff;

        }

        uVar16 = uVar16 & 0xffff;

      }

      *(unsigned int *)(puVar5 + 4) = uVar19 << 0x10 | uVar23 >> 0x10;

      uVar3 = puVar10[7];

      uVar19 = puVar13[-5];

      uVar1 = uVar3 ^ uVar19;

      if ((int)uVar3 < 0) {

        uVar3 = -uVar3;

      }

      if ((int)uVar19 < 0) {

        uVar19 = -uVar19;

      }

      uVar22 = (uVar19 & 0xffff) * (uVar3 & 0xffff);

      iVar21 = (uVar19 >> 0x10) * (uVar3 & 0xffff);

      iVar20 = 0;

      uVar2 = iVar21 + (uVar19 & 0xffff) * (uVar3 >> 0x10);

      if (iVar21 != 0) {

        iVar20 = 0x10000;

      }

      uVar23 = uVar22 + uVar2 * 0x10000;

      uVar19 = iVar20 + (unsigned int)(uVar23 < uVar22) + (uVar2 >> 0x10) +

               (uVar19 >> 0x10) * (uVar3 >> 0x10);

      if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

        uVar19 = ~uVar19;

        if (uVar23 == 0) {

          uVar19 = uVar19 + 1;

        }

        else {

          uVar23 = ~uVar23 + 1;

        }

      }

      if (((unsigned char)(uVar17 >> 1) & 1) == 1) {

        uVar23 = uVar24 + uVar23;

        uVar16 = uVar19 + (uVar23 < uVar24) + (uVar16 & 0xffff);

        if ((int)uVar16 < -0x8000) {

          uVar16 = 0xffff8000;

          uVar23 = 0;

        }

        if (0x7fff < (int)uVar16) {

          uVar16 = 0x7fff;

          uVar23 = 0xffffffff;

        }

        uVar16 = uVar16 & 0xffff;

      }

      else {

        uVar23 = uVar24 + uVar23;

        uVar16 = uVar19 + (uVar23 < uVar24) + uVar16;

      }

      uVar3 = puVar10[8];

      uVar19 = puVar13[-4];

      uVar1 = uVar3 ^ uVar19;

      if ((int)uVar3 < 0) {

        uVar3 = -uVar3;

      }

      if ((int)uVar19 < 0) {

        uVar19 = -uVar19;

      }

      uVar22 = (uVar19 & 0xffff) * (uVar3 & 0xffff);

      iVar21 = (uVar19 >> 0x10) * (uVar3 & 0xffff);

      iVar20 = 0;

      uVar2 = iVar21 + (uVar19 & 0xffff) * (uVar3 >> 0x10);

      if (iVar21 != 0) {

        iVar20 = 0x10000;

      }

      uVar24 = uVar22 + uVar2 * 0x10000;

      uVar19 = iVar20 + (unsigned int)(uVar24 < uVar22) + (uVar2 >> 0x10) +

               (uVar19 >> 0x10) * (uVar3 >> 0x10);

      if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

        uVar19 = ~uVar19;

        if (uVar24 == 0) {

          uVar19 = uVar19 + 1;

        }

        else {

          uVar24 = ~uVar24 + 1;

        }

      }

      if (((unsigned char)(uVar17 >> 1) & 1) == 1) {

        uVar24 = uVar23 + uVar24;

        uVar16 = uVar19 + (uVar24 < uVar23) + (uVar16 & 0xffff);

        if ((int)uVar16 < -0x8000) {

          uVar16 = 0xffff8000;

          uVar24 = 0;

        }

        if (0x7fff < (int)uVar16) {

          uVar16 = 0x7fff;

          uVar24 = 0xffffffff;

        }

        uVar16 = uVar16 & 0xffff;

      }

      else {

        uVar24 = uVar23 + uVar24;

        uVar16 = uVar19 + (uVar24 < uVar23) + uVar16;

      }

      *(unsigned int *)(puVar5 + 8) = uVar16 << 0x10 | uVar24 >> 0x10;

      uVar19 = *(unsigned int *)puVar5;

      uVar16 = *puVar8;

      uVar3 = uVar19 ^ uVar16;

      if ((int)uVar19 < 0) {

        uVar19 = -uVar19;

      }

      if ((int)uVar16 < 0) {

        uVar16 = -uVar16;

      }

      uVar2 = (uVar16 & 0xffff) * (uVar19 & 0xffff);

      iVar21 = (uVar16 >> 0x10) * (uVar19 & 0xffff);

      iVar20 = 0;

      uVar1 = iVar21 + (uVar16 & 0xffff) * (uVar19 >> 0x10);

      if (iVar21 != 0) {

        iVar20 = 0x10000;

      }

      uVar22 = uVar2 + uVar1 * 0x10000;

      uVar16 = iVar20 + (unsigned int)(uVar22 < uVar2) + (uVar1 >> 0x10) +

               (uVar16 >> 0x10) * (uVar19 >> 0x10);

      if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

        uVar16 = ~uVar16;

        if (uVar22 == 0) {

          uVar16 = uVar16 + 1;

        }

        else {

          uVar22 = ~uVar22 + 1;

        }

      }

      if (((unsigned char)(uVar17 >> 1) & 1) == 1) {

        if ((int)uVar16 < -0x8000) {

          uVar16 = 0xffff8000;

          uVar22 = 0;

        }

        if (0x7fff < (int)uVar16) {

          uVar16 = 0x7fff;

          uVar22 = 0xffffffff;

        }

        uVar16 = uVar16 & 0xffff;

      }

      uVar3 = *(unsigned int *)(puVar5 + 4);

      uVar19 = puVar8[1];

      uVar1 = uVar3 ^ uVar19;

      if ((int)uVar3 < 0) {

        uVar3 = -uVar3;

      }

      if ((int)uVar19 < 0) {

        uVar19 = -uVar19;

      }

      uVar24 = (uVar19 & 0xffff) * (uVar3 & 0xffff);

      iVar21 = (uVar19 >> 0x10) * (uVar3 & 0xffff);

      iVar20 = 0;

      uVar2 = iVar21 + (uVar19 & 0xffff) * (uVar3 >> 0x10);

      if (iVar21 != 0) {

        iVar20 = 0x10000;

      }

      uVar23 = uVar24 + uVar2 * 0x10000;

      uVar19 = iVar20 + (unsigned int)(uVar23 < uVar24) + (uVar2 >> 0x10) +

               (uVar19 >> 0x10) * (uVar3 >> 0x10);

      if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

        uVar19 = ~uVar19;

        if (uVar23 == 0) {

          uVar19 = uVar19 + 1;

        }

        else {

          uVar23 = ~uVar23 + 1;

        }

      }

      if (((unsigned char)(uVar17 >> 1) & 1) == 1) {

        uVar23 = uVar22 + uVar23;

        uVar16 = uVar19 + (uVar23 < uVar22) + (uVar16 & 0xffff);

        if ((int)uVar16 < -0x8000) {

          uVar16 = 0xffff8000;

          uVar23 = 0;

        }

        if (0x7fff < (int)uVar16) {

          uVar16 = 0x7fff;

          uVar23 = 0xffffffff;

        }

        uVar16 = uVar16 & 0xffff;

      }

      else {

        uVar23 = uVar22 + uVar23;

        uVar16 = uVar19 + (uVar23 < uVar22) + uVar16;

      }

      uVar3 = *(unsigned int *)(puVar5 + 8);

      uVar19 = puVar8[2];

      uVar1 = uVar3 ^ uVar19;

      if ((int)uVar3 < 0) {

        uVar3 = -uVar3;

      }

      if ((int)uVar19 < 0) {

        uVar19 = -uVar19;

      }

      uVar22 = (uVar19 & 0xffff) * (uVar3 & 0xffff);

      iVar21 = (uVar19 >> 0x10) * (uVar3 & 0xffff);

      iVar20 = 0;

      uVar2 = iVar21 + (uVar19 & 0xffff) * (uVar3 >> 0x10);

      if (iVar21 != 0) {

        iVar20 = 0x10000;

      }

      uVar24 = uVar22 + uVar2 * 0x10000;

      uVar19 = iVar20 + (unsigned int)(uVar24 < uVar22) + (uVar2 >> 0x10) +

               (uVar19 >> 0x10) * (uVar3 >> 0x10);

      if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

        uVar19 = ~uVar19;

        if (uVar24 == 0) {

          uVar19 = uVar19 + 1;

        }

        else {

          uVar24 = ~uVar24 + 1;

        }

      }

      if (((unsigned char)(uVar17 >> 1) & 1) == 1) {

        uVar24 = uVar23 + uVar24;

        uVar16 = uVar19 + (uVar24 < uVar23) + (uVar16 & 0xffff);

        if ((int)uVar16 < -0x8000) {

          uVar16 = 0xffff8000;

          uVar24 = 0;

        }

        if (0x7fff < (int)uVar16) {

          uVar16 = 0x7fff;

          uVar24 = 0xffffffff;

        }

        uVar16 = uVar16 & 0xffff;

      }

      else {

        uVar24 = uVar23 + uVar24;

        uVar16 = uVar19 + (uVar24 < uVar23) + uVar16;

      }

      uVar18 = uVar18 | 0 < (int)(uVar16 << 0x10 | uVar24 >> 0x10);

      if (((unsigned char)uVar18 & 1) != 1) goto LAB_0602b19e;

    }

    FUN_0602b298((int)*(short *)(puVar13 + -2));

    *puVar8 = extraout_r3_00;

    puVar8 = puVar8 + 1;

    FUN_0602b258();

    FUN_0602b298((int)*(short *)((int)puVar13 + -6));

    FUN_0602b1d6();

    *puVar8 = extraout_r3_01;

    puVar8 = puVar8 + 1;

    FUN_0602b258();

    FUN_0602b298((int)*(short *)(puVar13 + -1));

    FUN_0602b1d6();

    *puVar8 = extraout_r3_02;

    puVar8 = puVar8 + 1;

    FUN_0602b258();

    FUN_0602b298((int)*(short *)((int)puVar13 + -2));

    FUN_0602b1d6();

    *puVar8 = extraout_r3_03;

    FUN_0602b258();

    puVar5 = 0x0608AC20;

    uVar17 = *(unsigned int *)0x060620D0 & 0xffff;

    iVar14 = (int)DAT_0602b082;

    iVar20 = *(int *)(puVar4 + -0x20);

    iVar21 = *(int *)(puVar4 + -0x18);

    iVar7 = *(int *)(puVar4 + -0x10);

    iVar11 = *(int *)(puVar4 + -8);

    uVar18 = uVar18 & 0xfffffffe;

    if (((iVar14 <= iVar20) || (iVar14 <= iVar21)) || ((iVar14 <= iVar7 || (iVar14 <= iVar11)))) {

      iVar14 = (int)DAT_0602b116;

      uVar16 = uVar18 | iVar20 < iVar14;

      if (((((unsigned char)uVar16 & 1) == 1) || (uVar16 = uVar18 | iVar21 < iVar14, ((unsigned char)uVar16 & 1) == 1)

          ) || ((uVar16 = uVar18 | iVar7 < iVar14, ((unsigned char)uVar16 & 1) == 1 ||

                (uVar18 = uVar18 | iVar11 < iVar14, uVar16 = uVar18, ((unsigned char)uVar18 & 1) != 1)))) {

        iVar15 = (int)DAT_0602b118;

        iVar14 = *(int *)(puVar4 + -0x1c);

        iVar6 = *(int *)(puVar4 + -0x14);

        iVar9 = *(int *)(puVar4 + -0xc);

        iVar12 = *(int *)(puVar4 + -4);

        uVar18 = uVar16 & 0xfffffffe;

        if ((((iVar15 <= iVar14) || (iVar15 <= iVar6)) || (iVar15 <= iVar9)) ||

           (uVar18 = uVar18 | iVar12 < iVar15, ((unsigned char)uVar18 & 1) != 1)) {

          iVar15 = (int)DAT_0602b11a;

          uVar18 = uVar18 & 0xfffffffe;

          if (((iVar14 < iVar15) || (iVar6 < iVar15)) || ((iVar9 < iVar15 || (iVar12 < iVar15)))) {

            *(short *)(0x0608AC20 + uVar17 * 0x18 + 0x16) = (short)iVar12;

            *(short *)(puVar5 + uVar17 * 0x18 + 0x14) = (short)iVar11;

            *(short *)(puVar5 + uVar17 * 0x18 + 0x12) = (short)iVar9;

            *(short *)(puVar5 + uVar17 * 0x18 + 0x10) = (short)iVar7;

            *(short *)(puVar5 + uVar17 * 0x18 + 0xe) = (short)iVar6;

            *(short *)(puVar5 + uVar17 * 0x18 + 0xc) = (short)iVar21;

            *(short *)(puVar5 + uVar17 * 0x18 + 10) = (short)iVar14;

            *(short *)(puVar5 + uVar17 * 0x18 + 8) = (short)iVar20;

            *(short *)(puVar5 + uVar17 * 0x18 + 6) = *(short *)((int)puVar13 + -10);

            puVar5[uVar17 * 0x18 + 4] = (unsigned char)((unsigned int)(int)*(short *)(puVar13 + -3) >> 4) & 0xf;

            puVar5[uVar17 * 0x18 + 5] = unaff_r13;

            (**(void **)(0x0602B314 + ((int)*(short *)(puVar13 + -3) & 7U) * 4))

                      (DAT_0602b2ec,DAT_0602b2f0,DAT_0602b2f4);

            return;

          }

        }

      }

    }

  } while( true );

}
