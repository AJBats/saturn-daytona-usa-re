int FUN_06027344(param_1)
    int param_1;
{
  int tmp = param_1 + 0x4000;
  unsigned int mask = 0x3FFC;
  unsigned int offset = (((unsigned int)tmp >> 2) + 2) & mask;
  return *(int *)(0x002F2F20 + offset);
}
