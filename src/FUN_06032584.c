int FUN_06032584()
{

  char *puVar1;

  int uVar2;

  int iVar3;

  int iVar4;

  char *unaff_r14;

  (*(int(*)())0x06026DBC)();

  (*(int(*)())0x06026E2E)(*(int *)(unaff_r14 + 0x00000000),*(int *)(unaff_r14 + 0x00000004),

             *(int *)(unaff_r14 + 0x00000008));

  (*(int(*)())0x06026EDE)((int)*(short *)(unaff_r14 + 0x0000000C));

  puVar1 = unaff_r14;

  if (((unsigned int)0xFFFFFFFC & (int)(char)unaff_r14[0x000002DC]) == 0) {

    puVar1 = 0x06081898;

  }

  *(char **)(unaff_r14 + 0x000002D4) = puVar1 + 0x00000054;

  iVar4 = 0x0000000D;

  do {

    iVar3 = iVar4;

    (*(int(*)())0x06026DBC)();

    (*(int(*)())0x06026F72)(*(int *)(unaff_r14 + 0x000002D4));

    (*(int(*)())0x0600A474)((int)(char)unaff_r14[(0x0000000D - iVar3) + 0x000002DE]);

    *(int *)(unaff_r14 + 0x000002D4) = *(int *)(unaff_r14 + 0x000002D4) + 0x00000030;

    (*(int(*)())0x06026DF8)();

    iVar4 = iVar4 + -1;

  } while (iVar4 != 0);

  uVar2 = (*(int(*)())0x06026DF8)();

  return uVar2;

}
