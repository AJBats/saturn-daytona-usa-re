/* FUN_0602A840  0x0602A840 */


uint FUN_0602a840(int param_1,undefined4 param_2,undefined1 param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined *puVar4;
  undefined *puVar5;
  uint uVar6;
  uint extraout_r1;
  uint extraout_r2;
  uint extraout_r3;
  uint extraout_r3_00;
  uint extraout_r3_01;
  uint extraout_r3_02;
  uint extraout_r3_03;
  int iVar7;
  int iVar8;
  uint *puVar9;
  uint *puVar10;
  int iVar11;
  uint *puVar12;
  int iVar13;
  int iVar14;
  uint *puVar15;
  uint *puVar16;
  undefined4 *puVar17;
  int iVar18;
  int iVar19;
  uint in_sr;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  
  iVar8 = 0x40;
  puVar17 = (undefined4 *)PTR_DAT_0602a880;
  do {
    *puVar17 = 0xffffffff;
    iVar8 = iVar8 + -1;
    in_sr = in_sr & 0xfffffffe;
    puVar17 = puVar17 + 4;
  } while (iVar8 != 0);
  puVar9 = (uint *)0x0;
  puVar15 = (uint *)(param_1 + param_4 * 0x18);
  do {
    puVar4 = PTR_DAT_0602a8fc;
    puVar16 = puVar15 + -6;
    uVar21 = in_sr & 0xfffffffe;
    uVar20 = uVar21 | *(short *)PTR_DAT_0602a888 == 0;
    if ((((byte)uVar20 & 1) == 1) ||
       (uVar6 = (uint)*(short *)((int)puVar15 + -10), uVar20 = uVar21,
       (int)PTR_DAT_0602a87c._0_2_ != uVar6)) {
      puVar12 = *(uint **)PTR_DAT_0602a904;
      puVar10 = (uint *)PTR_DAT_0602a900;
      FUN_0602aaa0(puVar9);
      *puVar10 = extraout_r1;
      puVar10[1] = extraout_r2;
      puVar10[2] = extraout_r3;
      puVar5 = PTR_DAT_0602a908;
      uVar21 = uVar20 & 0xfffffffe;
      if ((puVar15[-3] & 0x80000) == 0) {
        uVar22 = *puVar12;
        uVar6 = *puVar16;
        uVar3 = uVar22 ^ uVar6;
        if ((int)uVar22 < 0) {
          uVar22 = -uVar22;
        }
        if ((int)uVar6 < 0) {
          uVar6 = -uVar6;
        }
        uVar2 = (uVar6 & 0xffff) * (uVar22 & 0xffff);
        iVar13 = (uVar6 >> 0x10) * (uVar22 & 0xffff);
        iVar8 = 0;
        uVar1 = iVar13 + (uVar6 & 0xffff) * (uVar22 >> 0x10);
        if (iVar13 != 0) {
          iVar8 = 0x10000;
        }
        uVar23 = uVar2 + uVar1 * 0x10000;
        uVar6 = iVar8 + (uint)(uVar23 < uVar2) + (uVar1 >> 0x10) +
                (uVar6 >> 0x10) * (uVar22 >> 0x10);
        if ((int)-(uint)((int)uVar3 < 0) < 0) {
          uVar6 = ~uVar6;
          if (uVar23 == 0) {
            uVar6 = uVar6 + 1;
          }
          else {
            uVar23 = ~uVar23 + 1;
          }
        }
        if (((byte)(uVar20 >> 1) & 1) == 1) {
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
        uVar3 = puVar12[1];
        uVar22 = puVar15[-5];
        uVar1 = uVar3 ^ uVar22;
        if ((int)uVar3 < 0) {
          uVar3 = -uVar3;
        }
        if ((int)uVar22 < 0) {
          uVar22 = -uVar22;
        }
        uVar25 = (uVar22 & 0xffff) * (uVar3 & 0xffff);
        iVar13 = (uVar22 >> 0x10) * (uVar3 & 0xffff);
        iVar8 = 0;
        uVar2 = iVar13 + (uVar22 & 0xffff) * (uVar3 >> 0x10);
        if (iVar13 != 0) {
          iVar8 = 0x10000;
        }
        uVar24 = uVar25 + uVar2 * 0x10000;
        uVar22 = iVar8 + (uint)(uVar24 < uVar25) + (uVar2 >> 0x10) +
                 (uVar22 >> 0x10) * (uVar3 >> 0x10);
        if ((int)-(uint)((int)uVar1 < 0) < 0) {
          uVar22 = ~uVar22;
          if (uVar24 == 0) {
            uVar22 = uVar22 + 1;
          }
          else {
            uVar24 = ~uVar24 + 1;
          }
        }
        if (((byte)(uVar20 >> 1) & 1) == 1) {
          uVar24 = uVar23 + uVar24;
          uVar6 = uVar22 + (uVar24 < uVar23) + (uVar6 & 0xffff);
          if ((int)uVar6 < -0x8000) {
            uVar6 = 0xffff8000;
            uVar24 = 0;
          }
          if (0x7fff < (int)uVar6) {
            uVar6 = 0x7fff;
            uVar24 = 0xffffffff;
          }
          uVar6 = uVar6 & 0xffff;
        }
        else {
          uVar24 = uVar23 + uVar24;
          uVar6 = uVar22 + (uVar24 < uVar23) + uVar6;
        }
        uVar3 = puVar12[2];
        uVar22 = puVar15[-4];
        uVar1 = uVar3 ^ uVar22;
        if ((int)uVar3 < 0) {
          uVar3 = -uVar3;
        }
        if ((int)uVar22 < 0) {
          uVar22 = -uVar22;
        }
        uVar23 = (uVar22 & 0xffff) * (uVar3 & 0xffff);
        iVar13 = (uVar22 >> 0x10) * (uVar3 & 0xffff);
        iVar8 = 0;
        uVar2 = iVar13 + (uVar22 & 0xffff) * (uVar3 >> 0x10);
        if (iVar13 != 0) {
          iVar8 = 0x10000;
        }
        uVar25 = uVar23 + uVar2 * 0x10000;
        uVar22 = iVar8 + (uint)(uVar25 < uVar23) + (uVar2 >> 0x10) +
                 (uVar22 >> 0x10) * (uVar3 >> 0x10);
        if ((int)-(uint)((int)uVar1 < 0) < 0) {
          uVar22 = ~uVar22;
          if (uVar25 == 0) {
            uVar22 = uVar22 + 1;
          }
          else {
            uVar25 = ~uVar25 + 1;
          }
        }
        if (((byte)(uVar20 >> 1) & 1) == 1) {
          uVar25 = uVar24 + uVar25;
          uVar6 = uVar22 + (uVar25 < uVar24) + (uVar6 & 0xffff);
          if ((int)uVar6 < -0x8000) {
            uVar6 = 0xffff8000;
            uVar25 = 0;
          }
          if (0x7fff < (int)uVar6) {
            uVar6 = 0x7fff;
            uVar25 = 0xffffffff;
          }
          uVar6 = uVar6 & 0xffff;
        }
        else {
          uVar25 = uVar24 + uVar25;
          uVar6 = uVar22 + (uVar25 < uVar24) + uVar6;
        }
        uVar3 = puVar12[3];
        uVar22 = *puVar16;
        uVar1 = uVar3 ^ uVar22;
        if ((int)uVar3 < 0) {
          uVar3 = -uVar3;
        }
        if ((int)uVar22 < 0) {
          uVar22 = -uVar22;
        }
        uVar23 = (uVar22 & 0xffff) * (uVar3 & 0xffff);
        iVar13 = (uVar22 >> 0x10) * (uVar3 & 0xffff);
        iVar8 = 0;
        uVar2 = iVar13 + (uVar22 & 0xffff) * (uVar3 >> 0x10);
        if (iVar13 != 0) {
          iVar8 = 0x10000;
        }
        uVar24 = uVar23 + uVar2 * 0x10000;
        uVar22 = iVar8 + (uint)(uVar24 < uVar23) + (uVar2 >> 0x10) +
                 (uVar22 >> 0x10) * (uVar3 >> 0x10);
        if ((int)-(uint)((int)uVar1 < 0) < 0) {
          uVar22 = ~uVar22;
          if (uVar24 == 0) {
            uVar22 = uVar22 + 1;
          }
          else {
            uVar24 = ~uVar24 + 1;
          }
        }
        if (((byte)(uVar20 >> 1) & 1) == 1) {
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
        *(uint *)PTR_DAT_0602a908 = uVar6 << 0x10 | uVar25 >> 0x10;
        uVar3 = puVar12[4];
        uVar6 = puVar15[-5];
        uVar1 = uVar3 ^ uVar6;
        if ((int)uVar3 < 0) {
          uVar3 = -uVar3;
        }
        if ((int)uVar6 < 0) {
          uVar6 = -uVar6;
        }
        uVar23 = (uVar6 & 0xffff) * (uVar3 & 0xffff);
        iVar13 = (uVar6 >> 0x10) * (uVar3 & 0xffff);
        iVar8 = 0;
        uVar2 = iVar13 + (uVar6 & 0xffff) * (uVar3 >> 0x10);
        if (iVar13 != 0) {
          iVar8 = 0x10000;
        }
        uVar25 = uVar23 + uVar2 * 0x10000;
        uVar6 = iVar8 + (uint)(uVar25 < uVar23) + (uVar2 >> 0x10) +
                (uVar6 >> 0x10) * (uVar3 >> 0x10);
        if ((int)-(uint)((int)uVar1 < 0) < 0) {
          uVar6 = ~uVar6;
          if (uVar25 == 0) {
            uVar6 = uVar6 + 1;
          }
          else {
            uVar25 = ~uVar25 + 1;
          }
        }
        if (((byte)(uVar20 >> 1) & 1) == 1) {
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
        uVar3 = puVar12[5];
        uVar6 = puVar15[-4];
        uVar1 = uVar3 ^ uVar6;
        if ((int)uVar3 < 0) {
          uVar3 = -uVar3;
        }
        if ((int)uVar6 < 0) {
          uVar6 = -uVar6;
        }
        uVar23 = (uVar6 & 0xffff) * (uVar3 & 0xffff);
        iVar13 = (uVar6 >> 0x10) * (uVar3 & 0xffff);
        iVar8 = 0;
        uVar2 = iVar13 + (uVar6 & 0xffff) * (uVar3 >> 0x10);
        if (iVar13 != 0) {
          iVar8 = 0x10000;
        }
        uVar24 = uVar23 + uVar2 * 0x10000;
        uVar6 = iVar8 + (uint)(uVar24 < uVar23) + (uVar2 >> 0x10) +
                (uVar6 >> 0x10) * (uVar3 >> 0x10);
        if ((int)-(uint)((int)uVar1 < 0) < 0) {
          uVar6 = ~uVar6;
          if (uVar24 == 0) {
            uVar6 = uVar6 + 1;
          }
          else {
            uVar24 = ~uVar24 + 1;
          }
        }
        if (((byte)(uVar20 >> 1) & 1) == 1) {
          uVar24 = uVar25 + uVar24;
          uVar22 = uVar6 + (uVar24 < uVar25) + (uVar22 & 0xffff);
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
          uVar24 = uVar25 + uVar24;
          uVar22 = uVar6 + (uVar24 < uVar25) + uVar22;
        }
        uVar3 = puVar12[6];
        uVar6 = *puVar16;
        uVar1 = uVar3 ^ uVar6;
        if ((int)uVar3 < 0) {
          uVar3 = -uVar3;
        }
        if ((int)uVar6 < 0) {
          uVar6 = -uVar6;
        }
        uVar23 = (uVar6 & 0xffff) * (uVar3 & 0xffff);
        iVar13 = (uVar6 >> 0x10) * (uVar3 & 0xffff);
        iVar8 = 0;
        uVar2 = iVar13 + (uVar6 & 0xffff) * (uVar3 >> 0x10);
        if (iVar13 != 0) {
          iVar8 = 0x10000;
        }
        uVar25 = uVar23 + uVar2 * 0x10000;
        uVar6 = iVar8 + (uint)(uVar25 < uVar23) + (uVar2 >> 0x10) +
                (uVar6 >> 0x10) * (uVar3 >> 0x10);
        if ((int)-(uint)((int)uVar1 < 0) < 0) {
          uVar6 = ~uVar6;
          if (uVar25 == 0) {
            uVar6 = uVar6 + 1;
          }
          else {
            uVar25 = ~uVar25 + 1;
          }
        }
        if (((byte)(uVar20 >> 1) & 1) == 1) {
          if ((int)uVar6 < -0x8000) {
            uVar6 = 0xffff8000;
            uVar25 = 0;
          }
          if (0x7fff < (int)uVar6) {
            uVar6 = 0x7fff;
            uVar25 = 0xffffffff;
          }
          uVar6 = uVar6 & 0xffff;
        }
        *(uint *)(puVar5 + 4) = uVar22 << 0x10 | uVar24 >> 0x10;
        uVar3 = puVar12[7];
        uVar22 = puVar15[-5];
        uVar1 = uVar3 ^ uVar22;
        if ((int)uVar3 < 0) {
          uVar3 = -uVar3;
        }
        if ((int)uVar22 < 0) {
          uVar22 = -uVar22;
        }
        uVar23 = (uVar22 & 0xffff) * (uVar3 & 0xffff);
        iVar13 = (uVar22 >> 0x10) * (uVar3 & 0xffff);
        iVar8 = 0;
        uVar2 = iVar13 + (uVar22 & 0xffff) * (uVar3 >> 0x10);
        if (iVar13 != 0) {
          iVar8 = 0x10000;
        }
        uVar24 = uVar23 + uVar2 * 0x10000;
        uVar22 = iVar8 + (uint)(uVar24 < uVar23) + (uVar2 >> 0x10) +
                 (uVar22 >> 0x10) * (uVar3 >> 0x10);
        if ((int)-(uint)((int)uVar1 < 0) < 0) {
          uVar22 = ~uVar22;
          if (uVar24 == 0) {
            uVar22 = uVar22 + 1;
          }
          else {
            uVar24 = ~uVar24 + 1;
          }
        }
        if (((byte)(uVar20 >> 1) & 1) == 1) {
          uVar24 = uVar25 + uVar24;
          uVar6 = uVar22 + (uVar24 < uVar25) + (uVar6 & 0xffff);
          if ((int)uVar6 < -0x8000) {
            uVar6 = 0xffff8000;
            uVar24 = 0;
          }
          if (0x7fff < (int)uVar6) {
            uVar6 = 0x7fff;
            uVar24 = 0xffffffff;
          }
          uVar6 = uVar6 & 0xffff;
        }
        else {
          uVar24 = uVar25 + uVar24;
          uVar6 = uVar22 + (uVar24 < uVar25) + uVar6;
        }
        uVar3 = puVar12[8];
        uVar22 = puVar15[-4];
        puVar9 = puVar15 + -3;
        uVar1 = uVar3 ^ uVar22;
        if ((int)uVar3 < 0) {
          uVar3 = -uVar3;
        }
        if ((int)uVar22 < 0) {
          uVar22 = -uVar22;
        }
        uVar23 = (uVar22 & 0xffff) * (uVar3 & 0xffff);
        iVar13 = (uVar22 >> 0x10) * (uVar3 & 0xffff);
        iVar8 = 0;
        uVar2 = iVar13 + (uVar22 & 0xffff) * (uVar3 >> 0x10);
        if (iVar13 != 0) {
          iVar8 = 0x10000;
        }
        uVar25 = uVar23 + uVar2 * 0x10000;
        uVar22 = iVar8 + (uint)(uVar25 < uVar23) + (uVar2 >> 0x10) +
                 (uVar22 >> 0x10) * (uVar3 >> 0x10);
        if ((int)-(uint)((int)uVar1 < 0) < 0) {
          uVar22 = ~uVar22;
          if (uVar25 == 0) {
            uVar22 = uVar22 + 1;
          }
          else {
            uVar25 = ~uVar25 + 1;
          }
        }
        if (((byte)(uVar20 >> 1) & 1) == 1) {
          uVar25 = uVar24 + uVar25;
          uVar6 = uVar22 + (uVar25 < uVar24) + (uVar6 & 0xffff);
          if ((int)uVar6 < -0x8000) {
            uVar6 = 0xffff8000;
            uVar25 = 0;
          }
          if (0x7fff < (int)uVar6) {
            uVar6 = 0x7fff;
            uVar25 = 0xffffffff;
          }
          uVar6 = uVar6 & 0xffff;
        }
        else {
          uVar25 = uVar24 + uVar25;
          uVar6 = uVar22 + (uVar25 < uVar24) + uVar6;
        }
        *(uint *)(puVar5 + 8) = uVar6 << 0x10 | uVar25 >> 0x10;
        uVar22 = *(uint *)puVar5;
        uVar6 = *puVar10;
        uVar3 = uVar22 ^ uVar6;
        if ((int)uVar22 < 0) {
          uVar22 = -uVar22;
        }
        if ((int)uVar6 < 0) {
          uVar6 = -uVar6;
        }
        uVar2 = (uVar6 & 0xffff) * (uVar22 & 0xffff);
        iVar13 = (uVar6 >> 0x10) * (uVar22 & 0xffff);
        iVar8 = 0;
        uVar1 = iVar13 + (uVar6 & 0xffff) * (uVar22 >> 0x10);
        if (iVar13 != 0) {
          iVar8 = 0x10000;
        }
        uVar23 = uVar2 + uVar1 * 0x10000;
        uVar6 = iVar8 + (uint)(uVar23 < uVar2) + (uVar1 >> 0x10) +
                (uVar6 >> 0x10) * (uVar22 >> 0x10);
        if ((int)-(uint)((int)uVar3 < 0) < 0) {
          uVar6 = ~uVar6;
          if (uVar23 == 0) {
            uVar6 = uVar6 + 1;
          }
          else {
            uVar23 = ~uVar23 + 1;
          }
        }
        if (((byte)(uVar20 >> 1) & 1) == 1) {
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
        uVar3 = *(uint *)(puVar5 + 4);
        uVar22 = puVar10[1];
        uVar1 = uVar3 ^ uVar22;
        if ((int)uVar3 < 0) {
          uVar3 = -uVar3;
        }
        if ((int)uVar22 < 0) {
          uVar22 = -uVar22;
        }
        uVar25 = (uVar22 & 0xffff) * (uVar3 & 0xffff);
        iVar13 = (uVar22 >> 0x10) * (uVar3 & 0xffff);
        iVar8 = 0;
        uVar2 = iVar13 + (uVar22 & 0xffff) * (uVar3 >> 0x10);
        if (iVar13 != 0) {
          iVar8 = 0x10000;
        }
        uVar24 = uVar25 + uVar2 * 0x10000;
        uVar22 = iVar8 + (uint)(uVar24 < uVar25) + (uVar2 >> 0x10) +
                 (uVar22 >> 0x10) * (uVar3 >> 0x10);
        if ((int)-(uint)((int)uVar1 < 0) < 0) {
          uVar22 = ~uVar22;
          if (uVar24 == 0) {
            uVar22 = uVar22 + 1;
          }
          else {
            uVar24 = ~uVar24 + 1;
          }
        }
        if (((byte)(uVar20 >> 1) & 1) == 1) {
          uVar24 = uVar23 + uVar24;
          uVar6 = uVar22 + (uVar24 < uVar23) + (uVar6 & 0xffff);
          if ((int)uVar6 < -0x8000) {
            uVar6 = 0xffff8000;
            uVar24 = 0;
          }
          if (0x7fff < (int)uVar6) {
            uVar6 = 0x7fff;
            uVar24 = 0xffffffff;
          }
          uVar6 = uVar6 & 0xffff;
        }
        else {
          uVar24 = uVar23 + uVar24;
          uVar6 = uVar22 + (uVar24 < uVar23) + uVar6;
        }
        uVar3 = *(uint *)(puVar5 + 8);
        uVar22 = puVar10[2];
        uVar1 = uVar3 ^ uVar22;
        if ((int)uVar3 < 0) {
          uVar3 = -uVar3;
        }
        if ((int)uVar22 < 0) {
          uVar22 = -uVar22;
        }
        uVar23 = (uVar22 & 0xffff) * (uVar3 & 0xffff);
        iVar13 = (uVar22 >> 0x10) * (uVar3 & 0xffff);
        iVar8 = 0;
        uVar2 = iVar13 + (uVar22 & 0xffff) * (uVar3 >> 0x10);
        if (iVar13 != 0) {
          iVar8 = 0x10000;
        }
        uVar25 = uVar23 + uVar2 * 0x10000;
        uVar22 = iVar8 + (uint)(uVar25 < uVar23) + (uVar2 >> 0x10) +
                 (uVar22 >> 0x10) * (uVar3 >> 0x10);
        if ((int)-(uint)((int)uVar1 < 0) < 0) {
          uVar22 = ~uVar22;
          if (uVar25 == 0) {
            uVar22 = uVar22 + 1;
          }
          else {
            uVar25 = ~uVar25 + 1;
          }
        }
        if (((byte)(uVar20 >> 1) & 1) == 1) {
          uVar25 = uVar24 + uVar25;
          uVar6 = uVar22 + (uVar25 < uVar24) + (uVar6 & 0xffff);
          if ((int)uVar6 < -0x8000) {
            uVar6 = 0xffff8000;
            uVar25 = 0;
          }
          if (0x7fff < (int)uVar6) {
            uVar6 = 0x7fff;
            uVar25 = 0xffffffff;
          }
          uVar6 = uVar6 & 0xffff;
        }
        else {
          uVar25 = uVar24 + uVar25;
          uVar6 = uVar22 + (uVar25 < uVar24) + uVar6;
        }
        uVar6 = uVar6 << 0x10 | uVar25 >> 0x10;
        uVar21 = uVar21 | 0 < (int)uVar6;
        if (((byte)uVar21 & 1) != 1) goto LAB_0602aa74;
      }
      FUN_0602ab3a();
      *puVar10 = extraout_r3_00;
      puVar10 = puVar10 + 1;
      FUN_0602ab00();
      FUN_0602ab3a();
      FUN_0602aaa0();
      *puVar10 = extraout_r3_01;
      puVar10 = puVar10 + 1;
      FUN_0602ab00();
      FUN_0602ab3a();
      FUN_0602aaa0();
      *puVar10 = extraout_r3_02;
      puVar10 = puVar10 + 1;
      FUN_0602ab00();
      FUN_0602ab3a();
      FUN_0602aaa0();
      *puVar10 = extraout_r3_03;
      FUN_0602ab00();
      puVar5 = PTR_DAT_0602a994;
      uVar20 = *(uint *)PTR_DAT_0602a990 & 0xffff;
      iVar18 = (int)DAT_0602a97e;
      uVar6 = *(uint *)(puVar4 + -0x20);
      iVar8 = *(int *)(puVar4 + -0x18);
      puVar9 = *(uint **)(puVar4 + -0x10);
      iVar13 = *(int *)(puVar4 + -8);
      uVar21 = uVar21 & 0xfffffffe;
      if ((((iVar18 <= (int)uVar6) || (iVar18 <= iVar8)) || (iVar18 <= (int)puVar9)) ||
         (iVar18 <= iVar13)) {
        iVar18 = (int)DAT_0602aa12;
        uVar22 = uVar21 | (int)uVar6 < iVar18;
        if (((((byte)uVar22 & 1) == 1) ||
            (uVar22 = uVar21 | iVar8 < iVar18, ((byte)uVar22 & 1) == 1)) ||
           ((uVar22 = uVar21 | (int)puVar9 < iVar18, ((byte)uVar22 & 1) == 1 ||
            (uVar21 = uVar21 | iVar13 < iVar18, uVar22 = uVar21, ((byte)uVar21 & 1) != 1)))) {
          iVar19 = (int)DAT_0602aa14;
          iVar18 = *(int *)(puVar4 + -0x1c);
          iVar7 = *(int *)(puVar4 + -0x14);
          iVar11 = *(int *)(puVar4 + -0xc);
          iVar14 = *(int *)(puVar4 + -4);
          uVar21 = uVar22 & 0xfffffffe;
          if (((iVar19 <= iVar18) || (iVar19 <= iVar7)) ||
             ((iVar19 <= iVar11 || (uVar21 = uVar21 | iVar14 < iVar19, ((byte)uVar21 & 1) != 1)))) {
            iVar19 = (int)DAT_0602aa16;
            uVar21 = uVar21 & 0xfffffffe;
            if ((((iVar18 < iVar19) || (iVar7 < iVar19)) || (iVar11 < iVar19)) || (iVar14 < iVar19))
            {
              *(short *)(PTR_DAT_0602a994 + uVar20 * 0x18 + 0x16) = (short)iVar14;
              *(short *)(puVar5 + uVar20 * 0x18 + 0x14) = (short)iVar13;
              *(short *)(puVar5 + uVar20 * 0x18 + 0x12) = (short)iVar11;
              *(short *)(puVar5 + uVar20 * 0x18 + 0x10) = (short)puVar9;
              *(short *)(puVar5 + uVar20 * 0x18 + 0xe) = (short)iVar7;
              *(short *)(puVar5 + uVar20 * 0x18 + 0xc) = (short)iVar8;
              *(short *)(puVar5 + uVar20 * 0x18 + 10) = (short)iVar18;
              *(short *)(puVar5 + uVar20 * 0x18 + 8) = (short)uVar6;
              *(undefined2 *)(puVar5 + uVar20 * 0x18 + 6) = *(undefined2 *)((int)puVar15 + -10);
              puVar5[uVar20 * 0x18 + 4] = (byte)((uint)(int)*(short *)(puVar15 + -3) >> 4) & 0xf;
              puVar5[uVar20 * 0x18 + 5] = param_3;
                    /* WARNING: Could not recover jumptable at 0x0602aa0e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
              uVar21 = (**(code **)(PTR_LAB_0602aa18 + ((int)*(short *)(puVar15 + -3) & 7U) * 4))
                                 (DAT_0602ab8c,DAT_0602ab90,DAT_0602ab94);
              return uVar21;
            }
          }
        }
      }
    }
LAB_0602aa74:
    param_4 = param_4 + -1;
    in_sr = uVar21 & 0xfffffffe | (uint)(param_4 == 0);
    puVar15 = puVar16;
    if (((byte)in_sr & 1) == 1) {
      return uVar6;
    }
  } while( true );
}

