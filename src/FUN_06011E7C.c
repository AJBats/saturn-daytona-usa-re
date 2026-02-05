extern short DAT_06011efe;
extern short DAT_06011f00;
extern short DAT_06011f02;

void FUN_06011e7c()
{
  register int func asm("r3") = 0x06028400;
  register int off asm("r2");

  off = (int)DAT_06011efe;

  (*(int(*)())func)(0xc,*(int *)0x060638B0,(int)DAT_06011f00,
                   *(int *)0x060638B4 + off);

  (*(int(*)())func)(0xc,*(int *)0x060638A0,(int)DAT_06011f02,
                   *(int *)0x060638A4 + off);
}
