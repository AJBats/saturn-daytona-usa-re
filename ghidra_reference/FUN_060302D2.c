/* FUN_060302D2  0x060302D2 */


void FUN_060302d2(void)

{
  ushort uVar1;
  undefined *puVar2;
  int iVar3;
  uint uVar4;
  short sVar6;
  int iVar5;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  byte bVar10;
  
  puVar2 = PTR_DAT_060304b8;
  iVar3 = *(int *)PTR_DAT_060302f0;
  if (*(short *)PTR_DAT_060302f4 != 0) {
    iVar8 = *(int *)PTR_DAT_060304b8;
    bVar10 = PTR_DAT_060304b4[iVar8];
    *(ushort *)(DAT_060304ac + iVar3) = bVar10 & 3;
    *(int *)puVar2 = iVar8 + 2;
    uVar7 = 1;
    if ((bVar10 & 0x80) == 0) {
      uVar7 = 0x38;
      iVar8 = *(int *)(DAT_060304f0 + iVar3) + -2;
      if (iVar8 < 0x38) {
        iVar8 = 0x38;
      }
      *(int *)(DAT_060304f0 + iVar3) = iVar8;
      *(undefined4 *)(DAT_060304f4 + iVar3) = 0;
    }
    else {
      iVar8 = (int)DAT_060304ae;
      *(undefined4 *)(iVar8 + iVar3) = 1;
      iVar8 = iVar8 + 8;
      iVar5 = *(int *)(iVar8 + iVar3);
      if (iVar5 <= PTR_DAT_060304b0._0_2_) {
        iVar5 = iVar5 + 4;
      }
      *(int *)(iVar8 + iVar3) = iVar5;
    }
    if ((bVar10 & 0x40) == 0) {
      iVar8 = *(int *)(DAT_06030530 + iVar3);
      *(int *)(DAT_06030534 + iVar3) = iVar8;
      iVar8 = iVar8 + -5;
      if (iVar8 < 0x38) {
        iVar8 = 0x38;
      }
      *(int *)(DAT_06030530 + iVar3) = iVar8;
      *(undefined4 *)(DAT_06030538 + iVar3) = 0;
    }
    else {
      *(undefined4 *)(DAT_060304f8 + iVar3) = uVar7;
      iVar8 = DAT_060304fc;
      iVar5 = *(int *)(DAT_060304fc + iVar3);
      iVar9 = (int)DAT_060304f2;
      *(int *)(DAT_06030500 + iVar3) = iVar5;
      if (iVar5 <= iVar9) {
        iVar5 = iVar5 + 5;
      }
      *(int *)(iVar8 + iVar3) = iVar5;
    }
    return;
  }
  uVar4 = (uint)*(ushort *)PTR_DAT_0603031c;
  iVar8 = (int)PTR_DAT_06030318._0_2_;
  if (*(short *)PTR_DAT_06030320 < 1) {
    if ((uVar4 & (int)*(short *)PTR_DAT_06030350) == 0) {
      if ((uVar4 & (int)*(short *)PTR_DAT_06030364) == 0) {
        if ((uVar4 & (int)*(short *)PTR_DAT_06030378) == 0) {
          if ((uVar4 & (int)*(short *)PTR_DAT_060303bc) != 0) {
            *(undefined2 *)(iVar8 + iVar3) = 0;
          }
        }
        else {
          *(undefined2 *)(iVar8 + iVar3) = 1;
        }
      }
      else {
        *(undefined2 *)(iVar8 + iVar3) = 2;
      }
    }
    else {
      *(undefined2 *)(iVar8 + iVar3) = 3;
    }
  }
  else if ((uVar4 & (int)*(short *)PTR_DAT_06030320) == 0) {
    if ((uVar4 & (int)*(short *)PTR_DAT_0603033c) != 0) {
      sVar6 = *(short *)(iVar8 + iVar3);
      if (sVar6 != 3) {
        sVar6 = sVar6 + 1;
      }
      *(short *)(iVar8 + iVar3) = sVar6;
    }
  }
  else {
    sVar6 = *(short *)(iVar8 + iVar3);
    if (sVar6 != 0) {
      sVar6 = sVar6 + -1;
    }
    *(short *)(iVar8 + iVar3) = sVar6;
  }
  bVar10 = (byte)*(undefined2 *)(iVar8 + iVar3);
  uVar1 = *(ushort *)PTR_DAT_060303c0;
  uVar7 = 1;
  if ((uVar1 & *(ushort *)PTR_DAT_060303c4) == 0) {
    uVar7 = 0x38;
    iVar8 = *(int *)(DAT_06030402 + iVar3) + -2;
    if (iVar8 < 0x39) {
      iVar8 = 0x38;
    }
    *(int *)(DAT_06030402 + iVar3) = iVar8;
    *(undefined4 *)(DAT_06030408 + iVar3) = 0;
  }
  else {
    bVar10 = bVar10 | 0x80;
    iVar8 = (int)DAT_060303b6;
    *(undefined4 *)(iVar8 + iVar3) = 1;
    iVar8 = iVar8 + 8;
    iVar5 = *(int *)(iVar8 + iVar3);
    if (iVar5 <= PTR_DAT_060303b8._0_2_) {
      iVar5 = iVar5 + 4;
    }
    *(int *)(iVar8 + iVar3) = iVar5;
  }
  if ((uVar1 & *(ushort *)PTR_DAT_0603040c) == 0) {
    iVar8 = *(int *)(DAT_06030460 + iVar3);
    *(int *)(DAT_06030464 + iVar3) = iVar8;
    iVar8 = iVar8 + -5;
    if (iVar8 < 0x38) {
      iVar8 = 0x38;
    }
    *(int *)(DAT_06030460 + iVar3) = iVar8;
    *(undefined4 *)(DAT_06030468 + iVar3) = 0;
  }
  else {
    bVar10 = bVar10 | 0x40;
    *(undefined4 *)(DAT_06030410 + iVar3) = uVar7;
    iVar8 = DAT_06030414;
    iVar5 = *(int *)(DAT_06030414 + iVar3);
    iVar9 = (int)PTR_DAT_06030404._0_2_;
    *(int *)(DAT_06030418 + iVar3) = iVar5;
    if (iVar5 <= iVar9) {
      iVar5 = iVar5 + 5;
    }
    *(int *)(iVar8 + iVar3) = iVar5;
  }
  puVar2 = PTR_DAT_06030470;
  iVar8 = *(int *)PTR_DAT_06030470;
  PTR_DAT_0603046c[iVar8] = bVar10;
  iVar3 = iVar8 + 2;
  if ((int)DAT_0603045e <= iVar8 + 2) {
    iVar3 = iVar8;
  }
  *(int *)puVar2 = iVar3;
  return;
}

