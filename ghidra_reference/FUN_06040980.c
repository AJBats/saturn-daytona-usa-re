/* FUN_06040980  0x06040980 */


void FUN_06040980(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int unaff_r14;
  
  *(undefined4 *)(unaff_r14 + 0x20) = param_2;
  (*(code *)PTR_FUN_060409b4)();
  iVar1 = (*(code *)PTR_FUN_060409b8)(*(undefined4 *)(unaff_r14 + 0x14));
  if (iVar1 != 0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x060409ac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_FUN_060409bc)();
  return;
}

