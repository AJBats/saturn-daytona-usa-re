extern int FUN_0603b96a();


int FUN_0603b9a4(param_1)
    int param_1;
{

  int iVar1;

  int iVar2;

  

  iVar1 = FUN_0603b96a();

  if (iVar1 == -1) {

    iVar2 = *(int *)0x060A4D14;

    *(int *)((*(int *)(iVar2 + 0x94) << 2) + iVar2 + 0x34) = param_1;

    iVar1 = 0x60;

    *(int *)(iVar2 + 0x94) = *(int *)(iVar2 + 0x94) + 1;

  }

  return iVar1;

}
