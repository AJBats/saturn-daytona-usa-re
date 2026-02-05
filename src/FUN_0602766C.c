void FUN_0602766c(param_1, param_2, param_3)
    int param_1;
    int param_2;
    int param_3;
{
  register int *base asm("r2") = (int *)0x25FE0000;

  do {
  } while ((*(int *)0x25FE007C & 0x272E) != 0);

  base[1] = param_1;
  base[0] = param_2;
  base[2] = param_3;
  base[3] = 0x101;
  base[5] = 7;
  base[4] = 0x101;
}
