void FUN_0601db84()
{
  register int *dest asm("r7") = (int *)0x06086050;
  register int *src asm("r6") = (int *)0x25A02C20;
  register int val asm("r5") = 1;
  register int count asm("r4") = 0x000186A0;

L:
  if (--count == 0) {
    *dest = val;
  }
  else if (*src != 0) goto L;
}
