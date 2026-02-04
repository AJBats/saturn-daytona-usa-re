extern int FUN_0603cd5c();

void FUN_0603c104()
{

  char *puVar1;

  unsigned int uVar2;

  unsigned char bVar3;

  puVar1 = 0x060A4D60;

  FUN_0603cd5c();

  (*(int(*)())0x0603D2CC)();

  (*(int(*)())0x0603D3A8)();

  (*(int(*)())0x0603D438)();

  (*(int(*)())0x0603D514)();

  (*(int(*)())0x0603D5D0)();

  bVar3 = 0;

  do {

    uVar2 = (unsigned int)bVar3;

    bVar3 = bVar3 + 1;

    *(int *)(puVar1 + (uVar2 << 2)) = 0;

  } while (bVar3 < 8);

  *(int *)0x060A4D80 = 0;

  *(int *)0x060A4DA6 = 0;

  return;

}
