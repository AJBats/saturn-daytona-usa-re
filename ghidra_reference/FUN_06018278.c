extern short PTR_DAT_060182f4;

unsigned int FUN_06018278()
{
  unsigned int uVar3;
  unsigned short *puVar4;
  unsigned int uVar5;

  uVar3 = (unsigned int)*(unsigned short *)0x0605BE1C;
  uVar5 = (unsigned int)*(unsigned short *)0x06063D9A;

  if ((uVar3 == 0) && (uVar5 != 0)) {
    puVar4 = (unsigned short *)0x0605BE1E;

    uVar3 = (*(int(*)())0x06035280)();

    if ((uVar3 & uVar5) == 0) {
      *puVar4 = 0;
      uVar3 = 0;
    }
    else {
      *puVar4 = *puVar4 + 1;
      uVar3 = (unsigned int)*puVar4;

      if (uVar3 == 7) {
        int idx;
        *puVar4 = 0;
        *(short *)0x0605BE1C = 1;

        idx = (unsigned int)*(unsigned short *)0x06069BB6 << 3;
        *(int *)(0x06063F64 + idx) = *(int *)0x06089E3C;
        uVar3 = (unsigned int)PTR_DAT_060182f4;
        *(short *)(0x06063F64 + idx + 6) = PTR_DAT_060182f4;
      }
    }
  }

  return uVar3;
}
