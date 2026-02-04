extern char DAT_06082A7C[];

void FUN_0603446c()
{
  int i = 0;
  do {
    *(char *)((char *)DAT_06082A7C + (unsigned short)i * (unsigned short)0x2C + 0x26) = 0;
    i++;
  } while (i < 5);
  return;
}
