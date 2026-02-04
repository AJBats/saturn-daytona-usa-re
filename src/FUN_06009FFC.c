void FUN_06009ffc()
{

  char *puVar1;

  puVar1 = 0x0601D5F4;

  (*(void(*)())0x0601D5F4)(1,0);

  (*(void(*)())puVar1)(3,0);

  (*(void(*)())puVar1)(2,0);

  (*(void(*)())puVar1)(0,0xAE0001FF);

  (*(void(*)())puVar1)(0,0xAE0600FF);

  return;

}
