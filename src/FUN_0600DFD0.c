extern void FUN_0600e0c0();

void FUN_0600dfd0()
{

  char *puVar1;

  int uVar2;

  int iVar3;

  iVar3 = *(int *)0x0607E944;

  *(short *)0x060786CA = (short)(*(int *)0x0607EA98 >> 1);

  *(int *)0x0607E940 = iVar3;

  *(char **)0x0607E948 = 0x06078B68;

  (*0x0602DB00)();

  uVar2 = (*0x06006838)(*(int *)(iVar3 + 0x10),*(int *)(iVar3 + 0x18));

  *(int *)0x060786B8 = uVar2;

  (*0x06005ECC)();

  puVar1 = 0x06027CA4;

  (*0x06027CA4)(0x06063EB0,0);

  (*puVar1)(0x06063E9C,1);

  (*puVar1)(0x06063ED8,2);

  (*puVar1)(0x06063EC4,3);

  FUN_0600e0c0();

  return;

}
