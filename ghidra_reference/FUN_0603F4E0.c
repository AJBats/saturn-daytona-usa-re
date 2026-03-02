extern int FUN_0603f3f6();

int FUN_0603f4e0(param_1)
    int param_1;
{
  short local_10[2];
  volatile int saved_param;
  char auStack_8[8];

  saved_param = param_1;
  FUN_0603f3f6(param_1, auStack_8, 2);
  FUN_0603f3f6(saved_param, local_10, 2);
  return (int)local_10[0];
}
