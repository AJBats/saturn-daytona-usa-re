/* FUN_060274DA  0x060274DA */


uint FUN_060274da(uint *param_1,uint *param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint in_sr;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  uVar5 = *param_2;
  uVar7 = *param_1;
  uVar6 = uVar5 ^ uVar7;
  if ((int)uVar5 < 0) {
    uVar5 = -uVar5;
  }
  if ((int)uVar7 < 0) {
    uVar7 = -uVar7;
  }
  uVar3 = (uVar7 & 0xffff) * (uVar5 & 0xffff);
  iVar4 = (uVar7 >> 0x10) * (uVar5 & 0xffff);
  iVar2 = 0;
  uVar1 = iVar4 + (uVar7 & 0xffff) * (uVar5 >> 0x10);
  if (iVar4 != 0) {
    iVar2 = 0x10000;
  }
  uVar8 = uVar3 + uVar1 * 0x10000;
  uVar7 = iVar2 + (uint)(uVar8 < uVar3) + (uVar1 >> 0x10) + (uVar7 >> 0x10) * (uVar5 >> 0x10);
  if ((int)-(uint)((int)uVar6 < 0) < 0) {
    uVar7 = ~uVar7;
    if (uVar8 == 0) {
      uVar7 = uVar7 + 1;
    }
    else {
      uVar8 = ~uVar8 + 1;
    }
  }
  if (((byte)(in_sr >> 1) & 1) == 1) {
    if ((int)uVar7 < -0x8000) {
      uVar7 = 0xffff8000;
      uVar8 = 0;
    }
    if (0x7fff < (int)uVar7) {
      uVar7 = 0x7fff;
      uVar8 = 0xffffffff;
    }
    uVar7 = uVar7 & 0xffff;
  }
  uVar6 = param_2[1];
  uVar5 = param_1[1];
  uVar1 = uVar6 ^ uVar5;
  if ((int)uVar6 < 0) {
    uVar6 = -uVar6;
  }
  if ((int)uVar5 < 0) {
    uVar5 = -uVar5;
  }
  uVar10 = (uVar5 & 0xffff) * (uVar6 & 0xffff);
  iVar4 = (uVar5 >> 0x10) * (uVar6 & 0xffff);
  iVar2 = 0;
  uVar3 = iVar4 + (uVar5 & 0xffff) * (uVar6 >> 0x10);
  if (iVar4 != 0) {
    iVar2 = 0x10000;
  }
  uVar9 = uVar10 + uVar3 * 0x10000;
  uVar5 = iVar2 + (uint)(uVar9 < uVar10) + (uVar3 >> 0x10) + (uVar5 >> 0x10) * (uVar6 >> 0x10);
  if ((int)-(uint)((int)uVar1 < 0) < 0) {
    uVar5 = ~uVar5;
    if (uVar9 == 0) {
      uVar5 = uVar5 + 1;
    }
    else {
      uVar9 = ~uVar9 + 1;
    }
  }
  if (((byte)(in_sr >> 1) & 1) == 1) {
    uVar9 = uVar8 + uVar9;
    uVar7 = uVar5 + (uVar9 < uVar8) + (uVar7 & 0xffff);
    if ((int)uVar7 < -0x8000) {
      uVar7 = 0xffff8000;
      uVar9 = 0;
    }
    if (0x7fff < (int)uVar7) {
      uVar7 = 0x7fff;
      uVar9 = 0xffffffff;
    }
    uVar7 = uVar7 & 0xffff;
  }
  else {
    uVar9 = uVar8 + uVar9;
    uVar7 = uVar5 + (uVar9 < uVar8) + uVar7;
  }
  uVar6 = param_2[2];
  uVar5 = param_1[2];
  uVar1 = uVar6 ^ uVar5;
  if ((int)uVar6 < 0) {
    uVar6 = -uVar6;
  }
  if ((int)uVar5 < 0) {
    uVar5 = -uVar5;
  }
  uVar8 = (uVar5 & 0xffff) * (uVar6 & 0xffff);
  iVar4 = (uVar5 >> 0x10) * (uVar6 & 0xffff);
  iVar2 = 0;
  uVar3 = iVar4 + (uVar5 & 0xffff) * (uVar6 >> 0x10);
  if (iVar4 != 0) {
    iVar2 = 0x10000;
  }
  uVar10 = uVar8 + uVar3 * 0x10000;
  uVar5 = iVar2 + (uint)(uVar10 < uVar8) + (uVar3 >> 0x10) + (uVar5 >> 0x10) * (uVar6 >> 0x10);
  if ((int)-(uint)((int)uVar1 < 0) < 0) {
    uVar5 = ~uVar5;
    if (uVar10 == 0) {
      uVar5 = uVar5 + 1;
    }
    else {
      uVar10 = ~uVar10 + 1;
    }
  }
  if (((byte)(in_sr >> 1) & 1) == 1) {
    uVar10 = uVar9 + uVar10;
    uVar7 = uVar5 + (uVar10 < uVar9) + (uVar7 & 0xffff);
    if ((int)uVar7 < -0x8000) {
      uVar7 = 0xffff8000;
      uVar10 = 0;
    }
    if (0x7fff < (int)uVar7) {
      uVar7 = 0x7fff;
      uVar10 = 0xffffffff;
    }
    uVar7 = uVar7 & 0xffff;
  }
  else {
    uVar10 = uVar9 + uVar10;
    uVar7 = uVar5 + (uVar10 < uVar9) + uVar7;
  }
  return uVar7 << 0x10 | uVar10 >> 0x10;
}

