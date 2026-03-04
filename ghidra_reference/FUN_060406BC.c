/* FUN_060406BC  0x060406BC */


undefined4 FUN_060406bc(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_r13;
  undefined4 local_c;
  int local_8;
  
  iVar1 = FUN_06040666();
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    iVar1 = (*(code *)PTR_FUN_060406e4)();
    if (iVar1 < 0) {
      uVar2 = 0;
    }
    else {
      local_c = 1;
      local_8 = FUN_06040722();
      local_8 = local_8 + *(int *)(unaff_r13 + 4);
      (*(code *)PTR_FUN_0604076c)(&local_c,iVar1,param_3,param_4,param_2);
      (*(code *)PTR_FUN_06040770)(iVar1);
      uVar2 = 1;
    }
  }
  return uVar2;
}

