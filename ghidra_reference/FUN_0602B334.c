/* FUN_0602B334  0x0602B334 */


uint FUN_0602b334(int param_1,int param_2,undefined1 param_3,int param_4)

{
  short sVar1;
  short sVar2;
  uint uVar3;
  uint uVar4;
  undefined *puVar5;
  undefined *puVar6;
  undefined *puVar7;
  undefined *puVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  undefined4 *puVar12;
  undefined4 uVar13;
  int iVar14;
  short *psVar15;
  uint *puVar16;
  uint *puVar17;
  uint *puVar18;
  int iVar19;
  uint in_sr;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  uint uVar28;
  
  iVar19 = *(int *)PTR_DAT_0602b42c;
  puVar17 = (uint *)(param_1 + param_4 * 0x18);
  do {
    puVar5 = PTR_DAT_0602b430;
    puVar18 = puVar17 + -6;
    psVar15 = (short *)((uint)*(ushort *)(puVar17 + -2) * 6 + param_2);
    sVar1 = psVar15[1];
    sVar2 = psVar15[2];
    uVar20 = in_sr & 0xfffffffe;
    *(int *)PTR_DAT_0602b430 = (int)*psVar15 << 0xb;
    *(int *)(puVar5 + 4) = (int)sVar1 << 0xb;
    *(int *)(puVar5 + 8) = (int)sVar2 << 0xb;
    puVar6 = PTR_DAT_0602b434;
    puVar16 = *(uint **)PTR_DAT_0602b438;
    uVar22 = *puVar16;
    uVar9 = *(uint *)puVar5;
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
    uVar9 = iVar10 + (uint)(uVar24 < uVar3) + (uVar21 >> 0x10) + (uVar9 >> 0x10) * (uVar22 >> 0x10);
    if ((int)-(uint)((int)uVar4 < 0) < 0) {
      uVar9 = ~uVar9;
      if (uVar24 == 0) {
        uVar9 = uVar9 + 1;
      }
      else {
        uVar24 = ~uVar24 + 1;
      }
    }
    if (((byte)(in_sr >> 1) & 1) == 1) {
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
    uVar22 = *(uint *)(puVar5 + 4);
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
    uVar22 = iVar10 + (uint)(uVar28 < uVar25) + (uVar3 >> 0x10) + (uVar22 >> 0x10) * (uVar4 >> 0x10)
    ;
    if ((int)-(uint)((int)uVar21 < 0) < 0) {
      uVar22 = ~uVar22;
      if (uVar28 == 0) {
        uVar22 = uVar22 + 1;
      }
      else {
        uVar28 = ~uVar28 + 1;
      }
    }
    if (((byte)(in_sr >> 1) & 1) == 1) {
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
    uVar22 = *(uint *)(puVar5 + 8);
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
    uVar22 = iVar10 + (uint)(uVar25 < uVar24) + (uVar3 >> 0x10) + (uVar22 >> 0x10) * (uVar4 >> 0x10)
    ;
    if ((int)-(uint)((int)uVar21 < 0) < 0) {
      uVar22 = ~uVar22;
      if (uVar25 == 0) {
        uVar22 = uVar22 + 1;
      }
      else {
        uVar25 = ~uVar25 + 1;
      }
    }
    if (((byte)(in_sr >> 1) & 1) == 1) {
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
    uVar22 = *(uint *)puVar5;
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
    uVar22 = iVar10 + (uint)(uVar28 < uVar24) + (uVar3 >> 0x10) + (uVar22 >> 0x10) * (uVar4 >> 0x10)
    ;
    if ((int)-(uint)((int)uVar21 < 0) < 0) {
      uVar22 = ~uVar22;
      if (uVar28 == 0) {
        uVar22 = uVar22 + 1;
      }
      else {
        uVar28 = ~uVar28 + 1;
      }
    }
    if (((byte)(in_sr >> 1) & 1) == 1) {
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
    uVar4 = *(uint *)(puVar5 + 4);
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
    uVar4 = iVar10 + (uint)(uVar23 < uVar26) + (uVar24 >> 0x10) + (uVar4 >> 0x10) * (uVar21 >> 0x10)
    ;
    if ((int)-(uint)((int)uVar3 < 0) < 0) {
      uVar4 = ~uVar4;
      if (uVar23 == 0) {
        uVar4 = uVar4 + 1;
      }
      else {
        uVar23 = ~uVar23 + 1;
      }
    }
    if (((byte)(in_sr >> 1) & 1) == 1) {
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
    *(uint *)PTR_DAT_0602b434 = (uVar9 << 0x10 | uVar25 >> 0x10) + puVar16[9];
    uVar4 = puVar16[5];
    uVar9 = *(uint *)(puVar5 + 8);
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
    uVar9 = iVar10 + (uint)(uVar25 < uVar24) + (uVar3 >> 0x10) + (uVar9 >> 0x10) * (uVar4 >> 0x10);
    if ((int)-(uint)((int)uVar21 < 0) < 0) {
      uVar9 = ~uVar9;
      if (uVar25 == 0) {
        uVar9 = uVar9 + 1;
      }
      else {
        uVar25 = ~uVar25 + 1;
      }
    }
    if (((byte)(in_sr >> 1) & 1) == 1) {
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
    uVar9 = *(uint *)puVar5;
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
    uVar9 = iVar10 + (uint)(uVar28 < uVar24) + (uVar3 >> 0x10) + (uVar9 >> 0x10) * (uVar4 >> 0x10);
    if ((int)-(uint)((int)uVar21 < 0) < 0) {
      uVar9 = ~uVar9;
      if (uVar28 == 0) {
        uVar9 = uVar9 + 1;
      }
      else {
        uVar28 = ~uVar28 + 1;
      }
    }
    if (((byte)(in_sr >> 1) & 1) == 1) {
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
    uVar4 = *(uint *)(puVar5 + 4);
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
    uVar4 = iVar10 + (uint)(uVar23 < uVar26) + (uVar24 >> 0x10) + (uVar4 >> 0x10) * (uVar21 >> 0x10)
    ;
    if ((int)-(uint)((int)uVar3 < 0) < 0) {
      uVar4 = ~uVar4;
      if (uVar23 == 0) {
        uVar4 = uVar4 + 1;
      }
      else {
        uVar23 = ~uVar23 + 1;
      }
    }
    if (((byte)(in_sr >> 1) & 1) == 1) {
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
    *(uint *)(puVar6 + 4) = (uVar22 << 0x10 | uVar25 >> 0x10) + puVar16[10];
    uVar4 = puVar16[8];
    uVar22 = *(uint *)(puVar5 + 8);
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
    uVar22 = iVar10 + (uint)(uVar25 < uVar24) + (uVar3 >> 0x10) + (uVar22 >> 0x10) * (uVar4 >> 0x10)
    ;
    if ((int)-(uint)((int)uVar21 < 0) < 0) {
      uVar22 = ~uVar22;
      if (uVar25 == 0) {
        uVar22 = uVar22 + 1;
      }
      else {
        uVar25 = ~uVar25 + 1;
      }
    }
    if (((byte)(in_sr >> 1) & 1) == 1) {
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
    *(uint *)(puVar6 + 8) = (uVar9 << 0x10 | uVar25 >> 0x10) + puVar16[0xb];
    puVar5 = PTR_DAT_0602b43c;
    *(ushort *)PTR_DAT_0602b43c = (ushort)(*(int *)(puVar6 + 8) <= iVar19);
    puVar6 = PTR_DAT_0602b440;
    if ((puVar17[-3] & 0x80000) == 0) {
      puVar16 = *(uint **)PTR_DAT_0602b438;
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
      uVar9 = iVar10 + (uint)(uVar24 < uVar3) + (uVar21 >> 0x10) +
              (uVar9 >> 0x10) * (uVar22 >> 0x10);
      if ((int)-(uint)((int)uVar4 < 0) < 0) {
        uVar9 = ~uVar9;
        if (uVar24 == 0) {
          uVar9 = uVar9 + 1;
        }
        else {
          uVar24 = ~uVar24 + 1;
        }
      }
      if (((byte)(in_sr >> 1) & 1) == 1) {
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
      uVar22 = iVar10 + (uint)(uVar28 < uVar25) + (uVar3 >> 0x10) +
               (uVar22 >> 0x10) * (uVar4 >> 0x10);
      if ((int)-(uint)((int)uVar21 < 0) < 0) {
        uVar22 = ~uVar22;
        if (uVar28 == 0) {
          uVar22 = uVar22 + 1;
        }
        else {
          uVar28 = ~uVar28 + 1;
        }
      }
      if (((byte)(in_sr >> 1) & 1) == 1) {
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
      uVar22 = iVar10 + (uint)(uVar25 < uVar24) + (uVar3 >> 0x10) +
               (uVar22 >> 0x10) * (uVar4 >> 0x10);
      if ((int)-(uint)((int)uVar21 < 0) < 0) {
        uVar22 = ~uVar22;
        if (uVar25 == 0) {
          uVar22 = uVar22 + 1;
        }
        else {
          uVar25 = ~uVar25 + 1;
        }
      }
      if (((byte)(in_sr >> 1) & 1) == 1) {
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
      uVar22 = iVar10 + (uint)(uVar28 < uVar24) + (uVar3 >> 0x10) +
               (uVar22 >> 0x10) * (uVar4 >> 0x10);
      if ((int)-(uint)((int)uVar21 < 0) < 0) {
        uVar22 = ~uVar22;
        if (uVar28 == 0) {
          uVar22 = uVar22 + 1;
        }
        else {
          uVar28 = ~uVar28 + 1;
        }
      }
      if (((byte)(in_sr >> 1) & 1) == 1) {
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
      *(uint *)PTR_DAT_0602b440 = uVar9 << 0x10 | uVar25 >> 0x10;
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
      uVar9 = iVar10 + (uint)(uVar25 < uVar24) + (uVar3 >> 0x10) + (uVar9 >> 0x10) * (uVar4 >> 0x10)
      ;
      if ((int)-(uint)((int)uVar21 < 0) < 0) {
        uVar9 = ~uVar9;
        if (uVar25 == 0) {
          uVar9 = uVar9 + 1;
        }
        else {
          uVar25 = ~uVar25 + 1;
        }
      }
      if (((byte)(in_sr >> 1) & 1) == 1) {
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
      uVar9 = iVar10 + (uint)(uVar28 < uVar24) + (uVar3 >> 0x10) + (uVar9 >> 0x10) * (uVar4 >> 0x10)
      ;
      if ((int)-(uint)((int)uVar21 < 0) < 0) {
        uVar9 = ~uVar9;
        if (uVar28 == 0) {
          uVar9 = uVar9 + 1;
        }
        else {
          uVar28 = ~uVar28 + 1;
        }
      }
      if (((byte)(in_sr >> 1) & 1) == 1) {
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
      uVar9 = iVar10 + (uint)(uVar25 < uVar24) + (uVar3 >> 0x10) + (uVar9 >> 0x10) * (uVar4 >> 0x10)
      ;
      if ((int)-(uint)((int)uVar21 < 0) < 0) {
        uVar9 = ~uVar9;
        if (uVar25 == 0) {
          uVar9 = uVar9 + 1;
        }
        else {
          uVar25 = ~uVar25 + 1;
        }
      }
      if (((byte)(in_sr >> 1) & 1) == 1) {
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
      *(uint *)(puVar6 + 4) = uVar22 << 0x10 | uVar28 >> 0x10;
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
      uVar22 = iVar10 + (uint)(uVar28 < uVar24) + (uVar3 >> 0x10) +
               (uVar22 >> 0x10) * (uVar4 >> 0x10);
      if ((int)-(uint)((int)uVar21 < 0) < 0) {
        uVar22 = ~uVar22;
        if (uVar28 == 0) {
          uVar22 = uVar22 + 1;
        }
        else {
          uVar28 = ~uVar28 + 1;
        }
      }
      if (((byte)(in_sr >> 1) & 1) == 1) {
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
      uVar22 = iVar10 + (uint)(uVar25 < uVar24) + (uVar3 >> 0x10) +
               (uVar22 >> 0x10) * (uVar4 >> 0x10);
      if ((int)-(uint)((int)uVar21 < 0) < 0) {
        uVar22 = ~uVar22;
        if (uVar25 == 0) {
          uVar22 = uVar22 + 1;
        }
        else {
          uVar25 = ~uVar25 + 1;
        }
      }
      if (((byte)(in_sr >> 1) & 1) == 1) {
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
      *(uint *)(puVar6 + 8) = uVar9 << 0x10 | uVar25 >> 0x10;
      uVar22 = *(uint *)puVar6;
      uVar9 = *(uint *)PTR_DAT_0602b434;
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
      uVar9 = iVar10 + (uint)(uVar24 < uVar3) + (uVar21 >> 0x10) +
              (uVar9 >> 0x10) * (uVar22 >> 0x10);
      if ((int)-(uint)((int)uVar4 < 0) < 0) {
        uVar9 = ~uVar9;
        if (uVar24 == 0) {
          uVar9 = uVar9 + 1;
        }
        else {
          uVar24 = ~uVar24 + 1;
        }
      }
      if (((byte)(in_sr >> 1) & 1) == 1) {
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
      uVar4 = *(uint *)(puVar6 + 4);
      uVar22 = *(uint *)(PTR_DAT_0602b434 + 4);
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
      uVar22 = iVar10 + (uint)(uVar28 < uVar25) + (uVar3 >> 0x10) +
               (uVar22 >> 0x10) * (uVar4 >> 0x10);
      if ((int)-(uint)((int)uVar21 < 0) < 0) {
        uVar22 = ~uVar22;
        if (uVar28 == 0) {
          uVar22 = uVar22 + 1;
        }
        else {
          uVar28 = ~uVar28 + 1;
        }
      }
      if (((byte)(in_sr >> 1) & 1) == 1) {
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
      uVar4 = *(uint *)(puVar6 + 8);
      uVar22 = *(uint *)(PTR_DAT_0602b434 + 8);
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
      uVar22 = iVar10 + (uint)(uVar25 < uVar24) + (uVar3 >> 0x10) +
               (uVar22 >> 0x10) * (uVar4 >> 0x10);
      if ((int)-(uint)((int)uVar21 < 0) < 0) {
        uVar22 = ~uVar22;
        if (uVar25 == 0) {
          uVar22 = uVar22 + 1;
        }
        else {
          uVar25 = ~uVar25 + 1;
        }
      }
      if (((byte)(in_sr >> 1) & 1) == 1) {
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
      if (((byte)uVar20 & 1) == 1) goto LAB_0602b444;
    }
    else {
LAB_0602b444:
      puVar6 = PTR_DAT_0602b5e0;
      psVar15 = (short *)((uint)*(ushort *)((int)puVar17 + -6) * 6 + param_2);
      sVar1 = psVar15[1];
      sVar2 = psVar15[2];
      uVar21 = uVar20 & 0xfffffffe;
      *(int *)PTR_DAT_0602b5e0 = (int)*psVar15 << 0xb;
      *(int *)(puVar6 + 4) = (int)sVar1 << 0xb;
      *(int *)(puVar6 + 8) = (int)sVar2 << 0xb;
      puVar7 = PTR_DAT_0602b5e4;
      puVar16 = *(uint **)PTR_DAT_0602b5e8;
      uVar22 = *puVar16;
      uVar9 = *(uint *)puVar6;
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
      uVar9 = iVar10 + (uint)(uVar25 < uVar24) + (uVar3 >> 0x10) +
              (uVar9 >> 0x10) * (uVar22 >> 0x10);
      if ((int)-(uint)((int)uVar4 < 0) < 0) {
        uVar9 = ~uVar9;
        if (uVar25 == 0) {
          uVar9 = uVar9 + 1;
        }
        else {
          uVar25 = ~uVar25 + 1;
        }
      }
      if (((byte)(uVar20 >> 1) & 1) == 1) {
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
      uVar22 = *(uint *)(puVar6 + 4);
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
      uVar22 = iVar10 + (uint)(uVar26 < uVar28) + (uVar24 >> 0x10) +
               (uVar22 >> 0x10) * (uVar4 >> 0x10);
      if ((int)-(uint)((int)uVar3 < 0) < 0) {
        uVar22 = ~uVar22;
        if (uVar26 == 0) {
          uVar22 = uVar22 + 1;
        }
        else {
          uVar26 = ~uVar26 + 1;
        }
      }
      if (((byte)(uVar20 >> 1) & 1) == 1) {
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
      uVar22 = *(uint *)(puVar6 + 8);
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
      uVar22 = iVar10 + (uint)(uVar28 < uVar25) + (uVar24 >> 0x10) +
               (uVar22 >> 0x10) * (uVar4 >> 0x10);
      if ((int)-(uint)((int)uVar3 < 0) < 0) {
        uVar22 = ~uVar22;
        if (uVar28 == 0) {
          uVar22 = uVar22 + 1;
        }
        else {
          uVar28 = ~uVar28 + 1;
        }
      }
      if (((byte)(uVar20 >> 1) & 1) == 1) {
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
      uVar22 = *(uint *)puVar6;
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
      uVar22 = iVar10 + (uint)(uVar26 < uVar25) + (uVar24 >> 0x10) +
               (uVar22 >> 0x10) * (uVar4 >> 0x10);
      if ((int)-(uint)((int)uVar3 < 0) < 0) {
        uVar22 = ~uVar22;
        if (uVar26 == 0) {
          uVar22 = uVar22 + 1;
        }
        else {
          uVar26 = ~uVar26 + 1;
        }
      }
      if (((byte)(uVar20 >> 1) & 1) == 1) {
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
      uVar4 = *(uint *)(puVar6 + 4);
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
      uVar4 = iVar10 + (uint)(uVar27 < uVar23) + (uVar25 >> 0x10) +
              (uVar4 >> 0x10) * (uVar3 >> 0x10);
      if ((int)-(uint)((int)uVar24 < 0) < 0) {
        uVar4 = ~uVar4;
        if (uVar27 == 0) {
          uVar4 = uVar4 + 1;
        }
        else {
          uVar27 = ~uVar27 + 1;
        }
      }
      if (((byte)(uVar20 >> 1) & 1) == 1) {
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
      *(uint *)(PTR_DAT_0602b5e4 + 0xc) = (uVar9 << 0x10 | uVar28 >> 0x10) + puVar16[9];
      uVar4 = puVar16[5];
      uVar9 = *(uint *)(puVar6 + 8);
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
      uVar9 = iVar10 + (uint)(uVar28 < uVar25) + (uVar24 >> 0x10) +
              (uVar9 >> 0x10) * (uVar4 >> 0x10);
      if ((int)-(uint)((int)uVar3 < 0) < 0) {
        uVar9 = ~uVar9;
        if (uVar28 == 0) {
          uVar9 = uVar9 + 1;
        }
        else {
          uVar28 = ~uVar28 + 1;
        }
      }
      if (((byte)(uVar20 >> 1) & 1) == 1) {
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
      uVar9 = *(uint *)puVar6;
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
      uVar9 = iVar10 + (uint)(uVar26 < uVar25) + (uVar24 >> 0x10) +
              (uVar9 >> 0x10) * (uVar4 >> 0x10);
      if ((int)-(uint)((int)uVar3 < 0) < 0) {
        uVar9 = ~uVar9;
        if (uVar26 == 0) {
          uVar9 = uVar9 + 1;
        }
        else {
          uVar26 = ~uVar26 + 1;
        }
      }
      if (((byte)(uVar20 >> 1) & 1) == 1) {
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
      uVar4 = *(uint *)(puVar6 + 4);
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
      uVar4 = iVar10 + (uint)(uVar27 < uVar23) + (uVar25 >> 0x10) +
              (uVar4 >> 0x10) * (uVar3 >> 0x10);
      if ((int)-(uint)((int)uVar24 < 0) < 0) {
        uVar4 = ~uVar4;
        if (uVar27 == 0) {
          uVar4 = uVar4 + 1;
        }
        else {
          uVar27 = ~uVar27 + 1;
        }
      }
      if (((byte)(uVar20 >> 1) & 1) == 1) {
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
      *(uint *)(puVar7 + 0x10) = (uVar22 << 0x10 | uVar28 >> 0x10) + puVar16[10];
      uVar4 = puVar16[8];
      uVar22 = *(uint *)(puVar6 + 8);
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
      uVar22 = iVar10 + (uint)(uVar28 < uVar25) + (uVar24 >> 0x10) +
               (uVar22 >> 0x10) * (uVar4 >> 0x10);
      if ((int)-(uint)((int)uVar3 < 0) < 0) {
        uVar22 = ~uVar22;
        if (uVar28 == 0) {
          uVar22 = uVar22 + 1;
        }
        else {
          uVar28 = ~uVar28 + 1;
        }
      }
      if (((byte)(uVar20 >> 1) & 1) == 1) {
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
      *(uint *)(puVar7 + 0x14) = (uVar9 << 0x10 | uVar28 >> 0x10) + puVar16[0xb];
      *(ushort *)(puVar5 + 2) = (ushort)(*(int *)(puVar7 + 0x14) <= iVar19);
      puVar6 = PTR_DAT_0602b5e0;
      psVar15 = (short *)((uint)*(ushort *)(puVar17 + -1) * 6 + param_2);
      sVar1 = psVar15[1];
      sVar2 = psVar15[2];
      *(int *)PTR_DAT_0602b5e0 = (int)*psVar15 << 0xb;
      *(int *)(puVar6 + 4) = (int)sVar1 << 0xb;
      *(int *)PTR_DAT_0602b5ec = (int)sVar1 << 0xb;
      *(int *)(puVar6 + 8) = (int)sVar2 << 0xb;
      puVar7 = PTR_DAT_0602b5e4;
      puVar16 = *(uint **)PTR_DAT_0602b5e8;
      uVar22 = *puVar16;
      uVar9 = *(uint *)puVar6;
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
      uVar9 = iVar10 + (uint)(uVar25 < uVar24) + (uVar3 >> 0x10) +
              (uVar9 >> 0x10) * (uVar22 >> 0x10);
      if ((int)-(uint)((int)uVar4 < 0) < 0) {
        uVar9 = ~uVar9;
        if (uVar25 == 0) {
          uVar9 = uVar9 + 1;
        }
        else {
          uVar25 = ~uVar25 + 1;
        }
      }
      if (((byte)(uVar20 >> 1) & 1) == 1) {
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
      uVar22 = *(uint *)(puVar6 + 4);
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
      uVar22 = iVar10 + (uint)(uVar26 < uVar28) + (uVar24 >> 0x10) +
               (uVar22 >> 0x10) * (uVar4 >> 0x10);
      if ((int)-(uint)((int)uVar3 < 0) < 0) {
        uVar22 = ~uVar22;
        if (uVar26 == 0) {
          uVar22 = uVar22 + 1;
        }
        else {
          uVar26 = ~uVar26 + 1;
        }
      }
      if (((byte)(uVar20 >> 1) & 1) == 1) {
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
      uVar22 = *(uint *)(puVar6 + 8);
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
      uVar22 = iVar10 + (uint)(uVar28 < uVar25) + (uVar24 >> 0x10) +
               (uVar22 >> 0x10) * (uVar4 >> 0x10);
      if ((int)-(uint)((int)uVar3 < 0) < 0) {
        uVar22 = ~uVar22;
        if (uVar28 == 0) {
          uVar22 = uVar22 + 1;
        }
        else {
          uVar28 = ~uVar28 + 1;
        }
      }
      if (((byte)(uVar20 >> 1) & 1) == 1) {
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
      uVar22 = *(uint *)puVar6;
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
      uVar22 = iVar10 + (uint)(uVar26 < uVar25) + (uVar24 >> 0x10) +
               (uVar22 >> 0x10) * (uVar4 >> 0x10);
      if ((int)-(uint)((int)uVar3 < 0) < 0) {
        uVar22 = ~uVar22;
        if (uVar26 == 0) {
          uVar22 = uVar22 + 1;
        }
        else {
          uVar26 = ~uVar26 + 1;
        }
      }
      if (((byte)(uVar20 >> 1) & 1) == 1) {
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
      uVar4 = *(uint *)(puVar6 + 4);
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
      uVar4 = iVar10 + (uint)(uVar27 < uVar23) + (uVar25 >> 0x10) +
              (uVar4 >> 0x10) * (uVar3 >> 0x10);
      if ((int)-(uint)((int)uVar24 < 0) < 0) {
        uVar4 = ~uVar4;
        if (uVar27 == 0) {
          uVar4 = uVar4 + 1;
        }
        else {
          uVar27 = ~uVar27 + 1;
        }
      }
      if (((byte)(uVar20 >> 1) & 1) == 1) {
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
      *(uint *)(PTR_DAT_0602b5e4 + 0x18) = (uVar9 << 0x10 | uVar28 >> 0x10) + puVar16[9];
      uVar4 = puVar16[5];
      uVar9 = *(uint *)(puVar6 + 8);
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
      uVar9 = iVar10 + (uint)(uVar28 < uVar25) + (uVar24 >> 0x10) +
              (uVar9 >> 0x10) * (uVar4 >> 0x10);
      if ((int)-(uint)((int)uVar3 < 0) < 0) {
        uVar9 = ~uVar9;
        if (uVar28 == 0) {
          uVar9 = uVar9 + 1;
        }
        else {
          uVar28 = ~uVar28 + 1;
        }
      }
      if (((byte)(uVar20 >> 1) & 1) == 1) {
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
      uVar9 = *(uint *)puVar6;
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
      uVar9 = iVar10 + (uint)(uVar26 < uVar25) + (uVar24 >> 0x10) +
              (uVar9 >> 0x10) * (uVar4 >> 0x10);
      if ((int)-(uint)((int)uVar3 < 0) < 0) {
        uVar9 = ~uVar9;
        if (uVar26 == 0) {
          uVar9 = uVar9 + 1;
        }
        else {
          uVar26 = ~uVar26 + 1;
        }
      }
      if (((byte)(uVar20 >> 1) & 1) == 1) {
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
      uVar4 = *(uint *)(puVar6 + 4);
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
      uVar4 = iVar10 + (uint)(uVar27 < uVar23) + (uVar25 >> 0x10) +
              (uVar4 >> 0x10) * (uVar3 >> 0x10);
      if ((int)-(uint)((int)uVar24 < 0) < 0) {
        uVar4 = ~uVar4;
        if (uVar27 == 0) {
          uVar4 = uVar4 + 1;
        }
        else {
          uVar27 = ~uVar27 + 1;
        }
      }
      if (((byte)(uVar20 >> 1) & 1) == 1) {
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
      *(uint *)(puVar7 + 0x1c) = (uVar22 << 0x10 | uVar28 >> 0x10) + puVar16[10];
      uVar4 = puVar16[8];
      uVar22 = *(uint *)(puVar6 + 8);
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
      uVar22 = iVar10 + (uint)(uVar28 < uVar25) + (uVar24 >> 0x10) +
               (uVar22 >> 0x10) * (uVar4 >> 0x10);
      if ((int)-(uint)((int)uVar3 < 0) < 0) {
        uVar22 = ~uVar22;
        if (uVar28 == 0) {
          uVar22 = uVar22 + 1;
        }
        else {
          uVar28 = ~uVar28 + 1;
        }
      }
      if (((byte)(uVar20 >> 1) & 1) == 1) {
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
      *(uint *)(puVar7 + 0x20) = (uVar9 << 0x10 | uVar28 >> 0x10) + puVar16[0xb];
      *(ushort *)(puVar5 + 4) = (ushort)(*(int *)(puVar7 + 0x20) <= iVar19);
      puVar6 = PTR_DAT_0602b5e0;
      psVar15 = (short *)((uint)*(ushort *)((int)puVar17 + -2) * 6 + param_2);
      sVar1 = psVar15[1];
      sVar2 = psVar15[2];
      *(int *)PTR_DAT_0602b5e0 = (int)*psVar15 << 0xb;
      *(int *)(puVar6 + 4) = (int)sVar1 << 0xb;
      *(int *)(puVar6 + 8) = (int)sVar2 << 0xb;
      puVar7 = PTR_DAT_0602b5e4;
      puVar16 = *(uint **)PTR_DAT_0602b5e8;
      uVar22 = *puVar16;
      uVar9 = *(uint *)puVar6;
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
      uVar9 = iVar10 + (uint)(uVar25 < uVar24) + (uVar3 >> 0x10) +
              (uVar9 >> 0x10) * (uVar22 >> 0x10);
      if ((int)-(uint)((int)uVar4 < 0) < 0) {
        uVar9 = ~uVar9;
        if (uVar25 == 0) {
          uVar9 = uVar9 + 1;
        }
        else {
          uVar25 = ~uVar25 + 1;
        }
      }
      if (((byte)(uVar20 >> 1) & 1) == 1) {
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
      uVar22 = *(uint *)(puVar6 + 4);
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
      uVar22 = iVar10 + (uint)(uVar26 < uVar28) + (uVar24 >> 0x10) +
               (uVar22 >> 0x10) * (uVar4 >> 0x10);
      if ((int)-(uint)((int)uVar3 < 0) < 0) {
        uVar22 = ~uVar22;
        if (uVar26 == 0) {
          uVar22 = uVar22 + 1;
        }
        else {
          uVar26 = ~uVar26 + 1;
        }
      }
      if (((byte)(uVar20 >> 1) & 1) == 1) {
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
      uVar22 = *(uint *)(puVar6 + 8);
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
      uVar22 = iVar10 + (uint)(uVar28 < uVar25) + (uVar24 >> 0x10) +
               (uVar22 >> 0x10) * (uVar4 >> 0x10);
      if ((int)-(uint)((int)uVar3 < 0) < 0) {
        uVar22 = ~uVar22;
        if (uVar28 == 0) {
          uVar22 = uVar22 + 1;
        }
        else {
          uVar28 = ~uVar28 + 1;
        }
      }
      if (((byte)(uVar20 >> 1) & 1) == 1) {
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
      uVar22 = *(uint *)puVar6;
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
      uVar22 = iVar10 + (uint)(uVar26 < uVar25) + (uVar24 >> 0x10) +
               (uVar22 >> 0x10) * (uVar4 >> 0x10);
      if ((int)-(uint)((int)uVar3 < 0) < 0) {
        uVar22 = ~uVar22;
        if (uVar26 == 0) {
          uVar22 = uVar22 + 1;
        }
        else {
          uVar26 = ~uVar26 + 1;
        }
      }
      if (((byte)(uVar20 >> 1) & 1) == 1) {
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
      uVar4 = *(uint *)(puVar6 + 4);
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
      uVar4 = iVar10 + (uint)(uVar27 < uVar23) + (uVar25 >> 0x10) +
              (uVar4 >> 0x10) * (uVar3 >> 0x10);
      if ((int)-(uint)((int)uVar24 < 0) < 0) {
        uVar4 = ~uVar4;
        if (uVar27 == 0) {
          uVar4 = uVar4 + 1;
        }
        else {
          uVar27 = ~uVar27 + 1;
        }
      }
      if (((byte)(uVar20 >> 1) & 1) == 1) {
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
      *(uint *)(PTR_DAT_0602b5e4 + 0x24) = (uVar9 << 0x10 | uVar28 >> 0x10) + puVar16[9];
      uVar4 = puVar16[5];
      uVar9 = *(uint *)(puVar6 + 8);
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
      uVar9 = iVar10 + (uint)(uVar28 < uVar25) + (uVar24 >> 0x10) +
              (uVar9 >> 0x10) * (uVar4 >> 0x10);
      if ((int)-(uint)((int)uVar3 < 0) < 0) {
        uVar9 = ~uVar9;
        if (uVar28 == 0) {
          uVar9 = uVar9 + 1;
        }
        else {
          uVar28 = ~uVar28 + 1;
        }
      }
      if (((byte)(uVar20 >> 1) & 1) == 1) {
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
      uVar9 = *(uint *)puVar6;
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
      uVar9 = iVar10 + (uint)(uVar26 < uVar25) + (uVar24 >> 0x10) +
              (uVar9 >> 0x10) * (uVar4 >> 0x10);
      if ((int)-(uint)((int)uVar3 < 0) < 0) {
        uVar9 = ~uVar9;
        if (uVar26 == 0) {
          uVar9 = uVar9 + 1;
        }
        else {
          uVar26 = ~uVar26 + 1;
        }
      }
      if (((byte)(uVar20 >> 1) & 1) == 1) {
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
      uVar4 = *(uint *)(puVar6 + 4);
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
      uVar4 = iVar10 + (uint)(uVar27 < uVar23) + (uVar25 >> 0x10) +
              (uVar4 >> 0x10) * (uVar3 >> 0x10);
      if ((int)-(uint)((int)uVar24 < 0) < 0) {
        uVar4 = ~uVar4;
        if (uVar27 == 0) {
          uVar4 = uVar4 + 1;
        }
        else {
          uVar27 = ~uVar27 + 1;
        }
      }
      if (((byte)(uVar20 >> 1) & 1) == 1) {
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
      *(uint *)(puVar7 + 0x28) = (uVar22 << 0x10 | uVar28 >> 0x10) + puVar16[10];
      uVar4 = puVar16[8];
      uVar22 = *(uint *)(puVar6 + 8);
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
      uVar22 = iVar10 + (uint)(uVar28 < uVar25) + (uVar24 >> 0x10) +
               (uVar22 >> 0x10) * (uVar4 >> 0x10);
      if ((int)-(uint)((int)uVar3 < 0) < 0) {
        uVar22 = ~uVar22;
        if (uVar28 == 0) {
          uVar22 = uVar22 + 1;
        }
        else {
          uVar28 = ~uVar28 + 1;
        }
      }
      if (((byte)(uVar20 >> 1) & 1) == 1) {
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
      *(uint *)(puVar7 + 0x2c) = (uVar9 << 0x10 | uVar28 >> 0x10) + puVar16[0xb];
      iVar10 = *(int *)(puVar7 + 0x2c);
      *(ushort *)(puVar5 + 6) = (ushort)(iVar10 <= iVar19);
      iVar10 = (uint)(iVar10 <= iVar19) + (int)*(short *)(puVar5 + 4) +
               (int)*(short *)(puVar5 + 2) + (int)*(short *)puVar5;
      uVar20 = uVar21 | iVar10 == 0;
      if (((byte)uVar20 & 1) != 1) {
        if (iVar10 == 4) {
          uVar9 = 4;
          uVar20 = uVar21;
          goto LAB_0602b972;
        }
        (**(code **)(PTR_DAT_0602b654 + iVar10 * 4))
                  (PTR_DAT_0602b658,PTR_DAT_0602b65c,puVar16 + 9,puVar16 + 0xc);
        uVar20 = uVar21;
      }
      puVar7 = PTR_DAT_0602b668;
      puVar6 = PTR_DAT_0602b664;
      puVar5 = PTR_DAT_0602b658;
      iVar10 = *(int *)PTR_DAT_0602b660;
      puVar12 = (undefined4 *)(int)DAT_0602b64c;
      uVar13 = *(undefined4 *)(PTR_DAT_0602b658 + 8);
      puVar12[4] = (int)DAT_0602b64e;
      *puVar12 = uVar13;
      puVar12[5] = 0;
      iVar14 = *(int *)(puVar5 + 4);
      iVar11 = puVar12[7];
      *(int *)puVar7 = (int)((ulonglong)((longlong)iVar11 * (longlong)*(int *)puVar5) >> 0x20);
      *(int *)(puVar7 + 4) = (int)((ulonglong)((longlong)iVar11 * (longlong)-iVar14) >> 0x20);
      puVar8 = PTR_DAT_0602b66c;
      iVar11 = *(int *)puVar7;
      iVar14 = *(int *)(puVar7 + 4);
      *(undefined2 *)PTR_DAT_0602b66c = 0;
      uVar20 = uVar20 & 0xfffffffe;
      if (PTR_DAT_0602b650._0_2_ < iVar11) {
        *(undefined2 *)puVar8 = 1;
      }
      else if (iVar11 < DAT_0602b67c) {
        *(undefined2 *)puVar8 = 1;
      }
      else if (DAT_0602b68a < iVar14) {
        *(undefined2 *)puVar8 = 1;
      }
      else if (iVar14 < DAT_0602b6d2) {
        *(undefined2 *)puVar8 = 1;
      }
      puVar12 = (undefined4 *)(int)DAT_0602b6d4;
      uVar13 = *(undefined4 *)(puVar5 + 0x14);
      puVar12[4] = (int)DAT_0602b6d6;
      *puVar12 = uVar13;
      puVar12[5] = 0;
      iVar14 = *(int *)(puVar5 + 0x10);
      iVar11 = puVar12[7];
      *(int *)(puVar7 + 8) =
           (int)((ulonglong)((longlong)iVar11 * (longlong)*(int *)(puVar5 + 0xc)) >> 0x20);
      *(int *)(puVar7 + 0xc) = (int)((ulonglong)((longlong)iVar11 * (longlong)-iVar14) >> 0x20);
      iVar11 = *(int *)(puVar7 + 8);
      iVar14 = *(int *)(puVar7 + 0xc);
      *(undefined2 *)(puVar8 + 2) = 0;
      if (DAT_0602b6d8 < iVar11) {
        *(undefined2 *)(puVar8 + 2) = 1;
      }
      else if (iVar11 < DAT_0602b6e6) {
        *(undefined2 *)(puVar8 + 2) = 1;
      }
      else if (DAT_0602b6f4 < iVar14) {
        *(undefined2 *)(puVar8 + 2) = 1;
      }
      else if (iVar14 < DAT_0602b73c) {
        *(undefined2 *)(puVar8 + 2) = 1;
      }
      puVar12 = (undefined4 *)(int)DAT_0602b73e;
      uVar13 = *(undefined4 *)(puVar5 + 0x20);
      puVar12[4] = (int)DAT_0602b740;
      *puVar12 = uVar13;
      puVar12[5] = 0;
      iVar14 = *(int *)(puVar5 + 0x1c);
      iVar11 = puVar12[7];
      *(int *)(puVar7 + 0x10) =
           (int)((ulonglong)((longlong)iVar11 * (longlong)*(int *)(puVar5 + 0x18)) >> 0x20);
      *(int *)(puVar7 + 0x14) = (int)((ulonglong)((longlong)iVar11 * (longlong)-iVar14) >> 0x20);
      iVar11 = *(int *)(puVar7 + 0x10);
      iVar14 = *(int *)(puVar7 + 0x14);
      *(undefined2 *)(puVar8 + 4) = 0;
      if (DAT_0602b742 < iVar11) {
        *(undefined2 *)(puVar8 + 4) = 1;
      }
      else if (iVar11 < DAT_0602b750) {
        *(undefined2 *)(puVar8 + 4) = 1;
      }
      else if (DAT_0602b75e < iVar14) {
        *(undefined2 *)(puVar8 + 4) = 1;
      }
      else if (iVar14 < DAT_0602b7a6) {
        *(undefined2 *)(puVar8 + 4) = 1;
      }
      puVar12 = (undefined4 *)(int)DAT_0602b7a8;
      uVar13 = *(undefined4 *)(puVar5 + 0x2c);
      puVar12[4] = (int)DAT_0602b7aa;
      *puVar12 = uVar13;
      puVar12[5] = 0;
      iVar14 = *(int *)(puVar5 + 0x28);
      iVar11 = puVar12[7];
      *(int *)(puVar7 + 0x18) =
           (int)((ulonglong)((longlong)iVar11 * (longlong)*(int *)(puVar5 + 0x24)) >> 0x20);
      *(int *)(puVar7 + 0x1c) = (int)((ulonglong)((longlong)iVar11 * (longlong)-iVar14) >> 0x20);
      iVar11 = *(int *)(puVar7 + 0x18);
      iVar14 = *(int *)(puVar7 + 0x1c);
      *(undefined2 *)(puVar8 + 6) = 0;
      if (DAT_0602b7ac < iVar11) {
        *(undefined2 *)(puVar8 + 6) = 1;
      }
      else if (iVar11 < DAT_0602b7ba) {
        *(undefined2 *)(puVar8 + 6) = 1;
      }
      else if (DAT_0602b7c8 < iVar14) {
        *(undefined2 *)(puVar8 + 6) = 1;
      }
      else if (iVar14 < DAT_0602b7f8) {
        *(undefined2 *)(puVar8 + 6) = 1;
      }
      if (((((int)PTR_DAT_0602b7fc <= *(int *)puVar7) ||
           ((int)PTR_DAT_0602b7fc <= *(int *)(puVar7 + 8))) ||
          ((int)PTR_DAT_0602b7fc <= *(int *)(puVar7 + 0x10))) ||
         (uVar9 = *(uint *)(puVar7 + 0x18), (int)PTR_DAT_0602b7fc <= (int)uVar9)) {
        uVar22 = uVar20 | *(int *)puVar7 < DAT_0602b800;
        if (((((byte)uVar22 & 1) != 1) &&
            (uVar22 = uVar20 | *(int *)(puVar7 + 8) < DAT_0602b800, ((byte)uVar22 & 1) != 1)) &&
           (uVar22 = uVar20 | *(int *)(puVar7 + 0x10) < DAT_0602b800, ((byte)uVar22 & 1) != 1)) {
          uVar9 = *(uint *)(puVar7 + 0x18);
          uVar22 = uVar20 | (int)uVar9 < DAT_0602b800;
          uVar20 = uVar22;
          if (((byte)uVar22 & 1) != 1) goto LAB_0602b972;
        }
        uVar22 = uVar22 & 0xfffffffe;
        if ((((int)PTR_DAT_0602b804 <= *(int *)(puVar7 + 4)) ||
            ((int)PTR_DAT_0602b804 <= *(int *)(puVar7 + 0xc))) ||
           (((int)PTR_DAT_0602b804 <= *(int *)(puVar7 + 0x14) ||
            (uVar9 = *(uint *)(puVar7 + 0x1c), uVar20 = uVar22, (int)PTR_DAT_0602b804 <= (int)uVar9)
            ))) {
          uVar20 = uVar22 | *(int *)(puVar7 + 4) < DAT_0602b808;
          if (((((byte)uVar20 & 1) != 1) &&
              (uVar20 = uVar22 | *(int *)(puVar7 + 0xc) < DAT_0602b808, ((byte)uVar20 & 1) != 1)) &&
             (uVar20 = uVar22 | *(int *)(puVar7 + 0x14) < DAT_0602b808, ((byte)uVar20 & 1) != 1)) {
            uVar9 = *(uint *)(puVar7 + 0x1c);
            uVar20 = uVar22 | (int)uVar9 < DAT_0602b808;
            if (((byte)uVar20 & 1) != 1) goto LAB_0602b972;
          }
          iVar11 = (int)*(short *)(puVar8 + 6) +
                   (int)*(short *)puVar8 + (int)*(short *)(puVar8 + 2) + (int)*(short *)(puVar8 + 4)
          ;
          if (iVar11 != 4) {
            if (iVar11 != 0) {
              (**(code **)(PTR_DAT_0602b8d0 + iVar11 * 4))(puVar7,puVar8);
            }
            *(short *)(puVar6 + iVar10 * 0x18 + 8) = (short)*(undefined4 *)puVar7;
            *(short *)(puVar6 + iVar10 * 0x18 + 10) = (short)*(undefined4 *)(puVar7 + 4);
            *(short *)(puVar6 + iVar10 * 0x18 + 0xc) = (short)*(undefined4 *)(puVar7 + 8);
            *(short *)(puVar6 + iVar10 * 0x18 + 0xe) = (short)*(undefined4 *)(puVar7 + 0xc);
            *(short *)(puVar6 + iVar10 * 0x18 + 0x10) = (short)*(undefined4 *)(puVar7 + 0x10);
            *(short *)(puVar6 + iVar10 * 0x18 + 0x12) = (short)*(undefined4 *)(puVar7 + 0x14);
            *(short *)(puVar6 + iVar10 * 0x18 + 0x14) = (short)*(undefined4 *)(puVar7 + 0x18);
            *(short *)(puVar6 + iVar10 * 0x18 + 0x16) = (short)*(undefined4 *)(puVar7 + 0x1c);
            *(undefined2 *)(puVar6 + iVar10 * 0x18 + 6) = *(undefined2 *)((int)puVar17 + -10);
            puVar6[iVar10 * 0x18 + 4] = (byte)((uint)(int)*(short *)(puVar17 + -3) >> 4) & 0xf;
            puVar6[iVar10 * 0x18 + 5] = param_3;
                    /* WARNING: Could not recover jumptable at 0x0602b8cc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            uVar20 = (**(code **)(PTR_PTR_0602b8d4 + ((int)*(short *)(puVar17 + -3) & 7U) * 4))
                               (*(undefined4 *)(PTR_DAT_0602b8d8 + 0x14),
                                *(undefined4 *)(PTR_DAT_0602b8d8 + 0x20),
                                *(undefined4 *)(PTR_DAT_0602b8d8 + 0x2c));
            return uVar20;
          }
          uVar9 = 4;
          uVar20 = uVar20 & 0xfffffffe;
        }
      }
    }
LAB_0602b972:
    param_4 = param_4 + -1;
    in_sr = uVar20 & 0xfffffffe | (uint)(param_4 == 0);
    puVar17 = puVar18;
    if (((byte)in_sr & 1) == 1) {
      return uVar9;
    }
  } while( true );
}

