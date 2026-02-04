void FUN_0603c05c(param_1, param_2)
    unsigned int param_1;
    int param_2;
{

  int *puVar1;

  int *puVar2;

  

  puVar1 = (int *)(param_1 & 0x1FFFFFF0 | 0x40000000);

  puVar2 = (int *)((int)puVar1 + param_2);

  for (; puVar1 < puVar2; puVar1 = puVar1 + 4) {

    *puVar1 = 0;

  }

  return;

}
