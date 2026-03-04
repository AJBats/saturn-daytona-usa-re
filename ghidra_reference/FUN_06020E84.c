/* FUN_06020E84  0x06020E84 */


int FUN_06020e84(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  uint uVar5;
  byte bVar6;
  int iVar7;
  int iVar8;
  int unaff_r8;
  int iVar9;
  int iVar10;
  
  puVar4 = PTR_DAT_06020f40;
  puVar3 = PTR_DAT_06020f3c;
  puVar2 = PTR_DAT_06020f38;
  puVar1 = PTR_DAT_06020f34;
  if (*PTR_DAT_06020f40 != '\0') {
    *PTR_DAT_06020f34 = 10;
    *puVar4 = 0;
  }
  if (*puVar1 != '\0') {
    *puVar1 = *puVar1 + -1;
  }
  if ((*(int *)(*(int *)PTR_DAT_06020f44 + (int)DAT_06020f2e) != *(int *)PTR_DAT_06020f48) &&
     (*PTR_DAT_06020f4c == '\0')) {
    iVar9 = (int)DAT_06020f30;
    uVar5 = *(uint *)((int)DAT_06020f2e + *(int *)PTR_DAT_06020f44) & 0xcc;
    if (uVar5 == 0) {
      (*(code *)PTR_FUN_06020fcc)
                (4,*(undefined4 *)(PTR_DAT_06020f50 + 0x48),iVar9,
                 *(undefined4 *)(PTR_DAT_06020f50 + 0x4c));
    }
    else if (uVar5 == 0x44) {
      if (*puVar2 == '\0') {
        iVar7 = 10;
      }
      else {
        iVar7 = 0xb;
      }
      if (*puVar2 == '\0') {
        iVar8 = 10;
      }
      else {
        iVar8 = 0xb;
      }
      (*(code *)PTR_FUN_06020fcc)
                (4,*(undefined4 *)(PTR_DAT_06020f50 + iVar8 * 8),iVar9,
                 *(undefined4 *)(PTR_DAT_06020f50 + iVar7 * 8 + 4));
    }
    else if (uVar5 == (int)DAT_06020fc6) {
      if (*puVar2 == '\0') {
        iVar7 = 0xb;
      }
      else {
        iVar7 = 10;
      }
      if (*puVar2 == '\0') {
        iVar8 = 0xb;
      }
      else {
        iVar8 = 10;
      }
      (*(code *)PTR_FUN_06020f54)
                (4,*(undefined4 *)(PTR_DAT_06020f50 + iVar8 * 8),iVar9,
                 *(undefined4 *)(PTR_DAT_06020f50 + iVar7 * 8 + 4));
    }
    else if (uVar5 == (int)DAT_06020fc8) {
      (*(code *)PTR_FUN_06020f54)
                (4,*(undefined4 *)(PTR_DAT_06020f50 + 0x60),iVar9,
                 *(undefined4 *)(PTR_DAT_06020f50 + 100));
    }
  }
  *(undefined4 *)PTR_DAT_06020fd4 = *(undefined4 *)(*(int *)PTR_DAT_06020fd0 + (int)DAT_06020fca);
  if (*(int *)PTR_DAT_06020fd8 != 1) {
    return *(int *)PTR_DAT_06020fd8;
  }
  iVar10 = 0;
  iVar7 = 0;
  iVar9 = *(int *)(*(int *)PTR_DAT_060210a4 + 0x60) >> 0xe;
  iVar8 = *(int *)(PTR_DAT_060210a0 + (uint)(byte)*puVar1 * 4);
  if (*puVar2 != '\0') {
    iVar9 = -iVar9;
  }
  if ((iVar9 < DAT_06021098) && (DAT_0602109a < iVar9)) {
    iVar9 = 0;
  }
  *(undefined4 *)(puVar3 + DAT_0602109c) = 0;
  bVar6 = 0;
  do {
    iVar10 = iVar10 + iVar9;
    iVar7 = iVar7 - iVar9;
    uVar5 = (uint)bVar6;
    *(int *)(puVar3 + (unaff_r8 - (uint)bVar6) * 4 + (int)DAT_0602109e) = iVar10 + iVar8;
    bVar6 = bVar6 + 1;
    *(int *)(puVar3 + uVar5 * 4 + (int)DAT_0602109e + 0x58) = iVar7 + iVar8;
  } while (bVar6 < 0x16);
  (*(code *)PTR_FUN_060210a8)(8);
  (*(code *)PTR_FUN_060210b0)(PTR_DAT_060210ac);
  iVar9 = (*(code *)PTR_FUN_060210b4)();
  return iVar9;
}

