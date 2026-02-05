int FUN_06017330(param_1)
    unsigned short param_1;
{
  register char *base asm("r2") = (char *)0x06085490;
  int offset;
  unsigned char bVar3;

  param_1 = param_1 & 0xff;
  offset = (short)(param_1 * 0x18);

  *(int *)(base + offset + 16) = 0;
  *(short *)(base + offset + 6) = 0;
  *(base + offset + 5) = 0;

  bVar3 = 0;
  do {
    *(short *)(base + (bVar3 << 1) + offset + 8) = 0;
    bVar3 = bVar3 + 1;
  } while (bVar3 < 8);

  return 0;
}
