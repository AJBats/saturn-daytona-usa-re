void FUN_060192b4()
{

  char *puVar1;

  char *puVar2;

  

  puVar1 = 0x0007FFFF;

  puVar2 = 0x25A00000;

  do {

    puVar1 = puVar1 + -1;

    *puVar2 = 0;

    puVar2 = puVar2 + 1;

  } while (puVar1 != (char *)0x0);

  return;

}
