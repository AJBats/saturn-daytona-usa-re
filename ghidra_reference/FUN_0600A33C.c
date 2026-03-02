int FUN_0600a33c()
{
  register int iVar1 asm("r0");
  register short *dest asm("r2") = (short *)0x0605A016;

  iVar1 = *(int *)0x06063E1C;

  if (iVar1 == 0) {
    *dest = 5;
  }
  else if (iVar1 == 1) {
    *dest = 6;
  }
  else if (iVar1 == 2) {
    *dest = 7;
  }
  else if (iVar1 == 3) {
    *dest = 8;
  }

  return iVar1;
}
