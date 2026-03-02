extern short DAT_0600ce86;
extern short DAT_0600ce88;
extern short DAT_0600ce8a;
extern short DAT_0600ce8c;

int FUN_0600cdd0()
{
  register int base asm("r2") = *(int *)0x0607E940;
  int iVar1;
  short sVar2;
  int iVar3;
  int *piVar4;
  int iVar5;

  iVar5 = *(int *)(base + (int)DAT_0600ce86) * 0x18 + *(int *)(base + (int)DAT_0600ce86 - 4);

  iVar1 = (int)DAT_0600ce88;
  *(unsigned int *)(base + iVar1) = (unsigned int)*(unsigned short *)(iVar5 + 0x16);
  iVar1 = *(int *)(base + iVar1 + 0x60);

  if (iVar1 == 0) {
    iVar1 = *(int *)0x0607EA9C;
  } else {
    iVar1 = iVar1 - 1;
  }

  piVar4 = (int *)(iVar1 * 0x18 + *(int *)(base + (int)DAT_0600ce8a));
  sVar2 = (*(int(*)())0x0602744C)(*piVar4 - *(int *)(base + 0x10), *(int *)(base + 0x18) - piVar4[1]);

  iVar3 = (int)sVar2 + *(short *)(iVar5 + 0xe) * -4;
  if (iVar3 < 0) {
    iVar3 = (*(short *)(iVar5 + 0xe) << 2) - (int)sVar2;
  }

  if ((int)DAT_0600ce8c < iVar3) {
    *(int *)(base + (int)DAT_0600ce86) = iVar1;
  }

  return iVar5;
}
