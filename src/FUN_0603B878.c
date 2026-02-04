int FUN_0603b878(param_1)
    int param_1;
{

  int iVar1;

  int iVar2;



  iVar2 = 0;

  for (iVar1 = *(int *)0x060A4D14 + 0x0C3C;

      (iVar2 < **(int **)0x060A4D14 && (iVar1 != param_1)); iVar1 = iVar1 + 0x00F0) {

    iVar2 = iVar2 + 1;

  }

  if (iVar2 == **(int **)0x060A4D14) {

    iVar1 = 0;

  }

  return iVar1;

}
