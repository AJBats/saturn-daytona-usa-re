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

unsigned int FUN_0602c380(param_1, param_2, param_3, param_4, param_5)
    int param_1;
    int param_2;
    int param_3;
    int param_4;
    int param_5;
{

  short sVar1;

  short sVar2;

  unsigned int uVar3;

  unsigned int uVar4;

  unsigned int uVar5;

  unsigned int uVar6;

  char *puVar7;

  char *puVar8;

  char *puVar9;

  int iVar10;

  int iVar11;

  unsigned int uVar12;

  int *puVar13;

  int uVar14;

  int iVar15;

  int in_r3;

  char *puVar16;

  short *psVar17;

  unsigned int *puVar18;

  unsigned int *unaff_r8;

  unsigned int *puVar19;

  int unaff_r10;

  char unaff_r13;

  int unaff_r14;

  unsigned int uVar20;

  unsigned int uVar21;

  unsigned int in_sr;

  unsigned int uVar22;

  unsigned int uVar23;

  unsigned int uVar24;

  unsigned int uVar25;

  unsigned int uVar26;

  puVar7 = 0x060620D4;

  puVar16 = (char *)((unsigned int)(in_r3 + param_1 + param_3 + param_2) >> 2);

  if ((int)(0x00020000 + *(int *)0x06094FA4) < *(int *)0x06063F54) {

    puVar16 = puVar16 + (int)0x000A0000;

  }

  iVar11 = *(int *)0x060620D4;

  *(short *)(0x0606A4F8 + iVar11 * 2) = (short)((unsigned int)-(int)puVar16 >> 0xc);

  uVar12 = (iVar11 * 2 >> 1) + 1;

  *(unsigned int *)puVar7 = uVar12;

  uVar21 = in_sr & 0xfffffffe;

LAB_0602c416:

  puVar19 = unaff_r8;

  puVar7 = 0x06094F74;

  param_5 = param_5 + -1;

  uVar20 = uVar21 & 0xfffffffe;

  if (param_5 == 0) {

    return uVar12;

  }

  unaff_r8 = puVar19 + -6;

  psVar17 = (short *)((unsigned int)*(unsigned short *)(puVar19 + -2) * 6 + unaff_r14);

  sVar1 = psVar17[1];

  sVar2 = psVar17[2];

  *(int *)0x06094F74 = (int)*psVar17 << 0xb;

  *(int *)(puVar7 + 4) = (int)sVar1 << 0xb;

  *(int *)(puVar7 + 8) = (int)sVar2 << 0xb;

  puVar16 = 0x06094EF4;

  puVar18 = *(unsigned int **)0x0608A52C;

  uVar22 = *puVar18;

  uVar12 = *(unsigned int *)puVar7;

  uVar6 = uVar22 ^ uVar12;

  if ((int)uVar22 < 0) {

    uVar22 = -uVar22;

  }

  if ((int)uVar12 < 0) {

    uVar12 = -uVar12;

  }

  uVar4 = (uVar12 & 0xffff) * (uVar22 & 0xffff);

  iVar10 = (uVar12 >> 0x10) * (uVar22 & 0xffff);

  iVar11 = 0;

  uVar3 = iVar10 + (uVar12 & 0xffff) * (uVar22 >> 0x10);

  if (iVar10 != 0) {

    iVar11 = 0x10000;

  }

  uVar23 = uVar4 + uVar3 * 0x10000;

  uVar12 = iVar11 + (unsigned int)(uVar23 < uVar4) + (uVar3 >> 0x10) + (uVar12 >> 0x10) * (uVar22 >> 0x10);

  if ((int)-(unsigned int)((int)uVar6 < 0) < 0) {

    uVar12 = ~uVar12;

    if (uVar23 == 0) {

      uVar12 = uVar12 + 1;

    }

    else {

      uVar23 = ~uVar23 + 1;

    }

  }

  if (((unsigned char)(uVar21 >> 1) & 1) == 1) {

    if ((int)uVar12 < -0x8000) {

      uVar12 = 0xffff8000;

      uVar23 = 0;

    }

    if (0x7fff < (int)uVar12) {

      uVar12 = 0x7fff;

      uVar23 = 0xffffffff;

    }

    uVar12 = uVar12 & 0xffff;

  }

  uVar6 = puVar18[1];

  uVar22 = *(unsigned int *)(puVar7 + 4);

  uVar3 = uVar6 ^ uVar22;

  if ((int)uVar6 < 0) {

    uVar6 = -uVar6;

  }

  if ((int)uVar22 < 0) {

    uVar22 = -uVar22;

  }

  uVar26 = (uVar22 & 0xffff) * (uVar6 & 0xffff);

  iVar10 = (uVar22 >> 0x10) * (uVar6 & 0xffff);

  iVar11 = 0;

  uVar4 = iVar10 + (uVar22 & 0xffff) * (uVar6 >> 0x10);

  if (iVar10 != 0) {

    iVar11 = 0x10000;

  }

  uVar24 = uVar26 + uVar4 * 0x10000;

  uVar22 = iVar11 + (unsigned int)(uVar24 < uVar26) + (uVar4 >> 0x10) + (uVar22 >> 0x10) * (uVar6 >> 0x10);

  if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

    uVar22 = ~uVar22;

    if (uVar24 == 0) {

      uVar22 = uVar22 + 1;

    }

    else {

      uVar24 = ~uVar24 + 1;

    }

  }

  if (((unsigned char)(uVar21 >> 1) & 1) == 1) {

    uVar24 = uVar23 + uVar24;

    uVar12 = uVar22 + (uVar24 < uVar23) + (uVar12 & 0xffff);

    if ((int)uVar12 < -0x8000) {

      uVar12 = 0xffff8000;

      uVar24 = 0;

    }

    if (0x7fff < (int)uVar12) {

      uVar12 = 0x7fff;

      uVar24 = 0xffffffff;

    }

    uVar12 = uVar12 & 0xffff;

  }

  else {

    uVar24 = uVar23 + uVar24;

    uVar12 = uVar22 + (uVar24 < uVar23) + uVar12;

  }

  uVar6 = puVar18[2];

  uVar22 = *(unsigned int *)(puVar7 + 8);

  uVar3 = uVar6 ^ uVar22;

  if ((int)uVar6 < 0) {

    uVar6 = -uVar6;

  }

  if ((int)uVar22 < 0) {

    uVar22 = -uVar22;

  }

  uVar23 = (uVar22 & 0xffff) * (uVar6 & 0xffff);

  iVar10 = (uVar22 >> 0x10) * (uVar6 & 0xffff);

  iVar11 = 0;

  uVar4 = iVar10 + (uVar22 & 0xffff) * (uVar6 >> 0x10);

  if (iVar10 != 0) {

    iVar11 = 0x10000;

  }

  uVar26 = uVar23 + uVar4 * 0x10000;

  uVar22 = iVar11 + (unsigned int)(uVar26 < uVar23) + (uVar4 >> 0x10) + (uVar22 >> 0x10) * (uVar6 >> 0x10);

  if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

    uVar22 = ~uVar22;

    if (uVar26 == 0) {

      uVar22 = uVar22 + 1;

    }

    else {

      uVar26 = ~uVar26 + 1;

    }

  }

  if (((unsigned char)(uVar21 >> 1) & 1) == 1) {

    uVar26 = uVar24 + uVar26;

    uVar12 = uVar22 + (uVar26 < uVar24) + (uVar12 & 0xffff);

    if ((int)uVar12 < -0x8000) {

      uVar12 = 0xffff8000;

      uVar26 = 0;

    }

    if (0x7fff < (int)uVar12) {

      uVar12 = 0x7fff;

      uVar26 = 0xffffffff;

    }

    uVar12 = uVar12 & 0xffff;

  }

  else {

    uVar26 = uVar24 + uVar26;

    uVar12 = uVar22 + (uVar26 < uVar24) + uVar12;

  }

  uVar6 = puVar18[3];

  uVar22 = *(unsigned int *)puVar7;

  uVar3 = uVar6 ^ uVar22;

  if ((int)uVar6 < 0) {

    uVar6 = -uVar6;

  }

  if ((int)uVar22 < 0) {

    uVar22 = -uVar22;

  }

  uVar23 = (uVar22 & 0xffff) * (uVar6 & 0xffff);

  iVar10 = (uVar22 >> 0x10) * (uVar6 & 0xffff);

  iVar11 = 0;

  uVar4 = iVar10 + (uVar22 & 0xffff) * (uVar6 >> 0x10);

  if (iVar10 != 0) {

    iVar11 = 0x10000;

  }

  uVar24 = uVar23 + uVar4 * 0x10000;

  uVar22 = iVar11 + (unsigned int)(uVar24 < uVar23) + (uVar4 >> 0x10) + (uVar22 >> 0x10) * (uVar6 >> 0x10);

  if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

    uVar22 = ~uVar22;

    if (uVar24 == 0) {

      uVar22 = uVar22 + 1;

    }

    else {

      uVar24 = ~uVar24 + 1;

    }

  }

  if (((unsigned char)(uVar21 >> 1) & 1) == 1) {

    if ((int)uVar22 < -0x8000) {

      uVar22 = 0xffff8000;

      uVar24 = 0;

    }

    if (0x7fff < (int)uVar22) {

      uVar22 = 0x7fff;

      uVar24 = 0xffffffff;

    }

    uVar22 = uVar22 & 0xffff;

  }

  uVar3 = puVar18[4];

  uVar6 = *(unsigned int *)(puVar7 + 4);

  uVar4 = uVar3 ^ uVar6;

  if ((int)uVar3 < 0) {

    uVar3 = -uVar3;

  }

  if ((int)uVar6 < 0) {

    uVar6 = -uVar6;

  }

  uVar5 = (uVar6 & 0xffff) * (uVar3 & 0xffff);

  iVar10 = (uVar6 >> 0x10) * (uVar3 & 0xffff);

  iVar11 = 0;

  uVar23 = iVar10 + (uVar6 & 0xffff) * (uVar3 >> 0x10);

  if (iVar10 != 0) {

    iVar11 = 0x10000;

  }

  uVar25 = uVar5 + uVar23 * 0x10000;

  uVar6 = iVar11 + (unsigned int)(uVar25 < uVar5) + (uVar23 >> 0x10) + (uVar6 >> 0x10) * (uVar3 >> 0x10);

  if ((int)-(unsigned int)((int)uVar4 < 0) < 0) {

    uVar6 = ~uVar6;

    if (uVar25 == 0) {

      uVar6 = uVar6 + 1;

    }

    else {

      uVar25 = ~uVar25 + 1;

    }

  }

  if (((unsigned char)(uVar21 >> 1) & 1) == 1) {

    uVar25 = uVar24 + uVar25;

    uVar22 = uVar6 + (uVar25 < uVar24) + (uVar22 & 0xffff);

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

    uVar25 = uVar24 + uVar25;

    uVar22 = uVar6 + (uVar25 < uVar24) + uVar22;

  }

  *(unsigned int *)0x06094EF4 = (uVar12 << 0x10 | uVar26 >> 0x10) + puVar18[9];

  uVar6 = puVar18[5];

  uVar12 = *(unsigned int *)(puVar7 + 8);

  uVar3 = uVar6 ^ uVar12;

  if ((int)uVar6 < 0) {

    uVar6 = -uVar6;

  }

  if ((int)uVar12 < 0) {

    uVar12 = -uVar12;

  }

  uVar23 = (uVar12 & 0xffff) * (uVar6 & 0xffff);

  iVar10 = (uVar12 >> 0x10) * (uVar6 & 0xffff);

  iVar11 = 0;

  uVar4 = iVar10 + (uVar12 & 0xffff) * (uVar6 >> 0x10);

  if (iVar10 != 0) {

    iVar11 = 0x10000;

  }

  uVar26 = uVar23 + uVar4 * 0x10000;

  uVar12 = iVar11 + (unsigned int)(uVar26 < uVar23) + (uVar4 >> 0x10) + (uVar12 >> 0x10) * (uVar6 >> 0x10);

  if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

    uVar12 = ~uVar12;

    if (uVar26 == 0) {

      uVar12 = uVar12 + 1;

    }

    else {

      uVar26 = ~uVar26 + 1;

    }

  }

  if (((unsigned char)(uVar21 >> 1) & 1) == 1) {

    uVar26 = uVar25 + uVar26;

    uVar22 = uVar12 + (uVar26 < uVar25) + (uVar22 & 0xffff);

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

  else {

    uVar26 = uVar25 + uVar26;

    uVar22 = uVar12 + (uVar26 < uVar25) + uVar22;

  }

  uVar6 = puVar18[6];

  uVar12 = *(unsigned int *)puVar7;

  uVar3 = uVar6 ^ uVar12;

  if ((int)uVar6 < 0) {

    uVar6 = -uVar6;

  }

  if ((int)uVar12 < 0) {

    uVar12 = -uVar12;

  }

  uVar23 = (uVar12 & 0xffff) * (uVar6 & 0xffff);

  iVar10 = (uVar12 >> 0x10) * (uVar6 & 0xffff);

  iVar11 = 0;

  uVar4 = iVar10 + (uVar12 & 0xffff) * (uVar6 >> 0x10);

  if (iVar10 != 0) {

    iVar11 = 0x10000;

  }

  uVar24 = uVar23 + uVar4 * 0x10000;

  uVar12 = iVar11 + (unsigned int)(uVar24 < uVar23) + (uVar4 >> 0x10) + (uVar12 >> 0x10) * (uVar6 >> 0x10);

  if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

    uVar12 = ~uVar12;

    if (uVar24 == 0) {

      uVar12 = uVar12 + 1;

    }

    else {

      uVar24 = ~uVar24 + 1;

    }

  }

  if (((unsigned char)(uVar21 >> 1) & 1) == 1) {

    if ((int)uVar12 < -0x8000) {

      uVar12 = 0xffff8000;

      uVar24 = 0;

    }

    if (0x7fff < (int)uVar12) {

      uVar12 = 0x7fff;

      uVar24 = 0xffffffff;

    }

    uVar12 = uVar12 & 0xffff;

  }

  uVar3 = puVar18[7];

  uVar6 = *(unsigned int *)(puVar7 + 4);

  uVar4 = uVar3 ^ uVar6;

  if ((int)uVar3 < 0) {

    uVar3 = -uVar3;

  }

  if ((int)uVar6 < 0) {

    uVar6 = -uVar6;

  }

  uVar5 = (uVar6 & 0xffff) * (uVar3 & 0xffff);

  iVar10 = (uVar6 >> 0x10) * (uVar3 & 0xffff);

  iVar11 = 0;

  uVar23 = iVar10 + (uVar6 & 0xffff) * (uVar3 >> 0x10);

  if (iVar10 != 0) {

    iVar11 = 0x10000;

  }

  uVar25 = uVar5 + uVar23 * 0x10000;

  uVar6 = iVar11 + (unsigned int)(uVar25 < uVar5) + (uVar23 >> 0x10) + (uVar6 >> 0x10) * (uVar3 >> 0x10);

  if ((int)-(unsigned int)((int)uVar4 < 0) < 0) {

    uVar6 = ~uVar6;

    if (uVar25 == 0) {

      uVar6 = uVar6 + 1;

    }

    else {

      uVar25 = ~uVar25 + 1;

    }

  }

  if (((unsigned char)(uVar21 >> 1) & 1) == 1) {

    uVar25 = uVar24 + uVar25;

    uVar12 = uVar6 + (uVar25 < uVar24) + (uVar12 & 0xffff);

    if ((int)uVar12 < -0x8000) {

      uVar12 = 0xffff8000;

      uVar25 = 0;

    }

    if (0x7fff < (int)uVar12) {

      uVar12 = 0x7fff;

      uVar25 = 0xffffffff;

    }

    uVar12 = uVar12 & 0xffff;

  }

  else {

    uVar25 = uVar24 + uVar25;

    uVar12 = uVar6 + (uVar25 < uVar24) + uVar12;

  }

  *(unsigned int *)(puVar16 + 4) = (uVar22 << 0x10 | uVar26 >> 0x10) + puVar18[10];

  uVar6 = puVar18[8];

  uVar22 = *(unsigned int *)(puVar7 + 8);

  uVar3 = uVar6 ^ uVar22;

  if ((int)uVar6 < 0) {

    uVar6 = -uVar6;

  }

  if ((int)uVar22 < 0) {

    uVar22 = -uVar22;

  }

  uVar23 = (uVar22 & 0xffff) * (uVar6 & 0xffff);

  iVar10 = (uVar22 >> 0x10) * (uVar6 & 0xffff);

  iVar11 = 0;

  uVar4 = iVar10 + (uVar22 & 0xffff) * (uVar6 >> 0x10);

  if (iVar10 != 0) {

    iVar11 = 0x10000;

  }

  uVar26 = uVar23 + uVar4 * 0x10000;

  uVar22 = iVar11 + (unsigned int)(uVar26 < uVar23) + (uVar4 >> 0x10) + (uVar22 >> 0x10) * (uVar6 >> 0x10);

  if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

    uVar22 = ~uVar22;

    if (uVar26 == 0) {

      uVar22 = uVar22 + 1;

    }

    else {

      uVar26 = ~uVar26 + 1;

    }

  }

  if (((unsigned char)(uVar21 >> 1) & 1) == 1) {

    uVar26 = uVar25 + uVar26;

    uVar12 = uVar22 + (uVar26 < uVar25) + (uVar12 & 0xffff);

    if ((int)uVar12 < -0x8000) {

      uVar12 = 0xffff8000;

      uVar26 = 0;

    }

    if (0x7fff < (int)uVar12) {

      uVar12 = 0x7fff;

      uVar26 = 0xffffffff;

    }

    uVar12 = uVar12 & 0xffff;

  }

  else {

    uVar26 = uVar25 + uVar26;

    uVar12 = uVar22 + (uVar26 < uVar25) + uVar12;

  }

  *(unsigned int *)(puVar16 + 8) = (uVar12 << 0x10 | uVar26 >> 0x10) + puVar18[0xb];

  puVar7 = 0x06094EEC;

  *(unsigned short *)0x06094EEC = (unsigned short)(*(int *)(puVar16 + 8) <= unaff_r10);

  puVar16 = 0x06094F24;

  if ((puVar19[-3] & 0x80000) == 0) goto code_r0x0602be7a;

  goto LAB_0602bee8;

