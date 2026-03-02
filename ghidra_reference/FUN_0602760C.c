void FUN_0602760c(param_1, param_2, param_3)
    char *param_1;
    char *param_2;
    int param_3;
{

  int iVar2 = 0;

  param_3--;

  do {

    *(char *)(param_1 + iVar2) = *(char *)(param_2 + iVar2);

    iVar2++;

  } while (param_3 > iVar2);

  return;

}
