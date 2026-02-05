extern short DAT_060032ba;
extern short DAT_060032bc;

void FUN_06003274()
{
  register int (*func)() asm("r3") = *(int(**)())0x06000310;

  func(4, 0x06028218);
  func(6, 0x06028230);
  func(9, 0x06028248);
  func((int)DAT_060032ba, 0x06028218);
  func((int)DAT_060032bc, 0x06028230);
  (*(void(*)())func)(0x109, 0x06028248);
}
