int FUN_06040c10(param_1, param_2)
    int param_1;
    int param_2;
{

  int iVar1;

  iVar1 = (*0x06041204)

                    (*(int *)(param_2 + 4),*(int *)(param_2 + 0x10),

                     *(int *)(param_1 + 0xc));

  if (iVar1 != 0) {

    return 0;

  }

  iVar1 = (*0x0604188C)();

  if (iVar1 != 0) {

    return 0;

  }

  return 1;

}
