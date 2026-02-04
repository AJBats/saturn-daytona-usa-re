void FUN_0603fce4(param_1, param_2, param_3)
    int param_1;
    int param_2;
    int param_3;
{

  int iVar1;

  int uVar2;

  int iVar3;

  if (*(int *)(param_1 + 0x30) < 2) {

    iVar3 = *(int *)(*(int *)(param_1 + 4) + 8) - *(int *)(param_1 + 0x1c);

    iVar1 = (*(void(*)())0x0603F8EE)(param_3);

    if (iVar1 <= iVar3) {

      iVar3 = (*(void(*)())0x0603F8EE)(param_3);

    }

  }

  else {

    iVar3 = *(int *)(*(int *)(param_1 + 4) + 8);

  }

  uVar2 = (*(void(*)())0x0603F90E)(param_3,iVar3);

  *(int *)(param_1 + 0xc) = uVar2;

  return;

}
