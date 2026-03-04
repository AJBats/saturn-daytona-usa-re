/* FUN_06041D74  0x06041D74 */


void FUN_06041d74(int *param_1)

{
  undefined *puVar1;
  ushort uVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  int unaff_r13;
  undefined1 local_10 [16];
  
  puVar1 = PTR_DAT_06041df4;
  iVar4 = 1;
  iVar5 = iVar4;
  if (*(int *)(*(int *)PTR_DAT_06041df4 + (int)DAT_06041dec) == 1) {
    if ((*(int *)(*(int *)PTR_DAT_06041df4 + (int)DAT_06041dee) == 0) &&
       (*(undefined **)(*(int *)PTR_DAT_06041df4 + (int)DAT_06041df0) == PTR_DAT_06041df8)) {
      iVar4 = (*(code *)PTR_FUN_06041dfc)
                        (0,*(undefined4 *)(*(int *)PTR_DAT_06041df4 + (int)DAT_06041df2));
      if (iVar4 != 0) {
        return;
      }
      (*(code *)PTR_FUN_06041e00)(local_10);
      *(undefined1 *)(*(int *)puVar1 + 0x40) = local_10[0];
      *param_1 = *param_1 + 1;
      *(undefined4 *)(*(int *)puVar1 + (int)DAT_06041dec) = 4;
    }
    else {
      iVar5 = unaff_r13;
      if (*(int *)(*(int *)PTR_DAT_06041df4 + (int)DAT_06041df0) != 0) {
        *(undefined4 *)(*(int *)PTR_DAT_06041df4 + (int)DAT_06041eb4) = 2;
        iVar5 = iVar4;
      }
    }
  }
  if (*(int *)((int)DAT_06041eb4 + *(int *)puVar1) == 2) {
    iVar4 = (int)DAT_06041eb6;
    iVar4 = (*(code *)PTR_FUN_06041ebc)
                      (*(undefined4 *)(*(int *)puVar1 + iVar4 + -8),
                       *(undefined4 *)(*(int *)puVar1 + iVar4 + -4),
                       *(undefined4 *)(*(int *)puVar1 + iVar4));
    *param_1 = *param_1 + 1;
    if (iVar4 == 0) {
      *(undefined4 *)(*(int *)puVar1 + (int)DAT_06041eb4) = 3;
      (*(code *)PTR_FUN_06041ec0)(local_10);
      *(undefined1 *)(*(int *)puVar1 + 0x40) = local_10[0];
    }
  }
  uVar3 = PTR_DAT_06041eb8._0_2_;
  if ((*(int *)((int)DAT_06041eb4 + *(int *)puVar1) == 3) &&
     (uVar2 = (*(code *)PTR_FUN_06041ec4)(), (uVar2 & uVar3) != 0)) {
    iVar5 = unaff_r13;
  }
  if ((*(int *)((int)DAT_06041eb4 + *(int *)puVar1) == 4) &&
     (uVar3 = (*(code *)PTR_FUN_06041ec4)(), (uVar3 & 0x40) != 0)) {
    iVar5 = unaff_r13;
  }
  if (iVar5 != 1) {
    (*(code *)PTR_FUN_06041f9c)(PTR_DAT_06041f98);
    *(int *)(*(int *)puVar1 + (int)DAT_06041f90) = unaff_r13;
    *(int *)(*(int *)puVar1 + 0x34) = unaff_r13;
  }
  return;
}

