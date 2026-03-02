int FUN_06038044(param_1)
    int param_1;
{
  unsigned short i;
  int base;

  base = 0x060A3D88;
  i = 0;
  do {
    *(short *)(base + (i << 1) + 0x10) = *(short *)(param_1 + (i << 1));
    i = i + 1;
  } while (i < 8);
  return base;
}
