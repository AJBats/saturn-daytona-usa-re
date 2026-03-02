void FUN_060148a2()
{
  register int func asm("r3") = 0x06038BD4;
  register char *data asm("r2") = (char *)0x0605B71C;

  (*(int(*)())func)(0x100, (int)(char)data[0]);
  (*(int(*)())func)(4, (int)(char)data[1]);
  (*(int(*)())func)(8, (int)(char)data[2]);
  (*(int(*)())func)(0x10, (int)(char)data[3]);
  (*(int(*)())func)(0x20, (int)(char)data[4]);
  (*(int(*)())func)(1, (int)(char)data[5]);
}
