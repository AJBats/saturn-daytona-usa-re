void FUN_0603fc60(param_1, param_2, param_3)
    int param_1;
    int param_2;
    int param_3;
{

  int iVar1;

  int iVar2;

  iVar2 = *(int *)(param_1 + 0x14) - *(int *)(param_1 + 0x18);

  if (*(int *)(param_1 + 0x10) < iVar2) {

    iVar2 = *(int *)(param_1 + 0x10);

  }

  iVar1 = iVar2;

  if (1 < *(int *)(param_1 + 0x30)) {

    if (*(int *)(param_1 + 4) != 0) {

      iVar2 = (*0x06034FFC)();

    }

    (*0x0603F8EE)(param_3);

    iVar1 = (*0x06034FFC)();

    if (iVar2 < iVar1) {

      iVar1 = iVar2;

    }

  }

  if (*(int *)(param_1 + 4) == 0) {

    iVar2 = (*0x0603F900)(param_2,iVar1);

    *(int *)(param_1 + 4) = iVar2;

    if (iVar2 != 0) {

      *(int *)(param_1 + 0x1c) = 0;

    }

  }

  return;

}
