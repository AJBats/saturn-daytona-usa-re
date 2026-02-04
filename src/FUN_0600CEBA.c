extern int DAT_0600cf3a;

extern int DAT_0600cf40;

extern int DAT_0600cf42;

int FUN_0600ceba()
{

  char *puVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  iVar2 = (int)DAT_0600cf3a;

  iVar4 = *(int *)0x0607E940;

  iVar3 = *(int *)0x0607EB84;

  *(int *)(iVar4 + iVar2 + 0x6c) = *(int *)(iVar4 + iVar2 + 0x68);

  *(unsigned int *)(iVar4 + iVar2 + 0x68) = (unsigned int)*(unsigned short *)(*(int *)(iVar4 + iVar2) * 4 + iVar3);

  (*(void(*)())0x06035228)();

  (*(void(*)())0x06035228)();

  iVar2 = DAT_0600cf40 + -4;

  iVar3 = (int)(short)((short)*(int *)(iVar4 + DAT_0600cf40) -

                      (short)*(int *)(iVar4 + iVar2));

  if ((0 < iVar3) && (*(int *)0x0607EA9C + -0x10 < iVar3)) {

    iVar2 = (int)DAT_0600cf42;

    iVar3 = *(int *)(iVar4 + iVar2) + 1;

    *(int *)(iVar4 + iVar2) = iVar3;

    *(int *)(iVar4 + iVar2 + -0xc) = iVar3;

    puVar1 = 0x0607EBD0;

    *(int *)(iVar4 + iVar2 + -8) = *(int *)0x0607EBD0 - *(int *)(iVar4 + iVar2 + 4);

    iVar2 = iVar2 + 4;

    *(int *)(iVar4 + iVar2) = *(int *)puVar1;

  }

  return iVar2;

}
