void FUN_060401f8(param_1, param_2)
    int param_1;
    int param_2;
{

  int iVar1;

  *(int *)(param_1 + 0x20) = param_2;

  iVar1 = (*0x060408B0)(*(int *)(param_1 + 0x18),0x7FFFFFFF,0);

  if (iVar1 < 0) {

    iVar1 = 0;

  }

  *(int *)(param_1 + 0x24) = iVar1 - *(int *)(*(int *)(param_1 + 0x18) + 0x10);

  return;

}
