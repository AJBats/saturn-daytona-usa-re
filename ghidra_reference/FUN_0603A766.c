extern int FUN_0603a7b0();
extern int FUN_0603ab46();

void FUN_0603a766()
{
  int *counter;
  unsigned short *limit;

  counter = (int *)0x060A4CB4;
  limit = (unsigned short *)0x060A4CAC;

  goto check;

loop:
  FUN_0603ab46(255);
  FUN_0603a7b0();
  *counter = *counter + 1;

check:
  if (*counter < (int)(unsigned int)*limit) {
    goto loop;
  }
}
