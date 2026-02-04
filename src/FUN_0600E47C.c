extern void FUN_0600e7c8();

void FUN_0600e47c()
{

  char *puVar1;

  int uVar2;

  int iVar3;

  iVar3 = *(int *)0x0607E944;

  *(int *)0x0607E940 = iVar3;

  (*0x0600A8BC)();

  (*0x060081F4)();

  (*0x060085B8)();

  (*0x06030A06)();

  (*0x06030EE0)();

  FUN_0600e7c8();

  uVar2 = (*0x06006838)(*(int *)(iVar3 + 0x10),*(int *)(iVar3 + 0x18));

  *(int *)0x060786B8 = uVar2;

  (*0x06005ECC)();

  puVar1 = 0x06027CA4;

  (*0x06027CA4)(0x06063EB0,0);

  (*puVar1)(0x06063E9C,1);

  (*puVar1)(0x06063ED8,2);

  (*puVar1)(0x06063EC4,3);

  (*0x0600DA7C)();

  (*0x0600CE66)();

  (*0x0603053C)(0);

  (*0x0600D780)(0);

  return;

}