code_r0x0602be7a:

  puVar18 = *(unsigned int **)0x0608A52C;

  uVar22 = *puVar18;

  uVar12 = *unaff_r8;

  uVar6 = uVar22 ^ uVar12;

  if ((int)uVar22 < 0) {

    uVar22 = -uVar22;

  }

  if ((int)uVar12 < 0) {

    uVar12 = -uVar12;

  }

  uVar4 = (uVar12 & 0xffff) * (uVar22 & 0xffff);

  iVar10 = (uVar12 >> 0x10) * (uVar22 & 0xffff);

  iVar11 = 0;

  uVar3 = iVar10 + (uVar12 & 0xffff) * (uVar22 >> 0x10);

  if (iVar10 != 0) {

    iVar11 = 0x10000;

  }

  uVar23 = uVar4 + uVar3 * 0x10000;

  uVar12 = iVar11 + (unsigned int)(uVar23 < uVar4) + (uVar3 >> 0x10) + (uVar12 >> 0x10) * (uVar22 >> 0x10);

  if ((int)-(unsigned int)((int)uVar6 < 0) < 0) {

    uVar12 = ~uVar12;

    if (uVar23 == 0) {

      uVar12 = uVar12 + 1;

    }

    else {

      uVar23 = ~uVar23 + 1;

    }

  }

  if (((unsigned char)(uVar21 >> 1) & 1) == 1) {

    if ((int)uVar12 < -0x8000) {

      uVar12 = 0xffff8000;

      uVar23 = 0;

    }

    if (0x7fff < (int)uVar12) {

      uVar12 = 0x7fff;

      uVar23 = 0xffffffff;

    }

    uVar12 = uVar12 & 0xffff;

  }

  uVar6 = puVar18[1];

  uVar22 = puVar19[-5];

  uVar3 = uVar6 ^ uVar22;

  if ((int)uVar6 < 0) {

    uVar6 = -uVar6;

  }

  if ((int)uVar22 < 0) {

    uVar22 = -uVar22;

  }

  uVar26 = (uVar22 & 0xffff) * (uVar6 & 0xffff);

  iVar10 = (uVar22 >> 0x10) * (uVar6 & 0xffff);

  iVar11 = 0;

  uVar4 = iVar10 + (uVar22 & 0xffff) * (uVar6 >> 0x10);

  if (iVar10 != 0) {

    iVar11 = 0x10000;

  }

  uVar24 = uVar26 + uVar4 * 0x10000;

  uVar22 = iVar11 + (unsigned int)(uVar24 < uVar26) + (uVar4 >> 0x10) + (uVar22 >> 0x10) * (uVar6 >> 0x10);

  if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

    uVar22 = ~uVar22;

    if (uVar24 == 0) {

      uVar22 = uVar22 + 1;

    }

    else {

      uVar24 = ~uVar24 + 1;

    }

  }

  if (((unsigned char)(uVar21 >> 1) & 1) == 1) {

    uVar24 = uVar23 + uVar24;

    uVar12 = uVar22 + (uVar24 < uVar23) + (uVar12 & 0xffff);

    if ((int)uVar12 < -0x8000) {

      uVar12 = 0xffff8000;

      uVar24 = 0;

    }

    if (0x7fff < (int)uVar12) {

      uVar12 = 0x7fff;

      uVar24 = 0xffffffff;

    }

    uVar12 = uVar12 & 0xffff;

  }

  else {

    uVar24 = uVar23 + uVar24;

    uVar12 = uVar22 + (uVar24 < uVar23) + uVar12;

  }

  uVar6 = puVar18[2];

  uVar22 = puVar19[-4];

  uVar3 = uVar6 ^ uVar22;

  if ((int)uVar6 < 0) {

    uVar6 = -uVar6;

  }

  if ((int)uVar22 < 0) {

    uVar22 = -uVar22;

  }

  uVar23 = (uVar22 & 0xffff) * (uVar6 & 0xffff);

  iVar10 = (uVar22 >> 0x10) * (uVar6 & 0xffff);

  iVar11 = 0;

  uVar4 = iVar10 + (uVar22 & 0xffff) * (uVar6 >> 0x10);

  if (iVar10 != 0) {

    iVar11 = 0x10000;

  }

  uVar26 = uVar23 + uVar4 * 0x10000;

  uVar22 = iVar11 + (unsigned int)(uVar26 < uVar23) + (uVar4 >> 0x10) + (uVar22 >> 0x10) * (uVar6 >> 0x10);

  if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

    uVar22 = ~uVar22;

    if (uVar26 == 0) {

      uVar22 = uVar22 + 1;

    }

    else {

      uVar26 = ~uVar26 + 1;

    }

  }

  if (((unsigned char)(uVar21 >> 1) & 1) == 1) {

    uVar26 = uVar24 + uVar26;

    uVar12 = uVar22 + (uVar26 < uVar24) + (uVar12 & 0xffff);

    if ((int)uVar12 < -0x8000) {

      uVar12 = 0xffff8000;

      uVar26 = 0;

    }

    if (0x7fff < (int)uVar12) {

      uVar12 = 0x7fff;

      uVar26 = 0xffffffff;

    }

    uVar12 = uVar12 & 0xffff;

  }

  else {

    uVar26 = uVar24 + uVar26;

    uVar12 = uVar22 + (uVar26 < uVar24) + uVar12;

  }

  uVar6 = puVar18[3];

  uVar22 = *unaff_r8;

  uVar3 = uVar6 ^ uVar22;

  if ((int)uVar6 < 0) {

    uVar6 = -uVar6;

  }

  if ((int)uVar22 < 0) {

    uVar22 = -uVar22;

  }

  uVar23 = (uVar22 & 0xffff) * (uVar6 & 0xffff);

  iVar10 = (uVar22 >> 0x10) * (uVar6 & 0xffff);

  iVar11 = 0;

  uVar4 = iVar10 + (uVar22 & 0xffff) * (uVar6 >> 0x10);

  if (iVar10 != 0) {

    iVar11 = 0x10000;

  }

  uVar24 = uVar23 + uVar4 * 0x10000;

  uVar22 = iVar11 + (unsigned int)(uVar24 < uVar23) + (uVar4 >> 0x10) + (uVar22 >> 0x10) * (uVar6 >> 0x10);

  if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

    uVar22 = ~uVar22;

    if (uVar24 == 0) {

      uVar22 = uVar22 + 1;

    }

    else {

      uVar24 = ~uVar24 + 1;

    }

  }

  if (((unsigned char)(uVar21 >> 1) & 1) == 1) {

    if ((int)uVar22 < -0x8000) {

      uVar22 = 0xffff8000;

      uVar24 = 0;

    }

    if (0x7fff < (int)uVar22) {

      uVar22 = 0x7fff;

      uVar24 = 0xffffffff;

    }

    uVar22 = uVar22 & 0xffff;

  }

  *(unsigned int *)0x06094F24 = uVar12 << 0x10 | uVar26 >> 0x10;

  uVar6 = puVar18[4];

  uVar12 = puVar19[-5];

  uVar3 = uVar6 ^ uVar12;

  if ((int)uVar6 < 0) {

    uVar6 = -uVar6;

  }

  if ((int)uVar12 < 0) {

    uVar12 = -uVar12;

  }

  uVar23 = (uVar12 & 0xffff) * (uVar6 & 0xffff);

  iVar10 = (uVar12 >> 0x10) * (uVar6 & 0xffff);

  iVar11 = 0;

  uVar4 = iVar10 + (uVar12 & 0xffff) * (uVar6 >> 0x10);

  if (iVar10 != 0) {

    iVar11 = 0x10000;

  }

  uVar26 = uVar23 + uVar4 * 0x10000;

  uVar12 = iVar11 + (unsigned int)(uVar26 < uVar23) + (uVar4 >> 0x10) + (uVar12 >> 0x10) * (uVar6 >> 0x10);

  if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

    uVar12 = ~uVar12;

    if (uVar26 == 0) {

      uVar12 = uVar12 + 1;

    }

    else {

      uVar26 = ~uVar26 + 1;

    }

  }

  if (((unsigned char)(uVar21 >> 1) & 1) == 1) {

    uVar26 = uVar24 + uVar26;

    uVar22 = uVar12 + (uVar26 < uVar24) + (uVar22 & 0xffff);

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

  else {

    uVar26 = uVar24 + uVar26;

    uVar22 = uVar12 + (uVar26 < uVar24) + uVar22;

  }

  uVar6 = puVar18[5];

  uVar12 = puVar19[-4];

  uVar3 = uVar6 ^ uVar12;

  if ((int)uVar6 < 0) {

    uVar6 = -uVar6;

  }

  if ((int)uVar12 < 0) {

    uVar12 = -uVar12;

  }

  uVar23 = (uVar12 & 0xffff) * (uVar6 & 0xffff);

  iVar10 = (uVar12 >> 0x10) * (uVar6 & 0xffff);

  iVar11 = 0;

  uVar4 = iVar10 + (uVar12 & 0xffff) * (uVar6 >> 0x10);

  if (iVar10 != 0) {

    iVar11 = 0x10000;

  }

  uVar24 = uVar23 + uVar4 * 0x10000;

  uVar12 = iVar11 + (unsigned int)(uVar24 < uVar23) + (uVar4 >> 0x10) + (uVar12 >> 0x10) * (uVar6 >> 0x10);

  if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

    uVar12 = ~uVar12;

    if (uVar24 == 0) {

      uVar12 = uVar12 + 1;

    }

    else {

      uVar24 = ~uVar24 + 1;

    }

  }

  if (((unsigned char)(uVar21 >> 1) & 1) == 1) {

    uVar24 = uVar26 + uVar24;

    uVar22 = uVar12 + (uVar24 < uVar26) + (uVar22 & 0xffff);

    if ((int)uVar22 < -0x8000) {

      uVar22 = 0xffff8000;

      uVar24 = 0;

    }

    if (0x7fff < (int)uVar22) {

      uVar22 = 0x7fff;

      uVar24 = 0xffffffff;

    }

    uVar22 = uVar22 & 0xffff;

  }

  else {

    uVar24 = uVar26 + uVar24;

    uVar22 = uVar12 + (uVar24 < uVar26) + uVar22;

  }

  uVar6 = puVar18[6];

  uVar12 = *unaff_r8;

  uVar3 = uVar6 ^ uVar12;

  if ((int)uVar6 < 0) {

    uVar6 = -uVar6;

  }

  if ((int)uVar12 < 0) {

    uVar12 = -uVar12;

  }

  uVar23 = (uVar12 & 0xffff) * (uVar6 & 0xffff);

  iVar10 = (uVar12 >> 0x10) * (uVar6 & 0xffff);

  iVar11 = 0;

  uVar4 = iVar10 + (uVar12 & 0xffff) * (uVar6 >> 0x10);

  if (iVar10 != 0) {

    iVar11 = 0x10000;

  }

  uVar26 = uVar23 + uVar4 * 0x10000;

  uVar12 = iVar11 + (unsigned int)(uVar26 < uVar23) + (uVar4 >> 0x10) + (uVar12 >> 0x10) * (uVar6 >> 0x10);

  if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

    uVar12 = ~uVar12;

    if (uVar26 == 0) {

      uVar12 = uVar12 + 1;

    }

    else {

      uVar26 = ~uVar26 + 1;

    }

  }

  if (((unsigned char)(uVar21 >> 1) & 1) == 1) {

    if ((int)uVar12 < -0x8000) {

      uVar12 = 0xffff8000;

      uVar26 = 0;

    }

    if (0x7fff < (int)uVar12) {

      uVar12 = 0x7fff;

      uVar26 = 0xffffffff;

    }

    uVar12 = uVar12 & 0xffff;

  }

  *(unsigned int *)(puVar16 + 4) = uVar22 << 0x10 | uVar24 >> 0x10;

  uVar6 = puVar18[7];

  uVar22 = puVar19[-5];

  uVar3 = uVar6 ^ uVar22;

  if ((int)uVar6 < 0) {

    uVar6 = -uVar6;

  }

  if ((int)uVar22 < 0) {

    uVar22 = -uVar22;

  }

  uVar23 = (uVar22 & 0xffff) * (uVar6 & 0xffff);

  iVar10 = (uVar22 >> 0x10) * (uVar6 & 0xffff);

  iVar11 = 0;

  uVar4 = iVar10 + (uVar22 & 0xffff) * (uVar6 >> 0x10);

  if (iVar10 != 0) {

    iVar11 = 0x10000;

  }

  uVar24 = uVar23 + uVar4 * 0x10000;

  uVar22 = iVar11 + (unsigned int)(uVar24 < uVar23) + (uVar4 >> 0x10) + (uVar22 >> 0x10) * (uVar6 >> 0x10);

  if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

    uVar22 = ~uVar22;

    if (uVar24 == 0) {

      uVar22 = uVar22 + 1;

    }

    else {

      uVar24 = ~uVar24 + 1;

    }

  }

  if (((unsigned char)(uVar21 >> 1) & 1) == 1) {

    uVar24 = uVar26 + uVar24;

    uVar12 = uVar22 + (uVar24 < uVar26) + (uVar12 & 0xffff);

    if ((int)uVar12 < -0x8000) {

      uVar12 = 0xffff8000;

      uVar24 = 0;

    }

    if (0x7fff < (int)uVar12) {

      uVar12 = 0x7fff;

      uVar24 = 0xffffffff;

    }

    uVar12 = uVar12 & 0xffff;

  }

  else {

    uVar24 = uVar26 + uVar24;

    uVar12 = uVar22 + (uVar24 < uVar26) + uVar12;

  }

  uVar6 = puVar18[8];

  uVar22 = puVar19[-4];

  uVar3 = uVar6 ^ uVar22;

  if ((int)uVar6 < 0) {

    uVar6 = -uVar6;

  }

  if ((int)uVar22 < 0) {

    uVar22 = -uVar22;

  }

  uVar23 = (uVar22 & 0xffff) * (uVar6 & 0xffff);

  iVar10 = (uVar22 >> 0x10) * (uVar6 & 0xffff);

  iVar11 = 0;

  uVar4 = iVar10 + (uVar22 & 0xffff) * (uVar6 >> 0x10);

  if (iVar10 != 0) {

    iVar11 = 0x10000;

  }

  uVar26 = uVar23 + uVar4 * 0x10000;

  uVar22 = iVar11 + (unsigned int)(uVar26 < uVar23) + (uVar4 >> 0x10) + (uVar22 >> 0x10) * (uVar6 >> 0x10);

  if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

    uVar22 = ~uVar22;

    if (uVar26 == 0) {

      uVar22 = uVar22 + 1;

    }

    else {

      uVar26 = ~uVar26 + 1;

    }

  }

  if (((unsigned char)(uVar21 >> 1) & 1) == 1) {

    uVar26 = uVar24 + uVar26;

    uVar12 = uVar22 + (uVar26 < uVar24) + (uVar12 & 0xffff);

    if ((int)uVar12 < -0x8000) {

      uVar12 = 0xffff8000;

      uVar26 = 0;

    }

    if (0x7fff < (int)uVar12) {

      uVar12 = 0x7fff;

      uVar26 = 0xffffffff;

    }

    uVar12 = uVar12 & 0xffff;

  }

  else {

    uVar26 = uVar24 + uVar26;

    uVar12 = uVar22 + (uVar26 < uVar24) + uVar12;

  }

  *(unsigned int *)(puVar16 + 8) = uVar12 << 0x10 | uVar26 >> 0x10;

  uVar22 = *(unsigned int *)puVar16;

  uVar12 = *(unsigned int *)0x06094EF4;

  uVar6 = uVar22 ^ uVar12;

  if ((int)uVar22 < 0) {

    uVar22 = -uVar22;

  }

  if ((int)uVar12 < 0) {

    uVar12 = -uVar12;

  }

  uVar4 = (uVar12 & 0xffff) * (uVar22 & 0xffff);

  iVar10 = (uVar12 >> 0x10) * (uVar22 & 0xffff);

  iVar11 = 0;

  uVar3 = iVar10 + (uVar12 & 0xffff) * (uVar22 >> 0x10);

  if (iVar10 != 0) {

    iVar11 = 0x10000;

  }

  uVar23 = uVar4 + uVar3 * 0x10000;

  uVar12 = iVar11 + (unsigned int)(uVar23 < uVar4) + (uVar3 >> 0x10) + (uVar12 >> 0x10) * (uVar22 >> 0x10);

  if ((int)-(unsigned int)((int)uVar6 < 0) < 0) {

    uVar12 = ~uVar12;

    if (uVar23 == 0) {

      uVar12 = uVar12 + 1;

    }

    else {

      uVar23 = ~uVar23 + 1;

    }

  }

  if (((unsigned char)(uVar21 >> 1) & 1) == 1) {

    if ((int)uVar12 < -0x8000) {

      uVar12 = 0xffff8000;

      uVar23 = 0;

    }

    if (0x7fff < (int)uVar12) {

      uVar12 = 0x7fff;

      uVar23 = 0xffffffff;

    }

    uVar12 = uVar12 & 0xffff;

  }

  uVar6 = *(unsigned int *)(puVar16 + 4);

  uVar22 = *(unsigned int *)(0x06094EF4 + 4);

  uVar3 = uVar6 ^ uVar22;

  if ((int)uVar6 < 0) {

    uVar6 = -uVar6;

  }

  if ((int)uVar22 < 0) {

    uVar22 = -uVar22;

  }

  uVar26 = (uVar22 & 0xffff) * (uVar6 & 0xffff);

  iVar10 = (uVar22 >> 0x10) * (uVar6 & 0xffff);

  iVar11 = 0;

  uVar4 = iVar10 + (uVar22 & 0xffff) * (uVar6 >> 0x10);

  if (iVar10 != 0) {

    iVar11 = 0x10000;

  }

  uVar24 = uVar26 + uVar4 * 0x10000;

  uVar22 = iVar11 + (unsigned int)(uVar24 < uVar26) + (uVar4 >> 0x10) + (uVar22 >> 0x10) * (uVar6 >> 0x10);

  if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

    uVar22 = ~uVar22;

    if (uVar24 == 0) {

      uVar22 = uVar22 + 1;

    }

    else {

      uVar24 = ~uVar24 + 1;

    }

  }

  if (((unsigned char)(uVar21 >> 1) & 1) == 1) {

    uVar24 = uVar23 + uVar24;

    uVar12 = uVar22 + (uVar24 < uVar23) + (uVar12 & 0xffff);

    if ((int)uVar12 < -0x8000) {

      uVar12 = 0xffff8000;

      uVar24 = 0;

    }

    if (0x7fff < (int)uVar12) {

      uVar12 = 0x7fff;

      uVar24 = 0xffffffff;

    }

    uVar12 = uVar12 & 0xffff;

  }

  else {

    uVar24 = uVar23 + uVar24;

    uVar12 = uVar22 + (uVar24 < uVar23) + uVar12;

  }

  uVar6 = *(unsigned int *)(puVar16 + 8);

  uVar22 = *(unsigned int *)(0x06094EF4 + 8);

  uVar3 = uVar6 ^ uVar22;

  if ((int)uVar6 < 0) {

    uVar6 = -uVar6;

  }

  if ((int)uVar22 < 0) {

    uVar22 = -uVar22;

  }

  uVar23 = (uVar22 & 0xffff) * (uVar6 & 0xffff);

  iVar10 = (uVar22 >> 0x10) * (uVar6 & 0xffff);

  iVar11 = 0;

  uVar4 = iVar10 + (uVar22 & 0xffff) * (uVar6 >> 0x10);

  if (iVar10 != 0) {

    iVar11 = 0x10000;

  }

  uVar26 = uVar23 + uVar4 * 0x10000;

  uVar22 = iVar11 + (unsigned int)(uVar26 < uVar23) + (uVar4 >> 0x10) + (uVar22 >> 0x10) * (uVar6 >> 0x10);

  if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

    uVar22 = ~uVar22;

    if (uVar26 == 0) {

      uVar22 = uVar22 + 1;

    }

    else {

      uVar26 = ~uVar26 + 1;

    }

  }

  if (((unsigned char)(uVar21 >> 1) & 1) == 1) {

    uVar26 = uVar24 + uVar26;

    uVar12 = uVar22 + (uVar26 < uVar24) + (uVar12 & 0xffff);

    if ((int)uVar12 < -0x8000) {

      uVar12 = 0xffff8000;

      uVar26 = 0;

    }

    if (0x7fff < (int)uVar12) {

      uVar12 = 0x7fff;

      uVar26 = 0xffffffff;

    }

    uVar12 = uVar12 & 0xffff;

  }

  else {

    uVar26 = uVar24 + uVar26;

    uVar12 = uVar22 + (uVar26 < uVar24) + uVar12;

  }

  uVar12 = uVar12 << 0x10 | uVar26 >> 0x10;

  uVar20 = uVar20 | 0 < (int)uVar12;

  uVar21 = uVar20;

  if (((unsigned char)uVar20 & 1) == 1) {

LAB_0602bee8:

    puVar16 = 0x06094F74;

    psVar17 = (short *)((unsigned int)*(unsigned short *)((int)puVar19 + -6) * 6 + unaff_r14);

    sVar1 = psVar17[1];

    sVar2 = psVar17[2];

    uVar21 = uVar20 & 0xfffffffe;

    *(int *)0x06094F74 = (int)*psVar17 << 0xb;

    *(int *)(puVar16 + 4) = (int)sVar1 << 0xb;

    *(int *)(puVar16 + 8) = (int)sVar2 << 0xb;

    puVar8 = 0x06094EF4;

    puVar18 = *(unsigned int **)0x0608A52C;

    uVar22 = *puVar18;

    uVar12 = *(unsigned int *)puVar16;

    uVar6 = uVar22 ^ uVar12;

    if ((int)uVar22 < 0) {

      uVar22 = -uVar22;

    }

    if ((int)uVar12 < 0) {

      uVar12 = -uVar12;

    }

    uVar4 = (uVar12 & 0xffff) * (uVar22 & 0xffff);

    iVar10 = (uVar12 >> 0x10) * (uVar22 & 0xffff);

    iVar11 = 0;

    uVar3 = iVar10 + (uVar12 & 0xffff) * (uVar22 >> 0x10);

    if (iVar10 != 0) {

      iVar11 = 0x10000;

    }

    uVar23 = uVar4 + uVar3 * 0x10000;

    uVar12 = iVar11 + (unsigned int)(uVar23 < uVar4) + (uVar3 >> 0x10) + (uVar12 >> 0x10) * (uVar22 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar6 < 0) < 0) {

      uVar12 = ~uVar12;

      if (uVar23 == 0) {

        uVar12 = uVar12 + 1;

      }

      else {

        uVar23 = ~uVar23 + 1;

      }

    }

    if (((unsigned char)(uVar20 >> 1) & 1) == 1) {

      if ((int)uVar12 < -0x8000) {

        uVar12 = 0xffff8000;

        uVar23 = 0;

      }

      if (0x7fff < (int)uVar12) {

        uVar12 = 0x7fff;

        uVar23 = 0xffffffff;

      }

      uVar12 = uVar12 & 0xffff;

    }

    uVar6 = puVar18[1];

    uVar22 = *(unsigned int *)(puVar16 + 4);

    uVar3 = uVar6 ^ uVar22;

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    if ((int)uVar22 < 0) {

      uVar22 = -uVar22;

    }

    uVar26 = (uVar22 & 0xffff) * (uVar6 & 0xffff);

    iVar10 = (uVar22 >> 0x10) * (uVar6 & 0xffff);

    iVar11 = 0;

    uVar4 = iVar10 + (uVar22 & 0xffff) * (uVar6 >> 0x10);

    if (iVar10 != 0) {

      iVar11 = 0x10000;

    }

    uVar24 = uVar26 + uVar4 * 0x10000;

    uVar22 = iVar11 + (unsigned int)(uVar24 < uVar26) + (uVar4 >> 0x10) + (uVar22 >> 0x10) * (uVar6 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

      uVar22 = ~uVar22;

      if (uVar24 == 0) {

        uVar22 = uVar22 + 1;

      }

      else {

        uVar24 = ~uVar24 + 1;

      }

    }

    if (((unsigned char)(uVar20 >> 1) & 1) == 1) {

      uVar24 = uVar23 + uVar24;

      uVar12 = uVar22 + (uVar24 < uVar23) + (uVar12 & 0xffff);

      if ((int)uVar12 < -0x8000) {

        uVar12 = 0xffff8000;

        uVar24 = 0;

      }

      if (0x7fff < (int)uVar12) {

        uVar12 = 0x7fff;

        uVar24 = 0xffffffff;

      }

      uVar12 = uVar12 & 0xffff;

    }

    else {

      uVar24 = uVar23 + uVar24;

      uVar12 = uVar22 + (uVar24 < uVar23) + uVar12;

    }

    uVar6 = puVar18[2];

    uVar22 = *(unsigned int *)(puVar16 + 8);

    uVar3 = uVar6 ^ uVar22;

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    if ((int)uVar22 < 0) {

      uVar22 = -uVar22;

    }

    uVar23 = (uVar22 & 0xffff) * (uVar6 & 0xffff);

    iVar10 = (uVar22 >> 0x10) * (uVar6 & 0xffff);

    iVar11 = 0;

    uVar4 = iVar10 + (uVar22 & 0xffff) * (uVar6 >> 0x10);

    if (iVar10 != 0) {

      iVar11 = 0x10000;

    }

    uVar26 = uVar23 + uVar4 * 0x10000;

    uVar22 = iVar11 + (unsigned int)(uVar26 < uVar23) + (uVar4 >> 0x10) + (uVar22 >> 0x10) * (uVar6 >> 0x10)

    ;

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

      uVar26 = uVar24 + uVar26;

      uVar12 = uVar22 + (uVar26 < uVar24) + (uVar12 & 0xffff);

      if ((int)uVar12 < -0x8000) {

        uVar12 = 0xffff8000;

        uVar26 = 0;

      }

      if (0x7fff < (int)uVar12) {

        uVar12 = 0x7fff;

        uVar26 = 0xffffffff;

      }

      uVar12 = uVar12 & 0xffff;

    }

    else {

      uVar26 = uVar24 + uVar26;

      uVar12 = uVar22 + (uVar26 < uVar24) + uVar12;

    }

    uVar6 = puVar18[3];

    uVar22 = *(unsigned int *)puVar16;

    uVar3 = uVar6 ^ uVar22;

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    if ((int)uVar22 < 0) {

      uVar22 = -uVar22;

    }

    uVar23 = (uVar22 & 0xffff) * (uVar6 & 0xffff);

    iVar10 = (uVar22 >> 0x10) * (uVar6 & 0xffff);

    iVar11 = 0;

    uVar4 = iVar10 + (uVar22 & 0xffff) * (uVar6 >> 0x10);

    if (iVar10 != 0) {

      iVar11 = 0x10000;

    }

    uVar24 = uVar23 + uVar4 * 0x10000;

    uVar22 = iVar11 + (unsigned int)(uVar24 < uVar23) + (uVar4 >> 0x10) + (uVar22 >> 0x10) * (uVar6 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

      uVar22 = ~uVar22;

      if (uVar24 == 0) {

        uVar22 = uVar22 + 1;

      }

      else {

        uVar24 = ~uVar24 + 1;

      }

    }

    if (((unsigned char)(uVar20 >> 1) & 1) == 1) {

      if ((int)uVar22 < -0x8000) {

        uVar22 = 0xffff8000;

        uVar24 = 0;

      }

      if (0x7fff < (int)uVar22) {

        uVar22 = 0x7fff;

        uVar24 = 0xffffffff;

      }

      uVar22 = uVar22 & 0xffff;

    }

    uVar3 = puVar18[4];

    uVar6 = *(unsigned int *)(puVar16 + 4);

    uVar4 = uVar3 ^ uVar6;

    if ((int)uVar3 < 0) {

      uVar3 = -uVar3;

    }

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    uVar5 = (uVar6 & 0xffff) * (uVar3 & 0xffff);

    iVar10 = (uVar6 >> 0x10) * (uVar3 & 0xffff);

    iVar11 = 0;

    uVar23 = iVar10 + (uVar6 & 0xffff) * (uVar3 >> 0x10);

    if (iVar10 != 0) {

      iVar11 = 0x10000;

    }

    uVar25 = uVar5 + uVar23 * 0x10000;

    uVar6 = iVar11 + (unsigned int)(uVar25 < uVar5) + (uVar23 >> 0x10) + (uVar6 >> 0x10) * (uVar3 >> 0x10);

    if ((int)-(unsigned int)((int)uVar4 < 0) < 0) {

      uVar6 = ~uVar6;

      if (uVar25 == 0) {

        uVar6 = uVar6 + 1;

      }

      else {

        uVar25 = ~uVar25 + 1;

      }

    }

    if (((unsigned char)(uVar20 >> 1) & 1) == 1) {

      uVar25 = uVar24 + uVar25;

      uVar22 = uVar6 + (uVar25 < uVar24) + (uVar22 & 0xffff);

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

      uVar25 = uVar24 + uVar25;

      uVar22 = uVar6 + (uVar25 < uVar24) + uVar22;

    }

    *(unsigned int *)(0x06094EF4 + 0xc) = (uVar12 << 0x10 | uVar26 >> 0x10) + puVar18[9];

    uVar6 = puVar18[5];

    uVar12 = *(unsigned int *)(puVar16 + 8);

    uVar3 = uVar6 ^ uVar12;

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    if ((int)uVar12 < 0) {

      uVar12 = -uVar12;

    }

    uVar23 = (uVar12 & 0xffff) * (uVar6 & 0xffff);

    iVar10 = (uVar12 >> 0x10) * (uVar6 & 0xffff);

    iVar11 = 0;

    uVar4 = iVar10 + (uVar12 & 0xffff) * (uVar6 >> 0x10);

    if (iVar10 != 0) {

      iVar11 = 0x10000;

    }

    uVar26 = uVar23 + uVar4 * 0x10000;

    uVar12 = iVar11 + (unsigned int)(uVar26 < uVar23) + (uVar4 >> 0x10) + (uVar12 >> 0x10) * (uVar6 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

      uVar12 = ~uVar12;

      if (uVar26 == 0) {

        uVar12 = uVar12 + 1;

      }

      else {

        uVar26 = ~uVar26 + 1;

      }

    }

    if (((unsigned char)(uVar20 >> 1) & 1) == 1) {

      uVar26 = uVar25 + uVar26;

      uVar22 = uVar12 + (uVar26 < uVar25) + (uVar22 & 0xffff);

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

    else {

      uVar26 = uVar25 + uVar26;

      uVar22 = uVar12 + (uVar26 < uVar25) + uVar22;

    }

    uVar6 = puVar18[6];

    uVar12 = *(unsigned int *)puVar16;

    uVar3 = uVar6 ^ uVar12;

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    if ((int)uVar12 < 0) {

      uVar12 = -uVar12;

    }

    uVar23 = (uVar12 & 0xffff) * (uVar6 & 0xffff);

    iVar10 = (uVar12 >> 0x10) * (uVar6 & 0xffff);

    iVar11 = 0;

    uVar4 = iVar10 + (uVar12 & 0xffff) * (uVar6 >> 0x10);

    if (iVar10 != 0) {

      iVar11 = 0x10000;

    }

    uVar24 = uVar23 + uVar4 * 0x10000;

    uVar12 = iVar11 + (unsigned int)(uVar24 < uVar23) + (uVar4 >> 0x10) + (uVar12 >> 0x10) * (uVar6 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

      uVar12 = ~uVar12;

      if (uVar24 == 0) {

        uVar12 = uVar12 + 1;

      }

      else {

        uVar24 = ~uVar24 + 1;

      }

    }

    if (((unsigned char)(uVar20 >> 1) & 1) == 1) {

      if ((int)uVar12 < -0x8000) {

        uVar12 = 0xffff8000;

        uVar24 = 0;

      }

      if (0x7fff < (int)uVar12) {

        uVar12 = 0x7fff;

        uVar24 = 0xffffffff;

      }

      uVar12 = uVar12 & 0xffff;

    }

    uVar3 = puVar18[7];

    uVar6 = *(unsigned int *)(puVar16 + 4);

    uVar4 = uVar3 ^ uVar6;

    if ((int)uVar3 < 0) {

      uVar3 = -uVar3;

    }

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    uVar5 = (uVar6 & 0xffff) * (uVar3 & 0xffff);

    iVar10 = (uVar6 >> 0x10) * (uVar3 & 0xffff);

    iVar11 = 0;

    uVar23 = iVar10 + (uVar6 & 0xffff) * (uVar3 >> 0x10);

    if (iVar10 != 0) {

      iVar11 = 0x10000;

    }

    uVar25 = uVar5 + uVar23 * 0x10000;

    uVar6 = iVar11 + (unsigned int)(uVar25 < uVar5) + (uVar23 >> 0x10) + (uVar6 >> 0x10) * (uVar3 >> 0x10);

    if ((int)-(unsigned int)((int)uVar4 < 0) < 0) {

      uVar6 = ~uVar6;

      if (uVar25 == 0) {

        uVar6 = uVar6 + 1;

      }

      else {

        uVar25 = ~uVar25 + 1;

      }

    }

    if (((unsigned char)(uVar20 >> 1) & 1) == 1) {

      uVar25 = uVar24 + uVar25;

      uVar12 = uVar6 + (uVar25 < uVar24) + (uVar12 & 0xffff);

      if ((int)uVar12 < -0x8000) {

        uVar12 = 0xffff8000;

        uVar25 = 0;

      }

      if (0x7fff < (int)uVar12) {

        uVar12 = 0x7fff;

        uVar25 = 0xffffffff;

      }

      uVar12 = uVar12 & 0xffff;

    }

    else {

      uVar25 = uVar24 + uVar25;

      uVar12 = uVar6 + (uVar25 < uVar24) + uVar12;

    }

    *(unsigned int *)(puVar8 + 0x10) = (uVar22 << 0x10 | uVar26 >> 0x10) + puVar18[10];

    uVar6 = puVar18[8];

    uVar22 = *(unsigned int *)(puVar16 + 8);

    uVar3 = uVar6 ^ uVar22;

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    if ((int)uVar22 < 0) {

      uVar22 = -uVar22;

    }

    uVar23 = (uVar22 & 0xffff) * (uVar6 & 0xffff);

    iVar10 = (uVar22 >> 0x10) * (uVar6 & 0xffff);

    iVar11 = 0;

    uVar4 = iVar10 + (uVar22 & 0xffff) * (uVar6 >> 0x10);

    if (iVar10 != 0) {

      iVar11 = 0x10000;

    }

    uVar26 = uVar23 + uVar4 * 0x10000;

    uVar22 = iVar11 + (unsigned int)(uVar26 < uVar23) + (uVar4 >> 0x10) + (uVar22 >> 0x10) * (uVar6 >> 0x10)

    ;

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

      uVar12 = uVar22 + (uVar26 < uVar25) + (uVar12 & 0xffff);

      if ((int)uVar12 < -0x8000) {

        uVar12 = 0xffff8000;

        uVar26 = 0;

      }

      if (0x7fff < (int)uVar12) {

        uVar12 = 0x7fff;

        uVar26 = 0xffffffff;

      }

      uVar12 = uVar12 & 0xffff;

    }

    else {

      uVar26 = uVar25 + uVar26;

      uVar12 = uVar22 + (uVar26 < uVar25) + uVar12;

    }

    *(unsigned int *)(puVar8 + 0x14) = (uVar12 << 0x10 | uVar26 >> 0x10) + puVar18[0xb];

    *(unsigned short *)(puVar7 + 2) = (unsigned short)(*(int *)(puVar8 + 0x14) <= unaff_r10);

    puVar16 = 0x06094F74;

    psVar17 = (short *)((unsigned int)*(unsigned short *)(puVar19 + -1) * 6 + unaff_r14);

    sVar1 = psVar17[1];

    sVar2 = psVar17[2];

    *(int *)0x06094F74 = (int)*psVar17 << 0xb;

    *(int *)(puVar16 + 4) = (int)sVar1 << 0xb;

    *(int *)0x06094FA4 = (int)sVar1 << 0xb;

    *(int *)(puVar16 + 8) = (int)sVar2 << 0xb;

    puVar8 = 0x06094EF4;

    puVar18 = *(unsigned int **)0x0608A52C;

    uVar22 = *puVar18;

    uVar12 = *(unsigned int *)puVar16;

    uVar6 = uVar22 ^ uVar12;

    if ((int)uVar22 < 0) {

      uVar22 = -uVar22;

    }

    if ((int)uVar12 < 0) {

      uVar12 = -uVar12;

    }

    uVar4 = (uVar12 & 0xffff) * (uVar22 & 0xffff);

    iVar10 = (uVar12 >> 0x10) * (uVar22 & 0xffff);

    iVar11 = 0;

    uVar3 = iVar10 + (uVar12 & 0xffff) * (uVar22 >> 0x10);

    if (iVar10 != 0) {

      iVar11 = 0x10000;

    }

    uVar23 = uVar4 + uVar3 * 0x10000;

    uVar12 = iVar11 + (unsigned int)(uVar23 < uVar4) + (uVar3 >> 0x10) + (uVar12 >> 0x10) * (uVar22 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar6 < 0) < 0) {

      uVar12 = ~uVar12;

      if (uVar23 == 0) {

        uVar12 = uVar12 + 1;

      }

      else {

        uVar23 = ~uVar23 + 1;

      }

    }

    if (((unsigned char)(uVar20 >> 1) & 1) == 1) {

      if ((int)uVar12 < -0x8000) {

        uVar12 = 0xffff8000;

        uVar23 = 0;

      }

      if (0x7fff < (int)uVar12) {

        uVar12 = 0x7fff;

        uVar23 = 0xffffffff;

      }

      uVar12 = uVar12 & 0xffff;

    }

    uVar6 = puVar18[1];

    uVar22 = *(unsigned int *)(puVar16 + 4);

    uVar3 = uVar6 ^ uVar22;

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    if ((int)uVar22 < 0) {

      uVar22 = -uVar22;

    }

    uVar26 = (uVar22 & 0xffff) * (uVar6 & 0xffff);

    iVar10 = (uVar22 >> 0x10) * (uVar6 & 0xffff);

    iVar11 = 0;

    uVar4 = iVar10 + (uVar22 & 0xffff) * (uVar6 >> 0x10);

    if (iVar10 != 0) {

      iVar11 = 0x10000;

    }

    uVar24 = uVar26 + uVar4 * 0x10000;

    uVar22 = iVar11 + (unsigned int)(uVar24 < uVar26) + (uVar4 >> 0x10) + (uVar22 >> 0x10) * (uVar6 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

      uVar22 = ~uVar22;

      if (uVar24 == 0) {

        uVar22 = uVar22 + 1;

      }

      else {

        uVar24 = ~uVar24 + 1;

      }

    }

    if (((unsigned char)(uVar20 >> 1) & 1) == 1) {

      uVar24 = uVar23 + uVar24;

      uVar12 = uVar22 + (uVar24 < uVar23) + (uVar12 & 0xffff);

      if ((int)uVar12 < -0x8000) {

        uVar12 = 0xffff8000;

        uVar24 = 0;

      }

      if (0x7fff < (int)uVar12) {

        uVar12 = 0x7fff;

        uVar24 = 0xffffffff;

      }

      uVar12 = uVar12 & 0xffff;

    }

    else {

      uVar24 = uVar23 + uVar24;

      uVar12 = uVar22 + (uVar24 < uVar23) + uVar12;

    }

    uVar6 = puVar18[2];

    uVar22 = *(unsigned int *)(puVar16 + 8);

    uVar3 = uVar6 ^ uVar22;

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    if ((int)uVar22 < 0) {

      uVar22 = -uVar22;

    }

    uVar23 = (uVar22 & 0xffff) * (uVar6 & 0xffff);

    iVar10 = (uVar22 >> 0x10) * (uVar6 & 0xffff);

    iVar11 = 0;

    uVar4 = iVar10 + (uVar22 & 0xffff) * (uVar6 >> 0x10);

    if (iVar10 != 0) {

      iVar11 = 0x10000;

    }

    uVar26 = uVar23 + uVar4 * 0x10000;

    uVar22 = iVar11 + (unsigned int)(uVar26 < uVar23) + (uVar4 >> 0x10) + (uVar22 >> 0x10) * (uVar6 >> 0x10)

    ;

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

      uVar26 = uVar24 + uVar26;

      uVar12 = uVar22 + (uVar26 < uVar24) + (uVar12 & 0xffff);

      if ((int)uVar12 < -0x8000) {

        uVar12 = 0xffff8000;

        uVar26 = 0;

      }

      if (0x7fff < (int)uVar12) {

        uVar12 = 0x7fff;

        uVar26 = 0xffffffff;

      }

      uVar12 = uVar12 & 0xffff;

    }

    else {

      uVar26 = uVar24 + uVar26;

      uVar12 = uVar22 + (uVar26 < uVar24) + uVar12;

    }

    uVar6 = puVar18[3];

    uVar22 = *(unsigned int *)puVar16;

    uVar3 = uVar6 ^ uVar22;

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    if ((int)uVar22 < 0) {

      uVar22 = -uVar22;

    }

    uVar23 = (uVar22 & 0xffff) * (uVar6 & 0xffff);

    iVar10 = (uVar22 >> 0x10) * (uVar6 & 0xffff);

    iVar11 = 0;

    uVar4 = iVar10 + (uVar22 & 0xffff) * (uVar6 >> 0x10);

    if (iVar10 != 0) {

      iVar11 = 0x10000;

    }

    uVar24 = uVar23 + uVar4 * 0x10000;

    uVar22 = iVar11 + (unsigned int)(uVar24 < uVar23) + (uVar4 >> 0x10) + (uVar22 >> 0x10) * (uVar6 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

      uVar22 = ~uVar22;

      if (uVar24 == 0) {

        uVar22 = uVar22 + 1;

      }

      else {

        uVar24 = ~uVar24 + 1;

      }

    }

    if (((unsigned char)(uVar20 >> 1) & 1) == 1) {

      if ((int)uVar22 < -0x8000) {

        uVar22 = 0xffff8000;

        uVar24 = 0;

      }

      if (0x7fff < (int)uVar22) {

        uVar22 = 0x7fff;

        uVar24 = 0xffffffff;

      }

      uVar22 = uVar22 & 0xffff;

    }

    uVar3 = puVar18[4];

    uVar6 = *(unsigned int *)(puVar16 + 4);

    uVar4 = uVar3 ^ uVar6;

    if ((int)uVar3 < 0) {

      uVar3 = -uVar3;

    }

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    uVar5 = (uVar6 & 0xffff) * (uVar3 & 0xffff);

    iVar10 = (uVar6 >> 0x10) * (uVar3 & 0xffff);

    iVar11 = 0;

    uVar23 = iVar10 + (uVar6 & 0xffff) * (uVar3 >> 0x10);

    if (iVar10 != 0) {

      iVar11 = 0x10000;

    }

    uVar25 = uVar5 + uVar23 * 0x10000;

    uVar6 = iVar11 + (unsigned int)(uVar25 < uVar5) + (uVar23 >> 0x10) + (uVar6 >> 0x10) * (uVar3 >> 0x10);

    if ((int)-(unsigned int)((int)uVar4 < 0) < 0) {

      uVar6 = ~uVar6;

      if (uVar25 == 0) {

        uVar6 = uVar6 + 1;

      }

      else {

        uVar25 = ~uVar25 + 1;

      }

    }

    if (((unsigned char)(uVar20 >> 1) & 1) == 1) {

      uVar25 = uVar24 + uVar25;

      uVar22 = uVar6 + (uVar25 < uVar24) + (uVar22 & 0xffff);

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

      uVar25 = uVar24 + uVar25;

      uVar22 = uVar6 + (uVar25 < uVar24) + uVar22;

    }

    *(unsigned int *)(0x06094EF4 + 0x18) = (uVar12 << 0x10 | uVar26 >> 0x10) + puVar18[9];

    uVar6 = puVar18[5];

    uVar12 = *(unsigned int *)(puVar16 + 8);

    uVar3 = uVar6 ^ uVar12;

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    if ((int)uVar12 < 0) {

      uVar12 = -uVar12;

    }

    uVar23 = (uVar12 & 0xffff) * (uVar6 & 0xffff);

    iVar10 = (uVar12 >> 0x10) * (uVar6 & 0xffff);

    iVar11 = 0;

    uVar4 = iVar10 + (uVar12 & 0xffff) * (uVar6 >> 0x10);

    if (iVar10 != 0) {

      iVar11 = 0x10000;

    }

    uVar26 = uVar23 + uVar4 * 0x10000;

    uVar12 = iVar11 + (unsigned int)(uVar26 < uVar23) + (uVar4 >> 0x10) + (uVar12 >> 0x10) * (uVar6 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

      uVar12 = ~uVar12;

      if (uVar26 == 0) {

        uVar12 = uVar12 + 1;

      }

      else {

        uVar26 = ~uVar26 + 1;

      }

    }

    if (((unsigned char)(uVar20 >> 1) & 1) == 1) {

      uVar26 = uVar25 + uVar26;

      uVar22 = uVar12 + (uVar26 < uVar25) + (uVar22 & 0xffff);

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

    else {

      uVar26 = uVar25 + uVar26;

      uVar22 = uVar12 + (uVar26 < uVar25) + uVar22;

    }

    uVar6 = puVar18[6];

    uVar12 = *(unsigned int *)puVar16;

    uVar3 = uVar6 ^ uVar12;

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    if ((int)uVar12 < 0) {

      uVar12 = -uVar12;

    }

    uVar23 = (uVar12 & 0xffff) * (uVar6 & 0xffff);

    iVar10 = (uVar12 >> 0x10) * (uVar6 & 0xffff);

    iVar11 = 0;

    uVar4 = iVar10 + (uVar12 & 0xffff) * (uVar6 >> 0x10);

    if (iVar10 != 0) {

      iVar11 = 0x10000;

    }

    uVar24 = uVar23 + uVar4 * 0x10000;

    uVar12 = iVar11 + (unsigned int)(uVar24 < uVar23) + (uVar4 >> 0x10) + (uVar12 >> 0x10) * (uVar6 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

      uVar12 = ~uVar12;

      if (uVar24 == 0) {

        uVar12 = uVar12 + 1;

      }

      else {

        uVar24 = ~uVar24 + 1;

      }

    }

    if (((unsigned char)(uVar20 >> 1) & 1) == 1) {

      if ((int)uVar12 < -0x8000) {

        uVar12 = 0xffff8000;

        uVar24 = 0;

      }

      if (0x7fff < (int)uVar12) {

        uVar12 = 0x7fff;

        uVar24 = 0xffffffff;

      }

      uVar12 = uVar12 & 0xffff;

    }

    uVar3 = puVar18[7];

    uVar6 = *(unsigned int *)(puVar16 + 4);

    uVar4 = uVar3 ^ uVar6;

    if ((int)uVar3 < 0) {

      uVar3 = -uVar3;

    }

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    uVar5 = (uVar6 & 0xffff) * (uVar3 & 0xffff);

    iVar10 = (uVar6 >> 0x10) * (uVar3 & 0xffff);

    iVar11 = 0;

    uVar23 = iVar10 + (uVar6 & 0xffff) * (uVar3 >> 0x10);

    if (iVar10 != 0) {

      iVar11 = 0x10000;

    }

    uVar25 = uVar5 + uVar23 * 0x10000;

    uVar6 = iVar11 + (unsigned int)(uVar25 < uVar5) + (uVar23 >> 0x10) + (uVar6 >> 0x10) * (uVar3 >> 0x10);

    if ((int)-(unsigned int)((int)uVar4 < 0) < 0) {

      uVar6 = ~uVar6;

      if (uVar25 == 0) {

        uVar6 = uVar6 + 1;

      }

      else {

        uVar25 = ~uVar25 + 1;

      }

    }

    if (((unsigned char)(uVar20 >> 1) & 1) == 1) {

      uVar25 = uVar24 + uVar25;

      uVar12 = uVar6 + (uVar25 < uVar24) + (uVar12 & 0xffff);

      if ((int)uVar12 < -0x8000) {

        uVar12 = 0xffff8000;

        uVar25 = 0;

      }

      if (0x7fff < (int)uVar12) {

        uVar12 = 0x7fff;

        uVar25 = 0xffffffff;

      }

      uVar12 = uVar12 & 0xffff;

    }

    else {

      uVar25 = uVar24 + uVar25;

      uVar12 = uVar6 + (uVar25 < uVar24) + uVar12;

    }

    *(unsigned int *)(puVar8 + 0x1c) = (uVar22 << 0x10 | uVar26 >> 0x10) + puVar18[10];

    uVar6 = puVar18[8];

    uVar22 = *(unsigned int *)(puVar16 + 8);

    uVar3 = uVar6 ^ uVar22;

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    if ((int)uVar22 < 0) {

      uVar22 = -uVar22;

    }

    uVar23 = (uVar22 & 0xffff) * (uVar6 & 0xffff);

    iVar10 = (uVar22 >> 0x10) * (uVar6 & 0xffff);

    iVar11 = 0;

    uVar4 = iVar10 + (uVar22 & 0xffff) * (uVar6 >> 0x10);

    if (iVar10 != 0) {

      iVar11 = 0x10000;

    }

    uVar26 = uVar23 + uVar4 * 0x10000;

    uVar22 = iVar11 + (unsigned int)(uVar26 < uVar23) + (uVar4 >> 0x10) + (uVar22 >> 0x10) * (uVar6 >> 0x10)

    ;

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

      uVar12 = uVar22 + (uVar26 < uVar25) + (uVar12 & 0xffff);

      if ((int)uVar12 < -0x8000) {

        uVar12 = 0xffff8000;

        uVar26 = 0;

      }

      if (0x7fff < (int)uVar12) {

        uVar12 = 0x7fff;

        uVar26 = 0xffffffff;

      }

      uVar12 = uVar12 & 0xffff;

    }

    else {

      uVar26 = uVar25 + uVar26;

      uVar12 = uVar22 + (uVar26 < uVar25) + uVar12;

    }

    *(unsigned int *)(puVar8 + 0x20) = (uVar12 << 0x10 | uVar26 >> 0x10) + puVar18[0xb];

    *(unsigned short *)(puVar7 + 4) = (unsigned short)(*(int *)(puVar8 + 0x20) <= unaff_r10);

    puVar16 = 0x06094F74;

    psVar17 = (short *)((unsigned int)*(unsigned short *)((int)puVar19 + -2) * 6 + unaff_r14);

    sVar1 = psVar17[1];

    sVar2 = psVar17[2];

    *(int *)0x06094F74 = (int)*psVar17 << 0xb;

    *(int *)(puVar16 + 4) = (int)sVar1 << 0xb;

    *(int *)(puVar16 + 8) = (int)sVar2 << 0xb;

    puVar8 = 0x06094EF4;

    puVar18 = *(unsigned int **)0x0608A52C;

    uVar22 = *puVar18;

    uVar12 = *(unsigned int *)puVar16;

    uVar6 = uVar22 ^ uVar12;

    if ((int)uVar22 < 0) {

      uVar22 = -uVar22;

    }

    if ((int)uVar12 < 0) {

      uVar12 = -uVar12;

    }

    uVar4 = (uVar12 & 0xffff) * (uVar22 & 0xffff);

    iVar10 = (uVar12 >> 0x10) * (uVar22 & 0xffff);

    iVar11 = 0;

    uVar3 = iVar10 + (uVar12 & 0xffff) * (uVar22 >> 0x10);

    if (iVar10 != 0) {

      iVar11 = 0x10000;

    }

    uVar23 = uVar4 + uVar3 * 0x10000;

    uVar12 = iVar11 + (unsigned int)(uVar23 < uVar4) + (uVar3 >> 0x10) + (uVar12 >> 0x10) * (uVar22 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar6 < 0) < 0) {

      uVar12 = ~uVar12;

      if (uVar23 == 0) {

        uVar12 = uVar12 + 1;

      }

      else {

        uVar23 = ~uVar23 + 1;

      }

    }

    if (((unsigned char)(uVar20 >> 1) & 1) == 1) {

      if ((int)uVar12 < -0x8000) {

        uVar12 = 0xffff8000;

        uVar23 = 0;

      }

      if (0x7fff < (int)uVar12) {

        uVar12 = 0x7fff;

        uVar23 = 0xffffffff;

      }

      uVar12 = uVar12 & 0xffff;

    }

    uVar6 = puVar18[1];

    uVar22 = *(unsigned int *)(puVar16 + 4);

    uVar3 = uVar6 ^ uVar22;

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    if ((int)uVar22 < 0) {

      uVar22 = -uVar22;

    }

    uVar26 = (uVar22 & 0xffff) * (uVar6 & 0xffff);

    iVar10 = (uVar22 >> 0x10) * (uVar6 & 0xffff);

    iVar11 = 0;

    uVar4 = iVar10 + (uVar22 & 0xffff) * (uVar6 >> 0x10);

    if (iVar10 != 0) {

      iVar11 = 0x10000;

    }

    uVar24 = uVar26 + uVar4 * 0x10000;

    uVar22 = iVar11 + (unsigned int)(uVar24 < uVar26) + (uVar4 >> 0x10) + (uVar22 >> 0x10) * (uVar6 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

      uVar22 = ~uVar22;

      if (uVar24 == 0) {

        uVar22 = uVar22 + 1;

      }

      else {

        uVar24 = ~uVar24 + 1;

      }

    }

    if (((unsigned char)(uVar20 >> 1) & 1) == 1) {

      uVar24 = uVar23 + uVar24;

      uVar12 = uVar22 + (uVar24 < uVar23) + (uVar12 & 0xffff);

      if ((int)uVar12 < -0x8000) {

        uVar12 = 0xffff8000;

        uVar24 = 0;

      }

      if (0x7fff < (int)uVar12) {

        uVar12 = 0x7fff;

        uVar24 = 0xffffffff;

      }

      uVar12 = uVar12 & 0xffff;

    }

    else {

      uVar24 = uVar23 + uVar24;

      uVar12 = uVar22 + (uVar24 < uVar23) + uVar12;

    }

    uVar6 = puVar18[2];

    uVar22 = *(unsigned int *)(puVar16 + 8);

    uVar3 = uVar6 ^ uVar22;

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    if ((int)uVar22 < 0) {

      uVar22 = -uVar22;

    }

    uVar23 = (uVar22 & 0xffff) * (uVar6 & 0xffff);

    iVar10 = (uVar22 >> 0x10) * (uVar6 & 0xffff);

    iVar11 = 0;

    uVar4 = iVar10 + (uVar22 & 0xffff) * (uVar6 >> 0x10);

    if (iVar10 != 0) {

      iVar11 = 0x10000;

    }

    uVar26 = uVar23 + uVar4 * 0x10000;

    uVar22 = iVar11 + (unsigned int)(uVar26 < uVar23) + (uVar4 >> 0x10) + (uVar22 >> 0x10) * (uVar6 >> 0x10)

    ;

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

      uVar26 = uVar24 + uVar26;

      uVar12 = uVar22 + (uVar26 < uVar24) + (uVar12 & 0xffff);

      if ((int)uVar12 < -0x8000) {

        uVar12 = 0xffff8000;

        uVar26 = 0;

      }

      if (0x7fff < (int)uVar12) {

        uVar12 = 0x7fff;

        uVar26 = 0xffffffff;

      }

      uVar12 = uVar12 & 0xffff;

    }

    else {

      uVar26 = uVar24 + uVar26;

      uVar12 = uVar22 + (uVar26 < uVar24) + uVar12;

    }

    uVar6 = puVar18[3];

    uVar22 = *(unsigned int *)puVar16;

    uVar3 = uVar6 ^ uVar22;

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    if ((int)uVar22 < 0) {

      uVar22 = -uVar22;

    }

    uVar23 = (uVar22 & 0xffff) * (uVar6 & 0xffff);

    iVar10 = (uVar22 >> 0x10) * (uVar6 & 0xffff);

    iVar11 = 0;

    uVar4 = iVar10 + (uVar22 & 0xffff) * (uVar6 >> 0x10);

    if (iVar10 != 0) {

      iVar11 = 0x10000;

    }

    uVar24 = uVar23 + uVar4 * 0x10000;

    uVar22 = iVar11 + (unsigned int)(uVar24 < uVar23) + (uVar4 >> 0x10) + (uVar22 >> 0x10) * (uVar6 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

      uVar22 = ~uVar22;

      if (uVar24 == 0) {

        uVar22 = uVar22 + 1;

      }

      else {

        uVar24 = ~uVar24 + 1;

      }

    }

    if (((unsigned char)(uVar20 >> 1) & 1) == 1) {

      if ((int)uVar22 < -0x8000) {

        uVar22 = 0xffff8000;

        uVar24 = 0;

      }

      if (0x7fff < (int)uVar22) {

        uVar22 = 0x7fff;

        uVar24 = 0xffffffff;

      }

      uVar22 = uVar22 & 0xffff;

    }

    uVar3 = puVar18[4];

    uVar6 = *(unsigned int *)(puVar16 + 4);

    uVar4 = uVar3 ^ uVar6;

    if ((int)uVar3 < 0) {

      uVar3 = -uVar3;

    }

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    uVar5 = (uVar6 & 0xffff) * (uVar3 & 0xffff);

    iVar10 = (uVar6 >> 0x10) * (uVar3 & 0xffff);

    iVar11 = 0;

    uVar23 = iVar10 + (uVar6 & 0xffff) * (uVar3 >> 0x10);

    if (iVar10 != 0) {

      iVar11 = 0x10000;

    }

    uVar25 = uVar5 + uVar23 * 0x10000;

    uVar6 = iVar11 + (unsigned int)(uVar25 < uVar5) + (uVar23 >> 0x10) + (uVar6 >> 0x10) * (uVar3 >> 0x10);

    if ((int)-(unsigned int)((int)uVar4 < 0) < 0) {

      uVar6 = ~uVar6;

      if (uVar25 == 0) {

        uVar6 = uVar6 + 1;

      }

      else {

        uVar25 = ~uVar25 + 1;

      }

    }

    if (((unsigned char)(uVar20 >> 1) & 1) == 1) {

      uVar25 = uVar24 + uVar25;

      uVar22 = uVar6 + (uVar25 < uVar24) + (uVar22 & 0xffff);

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

      uVar25 = uVar24 + uVar25;

      uVar22 = uVar6 + (uVar25 < uVar24) + uVar22;

    }

    *(unsigned int *)(0x06094EF4 + 0x24) = (uVar12 << 0x10 | uVar26 >> 0x10) + puVar18[9];

    uVar6 = puVar18[5];

    uVar12 = *(unsigned int *)(puVar16 + 8);

    uVar3 = uVar6 ^ uVar12;

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    if ((int)uVar12 < 0) {

      uVar12 = -uVar12;

    }

    uVar23 = (uVar12 & 0xffff) * (uVar6 & 0xffff);

    iVar10 = (uVar12 >> 0x10) * (uVar6 & 0xffff);

    iVar11 = 0;

    uVar4 = iVar10 + (uVar12 & 0xffff) * (uVar6 >> 0x10);

    if (iVar10 != 0) {

      iVar11 = 0x10000;

    }

    uVar26 = uVar23 + uVar4 * 0x10000;

    uVar12 = iVar11 + (unsigned int)(uVar26 < uVar23) + (uVar4 >> 0x10) + (uVar12 >> 0x10) * (uVar6 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

      uVar12 = ~uVar12;

      if (uVar26 == 0) {

        uVar12 = uVar12 + 1;

      }

      else {

        uVar26 = ~uVar26 + 1;

      }

    }

    if (((unsigned char)(uVar20 >> 1) & 1) == 1) {

      uVar26 = uVar25 + uVar26;

      uVar22 = uVar12 + (uVar26 < uVar25) + (uVar22 & 0xffff);

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

    else {

      uVar26 = uVar25 + uVar26;

      uVar22 = uVar12 + (uVar26 < uVar25) + uVar22;

    }

    uVar6 = puVar18[6];

    uVar12 = *(unsigned int *)puVar16;

    uVar3 = uVar6 ^ uVar12;

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    if ((int)uVar12 < 0) {

      uVar12 = -uVar12;

    }

    uVar23 = (uVar12 & 0xffff) * (uVar6 & 0xffff);

    iVar10 = (uVar12 >> 0x10) * (uVar6 & 0xffff);

    iVar11 = 0;

    uVar4 = iVar10 + (uVar12 & 0xffff) * (uVar6 >> 0x10);

    if (iVar10 != 0) {

      iVar11 = 0x10000;

    }

    uVar24 = uVar23 + uVar4 * 0x10000;

    uVar12 = iVar11 + (unsigned int)(uVar24 < uVar23) + (uVar4 >> 0x10) + (uVar12 >> 0x10) * (uVar6 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

      uVar12 = ~uVar12;

      if (uVar24 == 0) {

        uVar12 = uVar12 + 1;

      }

      else {

        uVar24 = ~uVar24 + 1;

      }

    }

    if (((unsigned char)(uVar20 >> 1) & 1) == 1) {

      if ((int)uVar12 < -0x8000) {

        uVar12 = 0xffff8000;

        uVar24 = 0;

      }

      if (0x7fff < (int)uVar12) {

        uVar12 = 0x7fff;

        uVar24 = 0xffffffff;

      }

      uVar12 = uVar12 & 0xffff;

    }

    uVar3 = puVar18[7];

    uVar6 = *(unsigned int *)(puVar16 + 4);

    uVar4 = uVar3 ^ uVar6;

    if ((int)uVar3 < 0) {

      uVar3 = -uVar3;

    }

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    uVar5 = (uVar6 & 0xffff) * (uVar3 & 0xffff);

    iVar10 = (uVar6 >> 0x10) * (uVar3 & 0xffff);

    iVar11 = 0;

    uVar23 = iVar10 + (uVar6 & 0xffff) * (uVar3 >> 0x10);

    if (iVar10 != 0) {

      iVar11 = 0x10000;

    }

    uVar25 = uVar5 + uVar23 * 0x10000;

    uVar6 = iVar11 + (unsigned int)(uVar25 < uVar5) + (uVar23 >> 0x10) + (uVar6 >> 0x10) * (uVar3 >> 0x10);

    if ((int)-(unsigned int)((int)uVar4 < 0) < 0) {

      uVar6 = ~uVar6;

      if (uVar25 == 0) {

        uVar6 = uVar6 + 1;

      }

      else {

        uVar25 = ~uVar25 + 1;

      }

    }

    if (((unsigned char)(uVar20 >> 1) & 1) == 1) {

      uVar25 = uVar24 + uVar25;

      uVar12 = uVar6 + (uVar25 < uVar24) + (uVar12 & 0xffff);

      if ((int)uVar12 < -0x8000) {

        uVar12 = 0xffff8000;

        uVar25 = 0;

      }

      if (0x7fff < (int)uVar12) {

        uVar12 = 0x7fff;

        uVar25 = 0xffffffff;

      }

      uVar12 = uVar12 & 0xffff;

    }

    else {

      uVar25 = uVar24 + uVar25;

      uVar12 = uVar6 + (uVar25 < uVar24) + uVar12;

    }

    *(unsigned int *)(puVar8 + 0x28) = (uVar22 << 0x10 | uVar26 >> 0x10) + puVar18[10];

    uVar6 = puVar18[8];

    uVar22 = *(unsigned int *)(puVar16 + 8);

    uVar3 = uVar6 ^ uVar22;

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    if ((int)uVar22 < 0) {

      uVar22 = -uVar22;

    }

    uVar23 = (uVar22 & 0xffff) * (uVar6 & 0xffff);

    iVar10 = (uVar22 >> 0x10) * (uVar6 & 0xffff);

    iVar11 = 0;

    uVar4 = iVar10 + (uVar22 & 0xffff) * (uVar6 >> 0x10);

    if (iVar10 != 0) {

      iVar11 = 0x10000;

    }

    uVar26 = uVar23 + uVar4 * 0x10000;

    uVar22 = iVar11 + (unsigned int)(uVar26 < uVar23) + (uVar4 >> 0x10) + (uVar22 >> 0x10) * (uVar6 >> 0x10)

    ;

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

      uVar12 = uVar22 + (uVar26 < uVar25) + (uVar12 & 0xffff);

      if ((int)uVar12 < -0x8000) {

        uVar12 = 0xffff8000;

        uVar26 = 0;

      }

      if (0x7fff < (int)uVar12) {

        uVar12 = 0x7fff;

        uVar26 = 0xffffffff;

      }

      uVar12 = uVar12 & 0xffff;

    }

    else {

      uVar26 = uVar25 + uVar26;

      uVar12 = uVar22 + (uVar26 < uVar25) + uVar12;

    }

    *(unsigned int *)(puVar8 + 0x2c) = (uVar12 << 0x10 | uVar26 >> 0x10) + puVar18[0xb];

    iVar11 = *(int *)(puVar8 + 0x2c);

    *(unsigned short *)(puVar7 + 6) = (unsigned short)(iVar11 <= unaff_r10);

    iVar11 = (unsigned int)(iVar11 <= unaff_r10) + (int)*(short *)(puVar7 + 4) +

             (int)*(short *)(puVar7 + 2) + (int)*(short *)puVar7;

    uVar12 = uVar21 | iVar11 == 0;

    if (((unsigned char)uVar12 & 1) != 1) {

      if (iVar11 == 4) {

        uVar12 = 4;

        goto LAB_0602c416;

      }

      (*(void(*)())(*(int *)(0x0602C450 + iVar11 * 4)))(0x06094EF4,0x06094EEC,puVar18 + 9,puVar18 + 0xc);

      uVar12 = uVar21;

    }

    puVar8 = 0x06094F54;

    puVar16 = 0x0608AC20;

    puVar7 = 0x06094EF4;

    iVar11 = *(int *)0x060620D4;

    puVar13 = (int *)(int)DAT_0602c0f0;

    uVar14 = *(int *)(0x06094EF4 + 8);

    puVar13[4] = (int)DAT_0602c0f2;

    *puVar13 = uVar14;

    puVar13[5] = 0;

    iVar15 = *(int *)(puVar7 + 4);

    iVar10 = puVar13[7];

    *(int *)puVar8 = (int)((unsigned long long)((long long)iVar10 * (long long)*(int *)puVar7) >> 0x20);

    *(int *)(puVar8 + 4) = (int)((unsigned long long)((long long)iVar10 * (long long)-iVar15) >> 0x20);

    puVar9 = 0x06094EE4;

    iVar10 = *(int *)puVar8;

    iVar15 = *(int *)(puVar8 + 4);

    *(short *)0x06094EE4 = 0;

    uVar21 = uVar12 & 0xfffffffe;

    if (PTR_DAT_0602c0f4 < iVar10) {

      *(short *)puVar9 = 1;

    }

    else if (iVar10 < DAT_0602c120) {

      *(short *)puVar9 = 1;

    }

    else if (DAT_0602c12e < iVar15) {

      *(short *)puVar9 = 1;

    }

    else if (iVar15 < DAT_0602c176) {

      *(short *)puVar9 = 1;

    }

    puVar13 = (int *)(int)DAT_0602c178;

    uVar14 = *(int *)(puVar7 + 0x14);

    puVar13[4] = (int)DAT_0602c17a;

    *puVar13 = uVar14;

    puVar13[5] = 0;

    iVar15 = *(int *)(puVar7 + 0x10);

    iVar10 = puVar13[7];

    *(int *)(puVar8 + 8) =

         (int)((unsigned long long)((long long)iVar10 * (long long)*(int *)(puVar7 + 0xc)) >> 0x20);

    *(int *)(puVar8 + 0xc) = (int)((unsigned long long)((long long)iVar10 * (long long)-iVar15) >> 0x20);

    iVar10 = *(int *)(puVar8 + 8);

    iVar15 = *(int *)(puVar8 + 0xc);

    *(short *)(puVar9 + 2) = 0;

    if (DAT_0602c17c < iVar10) {

      *(short *)(puVar9 + 2) = 1;

    }

    else if (iVar10 < DAT_0602c18a) {

      *(short *)(puVar9 + 2) = 1;

    }

    else if (DAT_0602c198 < iVar15) {

      *(short *)(puVar9 + 2) = 1;

    }

    else if (iVar15 < DAT_0602c1e0) {

      *(short *)(puVar9 + 2) = 1;

    }

    puVar13 = (int *)(int)DAT_0602c1e2;

    uVar14 = *(int *)(puVar7 + 0x20);

    puVar13[4] = (int)DAT_0602c1e4;

    *puVar13 = uVar14;

    puVar13[5] = 0;

    iVar15 = *(int *)(puVar7 + 0x1c);

    iVar10 = puVar13[7];

    *(int *)(puVar8 + 0x10) =

         (int)((unsigned long long)((long long)iVar10 * (long long)*(int *)(puVar7 + 0x18)) >> 0x20);

    *(int *)(puVar8 + 0x14) = (int)((unsigned long long)((long long)iVar10 * (long long)-iVar15) >> 0x20);

    iVar10 = *(int *)(puVar8 + 0x10);

    iVar15 = *(int *)(puVar8 + 0x14);

    *(short *)(puVar9 + 4) = 0;

    if (DAT_0602c1e6 < iVar10) {

      *(short *)(puVar9 + 4) = 1;

    }

    else if (iVar10 < DAT_0602c1f4) {

      *(short *)(puVar9 + 4) = 1;

    }

    else if (DAT_0602c202 < iVar15) {

      *(short *)(puVar9 + 4) = 1;

    }

    else if (iVar15 < DAT_0602c24a) {

      *(short *)(puVar9 + 4) = 1;

    }

    puVar13 = (int *)(int)DAT_0602c24c;

    uVar14 = *(int *)(puVar7 + 0x2c);

    puVar13[4] = (int)DAT_0602c24e;

    *puVar13 = uVar14;

    puVar13[5] = 0;

    iVar15 = *(int *)(puVar7 + 0x28);

    iVar10 = puVar13[7];

    *(int *)(puVar8 + 0x18) =

         (int)((unsigned long long)((long long)iVar10 * (long long)*(int *)(puVar7 + 0x24)) >> 0x20);

    *(int *)(puVar8 + 0x1c) = (int)((unsigned long long)((long long)iVar10 * (long long)-iVar15) >> 0x20);

    iVar10 = *(int *)(puVar8 + 0x18);

    iVar15 = *(int *)(puVar8 + 0x1c);

    *(short *)(puVar9 + 6) = 0;

    if (DAT_0602c250 < iVar10) {

      *(short *)(puVar9 + 6) = 1;

    }

    else if (iVar10 < DAT_0602c25e) {

      *(short *)(puVar9 + 6) = 1;

    }

    else if (DAT_0602c26c < iVar15) {

      *(short *)(puVar9 + 6) = 1;

    }

    else if (iVar15 < DAT_0602c29c) {

      *(short *)(puVar9 + 6) = 1;

    }

    if (((((int)0xFFFFFF50 <= *(int *)puVar8) ||

         ((int)0xFFFFFF50 <= *(int *)(puVar8 + 8))) ||

        ((int)0xFFFFFF50 <= *(int *)(puVar8 + 0x10))) ||

       (uVar12 = *(unsigned int *)(puVar8 + 0x18), (int)0xFFFFFF50 <= (int)uVar12)) {

      uVar20 = uVar21 | *(int *)puVar8 < 0x000000B0;

      if (((((unsigned char)uVar20 & 1) != 1) &&

          (uVar20 = uVar21 | *(int *)(puVar8 + 8) < 0x000000B0, ((unsigned char)uVar20 & 1) != 1)) &&

         (uVar20 = uVar21 | *(int *)(puVar8 + 0x10) < 0x000000B0, ((unsigned char)uVar20 & 1) != 1)) {

        uVar12 = *(unsigned int *)(puVar8 + 0x18);

        uVar20 = uVar21 | (int)uVar12 < 0x000000B0;

        uVar21 = uVar20;

        if (((unsigned char)uVar20 & 1) != 1) goto LAB_0602c416;

      }

      uVar20 = uVar20 & 0xfffffffe;

      if ((((int)0xFFFFFF81 <= *(int *)(puVar8 + 4)) ||

          ((int)0xFFFFFF81 <= *(int *)(puVar8 + 0xc))) ||

         (((int)0xFFFFFF81 <= *(int *)(puVar8 + 0x14) ||

          (uVar12 = *(unsigned int *)(puVar8 + 0x1c), uVar21 = uVar20, (int)0xFFFFFF81 <= (int)uVar12)

          ))) {

        uVar21 = uVar20 | *(int *)(puVar8 + 4) < 0x00000051;

        if (((((unsigned char)uVar21 & 1) != 1) &&

            (uVar21 = uVar20 | *(int *)(puVar8 + 0xc) < 0x00000051, ((unsigned char)uVar21 & 1) != 1)) &&

           (uVar21 = uVar20 | *(int *)(puVar8 + 0x14) < 0x00000051, ((unsigned char)uVar21 & 1) != 1)) {

          uVar12 = *(unsigned int *)(puVar8 + 0x1c);

          uVar21 = uVar20 | (int)uVar12 < 0x00000051;

          if (((unsigned char)uVar21 & 1) != 1) goto LAB_0602c416;

        }

        iVar10 = (int)*(short *)(puVar9 + 6) +

                 (int)*(short *)puVar9 + (int)*(short *)(puVar9 + 2) + (int)*(short *)(puVar9 + 4);

        if (iVar10 != 4) {

          if (iVar10 != 0) {

            (*(void(*)())(*(int *)(0x0602C460 + iVar10 * 4)))(puVar8,puVar9);

          }

          *(short *)(puVar16 + iVar11 * 0x18 + 8) = (short)*(int *)puVar8;

          *(short *)(puVar16 + iVar11 * 0x18 + 10) = (short)*(int *)(puVar8 + 4);

          *(short *)(puVar16 + iVar11 * 0x18 + 0xc) = (short)*(int *)(puVar8 + 8);

          *(short *)(puVar16 + iVar11 * 0x18 + 0xe) = (short)*(int *)(puVar8 + 0xc);

          *(short *)(puVar16 + iVar11 * 0x18 + 0x10) = (short)*(int *)(puVar8 + 0x10);

          *(short *)(puVar16 + iVar11 * 0x18 + 0x12) = (short)*(int *)(puVar8 + 0x14);

          *(short *)(puVar16 + iVar11 * 0x18 + 0x14) = (short)*(int *)(puVar8 + 0x18);

          *(short *)(puVar16 + iVar11 * 0x18 + 0x16) = (short)*(int *)(puVar8 + 0x1c);

          *(short *)(puVar16 + iVar11 * 0x18 + 6) = *(short *)((int)puVar19 + -10);

          puVar16[iVar11 * 0x18 + 4] = (unsigned char)((unsigned int)(int)*(short *)(puVar19 + -3) >> 4) & 0xf;

          puVar16[iVar11 * 0x18 + 5] = unaff_r13;

          uVar21 = (**(void **)(0x0602C470 + ((int)*(short *)(puVar19 + -3) & 7U) * 4))

                             (*(int *)(0x06094EF4 + 0x14),

                              *(int *)(0x06094EF4 + 0x20),

                              *(int *)(0x06094EF4 + 0x2c));

          return uVar21;

        }

        uVar12 = 4;

        uVar21 = uVar21 & 0xfffffffe;

      }

    }

  }

  goto LAB_0602c416;

}
