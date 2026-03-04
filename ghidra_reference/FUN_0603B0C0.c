/* FUN_0603B0C0  0x0603B0C0 */


undefined4 FUN_0603b0c0(int *param_1)

{
  byte bVar1;
  int in_r0;
  undefined4 uVar2;
  
  bVar1 = *(byte *)(*param_1 + in_r0);
  FUN_0603b93c(0);
  if (((bVar1 & 8) != 0) && ((bVar1 & 4) != 0)) {
    return 0;
  }
  uVar2 = (*(code *)PTR_FUN_0603b114)();
  return uVar2;
}

