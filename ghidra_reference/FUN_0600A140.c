void FUN_0600a140()
{

  char *puVar1;

  int *puVar2;

  int *puVar3;

  *(int *)0x25C00000 = 0x80000000;

  puVar1 = 0x00010000;

  puVar3 = (int *)0x25C80000;

  do {

    puVar1 = puVar1 + -2;

    puVar2 = puVar3 + 1;

    *puVar3 = 0;

    puVar3 = puVar3 + 2;

    *puVar2 = 0;

  } while (puVar1 != (char *)0x0);

  *(int *)0x0605A00C = 0;

  (*(int(*)())0x06026CE0)();

  *(int *)0x06059F44 = 0;

  puVar1 = 0x00010000;

  puVar3 = (int *)0x25C80000;

  do {

    puVar1 = puVar1 + -2;

    puVar2 = puVar3 + 1;

    *puVar3 = 0;

    puVar3 = puVar3 + 2;

    *puVar2 = 0;

  } while (puVar1 != (char *)0x0);

  *(int *)0x0605A00C = 0;

  (*(int(*)())0x06026CE0)();

  *(int *)0x06059F44 = 0;

  return;

}
