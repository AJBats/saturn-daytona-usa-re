int FUN_0601e6a4(param_1)
    int param_1;
{

  char *puVar1;

  int iVar2;

  int iVar3;

  puVar1 = 0x06000354;

  iVar3 = 0;

  do {

    iVar2 = (*(int(*)())(*(int *)(*(int *)puVar1 + 8)))(param_1);

    if (iVar2 == 0) {

      return 0;

    }

    iVar3 = iVar3 + 1;

  } while (iVar3 < 10);

  return iVar2;

}
