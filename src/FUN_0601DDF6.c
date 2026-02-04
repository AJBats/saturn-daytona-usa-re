extern int DAT_0601de28;

extern int DAT_0601de2a;

extern int DAT_0601de2c;

extern int DAT_0601de2e;

void FUN_0601ddf6()
{

  char *puVar1;

  puVar1 = 0x0605ACE3;

  (*(void(*)())0x060284AE)(8,(int)DAT_0601de2a,(int)DAT_0601de28,0x0605ACE3);

  (*(void(*)())0x060284AE)(8,(int)DAT_0601de2c,(int)DAT_0601de28,puVar1);

  (*(void(*)())0x060283E0)(8,(int)DAT_0601de2e,0x0000E000,puVar1);

  return;

}
