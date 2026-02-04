extern int DAT_0602a24e;

extern int DAT_0602a4c4;

extern int DAT_0602a4c6;

extern int DAT_0602a4f4;

extern int DAT_0602a502;

extern int DAT_0602a54a;

extern int DAT_0602a54c;

extern int DAT_0602a54e;

extern int DAT_0602a550;

extern int DAT_0602a55e;

extern int DAT_0602a56c;

extern int DAT_0602a5b4;

extern int DAT_0602a5b6;

extern int DAT_0602a5b8;

extern int DAT_0602a5ba;

extern int DAT_0602a5c8;

extern int DAT_0602a5d6;

extern int DAT_0602a61e;

extern int DAT_0602a620;

extern int DAT_0602a622;

extern int DAT_0602a624;

extern int DAT_0602a632;

extern int DAT_0602a640;

extern int DAT_0602a670;

extern int PTR_DAT_0602a4c8;

extern int PTR_DAT_0602a4c8;

unsigned int FUN_0602a754(param_1, param_2, param_3, param_4, param_5, param_6)
    int param_1;
    int param_2;
    int param_3;
    int param_4;
    int param_5;
    int param_6;
{

  unsigned int uVar1;

  unsigned int uVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  char *puVar6;

  int iVar7;

  int iVar8;

  unsigned int uVar9;

  int *puVar10;

  int uVar11;

  int iVar12;

  int in_r3;

  unsigned int *puVar13;

  unsigned int *puVar14;

  unsigned int *unaff_r8;

  unsigned int *puVar15;

  int unaff_r10;

  char unaff_r13;

  unsigned int uVar16;

  unsigned int uVar17;

  unsigned int in_sr;

  unsigned int uVar18;

  unsigned int uVar19;

  unsigned int uVar20;

  unsigned int uVar21;

  unsigned int uVar22;

  unsigned int uVar23;

  unsigned int uVar24;

  puVar3 = 0x060620D4;

  iVar8 = *(int *)0x060620D4;

  *(short *)(0x0606A4F8 + iVar8 * 2) =

       (short)(-((unsigned int)(in_r3 + param_1 + param_3 + param_2) >> 2) >> 0xc);

  uVar9 = (iVar8 * 2 >> 1) + 1;

  *(unsigned int *)puVar3 = uVar9;

  uVar17 = in_sr & 0xfffffffe;

LAB_0602a7d6:

  do {

    puVar15 = unaff_r8;

    puVar3 = 0x0608A7A0;

    param_5 = param_5 + -1;

    uVar17 = uVar17 & 0xfffffffe;

    if (param_5 == 0) {

      return uVar9;

    }

    unaff_r8 = puVar15 + -6;

    uVar16 = uVar17 | *(short *)0x0605BE36 == 0;

  } while ((((unsigned char)uVar16 & 1) != 1) &&

          (uVar9 = (unsigned int)*(short *)((int)puVar15 + -10), uVar16 = uVar17, (int)DAT_0602a24e == uVar9

          ));

  puVar13 = (unsigned int *)((unsigned int)*(unsigned short *)(puVar15 + -2) * 0xc + param_6);

  puVar14 = *(unsigned int **)0x0608A52C;

  uVar9 = *puVar14;

  uVar17 = *puVar13;

  uVar18 = uVar9 ^ uVar17;

  if ((int)uVar9 < 0) {

    uVar9 = -uVar9;

  }

  if ((int)uVar17 < 0) {

    uVar17 = -uVar17;

  }

  uVar2 = (uVar17 & 0xffff) * (uVar9 & 0xffff);

  iVar7 = (uVar17 >> 0x10) * (uVar9 & 0xffff);

  iVar8 = 0;

  uVar1 = iVar7 + (uVar17 & 0xffff) * (uVar9 >> 0x10);

  if (iVar7 != 0) {

    iVar8 = 0x10000;

  }

  uVar19 = uVar2 + uVar1 * 0x10000;

  uVar17 = iVar8 + (unsigned int)(uVar19 < uVar2) + (uVar1 >> 0x10) + (uVar17 >> 0x10) * (uVar9 >> 0x10);

  if ((int)-(unsigned int)((int)uVar18 < 0) < 0) {

    uVar17 = ~uVar17;

    if (uVar19 == 0) {

      uVar17 = uVar17 + 1;

    }

    else {

      uVar19 = ~uVar19 + 1;

    }

  }

  if (((unsigned char)(uVar16 >> 1) & 1) == 1) {

    if ((int)uVar17 < -0x8000) {

      uVar17 = 0xffff8000;

      uVar19 = 0;

    }

    if (0x7fff < (int)uVar17) {

      uVar17 = 0x7fff;

      uVar19 = 0xffffffff;

    }

    uVar17 = uVar17 & 0xffff;

  }

  uVar18 = puVar14[1];

  uVar9 = puVar13[1];

  uVar1 = uVar18 ^ uVar9;

  if ((int)uVar18 < 0) {

    uVar18 = -uVar18;

  }

  if ((int)uVar9 < 0) {

    uVar9 = -uVar9;

  }

  uVar21 = (uVar9 & 0xffff) * (uVar18 & 0xffff);

  iVar7 = (uVar9 >> 0x10) * (uVar18 & 0xffff);

  iVar8 = 0;

  uVar2 = iVar7 + (uVar9 & 0xffff) * (uVar18 >> 0x10);

  if (iVar7 != 0) {

    iVar8 = 0x10000;

  }

  uVar24 = uVar21 + uVar2 * 0x10000;

  uVar9 = iVar8 + (unsigned int)(uVar24 < uVar21) + (uVar2 >> 0x10) + (uVar9 >> 0x10) * (uVar18 >> 0x10);

  if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

    uVar9 = ~uVar9;

    if (uVar24 == 0) {

      uVar9 = uVar9 + 1;

    }

    else {

      uVar24 = ~uVar24 + 1;

    }

  }

  if (((unsigned char)(uVar16 >> 1) & 1) == 1) {

    uVar24 = uVar19 + uVar24;

    uVar17 = uVar9 + (uVar24 < uVar19) + (uVar17 & 0xffff);

    if ((int)uVar17 < -0x8000) {

      uVar17 = 0xffff8000;

      uVar24 = 0;

    }

    if (0x7fff < (int)uVar17) {

      uVar17 = 0x7fff;

      uVar24 = 0xffffffff;

    }

    uVar17 = uVar17 & 0xffff;

  }

  else {

    uVar24 = uVar19 + uVar24;

    uVar17 = uVar9 + (uVar24 < uVar19) + uVar17;

  }

  uVar18 = puVar14[2];

  uVar9 = puVar13[2];

  uVar1 = uVar18 ^ uVar9;

  if ((int)uVar18 < 0) {

    uVar18 = -uVar18;

  }

  if ((int)uVar9 < 0) {

    uVar9 = -uVar9;

  }

  uVar19 = (uVar9 & 0xffff) * (uVar18 & 0xffff);

  iVar7 = (uVar9 >> 0x10) * (uVar18 & 0xffff);

  iVar8 = 0;

  uVar2 = iVar7 + (uVar9 & 0xffff) * (uVar18 >> 0x10);

  if (iVar7 != 0) {

    iVar8 = 0x10000;

  }

  uVar21 = uVar19 + uVar2 * 0x10000;

  uVar9 = iVar8 + (unsigned int)(uVar21 < uVar19) + (uVar2 >> 0x10) + (uVar9 >> 0x10) * (uVar18 >> 0x10);

  if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

    uVar9 = ~uVar9;

    if (uVar21 == 0) {

      uVar9 = uVar9 + 1;

    }

    else {

      uVar21 = ~uVar21 + 1;

    }

  }

  if (((unsigned char)(uVar16 >> 1) & 1) == 1) {

    uVar21 = uVar24 + uVar21;

    uVar17 = uVar9 + (uVar21 < uVar24) + (uVar17 & 0xffff);

    if ((int)uVar17 < -0x8000) {

      uVar17 = 0xffff8000;

      uVar21 = 0;

    }

    if (0x7fff < (int)uVar17) {

      uVar17 = 0x7fff;

      uVar21 = 0xffffffff;

    }

    uVar17 = uVar17 & 0xffff;

  }

  else {

    uVar21 = uVar24 + uVar21;

    uVar17 = uVar9 + (uVar21 < uVar24) + uVar17;

  }

  uVar18 = puVar14[3];

  uVar9 = *puVar13;

  uVar1 = uVar18 ^ uVar9;

  if ((int)uVar18 < 0) {

    uVar18 = -uVar18;

  }

  if ((int)uVar9 < 0) {

    uVar9 = -uVar9;

  }

  uVar19 = (uVar9 & 0xffff) * (uVar18 & 0xffff);

  iVar7 = (uVar9 >> 0x10) * (uVar18 & 0xffff);

  iVar8 = 0;

  uVar2 = iVar7 + (uVar9 & 0xffff) * (uVar18 >> 0x10);

  if (iVar7 != 0) {

    iVar8 = 0x10000;

  }

  uVar24 = uVar19 + uVar2 * 0x10000;

  uVar9 = iVar8 + (unsigned int)(uVar24 < uVar19) + (uVar2 >> 0x10) + (uVar9 >> 0x10) * (uVar18 >> 0x10);

  if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

    uVar9 = ~uVar9;

    if (uVar24 == 0) {

      uVar9 = uVar9 + 1;

    }

    else {

      uVar24 = ~uVar24 + 1;

    }

  }

  if (((unsigned char)(uVar16 >> 1) & 1) == 1) {

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

  uVar1 = puVar14[4];

  uVar18 = puVar13[1];

  uVar2 = uVar1 ^ uVar18;

  if ((int)uVar1 < 0) {

    uVar1 = -uVar1;

  }

  if ((int)uVar18 < 0) {

    uVar18 = -uVar18;

  }

  uVar22 = (uVar18 & 0xffff) * (uVar1 & 0xffff);

  iVar7 = (uVar18 >> 0x10) * (uVar1 & 0xffff);

  iVar8 = 0;

  uVar19 = iVar7 + (uVar18 & 0xffff) * (uVar1 >> 0x10);

  if (iVar7 != 0) {

    iVar8 = 0x10000;

  }

  uVar20 = uVar22 + uVar19 * 0x10000;

  uVar18 = iVar8 + (unsigned int)(uVar20 < uVar22) + (uVar19 >> 0x10) + (uVar18 >> 0x10) * (uVar1 >> 0x10);

  if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

    uVar18 = ~uVar18;

    if (uVar20 == 0) {

      uVar18 = uVar18 + 1;

    }

    else {

      uVar20 = ~uVar20 + 1;

    }

  }

  if (((unsigned char)(uVar16 >> 1) & 1) == 1) {

    uVar20 = uVar24 + uVar20;

    uVar9 = uVar18 + (uVar20 < uVar24) + (uVar9 & 0xffff);

    if ((int)uVar9 < -0x8000) {

      uVar9 = 0xffff8000;

      uVar20 = 0;

    }

    if (0x7fff < (int)uVar9) {

      uVar9 = 0x7fff;

      uVar20 = 0xffffffff;

    }

    uVar9 = uVar9 & 0xffff;

  }

  else {

    uVar20 = uVar24 + uVar20;

    uVar9 = uVar18 + (uVar20 < uVar24) + uVar9;

  }

  *(unsigned int *)0x0608A7A0 = (uVar17 << 0x10 | uVar21 >> 0x10) + puVar14[9];

  uVar18 = puVar14[5];

  uVar17 = puVar13[2];

  uVar1 = uVar18 ^ uVar17;

  if ((int)uVar18 < 0) {

    uVar18 = -uVar18;

  }

  if ((int)uVar17 < 0) {

    uVar17 = -uVar17;

  }

  uVar19 = (uVar17 & 0xffff) * (uVar18 & 0xffff);

  iVar7 = (uVar17 >> 0x10) * (uVar18 & 0xffff);

  iVar8 = 0;

  uVar2 = iVar7 + (uVar17 & 0xffff) * (uVar18 >> 0x10);

  if (iVar7 != 0) {

    iVar8 = 0x10000;

  }

  uVar21 = uVar19 + uVar2 * 0x10000;

  uVar17 = iVar8 + (unsigned int)(uVar21 < uVar19) + (uVar2 >> 0x10) + (uVar17 >> 0x10) * (uVar18 >> 0x10);

  if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

    uVar17 = ~uVar17;

    if (uVar21 == 0) {

      uVar17 = uVar17 + 1;

    }

    else {

      uVar21 = ~uVar21 + 1;

    }

  }

  if (((unsigned char)(uVar16 >> 1) & 1) == 1) {

    uVar21 = uVar20 + uVar21;

    uVar9 = uVar17 + (uVar21 < uVar20) + (uVar9 & 0xffff);

    if ((int)uVar9 < -0x8000) {

      uVar9 = 0xffff8000;

      uVar21 = 0;

    }

    if (0x7fff < (int)uVar9) {

      uVar9 = 0x7fff;

      uVar21 = 0xffffffff;

    }

    uVar9 = uVar9 & 0xffff;

  }

  else {

    uVar21 = uVar20 + uVar21;

    uVar9 = uVar17 + (uVar21 < uVar20) + uVar9;

  }

  uVar18 = puVar14[6];

  uVar17 = *puVar13;

  uVar1 = uVar18 ^ uVar17;

  if ((int)uVar18 < 0) {

    uVar18 = -uVar18;

  }

  if ((int)uVar17 < 0) {

    uVar17 = -uVar17;

  }

  uVar19 = (uVar17 & 0xffff) * (uVar18 & 0xffff);

  iVar7 = (uVar17 >> 0x10) * (uVar18 & 0xffff);

  iVar8 = 0;

  uVar2 = iVar7 + (uVar17 & 0xffff) * (uVar18 >> 0x10);

  if (iVar7 != 0) {

    iVar8 = 0x10000;

  }

  uVar24 = uVar19 + uVar2 * 0x10000;

  uVar17 = iVar8 + (unsigned int)(uVar24 < uVar19) + (uVar2 >> 0x10) + (uVar17 >> 0x10) * (uVar18 >> 0x10);

  if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

    uVar17 = ~uVar17;

    if (uVar24 == 0) {

      uVar17 = uVar17 + 1;

    }

    else {

      uVar24 = ~uVar24 + 1;

    }

  }

  if (((unsigned char)(uVar16 >> 1) & 1) == 1) {

    if ((int)uVar17 < -0x8000) {

      uVar17 = 0xffff8000;

      uVar24 = 0;

    }

    if (0x7fff < (int)uVar17) {

      uVar17 = 0x7fff;

      uVar24 = 0xffffffff;

    }

    uVar17 = uVar17 & 0xffff;

  }

  uVar1 = puVar14[7];

  uVar18 = puVar13[1];

  uVar2 = uVar1 ^ uVar18;

  if ((int)uVar1 < 0) {

    uVar1 = -uVar1;

  }

  if ((int)uVar18 < 0) {

    uVar18 = -uVar18;

  }

  uVar22 = (uVar18 & 0xffff) * (uVar1 & 0xffff);

  iVar7 = (uVar18 >> 0x10) * (uVar1 & 0xffff);

  iVar8 = 0;

  uVar19 = iVar7 + (uVar18 & 0xffff) * (uVar1 >> 0x10);

  if (iVar7 != 0) {

    iVar8 = 0x10000;

  }

  uVar20 = uVar22 + uVar19 * 0x10000;

  uVar18 = iVar8 + (unsigned int)(uVar20 < uVar22) + (uVar19 >> 0x10) + (uVar18 >> 0x10) * (uVar1 >> 0x10);

  if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

    uVar18 = ~uVar18;

    if (uVar20 == 0) {

      uVar18 = uVar18 + 1;

    }

    else {

      uVar20 = ~uVar20 + 1;

    }

  }

  if (((unsigned char)(uVar16 >> 1) & 1) == 1) {

    uVar20 = uVar24 + uVar20;

    uVar17 = uVar18 + (uVar20 < uVar24) + (uVar17 & 0xffff);

    if ((int)uVar17 < -0x8000) {

      uVar17 = 0xffff8000;

      uVar20 = 0;

    }

    if (0x7fff < (int)uVar17) {

      uVar17 = 0x7fff;

      uVar20 = 0xffffffff;

    }

    uVar17 = uVar17 & 0xffff;

  }

  else {

    uVar20 = uVar24 + uVar20;

    uVar17 = uVar18 + (uVar20 < uVar24) + uVar17;

  }

  *(unsigned int *)(puVar3 + 4) = (uVar9 << 0x10 | uVar21 >> 0x10) + puVar14[10];

  uVar18 = puVar14[8];

  uVar9 = puVar13[2];

  uVar1 = uVar18 ^ uVar9;

  if ((int)uVar18 < 0) {

    uVar18 = -uVar18;

  }

  if ((int)uVar9 < 0) {

    uVar9 = -uVar9;

  }

  uVar19 = (uVar9 & 0xffff) * (uVar18 & 0xffff);

  iVar7 = (uVar9 >> 0x10) * (uVar18 & 0xffff);

  iVar8 = 0;

  uVar2 = iVar7 + (uVar9 & 0xffff) * (uVar18 >> 0x10);

  if (iVar7 != 0) {

    iVar8 = 0x10000;

  }

  uVar21 = uVar19 + uVar2 * 0x10000;

  uVar9 = iVar8 + (unsigned int)(uVar21 < uVar19) + (uVar2 >> 0x10) + (uVar9 >> 0x10) * (uVar18 >> 0x10);

  if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

    uVar9 = ~uVar9;

    if (uVar21 == 0) {

      uVar9 = uVar9 + 1;

    }

    else {

      uVar21 = ~uVar21 + 1;

    }

  }

  if (((unsigned char)(uVar16 >> 1) & 1) == 1) {

    uVar21 = uVar20 + uVar21;

    uVar17 = uVar9 + (uVar21 < uVar20) + (uVar17 & 0xffff);

    if ((int)uVar17 < -0x8000) {

      uVar17 = 0xffff8000;

      uVar21 = 0;

    }

    if (0x7fff < (int)uVar17) {

      uVar17 = 0x7fff;

      uVar21 = 0xffffffff;

    }

    uVar17 = uVar17 & 0xffff;

  }

  else {

    uVar21 = uVar20 + uVar21;

    uVar17 = uVar9 + (uVar21 < uVar20) + uVar17;

  }

  *(unsigned int *)(puVar3 + 8) = (uVar17 << 0x10 | uVar21 >> 0x10) + puVar14[0xb];

  puVar4 = 0x0608A798;

  uVar17 = uVar16 & 0xfffffffe;

  *(unsigned short *)0x0608A798 = (unsigned short)(*(int *)(puVar3 + 8) <= unaff_r10);

  puVar3 = 0x0608A7D0;

  if ((puVar15[-3] & 0x80000) == 0) goto code_r0x0602a2be;

  goto LAB_0602a324;

