/* FUN_0603B630  0x0603B630 */


void FUN_0603b630(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((*(byte *)(*param_1 + 0x1d) & 0x60) == 0) {
    uVar1 = FUN_0603b058(param_1);
    iVar2 = (*(code *)PTR_FUN_0603b69c)(*param_1,uVar1);
    if (iVar2 == 0) {
      FUN_0603b93c(0xffffffec);
      return;
    }
    *(int **)(*(int *)PTR_DAT_0603b6a0 + (int)DAT_0603b698) = param_1;
  }
  FUN_0603b93c(0);
  return;
}

