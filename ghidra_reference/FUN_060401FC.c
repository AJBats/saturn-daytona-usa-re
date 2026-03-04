/* FUN_060401FC  0x060401FC */


void FUN_060401fc(int param_1,undefined4 param_2)

{
  int iVar1;
  
  *(undefined4 *)(param_1 + 0x20) = param_2;
  iVar1 = (*(code *)PTR_FUN_06040240)(*(undefined4 *)(param_1 + 0x18),DAT_0604023c);
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  *(int *)(param_1 + 0x24) = iVar1 - *(int *)(*(int *)(param_1 + 0x18) + 0x10);
  return;
}