code_r0x0602a2be:

  puVar13 = *(unsigned int **)0x0608A52C;

  uVar18 = *puVar13;

  uVar9 = *unaff_r8;

  uVar1 = uVar18 ^ uVar9;

  if ((int)uVar18 < 0) {

    uVar18 = -uVar18;

  }

  if ((int)uVar9 < 0) {

    uVar9 = -uVar9;

  }

  uVar19 = (uVar9 & 0xffff) * (uVar18 & 0xffff);

  iVar7 = (uVar9 >> 0x10) * (uVar18 & 0xffff);

  iVar8 = 0;

  uVar2 = iVar7 + (uVar9 & 0xffff) * (uVar18 >> 0x10);

  if (iVar7 != 0) {

    iVar8 = 0x10000;

  }

  uVar21 = uVar19 + uVar2 * 0x10000;

  uVar9 = iVar8 + (unsigned int)(uVar21 < uVar19) + (uVar2 >> 0x10) + (uVar9 >> 0x10) * (uVar18 >> 0x10);

  if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

    uVar9 = ~uVar9;

    if (uVar21 == 0) {

      uVar9 = uVar9 + 1;

    }

    else {

      uVar21 = ~uVar21 + 1;

    }

  }

  if (((unsigned char)(uVar16 >> 1) & 1) == 1) {

    if ((int)uVar9 < -0x8000) {

      uVar9 = 0xffff8000;

      uVar21 = 0;

    }

    if (0x7fff < (int)uVar9) {

      uVar9 = 0x7fff;

      uVar21 = 0xffffffff;

    }

    uVar9 = uVar9 & 0xffff;

  }

  uVar1 = puVar13[1];

  uVar18 = puVar15[-5];

  uVar2 = uVar1 ^ uVar18;

  if ((int)uVar1 < 0) {

    uVar1 = -uVar1;

  }

  if ((int)uVar18 < 0) {

    uVar18 = -uVar18;

  }

  uVar24 = (uVar18 & 0xffff) * (uVar1 & 0xffff);

  iVar7 = (uVar18 >> 0x10) * (uVar1 & 0xffff);

  iVar8 = 0;

  uVar19 = iVar7 + (uVar18 & 0xffff) * (uVar1 >> 0x10);

  if (iVar7 != 0) {

    iVar8 = 0x10000;

  }

  uVar22 = uVar24 + uVar19 * 0x10000;

  uVar18 = iVar8 + (unsigned int)(uVar22 < uVar24) + (uVar19 >> 0x10) + (uVar18 >> 0x10) * (uVar1 >> 0x10);

  if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

    uVar18 = ~uVar18;

    if (uVar22 == 0) {

      uVar18 = uVar18 + 1;

    }

    else {

      uVar22 = ~uVar22 + 1;

    }

  }

  if (((unsigned char)(uVar16 >> 1) & 1) == 1) {

    uVar22 = uVar21 + uVar22;

    uVar9 = uVar18 + (uVar22 < uVar21) + (uVar9 & 0xffff);

    if ((int)uVar9 < -0x8000) {

      uVar9 = 0xffff8000;

      uVar22 = 0;

    }

    if (0x7fff < (int)uVar9) {

      uVar9 = 0x7fff;

      uVar22 = 0xffffffff;

    }

    uVar9 = uVar9 & 0xffff;

  }

  else {

    uVar22 = uVar21 + uVar22;

    uVar9 = uVar18 + (uVar22 < uVar21) + uVar9;

  }

  uVar1 = puVar13[2];

  uVar18 = puVar15[-4];

  uVar2 = uVar1 ^ uVar18;

  if ((int)uVar1 < 0) {

    uVar1 = -uVar1;

  }

  if ((int)uVar18 < 0) {

    uVar18 = -uVar18;

  }

  uVar21 = (uVar18 & 0xffff) * (uVar1 & 0xffff);

  iVar7 = (uVar18 >> 0x10) * (uVar1 & 0xffff);

  iVar8 = 0;

  uVar19 = iVar7 + (uVar18 & 0xffff) * (uVar1 >> 0x10);

  if (iVar7 != 0) {

    iVar8 = 0x10000;

  }

  uVar24 = uVar21 + uVar19 * 0x10000;

  uVar18 = iVar8 + (unsigned int)(uVar24 < uVar21) + (uVar19 >> 0x10) + (uVar18 >> 0x10) * (uVar1 >> 0x10);

  if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

    uVar18 = ~uVar18;

    if (uVar24 == 0) {

      uVar18 = uVar18 + 1;

    }

    else {

      uVar24 = ~uVar24 + 1;

    }

  }

  if (((unsigned char)(uVar16 >> 1) & 1) == 1) {

    uVar24 = uVar22 + uVar24;

    uVar9 = uVar18 + (uVar24 < uVar22) + (uVar9 & 0xffff);

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

  else {

    uVar24 = uVar22 + uVar24;

    uVar9 = uVar18 + (uVar24 < uVar22) + uVar9;

  }

  uVar1 = puVar13[3];

  uVar18 = *unaff_r8;

  uVar2 = uVar1 ^ uVar18;

  if ((int)uVar1 < 0) {

    uVar1 = -uVar1;

  }

  if ((int)uVar18 < 0) {

    uVar18 = -uVar18;

  }

  uVar21 = (uVar18 & 0xffff) * (uVar1 & 0xffff);

  iVar7 = (uVar18 >> 0x10) * (uVar1 & 0xffff);

  iVar8 = 0;

  uVar19 = iVar7 + (uVar18 & 0xffff) * (uVar1 >> 0x10);

  if (iVar7 != 0) {

    iVar8 = 0x10000;

  }

  uVar22 = uVar21 + uVar19 * 0x10000;

  uVar18 = iVar8 + (unsigned int)(uVar22 < uVar21) + (uVar19 >> 0x10) + (uVar18 >> 0x10) * (uVar1 >> 0x10);

  if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

    uVar18 = ~uVar18;

    if (uVar22 == 0) {

      uVar18 = uVar18 + 1;

    }

    else {

      uVar22 = ~uVar22 + 1;

    }

  }

  if (((unsigned char)(uVar16 >> 1) & 1) == 1) {

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

  *(unsigned int *)0x0608A7D0 = uVar9 << 0x10 | uVar24 >> 0x10;

  uVar1 = puVar13[4];

  uVar9 = puVar15[-5];

  uVar2 = uVar1 ^ uVar9;

  if ((int)uVar1 < 0) {

    uVar1 = -uVar1;

  }

  if ((int)uVar9 < 0) {

    uVar9 = -uVar9;

  }

  uVar21 = (uVar9 & 0xffff) * (uVar1 & 0xffff);

  iVar7 = (uVar9 >> 0x10) * (uVar1 & 0xffff);

  iVar8 = 0;

  uVar19 = iVar7 + (uVar9 & 0xffff) * (uVar1 >> 0x10);

  if (iVar7 != 0) {

    iVar8 = 0x10000;

  }

  uVar24 = uVar21 + uVar19 * 0x10000;

  uVar9 = iVar8 + (unsigned int)(uVar24 < uVar21) + (uVar19 >> 0x10) + (uVar9 >> 0x10) * (uVar1 >> 0x10);

  if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

    uVar9 = ~uVar9;

    if (uVar24 == 0) {

      uVar9 = uVar9 + 1;

    }

    else {

      uVar24 = ~uVar24 + 1;

    }

  }

  if (((unsigned char)(uVar16 >> 1) & 1) == 1) {

    uVar24 = uVar22 + uVar24;

    uVar18 = uVar9 + (uVar24 < uVar22) + (uVar18 & 0xffff);

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

    uVar24 = uVar22 + uVar24;

    uVar18 = uVar9 + (uVar24 < uVar22) + uVar18;

  }

  uVar1 = puVar13[5];

  uVar9 = puVar15[-4];

  uVar2 = uVar1 ^ uVar9;

  if ((int)uVar1 < 0) {

    uVar1 = -uVar1;

  }

  if ((int)uVar9 < 0) {

    uVar9 = -uVar9;

  }

  uVar21 = (uVar9 & 0xffff) * (uVar1 & 0xffff);

  iVar7 = (uVar9 >> 0x10) * (uVar1 & 0xffff);

  iVar8 = 0;

  uVar19 = iVar7 + (uVar9 & 0xffff) * (uVar1 >> 0x10);

  if (iVar7 != 0) {

    iVar8 = 0x10000;

  }

  uVar22 = uVar21 + uVar19 * 0x10000;

  uVar9 = iVar8 + (unsigned int)(uVar22 < uVar21) + (uVar19 >> 0x10) + (uVar9 >> 0x10) * (uVar1 >> 0x10);

  if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

    uVar9 = ~uVar9;

    if (uVar22 == 0) {

      uVar9 = uVar9 + 1;

    }

    else {

      uVar22 = ~uVar22 + 1;

    }

  }

  if (((unsigned char)(uVar16 >> 1) & 1) == 1) {

    uVar22 = uVar24 + uVar22;

    uVar18 = uVar9 + (uVar22 < uVar24) + (uVar18 & 0xffff);

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

    uVar22 = uVar24 + uVar22;

    uVar18 = uVar9 + (uVar22 < uVar24) + uVar18;

  }

  uVar1 = puVar13[6];

  uVar9 = *unaff_r8;

  uVar2 = uVar1 ^ uVar9;

  if ((int)uVar1 < 0) {

    uVar1 = -uVar1;

  }

  if ((int)uVar9 < 0) {

    uVar9 = -uVar9;

  }

  uVar21 = (uVar9 & 0xffff) * (uVar1 & 0xffff);

  iVar7 = (uVar9 >> 0x10) * (uVar1 & 0xffff);

  iVar8 = 0;

  uVar19 = iVar7 + (uVar9 & 0xffff) * (uVar1 >> 0x10);

  if (iVar7 != 0) {

    iVar8 = 0x10000;

  }

  uVar24 = uVar21 + uVar19 * 0x10000;

  uVar9 = iVar8 + (unsigned int)(uVar24 < uVar21) + (uVar19 >> 0x10) + (uVar9 >> 0x10) * (uVar1 >> 0x10);

  if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

    uVar9 = ~uVar9;

    if (uVar24 == 0) {

      uVar9 = uVar9 + 1;

    }

    else {

      uVar24 = ~uVar24 + 1;

    }

  }

  if (((unsigned char)(uVar16 >> 1) & 1) == 1) {

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

  *(unsigned int *)(puVar3 + 4) = uVar18 << 0x10 | uVar22 >> 0x10;

  uVar1 = puVar13[7];

  uVar18 = puVar15[-5];

  uVar2 = uVar1 ^ uVar18;

  if ((int)uVar1 < 0) {

    uVar1 = -uVar1;

  }

  if ((int)uVar18 < 0) {

    uVar18 = -uVar18;

  }

  uVar21 = (uVar18 & 0xffff) * (uVar1 & 0xffff);

  iVar7 = (uVar18 >> 0x10) * (uVar1 & 0xffff);

  iVar8 = 0;

  uVar19 = iVar7 + (uVar18 & 0xffff) * (uVar1 >> 0x10);

  if (iVar7 != 0) {

    iVar8 = 0x10000;

  }

  uVar22 = uVar21 + uVar19 * 0x10000;

  uVar18 = iVar8 + (unsigned int)(uVar22 < uVar21) + (uVar19 >> 0x10) + (uVar18 >> 0x10) * (uVar1 >> 0x10);

  if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

    uVar18 = ~uVar18;

    if (uVar22 == 0) {

      uVar18 = uVar18 + 1;

    }

    else {

      uVar22 = ~uVar22 + 1;

    }

  }

  if (((unsigned char)(uVar16 >> 1) & 1) == 1) {

    uVar22 = uVar24 + uVar22;

    uVar9 = uVar18 + (uVar22 < uVar24) + (uVar9 & 0xffff);

    if ((int)uVar9 < -0x8000) {

      uVar9 = 0xffff8000;

      uVar22 = 0;

    }

    if (0x7fff < (int)uVar9) {

      uVar9 = 0x7fff;

      uVar22 = 0xffffffff;

    }

    uVar9 = uVar9 & 0xffff;

  }

  else {

    uVar22 = uVar24 + uVar22;

    uVar9 = uVar18 + (uVar22 < uVar24) + uVar9;

  }

  uVar1 = puVar13[8];

  uVar18 = puVar15[-4];

  uVar2 = uVar1 ^ uVar18;

  if ((int)uVar1 < 0) {

    uVar1 = -uVar1;

  }

  if ((int)uVar18 < 0) {

    uVar18 = -uVar18;

  }

  uVar21 = (uVar18 & 0xffff) * (uVar1 & 0xffff);

  iVar7 = (uVar18 >> 0x10) * (uVar1 & 0xffff);

  iVar8 = 0;

  uVar19 = iVar7 + (uVar18 & 0xffff) * (uVar1 >> 0x10);

  if (iVar7 != 0) {

    iVar8 = 0x10000;

  }

  uVar24 = uVar21 + uVar19 * 0x10000;

  uVar18 = iVar8 + (unsigned int)(uVar24 < uVar21) + (uVar19 >> 0x10) + (uVar18 >> 0x10) * (uVar1 >> 0x10);

  if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

    uVar18 = ~uVar18;

    if (uVar24 == 0) {

      uVar18 = uVar18 + 1;

    }

    else {

      uVar24 = ~uVar24 + 1;

    }

  }

  if (((unsigned char)(uVar16 >> 1) & 1) == 1) {

    uVar24 = uVar22 + uVar24;

    uVar9 = uVar18 + (uVar24 < uVar22) + (uVar9 & 0xffff);

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

  else {

    uVar24 = uVar22 + uVar24;

    uVar9 = uVar18 + (uVar24 < uVar22) + uVar9;

  }

  *(unsigned int *)(puVar3 + 8) = uVar9 << 0x10 | uVar24 >> 0x10;

  uVar18 = *(unsigned int *)puVar3;

  uVar9 = *(unsigned int *)0x0608A7A0;

  uVar1 = uVar18 ^ uVar9;

  if ((int)uVar18 < 0) {

    uVar18 = -uVar18;

  }

  if ((int)uVar9 < 0) {

    uVar9 = -uVar9;

  }

  uVar19 = (uVar9 & 0xffff) * (uVar18 & 0xffff);

  iVar7 = (uVar9 >> 0x10) * (uVar18 & 0xffff);

  iVar8 = 0;

  uVar2 = iVar7 + (uVar9 & 0xffff) * (uVar18 >> 0x10);

  if (iVar7 != 0) {

    iVar8 = 0x10000;

  }

  uVar21 = uVar19 + uVar2 * 0x10000;

  uVar9 = iVar8 + (unsigned int)(uVar21 < uVar19) + (uVar2 >> 0x10) + (uVar9 >> 0x10) * (uVar18 >> 0x10);

  if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

    uVar9 = ~uVar9;

    if (uVar21 == 0) {

      uVar9 = uVar9 + 1;

    }

    else {

      uVar21 = ~uVar21 + 1;

    }

  }

  if (((unsigned char)(uVar16 >> 1) & 1) == 1) {

    if ((int)uVar9 < -0x8000) {

      uVar9 = 0xffff8000;

      uVar21 = 0;

    }

    if (0x7fff < (int)uVar9) {

      uVar9 = 0x7fff;

      uVar21 = 0xffffffff;

    }

    uVar9 = uVar9 & 0xffff;

  }

  uVar1 = *(unsigned int *)(puVar3 + 4);

  uVar18 = *(unsigned int *)(0x0608A7A0 + 4);

  uVar2 = uVar1 ^ uVar18;

  if ((int)uVar1 < 0) {

    uVar1 = -uVar1;

  }

  if ((int)uVar18 < 0) {

    uVar18 = -uVar18;

  }

  uVar24 = (uVar18 & 0xffff) * (uVar1 & 0xffff);

  iVar7 = (uVar18 >> 0x10) * (uVar1 & 0xffff);

  iVar8 = 0;

  uVar19 = iVar7 + (uVar18 & 0xffff) * (uVar1 >> 0x10);

  if (iVar7 != 0) {

    iVar8 = 0x10000;

  }

  uVar22 = uVar24 + uVar19 * 0x10000;

  uVar18 = iVar8 + (unsigned int)(uVar22 < uVar24) + (uVar19 >> 0x10) + (uVar18 >> 0x10) * (uVar1 >> 0x10);

  if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

    uVar18 = ~uVar18;

    if (uVar22 == 0) {

      uVar18 = uVar18 + 1;

    }

    else {

      uVar22 = ~uVar22 + 1;

    }

  }

  if (((unsigned char)(uVar16 >> 1) & 1) == 1) {

    uVar22 = uVar21 + uVar22;

    uVar9 = uVar18 + (uVar22 < uVar21) + (uVar9 & 0xffff);

    if ((int)uVar9 < -0x8000) {

      uVar9 = 0xffff8000;

      uVar22 = 0;

    }

    if (0x7fff < (int)uVar9) {

      uVar9 = 0x7fff;

      uVar22 = 0xffffffff;

    }

    uVar9 = uVar9 & 0xffff;

  }

  else {

    uVar22 = uVar21 + uVar22;

    uVar9 = uVar18 + (uVar22 < uVar21) + uVar9;

  }

  uVar1 = *(unsigned int *)(puVar3 + 8);

  uVar18 = *(unsigned int *)(0x0608A7A0 + 8);

  uVar2 = uVar1 ^ uVar18;

  if ((int)uVar1 < 0) {

    uVar1 = -uVar1;

  }

  if ((int)uVar18 < 0) {

    uVar18 = -uVar18;

  }

  uVar21 = (uVar18 & 0xffff) * (uVar1 & 0xffff);

  iVar7 = (uVar18 >> 0x10) * (uVar1 & 0xffff);

  iVar8 = 0;

  uVar19 = iVar7 + (uVar18 & 0xffff) * (uVar1 >> 0x10);

  if (iVar7 != 0) {

    iVar8 = 0x10000;

  }

  uVar24 = uVar21 + uVar19 * 0x10000;

  uVar18 = iVar8 + (unsigned int)(uVar24 < uVar21) + (uVar19 >> 0x10) + (uVar18 >> 0x10) * (uVar1 >> 0x10);

  if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

    uVar18 = ~uVar18;

    if (uVar24 == 0) {

      uVar18 = uVar18 + 1;

    }

    else {

      uVar24 = ~uVar24 + 1;

    }

  }

  if (((unsigned char)(uVar16 >> 1) & 1) == 1) {

    uVar24 = uVar22 + uVar24;

    uVar9 = uVar18 + (uVar24 < uVar22) + (uVar9 & 0xffff);

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

  else {

    uVar24 = uVar22 + uVar24;

    uVar9 = uVar18 + (uVar24 < uVar22) + uVar9;

  }

  uVar9 = uVar9 << 0x10 | uVar24 >> 0x10;

  uVar17 = uVar17 | 0 < (int)uVar9;

  if (((unsigned char)uVar17 & 1) == 1) {

LAB_0602a324:

    puVar3 = 0x0608A7AC;

    puVar13 = (unsigned int *)((unsigned int)*(unsigned short *)((int)puVar15 + -6) * 0xc + param_6);

    puVar14 = *(unsigned int **)0x0608A52C;

    uVar16 = *puVar14;

    uVar9 = *puVar13;

    uVar18 = uVar16 ^ uVar9;

    if ((int)uVar16 < 0) {

      uVar16 = -uVar16;

    }

    if ((int)uVar9 < 0) {

      uVar9 = -uVar9;

    }

    uVar2 = (uVar9 & 0xffff) * (uVar16 & 0xffff);

    iVar7 = (uVar9 >> 0x10) * (uVar16 & 0xffff);

    iVar8 = 0;

    uVar1 = iVar7 + (uVar9 & 0xffff) * (uVar16 >> 0x10);

    if (iVar7 != 0) {

      iVar8 = 0x10000;

    }

    uVar19 = uVar2 + uVar1 * 0x10000;

    uVar9 = iVar8 + (unsigned int)(uVar19 < uVar2) + (uVar1 >> 0x10) + (uVar9 >> 0x10) * (uVar16 >> 0x10);

    if ((int)-(unsigned int)((int)uVar18 < 0) < 0) {

      uVar9 = ~uVar9;

      if (uVar19 == 0) {

        uVar9 = uVar9 + 1;

      }

      else {

        uVar19 = ~uVar19 + 1;

      }

    }

    if (((unsigned char)(uVar17 >> 1) & 1) == 1) {

      if ((int)uVar9 < -0x8000) {

        uVar9 = 0xffff8000;

        uVar19 = 0;

      }

      if (0x7fff < (int)uVar9) {

        uVar9 = 0x7fff;

        uVar19 = 0xffffffff;

      }

      uVar9 = uVar9 & 0xffff;

    }

    uVar18 = puVar14[1];

    uVar16 = puVar13[1];

    uVar1 = uVar18 ^ uVar16;

    if ((int)uVar18 < 0) {

      uVar18 = -uVar18;

    }

    if ((int)uVar16 < 0) {

      uVar16 = -uVar16;

    }

    uVar21 = (uVar16 & 0xffff) * (uVar18 & 0xffff);

    iVar7 = (uVar16 >> 0x10) * (uVar18 & 0xffff);

    iVar8 = 0;

    uVar2 = iVar7 + (uVar16 & 0xffff) * (uVar18 >> 0x10);

    if (iVar7 != 0) {

      iVar8 = 0x10000;

    }

    uVar24 = uVar21 + uVar2 * 0x10000;

    uVar16 = iVar8 + (unsigned int)(uVar24 < uVar21) + (uVar2 >> 0x10) + (uVar16 >> 0x10) * (uVar18 >> 0x10)

    ;

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

      uVar24 = uVar19 + uVar24;

      uVar9 = uVar16 + (uVar24 < uVar19) + (uVar9 & 0xffff);

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

    else {

      uVar24 = uVar19 + uVar24;

      uVar9 = uVar16 + (uVar24 < uVar19) + uVar9;

    }

    uVar18 = puVar14[2];

    uVar16 = puVar13[2];

    uVar1 = uVar18 ^ uVar16;

    if ((int)uVar18 < 0) {

      uVar18 = -uVar18;

    }

    if ((int)uVar16 < 0) {

      uVar16 = -uVar16;

    }

    uVar19 = (uVar16 & 0xffff) * (uVar18 & 0xffff);

    iVar7 = (uVar16 >> 0x10) * (uVar18 & 0xffff);

    iVar8 = 0;

    uVar2 = iVar7 + (uVar16 & 0xffff) * (uVar18 >> 0x10);

    if (iVar7 != 0) {

      iVar8 = 0x10000;

    }

    uVar21 = uVar19 + uVar2 * 0x10000;

    uVar16 = iVar8 + (unsigned int)(uVar21 < uVar19) + (uVar2 >> 0x10) + (uVar16 >> 0x10) * (uVar18 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

      uVar16 = ~uVar16;

      if (uVar21 == 0) {

        uVar16 = uVar16 + 1;

      }

      else {

        uVar21 = ~uVar21 + 1;

      }

    }

    if (((unsigned char)(uVar17 >> 1) & 1) == 1) {

      uVar21 = uVar24 + uVar21;

      uVar9 = uVar16 + (uVar21 < uVar24) + (uVar9 & 0xffff);

      if ((int)uVar9 < -0x8000) {

        uVar9 = 0xffff8000;

        uVar21 = 0;

      }

      if (0x7fff < (int)uVar9) {

        uVar9 = 0x7fff;

        uVar21 = 0xffffffff;

      }

      uVar9 = uVar9 & 0xffff;

    }

    else {

      uVar21 = uVar24 + uVar21;

      uVar9 = uVar16 + (uVar21 < uVar24) + uVar9;

    }

    uVar18 = puVar14[3];

    uVar16 = *puVar13;

    uVar1 = uVar18 ^ uVar16;

    if ((int)uVar18 < 0) {

      uVar18 = -uVar18;

    }

    if ((int)uVar16 < 0) {

      uVar16 = -uVar16;

    }

    uVar19 = (uVar16 & 0xffff) * (uVar18 & 0xffff);

    iVar7 = (uVar16 >> 0x10) * (uVar18 & 0xffff);

    iVar8 = 0;

    uVar2 = iVar7 + (uVar16 & 0xffff) * (uVar18 >> 0x10);

    if (iVar7 != 0) {

      iVar8 = 0x10000;

    }

    uVar24 = uVar19 + uVar2 * 0x10000;

    uVar16 = iVar8 + (unsigned int)(uVar24 < uVar19) + (uVar2 >> 0x10) + (uVar16 >> 0x10) * (uVar18 >> 0x10)

    ;

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

    uVar1 = puVar14[4];

    uVar18 = puVar13[1];

    uVar2 = uVar1 ^ uVar18;

    if ((int)uVar1 < 0) {

      uVar1 = -uVar1;

    }

    if ((int)uVar18 < 0) {

      uVar18 = -uVar18;

    }

    uVar22 = (uVar18 & 0xffff) * (uVar1 & 0xffff);

    iVar7 = (uVar18 >> 0x10) * (uVar1 & 0xffff);

    iVar8 = 0;

    uVar19 = iVar7 + (uVar18 & 0xffff) * (uVar1 >> 0x10);

    if (iVar7 != 0) {

      iVar8 = 0x10000;

    }

    uVar20 = uVar22 + uVar19 * 0x10000;

    uVar18 = iVar8 + (unsigned int)(uVar20 < uVar22) + (uVar19 >> 0x10) + (uVar18 >> 0x10) * (uVar1 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

      uVar18 = ~uVar18;

      if (uVar20 == 0) {

        uVar18 = uVar18 + 1;

      }

      else {

        uVar20 = ~uVar20 + 1;

      }

    }

    if (((unsigned char)(uVar17 >> 1) & 1) == 1) {

      uVar20 = uVar24 + uVar20;

      uVar16 = uVar18 + (uVar20 < uVar24) + (uVar16 & 0xffff);

      if ((int)uVar16 < -0x8000) {

        uVar16 = 0xffff8000;

        uVar20 = 0;

      }

      if (0x7fff < (int)uVar16) {

        uVar16 = 0x7fff;

        uVar20 = 0xffffffff;

      }

      uVar16 = uVar16 & 0xffff;

    }

    else {

      uVar20 = uVar24 + uVar20;

      uVar16 = uVar18 + (uVar20 < uVar24) + uVar16;

    }

    *(unsigned int *)0x0608A7AC = (uVar9 << 0x10 | uVar21 >> 0x10) + puVar14[9];

    uVar18 = puVar14[5];

    uVar9 = puVar13[2];

    uVar1 = uVar18 ^ uVar9;

    if ((int)uVar18 < 0) {

      uVar18 = -uVar18;

    }

    if ((int)uVar9 < 0) {

      uVar9 = -uVar9;

    }

    uVar19 = (uVar9 & 0xffff) * (uVar18 & 0xffff);

    iVar7 = (uVar9 >> 0x10) * (uVar18 & 0xffff);

    iVar8 = 0;

    uVar2 = iVar7 + (uVar9 & 0xffff) * (uVar18 >> 0x10);

    if (iVar7 != 0) {

      iVar8 = 0x10000;

    }

    uVar21 = uVar19 + uVar2 * 0x10000;

    uVar9 = iVar8 + (unsigned int)(uVar21 < uVar19) + (uVar2 >> 0x10) + (uVar9 >> 0x10) * (uVar18 >> 0x10);

    if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

      uVar9 = ~uVar9;

      if (uVar21 == 0) {

        uVar9 = uVar9 + 1;

      }

      else {

        uVar21 = ~uVar21 + 1;

      }

    }

    if (((unsigned char)(uVar17 >> 1) & 1) == 1) {

      uVar21 = uVar20 + uVar21;

      uVar16 = uVar9 + (uVar21 < uVar20) + (uVar16 & 0xffff);

      if ((int)uVar16 < -0x8000) {

        uVar16 = 0xffff8000;

        uVar21 = 0;

      }

      if (0x7fff < (int)uVar16) {

        uVar16 = 0x7fff;

        uVar21 = 0xffffffff;

      }

      uVar16 = uVar16 & 0xffff;

    }

    else {

      uVar21 = uVar20 + uVar21;

      uVar16 = uVar9 + (uVar21 < uVar20) + uVar16;

    }

    uVar18 = puVar14[6];

    uVar9 = *puVar13;

    uVar1 = uVar18 ^ uVar9;

    if ((int)uVar18 < 0) {

      uVar18 = -uVar18;

    }

    if ((int)uVar9 < 0) {

      uVar9 = -uVar9;

    }

    uVar19 = (uVar9 & 0xffff) * (uVar18 & 0xffff);

    iVar7 = (uVar9 >> 0x10) * (uVar18 & 0xffff);

    iVar8 = 0;

    uVar2 = iVar7 + (uVar9 & 0xffff) * (uVar18 >> 0x10);

    if (iVar7 != 0) {

      iVar8 = 0x10000;

    }

    uVar24 = uVar19 + uVar2 * 0x10000;

    uVar9 = iVar8 + (unsigned int)(uVar24 < uVar19) + (uVar2 >> 0x10) + (uVar9 >> 0x10) * (uVar18 >> 0x10);

    if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

      uVar9 = ~uVar9;

      if (uVar24 == 0) {

        uVar9 = uVar9 + 1;

      }

      else {

        uVar24 = ~uVar24 + 1;

      }

    }

    if (((unsigned char)(uVar17 >> 1) & 1) == 1) {

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

    uVar1 = puVar14[7];

    uVar18 = puVar13[1];

    uVar2 = uVar1 ^ uVar18;

    if ((int)uVar1 < 0) {

      uVar1 = -uVar1;

    }

    if ((int)uVar18 < 0) {

      uVar18 = -uVar18;

    }

    uVar22 = (uVar18 & 0xffff) * (uVar1 & 0xffff);

    iVar7 = (uVar18 >> 0x10) * (uVar1 & 0xffff);

    iVar8 = 0;

    uVar19 = iVar7 + (uVar18 & 0xffff) * (uVar1 >> 0x10);

    if (iVar7 != 0) {

      iVar8 = 0x10000;

    }

    uVar20 = uVar22 + uVar19 * 0x10000;

    uVar18 = iVar8 + (unsigned int)(uVar20 < uVar22) + (uVar19 >> 0x10) + (uVar18 >> 0x10) * (uVar1 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

      uVar18 = ~uVar18;

      if (uVar20 == 0) {

        uVar18 = uVar18 + 1;

      }

      else {

        uVar20 = ~uVar20 + 1;

      }

    }

    if (((unsigned char)(uVar17 >> 1) & 1) == 1) {

      uVar20 = uVar24 + uVar20;

      uVar9 = uVar18 + (uVar20 < uVar24) + (uVar9 & 0xffff);

      if ((int)uVar9 < -0x8000) {

        uVar9 = 0xffff8000;

        uVar20 = 0;

      }

      if (0x7fff < (int)uVar9) {

        uVar9 = 0x7fff;

        uVar20 = 0xffffffff;

      }

      uVar9 = uVar9 & 0xffff;

    }

    else {

      uVar20 = uVar24 + uVar20;

      uVar9 = uVar18 + (uVar20 < uVar24) + uVar9;

    }

    *(unsigned int *)(puVar3 + 4) = (uVar16 << 0x10 | uVar21 >> 0x10) + puVar14[10];

    uVar18 = puVar14[8];

    uVar16 = puVar13[2];

    uVar1 = uVar18 ^ uVar16;

    if ((int)uVar18 < 0) {

      uVar18 = -uVar18;

    }

    if ((int)uVar16 < 0) {

      uVar16 = -uVar16;

    }

    uVar19 = (uVar16 & 0xffff) * (uVar18 & 0xffff);

    iVar7 = (uVar16 >> 0x10) * (uVar18 & 0xffff);

    iVar8 = 0;

    uVar2 = iVar7 + (uVar16 & 0xffff) * (uVar18 >> 0x10);

    if (iVar7 != 0) {

      iVar8 = 0x10000;

    }

    uVar21 = uVar19 + uVar2 * 0x10000;

    uVar16 = iVar8 + (unsigned int)(uVar21 < uVar19) + (uVar2 >> 0x10) + (uVar16 >> 0x10) * (uVar18 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

      uVar16 = ~uVar16;

      if (uVar21 == 0) {

        uVar16 = uVar16 + 1;

      }

      else {

        uVar21 = ~uVar21 + 1;

      }

    }

    if (((unsigned char)(uVar17 >> 1) & 1) == 1) {

      uVar21 = uVar20 + uVar21;

      uVar9 = uVar16 + (uVar21 < uVar20) + (uVar9 & 0xffff);

      if ((int)uVar9 < -0x8000) {

        uVar9 = 0xffff8000;

        uVar21 = 0;

      }

      if (0x7fff < (int)uVar9) {

        uVar9 = 0x7fff;

        uVar21 = 0xffffffff;

      }

      uVar9 = uVar9 & 0xffff;

    }

    else {

      uVar21 = uVar20 + uVar21;

      uVar9 = uVar16 + (uVar21 < uVar20) + uVar9;

    }

    *(unsigned int *)(puVar3 + 8) = (uVar9 << 0x10 | uVar21 >> 0x10) + puVar14[0xb];

    uVar16 = uVar17 & 0xfffffffe;

    *(unsigned short *)(puVar4 + 2) = (unsigned short)(*(int *)(puVar3 + 8) <= unaff_r10);

    puVar3 = 0x0608A7B8;

    puVar13 = (unsigned int *)((unsigned int)*(unsigned short *)(puVar15 + -1) * 0xc + param_6);

    puVar14 = *(unsigned int **)0x0608A52C;

    uVar18 = *puVar14;

    uVar9 = *puVar13;

    uVar1 = uVar18 ^ uVar9;

    if ((int)uVar18 < 0) {

      uVar18 = -uVar18;

    }

    if ((int)uVar9 < 0) {

      uVar9 = -uVar9;

    }

    uVar19 = (uVar9 & 0xffff) * (uVar18 & 0xffff);

    iVar7 = (uVar9 >> 0x10) * (uVar18 & 0xffff);

    iVar8 = 0;

    uVar2 = iVar7 + (uVar9 & 0xffff) * (uVar18 >> 0x10);

    if (iVar7 != 0) {

      iVar8 = 0x10000;

    }

    uVar21 = uVar19 + uVar2 * 0x10000;

    uVar9 = iVar8 + (unsigned int)(uVar21 < uVar19) + (uVar2 >> 0x10) + (uVar9 >> 0x10) * (uVar18 >> 0x10);

    if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

      uVar9 = ~uVar9;

      if (uVar21 == 0) {

        uVar9 = uVar9 + 1;

      }

      else {

        uVar21 = ~uVar21 + 1;

      }

    }

    if (((unsigned char)(uVar17 >> 1) & 1) == 1) {

      if ((int)uVar9 < -0x8000) {

        uVar9 = 0xffff8000;

        uVar21 = 0;

      }

      if (0x7fff < (int)uVar9) {

        uVar9 = 0x7fff;

        uVar21 = 0xffffffff;

      }

      uVar9 = uVar9 & 0xffff;

    }

    uVar1 = puVar14[1];

    uVar18 = puVar13[1];

    uVar2 = uVar1 ^ uVar18;

    if ((int)uVar1 < 0) {

      uVar1 = -uVar1;

    }

    if ((int)uVar18 < 0) {

      uVar18 = -uVar18;

    }

    uVar24 = (uVar18 & 0xffff) * (uVar1 & 0xffff);

    iVar7 = (uVar18 >> 0x10) * (uVar1 & 0xffff);

    iVar8 = 0;

    uVar19 = iVar7 + (uVar18 & 0xffff) * (uVar1 >> 0x10);

    if (iVar7 != 0) {

      iVar8 = 0x10000;

    }

    uVar22 = uVar24 + uVar19 * 0x10000;

    uVar18 = iVar8 + (unsigned int)(uVar22 < uVar24) + (uVar19 >> 0x10) + (uVar18 >> 0x10) * (uVar1 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

      uVar18 = ~uVar18;

      if (uVar22 == 0) {

        uVar18 = uVar18 + 1;

      }

      else {

        uVar22 = ~uVar22 + 1;

      }

    }

    if (((unsigned char)(uVar17 >> 1) & 1) == 1) {

      uVar22 = uVar21 + uVar22;

      uVar9 = uVar18 + (uVar22 < uVar21) + (uVar9 & 0xffff);

      if ((int)uVar9 < -0x8000) {

        uVar9 = 0xffff8000;

        uVar22 = 0;

      }

      if (0x7fff < (int)uVar9) {

        uVar9 = 0x7fff;

        uVar22 = 0xffffffff;

      }

      uVar9 = uVar9 & 0xffff;

    }

    else {

      uVar22 = uVar21 + uVar22;

      uVar9 = uVar18 + (uVar22 < uVar21) + uVar9;

    }

    uVar1 = puVar14[2];

    uVar18 = puVar13[2];

    uVar2 = uVar1 ^ uVar18;

    if ((int)uVar1 < 0) {

      uVar1 = -uVar1;

    }

    if ((int)uVar18 < 0) {

      uVar18 = -uVar18;

    }

    uVar21 = (uVar18 & 0xffff) * (uVar1 & 0xffff);

    iVar7 = (uVar18 >> 0x10) * (uVar1 & 0xffff);

    iVar8 = 0;

    uVar19 = iVar7 + (uVar18 & 0xffff) * (uVar1 >> 0x10);

    if (iVar7 != 0) {

      iVar8 = 0x10000;

    }

    uVar24 = uVar21 + uVar19 * 0x10000;

    uVar18 = iVar8 + (unsigned int)(uVar24 < uVar21) + (uVar19 >> 0x10) + (uVar18 >> 0x10) * (uVar1 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

      uVar18 = ~uVar18;

      if (uVar24 == 0) {

        uVar18 = uVar18 + 1;

      }

      else {

        uVar24 = ~uVar24 + 1;

      }

    }

    if (((unsigned char)(uVar17 >> 1) & 1) == 1) {

      uVar24 = uVar22 + uVar24;

      uVar9 = uVar18 + (uVar24 < uVar22) + (uVar9 & 0xffff);

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

    else {

      uVar24 = uVar22 + uVar24;

      uVar9 = uVar18 + (uVar24 < uVar22) + uVar9;

    }

    uVar1 = puVar14[3];

    uVar18 = *puVar13;

    uVar2 = uVar1 ^ uVar18;

    if ((int)uVar1 < 0) {

      uVar1 = -uVar1;

    }

    if ((int)uVar18 < 0) {

      uVar18 = -uVar18;

    }

    uVar21 = (uVar18 & 0xffff) * (uVar1 & 0xffff);

    iVar7 = (uVar18 >> 0x10) * (uVar1 & 0xffff);

    iVar8 = 0;

    uVar19 = iVar7 + (uVar18 & 0xffff) * (uVar1 >> 0x10);

    if (iVar7 != 0) {

      iVar8 = 0x10000;

    }

    uVar22 = uVar21 + uVar19 * 0x10000;

    uVar18 = iVar8 + (unsigned int)(uVar22 < uVar21) + (uVar19 >> 0x10) + (uVar18 >> 0x10) * (uVar1 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

      uVar18 = ~uVar18;

      if (uVar22 == 0) {

        uVar18 = uVar18 + 1;

      }

      else {

        uVar22 = ~uVar22 + 1;

      }

    }

    if (((unsigned char)(uVar17 >> 1) & 1) == 1) {

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

    uVar2 = puVar14[4];

    uVar1 = puVar13[1];

    uVar19 = uVar2 ^ uVar1;

    if ((int)uVar2 < 0) {

      uVar2 = -uVar2;

    }

    if ((int)uVar1 < 0) {

      uVar1 = -uVar1;

    }

    uVar20 = (uVar1 & 0xffff) * (uVar2 & 0xffff);

    iVar7 = (uVar1 >> 0x10) * (uVar2 & 0xffff);

    iVar8 = 0;

    uVar21 = iVar7 + (uVar1 & 0xffff) * (uVar2 >> 0x10);

    if (iVar7 != 0) {

      iVar8 = 0x10000;

    }

    uVar23 = uVar20 + uVar21 * 0x10000;

    uVar1 = iVar8 + (unsigned int)(uVar23 < uVar20) + (uVar21 >> 0x10) + (uVar1 >> 0x10) * (uVar2 >> 0x10);

    if ((int)-(unsigned int)((int)uVar19 < 0) < 0) {

      uVar1 = ~uVar1;

      if (uVar23 == 0) {

        uVar1 = uVar1 + 1;

      }

      else {

        uVar23 = ~uVar23 + 1;

      }

    }

    if (((unsigned char)(uVar17 >> 1) & 1) == 1) {

      uVar23 = uVar22 + uVar23;

      uVar18 = uVar1 + (uVar23 < uVar22) + (uVar18 & 0xffff);

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

      uVar23 = uVar22 + uVar23;

      uVar18 = uVar1 + (uVar23 < uVar22) + uVar18;

    }

    *(unsigned int *)0x0608A7B8 = (uVar9 << 0x10 | uVar24 >> 0x10) + puVar14[9];

    uVar1 = puVar14[5];

    uVar9 = puVar13[2];

    uVar2 = uVar1 ^ uVar9;

    if ((int)uVar1 < 0) {

      uVar1 = -uVar1;

    }

    if ((int)uVar9 < 0) {

      uVar9 = -uVar9;

    }

    uVar21 = (uVar9 & 0xffff) * (uVar1 & 0xffff);

    iVar7 = (uVar9 >> 0x10) * (uVar1 & 0xffff);

    iVar8 = 0;

    uVar19 = iVar7 + (uVar9 & 0xffff) * (uVar1 >> 0x10);

    if (iVar7 != 0) {

      iVar8 = 0x10000;

    }

    uVar24 = uVar21 + uVar19 * 0x10000;

    uVar9 = iVar8 + (unsigned int)(uVar24 < uVar21) + (uVar19 >> 0x10) + (uVar9 >> 0x10) * (uVar1 >> 0x10);

    if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

      uVar9 = ~uVar9;

      if (uVar24 == 0) {

        uVar9 = uVar9 + 1;

      }

      else {

        uVar24 = ~uVar24 + 1;

      }

    }

    if (((unsigned char)(uVar17 >> 1) & 1) == 1) {

      uVar24 = uVar23 + uVar24;

      uVar18 = uVar9 + (uVar24 < uVar23) + (uVar18 & 0xffff);

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

      uVar18 = uVar9 + (uVar24 < uVar23) + uVar18;

    }

    uVar1 = puVar14[6];

    uVar9 = *puVar13;

    uVar2 = uVar1 ^ uVar9;

    if ((int)uVar1 < 0) {

      uVar1 = -uVar1;

    }

    if ((int)uVar9 < 0) {

      uVar9 = -uVar9;

    }

    uVar21 = (uVar9 & 0xffff) * (uVar1 & 0xffff);

    iVar7 = (uVar9 >> 0x10) * (uVar1 & 0xffff);

    iVar8 = 0;

    uVar19 = iVar7 + (uVar9 & 0xffff) * (uVar1 >> 0x10);

    if (iVar7 != 0) {

      iVar8 = 0x10000;

    }

    uVar22 = uVar21 + uVar19 * 0x10000;

    uVar9 = iVar8 + (unsigned int)(uVar22 < uVar21) + (uVar19 >> 0x10) + (uVar9 >> 0x10) * (uVar1 >> 0x10);

    if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

      uVar9 = ~uVar9;

      if (uVar22 == 0) {

        uVar9 = uVar9 + 1;

      }

      else {

        uVar22 = ~uVar22 + 1;

      }

    }

    if (((unsigned char)(uVar17 >> 1) & 1) == 1) {

      if ((int)uVar9 < -0x8000) {

        uVar9 = 0xffff8000;

        uVar22 = 0;

      }

      if (0x7fff < (int)uVar9) {

        uVar9 = 0x7fff;

        uVar22 = 0xffffffff;

      }

      uVar9 = uVar9 & 0xffff;

    }

    uVar2 = puVar14[7];

    uVar1 = puVar13[1];

    uVar19 = uVar2 ^ uVar1;

    if ((int)uVar2 < 0) {

      uVar2 = -uVar2;

    }

    if ((int)uVar1 < 0) {

      uVar1 = -uVar1;

    }

    uVar20 = (uVar1 & 0xffff) * (uVar2 & 0xffff);

    iVar7 = (uVar1 >> 0x10) * (uVar2 & 0xffff);

    iVar8 = 0;

    uVar21 = iVar7 + (uVar1 & 0xffff) * (uVar2 >> 0x10);

    if (iVar7 != 0) {

      iVar8 = 0x10000;

    }

    uVar23 = uVar20 + uVar21 * 0x10000;

    uVar1 = iVar8 + (unsigned int)(uVar23 < uVar20) + (uVar21 >> 0x10) + (uVar1 >> 0x10) * (uVar2 >> 0x10);

    if ((int)-(unsigned int)((int)uVar19 < 0) < 0) {

      uVar1 = ~uVar1;

      if (uVar23 == 0) {

        uVar1 = uVar1 + 1;

      }

      else {

        uVar23 = ~uVar23 + 1;

      }

    }

    if (((unsigned char)(uVar17 >> 1) & 1) == 1) {

      uVar23 = uVar22 + uVar23;

      uVar9 = uVar1 + (uVar23 < uVar22) + (uVar9 & 0xffff);

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

      uVar23 = uVar22 + uVar23;

      uVar9 = uVar1 + (uVar23 < uVar22) + uVar9;

    }

    *(unsigned int *)(puVar3 + 4) = (uVar18 << 0x10 | uVar24 >> 0x10) + puVar14[10];

    uVar1 = puVar14[8];

    uVar18 = puVar13[2];

    uVar2 = uVar1 ^ uVar18;

    if ((int)uVar1 < 0) {

      uVar1 = -uVar1;

    }

    if ((int)uVar18 < 0) {

      uVar18 = -uVar18;

    }

    uVar21 = (uVar18 & 0xffff) * (uVar1 & 0xffff);

    iVar7 = (uVar18 >> 0x10) * (uVar1 & 0xffff);

    iVar8 = 0;

    uVar19 = iVar7 + (uVar18 & 0xffff) * (uVar1 >> 0x10);

    if (iVar7 != 0) {

      iVar8 = 0x10000;

    }

    uVar24 = uVar21 + uVar19 * 0x10000;

    uVar18 = iVar8 + (unsigned int)(uVar24 < uVar21) + (uVar19 >> 0x10) + (uVar18 >> 0x10) * (uVar1 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

      uVar18 = ~uVar18;

      if (uVar24 == 0) {

        uVar18 = uVar18 + 1;

      }

      else {

        uVar24 = ~uVar24 + 1;

      }

    }

    if (((unsigned char)(uVar17 >> 1) & 1) == 1) {

      uVar24 = uVar23 + uVar24;

      uVar9 = uVar18 + (uVar24 < uVar23) + (uVar9 & 0xffff);

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

    else {

      uVar24 = uVar23 + uVar24;

      uVar9 = uVar18 + (uVar24 < uVar23) + uVar9;

    }

    *(unsigned int *)(puVar3 + 8) = (uVar9 << 0x10 | uVar24 >> 0x10) + puVar14[0xb];

    *(unsigned short *)(puVar4 + 4) = (unsigned short)(*(int *)(puVar3 + 8) <= unaff_r10);

    puVar3 = 0x0608A7C4;

    puVar13 = (unsigned int *)((unsigned int)*(unsigned short *)((int)puVar15 + -2) * 0xc + param_6);

    puVar14 = *(unsigned int **)0x0608A52C;

    uVar18 = *puVar14;

    uVar9 = *puVar13;

    uVar1 = uVar18 ^ uVar9;

    if ((int)uVar18 < 0) {

      uVar18 = -uVar18;

    }

    if ((int)uVar9 < 0) {

      uVar9 = -uVar9;

    }

    uVar19 = (uVar9 & 0xffff) * (uVar18 & 0xffff);

    iVar7 = (uVar9 >> 0x10) * (uVar18 & 0xffff);

    iVar8 = 0;

    uVar2 = iVar7 + (uVar9 & 0xffff) * (uVar18 >> 0x10);

    if (iVar7 != 0) {

      iVar8 = 0x10000;

    }

    uVar21 = uVar19 + uVar2 * 0x10000;

    uVar9 = iVar8 + (unsigned int)(uVar21 < uVar19) + (uVar2 >> 0x10) + (uVar9 >> 0x10) * (uVar18 >> 0x10);

    if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

      uVar9 = ~uVar9;

      if (uVar21 == 0) {

        uVar9 = uVar9 + 1;

      }

      else {

        uVar21 = ~uVar21 + 1;

      }

    }

    if (((unsigned char)(uVar17 >> 1) & 1) == 1) {

      if ((int)uVar9 < -0x8000) {

        uVar9 = 0xffff8000;

        uVar21 = 0;

      }

      if (0x7fff < (int)uVar9) {

        uVar9 = 0x7fff;

        uVar21 = 0xffffffff;

      }

      uVar9 = uVar9 & 0xffff;

    }

    uVar1 = puVar14[1];

    uVar18 = puVar13[1];

    uVar2 = uVar1 ^ uVar18;

    if ((int)uVar1 < 0) {

      uVar1 = -uVar1;

    }

    if ((int)uVar18 < 0) {

      uVar18 = -uVar18;

    }

    uVar24 = (uVar18 & 0xffff) * (uVar1 & 0xffff);

    iVar7 = (uVar18 >> 0x10) * (uVar1 & 0xffff);

    iVar8 = 0;

    uVar19 = iVar7 + (uVar18 & 0xffff) * (uVar1 >> 0x10);

    if (iVar7 != 0) {

      iVar8 = 0x10000;

    }

    uVar22 = uVar24 + uVar19 * 0x10000;

    uVar18 = iVar8 + (unsigned int)(uVar22 < uVar24) + (uVar19 >> 0x10) + (uVar18 >> 0x10) * (uVar1 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

      uVar18 = ~uVar18;

      if (uVar22 == 0) {

        uVar18 = uVar18 + 1;

      }

      else {

        uVar22 = ~uVar22 + 1;

      }

    }

    if (((unsigned char)(uVar17 >> 1) & 1) == 1) {

      uVar22 = uVar21 + uVar22;

      uVar9 = uVar18 + (uVar22 < uVar21) + (uVar9 & 0xffff);

      if ((int)uVar9 < -0x8000) {

        uVar9 = 0xffff8000;

        uVar22 = 0;

      }

      if (0x7fff < (int)uVar9) {

        uVar9 = 0x7fff;

        uVar22 = 0xffffffff;

      }

      uVar9 = uVar9 & 0xffff;

    }

    else {

      uVar22 = uVar21 + uVar22;

      uVar9 = uVar18 + (uVar22 < uVar21) + uVar9;

    }

    uVar1 = puVar14[2];

    uVar18 = puVar13[2];

    uVar2 = uVar1 ^ uVar18;

    if ((int)uVar1 < 0) {

      uVar1 = -uVar1;

    }

    if ((int)uVar18 < 0) {

      uVar18 = -uVar18;

    }

    uVar21 = (uVar18 & 0xffff) * (uVar1 & 0xffff);

    iVar7 = (uVar18 >> 0x10) * (uVar1 & 0xffff);

    iVar8 = 0;

    uVar19 = iVar7 + (uVar18 & 0xffff) * (uVar1 >> 0x10);

    if (iVar7 != 0) {

      iVar8 = 0x10000;

    }

    uVar24 = uVar21 + uVar19 * 0x10000;

    uVar18 = iVar8 + (unsigned int)(uVar24 < uVar21) + (uVar19 >> 0x10) + (uVar18 >> 0x10) * (uVar1 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

      uVar18 = ~uVar18;

      if (uVar24 == 0) {

        uVar18 = uVar18 + 1;

      }

      else {

        uVar24 = ~uVar24 + 1;

      }

    }

    if (((unsigned char)(uVar17 >> 1) & 1) == 1) {

      uVar24 = uVar22 + uVar24;

      uVar9 = uVar18 + (uVar24 < uVar22) + (uVar9 & 0xffff);

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

    else {

      uVar24 = uVar22 + uVar24;

      uVar9 = uVar18 + (uVar24 < uVar22) + uVar9;

    }

    uVar1 = puVar14[3];

    uVar18 = *puVar13;

    uVar2 = uVar1 ^ uVar18;

    if ((int)uVar1 < 0) {

      uVar1 = -uVar1;

    }

    if ((int)uVar18 < 0) {

      uVar18 = -uVar18;

    }

    uVar21 = (uVar18 & 0xffff) * (uVar1 & 0xffff);

    iVar7 = (uVar18 >> 0x10) * (uVar1 & 0xffff);

    iVar8 = 0;

    uVar19 = iVar7 + (uVar18 & 0xffff) * (uVar1 >> 0x10);

    if (iVar7 != 0) {

      iVar8 = 0x10000;

    }

    uVar22 = uVar21 + uVar19 * 0x10000;

    uVar18 = iVar8 + (unsigned int)(uVar22 < uVar21) + (uVar19 >> 0x10) + (uVar18 >> 0x10) * (uVar1 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

      uVar18 = ~uVar18;

      if (uVar22 == 0) {

        uVar18 = uVar18 + 1;

      }

      else {

        uVar22 = ~uVar22 + 1;

      }

    }

    if (((unsigned char)(uVar17 >> 1) & 1) == 1) {

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

    uVar2 = puVar14[4];

    uVar1 = puVar13[1];

    uVar19 = uVar2 ^ uVar1;

    if ((int)uVar2 < 0) {

      uVar2 = -uVar2;

    }

    if ((int)uVar1 < 0) {

      uVar1 = -uVar1;

    }

    uVar20 = (uVar1 & 0xffff) * (uVar2 & 0xffff);

    iVar7 = (uVar1 >> 0x10) * (uVar2 & 0xffff);

    iVar8 = 0;

    uVar21 = iVar7 + (uVar1 & 0xffff) * (uVar2 >> 0x10);

    if (iVar7 != 0) {

      iVar8 = 0x10000;

    }

    uVar23 = uVar20 + uVar21 * 0x10000;

    uVar1 = iVar8 + (unsigned int)(uVar23 < uVar20) + (uVar21 >> 0x10) + (uVar1 >> 0x10) * (uVar2 >> 0x10);

    if ((int)-(unsigned int)((int)uVar19 < 0) < 0) {

      uVar1 = ~uVar1;

      if (uVar23 == 0) {

        uVar1 = uVar1 + 1;

      }

      else {

        uVar23 = ~uVar23 + 1;

      }

    }

    if (((unsigned char)(uVar17 >> 1) & 1) == 1) {

      uVar23 = uVar22 + uVar23;

      uVar18 = uVar1 + (uVar23 < uVar22) + (uVar18 & 0xffff);

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

      uVar23 = uVar22 + uVar23;

      uVar18 = uVar1 + (uVar23 < uVar22) + uVar18;

    }

    *(unsigned int *)0x0608A7C4 = (uVar9 << 0x10 | uVar24 >> 0x10) + puVar14[9];

    uVar1 = puVar14[5];

    uVar9 = puVar13[2];

    uVar2 = uVar1 ^ uVar9;

    if ((int)uVar1 < 0) {

      uVar1 = -uVar1;

    }

    if ((int)uVar9 < 0) {

      uVar9 = -uVar9;

    }

    uVar21 = (uVar9 & 0xffff) * (uVar1 & 0xffff);

    iVar7 = (uVar9 >> 0x10) * (uVar1 & 0xffff);

    iVar8 = 0;

    uVar19 = iVar7 + (uVar9 & 0xffff) * (uVar1 >> 0x10);

    if (iVar7 != 0) {

      iVar8 = 0x10000;

    }

    uVar24 = uVar21 + uVar19 * 0x10000;

    uVar9 = iVar8 + (unsigned int)(uVar24 < uVar21) + (uVar19 >> 0x10) + (uVar9 >> 0x10) * (uVar1 >> 0x10);

    if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

      uVar9 = ~uVar9;

      if (uVar24 == 0) {

        uVar9 = uVar9 + 1;

      }

      else {

        uVar24 = ~uVar24 + 1;

      }

    }

    if (((unsigned char)(uVar17 >> 1) & 1) == 1) {

      uVar24 = uVar23 + uVar24;

      uVar18 = uVar9 + (uVar24 < uVar23) + (uVar18 & 0xffff);

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

      uVar18 = uVar9 + (uVar24 < uVar23) + uVar18;

    }

    uVar1 = puVar14[6];

    uVar9 = *puVar13;

    uVar2 = uVar1 ^ uVar9;

    if ((int)uVar1 < 0) {

      uVar1 = -uVar1;

    }

    if ((int)uVar9 < 0) {

      uVar9 = -uVar9;

    }

    uVar21 = (uVar9 & 0xffff) * (uVar1 & 0xffff);

    iVar7 = (uVar9 >> 0x10) * (uVar1 & 0xffff);

    iVar8 = 0;

    uVar19 = iVar7 + (uVar9 & 0xffff) * (uVar1 >> 0x10);

    if (iVar7 != 0) {

      iVar8 = 0x10000;

    }

    uVar22 = uVar21 + uVar19 * 0x10000;

    uVar9 = iVar8 + (unsigned int)(uVar22 < uVar21) + (uVar19 >> 0x10) + (uVar9 >> 0x10) * (uVar1 >> 0x10);

    if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

      uVar9 = ~uVar9;

      if (uVar22 == 0) {

        uVar9 = uVar9 + 1;

      }

      else {

        uVar22 = ~uVar22 + 1;

      }

    }

    if (((unsigned char)(uVar17 >> 1) & 1) == 1) {

      if ((int)uVar9 < -0x8000) {

        uVar9 = 0xffff8000;

        uVar22 = 0;

      }

      if (0x7fff < (int)uVar9) {

        uVar9 = 0x7fff;

        uVar22 = 0xffffffff;

      }

      uVar9 = uVar9 & 0xffff;

    }

    uVar2 = puVar14[7];

    uVar1 = puVar13[1];

    uVar19 = uVar2 ^ uVar1;

    if ((int)uVar2 < 0) {

      uVar2 = -uVar2;

    }

    if ((int)uVar1 < 0) {

      uVar1 = -uVar1;

    }

    uVar20 = (uVar1 & 0xffff) * (uVar2 & 0xffff);

    iVar7 = (uVar1 >> 0x10) * (uVar2 & 0xffff);

    iVar8 = 0;

    uVar21 = iVar7 + (uVar1 & 0xffff) * (uVar2 >> 0x10);

    if (iVar7 != 0) {

      iVar8 = 0x10000;

    }

    uVar23 = uVar20 + uVar21 * 0x10000;

    uVar1 = iVar8 + (unsigned int)(uVar23 < uVar20) + (uVar21 >> 0x10) + (uVar1 >> 0x10) * (uVar2 >> 0x10);

    if ((int)-(unsigned int)((int)uVar19 < 0) < 0) {

      uVar1 = ~uVar1;

      if (uVar23 == 0) {

        uVar1 = uVar1 + 1;

      }

      else {

        uVar23 = ~uVar23 + 1;

      }

    }

    if (((unsigned char)(uVar17 >> 1) & 1) == 1) {

      uVar23 = uVar22 + uVar23;

      uVar9 = uVar1 + (uVar23 < uVar22) + (uVar9 & 0xffff);

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

      uVar23 = uVar22 + uVar23;

      uVar9 = uVar1 + (uVar23 < uVar22) + uVar9;

    }

    *(unsigned int *)(puVar3 + 4) = (uVar18 << 0x10 | uVar24 >> 0x10) + puVar14[10];

    uVar1 = puVar14[8];

    uVar18 = puVar13[2];

    uVar2 = uVar1 ^ uVar18;

    if ((int)uVar1 < 0) {

      uVar1 = -uVar1;

    }

    if ((int)uVar18 < 0) {

      uVar18 = -uVar18;

    }

    uVar21 = (uVar18 & 0xffff) * (uVar1 & 0xffff);

    iVar7 = (uVar18 >> 0x10) * (uVar1 & 0xffff);

    iVar8 = 0;

    uVar19 = iVar7 + (uVar18 & 0xffff) * (uVar1 >> 0x10);

    if (iVar7 != 0) {

      iVar8 = 0x10000;

    }

    uVar24 = uVar21 + uVar19 * 0x10000;

    uVar18 = iVar8 + (unsigned int)(uVar24 < uVar21) + (uVar19 >> 0x10) + (uVar18 >> 0x10) * (uVar1 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

      uVar18 = ~uVar18;

      if (uVar24 == 0) {

        uVar18 = uVar18 + 1;

      }

      else {

        uVar24 = ~uVar24 + 1;

      }

    }

    if (((unsigned char)(uVar17 >> 1) & 1) == 1) {

      uVar24 = uVar23 + uVar24;

      uVar9 = uVar18 + (uVar24 < uVar23) + (uVar9 & 0xffff);

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

    else {

      uVar24 = uVar23 + uVar24;

      uVar9 = uVar18 + (uVar24 < uVar23) + uVar9;

    }

    *(unsigned int *)(puVar3 + 8) = (uVar9 << 0x10 | uVar24 >> 0x10) + puVar14[0xb];

    iVar8 = *(int *)(puVar3 + 8);

    *(unsigned short *)(puVar4 + 6) = (unsigned short)(iVar8 <= unaff_r10);

    iVar8 = (unsigned int)(iVar8 <= unaff_r10) + (int)*(short *)(puVar4 + 4) +

            (int)*(short *)(puVar4 + 2) + (int)*(short *)puVar4;

    uVar17 = uVar16 | iVar8 == 0;

    if (((unsigned char)uVar17 & 1) != 1) {

      if (iVar8 == 4) {

        uVar9 = 4;

        uVar17 = uVar16;

        goto LAB_0602a7d6;

      }

      (*(void(*)())(*(int *)(0x0602A800 + iVar8 * 4)))(0x0608A7A0,0x0608A798,puVar14 + 9,puVar14 + 0xc);

      uVar17 = uVar16;

    }

    puVar5 = 0x0608A800;

    puVar4 = 0x0608AC20;

    puVar3 = 0x0608A7A0;

    iVar8 = *(int *)0x060620D4;

    puVar10 = (int *)(int)DAT_0602a4c4;

    uVar11 = *(int *)(0x0608A7A0 + 8);

    puVar10[4] = (int)DAT_0602a4c6;

    *puVar10 = uVar11;

    puVar10[5] = 0;

    iVar12 = *(int *)(puVar3 + 4);

    iVar7 = puVar10[7];

    *(int *)puVar5 = (int)((unsigned long long)((long long)iVar7 * (long long)*(int *)puVar3) >> 0x20);

    *(int *)(puVar5 + 4) = (int)((unsigned long long)((long long)iVar7 * (long long)-iVar12) >> 0x20);

    puVar6 = 0x0608A790;

    iVar7 = *(int *)puVar5;

    iVar12 = *(int *)(puVar5 + 4);

    *(short *)0x0608A790 = 0;

    uVar17 = uVar17 & 0xfffffffe;

    if (PTR_DAT_0602a4c8 < iVar7) {

      *(short *)puVar6 = 1;

    }

    else if (iVar7 < DAT_0602a4f4) {

      *(short *)puVar6 = 1;

    }

    else if (DAT_0602a502 < iVar12) {

      *(short *)puVar6 = 1;

    }

    else if (iVar12 < DAT_0602a54a) {

      *(short *)puVar6 = 1;

    }

    puVar10 = (int *)(int)DAT_0602a54c;

    uVar11 = *(int *)(puVar3 + 0x14);

    puVar10[4] = (int)DAT_0602a54e;

    *puVar10 = uVar11;

    puVar10[5] = 0;

    iVar12 = *(int *)(puVar3 + 0x10);

    iVar7 = puVar10[7];

    *(int *)(puVar5 + 8) =

         (int)((unsigned long long)((long long)iVar7 * (long long)*(int *)(puVar3 + 0xc)) >> 0x20);

    *(int *)(puVar5 + 0xc) = (int)((unsigned long long)((long long)iVar7 * (long long)-iVar12) >> 0x20);

    iVar7 = *(int *)(puVar5 + 8);

    iVar12 = *(int *)(puVar5 + 0xc);

    *(short *)(puVar6 + 2) = 0;

    if (DAT_0602a550 < iVar7) {

      *(short *)(puVar6 + 2) = 1;

    }

    else if (iVar7 < DAT_0602a55e) {

      *(short *)(puVar6 + 2) = 1;

    }

    else if (DAT_0602a56c < iVar12) {

      *(short *)(puVar6 + 2) = 1;

    }

    else if (iVar12 < DAT_0602a5b4) {

      *(short *)(puVar6 + 2) = 1;

    }

    puVar10 = (int *)(int)DAT_0602a5b6;

    uVar11 = *(int *)(puVar3 + 0x20);

    puVar10[4] = (int)DAT_0602a5b8;

    *puVar10 = uVar11;

    puVar10[5] = 0;

    iVar12 = *(int *)(puVar3 + 0x1c);

    iVar7 = puVar10[7];

    *(int *)(puVar5 + 0x10) =

         (int)((unsigned long long)((long long)iVar7 * (long long)*(int *)(puVar3 + 0x18)) >> 0x20);

    *(int *)(puVar5 + 0x14) = (int)((unsigned long long)((long long)iVar7 * (long long)-iVar12) >> 0x20);

    iVar7 = *(int *)(puVar5 + 0x10);

    iVar12 = *(int *)(puVar5 + 0x14);

    *(short *)(puVar6 + 4) = 0;

    if (DAT_0602a5ba < iVar7) {

      *(short *)(puVar6 + 4) = 1;

    }

    else if (iVar7 < DAT_0602a5c8) {

      *(short *)(puVar6 + 4) = 1;

    }

    else if (DAT_0602a5d6 < iVar12) {

      *(short *)(puVar6 + 4) = 1;

    }

    else if (iVar12 < DAT_0602a61e) {

      *(short *)(puVar6 + 4) = 1;

    }

    puVar10 = (int *)(int)DAT_0602a620;

    uVar11 = *(int *)(puVar3 + 0x2c);

    puVar10[4] = (int)DAT_0602a622;

    *puVar10 = uVar11;

    puVar10[5] = 0;

    iVar12 = *(int *)(puVar3 + 0x28);

    iVar7 = puVar10[7];

    *(int *)(puVar5 + 0x18) =

         (int)((unsigned long long)((long long)iVar7 * (long long)*(int *)(puVar3 + 0x24)) >> 0x20);

    *(int *)(puVar5 + 0x1c) = (int)((unsigned long long)((long long)iVar7 * (long long)-iVar12) >> 0x20);

    iVar7 = *(int *)(puVar5 + 0x18);

    iVar12 = *(int *)(puVar5 + 0x1c);

    *(short *)(puVar6 + 6) = 0;

    if (DAT_0602a624 < iVar7) {

      *(short *)(puVar6 + 6) = 1;

    }

    else if (iVar7 < DAT_0602a632) {

      *(short *)(puVar6 + 6) = 1;

    }

    else if (DAT_0602a640 < iVar12) {

      *(short *)(puVar6 + 6) = 1;

    }

    else if (iVar12 < DAT_0602a670) {

      *(short *)(puVar6 + 6) = 1;

    }

    if (((((int)0xFFFFFF50 <= *(int *)puVar5) ||

         ((int)0xFFFFFF50 <= *(int *)(puVar5 + 8))) ||

        ((int)0xFFFFFF50 <= *(int *)(puVar5 + 0x10))) ||

       (uVar9 = *(unsigned int *)(puVar5 + 0x18), (int)0xFFFFFF50 <= (int)uVar9)) {

      uVar16 = uVar17 | *(int *)puVar5 < 0x000000B0;

      if (((((unsigned char)uVar16 & 1) != 1) &&

          (uVar16 = uVar17 | *(int *)(puVar5 + 8) < 0x000000B0, ((unsigned char)uVar16 & 1) != 1)) &&

         (uVar16 = uVar17 | *(int *)(puVar5 + 0x10) < 0x000000B0, ((unsigned char)uVar16 & 1) != 1)) {

        uVar9 = *(unsigned int *)(puVar5 + 0x18);

        uVar16 = uVar17 | (int)uVar9 < 0x000000B0;

        uVar17 = uVar16;

        if (((unsigned char)uVar16 & 1) != 1) goto LAB_0602a7d6;

      }

      uVar16 = uVar16 & 0xfffffffe;

      if ((((int)0xFFFFFF81 <= *(int *)(puVar5 + 4)) ||

          ((int)0xFFFFFF81 <= *(int *)(puVar5 + 0xc))) ||

         (((int)0xFFFFFF81 <= *(int *)(puVar5 + 0x14) ||

          (uVar9 = *(unsigned int *)(puVar5 + 0x1c), uVar17 = uVar16, (int)0xFFFFFF81 <= (int)uVar9)))

         ) {

        uVar17 = uVar16 | *(int *)(puVar5 + 4) < 0x00000051;

        if (((((unsigned char)uVar17 & 1) != 1) &&

            (uVar17 = uVar16 | *(int *)(puVar5 + 0xc) < 0x00000051, ((unsigned char)uVar17 & 1) != 1)) &&

           (uVar17 = uVar16 | *(int *)(puVar5 + 0x14) < 0x00000051, ((unsigned char)uVar17 & 1) != 1)) {

          uVar9 = *(unsigned int *)(puVar5 + 0x1c);

          uVar17 = uVar16 | (int)uVar9 < 0x00000051;

          if (((unsigned char)uVar17 & 1) != 1) goto LAB_0602a7d6;

        }

        iVar7 = (int)*(short *)(puVar6 + 6) +

                (int)*(short *)puVar6 + (int)*(short *)(puVar6 + 2) + (int)*(short *)(puVar6 + 4);

        if (iVar7 != 4) {

          if (iVar7 != 0) {

            (*(void(*)())(*(int *)(0x0602A810 + iVar7 * 4)))(puVar5,puVar6);

          }

          *(short *)(puVar4 + iVar8 * 0x18 + 8) = (short)*(int *)puVar5;

          *(short *)(puVar4 + iVar8 * 0x18 + 10) = (short)*(int *)(puVar5 + 4);

          *(short *)(puVar4 + iVar8 * 0x18 + 0xc) = (short)*(int *)(puVar5 + 8);

          *(short *)(puVar4 + iVar8 * 0x18 + 0xe) = (short)*(int *)(puVar5 + 0xc);

          *(short *)(puVar4 + iVar8 * 0x18 + 0x10) = (short)*(int *)(puVar5 + 0x10);

          *(short *)(puVar4 + iVar8 * 0x18 + 0x12) = (short)*(int *)(puVar5 + 0x14);

          *(short *)(puVar4 + iVar8 * 0x18 + 0x14) = (short)*(int *)(puVar5 + 0x18);

          *(short *)(puVar4 + iVar8 * 0x18 + 0x16) = (short)*(int *)(puVar5 + 0x1c);

          *(short *)(puVar4 + iVar8 * 0x18 + 6) = *(short *)((int)puVar15 + -10);

          puVar4[iVar8 * 0x18 + 4] = (unsigned char)((unsigned int)(int)*(short *)(puVar15 + -3) >> 4) & 0xf;

          puVar4[iVar8 * 0x18 + 5] = unaff_r13;

          uVar17 = (**(void **)(0x0602A820 + ((int)*(short *)(puVar15 + -3) & 7U) * 4))

                             (*(int *)(0x0608A7A0 + 0x14),

                              *(int *)(0x0608A7A0 + 0x20),

                              *(int *)(0x0608A7A0 + 0x2c));

          return uVar17;

        }

        uVar9 = 4;

        uVar17 = uVar17 & 0xfffffffe;

      }

    }

  }

  goto LAB_0602a7d6;

}
