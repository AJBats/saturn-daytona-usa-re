unsigned char FUN_0603f202(param_1, param_2)
    int param_1;
    int param_2;
{
  int addr = (param_1 << 2) + (param_1 << 3) + param_2;
  return *(unsigned char *)(addr + 0xB);
}
