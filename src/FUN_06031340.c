extern int DAT_0603135c;

void FUN_06031340()
{

  int in_r1;

  unsigned int uVar1;

  short *puVar2;

  uVar1 = (unsigned int)DAT_0603135c;

  puVar2 = (short *)(uVar1 * 2);

  if (((uVar1 & 0x80000000) == 0) &&

     (puVar2 = (short *)0x06031A24, in_r1 < (int)(uVar1 * 3))) {

    *(short *)0x06031A24 = 1;

  }

  else {

    *puVar2 = 0;

  }

  return;

}
