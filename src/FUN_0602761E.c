void FUN_0602761e(param_1, param_2, param_3)
    char *param_1;
    char *param_2;
    int param_3;
{

  int iVar2 = 0;

  param_3 -= 2;

  do {

    *(short *)(param_1 + iVar2) = *(short *)(param_2 + iVar2);

    iVar2 += 2;

  } while (param_3 > iVar2);

  return;

}
