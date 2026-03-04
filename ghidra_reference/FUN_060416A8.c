/* FUN_060416A8  0x060416A8 */


undefined4 FUN_060416a8(void)

{
  undefined *puVar1;
  undefined4 uVar2;
  short sVar4;
  int iVar3;
  int iVar5;
  int unaff_r10;
  int unaff_r11;
  int iVar6;
  int local_18;
  uint uStack_14;
  undefined1 auStack_10 [16];
  
  puVar1 = PTR_DAT_06041730;
  local_18 = 0;
  iVar6 = 0;
  if ((*(int *)(*(int *)PTR_DAT_06041730 + 0x3c) == 0) ||
     (iVar5 = *(int *)(*(int *)PTR_DAT_06041730 + 0x3c) + -1,
     *(int *)(*(int *)PTR_DAT_06041730 + 0x3c) = iVar5, 0 < iVar5)) {
    uStack_14 = (uint)PTR_DAT_0604172a._0_2_;
    sVar4 = (*(code *)PTR_FUN_06041734)();
    if (((int)sVar4 & uStack_14) == 0) {
      iVar5 = (*(code *)PTR_FUN_060417e4)(auStack_10);
      if (iVar5 == 0) {
        (*(code *)PTR_FUN_060417e8)();
      }
    }
    else {
      (*(code *)PTR_FUN_0604173c)(PTR_DAT_06041738);
      (*(code *)PTR_FUN_06041740)(auStack_10);
      (*(code *)PTR_FUN_06041744)();
      if (*(int *)(*(int *)puVar1 + 0x4c) != 0) {
        iVar5 = *(int *)puVar1;
        (**(code **)(iVar5 + 0x4c))(*(undefined4 *)(iVar5 + 0x50));
      }
    }
    for (iVar5 = 0; iVar5 < unaff_r11; iVar5 = iVar5 + 1) {
      iVar3 = FUN_060417a8(iVar5);
      if (iVar3 == 0) {
        iVar3 = FUN_06041826(iVar5,&local_18);
        iVar6 = iVar6 + iVar3;
        if (unaff_r10 < local_18) {
          return 1;
        }
      }
    }
    if (iVar6 < 1) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  else {
    FUN_0604231e();
    uVar2 = 3;
  }
  return uVar2;
}

