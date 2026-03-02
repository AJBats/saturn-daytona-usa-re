extern int DAT_06003362;

extern int DAT_06003364;

void FUN_060032d4()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  puVar3 = 0x0000F000;

  puVar2 = 0x060283E0;

  puVar1 = 0x06059ECE;

  (*(int(*)())0x060283E0)(8,0,0x0000F000,0x06059ECE);

  (*(int(*)())puVar2)(8,0xd00,puVar3,puVar1);

  (*(int(*)())puVar2)(8,0xd80,puVar3,puVar1);

  return;

}
