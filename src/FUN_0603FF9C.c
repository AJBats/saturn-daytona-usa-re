void FUN_0603ff9c(param_1)
    int param_1;
{

  int iVar1;

  int *puVar2;

  int iVar3;

  puVar2 = *(int **)(param_1 + 0xc);

  iVar1 = (*(int **)(param_1 + 4))[1];

  iVar3 = puVar2[2];

  (**(void **)(param_1 + 0x28))

            (*(int *)(param_1 + 0x20),*puVar2,puVar2[1],

             iVar1 * *(int *)(param_1 + 0x1c) + **(int **)(param_1 + 4),iVar1,iVar3);

  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + iVar3;

  return;

}
