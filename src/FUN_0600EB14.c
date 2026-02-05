extern short DAT_0600ebd8;

void FUN_0600eb14()
{
  register int *ptr asm("r4") = (int *)0x06078900;
  register unsigned int cnt asm("r5") = 0;
  register int zero asm("r6") = 0;
  unsigned int limit = (unsigned int)DAT_0600ebd8;

  do {
    *ptr++ = zero;
    cnt++;
  } while (cnt < limit);

  (*(void(*)())0x06026E02)();
  (*(void(*)())0x060270C6)();
  (*(void(*)())0x0600629C)();

  *(int *)0x06078A20 = 1;
  *(int *)0x06078A24 = 1;
  *(int *)0x06078A28 = 1;
  *(int *)0x06078A2C = 1;

  *(short *)0x06063F46 = zero;
  *(int *)0x0607EAE4 = zero;
  *(int *)0x0607EAE8 = zero;
  *(int *)0x0607EAEC = zero;
  *(int *)0x0607EBD0 = zero;
  *(int *)0x0607EBF4 = zero;
  *(int *)0x06078654 = 5;
  *(int *)0x0605A1C4 = zero;
  *(int *)0x06082A30 = zero;
  *(int *)0x0607EABC = zero;
  *(int *)0x0607EAC0 = zero;
  *(int *)0x06083260 = zero;
  *(int *)0x06082A26 = zero;
  *(int *)0x060788FC = zero;
  *(int *)0x06082A38 = zero;
  *(int *)0x06083261 = zero;
  *(int *)0x0608325C = zero;
  *(int *)0x06083258 = zero;
  *(int *)0x0605A21C = zero;
  *(short *)0x06086058 = zero;
  *(int *)0x0608605A = zero;
  *(int *)0x0605DE3C = zero;
  *(int *)0x060786A8 = zero;
  *(int *)0x060786BC = zero;
  *(int *)0x06085FCC = zero;
  *(int *)0x06087060 = zero;

  *(short *)0x0602FD98 = zero;
  *(short *)0x0602FD9A = zero;
  *(short *)0x0602FD9C = zero;
  *(short *)0x0602FD9E = zero;
  *(short *)0x0602FDA0 = zero;

  (*(void(*)())0x06021450)();
  (*(void(*)())0x06018634)();
}
