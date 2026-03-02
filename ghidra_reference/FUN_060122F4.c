void FUN_060122f4()
{
  volatile int *base;
  short sub1, sub2, add_val;
  int limit1, limit2;
  short *pw;

  base = (volatile int *)0x060788B4;
  sub1 = 0x2999;
  base[1] = base[1] - sub1;

  sub2 = 0x4000;
  base[2] = base[2] - sub2;

  limit1 = 0x00020000;
  if (!(base[1] >= limit1)) {
    base[1] = limit1;
  }

  limit2 = 0x0004CCCC;
  if (!(base[2] >= limit2)) {
    base[2] = limit2;
  }

  pw = (short *)0x060788B2;
  add_val = 0x1800;
  *pw = *pw + add_val;
}
