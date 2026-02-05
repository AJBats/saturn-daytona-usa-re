unsigned int FUN_0600a1b8()
{
  register char *base asm("r2") = (char *)0x0607ED90;
  unsigned int uVar2;

  if (*(char *)0x06078635 != 0 ||
     ((uVar2 = *(unsigned short *)0x0607ED8C) == 0 &&
      (uVar2 = *(unsigned int *)0x0605AD00) == 0)) {
    base[0] = (char)*(short *)0x06063F44;
    base[1] = (char)*(int *)0x06078868;
    uVar2 = *(unsigned int *)0x0607EAB8 & 0xff;
    base[2] = (char)uVar2;
  }
  return uVar2;
}
