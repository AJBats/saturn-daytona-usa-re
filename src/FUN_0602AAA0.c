extern int DAT_0602a97e;

extern int DAT_0602aa12;

extern int DAT_0602aa14;

extern int DAT_0602aa16;

extern int DAT_0602aafa;

extern int DAT_0602ab8c;

extern int DAT_0602ab90;

extern int DAT_0602ab94;

extern int PTR_DAT_0602a87c;

extern int PTR_DAT_0602a87c;

extern int PTR_DAT_0602aafc;

extern int PTR_DAT_0602aafc;

extern void FUN_0602ab00();
extern void FUN_0602ab3a();

long long 
{

  unsigned int uVar1;

  char *puVar2;

  char *puVar3;

  unsigned int extraout_r1;

  unsigned int in_r1;

  unsigned int extraout_r2;

  int *piVar4;

  unsigned int extraout_r3;

  unsigned int extraout_r3_00;

  unsigned int extraout_r3_01;

  unsigned int extraout_r3_02;

  unsigned int extraout_r3_03;

  int iVar5;

  unsigned int *puVar6;

  unsigned int *puVar7;

  int iVar8;

  unsigned int *puVar9;

  int iVar10;

  int iVar11;

  unsigned int *puVar12;

  unsigned int *unaff_r8;

  int unaff_r9;

  int unaff_r10;

  int iVar13;

  int iVar14;

  char unaff_r13;

  int unaff_r14;

  unsigned int uVar15;

  unsigned int uVar16;

  unsigned int in_sr;

  unsigned int uVar17;

  unsigned int uVar18;

  unsigned int uVar19;

  unsigned int uVar20;

  unsigned int uVar21;

  unsigned int uVar22;

  unsigned int uVar23;

  long long uVar24;

  puVar6 = (unsigned int *)(unaff_r9 * 0xc + unaff_r14);

  uVar18 = param_3[6];

  uVar17 = *puVar6;

  uVar15 = uVar18 ^ uVar17;

  if ((int)uVar18 < 0) {

    uVar18 = -uVar18;

  }

  if ((int)uVar17 < 0) {

    uVar17 = -uVar17;

  }

  uVar1 = (uVar17 & 0xffff) * (uVar18 & 0xffff);

  iVar10 = (uVar17 >> 0x10) * (uVar18 & 0xffff);

  iVar5 = 0;

  uVar16 = iVar10 + (uVar17 & 0xffff) * (uVar18 >> 0x10);

  if (iVar10 != 0) {

    iVar5 = 0x10000;

  }

  uVar22 = uVar1 + uVar16 * 0x10000;

  uVar17 = iVar5 + (unsigned int)(uVar22 < uVar1) + (uVar16 >> 0x10) + (uVar17 >> 0x10) * (uVar18 >> 0x10);

  if ((int)-(unsigned int)((int)uVar15 < 0) < 0) {

    uVar17 = ~uVar17;

    if (uVar22 == 0) {

      uVar17 = uVar17 + 1;

    }

    else {

      uVar22 = ~uVar22 + 1;

    }

  }

  if (((unsigned char)(in_sr >> 1) & 1) == 1) {

    if ((int)uVar17 < -0x8000) {

      uVar17 = 0xffff8000;

      uVar22 = 0;

    }

    if (0x7fff < (int)uVar17) {

      uVar17 = 0x7fff;

      uVar22 = 0xffffffff;

    }

    uVar17 = uVar17 & 0xffff;

  }

  uVar15 = param_3[7];

  uVar18 = puVar6[1];

  uVar16 = uVar15 ^ uVar18;

  if ((int)uVar15 < 0) {

    uVar15 = -uVar15;

  }

  if ((int)uVar18 < 0) {

    uVar18 = -uVar18;

  }

  uVar23 = (uVar18 & 0xffff) * (uVar15 & 0xffff);

  iVar10 = (uVar18 >> 0x10) * (uVar15 & 0xffff);

  iVar5 = 0;

  uVar1 = iVar10 + (uVar18 & 0xffff) * (uVar15 >> 0x10);

  if (iVar10 != 0) {

    iVar5 = 0x10000;

  }

  uVar19 = uVar23 + uVar1 * 0x10000;

  uVar18 = iVar5 + (unsigned int)(uVar19 < uVar23) + (uVar1 >> 0x10) + (uVar18 >> 0x10) * (uVar15 >> 0x10);

  if ((int)-(unsigned int)((int)uVar16 < 0) < 0) {

    uVar18 = ~uVar18;

    if (uVar19 == 0) {

      uVar18 = uVar18 + 1;

    }

    else {

      uVar19 = ~uVar19 + 1;

    }

  }

  if (((unsigned char)(in_sr >> 1) & 1) == 1) {

    uVar19 = uVar22 + uVar19;

    uVar18 = uVar18 + (uVar19 < uVar22) + (uVar17 & 0xffff);

    if ((int)uVar18 < -0x8000) {

      uVar18 = 0xffff8000;

      uVar19 = 0;

    }

    if (0x7fff < (int)uVar18) {

      uVar18 = 0x7fff;

      uVar19 = 0xffffffff;

    }

    uVar17 = uVar18 & 0xffff | uVar17 & 0xffff0000;

  }

  else {

    uVar19 = uVar22 + uVar19;

    uVar17 = uVar18 + (uVar19 < uVar22) + uVar17;

  }

  uVar15 = param_3[8];

  uVar18 = puVar6[2];

  uVar16 = uVar15 ^ uVar18;

  if ((int)uVar15 < 0) {

    uVar15 = -uVar15;

  }

  if ((int)uVar18 < 0) {

    uVar18 = -uVar18;

  }

  uVar22 = (uVar18 & 0xffff) * (uVar15 & 0xffff);

  iVar10 = (uVar18 >> 0x10) * (uVar15 & 0xffff);

  iVar5 = 0;

  uVar1 = iVar10 + (uVar18 & 0xffff) * (uVar15 >> 0x10);

  if (iVar10 != 0) {

    iVar5 = 0x10000;

  }

  uVar23 = uVar22 + uVar1 * 0x10000;

  uVar18 = iVar5 + (unsigned int)(uVar23 < uVar22) + (uVar1 >> 0x10) + (uVar18 >> 0x10) * (uVar15 >> 0x10);

  if ((int)-(unsigned int)((int)uVar16 < 0) < 0) {

    uVar18 = ~uVar18;

    if (uVar23 == 0) {

      uVar18 = uVar18 + 1;

    }

    else {

      uVar23 = ~uVar23 + 1;

    }

  }

  if (((unsigned char)(in_sr >> 1) & 1) == 1) {

    uVar23 = uVar19 + uVar23;

    uVar18 = uVar18 + (uVar23 < uVar19) + (uVar17 & 0xffff);

    if ((int)uVar18 < -0x8000) {

      uVar18 = 0xffff8000;

      uVar23 = 0;

    }

    if (0x7fff < (int)uVar18) {

      uVar18 = 0x7fff;

      uVar23 = 0xffffffff;

    }

    uVar17 = uVar18 & 0xffff | uVar17 & 0xffff0000;

  }

  else {

    uVar23 = uVar19 + uVar23;

    uVar17 = uVar18 + (uVar23 < uVar19) + uVar17;

  }

  iVar5 = (uVar17 << 0x10 | uVar23 >> 0x10) + param_3[0xb];

  uVar18 = in_sr & 0xfffffffe;

  if (unaff_r10 < iVar5) {

    piVar4 = (int *)(int)DAT_0602aafa;

    piVar4[4] = (int)PTR_DAT_0602aafc;

    *piVar4 = iVar5;

    piVar4[5] = 0;

    uVar18 = *param_3;

    uVar17 = *puVar6;

    uVar15 = uVar18 ^ uVar17;

    if ((int)uVar18 < 0) {

      uVar18 = -uVar18;

    }

    if ((int)uVar17 < 0) {

      uVar17 = -uVar17;

    }

    uVar1 = (uVar17 & 0xffff) * (uVar18 & 0xffff);

    iVar10 = (uVar17 >> 0x10) * (uVar18 & 0xffff);

    iVar5 = 0;

    uVar16 = iVar10 + (uVar17 & 0xffff) * (uVar18 >> 0x10);

    if (iVar10 != 0) {

      iVar5 = 0x10000;

    }

    uVar22 = uVar1 + uVar16 * 0x10000;

    uVar17 = iVar5 + (unsigned int)(uVar22 < uVar1) + (uVar16 >> 0x10) + (uVar17 >> 0x10) * (uVar18 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar15 < 0) < 0) {

      uVar17 = ~uVar17;

      if (uVar22 == 0) {

        uVar17 = uVar17 + 1;

      }

      else {

        uVar22 = ~uVar22 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      if ((int)uVar17 < -0x8000) {

        uVar17 = 0xffff8000;

        uVar22 = 0;

      }

      if (0x7fff < (int)uVar17) {

        uVar17 = 0x7fff;

        uVar22 = 0xffffffff;

      }

      uVar17 = uVar17 & 0xffff;

    }

    uVar15 = param_3[1];

    uVar18 = puVar6[1];

    uVar16 = uVar15 ^ uVar18;

    if ((int)uVar15 < 0) {

      uVar15 = -uVar15;

    }

    if ((int)uVar18 < 0) {

      uVar18 = -uVar18;

    }

    uVar23 = (uVar18 & 0xffff) * (uVar15 & 0xffff);

    iVar10 = (uVar18 >> 0x10) * (uVar15 & 0xffff);

    iVar5 = 0;

    uVar1 = iVar10 + (uVar18 & 0xffff) * (uVar15 >> 0x10);

    if (iVar10 != 0) {

      iVar5 = 0x10000;

    }

    uVar19 = uVar23 + uVar1 * 0x10000;

    uVar18 = iVar5 + (unsigned int)(uVar19 < uVar23) + (uVar1 >> 0x10) + (uVar18 >> 0x10) * (uVar15 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar16 < 0) < 0) {

      uVar18 = ~uVar18;

      if (uVar19 == 0) {

        uVar18 = uVar18 + 1;

      }

      else {

        uVar19 = ~uVar19 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      uVar19 = uVar22 + uVar19;

      uVar17 = uVar18 + (uVar19 < uVar22) + (uVar17 & 0xffff);

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

    else {

      uVar19 = uVar22 + uVar19;

      uVar17 = uVar18 + (uVar19 < uVar22) + uVar17;

    }

    uVar15 = param_3[2];

    uVar18 = puVar6[2];

    uVar16 = uVar15 ^ uVar18;

    if ((int)uVar15 < 0) {

      uVar15 = -uVar15;

    }

    if ((int)uVar18 < 0) {

      uVar18 = -uVar18;

    }

    uVar22 = (uVar18 & 0xffff) * (uVar15 & 0xffff);

    iVar10 = (uVar18 >> 0x10) * (uVar15 & 0xffff);

    iVar5 = 0;

    uVar1 = iVar10 + (uVar18 & 0xffff) * (uVar15 >> 0x10);

    if (iVar10 != 0) {

      iVar5 = 0x10000;

    }

    uVar23 = uVar22 + uVar1 * 0x10000;

    uVar18 = iVar5 + (unsigned int)(uVar23 < uVar22) + (uVar1 >> 0x10) + (uVar18 >> 0x10) * (uVar15 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar16 < 0) < 0) {

      uVar18 = ~uVar18;

      if (uVar23 == 0) {

        uVar18 = uVar18 + 1;

      }

      else {

        uVar23 = ~uVar23 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      uVar23 = uVar19 + uVar23;

      uVar17 = uVar18 + (uVar23 < uVar19) + (uVar17 & 0xffff);

      if ((int)uVar17 < -0x8000) {

        uVar17 = 0xffff8000;

        uVar23 = 0;

      }

      if (0x7fff < (int)uVar17) {

        uVar17 = 0x7fff;

        uVar23 = 0xffffffff;

      }

      uVar17 = uVar17 & 0xffff;

    }

    else {

      uVar23 = uVar19 + uVar23;

      uVar17 = uVar18 + (uVar23 < uVar19) + uVar17;

    }

    uVar15 = param_3[3];

    uVar18 = *puVar6;

    uVar16 = uVar15 ^ uVar18;

    if ((int)uVar15 < 0) {

      uVar15 = -uVar15;

    }

    if ((int)uVar18 < 0) {

      uVar18 = -uVar18;

    }

    uVar22 = (uVar18 & 0xffff) * (uVar15 & 0xffff);

    iVar10 = (uVar18 >> 0x10) * (uVar15 & 0xffff);

    iVar5 = 0;

    uVar1 = iVar10 + (uVar18 & 0xffff) * (uVar15 >> 0x10);

    if (iVar10 != 0) {

      iVar5 = 0x10000;

    }

    uVar19 = uVar22 + uVar1 * 0x10000;

    uVar18 = iVar5 + (unsigned int)(uVar19 < uVar22) + (uVar1 >> 0x10) + (uVar18 >> 0x10) * (uVar15 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar16 < 0) < 0) {

      uVar18 = ~uVar18;

      if (uVar19 == 0) {

        uVar18 = uVar18 + 1;

      }

      else {

        uVar19 = ~uVar19 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      if ((int)uVar18 < -0x8000) {

        uVar18 = 0xffff8000;

        uVar19 = 0;

      }

      if (0x7fff < (int)uVar18) {

        uVar18 = 0x7fff;

        uVar19 = 0xffffffff;

      }

      uVar18 = uVar18 & 0xffff;

    }

    uVar16 = param_3[4];

    uVar15 = puVar6[1];

    uVar1 = uVar16 ^ uVar15;

    if ((int)uVar16 < 0) {

      uVar16 = -uVar16;

    }

    if ((int)uVar15 < 0) {

      uVar15 = -uVar15;

    }

    uVar21 = (uVar15 & 0xffff) * (uVar16 & 0xffff);

    iVar10 = (uVar15 >> 0x10) * (uVar16 & 0xffff);

    iVar5 = 0;

    uVar22 = iVar10 + (uVar15 & 0xffff) * (uVar16 >> 0x10);

    if (iVar10 != 0) {

      iVar5 = 0x10000;

    }

    uVar20 = uVar21 + uVar22 * 0x10000;

    uVar15 = iVar5 + (unsigned int)(uVar20 < uVar21) + (uVar22 >> 0x10) +

             (uVar15 >> 0x10) * (uVar16 >> 0x10);

    if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

      uVar15 = ~uVar15;

      if (uVar20 == 0) {

        uVar15 = uVar15 + 1;

      }

      else {

        uVar20 = ~uVar20 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      uVar20 = uVar19 + uVar20;

      uVar15 = uVar15 + (uVar20 < uVar19) + (uVar18 & 0xffff);

      if ((int)uVar15 < -0x8000) {

        uVar15 = 0xffff8000;

        uVar20 = 0;

      }

      if (0x7fff < (int)uVar15) {

        uVar15 = 0x7fff;

        uVar20 = 0xffffffff;

      }

      uVar18 = uVar15 & 0xffff | uVar18 & 0xffff0000;

    }

    else {

      uVar20 = uVar19 + uVar20;

      uVar18 = uVar15 + (uVar20 < uVar19) + uVar18;

    }

    uVar16 = param_3[5];

    uVar15 = puVar6[2];

    uVar1 = uVar16 ^ uVar15;

    if ((int)uVar16 < 0) {

      uVar16 = -uVar16;

    }

    if ((int)uVar15 < 0) {

      uVar15 = -uVar15;

    }

    uVar19 = (uVar15 & 0xffff) * (uVar16 & 0xffff);

    iVar10 = (uVar15 >> 0x10) * (uVar16 & 0xffff);

    iVar5 = 0;

    uVar22 = iVar10 + (uVar15 & 0xffff) * (uVar16 >> 0x10);

    if (iVar10 != 0) {

      iVar5 = 0x10000;

    }

    uVar21 = uVar19 + uVar22 * 0x10000;

    uVar15 = iVar5 + (unsigned int)(uVar21 < uVar19) + (uVar22 >> 0x10) +

             (uVar15 >> 0x10) * (uVar16 >> 0x10);

    if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

      uVar15 = ~uVar15;

      if (uVar21 == 0) {

        uVar15 = uVar15 + 1;

      }

      else {

        uVar21 = ~uVar21 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      uVar15 = uVar15 + (uVar20 + uVar21 < uVar20) + (uVar18 & 0xffff);

      if ((int)uVar15 < -0x8000) {

        uVar15 = 0xffff8000;

      }

      if (0x7fff < (int)uVar15) {

        uVar15 = 0x7fff;

      }

      uVar18 = uVar15 & 0xffff | uVar18 & 0xffff0000;

    }

    else {

      uVar18 = uVar15 + (uVar20 + uVar21 < uVar20) + uVar18;

    }

    return CONCAT44((uVar17 << 0x10 | uVar23 >> 0x10) + param_3[9],uVar18);

  }

LAB_0602aa74:

  puVar12 = unaff_r8;

  puVar2 = 0x0602AB68;

  param_5 = param_5 + -1;

  uVar18 = uVar18 & 0xfffffffe;

  if (param_5 == 0) {

    return CONCAT44(in_r1,uVar17);

  }

  unaff_r8 = puVar12 + -6;

  uVar15 = uVar18 | *(short *)0x0605BE36 == 0;

  if (((unsigned char)uVar15 & 1) != 1) {

    uVar17 = (unsigned int)*(short *)((int)puVar12 + -10);

    in_r1 = (unsigned int)PTR_DAT_0602a87c;

    uVar15 = uVar18;

    if (in_r1 == uVar17) goto LAB_0602aa74;

  }

  puVar9 = *(unsigned int **)0x06089EDC;

  puVar7 = (unsigned int *)0x0602AB88;

  FUN_0602aaa0(puVar6);

  *puVar7 = extraout_r1;

  puVar7[1] = extraout_r2;

  puVar7[2] = extraout_r3;

  puVar3 = 0x0602AB98;

  uVar18 = uVar15 & 0xfffffffe;

  if ((puVar12[-3] & 0x80000) == 0) {

    uVar16 = *puVar9;

    uVar17 = *unaff_r8;

    uVar1 = uVar16 ^ uVar17;

    if ((int)uVar16 < 0) {

      uVar16 = -uVar16;

    }

    if ((int)uVar17 < 0) {

      uVar17 = -uVar17;

    }

    uVar23 = (uVar17 & 0xffff) * (uVar16 & 0xffff);

    iVar10 = (uVar17 >> 0x10) * (uVar16 & 0xffff);

    iVar5 = 0;

    uVar22 = iVar10 + (uVar17 & 0xffff) * (uVar16 >> 0x10);

    if (iVar10 != 0) {

      iVar5 = 0x10000;

    }

    uVar19 = uVar23 + uVar22 * 0x10000;

    uVar17 = iVar5 + (unsigned int)(uVar19 < uVar23) + (uVar22 >> 0x10) +

             (uVar17 >> 0x10) * (uVar16 >> 0x10);

    if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

      uVar17 = ~uVar17;

      if (uVar19 == 0) {

        uVar17 = uVar17 + 1;

      }

      else {

        uVar19 = ~uVar19 + 1;

      }

    }

    if (((unsigned char)(uVar15 >> 1) & 1) == 1) {

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

    uVar1 = puVar9[1];

    uVar16 = puVar12[-5];

    uVar22 = uVar1 ^ uVar16;

    if ((int)uVar1 < 0) {

      uVar1 = -uVar1;

    }

    if ((int)uVar16 < 0) {

      uVar16 = -uVar16;

    }

    uVar21 = (uVar16 & 0xffff) * (uVar1 & 0xffff);

    iVar10 = (uVar16 >> 0x10) * (uVar1 & 0xffff);

    iVar5 = 0;

    uVar23 = iVar10 + (uVar16 & 0xffff) * (uVar1 >> 0x10);

    if (iVar10 != 0) {

      iVar5 = 0x10000;

    }

    uVar20 = uVar21 + uVar23 * 0x10000;

    uVar16 = iVar5 + (unsigned int)(uVar20 < uVar21) + (uVar23 >> 0x10) + (uVar16 >> 0x10) * (uVar1 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar22 < 0) < 0) {

      uVar16 = ~uVar16;

      if (uVar20 == 0) {

        uVar16 = uVar16 + 1;

      }

      else {

        uVar20 = ~uVar20 + 1;

      }

    }

    if (((unsigned char)(uVar15 >> 1) & 1) == 1) {

      uVar20 = uVar19 + uVar20;

      uVar17 = uVar16 + (uVar20 < uVar19) + (uVar17 & 0xffff);

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

      uVar20 = uVar19 + uVar20;

      uVar17 = uVar16 + (uVar20 < uVar19) + uVar17;

    }

    uVar1 = puVar9[2];

    uVar16 = puVar12[-4];

    uVar22 = uVar1 ^ uVar16;

    if ((int)uVar1 < 0) {

      uVar1 = -uVar1;

    }

    if ((int)uVar16 < 0) {

      uVar16 = -uVar16;

    }

    uVar19 = (uVar16 & 0xffff) * (uVar1 & 0xffff);

    iVar10 = (uVar16 >> 0x10) * (uVar1 & 0xffff);

    iVar5 = 0;

    uVar23 = iVar10 + (uVar16 & 0xffff) * (uVar1 >> 0x10);

    if (iVar10 != 0) {

      iVar5 = 0x10000;

    }

    uVar21 = uVar19 + uVar23 * 0x10000;

    uVar16 = iVar5 + (unsigned int)(uVar21 < uVar19) + (uVar23 >> 0x10) + (uVar16 >> 0x10) * (uVar1 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar22 < 0) < 0) {

      uVar16 = ~uVar16;

      if (uVar21 == 0) {

        uVar16 = uVar16 + 1;

      }

      else {

        uVar21 = ~uVar21 + 1;

      }

    }

    if (((unsigned char)(uVar15 >> 1) & 1) == 1) {

      uVar21 = uVar20 + uVar21;

      uVar17 = uVar16 + (uVar21 < uVar20) + (uVar17 & 0xffff);

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

      uVar17 = uVar16 + (uVar21 < uVar20) + uVar17;

    }

    uVar1 = puVar9[3];

    uVar16 = *unaff_r8;

    uVar22 = uVar1 ^ uVar16;

    if ((int)uVar1 < 0) {

      uVar1 = -uVar1;

    }

    if ((int)uVar16 < 0) {

      uVar16 = -uVar16;

    }

    uVar19 = (uVar16 & 0xffff) * (uVar1 & 0xffff);

    iVar10 = (uVar16 >> 0x10) * (uVar1 & 0xffff);

    iVar5 = 0;

    uVar23 = iVar10 + (uVar16 & 0xffff) * (uVar1 >> 0x10);

    if (iVar10 != 0) {

      iVar5 = 0x10000;

    }

    uVar20 = uVar19 + uVar23 * 0x10000;

    uVar16 = iVar5 + (unsigned int)(uVar20 < uVar19) + (uVar23 >> 0x10) + (uVar16 >> 0x10) * (uVar1 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar22 < 0) < 0) {

      uVar16 = ~uVar16;

      if (uVar20 == 0) {

        uVar16 = uVar16 + 1;

      }

      else {

        uVar20 = ~uVar20 + 1;

      }

    }

    if (((unsigned char)(uVar15 >> 1) & 1) == 1) {

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

    *(unsigned int *)0x0602AB98 = uVar17 << 0x10 | uVar21 >> 0x10;

    uVar1 = puVar9[4];

    uVar17 = puVar12[-5];

    uVar22 = uVar1 ^ uVar17;

    if ((int)uVar1 < 0) {

      uVar1 = -uVar1;

    }

    if ((int)uVar17 < 0) {

      uVar17 = -uVar17;

    }

    uVar19 = (uVar17 & 0xffff) * (uVar1 & 0xffff);

    iVar10 = (uVar17 >> 0x10) * (uVar1 & 0xffff);

    iVar5 = 0;

    uVar23 = iVar10 + (uVar17 & 0xffff) * (uVar1 >> 0x10);

    if (iVar10 != 0) {

      iVar5 = 0x10000;

    }

    uVar21 = uVar19 + uVar23 * 0x10000;

    uVar17 = iVar5 + (unsigned int)(uVar21 < uVar19) + (uVar23 >> 0x10) + (uVar17 >> 0x10) * (uVar1 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar22 < 0) < 0) {

      uVar17 = ~uVar17;

      if (uVar21 == 0) {

        uVar17 = uVar17 + 1;

      }

      else {

        uVar21 = ~uVar21 + 1;

      }

    }

    if (((unsigned char)(uVar15 >> 1) & 1) == 1) {

      uVar21 = uVar20 + uVar21;

      uVar16 = uVar17 + (uVar21 < uVar20) + (uVar16 & 0xffff);

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

      uVar16 = uVar17 + (uVar21 < uVar20) + uVar16;

    }

    uVar1 = puVar9[5];

    uVar17 = puVar12[-4];

    uVar22 = uVar1 ^ uVar17;

    if ((int)uVar1 < 0) {

      uVar1 = -uVar1;

    }

    if ((int)uVar17 < 0) {

      uVar17 = -uVar17;

    }

    uVar19 = (uVar17 & 0xffff) * (uVar1 & 0xffff);

    iVar10 = (uVar17 >> 0x10) * (uVar1 & 0xffff);

    iVar5 = 0;

    uVar23 = iVar10 + (uVar17 & 0xffff) * (uVar1 >> 0x10);

    if (iVar10 != 0) {

      iVar5 = 0x10000;

    }

    uVar20 = uVar19 + uVar23 * 0x10000;

    uVar17 = iVar5 + (unsigned int)(uVar20 < uVar19) + (uVar23 >> 0x10) + (uVar17 >> 0x10) * (uVar1 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar22 < 0) < 0) {

      uVar17 = ~uVar17;

      if (uVar20 == 0) {

        uVar17 = uVar17 + 1;

      }

      else {

        uVar20 = ~uVar20 + 1;

      }

    }

    if (((unsigned char)(uVar15 >> 1) & 1) == 1) {

      uVar20 = uVar21 + uVar20;

      uVar16 = uVar17 + (uVar20 < uVar21) + (uVar16 & 0xffff);

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

      uVar20 = uVar21 + uVar20;

      uVar16 = uVar17 + (uVar20 < uVar21) + uVar16;

    }

    uVar1 = puVar9[6];

    uVar17 = *unaff_r8;

    uVar22 = uVar1 ^ uVar17;

    if ((int)uVar1 < 0) {

      uVar1 = -uVar1;

    }

    if ((int)uVar17 < 0) {

      uVar17 = -uVar17;

    }

    uVar19 = (uVar17 & 0xffff) * (uVar1 & 0xffff);

    iVar10 = (uVar17 >> 0x10) * (uVar1 & 0xffff);

    iVar5 = 0;

    uVar23 = iVar10 + (uVar17 & 0xffff) * (uVar1 >> 0x10);

    if (iVar10 != 0) {

      iVar5 = 0x10000;

    }

    uVar21 = uVar19 + uVar23 * 0x10000;

    uVar17 = iVar5 + (unsigned int)(uVar21 < uVar19) + (uVar23 >> 0x10) + (uVar17 >> 0x10) * (uVar1 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar22 < 0) < 0) {

      uVar17 = ~uVar17;

      if (uVar21 == 0) {

        uVar17 = uVar17 + 1;

      }

      else {

        uVar21 = ~uVar21 + 1;

      }

    }

    if (((unsigned char)(uVar15 >> 1) & 1) == 1) {

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

    *(unsigned int *)(puVar3 + 4) = uVar16 << 0x10 | uVar20 >> 0x10;

    uVar1 = puVar9[7];

    uVar16 = puVar12[-5];

    uVar22 = uVar1 ^ uVar16;

    if ((int)uVar1 < 0) {

      uVar1 = -uVar1;

    }

    if ((int)uVar16 < 0) {

      uVar16 = -uVar16;

    }

    uVar19 = (uVar16 & 0xffff) * (uVar1 & 0xffff);

    iVar10 = (uVar16 >> 0x10) * (uVar1 & 0xffff);

    iVar5 = 0;

    uVar23 = iVar10 + (uVar16 & 0xffff) * (uVar1 >> 0x10);

    if (iVar10 != 0) {

      iVar5 = 0x10000;

    }

    uVar20 = uVar19 + uVar23 * 0x10000;

    uVar16 = iVar5 + (unsigned int)(uVar20 < uVar19) + (uVar23 >> 0x10) + (uVar16 >> 0x10) * (uVar1 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar22 < 0) < 0) {

      uVar16 = ~uVar16;

      if (uVar20 == 0) {

        uVar16 = uVar16 + 1;

      }

      else {

        uVar20 = ~uVar20 + 1;

      }

    }

    if (((unsigned char)(uVar15 >> 1) & 1) == 1) {

      uVar20 = uVar21 + uVar20;

      uVar17 = uVar16 + (uVar20 < uVar21) + (uVar17 & 0xffff);

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

      uVar20 = uVar21 + uVar20;

      uVar17 = uVar16 + (uVar20 < uVar21) + uVar17;

    }

    uVar1 = puVar9[8];

    uVar16 = puVar12[-4];

    puVar6 = puVar12 + -3;

    uVar22 = uVar1 ^ uVar16;

    if ((int)uVar1 < 0) {

      uVar1 = -uVar1;

    }

    if ((int)uVar16 < 0) {

      uVar16 = -uVar16;

    }

    uVar19 = (uVar16 & 0xffff) * (uVar1 & 0xffff);

    iVar10 = (uVar16 >> 0x10) * (uVar1 & 0xffff);

    iVar5 = 0;

    uVar23 = iVar10 + (uVar16 & 0xffff) * (uVar1 >> 0x10);

    if (iVar10 != 0) {

      iVar5 = 0x10000;

    }

    uVar21 = uVar19 + uVar23 * 0x10000;

    uVar16 = iVar5 + (unsigned int)(uVar21 < uVar19) + (uVar23 >> 0x10) + (uVar16 >> 0x10) * (uVar1 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar22 < 0) < 0) {

      uVar16 = ~uVar16;

      if (uVar21 == 0) {

        uVar16 = uVar16 + 1;

      }

      else {

        uVar21 = ~uVar21 + 1;

      }

    }

    if (((unsigned char)(uVar15 >> 1) & 1) == 1) {

      uVar21 = uVar20 + uVar21;

      uVar17 = uVar16 + (uVar21 < uVar20) + (uVar17 & 0xffff);

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

      uVar17 = uVar16 + (uVar21 < uVar20) + uVar17;

    }

    *(unsigned int *)(puVar3 + 8) = uVar17 << 0x10 | uVar21 >> 0x10;

    uVar16 = *(unsigned int *)puVar3;

    uVar17 = *puVar7;

    uVar1 = uVar16 ^ uVar17;

    if ((int)uVar16 < 0) {

      uVar16 = -uVar16;

    }

    if ((int)uVar17 < 0) {

      uVar17 = -uVar17;

    }

    uVar23 = (uVar17 & 0xffff) * (uVar16 & 0xffff);

    iVar10 = (uVar17 >> 0x10) * (uVar16 & 0xffff);

    iVar5 = 0;

    uVar22 = iVar10 + (uVar17 & 0xffff) * (uVar16 >> 0x10);

    if (iVar10 != 0) {

      iVar5 = 0x10000;

    }

    uVar19 = uVar23 + uVar22 * 0x10000;

    uVar17 = iVar5 + (unsigned int)(uVar19 < uVar23) + (uVar22 >> 0x10) +

             (uVar17 >> 0x10) * (uVar16 >> 0x10);

    if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

      uVar17 = ~uVar17;

      if (uVar19 == 0) {

        uVar17 = uVar17 + 1;

      }

      else {

        uVar19 = ~uVar19 + 1;

      }

    }

    if (((unsigned char)(uVar15 >> 1) & 1) == 1) {

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

    uVar1 = *(unsigned int *)(puVar3 + 4);

    uVar16 = puVar7[1];

    uVar22 = uVar1 ^ uVar16;

    if ((int)uVar1 < 0) {

      uVar1 = -uVar1;

    }

    if ((int)uVar16 < 0) {

      uVar16 = -uVar16;

    }

    uVar21 = (uVar16 & 0xffff) * (uVar1 & 0xffff);

    iVar10 = (uVar16 >> 0x10) * (uVar1 & 0xffff);

    iVar5 = 0;

    uVar23 = iVar10 + (uVar16 & 0xffff) * (uVar1 >> 0x10);

    if (iVar10 != 0) {

      iVar5 = 0x10000;

    }

    uVar20 = uVar21 + uVar23 * 0x10000;

    uVar16 = iVar5 + (unsigned int)(uVar20 < uVar21) + (uVar23 >> 0x10) + (uVar16 >> 0x10) * (uVar1 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar22 < 0) < 0) {

      uVar16 = ~uVar16;

      if (uVar20 == 0) {

        uVar16 = uVar16 + 1;

      }

      else {

        uVar20 = ~uVar20 + 1;

      }

    }

    if (((unsigned char)(uVar15 >> 1) & 1) == 1) {

      uVar20 = uVar19 + uVar20;

      uVar17 = uVar16 + (uVar20 < uVar19) + (uVar17 & 0xffff);

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

      uVar20 = uVar19 + uVar20;

      uVar17 = uVar16 + (uVar20 < uVar19) + uVar17;

    }

    uVar1 = *(unsigned int *)(puVar3 + 8);

    uVar16 = puVar7[2];

    uVar22 = uVar1 ^ uVar16;

    if ((int)uVar1 < 0) {

      uVar1 = -uVar1;

    }

    if ((int)uVar16 < 0) {

      uVar16 = -uVar16;

    }

    uVar19 = (uVar16 & 0xffff) * (uVar1 & 0xffff);

    iVar10 = (uVar16 >> 0x10) * (uVar1 & 0xffff);

    iVar5 = 0;

    uVar23 = iVar10 + (uVar16 & 0xffff) * (uVar1 >> 0x10);

    if (iVar10 != 0) {

      iVar5 = 0x10000;

    }

    uVar21 = uVar19 + uVar23 * 0x10000;

    uVar16 = iVar5 + (unsigned int)(uVar21 < uVar19) + (uVar23 >> 0x10) + (uVar16 >> 0x10) * (uVar1 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar22 < 0) < 0) {

      uVar16 = ~uVar16;

      if (uVar21 == 0) {

        uVar16 = uVar16 + 1;

      }

      else {

        uVar21 = ~uVar21 + 1;

      }

    }

    if (((unsigned char)(uVar15 >> 1) & 1) == 1) {

      uVar21 = uVar20 + uVar21;

      uVar17 = uVar16 + (uVar21 < uVar20) + (uVar17 & 0xffff);

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

      uVar17 = uVar16 + (uVar21 < uVar20) + uVar17;

    }

    uVar17 = uVar17 << 0x10 | uVar21 >> 0x10;

    uVar18 = uVar18 | 0 < (int)uVar17;

    in_r1 = extraout_r1;

    if (((unsigned char)uVar18 & 1) != 1) goto LAB_0602aa74;

  }

  FUN_0602ab3a();

  *puVar7 = extraout_r3_00;

  puVar7 = puVar7 + 1;

  FUN_0602ab00();

  FUN_0602ab3a();

  FUN_0602aaa0();

  *puVar7 = extraout_r3_01;

  puVar7 = puVar7 + 1;

  FUN_0602ab00();

  FUN_0602ab3a();

  FUN_0602aaa0();

  *puVar7 = extraout_r3_02;

  puVar7 = puVar7 + 1;

  FUN_0602ab00();

  FUN_0602ab3a();

  FUN_0602aaa0();

  *puVar7 = extraout_r3_03;

  FUN_0602ab00();

  puVar3 = 0x0608AC20;

  in_r1 = 0x18;

  uVar15 = *(unsigned int *)0x060620D0 & 0xffff;

  iVar13 = (int)DAT_0602a97e;

  uVar17 = *(unsigned int *)(puVar2 + -0x20);

  iVar5 = *(int *)(puVar2 + -0x18);

  puVar6 = *(unsigned int **)(puVar2 + -0x10);

  iVar10 = *(int *)(puVar2 + -8);

  uVar18 = uVar18 & 0xfffffffe;

  if ((((iVar13 <= (int)uVar17) || (iVar13 <= iVar5)) || (iVar13 <= (int)puVar6)) ||

     (iVar13 <= iVar10)) {

    iVar13 = (int)DAT_0602aa12;

    uVar16 = uVar18 | (int)uVar17 < iVar13;

    if (((((unsigned char)uVar16 & 1) == 1) || (uVar16 = uVar18 | iVar5 < iVar13, ((unsigned char)uVar16 & 1) == 1))

       || ((uVar16 = uVar18 | (int)puVar6 < iVar13, ((unsigned char)uVar16 & 1) == 1 ||

           (uVar18 = uVar18 | iVar10 < iVar13, uVar16 = uVar18, ((unsigned char)uVar18 & 1) != 1)))) {

      iVar14 = (int)DAT_0602aa14;

      in_r1 = *(unsigned int *)(puVar2 + -0x1c);

      iVar13 = *(int *)(puVar2 + -0x14);

      iVar8 = *(int *)(puVar2 + -0xc);

      iVar11 = *(int *)(puVar2 + -4);

      uVar18 = uVar16 & 0xfffffffe;

      if (((iVar14 <= (int)in_r1) || (iVar14 <= iVar13)) ||

         ((iVar14 <= iVar8 || (uVar18 = uVar18 | iVar11 < iVar14, ((unsigned char)uVar18 & 1) != 1)))) {

        iVar14 = (int)DAT_0602aa16;

        uVar18 = uVar18 & 0xfffffffe;

        if (((((int)in_r1 < iVar14) || (iVar13 < iVar14)) || (iVar8 < iVar14)) || (iVar11 < iVar14))

        {

          *(short *)(0x0608AC20 + uVar15 * 0x18 + 0x16) = (short)iVar11;

          *(short *)(puVar3 + uVar15 * 0x18 + 0x14) = (short)iVar10;

          *(short *)(puVar3 + uVar15 * 0x18 + 0x12) = (short)iVar8;

          *(short *)(puVar3 + uVar15 * 0x18 + 0x10) = (short)puVar6;

          *(short *)(puVar3 + uVar15 * 0x18 + 0xe) = (short)iVar13;

          *(short *)(puVar3 + uVar15 * 0x18 + 0xc) = (short)iVar5;

          *(short *)(puVar3 + uVar15 * 0x18 + 10) = (short)in_r1;

          *(short *)(puVar3 + uVar15 * 0x18 + 8) = (short)uVar17;

          *(short *)(puVar3 + uVar15 * 0x18 + 6) = *(short *)((int)puVar12 + -10);

          puVar3[uVar15 * 0x18 + 4] = (unsigned char)((unsigned int)(int)*(short *)(puVar12 + -3) >> 4) & 0xf;

          puVar3[uVar15 * 0x18 + 5] = unaff_r13;

          uVar24 = (**(void **)(0x0602ABA4 + ((int)*(short *)(puVar12 + -3) & 7U) * 4))

                             (DAT_0602ab8c,DAT_0602ab90,DAT_0602ab94);

          return uVar24;

        }

      }

    }

  }

  goto LAB_0602aa74;

}
