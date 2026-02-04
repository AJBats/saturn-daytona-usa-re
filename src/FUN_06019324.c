extern int PTR_DAT_06019374;

extern int PTR_DAT_06019374;

void FUN_06019324()
{

  char *puVar1;

  puVar1 = 0x06038BD4;

  (*(void(*)())0x06038BD4)((int)PTR_DAT_06019374,1);

  (*(void(*)())puVar1)(4);

  (*(void(*)())puVar1)(8,5);

  (*(void(*)())puVar1)(0x10,6);

  (*(void(*)())puVar1)(0x20,7);

  (*(void(*)())puVar1)(1,0);

  *(unsigned int *)0x0605B6D8 = *(unsigned int *)0x0605B6D8 | 0x40000000;

  return;

}
