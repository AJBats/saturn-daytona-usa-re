extern int DAT_0602c0f0;

extern int DAT_0602c0f2;

extern int DAT_0602c120;

extern int DAT_0602c12e;

extern int DAT_0602c176;

extern int DAT_0602c178;

extern int DAT_0602c17a;

extern int DAT_0602c17c;

extern int DAT_0602c18a;

extern int DAT_0602c198;

extern int DAT_0602c1e0;

extern int DAT_0602c1e2;

extern int DAT_0602c1e4;

extern int DAT_0602c1e6;

extern int DAT_0602c1f4;

extern int DAT_0602c202;

extern int DAT_0602c24a;

extern int DAT_0602c24c;

extern int DAT_0602c24e;

extern int DAT_0602c250;

extern int DAT_0602c25e;

extern int DAT_0602c26c;

extern int DAT_0602c29c;

extern int PTR_DAT_0602c0f4;

extern int PTR_DAT_0602c0f4;

unsigned int FUN_0602bdcc(param_1, param_2, param_3, param_4)
    int param_1;
    int param_2;
    char param_3;
    int param_4;
{

  short sVar1;

  short sVar2;

  unsigned int uVar3;

  unsigned int uVar4;

  char *puVar5;

  char *puVar6;

  char *puVar7;

  char *puVar8;

  unsigned int uVar9;

  int iVar10;

  int iVar11;

  int *puVar12;

  int uVar13;

  int iVar14;

  short *psVar15;

  unsigned int *puVar16;

  unsigned int *puVar17;

  unsigned int *puVar18;

  int iVar19;

  unsigned int in_sr;

  unsigned int uVar20;

  unsigned int uVar21;

  unsigned int uVar22;

  unsigned int uVar23;

  unsigned int uVar24;

  unsigned int uVar25;

  unsigned int uVar26;

  unsigned int uVar27;

  unsigned int uVar28;

  iVar19 = *(int *)0x06063F08;

  puVar17 = (unsigned int *)(param_1 + param_4 * 0x18);

  do {

    puVar5 = 0x06094F74;

    puVar18 = puVar17 + -6;

    psVar15 = (short *)((unsigned int)*(unsigned short *)(puVar17 + -2) * 6 + param_2);

    sVar1 = psVar15[1];

    sVar2 = psVar15[2];

    uVar20 = in_sr & 0xfffffffe;

    *(int *)0x06094F74 = (int)*psVar15 << 0xb;

    *(int *)(puVar5 + 4) = (int)sVar1 << 0xb;

    *(int *)(puVar5 + 8) = (int)sVar2 << 0xb;

    puVar6 = 0x06094EF4;

    puVar16 = *(unsigned int **)0x0608A52C;

    uVar22 = *puVar16;

    uVar9 = *(unsigned int *)puVar5;

    uVar4 = uVar22 ^ uVar9;

    if ((int)uVar22 < 0) {

      uVar22 = -uVar22;

    }

    if ((int)uVar9 < 0) {

      uVar9 = -uVar9;

    }

    uVar3 = (uVar9 & 0xffff) * (uVar22 & 0xffff);

    iVar11 = (uVar9 >> 0x10) * (uVar22 & 0xffff);

    iVar10 = 0;

    uVar21 = iVar11 + (uVar9 & 0xffff) * (uVar22 >> 0x10);

    if (iVar11 != 0) {

      iVar10 = 0x10000;

    }

    uVar24 = uVar3 + uVar21 * 0x10000;

    uVar9 = iVar10 + (unsigned int)(uVar24 < uVar3) + (uVar21 >> 0x10) + (uVar9 >> 0x10) * (uVar22 >> 0x10);

    if ((int)-(unsigned int)((int)uVar4 < 0) < 0) {

      uVar9 = ~uVar9;

      if (uVar24 == 0) {

        uVar9 = uVar9 + 1;

      }

      else {

        uVar24 = ~uVar24 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      if ((int)uVar9 < -0x8000) {

        uVar9 = 0xffff8000;

        uVar24 = 0;

      }

      if (0x7fff < (int)uVar9) {

        uVar9 = 0x7fff;

        uVar24 = 0xffffffff;

      }

      uVar9 = uVar9 & 0xffff;

    }

    uVar4 = puVar16[1];

    uVar22 = *(unsigned int *)(puVar5 + 4);

    uVar21 = uVar4 ^ uVar22;

    if ((int)uVar4 < 0) {

      uVar4 = -uVar4;

    }

    if ((int)uVar22 < 0) {

      uVar22 = -uVar22;

    }

    uVar25 = (uVar22 & 0xffff) * (uVar4 & 0xffff);

    iVar11 = (uVar22 >> 0x10) * (uVar4 & 0xffff);

    iVar10 = 0;

    uVar3 = iVar11 + (uVar22 & 0xffff) * (uVar4 >> 0x10);

    if (iVar11 != 0) {

      iVar10 = 0x10000;

    }

    uVar28 = uVar25 + uVar3 * 0x10000;

    uVar22 = iVar10 + (unsigned int)(uVar28 < uVar25) + (uVar3 >> 0x10) + (uVar22 >> 0x10) * (uVar4 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar21 < 0) < 0) {

      uVar22 = ~uVar22;

      if (uVar28 == 0) {

        uVar22 = uVar22 + 1;

      }

      else {

        uVar28 = ~uVar28 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      uVar28 = uVar24 + uVar28;

      uVar9 = uVar22 + (uVar28 < uVar24) + (uVar9 & 0xffff);

      if ((int)uVar9 < -0x8000) {

        uVar9 = 0xffff8000;

        uVar28 = 0;

      }

      if (0x7fff < (int)uVar9) {

        uVar9 = 0x7fff;

        uVar28 = 0xffffffff;

      }

      uVar9 = uVar9 & 0xffff;

    }

    else {

      uVar28 = uVar24 + uVar28;

      uVar9 = uVar22 + (uVar28 < uVar24) + uVar9;

    }

    uVar4 = puVar16[2];

    uVar22 = *(unsigned int *)(puVar5 + 8);

    uVar21 = uVar4 ^ uVar22;

    if ((int)uVar4 < 0) {

      uVar4 = -uVar4;

    }

    if ((int)uVar22 < 0) {

      uVar22 = -uVar22;

    }

    uVar24 = (uVar22 & 0xffff) * (uVar4 & 0xffff);

    iVar11 = (uVar22 >> 0x10) * (uVar4 & 0xffff);

    iVar10 = 0;

    uVar3 = iVar11 + (uVar22 & 0xffff) * (uVar4 >> 0x10);

    if (iVar11 != 0) {

      iVar10 = 0x10000;

    }

    uVar25 = uVar24 + uVar3 * 0x10000;

    uVar22 = iVar10 + (unsigned int)(uVar25 < uVar24) + (uVar3 >> 0x10) + (uVar22 >> 0x10) * (uVar4 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar21 < 0) < 0) {

      uVar22 = ~uVar22;

      if (uVar25 == 0) {

        uVar22 = uVar22 + 1;

      }

      else {

        uVar25 = ~uVar25 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      uVar25 = uVar28 + uVar25;

      uVar9 = uVar22 + (uVar25 < uVar28) + (uVar9 & 0xffff);

      if ((int)uVar9 < -0x8000) {

        uVar9 = 0xffff8000;

        uVar25 = 0;

      }

      if (0x7fff < (int)uVar9) {

        uVar9 = 0x7fff;

        uVar25 = 0xffffffff;

      }

      uVar9 = uVar9 & 0xffff;

    }

    else {

      uVar25 = uVar28 + uVar25;

      uVar9 = uVar22 + (uVar25 < uVar28) + uVar9;

    }

    uVar4 = puVar16[3];

    uVar22 = *(unsigned int *)puVar5;

    uVar21 = uVar4 ^ uVar22;

    if ((int)uVar4 < 0) {

      uVar4 = -uVar4;

    }

    if ((int)uVar22 < 0) {

      uVar22 = -uVar22;

    }

    uVar24 = (uVar22 & 0xffff) * (uVar4 & 0xffff);

    iVar11 = (uVar22 >> 0x10) * (uVar4 & 0xffff);

    iVar10 = 0;

    uVar3 = iVar11 + (uVar22 & 0xffff) * (uVar4 >> 0x10);

    if (iVar11 != 0) {

      iVar10 = 0x10000;

    }

    uVar28 = uVar24 + uVar3 * 0x10000;

    uVar22 = iVar10 + (unsigned int)(uVar28 < uVar24) + (uVar3 >> 0x10) + (uVar22 >> 0x10) * (uVar4 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar21 < 0) < 0) {

      uVar22 = ~uVar22;

      if (uVar28 == 0) {

        uVar22 = uVar22 + 1;

      }

      else {

        uVar28 = ~uVar28 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      if ((int)uVar22 < -0x8000) {

        uVar22 = 0xffff8000;

        uVar28 = 0;

      }

      if (0x7fff < (int)uVar22) {

        uVar22 = 0x7fff;

        uVar28 = 0xffffffff;

      }

      uVar22 = uVar22 & 0xffff;

    }

    uVar21 = puVar16[4];

    uVar4 = *(unsigned int *)(puVar5 + 4);

    uVar3 = uVar21 ^ uVar4;

    if ((int)uVar21 < 0) {

      uVar21 = -uVar21;

    }

    if ((int)uVar4 < 0) {

      uVar4 = -uVar4;

    }

    uVar26 = (uVar4 & 0xffff) * (uVar21 & 0xffff);

    iVar11 = (uVar4 >> 0x10) * (uVar21 & 0xffff);

    iVar10 = 0;

    uVar24 = iVar11 + (uVar4 & 0xffff) * (uVar21 >> 0x10);

    if (iVar11 != 0) {

      iVar10 = 0x10000;

    }

    uVar23 = uVar26 + uVar24 * 0x10000;

    uVar4 = iVar10 + (unsigned int)(uVar23 < uVar26) + (uVar24 >> 0x10) + (uVar4 >> 0x10) * (uVar21 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

      uVar4 = ~uVar4;

      if (uVar23 == 0) {

        uVar4 = uVar4 + 1;

      }

      else {

        uVar23 = ~uVar23 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      uVar23 = uVar28 + uVar23;

      uVar22 = uVar4 + (uVar23 < uVar28) + (uVar22 & 0xffff);

      if ((int)uVar22 < -0x8000) {

        uVar22 = 0xffff8000;

        uVar23 = 0;

      }

      if (0x7fff < (int)uVar22) {

        uVar22 = 0x7fff;

        uVar23 = 0xffffffff;

      }

      uVar22 = uVar22 & 0xffff;

    }

    else {

      uVar23 = uVar28 + uVar23;

      uVar22 = uVar4 + (uVar23 < uVar28) + uVar22;

    }

    *(unsigned int *)0x06094EF4 = (uVar9 << 0x10 | uVar25 >> 0x10) + puVar16[9];

    uVar4 = puVar16[5];

    uVar9 = *(unsigned int *)(puVar5 + 8);

    uVar21 = uVar4 ^ uVar9;

    if ((int)uVar4 < 0) {

      uVar4 = -uVar4;

    }

    if ((int)uVar9 < 0) {

      uVar9 = -uVar9;

    }

    uVar24 = (uVar9 & 0xffff) * (uVar4 & 0xffff);

    iVar11 = (uVar9 >> 0x10) * (uVar4 & 0xffff);

    iVar10 = 0;

    uVar3 = iVar11 + (uVar9 & 0xffff) * (uVar4 >> 0x10);

    if (iVar11 != 0) {

      iVar10 = 0x10000;

    }

    uVar25 = uVar24 + uVar3 * 0x10000;

    uVar9 = iVar10 + (unsigned int)(uVar25 < uVar24) + (uVar3 >> 0x10) + (uVar9 >> 0x10) * (uVar4 >> 0x10);

    if ((int)-(unsigned int)((int)uVar21 < 0) < 0) {

      uVar9 = ~uVar9;

      if (uVar25 == 0) {

        uVar9 = uVar9 + 1;

      }

      else {

        uVar25 = ~uVar25 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      uVar25 = uVar23 + uVar25;

      uVar22 = uVar9 + (uVar25 < uVar23) + (uVar22 & 0xffff);

      if ((int)uVar22 < -0x8000) {

        uVar22 = 0xffff8000;

        uVar25 = 0;

      }

      if (0x7fff < (int)uVar22) {

        uVar22 = 0x7fff;

        uVar25 = 0xffffffff;

      }

      uVar22 = uVar22 & 0xffff;

    }

    else {

      uVar25 = uVar23 + uVar25;

      uVar22 = uVar9 + (uVar25 < uVar23) + uVar22;

    }

    uVar4 = puVar16[6];

    uVar9 = *(unsigned int *)puVar5;

    uVar21 = uVar4 ^ uVar9;

    if ((int)uVar4 < 0) {

      uVar4 = -uVar4;

    }

    if ((int)uVar9 < 0) {

      uVar9 = -uVar9;

    }

    uVar24 = (uVar9 & 0xffff) * (uVar4 & 0xffff);

    iVar11 = (uVar9 >> 0x10) * (uVar4 & 0xffff);

    iVar10 = 0;

    uVar3 = iVar11 + (uVar9 & 0xffff) * (uVar4 >> 0x10);

    if (iVar11 != 0) {

      iVar10 = 0x10000;

    }

    uVar28 = uVar24 + uVar3 * 0x10000;

    uVar9 = iVar10 + (unsigned int)(uVar28 < uVar24) + (uVar3 >> 0x10) + (uVar9 >> 0x10) * (uVar4 >> 0x10);

    if ((int)-(unsigned int)((int)uVar21 < 0) < 0) {

      uVar9 = ~uVar9;

      if (uVar28 == 0) {

        uVar9 = uVar9 + 1;

      }

      else {

        uVar28 = ~uVar28 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      if ((int)uVar9 < -0x8000) {

        uVar9 = 0xffff8000;

        uVar28 = 0;

      }

      if (0x7fff < (int)uVar9) {

        uVar9 = 0x7fff;

        uVar28 = 0xffffffff;

      }

      uVar9 = uVar9 & 0xffff;

    }

    uVar21 = puVar16[7];

    uVar4 = *(unsigned int *)(puVar5 + 4);

    uVar3 = uVar21 ^ uVar4;

    if ((int)uVar21 < 0) {

      uVar21 = -uVar21;

    }

    if ((int)uVar4 < 0) {

      uVar4 = -uVar4;

    }

    uVar26 = (uVar4 & 0xffff) * (uVar21 & 0xffff);

    iVar11 = (uVar4 >> 0x10) * (uVar21 & 0xffff);

    iVar10 = 0;

    uVar24 = iVar11 + (uVar4 & 0xffff) * (uVar21 >> 0x10);

    if (iVar11 != 0) {

      iVar10 = 0x10000;

    }

    uVar23 = uVar26 + uVar24 * 0x10000;

    uVar4 = iVar10 + (unsigned int)(uVar23 < uVar26) + (uVar24 >> 0x10) + (uVar4 >> 0x10) * (uVar21 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

      uVar4 = ~uVar4;

      if (uVar23 == 0) {

        uVar4 = uVar4 + 1;

      }

      else {

        uVar23 = ~uVar23 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      uVar23 = uVar28 + uVar23;

      uVar9 = uVar4 + (uVar23 < uVar28) + (uVar9 & 0xffff);

      if ((int)uVar9 < -0x8000) {

        uVar9 = 0xffff8000;

        uVar23 = 0;

      }

      if (0x7fff < (int)uVar9) {

        uVar9 = 0x7fff;

        uVar23 = 0xffffffff;

      }

      uVar9 = uVar9 & 0xffff;

    }

    else {

      uVar23 = uVar28 + uVar23;

      uVar9 = uVar4 + (uVar23 < uVar28) + uVar9;

    }

    *(unsigned int *)(puVar6 + 4) = (uVar22 << 0x10 | uVar25 >> 0x10) + puVar16[10];

    uVar4 = puVar16[8];

    uVar22 = *(unsigned int *)(puVar5 + 8);

    uVar21 = uVar4 ^ uVar22;

    if ((int)uVar4 < 0) {

      uVar4 = -uVar4;

    }

    if ((int)uVar22 < 0) {

      uVar22 = -uVar22;

    }

    uVar24 = (uVar22 & 0xffff) * (uVar4 & 0xffff);

    iVar11 = (uVar22 >> 0x10) * (uVar4 & 0xffff);

    iVar10 = 0;

    uVar3 = iVar11 + (uVar22 & 0xffff) * (uVar4 >> 0x10);

    if (iVar11 != 0) {

      iVar10 = 0x10000;

    }

    uVar25 = uVar24 + uVar3 * 0x10000;

    uVar22 = iVar10 + (unsigned int)(uVar25 < uVar24) + (uVar3 >> 0x10) + (uVar22 >> 0x10) * (uVar4 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar21 < 0) < 0) {

      uVar22 = ~uVar22;

      if (uVar25 == 0) {

        uVar22 = uVar22 + 1;

      }

      else {

        uVar25 = ~uVar25 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      uVar25 = uVar23 + uVar25;

      uVar9 = uVar22 + (uVar25 < uVar23) + (uVar9 & 0xffff);

      if ((int)uVar9 < -0x8000) {

        uVar9 = 0xffff8000;

        uVar25 = 0;

      }

      if (0x7fff < (int)uVar9) {

        uVar9 = 0x7fff;

        uVar25 = 0xffffffff;

      }

      uVar9 = uVar9 & 0xffff;

    }

    else {

      uVar25 = uVar23 + uVar25;

      uVar9 = uVar22 + (uVar25 < uVar23) + uVar9;

    }

    *(unsigned int *)(puVar6 + 8) = (uVar9 << 0x10 | uVar25 >> 0x10) + puVar16[0xb];

    puVar5 = 0x06094EEC;

    *(unsigned short *)0x06094EEC = (unsigned short)(*(int *)(puVar6 + 8) <= iVar19);

    puVar6 = 0x06094F24;

    if ((puVar17[-3] & 0x80000) == 0) {

      puVar16 = *(unsigned int **)0x0608A52C;

      uVar22 = *puVar16;

      uVar9 = *puVar18;

      uVar4 = uVar22 ^ uVar9;

      if ((int)uVar22 < 0) {

        uVar22 = -uVar22;

      }

      if ((int)uVar9 < 0) {

        uVar9 = -uVar9;

      }

      uVar3 = (uVar9 & 0xffff) * (uVar22 & 0xffff);

      iVar11 = (uVar9 >> 0x10) * (uVar22 & 0xffff);

      iVar10 = 0;

      uVar21 = iVar11 + (uVar9 & 0xffff) * (uVar22 >> 0x10);

      if (iVar11 != 0) {

        iVar10 = 0x10000;

      }

      uVar24 = uVar3 + uVar21 * 0x10000;

      uVar9 = iVar10 + (unsigned int)(uVar24 < uVar3) + (uVar21 >> 0x10) +

              (uVar9 >> 0x10) * (uVar22 >> 0x10);

      if ((int)-(unsigned int)((int)uVar4 < 0) < 0) {

        uVar9 = ~uVar9;

        if (uVar24 == 0) {

          uVar9 = uVar9 + 1;

        }

        else {

          uVar24 = ~uVar24 + 1;

        }

      }

      if (((unsigned char)(in_sr >> 1) & 1) == 1) {

        if ((int)uVar9 < -0x8000) {

          uVar9 = 0xffff8000;

          uVar24 = 0;

        }

        if (0x7fff < (int)uVar9) {

          uVar9 = 0x7fff;

          uVar24 = 0xffffffff;

        }

        uVar9 = uVar9 & 0xffff;

      }

      uVar4 = puVar16[1];

      uVar22 = puVar17[-5];

      uVar21 = uVar4 ^ uVar22;

      if ((int)uVar4 < 0) {

        uVar4 = -uVar4;

      }

      if ((int)uVar22 < 0) {

        uVar22 = -uVar22;

      }

      uVar25 = (uVar22 & 0xffff) * (uVar4 & 0xffff);

      iVar11 = (uVar22 >> 0x10) * (uVar4 & 0xffff);

      iVar10 = 0;

      uVar3 = iVar11 + (uVar22 & 0xffff) * (uVar4 >> 0x10);

      if (iVar11 != 0) {

        iVar10 = 0x10000;

      }

      uVar28 = uVar25 + uVar3 * 0x10000;

      uVar22 = iVar10 + (unsigned int)(uVar28 < uVar25) + (uVar3 >> 0x10) +

               (uVar22 >> 0x10) * (uVar4 >> 0x10);

      if ((int)-(unsigned int)((int)uVar21 < 0) < 0) {

        uVar22 = ~uVar22;

        if (uVar28 == 0) {

          uVar22 = uVar22 + 1;

        }

        else {

          uVar28 = ~uVar28 + 1;

        }

      }

      if (((unsigned char)(in_sr >> 1) & 1) == 1) {

        uVar28 = uVar24 + uVar28;

        uVar9 = uVar22 + (uVar28 < uVar24) + (uVar9 & 0xffff);

        if ((int)uVar9 < -0x8000) {

          uVar9 = 0xffff8000;

          uVar28 = 0;

        }

        if (0x7fff < (int)uVar9) {

          uVar9 = 0x7fff;

          uVar28 = 0xffffffff;

        }

        uVar9 = uVar9 & 0xffff;

      }

      else {

        uVar28 = uVar24 + uVar28;

        uVar9 = uVar22 + (uVar28 < uVar24) + uVar9;

      }

      uVar4 = puVar16[2];

      uVar22 = puVar17[-4];

      uVar21 = uVar4 ^ uVar22;

      if ((int)uVar4 < 0) {

        uVar4 = -uVar4;

      }

      if ((int)uVar22 < 0) {

        uVar22 = -uVar22;

      }

      uVar24 = (uVar22 & 0xffff) * (uVar4 & 0xffff);

      iVar11 = (uVar22 >> 0x10) * (uVar4 & 0xffff);

      iVar10 = 0;

      uVar3 = iVar11 + (uVar22 & 0xffff) * (uVar4 >> 0x10);

      if (iVar11 != 0) {

        iVar10 = 0x10000;

      }

      uVar25 = uVar24 + uVar3 * 0x10000;

      uVar22 = iVar10 + (unsigned int)(uVar25 < uVar24) + (uVar3 >> 0x10) +

               (uVar22 >> 0x10) * (uVar4 >> 0x10);

      if ((int)-(unsigned int)((int)uVar21 < 0) < 0) {

        uVar22 = ~uVar22;

        if (uVar25 == 0) {

          uVar22 = uVar22 + 1;

        }

        else {

          uVar25 = ~uVar25 + 1;

        }

      }

      if (((unsigned char)(in_sr >> 1) & 1) == 1) {

        uVar25 = uVar28 + uVar25;

        uVar9 = uVar22 + (uVar25 < uVar28) + (uVar9 & 0xffff);

        if ((int)uVar9 < -0x8000) {

          uVar9 = 0xffff8000;

          uVar25 = 0;

        }

        if (0x7fff < (int)uVar9) {

          uVar9 = 0x7fff;

          uVar25 = 0xffffffff;

        }

        uVar9 = uVar9 & 0xffff;

      }

      else {

        uVar25 = uVar28 + uVar25;

        uVar9 = uVar22 + (uVar25 < uVar28) + uVar9;

      }

      uVar4 = puVar16[3];

      uVar22 = *puVar18;

      uVar21 = uVar4 ^ uVar22;

      if ((int)uVar4 < 0) {

        uVar4 = -uVar4;

      }

      if ((int)uVar22 < 0) {

        uVar22 = -uVar22;

      }

      uVar24 = (uVar22 & 0xffff) * (uVar4 & 0xffff);

      iVar11 = (uVar22 >> 0x10) * (uVar4 & 0xffff);

      iVar10 = 0;

      uVar3 = iVar11 + (uVar22 & 0xffff) * (uVar4 >> 0x10);

      if (iVar11 != 0) {

        iVar10 = 0x10000;

      }

      uVar28 = uVar24 + uVar3 * 0x10000;

      uVar22 = iVar10 + (unsigned int)(uVar28 < uVar24) + (uVar3 >> 0x10) +

               (uVar22 >> 0x10) * (uVar4 >> 0x10);

      if ((int)-(unsigned int)((int)uVar21 < 0) < 0) {

        uVar22 = ~uVar22;

        if (uVar28 == 0) {

          uVar22 = uVar22 + 1;

        }

        else {

          uVar28 = ~uVar28 + 1;

        }

      }

      if (((unsigned char)(in_sr >> 1) & 1) == 1) {

        if ((int)uVar22 < -0x8000) {

          uVar22 = 0xffff8000;

          uVar28 = 0;

        }

        if (0x7fff < (int)uVar22) {

          uVar22 = 0x7fff;

          uVar28 = 0xffffffff;

        }

        uVar22 = uVar22 & 0xffff;

      }

      *(unsigned int *)0x06094F24 = uVar9 << 0x10 | uVar25 >> 0x10;

      uVar4 = puVar16[4];

      uVar9 = puVar17[-5];

      uVar21 = uVar4 ^ uVar9;

      if ((int)uVar4 < 0) {

        uVar4 = -uVar4;

      }

      if ((int)uVar9 < 0) {

        uVar9 = -uVar9;

      }

      uVar24 = (uVar9 & 0xffff) * (uVar4 & 0xffff);

      iVar11 = (uVar9 >> 0x10) * (uVar4 & 0xffff);

      iVar10 = 0;

      uVar3 = iVar11 + (uVar9 & 0xffff) * (uVar4 >> 0x10);

      if (iVar11 != 0) {

        iVar10 = 0x10000;

      }

      uVar25 = uVar24 + uVar3 * 0x10000;

      uVar9 = iVar10 + (unsigned int)(uVar25 < uVar24) + (uVar3 >> 0x10) + (uVar9 >> 0x10) * (uVar4 >> 0x10)

      ;

      if ((int)-(unsigned int)((int)uVar21 < 0) < 0) {

        uVar9 = ~uVar9;

        if (uVar25 == 0) {

          uVar9 = uVar9 + 1;

        }

        else {

          uVar25 = ~uVar25 + 1;

        }

      }

      if (((unsigned char)(in_sr >> 1) & 1) == 1) {

        uVar25 = uVar28 + uVar25;

        uVar22 = uVar9 + (uVar25 < uVar28) + (uVar22 & 0xffff);

        if ((int)uVar22 < -0x8000) {

          uVar22 = 0xffff8000;

          uVar25 = 0;

        }

        if (0x7fff < (int)uVar22) {

          uVar22 = 0x7fff;

          uVar25 = 0xffffffff;

        }

        uVar22 = uVar22 & 0xffff;

      }

      else {

        uVar25 = uVar28 + uVar25;

        uVar22 = uVar9 + (uVar25 < uVar28) + uVar22;

      }

      uVar4 = puVar16[5];

      uVar9 = puVar17[-4];

      uVar21 = uVar4 ^ uVar9;

      if ((int)uVar4 < 0) {

        uVar4 = -uVar4;

      }

      if ((int)uVar9 < 0) {

        uVar9 = -uVar9;

      }

      uVar24 = (uVar9 & 0xffff) * (uVar4 & 0xffff);

      iVar11 = (uVar9 >> 0x10) * (uVar4 & 0xffff);

      iVar10 = 0;

      uVar3 = iVar11 + (uVar9 & 0xffff) * (uVar4 >> 0x10);

      if (iVar11 != 0) {

        iVar10 = 0x10000;

      }

      uVar28 = uVar24 + uVar3 * 0x10000;

      uVar9 = iVar10 + (unsigned int)(uVar28 < uVar24) + (uVar3 >> 0x10) + (uVar9 >> 0x10) * (uVar4 >> 0x10)

      ;

      if ((int)-(unsigned int)((int)uVar21 < 0) < 0) {

        uVar9 = ~uVar9;

        if (uVar28 == 0) {

          uVar9 = uVar9 + 1;

        }

        else {

          uVar28 = ~uVar28 + 1;

        }

      }

      if (((unsigned char)(in_sr >> 1) & 1) == 1) {

        uVar28 = uVar25 + uVar28;

        uVar22 = uVar9 + (uVar28 < uVar25) + (uVar22 & 0xffff);

        if ((int)uVar22 < -0x8000) {

          uVar22 = 0xffff8000;

          uVar28 = 0;

        }

        if (0x7fff < (int)uVar22) {

          uVar22 = 0x7fff;

          uVar28 = 0xffffffff;

        }

        uVar22 = uVar22 & 0xffff;

      }

      else {

        uVar28 = uVar25 + uVar28;

        uVar22 = uVar9 + (uVar28 < uVar25) + uVar22;

      }

      uVar4 = puVar16[6];

      uVar9 = *puVar18;

      uVar21 = uVar4 ^ uVar9;

      if ((int)uVar4 < 0) {

        uVar4 = -uVar4;

      }

      if ((int)uVar9 < 0) {

        uVar9 = -uVar9;

      }

      uVar24 = (uVar9 & 0xffff) * (uVar4 & 0xffff);

      iVar11 = (uVar9 >> 0x10) * (uVar4 & 0xffff);

      iVar10 = 0;

      uVar3 = iVar11 + (uVar9 & 0xffff) * (uVar4 >> 0x10);

      if (iVar11 != 0) {

        iVar10 = 0x10000;

      }

      uVar25 = uVar24 + uVar3 * 0x10000;

      uVar9 = iVar10 + (unsigned int)(uVar25 < uVar24) + (uVar3 >> 0x10) + (uVar9 >> 0x10) * (uVar4 >> 0x10)

      ;

      if ((int)-(unsigned int)((int)uVar21 < 0) < 0) {

        uVar9 = ~uVar9;

        if (uVar25 == 0) {

          uVar9 = uVar9 + 1;

        }

        else {

          uVar25 = ~uVar25 + 1;

        }

      }

      if (((unsigned char)(in_sr >> 1) & 1) == 1) {

        if ((int)uVar9 < -0x8000) {

          uVar9 = 0xffff8000;

          uVar25 = 0;

        }

        if (0x7fff < (int)uVar9) {

          uVar9 = 0x7fff;

          uVar25 = 0xffffffff;

        }

        uVar9 = uVar9 & 0xffff;

      }

      *(unsigned int *)(puVar6 + 4) = uVar22 << 0x10 | uVar28 >> 0x10;

      uVar4 = puVar16[7];

      uVar22 = puVar17[-5];

      uVar21 = uVar4 ^ uVar22;

      if ((int)uVar4 < 0) {

        uVar4 = -uVar4;

      }

      if ((int)uVar22 < 0) {

        uVar22 = -uVar22;

      }

      uVar24 = (uVar22 & 0xffff) * (uVar4 & 0xffff);

      iVar11 = (uVar22 >> 0x10) * (uVar4 & 0xffff);

      iVar10 = 0;

      uVar3 = iVar11 + (uVar22 & 0xffff) * (uVar4 >> 0x10);

      if (iVar11 != 0) {

        iVar10 = 0x10000;

      }

      uVar28 = uVar24 + uVar3 * 0x10000;

      uVar22 = iVar10 + (unsigned int)(uVar28 < uVar24) + (uVar3 >> 0x10) +

               (uVar22 >> 0x10) * (uVar4 >> 0x10);

      if ((int)-(unsigned int)((int)uVar21 < 0) < 0) {

        uVar22 = ~uVar22;

        if (uVar28 == 0) {

          uVar22 = uVar22 + 1;

        }

        else {

          uVar28 = ~uVar28 + 1;

        }

      }

      if (((unsigned char)(in_sr >> 1) & 1) == 1) {

        uVar28 = uVar25 + uVar28;

        uVar9 = uVar22 + (uVar28 < uVar25) + (uVar9 & 0xffff);

        if ((int)uVar9 < -0x8000) {

          uVar9 = 0xffff8000;

          uVar28 = 0;

        }

        if (0x7fff < (int)uVar9) {

          uVar9 = 0x7fff;

          uVar28 = 0xffffffff;

        }

        uVar9 = uVar9 & 0xffff;

      }

      else {

        uVar28 = uVar25 + uVar28;

        uVar9 = uVar22 + (uVar28 < uVar25) + uVar9;

      }

      uVar4 = puVar16[8];

      uVar22 = puVar17[-4];

      uVar21 = uVar4 ^ uVar22;

      if ((int)uVar4 < 0) {

        uVar4 = -uVar4;

      }

      if ((int)uVar22 < 0) {

        uVar22 = -uVar22;

      }

      uVar24 = (uVar22 & 0xffff) * (uVar4 & 0xffff);

      iVar11 = (uVar22 >> 0x10) * (uVar4 & 0xffff);

      iVar10 = 0;

      uVar3 = iVar11 + (uVar22 & 0xffff) * (uVar4 >> 0x10);

      if (iVar11 != 0) {

        iVar10 = 0x10000;

      }

      uVar25 = uVar24 + uVar3 * 0x10000;

      uVar22 = iVar10 + (unsigned int)(uVar25 < uVar24) + (uVar3 >> 0x10) +

               (uVar22 >> 0x10) * (uVar4 >> 0x10);

      if ((int)-(unsigned int)((int)uVar21 < 0) < 0) {

        uVar22 = ~uVar22;

        if (uVar25 == 0) {

          uVar22 = uVar22 + 1;

        }

        else {

          uVar25 = ~uVar25 + 1;

        }

      }

      if (((unsigned char)(in_sr >> 1) & 1) == 1) {

        uVar25 = uVar28 + uVar25;

        uVar9 = uVar22 + (uVar25 < uVar28) + (uVar9 & 0xffff);

        if ((int)uVar9 < -0x8000) {

          uVar9 = 0xffff8000;

          uVar25 = 0;

        }

        if (0x7fff < (int)uVar9) {

          uVar9 = 0x7fff;

          uVar25 = 0xffffffff;

        }

        uVar9 = uVar9 & 0xffff;

      }

      else {

        uVar25 = uVar28 + uVar25;

        uVar9 = uVar22 + (uVar25 < uVar28) + uVar9;

      }

      *(unsigned int *)(puVar6 + 8) = uVar9 << 0x10 | uVar25 >> 0x10;

      uVar22 = *(unsigned int *)puVar6;

      uVar9 = *(unsigned int *)0x06094EF4;

      uVar4 = uVar22 ^ uVar9;

      if ((int)uVar22 < 0) {

        uVar22 = -uVar22;

      }

      if ((int)uVar9 < 0) {

        uVar9 = -uVar9;

      }

      uVar3 = (uVar9 & 0xffff) * (uVar22 & 0xffff);

      iVar11 = (uVar9 >> 0x10) * (uVar22 & 0xffff);

      iVar10 = 0;

      uVar21 = iVar11 + (uVar9 & 0xffff) * (uVar22 >> 0x10);

      if (iVar11 != 0) {

        iVar10 = 0x10000;

      }

      uVar24 = uVar3 + uVar21 * 0x10000;

      uVar9 = iVar10 + (unsigned int)(uVar24 < uVar3) + (uVar21 >> 0x10) +

              (uVar9 >> 0x10) * (uVar22 >> 0x10);

      if ((int)-(unsigned int)((int)uVar4 < 0) < 0) {

        uVar9 = ~uVar9;

        if (uVar24 == 0) {

          uVar9 = uVar9 + 1;

        }

        else {

          uVar24 = ~uVar24 + 1;

        }

      }

      if (((unsigned char)(in_sr >> 1) & 1) == 1) {

        if ((int)uVar9 < -0x8000) {

          uVar9 = 0xffff8000;

          uVar24 = 0;

        }

        if (0x7fff < (int)uVar9) {

          uVar9 = 0x7fff;

          uVar24 = 0xffffffff;

        }

        uVar9 = uVar9 & 0xffff;

      }

      uVar4 = *(unsigned int *)(puVar6 + 4);

      uVar22 = *(unsigned int *)(0x06094EF4 + 4);

      uVar21 = uVar4 ^ uVar22;

      if ((int)uVar4 < 0) {

        uVar4 = -uVar4;

      }

      if ((int)uVar22 < 0) {

        uVar22 = -uVar22;

      }

      uVar25 = (uVar22 & 0xffff) * (uVar4 & 0xffff);

      iVar11 = (uVar22 >> 0x10) * (uVar4 & 0xffff);

      iVar10 = 0;

      uVar3 = iVar11 + (uVar22 & 0xffff) * (uVar4 >> 0x10);

      if (iVar11 != 0) {

        iVar10 = 0x10000;

      }

      uVar28 = uVar25 + uVar3 * 0x10000;

      uVar22 = iVar10 + (unsigned int)(uVar28 < uVar25) + (uVar3 >> 0x10) +

               (uVar22 >> 0x10) * (uVar4 >> 0x10);

      if ((int)-(unsigned int)((int)uVar21 < 0) < 0) {

        uVar22 = ~uVar22;

        if (uVar28 == 0) {

          uVar22 = uVar22 + 1;

        }

        else {

          uVar28 = ~uVar28 + 1;

        }

      }

      if (((unsigned char)(in_sr >> 1) & 1) == 1) {

        uVar28 = uVar24 + uVar28;

        uVar9 = uVar22 + (uVar28 < uVar24) + (uVar9 & 0xffff);

        if ((int)uVar9 < -0x8000) {

          uVar9 = 0xffff8000;

          uVar28 = 0;

        }

        if (0x7fff < (int)uVar9) {

          uVar9 = 0x7fff;

          uVar28 = 0xffffffff;

        }

        uVar9 = uVar9 & 0xffff;

      }

      else {

        uVar28 = uVar24 + uVar28;

        uVar9 = uVar22 + (uVar28 < uVar24) + uVar9;

      }

      uVar4 = *(unsigned int *)(puVar6 + 8);

      uVar22 = *(unsigned int *)(0x06094EF4 + 8);

      uVar21 = uVar4 ^ uVar22;

      if ((int)uVar4 < 0) {

        uVar4 = -uVar4;

      }

      if ((int)uVar22 < 0) {

        uVar22 = -uVar22;

      }

      uVar24 = (uVar22 & 0xffff) * (uVar4 & 0xffff);

      iVar11 = (uVar22 >> 0x10) * (uVar4 & 0xffff);

      iVar10 = 0;

      uVar3 = iVar11 + (uVar22 & 0xffff) * (uVar4 >> 0x10);

      if (iVar11 != 0) {

        iVar10 = 0x10000;

      }

      uVar25 = uVar24 + uVar3 * 0x10000;

      uVar22 = iVar10 + (unsigned int)(uVar25 < uVar24) + (uVar3 >> 0x10) +

               (uVar22 >> 0x10) * (uVar4 >> 0x10);

      if ((int)-(unsigned int)((int)uVar21 < 0) < 0) {

        uVar22 = ~uVar22;

        if (uVar25 == 0) {

          uVar22 = uVar22 + 1;

        }

        else {

          uVar25 = ~uVar25 + 1;

        }

      }

      if (((unsigned char)(in_sr >> 1) & 1) == 1) {

        uVar25 = uVar28 + uVar25;

        uVar9 = uVar22 + (uVar25 < uVar28) + (uVar9 & 0xffff);

        if ((int)uVar9 < -0x8000) {

          uVar9 = 0xffff8000;

          uVar25 = 0;

        }

        if (0x7fff < (int)uVar9) {

          uVar9 = 0x7fff;

          uVar25 = 0xffffffff;

        }

        uVar9 = uVar9 & 0xffff;

      }

      else {

        uVar25 = uVar28 + uVar25;

        uVar9 = uVar22 + (uVar25 < uVar28) + uVar9;

      }

      uVar9 = uVar9 << 0x10 | uVar25 >> 0x10;

      uVar20 = uVar20 | 0 < (int)uVar9;

      if (((unsigned char)uVar20 & 1) == 1) goto LAB_0602bee8;

    }

    else {

LAB_0602bee8:

      puVar6 = 0x06094F74;

      psVar15 = (short *)((unsigned int)*(unsigned short *)((int)puVar17 + -6) * 6 + param_2);

      sVar1 = psVar15[1];

      sVar2 = psVar15[2];

      uVar21 = uVar20 & 0xfffffffe;

      *(int *)0x06094F74 = (int)*psVar15 << 0xb;

      *(int *)(puVar6 + 4) = (int)sVar1 << 0xb;

      *(int *)(puVar6 + 8) = (int)sVar2 << 0xb;

      puVar7 = 0x06094EF4;

      puVar16 = *(unsigned int **)0x0608A52C;

      uVar22 = *puVar16;

      uVar9 = *(unsigned int *)puVar6;

      uVar4 = uVar22 ^ uVar9;

      if ((int)uVar22 < 0) {

        uVar22 = -uVar22;

      }

      if ((int)uVar9 < 0) {

        uVar9 = -uVar9;

      }

      uVar24 = (uVar9 & 0xffff) * (uVar22 & 0xffff);

      iVar11 = (uVar9 >> 0x10) * (uVar22 & 0xffff);

      iVar10 = 0;

      uVar3 = iVar11 + (uVar9 & 0xffff) * (uVar22 >> 0x10);

      if (iVar11 != 0) {

        iVar10 = 0x10000;

      }

      uVar25 = uVar24 + uVar3 * 0x10000;

      uVar9 = iVar10 + (unsigned int)(uVar25 < uVar24) + (uVar3 >> 0x10) +

              (uVar9 >> 0x10) * (uVar22 >> 0x10);

      if ((int)-(unsigned int)((int)uVar4 < 0) < 0) {

        uVar9 = ~uVar9;

        if (uVar25 == 0) {

          uVar9 = uVar9 + 1;

        }

        else {

          uVar25 = ~uVar25 + 1;

        }

      }

      if (((unsigned char)(uVar20 >> 1) & 1) == 1) {

        if ((int)uVar9 < -0x8000) {

          uVar9 = 0xffff8000;

          uVar25 = 0;

        }

        if (0x7fff < (int)uVar9) {

          uVar9 = 0x7fff;

          uVar25 = 0xffffffff;

        }

        uVar9 = uVar9 & 0xffff;

      }

      uVar4 = puVar16[1];

      uVar22 = *(unsigned int *)(puVar6 + 4);

      uVar3 = uVar4 ^ uVar22;

      if ((int)uVar4 < 0) {

        uVar4 = -uVar4;

      }

      if ((int)uVar22 < 0) {

        uVar22 = -uVar22;

      }

      uVar28 = (uVar22 & 0xffff) * (uVar4 & 0xffff);

      iVar11 = (uVar22 >> 0x10) * (uVar4 & 0xffff);

      iVar10 = 0;

      uVar24 = iVar11 + (uVar22 & 0xffff) * (uVar4 >> 0x10);

      if (iVar11 != 0) {

        iVar10 = 0x10000;

      }

      uVar26 = uVar28 + uVar24 * 0x10000;

      uVar22 = iVar10 + (unsigned int)(uVar26 < uVar28) + (uVar24 >> 0x10) +

               (uVar22 >> 0x10) * (uVar4 >> 0x10);

      if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

        uVar22 = ~uVar22;

        if (uVar26 == 0) {

          uVar22 = uVar22 + 1;

        }

        else {

          uVar26 = ~uVar26 + 1;

        }

      }

      if (((unsigned char)(uVar20 >> 1) & 1) == 1) {

        uVar26 = uVar25 + uVar26;

        uVar9 = uVar22 + (uVar26 < uVar25) + (uVar9 & 0xffff);

        if ((int)uVar9 < -0x8000) {

          uVar9 = 0xffff8000;

          uVar26 = 0;

        }

        if (0x7fff < (int)uVar9) {

          uVar9 = 0x7fff;

          uVar26 = 0xffffffff;

        }

        uVar9 = uVar9 & 0xffff;

      }

      else {

        uVar26 = uVar25 + uVar26;

        uVar9 = uVar22 + (uVar26 < uVar25) + uVar9;

      }

      uVar4 = puVar16[2];

      uVar22 = *(unsigned int *)(puVar6 + 8);

      uVar3 = uVar4 ^ uVar22;

      if ((int)uVar4 < 0) {

        uVar4 = -uVar4;

      }

      if ((int)uVar22 < 0) {

        uVar22 = -uVar22;

      }

      uVar25 = (uVar22 & 0xffff) * (uVar4 & 0xffff);

      iVar11 = (uVar22 >> 0x10) * (uVar4 & 0xffff);

      iVar10 = 0;

      uVar24 = iVar11 + (uVar22 & 0xffff) * (uVar4 >> 0x10);

      if (iVar11 != 0) {

        iVar10 = 0x10000;

      }

      uVar28 = uVar25 + uVar24 * 0x10000;

      uVar22 = iVar10 + (unsigned int)(uVar28 < uVar25) + (uVar24 >> 0x10) +

               (uVar22 >> 0x10) * (uVar4 >> 0x10);

      if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

        uVar22 = ~uVar22;

        if (uVar28 == 0) {

          uVar22 = uVar22 + 1;

        }

        else {

          uVar28 = ~uVar28 + 1;

        }

      }

      if (((unsigned char)(uVar20 >> 1) & 1) == 1) {

        uVar28 = uVar26 + uVar28;

        uVar9 = uVar22 + (uVar28 < uVar26) + (uVar9 & 0xffff);

        if ((int)uVar9 < -0x8000) {

          uVar9 = 0xffff8000;

          uVar28 = 0;

        }

        if (0x7fff < (int)uVar9) {

          uVar9 = 0x7fff;

          uVar28 = 0xffffffff;

        }

        uVar9 = uVar9 & 0xffff;

      }

      else {

        uVar28 = uVar26 + uVar28;

        uVar9 = uVar22 + (uVar28 < uVar26) + uVar9;

      }

      uVar4 = puVar16[3];

      uVar22 = *(unsigned int *)puVar6;

      uVar3 = uVar4 ^ uVar22;

      if ((int)uVar4 < 0) {

        uVar4 = -uVar4;

      }

      if ((int)uVar22 < 0) {

        uVar22 = -uVar22;

      }

      uVar25 = (uVar22 & 0xffff) * (uVar4 & 0xffff);

      iVar11 = (uVar22 >> 0x10) * (uVar4 & 0xffff);

      iVar10 = 0;

      uVar24 = iVar11 + (uVar22 & 0xffff) * (uVar4 >> 0x10);

      if (iVar11 != 0) {

        iVar10 = 0x10000;

      }

      uVar26 = uVar25 + uVar24 * 0x10000;

      uVar22 = iVar10 + (unsigned int)(uVar26 < uVar25) + (uVar24 >> 0x10) +

               (uVar22 >> 0x10) * (uVar4 >> 0x10);

      if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

        uVar22 = ~uVar22;

        if (uVar26 == 0) {

          uVar22 = uVar22 + 1;

        }

        else {

          uVar26 = ~uVar26 + 1;

        }

      }

      if (((unsigned char)(uVar20 >> 1) & 1) == 1) {

        if ((int)uVar22 < -0x8000) {

          uVar22 = 0xffff8000;

          uVar26 = 0;

        }

        if (0x7fff < (int)uVar22) {

          uVar22 = 0x7fff;

          uVar26 = 0xffffffff;

        }

        uVar22 = uVar22 & 0xffff;

      }

      uVar3 = puVar16[4];

      uVar4 = *(unsigned int *)(puVar6 + 4);

      uVar24 = uVar3 ^ uVar4;

      if ((int)uVar3 < 0) {

        uVar3 = -uVar3;

      }

      if ((int)uVar4 < 0) {

        uVar4 = -uVar4;

      }

      uVar23 = (uVar4 & 0xffff) * (uVar3 & 0xffff);

      iVar11 = (uVar4 >> 0x10) * (uVar3 & 0xffff);

      iVar10 = 0;

      uVar25 = iVar11 + (uVar4 & 0xffff) * (uVar3 >> 0x10);

      if (iVar11 != 0) {

        iVar10 = 0x10000;

      }

      uVar27 = uVar23 + uVar25 * 0x10000;

      uVar4 = iVar10 + (unsigned int)(uVar27 < uVar23) + (uVar25 >> 0x10) +

              (uVar4 >> 0x10) * (uVar3 >> 0x10);

      if ((int)-(unsigned int)((int)uVar24 < 0) < 0) {

        uVar4 = ~uVar4;

        if (uVar27 == 0) {

          uVar4 = uVar4 + 1;

        }

        else {

          uVar27 = ~uVar27 + 1;

        }

      }

      if (((unsigned char)(uVar20 >> 1) & 1) == 1) {

        uVar27 = uVar26 + uVar27;

        uVar22 = uVar4 + (uVar27 < uVar26) + (uVar22 & 0xffff);

        if ((int)uVar22 < -0x8000) {

          uVar22 = 0xffff8000;

          uVar27 = 0;

        }

        if (0x7fff < (int)uVar22) {

          uVar22 = 0x7fff;

          uVar27 = 0xffffffff;

        }

        uVar22 = uVar22 & 0xffff;

      }

      else {

        uVar27 = uVar26 + uVar27;

        uVar22 = uVar4 + (uVar27 < uVar26) + uVar22;

      }

      *(unsigned int *)(0x06094EF4 + 0xc) = (uVar9 << 0x10 | uVar28 >> 0x10) + puVar16[9];

      uVar4 = puVar16[5];

      uVar9 = *(unsigned int *)(puVar6 + 8);

      uVar3 = uVar4 ^ uVar9;

      if ((int)uVar4 < 0) {

        uVar4 = -uVar4;

      }

      if ((int)uVar9 < 0) {

        uVar9 = -uVar9;

      }

      uVar25 = (uVar9 & 0xffff) * (uVar4 & 0xffff);

      iVar11 = (uVar9 >> 0x10) * (uVar4 & 0xffff);

      iVar10 = 0;

      uVar24 = iVar11 + (uVar9 & 0xffff) * (uVar4 >> 0x10);

      if (iVar11 != 0) {

        iVar10 = 0x10000;

      }

      uVar28 = uVar25 + uVar24 * 0x10000;

      uVar9 = iVar10 + (unsigned int)(uVar28 < uVar25) + (uVar24 >> 0x10) +

              (uVar9 >> 0x10) * (uVar4 >> 0x10);

      if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

        uVar9 = ~uVar9;

        if (uVar28 == 0) {

          uVar9 = uVar9 + 1;

        }

        else {

          uVar28 = ~uVar28 + 1;

        }

      }

      if (((unsigned char)(uVar20 >> 1) & 1) == 1) {

        uVar28 = uVar27 + uVar28;

        uVar22 = uVar9 + (uVar28 < uVar27) + (uVar22 & 0xffff);

        if ((int)uVar22 < -0x8000) {

          uVar22 = 0xffff8000;

          uVar28 = 0;

        }

        if (0x7fff < (int)uVar22) {

          uVar22 = 0x7fff;

          uVar28 = 0xffffffff;

        }

        uVar22 = uVar22 & 0xffff;

      }

      else {

        uVar28 = uVar27 + uVar28;

        uVar22 = uVar9 + (uVar28 < uVar27) + uVar22;

      }

      uVar4 = puVar16[6];

      uVar9 = *(unsigned int *)puVar6;

      uVar3 = uVar4 ^ uVar9;

      if ((int)uVar4 < 0) {

        uVar4 = -uVar4;

      }

      if ((int)uVar9 < 0) {

        uVar9 = -uVar9;

      }

      uVar25 = (uVar9 & 0xffff) * (uVar4 & 0xffff);

      iVar11 = (uVar9 >> 0x10) * (uVar4 & 0xffff);

      iVar10 = 0;

      uVar24 = iVar11 + (uVar9 & 0xffff) * (uVar4 >> 0x10);

      if (iVar11 != 0) {

        iVar10 = 0x10000;

      }

      uVar26 = uVar25 + uVar24 * 0x10000;

      uVar9 = iVar10 + (unsigned int)(uVar26 < uVar25) + (uVar24 >> 0x10) +

              (uVar9 >> 0x10) * (uVar4 >> 0x10);

      if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

        uVar9 = ~uVar9;

        if (uVar26 == 0) {

          uVar9 = uVar9 + 1;

        }

        else {

          uVar26 = ~uVar26 + 1;

        }

      }

      if (((unsigned char)(uVar20 >> 1) & 1) == 1) {

        if ((int)uVar9 < -0x8000) {

          uVar9 = 0xffff8000;

          uVar26 = 0;

        }

        if (0x7fff < (int)uVar9) {

          uVar9 = 0x7fff;

          uVar26 = 0xffffffff;

        }

        uVar9 = uVar9 & 0xffff;

      }

      uVar3 = puVar16[7];

      uVar4 = *(unsigned int *)(puVar6 + 4);

      uVar24 = uVar3 ^ uVar4;

      if ((int)uVar3 < 0) {

        uVar3 = -uVar3;

      }

      if ((int)uVar4 < 0) {

        uVar4 = -uVar4;

      }

      uVar23 = (uVar4 & 0xffff) * (uVar3 & 0xffff);

      iVar11 = (uVar4 >> 0x10) * (uVar3 & 0xffff);

      iVar10 = 0;

      uVar25 = iVar11 + (uVar4 & 0xffff) * (uVar3 >> 0x10);

      if (iVar11 != 0) {

        iVar10 = 0x10000;

      }

      uVar27 = uVar23 + uVar25 * 0x10000;

      uVar4 = iVar10 + (unsigned int)(uVar27 < uVar23) + (uVar25 >> 0x10) +

              (uVar4 >> 0x10) * (uVar3 >> 0x10);

      if ((int)-(unsigned int)((int)uVar24 < 0) < 0) {

        uVar4 = ~uVar4;

        if (uVar27 == 0) {

          uVar4 = uVar4 + 1;

        }

        else {

          uVar27 = ~uVar27 + 1;

        }

      }

      if (((unsigned char)(uVar20 >> 1) & 1) == 1) {

        uVar27 = uVar26 + uVar27;

        uVar9 = uVar4 + (uVar27 < uVar26) + (uVar9 & 0xffff);

        if ((int)uVar9 < -0x8000) {

          uVar9 = 0xffff8000;

          uVar27 = 0;

        }

        if (0x7fff < (int)uVar9) {

          uVar9 = 0x7fff;

          uVar27 = 0xffffffff;

        }

        uVar9 = uVar9 & 0xffff;

      }

      else {

        uVar27 = uVar26 + uVar27;

        uVar9 = uVar4 + (uVar27 < uVar26) + uVar9;

      }

      *(unsigned int *)(puVar7 + 0x10) = (uVar22 << 0x10 | uVar28 >> 0x10) + puVar16[10];

      uVar4 = puVar16[8];

      uVar22 = *(unsigned int *)(puVar6 + 8);

      uVar3 = uVar4 ^ uVar22;

      if ((int)uVar4 < 0) {

        uVar4 = -uVar4;

      }

      if ((int)uVar22 < 0) {

        uVar22 = -uVar22;

      }

      uVar25 = (uVar22 & 0xffff) * (uVar4 & 0xffff);

      iVar11 = (uVar22 >> 0x10) * (uVar4 & 0xffff);

      iVar10 = 0;

      uVar24 = iVar11 + (uVar22 & 0xffff) * (uVar4 >> 0x10);

      if (iVar11 != 0) {

        iVar10 = 0x10000;

      }

      uVar28 = uVar25 + uVar24 * 0x10000;

      uVar22 = iVar10 + (unsigned int)(uVar28 < uVar25) + (uVar24 >> 0x10) +

               (uVar22 >> 0x10) * (uVar4 >> 0x10);

      if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

        uVar22 = ~uVar22;

        if (uVar28 == 0) {

          uVar22 = uVar22 + 1;

        }

        else {

          uVar28 = ~uVar28 + 1;

        }

      }

      if (((unsigned char)(uVar20 >> 1) & 1) == 1) {

        uVar28 = uVar27 + uVar28;

        uVar9 = uVar22 + (uVar28 < uVar27) + (uVar9 & 0xffff);

        if ((int)uVar9 < -0x8000) {

          uVar9 = 0xffff8000;

          uVar28 = 0;

        }

        if (0x7fff < (int)uVar9) {

          uVar9 = 0x7fff;

          uVar28 = 0xffffffff;

        }

        uVar9 = uVar9 & 0xffff;

      }

      else {

        uVar28 = uVar27 + uVar28;

        uVar9 = uVar22 + (uVar28 < uVar27) + uVar9;

      }

      *(unsigned int *)(puVar7 + 0x14) = (uVar9 << 0x10 | uVar28 >> 0x10) + puVar16[0xb];

      *(unsigned short *)(puVar5 + 2) = (unsigned short)(*(int *)(puVar7 + 0x14) <= iVar19);

      puVar6 = 0x06094F74;

      psVar15 = (short *)((unsigned int)*(unsigned short *)(puVar17 + -1) * 6 + param_2);

      sVar1 = psVar15[1];

      sVar2 = psVar15[2];

      *(int *)0x06094F74 = (int)*psVar15 << 0xb;

      *(int *)(puVar6 + 4) = (int)sVar1 << 0xb;

      *(int *)0x06094FA4 = (int)sVar1 << 0xb;

      *(int *)(puVar6 + 8) = (int)sVar2 << 0xb;

      puVar7 = 0x06094EF4;

      puVar16 = *(unsigned int **)0x0608A52C;

      uVar22 = *puVar16;

      uVar9 = *(unsigned int *)puVar6;

      uVar4 = uVar22 ^ uVar9;

      if ((int)uVar22 < 0) {

        uVar22 = -uVar22;

      }

      if ((int)uVar9 < 0) {

        uVar9 = -uVar9;

      }

      uVar24 = (uVar9 & 0xffff) * (uVar22 & 0xffff);

      iVar11 = (uVar9 >> 0x10) * (uVar22 & 0xffff);

      iVar10 = 0;

      uVar3 = iVar11 + (uVar9 & 0xffff) * (uVar22 >> 0x10);

      if (iVar11 != 0) {

        iVar10 = 0x10000;

      }

      uVar25 = uVar24 + uVar3 * 0x10000;

      uVar9 = iVar10 + (unsigned int)(uVar25 < uVar24) + (uVar3 >> 0x10) +

              (uVar9 >> 0x10) * (uVar22 >> 0x10);

      if ((int)-(unsigned int)((int)uVar4 < 0) < 0) {

        uVar9 = ~uVar9;

        if (uVar25 == 0) {

          uVar9 = uVar9 + 1;

        }

        else {

          uVar25 = ~uVar25 + 1;

        }

      }

      if (((unsigned char)(uVar20 >> 1) & 1) == 1) {

        if ((int)uVar9 < -0x8000) {

          uVar9 = 0xffff8000;

          uVar25 = 0;

        }

        if (0x7fff < (int)uVar9) {

          uVar9 = 0x7fff;

          uVar25 = 0xffffffff;

        }

        uVar9 = uVar9 & 0xffff;

      }

      uVar4 = puVar16[1];

      uVar22 = *(unsigned int *)(puVar6 + 4);

      uVar3 = uVar4 ^ uVar22;

      if ((int)uVar4 < 0) {

        uVar4 = -uVar4;

      }

      if ((int)uVar22 < 0) {

        uVar22 = -uVar22;

      }

      uVar28 = (uVar22 & 0xffff) * (uVar4 & 0xffff);

      iVar11 = (uVar22 >> 0x10) * (uVar4 & 0xffff);

      iVar10 = 0;

      uVar24 = iVar11 + (uVar22 & 0xffff) * (uVar4 >> 0x10);

      if (iVar11 != 0) {

        iVar10 = 0x10000;

      }

      uVar26 = uVar28 + uVar24 * 0x10000;

      uVar22 = iVar10 + (unsigned int)(uVar26 < uVar28) + (uVar24 >> 0x10) +

               (uVar22 >> 0x10) * (uVar4 >> 0x10);

      if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

        uVar22 = ~uVar22;

        if (uVar26 == 0) {

          uVar22 = uVar22 + 1;

        }

        else {

          uVar26 = ~uVar26 + 1;

        }

      }

      if (((unsigned char)(uVar20 >> 1) & 1) == 1) {

        uVar26 = uVar25 + uVar26;

        uVar9 = uVar22 + (uVar26 < uVar25) + (uVar9 & 0xffff);

        if ((int)uVar9 < -0x8000) {

          uVar9 = 0xffff8000;

          uVar26 = 0;

        }

        if (0x7fff < (int)uVar9) {

          uVar9 = 0x7fff;

          uVar26 = 0xffffffff;

        }

        uVar9 = uVar9 & 0xffff;

      }

      else {

        uVar26 = uVar25 + uVar26;

        uVar9 = uVar22 + (uVar26 < uVar25) + uVar9;

      }

      uVar4 = puVar16[2];

      uVar22 = *(unsigned int *)(puVar6 + 8);

      uVar3 = uVar4 ^ uVar22;

      if ((int)uVar4 < 0) {

        uVar4 = -uVar4;

      }

      if ((int)uVar22 < 0) {

        uVar22 = -uVar22;

      }

      uVar25 = (uVar22 & 0xffff) * (uVar4 & 0xffff);

      iVar11 = (uVar22 >> 0x10) * (uVar4 & 0xffff);

      iVar10 = 0;

      uVar24 = iVar11 + (uVar22 & 0xffff) * (uVar4 >> 0x10);

      if (iVar11 != 0) {

        iVar10 = 0x10000;

      }

      uVar28 = uVar25 + uVar24 * 0x10000;

      uVar22 = iVar10 + (unsigned int)(uVar28 < uVar25) + (uVar24 >> 0x10) +

               (uVar22 >> 0x10) * (uVar4 >> 0x10);

      if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

        uVar22 = ~uVar22;

        if (uVar28 == 0) {

          uVar22 = uVar22 + 1;

        }

        else {

          uVar28 = ~uVar28 + 1;

        }

      }

      if (((unsigned char)(uVar20 >> 1) & 1) == 1) {

        uVar28 = uVar26 + uVar28;

        uVar9 = uVar22 + (uVar28 < uVar26) + (uVar9 & 0xffff);

        if ((int)uVar9 < -0x8000) {

          uVar9 = 0xffff8000;

          uVar28 = 0;

        }

        if (0x7fff < (int)uVar9) {

          uVar9 = 0x7fff;

          uVar28 = 0xffffffff;

        }

        uVar9 = uVar9 & 0xffff;

      }

      else {

        uVar28 = uVar26 + uVar28;

        uVar9 = uVar22 + (uVar28 < uVar26) + uVar9;

      }

      uVar4 = puVar16[3];

      uVar22 = *(unsigned int *)puVar6;

      uVar3 = uVar4 ^ uVar22;

      if ((int)uVar4 < 0) {

        uVar4 = -uVar4;

      }

      if ((int)uVar22 < 0) {

        uVar22 = -uVar22;

      }

      uVar25 = (uVar22 & 0xffff) * (uVar4 & 0xffff);

      iVar11 = (uVar22 >> 0x10) * (uVar4 & 0xffff);

      iVar10 = 0;

      uVar24 = iVar11 + (uVar22 & 0xffff) * (uVar4 >> 0x10);

      if (iVar11 != 0) {

        iVar10 = 0x10000;

      }

      uVar26 = uVar25 + uVar24 * 0x10000;

      uVar22 = iVar10 + (unsigned int)(uVar26 < uVar25) + (uVar24 >> 0x10) +

               (uVar22 >> 0x10) * (uVar4 >> 0x10);

      if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

        uVar22 = ~uVar22;

        if (uVar26 == 0) {

          uVar22 = uVar22 + 1;

        }

        else {

          uVar26 = ~uVar26 + 1;

        }

      }

      if (((unsigned char)(uVar20 >> 1) & 1) == 1) {

        if ((int)uVar22 < -0x8000) {

          uVar22 = 0xffff8000;

          uVar26 = 0;

        }

        if (0x7fff < (int)uVar22) {

          uVar22 = 0x7fff;

          uVar26 = 0xffffffff;

        }

        uVar22 = uVar22 & 0xffff;

      }

      uVar3 = puVar16[4];

      uVar4 = *(unsigned int *)(puVar6 + 4);

      uVar24 = uVar3 ^ uVar4;

      if ((int)uVar3 < 0) {

        uVar3 = -uVar3;

      }

      if ((int)uVar4 < 0) {

        uVar4 = -uVar4;

      }

      uVar23 = (uVar4 & 0xffff) * (uVar3 & 0xffff);

      iVar11 = (uVar4 >> 0x10) * (uVar3 & 0xffff);

      iVar10 = 0;

      uVar25 = iVar11 + (uVar4 & 0xffff) * (uVar3 >> 0x10);

      if (iVar11 != 0) {

        iVar10 = 0x10000;

      }

      uVar27 = uVar23 + uVar25 * 0x10000;

      uVar4 = iVar10 + (unsigned int)(uVar27 < uVar23) + (uVar25 >> 0x10) +

              (uVar4 >> 0x10) * (uVar3 >> 0x10);

      if ((int)-(unsigned int)((int)uVar24 < 0) < 0) {

        uVar4 = ~uVar4;

        if (uVar27 == 0) {

          uVar4 = uVar4 + 1;

        }

        else {

          uVar27 = ~uVar27 + 1;

        }

      }

      if (((unsigned char)(uVar20 >> 1) & 1) == 1) {

        uVar27 = uVar26 + uVar27;

        uVar22 = uVar4 + (uVar27 < uVar26) + (uVar22 & 0xffff);

        if ((int)uVar22 < -0x8000) {

          uVar22 = 0xffff8000;

          uVar27 = 0;

        }

        if (0x7fff < (int)uVar22) {

          uVar22 = 0x7fff;

          uVar27 = 0xffffffff;

        }

        uVar22 = uVar22 & 0xffff;

      }

      else {

        uVar27 = uVar26 + uVar27;

        uVar22 = uVar4 + (uVar27 < uVar26) + uVar22;

      }

      *(unsigned int *)(0x06094EF4 + 0x18) = (uVar9 << 0x10 | uVar28 >> 0x10) + puVar16[9];

      uVar4 = puVar16[5];

      uVar9 = *(unsigned int *)(puVar6 + 8);

      uVar3 = uVar4 ^ uVar9;

      if ((int)uVar4 < 0) {

        uVar4 = -uVar4;

      }

      if ((int)uVar9 < 0) {

        uVar9 = -uVar9;

      }

      uVar25 = (uVar9 & 0xffff) * (uVar4 & 0xffff);

      iVar11 = (uVar9 >> 0x10) * (uVar4 & 0xffff);

      iVar10 = 0;

      uVar24 = iVar11 + (uVar9 & 0xffff) * (uVar4 >> 0x10);

      if (iVar11 != 0) {

        iVar10 = 0x10000;

      }

      uVar28 = uVar25 + uVar24 * 0x10000;

      uVar9 = iVar10 + (unsigned int)(uVar28 < uVar25) + (uVar24 >> 0x10) +

              (uVar9 >> 0x10) * (uVar4 >> 0x10);

      if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

        uVar9 = ~uVar9;

        if (uVar28 == 0) {

          uVar9 = uVar9 + 1;

        }

        else {

          uVar28 = ~uVar28 + 1;

        }

      }

      if (((unsigned char)(uVar20 >> 1) & 1) == 1) {

        uVar28 = uVar27 + uVar28;

        uVar22 = uVar9 + (uVar28 < uVar27) + (uVar22 & 0xffff);

        if ((int)uVar22 < -0x8000) {

          uVar22 = 0xffff8000;

          uVar28 = 0;

        }

        if (0x7fff < (int)uVar22) {

          uVar22 = 0x7fff;

          uVar28 = 0xffffffff;

        }

        uVar22 = uVar22 & 0xffff;

      }

      else {

        uVar28 = uVar27 + uVar28;

        uVar22 = uVar9 + (uVar28 < uVar27) + uVar22;

      }

      uVar4 = puVar16[6];

      uVar9 = *(unsigned int *)puVar6;

      uVar3 = uVar4 ^ uVar9;

      if ((int)uVar4 < 0) {

        uVar4 = -uVar4;

      }

      if ((int)uVar9 < 0) {

        uVar9 = -uVar9;

      }

      uVar25 = (uVar9 & 0xffff) * (uVar4 & 0xffff);

      iVar11 = (uVar9 >> 0x10) * (uVar4 & 0xffff);

      iVar10 = 0;

      uVar24 = iVar11 + (uVar9 & 0xffff) * (uVar4 >> 0x10);

      if (iVar11 != 0) {

        iVar10 = 0x10000;

      }

      uVar26 = uVar25 + uVar24 * 0x10000;

      uVar9 = iVar10 + (unsigned int)(uVar26 < uVar25) + (uVar24 >> 0x10) +

              (uVar9 >> 0x10) * (uVar4 >> 0x10);

      if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

        uVar9 = ~uVar9;

        if (uVar26 == 0) {

          uVar9 = uVar9 + 1;

        }

        else {

          uVar26 = ~uVar26 + 1;

        }

      }

      if (((unsigned char)(uVar20 >> 1) & 1) == 1) {

        if ((int)uVar9 < -0x8000) {

          uVar9 = 0xffff8000;

          uVar26 = 0;

        }

        if (0x7fff < (int)uVar9) {

          uVar9 = 0x7fff;

          uVar26 = 0xffffffff;

        }

        uVar9 = uVar9 & 0xffff;

      }

      uVar3 = puVar16[7];

      uVar4 = *(unsigned int *)(puVar6 + 4);

      uVar24 = uVar3 ^ uVar4;

      if ((int)uVar3 < 0) {

        uVar3 = -uVar3;

      }

      if ((int)uVar4 < 0) {

        uVar4 = -uVar4;

      }

      uVar23 = (uVar4 & 0xffff) * (uVar3 & 0xffff);

      iVar11 = (uVar4 >> 0x10) * (uVar3 & 0xffff);

      iVar10 = 0;

      uVar25 = iVar11 + (uVar4 & 0xffff) * (uVar3 >> 0x10);

      if (iVar11 != 0) {

        iVar10 = 0x10000;

      }

      uVar27 = uVar23 + uVar25 * 0x10000;

      uVar4 = iVar10 + (unsigned int)(uVar27 < uVar23) + (uVar25 >> 0x10) +

              (uVar4 >> 0x10) * (uVar3 >> 0x10);

      if ((int)-(unsigned int)((int)uVar24 < 0) < 0) {

        uVar4 = ~uVar4;

        if (uVar27 == 0) {

          uVar4 = uVar4 + 1;

        }

        else {

          uVar27 = ~uVar27 + 1;

        }

      }

      if (((unsigned char)(uVar20 >> 1) & 1) == 1) {

        uVar27 = uVar26 + uVar27;

        uVar9 = uVar4 + (uVar27 < uVar26) + (uVar9 & 0xffff);

        if ((int)uVar9 < -0x8000) {

          uVar9 = 0xffff8000;

          uVar27 = 0;

        }

        if (0x7fff < (int)uVar9) {

          uVar9 = 0x7fff;

          uVar27 = 0xffffffff;

        }

        uVar9 = uVar9 & 0xffff;

      }

      else {

        uVar27 = uVar26 + uVar27;

        uVar9 = uVar4 + (uVar27 < uVar26) + uVar9;

      }

      *(unsigned int *)(puVar7 + 0x1c) = (uVar22 << 0x10 | uVar28 >> 0x10) + puVar16[10];

      uVar4 = puVar16[8];

      uVar22 = *(unsigned int *)(puVar6 + 8);

      uVar3 = uVar4 ^ uVar22;

      if ((int)uVar4 < 0) {

        uVar4 = -uVar4;

      }

      if ((int)uVar22 < 0) {

        uVar22 = -uVar22;

      }

      uVar25 = (uVar22 & 0xffff) * (uVar4 & 0xffff);

      iVar11 = (uVar22 >> 0x10) * (uVar4 & 0xffff);

      iVar10 = 0;

      uVar24 = iVar11 + (uVar22 & 0xffff) * (uVar4 >> 0x10);

      if (iVar11 != 0) {

        iVar10 = 0x10000;

      }

      uVar28 = uVar25 + uVar24 * 0x10000;

      uVar22 = iVar10 + (unsigned int)(uVar28 < uVar25) + (uVar24 >> 0x10) +

               (uVar22 >> 0x10) * (uVar4 >> 0x10);

      if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

        uVar22 = ~uVar22;

        if (uVar28 == 0) {

          uVar22 = uVar22 + 1;

        }

        else {

          uVar28 = ~uVar28 + 1;

        }

      }

      if (((unsigned char)(uVar20 >> 1) & 1) == 1) {

        uVar28 = uVar27 + uVar28;

        uVar9 = uVar22 + (uVar28 < uVar27) + (uVar9 & 0xffff);

        if ((int)uVar9 < -0x8000) {

          uVar9 = 0xffff8000;

          uVar28 = 0;

        }

        if (0x7fff < (int)uVar9) {

          uVar9 = 0x7fff;

          uVar28 = 0xffffffff;

        }

        uVar9 = uVar9 & 0xffff;

      }

      else {

        uVar28 = uVar27 + uVar28;

        uVar9 = uVar22 + (uVar28 < uVar27) + uVar9;

      }

      *(unsigned int *)(puVar7 + 0x20) = (uVar9 << 0x10 | uVar28 >> 0x10) + puVar16[0xb];

      *(unsigned short *)(puVar5 + 4) = (unsigned short)(*(int *)(puVar7 + 0x20) <= iVar19);

      puVar6 = 0x06094F74;

      psVar15 = (short *)((unsigned int)*(unsigned short *)((int)puVar17 + -2) * 6 + param_2);

      sVar1 = psVar15[1];

      sVar2 = psVar15[2];

      *(int *)0x06094F74 = (int)*psVar15 << 0xb;

      *(int *)(puVar6 + 4) = (int)sVar1 << 0xb;

      *(int *)(puVar6 + 8) = (int)sVar2 << 0xb;

      puVar7 = 0x06094EF4;

      puVar16 = *(unsigned int **)0x0608A52C;

      uVar22 = *puVar16;

      uVar9 = *(unsigned int *)puVar6;

      uVar4 = uVar22 ^ uVar9;

      if ((int)uVar22 < 0) {

        uVar22 = -uVar22;

      }

      if ((int)uVar9 < 0) {

        uVar9 = -uVar9;

      }

      uVar24 = (uVar9 & 0xffff) * (uVar22 & 0xffff);

      iVar11 = (uVar9 >> 0x10) * (uVar22 & 0xffff);

      iVar10 = 0;

      uVar3 = iVar11 + (uVar9 & 0xffff) * (uVar22 >> 0x10);

      if (iVar11 != 0) {

        iVar10 = 0x10000;

      }

      uVar25 = uVar24 + uVar3 * 0x10000;

      uVar9 = iVar10 + (unsigned int)(uVar25 < uVar24) + (uVar3 >> 0x10) +

              (uVar9 >> 0x10) * (uVar22 >> 0x10);

      if ((int)-(unsigned int)((int)uVar4 < 0) < 0) {

        uVar9 = ~uVar9;

        if (uVar25 == 0) {

          uVar9 = uVar9 + 1;

        }

        else {

          uVar25 = ~uVar25 + 1;

        }

      }

      if (((unsigned char)(uVar20 >> 1) & 1) == 1) {

        if ((int)uVar9 < -0x8000) {

          uVar9 = 0xffff8000;

          uVar25 = 0;

        }

        if (0x7fff < (int)uVar9) {

          uVar9 = 0x7fff;

          uVar25 = 0xffffffff;

        }

        uVar9 = uVar9 & 0xffff;

      }

      uVar4 = puVar16[1];

      uVar22 = *(unsigned int *)(puVar6 + 4);

      uVar3 = uVar4 ^ uVar22;

      if ((int)uVar4 < 0) {

        uVar4 = -uVar4;

      }

      if ((int)uVar22 < 0) {

        uVar22 = -uVar22;

      }

      uVar28 = (uVar22 & 0xffff) * (uVar4 & 0xffff);

      iVar11 = (uVar22 >> 0x10) * (uVar4 & 0xffff);

      iVar10 = 0;

      uVar24 = iVar11 + (uVar22 & 0xffff) * (uVar4 >> 0x10);

      if (iVar11 != 0) {

        iVar10 = 0x10000;

      }

      uVar26 = uVar28 + uVar24 * 0x10000;

      uVar22 = iVar10 + (unsigned int)(uVar26 < uVar28) + (uVar24 >> 0x10) +

               (uVar22 >> 0x10) * (uVar4 >> 0x10);

      if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

        uVar22 = ~uVar22;

        if (uVar26 == 0) {

          uVar22 = uVar22 + 1;

        }

        else {

          uVar26 = ~uVar26 + 1;

        }

      }

      if (((unsigned char)(uVar20 >> 1) & 1) == 1) {

        uVar26 = uVar25 + uVar26;

        uVar9 = uVar22 + (uVar26 < uVar25) + (uVar9 & 0xffff);

        if ((int)uVar9 < -0x8000) {

          uVar9 = 0xffff8000;

          uVar26 = 0;

        }

        if (0x7fff < (int)uVar9) {

          uVar9 = 0x7fff;

          uVar26 = 0xffffffff;

        }

        uVar9 = uVar9 & 0xffff;

      }

      else {

        uVar26 = uVar25 + uVar26;

        uVar9 = uVar22 + (uVar26 < uVar25) + uVar9;

      }

      uVar4 = puVar16[2];

      uVar22 = *(unsigned int *)(puVar6 + 8);

      uVar3 = uVar4 ^ uVar22;

      if ((int)uVar4 < 0) {

        uVar4 = -uVar4;

      }

      if ((int)uVar22 < 0) {

        uVar22 = -uVar22;

      }

      uVar25 = (uVar22 & 0xffff) * (uVar4 & 0xffff);

      iVar11 = (uVar22 >> 0x10) * (uVar4 & 0xffff);

      iVar10 = 0;

      uVar24 = iVar11 + (uVar22 & 0xffff) * (uVar4 >> 0x10);

      if (iVar11 != 0) {

        iVar10 = 0x10000;

      }

      uVar28 = uVar25 + uVar24 * 0x10000;

      uVar22 = iVar10 + (unsigned int)(uVar28 < uVar25) + (uVar24 >> 0x10) +

               (uVar22 >> 0x10) * (uVar4 >> 0x10);

      if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

        uVar22 = ~uVar22;

        if (uVar28 == 0) {

          uVar22 = uVar22 + 1;

        }

        else {

          uVar28 = ~uVar28 + 1;

        }

      }

      if (((unsigned char)(uVar20 >> 1) & 1) == 1) {

        uVar28 = uVar26 + uVar28;

        uVar9 = uVar22 + (uVar28 < uVar26) + (uVar9 & 0xffff);

        if ((int)uVar9 < -0x8000) {

          uVar9 = 0xffff8000;

          uVar28 = 0;

        }

        if (0x7fff < (int)uVar9) {

          uVar9 = 0x7fff;

          uVar28 = 0xffffffff;

        }

        uVar9 = uVar9 & 0xffff;

      }

      else {

        uVar28 = uVar26 + uVar28;

        uVar9 = uVar22 + (uVar28 < uVar26) + uVar9;

      }

      uVar4 = puVar16[3];

      uVar22 = *(unsigned int *)puVar6;

      uVar3 = uVar4 ^ uVar22;

      if ((int)uVar4 < 0) {

        uVar4 = -uVar4;

      }

      if ((int)uVar22 < 0) {

        uVar22 = -uVar22;

      }

      uVar25 = (uVar22 & 0xffff) * (uVar4 & 0xffff);

      iVar11 = (uVar22 >> 0x10) * (uVar4 & 0xffff);

      iVar10 = 0;

      uVar24 = iVar11 + (uVar22 & 0xffff) * (uVar4 >> 0x10);

      if (iVar11 != 0) {

        iVar10 = 0x10000;

      }

      uVar26 = uVar25 + uVar24 * 0x10000;

      uVar22 = iVar10 + (unsigned int)(uVar26 < uVar25) + (uVar24 >> 0x10) +

               (uVar22 >> 0x10) * (uVar4 >> 0x10);

      if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

        uVar22 = ~uVar22;

        if (uVar26 == 0) {

          uVar22 = uVar22 + 1;

        }

        else {

          uVar26 = ~uVar26 + 1;

        }

      }

      if (((unsigned char)(uVar20 >> 1) & 1) == 1) {

        if ((int)uVar22 < -0x8000) {

          uVar22 = 0xffff8000;

          uVar26 = 0;

        }

        if (0x7fff < (int)uVar22) {

          uVar22 = 0x7fff;

          uVar26 = 0xffffffff;

        }

        uVar22 = uVar22 & 0xffff;

      }

      uVar3 = puVar16[4];

      uVar4 = *(unsigned int *)(puVar6 + 4);

      uVar24 = uVar3 ^ uVar4;

      if ((int)uVar3 < 0) {

        uVar3 = -uVar3;

      }

      if ((int)uVar4 < 0) {

        uVar4 = -uVar4;

      }

      uVar23 = (uVar4 & 0xffff) * (uVar3 & 0xffff);

      iVar11 = (uVar4 >> 0x10) * (uVar3 & 0xffff);

      iVar10 = 0;

      uVar25 = iVar11 + (uVar4 & 0xffff) * (uVar3 >> 0x10);

      if (iVar11 != 0) {

        iVar10 = 0x10000;

      }

      uVar27 = uVar23 + uVar25 * 0x10000;

      uVar4 = iVar10 + (unsigned int)(uVar27 < uVar23) + (uVar25 >> 0x10) +

              (uVar4 >> 0x10) * (uVar3 >> 0x10);

      if ((int)-(unsigned int)((int)uVar24 < 0) < 0) {

        uVar4 = ~uVar4;

        if (uVar27 == 0) {

          uVar4 = uVar4 + 1;

        }

        else {

          uVar27 = ~uVar27 + 1;

        }

      }

      if (((unsigned char)(uVar20 >> 1) & 1) == 1) {

        uVar27 = uVar26 + uVar27;

        uVar22 = uVar4 + (uVar27 < uVar26) + (uVar22 & 0xffff);

        if ((int)uVar22 < -0x8000) {

          uVar22 = 0xffff8000;

          uVar27 = 0;

        }

        if (0x7fff < (int)uVar22) {

          uVar22 = 0x7fff;

          uVar27 = 0xffffffff;

        }

        uVar22 = uVar22 & 0xffff;

      }

      else {

        uVar27 = uVar26 + uVar27;

        uVar22 = uVar4 + (uVar27 < uVar26) + uVar22;

      }

      *(unsigned int *)(0x06094EF4 + 0x24) = (uVar9 << 0x10 | uVar28 >> 0x10) + puVar16[9];

      uVar4 = puVar16[5];

      uVar9 = *(unsigned int *)(puVar6 + 8);

      uVar3 = uVar4 ^ uVar9;

      if ((int)uVar4 < 0) {

        uVar4 = -uVar4;

      }

      if ((int)uVar9 < 0) {

        uVar9 = -uVar9;

      }

      uVar25 = (uVar9 & 0xffff) * (uVar4 & 0xffff);

      iVar11 = (uVar9 >> 0x10) * (uVar4 & 0xffff);

      iVar10 = 0;

      uVar24 = iVar11 + (uVar9 & 0xffff) * (uVar4 >> 0x10);

      if (iVar11 != 0) {

        iVar10 = 0x10000;

      }

      uVar28 = uVar25 + uVar24 * 0x10000;

      uVar9 = iVar10 + (unsigned int)(uVar28 < uVar25) + (uVar24 >> 0x10) +

              (uVar9 >> 0x10) * (uVar4 >> 0x10);

      if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

        uVar9 = ~uVar9;

        if (uVar28 == 0) {

          uVar9 = uVar9 + 1;

        }

        else {

          uVar28 = ~uVar28 + 1;

        }

      }

      if (((unsigned char)(uVar20 >> 1) & 1) == 1) {

        uVar28 = uVar27 + uVar28;

        uVar22 = uVar9 + (uVar28 < uVar27) + (uVar22 & 0xffff);

        if ((int)uVar22 < -0x8000) {

          uVar22 = 0xffff8000;

          uVar28 = 0;

        }

        if (0x7fff < (int)uVar22) {

          uVar22 = 0x7fff;

          uVar28 = 0xffffffff;

        }

        uVar22 = uVar22 & 0xffff;

      }

      else {

        uVar28 = uVar27 + uVar28;

        uVar22 = uVar9 + (uVar28 < uVar27) + uVar22;

      }

      uVar4 = puVar16[6];

      uVar9 = *(unsigned int *)puVar6;

      uVar3 = uVar4 ^ uVar9;

      if ((int)uVar4 < 0) {

        uVar4 = -uVar4;

      }

      if ((int)uVar9 < 0) {

        uVar9 = -uVar9;

      }

      uVar25 = (uVar9 & 0xffff) * (uVar4 & 0xffff);

      iVar11 = (uVar9 >> 0x10) * (uVar4 & 0xffff);

      iVar10 = 0;

      uVar24 = iVar11 + (uVar9 & 0xffff) * (uVar4 >> 0x10);

      if (iVar11 != 0) {

        iVar10 = 0x10000;

      }

      uVar26 = uVar25 + uVar24 * 0x10000;

      uVar9 = iVar10 + (unsigned int)(uVar26 < uVar25) + (uVar24 >> 0x10) +

              (uVar9 >> 0x10) * (uVar4 >> 0x10);

      if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

        uVar9 = ~uVar9;

        if (uVar26 == 0) {

          uVar9 = uVar9 + 1;

        }

        else {

          uVar26 = ~uVar26 + 1;

        }

      }

      if (((unsigned char)(uVar20 >> 1) & 1) == 1) {

        if ((int)uVar9 < -0x8000) {

          uVar9 = 0xffff8000;

          uVar26 = 0;

        }

        if (0x7fff < (int)uVar9) {

          uVar9 = 0x7fff;

          uVar26 = 0xffffffff;

        }

        uVar9 = uVar9 & 0xffff;

      }

      uVar3 = puVar16[7];

      uVar4 = *(unsigned int *)(puVar6 + 4);

      uVar24 = uVar3 ^ uVar4;

      if ((int)uVar3 < 0) {

        uVar3 = -uVar3;

      }

      if ((int)uVar4 < 0) {

        uVar4 = -uVar4;

      }

      uVar23 = (uVar4 & 0xffff) * (uVar3 & 0xffff);

      iVar11 = (uVar4 >> 0x10) * (uVar3 & 0xffff);

      iVar10 = 0;

      uVar25 = iVar11 + (uVar4 & 0xffff) * (uVar3 >> 0x10);

      if (iVar11 != 0) {

        iVar10 = 0x10000;

      }

      uVar27 = uVar23 + uVar25 * 0x10000;

      uVar4 = iVar10 + (unsigned int)(uVar27 < uVar23) + (uVar25 >> 0x10) +

              (uVar4 >> 0x10) * (uVar3 >> 0x10);

      if ((int)-(unsigned int)((int)uVar24 < 0) < 0) {

        uVar4 = ~uVar4;

        if (uVar27 == 0) {

          uVar4 = uVar4 + 1;

        }

        else {

          uVar27 = ~uVar27 + 1;

        }

      }

      if (((unsigned char)(uVar20 >> 1) & 1) == 1) {

        uVar27 = uVar26 + uVar27;

        uVar9 = uVar4 + (uVar27 < uVar26) + (uVar9 & 0xffff);

        if ((int)uVar9 < -0x8000) {

          uVar9 = 0xffff8000;

          uVar27 = 0;

        }

        if (0x7fff < (int)uVar9) {

          uVar9 = 0x7fff;

          uVar27 = 0xffffffff;

        }

        uVar9 = uVar9 & 0xffff;

      }

      else {

        uVar27 = uVar26 + uVar27;

        uVar9 = uVar4 + (uVar27 < uVar26) + uVar9;

      }

      *(unsigned int *)(puVar7 + 0x28) = (uVar22 << 0x10 | uVar28 >> 0x10) + puVar16[10];

      uVar4 = puVar16[8];

      uVar22 = *(unsigned int *)(puVar6 + 8);

      uVar3 = uVar4 ^ uVar22;

      if ((int)uVar4 < 0) {

        uVar4 = -uVar4;

      }

      if ((int)uVar22 < 0) {

        uVar22 = -uVar22;

      }

      uVar25 = (uVar22 & 0xffff) * (uVar4 & 0xffff);

      iVar11 = (uVar22 >> 0x10) * (uVar4 & 0xffff);

      iVar10 = 0;

      uVar24 = iVar11 + (uVar22 & 0xffff) * (uVar4 >> 0x10);

      if (iVar11 != 0) {

        iVar10 = 0x10000;

      }

      uVar28 = uVar25 + uVar24 * 0x10000;

      uVar22 = iVar10 + (unsigned int)(uVar28 < uVar25) + (uVar24 >> 0x10) +

               (uVar22 >> 0x10) * (uVar4 >> 0x10);

      if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

        uVar22 = ~uVar22;

        if (uVar28 == 0) {

          uVar22 = uVar22 + 1;

        }

        else {

          uVar28 = ~uVar28 + 1;

        }

      }

      if (((unsigned char)(uVar20 >> 1) & 1) == 1) {

        uVar28 = uVar27 + uVar28;

        uVar9 = uVar22 + (uVar28 < uVar27) + (uVar9 & 0xffff);

        if ((int)uVar9 < -0x8000) {

          uVar9 = 0xffff8000;

          uVar28 = 0;

        }

        if (0x7fff < (int)uVar9) {

          uVar9 = 0x7fff;

          uVar28 = 0xffffffff;

        }

        uVar9 = uVar9 & 0xffff;

      }

      else {

        uVar28 = uVar27 + uVar28;

        uVar9 = uVar22 + (uVar28 < uVar27) + uVar9;

      }

      *(unsigned int *)(puVar7 + 0x2c) = (uVar9 << 0x10 | uVar28 >> 0x10) + puVar16[0xb];

      iVar10 = *(int *)(puVar7 + 0x2c);

      *(unsigned short *)(puVar5 + 6) = (unsigned short)(iVar10 <= iVar19);

      iVar10 = (unsigned int)(iVar10 <= iVar19) + (int)*(short *)(puVar5 + 4) +

               (int)*(short *)(puVar5 + 2) + (int)*(short *)puVar5;

      uVar20 = uVar21 | iVar10 == 0;

      if (((unsigned char)uVar20 & 1) != 1) {

        if (iVar10 == 4) {

          uVar9 = 4;

          uVar20 = uVar21;

          goto LAB_0602c416;

        }

        (*(void(*)())(*(int *)(0x0602C450 + iVar10 * 4)))(0x06094EF4,0x06094EEC,puVar16 + 9,puVar16 + 0xc);

        uVar20 = uVar21;

      }

      puVar7 = 0x06094F54;

      puVar6 = 0x0608AC20;

      puVar5 = 0x06094EF4;

      iVar10 = *(int *)0x060620D4;

      puVar12 = (int *)(int)DAT_0602c0f0;

      uVar13 = *(int *)(0x06094EF4 + 8);

      puVar12[4] = (int)DAT_0602c0f2;

      *puVar12 = uVar13;

      puVar12[5] = 0;

      iVar14 = *(int *)(puVar5 + 4);

      iVar11 = puVar12[7];

      *(int *)puVar7 = (int)((unsigned long long)((long long)iVar11 * (long long)*(int *)puVar5) >> 0x20);

      *(int *)(puVar7 + 4) = (int)((unsigned long long)((long long)iVar11 * (long long)-iVar14) >> 0x20);

      puVar8 = 0x06094EE4;

      iVar11 = *(int *)puVar7;

      iVar14 = *(int *)(puVar7 + 4);

      *(short *)0x06094EE4 = 0;

      uVar20 = uVar20 & 0xfffffffe;

      if (PTR_DAT_0602c0f4 < iVar11) {

        *(short *)puVar8 = 1;

      }

      else if (iVar11 < DAT_0602c120) {

        *(short *)puVar8 = 1;

      }

      else if (DAT_0602c12e < iVar14) {

        *(short *)puVar8 = 1;

      }

      else if (iVar14 < DAT_0602c176) {

        *(short *)puVar8 = 1;

      }

      puVar12 = (int *)(int)DAT_0602c178;

      uVar13 = *(int *)(puVar5 + 0x14);

      puVar12[4] = (int)DAT_0602c17a;

      *puVar12 = uVar13;

      puVar12[5] = 0;

      iVar14 = *(int *)(puVar5 + 0x10);

      iVar11 = puVar12[7];

      *(int *)(puVar7 + 8) =

           (int)((unsigned long long)((long long)iVar11 * (long long)*(int *)(puVar5 + 0xc)) >> 0x20);

      *(int *)(puVar7 + 0xc) = (int)((unsigned long long)((long long)iVar11 * (long long)-iVar14) >> 0x20);

      iVar11 = *(int *)(puVar7 + 8);

      iVar14 = *(int *)(puVar7 + 0xc);

      *(short *)(puVar8 + 2) = 0;

      if (DAT_0602c17c < iVar11) {

        *(short *)(puVar8 + 2) = 1;

      }

      else if (iVar11 < DAT_0602c18a) {

        *(short *)(puVar8 + 2) = 1;

      }

      else if (DAT_0602c198 < iVar14) {

        *(short *)(puVar8 + 2) = 1;

      }

      else if (iVar14 < DAT_0602c1e0) {

        *(short *)(puVar8 + 2) = 1;

      }

      puVar12 = (int *)(int)DAT_0602c1e2;

      uVar13 = *(int *)(puVar5 + 0x20);

      puVar12[4] = (int)DAT_0602c1e4;

      *puVar12 = uVar13;

      puVar12[5] = 0;

      iVar14 = *(int *)(puVar5 + 0x1c);

      iVar11 = puVar12[7];

      *(int *)(puVar7 + 0x10) =

           (int)((unsigned long long)((long long)iVar11 * (long long)*(int *)(puVar5 + 0x18)) >> 0x20);

      *(int *)(puVar7 + 0x14) = (int)((unsigned long long)((long long)iVar11 * (long long)-iVar14) >> 0x20);

      iVar11 = *(int *)(puVar7 + 0x10);

      iVar14 = *(int *)(puVar7 + 0x14);

      *(short *)(puVar8 + 4) = 0;

      if (DAT_0602c1e6 < iVar11) {

        *(short *)(puVar8 + 4) = 1;

      }

      else if (iVar11 < DAT_0602c1f4) {

        *(short *)(puVar8 + 4) = 1;

      }

      else if (DAT_0602c202 < iVar14) {

        *(short *)(puVar8 + 4) = 1;

      }

      else if (iVar14 < DAT_0602c24a) {

        *(short *)(puVar8 + 4) = 1;

      }

      puVar12 = (int *)(int)DAT_0602c24c;

      uVar13 = *(int *)(puVar5 + 0x2c);

      puVar12[4] = (int)DAT_0602c24e;

      *puVar12 = uVar13;

      puVar12[5] = 0;

      iVar14 = *(int *)(puVar5 + 0x28);

      iVar11 = puVar12[7];

      *(int *)(puVar7 + 0x18) =

           (int)((unsigned long long)((long long)iVar11 * (long long)*(int *)(puVar5 + 0x24)) >> 0x20);

      *(int *)(puVar7 + 0x1c) = (int)((unsigned long long)((long long)iVar11 * (long long)-iVar14) >> 0x20);

      iVar11 = *(int *)(puVar7 + 0x18);

      iVar14 = *(int *)(puVar7 + 0x1c);

      *(short *)(puVar8 + 6) = 0;

      if (DAT_0602c250 < iVar11) {

        *(short *)(puVar8 + 6) = 1;

      }

      else if (iVar11 < DAT_0602c25e) {

        *(short *)(puVar8 + 6) = 1;

      }

      else if (DAT_0602c26c < iVar14) {

        *(short *)(puVar8 + 6) = 1;

      }

      else if (iVar14 < DAT_0602c29c) {

        *(short *)(puVar8 + 6) = 1;

      }

      if (((((int)0xFFFFFF50 <= *(int *)puVar7) ||

           ((int)0xFFFFFF50 <= *(int *)(puVar7 + 8))) ||

          ((int)0xFFFFFF50 <= *(int *)(puVar7 + 0x10))) ||

         (uVar9 = *(unsigned int *)(puVar7 + 0x18), (int)0xFFFFFF50 <= (int)uVar9)) {

        uVar22 = uVar20 | *(int *)puVar7 < 0x000000B0;

        if (((((unsigned char)uVar22 & 1) != 1) &&

            (uVar22 = uVar20 | *(int *)(puVar7 + 8) < 0x000000B0, ((unsigned char)uVar22 & 1) != 1)) &&

           (uVar22 = uVar20 | *(int *)(puVar7 + 0x10) < 0x000000B0, ((unsigned char)uVar22 & 1) != 1)) {

          uVar9 = *(unsigned int *)(puVar7 + 0x18);

          uVar22 = uVar20 | (int)uVar9 < 0x000000B0;

          uVar20 = uVar22;

          if (((unsigned char)uVar22 & 1) != 1) goto LAB_0602c416;

        }

        uVar22 = uVar22 & 0xfffffffe;

        if ((((int)0xFFFFFF81 <= *(int *)(puVar7 + 4)) ||

            ((int)0xFFFFFF81 <= *(int *)(puVar7 + 0xc))) ||

           (((int)0xFFFFFF81 <= *(int *)(puVar7 + 0x14) ||

            (uVar9 = *(unsigned int *)(puVar7 + 0x1c), uVar20 = uVar22, (int)0xFFFFFF81 <= (int)uVar9)

            ))) {

          uVar20 = uVar22 | *(int *)(puVar7 + 4) < 0x00000051;

          if (((((unsigned char)uVar20 & 1) != 1) &&

              (uVar20 = uVar22 | *(int *)(puVar7 + 0xc) < 0x00000051, ((unsigned char)uVar20 & 1) != 1)) &&

             (uVar20 = uVar22 | *(int *)(puVar7 + 0x14) < 0x00000051, ((unsigned char)uVar20 & 1) != 1)) {

            uVar9 = *(unsigned int *)(puVar7 + 0x1c);

            uVar20 = uVar22 | (int)uVar9 < 0x00000051;

            if (((unsigned char)uVar20 & 1) != 1) goto LAB_0602c416;

          }

          iVar11 = (int)*(short *)(puVar8 + 6) +

                   (int)*(short *)puVar8 + (int)*(short *)(puVar8 + 2) + (int)*(short *)(puVar8 + 4)

          ;

          if (iVar11 != 4) {

            if (iVar11 != 0) {

              (*(void(*)())(*(int *)(0x0602C460 + iVar11 * 4)))(puVar7,puVar8);

            }

            *(short *)(puVar6 + iVar10 * 0x18 + 8) = (short)*(int *)puVar7;

            *(short *)(puVar6 + iVar10 * 0x18 + 10) = (short)*(int *)(puVar7 + 4);

            *(short *)(puVar6 + iVar10 * 0x18 + 0xc) = (short)*(int *)(puVar7 + 8);

            *(short *)(puVar6 + iVar10 * 0x18 + 0xe) = (short)*(int *)(puVar7 + 0xc);

            *(short *)(puVar6 + iVar10 * 0x18 + 0x10) = (short)*(int *)(puVar7 + 0x10);

            *(short *)(puVar6 + iVar10 * 0x18 + 0x12) = (short)*(int *)(puVar7 + 0x14);

            *(short *)(puVar6 + iVar10 * 0x18 + 0x14) = (short)*(int *)(puVar7 + 0x18);

            *(short *)(puVar6 + iVar10 * 0x18 + 0x16) = (short)*(int *)(puVar7 + 0x1c);

            *(short *)(puVar6 + iVar10 * 0x18 + 6) = *(short *)((int)puVar17 + -10);

            puVar6[iVar10 * 0x18 + 4] = (unsigned char)((unsigned int)(int)*(short *)(puVar17 + -3) >> 4) & 0xf;

            puVar6[iVar10 * 0x18 + 5] = param_3;

            uVar20 = (**(void **)(0x0602C470 + ((int)*(short *)(puVar17 + -3) & 7U) * 4))

                               (*(int *)(0x06094EF4 + 0x14),

                                *(int *)(0x06094EF4 + 0x20),

                                *(int *)(0x06094EF4 + 0x2c));

            return uVar20;

          }

          uVar9 = 4;

          uVar20 = uVar20 & 0xfffffffe;

        }

      }

    }

LAB_0602c416:

    param_4 = param_4 + -1;

    in_sr = uVar20 & 0xfffffffe | (unsigned int)(param_4 == 0);

    puVar17 = puVar18;

    if (((unsigned char)in_sr & 1) == 1) {

      return uVar9;

    }

  } while( 1 );

}
