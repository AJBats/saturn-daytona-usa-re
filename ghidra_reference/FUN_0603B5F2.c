/* FUN_0603B5F2  0x0603B5F2 */


undefined4 FUN_0603b5f2(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(*param_1 + 0x28);
  *(undefined4 *)(*param_1 + 0x28) = param_2;
  FUN_0603b93c(0);
  return uVar1;
}

