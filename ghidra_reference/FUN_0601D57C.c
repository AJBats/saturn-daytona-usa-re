void FUN_0601d57c(param_1)
    unsigned short param_1;
{
  register char *dest asm("r2") = (char *)0x0605AAA6;
  register char *src asm("r3") = (char *)0x06094FAC;
  unsigned short uVar3;
  int srcOff;
  int destOff;

  uVar3 = 0;
  do {
    destOff = uVar3 << 2;
    srcOff = uVar3 * 0x58 + (param_1 << 1);
    uVar3 = uVar3 + 1;

    *(short *)(dest + destOff) = *(short *)(src + srcOff);
    *(short *)(dest + destOff + 2) = *(short *)(src + srcOff + 2);
  } while (uVar3 < 0x1c);

  (*(void(*)())0x06028400)(0xc, 0x0605AAA2, (param_1 & 0x3f) << 1, 0);
}
