extern int DAT_0600dc9c;
extern int DAT_0600dc9e;

void FUN_0600dc74()
{
  register int addr asm("r0") = 0x0605ACE8;
  register int func asm("r3") = 0x060284AE;

  (*(int(*)())func)(8,(int)DAT_0600dc9c,0x60,addr);
  (*(int(*)())func)(8,(int)DAT_0600dc9e,0x60,addr);
}
