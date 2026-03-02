extern int DAT_0600cdbe;

extern int DAT_0600cdc0;

extern int DAT_0600cdc2;

int * FUN_0600cd40()
{

  short sVar1;

  int iVar2;

  int *piVar3;

  int iVar4;

  iVar4 = *(int *)0x0607E940;

  piVar3 = (int *)(*(int *)(iVar4 + DAT_0600cdbe) * 0x18 + *(int *)(iVar4 + DAT_0600cdbe + -4));

  *(unsigned int *)(iVar4 + DAT_0600cdc0) = (unsigned int)*(unsigned short *)((int)piVar3 + 0x16);

  sVar1 = (*(int(*)())0x0602744C)(*(int *)(iVar4 + 0x10) - *piVar3,piVar3[1] - *(int *)(iVar4 + 0x18));

  iVar2 = (int)sVar1 + *(short *)((int)piVar3 + 0xe) * -4;

  if (iVar2 < 0) {

    iVar2 = *(short *)((int)piVar3 + 0xe) << 2 - (int)sVar1;

  }

  if (DAT_0600cdc2 < iVar2) {

    iVar2 = (int)DAT_0600cdbe;

    *(int *)(iVar4 + iVar2) = *(int *)(iVar4 + iVar2) + 1;

    if (*(int *)0x0607EA9C < *(int *)(iVar4 + iVar2)) {

      *(int *)(iVar4 + DAT_0600cdbe) = 0;

    }

  }

  return piVar3;

}
