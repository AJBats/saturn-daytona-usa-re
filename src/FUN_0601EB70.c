unsigned int FUN_0601eb70()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  unsigned int uVar6;

  unsigned int uVar7;

  int iVar8;

  puVar5 = 0x0605E09C;

  puVar4 = 0x0604A5AC;

  puVar3 = 0x0605E098;

  puVar2 = 0x060877D8;

  puVar1 = 0x0604A5C0;

  uVar6 = (unsigned int)(unsigned char)*0x06087080;

  if (uVar6 == 0) {

    for (uVar7 = 0; uVar6 = (unsigned int)(unsigned char)*puVar2 * 4, uVar7 < *(unsigned int *)(puVar1 + uVar6);

        uVar7 = uVar7 + 1) {

      *(char *)(*(int *)puVar3 + uVar7) = 0;

    }

    iVar8 = 0;

    do {

      *(char *)(*(int *)puVar5 + iVar8) = puVar4[iVar8];

      *(char *)(*(int *)puVar5 + iVar8 + 1) = puVar4[iVar8 + 1];

      iVar8 = iVar8 + 2;

    } while (iVar8 < 0x10);

  }

  return uVar6;

}
