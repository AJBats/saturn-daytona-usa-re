/* FUN_060333F4  0x060333F4 */


undefined4 FUN_060333f4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 in_pr;
  
  FUN_06033550();
  *(undefined2 *)PTR_DAT_0603345c = 8;
  FUN_06033648();
  FUN_06033470();
  if (('\0' < **(char **)PTR_PTR_06033460) || (**(int **)PTR_PTR_06033464 < 1)) {
    FUN_06033700(param_1,param_2,PTR_DAT_06033468,param_4,in_pr);
  }
  FUN_06033700(param_1,param_2,PTR_DAT_0603346c,param_4,in_pr);
  uVar1 = FUN_0603307c();
  return uVar1;
}

