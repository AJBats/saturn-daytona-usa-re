void FUN_0601ddf6()
{
  register int ptr asm("r0") = 0x0605ACE3;
  register int func1 asm("r3") = 0x060284AE;

  (*(int(*)())func1)(8, 0x7c2, 0x90, ptr);
  (*(int(*)())func1)(8, 0x8c2, 0x90, ptr);
  (*(void(*)())0x060283E0)(8, 0x9c2, 0xE000, ptr);
}
