/* FUN_0602AA6E  0x0602AA6E */


uint FUN_0602aa6e(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined *puVar4;
  undefined *puVar5;
  int in_r0;
  uint uVar6;
  uint extraout_r1;
  uint extraout_r2;
  int iVar7;
  uint *in_r2;
  uint extraout_r3;
  uint extraout_r3_00;
  uint extraout_r3_01;
  uint extraout_r3_02;
  uint extraout_r3_03;
  int iVar8;
  uint *puVar9;
  int iVar10;
  uint *puVar11;
  int iVar12;
  int iVar13;
  uint *unaff_r8;
  uint *puVar14;
  int iVar15;
  int iVar16;
  undefined1 unaff_r13;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint in_sr;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  int in_stack_00000000;
  
  uVar18 = in_sr & 0xfffffffe;
  uVar6 = (in_r0 >> 1) + 1;
  *in_r2 = uVar6;
LAB_0602aa74:
  do {
    puVar14 = unaff_r8;
    puVar4 = PTR_DAT_0602a8fc;
    in_stack_00000000 = in_stack_00000000 + -1;
    uVar18 = uVar18 & 0xfffffffe;
    if (in_stack_00000000 == 0) {
      return uVar6;
    }
    unaff_r8 = puVar14 + -6;
    uVar17 = uVar18 | *(short *)PTR_DAT_0602a888 == 0;
  } while ((((byte)uVar17 & 1) != 1) &&
          (uVar6 = (uint)*(short *)((int)puVar14 + -10), uVar17 = uVar18,
          (int)PTR_DAT_0602a87c._0_2_ == uVar6));
  puVar11 = *(uint **)PTR_DAT_0602a904;
  puVar9 = (uint *)PTR_DAT_0602a900;
  FUN_0602aaa0(param_1);
  *puVar9 = extraout_r1;
  puVar9[1] = extraout_r2;
  puVar9[2] = extraout_r3;
  puVar5 = PTR_DAT_0602a908;
  uVar18 = uVar17 & 0xfffffffe;
  if ((puVar14[-3] & 0x80000) == 0) {
    uVar19 = *puVar11;
    uVar6 = *unaff_r8;
    uVar3 = uVar19 ^ uVar6;
    if ((int)uVar19 < 0) {
      uVar19 = -uVar19;
    }
    if ((int)uVar6 < 0) {
      uVar6 = -uVar6;
    }
    uVar2 = (uVar6 & 0xffff) * (uVar19 & 0xffff);
    iVar12 = (uVar6 >> 0x10) * (uVar19 & 0xffff);
    iVar7 = 0;
    uVar1 = iVar12 + (uVar6 & 0xffff) * (uVar19 >> 0x10);
    if (iVar12 != 0) {
      iVar7 = 0x10000;
    }
    uVar20 = uVar2 + uVar1 * 0x10000;
    uVar6 = iVar7 + (uint)(uVar20 < uVar2) + (uVar1 >> 0x10) + (uVar6 >> 0x10) * (uVar19 >> 0x10);
    if ((int)-(uint)((int)uVar3 < 0) < 0) {
      uVar6 = ~uVar6;
      if (uVar20 == 0) {
        uVar6 = uVar6 + 1;
      }
      else {
        uVar20 = ~uVar20 + 1;
      }
    }
    if (((byte)(uVar17 >> 1) & 1) == 1) {
      if ((int)uVar6 < -0x8000) {
        uVar6 = 0xffff8000;
        uVar20 = 0;
      }
      if (0x7fff < (int)uVar6) {
        uVar6 = 0x7fff;
        uVar20 = 0xffffffff;
      }
      uVar6 = uVar6 & 0xffff;
    }
    uVar3 = puVar11[1];
    uVar19 = puVar14[-5];
    uVar1 = uVar3 ^ uVar19;
    if ((int)uVar3 < 0) {
      uVar3 = -uVar3;
    }
    if ((int)uVar19 < 0) {
      uVar19 = -uVar19;
    }
    uVar22 = (uVar19 & 0xffff) * (uVar3 & 0xffff);
    iVar12 = (uVar19 >> 0x10) * (uVar3 & 0xffff);
    iVar7 = 0;
    uVar2 = iVar12 + (uVar19 & 0xffff) * (uVar3 >> 0x10);
    if (iVar12 != 0) {
      iVar7 = 0x10000;
    }
    uVar21 = uVar22 + uVar2 * 0x10000;
    uVar19 = iVar7 + (uint)(uVar21 < uVar22) + (uVar2 >> 0x10) + (uVar19 >> 0x10) * (uVar3 >> 0x10);
    if ((int)-(uint)((int)uVar1 < 0) < 0) {
      uVar19 = ~uVar19;
      if (uVar21 == 0) {
        uVar19 = uVar19 + 1;
      }
      else {
        uVar21 = ~uVar21 + 1;
      }
    }
    if (((byte)(uVar17 >> 1) & 1) == 1) {
      uVar21 = uVar20 + uVar21;
      uVar6 = uVar19 + (uVar21 < uVar20) + (uVar6 & 0xffff);
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
    else {
      uVar21 = uVar20 + uVar21;
      uVar6 = uVar19 + (uVar21 < uVar20) + uVar6;
    }
    uVar3 = puVar11[2];
    uVar19 = puVar14[-4];
    uVar1 = uVar3 ^ uVar19;
    if ((int)uVar3 < 0) {
      uVar3 = -uVar3;
    }
    if ((int)uVar19 < 0) {
      uVar19 = -uVar19;
    }
    uVar20 = (uVar19 & 0xffff) * (uVar3 & 0xffff);
    iVar12 = (uVar19 >> 0x10) * (uVar3 & 0xffff);
    iVar7 = 0;
    uVar2 = iVar12 + (uVar19 & 0xffff) * (uVar3 >> 0x10);
    if (iVar12 != 0) {
      iVar7 = 0x10000;
    }
    uVar22 = uVar20 + uVar2 * 0x10000;
    uVar19 = iVar7 + (uint)(uVar22 < uVar20) + (uVar2 >> 0x10) + (uVar19 >> 0x10) * (uVar3 >> 0x10);
    if ((int)-(uint)((int)uVar1 < 0) < 0) {
      uVar19 = ~uVar19;
      if (uVar22 == 0) {
        uVar19 = uVar19 + 1;
      }
      else {
        uVar22 = ~uVar22 + 1;
      }
    }
    if (((byte)(uVar17 >> 1) & 1) == 1) {
      uVar22 = uVar21 + uVar22;
      uVar6 = uVar19 + (uVar22 < uVar21) + (uVar6 & 0xffff);
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
      uVar6 = uVar19 + (uVar22 < uVar21) + uVar6;
    }
    uVar3 = puVar11[3];
    uVar19 = *unaff_r8;
    uVar1 = uVar3 ^ uVar19;
    if ((int)uVar3 < 0) {
      uVar3 = -uVar3;
    }
    if ((int)uVar19 < 0) {
      uVar19 = -uVar19;
    }
    uVar20 = (uVar19 & 0xffff) * (uVar3 & 0xffff);
    iVar12 = (uVar19 >> 0x10) * (uVar3 & 0xffff);
    iVar7 = 0;
    uVar2 = iVar12 + (uVar19 & 0xffff) * (uVar3 >> 0x10);
    if (iVar12 != 0) {
      iVar7 = 0x10000;
    }
    uVar21 = uVar20 + uVar2 * 0x10000;
    uVar19 = iVar7 + (uint)(uVar21 < uVar20) + (uVar2 >> 0x10) + (uVar19 >> 0x10) * (uVar3 >> 0x10);
    if ((int)-(uint)((int)uVar1 < 0) < 0) {
      uVar19 = ~uVar19;
      if (uVar21 == 0) {
        uVar19 = uVar19 + 1;
      }
      else {
        uVar21 = ~uVar21 + 1;
      }
    }
    if (((byte)(uVar17 >> 1) & 1) == 1) {
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
    *(uint *)PTR_DAT_0602a908 = uVar6 << 0x10 | uVar22 >> 0x10;
    uVar3 = puVar11[4];
    uVar6 = puVar14[-5];
    uVar1 = uVar3 ^ uVar6;
    if ((int)uVar3 < 0) {
      uVar3 = -uVar3;
    }
    if ((int)uVar6 < 0) {
      uVar6 = -uVar6;
    }
    uVar20 = (uVar6 & 0xffff) * (uVar3 & 0xffff);
    iVar12 = (uVar6 >> 0x10) * (uVar3 & 0xffff);
    iVar7 = 0;
    uVar2 = iVar12 + (uVar6 & 0xffff) * (uVar3 >> 0x10);
    if (iVar12 != 0) {
      iVar7 = 0x10000;
    }
    uVar22 = uVar20 + uVar2 * 0x10000;
    uVar6 = iVar7 + (uint)(uVar22 < uVar20) + (uVar2 >> 0x10) + (uVar6 >> 0x10) * (uVar3 >> 0x10);
    if ((int)-(uint)((int)uVar1 < 0) < 0) {
      uVar6 = ~uVar6;
      if (uVar22 == 0) {
        uVar6 = uVar6 + 1;
      }
      else {
        uVar22 = ~uVar22 + 1;
      }
    }
    if (((byte)(uVar17 >> 1) & 1) == 1) {
      uVar22 = uVar21 + uVar22;
      uVar19 = uVar6 + (uVar22 < uVar21) + (uVar19 & 0xffff);
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
      uVar22 = uVar21 + uVar22;
      uVar19 = uVar6 + (uVar22 < uVar21) + uVar19;
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
    uVar20 = (uVar6 & 0xffff) * (uVar3 & 0xffff);
    iVar12 = (uVar6 >> 0x10) * (uVar3 & 0xffff);
    iVar7 = 0;
    uVar2 = iVar12 + (uVar6 & 0xffff) * (uVar3 >> 0x10);
    if (iVar12 != 0) {
      iVar7 = 0x10000;
    }
    uVar21 = uVar20 + uVar2 * 0x10000;
    uVar6 = iVar7 + (uint)(uVar21 < uVar20) + (uVar2 >> 0x10) + (uVar6 >> 0x10) * (uVar3 >> 0x10);
    if ((int)-(uint)((int)uVar1 < 0) < 0) {
      uVar6 = ~uVar6;
      if (uVar21 == 0) {
        uVar6 = uVar6 + 1;
      }
      else {
        uVar21 = ~uVar21 + 1;
      }
    }
    if (((byte)(uVar17 >> 1) & 1) == 1) {
      uVar21 = uVar22 + uVar21;
      uVar19 = uVar6 + (uVar21 < uVar22) + (uVar19 & 0xffff);
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
      uVar19 = uVar6 + (uVar21 < uVar22) + uVar19;
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
    uVar20 = (uVar6 & 0xffff) * (uVar3 & 0xffff);
    iVar12 = (uVar6 >> 0x10) * (uVar3 & 0xffff);
    iVar7 = 0;
    uVar2 = iVar12 + (uVar6 & 0xffff) * (uVar3 >> 0x10);
    if (iVar12 != 0) {
      iVar7 = 0x10000;
    }
    uVar22 = uVar20 + uVar2 * 0x10000;
    uVar6 = iVar7 + (uint)(uVar22 < uVar20) + (uVar2 >> 0x10) + (uVar6 >> 0x10) * (uVar3 >> 0x10);
    if ((int)-(uint)((int)uVar1 < 0) < 0) {
      uVar6 = ~uVar6;
      if (uVar22 == 0) {
        uVar6 = uVar6 + 1;
      }
      else {
        uVar22 = ~uVar22 + 1;
      }
    }
    if (((byte)(uVar17 >> 1) & 1) == 1) {
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
    *(uint *)(puVar5 + 4) = uVar19 << 0x10 | uVar21 >> 0x10;
    uVar3 = puVar11[7];
    uVar19 = puVar14[-5];
    uVar1 = uVar3 ^ uVar19;
    if ((int)uVar3 < 0) {
      uVar3 = -uVar3;
    }
    if ((int)uVar19 < 0) {
      uVar19 = -uVar19;
    }
    uVar20 = (uVar19 & 0xffff) * (uVar3 & 0xffff);
    iVar12 = (uVar19 >> 0x10) * (uVar3 & 0xffff);
    iVar7 = 0;
    uVar2 = iVar12 + (uVar19 & 0xffff) * (uVar3 >> 0x10);
    if (iVar12 != 0) {
      iVar7 = 0x10000;
    }
    uVar21 = uVar20 + uVar2 * 0x10000;
    uVar19 = iVar7 + (uint)(uVar21 < uVar20) + (uVar2 >> 0x10) + (uVar19 >> 0x10) * (uVar3 >> 0x10);
    if ((int)-(uint)((int)uVar1 < 0) < 0) {
      uVar19 = ~uVar19;
      if (uVar21 == 0) {
        uVar19 = uVar19 + 1;
      }
      else {
        uVar21 = ~uVar21 + 1;
      }
    }
    if (((byte)(uVar17 >> 1) & 1) == 1) {
      uVar21 = uVar22 + uVar21;
      uVar6 = uVar19 + (uVar21 < uVar22) + (uVar6 & 0xffff);
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
    else {
      uVar21 = uVar22 + uVar21;
      uVar6 = uVar19 + (uVar21 < uVar22) + uVar6;
    }
    uVar3 = puVar11[8];
    uVar19 = puVar14[-4];
    param_1 = puVar14 + -3;
    uVar1 = uVar3 ^ uVar19;
    if ((int)uVar3 < 0) {
      uVar3 = -uVar3;
    }
    if ((int)uVar19 < 0) {
      uVar19 = -uVar19;
    }
    uVar20 = (uVar19 & 0xffff) * (uVar3 & 0xffff);
    iVar12 = (uVar19 >> 0x10) * (uVar3 & 0xffff);
    iVar7 = 0;
    uVar2 = iVar12 + (uVar19 & 0xffff) * (uVar3 >> 0x10);
    if (iVar12 != 0) {
      iVar7 = 0x10000;
    }
    uVar22 = uVar20 + uVar2 * 0x10000;
    uVar19 = iVar7 + (uint)(uVar22 < uVar20) + (uVar2 >> 0x10) + (uVar19 >> 0x10) * (uVar3 >> 0x10);
    if ((int)-(uint)((int)uVar1 < 0) < 0) {
      uVar19 = ~uVar19;
      if (uVar22 == 0) {
        uVar19 = uVar19 + 1;
      }
      else {
        uVar22 = ~uVar22 + 1;
      }
    }
    if (((byte)(uVar17 >> 1) & 1) == 1) {
      uVar22 = uVar21 + uVar22;
      uVar6 = uVar19 + (uVar22 < uVar21) + (uVar6 & 0xffff);
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
      uVar6 = uVar19 + (uVar22 < uVar21) + uVar6;
    }
    *(uint *)(puVar5 + 8) = uVar6 << 0x10 | uVar22 >> 0x10;
    uVar19 = *(uint *)puVar5;
    uVar6 = *puVar9;
    uVar3 = uVar19 ^ uVar6;
    if ((int)uVar19 < 0) {
      uVar19 = -uVar19;
    }
    if ((int)uVar6 < 0) {
      uVar6 = -uVar6;
    }
    uVar2 = (uVar6 & 0xffff) * (uVar19 & 0xffff);
    iVar12 = (uVar6 >> 0x10) * (uVar19 & 0xffff);
    iVar7 = 0;
    uVar1 = iVar12 + (uVar6 & 0xffff) * (uVar19 >> 0x10);
    if (iVar12 != 0) {
      iVar7 = 0x10000;
    }
    uVar20 = uVar2 + uVar1 * 0x10000;
    uVar6 = iVar7 + (uint)(uVar20 < uVar2) + (uVar1 >> 0x10) + (uVar6 >> 0x10) * (uVar19 >> 0x10);
    if ((int)-(uint)((int)uVar3 < 0) < 0) {
      uVar6 = ~uVar6;
      if (uVar20 == 0) {
        uVar6 = uVar6 + 1;
      }
      else {
        uVar20 = ~uVar20 + 1;
      }
    }
    if (((byte)(uVar17 >> 1) & 1) == 1) {
      if ((int)uVar6 < -0x8000) {
        uVar6 = 0xffff8000;
        uVar20 = 0;
      }
      if (0x7fff < (int)uVar6) {
        uVar6 = 0x7fff;
        uVar20 = 0xffffffff;
      }
      uVar6 = uVar6 & 0xffff;
    }
    uVar3 = *(uint *)(puVar5 + 4);
    uVar19 = puVar9[1];
    uVar1 = uVar3 ^ uVar19;
    if ((int)uVar3 < 0) {
      uVar3 = -uVar3;
    }
    if ((int)uVar19 < 0) {
      uVar19 = -uVar19;
    }
    uVar22 = (uVar19 & 0xffff) * (uVar3 & 0xffff);
    iVar12 = (uVar19 >> 0x10) * (uVar3 & 0xffff);
    iVar7 = 0;
    uVar2 = iVar12 + (uVar19 & 0xffff) * (uVar3 >> 0x10);
    if (iVar12 != 0) {
      iVar7 = 0x10000;
    }
    uVar21 = uVar22 + uVar2 * 0x10000;
    uVar19 = iVar7 + (uint)(uVar21 < uVar22) + (uVar2 >> 0x10) + (uVar19 >> 0x10) * (uVar3 >> 0x10);
    if ((int)-(uint)((int)uVar1 < 0) < 0) {
      uVar19 = ~uVar19;
      if (uVar21 == 0) {
        uVar19 = uVar19 + 1;
      }
      else {
        uVar21 = ~uVar21 + 1;
      }
    }
    if (((byte)(uVar17 >> 1) & 1) == 1) {
      uVar21 = uVar20 + uVar21;
      uVar6 = uVar19 + (uVar21 < uVar20) + (uVar6 & 0xffff);
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
    else {
      uVar21 = uVar20 + uVar21;
      uVar6 = uVar19 + (uVar21 < uVar20) + uVar6;
    }
    uVar3 = *(uint *)(puVar5 + 8);
    uVar19 = puVar9[2];
    uVar1 = uVar3 ^ uVar19;
    if ((int)uVar3 < 0) {
      uVar3 = -uVar3;
    }
    if ((int)uVar19 < 0) {
      uVar19 = -uVar19;
    }
    uVar20 = (uVar19 & 0xffff) * (uVar3 & 0xffff);
    iVar12 = (uVar19 >> 0x10) * (uVar3 & 0xffff);
    iVar7 = 0;
    uVar2 = iVar12 + (uVar19 & 0xffff) * (uVar3 >> 0x10);
    if (iVar12 != 0) {
      iVar7 = 0x10000;
    }
    uVar22 = uVar20 + uVar2 * 0x10000;
    uVar19 = iVar7 + (uint)(uVar22 < uVar20) + (uVar2 >> 0x10) + (uVar19 >> 0x10) * (uVar3 >> 0x10);
    if ((int)-(uint)((int)uVar1 < 0) < 0) {
      uVar19 = ~uVar19;
      if (uVar22 == 0) {
        uVar19 = uVar19 + 1;
      }
      else {
        uVar22 = ~uVar22 + 1;
      }
    }
    if (((byte)(uVar17 >> 1) & 1) == 1) {
      uVar22 = uVar21 + uVar22;
      uVar6 = uVar19 + (uVar22 < uVar21) + (uVar6 & 0xffff);
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
      uVar6 = uVar19 + (uVar22 < uVar21) + uVar6;
    }
    uVar6 = uVar6 << 0x10 | uVar22 >> 0x10;
    uVar18 = uVar18 | 0 < (int)uVar6;
    if (((byte)uVar18 & 1) != 1) goto LAB_0602aa74;
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
  puVar5 = PTR_DAT_0602a994;
  uVar17 = *(uint *)PTR_DAT_0602a990 & 0xffff;
  iVar15 = (int)DAT_0602a97e;
  uVar6 = *(uint *)(puVar4 + -0x20);
  iVar7 = *(int *)(puVar4 + -0x18);
  param_1 = *(uint **)(puVar4 + -0x10);
  iVar12 = *(int *)(puVar4 + -8);
  uVar18 = uVar18 & 0xfffffffe;
  if ((((iVar15 <= (int)uVar6) || (iVar15 <= iVar7)) || (iVar15 <= (int)param_1)) ||
     (iVar15 <= iVar12)) {
    iVar15 = (int)DAT_0602aa12;
    uVar19 = uVar18 | (int)uVar6 < iVar15;
    if (((((byte)uVar19 & 1) == 1) || (uVar19 = uVar18 | iVar7 < iVar15, ((byte)uVar19 & 1) == 1))
       || ((uVar19 = uVar18 | (int)param_1 < iVar15, ((byte)uVar19 & 1) == 1 ||
           (uVar18 = uVar18 | iVar12 < iVar15, uVar19 = uVar18, ((byte)uVar18 & 1) != 1)))) {
      iVar16 = (int)DAT_0602aa14;
      iVar15 = *(int *)(puVar4 + -0x1c);
      iVar8 = *(int *)(puVar4 + -0x14);
      iVar10 = *(int *)(puVar4 + -0xc);
      iVar13 = *(int *)(puVar4 + -4);
      uVar18 = uVar19 & 0xfffffffe;
      if (((iVar16 <= iVar15) || (iVar16 <= iVar8)) ||
         ((iVar16 <= iVar10 || (uVar18 = uVar18 | iVar13 < iVar16, ((byte)uVar18 & 1) != 1)))) {
        iVar16 = (int)DAT_0602aa16;
        uVar18 = uVar18 & 0xfffffffe;
        if ((((iVar15 < iVar16) || (iVar8 < iVar16)) || (iVar10 < iVar16)) || (iVar13 < iVar16)) {
          *(short *)(PTR_DAT_0602a994 + uVar17 * 0x18 + 0x16) = (short)iVar13;
          *(short *)(puVar5 + uVar17 * 0x18 + 0x14) = (short)iVar12;
          *(short *)(puVar5 + uVar17 * 0x18 + 0x12) = (short)iVar10;
          *(short *)(puVar5 + uVar17 * 0x18 + 0x10) = (short)param_1;
          *(short *)(puVar5 + uVar17 * 0x18 + 0xe) = (short)iVar8;
          *(short *)(puVar5 + uVar17 * 0x18 + 0xc) = (short)iVar7;
          *(short *)(puVar5 + uVar17 * 0x18 + 10) = (short)iVar15;
          *(short *)(puVar5 + uVar17 * 0x18 + 8) = (short)uVar6;
          *(undefined2 *)(puVar5 + uVar17 * 0x18 + 6) = *(undefined2 *)((int)puVar14 + -10);
          puVar5[uVar17 * 0x18 + 4] = (byte)((uint)(int)*(short *)(puVar14 + -3) >> 4) & 0xf;
          puVar5[uVar17 * 0x18 + 5] = unaff_r13;
                    /* WARNING: Could not recover jumptable at 0x0602aa0e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          uVar18 = (**(code **)(PTR_LAB_0602aa18 + ((int)*(short *)(puVar14 + -3) & 7U) * 4))
                             (DAT_0602ab8c,DAT_0602ab90,DAT_0602ab94);
          return uVar18;
        }
      }
    }
  }
  goto LAB_0602aa74;
}

