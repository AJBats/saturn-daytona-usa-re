/* FUN_0603AE74  0x0603AE74 */


int FUN_0603ae74(int param_1)

{
  int iVar1;
  
  if ((*(int *)(*(int *)PTR_DAT_0603aee0 + (int)DAT_0603aed8) == 0) ||
     (*(int *)((int)DAT_0603aeda + *(int *)PTR_DAT_0603aee0) != 1)) {
    FUN_0603b93c(0xfffffff8);
    return 0;
  }
  if ((-1 < param_1) && (param_1 < *(int *)(*(int *)PTR_DAT_0603aee0 + (int)PTR_DAT_0603aedc._0_2_))
     ) {
    iVar1 = (*(code *)PTR_FUN_0603aee4)
                      (param_1,*(undefined4 *)(*(int *)PTR_DAT_0603aee0 + (int)DAT_0603aed8));
    FUN_0603b93c(0);
    return iVar1 + 0xc;
  }
  FUN_0603b93c(0xfffffff7);
  return 0;
}

