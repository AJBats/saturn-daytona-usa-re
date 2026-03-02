void FUN_06019324()
{

  char *puVar1;

  puVar1 = 0x06038BD4;

  (*(int(*)())0x06038BD4)(0x100,1);

  (*(int(*)())puVar1)(4);

  (*(int(*)())puVar1)(8,5);

  (*(int(*)())puVar1)(0x10,6);

  (*(int(*)())puVar1)(0x20,7);

  (*(int(*)())puVar1)(1,0);

  *(unsigned int *)0x0605B6D8 = *(unsigned int *)0x0605B6D8 | 0x40000000;

  return;

}
