/* FUN_06031E00  0x06031E00 */


uint FUN_06031e00(int param_1,undefined1 param_2,int param_3)

{
  uint uVar1;
  undefined *puVar2;
  undefined *puVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int extraout_r3;
  int extraout_r3_00;
  int extraout_r3_01;
  int iVar8;
  uint uVar9;
  int iVar10;
  undefined *puVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  int iVar14;
  int iVar15;
  uint *puVar16;
  int *piVar17;
  int iVar18;
  uint *puVar19;
  uint *puVar21;
  uint *puVar22;
  int iVar23;
  int iVar24;
  uint in_sr;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  uint uVar28;
  uint uVar29;
  uint *puVar20;
  
  puVar3 = PTR_DAT_06031e38;
  puVar2 = PTR_DAT_06031e34;
  puVar19 = (uint *)(param_1 + param_3 * 0x18);
  do {
    puVar20 = puVar19 + -6;
    uVar4 = (uint)(short)*(ushort *)(puVar19 + -2);
    puVar22 = (uint *)(int)DAT_06031e30;
    puVar16 = (uint *)(PTR_DAT_06031e3c + (uint)*(ushort *)(puVar19 + -2) * 0xc);
    uVar7 = puVar16[2];
    uVar26 = in_sr & 0xfffffffe;
    uVar25 = uVar26 | 0 < (int)uVar7;
    if (((byte)uVar25 & 1) == 1) {
      puVar22[4] = (int)PTR_DAT_06031ea8._0_2_;
      *puVar22 = uVar7;
      puVar22[5] = 0;
      *(uint *)puVar2 = uVar7;
      puVar11 = PTR_DAT_06031eac;
      if ((puVar19[-3] & 0x80000) == 0) {
        puVar21 = *(uint **)PTR_DAT_06031eb0;
        uVar4 = *puVar21;
        uVar25 = *puVar20;
        uVar7 = uVar4 ^ uVar25;
        if ((int)uVar4 < 0) {
          uVar4 = -uVar4;
        }
        if ((int)uVar25 < 0) {
          uVar25 = -uVar25;
        }
        uVar1 = (uVar25 & 0xffff) * (uVar4 & 0xffff);
        iVar6 = (uVar25 >> 0x10) * (uVar4 & 0xffff);
        iVar5 = 0;
        uVar9 = iVar6 + (uVar25 & 0xffff) * (uVar4 >> 0x10);
        if (iVar6 != 0) {
          iVar5 = 0x10000;
        }
        uVar27 = uVar1 + uVar9 * 0x10000;
        uVar25 = iVar5 + (uint)(uVar27 < uVar1) + (uVar9 >> 0x10) +
                 (uVar25 >> 0x10) * (uVar4 >> 0x10);
        if ((int)-(uint)((int)uVar7 < 0) < 0) {
          uVar25 = ~uVar25;
          if (uVar27 == 0) {
            uVar25 = uVar25 + 1;
          }
          else {
            uVar27 = ~uVar27 + 1;
          }
        }
        if (((byte)(in_sr >> 1) & 1) == 1) {
          if ((int)uVar25 < -0x8000) {
            uVar25 = 0xffff8000;
            uVar27 = 0;
          }
          if (0x7fff < (int)uVar25) {
            uVar25 = 0x7fff;
            uVar27 = 0xffffffff;
          }
          uVar25 = uVar25 & 0xffff;
        }
        uVar7 = puVar21[1];
        uVar4 = puVar19[-5];
        uVar9 = uVar7 ^ uVar4;
        if ((int)uVar7 < 0) {
          uVar7 = -uVar7;
        }
        if ((int)uVar4 < 0) {
          uVar4 = -uVar4;
        }
        uVar29 = (uVar4 & 0xffff) * (uVar7 & 0xffff);
        iVar6 = (uVar4 >> 0x10) * (uVar7 & 0xffff);
        iVar5 = 0;
        uVar1 = iVar6 + (uVar4 & 0xffff) * (uVar7 >> 0x10);
        if (iVar6 != 0) {
          iVar5 = 0x10000;
        }
        uVar28 = uVar29 + uVar1 * 0x10000;
        uVar4 = iVar5 + (uint)(uVar28 < uVar29) + (uVar1 >> 0x10) +
                (uVar4 >> 0x10) * (uVar7 >> 0x10);
        if ((int)-(uint)((int)uVar9 < 0) < 0) {
          uVar4 = ~uVar4;
          if (uVar28 == 0) {
            uVar4 = uVar4 + 1;
          }
          else {
            uVar28 = ~uVar28 + 1;
          }
        }
        if (((byte)(in_sr >> 1) & 1) == 1) {
          uVar28 = uVar27 + uVar28;
          uVar25 = uVar4 + (uVar28 < uVar27) + (uVar25 & 0xffff);
          if ((int)uVar25 < -0x8000) {
            uVar25 = 0xffff8000;
            uVar28 = 0;
          }
          if (0x7fff < (int)uVar25) {
            uVar25 = 0x7fff;
            uVar28 = 0xffffffff;
          }
          uVar25 = uVar25 & 0xffff;
        }
        else {
          uVar28 = uVar27 + uVar28;
          uVar25 = uVar4 + (uVar28 < uVar27) + uVar25;
        }
        uVar7 = puVar21[2];
        uVar4 = puVar19[-4];
        uVar9 = uVar7 ^ uVar4;
        if ((int)uVar7 < 0) {
          uVar7 = -uVar7;
        }
        if ((int)uVar4 < 0) {
          uVar4 = -uVar4;
        }
        uVar27 = (uVar4 & 0xffff) * (uVar7 & 0xffff);
        iVar6 = (uVar4 >> 0x10) * (uVar7 & 0xffff);
        iVar5 = 0;
        uVar1 = iVar6 + (uVar4 & 0xffff) * (uVar7 >> 0x10);
        if (iVar6 != 0) {
          iVar5 = 0x10000;
        }
        uVar29 = uVar27 + uVar1 * 0x10000;
        uVar4 = iVar5 + (uint)(uVar29 < uVar27) + (uVar1 >> 0x10) +
                (uVar4 >> 0x10) * (uVar7 >> 0x10);
        if ((int)-(uint)((int)uVar9 < 0) < 0) {
          uVar4 = ~uVar4;
          if (uVar29 == 0) {
            uVar4 = uVar4 + 1;
          }
          else {
            uVar29 = ~uVar29 + 1;
          }
        }
        if (((byte)(in_sr >> 1) & 1) == 1) {
          uVar29 = uVar28 + uVar29;
          uVar25 = uVar4 + (uVar29 < uVar28) + (uVar25 & 0xffff);
          if ((int)uVar25 < -0x8000) {
            uVar25 = 0xffff8000;
            uVar29 = 0;
          }
          if (0x7fff < (int)uVar25) {
            uVar25 = 0x7fff;
            uVar29 = 0xffffffff;
          }
          uVar25 = uVar25 & 0xffff;
        }
        else {
          uVar29 = uVar28 + uVar29;
          uVar25 = uVar4 + (uVar29 < uVar28) + uVar25;
        }
        uVar7 = puVar21[3];
        uVar4 = *puVar20;
        uVar9 = uVar7 ^ uVar4;
        if ((int)uVar7 < 0) {
          uVar7 = -uVar7;
        }
        if ((int)uVar4 < 0) {
          uVar4 = -uVar4;
        }
        uVar27 = (uVar4 & 0xffff) * (uVar7 & 0xffff);
        iVar6 = (uVar4 >> 0x10) * (uVar7 & 0xffff);
        iVar5 = 0;
        uVar1 = iVar6 + (uVar4 & 0xffff) * (uVar7 >> 0x10);
        if (iVar6 != 0) {
          iVar5 = 0x10000;
        }
        uVar28 = uVar27 + uVar1 * 0x10000;
        uVar4 = iVar5 + (uint)(uVar28 < uVar27) + (uVar1 >> 0x10) +
                (uVar4 >> 0x10) * (uVar7 >> 0x10);
        if ((int)-(uint)((int)uVar9 < 0) < 0) {
          uVar4 = ~uVar4;
          if (uVar28 == 0) {
            uVar4 = uVar4 + 1;
          }
          else {
            uVar28 = ~uVar28 + 1;
          }
        }
        if (((byte)(in_sr >> 1) & 1) == 1) {
          if ((int)uVar4 < -0x8000) {
            uVar4 = 0xffff8000;
            uVar28 = 0;
          }
          if (0x7fff < (int)uVar4) {
            uVar4 = 0x7fff;
            uVar28 = 0xffffffff;
          }
          uVar4 = uVar4 & 0xffff;
        }
        *(uint *)PTR_DAT_06031eac = uVar25 << 0x10 | uVar29 >> 0x10;
        uVar7 = puVar21[4];
        uVar25 = puVar19[-5];
        uVar9 = uVar7 ^ uVar25;
        if ((int)uVar7 < 0) {
          uVar7 = -uVar7;
        }
        if ((int)uVar25 < 0) {
          uVar25 = -uVar25;
        }
        uVar27 = (uVar25 & 0xffff) * (uVar7 & 0xffff);
        iVar6 = (uVar25 >> 0x10) * (uVar7 & 0xffff);
        iVar5 = 0;
        uVar1 = iVar6 + (uVar25 & 0xffff) * (uVar7 >> 0x10);
        if (iVar6 != 0) {
          iVar5 = 0x10000;
        }
        uVar29 = uVar27 + uVar1 * 0x10000;
        uVar25 = iVar5 + (uint)(uVar29 < uVar27) + (uVar1 >> 0x10) +
                 (uVar25 >> 0x10) * (uVar7 >> 0x10);
        if ((int)-(uint)((int)uVar9 < 0) < 0) {
          uVar25 = ~uVar25;
          if (uVar29 == 0) {
            uVar25 = uVar25 + 1;
          }
          else {
            uVar29 = ~uVar29 + 1;
          }
        }
        if (((byte)(in_sr >> 1) & 1) == 1) {
          uVar29 = uVar28 + uVar29;
          uVar4 = uVar25 + (uVar29 < uVar28) + (uVar4 & 0xffff);
          if ((int)uVar4 < -0x8000) {
            uVar4 = 0xffff8000;
            uVar29 = 0;
          }
          if (0x7fff < (int)uVar4) {
            uVar4 = 0x7fff;
            uVar29 = 0xffffffff;
          }
          uVar4 = uVar4 & 0xffff;
        }
        else {
          uVar29 = uVar28 + uVar29;
          uVar4 = uVar25 + (uVar29 < uVar28) + uVar4;
        }
        uVar7 = puVar21[5];
        uVar25 = puVar19[-4];
        uVar9 = uVar7 ^ uVar25;
        if ((int)uVar7 < 0) {
          uVar7 = -uVar7;
        }
        if ((int)uVar25 < 0) {
          uVar25 = -uVar25;
        }
        uVar27 = (uVar25 & 0xffff) * (uVar7 & 0xffff);
        iVar6 = (uVar25 >> 0x10) * (uVar7 & 0xffff);
        iVar5 = 0;
        uVar1 = iVar6 + (uVar25 & 0xffff) * (uVar7 >> 0x10);
        if (iVar6 != 0) {
          iVar5 = 0x10000;
        }
        uVar28 = uVar27 + uVar1 * 0x10000;
        uVar25 = iVar5 + (uint)(uVar28 < uVar27) + (uVar1 >> 0x10) +
                 (uVar25 >> 0x10) * (uVar7 >> 0x10);
        if ((int)-(uint)((int)uVar9 < 0) < 0) {
          uVar25 = ~uVar25;
          if (uVar28 == 0) {
            uVar25 = uVar25 + 1;
          }
          else {
            uVar28 = ~uVar28 + 1;
          }
        }
        if (((byte)(in_sr >> 1) & 1) == 1) {
          uVar28 = uVar29 + uVar28;
          uVar4 = uVar25 + (uVar28 < uVar29) + (uVar4 & 0xffff);
          if ((int)uVar4 < -0x8000) {
            uVar4 = 0xffff8000;
            uVar28 = 0;
          }
          if (0x7fff < (int)uVar4) {
            uVar4 = 0x7fff;
            uVar28 = 0xffffffff;
          }
          uVar4 = uVar4 & 0xffff;
        }
        else {
          uVar28 = uVar29 + uVar28;
          uVar4 = uVar25 + (uVar28 < uVar29) + uVar4;
        }
        uVar7 = puVar21[6];
        uVar25 = *puVar20;
        uVar9 = uVar7 ^ uVar25;
        if ((int)uVar7 < 0) {
          uVar7 = -uVar7;
        }
        if ((int)uVar25 < 0) {
          uVar25 = -uVar25;
        }
        uVar27 = (uVar25 & 0xffff) * (uVar7 & 0xffff);
        iVar6 = (uVar25 >> 0x10) * (uVar7 & 0xffff);
        iVar5 = 0;
        uVar1 = iVar6 + (uVar25 & 0xffff) * (uVar7 >> 0x10);
        if (iVar6 != 0) {
          iVar5 = 0x10000;
        }
        uVar29 = uVar27 + uVar1 * 0x10000;
        uVar25 = iVar5 + (uint)(uVar29 < uVar27) + (uVar1 >> 0x10) +
                 (uVar25 >> 0x10) * (uVar7 >> 0x10);
        if ((int)-(uint)((int)uVar9 < 0) < 0) {
          uVar25 = ~uVar25;
          if (uVar29 == 0) {
            uVar25 = uVar25 + 1;
          }
          else {
            uVar29 = ~uVar29 + 1;
          }
        }
        if (((byte)(in_sr >> 1) & 1) == 1) {
          if ((int)uVar25 < -0x8000) {
            uVar25 = 0xffff8000;
            uVar29 = 0;
          }
          if (0x7fff < (int)uVar25) {
            uVar25 = 0x7fff;
            uVar29 = 0xffffffff;
          }
          uVar25 = uVar25 & 0xffff;
        }
        *(uint *)(puVar11 + 4) = uVar4 << 0x10 | uVar28 >> 0x10;
        uVar7 = puVar21[7];
        uVar4 = puVar19[-5];
        uVar9 = uVar7 ^ uVar4;
        if ((int)uVar7 < 0) {
          uVar7 = -uVar7;
        }
        if ((int)uVar4 < 0) {
          uVar4 = -uVar4;
        }
        uVar27 = (uVar4 & 0xffff) * (uVar7 & 0xffff);
        iVar6 = (uVar4 >> 0x10) * (uVar7 & 0xffff);
        iVar5 = 0;
        uVar1 = iVar6 + (uVar4 & 0xffff) * (uVar7 >> 0x10);
        if (iVar6 != 0) {
          iVar5 = 0x10000;
        }
        uVar28 = uVar27 + uVar1 * 0x10000;
        uVar4 = iVar5 + (uint)(uVar28 < uVar27) + (uVar1 >> 0x10) +
                (uVar4 >> 0x10) * (uVar7 >> 0x10);
        if ((int)-(uint)((int)uVar9 < 0) < 0) {
          uVar4 = ~uVar4;
          if (uVar28 == 0) {
            uVar4 = uVar4 + 1;
          }
          else {
            uVar28 = ~uVar28 + 1;
          }
        }
        if (((byte)(in_sr >> 1) & 1) == 1) {
          uVar28 = uVar29 + uVar28;
          uVar25 = uVar4 + (uVar28 < uVar29) + (uVar25 & 0xffff);
          if ((int)uVar25 < -0x8000) {
            uVar25 = 0xffff8000;
            uVar28 = 0;
          }
          if (0x7fff < (int)uVar25) {
            uVar25 = 0x7fff;
            uVar28 = 0xffffffff;
          }
          uVar25 = uVar25 & 0xffff;
        }
        else {
          uVar28 = uVar29 + uVar28;
          uVar25 = uVar4 + (uVar28 < uVar29) + uVar25;
        }
        uVar7 = puVar21[8];
        uVar4 = puVar19[-4];
        uVar9 = uVar7 ^ uVar4;
        if ((int)uVar7 < 0) {
          uVar7 = -uVar7;
        }
        if ((int)uVar4 < 0) {
          uVar4 = -uVar4;
        }
        uVar27 = (uVar4 & 0xffff) * (uVar7 & 0xffff);
        iVar6 = (uVar4 >> 0x10) * (uVar7 & 0xffff);
        iVar5 = 0;
        uVar1 = iVar6 + (uVar4 & 0xffff) * (uVar7 >> 0x10);
        if (iVar6 != 0) {
          iVar5 = 0x10000;
        }
        uVar29 = uVar27 + uVar1 * 0x10000;
        uVar4 = iVar5 + (uint)(uVar29 < uVar27) + (uVar1 >> 0x10) +
                (uVar4 >> 0x10) * (uVar7 >> 0x10);
        if ((int)-(uint)((int)uVar9 < 0) < 0) {
          uVar4 = ~uVar4;
          if (uVar29 == 0) {
            uVar4 = uVar4 + 1;
          }
          else {
            uVar29 = ~uVar29 + 1;
          }
        }
        if (((byte)(in_sr >> 1) & 1) == 1) {
          uVar29 = uVar28 + uVar29;
          uVar25 = uVar4 + (uVar29 < uVar28) + (uVar25 & 0xffff);
          if ((int)uVar25 < -0x8000) {
            uVar25 = 0xffff8000;
            uVar29 = 0;
          }
          if (0x7fff < (int)uVar25) {
            uVar25 = 0x7fff;
            uVar29 = 0xffffffff;
          }
          uVar25 = uVar25 & 0xffff;
        }
        else {
          uVar29 = uVar28 + uVar29;
          uVar25 = uVar4 + (uVar29 < uVar28) + uVar25;
        }
        *(uint *)(puVar11 + 8) = uVar25 << 0x10 | uVar29 >> 0x10;
        uVar4 = *(uint *)puVar11;
        uVar25 = *puVar16;
        uVar7 = uVar4 ^ uVar25;
        if ((int)uVar4 < 0) {
          uVar4 = -uVar4;
        }
        if ((int)uVar25 < 0) {
          uVar25 = -uVar25;
        }
        uVar1 = (uVar25 & 0xffff) * (uVar4 & 0xffff);
        iVar6 = (uVar25 >> 0x10) * (uVar4 & 0xffff);
        iVar5 = 0;
        uVar9 = iVar6 + (uVar25 & 0xffff) * (uVar4 >> 0x10);
        if (iVar6 != 0) {
          iVar5 = 0x10000;
        }
        uVar27 = uVar1 + uVar9 * 0x10000;
        uVar25 = iVar5 + (uint)(uVar27 < uVar1) + (uVar9 >> 0x10) +
                 (uVar25 >> 0x10) * (uVar4 >> 0x10);
        if ((int)-(uint)((int)uVar7 < 0) < 0) {
          uVar25 = ~uVar25;
          if (uVar27 == 0) {
            uVar25 = uVar25 + 1;
          }
          else {
            uVar27 = ~uVar27 + 1;
          }
        }
        if (((byte)(in_sr >> 1) & 1) == 1) {
          if ((int)uVar25 < -0x8000) {
            uVar25 = 0xffff8000;
            uVar27 = 0;
          }
          if (0x7fff < (int)uVar25) {
            uVar25 = 0x7fff;
            uVar27 = 0xffffffff;
          }
          uVar25 = uVar25 & 0xffff;
        }
        uVar7 = *(uint *)(puVar11 + 4);
        uVar4 = puVar16[1];
        uVar9 = uVar7 ^ uVar4;
        if ((int)uVar7 < 0) {
          uVar7 = -uVar7;
        }
        if ((int)uVar4 < 0) {
          uVar4 = -uVar4;
        }
        uVar29 = (uVar4 & 0xffff) * (uVar7 & 0xffff);
        iVar6 = (uVar4 >> 0x10) * (uVar7 & 0xffff);
        iVar5 = 0;
        uVar1 = iVar6 + (uVar4 & 0xffff) * (uVar7 >> 0x10);
        if (iVar6 != 0) {
          iVar5 = 0x10000;
        }
        uVar28 = uVar29 + uVar1 * 0x10000;
        uVar4 = iVar5 + (uint)(uVar28 < uVar29) + (uVar1 >> 0x10) +
                (uVar4 >> 0x10) * (uVar7 >> 0x10);
        if ((int)-(uint)((int)uVar9 < 0) < 0) {
          uVar4 = ~uVar4;
          if (uVar28 == 0) {
            uVar4 = uVar4 + 1;
          }
          else {
            uVar28 = ~uVar28 + 1;
          }
        }
        if (((byte)(in_sr >> 1) & 1) == 1) {
          uVar28 = uVar27 + uVar28;
          uVar25 = uVar4 + (uVar28 < uVar27) + (uVar25 & 0xffff);
          if ((int)uVar25 < -0x8000) {
            uVar25 = 0xffff8000;
            uVar28 = 0;
          }
          if (0x7fff < (int)uVar25) {
            uVar25 = 0x7fff;
            uVar28 = 0xffffffff;
          }
          uVar25 = uVar25 & 0xffff;
        }
        else {
          uVar28 = uVar27 + uVar28;
          uVar25 = uVar4 + (uVar28 < uVar27) + uVar25;
        }
        uVar7 = *(uint *)(puVar11 + 8);
        uVar4 = puVar16[2];
        uVar9 = uVar7 ^ uVar4;
        if ((int)uVar7 < 0) {
          uVar7 = -uVar7;
        }
        if ((int)uVar4 < 0) {
          uVar4 = -uVar4;
        }
        uVar27 = (uVar4 & 0xffff) * (uVar7 & 0xffff);
        iVar6 = (uVar4 >> 0x10) * (uVar7 & 0xffff);
        iVar5 = 0;
        uVar1 = iVar6 + (uVar4 & 0xffff) * (uVar7 >> 0x10);
        if (iVar6 != 0) {
          iVar5 = 0x10000;
        }
        uVar29 = uVar27 + uVar1 * 0x10000;
        uVar4 = iVar5 + (uint)(uVar29 < uVar27) + (uVar1 >> 0x10) +
                (uVar4 >> 0x10) * (uVar7 >> 0x10);
        if ((int)-(uint)((int)uVar9 < 0) < 0) {
          uVar4 = ~uVar4;
          if (uVar29 == 0) {
            uVar4 = uVar4 + 1;
          }
          else {
            uVar29 = ~uVar29 + 1;
          }
        }
        if (((byte)(in_sr >> 1) & 1) == 1) {
          uVar29 = uVar28 + uVar29;
          uVar25 = uVar4 + (uVar29 < uVar28) + (uVar25 & 0xffff);
          if ((int)uVar25 < -0x8000) {
            uVar25 = 0xffff8000;
            uVar29 = 0;
          }
          if (0x7fff < (int)uVar25) {
            uVar25 = 0x7fff;
            uVar29 = 0xffffffff;
          }
          uVar25 = uVar25 & 0xffff;
        }
        else {
          uVar29 = uVar28 + uVar29;
          uVar25 = uVar4 + (uVar29 < uVar28) + uVar25;
        }
        uVar4 = uVar25 << 0x10 | uVar29 >> 0x10;
        uVar26 = uVar26 | 0 < (int)uVar4;
        uVar25 = uVar26;
        if (((byte)uVar26 & 1) != 1) goto LAB_060320be;
      }
      uVar4 = puVar16[1];
      uVar25 = *puVar16;
      uVar9 = puVar22[7];
      piVar17 = (int *)(PTR_DAT_06031ef0 + (uint)*(ushort *)((int)puVar19 + -6) * 0xc);
      uVar7 = piVar17[2];
      puVar22[4] = (int)DAT_06031eee;
      *puVar22 = uVar7;
      puVar22[5] = 0;
      *(int *)puVar3 = (int)((ulonglong)((longlong)(int)uVar9 * (longlong)(int)uVar25) >> 0x20);
      *(int *)(puVar3 + 4) =
           (int)((ulonglong)((longlong)(int)uVar9 * (longlong)(int)-uVar4) >> 0x20);
      puVar11 = puVar3;
      uVar4 = FUN_060320e6();
      uVar25 = uVar26 & 0xfffffffe | (uint)(0 < extraout_r3);
      if (((byte)uVar25 & 1) == 1) {
        *(int *)(puVar2 + 4) = extraout_r3;
        puVar12 = (undefined4 *)(puVar11 + 8);
        iVar6 = piVar17[1];
        iVar5 = *piVar17;
        uVar4 = puVar22[7];
        piVar17 = (int *)(PTR_DAT_06031f34 + (uint)*(ushort *)(puVar19 + -1) * 0xc);
        uVar26 = piVar17[2];
        puVar22[4] = (int)PTR_DAT_06031f30._0_2_;
        *puVar22 = uVar26;
        puVar22[5] = 0;
        *puVar12 = (int)((ulonglong)((longlong)(int)uVar4 * (longlong)iVar5) >> 0x20);
        *(int *)(puVar11 + 0xc) =
             (int)((ulonglong)((longlong)(int)uVar4 * (longlong)-iVar6) >> 0x20);
        uVar4 = FUN_060320e6();
        uVar25 = uVar25 & 0xfffffffe | (uint)(0 < extraout_r3_00);
        if (((byte)uVar25 & 1) == 1) {
          *(int *)(puVar2 + 8) = extraout_r3_00;
          puVar13 = puVar12 + 2;
          iVar6 = piVar17[1];
          iVar5 = *piVar17;
          uVar4 = puVar22[7];
          piVar17 = (int *)(PTR_DAT_06031f78 + (uint)*(ushort *)((int)puVar19 + -2) * 0xc);
          uVar26 = piVar17[2];
          puVar22[4] = (int)PTR_DAT_06031f74._0_2_;
          *puVar22 = uVar26;
          puVar22[5] = 0;
          *puVar13 = (int)((ulonglong)((longlong)(int)uVar4 * (longlong)iVar5) >> 0x20);
          puVar12[3] = (int)((ulonglong)((longlong)(int)uVar4 * (longlong)-iVar6) >> 0x20);
          uVar4 = FUN_060320e6();
          uVar25 = uVar25 & 0xfffffffe | (uint)(0 < extraout_r3_01);
          if (((byte)uVar25 & 1) == 1) {
            *(int *)(puVar2 + 0xc) = extraout_r3_01;
            iVar5 = piVar17[1];
            uVar26 = puVar22[7];
            puVar13[2] = (int)((ulonglong)((longlong)(int)uVar26 * (longlong)*piVar17) >> 0x20);
            puVar13[3] = (int)((ulonglong)((longlong)(int)uVar26 * (longlong)-iVar5) >> 0x20);
            FUN_060320e6();
            puVar11 = PTR_DAT_06031fcc;
            iVar5 = *(int *)PTR_DAT_06031fc8;
            iVar23 = (int)DAT_06031fc4;
            uVar4 = *(uint *)puVar3;
            iVar6 = *(int *)(puVar3 + 8);
            iVar10 = *(int *)(puVar3 + 0x10);
            iVar15 = *(int *)(puVar3 + 0x18);
            uVar25 = uVar25 & 0xfffffffe;
            if ((((iVar23 <= (int)uVar4) || (iVar23 <= iVar6)) || (iVar23 <= iVar10)) ||
               (iVar23 <= iVar15)) {
              iVar23 = (int)DAT_06032048;
              uVar26 = uVar25 | (int)uVar4 < iVar23;
              if (((((byte)uVar26 & 1) == 1) ||
                  (uVar26 = uVar25 | iVar6 < iVar23, ((byte)uVar26 & 1) == 1)) ||
                 ((uVar26 = uVar25 | iVar10 < iVar23, ((byte)uVar26 & 1) == 1 ||
                  (uVar26 = uVar25 | iVar15 < iVar23, uVar25 = uVar26, ((byte)uVar26 & 1) != 1)))) {
                iVar24 = (int)DAT_0603204a;
                iVar23 = *(int *)(puVar3 + 4);
                iVar8 = *(int *)(puVar3 + 0xc);
                iVar14 = *(int *)(puVar3 + 0x14);
                iVar18 = *(int *)(puVar3 + 0x1c);
                uVar25 = uVar26 & 0xfffffffe;
                if (((iVar24 <= iVar23) || (iVar24 <= iVar8)) ||
                   ((iVar24 <= iVar14 ||
                    (uVar25 = uVar25 | iVar18 < iVar24, ((byte)uVar25 & 1) != 1)))) {
                  iVar24 = (int)PTR_DAT_0603204c._0_2_;
                  if ((((iVar23 < iVar24) || (iVar8 < iVar24)) || (iVar14 < iVar24)) ||
                     (uVar25 = uVar25 & 0xfffffffe, iVar18 < iVar24)) {
                    *(short *)(PTR_DAT_06031fcc + iVar5 * 0x18 + 0x16) = (short)iVar18;
                    *(short *)(puVar11 + iVar5 * 0x18 + 0x14) = (short)iVar15;
                    *(short *)(puVar11 + iVar5 * 0x18 + 0x12) = (short)iVar14;
                    *(short *)(puVar11 + iVar5 * 0x18 + 0x10) = (short)iVar10;
                    *(short *)(puVar11 + iVar5 * 0x18 + 0xe) = (short)iVar8;
                    *(short *)(puVar11 + iVar5 * 0x18 + 0xc) = (short)iVar6;
                    *(short *)(puVar11 + iVar5 * 0x18 + 10) = (short)iVar23;
                    *(short *)(puVar11 + iVar5 * 0x18 + 8) = (short)uVar4;
                    *(undefined2 *)(puVar11 + iVar5 * 0x18 + 6) =
                         *(undefined2 *)((int)puVar19 + -10);
                    puVar11[iVar5 * 0x18 + 4] =
                         (byte)((uint)(int)*(short *)(puVar19 + -3) >> 4) & 0xf;
                    puVar11[iVar5 * 0x18 + 5] = param_2;
                    /* WARNING: Could not recover jumptable at 0x06032044. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    uVar25 = (**(code **)(PTR_LAB_06032050 +
                                         ((int)*(short *)(puVar19 + -3) & 7U) * 4))
                                       (*(undefined4 *)(puVar2 + 4),*(undefined4 *)(puVar2 + 8),
                                        *(undefined4 *)(puVar2 + 0xc));
                    return uVar25;
                  }
                }
              }
            }
          }
        }
      }
    }
LAB_060320be:
    param_3 = param_3 + -1;
    in_sr = uVar25 & 0xfffffffe | (uint)(param_3 == 0);
    puVar19 = puVar20;
    if (((byte)in_sr & 1) == 1) {
      return uVar4;
    }
  } while( true );
}

