/* FUN_0603B6A8  0x0603B6A8 */


undefined4 FUN_0603b6a8(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (((*(int *)(*(int *)PTR_DAT_0603b724 + (int)DAT_0603b71c) != 0) && (-1 < param_1)) &&
     (param_1 < *(int *)(*(int *)PTR_DAT_0603b724 + (int)DAT_0603b71e))) {
    if (*(int *)((int)PTR_DAT_0603b720._0_2_ + *(int *)PTR_DAT_0603b724) == 1) {
      uVar1 = (*(code *)PTR_FUN_0603b728)
                        (param_1,*(undefined4 *)(*(int *)PTR_DAT_0603b724 + (int)DAT_0603b71c));
      (*(code *)PTR_FUN_0603b72c)(param_2,uVar1,0xc);
    }
    else {
      uVar1 = (*(code *)PTR_FUN_0603b730)
                        (param_1,*(undefined4 *)(*(int *)PTR_DAT_0603b724 + (int)DAT_0603b71c));
      (*(code *)PTR_FUN_0603b72c)(param_2,uVar1,0xc);
    }
    uVar1 = FUN_0603b93c(0);
    return uVar1;
  }
  return 0xfffffff6;
}

