extern int DAT_0601f962;
extern int FUN_0601f87a();
extern int FUN_0601f9cc();
extern int FUN_0601fd20();

int FUN_0601f936()
{
  register int base asm("r2") = 0x0605B6D8;
  register int func asm("r3") = 0x06026CE0;
  unsigned short uVar1 = DAT_0601f962;
  int uVar4;

  *(int *)0x0605E05C = 0;
  FUN_0601f87a(0);
  uVar4 = (*(int(*)())0x0601E958)();

  if (*(char *)0x0605E05C != 0) {
    *(unsigned int *)base |= 0x80000000;
    (*(int(*)())func)();
    (*(int(*)())func)();
    FUN_0601f9cc();
    *(unsigned int *)base |= 0x40000000;

    do {
      FUN_0601fd20();
    } while ((*(unsigned short *)0x06063D9A & uVar1) == 0);

    uVar4 = FUN_0601fd20();
    *(unsigned int *)base |= 0x80000000;
  }
  return uVar4;
}
