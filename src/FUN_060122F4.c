void FUN_060122f4()
{
  int *base;
  int val4, val8;
  short *pw;

  base = (int *)0x060788B4;

  val4 = base[1] - 0x2999;
  base[1] = val4;

  val8 = base[2] - 0x4000;
  base[2] = val8;

  if (val4 < 0x00020000) {
    base[1] = 0x00020000;
  }

  if (val8 < 0x0004CCCC) {
    base[2] = 0x0004CCCC;
  }

  pw = (short *)0x060788B2;
  *pw = *pw + 0x1800;
}
