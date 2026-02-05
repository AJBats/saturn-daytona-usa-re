extern short DAT_0600a36c;
extern short DAT_0600a36e;
extern short DAT_0600a370;
extern short DAT_0600a372;

int FUN_0600a294()
{
  register short *dest asm("r4") = (short *)0x0605A016;
  register int *src asm("r5") = (int *)0x0607EBCC;
  register short v3 asm("r7") = 3;
  register short v4 asm("r6") = 4;
  int iVar1;
  int cmp;

  iVar1 = *(int *)0x0607EAD8;
  if (iVar1 == 1) {
    cmp = *src;
    if (cmp == 0x371) {
      *dest = v3;
    }
    else if (cmp == 0x352) {
      *dest = v4;
    }
  }
  else if (iVar1 == 2) {
    cmp = *src;
    if (cmp == 0x3ab) {
      *dest = v3;
    }
    else if (cmp == 0x398) {
      *dest = v4;
    }
    else if (cmp == (int)DAT_0600a36c) {
      *dest = v3;
    }
    else if (cmp == (int)DAT_0600a36e) {
      *dest = v4;
    }
    else if (cmp == (int)DAT_0600a370) {
      *dest = v3;
    }
    else if (cmp == (int)DAT_0600a372) {
      *dest = v4;
    }
  }
  return iVar1;
}
