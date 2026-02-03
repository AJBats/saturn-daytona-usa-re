void FUN_0601db84()
{

  char *puVar1;

  

  puVar1 = 0x000186A0;

  do {

    puVar1 = puVar1 + -1;

    if (puVar1 == (char *)0x0) {

      *(int *)0x06086050 = 1;

      return;

    }

  } while (*(int *)0x25A02C20 != 0);

  return;

}
