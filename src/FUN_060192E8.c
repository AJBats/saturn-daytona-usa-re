void FUN_060192e8()
{

  char *puVar1;

  puVar1 = 0x000186A0;

  do {

    puVar1 = puVar1 + -1;

    if (puVar1 == (char *)0x0) {

      *(int *)0x06086050 = 1;

      return;

    }

  } while ((char *)(unsigned int)*(unsigned short *)0x25A02DBE != 0x0000FFFF);

  return;

}
