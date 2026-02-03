void FUN_060054ea(param_1)
    int param_1;
{

  char *puVar1;

  

  *(int *)0x06063E04 = param_1;

  *(short *)0x06063E08 = 0;

  puVar1 = 0x06063F08;

  *(int *)0x06063F08 = 0;

  *(int *)0x06063F04 = *(int *)puVar1;

  return;

}
