extern int DAT_06020db2;

void FUN_06020cf4()
{

  short uVar1;

  char *puVar2;

  char *puVar3;

  puVar2 = 0x06087C6C;

  uVar1 = DAT_06020db2;

  *(short *)(0x06087C6C + 8) = DAT_06020db2;

  *(short *)(puVar2 + 10) = uVar1;

  *(short *)(puVar2 + 0xc) = uVar1;

  *(short *)(puVar2 + 0xe) = uVar1;

  *(short *)(puVar2 + 0x10) = uVar1;

  *(short *)(puVar2 + 0x12) = uVar1;

  *(short *)(puVar2 + 0x14) = uVar1;

  *(short *)(puVar2 + 0x16) = uVar1;

  *(short *)(puVar2 + 6) = 0x17;

  puVar2[4] = 0;

  puVar2[5] = 0x3a;

  puVar3 = 0x060785FC;

  (*(int(*)())0x060280F8)(puVar2,*(int *)0x060785FC);

  *(int *)0x0605A008 = *(int *)0x0605A008 + 1;

  *(int *)puVar3 = *(int *)puVar3 + 0x20;

  return;

}
