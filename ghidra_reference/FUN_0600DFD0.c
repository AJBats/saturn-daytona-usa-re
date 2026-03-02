extern int FUN_0600e0c0();

void FUN_0600dfd0()
{
  register int func asm("r3") = 0x06027CA4;
  int iVar3 = *(int *)0x0607E944;
  int uVar2;

  *(short *)0x060786CA = (short)(*(int *)0x0607EA98 >> 1);
  *(int *)0x0607E940 = iVar3;
  *(int *)0x0607E948 = 0x06078B68;

  (*(int(*)())0x0602DB00)();
  uVar2 = (*(int(*)())0x06006838)(*(int *)(iVar3 + 0x10), *(int *)(iVar3 + 0x18));
  *(int *)0x060786B8 = uVar2;
  (*(int(*)())0x06005ECC)();

  (*(int(*)())func)(0x06063EB0, 0);
  (*(int(*)())func)(0x06063E9C, 1);
  (*(int(*)())func)(0x06063ED8, 2);
  (*(int(*)())func)(0x06063EC4, 3);
  FUN_0600e0c0();
}
