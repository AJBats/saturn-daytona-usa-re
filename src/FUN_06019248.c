extern void FUN_060192e8();

void FUN_06019248()
{

  char *puVar1;

  puVar1 = 0x0601D5F4;

  *(int *)0x06086050 = 0;

  (*puVar1)(0xf,0xAE0001FF);

  (*puVar1)(0xf,0xAE0005FF);

  FUN_060192e8();

  if (*(int *)0x06086050 == 0) {

    (*0x0602760C)(0x25A03000,0x0026D000,0x0006D000);

    *(short *)0x25A02DBE = 0;

  }

  (*puVar1)(0xf,0xAE0001FF);

  return;

}
