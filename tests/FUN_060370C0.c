void FUN_060370c0(param_1)
    int *param_1;
{

  *param_1 = 0;

  param_1[1] = 0;

  *(char *)(param_1 + 2) = 0;

  *(char *)((int)param_1 + 9) = 0;

  *(char *)((int)param_1 + 10) = 0;

  *(char *)((int)param_1 + 0xb) = 0;

  *(char *)(param_1 + 3) = 0;

  *(char *)((int)param_1 + 0xd) = 0;

  *(char *)((int)param_1 + 0xe) = 0;

  return;

}
