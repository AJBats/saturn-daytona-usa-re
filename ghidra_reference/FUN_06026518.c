extern short DAT_06026576;
extern short DAT_06026578;

void FUN_06026518(param_1)
    unsigned int param_1;
{
  register int func1 asm("r3") = 0x060284AE;
  register int func2 asm("r2") = 0x06028400;

  if ((param_1 & 4) != 0) {
    (*(int(*)())func1)(8, 0x2a0, 0x90, 0x06059128);
    (*(void(*)())func1)(8, (int)DAT_06026576, 0x90, 0x06059128);
    return;
  }

  (*(int(*)())func2)(8, *(int *)0x06063B80, 0x2a0,
             *(int *)0x06063B84 + (int)DAT_06026578, 0x06063B80);

  (*(void(*)())func2)(8, *(int *)0x06063B88, (int)DAT_06026576,
             *(int *)0x06063B8C + (int)DAT_06026578);
}
