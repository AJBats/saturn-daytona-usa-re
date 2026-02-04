extern int DAT_0603b91e;

void FUN_0603b8f4(param_1)
    int param_1;
{

  if (*(int *)(*(int *)0x060A4D14 + (int)DAT_0603b91e) == param_1) {

    *(int *)(*(int *)0x060A4D14 + (int)DAT_0603b91e) = 0;

    (*(void(*)())0x0603FA1A)(*(int *)(param_1 + 8),0xffffffff);

    return;

  }

  return;

}
