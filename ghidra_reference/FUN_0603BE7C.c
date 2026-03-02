void FUN_0603be7c(param_1, param_2)
    int param_1;
    int param_2;
{

  if ((*(unsigned char *)(param_1 + 0x1d) & 0x60) == 0) {

    (*(int(*)())0x060401F8)();

    return;

  }

  *(int *)(param_1 + 0x20) = param_2;

  *(int *)(param_1 + 0x24) = 0;

  return;

}
