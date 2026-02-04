extern int DAT_0602b082;

extern int DAT_0602b116;

extern int DAT_0602b118;

extern int DAT_0602b11a;

extern int DAT_0602b24e;

extern int DAT_0602b2ec;

extern int DAT_0602b2f0;

extern int DAT_0602b2f4;

extern int PTR_DAT_0602b250;

extern int PTR_DAT_0602b250;

extern int FUN_0602b258();
extern int FUN_0602b298();

long long FUN_0602b1d6(param_1, param_2, param_3, param_4, param_5)
    int param_1;
    int param_2;
    unsigned int *param_3;
    int param_4;
    int param_5;
{

  short sVar1;

  short sVar2;

  char *puVar3;

  char *puVar4;

  short *psVar5;

  unsigned int extraout_r1;

  unsigned int uVar6;

  unsigned int extraout_r2;

  unsigned int extraout_r3;

  unsigned int extraout_r3_00;

  unsigned int extraout_r3_01;

  unsigned int extraout_r3_02;

  unsigned int extraout_r3_03;

  int iVar7;

  int iVar8;

  unsigned int *puVar9;

  int iVar10;

  unsigned int *puVar11;

  int iVar12;

  int iVar13;

  unsigned int *puVar14;

  unsigned int *unaff_r8;

  int unaff_r9;

  int *piVar15;

  int unaff_r10;

  int iVar16;

  int iVar17;

  char unaff_r13;

  int unaff_r14;

  unsigned int uVar18;

  unsigned int uVar19;

  unsigned int uVar20;

  unsigned int in_sr;

  unsigned int uVar21;

  unsigned int uVar22;

  unsigned int uVar23;

  unsigned int uVar24;

  unsigned int uVar25;

  unsigned int uVar26;

  long long uVar27;

  puVar3 = 0x0602B304;

  psVar5 = (short *)(param_1 * unaff_r9 + unaff_r14);

  sVar1 = psVar5[1];

  sVar2 = psVar5[2];

  uVar18 = in_sr & 0xfffffffe;

  uVar6 = (int)*psVar5 << 0xb;

  *(unsigned int *)0x0602B304 = uVar6;

  *(int *)(puVar3 + 4) = (int)sVar1 << 0xb;

  *(int *)(puVar3 + 8) = (int)sVar2 << 0xb;

  uVar20 = param_3[6];

  uVar21 = *(unsigned int *)puVar3;

  uVar19 = uVar20 ^ uVar21;

  if ((int)uVar20 < 0) {

    uVar20 = -uVar20;

  }

  if ((int)uVar21 < 0) {

    uVar21 = -uVar21;

  }

  uVar26 = (uVar21 & 0xffff) * (uVar20 & 0xffff);

  iVar8 = (uVar21 >> 0x10) * (uVar20 & 0xffff);

  iVar7 = 0;

  uVar25 = iVar8 + (uVar21 & 0xffff) * (uVar20 >> 0x10);

  if (iVar8 != 0) {

    iVar7 = 0x10000;

  }

  uVar22 = uVar26 + uVar25 * 0x10000;

  uVar21 = iVar7 + (unsigned int)(uVar22 < uVar26) + (uVar25 >> 0x10) + (uVar21 >> 0x10) * (uVar20 >> 0x10);

  if ((int)-(unsigned int)((int)uVar19 < 0) < 0) {

    uVar21 = ~uVar21;

    if (uVar22 == 0) {

      uVar21 = uVar21 + 1;

    }

    else {

      uVar22 = ~uVar22 + 1;

    }

  }

  if (((unsigned char)(in_sr >> 1) & 1) == 1) {

    if ((int)uVar21 < -0x8000) {

      uVar21 = 0xffff8000;

      uVar22 = 0;

    }

    if (0x7fff < (int)uVar21) {

      uVar21 = 0x7fff;

      uVar22 = 0xffffffff;

    }

    uVar21 = uVar21 & 0xffff;

  }

  uVar19 = param_3[7];

  uVar20 = *(unsigned int *)(puVar3 + 4);

  uVar25 = uVar19 ^ uVar20;

  if ((int)uVar19 < 0) {

    uVar19 = -uVar19;

  }

  if ((int)uVar20 < 0) {

    uVar20 = -uVar20;

  }

  uVar24 = (uVar20 & 0xffff) * (uVar19 & 0xffff);

  iVar8 = (uVar20 >> 0x10) * (uVar19 & 0xffff);

  iVar7 = 0;

  uVar26 = iVar8 + (uVar20 & 0xffff) * (uVar19 >> 0x10);

  if (iVar8 != 0) {

    iVar7 = 0x10000;

  }

  uVar23 = uVar24 + uVar26 * 0x10000;

  uVar20 = iVar7 + (unsigned int)(uVar23 < uVar24) + (uVar26 >> 0x10) + (uVar20 >> 0x10) * (uVar19 >> 0x10);

  if ((int)-(unsigned int)((int)uVar25 < 0) < 0) {

    uVar20 = ~uVar20;

    if (uVar23 == 0) {

      uVar20 = uVar20 + 1;

    }

    else {

      uVar23 = ~uVar23 + 1;

    }

  }

  if (((unsigned char)(in_sr >> 1) & 1) == 1) {

    uVar23 = uVar22 + uVar23;

    uVar20 = uVar20 + (uVar23 < uVar22) + (uVar21 & 0xffff);

    if ((int)uVar20 < -0x8000) {

      uVar20 = 0xffff8000;

      uVar23 = 0;

    }

    if (0x7fff < (int)uVar20) {

      uVar20 = 0x7fff;

      uVar23 = 0xffffffff;

    }

    uVar21 = uVar20 & 0xffff | uVar21 & 0xffff0000;

  }

  else {

    uVar23 = uVar22 + uVar23;

    uVar21 = uVar20 + (uVar23 < uVar22) + uVar21;

  }

  uVar19 = param_3[8];

  uVar20 = *(unsigned int *)(puVar3 + 8);

  uVar25 = uVar19 ^ uVar20;

  if ((int)uVar19 < 0) {

    uVar19 = -uVar19;

  }

  if ((int)uVar20 < 0) {

    uVar20 = -uVar20;

  }

  uVar22 = (uVar20 & 0xffff) * (uVar19 & 0xffff);

  iVar8 = (uVar20 >> 0x10) * (uVar19 & 0xffff);

  iVar7 = 0;

  uVar26 = iVar8 + (uVar20 & 0xffff) * (uVar19 >> 0x10);

  if (iVar8 != 0) {

    iVar7 = 0x10000;

  }

  uVar24 = uVar22 + uVar26 * 0x10000;

  uVar20 = iVar7 + (unsigned int)(uVar24 < uVar22) + (uVar26 >> 0x10) + (uVar20 >> 0x10) * (uVar19 >> 0x10);

  if ((int)-(unsigned int)((int)uVar25 < 0) < 0) {

    uVar20 = ~uVar20;

    if (uVar24 == 0) {

      uVar20 = uVar20 + 1;

    }

    else {

      uVar24 = ~uVar24 + 1;

    }

  }

  if (((unsigned char)(in_sr >> 1) & 1) == 1) {

    uVar24 = uVar23 + uVar24;

    uVar20 = uVar20 + (uVar24 < uVar23) + (uVar21 & 0xffff);

    if ((int)uVar20 < -0x8000) {

      uVar20 = 0xffff8000;

      uVar24 = 0;

    }

    if (0x7fff < (int)uVar20) {

      uVar20 = 0x7fff;

      uVar24 = 0xffffffff;

    }

    uVar21 = uVar20 & 0xffff | uVar21 & 0xffff0000;

  }

  else {

    uVar24 = uVar23 + uVar24;

    uVar21 = uVar20 + (uVar24 < uVar23) + uVar21;

  }

  iVar7 = (uVar21 << 0x10 | uVar24 >> 0x10) + param_3[0xb];

  if (unaff_r10 < iVar7) {

    piVar15 = (int *)(int)DAT_0602b24e;

    piVar15[4] = (int)PTR_DAT_0602b250;

    *piVar15 = iVar7;

    piVar15[5] = 0;

    uVar21 = *param_3;

    uVar18 = *(unsigned int *)puVar3;

    uVar20 = uVar21 ^ uVar18;

    if ((int)uVar21 < 0) {

      uVar21 = -uVar21;

    }

    if ((int)uVar18 < 0) {

      uVar18 = -uVar18;

    }

    uVar6 = (uVar18 & 0xffff) * (uVar21 & 0xffff);

    iVar8 = (uVar18 >> 0x10) * (uVar21 & 0xffff);

    iVar7 = 0;

    uVar19 = iVar8 + (uVar18 & 0xffff) * (uVar21 >> 0x10);

    if (iVar8 != 0) {

      iVar7 = 0x10000;

    }

    uVar25 = uVar6 + uVar19 * 0x10000;

    uVar18 = iVar7 + (unsigned int)(uVar25 < uVar6) + (uVar19 >> 0x10) + (uVar18 >> 0x10) * (uVar21 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar20 < 0) < 0) {

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

    uVar20 = param_3[1];

    uVar21 = *(unsigned int *)(puVar3 + 4);

    uVar19 = uVar20 ^ uVar21;

    if ((int)uVar20 < 0) {

      uVar20 = -uVar20;

    }

    if ((int)uVar21 < 0) {

      uVar21 = -uVar21;

    }

    uVar26 = (uVar21 & 0xffff) * (uVar20 & 0xffff);

    iVar8 = (uVar21 >> 0x10) * (uVar20 & 0xffff);

    iVar7 = 0;

    uVar6 = iVar8 + (uVar21 & 0xffff) * (uVar20 >> 0x10);

    if (iVar8 != 0) {

      iVar7 = 0x10000;

    }

    uVar22 = uVar26 + uVar6 * 0x10000;

    uVar21 = iVar7 + (unsigned int)(uVar22 < uVar26) + (uVar6 >> 0x10) + (uVar21 >> 0x10) * (uVar20 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar19 < 0) < 0) {

      uVar21 = ~uVar21;

      if (uVar22 == 0) {

        uVar21 = uVar21 + 1;

      }

      else {

        uVar22 = ~uVar22 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      uVar22 = uVar25 + uVar22;

      uVar18 = uVar21 + (uVar22 < uVar25) + (uVar18 & 0xffff);

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

      uVar22 = uVar25 + uVar22;

      uVar18 = uVar21 + (uVar22 < uVar25) + uVar18;

    }

    uVar20 = param_3[2];

    uVar21 = *(unsigned int *)(puVar3 + 8);

    uVar19 = uVar20 ^ uVar21;

    if ((int)uVar20 < 0) {

      uVar20 = -uVar20;

    }

    if ((int)uVar21 < 0) {

      uVar21 = -uVar21;

    }

    uVar25 = (uVar21 & 0xffff) * (uVar20 & 0xffff);

    iVar8 = (uVar21 >> 0x10) * (uVar20 & 0xffff);

    iVar7 = 0;

    uVar6 = iVar8 + (uVar21 & 0xffff) * (uVar20 >> 0x10);

    if (iVar8 != 0) {

      iVar7 = 0x10000;

    }

    uVar26 = uVar25 + uVar6 * 0x10000;

    uVar21 = iVar7 + (unsigned int)(uVar26 < uVar25) + (uVar6 >> 0x10) + (uVar21 >> 0x10) * (uVar20 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar19 < 0) < 0) {

      uVar21 = ~uVar21;

      if (uVar26 == 0) {

        uVar21 = uVar21 + 1;

      }

      else {

        uVar26 = ~uVar26 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      uVar26 = uVar22 + uVar26;

      uVar18 = uVar21 + (uVar26 < uVar22) + (uVar18 & 0xffff);

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

      uVar26 = uVar22 + uVar26;

      uVar18 = uVar21 + (uVar26 < uVar22) + uVar18;

    }

    uVar20 = param_3[3];

    uVar21 = *(unsigned int *)puVar3;

    uVar19 = uVar20 ^ uVar21;

    if ((int)uVar20 < 0) {

      uVar20 = -uVar20;

    }

    if ((int)uVar21 < 0) {

      uVar21 = -uVar21;

    }

    uVar25 = (uVar21 & 0xffff) * (uVar20 & 0xffff);

    iVar8 = (uVar21 >> 0x10) * (uVar20 & 0xffff);

    iVar7 = 0;

    uVar6 = iVar8 + (uVar21 & 0xffff) * (uVar20 >> 0x10);

    if (iVar8 != 0) {

      iVar7 = 0x10000;

    }

    uVar22 = uVar25 + uVar6 * 0x10000;

    uVar21 = iVar7 + (unsigned int)(uVar22 < uVar25) + (uVar6 >> 0x10) + (uVar21 >> 0x10) * (uVar20 >> 0x10)

    ;

    if ((int)-(unsigned int)((int)uVar19 < 0) < 0) {

      uVar21 = ~uVar21;

      if (uVar22 == 0) {

        uVar21 = uVar21 + 1;

      }

      else {

        uVar22 = ~uVar22 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      if ((int)uVar21 < -0x8000) {

        uVar21 = 0xffff8000;

        uVar22 = 0;

      }

      if (0x7fff < (int)uVar21) {

        uVar21 = 0x7fff;

        uVar22 = 0xffffffff;

      }

      uVar21 = uVar21 & 0xffff;

    }

    uVar19 = param_3[4];

    uVar20 = *(unsigned int *)(puVar3 + 4);

    uVar6 = uVar19 ^ uVar20;

    if ((int)uVar19 < 0) {

      uVar19 = -uVar19;

    }

    if ((int)uVar20 < 0) {

      uVar20 = -uVar20;

    }

    uVar24 = (uVar20 & 0xffff) * (uVar19 & 0xffff);

    iVar8 = (uVar20 >> 0x10) * (uVar19 & 0xffff);

    iVar7 = 0;

    uVar25 = iVar8 + (uVar20 & 0xffff) * (uVar19 >> 0x10);

    if (iVar8 != 0) {

      iVar7 = 0x10000;

    }

    uVar23 = uVar24 + uVar25 * 0x10000;

    uVar20 = iVar7 + (unsigned int)(uVar23 < uVar24) + (uVar25 >> 0x10) +

             (uVar20 >> 0x10) * (uVar19 >> 0x10);

    if ((int)-(unsigned int)((int)uVar6 < 0) < 0) {

      uVar20 = ~uVar20;

      if (uVar23 == 0) {

        uVar20 = uVar20 + 1;

      }

      else {

        uVar23 = ~uVar23 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      uVar23 = uVar22 + uVar23;

      uVar20 = uVar20 + (uVar23 < uVar22) + (uVar21 & 0xffff);

      if ((int)uVar20 < -0x8000) {

        uVar20 = 0xffff8000;

        uVar23 = 0;

      }

      if (0x7fff < (int)uVar20) {

        uVar20 = 0x7fff;

        uVar23 = 0xffffffff;

      }

      uVar21 = uVar20 & 0xffff | uVar21 & 0xffff0000;

    }

    else {

      uVar23 = uVar22 + uVar23;

      uVar21 = uVar20 + (uVar23 < uVar22) + uVar21;

    }

    uVar19 = param_3[5];

    uVar20 = *(unsigned int *)(puVar3 + 8);

    uVar6 = uVar19 ^ uVar20;

    if ((int)uVar19 < 0) {

      uVar19 = -uVar19;

    }

    if ((int)uVar20 < 0) {

      uVar20 = -uVar20;

    }

    uVar22 = (uVar20 & 0xffff) * (uVar19 & 0xffff);

    iVar8 = (uVar20 >> 0x10) * (uVar19 & 0xffff);

    iVar7 = 0;

    uVar25 = iVar8 + (uVar20 & 0xffff) * (uVar19 >> 0x10);

    if (iVar8 != 0) {

      iVar7 = 0x10000;

    }

    uVar24 = uVar22 + uVar25 * 0x10000;

    uVar20 = iVar7 + (unsigned int)(uVar24 < uVar22) + (uVar25 >> 0x10) +

             (uVar20 >> 0x10) * (uVar19 >> 0x10);

    if ((int)-(unsigned int)((int)uVar6 < 0) < 0) {

      uVar20 = ~uVar20;

      if (uVar24 == 0) {

        uVar20 = uVar20 + 1;

      }

      else {

        uVar24 = ~uVar24 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      uVar20 = uVar20 + (uVar23 + uVar24 < uVar23) + (uVar21 & 0xffff);

      if ((int)uVar20 < -0x8000) {

        uVar20 = 0xffff8000;

      }

      if (0x7fff < (int)uVar20) {

        uVar20 = 0x7fff;

      }

      uVar21 = uVar20 & 0xffff | uVar21 & 0xffff0000;

    }

    else {

      uVar21 = uVar20 + (uVar23 + uVar24 < uVar23) + uVar21;

    }

    return CONCAT44((uVar18 << 0x10 | uVar26 >> 0x10) + param_3[9],uVar21);

  }

LAB_0602b19e:

  do {

    puVar14 = unaff_r8;

    puVar3 = 0x0602B2C8;

    param_5 = param_5 + -1;

    uVar20 = uVar18 & 0xfffffffe | (unsigned int)(param_5 == 0);

    if (((unsigned char)uVar20 & 1) == 1) {

      return CONCAT44(uVar6,uVar21);

    }

    unaff_r8 = puVar14 + -6;

    puVar11 = *(unsigned int **)0x06089EDC;

    puVar9 = (unsigned int *)0x0602B2E8;

    FUN_0602b1d6(*(short *)(puVar14 + -2));

    *puVar9 = extraout_r1;

    puVar9[1] = extraout_r2;

    puVar9[2] = extraout_r3;

    *(unsigned int *)0x0602B310 = extraout_r2;

    puVar4 = 0x0602B2F8;

    uVar18 = uVar20 & 0xfffffffe;

    if ((puVar14[-3] & 0x80000) == 0) {

      uVar19 = *puVar11;

      uVar21 = *unaff_r8;

      uVar6 = uVar19 ^ uVar21;

      if ((int)uVar19 < 0) {

        uVar19 = -uVar19;

      }

      if ((int)uVar21 < 0) {

        uVar21 = -uVar21;

      }

      uVar26 = (uVar21 & 0xffff) * (uVar19 & 0xffff);

      iVar8 = (uVar21 >> 0x10) * (uVar19 & 0xffff);

      iVar7 = 0;

      uVar25 = iVar8 + (uVar21 & 0xffff) * (uVar19 >> 0x10);

      if (iVar8 != 0) {

        iVar7 = 0x10000;

      }

      uVar22 = uVar26 + uVar25 * 0x10000;

      uVar21 = iVar7 + (unsigned int)(uVar22 < uVar26) + (uVar25 >> 0x10) +

               (uVar21 >> 0x10) * (uVar19 >> 0x10);

      if ((int)-(unsigned int)((int)uVar6 < 0) < 0) {

        uVar21 = ~uVar21;

        if (uVar22 == 0) {

          uVar21 = uVar21 + 1;

        }

        else {

          uVar22 = ~uVar22 + 1;

        }

      }

      if (((unsigned char)(uVar20 >> 1) & 1) == 1) {

        if ((int)uVar21 < -0x8000) {

          uVar21 = 0xffff8000;

          uVar22 = 0;

        }

        if (0x7fff < (int)uVar21) {

          uVar21 = 0x7fff;

          uVar22 = 0xffffffff;

        }

        uVar21 = uVar21 & 0xffff;

      }

      uVar6 = puVar11[1];

      uVar19 = puVar14[-5];

      uVar25 = uVar6 ^ uVar19;

      if ((int)uVar6 < 0) {

        uVar6 = -uVar6;

      }

      if ((int)uVar19 < 0) {

        uVar19 = -uVar19;

      }

      uVar24 = (uVar19 & 0xffff) * (uVar6 & 0xffff);

      iVar8 = (uVar19 >> 0x10) * (uVar6 & 0xffff);

      iVar7 = 0;

      uVar26 = iVar8 + (uVar19 & 0xffff) * (uVar6 >> 0x10);

      if (iVar8 != 0) {

        iVar7 = 0x10000;

      }

      uVar23 = uVar24 + uVar26 * 0x10000;

      uVar19 = iVar7 + (unsigned int)(uVar23 < uVar24) + (uVar26 >> 0x10) +

               (uVar19 >> 0x10) * (uVar6 >> 0x10);

      if ((int)-(unsigned int)((int)uVar25 < 0) < 0) {

        uVar19 = ~uVar19;

        if (uVar23 == 0) {

          uVar19 = uVar19 + 1;

        }

        else {

          uVar23 = ~uVar23 + 1;

        }

      }

      if (((unsigned char)(uVar20 >> 1) & 1) == 1) {

        uVar23 = uVar22 + uVar23;

        uVar21 = uVar19 + (uVar23 < uVar22) + (uVar21 & 0xffff);

        if ((int)uVar21 < -0x8000) {

          uVar21 = 0xffff8000;

          uVar23 = 0;

        }

        if (0x7fff < (int)uVar21) {

          uVar21 = 0x7fff;

          uVar23 = 0xffffffff;

        }

        uVar21 = uVar21 & 0xffff;

      }

      else {

        uVar23 = uVar22 + uVar23;

        uVar21 = uVar19 + (uVar23 < uVar22) + uVar21;

      }

      uVar6 = puVar11[2];

      uVar19 = puVar14[-4];

      uVar25 = uVar6 ^ uVar19;

      if ((int)uVar6 < 0) {

        uVar6 = -uVar6;

      }

      if ((int)uVar19 < 0) {

        uVar19 = -uVar19;

      }

      uVar22 = (uVar19 & 0xffff) * (uVar6 & 0xffff);

      iVar8 = (uVar19 >> 0x10) * (uVar6 & 0xffff);

      iVar7 = 0;

      uVar26 = iVar8 + (uVar19 & 0xffff) * (uVar6 >> 0x10);

      if (iVar8 != 0) {

        iVar7 = 0x10000;

      }

      uVar24 = uVar22 + uVar26 * 0x10000;

      uVar19 = iVar7 + (unsigned int)(uVar24 < uVar22) + (uVar26 >> 0x10) +

               (uVar19 >> 0x10) * (uVar6 >> 0x10);

      if ((int)-(unsigned int)((int)uVar25 < 0) < 0) {

        uVar19 = ~uVar19;

        if (uVar24 == 0) {

          uVar19 = uVar19 + 1;

        }

        else {

          uVar24 = ~uVar24 + 1;

        }

      }

      if (((unsigned char)(uVar20 >> 1) & 1) == 1) {

        uVar24 = uVar23 + uVar24;

        uVar21 = uVar19 + (uVar24 < uVar23) + (uVar21 & 0xffff);

        if ((int)uVar21 < -0x8000) {

          uVar21 = 0xffff8000;

          uVar24 = 0;

        }

        if (0x7fff < (int)uVar21) {

          uVar21 = 0x7fff;

          uVar24 = 0xffffffff;

        }

        uVar21 = uVar21 & 0xffff;

      }

      else {

        uVar24 = uVar23 + uVar24;

        uVar21 = uVar19 + (uVar24 < uVar23) + uVar21;

      }

      uVar6 = puVar11[3];

      uVar19 = *unaff_r8;

      uVar25 = uVar6 ^ uVar19;

      if ((int)uVar6 < 0) {

        uVar6 = -uVar6;

      }

      if ((int)uVar19 < 0) {

        uVar19 = -uVar19;

      }

      uVar22 = (uVar19 & 0xffff) * (uVar6 & 0xffff);

      iVar8 = (uVar19 >> 0x10) * (uVar6 & 0xffff);

      iVar7 = 0;

      uVar26 = iVar8 + (uVar19 & 0xffff) * (uVar6 >> 0x10);

      if (iVar8 != 0) {

        iVar7 = 0x10000;

      }

      uVar23 = uVar22 + uVar26 * 0x10000;

      uVar19 = iVar7 + (unsigned int)(uVar23 < uVar22) + (uVar26 >> 0x10) +

               (uVar19 >> 0x10) * (uVar6 >> 0x10);

      if ((int)-(unsigned int)((int)uVar25 < 0) < 0) {

        uVar19 = ~uVar19;

        if (uVar23 == 0) {

          uVar19 = uVar19 + 1;

        }

        else {

          uVar23 = ~uVar23 + 1;

        }

      }

      if (((unsigned char)(uVar20 >> 1) & 1) == 1) {

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

      *(unsigned int *)0x0602B2F8 = uVar21 << 0x10 | uVar24 >> 0x10;

      uVar6 = puVar11[4];

      uVar21 = puVar14[-5];

      uVar25 = uVar6 ^ uVar21;

      if ((int)uVar6 < 0) {

        uVar6 = -uVar6;

      }

      if ((int)uVar21 < 0) {

        uVar21 = -uVar21;

      }

      uVar22 = (uVar21 & 0xffff) * (uVar6 & 0xffff);

      iVar8 = (uVar21 >> 0x10) * (uVar6 & 0xffff);

      iVar7 = 0;

      uVar26 = iVar8 + (uVar21 & 0xffff) * (uVar6 >> 0x10);

      if (iVar8 != 0) {

        iVar7 = 0x10000;

      }

      uVar24 = uVar22 + uVar26 * 0x10000;

      uVar21 = iVar7 + (unsigned int)(uVar24 < uVar22) + (uVar26 >> 0x10) +

               (uVar21 >> 0x10) * (uVar6 >> 0x10);

      if ((int)-(unsigned int)((int)uVar25 < 0) < 0) {

        uVar21 = ~uVar21;

        if (uVar24 == 0) {

          uVar21 = uVar21 + 1;

        }

        else {

          uVar24 = ~uVar24 + 1;

        }

      }

      if (((unsigned char)(uVar20 >> 1) & 1) == 1) {

        uVar24 = uVar23 + uVar24;

        uVar19 = uVar21 + (uVar24 < uVar23) + (uVar19 & 0xffff);

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

        uVar19 = uVar21 + (uVar24 < uVar23) + uVar19;

      }

      uVar6 = puVar11[5];

      uVar21 = puVar14[-4];

      uVar25 = uVar6 ^ uVar21;

      if ((int)uVar6 < 0) {

        uVar6 = -uVar6;

      }

      if ((int)uVar21 < 0) {

        uVar21 = -uVar21;

      }

      uVar22 = (uVar21 & 0xffff) * (uVar6 & 0xffff);

      iVar8 = (uVar21 >> 0x10) * (uVar6 & 0xffff);

      iVar7 = 0;

      uVar26 = iVar8 + (uVar21 & 0xffff) * (uVar6 >> 0x10);

      if (iVar8 != 0) {

        iVar7 = 0x10000;

      }

      uVar23 = uVar22 + uVar26 * 0x10000;

      uVar21 = iVar7 + (unsigned int)(uVar23 < uVar22) + (uVar26 >> 0x10) +

               (uVar21 >> 0x10) * (uVar6 >> 0x10);

      if ((int)-(unsigned int)((int)uVar25 < 0) < 0) {

        uVar21 = ~uVar21;

        if (uVar23 == 0) {

          uVar21 = uVar21 + 1;

        }

        else {

          uVar23 = ~uVar23 + 1;

        }

      }

      if (((unsigned char)(uVar20 >> 1) & 1) == 1) {

        uVar23 = uVar24 + uVar23;

        uVar19 = uVar21 + (uVar23 < uVar24) + (uVar19 & 0xffff);

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

        uVar19 = uVar21 + (uVar23 < uVar24) + uVar19;

      }

      uVar6 = puVar11[6];

      uVar21 = *unaff_r8;

      uVar25 = uVar6 ^ uVar21;

      if ((int)uVar6 < 0) {

        uVar6 = -uVar6;

      }

      if ((int)uVar21 < 0) {

        uVar21 = -uVar21;

      }

      uVar22 = (uVar21 & 0xffff) * (uVar6 & 0xffff);

      iVar8 = (uVar21 >> 0x10) * (uVar6 & 0xffff);

      iVar7 = 0;

      uVar26 = iVar8 + (uVar21 & 0xffff) * (uVar6 >> 0x10);

      if (iVar8 != 0) {

        iVar7 = 0x10000;

      }

      uVar24 = uVar22 + uVar26 * 0x10000;

      uVar21 = iVar7 + (unsigned int)(uVar24 < uVar22) + (uVar26 >> 0x10) +

               (uVar21 >> 0x10) * (uVar6 >> 0x10);

      if ((int)-(unsigned int)((int)uVar25 < 0) < 0) {

        uVar21 = ~uVar21;

        if (uVar24 == 0) {

          uVar21 = uVar21 + 1;

        }

        else {

          uVar24 = ~uVar24 + 1;

        }

      }

      if (((unsigned char)(uVar20 >> 1) & 1) == 1) {

        if ((int)uVar21 < -0x8000) {

          uVar21 = 0xffff8000;

          uVar24 = 0;

        }

        if (0x7fff < (int)uVar21) {

          uVar21 = 0x7fff;

          uVar24 = 0xffffffff;

        }

        uVar21 = uVar21 & 0xffff;

      }

      *(unsigned int *)(puVar4 + 4) = uVar19 << 0x10 | uVar23 >> 0x10;

      uVar6 = puVar11[7];

      uVar19 = puVar14[-5];

      uVar25 = uVar6 ^ uVar19;

      if ((int)uVar6 < 0) {

        uVar6 = -uVar6;

      }

      if ((int)uVar19 < 0) {

        uVar19 = -uVar19;

      }

      uVar22 = (uVar19 & 0xffff) * (uVar6 & 0xffff);

      iVar8 = (uVar19 >> 0x10) * (uVar6 & 0xffff);

      iVar7 = 0;

      uVar26 = iVar8 + (uVar19 & 0xffff) * (uVar6 >> 0x10);

      if (iVar8 != 0) {

        iVar7 = 0x10000;

      }

      uVar23 = uVar22 + uVar26 * 0x10000;

      uVar19 = iVar7 + (unsigned int)(uVar23 < uVar22) + (uVar26 >> 0x10) +

               (uVar19 >> 0x10) * (uVar6 >> 0x10);

      if ((int)-(unsigned int)((int)uVar25 < 0) < 0) {

        uVar19 = ~uVar19;

        if (uVar23 == 0) {

          uVar19 = uVar19 + 1;

        }

        else {

          uVar23 = ~uVar23 + 1;

        }

      }

      if (((unsigned char)(uVar20 >> 1) & 1) == 1) {

        uVar23 = uVar24 + uVar23;

        uVar21 = uVar19 + (uVar23 < uVar24) + (uVar21 & 0xffff);

        if ((int)uVar21 < -0x8000) {

          uVar21 = 0xffff8000;

          uVar23 = 0;

        }

        if (0x7fff < (int)uVar21) {

          uVar21 = 0x7fff;

          uVar23 = 0xffffffff;

        }

        uVar21 = uVar21 & 0xffff;

      }

      else {

        uVar23 = uVar24 + uVar23;

        uVar21 = uVar19 + (uVar23 < uVar24) + uVar21;

      }

      uVar6 = puVar11[8];

      uVar19 = puVar14[-4];

      uVar25 = uVar6 ^ uVar19;

      if ((int)uVar6 < 0) {

        uVar6 = -uVar6;

      }

      if ((int)uVar19 < 0) {

        uVar19 = -uVar19;

      }

      uVar22 = (uVar19 & 0xffff) * (uVar6 & 0xffff);

      iVar8 = (uVar19 >> 0x10) * (uVar6 & 0xffff);

      iVar7 = 0;

      uVar26 = iVar8 + (uVar19 & 0xffff) * (uVar6 >> 0x10);

      if (iVar8 != 0) {

        iVar7 = 0x10000;

      }

      uVar24 = uVar22 + uVar26 * 0x10000;

      uVar19 = iVar7 + (unsigned int)(uVar24 < uVar22) + (uVar26 >> 0x10) +

               (uVar19 >> 0x10) * (uVar6 >> 0x10);

      if ((int)-(unsigned int)((int)uVar25 < 0) < 0) {

        uVar19 = ~uVar19;

        if (uVar24 == 0) {

          uVar19 = uVar19 + 1;

        }

        else {

          uVar24 = ~uVar24 + 1;

        }

      }

      if (((unsigned char)(uVar20 >> 1) & 1) == 1) {

        uVar24 = uVar23 + uVar24;

        uVar21 = uVar19 + (uVar24 < uVar23) + (uVar21 & 0xffff);

        if ((int)uVar21 < -0x8000) {

          uVar21 = 0xffff8000;

          uVar24 = 0;

        }

        if (0x7fff < (int)uVar21) {

          uVar21 = 0x7fff;

          uVar24 = 0xffffffff;

        }

        uVar21 = uVar21 & 0xffff;

      }

      else {

        uVar24 = uVar23 + uVar24;

        uVar21 = uVar19 + (uVar24 < uVar23) + uVar21;

      }

      *(unsigned int *)(puVar4 + 8) = uVar21 << 0x10 | uVar24 >> 0x10;

      uVar19 = *(unsigned int *)puVar4;

      uVar21 = *puVar9;

      uVar6 = uVar19 ^ uVar21;

      if ((int)uVar19 < 0) {

        uVar19 = -uVar19;

      }

      if ((int)uVar21 < 0) {

        uVar21 = -uVar21;

      }

      uVar26 = (uVar21 & 0xffff) * (uVar19 & 0xffff);

      iVar8 = (uVar21 >> 0x10) * (uVar19 & 0xffff);

      iVar7 = 0;

      uVar25 = iVar8 + (uVar21 & 0xffff) * (uVar19 >> 0x10);

      if (iVar8 != 0) {

        iVar7 = 0x10000;

      }

      uVar22 = uVar26 + uVar25 * 0x10000;

      uVar21 = iVar7 + (unsigned int)(uVar22 < uVar26) + (uVar25 >> 0x10) +

               (uVar21 >> 0x10) * (uVar19 >> 0x10);

      if ((int)-(unsigned int)((int)uVar6 < 0) < 0) {

        uVar21 = ~uVar21;

        if (uVar22 == 0) {

          uVar21 = uVar21 + 1;

        }

        else {

          uVar22 = ~uVar22 + 1;

        }

      }

      if (((unsigned char)(uVar20 >> 1) & 1) == 1) {

        if ((int)uVar21 < -0x8000) {

          uVar21 = 0xffff8000;

          uVar22 = 0;

        }

        if (0x7fff < (int)uVar21) {

          uVar21 = 0x7fff;

          uVar22 = 0xffffffff;

        }

        uVar21 = uVar21 & 0xffff;

      }

      uVar6 = *(unsigned int *)(puVar4 + 4);

      uVar19 = puVar9[1];

      uVar25 = uVar6 ^ uVar19;

      if ((int)uVar6 < 0) {

        uVar6 = -uVar6;

      }

      if ((int)uVar19 < 0) {

        uVar19 = -uVar19;

      }

      uVar24 = (uVar19 & 0xffff) * (uVar6 & 0xffff);

      iVar8 = (uVar19 >> 0x10) * (uVar6 & 0xffff);

      iVar7 = 0;

      uVar26 = iVar8 + (uVar19 & 0xffff) * (uVar6 >> 0x10);

      if (iVar8 != 0) {

        iVar7 = 0x10000;

      }

      uVar23 = uVar24 + uVar26 * 0x10000;

      uVar19 = iVar7 + (unsigned int)(uVar23 < uVar24) + (uVar26 >> 0x10) +

               (uVar19 >> 0x10) * (uVar6 >> 0x10);

      if ((int)-(unsigned int)((int)uVar25 < 0) < 0) {

        uVar19 = ~uVar19;

        if (uVar23 == 0) {

          uVar19 = uVar19 + 1;

        }

        else {

          uVar23 = ~uVar23 + 1;

        }

      }

      if (((unsigned char)(uVar20 >> 1) & 1) == 1) {

        uVar23 = uVar22 + uVar23;

        uVar21 = uVar19 + (uVar23 < uVar22) + (uVar21 & 0xffff);

        if ((int)uVar21 < -0x8000) {

          uVar21 = 0xffff8000;

          uVar23 = 0;

        }

        if (0x7fff < (int)uVar21) {

          uVar21 = 0x7fff;

          uVar23 = 0xffffffff;

        }

        uVar21 = uVar21 & 0xffff;

      }

      else {

        uVar23 = uVar22 + uVar23;

        uVar21 = uVar19 + (uVar23 < uVar22) + uVar21;

      }

      uVar6 = *(unsigned int *)(puVar4 + 8);

      uVar19 = puVar9[2];

      uVar25 = uVar6 ^ uVar19;

      if ((int)uVar6 < 0) {

        uVar6 = -uVar6;

      }

      if ((int)uVar19 < 0) {

        uVar19 = -uVar19;

      }

      uVar22 = (uVar19 & 0xffff) * (uVar6 & 0xffff);

      iVar8 = (uVar19 >> 0x10) * (uVar6 & 0xffff);

      iVar7 = 0;

      uVar26 = iVar8 + (uVar19 & 0xffff) * (uVar6 >> 0x10);

      if (iVar8 != 0) {

        iVar7 = 0x10000;

      }

      uVar24 = uVar22 + uVar26 * 0x10000;

      uVar19 = iVar7 + (unsigned int)(uVar24 < uVar22) + (uVar26 >> 0x10) +

               (uVar19 >> 0x10) * (uVar6 >> 0x10);

      if ((int)-(unsigned int)((int)uVar25 < 0) < 0) {

        uVar19 = ~uVar19;

        if (uVar24 == 0) {

          uVar19 = uVar19 + 1;

        }

        else {

          uVar24 = ~uVar24 + 1;

        }

      }

      if (((unsigned char)(uVar20 >> 1) & 1) == 1) {

        uVar24 = uVar23 + uVar24;

        uVar21 = uVar19 + (uVar24 < uVar23) + (uVar21 & 0xffff);

        if ((int)uVar21 < -0x8000) {

          uVar21 = 0xffff8000;

          uVar24 = 0;

        }

        if (0x7fff < (int)uVar21) {

          uVar21 = 0x7fff;

          uVar24 = 0xffffffff;

        }

        uVar21 = uVar21 & 0xffff;

      }

      else {

        uVar24 = uVar23 + uVar24;

        uVar21 = uVar19 + (uVar24 < uVar23) + uVar21;

      }

      uVar21 = uVar21 << 0x10 | uVar24 >> 0x10;

      uVar18 = uVar18 | 0 < (int)uVar21;

      uVar6 = extraout_r1;

      if (((unsigned char)uVar18 & 1) != 1) goto LAB_0602b19e;

    }

    FUN_0602b298((int)*(short *)(puVar14 + -2));

    *puVar9 = extraout_r3_00;

    puVar9 = puVar9 + 1;

    FUN_0602b258();

    FUN_0602b298((int)*(short *)((int)puVar14 + -6));

    FUN_0602b1d6();

    *puVar9 = extraout_r3_01;

    puVar9 = puVar9 + 1;

    FUN_0602b258();

    FUN_0602b298((int)*(short *)(puVar14 + -1));

    FUN_0602b1d6();

    *puVar9 = extraout_r3_02;

    puVar9 = puVar9 + 1;

    FUN_0602b258();

    FUN_0602b298((int)*(short *)((int)puVar14 + -2));

    FUN_0602b1d6();

    *puVar9 = extraout_r3_03;

    FUN_0602b258();

    puVar4 = 0x0608AC20;

    uVar6 = 0x18;

    uVar20 = *(unsigned int *)0x060620D0 & 0xffff;

    iVar16 = (int)DAT_0602b082;

    uVar21 = *(unsigned int *)(puVar3 + -0x20);

    iVar7 = *(int *)(puVar3 + -0x18);

    iVar8 = *(int *)(puVar3 + -0x10);

    iVar12 = *(int *)(puVar3 + -8);

    uVar18 = uVar18 & 0xfffffffe;

    if ((((iVar16 <= (int)uVar21) || (iVar16 <= iVar7)) || (iVar16 <= iVar8)) || (iVar16 <= iVar12))

    {

      iVar16 = (int)DAT_0602b116;

      uVar19 = uVar18 | (int)uVar21 < iVar16;

      if (((((unsigned char)uVar19 & 1) == 1) || (uVar19 = uVar18 | iVar7 < iVar16, ((unsigned char)uVar19 & 1) == 1))

         || ((uVar19 = uVar18 | iVar8 < iVar16, ((unsigned char)uVar19 & 1) == 1 ||

             (uVar18 = uVar18 | iVar12 < iVar16, uVar19 = uVar18, ((unsigned char)uVar18 & 1) != 1)))) {

        iVar17 = (int)DAT_0602b118;

        uVar6 = *(unsigned int *)(puVar3 + -0x1c);

        iVar16 = *(int *)(puVar3 + -0x14);

        iVar10 = *(int *)(puVar3 + -0xc);

        iVar13 = *(int *)(puVar3 + -4);

        uVar18 = uVar19 & 0xfffffffe;

        if (((iVar17 <= (int)uVar6) || (iVar17 <= iVar16)) ||

           ((iVar17 <= iVar10 || (uVar18 = uVar18 | iVar13 < iVar17, ((unsigned char)uVar18 & 1) != 1)))) {

          iVar17 = (int)DAT_0602b11a;

          uVar18 = uVar18 & 0xfffffffe;

          if (((((int)uVar6 < iVar17) || (iVar16 < iVar17)) || (iVar10 < iVar17)) ||

             (iVar13 < iVar17)) {

            *(short *)(0x0608AC20 + uVar20 * 0x18 + 0x16) = (short)iVar13;

            *(short *)(puVar4 + uVar20 * 0x18 + 0x14) = (short)iVar12;

            *(short *)(puVar4 + uVar20 * 0x18 + 0x12) = (short)iVar10;

            *(short *)(puVar4 + uVar20 * 0x18 + 0x10) = (short)iVar8;

            *(short *)(puVar4 + uVar20 * 0x18 + 0xe) = (short)iVar16;

            *(short *)(puVar4 + uVar20 * 0x18 + 0xc) = (short)iVar7;

            *(short *)(puVar4 + uVar20 * 0x18 + 10) = (short)uVar6;

            *(short *)(puVar4 + uVar20 * 0x18 + 8) = (short)uVar21;

            *(short *)(puVar4 + uVar20 * 0x18 + 6) = *(short *)((int)puVar14 + -10);

            puVar4[uVar20 * 0x18 + 4] = (unsigned char)((unsigned int)(int)*(short *)(puVar14 + -3) >> 4) & 0xf;

            puVar4[uVar20 * 0x18 + 5] = unaff_r13;

            uVar27 = (**(void **)(0x0602B314 + ((int)*(short *)(puVar14 + -3) & 7U) * 4))

                               (DAT_0602b2ec,DAT_0602b2f0,DAT_0602b2f4);

            return uVar27;

          }

        }

      }

    }

  } while( 1 );

}
