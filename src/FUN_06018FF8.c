extern int FUN_060192e8();

void FUN_06018ff8()
{

  char *puVar1;

  puVar1 = 0x0601D5F4;

  *(int *)0x06086050 = 0;

  (*(void(*)())puVar1)(0xf,0xAE0001FF);

  (*(void(*)())puVar1)(0xf,0xAE0005FF);

  FUN_060192e8();

  if (*(int *)0x06086050 == 0) {

    (*(void(*)())0x06012EBC)();

    *(short *)0x25A02DBE = 0;

  }

  (*(void(*)())puVar1)(0xf,0xAE0600FF);

  (*(void(*)())puVar1)(0xf,0xAE0001FF);

  return;

}
