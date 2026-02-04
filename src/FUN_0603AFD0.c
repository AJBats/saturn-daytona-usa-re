extern void FUN_0603b93c();

int FUN_0603afd0(param_1, param_2, param_3)
    int *param_1;
    int param_2;
    int param_3;
{

  int iVar1;

  int uVar2;

  int iVar3;

  iVar3 = *(int *)0x060A4D14 + 4 + (unsigned int)*(unsigned char *)(param_1 + 4) * 0x10;

  if (param_3 == 1) {

    iVar1 = (**(void **)(iVar3 + 0xc))(*param_1);

    param_2 = param_2 + iVar1;

  }

  else if (param_3 == 2) {

    param_2 = param_2 + *(int *)(*param_1 + 0x10);

  }

  else if (param_3 != 0) {

    uVar2 = FUN_0603b93c(0xfffffff3);

    return uVar2;

  }

  if (param_2 < 0) {

    uVar2 = FUN_0603b93c(0xfffffff1);

    return uVar2;

  }

  uVar2 = (**(void **)(iVar3 + 8))(*param_1,param_2);

  FUN_0603b93c(0);

  return uVar2;

}
