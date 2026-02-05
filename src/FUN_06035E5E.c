void FUN_06035e5e(param_1)
    short *param_1;
{
  short r0;

  r0 = *(volatile short *)0x25890018;
  *param_1 = r0;

  r0 = *(volatile short *)0x2589001C;
  *(short *)((char *)param_1 + 2) = r0;

  r0 = *(volatile short *)0x25890020;
  *(short *)((char *)param_1 + 4) = r0;

  r0 = *(volatile short *)0x25890024;
  *(short *)((char *)param_1 + 6) = r0;
}
