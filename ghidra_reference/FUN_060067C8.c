extern short DAT_06006804;

int FUN_060067c8()
{
  short uVar4;
  char cVar1;
  short uVar2;

  uVar4 = (*(int(*)())0x0601A5F8)();
  (*(int(*)())0x06026590)((int)(char)*(char *)0x0605D240, uVar4);

  uVar2 = DAT_06006804;
  cVar1 = *(char *)0x06078663;
  uVar4 = (short)0x8000;

  if (cVar1 == 0) {
    *(short *)0x06063F48 = uVar2;
    *(short *)0x06063F4A = uVar4;
  }
  else {
    *(short *)0x06063F48 = uVar4;
    *(short *)0x06063F4A = uVar2;
  }

  return (int)cVar1;
}
