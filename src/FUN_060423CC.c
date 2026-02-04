extern int PTR_DAT_060423f6;

extern int PTR_DAT_060423f6;

int FUN_060423cc()
{

  unsigned short uVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  unsigned short uVar6;

  int uVar5;

  puVar4 = 0x0000FBFF;

  puVar3 = 0x06035C4E;

  puVar2 = 0x06035C54;

  uVar1 = PTR_DAT_060423f6;

  do {

    uVar6 = (*puVar3)();

  } while ((uVar6 & uVar1) == 0);

  uVar5 = (*puVar2)((unsigned int)puVar4 & 0xffff);

  return uVar5;

}
