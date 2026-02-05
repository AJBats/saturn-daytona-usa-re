void FUN_060192e8()
{
  register unsigned int cnt asm("r1") = 100000;

  do {
    cnt = cnt - 1;
  } while (cnt != 0);

  *(int *)0x06086050 = 1;
}
