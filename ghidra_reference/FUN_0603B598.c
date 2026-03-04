/* FUN_0603B598  0x0603B598 */


undefined4 FUN_0603b598(int *param_1,undefined1 param_2)

{
  undefined4 uStack_8;
  
  if ((*(byte *)(*param_1 + 0x1d) & 0x60) == 0) {
    uStack_8 = (*(code *)PTR_FUN_0603b5cc)(*(undefined4 *)(*param_1 + 0x18),param_2);
  }
  FUN_0603b93c(0);
  return uStack_8;
}

