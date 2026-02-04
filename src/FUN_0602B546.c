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

unsigned int FUN_0602b546()
{

  short sVar1;

  short sVar2;

  unsigned int uVar3;

  unsigned int uVar4;

  char *puVar5;

  char *puVar6;

  char *puVar7;

  char *puVar8;

  unsigned short in_r0;

  int iVar9;

  int iVar10;

  unsigned int uVar11;

  int *puVar12;

  int uVar13;

  int iVar14;

  short *psVar15;

  unsigned int *puVar16;

  unsigned int *puVar17;

  unsigned int *unaff_r8;

  int unaff_r10;

  short *unaff_r11;

  char unaff_r13;

  int unaff_r14;

  unsigned int uVar18;

  unsigned int in_sr;

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

    unaff_r11[2] = in_r0;

    puVar5 = 0x06094AB0;

    psVar15 = (short *)((unsigned int)*(unsigned short *)((int)unaff_r8 + 0x16) * 6 + unaff_r14);

    sVar1 = psVar15[1];

    sVar2 = psVar15[2];

    uVar11 = in_sr & 0xfffffffe;

    *(int *)0x06094AB0 = (int)*psVar15 << 0xb;

    *(int *)(puVar5 + 4) = (int)sVar1 << 0xb;

    *(int *)(puVar5 + 8) = (int)sVar2 << 0xb;

    puVar6 = 0x06094A30;

    puVar17 = *(unsigned int **)0x06089EDC;

    uVar18 = *puVar17;

    uVar19 = *(unsigned int *)puVar5;

    uVar20 = uVar18 ^ uVar19;

    if ((int)uVar18 < 0) {

      uVar18 = -uVar18;

    }

    if ((int)uVar19 < 0) {

      uVar19 = -uVar19;

    }

    uVar4 = (uVar19 & 0xffff) * (uVar18 & 0xffff);

    iVar10 = (uVar19 >> 0x10) * (uVar18 & 0xffff);

    iVar9 = 0;

    uVar3 = iVar10 + (uVar19 & 0xffff) * (uVar18 >> 0x10);

    if (iVar10 != 0) {

      iVar9 = 0x10000;

    }

    uVar23 = uVar4 + uVar3 * 0x10000;

    uVar19 = iVar9 + (unsigned int)(uVar23 < uVar4) + (uVar3 >> 0x10) + (uVar19 >> 0x10) * (uVar18 >> 0x10);

    if ((int)-(unsigned int)((int)uVar20 < 0) < 0) {

      uVar19 = ~uVar19;

      if (uVar23 == 0) {

        uVar19 = uVar19 + 1;

      }

      else {

        uVar23 = ~uVar23 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

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

    uVar20 = puVar17[1];

    uVar18 = *(unsigned int *)(puVar5 + 4);

    uVar3 = uVar20 ^ uVar18;

    if ((int)uVar20 < 0) {

      uVar20 = -uVar20;

    }

    if ((int)uVar18 < 0) {

      uVar18 = -uVar18;

    }

    uVar26 = (uVar18 & 0xffff) * (uVar20 & 0xffff);

    iVar10 = (uVar18 >> 0x10) * (uVar20 & 0xffff);

    iVar9 = 0;

    uVar4 = iVar10 + (uVar18 & 0xffff) * (uVar20 >> 0x10);

    if (iVar10 != 0) {

      iVar9 = 0x10000;

    }

    uVar24 = uVar26 + uVar4 * 0x10000;

    uVar18 = iVar9 + (unsigned int)(uVar24 < uVar26) + (uVar4 >> 0x10) + (uVar18 >> 0x10) * (uVar20 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

      uVar18 = ~uVar18;

      if (uVar24 == 0) {

        uVar18 = uVar18 + 1;

      }

      else {

        uVar24 = ~uVar24 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      uVar24 = uVar23 + uVar24;

      uVar19 = uVar18 + (uVar24 < uVar23) + (uVar19 & 0xffff);

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

      uVar19 = uVar18 + (uVar24 < uVar23) + uVar19;

    }

    uVar20 = puVar17[2];

    uVar18 = *(unsigned int *)(puVar5 + 8);

    uVar3 = uVar20 ^ uVar18;

    if ((int)uVar20 < 0) {

      uVar20 = -uVar20;

    }

    if ((int)uVar18 < 0) {

      uVar18 = -uVar18;

    }

    uVar23 = (uVar18 & 0xffff) * (uVar20 & 0xffff);

    iVar10 = (uVar18 >> 0x10) * (uVar20 & 0xffff);

    iVar9 = 0;

    uVar4 = iVar10 + (uVar18 & 0xffff) * (uVar20 >> 0x10);

    if (iVar10 != 0) {

      iVar9 = 0x10000;

    }

    uVar26 = uVar23 + uVar4 * 0x10000;

    uVar18 = iVar9 + (unsigned int)(uVar26 < uVar23) + (uVar4 >> 0x10) + (uVar18 >> 0x10) * (uVar20 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

      uVar18 = ~uVar18;

      if (uVar26 == 0) {

        uVar18 = uVar18 + 1;

      }

      else {

        uVar26 = ~uVar26 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      uVar26 = uVar24 + uVar26;

      uVar19 = uVar18 + (uVar26 < uVar24) + (uVar19 & 0xffff);

      if ((int)uVar19 < -0x8000) {

        uVar19 = 0xffff8000;

        uVar26 = 0;

      }

      if (0x7fff < (int)uVar19) {

        uVar19 = 0x7fff;

        uVar26 = 0xffffffff;

      }

      uVar19 = uVar19 & 0xffff;

    }

    else {

      uVar26 = uVar24 + uVar26;

      uVar19 = uVar18 + (uVar26 < uVar24) + uVar19;

    }

    uVar20 = puVar17[3];

    uVar18 = *(unsigned int *)puVar5;

    uVar3 = uVar20 ^ uVar18;

    if ((int)uVar20 < 0) {

      uVar20 = -uVar20;

    }

    if ((int)uVar18 < 0) {

      uVar18 = -uVar18;

    }

    uVar23 = (uVar18 & 0xffff) * (uVar20 & 0xffff);

    iVar10 = (uVar18 >> 0x10) * (uVar20 & 0xffff);

    iVar9 = 0;

    uVar4 = iVar10 + (uVar18 & 0xffff) * (uVar20 >> 0x10);

    if (iVar10 != 0) {

      iVar9 = 0x10000;

    }

    uVar24 = uVar23 + uVar4 * 0x10000;

    uVar18 = iVar9 + (unsigned int)(uVar24 < uVar23) + (uVar4 >> 0x10) + (uVar18 >> 0x10) * (uVar20 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

      uVar18 = ~uVar18;

      if (uVar24 == 0) {

        uVar18 = uVar18 + 1;

      }

      else {

        uVar24 = ~uVar24 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

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

    uVar3 = puVar17[4];

    uVar20 = *(unsigned int *)(puVar5 + 4);

    uVar4 = uVar3 ^ uVar20;

    if ((int)uVar3 < 0) {

      uVar3 = -uVar3;

    }

    if ((int)uVar20 < 0) {

      uVar20 = -uVar20;

    }

    uVar22 = (uVar20 & 0xffff) * (uVar3 & 0xffff);

    iVar10 = (uVar20 >> 0x10) * (uVar3 & 0xffff);

    iVar9 = 0;

    uVar23 = iVar10 + (uVar20 & 0xffff) * (uVar3 >> 0x10);

    if (iVar10 != 0) {

      iVar9 = 0x10000;

    }

    uVar25 = uVar22 + uVar23 * 0x10000;

    uVar20 = iVar9 + (unsigned int)(uVar25 < uVar22) + (uVar23 >> 0x10) + (uVar20 >> 0x10) * (uVar3 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar4 < 0) < 0) {

      uVar20 = ~uVar20;

      if (uVar25 == 0) {

        uVar20 = uVar20 + 1;

      }

      else {

        uVar25 = ~uVar25 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      uVar25 = uVar24 + uVar25;

      uVar18 = uVar20 + (uVar25 < uVar24) + (uVar18 & 0xffff);

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

      uVar18 = uVar20 + (uVar25 < uVar24) + uVar18;

    }

    *(unsigned int *)(0x06094A30 + 0x24) = (uVar19 << 0x10 | uVar26 >> 0x10) + puVar17[9];

    uVar20 = puVar17[5];

    uVar19 = *(unsigned int *)(puVar5 + 8);

    uVar3 = uVar20 ^ uVar19;

    if ((int)uVar20 < 0) {

      uVar20 = -uVar20;

    }

    if ((int)uVar19 < 0) {

      uVar19 = -uVar19;

    }

    uVar23 = (uVar19 & 0xffff) * (uVar20 & 0xffff);

    iVar10 = (uVar19 >> 0x10) * (uVar20 & 0xffff);

    iVar9 = 0;

    uVar4 = iVar10 + (uVar19 & 0xffff) * (uVar20 >> 0x10);

    if (iVar10 != 0) {

      iVar9 = 0x10000;

    }

    uVar26 = uVar23 + uVar4 * 0x10000;

    uVar19 = iVar9 + (unsigned int)(uVar26 < uVar23) + (uVar4 >> 0x10) + (uVar19 >> 0x10) * (uVar20 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

      uVar19 = ~uVar19;

      if (uVar26 == 0) {

        uVar19 = uVar19 + 1;

      }

      else {

        uVar26 = ~uVar26 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      uVar26 = uVar25 + uVar26;

      uVar18 = uVar19 + (uVar26 < uVar25) + (uVar18 & 0xffff);

      if ((int)uVar18 < -0x8000) {

        uVar18 = 0xffff8000;

        uVar26 = 0;

      }

      if (0x7fff < (int)uVar18) {

        uVar18 = 0x7fff;

        uVar26 = 0xffffffff;

      }

      uVar18 = uVar18 & 0xffff;

    }

    else {

      uVar26 = uVar25 + uVar26;

      uVar18 = uVar19 + (uVar26 < uVar25) + uVar18;

    }

    uVar20 = puVar17[6];

    uVar19 = *(unsigned int *)puVar5;

    uVar3 = uVar20 ^ uVar19;

    if ((int)uVar20 < 0) {

      uVar20 = -uVar20;

    }

    if ((int)uVar19 < 0) {

      uVar19 = -uVar19;

    }

    uVar23 = (uVar19 & 0xffff) * (uVar20 & 0xffff);

    iVar10 = (uVar19 >> 0x10) * (uVar20 & 0xffff);

    iVar9 = 0;

    uVar4 = iVar10 + (uVar19 & 0xffff) * (uVar20 >> 0x10);

    if (iVar10 != 0) {

      iVar9 = 0x10000;

    }

    uVar24 = uVar23 + uVar4 * 0x10000;

    uVar19 = iVar9 + (unsigned int)(uVar24 < uVar23) + (uVar4 >> 0x10) + (uVar19 >> 0x10) * (uVar20 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

      uVar19 = ~uVar19;

      if (uVar24 == 0) {

        uVar19 = uVar19 + 1;

      }

      else {

        uVar24 = ~uVar24 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

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

    uVar3 = puVar17[7];

    uVar20 = *(unsigned int *)(puVar5 + 4);

    uVar4 = uVar3 ^ uVar20;

    if ((int)uVar3 < 0) {

      uVar3 = -uVar3;

    }

    if ((int)uVar20 < 0) {

      uVar20 = -uVar20;

    }

    uVar22 = (uVar20 & 0xffff) * (uVar3 & 0xffff);

    iVar10 = (uVar20 >> 0x10) * (uVar3 & 0xffff);

    iVar9 = 0;

    uVar23 = iVar10 + (uVar20 & 0xffff) * (uVar3 >> 0x10);

    if (iVar10 != 0) {

      iVar9 = 0x10000;

    }

    uVar25 = uVar22 + uVar23 * 0x10000;

    uVar20 = iVar9 + (unsigned int)(uVar25 < uVar22) + (uVar23 >> 0x10) + (uVar20 >> 0x10) * (uVar3 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar4 < 0) < 0) {

      uVar20 = ~uVar20;

      if (uVar25 == 0) {

        uVar20 = uVar20 + 1;

      }

      else {

        uVar25 = ~uVar25 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      uVar25 = uVar24 + uVar25;

      uVar19 = uVar20 + (uVar25 < uVar24) + (uVar19 & 0xffff);

      if ((int)uVar19 < -0x8000) {

        uVar19 = 0xffff8000;

        uVar25 = 0;

      }

      if (0x7fff < (int)uVar19) {

        uVar19 = 0x7fff;

        uVar25 = 0xffffffff;

      }

      uVar19 = uVar19 & 0xffff;

    }

    else {

      uVar25 = uVar24 + uVar25;

      uVar19 = uVar20 + (uVar25 < uVar24) + uVar19;

    }

    *(unsigned int *)(puVar6 + 0x28) = (uVar18 << 0x10 | uVar26 >> 0x10) + puVar17[10];

    uVar20 = puVar17[8];

    uVar18 = *(unsigned int *)(puVar5 + 8);

    uVar3 = uVar20 ^ uVar18;

    if ((int)uVar20 < 0) {

      uVar20 = -uVar20;

    }

    if ((int)uVar18 < 0) {

      uVar18 = -uVar18;

    }

    uVar23 = (uVar18 & 0xffff) * (uVar20 & 0xffff);

    iVar10 = (uVar18 >> 0x10) * (uVar20 & 0xffff);

    iVar9 = 0;

    uVar4 = iVar10 + (uVar18 & 0xffff) * (uVar20 >> 0x10);

    if (iVar10 != 0) {

      iVar9 = 0x10000;

    }

    uVar26 = uVar23 + uVar4 * 0x10000;

    uVar18 = iVar9 + (unsigned int)(uVar26 < uVar23) + (uVar4 >> 0x10) + (uVar18 >> 0x10) * (uVar20 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

      uVar18 = ~uVar18;

      if (uVar26 == 0) {

        uVar18 = uVar18 + 1;

      }

      else {

        uVar26 = ~uVar26 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      uVar26 = uVar25 + uVar26;

      uVar19 = uVar18 + (uVar26 < uVar25) + (uVar19 & 0xffff);

      if ((int)uVar19 < -0x8000) {

        uVar19 = 0xffff8000;

        uVar26 = 0;

      }

      if (0x7fff < (int)uVar19) {

        uVar19 = 0x7fff;

        uVar26 = 0xffffffff;

      }

      uVar19 = uVar19 & 0xffff;

    }

    else {

      uVar26 = uVar25 + uVar26;

      uVar19 = uVar18 + (uVar26 < uVar25) + uVar19;

    }

    *(unsigned int *)(puVar6 + 0x2c) = (uVar19 << 0x10 | uVar26 >> 0x10) + puVar17[0xb];

    iVar9 = *(int *)(puVar6 + 0x2c);

    unaff_r11[3] = (unsigned short)(iVar9 <= unaff_r10);

    iVar9 = (unsigned int)(iVar9 <= unaff_r10) + (int)unaff_r11[2] + (int)unaff_r11[1] + (int)*unaff_r11;

    uVar19 = uVar11 | iVar9 == 0;

    if (((unsigned char)uVar19 & 1) == 1) {

LAB_0602b600:

      puVar7 = 0x06094A90;

      puVar6 = 0x0608AC20;

      puVar5 = 0x06094A30;

      iVar9 = *(int *)0x060620D0;

      puVar12 = (int *)(int)DAT_0602b64c;

      uVar13 = *(int *)(0x06094A30 + 8);

      puVar12[4] = (int)DAT_0602b64e;

      *puVar12 = uVar13;

      puVar12[5] = 0;

      iVar14 = *(int *)(puVar5 + 4);

      iVar10 = puVar12[7];

      *(int *)puVar7 = (int)((unsigned long long)((long long)iVar10 * (long long)*(int *)puVar5) >> 0x20);

      *(int *)(puVar7 + 4) = (int)((unsigned long long)((long long)iVar10 * (long long)-iVar14) >> 0x20);

      puVar8 = 0x06094A20;

      iVar10 = *(int *)puVar7;

      iVar14 = *(int *)(puVar7 + 4);

      *(short *)0x06094A20 = 0;

      uVar11 = uVar19 & 0xfffffffe;

      if (PTR_DAT_0602b650 < iVar10) {

        *(short *)puVar8 = 1;

      }

      else if (iVar10 < DAT_0602b67c) {

        *(short *)puVar8 = 1;

      }

      else if (DAT_0602b68a < iVar14) {

        *(short *)puVar8 = 1;

      }

      else if (iVar14 < DAT_0602b6d2) {

        *(short *)puVar8 = 1;

      }

      puVar12 = (int *)(int)DAT_0602b6d4;

      uVar13 = *(int *)(puVar5 + 0x14);

      puVar12[4] = (int)DAT_0602b6d6;

      *puVar12 = uVar13;

      puVar12[5] = 0;

      iVar14 = *(int *)(puVar5 + 0x10);

      iVar10 = puVar12[7];

      *(int *)(puVar7 + 8) =

           (int)((unsigned long long)((long long)iVar10 * (long long)*(int *)(puVar5 + 0xc)) >> 0x20);

      *(int *)(puVar7 + 0xc) = (int)((unsigned long long)((long long)iVar10 * (long long)-iVar14) >> 0x20);

      iVar10 = *(int *)(puVar7 + 8);

      iVar14 = *(int *)(puVar7 + 0xc);

      *(short *)(puVar8 + 2) = 0;

      if (DAT_0602b6d8 < iVar10) {

        *(short *)(puVar8 + 2) = 1;

      }

      else if (iVar10 < DAT_0602b6e6) {

        *(short *)(puVar8 + 2) = 1;

      }

      else if (DAT_0602b6f4 < iVar14) {

        *(short *)(puVar8 + 2) = 1;

      }

      else if (iVar14 < DAT_0602b73c) {

        *(short *)(puVar8 + 2) = 1;

      }

      puVar12 = (int *)(int)DAT_0602b73e;

      uVar13 = *(int *)(puVar5 + 0x20);

      puVar12[4] = (int)DAT_0602b740;

      *puVar12 = uVar13;

      puVar12[5] = 0;

      iVar14 = *(int *)(puVar5 + 0x1c);

      iVar10 = puVar12[7];

      *(int *)(puVar7 + 0x10) =

           (int)((unsigned long long)((long long)iVar10 * (long long)*(int *)(puVar5 + 0x18)) >> 0x20);

      *(int *)(puVar7 + 0x14) = (int)((unsigned long long)((long long)iVar10 * (long long)-iVar14) >> 0x20);

      iVar10 = *(int *)(puVar7 + 0x10);

      iVar14 = *(int *)(puVar7 + 0x14);

      *(short *)(puVar8 + 4) = 0;

      if (DAT_0602b742 < iVar10) {

        *(short *)(puVar8 + 4) = 1;

      }

      else if (iVar10 < DAT_0602b750) {

        *(short *)(puVar8 + 4) = 1;

      }

      else if (DAT_0602b75e < iVar14) {

        *(short *)(puVar8 + 4) = 1;

      }

      else if (iVar14 < DAT_0602b7a6) {

        *(short *)(puVar8 + 4) = 1;

      }

      puVar12 = (int *)(int)DAT_0602b7a8;

      uVar13 = *(int *)(puVar5 + 0x2c);

      puVar12[4] = (int)DAT_0602b7aa;

      *puVar12 = uVar13;

      puVar12[5] = 0;

      iVar14 = *(int *)(puVar5 + 0x28);

      iVar10 = puVar12[7];

      *(int *)(puVar7 + 0x18) =

           (int)((unsigned long long)((long long)iVar10 * (long long)*(int *)(puVar5 + 0x24)) >> 0x20);

      *(int *)(puVar7 + 0x1c) = (int)((unsigned long long)((long long)iVar10 * (long long)-iVar14) >> 0x20);

      iVar10 = *(int *)(puVar7 + 0x18);

      iVar14 = *(int *)(puVar7 + 0x1c);

      *(short *)(puVar8 + 6) = 0;

      if (DAT_0602b7ac < iVar10) {

        *(short *)(puVar8 + 6) = 1;

      }

      else if (iVar10 < DAT_0602b7ba) {

        *(short *)(puVar8 + 6) = 1;

      }

      else if (DAT_0602b7c8 < iVar14) {

        *(short *)(puVar8 + 6) = 1;

      }

      else if (iVar14 < DAT_0602b7f8) {

        *(short *)(puVar8 + 6) = 1;

      }

      if (((((int)0xFFFFFF50 <= *(int *)puVar7) ||

           ((int)0xFFFFFF50 <= *(int *)(puVar7 + 8))) ||

          ((int)0xFFFFFF50 <= *(int *)(puVar7 + 0x10))) ||

         (uVar19 = *(unsigned int *)(puVar7 + 0x18), (int)0xFFFFFF50 <= (int)uVar19)) {

        uVar18 = uVar11 | *(int *)puVar7 < 0x000000B0;

        if (((((unsigned char)uVar18 & 1) != 1) &&

            (uVar18 = uVar11 | *(int *)(puVar7 + 8) < 0x000000B0, ((unsigned char)uVar18 & 1) != 1)) &&

           (uVar18 = uVar11 | *(int *)(puVar7 + 0x10) < 0x000000B0, ((unsigned char)uVar18 & 1) != 1)) {

          uVar19 = *(unsigned int *)(puVar7 + 0x18);

          uVar18 = uVar11 | (int)uVar19 < 0x000000B0;

          uVar11 = uVar18;

          if (((unsigned char)uVar18 & 1) != 1) goto LAB_0602b972;

        }

        uVar11 = uVar18 & 0xfffffffe;

        if ((((int)0xFFFFFF81 <= *(int *)(puVar7 + 4)) ||

            ((int)0xFFFFFF81 <= *(int *)(puVar7 + 0xc))) ||

           (((int)0xFFFFFF81 <= *(int *)(puVar7 + 0x14) ||

            (uVar19 = *(unsigned int *)(puVar7 + 0x1c), (int)0xFFFFFF81 <= (int)uVar19)))) {

          uVar18 = uVar11 | *(int *)(puVar7 + 4) < 0x00000051;

          if (((((unsigned char)uVar18 & 1) != 1) &&

              (uVar18 = uVar11 | *(int *)(puVar7 + 0xc) < 0x00000051, ((unsigned char)uVar18 & 1) != 1)) &&

             (uVar18 = uVar11 | *(int *)(puVar7 + 0x14) < 0x00000051, ((unsigned char)uVar18 & 1) != 1)) {

            uVar19 = *(unsigned int *)(puVar7 + 0x1c);

            uVar18 = uVar11 | (int)uVar19 < 0x00000051;

            uVar11 = uVar18;

            if (((unsigned char)uVar18 & 1) != 1) goto LAB_0602b972;

          }

          iVar10 = (int)*(short *)(puVar8 + 6) +

                   (int)*(short *)puVar8 + (int)*(short *)(puVar8 + 2) + (int)*(short *)(puVar8 + 4)

          ;

          if (iVar10 != 4) {

            if (iVar10 != 0) {

              (**(void **)(0x0602B9BC + iVar10 * 4))(puVar7,puVar8);

            }

            *(short *)(puVar6 + iVar9 * 0x18 + 8) = (short)*(int *)puVar7;

            *(short *)(puVar6 + iVar9 * 0x18 + 10) = (short)*(int *)(puVar7 + 4);

            *(short *)(puVar6 + iVar9 * 0x18 + 0xc) = (short)*(int *)(puVar7 + 8);

            *(short *)(puVar6 + iVar9 * 0x18 + 0xe) = (short)*(int *)(puVar7 + 0xc);

            *(short *)(puVar6 + iVar9 * 0x18 + 0x10) = (short)*(int *)(puVar7 + 0x10);

            *(short *)(puVar6 + iVar9 * 0x18 + 0x12) = (short)*(int *)(puVar7 + 0x14);

            *(short *)(puVar6 + iVar9 * 0x18 + 0x14) = (short)*(int *)(puVar7 + 0x18);

            *(short *)(puVar6 + iVar9 * 0x18 + 0x16) = (short)*(int *)(puVar7 + 0x1c);

            *(short *)(puVar6 + iVar9 * 0x18 + 6) = *(short *)((int)unaff_r8 + 0xe);

            puVar6[iVar9 * 0x18 + 4] = (unsigned char)((unsigned int)(int)*(short *)(unaff_r8 + 3) >> 4) & 0xf;

            puVar6[iVar9 * 0x18 + 5] = unaff_r13;

            uVar11 = (**(void **)(0x0602B9CC + ((int)*(short *)(unaff_r8 + 3) & 7U) * 4))

                               (*(int *)(0x06094A30 + 0x14),

                                *(int *)(0x06094A30 + 0x20),

                                *(int *)(0x06094A30 + 0x2c));

            return uVar11;

          }

          uVar19 = 4;

          uVar11 = uVar18 & 0xfffffffe;

        }

      }

    }

    else {

      if (iVar9 != 4) {

        (**(void **)(0x0602B9AC + iVar9 * 4))

                  (0x06094A30,0x06094A28,puVar17 + 9,puVar17 + 0xc);

        uVar19 = uVar11;

        goto LAB_0602b600;

      }

      uVar19 = 4;

    }

LAB_0602b972:

    do {

      puVar17 = unaff_r8;

      puVar5 = 0x06094AB0;

      in_stack_00000000 = in_stack_00000000 + -1;

      uVar18 = uVar11 & 0xfffffffe;

      if (in_stack_00000000 == 0) {

        return uVar19;

      }

      unaff_r8 = puVar17 + -6;

      psVar15 = (short *)((unsigned int)*(unsigned short *)(puVar17 + -2) * 6 + unaff_r14);

      sVar1 = psVar15[1];

      sVar2 = psVar15[2];

      *(int *)0x06094AB0 = (int)*psVar15 << 0xb;

      *(int *)(puVar5 + 4) = (int)sVar1 << 0xb;

      *(int *)(puVar5 + 8) = (int)sVar2 << 0xb;

      puVar6 = 0x06094A30;

      puVar16 = *(unsigned int **)0x06089EDC;

      uVar20 = *puVar16;

      uVar19 = *(unsigned int *)puVar5;

      uVar3 = uVar20 ^ uVar19;

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      if ((int)uVar19 < 0) {

        uVar19 = -uVar19;

      }

      uVar23 = (uVar19 & 0xffff) * (uVar20 & 0xffff);

      iVar10 = (uVar19 >> 0x10) * (uVar20 & 0xffff);

      iVar9 = 0;

      uVar4 = iVar10 + (uVar19 & 0xffff) * (uVar20 >> 0x10);

      if (iVar10 != 0) {

        iVar9 = 0x10000;

      }

      uVar26 = uVar23 + uVar4 * 0x10000;

      uVar19 = iVar9 + (unsigned int)(uVar26 < uVar23) + (uVar4 >> 0x10) +

               (uVar19 >> 0x10) * (uVar20 >> 0x10);

      if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

        uVar19 = ~uVar19;

        if (uVar26 == 0) {

          uVar19 = uVar19 + 1;

        }

        else {

          uVar26 = ~uVar26 + 1;

        }

      }

      if (((unsigned char)(uVar11 >> 1) & 1) == 1) {

        if ((int)uVar19 < -0x8000) {

          uVar19 = 0xffff8000;

          uVar26 = 0;

        }

        if (0x7fff < (int)uVar19) {

          uVar19 = 0x7fff;

          uVar26 = 0xffffffff;

        }

        uVar19 = uVar19 & 0xffff;

      }

      uVar3 = puVar16[1];

      uVar20 = *(unsigned int *)(puVar5 + 4);

      uVar4 = uVar3 ^ uVar20;

      if ((int)uVar3 < 0) {

        uVar3 = -uVar3;

      }

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      uVar24 = (uVar20 & 0xffff) * (uVar3 & 0xffff);

      iVar10 = (uVar20 >> 0x10) * (uVar3 & 0xffff);

      iVar9 = 0;

      uVar23 = iVar10 + (uVar20 & 0xffff) * (uVar3 >> 0x10);

      if (iVar10 != 0) {

        iVar9 = 0x10000;

      }

      uVar22 = uVar24 + uVar23 * 0x10000;

      uVar20 = iVar9 + (unsigned int)(uVar22 < uVar24) + (uVar23 >> 0x10) +

               (uVar20 >> 0x10) * (uVar3 >> 0x10);

      if ((int)-(unsigned int)((int)uVar4 < 0) < 0) {

        uVar20 = ~uVar20;

        if (uVar22 == 0) {

          uVar20 = uVar20 + 1;

        }

        else {

          uVar22 = ~uVar22 + 1;

        }

      }

      if (((unsigned char)(uVar11 >> 1) & 1) == 1) {

        uVar22 = uVar26 + uVar22;

        uVar19 = uVar20 + (uVar22 < uVar26) + (uVar19 & 0xffff);

        if ((int)uVar19 < -0x8000) {

          uVar19 = 0xffff8000;

          uVar22 = 0;

        }

        if (0x7fff < (int)uVar19) {

          uVar19 = 0x7fff;

          uVar22 = 0xffffffff;

        }

        uVar19 = uVar19 & 0xffff;

      }

      else {

        uVar22 = uVar26 + uVar22;

        uVar19 = uVar20 + (uVar22 < uVar26) + uVar19;

      }

      uVar3 = puVar16[2];

      uVar20 = *(unsigned int *)(puVar5 + 8);

      uVar4 = uVar3 ^ uVar20;

      if ((int)uVar3 < 0) {

        uVar3 = -uVar3;

      }

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      uVar26 = (uVar20 & 0xffff) * (uVar3 & 0xffff);

      iVar10 = (uVar20 >> 0x10) * (uVar3 & 0xffff);

      iVar9 = 0;

      uVar23 = iVar10 + (uVar20 & 0xffff) * (uVar3 >> 0x10);

      if (iVar10 != 0) {

        iVar9 = 0x10000;

      }

      uVar24 = uVar26 + uVar23 * 0x10000;

      uVar20 = iVar9 + (unsigned int)(uVar24 < uVar26) + (uVar23 >> 0x10) +

               (uVar20 >> 0x10) * (uVar3 >> 0x10);

      if ((int)-(unsigned int)((int)uVar4 < 0) < 0) {

        uVar20 = ~uVar20;

        if (uVar24 == 0) {

          uVar20 = uVar20 + 1;

        }

        else {

          uVar24 = ~uVar24 + 1;

        }

      }

      if (((unsigned char)(uVar11 >> 1) & 1) == 1) {

        uVar24 = uVar22 + uVar24;

        uVar19 = uVar20 + (uVar24 < uVar22) + (uVar19 & 0xffff);

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

        uVar24 = uVar22 + uVar24;

        uVar19 = uVar20 + (uVar24 < uVar22) + uVar19;

      }

      uVar3 = puVar16[3];

      uVar20 = *(unsigned int *)puVar5;

      uVar4 = uVar3 ^ uVar20;

      if ((int)uVar3 < 0) {

        uVar3 = -uVar3;

      }

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      uVar26 = (uVar20 & 0xffff) * (uVar3 & 0xffff);

      iVar10 = (uVar20 >> 0x10) * (uVar3 & 0xffff);

      iVar9 = 0;

      uVar23 = iVar10 + (uVar20 & 0xffff) * (uVar3 >> 0x10);

      if (iVar10 != 0) {

        iVar9 = 0x10000;

      }

      uVar22 = uVar26 + uVar23 * 0x10000;

      uVar20 = iVar9 + (unsigned int)(uVar22 < uVar26) + (uVar23 >> 0x10) +

               (uVar20 >> 0x10) * (uVar3 >> 0x10);

      if ((int)-(unsigned int)((int)uVar4 < 0) < 0) {

        uVar20 = ~uVar20;

        if (uVar22 == 0) {

          uVar20 = uVar20 + 1;

        }

        else {

          uVar22 = ~uVar22 + 1;

        }

      }

      if (((unsigned char)(uVar11 >> 1) & 1) == 1) {

        if ((int)uVar20 < -0x8000) {

          uVar20 = 0xffff8000;

          uVar22 = 0;

        }

        if (0x7fff < (int)uVar20) {

          uVar20 = 0x7fff;

          uVar22 = 0xffffffff;

        }

        uVar20 = uVar20 & 0xffff;

      }

      uVar4 = puVar16[4];

      uVar3 = *(unsigned int *)(puVar5 + 4);

      uVar23 = uVar4 ^ uVar3;

      if ((int)uVar4 < 0) {

        uVar4 = -uVar4;

      }

      if ((int)uVar3 < 0) {

        uVar3 = -uVar3;

      }

      uVar25 = (uVar3 & 0xffff) * (uVar4 & 0xffff);

      iVar10 = (uVar3 >> 0x10) * (uVar4 & 0xffff);

      iVar9 = 0;

      uVar26 = iVar10 + (uVar3 & 0xffff) * (uVar4 >> 0x10);

      if (iVar10 != 0) {

        iVar9 = 0x10000;

      }

      uVar21 = uVar25 + uVar26 * 0x10000;

      uVar3 = iVar9 + (unsigned int)(uVar21 < uVar25) + (uVar26 >> 0x10) + (uVar3 >> 0x10) * (uVar4 >> 0x10)

      ;

      if ((int)-(unsigned int)((int)uVar23 < 0) < 0) {

        uVar3 = ~uVar3;

        if (uVar21 == 0) {

          uVar3 = uVar3 + 1;

        }

        else {

          uVar21 = ~uVar21 + 1;

        }

      }

      if (((unsigned char)(uVar11 >> 1) & 1) == 1) {

        uVar21 = uVar22 + uVar21;

        uVar20 = uVar3 + (uVar21 < uVar22) + (uVar20 & 0xffff);

        if ((int)uVar20 < -0x8000) {

          uVar20 = 0xffff8000;

          uVar21 = 0;

        }

        if (0x7fff < (int)uVar20) {

          uVar20 = 0x7fff;

          uVar21 = 0xffffffff;

        }

        uVar20 = uVar20 & 0xffff;

      }

      else {

        uVar21 = uVar22 + uVar21;

        uVar20 = uVar3 + (uVar21 < uVar22) + uVar20;

      }

      *(unsigned int *)0x06094A30 = (uVar19 << 0x10 | uVar24 >> 0x10) + puVar16[9];

      uVar3 = puVar16[5];

      uVar19 = *(unsigned int *)(puVar5 + 8);

      uVar4 = uVar3 ^ uVar19;

      if ((int)uVar3 < 0) {

        uVar3 = -uVar3;

      }

      if ((int)uVar19 < 0) {

        uVar19 = -uVar19;

      }

      uVar26 = (uVar19 & 0xffff) * (uVar3 & 0xffff);

      iVar10 = (uVar19 >> 0x10) * (uVar3 & 0xffff);

      iVar9 = 0;

      uVar23 = iVar10 + (uVar19 & 0xffff) * (uVar3 >> 0x10);

      if (iVar10 != 0) {

        iVar9 = 0x10000;

      }

      uVar24 = uVar26 + uVar23 * 0x10000;

      uVar19 = iVar9 + (unsigned int)(uVar24 < uVar26) + (uVar23 >> 0x10) +

               (uVar19 >> 0x10) * (uVar3 >> 0x10);

      if ((int)-(unsigned int)((int)uVar4 < 0) < 0) {

        uVar19 = ~uVar19;

        if (uVar24 == 0) {

          uVar19 = uVar19 + 1;

        }

        else {

          uVar24 = ~uVar24 + 1;

        }

      }

      if (((unsigned char)(uVar11 >> 1) & 1) == 1) {

        uVar24 = uVar21 + uVar24;

        uVar20 = uVar19 + (uVar24 < uVar21) + (uVar20 & 0xffff);

        if ((int)uVar20 < -0x8000) {

          uVar20 = 0xffff8000;

          uVar24 = 0;

        }

        if (0x7fff < (int)uVar20) {

          uVar20 = 0x7fff;

          uVar24 = 0xffffffff;

        }

        uVar20 = uVar20 & 0xffff;

      }

      else {

        uVar24 = uVar21 + uVar24;

        uVar20 = uVar19 + (uVar24 < uVar21) + uVar20;

      }

      uVar3 = puVar16[6];

      uVar19 = *(unsigned int *)puVar5;

      uVar4 = uVar3 ^ uVar19;

      if ((int)uVar3 < 0) {

        uVar3 = -uVar3;

      }

      if ((int)uVar19 < 0) {

        uVar19 = -uVar19;

      }

      uVar26 = (uVar19 & 0xffff) * (uVar3 & 0xffff);

      iVar10 = (uVar19 >> 0x10) * (uVar3 & 0xffff);

      iVar9 = 0;

      uVar23 = iVar10 + (uVar19 & 0xffff) * (uVar3 >> 0x10);

      if (iVar10 != 0) {

        iVar9 = 0x10000;

      }

      uVar22 = uVar26 + uVar23 * 0x10000;

      uVar19 = iVar9 + (unsigned int)(uVar22 < uVar26) + (uVar23 >> 0x10) +

               (uVar19 >> 0x10) * (uVar3 >> 0x10);

      if ((int)-(unsigned int)((int)uVar4 < 0) < 0) {

        uVar19 = ~uVar19;

        if (uVar22 == 0) {

          uVar19 = uVar19 + 1;

        }

        else {

          uVar22 = ~uVar22 + 1;

        }

      }

      if (((unsigned char)(uVar11 >> 1) & 1) == 1) {

        if ((int)uVar19 < -0x8000) {

          uVar19 = 0xffff8000;

          uVar22 = 0;

        }

        if (0x7fff < (int)uVar19) {

          uVar19 = 0x7fff;

          uVar22 = 0xffffffff;

        }

        uVar19 = uVar19 & 0xffff;

      }

      uVar4 = puVar16[7];

      uVar3 = *(unsigned int *)(puVar5 + 4);

      uVar23 = uVar4 ^ uVar3;

      if ((int)uVar4 < 0) {

        uVar4 = -uVar4;

      }

      if ((int)uVar3 < 0) {

        uVar3 = -uVar3;

      }

      uVar25 = (uVar3 & 0xffff) * (uVar4 & 0xffff);

      iVar10 = (uVar3 >> 0x10) * (uVar4 & 0xffff);

      iVar9 = 0;

      uVar26 = iVar10 + (uVar3 & 0xffff) * (uVar4 >> 0x10);

      if (iVar10 != 0) {

        iVar9 = 0x10000;

      }

      uVar21 = uVar25 + uVar26 * 0x10000;

      uVar3 = iVar9 + (unsigned int)(uVar21 < uVar25) + (uVar26 >> 0x10) + (uVar3 >> 0x10) * (uVar4 >> 0x10)

      ;

      if ((int)-(unsigned int)((int)uVar23 < 0) < 0) {

        uVar3 = ~uVar3;

        if (uVar21 == 0) {

          uVar3 = uVar3 + 1;

        }

        else {

          uVar21 = ~uVar21 + 1;

        }

      }

      if (((unsigned char)(uVar11 >> 1) & 1) == 1) {

        uVar21 = uVar22 + uVar21;

        uVar19 = uVar3 + (uVar21 < uVar22) + (uVar19 & 0xffff);

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

        uVar21 = uVar22 + uVar21;

        uVar19 = uVar3 + (uVar21 < uVar22) + uVar19;

      }

      *(unsigned int *)(puVar6 + 4) = (uVar20 << 0x10 | uVar24 >> 0x10) + puVar16[10];

      uVar3 = puVar16[8];

      uVar20 = *(unsigned int *)(puVar5 + 8);

      uVar4 = uVar3 ^ uVar20;

      if ((int)uVar3 < 0) {

        uVar3 = -uVar3;

      }

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      uVar26 = (uVar20 & 0xffff) * (uVar3 & 0xffff);

      iVar10 = (uVar20 >> 0x10) * (uVar3 & 0xffff);

      iVar9 = 0;

      uVar23 = iVar10 + (uVar20 & 0xffff) * (uVar3 >> 0x10);

      if (iVar10 != 0) {

        iVar9 = 0x10000;

      }

      uVar24 = uVar26 + uVar23 * 0x10000;

      uVar20 = iVar9 + (unsigned int)(uVar24 < uVar26) + (uVar23 >> 0x10) +

               (uVar20 >> 0x10) * (uVar3 >> 0x10);

      if ((int)-(unsigned int)((int)uVar4 < 0) < 0) {

        uVar20 = ~uVar20;

        if (uVar24 == 0) {

          uVar20 = uVar20 + 1;

        }

        else {

          uVar24 = ~uVar24 + 1;

        }

      }

      if (((unsigned char)(uVar11 >> 1) & 1) == 1) {

        uVar24 = uVar21 + uVar24;

        uVar19 = uVar20 + (uVar24 < uVar21) + (uVar19 & 0xffff);

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

        uVar24 = uVar21 + uVar24;

        uVar19 = uVar20 + (uVar24 < uVar21) + uVar19;

      }

      *(unsigned int *)(puVar6 + 8) = (uVar19 << 0x10 | uVar24 >> 0x10) + puVar16[0xb];

      unaff_r11 = (short *)0x06094A28;

      *(unsigned short *)0x06094A28 = (unsigned short)(*(int *)(puVar6 + 8) <= unaff_r10);

      puVar5 = 0x06094A60;

      if ((puVar17[-3] & 0x80000) != 0) break;

      puVar16 = *(unsigned int **)0x06089EDC;

      uVar20 = *puVar16;

      uVar19 = *unaff_r8;

      uVar3 = uVar20 ^ uVar19;

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      if ((int)uVar19 < 0) {

        uVar19 = -uVar19;

      }

      uVar23 = (uVar19 & 0xffff) * (uVar20 & 0xffff);

      iVar10 = (uVar19 >> 0x10) * (uVar20 & 0xffff);

      iVar9 = 0;

      uVar4 = iVar10 + (uVar19 & 0xffff) * (uVar20 >> 0x10);

      if (iVar10 != 0) {

        iVar9 = 0x10000;

      }

      uVar26 = uVar23 + uVar4 * 0x10000;

      uVar19 = iVar9 + (unsigned int)(uVar26 < uVar23) + (uVar4 >> 0x10) +

               (uVar19 >> 0x10) * (uVar20 >> 0x10);

      if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

        uVar19 = ~uVar19;

        if (uVar26 == 0) {

          uVar19 = uVar19 + 1;

        }

        else {

          uVar26 = ~uVar26 + 1;

        }

      }

      if (((unsigned char)(uVar11 >> 1) & 1) == 1) {

        if ((int)uVar19 < -0x8000) {

          uVar19 = 0xffff8000;

          uVar26 = 0;

        }

        if (0x7fff < (int)uVar19) {

          uVar19 = 0x7fff;

          uVar26 = 0xffffffff;

        }

        uVar19 = uVar19 & 0xffff;

      }

      uVar3 = puVar16[1];

      uVar20 = puVar17[-5];

      uVar4 = uVar3 ^ uVar20;

      if ((int)uVar3 < 0) {

        uVar3 = -uVar3;

      }

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      uVar24 = (uVar20 & 0xffff) * (uVar3 & 0xffff);

      iVar10 = (uVar20 >> 0x10) * (uVar3 & 0xffff);

      iVar9 = 0;

      uVar23 = iVar10 + (uVar20 & 0xffff) * (uVar3 >> 0x10);

      if (iVar10 != 0) {

        iVar9 = 0x10000;

      }

      uVar22 = uVar24 + uVar23 * 0x10000;

      uVar20 = iVar9 + (unsigned int)(uVar22 < uVar24) + (uVar23 >> 0x10) +

               (uVar20 >> 0x10) * (uVar3 >> 0x10);

      if ((int)-(unsigned int)((int)uVar4 < 0) < 0) {

        uVar20 = ~uVar20;

        if (uVar22 == 0) {

          uVar20 = uVar20 + 1;

        }

        else {

          uVar22 = ~uVar22 + 1;

        }

      }

      if (((unsigned char)(uVar11 >> 1) & 1) == 1) {

        uVar22 = uVar26 + uVar22;

        uVar19 = uVar20 + (uVar22 < uVar26) + (uVar19 & 0xffff);

        if ((int)uVar19 < -0x8000) {

          uVar19 = 0xffff8000;

          uVar22 = 0;

        }

        if (0x7fff < (int)uVar19) {

          uVar19 = 0x7fff;

          uVar22 = 0xffffffff;

        }

        uVar19 = uVar19 & 0xffff;

      }

      else {

        uVar22 = uVar26 + uVar22;

        uVar19 = uVar20 + (uVar22 < uVar26) + uVar19;

      }

      uVar3 = puVar16[2];

      uVar20 = puVar17[-4];

      uVar4 = uVar3 ^ uVar20;

      if ((int)uVar3 < 0) {

        uVar3 = -uVar3;

      }

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      uVar26 = (uVar20 & 0xffff) * (uVar3 & 0xffff);

      iVar10 = (uVar20 >> 0x10) * (uVar3 & 0xffff);

      iVar9 = 0;

      uVar23 = iVar10 + (uVar20 & 0xffff) * (uVar3 >> 0x10);

      if (iVar10 != 0) {

        iVar9 = 0x10000;

      }

      uVar24 = uVar26 + uVar23 * 0x10000;

      uVar20 = iVar9 + (unsigned int)(uVar24 < uVar26) + (uVar23 >> 0x10) +

               (uVar20 >> 0x10) * (uVar3 >> 0x10);

      if ((int)-(unsigned int)((int)uVar4 < 0) < 0) {

        uVar20 = ~uVar20;

        if (uVar24 == 0) {

          uVar20 = uVar20 + 1;

        }

        else {

          uVar24 = ~uVar24 + 1;

        }

      }

      if (((unsigned char)(uVar11 >> 1) & 1) == 1) {

        uVar24 = uVar22 + uVar24;

        uVar19 = uVar20 + (uVar24 < uVar22) + (uVar19 & 0xffff);

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

        uVar24 = uVar22 + uVar24;

        uVar19 = uVar20 + (uVar24 < uVar22) + uVar19;

      }

      uVar3 = puVar16[3];

      uVar20 = *unaff_r8;

      uVar4 = uVar3 ^ uVar20;

      if ((int)uVar3 < 0) {

        uVar3 = -uVar3;

      }

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      uVar26 = (uVar20 & 0xffff) * (uVar3 & 0xffff);

      iVar10 = (uVar20 >> 0x10) * (uVar3 & 0xffff);

      iVar9 = 0;

      uVar23 = iVar10 + (uVar20 & 0xffff) * (uVar3 >> 0x10);

      if (iVar10 != 0) {

        iVar9 = 0x10000;

      }

      uVar22 = uVar26 + uVar23 * 0x10000;

      uVar20 = iVar9 + (unsigned int)(uVar22 < uVar26) + (uVar23 >> 0x10) +

               (uVar20 >> 0x10) * (uVar3 >> 0x10);

      if ((int)-(unsigned int)((int)uVar4 < 0) < 0) {

        uVar20 = ~uVar20;

        if (uVar22 == 0) {

          uVar20 = uVar20 + 1;

        }

        else {

          uVar22 = ~uVar22 + 1;

        }

      }

      if (((unsigned char)(uVar11 >> 1) & 1) == 1) {

        if ((int)uVar20 < -0x8000) {

          uVar20 = 0xffff8000;

          uVar22 = 0;

        }

        if (0x7fff < (int)uVar20) {

          uVar20 = 0x7fff;

          uVar22 = 0xffffffff;

        }

        uVar20 = uVar20 & 0xffff;

      }

      *(unsigned int *)0x06094A60 = uVar19 << 0x10 | uVar24 >> 0x10;

      uVar3 = puVar16[4];

      uVar19 = puVar17[-5];

      uVar4 = uVar3 ^ uVar19;

      if ((int)uVar3 < 0) {

        uVar3 = -uVar3;

      }

      if ((int)uVar19 < 0) {

        uVar19 = -uVar19;

      }

      uVar26 = (uVar19 & 0xffff) * (uVar3 & 0xffff);

      iVar10 = (uVar19 >> 0x10) * (uVar3 & 0xffff);

      iVar9 = 0;

      uVar23 = iVar10 + (uVar19 & 0xffff) * (uVar3 >> 0x10);

      if (iVar10 != 0) {

        iVar9 = 0x10000;

      }

      uVar24 = uVar26 + uVar23 * 0x10000;

      uVar19 = iVar9 + (unsigned int)(uVar24 < uVar26) + (uVar23 >> 0x10) +

               (uVar19 >> 0x10) * (uVar3 >> 0x10);

      if ((int)-(unsigned int)((int)uVar4 < 0) < 0) {

        uVar19 = ~uVar19;

        if (uVar24 == 0) {

          uVar19 = uVar19 + 1;

        }

        else {

          uVar24 = ~uVar24 + 1;

        }

      }

      if (((unsigned char)(uVar11 >> 1) & 1) == 1) {

        uVar24 = uVar22 + uVar24;

        uVar20 = uVar19 + (uVar24 < uVar22) + (uVar20 & 0xffff);

        if ((int)uVar20 < -0x8000) {

          uVar20 = 0xffff8000;

          uVar24 = 0;

        }

        if (0x7fff < (int)uVar20) {

          uVar20 = 0x7fff;

          uVar24 = 0xffffffff;

        }

        uVar20 = uVar20 & 0xffff;

      }

      else {

        uVar24 = uVar22 + uVar24;

        uVar20 = uVar19 + (uVar24 < uVar22) + uVar20;

      }

      uVar3 = puVar16[5];

      uVar19 = puVar17[-4];

      uVar4 = uVar3 ^ uVar19;

      if ((int)uVar3 < 0) {

        uVar3 = -uVar3;

      }

      if ((int)uVar19 < 0) {

        uVar19 = -uVar19;

      }

      uVar26 = (uVar19 & 0xffff) * (uVar3 & 0xffff);

      iVar10 = (uVar19 >> 0x10) * (uVar3 & 0xffff);

      iVar9 = 0;

      uVar23 = iVar10 + (uVar19 & 0xffff) * (uVar3 >> 0x10);

      if (iVar10 != 0) {

        iVar9 = 0x10000;

      }

      uVar22 = uVar26 + uVar23 * 0x10000;

      uVar19 = iVar9 + (unsigned int)(uVar22 < uVar26) + (uVar23 >> 0x10) +

               (uVar19 >> 0x10) * (uVar3 >> 0x10);

      if ((int)-(unsigned int)((int)uVar4 < 0) < 0) {

        uVar19 = ~uVar19;

        if (uVar22 == 0) {

          uVar19 = uVar19 + 1;

        }

        else {

          uVar22 = ~uVar22 + 1;

        }

      }

      if (((unsigned char)(uVar11 >> 1) & 1) == 1) {

        uVar22 = uVar24 + uVar22;

        uVar20 = uVar19 + (uVar22 < uVar24) + (uVar20 & 0xffff);

        if ((int)uVar20 < -0x8000) {

          uVar20 = 0xffff8000;

          uVar22 = 0;

        }

        if (0x7fff < (int)uVar20) {

          uVar20 = 0x7fff;

          uVar22 = 0xffffffff;

        }

        uVar20 = uVar20 & 0xffff;

      }

      else {

        uVar22 = uVar24 + uVar22;

        uVar20 = uVar19 + (uVar22 < uVar24) + uVar20;

      }

      uVar3 = puVar16[6];

      uVar19 = *unaff_r8;

      uVar4 = uVar3 ^ uVar19;

      if ((int)uVar3 < 0) {

        uVar3 = -uVar3;

      }

      if ((int)uVar19 < 0) {

        uVar19 = -uVar19;

      }

      uVar26 = (uVar19 & 0xffff) * (uVar3 & 0xffff);

      iVar10 = (uVar19 >> 0x10) * (uVar3 & 0xffff);

      iVar9 = 0;

      uVar23 = iVar10 + (uVar19 & 0xffff) * (uVar3 >> 0x10);

      if (iVar10 != 0) {

        iVar9 = 0x10000;

      }

      uVar24 = uVar26 + uVar23 * 0x10000;

      uVar19 = iVar9 + (unsigned int)(uVar24 < uVar26) + (uVar23 >> 0x10) +

               (uVar19 >> 0x10) * (uVar3 >> 0x10);

      if ((int)-(unsigned int)((int)uVar4 < 0) < 0) {

        uVar19 = ~uVar19;

        if (uVar24 == 0) {

          uVar19 = uVar19 + 1;

        }

        else {

          uVar24 = ~uVar24 + 1;

        }

      }

      if (((unsigned char)(uVar11 >> 1) & 1) == 1) {

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

      *(unsigned int *)(puVar5 + 4) = uVar20 << 0x10 | uVar22 >> 0x10;

      uVar3 = puVar16[7];

      uVar20 = puVar17[-5];

      uVar4 = uVar3 ^ uVar20;

      if ((int)uVar3 < 0) {

        uVar3 = -uVar3;

      }

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      uVar26 = (uVar20 & 0xffff) * (uVar3 & 0xffff);

      iVar10 = (uVar20 >> 0x10) * (uVar3 & 0xffff);

      iVar9 = 0;

      uVar23 = iVar10 + (uVar20 & 0xffff) * (uVar3 >> 0x10);

      if (iVar10 != 0) {

        iVar9 = 0x10000;

      }

      uVar22 = uVar26 + uVar23 * 0x10000;

      uVar20 = iVar9 + (unsigned int)(uVar22 < uVar26) + (uVar23 >> 0x10) +

               (uVar20 >> 0x10) * (uVar3 >> 0x10);

      if ((int)-(unsigned int)((int)uVar4 < 0) < 0) {

        uVar20 = ~uVar20;

        if (uVar22 == 0) {

          uVar20 = uVar20 + 1;

        }

        else {

          uVar22 = ~uVar22 + 1;

        }

      }

      if (((unsigned char)(uVar11 >> 1) & 1) == 1) {

        uVar22 = uVar24 + uVar22;

        uVar19 = uVar20 + (uVar22 < uVar24) + (uVar19 & 0xffff);

        if ((int)uVar19 < -0x8000) {

          uVar19 = 0xffff8000;

          uVar22 = 0;

        }

        if (0x7fff < (int)uVar19) {

          uVar19 = 0x7fff;

          uVar22 = 0xffffffff;

        }

        uVar19 = uVar19 & 0xffff;

      }

      else {

        uVar22 = uVar24 + uVar22;

        uVar19 = uVar20 + (uVar22 < uVar24) + uVar19;

      }

      uVar3 = puVar16[8];

      uVar20 = puVar17[-4];

      uVar4 = uVar3 ^ uVar20;

      if ((int)uVar3 < 0) {

        uVar3 = -uVar3;

      }

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      uVar26 = (uVar20 & 0xffff) * (uVar3 & 0xffff);

      iVar10 = (uVar20 >> 0x10) * (uVar3 & 0xffff);

      iVar9 = 0;

      uVar23 = iVar10 + (uVar20 & 0xffff) * (uVar3 >> 0x10);

      if (iVar10 != 0) {

        iVar9 = 0x10000;

      }

      uVar24 = uVar26 + uVar23 * 0x10000;

      uVar20 = iVar9 + (unsigned int)(uVar24 < uVar26) + (uVar23 >> 0x10) +

               (uVar20 >> 0x10) * (uVar3 >> 0x10);

      if ((int)-(unsigned int)((int)uVar4 < 0) < 0) {

        uVar20 = ~uVar20;

        if (uVar24 == 0) {

          uVar20 = uVar20 + 1;

        }

        else {

          uVar24 = ~uVar24 + 1;

        }

      }

      if (((unsigned char)(uVar11 >> 1) & 1) == 1) {

        uVar24 = uVar22 + uVar24;

        uVar19 = uVar20 + (uVar24 < uVar22) + (uVar19 & 0xffff);

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

        uVar24 = uVar22 + uVar24;

        uVar19 = uVar20 + (uVar24 < uVar22) + uVar19;

      }

      *(unsigned int *)(puVar5 + 8) = uVar19 << 0x10 | uVar24 >> 0x10;

      uVar20 = *(unsigned int *)puVar5;

      uVar19 = *(unsigned int *)0x06094A30;

      uVar3 = uVar20 ^ uVar19;

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      if ((int)uVar19 < 0) {

        uVar19 = -uVar19;

      }

      uVar23 = (uVar19 & 0xffff) * (uVar20 & 0xffff);

      iVar10 = (uVar19 >> 0x10) * (uVar20 & 0xffff);

      iVar9 = 0;

      uVar4 = iVar10 + (uVar19 & 0xffff) * (uVar20 >> 0x10);

      if (iVar10 != 0) {

        iVar9 = 0x10000;

      }

      uVar26 = uVar23 + uVar4 * 0x10000;

      uVar19 = iVar9 + (unsigned int)(uVar26 < uVar23) + (uVar4 >> 0x10) +

               (uVar19 >> 0x10) * (uVar20 >> 0x10);

      if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

        uVar19 = ~uVar19;

        if (uVar26 == 0) {

          uVar19 = uVar19 + 1;

        }

        else {

          uVar26 = ~uVar26 + 1;

        }

      }

      if (((unsigned char)(uVar11 >> 1) & 1) == 1) {

        if ((int)uVar19 < -0x8000) {

          uVar19 = 0xffff8000;

          uVar26 = 0;

        }

        if (0x7fff < (int)uVar19) {

          uVar19 = 0x7fff;

          uVar26 = 0xffffffff;

        }

        uVar19 = uVar19 & 0xffff;

      }

      uVar3 = *(unsigned int *)(puVar5 + 4);

      uVar20 = *(unsigned int *)(0x06094A30 + 4);

      uVar4 = uVar3 ^ uVar20;

      if ((int)uVar3 < 0) {

        uVar3 = -uVar3;

      }

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      uVar24 = (uVar20 & 0xffff) * (uVar3 & 0xffff);

      iVar10 = (uVar20 >> 0x10) * (uVar3 & 0xffff);

      iVar9 = 0;

      uVar23 = iVar10 + (uVar20 & 0xffff) * (uVar3 >> 0x10);

      if (iVar10 != 0) {

        iVar9 = 0x10000;

      }

      uVar22 = uVar24 + uVar23 * 0x10000;

      uVar20 = iVar9 + (unsigned int)(uVar22 < uVar24) + (uVar23 >> 0x10) +

               (uVar20 >> 0x10) * (uVar3 >> 0x10);

      if ((int)-(unsigned int)((int)uVar4 < 0) < 0) {

        uVar20 = ~uVar20;

        if (uVar22 == 0) {

          uVar20 = uVar20 + 1;

        }

        else {

          uVar22 = ~uVar22 + 1;

        }

      }

      if (((unsigned char)(uVar11 >> 1) & 1) == 1) {

        uVar22 = uVar26 + uVar22;

        uVar19 = uVar20 + (uVar22 < uVar26) + (uVar19 & 0xffff);

        if ((int)uVar19 < -0x8000) {

          uVar19 = 0xffff8000;

          uVar22 = 0;

        }

        if (0x7fff < (int)uVar19) {

          uVar19 = 0x7fff;

          uVar22 = 0xffffffff;

        }

        uVar19 = uVar19 & 0xffff;

      }

      else {

        uVar22 = uVar26 + uVar22;

        uVar19 = uVar20 + (uVar22 < uVar26) + uVar19;

      }

      uVar3 = *(unsigned int *)(puVar5 + 8);

      uVar20 = *(unsigned int *)(0x06094A30 + 8);

      uVar4 = uVar3 ^ uVar20;

      if ((int)uVar3 < 0) {

        uVar3 = -uVar3;

      }

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      uVar26 = (uVar20 & 0xffff) * (uVar3 & 0xffff);

      iVar10 = (uVar20 >> 0x10) * (uVar3 & 0xffff);

      iVar9 = 0;

      uVar23 = iVar10 + (uVar20 & 0xffff) * (uVar3 >> 0x10);

      if (iVar10 != 0) {

        iVar9 = 0x10000;

      }

      uVar24 = uVar26 + uVar23 * 0x10000;

      uVar20 = iVar9 + (unsigned int)(uVar24 < uVar26) + (uVar23 >> 0x10) +

               (uVar20 >> 0x10) * (uVar3 >> 0x10);

      if ((int)-(unsigned int)((int)uVar4 < 0) < 0) {

        uVar20 = ~uVar20;

        if (uVar24 == 0) {

          uVar20 = uVar20 + 1;

        }

        else {

          uVar24 = ~uVar24 + 1;

        }

      }

      if (((unsigned char)(uVar11 >> 1) & 1) == 1) {

        uVar24 = uVar22 + uVar24;

        uVar19 = uVar20 + (uVar24 < uVar22) + (uVar19 & 0xffff);

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

        uVar24 = uVar22 + uVar24;

        uVar19 = uVar20 + (uVar24 < uVar22) + uVar19;

      }

      uVar19 = uVar19 << 0x10 | uVar24 >> 0x10;

      uVar18 = uVar18 | 0 < (int)uVar19;

      uVar11 = uVar18;

    } while (((unsigned char)uVar18 & 1) != 1);

    puVar5 = 0x06094AB0;

    psVar15 = (short *)((unsigned int)*(unsigned short *)((int)puVar17 + -6) * 6 + unaff_r14);

    sVar1 = psVar15[1];

    sVar2 = psVar15[2];

    *(int *)0x06094AB0 = (int)*psVar15 << 0xb;

    *(int *)(puVar5 + 4) = (int)sVar1 << 0xb;

    *(int *)(puVar5 + 8) = (int)sVar2 << 0xb;

    puVar6 = 0x06094A30;

    puVar16 = *(unsigned int **)0x06089EDC;

    uVar19 = *puVar16;

    uVar11 = *(unsigned int *)puVar5;

    uVar20 = uVar19 ^ uVar11;

    if ((int)uVar19 < 0) {

      uVar19 = -uVar19;

    }

    if ((int)uVar11 < 0) {

      uVar11 = -uVar11;

    }

    uVar4 = (uVar11 & 0xffff) * (uVar19 & 0xffff);

    iVar10 = (uVar11 >> 0x10) * (uVar19 & 0xffff);

    iVar9 = 0;

    uVar3 = iVar10 + (uVar11 & 0xffff) * (uVar19 >> 0x10);

    if (iVar10 != 0) {

      iVar9 = 0x10000;

    }

    uVar23 = uVar4 + uVar3 * 0x10000;

    uVar11 = iVar9 + (unsigned int)(uVar23 < uVar4) + (uVar3 >> 0x10) + (uVar11 >> 0x10) * (uVar19 >> 0x10);

    if ((int)-(unsigned int)((int)uVar20 < 0) < 0) {

      uVar11 = ~uVar11;

      if (uVar23 == 0) {

        uVar11 = uVar11 + 1;

      }

      else {

        uVar23 = ~uVar23 + 1;

      }

    }

    if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

      if ((int)uVar11 < -0x8000) {

        uVar11 = 0xffff8000;

        uVar23 = 0;

      }

      if (0x7fff < (int)uVar11) {

        uVar11 = 0x7fff;

        uVar23 = 0xffffffff;

      }

      uVar11 = uVar11 & 0xffff;

    }

    uVar20 = puVar16[1];

    uVar19 = *(unsigned int *)(puVar5 + 4);

    uVar3 = uVar20 ^ uVar19;

    if ((int)uVar20 < 0) {

      uVar20 = -uVar20;

    }

    if ((int)uVar19 < 0) {

      uVar19 = -uVar19;

    }

    uVar26 = (uVar19 & 0xffff) * (uVar20 & 0xffff);

    iVar10 = (uVar19 >> 0x10) * (uVar20 & 0xffff);

    iVar9 = 0;

    uVar4 = iVar10 + (uVar19 & 0xffff) * (uVar20 >> 0x10);

    if (iVar10 != 0) {

      iVar9 = 0x10000;

    }

    uVar24 = uVar26 + uVar4 * 0x10000;

    uVar19 = iVar9 + (unsigned int)(uVar24 < uVar26) + (uVar4 >> 0x10) + (uVar19 >> 0x10) * (uVar20 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

      uVar19 = ~uVar19;

      if (uVar24 == 0) {

        uVar19 = uVar19 + 1;

      }

      else {

        uVar24 = ~uVar24 + 1;

      }

    }

    if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

      uVar24 = uVar23 + uVar24;

      uVar11 = uVar19 + (uVar24 < uVar23) + (uVar11 & 0xffff);

      if ((int)uVar11 < -0x8000) {

        uVar11 = 0xffff8000;

        uVar24 = 0;

      }

      if (0x7fff < (int)uVar11) {

        uVar11 = 0x7fff;

        uVar24 = 0xffffffff;

      }

      uVar11 = uVar11 & 0xffff;

    }

    else {

      uVar24 = uVar23 + uVar24;

      uVar11 = uVar19 + (uVar24 < uVar23) + uVar11;

    }

    uVar20 = puVar16[2];

    uVar19 = *(unsigned int *)(puVar5 + 8);

    uVar3 = uVar20 ^ uVar19;

    if ((int)uVar20 < 0) {

      uVar20 = -uVar20;

    }

    if ((int)uVar19 < 0) {

      uVar19 = -uVar19;

    }

    uVar23 = (uVar19 & 0xffff) * (uVar20 & 0xffff);

    iVar10 = (uVar19 >> 0x10) * (uVar20 & 0xffff);

    iVar9 = 0;

    uVar4 = iVar10 + (uVar19 & 0xffff) * (uVar20 >> 0x10);

    if (iVar10 != 0) {

      iVar9 = 0x10000;

    }

    uVar26 = uVar23 + uVar4 * 0x10000;

    uVar19 = iVar9 + (unsigned int)(uVar26 < uVar23) + (uVar4 >> 0x10) + (uVar19 >> 0x10) * (uVar20 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

      uVar19 = ~uVar19;

      if (uVar26 == 0) {

        uVar19 = uVar19 + 1;

      }

      else {

        uVar26 = ~uVar26 + 1;

      }

    }

    if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

      uVar26 = uVar24 + uVar26;

      uVar11 = uVar19 + (uVar26 < uVar24) + (uVar11 & 0xffff);

      if ((int)uVar11 < -0x8000) {

        uVar11 = 0xffff8000;

        uVar26 = 0;

      }

      if (0x7fff < (int)uVar11) {

        uVar11 = 0x7fff;

        uVar26 = 0xffffffff;

      }

      uVar11 = uVar11 & 0xffff;

    }

    else {

      uVar26 = uVar24 + uVar26;

      uVar11 = uVar19 + (uVar26 < uVar24) + uVar11;

    }

    uVar20 = puVar16[3];

    uVar19 = *(unsigned int *)puVar5;

    uVar3 = uVar20 ^ uVar19;

    if ((int)uVar20 < 0) {

      uVar20 = -uVar20;

    }

    if ((int)uVar19 < 0) {

      uVar19 = -uVar19;

    }

    uVar23 = (uVar19 & 0xffff) * (uVar20 & 0xffff);

    iVar10 = (uVar19 >> 0x10) * (uVar20 & 0xffff);

    iVar9 = 0;

    uVar4 = iVar10 + (uVar19 & 0xffff) * (uVar20 >> 0x10);

    if (iVar10 != 0) {

      iVar9 = 0x10000;

    }

    uVar24 = uVar23 + uVar4 * 0x10000;

    uVar19 = iVar9 + (unsigned int)(uVar24 < uVar23) + (uVar4 >> 0x10) + (uVar19 >> 0x10) * (uVar20 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

      uVar19 = ~uVar19;

      if (uVar24 == 0) {

        uVar19 = uVar19 + 1;

      }

      else {

        uVar24 = ~uVar24 + 1;

      }

    }

    if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

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

    uVar3 = puVar16[4];

    uVar20 = *(unsigned int *)(puVar5 + 4);

    uVar4 = uVar3 ^ uVar20;

    if ((int)uVar3 < 0) {

      uVar3 = -uVar3;

    }

    if ((int)uVar20 < 0) {

      uVar20 = -uVar20;

    }

    uVar22 = (uVar20 & 0xffff) * (uVar3 & 0xffff);

    iVar10 = (uVar20 >> 0x10) * (uVar3 & 0xffff);

    iVar9 = 0;

    uVar23 = iVar10 + (uVar20 & 0xffff) * (uVar3 >> 0x10);

    if (iVar10 != 0) {

      iVar9 = 0x10000;

    }

    uVar25 = uVar22 + uVar23 * 0x10000;

    uVar20 = iVar9 + (unsigned int)(uVar25 < uVar22) + (uVar23 >> 0x10) + (uVar20 >> 0x10) * (uVar3 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar4 < 0) < 0) {

      uVar20 = ~uVar20;

      if (uVar25 == 0) {

        uVar20 = uVar20 + 1;

      }

      else {

        uVar25 = ~uVar25 + 1;

      }

    }

    if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

      uVar25 = uVar24 + uVar25;

      uVar19 = uVar20 + (uVar25 < uVar24) + (uVar19 & 0xffff);

      if ((int)uVar19 < -0x8000) {

        uVar19 = 0xffff8000;

        uVar25 = 0;

      }

      if (0x7fff < (int)uVar19) {

        uVar19 = 0x7fff;

        uVar25 = 0xffffffff;

      }

      uVar19 = uVar19 & 0xffff;

    }

    else {

      uVar25 = uVar24 + uVar25;

      uVar19 = uVar20 + (uVar25 < uVar24) + uVar19;

    }

    *(unsigned int *)(0x06094A30 + 0xc) = (uVar11 << 0x10 | uVar26 >> 0x10) + puVar16[9];

    uVar20 = puVar16[5];

    uVar11 = *(unsigned int *)(puVar5 + 8);

    uVar3 = uVar20 ^ uVar11;

    if ((int)uVar20 < 0) {

      uVar20 = -uVar20;

    }

    if ((int)uVar11 < 0) {

      uVar11 = -uVar11;

    }

    uVar23 = (uVar11 & 0xffff) * (uVar20 & 0xffff);

    iVar10 = (uVar11 >> 0x10) * (uVar20 & 0xffff);

    iVar9 = 0;

    uVar4 = iVar10 + (uVar11 & 0xffff) * (uVar20 >> 0x10);

    if (iVar10 != 0) {

      iVar9 = 0x10000;

    }

    uVar26 = uVar23 + uVar4 * 0x10000;

    uVar11 = iVar9 + (unsigned int)(uVar26 < uVar23) + (uVar4 >> 0x10) + (uVar11 >> 0x10) * (uVar20 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

      uVar11 = ~uVar11;

      if (uVar26 == 0) {

        uVar11 = uVar11 + 1;

      }

      else {

        uVar26 = ~uVar26 + 1;

      }

    }

    if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

      uVar26 = uVar25 + uVar26;

      uVar19 = uVar11 + (uVar26 < uVar25) + (uVar19 & 0xffff);

      if ((int)uVar19 < -0x8000) {

        uVar19 = 0xffff8000;

        uVar26 = 0;

      }

      if (0x7fff < (int)uVar19) {

        uVar19 = 0x7fff;

        uVar26 = 0xffffffff;

      }

      uVar19 = uVar19 & 0xffff;

    }

    else {

      uVar26 = uVar25 + uVar26;

      uVar19 = uVar11 + (uVar26 < uVar25) + uVar19;

    }

    uVar20 = puVar16[6];

    uVar11 = *(unsigned int *)puVar5;

    uVar3 = uVar20 ^ uVar11;

    if ((int)uVar20 < 0) {

      uVar20 = -uVar20;

    }

    if ((int)uVar11 < 0) {

      uVar11 = -uVar11;

    }

    uVar23 = (uVar11 & 0xffff) * (uVar20 & 0xffff);

    iVar10 = (uVar11 >> 0x10) * (uVar20 & 0xffff);

    iVar9 = 0;

    uVar4 = iVar10 + (uVar11 & 0xffff) * (uVar20 >> 0x10);

    if (iVar10 != 0) {

      iVar9 = 0x10000;

    }

    uVar24 = uVar23 + uVar4 * 0x10000;

    uVar11 = iVar9 + (unsigned int)(uVar24 < uVar23) + (uVar4 >> 0x10) + (uVar11 >> 0x10) * (uVar20 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

      uVar11 = ~uVar11;

      if (uVar24 == 0) {

        uVar11 = uVar11 + 1;

      }

      else {

        uVar24 = ~uVar24 + 1;

      }

    }

    if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

      if ((int)uVar11 < -0x8000) {

        uVar11 = 0xffff8000;

        uVar24 = 0;

      }

      if (0x7fff < (int)uVar11) {

        uVar11 = 0x7fff;

        uVar24 = 0xffffffff;

      }

      uVar11 = uVar11 & 0xffff;

    }

    uVar3 = puVar16[7];

    uVar20 = *(unsigned int *)(puVar5 + 4);

    uVar4 = uVar3 ^ uVar20;

    if ((int)uVar3 < 0) {

      uVar3 = -uVar3;

    }

    if ((int)uVar20 < 0) {

      uVar20 = -uVar20;

    }

    uVar22 = (uVar20 & 0xffff) * (uVar3 & 0xffff);

    iVar10 = (uVar20 >> 0x10) * (uVar3 & 0xffff);

    iVar9 = 0;

    uVar23 = iVar10 + (uVar20 & 0xffff) * (uVar3 >> 0x10);

    if (iVar10 != 0) {

      iVar9 = 0x10000;

    }

    uVar25 = uVar22 + uVar23 * 0x10000;

    uVar20 = iVar9 + (unsigned int)(uVar25 < uVar22) + (uVar23 >> 0x10) + (uVar20 >> 0x10) * (uVar3 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar4 < 0) < 0) {

      uVar20 = ~uVar20;

      if (uVar25 == 0) {

        uVar20 = uVar20 + 1;

      }

      else {

        uVar25 = ~uVar25 + 1;

      }

    }

    if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

      uVar25 = uVar24 + uVar25;

      uVar11 = uVar20 + (uVar25 < uVar24) + (uVar11 & 0xffff);

      if ((int)uVar11 < -0x8000) {

        uVar11 = 0xffff8000;

        uVar25 = 0;

      }

      if (0x7fff < (int)uVar11) {

        uVar11 = 0x7fff;

        uVar25 = 0xffffffff;

      }

      uVar11 = uVar11 & 0xffff;

    }

    else {

      uVar25 = uVar24 + uVar25;

      uVar11 = uVar20 + (uVar25 < uVar24) + uVar11;

    }

    *(unsigned int *)(puVar6 + 0x10) = (uVar19 << 0x10 | uVar26 >> 0x10) + puVar16[10];

    uVar20 = puVar16[8];

    uVar19 = *(unsigned int *)(puVar5 + 8);

    uVar3 = uVar20 ^ uVar19;

    if ((int)uVar20 < 0) {

      uVar20 = -uVar20;

    }

    if ((int)uVar19 < 0) {

      uVar19 = -uVar19;

    }

    uVar23 = (uVar19 & 0xffff) * (uVar20 & 0xffff);

    iVar10 = (uVar19 >> 0x10) * (uVar20 & 0xffff);

    iVar9 = 0;

    uVar4 = iVar10 + (uVar19 & 0xffff) * (uVar20 >> 0x10);

    if (iVar10 != 0) {

      iVar9 = 0x10000;

    }

    uVar26 = uVar23 + uVar4 * 0x10000;

    uVar19 = iVar9 + (unsigned int)(uVar26 < uVar23) + (uVar4 >> 0x10) + (uVar19 >> 0x10) * (uVar20 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

      uVar19 = ~uVar19;

      if (uVar26 == 0) {

        uVar19 = uVar19 + 1;

      }

      else {

        uVar26 = ~uVar26 + 1;

      }

    }

    if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

      uVar26 = uVar25 + uVar26;

      uVar11 = uVar19 + (uVar26 < uVar25) + (uVar11 & 0xffff);

      if ((int)uVar11 < -0x8000) {

        uVar11 = 0xffff8000;

        uVar26 = 0;

      }

      if (0x7fff < (int)uVar11) {

        uVar11 = 0x7fff;

        uVar26 = 0xffffffff;

      }

      uVar11 = uVar11 & 0xffff;

    }

    else {

      uVar26 = uVar25 + uVar26;

      uVar11 = uVar19 + (uVar26 < uVar25) + uVar11;

    }

    *(unsigned int *)(puVar6 + 0x14) = (uVar11 << 0x10 | uVar26 >> 0x10) + puVar16[0xb];

    *(unsigned short *)((int)unaff_r11 + 2) = (unsigned short)(*(int *)(puVar6 + 0x14) <= unaff_r10);

    puVar5 = 0x06094AB0;

    psVar15 = (short *)((unsigned int)*(unsigned short *)(puVar17 + -1) * 6 + unaff_r14);

    sVar1 = psVar15[1];

    sVar2 = psVar15[2];

    *(int *)0x06094AB0 = (int)*psVar15 << 0xb;

    *(int *)(puVar5 + 4) = (int)sVar1 << 0xb;

    *(int *)0x06094AE0 = (int)sVar1 << 0xb;

    *(int *)(puVar5 + 8) = (int)sVar2 << 0xb;

    puVar6 = 0x06094A30;

    puVar17 = *(unsigned int **)0x06089EDC;

    uVar19 = *puVar17;

    uVar11 = *(unsigned int *)puVar5;

    uVar20 = uVar19 ^ uVar11;

    if ((int)uVar19 < 0) {

      uVar19 = -uVar19;

    }

    if ((int)uVar11 < 0) {

      uVar11 = -uVar11;

    }

    uVar4 = (uVar11 & 0xffff) * (uVar19 & 0xffff);

    iVar10 = (uVar11 >> 0x10) * (uVar19 & 0xffff);

    iVar9 = 0;

    uVar3 = iVar10 + (uVar11 & 0xffff) * (uVar19 >> 0x10);

    if (iVar10 != 0) {

      iVar9 = 0x10000;

    }

    uVar23 = uVar4 + uVar3 * 0x10000;

    uVar11 = iVar9 + (unsigned int)(uVar23 < uVar4) + (uVar3 >> 0x10) + (uVar11 >> 0x10) * (uVar19 >> 0x10);

    if ((int)-(unsigned int)((int)uVar20 < 0) < 0) {

      uVar11 = ~uVar11;

      if (uVar23 == 0) {

        uVar11 = uVar11 + 1;

      }

      else {

        uVar23 = ~uVar23 + 1;

      }

    }

    if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

      if ((int)uVar11 < -0x8000) {

        uVar11 = 0xffff8000;

        uVar23 = 0;

      }

      if (0x7fff < (int)uVar11) {

        uVar11 = 0x7fff;

        uVar23 = 0xffffffff;

      }

      uVar11 = uVar11 & 0xffff;

    }

    uVar20 = puVar17[1];

    uVar19 = *(unsigned int *)(puVar5 + 4);

    uVar3 = uVar20 ^ uVar19;

    if ((int)uVar20 < 0) {

      uVar20 = -uVar20;

    }

    if ((int)uVar19 < 0) {

      uVar19 = -uVar19;

    }

    uVar26 = (uVar19 & 0xffff) * (uVar20 & 0xffff);

    iVar10 = (uVar19 >> 0x10) * (uVar20 & 0xffff);

    iVar9 = 0;

    uVar4 = iVar10 + (uVar19 & 0xffff) * (uVar20 >> 0x10);

    if (iVar10 != 0) {

      iVar9 = 0x10000;

    }

    uVar24 = uVar26 + uVar4 * 0x10000;

    uVar19 = iVar9 + (unsigned int)(uVar24 < uVar26) + (uVar4 >> 0x10) + (uVar19 >> 0x10) * (uVar20 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

      uVar19 = ~uVar19;

      if (uVar24 == 0) {

        uVar19 = uVar19 + 1;

      }

      else {

        uVar24 = ~uVar24 + 1;

      }

    }

    if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

      uVar24 = uVar23 + uVar24;

      uVar11 = uVar19 + (uVar24 < uVar23) + (uVar11 & 0xffff);

      if ((int)uVar11 < -0x8000) {

        uVar11 = 0xffff8000;

        uVar24 = 0;

      }

      if (0x7fff < (int)uVar11) {

        uVar11 = 0x7fff;

        uVar24 = 0xffffffff;

      }

      uVar11 = uVar11 & 0xffff;

    }

    else {

      uVar24 = uVar23 + uVar24;

      uVar11 = uVar19 + (uVar24 < uVar23) + uVar11;

    }

    uVar20 = puVar17[2];

    uVar19 = *(unsigned int *)(puVar5 + 8);

    uVar3 = uVar20 ^ uVar19;

    if ((int)uVar20 < 0) {

      uVar20 = -uVar20;

    }

    if ((int)uVar19 < 0) {

      uVar19 = -uVar19;

    }

    uVar23 = (uVar19 & 0xffff) * (uVar20 & 0xffff);

    iVar10 = (uVar19 >> 0x10) * (uVar20 & 0xffff);

    iVar9 = 0;

    uVar4 = iVar10 + (uVar19 & 0xffff) * (uVar20 >> 0x10);

    if (iVar10 != 0) {

      iVar9 = 0x10000;

    }

    uVar26 = uVar23 + uVar4 * 0x10000;

    uVar19 = iVar9 + (unsigned int)(uVar26 < uVar23) + (uVar4 >> 0x10) + (uVar19 >> 0x10) * (uVar20 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

      uVar19 = ~uVar19;

      if (uVar26 == 0) {

        uVar19 = uVar19 + 1;

      }

      else {

        uVar26 = ~uVar26 + 1;

      }

    }

    if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

      uVar26 = uVar24 + uVar26;

      uVar11 = uVar19 + (uVar26 < uVar24) + (uVar11 & 0xffff);

      if ((int)uVar11 < -0x8000) {

        uVar11 = 0xffff8000;

        uVar26 = 0;

      }

      if (0x7fff < (int)uVar11) {

        uVar11 = 0x7fff;

        uVar26 = 0xffffffff;

      }

      uVar11 = uVar11 & 0xffff;

    }

    else {

      uVar26 = uVar24 + uVar26;

      uVar11 = uVar19 + (uVar26 < uVar24) + uVar11;

    }

    uVar20 = puVar17[3];

    uVar19 = *(unsigned int *)puVar5;

    uVar3 = uVar20 ^ uVar19;

    if ((int)uVar20 < 0) {

      uVar20 = -uVar20;

    }

    if ((int)uVar19 < 0) {

      uVar19 = -uVar19;

    }

    uVar23 = (uVar19 & 0xffff) * (uVar20 & 0xffff);

    iVar10 = (uVar19 >> 0x10) * (uVar20 & 0xffff);

    iVar9 = 0;

    uVar4 = iVar10 + (uVar19 & 0xffff) * (uVar20 >> 0x10);

    if (iVar10 != 0) {

      iVar9 = 0x10000;

    }

    uVar24 = uVar23 + uVar4 * 0x10000;

    uVar19 = iVar9 + (unsigned int)(uVar24 < uVar23) + (uVar4 >> 0x10) + (uVar19 >> 0x10) * (uVar20 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

      uVar19 = ~uVar19;

      if (uVar24 == 0) {

        uVar19 = uVar19 + 1;

      }

      else {

        uVar24 = ~uVar24 + 1;

      }

    }

    if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

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

    uVar3 = puVar17[4];

    uVar20 = *(unsigned int *)(puVar5 + 4);

    uVar4 = uVar3 ^ uVar20;

    if ((int)uVar3 < 0) {

      uVar3 = -uVar3;

    }

    if ((int)uVar20 < 0) {

      uVar20 = -uVar20;

    }

    uVar22 = (uVar20 & 0xffff) * (uVar3 & 0xffff);

    iVar10 = (uVar20 >> 0x10) * (uVar3 & 0xffff);

    iVar9 = 0;

    uVar23 = iVar10 + (uVar20 & 0xffff) * (uVar3 >> 0x10);

    if (iVar10 != 0) {

      iVar9 = 0x10000;

    }

    uVar25 = uVar22 + uVar23 * 0x10000;

    uVar20 = iVar9 + (unsigned int)(uVar25 < uVar22) + (uVar23 >> 0x10) + (uVar20 >> 0x10) * (uVar3 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar4 < 0) < 0) {

      uVar20 = ~uVar20;

      if (uVar25 == 0) {

        uVar20 = uVar20 + 1;

      }

      else {

        uVar25 = ~uVar25 + 1;

      }

    }

    if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

      uVar25 = uVar24 + uVar25;

      uVar19 = uVar20 + (uVar25 < uVar24) + (uVar19 & 0xffff);

      if ((int)uVar19 < -0x8000) {

        uVar19 = 0xffff8000;

        uVar25 = 0;

      }

      if (0x7fff < (int)uVar19) {

        uVar19 = 0x7fff;

        uVar25 = 0xffffffff;

      }

      uVar19 = uVar19 & 0xffff;

    }

    else {

      uVar25 = uVar24 + uVar25;

      uVar19 = uVar20 + (uVar25 < uVar24) + uVar19;

    }

    *(unsigned int *)(0x06094A30 + 0x18) = (uVar11 << 0x10 | uVar26 >> 0x10) + puVar17[9];

    uVar20 = puVar17[5];

    uVar11 = *(unsigned int *)(puVar5 + 8);

    uVar3 = uVar20 ^ uVar11;

    if ((int)uVar20 < 0) {

      uVar20 = -uVar20;

    }

    if ((int)uVar11 < 0) {

      uVar11 = -uVar11;

    }

    uVar23 = (uVar11 & 0xffff) * (uVar20 & 0xffff);

    iVar10 = (uVar11 >> 0x10) * (uVar20 & 0xffff);

    iVar9 = 0;

    uVar4 = iVar10 + (uVar11 & 0xffff) * (uVar20 >> 0x10);

    if (iVar10 != 0) {

      iVar9 = 0x10000;

    }

    uVar26 = uVar23 + uVar4 * 0x10000;

    uVar11 = iVar9 + (unsigned int)(uVar26 < uVar23) + (uVar4 >> 0x10) + (uVar11 >> 0x10) * (uVar20 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

      uVar11 = ~uVar11;

      if (uVar26 == 0) {

        uVar11 = uVar11 + 1;

      }

      else {

        uVar26 = ~uVar26 + 1;

      }

    }

    if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

      uVar26 = uVar25 + uVar26;

      uVar19 = uVar11 + (uVar26 < uVar25) + (uVar19 & 0xffff);

      if ((int)uVar19 < -0x8000) {

        uVar19 = 0xffff8000;

        uVar26 = 0;

      }

      if (0x7fff < (int)uVar19) {

        uVar19 = 0x7fff;

        uVar26 = 0xffffffff;

      }

      uVar19 = uVar19 & 0xffff;

    }

    else {

      uVar26 = uVar25 + uVar26;

      uVar19 = uVar11 + (uVar26 < uVar25) + uVar19;

    }

    uVar20 = puVar17[6];

    uVar11 = *(unsigned int *)puVar5;

    uVar3 = uVar20 ^ uVar11;

    if ((int)uVar20 < 0) {

      uVar20 = -uVar20;

    }

    if ((int)uVar11 < 0) {

      uVar11 = -uVar11;

    }

    uVar23 = (uVar11 & 0xffff) * (uVar20 & 0xffff);

    iVar10 = (uVar11 >> 0x10) * (uVar20 & 0xffff);

    iVar9 = 0;

    uVar4 = iVar10 + (uVar11 & 0xffff) * (uVar20 >> 0x10);

    if (iVar10 != 0) {

      iVar9 = 0x10000;

    }

    uVar24 = uVar23 + uVar4 * 0x10000;

    uVar11 = iVar9 + (unsigned int)(uVar24 < uVar23) + (uVar4 >> 0x10) + (uVar11 >> 0x10) * (uVar20 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

      uVar11 = ~uVar11;

      if (uVar24 == 0) {

        uVar11 = uVar11 + 1;

      }

      else {

        uVar24 = ~uVar24 + 1;

      }

    }

    if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

      if ((int)uVar11 < -0x8000) {

        uVar11 = 0xffff8000;

        uVar24 = 0;

      }

      if (0x7fff < (int)uVar11) {

        uVar11 = 0x7fff;

        uVar24 = 0xffffffff;

      }

      uVar11 = uVar11 & 0xffff;

    }

    uVar3 = puVar17[7];

    uVar20 = *(unsigned int *)(puVar5 + 4);

    uVar4 = uVar3 ^ uVar20;

    if ((int)uVar3 < 0) {

      uVar3 = -uVar3;

    }

    if ((int)uVar20 < 0) {

      uVar20 = -uVar20;

    }

    uVar22 = (uVar20 & 0xffff) * (uVar3 & 0xffff);

    iVar10 = (uVar20 >> 0x10) * (uVar3 & 0xffff);

    iVar9 = 0;

    uVar23 = iVar10 + (uVar20 & 0xffff) * (uVar3 >> 0x10);

    if (iVar10 != 0) {

      iVar9 = 0x10000;

    }

    uVar25 = uVar22 + uVar23 * 0x10000;

    uVar20 = iVar9 + (unsigned int)(uVar25 < uVar22) + (uVar23 >> 0x10) + (uVar20 >> 0x10) * (uVar3 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar4 < 0) < 0) {

      uVar20 = ~uVar20;

      if (uVar25 == 0) {

        uVar20 = uVar20 + 1;

      }

      else {

        uVar25 = ~uVar25 + 1;

      }

    }

    if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

      uVar25 = uVar24 + uVar25;

      uVar11 = uVar20 + (uVar25 < uVar24) + (uVar11 & 0xffff);

      if ((int)uVar11 < -0x8000) {

        uVar11 = 0xffff8000;

        uVar25 = 0;

      }

      if (0x7fff < (int)uVar11) {

        uVar11 = 0x7fff;

        uVar25 = 0xffffffff;

      }

      uVar11 = uVar11 & 0xffff;

    }

    else {

      uVar25 = uVar24 + uVar25;

      uVar11 = uVar20 + (uVar25 < uVar24) + uVar11;

    }

    *(unsigned int *)(puVar6 + 0x1c) = (uVar19 << 0x10 | uVar26 >> 0x10) + puVar17[10];

    uVar20 = puVar17[8];

    uVar19 = *(unsigned int *)(puVar5 + 8);

    uVar3 = uVar20 ^ uVar19;

    if ((int)uVar20 < 0) {

      uVar20 = -uVar20;

    }

    if ((int)uVar19 < 0) {

      uVar19 = -uVar19;

    }

    uVar23 = (uVar19 & 0xffff) * (uVar20 & 0xffff);

    iVar10 = (uVar19 >> 0x10) * (uVar20 & 0xffff);

    iVar9 = 0;

    uVar4 = iVar10 + (uVar19 & 0xffff) * (uVar20 >> 0x10);

    if (iVar10 != 0) {

      iVar9 = 0x10000;

    }

    uVar26 = uVar23 + uVar4 * 0x10000;

    uVar19 = iVar9 + (unsigned int)(uVar26 < uVar23) + (uVar4 >> 0x10) + (uVar19 >> 0x10) * (uVar20 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

      uVar19 = ~uVar19;

      if (uVar26 == 0) {

        uVar19 = uVar19 + 1;

      }

      else {

        uVar26 = ~uVar26 + 1;

      }

    }

    if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

      uVar26 = uVar25 + uVar26;

      uVar11 = uVar19 + (uVar26 < uVar25) + (uVar11 & 0xffff);

      if ((int)uVar11 < -0x8000) {

        uVar11 = 0xffff8000;

        uVar26 = 0;

      }

      if (0x7fff < (int)uVar11) {

        uVar11 = 0x7fff;

        uVar26 = 0xffffffff;

      }

      uVar11 = uVar11 & 0xffff;

    }

    else {

      uVar26 = uVar25 + uVar26;

      uVar11 = uVar19 + (uVar26 < uVar25) + uVar11;

    }

    *(unsigned int *)(puVar6 + 0x20) = (uVar11 << 0x10 | uVar26 >> 0x10) + puVar17[0xb];

    in_sr = uVar18 & 0xfffffffe | (unsigned int)(*(int *)(puVar6 + 0x20) <= unaff_r10);

    in_r0 = (unsigned short)((unsigned char)in_sr & 1);

  } while( true );

}
