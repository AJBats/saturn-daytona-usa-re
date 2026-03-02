void FUN_0603f92c(param_1, param_2, param_3)
    int param_1;
    int param_2;
    int *param_3;
{

  *(int *)(param_1 + 0x20) = param_2;

  *(int *)(param_1 + 0x24) = *param_3;

  *(int *)(param_1 + 0x28) = param_3[1];

  *(int *)(param_1 + 0x2c) = param_3[2];

  return;

}
