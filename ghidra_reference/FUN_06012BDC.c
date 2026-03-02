extern int DAT_06012c66;

extern int FUN_06012b58();

void FUN_06012bdc()
{

  char *puVar1;

  unsigned int uVar2;

  int iVar3;

  puVar1 = 0x06018EAC;

  iVar3 = (int)DAT_06012c66;

  (*(int(*)())0x060283E0)(8,iVar3,0x0000E000,0x060448D4);

  (*(int(*)())0x0602761E)(*(int *)0x060612B4 + iVar3,0x060612C4 + iVar3,0x24);

  (*(int(*)())0x06034C48)();

  do {

    uVar2 = (*(int(*)())puVar1)();

  } while ((uVar2 & 0xf) != 1);

  (*(int(*)())0x060283E0)(8,iVar3,0x0000E000,0x0605ACCA);

  (*(int(*)())0x0602761E)(*(int *)0x060612B4 + iVar3,0x060612C4 + iVar3,0x24);

  FUN_06012b58();

  return;

}
