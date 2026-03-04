/* FUN_0601ABC8  0x0601ABC8 */


int FUN_0601abc8(undefined4 param_1)

{
  int iVar1;
  
  *PTR_DAT_0601ac30 = (char)param_1;
  *PTR_DAT_0601ac34 = (char)param_1;
  *(undefined4 *)PTR_DAT_0601ac38 = param_1;
  *(undefined4 *)PTR_DAT_0601ac3c = param_1;
  FUN_0601adb0();
  if ((*(int *)PTR_DAT_0601ac40 <
       *(int *)(*(int *)(PTR_PTR_0601ac28 + *(int *)PTR_DAT_0601ac14 * 8) + 4)) &&
     (0 < *(int *)PTR_DAT_0601ac40)) {
    *PTR_DAT_0601ac34 = 1;
  }
  if (*(int *)PTR_DAT_0601ac44 == 0) {
    return 0;
  }
  iVar1 = (int)PTR_DAT_0601ace4._0_2_;
  if (*(uint *)PTR_DAT_0601acf4 <
      *(uint *)(*(int *)(PTR_PTR_0601acf0 +
                        (*(int *)PTR_DAT_0601ace8 * 6 + *(int *)PTR_DAT_0601acec * 2) * 4) + iVar1))
  {
    *PTR_DAT_0601acf8 = 1;
  }
  return iVar1;
}

