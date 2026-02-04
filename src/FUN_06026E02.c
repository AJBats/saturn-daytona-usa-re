void FUN_06026e02()
{

  int *puVar1;

  char *puVar2;

  puVar1 = 0x06089EE0;

  *(int **)0x06089EDC = 0x06089EE0;

  puVar2 = 0x00010000;

  puVar1[1] = 0;

  *puVar1 = puVar2;

  puVar1[2] = 0;

  puVar1[3] = 0;

  puVar1[4] = puVar2;

  puVar1[5] = 0;

  puVar1[6] = 0;

  puVar1[7] = 0;

  puVar1[8] = puVar2;

  puVar1[9] = 0;

  puVar1[10] = 0;

  puVar1[0xb] = 0;

  return;

}
