int FUN_060335f4(param_1, param_2, param_3)
    int param_1;
    int param_2;
    int param_3;
{
  register int p2 asm("r2") = param_2;
  register int p3 asm("r1") = param_3;
  int uVar2 = *(int *)(0x0603363C + (*(int *)0x0607EAD8 << 2));
  int uVar1 = (*(int(*)())0x06027348)();
  return (*(int(*)())0x06027344)(uVar2, p2, p3, uVar1);
}
