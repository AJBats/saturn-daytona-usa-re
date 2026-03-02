int FUN_06040eec(param_1)
    int *param_1;
{
  int iVar1;

  iVar1 = 0;
  do {
    if (*(char *)(iVar1 + *(int *)0x060A5400) == '\0') {
      *(char *)(iVar1 + *(int *)0x060A5400) = 1;
      *param_1 = iVar1;
      return 0;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x18);
  *param_1 = -1;
  return -4;
}
