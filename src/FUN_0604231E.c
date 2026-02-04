extern int DAT_06042398;

extern int DAT_0604239a;

void FUN_0604231e()
{

  char *puVar1;

  int iVar2;

  puVar1 = 0x060A5400;

  iVar2 = 0;

  do {

    *(char *)(iVar2 + *(int *)puVar1) = 0;

    *(char *)(*(int *)puVar1 + 0x18 + iVar2) = 0;

    iVar2 = iVar2 + 1;

  } while (iVar2 < 0x17);

  *(int *)(*(int *)puVar1 + 0x30) = 0;

  *(int *)(*(int *)puVar1 + 0x34) = 0;

  *(int *)(*(int *)puVar1 + 0x38) = 0xffffffff;

  *(int *)(*(int *)puVar1 + 0x3c) = 0;

  *(int *)(*(int *)puVar1 + 0x4c) = 0;

  *(int *)(*(int *)puVar1 + 0x50) = 0;

  *(int *)(*(int *)puVar1 + 0x54) = 0;

  *(int *)(*(int *)puVar1 + 0x58) = 0;

  iVar2 = (int)DAT_06042398;

  *(int *)(*(int *)puVar1 + iVar2) = 0;

  *(int *)(*(int *)puVar1 + iVar2 + 8) = 0;

  *(int *)(*(int *)puVar1 + iVar2 + 0x24) = 0;

  *(int *)(*(int *)puVar1 + iVar2 + 0x34) = 0;

  *(int *)(*(int *)puVar1 + iVar2 + 0x44) = 0;

  *(int *)(*(int *)puVar1 + iVar2 + 0x5c) = 0;

  iVar2 = (int)DAT_0604239a;

  *(int *)(*(int *)puVar1 + iVar2) = 0;

  *(int *)(*(int *)puVar1 + iVar2 + 4) = 0;

  return;

}
