extern int DAT_0602b64c;

extern int DAT_0602b64e;

extern int DAT_0602b67c;

extern int DAT_0602b68a;

extern int DAT_0602b6d2;

extern int DAT_0602b6d4;

extern int DAT_0602b6d6;

extern int DAT_0602b6d8;

extern int DAT_0602b6e6;

extern int DAT_0602b6f4;

extern int DAT_0602b73c;

extern int DAT_0602b73e;

extern int DAT_0602b740;

extern int DAT_0602b742;

extern int DAT_0602b750;

extern int DAT_0602b75e;

extern int DAT_0602b7a6;

extern int DAT_0602b7a8;

extern int DAT_0602b7aa;

extern int DAT_0602b7ac;

extern int DAT_0602b7ba;

extern int DAT_0602b7c8;

extern int DAT_0602b7f8;

extern int PTR_DAT_0602b650;

extern int PTR_DAT_0602b650;

unsigned int FUN_0602b572(param_1)
    unsigned int *param_1;
{

  short sVar1;

  short sVar2;

  unsigned int uVar3;

  char *puVar4;

  char *puVar5;

  char *puVar6;

  char *puVar7;

  int iVar8;

  int iVar9;

  unsigned int uVar10;

  int *puVar11;

  unsigned int in_r2;

  int uVar12;

  int iVar13;

  short *psVar14;

  unsigned int *puVar15;

  unsigned int *puVar16;

  unsigned int *unaff_r8;

  int unaff_r10;

  short *unaff_r11;

  char unaff_r13;

  int unaff_r14;

  unsigned int uVar17;

  unsigned int in_sr;

  unsigned int uVar18;

  unsigned int uVar19;

  unsigned int uVar20;

  unsigned int uVar21;

  unsigned int uVar22;

  unsigned int uVar23;

  unsigned int uVar24;

  unsigned int uVar25;

  unsigned int uVar26;

  int in_stack_00000000;

  do {

    param_1[2] = in_r2;

    puVar4 = 0x06094A30;

    puVar16 = *(unsigned int **)0x06089EDC;

    uVar18 = *puVar16;

    uVar10 = *param_1;

    uVar17 = uVar18 ^ uVar10;

    if ((int)uVar18 < 0) {

      uVar18 = -uVar18;

    }

    if ((int)uVar10 < 0) {

      uVar10 = -uVar10;

    }

    uVar3 = (uVar10 & 0xffff) * (uVar18 & 0xffff);

    iVar9 = (uVar10 >> 0x10) * (uVar18 & 0xffff);

    iVar8 = 0;

    uVar19 = iVar9 + (uVar10 & 0xffff) * (uVar18 >> 0x10);

    if (iVar9 != 0) {

      iVar8 = 0x10000;

    }

    uVar26 = uVar3 + uVar19 * 0x10000;

    uVar10 = iVar8 + (unsigned int)(uVar26 < uVar3) + (uVar19 >> 0x10) + (uVar10 >> 0x10) * (uVar18 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar17 < 0) < 0) {

      uVar10 = ~uVar10;

      if (uVar26 == 0) {

        uVar10 = uVar10 + 1;

      }

      else {

        uVar26 = ~uVar26 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      if ((int)uVar10 < -0x8000) {

        uVar10 = 0xffff8000;

        uVar26 = 0;

      }

      if (0x7fff < (int)uVar10) {

        uVar10 = 0x7fff;

        uVar26 = 0xffffffff;

      }

      uVar10 = uVar10 & 0xffff;

    }

    uVar17 = puVar16[1];

    uVar18 = param_1[1];

    uVar19 = uVar17 ^ uVar18;

    if ((int)uVar17 < 0) {

      uVar17 = -uVar17;

    }

    if ((int)uVar18 < 0) {

      uVar18 = -uVar18;

    }

    uVar22 = (uVar18 & 0xffff) * (uVar17 & 0xffff);

    iVar9 = (uVar18 >> 0x10) * (uVar17 & 0xffff);

    iVar8 = 0;

    uVar3 = iVar9 + (uVar18 & 0xffff) * (uVar17 >> 0x10);

    if (iVar9 != 0) {

      iVar8 = 0x10000;

    }

    uVar25 = uVar22 + uVar3 * 0x10000;

    uVar18 = iVar8 + (unsigned int)(uVar25 < uVar22) + (uVar3 >> 0x10) + (uVar18 >> 0x10) * (uVar17 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar19 < 0) < 0) {

      uVar18 = ~uVar18;

      if (uVar25 == 0) {

        uVar18 = uVar18 + 1;

      }

      else {

        uVar25 = ~uVar25 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      uVar25 = uVar26 + uVar25;

      uVar10 = uVar18 + (uVar25 < uVar26) + (uVar10 & 0xffff);

      if ((int)uVar10 < -0x8000) {

        uVar10 = 0xffff8000;

        uVar25 = 0;

      }

      if (0x7fff < (int)uVar10) {

        uVar10 = 0x7fff;

        uVar25 = 0xffffffff;

      }

      uVar10 = uVar10 & 0xffff;

    }

    else {

      uVar25 = uVar26 + uVar25;

      uVar10 = uVar18 + (uVar25 < uVar26) + uVar10;

    }

    uVar17 = puVar16[2];

    uVar18 = param_1[2];

    uVar19 = uVar17 ^ uVar18;

    if ((int)uVar17 < 0) {

      uVar17 = -uVar17;

    }

    if ((int)uVar18 < 0) {

      uVar18 = -uVar18;

    }

    uVar26 = (uVar18 & 0xffff) * (uVar17 & 0xffff);

    iVar9 = (uVar18 >> 0x10) * (uVar17 & 0xffff);

    iVar8 = 0;

    uVar3 = iVar9 + (uVar18 & 0xffff) * (uVar17 >> 0x10);

    if (iVar9 != 0) {

      iVar8 = 0x10000;

    }

    uVar22 = uVar26 + uVar3 * 0x10000;

    uVar18 = iVar8 + (unsigned int)(uVar22 < uVar26) + (uVar3 >> 0x10) + (uVar18 >> 0x10) * (uVar17 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar19 < 0) < 0) {

      uVar18 = ~uVar18;

      if (uVar22 == 0) {

        uVar18 = uVar18 + 1;

      }

      else {

        uVar22 = ~uVar22 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      uVar22 = uVar25 + uVar22;

      uVar10 = uVar18 + (uVar22 < uVar25) + (uVar10 & 0xffff);

      if ((int)uVar10 < -0x8000) {

        uVar10 = 0xffff8000;

        uVar22 = 0;

      }

      if (0x7fff < (int)uVar10) {

        uVar10 = 0x7fff;

        uVar22 = 0xffffffff;

      }

      uVar10 = uVar10 & 0xffff;

    }

    else {

      uVar22 = uVar25 + uVar22;

      uVar10 = uVar18 + (uVar22 < uVar25) + uVar10;

    }

    uVar17 = puVar16[3];

    uVar18 = *param_1;

    uVar19 = uVar17 ^ uVar18;

    if ((int)uVar17 < 0) {

      uVar17 = -uVar17;

    }

    if ((int)uVar18 < 0) {

      uVar18 = -uVar18;

    }

    uVar26 = (uVar18 & 0xffff) * (uVar17 & 0xffff);

    iVar9 = (uVar18 >> 0x10) * (uVar17 & 0xffff);

    iVar8 = 0;

    uVar3 = iVar9 + (uVar18 & 0xffff) * (uVar17 >> 0x10);

    if (iVar9 != 0) {

      iVar8 = 0x10000;

    }

    uVar25 = uVar26 + uVar3 * 0x10000;

    uVar18 = iVar8 + (unsigned int)(uVar25 < uVar26) + (uVar3 >> 0x10) + (uVar18 >> 0x10) * (uVar17 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar19 < 0) < 0) {

      uVar18 = ~uVar18;

      if (uVar25 == 0) {

        uVar18 = uVar18 + 1;

      }

      else {

        uVar25 = ~uVar25 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      if ((int)uVar18 < -0x8000) {

        uVar18 = 0xffff8000;

        uVar25 = 0;

      }

      if (0x7fff < (int)uVar18) {

        uVar18 = 0x7fff;

        uVar25 = 0xffffffff;

      }

      uVar18 = uVar18 & 0xffff;

    }

    uVar19 = puVar16[4];

    uVar17 = param_1[1];

    uVar3 = uVar19 ^ uVar17;

    if ((int)uVar19 < 0) {

      uVar19 = -uVar19;

    }

    if ((int)uVar17 < 0) {

      uVar17 = -uVar17;

    }

    uVar23 = (uVar17 & 0xffff) * (uVar19 & 0xffff);

    iVar9 = (uVar17 >> 0x10) * (uVar19 & 0xffff);

    iVar8 = 0;

    uVar26 = iVar9 + (uVar17 & 0xffff) * (uVar19 >> 0x10);

    if (iVar9 != 0) {

      iVar8 = 0x10000;

    }

    uVar21 = uVar23 + uVar26 * 0x10000;

    uVar17 = iVar8 + (unsigned int)(uVar21 < uVar23) + (uVar26 >> 0x10) +

             (uVar17 >> 0x10) * (uVar19 >> 0x10);

    if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

      uVar17 = ~uVar17;

      if (uVar21 == 0) {

        uVar17 = uVar17 + 1;

      }

      else {

        uVar21 = ~uVar21 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      uVar21 = uVar25 + uVar21;

      uVar18 = uVar17 + (uVar21 < uVar25) + (uVar18 & 0xffff);

      if ((int)uVar18 < -0x8000) {

        uVar18 = 0xffff8000;

        uVar21 = 0;

      }

      if (0x7fff < (int)uVar18) {

        uVar18 = 0x7fff;

        uVar21 = 0xffffffff;

      }

      uVar18 = uVar18 & 0xffff;

    }

    else {

      uVar21 = uVar25 + uVar21;

      uVar18 = uVar17 + (uVar21 < uVar25) + uVar18;

    }

    *(unsigned int *)(0x06094A30 + 0x24) = (uVar10 << 0x10 | uVar22 >> 0x10) + puVar16[9];

    uVar17 = puVar16[5];

    uVar10 = param_1[2];

    uVar19 = uVar17 ^ uVar10;

    if ((int)uVar17 < 0) {

      uVar17 = -uVar17;

    }

    if ((int)uVar10 < 0) {

      uVar10 = -uVar10;

    }

    uVar26 = (uVar10 & 0xffff) * (uVar17 & 0xffff);

    iVar9 = (uVar10 >> 0x10) * (uVar17 & 0xffff);

    iVar8 = 0;

    uVar3 = iVar9 + (uVar10 & 0xffff) * (uVar17 >> 0x10);

    if (iVar9 != 0) {

      iVar8 = 0x10000;

    }

    uVar22 = uVar26 + uVar3 * 0x10000;

    uVar10 = iVar8 + (unsigned int)(uVar22 < uVar26) + (uVar3 >> 0x10) + (uVar10 >> 0x10) * (uVar17 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar19 < 0) < 0) {

      uVar10 = ~uVar10;

      if (uVar22 == 0) {

        uVar10 = uVar10 + 1;

      }

      else {

        uVar22 = ~uVar22 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      uVar22 = uVar21 + uVar22;

      uVar18 = uVar10 + (uVar22 < uVar21) + (uVar18 & 0xffff);

      if ((int)uVar18 < -0x8000) {

        uVar18 = 0xffff8000;

        uVar22 = 0;

      }

      if (0x7fff < (int)uVar18) {

        uVar18 = 0x7fff;

        uVar22 = 0xffffffff;

      }

      uVar18 = uVar18 & 0xffff;

    }

    else {

      uVar22 = uVar21 + uVar22;

      uVar18 = uVar10 + (uVar22 < uVar21) + uVar18;

    }

    uVar17 = puVar16[6];

    uVar10 = *param_1;

    uVar19 = uVar17 ^ uVar10;

    if ((int)uVar17 < 0) {

      uVar17 = -uVar17;

    }

    if ((int)uVar10 < 0) {

      uVar10 = -uVar10;

    }

    uVar26 = (uVar10 & 0xffff) * (uVar17 & 0xffff);

    iVar9 = (uVar10 >> 0x10) * (uVar17 & 0xffff);

    iVar8 = 0;

    uVar3 = iVar9 + (uVar10 & 0xffff) * (uVar17 >> 0x10);

    if (iVar9 != 0) {

      iVar8 = 0x10000;

    }

    uVar25 = uVar26 + uVar3 * 0x10000;

    uVar10 = iVar8 + (unsigned int)(uVar25 < uVar26) + (uVar3 >> 0x10) + (uVar10 >> 0x10) * (uVar17 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar19 < 0) < 0) {

      uVar10 = ~uVar10;

      if (uVar25 == 0) {

        uVar10 = uVar10 + 1;

      }

      else {

        uVar25 = ~uVar25 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      if ((int)uVar10 < -0x8000) {

        uVar10 = 0xffff8000;

        uVar25 = 0;

      }

      if (0x7fff < (int)uVar10) {

        uVar10 = 0x7fff;

        uVar25 = 0xffffffff;

      }

      uVar10 = uVar10 & 0xffff;

    }

    uVar19 = puVar16[7];

    uVar17 = param_1[1];

    uVar3 = uVar19 ^ uVar17;

    if ((int)uVar19 < 0) {

      uVar19 = -uVar19;

    }

    if ((int)uVar17 < 0) {

      uVar17 = -uVar17;

    }

    uVar23 = (uVar17 & 0xffff) * (uVar19 & 0xffff);

    iVar9 = (uVar17 >> 0x10) * (uVar19 & 0xffff);

    iVar8 = 0;

    uVar26 = iVar9 + (uVar17 & 0xffff) * (uVar19 >> 0x10);

    if (iVar9 != 0) {

      iVar8 = 0x10000;

    }

    uVar21 = uVar23 + uVar26 * 0x10000;

    uVar17 = iVar8 + (unsigned int)(uVar21 < uVar23) + (uVar26 >> 0x10) +

             (uVar17 >> 0x10) * (uVar19 >> 0x10);

    if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

      uVar17 = ~uVar17;

      if (uVar21 == 0) {

        uVar17 = uVar17 + 1;

      }

      else {

        uVar21 = ~uVar21 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      uVar21 = uVar25 + uVar21;

      uVar10 = uVar17 + (uVar21 < uVar25) + (uVar10 & 0xffff);

      if ((int)uVar10 < -0x8000) {

        uVar10 = 0xffff8000;

        uVar21 = 0;

      }

      if (0x7fff < (int)uVar10) {

        uVar10 = 0x7fff;

        uVar21 = 0xffffffff;

      }

      uVar10 = uVar10 & 0xffff;

    }

    else {

      uVar21 = uVar25 + uVar21;

      uVar10 = uVar17 + (uVar21 < uVar25) + uVar10;

    }

    *(unsigned int *)(puVar4 + 0x28) = (uVar18 << 0x10 | uVar22 >> 0x10) + puVar16[10];

    uVar17 = puVar16[8];

    uVar18 = param_1[2];

    uVar19 = uVar17 ^ uVar18;

    if ((int)uVar17 < 0) {

      uVar17 = -uVar17;

    }

    if ((int)uVar18 < 0) {

      uVar18 = -uVar18;

    }

    uVar26 = (uVar18 & 0xffff) * (uVar17 & 0xffff);

    iVar9 = (uVar18 >> 0x10) * (uVar17 & 0xffff);

    iVar8 = 0;

    uVar3 = iVar9 + (uVar18 & 0xffff) * (uVar17 >> 0x10);

    if (iVar9 != 0) {

      iVar8 = 0x10000;

    }

    uVar22 = uVar26 + uVar3 * 0x10000;

    uVar18 = iVar8 + (unsigned int)(uVar22 < uVar26) + (uVar3 >> 0x10) + (uVar18 >> 0x10) * (uVar17 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar19 < 0) < 0) {

      uVar18 = ~uVar18;

      if (uVar22 == 0) {

        uVar18 = uVar18 + 1;

      }

      else {

        uVar22 = ~uVar22 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      uVar22 = uVar21 + uVar22;

      uVar10 = uVar18 + (uVar22 < uVar21) + (uVar10 & 0xffff);

      if ((int)uVar10 < -0x8000) {

        uVar10 = 0xffff8000;

        uVar22 = 0;

      }

      if (0x7fff < (int)uVar10) {

        uVar10 = 0x7fff;

        uVar22 = 0xffffffff;

      }

      uVar10 = uVar10 & 0xffff;

    }

    else {

      uVar22 = uVar21 + uVar22;

      uVar10 = uVar18 + (uVar22 < uVar21) + uVar10;

    }

    *(unsigned int *)(puVar4 + 0x2c) = (uVar10 << 0x10 | uVar22 >> 0x10) + puVar16[0xb];

    iVar8 = *(int *)(puVar4 + 0x2c);

    uVar10 = in_sr & 0xfffffffe;

    unaff_r11[3] = (unsigned short)(iVar8 <= unaff_r10);

    iVar8 = (unsigned int)(iVar8 <= unaff_r10) + (int)unaff_r11[2] + (int)unaff_r11[1] + (int)*unaff_r11;

    uVar18 = uVar10 | iVar8 == 0;

    if (((unsigned char)uVar18 & 1) == 1) {

LAB_0602b600:

      puVar6 = 0x06094A90;

      puVar5 = 0x0608AC20;

      puVar4 = 0x06094A30;

      iVar8 = *(int *)0x060620D0;

      puVar11 = (int *)(int)DAT_0602b64c;

      uVar12 = *(int *)(0x06094A30 + 8);

      puVar11[4] = (int)DAT_0602b64e;

      *puVar11 = uVar12;

      puVar11[5] = 0;

      iVar13 = *(int *)(puVar4 + 4);

      iVar9 = puVar11[7];

      *(int *)puVar6 = (int)((unsigned long long)((long long)iVar9 * (long long)*(int *)puVar4) >> 0x20);

      *(int *)(puVar6 + 4) = (int)((unsigned long long)((long long)iVar9 * (long long)-iVar13) >> 0x20);

      puVar7 = 0x06094A20;

      iVar9 = *(int *)puVar6;

      iVar13 = *(int *)(puVar6 + 4);

      *(short *)0x06094A20 = 0;

      uVar10 = uVar18 & 0xfffffffe;

      if (PTR_DAT_0602b650 < iVar9) {

        *(short *)puVar7 = 1;

      }

      else if (iVar9 < DAT_0602b67c) {

        *(short *)puVar7 = 1;

      }

      else if (DAT_0602b68a < iVar13) {

        *(short *)puVar7 = 1;

      }

      else if (iVar13 < DAT_0602b6d2) {

        *(short *)puVar7 = 1;

      }

      puVar11 = (int *)(int)DAT_0602b6d4;

      uVar12 = *(int *)(puVar4 + 0x14);

      puVar11[4] = (int)DAT_0602b6d6;

      *puVar11 = uVar12;

      puVar11[5] = 0;

      iVar13 = *(int *)(puVar4 + 0x10);

      iVar9 = puVar11[7];

      *(int *)(puVar6 + 8) =

           (int)((unsigned long long)((long long)iVar9 * (long long)*(int *)(puVar4 + 0xc)) >> 0x20);

      *(int *)(puVar6 + 0xc) = (int)((unsigned long long)((long long)iVar9 * (long long)-iVar13) >> 0x20);

      iVar9 = *(int *)(puVar6 + 8);

      iVar13 = *(int *)(puVar6 + 0xc);

      *(short *)(puVar7 + 2) = 0;

      if (DAT_0602b6d8 < iVar9) {

        *(short *)(puVar7 + 2) = 1;

      }

      else if (iVar9 < DAT_0602b6e6) {

        *(short *)(puVar7 + 2) = 1;

      }

      else if (DAT_0602b6f4 < iVar13) {

        *(short *)(puVar7 + 2) = 1;

      }

      else if (iVar13 < DAT_0602b73c) {

        *(short *)(puVar7 + 2) = 1;

      }

      puVar11 = (int *)(int)DAT_0602b73e;

      uVar12 = *(int *)(puVar4 + 0x20);

      puVar11[4] = (int)DAT_0602b740;

      *puVar11 = uVar12;

      puVar11[5] = 0;

      iVar13 = *(int *)(puVar4 + 0x1c);

      iVar9 = puVar11[7];

      *(int *)(puVar6 + 0x10) =

           (int)((unsigned long long)((long long)iVar9 * (long long)*(int *)(puVar4 + 0x18)) >> 0x20);

      *(int *)(puVar6 + 0x14) = (int)((unsigned long long)((long long)iVar9 * (long long)-iVar13) >> 0x20);

      iVar9 = *(int *)(puVar6 + 0x10);

      iVar13 = *(int *)(puVar6 + 0x14);

      *(short *)(puVar7 + 4) = 0;

      if (DAT_0602b742 < iVar9) {

        *(short *)(puVar7 + 4) = 1;

      }

      else if (iVar9 < DAT_0602b750) {

        *(short *)(puVar7 + 4) = 1;

      }

      else if (DAT_0602b75e < iVar13) {

        *(short *)(puVar7 + 4) = 1;

      }

      else if (iVar13 < DAT_0602b7a6) {

        *(short *)(puVar7 + 4) = 1;

      }

      puVar11 = (int *)(int)DAT_0602b7a8;

      uVar12 = *(int *)(puVar4 + 0x2c);

      puVar11[4] = (int)DAT_0602b7aa;

      *puVar11 = uVar12;

      puVar11[5] = 0;

      iVar13 = *(int *)(puVar4 + 0x28);

      iVar9 = puVar11[7];

      *(int *)(puVar6 + 0x18) =

           (int)((unsigned long long)((long long)iVar9 * (long long)*(int *)(puVar4 + 0x24)) >> 0x20);

      *(int *)(puVar6 + 0x1c) = (int)((unsigned long long)((long long)iVar9 * (long long)-iVar13) >> 0x20);

      iVar9 = *(int *)(puVar6 + 0x18);

      iVar13 = *(int *)(puVar6 + 0x1c);

      *(short *)(puVar7 + 6) = 0;

      if (DAT_0602b7ac < iVar9) {

        *(short *)(puVar7 + 6) = 1;

      }

      else if (iVar9 < DAT_0602b7ba) {

        *(short *)(puVar7 + 6) = 1;

      }

      else if (DAT_0602b7c8 < iVar13) {

        *(short *)(puVar7 + 6) = 1;

      }

      else if (iVar13 < DAT_0602b7f8) {

        *(short *)(puVar7 + 6) = 1;

      }

      if (((((int)0xFFFFFF50 <= *(int *)puVar6) ||

           ((int)0xFFFFFF50 <= *(int *)(puVar6 + 8))) ||

          ((int)0xFFFFFF50 <= *(int *)(puVar6 + 0x10))) ||

         (uVar18 = *(unsigned int *)(puVar6 + 0x18), (int)0xFFFFFF50 <= (int)uVar18)) {

        uVar17 = uVar10 | *(int *)puVar6 < 0x000000B0;

        if (((((unsigned char)uVar17 & 1) != 1) &&

            (uVar17 = uVar10 | *(int *)(puVar6 + 8) < 0x000000B0, ((unsigned char)uVar17 & 1) != 1)) &&

           (uVar17 = uVar10 | *(int *)(puVar6 + 0x10) < 0x000000B0, ((unsigned char)uVar17 & 1) != 1)) {

          uVar18 = *(unsigned int *)(puVar6 + 0x18);

          uVar17 = uVar10 | (int)uVar18 < 0x000000B0;

          uVar10 = uVar17;

          if (((unsigned char)uVar17 & 1) != 1) goto LAB_0602b972;

        }

        uVar10 = uVar17 & 0xfffffffe;

        if ((((int)0xFFFFFF81 <= *(int *)(puVar6 + 4)) ||

            ((int)0xFFFFFF81 <= *(int *)(puVar6 + 0xc))) ||

           (((int)0xFFFFFF81 <= *(int *)(puVar6 + 0x14) ||

            (uVar18 = *(unsigned int *)(puVar6 + 0x1c), (int)0xFFFFFF81 <= (int)uVar18)))) {

          uVar17 = uVar10 | *(int *)(puVar6 + 4) < 0x00000051;

          if (((((unsigned char)uVar17 & 1) != 1) &&

              (uVar17 = uVar10 | *(int *)(puVar6 + 0xc) < 0x00000051, ((unsigned char)uVar17 & 1) != 1)) &&

             (uVar17 = uVar10 | *(int *)(puVar6 + 0x14) < 0x00000051, ((unsigned char)uVar17 & 1) != 1)) {

            uVar18 = *(unsigned int *)(puVar6 + 0x1c);

            uVar17 = uVar10 | (int)uVar18 < 0x00000051;

            uVar10 = uVar17;

            if (((unsigned char)uVar17 & 1) != 1) goto LAB_0602b972;

          }

          iVar9 = (int)*(short *)(puVar7 + 6) +

                  (int)*(short *)puVar7 + (int)*(short *)(puVar7 + 2) + (int)*(short *)(puVar7 + 4);

          if (iVar9 != 4) {

            if (iVar9 != 0) {

              (*(void(*)())(*(int *)(0x0602B9BC + iVar9 * 4)))(puVar6,puVar7);

            }

            *(short *)(puVar5 + iVar8 * 0x18 + 8) = (short)*(int *)puVar6;

            *(short *)(puVar5 + iVar8 * 0x18 + 10) = (short)*(int *)(puVar6 + 4);

            *(short *)(puVar5 + iVar8 * 0x18 + 0xc) = (short)*(int *)(puVar6 + 8);

            *(short *)(puVar5 + iVar8 * 0x18 + 0xe) = (short)*(int *)(puVar6 + 0xc);

            *(short *)(puVar5 + iVar8 * 0x18 + 0x10) = (short)*(int *)(puVar6 + 0x10);

            *(short *)(puVar5 + iVar8 * 0x18 + 0x12) = (short)*(int *)(puVar6 + 0x14);

            *(short *)(puVar5 + iVar8 * 0x18 + 0x14) = (short)*(int *)(puVar6 + 0x18);

            *(short *)(puVar5 + iVar8 * 0x18 + 0x16) = (short)*(int *)(puVar6 + 0x1c);

            *(short *)(puVar5 + iVar8 * 0x18 + 6) = *(short *)((int)unaff_r8 + 0xe);

            puVar5[iVar8 * 0x18 + 4] = (unsigned char)((unsigned int)(int)*(short *)(unaff_r8 + 3) >> 4) & 0xf;

            puVar5[iVar8 * 0x18 + 5] = unaff_r13;

            uVar10 = (**(void **)(0x0602B9CC + ((int)*(short *)(unaff_r8 + 3) & 7U) * 4))

                               (*(int *)(0x06094A30 + 0x14),

                                *(int *)(0x06094A30 + 0x20),

                                *(int *)(0x06094A30 + 0x2c));

            return uVar10;

          }

          uVar18 = 4;

          uVar10 = uVar17 & 0xfffffffe;

        }

      }

    }

    else {

      if (iVar8 != 4) {

        (*(void(*)())(*(int *)(0x0602B9AC + iVar8 * 4)))(0x06094A30,0x06094A28,puVar16 + 9,puVar16 + 0xc);

        uVar18 = uVar10;

        goto LAB_0602b600;

      }

      uVar18 = 4;

    }

LAB_0602b972:

    do {

      puVar16 = unaff_r8;

      puVar4 = 0x06094AB0;

      in_stack_00000000 = in_stack_00000000 + -1;

      uVar17 = uVar10 & 0xfffffffe;

      if (in_stack_00000000 == 0) {

        return uVar18;

      }

      unaff_r8 = puVar16 + -6;

      psVar14 = (short *)((unsigned int)*(unsigned short *)(puVar16 + -2) * 6 + unaff_r14);

      sVar1 = psVar14[1];

      sVar2 = psVar14[2];

      *(int *)0x06094AB0 = (int)*psVar14 << 0xb;

      *(int *)(puVar4 + 4) = (int)sVar1 << 0xb;

      *(int *)(puVar4 + 8) = (int)sVar2 << 0xb;

      puVar5 = 0x06094A30;

      puVar15 = *(unsigned int **)0x06089EDC;

      uVar19 = *puVar15;

      uVar18 = *(unsigned int *)puVar4;

      uVar3 = uVar19 ^ uVar18;

      if ((int)uVar19 < 0) {

        uVar19 = -uVar19;

      }

      if ((int)uVar18 < 0) {

        uVar18 = -uVar18;

      }

      uVar22 = (uVar18 & 0xffff) * (uVar19 & 0xffff);

      iVar9 = (uVar18 >> 0x10) * (uVar19 & 0xffff);

      iVar8 = 0;

      uVar26 = iVar9 + (uVar18 & 0xffff) * (uVar19 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar25 = uVar22 + uVar26 * 0x10000;

      uVar18 = iVar8 + (unsigned int)(uVar25 < uVar22) + (uVar26 >> 0x10) +

               (uVar18 >> 0x10) * (uVar19 >> 0x10);

      if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

        uVar18 = ~uVar18;

        if (uVar25 == 0) {

          uVar18 = uVar18 + 1;

        }

        else {

          uVar25 = ~uVar25 + 1;

        }

      }

      if (((unsigned char)(uVar10 >> 1) & 1) == 1) {

        if ((int)uVar18 < -0x8000) {

          uVar18 = 0xffff8000;

          uVar25 = 0;

        }

        if (0x7fff < (int)uVar18) {

          uVar18 = 0x7fff;

          uVar25 = 0xffffffff;

        }

        uVar18 = uVar18 & 0xffff;

      }

      uVar3 = puVar15[1];

      uVar19 = *(unsigned int *)(puVar4 + 4);

      uVar26 = uVar3 ^ uVar19;

      if ((int)uVar3 < 0) {

        uVar3 = -uVar3;

      }

      if ((int)uVar19 < 0) {

        uVar19 = -uVar19;

      }

      uVar23 = (uVar19 & 0xffff) * (uVar3 & 0xffff);

      iVar9 = (uVar19 >> 0x10) * (uVar3 & 0xffff);

      iVar8 = 0;

      uVar22 = iVar9 + (uVar19 & 0xffff) * (uVar3 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar21 = uVar23 + uVar22 * 0x10000;

      uVar19 = iVar8 + (unsigned int)(uVar21 < uVar23) + (uVar22 >> 0x10) +

               (uVar19 >> 0x10) * (uVar3 >> 0x10);

      if ((int)-(unsigned int)((int)uVar26 < 0) < 0) {

        uVar19 = ~uVar19;

        if (uVar21 == 0) {

          uVar19 = uVar19 + 1;

        }

        else {

          uVar21 = ~uVar21 + 1;

        }

      }

      if (((unsigned char)(uVar10 >> 1) & 1) == 1) {

        uVar21 = uVar25 + uVar21;

        uVar18 = uVar19 + (uVar21 < uVar25) + (uVar18 & 0xffff);

        if ((int)uVar18 < -0x8000) {

          uVar18 = 0xffff8000;

          uVar21 = 0;

        }

        if (0x7fff < (int)uVar18) {

          uVar18 = 0x7fff;

          uVar21 = 0xffffffff;

        }

        uVar18 = uVar18 & 0xffff;

      }

      else {

        uVar21 = uVar25 + uVar21;

        uVar18 = uVar19 + (uVar21 < uVar25) + uVar18;

      }

      uVar3 = puVar15[2];

      uVar19 = *(unsigned int *)(puVar4 + 8);

      uVar26 = uVar3 ^ uVar19;

      if ((int)uVar3 < 0) {

        uVar3 = -uVar3;

      }

      if ((int)uVar19 < 0) {

        uVar19 = -uVar19;

      }

      uVar25 = (uVar19 & 0xffff) * (uVar3 & 0xffff);

      iVar9 = (uVar19 >> 0x10) * (uVar3 & 0xffff);

      iVar8 = 0;

      uVar22 = iVar9 + (uVar19 & 0xffff) * (uVar3 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar23 = uVar25 + uVar22 * 0x10000;

      uVar19 = iVar8 + (unsigned int)(uVar23 < uVar25) + (uVar22 >> 0x10) +

               (uVar19 >> 0x10) * (uVar3 >> 0x10);

      if ((int)-(unsigned int)((int)uVar26 < 0) < 0) {

        uVar19 = ~uVar19;

        if (uVar23 == 0) {

          uVar19 = uVar19 + 1;

        }

        else {

          uVar23 = ~uVar23 + 1;

        }

      }

      if (((unsigned char)(uVar10 >> 1) & 1) == 1) {

        uVar23 = uVar21 + uVar23;

        uVar18 = uVar19 + (uVar23 < uVar21) + (uVar18 & 0xffff);

        if ((int)uVar18 < -0x8000) {

          uVar18 = 0xffff8000;

          uVar23 = 0;

        }

        if (0x7fff < (int)uVar18) {

          uVar18 = 0x7fff;

          uVar23 = 0xffffffff;

        }

        uVar18 = uVar18 & 0xffff;

      }

      else {

        uVar23 = uVar21 + uVar23;

        uVar18 = uVar19 + (uVar23 < uVar21) + uVar18;

      }

      uVar3 = puVar15[3];

      uVar19 = *(unsigned int *)puVar4;

      uVar26 = uVar3 ^ uVar19;

      if ((int)uVar3 < 0) {

        uVar3 = -uVar3;

      }

      if ((int)uVar19 < 0) {

        uVar19 = -uVar19;

      }

      uVar25 = (uVar19 & 0xffff) * (uVar3 & 0xffff);

      iVar9 = (uVar19 >> 0x10) * (uVar3 & 0xffff);

      iVar8 = 0;

      uVar22 = iVar9 + (uVar19 & 0xffff) * (uVar3 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar21 = uVar25 + uVar22 * 0x10000;

      uVar19 = iVar8 + (unsigned int)(uVar21 < uVar25) + (uVar22 >> 0x10) +

               (uVar19 >> 0x10) * (uVar3 >> 0x10);

      if ((int)-(unsigned int)((int)uVar26 < 0) < 0) {

        uVar19 = ~uVar19;

        if (uVar21 == 0) {

          uVar19 = uVar19 + 1;

        }

        else {

          uVar21 = ~uVar21 + 1;

        }

      }

      if (((unsigned char)(uVar10 >> 1) & 1) == 1) {

        if ((int)uVar19 < -0x8000) {

          uVar19 = 0xffff8000;

          uVar21 = 0;

        }

        if (0x7fff < (int)uVar19) {

          uVar19 = 0x7fff;

          uVar21 = 0xffffffff;

        }

        uVar19 = uVar19 & 0xffff;

      }

      uVar26 = puVar15[4];

      uVar3 = *(unsigned int *)(puVar4 + 4);

      uVar22 = uVar26 ^ uVar3;

      if ((int)uVar26 < 0) {

        uVar26 = -uVar26;

      }

      if ((int)uVar3 < 0) {

        uVar3 = -uVar3;

      }

      uVar24 = (uVar3 & 0xffff) * (uVar26 & 0xffff);

      iVar9 = (uVar3 >> 0x10) * (uVar26 & 0xffff);

      iVar8 = 0;

      uVar25 = iVar9 + (uVar3 & 0xffff) * (uVar26 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar20 = uVar24 + uVar25 * 0x10000;

      uVar3 = iVar8 + (unsigned int)(uVar20 < uVar24) + (uVar25 >> 0x10) +

              (uVar3 >> 0x10) * (uVar26 >> 0x10);

      if ((int)-(unsigned int)((int)uVar22 < 0) < 0) {

        uVar3 = ~uVar3;

        if (uVar20 == 0) {

          uVar3 = uVar3 + 1;

        }

        else {

          uVar20 = ~uVar20 + 1;

        }

      }

      if (((unsigned char)(uVar10 >> 1) & 1) == 1) {

        uVar20 = uVar21 + uVar20;

        uVar19 = uVar3 + (uVar20 < uVar21) + (uVar19 & 0xffff);

        if ((int)uVar19 < -0x8000) {

          uVar19 = 0xffff8000;

          uVar20 = 0;

        }

        if (0x7fff < (int)uVar19) {

          uVar19 = 0x7fff;

          uVar20 = 0xffffffff;

        }

        uVar19 = uVar19 & 0xffff;

      }

      else {

        uVar20 = uVar21 + uVar20;

        uVar19 = uVar3 + (uVar20 < uVar21) + uVar19;

      }

      *(unsigned int *)0x06094A30 = (uVar18 << 0x10 | uVar23 >> 0x10) + puVar15[9];

      uVar3 = puVar15[5];

      uVar18 = *(unsigned int *)(puVar4 + 8);

      uVar26 = uVar3 ^ uVar18;

      if ((int)uVar3 < 0) {

        uVar3 = -uVar3;

      }

      if ((int)uVar18 < 0) {

        uVar18 = -uVar18;

      }

      uVar25 = (uVar18 & 0xffff) * (uVar3 & 0xffff);

      iVar9 = (uVar18 >> 0x10) * (uVar3 & 0xffff);

      iVar8 = 0;

      uVar22 = iVar9 + (uVar18 & 0xffff) * (uVar3 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar23 = uVar25 + uVar22 * 0x10000;

      uVar18 = iVar8 + (unsigned int)(uVar23 < uVar25) + (uVar22 >> 0x10) +

               (uVar18 >> 0x10) * (uVar3 >> 0x10);

      if ((int)-(unsigned int)((int)uVar26 < 0) < 0) {

        uVar18 = ~uVar18;

        if (uVar23 == 0) {

          uVar18 = uVar18 + 1;

        }

        else {

          uVar23 = ~uVar23 + 1;

        }

      }

      if (((unsigned char)(uVar10 >> 1) & 1) == 1) {

        uVar23 = uVar20 + uVar23;

        uVar19 = uVar18 + (uVar23 < uVar20) + (uVar19 & 0xffff);

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

        uVar23 = uVar20 + uVar23;

        uVar19 = uVar18 + (uVar23 < uVar20) + uVar19;

      }

      uVar3 = puVar15[6];

      uVar18 = *(unsigned int *)puVar4;

      uVar26 = uVar3 ^ uVar18;

      if ((int)uVar3 < 0) {

        uVar3 = -uVar3;

      }

      if ((int)uVar18 < 0) {

        uVar18 = -uVar18;

      }

      uVar25 = (uVar18 & 0xffff) * (uVar3 & 0xffff);

      iVar9 = (uVar18 >> 0x10) * (uVar3 & 0xffff);

      iVar8 = 0;

      uVar22 = iVar9 + (uVar18 & 0xffff) * (uVar3 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar21 = uVar25 + uVar22 * 0x10000;

      uVar18 = iVar8 + (unsigned int)(uVar21 < uVar25) + (uVar22 >> 0x10) +

               (uVar18 >> 0x10) * (uVar3 >> 0x10);

      if ((int)-(unsigned int)((int)uVar26 < 0) < 0) {

        uVar18 = ~uVar18;

        if (uVar21 == 0) {

          uVar18 = uVar18 + 1;

        }

        else {

          uVar21 = ~uVar21 + 1;

        }

      }

      if (((unsigned char)(uVar10 >> 1) & 1) == 1) {

        if ((int)uVar18 < -0x8000) {

          uVar18 = 0xffff8000;

          uVar21 = 0;

        }

        if (0x7fff < (int)uVar18) {

          uVar18 = 0x7fff;

          uVar21 = 0xffffffff;

        }

        uVar18 = uVar18 & 0xffff;

      }

      uVar26 = puVar15[7];

      uVar3 = *(unsigned int *)(puVar4 + 4);

      uVar22 = uVar26 ^ uVar3;

      if ((int)uVar26 < 0) {

        uVar26 = -uVar26;

      }

      if ((int)uVar3 < 0) {

        uVar3 = -uVar3;

      }

      uVar24 = (uVar3 & 0xffff) * (uVar26 & 0xffff);

      iVar9 = (uVar3 >> 0x10) * (uVar26 & 0xffff);

      iVar8 = 0;

      uVar25 = iVar9 + (uVar3 & 0xffff) * (uVar26 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar20 = uVar24 + uVar25 * 0x10000;

      uVar3 = iVar8 + (unsigned int)(uVar20 < uVar24) + (uVar25 >> 0x10) +

              (uVar3 >> 0x10) * (uVar26 >> 0x10);

      if ((int)-(unsigned int)((int)uVar22 < 0) < 0) {

        uVar3 = ~uVar3;

        if (uVar20 == 0) {

          uVar3 = uVar3 + 1;

        }

        else {

          uVar20 = ~uVar20 + 1;

        }

      }

      if (((unsigned char)(uVar10 >> 1) & 1) == 1) {

        uVar20 = uVar21 + uVar20;

        uVar18 = uVar3 + (uVar20 < uVar21) + (uVar18 & 0xffff);

        if ((int)uVar18 < -0x8000) {

          uVar18 = 0xffff8000;

          uVar20 = 0;

        }

        if (0x7fff < (int)uVar18) {

          uVar18 = 0x7fff;

          uVar20 = 0xffffffff;

        }

        uVar18 = uVar18 & 0xffff;

      }

      else {

        uVar20 = uVar21 + uVar20;

        uVar18 = uVar3 + (uVar20 < uVar21) + uVar18;

      }

      *(unsigned int *)(puVar5 + 4) = (uVar19 << 0x10 | uVar23 >> 0x10) + puVar15[10];

      uVar3 = puVar15[8];

      uVar19 = *(unsigned int *)(puVar4 + 8);

      uVar26 = uVar3 ^ uVar19;

      if ((int)uVar3 < 0) {

        uVar3 = -uVar3;

      }

      if ((int)uVar19 < 0) {

        uVar19 = -uVar19;

      }

      uVar25 = (uVar19 & 0xffff) * (uVar3 & 0xffff);

      iVar9 = (uVar19 >> 0x10) * (uVar3 & 0xffff);

      iVar8 = 0;

      uVar22 = iVar9 + (uVar19 & 0xffff) * (uVar3 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar23 = uVar25 + uVar22 * 0x10000;

      uVar19 = iVar8 + (unsigned int)(uVar23 < uVar25) + (uVar22 >> 0x10) +

               (uVar19 >> 0x10) * (uVar3 >> 0x10);

      if ((int)-(unsigned int)((int)uVar26 < 0) < 0) {

        uVar19 = ~uVar19;

        if (uVar23 == 0) {

          uVar19 = uVar19 + 1;

        }

        else {

          uVar23 = ~uVar23 + 1;

        }

      }

      if (((unsigned char)(uVar10 >> 1) & 1) == 1) {

        uVar23 = uVar20 + uVar23;

        uVar18 = uVar19 + (uVar23 < uVar20) + (uVar18 & 0xffff);

        if ((int)uVar18 < -0x8000) {

          uVar18 = 0xffff8000;

          uVar23 = 0;

        }

        if (0x7fff < (int)uVar18) {

          uVar18 = 0x7fff;

          uVar23 = 0xffffffff;

        }

        uVar18 = uVar18 & 0xffff;

      }

      else {

        uVar23 = uVar20 + uVar23;

        uVar18 = uVar19 + (uVar23 < uVar20) + uVar18;

      }

      *(unsigned int *)(puVar5 + 8) = (uVar18 << 0x10 | uVar23 >> 0x10) + puVar15[0xb];

      unaff_r11 = (short *)0x06094A28;

      *(unsigned short *)0x06094A28 = (unsigned short)(*(int *)(puVar5 + 8) <= unaff_r10);

      puVar4 = 0x06094A60;

      if ((puVar16[-3] & 0x80000) != 0) break;

      puVar15 = *(unsigned int **)0x06089EDC;

      uVar19 = *puVar15;

      uVar18 = *unaff_r8;

      uVar3 = uVar19 ^ uVar18;

      if ((int)uVar19 < 0) {

        uVar19 = -uVar19;

      }

      if ((int)uVar18 < 0) {

        uVar18 = -uVar18;

      }

      uVar22 = (uVar18 & 0xffff) * (uVar19 & 0xffff);

      iVar9 = (uVar18 >> 0x10) * (uVar19 & 0xffff);

      iVar8 = 0;

      uVar26 = iVar9 + (uVar18 & 0xffff) * (uVar19 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar25 = uVar22 + uVar26 * 0x10000;

      uVar18 = iVar8 + (unsigned int)(uVar25 < uVar22) + (uVar26 >> 0x10) +

               (uVar18 >> 0x10) * (uVar19 >> 0x10);

      if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

        uVar18 = ~uVar18;

        if (uVar25 == 0) {

          uVar18 = uVar18 + 1;

        }

        else {

          uVar25 = ~uVar25 + 1;

        }

      }

      if (((unsigned char)(uVar10 >> 1) & 1) == 1) {

        if ((int)uVar18 < -0x8000) {

          uVar18 = 0xffff8000;

          uVar25 = 0;

        }

        if (0x7fff < (int)uVar18) {

          uVar18 = 0x7fff;

          uVar25 = 0xffffffff;

        }

        uVar18 = uVar18 & 0xffff;

      }

      uVar3 = puVar15[1];

      uVar19 = puVar16[-5];

      uVar26 = uVar3 ^ uVar19;

      if ((int)uVar3 < 0) {

        uVar3 = -uVar3;

      }

      if ((int)uVar19 < 0) {

        uVar19 = -uVar19;

      }

      uVar23 = (uVar19 & 0xffff) * (uVar3 & 0xffff);

      iVar9 = (uVar19 >> 0x10) * (uVar3 & 0xffff);

      iVar8 = 0;

      uVar22 = iVar9 + (uVar19 & 0xffff) * (uVar3 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar21 = uVar23 + uVar22 * 0x10000;

      uVar19 = iVar8 + (unsigned int)(uVar21 < uVar23) + (uVar22 >> 0x10) +

               (uVar19 >> 0x10) * (uVar3 >> 0x10);

      if ((int)-(unsigned int)((int)uVar26 < 0) < 0) {

        uVar19 = ~uVar19;

        if (uVar21 == 0) {

          uVar19 = uVar19 + 1;

        }

        else {

          uVar21 = ~uVar21 + 1;

        }

      }

      if (((unsigned char)(uVar10 >> 1) & 1) == 1) {

        uVar21 = uVar25 + uVar21;

        uVar18 = uVar19 + (uVar21 < uVar25) + (uVar18 & 0xffff);

        if ((int)uVar18 < -0x8000) {

          uVar18 = 0xffff8000;

          uVar21 = 0;

        }

        if (0x7fff < (int)uVar18) {

          uVar18 = 0x7fff;

          uVar21 = 0xffffffff;

        }

        uVar18 = uVar18 & 0xffff;

      }

      else {

        uVar21 = uVar25 + uVar21;

        uVar18 = uVar19 + (uVar21 < uVar25) + uVar18;

      }

      uVar3 = puVar15[2];

      uVar19 = puVar16[-4];

      uVar26 = uVar3 ^ uVar19;

      if ((int)uVar3 < 0) {

        uVar3 = -uVar3;

      }

      if ((int)uVar19 < 0) {

        uVar19 = -uVar19;

      }

      uVar25 = (uVar19 & 0xffff) * (uVar3 & 0xffff);

      iVar9 = (uVar19 >> 0x10) * (uVar3 & 0xffff);

      iVar8 = 0;

      uVar22 = iVar9 + (uVar19 & 0xffff) * (uVar3 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar23 = uVar25 + uVar22 * 0x10000;

      uVar19 = iVar8 + (unsigned int)(uVar23 < uVar25) + (uVar22 >> 0x10) +

               (uVar19 >> 0x10) * (uVar3 >> 0x10);

      if ((int)-(unsigned int)((int)uVar26 < 0) < 0) {

        uVar19 = ~uVar19;

        if (uVar23 == 0) {

          uVar19 = uVar19 + 1;

        }

        else {

          uVar23 = ~uVar23 + 1;

        }

      }

      if (((unsigned char)(uVar10 >> 1) & 1) == 1) {

        uVar23 = uVar21 + uVar23;

        uVar18 = uVar19 + (uVar23 < uVar21) + (uVar18 & 0xffff);

        if ((int)uVar18 < -0x8000) {

          uVar18 = 0xffff8000;

          uVar23 = 0;

        }

        if (0x7fff < (int)uVar18) {

          uVar18 = 0x7fff;

          uVar23 = 0xffffffff;

        }

        uVar18 = uVar18 & 0xffff;

      }

      else {

        uVar23 = uVar21 + uVar23;

        uVar18 = uVar19 + (uVar23 < uVar21) + uVar18;

      }

      uVar3 = puVar15[3];

      uVar19 = *unaff_r8;

      uVar26 = uVar3 ^ uVar19;

      if ((int)uVar3 < 0) {

        uVar3 = -uVar3;

      }

      if ((int)uVar19 < 0) {

        uVar19 = -uVar19;

      }

      uVar25 = (uVar19 & 0xffff) * (uVar3 & 0xffff);

      iVar9 = (uVar19 >> 0x10) * (uVar3 & 0xffff);

      iVar8 = 0;

      uVar22 = iVar9 + (uVar19 & 0xffff) * (uVar3 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar21 = uVar25 + uVar22 * 0x10000;

      uVar19 = iVar8 + (unsigned int)(uVar21 < uVar25) + (uVar22 >> 0x10) +

               (uVar19 >> 0x10) * (uVar3 >> 0x10);

      if ((int)-(unsigned int)((int)uVar26 < 0) < 0) {

        uVar19 = ~uVar19;

        if (uVar21 == 0) {

          uVar19 = uVar19 + 1;

        }

        else {

          uVar21 = ~uVar21 + 1;

        }

      }

      if (((unsigned char)(uVar10 >> 1) & 1) == 1) {

        if ((int)uVar19 < -0x8000) {

          uVar19 = 0xffff8000;

          uVar21 = 0;

        }

        if (0x7fff < (int)uVar19) {

          uVar19 = 0x7fff;

          uVar21 = 0xffffffff;

        }

        uVar19 = uVar19 & 0xffff;

      }

      *(unsigned int *)0x06094A60 = uVar18 << 0x10 | uVar23 >> 0x10;

      uVar3 = puVar15[4];

      uVar18 = puVar16[-5];

      uVar26 = uVar3 ^ uVar18;

      if ((int)uVar3 < 0) {

        uVar3 = -uVar3;

      }

      if ((int)uVar18 < 0) {

        uVar18 = -uVar18;

      }

      uVar25 = (uVar18 & 0xffff) * (uVar3 & 0xffff);

      iVar9 = (uVar18 >> 0x10) * (uVar3 & 0xffff);

      iVar8 = 0;

      uVar22 = iVar9 + (uVar18 & 0xffff) * (uVar3 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar23 = uVar25 + uVar22 * 0x10000;

      uVar18 = iVar8 + (unsigned int)(uVar23 < uVar25) + (uVar22 >> 0x10) +

               (uVar18 >> 0x10) * (uVar3 >> 0x10);

      if ((int)-(unsigned int)((int)uVar26 < 0) < 0) {

        uVar18 = ~uVar18;

        if (uVar23 == 0) {

          uVar18 = uVar18 + 1;

        }

        else {

          uVar23 = ~uVar23 + 1;

        }

      }

      if (((unsigned char)(uVar10 >> 1) & 1) == 1) {

        uVar23 = uVar21 + uVar23;

        uVar19 = uVar18 + (uVar23 < uVar21) + (uVar19 & 0xffff);

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

        uVar23 = uVar21 + uVar23;

        uVar19 = uVar18 + (uVar23 < uVar21) + uVar19;

      }

      uVar3 = puVar15[5];

      uVar18 = puVar16[-4];

      uVar26 = uVar3 ^ uVar18;

      if ((int)uVar3 < 0) {

        uVar3 = -uVar3;

      }

      if ((int)uVar18 < 0) {

        uVar18 = -uVar18;

      }

      uVar25 = (uVar18 & 0xffff) * (uVar3 & 0xffff);

      iVar9 = (uVar18 >> 0x10) * (uVar3 & 0xffff);

      iVar8 = 0;

      uVar22 = iVar9 + (uVar18 & 0xffff) * (uVar3 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar21 = uVar25 + uVar22 * 0x10000;

      uVar18 = iVar8 + (unsigned int)(uVar21 < uVar25) + (uVar22 >> 0x10) +

               (uVar18 >> 0x10) * (uVar3 >> 0x10);

      if ((int)-(unsigned int)((int)uVar26 < 0) < 0) {

        uVar18 = ~uVar18;

        if (uVar21 == 0) {

          uVar18 = uVar18 + 1;

        }

        else {

          uVar21 = ~uVar21 + 1;

        }

      }

      if (((unsigned char)(uVar10 >> 1) & 1) == 1) {

        uVar21 = uVar23 + uVar21;

        uVar19 = uVar18 + (uVar21 < uVar23) + (uVar19 & 0xffff);

        if ((int)uVar19 < -0x8000) {

          uVar19 = 0xffff8000;

          uVar21 = 0;

        }

        if (0x7fff < (int)uVar19) {

          uVar19 = 0x7fff;

          uVar21 = 0xffffffff;

        }

        uVar19 = uVar19 & 0xffff;

      }

      else {

        uVar21 = uVar23 + uVar21;

        uVar19 = uVar18 + (uVar21 < uVar23) + uVar19;

      }

      uVar3 = puVar15[6];

      uVar18 = *unaff_r8;

      uVar26 = uVar3 ^ uVar18;

      if ((int)uVar3 < 0) {

        uVar3 = -uVar3;

      }

      if ((int)uVar18 < 0) {

        uVar18 = -uVar18;

      }

      uVar25 = (uVar18 & 0xffff) * (uVar3 & 0xffff);

      iVar9 = (uVar18 >> 0x10) * (uVar3 & 0xffff);

      iVar8 = 0;

      uVar22 = iVar9 + (uVar18 & 0xffff) * (uVar3 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar23 = uVar25 + uVar22 * 0x10000;

      uVar18 = iVar8 + (unsigned int)(uVar23 < uVar25) + (uVar22 >> 0x10) +

               (uVar18 >> 0x10) * (uVar3 >> 0x10);

      if ((int)-(unsigned int)((int)uVar26 < 0) < 0) {

        uVar18 = ~uVar18;

        if (uVar23 == 0) {

          uVar18 = uVar18 + 1;

        }

        else {

          uVar23 = ~uVar23 + 1;

        }

      }

      if (((unsigned char)(uVar10 >> 1) & 1) == 1) {

        if ((int)uVar18 < -0x8000) {

          uVar18 = 0xffff8000;

          uVar23 = 0;

        }

        if (0x7fff < (int)uVar18) {

          uVar18 = 0x7fff;

          uVar23 = 0xffffffff;

        }

        uVar18 = uVar18 & 0xffff;

      }

      *(unsigned int *)(puVar4 + 4) = uVar19 << 0x10 | uVar21 >> 0x10;

      uVar3 = puVar15[7];

      uVar19 = puVar16[-5];

      uVar26 = uVar3 ^ uVar19;

      if ((int)uVar3 < 0) {

        uVar3 = -uVar3;

      }

      if ((int)uVar19 < 0) {

        uVar19 = -uVar19;

      }

      uVar25 = (uVar19 & 0xffff) * (uVar3 & 0xffff);

      iVar9 = (uVar19 >> 0x10) * (uVar3 & 0xffff);

      iVar8 = 0;

      uVar22 = iVar9 + (uVar19 & 0xffff) * (uVar3 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar21 = uVar25 + uVar22 * 0x10000;

      uVar19 = iVar8 + (unsigned int)(uVar21 < uVar25) + (uVar22 >> 0x10) +

               (uVar19 >> 0x10) * (uVar3 >> 0x10);

      if ((int)-(unsigned int)((int)uVar26 < 0) < 0) {

        uVar19 = ~uVar19;

        if (uVar21 == 0) {

          uVar19 = uVar19 + 1;

        }

        else {

          uVar21 = ~uVar21 + 1;

        }

      }

      if (((unsigned char)(uVar10 >> 1) & 1) == 1) {

        uVar21 = uVar23 + uVar21;

        uVar18 = uVar19 + (uVar21 < uVar23) + (uVar18 & 0xffff);

        if ((int)uVar18 < -0x8000) {

          uVar18 = 0xffff8000;

          uVar21 = 0;

        }

        if (0x7fff < (int)uVar18) {

          uVar18 = 0x7fff;

          uVar21 = 0xffffffff;

        }

        uVar18 = uVar18 & 0xffff;

      }

      else {

        uVar21 = uVar23 + uVar21;

        uVar18 = uVar19 + (uVar21 < uVar23) + uVar18;

      }

      uVar3 = puVar15[8];

      uVar19 = puVar16[-4];

      uVar26 = uVar3 ^ uVar19;

      if ((int)uVar3 < 0) {

        uVar3 = -uVar3;

      }

      if ((int)uVar19 < 0) {

        uVar19 = -uVar19;

      }

      uVar25 = (uVar19 & 0xffff) * (uVar3 & 0xffff);

      iVar9 = (uVar19 >> 0x10) * (uVar3 & 0xffff);

      iVar8 = 0;

      uVar22 = iVar9 + (uVar19 & 0xffff) * (uVar3 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar23 = uVar25 + uVar22 * 0x10000;

      uVar19 = iVar8 + (unsigned int)(uVar23 < uVar25) + (uVar22 >> 0x10) +

               (uVar19 >> 0x10) * (uVar3 >> 0x10);

      if ((int)-(unsigned int)((int)uVar26 < 0) < 0) {

        uVar19 = ~uVar19;

        if (uVar23 == 0) {

          uVar19 = uVar19 + 1;

        }

        else {

          uVar23 = ~uVar23 + 1;

        }

      }

      if (((unsigned char)(uVar10 >> 1) & 1) == 1) {

        uVar23 = uVar21 + uVar23;

        uVar18 = uVar19 + (uVar23 < uVar21) + (uVar18 & 0xffff);

        if ((int)uVar18 < -0x8000) {

          uVar18 = 0xffff8000;

          uVar23 = 0;

        }

        if (0x7fff < (int)uVar18) {

          uVar18 = 0x7fff;

          uVar23 = 0xffffffff;

        }

        uVar18 = uVar18 & 0xffff;

      }

      else {

        uVar23 = uVar21 + uVar23;

        uVar18 = uVar19 + (uVar23 < uVar21) + uVar18;

      }

      *(unsigned int *)(puVar4 + 8) = uVar18 << 0x10 | uVar23 >> 0x10;

      uVar19 = *(unsigned int *)puVar4;

      uVar18 = *(unsigned int *)0x06094A30;

      uVar3 = uVar19 ^ uVar18;

      if ((int)uVar19 < 0) {

        uVar19 = -uVar19;

      }

      if ((int)uVar18 < 0) {

        uVar18 = -uVar18;

      }

      uVar22 = (uVar18 & 0xffff) * (uVar19 & 0xffff);

      iVar9 = (uVar18 >> 0x10) * (uVar19 & 0xffff);

      iVar8 = 0;

      uVar26 = iVar9 + (uVar18 & 0xffff) * (uVar19 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar25 = uVar22 + uVar26 * 0x10000;

      uVar18 = iVar8 + (unsigned int)(uVar25 < uVar22) + (uVar26 >> 0x10) +

               (uVar18 >> 0x10) * (uVar19 >> 0x10);

      if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

        uVar18 = ~uVar18;

        if (uVar25 == 0) {

          uVar18 = uVar18 + 1;

        }

        else {

          uVar25 = ~uVar25 + 1;

        }

      }

      if (((unsigned char)(uVar10 >> 1) & 1) == 1) {

        if ((int)uVar18 < -0x8000) {

          uVar18 = 0xffff8000;

          uVar25 = 0;

        }

        if (0x7fff < (int)uVar18) {

          uVar18 = 0x7fff;

          uVar25 = 0xffffffff;

        }

        uVar18 = uVar18 & 0xffff;

      }

      uVar3 = *(unsigned int *)(puVar4 + 4);

      uVar19 = *(unsigned int *)(0x06094A30 + 4);

      uVar26 = uVar3 ^ uVar19;

      if ((int)uVar3 < 0) {

        uVar3 = -uVar3;

      }

      if ((int)uVar19 < 0) {

        uVar19 = -uVar19;

      }

      uVar23 = (uVar19 & 0xffff) * (uVar3 & 0xffff);

      iVar9 = (uVar19 >> 0x10) * (uVar3 & 0xffff);

      iVar8 = 0;

      uVar22 = iVar9 + (uVar19 & 0xffff) * (uVar3 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar21 = uVar23 + uVar22 * 0x10000;

      uVar19 = iVar8 + (unsigned int)(uVar21 < uVar23) + (uVar22 >> 0x10) +

               (uVar19 >> 0x10) * (uVar3 >> 0x10);

      if ((int)-(unsigned int)((int)uVar26 < 0) < 0) {

        uVar19 = ~uVar19;

        if (uVar21 == 0) {

          uVar19 = uVar19 + 1;

        }

        else {

          uVar21 = ~uVar21 + 1;

        }

      }

      if (((unsigned char)(uVar10 >> 1) & 1) == 1) {

        uVar21 = uVar25 + uVar21;

        uVar18 = uVar19 + (uVar21 < uVar25) + (uVar18 & 0xffff);

        if ((int)uVar18 < -0x8000) {

          uVar18 = 0xffff8000;

          uVar21 = 0;

        }

        if (0x7fff < (int)uVar18) {

          uVar18 = 0x7fff;

          uVar21 = 0xffffffff;

        }

        uVar18 = uVar18 & 0xffff;

      }

      else {

        uVar21 = uVar25 + uVar21;

        uVar18 = uVar19 + (uVar21 < uVar25) + uVar18;

      }

      uVar3 = *(unsigned int *)(puVar4 + 8);

      uVar19 = *(unsigned int *)(0x06094A30 + 8);

      uVar26 = uVar3 ^ uVar19;

      if ((int)uVar3 < 0) {

        uVar3 = -uVar3;

      }

      if ((int)uVar19 < 0) {

        uVar19 = -uVar19;

      }

      uVar25 = (uVar19 & 0xffff) * (uVar3 & 0xffff);

      iVar9 = (uVar19 >> 0x10) * (uVar3 & 0xffff);

      iVar8 = 0;

      uVar22 = iVar9 + (uVar19 & 0xffff) * (uVar3 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar23 = uVar25 + uVar22 * 0x10000;

      uVar19 = iVar8 + (unsigned int)(uVar23 < uVar25) + (uVar22 >> 0x10) +

               (uVar19 >> 0x10) * (uVar3 >> 0x10);

      if ((int)-(unsigned int)((int)uVar26 < 0) < 0) {

        uVar19 = ~uVar19;

        if (uVar23 == 0) {

          uVar19 = uVar19 + 1;

        }

        else {

          uVar23 = ~uVar23 + 1;

        }

      }

      if (((unsigned char)(uVar10 >> 1) & 1) == 1) {

        uVar23 = uVar21 + uVar23;

        uVar18 = uVar19 + (uVar23 < uVar21) + (uVar18 & 0xffff);

        if ((int)uVar18 < -0x8000) {

          uVar18 = 0xffff8000;

          uVar23 = 0;

        }

        if (0x7fff < (int)uVar18) {

          uVar18 = 0x7fff;

          uVar23 = 0xffffffff;

        }

        uVar18 = uVar18 & 0xffff;

      }

      else {

        uVar23 = uVar21 + uVar23;

        uVar18 = uVar19 + (uVar23 < uVar21) + uVar18;

      }

      uVar18 = uVar18 << 0x10 | uVar23 >> 0x10;

      uVar17 = uVar17 | 0 < (int)uVar18;

      uVar10 = uVar17;

    } while (((unsigned char)uVar17 & 1) != 1);

    puVar4 = 0x06094AB0;

    psVar14 = (short *)((unsigned int)*(unsigned short *)((int)puVar16 + -6) * 6 + unaff_r14);

    sVar1 = psVar14[1];

    sVar2 = psVar14[2];

    in_sr = uVar17 & 0xfffffffe;

    *(int *)0x06094AB0 = (int)*psVar14 << 0xb;

    *(int *)(puVar4 + 4) = (int)sVar1 << 0xb;

    *(int *)(puVar4 + 8) = (int)sVar2 << 0xb;

    puVar5 = 0x06094A30;

    puVar15 = *(unsigned int **)0x06089EDC;

    uVar18 = *puVar15;

    uVar10 = *(unsigned int *)puVar4;

    uVar19 = uVar18 ^ uVar10;

    if ((int)uVar18 < 0) {

      uVar18 = -uVar18;

    }

    if ((int)uVar10 < 0) {

      uVar10 = -uVar10;

    }

    uVar26 = (uVar10 & 0xffff) * (uVar18 & 0xffff);

    iVar9 = (uVar10 >> 0x10) * (uVar18 & 0xffff);

    iVar8 = 0;

    uVar3 = iVar9 + (uVar10 & 0xffff) * (uVar18 >> 0x10);

    if (iVar9 != 0) {

      iVar8 = 0x10000;

    }

    uVar22 = uVar26 + uVar3 * 0x10000;

    uVar10 = iVar8 + (unsigned int)(uVar22 < uVar26) + (uVar3 >> 0x10) + (uVar10 >> 0x10) * (uVar18 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar19 < 0) < 0) {

      uVar10 = ~uVar10;

      if (uVar22 == 0) {

        uVar10 = uVar10 + 1;

      }

      else {

        uVar22 = ~uVar22 + 1;

      }

    }

    if (((unsigned char)(uVar17 >> 1) & 1) == 1) {

      if ((int)uVar10 < -0x8000) {

        uVar10 = 0xffff8000;

        uVar22 = 0;

      }

      if (0x7fff < (int)uVar10) {

        uVar10 = 0x7fff;

        uVar22 = 0xffffffff;

      }

      uVar10 = uVar10 & 0xffff;

    }

    uVar19 = puVar15[1];

    uVar18 = *(unsigned int *)(puVar4 + 4);

    uVar3 = uVar19 ^ uVar18;

    if ((int)uVar19 < 0) {

      uVar19 = -uVar19;

    }

    if ((int)uVar18 < 0) {

      uVar18 = -uVar18;

    }

    uVar25 = (uVar18 & 0xffff) * (uVar19 & 0xffff);

    iVar9 = (uVar18 >> 0x10) * (uVar19 & 0xffff);

    iVar8 = 0;

    uVar26 = iVar9 + (uVar18 & 0xffff) * (uVar19 >> 0x10);

    if (iVar9 != 0) {

      iVar8 = 0x10000;

    }

    uVar23 = uVar25 + uVar26 * 0x10000;

    uVar18 = iVar8 + (unsigned int)(uVar23 < uVar25) + (uVar26 >> 0x10) +

             (uVar18 >> 0x10) * (uVar19 >> 0x10);

    if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

      uVar18 = ~uVar18;

      if (uVar23 == 0) {

        uVar18 = uVar18 + 1;

      }

      else {

        uVar23 = ~uVar23 + 1;

      }

    }

    if (((unsigned char)(uVar17 >> 1) & 1) == 1) {

      uVar23 = uVar22 + uVar23;

      uVar10 = uVar18 + (uVar23 < uVar22) + (uVar10 & 0xffff);

      if ((int)uVar10 < -0x8000) {

        uVar10 = 0xffff8000;

        uVar23 = 0;

      }

      if (0x7fff < (int)uVar10) {

        uVar10 = 0x7fff;

        uVar23 = 0xffffffff;

      }

      uVar10 = uVar10 & 0xffff;

    }

    else {

      uVar23 = uVar22 + uVar23;

      uVar10 = uVar18 + (uVar23 < uVar22) + uVar10;

    }

    uVar19 = puVar15[2];

    uVar18 = *(unsigned int *)(puVar4 + 8);

    uVar3 = uVar19 ^ uVar18;

    if ((int)uVar19 < 0) {

      uVar19 = -uVar19;

    }

    if ((int)uVar18 < 0) {

      uVar18 = -uVar18;

    }

    uVar22 = (uVar18 & 0xffff) * (uVar19 & 0xffff);

    iVar9 = (uVar18 >> 0x10) * (uVar19 & 0xffff);

    iVar8 = 0;

    uVar26 = iVar9 + (uVar18 & 0xffff) * (uVar19 >> 0x10);

    if (iVar9 != 0) {

      iVar8 = 0x10000;

    }

    uVar25 = uVar22 + uVar26 * 0x10000;

    uVar18 = iVar8 + (unsigned int)(uVar25 < uVar22) + (uVar26 >> 0x10) +

             (uVar18 >> 0x10) * (uVar19 >> 0x10);

    if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

      uVar18 = ~uVar18;

      if (uVar25 == 0) {

        uVar18 = uVar18 + 1;

      }

      else {

        uVar25 = ~uVar25 + 1;

      }

    }

    if (((unsigned char)(uVar17 >> 1) & 1) == 1) {

      uVar25 = uVar23 + uVar25;

      uVar10 = uVar18 + (uVar25 < uVar23) + (uVar10 & 0xffff);

      if ((int)uVar10 < -0x8000) {

        uVar10 = 0xffff8000;

        uVar25 = 0;

      }

      if (0x7fff < (int)uVar10) {

        uVar10 = 0x7fff;

        uVar25 = 0xffffffff;

      }

      uVar10 = uVar10 & 0xffff;

    }

    else {

      uVar25 = uVar23 + uVar25;

      uVar10 = uVar18 + (uVar25 < uVar23) + uVar10;

    }

    uVar19 = puVar15[3];

    uVar18 = *(unsigned int *)puVar4;

    uVar3 = uVar19 ^ uVar18;

    if ((int)uVar19 < 0) {

      uVar19 = -uVar19;

    }

    if ((int)uVar18 < 0) {

      uVar18 = -uVar18;

    }

    uVar22 = (uVar18 & 0xffff) * (uVar19 & 0xffff);

    iVar9 = (uVar18 >> 0x10) * (uVar19 & 0xffff);

    iVar8 = 0;

    uVar26 = iVar9 + (uVar18 & 0xffff) * (uVar19 >> 0x10);

    if (iVar9 != 0) {

      iVar8 = 0x10000;

    }

    uVar23 = uVar22 + uVar26 * 0x10000;

    uVar18 = iVar8 + (unsigned int)(uVar23 < uVar22) + (uVar26 >> 0x10) +

             (uVar18 >> 0x10) * (uVar19 >> 0x10);

    if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

      uVar18 = ~uVar18;

      if (uVar23 == 0) {

        uVar18 = uVar18 + 1;

      }

      else {

        uVar23 = ~uVar23 + 1;

      }

    }

    if (((unsigned char)(uVar17 >> 1) & 1) == 1) {

      if ((int)uVar18 < -0x8000) {

        uVar18 = 0xffff8000;

        uVar23 = 0;

      }

      if (0x7fff < (int)uVar18) {

        uVar18 = 0x7fff;

        uVar23 = 0xffffffff;

      }

      uVar18 = uVar18 & 0xffff;

    }

    uVar3 = puVar15[4];

    uVar19 = *(unsigned int *)(puVar4 + 4);

    uVar26 = uVar3 ^ uVar19;

    if ((int)uVar3 < 0) {

      uVar3 = -uVar3;

    }

    if ((int)uVar19 < 0) {

      uVar19 = -uVar19;

    }

    uVar21 = (uVar19 & 0xffff) * (uVar3 & 0xffff);

    iVar9 = (uVar19 >> 0x10) * (uVar3 & 0xffff);

    iVar8 = 0;

    uVar22 = iVar9 + (uVar19 & 0xffff) * (uVar3 >> 0x10);

    if (iVar9 != 0) {

      iVar8 = 0x10000;

    }

    uVar24 = uVar21 + uVar22 * 0x10000;

    uVar19 = iVar8 + (unsigned int)(uVar24 < uVar21) + (uVar22 >> 0x10) + (uVar19 >> 0x10) * (uVar3 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar26 < 0) < 0) {

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

      uVar18 = uVar19 + (uVar24 < uVar23) + (uVar18 & 0xffff);

      if ((int)uVar18 < -0x8000) {

        uVar18 = 0xffff8000;

        uVar24 = 0;

      }

      if (0x7fff < (int)uVar18) {

        uVar18 = 0x7fff;

        uVar24 = 0xffffffff;

      }

      uVar18 = uVar18 & 0xffff;

    }

    else {

      uVar24 = uVar23 + uVar24;

      uVar18 = uVar19 + (uVar24 < uVar23) + uVar18;

    }

    *(unsigned int *)(0x06094A30 + 0xc) = (uVar10 << 0x10 | uVar25 >> 0x10) + puVar15[9];

    uVar19 = puVar15[5];

    uVar10 = *(unsigned int *)(puVar4 + 8);

    uVar3 = uVar19 ^ uVar10;

    if ((int)uVar19 < 0) {

      uVar19 = -uVar19;

    }

    if ((int)uVar10 < 0) {

      uVar10 = -uVar10;

    }

    uVar22 = (uVar10 & 0xffff) * (uVar19 & 0xffff);

    iVar9 = (uVar10 >> 0x10) * (uVar19 & 0xffff);

    iVar8 = 0;

    uVar26 = iVar9 + (uVar10 & 0xffff) * (uVar19 >> 0x10);

    if (iVar9 != 0) {

      iVar8 = 0x10000;

    }

    uVar25 = uVar22 + uVar26 * 0x10000;

    uVar10 = iVar8 + (unsigned int)(uVar25 < uVar22) + (uVar26 >> 0x10) +

             (uVar10 >> 0x10) * (uVar19 >> 0x10);

    if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

      uVar10 = ~uVar10;

      if (uVar25 == 0) {

        uVar10 = uVar10 + 1;

      }

      else {

        uVar25 = ~uVar25 + 1;

      }

    }

    if (((unsigned char)(uVar17 >> 1) & 1) == 1) {

      uVar25 = uVar24 + uVar25;

      uVar18 = uVar10 + (uVar25 < uVar24) + (uVar18 & 0xffff);

      if ((int)uVar18 < -0x8000) {

        uVar18 = 0xffff8000;

        uVar25 = 0;

      }

      if (0x7fff < (int)uVar18) {

        uVar18 = 0x7fff;

        uVar25 = 0xffffffff;

      }

      uVar18 = uVar18 & 0xffff;

    }

    else {

      uVar25 = uVar24 + uVar25;

      uVar18 = uVar10 + (uVar25 < uVar24) + uVar18;

    }

    uVar19 = puVar15[6];

    uVar10 = *(unsigned int *)puVar4;

    uVar3 = uVar19 ^ uVar10;

    if ((int)uVar19 < 0) {

      uVar19 = -uVar19;

    }

    if ((int)uVar10 < 0) {

      uVar10 = -uVar10;

    }

    uVar22 = (uVar10 & 0xffff) * (uVar19 & 0xffff);

    iVar9 = (uVar10 >> 0x10) * (uVar19 & 0xffff);

    iVar8 = 0;

    uVar26 = iVar9 + (uVar10 & 0xffff) * (uVar19 >> 0x10);

    if (iVar9 != 0) {

      iVar8 = 0x10000;

    }

    uVar23 = uVar22 + uVar26 * 0x10000;

    uVar10 = iVar8 + (unsigned int)(uVar23 < uVar22) + (uVar26 >> 0x10) +

             (uVar10 >> 0x10) * (uVar19 >> 0x10);

    if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

      uVar10 = ~uVar10;

      if (uVar23 == 0) {

        uVar10 = uVar10 + 1;

      }

      else {

        uVar23 = ~uVar23 + 1;

      }

    }

    if (((unsigned char)(uVar17 >> 1) & 1) == 1) {

      if ((int)uVar10 < -0x8000) {

        uVar10 = 0xffff8000;

        uVar23 = 0;

      }

      if (0x7fff < (int)uVar10) {

        uVar10 = 0x7fff;

        uVar23 = 0xffffffff;

      }

      uVar10 = uVar10 & 0xffff;

    }

    uVar3 = puVar15[7];

    uVar19 = *(unsigned int *)(puVar4 + 4);

    uVar26 = uVar3 ^ uVar19;

    if ((int)uVar3 < 0) {

      uVar3 = -uVar3;

    }

    if ((int)uVar19 < 0) {

      uVar19 = -uVar19;

    }

    uVar21 = (uVar19 & 0xffff) * (uVar3 & 0xffff);

    iVar9 = (uVar19 >> 0x10) * (uVar3 & 0xffff);

    iVar8 = 0;

    uVar22 = iVar9 + (uVar19 & 0xffff) * (uVar3 >> 0x10);

    if (iVar9 != 0) {

      iVar8 = 0x10000;

    }

    uVar24 = uVar21 + uVar22 * 0x10000;

    uVar19 = iVar8 + (unsigned int)(uVar24 < uVar21) + (uVar22 >> 0x10) + (uVar19 >> 0x10) * (uVar3 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar26 < 0) < 0) {

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

      uVar10 = uVar19 + (uVar24 < uVar23) + (uVar10 & 0xffff);

      if ((int)uVar10 < -0x8000) {

        uVar10 = 0xffff8000;

        uVar24 = 0;

      }

      if (0x7fff < (int)uVar10) {

        uVar10 = 0x7fff;

        uVar24 = 0xffffffff;

      }

      uVar10 = uVar10 & 0xffff;

    }

    else {

      uVar24 = uVar23 + uVar24;

      uVar10 = uVar19 + (uVar24 < uVar23) + uVar10;

    }

    *(unsigned int *)(puVar5 + 0x10) = (uVar18 << 0x10 | uVar25 >> 0x10) + puVar15[10];

    uVar19 = puVar15[8];

    uVar18 = *(unsigned int *)(puVar4 + 8);

    uVar3 = uVar19 ^ uVar18;

    if ((int)uVar19 < 0) {

      uVar19 = -uVar19;

    }

    if ((int)uVar18 < 0) {

      uVar18 = -uVar18;

    }

    uVar22 = (uVar18 & 0xffff) * (uVar19 & 0xffff);

    iVar9 = (uVar18 >> 0x10) * (uVar19 & 0xffff);

    iVar8 = 0;

    uVar26 = iVar9 + (uVar18 & 0xffff) * (uVar19 >> 0x10);

    if (iVar9 != 0) {

      iVar8 = 0x10000;

    }

    uVar25 = uVar22 + uVar26 * 0x10000;

    uVar18 = iVar8 + (unsigned int)(uVar25 < uVar22) + (uVar26 >> 0x10) +

             (uVar18 >> 0x10) * (uVar19 >> 0x10);

    if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

      uVar18 = ~uVar18;

      if (uVar25 == 0) {

        uVar18 = uVar18 + 1;

      }

      else {

        uVar25 = ~uVar25 + 1;

      }

    }

    if (((unsigned char)(uVar17 >> 1) & 1) == 1) {

      uVar25 = uVar24 + uVar25;

      uVar10 = uVar18 + (uVar25 < uVar24) + (uVar10 & 0xffff);

      if ((int)uVar10 < -0x8000) {

        uVar10 = 0xffff8000;

        uVar25 = 0;

      }

      if (0x7fff < (int)uVar10) {

        uVar10 = 0x7fff;

        uVar25 = 0xffffffff;

      }

      uVar10 = uVar10 & 0xffff;

    }

    else {

      uVar25 = uVar24 + uVar25;

      uVar10 = uVar18 + (uVar25 < uVar24) + uVar10;

    }

    *(unsigned int *)(puVar5 + 0x14) = (uVar10 << 0x10 | uVar25 >> 0x10) + puVar15[0xb];

    *(unsigned short *)((int)unaff_r11 + 2) = (unsigned short)(*(int *)(puVar5 + 0x14) <= unaff_r10);

    puVar4 = 0x06094AB0;

    psVar14 = (short *)((unsigned int)*(unsigned short *)(puVar16 + -1) * 6 + unaff_r14);

    sVar1 = psVar14[1];

    sVar2 = psVar14[2];

    *(int *)0x06094AB0 = (int)*psVar14 << 0xb;

    *(int *)(puVar4 + 4) = (int)sVar1 << 0xb;

    *(int *)0x06094AE0 = (int)sVar1 << 0xb;

    *(int *)(puVar4 + 8) = (int)sVar2 << 0xb;

    puVar5 = 0x06094A30;

    puVar15 = *(unsigned int **)0x06089EDC;

    uVar18 = *puVar15;

    uVar10 = *(unsigned int *)puVar4;

    uVar19 = uVar18 ^ uVar10;

    if ((int)uVar18 < 0) {

      uVar18 = -uVar18;

    }

    if ((int)uVar10 < 0) {

      uVar10 = -uVar10;

    }

    uVar26 = (uVar10 & 0xffff) * (uVar18 & 0xffff);

    iVar9 = (uVar10 >> 0x10) * (uVar18 & 0xffff);

    iVar8 = 0;

    uVar3 = iVar9 + (uVar10 & 0xffff) * (uVar18 >> 0x10);

    if (iVar9 != 0) {

      iVar8 = 0x10000;

    }

    uVar22 = uVar26 + uVar3 * 0x10000;

    uVar10 = iVar8 + (unsigned int)(uVar22 < uVar26) + (uVar3 >> 0x10) + (uVar10 >> 0x10) * (uVar18 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar19 < 0) < 0) {

      uVar10 = ~uVar10;

      if (uVar22 == 0) {

        uVar10 = uVar10 + 1;

      }

      else {

        uVar22 = ~uVar22 + 1;

      }

    }

    if (((unsigned char)(uVar17 >> 1) & 1) == 1) {

      if ((int)uVar10 < -0x8000) {

        uVar10 = 0xffff8000;

        uVar22 = 0;

      }

      if (0x7fff < (int)uVar10) {

        uVar10 = 0x7fff;

        uVar22 = 0xffffffff;

      }

      uVar10 = uVar10 & 0xffff;

    }

    uVar19 = puVar15[1];

    uVar18 = *(unsigned int *)(puVar4 + 4);

    uVar3 = uVar19 ^ uVar18;

    if ((int)uVar19 < 0) {

      uVar19 = -uVar19;

    }

    if ((int)uVar18 < 0) {

      uVar18 = -uVar18;

    }

    uVar25 = (uVar18 & 0xffff) * (uVar19 & 0xffff);

    iVar9 = (uVar18 >> 0x10) * (uVar19 & 0xffff);

    iVar8 = 0;

    uVar26 = iVar9 + (uVar18 & 0xffff) * (uVar19 >> 0x10);

    if (iVar9 != 0) {

      iVar8 = 0x10000;

    }

    uVar23 = uVar25 + uVar26 * 0x10000;

    uVar18 = iVar8 + (unsigned int)(uVar23 < uVar25) + (uVar26 >> 0x10) +

             (uVar18 >> 0x10) * (uVar19 >> 0x10);

    if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

      uVar18 = ~uVar18;

      if (uVar23 == 0) {

        uVar18 = uVar18 + 1;

      }

      else {

        uVar23 = ~uVar23 + 1;

      }

    }

    if (((unsigned char)(uVar17 >> 1) & 1) == 1) {

      uVar23 = uVar22 + uVar23;

      uVar10 = uVar18 + (uVar23 < uVar22) + (uVar10 & 0xffff);

      if ((int)uVar10 < -0x8000) {

        uVar10 = 0xffff8000;

        uVar23 = 0;

      }

      if (0x7fff < (int)uVar10) {

        uVar10 = 0x7fff;

        uVar23 = 0xffffffff;

      }

      uVar10 = uVar10 & 0xffff;

    }

    else {

      uVar23 = uVar22 + uVar23;

      uVar10 = uVar18 + (uVar23 < uVar22) + uVar10;

    }

    uVar19 = puVar15[2];

    uVar18 = *(unsigned int *)(puVar4 + 8);

    uVar3 = uVar19 ^ uVar18;

    if ((int)uVar19 < 0) {

      uVar19 = -uVar19;

    }

    if ((int)uVar18 < 0) {

      uVar18 = -uVar18;

    }

    uVar22 = (uVar18 & 0xffff) * (uVar19 & 0xffff);

    iVar9 = (uVar18 >> 0x10) * (uVar19 & 0xffff);

    iVar8 = 0;

    uVar26 = iVar9 + (uVar18 & 0xffff) * (uVar19 >> 0x10);

    if (iVar9 != 0) {

      iVar8 = 0x10000;

    }

    uVar25 = uVar22 + uVar26 * 0x10000;

    uVar18 = iVar8 + (unsigned int)(uVar25 < uVar22) + (uVar26 >> 0x10) +

             (uVar18 >> 0x10) * (uVar19 >> 0x10);

    if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

      uVar18 = ~uVar18;

      if (uVar25 == 0) {

        uVar18 = uVar18 + 1;

      }

      else {

        uVar25 = ~uVar25 + 1;

      }

    }

    if (((unsigned char)(uVar17 >> 1) & 1) == 1) {

      uVar25 = uVar23 + uVar25;

      uVar10 = uVar18 + (uVar25 < uVar23) + (uVar10 & 0xffff);

      if ((int)uVar10 < -0x8000) {

        uVar10 = 0xffff8000;

        uVar25 = 0;

      }

      if (0x7fff < (int)uVar10) {

        uVar10 = 0x7fff;

        uVar25 = 0xffffffff;

      }

      uVar10 = uVar10 & 0xffff;

    }

    else {

      uVar25 = uVar23 + uVar25;

      uVar10 = uVar18 + (uVar25 < uVar23) + uVar10;

    }

    uVar19 = puVar15[3];

    uVar18 = *(unsigned int *)puVar4;

    uVar3 = uVar19 ^ uVar18;

    if ((int)uVar19 < 0) {

      uVar19 = -uVar19;

    }

    if ((int)uVar18 < 0) {

      uVar18 = -uVar18;

    }

    uVar22 = (uVar18 & 0xffff) * (uVar19 & 0xffff);

    iVar9 = (uVar18 >> 0x10) * (uVar19 & 0xffff);

    iVar8 = 0;

    uVar26 = iVar9 + (uVar18 & 0xffff) * (uVar19 >> 0x10);

    if (iVar9 != 0) {

      iVar8 = 0x10000;

    }

    uVar23 = uVar22 + uVar26 * 0x10000;

    uVar18 = iVar8 + (unsigned int)(uVar23 < uVar22) + (uVar26 >> 0x10) +

             (uVar18 >> 0x10) * (uVar19 >> 0x10);

    if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

      uVar18 = ~uVar18;

      if (uVar23 == 0) {

        uVar18 = uVar18 + 1;

      }

      else {

        uVar23 = ~uVar23 + 1;

      }

    }

    if (((unsigned char)(uVar17 >> 1) & 1) == 1) {

      if ((int)uVar18 < -0x8000) {

        uVar18 = 0xffff8000;

        uVar23 = 0;

      }

      if (0x7fff < (int)uVar18) {

        uVar18 = 0x7fff;

        uVar23 = 0xffffffff;

      }

      uVar18 = uVar18 & 0xffff;

    }

    uVar3 = puVar15[4];

    uVar19 = *(unsigned int *)(puVar4 + 4);

    uVar26 = uVar3 ^ uVar19;

    if ((int)uVar3 < 0) {

      uVar3 = -uVar3;

    }

    if ((int)uVar19 < 0) {

      uVar19 = -uVar19;

    }

    uVar21 = (uVar19 & 0xffff) * (uVar3 & 0xffff);

    iVar9 = (uVar19 >> 0x10) * (uVar3 & 0xffff);

    iVar8 = 0;

    uVar22 = iVar9 + (uVar19 & 0xffff) * (uVar3 >> 0x10);

    if (iVar9 != 0) {

      iVar8 = 0x10000;

    }

    uVar24 = uVar21 + uVar22 * 0x10000;

    uVar19 = iVar8 + (unsigned int)(uVar24 < uVar21) + (uVar22 >> 0x10) + (uVar19 >> 0x10) * (uVar3 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar26 < 0) < 0) {

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

      uVar18 = uVar19 + (uVar24 < uVar23) + (uVar18 & 0xffff);

      if ((int)uVar18 < -0x8000) {

        uVar18 = 0xffff8000;

        uVar24 = 0;

      }

      if (0x7fff < (int)uVar18) {

        uVar18 = 0x7fff;

        uVar24 = 0xffffffff;

      }

      uVar18 = uVar18 & 0xffff;

    }

    else {

      uVar24 = uVar23 + uVar24;

      uVar18 = uVar19 + (uVar24 < uVar23) + uVar18;

    }

    *(unsigned int *)(0x06094A30 + 0x18) = (uVar10 << 0x10 | uVar25 >> 0x10) + puVar15[9];

    uVar19 = puVar15[5];

    uVar10 = *(unsigned int *)(puVar4 + 8);

    uVar3 = uVar19 ^ uVar10;

    if ((int)uVar19 < 0) {

      uVar19 = -uVar19;

    }

    if ((int)uVar10 < 0) {

      uVar10 = -uVar10;

    }

    uVar22 = (uVar10 & 0xffff) * (uVar19 & 0xffff);

    iVar9 = (uVar10 >> 0x10) * (uVar19 & 0xffff);

    iVar8 = 0;

    uVar26 = iVar9 + (uVar10 & 0xffff) * (uVar19 >> 0x10);

    if (iVar9 != 0) {

      iVar8 = 0x10000;

    }

    uVar25 = uVar22 + uVar26 * 0x10000;

    uVar10 = iVar8 + (unsigned int)(uVar25 < uVar22) + (uVar26 >> 0x10) +

             (uVar10 >> 0x10) * (uVar19 >> 0x10);

    if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

      uVar10 = ~uVar10;

      if (uVar25 == 0) {

        uVar10 = uVar10 + 1;

      }

      else {

        uVar25 = ~uVar25 + 1;

      }

    }

    if (((unsigned char)(uVar17 >> 1) & 1) == 1) {

      uVar25 = uVar24 + uVar25;

      uVar18 = uVar10 + (uVar25 < uVar24) + (uVar18 & 0xffff);

      if ((int)uVar18 < -0x8000) {

        uVar18 = 0xffff8000;

        uVar25 = 0;

      }

      if (0x7fff < (int)uVar18) {

        uVar18 = 0x7fff;

        uVar25 = 0xffffffff;

      }

      uVar18 = uVar18 & 0xffff;

    }

    else {

      uVar25 = uVar24 + uVar25;

      uVar18 = uVar10 + (uVar25 < uVar24) + uVar18;

    }

    uVar19 = puVar15[6];

    uVar10 = *(unsigned int *)puVar4;

    uVar3 = uVar19 ^ uVar10;

    if ((int)uVar19 < 0) {

      uVar19 = -uVar19;

    }

    if ((int)uVar10 < 0) {

      uVar10 = -uVar10;

    }

    uVar22 = (uVar10 & 0xffff) * (uVar19 & 0xffff);

    iVar9 = (uVar10 >> 0x10) * (uVar19 & 0xffff);

    iVar8 = 0;

    uVar26 = iVar9 + (uVar10 & 0xffff) * (uVar19 >> 0x10);

    if (iVar9 != 0) {

      iVar8 = 0x10000;

    }

    uVar23 = uVar22 + uVar26 * 0x10000;

    uVar10 = iVar8 + (unsigned int)(uVar23 < uVar22) + (uVar26 >> 0x10) +

             (uVar10 >> 0x10) * (uVar19 >> 0x10);

    if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

      uVar10 = ~uVar10;

      if (uVar23 == 0) {

        uVar10 = uVar10 + 1;

      }

      else {

        uVar23 = ~uVar23 + 1;

      }

    }

    if (((unsigned char)(uVar17 >> 1) & 1) == 1) {

      if ((int)uVar10 < -0x8000) {

        uVar10 = 0xffff8000;

        uVar23 = 0;

      }

      if (0x7fff < (int)uVar10) {

        uVar10 = 0x7fff;

        uVar23 = 0xffffffff;

      }

      uVar10 = uVar10 & 0xffff;

    }

    uVar3 = puVar15[7];

    uVar19 = *(unsigned int *)(puVar4 + 4);

    uVar26 = uVar3 ^ uVar19;

    if ((int)uVar3 < 0) {

      uVar3 = -uVar3;

    }

    if ((int)uVar19 < 0) {

      uVar19 = -uVar19;

    }

    uVar21 = (uVar19 & 0xffff) * (uVar3 & 0xffff);

    iVar9 = (uVar19 >> 0x10) * (uVar3 & 0xffff);

    iVar8 = 0;

    uVar22 = iVar9 + (uVar19 & 0xffff) * (uVar3 >> 0x10);

    if (iVar9 != 0) {

      iVar8 = 0x10000;

    }

    uVar24 = uVar21 + uVar22 * 0x10000;

    uVar19 = iVar8 + (unsigned int)(uVar24 < uVar21) + (uVar22 >> 0x10) + (uVar19 >> 0x10) * (uVar3 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar26 < 0) < 0) {

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

      uVar10 = uVar19 + (uVar24 < uVar23) + (uVar10 & 0xffff);

      if ((int)uVar10 < -0x8000) {

        uVar10 = 0xffff8000;

        uVar24 = 0;

      }

      if (0x7fff < (int)uVar10) {

        uVar10 = 0x7fff;

        uVar24 = 0xffffffff;

      }

      uVar10 = uVar10 & 0xffff;

    }

    else {

      uVar24 = uVar23 + uVar24;

      uVar10 = uVar19 + (uVar24 < uVar23) + uVar10;

    }

    *(unsigned int *)(puVar5 + 0x1c) = (uVar18 << 0x10 | uVar25 >> 0x10) + puVar15[10];

    uVar19 = puVar15[8];

    uVar18 = *(unsigned int *)(puVar4 + 8);

    uVar3 = uVar19 ^ uVar18;

    if ((int)uVar19 < 0) {

      uVar19 = -uVar19;

    }

    if ((int)uVar18 < 0) {

      uVar18 = -uVar18;

    }

    uVar22 = (uVar18 & 0xffff) * (uVar19 & 0xffff);

    iVar9 = (uVar18 >> 0x10) * (uVar19 & 0xffff);

    iVar8 = 0;

    uVar26 = iVar9 + (uVar18 & 0xffff) * (uVar19 >> 0x10);

    if (iVar9 != 0) {

      iVar8 = 0x10000;

    }

    uVar25 = uVar22 + uVar26 * 0x10000;

    uVar18 = iVar8 + (unsigned int)(uVar25 < uVar22) + (uVar26 >> 0x10) +

             (uVar18 >> 0x10) * (uVar19 >> 0x10);

    if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

      uVar18 = ~uVar18;

      if (uVar25 == 0) {

        uVar18 = uVar18 + 1;

      }

      else {

        uVar25 = ~uVar25 + 1;

      }

    }

    if (((unsigned char)(uVar17 >> 1) & 1) == 1) {

      uVar25 = uVar24 + uVar25;

      uVar10 = uVar18 + (uVar25 < uVar24) + (uVar10 & 0xffff);

      if ((int)uVar10 < -0x8000) {

        uVar10 = 0xffff8000;

        uVar25 = 0;

      }

      if (0x7fff < (int)uVar10) {

        uVar10 = 0x7fff;

        uVar25 = 0xffffffff;

      }

      uVar10 = uVar10 & 0xffff;

    }

    else {

      uVar25 = uVar24 + uVar25;

      uVar10 = uVar18 + (uVar25 < uVar24) + uVar10;

    }

    *(unsigned int *)(puVar5 + 0x20) = (uVar10 << 0x10 | uVar25 >> 0x10) + puVar15[0xb];

    *(unsigned short *)((int)unaff_r11 + 4) = (unsigned short)(*(int *)(puVar5 + 0x20) <= unaff_r10);

    param_1 = (unsigned int *)0x06094AB0;

    psVar14 = (short *)((unsigned int)*(unsigned short *)((int)puVar16 + -2) * 6 + unaff_r14);

    sVar1 = psVar14[1];

    sVar2 = psVar14[2];

    *(int *)0x06094AB0 = (int)*psVar14 << 0xb;

    *(int *)((int)param_1 + 4) = (int)sVar1 << 0xb;

    in_r2 = (int)sVar2 << 0xb;

  } while( 1 );

}
