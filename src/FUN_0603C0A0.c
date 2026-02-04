int FUN_0603c0a0(param_1, param_2)
    int param_1;
    int param_2;
{

  char *puVar1;

  

  puVar1 = 0xFFFFFF00;

  *(int *)0xFFFFFF00 = param_2;

  *(int *)(puVar1 + 0x10) = (int)(short)((unsigned int)param_1 >> 0x10);

  *(int *)(puVar1 + 0x14) = param_1 << 0x10;

  return *(int *)(puVar1 + 0x14);

}
