/* FUN_0603B5D0  0x0603B5D0 */


undefined4 FUN_0603b5d0(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + 0xc) = param_2;
  uVar1 = (*(code *)PTR_FUN_0603b628)(*(undefined4 *)(param_1 + 8));
  FUN_0603b93c(0);
  return uVar1;
}

