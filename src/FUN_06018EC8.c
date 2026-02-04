void FUN_06018ec8()
{
  short val = 0x00E0;
  *(volatile char *)0x25B00217 = (unsigned char)val;
  *(volatile char *)0x25B00237 = (char)val;
}
