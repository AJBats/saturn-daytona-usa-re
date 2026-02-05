void FUN_060370c0(param_1)
    int *param_1;
{
  register int zero asm("r0") = 0;

  param_1[0] = 0;
  param_1[1] = 0;
  *((char *)param_1 + 8) = zero;
  *((char *)param_1 + 9) = zero;
  *((char *)param_1 + 10) = zero;
  *((char *)param_1 + 11) = zero;
  *((char *)param_1 + 12) = zero;
  *((char *)param_1 + 13) = zero;
  *((char *)param_1 + 14) = zero;
}
