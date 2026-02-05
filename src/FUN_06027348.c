int FUN_06027348(param_1)
    unsigned int param_1;
{
  unsigned int mask = 0x3FFC;
  unsigned int offset = ((param_1 >> 2) + 2) & mask;
  return *(int *)(0x002F2F20 + offset);
}
