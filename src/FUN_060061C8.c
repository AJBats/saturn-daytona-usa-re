void FUN_060061c8()
{

  char *puVar1;

  int iVar2;

  int iVar3;

  int uVar4;

  int iVar5;

  iVar2 = *(int *)0x0607E940;

  iVar5 = *(int *)(iVar2 + 0x10);

  uVar4 = *(int *)(iVar2 + 0x14);

  iVar3 = *(int *)(iVar2 + 0x18);

  (*0x06026DBC)();

  (*0x06026E0C)();

  (*0x06026EDE)(*(int *)(iVar2 + 0x30));

  puVar1 = 0x06026FFC;

  (*0x06026FFC)(0x0604464C,0x06063E9C);

  (*puVar1)(0x06044640,0x06063EB0);

  (*puVar1)(0x06044658,0x06063ED8);

  (*puVar1)(0x06044664,0x06063EC4);

  puVar1 = 0x06063E9C;

  *(int *)0x06063E9C = *(int *)0x06063E9C + iVar5;

  *(int *)(puVar1 + 4) = uVar4;

  *(int *)(puVar1 + 8) = *(int *)(puVar1 + 8) + iVar3;

  puVar1 = 0x06063EB0;

  *(int *)0x06063EB0 = *(int *)0x06063EB0 + iVar5;

  *(int *)(puVar1 + 4) = uVar4;

  *(int *)(puVar1 + 8) = *(int *)(puVar1 + 8) + iVar3;

  puVar1 = 0x06063ED8;

  *(int *)0x06063ED8 = *(int *)0x06063ED8 + iVar5;

  *(int *)(puVar1 + 4) = uVar4;

  *(int *)(puVar1 + 8) = *(int *)(puVar1 + 8) + iVar3;

  puVar1 = 0x06063EC4;

  *(int *)0x06063EC4 = *(int *)0x06063EC4 + iVar5;

  *(int *)(puVar1 + 4) = uVar4;

  *(int *)(puVar1 + 8) = *(int *)(puVar1 + 8) + iVar3;

  *(int *)0x06089EDC = *(int *)0x06089EDC + -0x30;

  return;

}
