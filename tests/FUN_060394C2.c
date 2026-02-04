extern volatile unsigned short REG_25D00010;

void FUN_060394c2()
{
  do {
  } while ((REG_25D00010 & 2) == 0);
  return;
}
