int FUN_0603a72c()
{

  char *puVar1;

  char *puVar2;

  if ((*0x20100063 & 1) == 1) {

    return 1;

  }

  *0x20100063 = 1;

  puVar2 = 0x20100001;

  puVar1 = 0x06063602;

  *0x20100001 = *0x06063602;

  puVar2[2] = puVar1[1];

  puVar2[4] = puVar1[2];

  puVar2[0x1e] = 0x10;

  return 0;

}
