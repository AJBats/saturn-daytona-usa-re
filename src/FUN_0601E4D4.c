extern int FUN_0601e764();

unsigned int FUN_0601e4d4()
{

  char *puVar1;

  char *puVar2;

  int iVar3;

  unsigned int uVar4;

  char *pcVar5;

  int iVar6;

  unsigned char *pbVar7;

  char local_28 [4];

  char local_24 [8];

  puVar1 = 0x2010001F;

  pbVar7 = 0x2010001F + 0x44;

  pcVar5 = local_28;

  local_28[0] = '\0';

  local_24[0] = '\0';

  local_28[1] = 0;

  local_24[1] = 0;

  local_28[2] = 0;

  local_24[2] = 0;

  for (iVar6 = 0; puVar2 = 0x06087094, iVar6 < (int)(unsigned int)*(unsigned short *)0x06087084;

      iVar6 = iVar6 + 1) {

    do {

    } while ((*pbVar7 & 1) == 1);

    *pbVar7 = 1;

    *puVar1 = 0x1a;

    do {

    } while ((*pbVar7 & 1) != 0);

    (**(void **)(*(int *)0x06000354 + 4))(*(short *)(puVar2 + iVar6 * 0x20 + 0x1c),0);

    iVar3 = FUN_0601e764((int)*(short *)(puVar2 + iVar6 * 0x20 + 0x1c),

                         0x0604A57C + (unsigned int)(unsigned char)*0x060877D8 * 0xc,

                         *(int *)0x0605E098);

    do {

    } while ((*pbVar7 & 1) == 1);

    *pbVar7 = 1;

    *puVar1 = 0x19;

    do {

    } while ((*pbVar7 & 1) != 0);

    if (iVar3 == 0) {

      local_24[iVar6] = '\x01';

    }

    if (puVar2[iVar6 * 0x20 + 0x1e] != '\0') {

      local_28[iVar6] = '\x01';

    }

  }

  uVar4 = 0;

  do {

    if (local_24[uVar4] != '\0') {

      return uVar4 & 0xff;

    }

    uVar4 = uVar4 + 1;

  } while ((int)uVar4 < 3);

  uVar4 = 3;

  while( 1 ) {

    if (local_28 + 3 <= pcVar5) {

      return 8;

    }

    if (*pcVar5 != '\0') break;

    pcVar5 = pcVar5 + 1;

    uVar4 = uVar4 + 1;

  }

  return uVar4 & 0xff;

}
