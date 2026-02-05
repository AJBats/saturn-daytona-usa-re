void FUN_06014868(param_1, param_2, param_3)
    int param_1;
    int param_2;
    int param_3;
{
  register int p2 asm("r2") = param_2;
  register int p3 asm("r3") = param_3;

  (*(int(*)())0x0603850C)();
  (*(int(*)())0x06038794)(p2, p3);
  (*(void(*)())0x06038520)();
}
