void FUN_0600511e(param_1, param_2, param_3, param_4)
    int param_1;
    int param_2;
    int param_3;
    unsigned int param_4;
{

  char *puVar1;

  puVar1 = 0x25E20000;

  if ((param_4 & 3) == 0) {

    puVar1 = 0x25E00000;

  }

  if ((param_4 & 8) == 0) {

    (*(int(*)())0x06027630)(puVar1 + param_2,param_1,param_3);

    return;

  }

  (*(int(*)())0x06028654)(param_1,puVar1 + param_2);

  return;

}
