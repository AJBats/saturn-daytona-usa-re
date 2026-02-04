void FUN_06027630(param_1, param_2, param_3)
    char *param_1;
    char *param_2;
    int param_3;
{

  int iVar2 = 0;

  param_3 -= 4;

  do {

    *(int *)(param_1 + iVar2) = *(int *)(param_2 + iVar2);

    iVar2 += 4;

  } while (param_3 > iVar2);

  return;

}
