void FUN_06020946()
{

  char *puVar1;

  unsigned char bVar2;

  char auStack_70 [96];

  puVar1 = 0x06028400;

  (*(int(*)())0x06035228)();

  bVar2 = 0;

  do {

    (*(int(*)())puVar1)(4,auStack_70,(unsigned int)bVar2 << 7,0);

    (*(int(*)())puVar1)(4,auStack_70,((unsigned int)(bVar2 << 6) + 0x2c) << 1,0);

    bVar2 = bVar2 + 1;

  } while (bVar2 < 0x1c);

  return;

}
