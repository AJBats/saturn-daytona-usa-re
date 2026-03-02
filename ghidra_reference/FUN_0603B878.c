int FUN_0603b878(param_1)
    int param_1;
{
  int iVar1;
  int iVar2;
  int *pp;

  pp = (int *)0x060A4D14;
  iVar2 = 0;
  iVar1 = *(int *)pp + 0x0C3C;
  goto check;
loop:
  if (iVar1 == param_1) goto done;
  iVar1 = iVar1 + 0x00F0;
  iVar2 = iVar2 + 1;
check:
  if (iVar2 < **(int **)pp) goto loop;
done:
  if (iVar2 == **(int **)pp) {
    iVar1 = 0;
  }
  return iVar1;
}
