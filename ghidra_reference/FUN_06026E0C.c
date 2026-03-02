void FUN_06026e0c()
{

  char *puVar1;

  int *puVar2;

  

  puVar1 = 0x00010000;

  puVar2 = *(int **)0x06089EDC;

  puVar2[1] = 0;

  *puVar2 = puVar1;

  puVar2[2] = 0;

  puVar2[3] = 0;

  puVar2[4] = puVar1;

  puVar2[5] = 0;

  puVar2[6] = 0;

  puVar2[7] = 0;

  puVar2[8] = puVar1;

  puVar2[9] = 0;

  puVar2[10] = 0;

  puVar2[0xb] = 0;

  return;

}
