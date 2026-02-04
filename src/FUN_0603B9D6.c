extern int FUN_0603b96a();

void FUN_0603b9d6(param_1)
    int param_1;
{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  if (param_1 != 0) {

    iVar2 = FUN_0603b96a();

    if (iVar2 != -1) {

      iVar5 = *(int *)0x060A4D14;

      iVar3 = *(int *)(iVar5 + 0x94) + -1;

      *(int *)(iVar5 + 0x94) = iVar3;

      iVar4 = iVar2 << 2;

      iVar1 = (iVar2 + 1) << 2;

      for (; iVar2 < iVar3; iVar2 = iVar2 + 1) {

        *(int *)(iVar5 + 0x34 + iVar4) = *(int *)(iVar1 + iVar5 + 0x34);

        iVar4 = iVar4 + 4;

        iVar1 = iVar1 + 4;

      }

    }

    return;

  }

  return;

}
