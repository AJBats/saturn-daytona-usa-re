/* FUN_0603F9FA  0x0603F9FA */


undefined4 FUN_0603f9fa(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(param_1 + 0x10) = param_2;
  return uVar1;
}

