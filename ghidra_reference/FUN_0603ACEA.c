/* FUN_0603ACEA  0x0603ACEA */


int FUN_0603acea(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int local_10;
  
  iVar1 = (int)DAT_0603ad2c;
  *(int *)((int)&local_10 + iVar1) = param_2;
  if (param_2 == 0) {
    if (*(int *)(*(int *)PTR_DAT_0603ad38 + (int)DAT_0603ad2e) == 0) {
      iVar1 = (*(code *)PTR_FUN_0603ad3c)(param_1);
      if (iVar1 < 0) {
        iVar1 = FUN_0603b93c(0xffffffff);
      }
    }
    else {
      iVar1 = FUN_0603b93c(0xfffffff9);
    }
  }
  else {
    if (*(int *)(*(int *)PTR_DAT_0603ad38 + (int)DAT_0603adda) == 0) {
      iVar2 = (*(code *)PTR_FUN_0603ade0)
                        (param_1,*(undefined4 *)
                                  (*(int *)PTR_DAT_0603ad38 + (int)PTR_DAT_0603addc._0_2_));
    }
    else {
      iVar2 = (*(code *)PTR_FUN_0603ade4)
                        (param_1,*(undefined4 *)
                                  (*(int *)PTR_DAT_0603ad38 + (int)PTR_DAT_0603addc._0_2_));
    }
    if ((*(byte *)(iVar2 + 0xb) & 0x10) == 0) {
      iVar1 = FUN_0603b93c(0xfffffffa);
    }
    else {
      uVar3 = FUN_0603ba2c(&stack0xfffffff4 + iVar1,iVar2,param_1);
      uVar4 = (*(code *)PTR_FUN_0603ade8)
                        (uVar3,*(undefined4 *)((int)&local_10 + iVar1),*(undefined4 *)(iVar2 + 4));
      *(undefined4 *)((int)&local_10 + iVar1) = uVar4;
      FUN_0603b9d6(uVar3);
      FUN_0603b93c(0);
      iVar1 = *(int *)((int)&local_10 + iVar1);
    }
  }
  return iVar1;
}

