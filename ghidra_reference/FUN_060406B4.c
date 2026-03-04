/* FUN_060406B4  0x060406B4 */


undefined4 FUN_060406b4(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uStack_18;
  int iStack_14;
  
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
      uStack_18 = 1;
      iStack_14 = FUN_06040722(param_1,param_2);
      iStack_14 = iStack_14 + *(int *)(param_1 + 4);
      (*(code *)PTR_FUN_0604076c)(&uStack_18,iVar1);
      (*(code *)PTR_FUN_06040770)(iVar1);
      uVar2 = 1;
    }
  }
  return uVar2;
}

