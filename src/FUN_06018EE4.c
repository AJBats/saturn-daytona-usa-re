extern int DAT_06018f74;

extern int DAT_06018f76;

extern int FUN_060192b4();

void FUN_06018ee4()
{

  char *puVar1;

  char *puVar2;

  unsigned int uVar3;

  puVar2 = 0x20100063;

  puVar1 = 0x25A02DBC;

  uVar3 = (unsigned int)DAT_06018f74;

  do {

  } while ((*(int *)0x20100063 & 1) == 1);

  *(int *)0x20100063 = 1;

  *(int *)0x2010001F = 7;

  do {

  } while ((*puVar2 & 1) != 0);

  FUN_060192b4();

  *(short *)0x25B00400 = DAT_06018f76;

  (*(void(*)())0x06012E84)();

  (*(void(*)())0x06012EBC)();

  do {

  } while ((*puVar2 & 1) == 1);

  *puVar2 = 1;

  *(int *)0x2010001F = 6;

  do {

  } while ((*puVar2 & 1) != 0);

  do {

  } while (*(unsigned short *)puVar1 != uVar3);

  (*(void(*)())0x0601D5F4)(0xf,0xAE0600FF);

  (*(void(*)())0x0601D5F4)(0xf,0xAE0007FF);

  *(int *)0x06086038 = 0;

  (*(void(*)())0x06018EC8)();

  return;

}
