void FUN_0603f3da(param_1, param_2)
    int *param_1;
    int *param_2;
{

  *param_1 = param_2;

  param_1[1] = 0x043C + *(int *)0x060A4D14;

  param_1[2] = 0xffffffff;

  param_1[4] = *(int *)(*param_2 + 0x10);

  param_1[3] = 0;

  return;

}
