void FUN_060280c4(param_1, param_2)
    int param_1;
    short *param_2;
{

  short *puVar1;

  puVar1 = 0x060280F4 + 1;

  *param_2 = *(int *)0x060280F4;

  param_2[2] = *puVar1;

  param_2[3] = *(short *)(param_1 + 6);

  *(int *)(param_2 + 6) = *(int *)(param_1 + 8);

  *(int *)(param_2 + 8) = *(int *)(param_1 + 0xc);

  *(int *)(param_2 + 10) = *(int *)(param_1 + 0x10);

  *(int *)(param_2 + 0xc) = *(int *)(param_1 + 0x14);

  return;

}
