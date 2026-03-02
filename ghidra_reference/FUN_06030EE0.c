int FUN_06030ee0()
{
  short *p;
  short val;

  p = (short *)(*(int *)0x0607E940 + 0x0150);
  val = *p;
  if (val > 0) {
    *p = val - 1;
  }
  return 0x0150;
}
