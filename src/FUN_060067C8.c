extern int DAT_06006804;

int FUN_060067c8()
{

  char cVar1;

  short uVar2;

  char *puVar3;

  short uVar4;

  uVar4 = (*(int(*)())0x0601A5F8)();

  (*(int(*)())0x06026590)((int)(char)*(int *)0x0605D240,uVar4);

  puVar3 = 0x06063F4A;

  uVar2 = DAT_06006804;

  cVar1 = *(int *)0x06078663;

  uVar4 = SUB42(0x00008000,0);

  if (cVar1 == 0) {

    *(short *)0x06063F48 = DAT_06006804;

    *(short *)puVar3 = uVar4;

  }

  else {

    *(short *)0x06063F48 = uVar4;

    *(short *)puVar3 = uVar2;

  }

  return (int)cVar1;

}
