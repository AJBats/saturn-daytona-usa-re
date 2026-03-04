/* FUN_06030548  0x06030548 */


void FUN_06030548(void)

{
  undefined *puVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  short sVar6;
  int iVar5;
  uint uVar7;
  undefined *puVar8;
  byte bVar9;
  undefined4 uVar10;
  int *unaff_r14;
  int iVar11;
  
  iVar11 = *unaff_r14;
  puVar2 = (uint *)(DAT_0603056a + iVar11);
  uVar4 = puVar2[2];
  if ((((int)PTR_DAT_0603056c._0_2_ & (*puVar2 | puVar2[1] | uVar4 | puVar2[3])) != 0) &&
     (uVar7 = puVar2[3] & uVar4 & puVar2[1] & *puVar2, ((int)DAT_06030588 & uVar7) == 0)) {
    if (((int)PTR_DAT_06030598._0_2_ & uVar7) != 0) {
      FUN_06030a9c(0,uVar4,*(undefined4 *)(PTR_DAT_0603059c + 0x10));
      return;
    }
    if (((int)DAT_060305ae & uVar7) == 0) {
      uVar4 = (uint)DAT_06030602;
      bVar9 = (uVar4 & *puVar2) != 0;
      if ((uVar4 & puVar2[1]) != 0) {
        bVar9 = bVar9 + 2;
      }
      if ((uVar4 & puVar2[2]) != 0) {
        bVar9 = bVar9 + 4;
      }
      if ((uVar4 & puVar2[3]) != 0) {
        bVar9 = bVar9 + 8;
      }
      *(undefined4 *)(DAT_06030604 + iVar11) = 8;
      puVar1 = PTR_DAT_06030684;
      puVar8 = PTR_DAT_0603063c;
      if (bVar9 == 3) {
        iVar3 = (int)DAT_06030680;
        uVar4 = (*(int *)(iVar11 + 0x30) + 0x8000) - (*(int *)(PTR_DAT_06030684 + 0x10) + iVar3);
        sVar6 = (short)*(undefined4 *)(PTR_DAT_06030684 + 0x10);
        if ((int)uVar4 < 0) {
          uVar4 = -uVar4;
        }
        if ((iVar3 <= (int)(uVar4 & 0xffff)) && ((int)(uVar4 & 0xffff) <= iVar3 * 3)) {
          sVar6 = sVar6 + DAT_06030680 * 2;
        }
        *(short *)PTR_DAT_06030688 = sVar6 + DAT_06030680;
        FUN_06030b68(0,*(undefined4 *)(puVar1 + 0x10));
        return;
      }
      if (bVar9 == 0xc) {
        iVar3 = (int)DAT_0603063a;
        uVar4 = *(int *)(iVar11 + 0x30) - (*(int *)(PTR_DAT_0603063c + 0x10) + iVar3);
        sVar6 = (short)*(undefined4 *)(PTR_DAT_0603063c + 0x10);
        if ((int)uVar4 < 0) {
          uVar4 = -uVar4;
        }
        if ((iVar3 <= (int)(uVar4 & 0xffff)) && ((int)(uVar4 & 0xffff) <= iVar3 * 3)) {
          sVar6 = sVar6 + DAT_0603063a * 2;
        }
        *(short *)PTR_DAT_06030640 = sVar6 + DAT_0603063a;
        FUN_06030b68(2,*(undefined4 *)(puVar8 + 0x10));
        return;
      }
      if (((bVar9 & 5) != 5) && (((bVar9 & 5) == 0 || ((bVar9 & 10) != 0)))) {
        uVar10 = 1;
        puVar8 = PTR_DAT_060306cc;
        if ((bVar9 & 2) == 0) {
          uVar10 = 3;
          puVar8 = PTR_DAT_060306d0;
        }
        iVar3 = (int)DAT_060306c8;
        iVar5 = *(int *)(puVar8 + 0x10);
        uVar4 = *(int *)(iVar11 + 0x30) - iVar5;
        if ((int)uVar4 < 0) {
          uVar4 = -uVar4;
        }
        if ((iVar3 <= (int)(uVar4 & 0xffff)) && ((int)(uVar4 & 0xffff) <= iVar3 * 3)) {
          iVar5 = iVar5 + iVar3 * 2;
        }
        *(short *)PTR_DAT_060306d4 = (short)iVar5 + DAT_060306c8;
        FUN_06030b68(uVar10,*(undefined4 *)(puVar8 + 0x10));
        return;
      }
      uVar10 = 0;
      puVar8 = PTR_DAT_06030718;
      if ((bVar9 & 1) == 0) {
        uVar10 = 2;
        puVar8 = PTR_DAT_0603071c;
      }
      iVar3 = (int)DAT_06030714;
      iVar5 = *(int *)(puVar8 + 0x10);
      uVar4 = *(int *)(iVar11 + 0x30) - iVar5;
      if ((int)uVar4 < 0) {
        uVar4 = -uVar4;
      }
      if ((iVar3 <= (int)(uVar4 & 0xffff)) && ((int)(uVar4 & 0xffff) <= iVar3 * 3)) {
        iVar5 = iVar5 + iVar3 * 2;
      }
      *(short *)PTR_DAT_06030720 = (short)iVar5 + DAT_06030716;
      FUN_06030b68(uVar10,*(undefined4 *)(puVar8 + 0x10));
      return;
    }
    *(undefined2 *)(iVar11 + DAT_060305b0) = 0xf;
  }
  return;
}

