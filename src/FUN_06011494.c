void FUN_06011494(param_1)
    unsigned short param_1;
{

  char *puVar1;

  

  puVar1 = 0x060447A8;

  *(int *)0x0607EADC = 0;

  *(int *)0x06078860 = *(int *)(puVar1 + ((unsigned int)param_1 << 4));

  return;

}
