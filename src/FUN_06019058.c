extern void FUN_060192e8();

void FUN_06019058()
{

  char *puVar1;

  puVar1 = 0x0601D5F4;

  *(int *)0x06086050 = 0;

  (*puVar1)(0xf,0xAE0001FF);

  (*puVar1)(0xf,0xAE0005FF);

  FUN_060192e8();

  if (*(int *)0x06086050 == 0) {

    (*0x06012F10)();

    *(short *)0x25A02DBE = 0;

  }

  (*puVar1)(0xf,0xAE0001FF);

  (*puVar1)(0xf,0xAE0600FF);

  return;

}
