extern int DAT_0600a110;
extern int DAT_0600a112;

void FUN_0600a0c0()
{
  register int func1 asm("r3") = 0x06026CE0;
  register int ptrAddr asm("r2") = 0x06063F5C;

  (*(int(*)())0x06038BD4)(0x100, 0);
  (*(int(*)())func1)();
  *(int *)0x06059F44 = 0;
  (*(int(*)())0x06039250)(ptrAddr);
  (*(int(*)())0x060393FC)(0, 0, 0, (int)DAT_0600a112, (int)DAT_0600a110);
  *(int *)0x0605A008 = 0;
  **(short **)ptrAddr = (short)0x8000;
  (*(int(*)())func1)();
  *(int *)0x06059F44 = 0;
}
