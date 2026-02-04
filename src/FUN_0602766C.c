extern volatile int REG_25FE007C;
extern short DAT_0602768a;

void FUN_0602766c(param_1, param_2, param_3)
    int param_1;
    int param_2;
    int param_3;
{
  volatile int *base;
  int val;

  base = (volatile int *)0x25FE0000;
  do {
  } while ((0x0000272E & REG_25FE007C) != 0);
  val = 0x101;
  base[1] = param_1;
  base[0] = param_2;
  base[2] = param_3;
  base[3] = val;
  base[5] = 7;
  base[4] = val;
}
