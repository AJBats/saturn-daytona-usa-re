void FUN_0601155e(param_1)
    unsigned short param_1;
{

  char *puVar1;

  unsigned short uVar2;

  unsigned int uVar3;

  unsigned int uVar4;

  short *puVar5;

  int iVar6;

  puVar1 = 0x0605AAA6;

  uVar2 = 0;

  iVar6 = *(int *)0x06063788;

  do {

    uVar3 = (unsigned int)uVar2;

    uVar4 = (unsigned int)uVar2;

    uVar2 = uVar2 + 1;

    puVar5 = (short *)(uVar4 * 0x58 + (unsigned int)(param_1 << 1) + iVar6 + 4);

    *(short *)(puVar1 + (uVar3 << 2)) = *puVar5;

    *(short *)((int)(puVar1 + (uVar3 << 2)) + 2) = puVar5[1];

  } while (uVar2 < 0x1c);

  (*(int(*)())0x06028400)(8,0x0605AAA2,(param_1 & 0x3f) << 1,

             0x0000F000 + *(int *)(0x06063788 + 4));

  return;

}
