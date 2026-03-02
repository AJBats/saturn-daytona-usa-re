extern int FUN_0601164a();

void FUN_06011678()
{
  int *p;
  int i;

  p = (int *)0x25E5F800;
  FUN_0601164a();
  i = 0;
  do {
    p[i] = 0;
    i = i + 1;
  } while (i < 0x0100);
}
