void FUN_06036e90(param_1, param_2, param_3)
    unsigned int param_1;
    unsigned short param_2;
    int param_3;
{

  char *puVar1;

  puVar1 = 0x060A3DF8;

  if ((param_2 == 1) || (param_2 == *(unsigned short *)0x060635B0)) {

    param_1 = param_1 & (unsigned int)0x0007FFFF;

    *(unsigned int *)(0x060A3DF8 + 0x3c) = param_1;

    (*0x06038A48)(param_1 | (unsigned int)0x25E00000,param_3,(unsigned int)param_2 << 1);

    *(unsigned int *)(puVar1 + 0x3c) = *(unsigned int *)(puVar1 + 0x3c) >> 1;

    if (param_2 != 1) {

      *(unsigned int *)(puVar1 + 0x3c) = *(unsigned int *)(puVar1 + 0x3c) | 0x80000000;

    }

    if (*(short *)0x060635AC == 0) {

      *(short *)0x060635AC = 1;

    }

  }

  return;

}
