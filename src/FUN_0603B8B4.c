extern int DAT_0603b91c;

void FUN_0603b8b4(param_1)
    int *param_1;
{

  char *puVar1;

  puVar1 = 0x060A4D14;

  if (*(int **)(*(int *)0x060A4D14 + (int)DAT_0603b91c) == param_1) {

    *(int *)(*(int *)0x060A4D14 + (int)DAT_0603b91c) = 0;

    (**(void **)((unsigned int)*(unsigned char *)(param_1 + 4) * 0x10 + *(int *)puVar1 + 8))(*param_1,1);

    return;

  }

  return;

}
