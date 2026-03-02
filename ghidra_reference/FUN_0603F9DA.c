void FUN_0603f9da(param_1, param_2)
    int param_1;
    int param_2;
{

  *(int *)(param_1 + 0x14) = param_2;

  *(int *)(param_1 + 0x18) = 0;

  *(unsigned char *)(param_1 + 0x34) = *(unsigned char *)(param_1 + 0x34) & 0x80;

  return;

}
