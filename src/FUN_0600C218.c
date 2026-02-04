extern int DAT_0600c2a6;

extern int PTR_DAT_0600c2a8;

extern int PTR_DAT_0600c2a8;

void FUN_0600c218()
{

  unsigned short uVar1;

  char *puVar2;

  char *puVar3;

  int iVar4;

  unsigned char *pbVar5;

  puVar2 = 0x0608A52C;

  uVar1 = PTR_DAT_0600c2a8;

  pbVar5 = (unsigned char *)(int)DAT_0600c2a6;

  iVar4 = *(int *)0x0608A52C;

  *(int *)0x0608A52C = iVar4 + 0x30;

  (*(void(*)())0x06027630)(iVar4 + 0x30,*(int *)0x06089EDC,0x30);

  (*(void(*)())0x0600D31C)();

  *(char **)0x06063574 = 0x0600C286;

  *(short *)0x21000000 = (short)0x0000FFFF;

  (*(void(*)())0x060058FA)();

  (*(void(*)())0x06006868)();

  (*(void(*)())0x0601BDEC)();

  puVar3 = 0x0603C000;

  do {

  } while ((*pbVar5 & uVar1) != uVar1);

  *pbVar5 = *pbVar5 & 0xf;

  (*(void(*)())puVar3)();

  *(int *)puVar2 = *(int *)puVar2 + -0x30;

  return;

}
