void FUN_06035f16(param_1, param_2)
    char *param_1;
    char *param_2;
{

  *param_2 = *param_1;

  param_2[4] = param_1[1];

  param_2[5] = param_1[2];

  param_2[6] = param_1[3];

  param_2[7] = param_1[4];

  *(unsigned int *)(param_2 + 8) = *(unsigned int *)(param_1 + 4) & 0x00FFFFFF;

  return;

}
