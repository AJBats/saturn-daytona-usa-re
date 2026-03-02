void FUN_06038520()
{
  unsigned short val = *(unsigned short *)0x060635AC;
  if (val == 0) {
    *(unsigned short *)0x060635AC = 1;
  }
}
