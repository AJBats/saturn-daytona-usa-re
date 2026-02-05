extern int DAT_0600a10c;

void FUN_0600a084()
{
  register int func asm("r3") = 0x06014884;
  int val = *(int *)(*(int *)0x0607E944 + (int)DAT_0600a10c);
  int iVar1;

  if (val < 2) {
    (*(void(*)())func)(0x10, 0, 0);
    return;
  }

  iVar1 = val << 15;
  if ((*(unsigned int *)0x0607EBC8 & 1) != 0) {
    iVar1 = val * -0x8000;
  }
  (*(void(*)())func)(0x10, iVar1, 0);
}
