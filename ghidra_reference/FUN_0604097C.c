/* FUN_0604097C  0x0604097C */


void FUN_0604097c(int param_1,undefined4 param_2)

{
  int iVar1;
  
  *(undefined4 *)(param_1 + 0x20) = param_2;
  (*(code *)PTR_FUN_060409b4)();
  iVar1 = (*(code *)PTR_FUN_060409b8)(*(undefined4 *)(param_1 + 0x14));
  if (iVar1 != 0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x060409ac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_FUN_060409bc)();
  return;
}

