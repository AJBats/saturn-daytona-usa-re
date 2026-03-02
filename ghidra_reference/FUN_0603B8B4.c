extern int DAT_0603b91c;

void FUN_0603b8b4(param_1)
    int *param_1;
{

  char *puVar1;

  puVar1 = 0x060A4D14;

  if (*(int **)(*(int *)0x060A4D14 + 0xa8) == param_1) {

    *(int *)(*(int *)0x060A4D14 + 0xa8) = 0;

    (*(int(*)())(*(int *)((unsigned int)*(unsigned char *)(param_1 + 4) << 4 + *(int *)puVar1 + 8)))(*param_1,1);

    return;

  }

  return;

}
