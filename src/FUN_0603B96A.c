int FUN_0603b96a(param_1)
    int param_1;
{

  int iVar1;

  int iVar2;

  

  iVar2 = *(int *)0x060A4D14;

  for (iVar1 = 0;

      (iVar1 < *(int *)(iVar2 + 0x94) && (param_1 != *(int *)((iVar1 << 2) + iVar2 + 0x34)));

      iVar1 = iVar1 + 1) {

  }

  if (iVar1 == *(int *)(iVar2 + 0x94)) {

    iVar1 = -1;

  }

  return iVar1;

}
