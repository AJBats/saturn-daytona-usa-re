void FUN_0603fce4(param_1, param_2, param_3)
    int param_1;
    int param_2;
    int param_3;
{
  register int func1 asm("r3") = 0x0603F8EE;
  int iVar1;
  int iVar3;

  if (*(int *)(param_1 + 0x30) < 2) {
    iVar3 = *(int *)(*(int *)(param_1 + 4) + 8) - *(int *)(param_1 + 0x1c);
    iVar1 = (*(int(*)())func1)(param_3);
    if (iVar1 <= iVar3) {
      iVar3 = (*(int(*)())func1)(param_3);
    }
  } else {
    iVar3 = *(int *)(*(int *)(param_1 + 4) + 8);
  }

  *(int *)(param_1 + 0xc) = (*(int(*)())0x0603F90E)(param_3, iVar3);
}
