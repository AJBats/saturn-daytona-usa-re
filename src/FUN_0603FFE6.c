void FUN_0603ffe6(param_1, param_2, param_3)
    int param_1;
    char *param_2;
    int *param_3;
{

  char *puVar1;

  int iVar2;

  int local_4;

  

  if (0 < param_1) {

    local_4 = *param_3;

    iVar2 = 0;

    if (0 < param_1) {

      do {

        puVar1 = (char *)((int)&local_4 + iVar2);

        iVar2 = iVar2 + 1;

        *param_2 = *puVar1;

        param_2 = param_2 + 1;

      } while (iVar2 < param_1);

    }

  }

  return;

}
