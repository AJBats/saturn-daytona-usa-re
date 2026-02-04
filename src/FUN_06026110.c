unsigned int FUN_06026110()
{

  short sVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  unsigned int uVar6;

  unsigned int uVar7;

  unsigned int uVar8;

  unsigned short uVar9;

  puVar5 = 0x06060D7C;

  puVar4 = 0x060610BC;

  puVar3 = 0x0606107C;

  puVar2 = 0x06060F2C;

  *(int *)0x06061198 = 0;

  *(int *)0x06061199 = 0;

  uVar6 = (unsigned int)*(int *)0x06060D78;

  if (uVar6 == 0) {

    *(int *)0x06060D78 = 1;

    uVar7 = 0;

    do {

      uVar8 = uVar7 & 0xff;

      uVar7 = uVar7 + 1;

      uVar9 = 0;

      **(short **)(puVar4 + (uVar8 * 0xc & 0xff)) = 0;

      **(short **)((int)(puVar4 + (uVar8 * 0xc & 0xff)) + 4) = 0;

    } while ((uVar7 & 0xffff) < 0xe);

    do {

      if (**(short **)(puVar5 + (unsigned int)(uVar9 << 3)) != 0) break;

      uVar9 = uVar9 + 1;

    } while (uVar9 < 0xe);

    if (uVar9 < 0xe) {

      uVar6 = (*(int(*)())0x06025070)();

    }

    else {

      for (uVar7 = 0; (uVar7 & 0xffff) < 0xe; uVar7 = uVar7 + 1) {

        uVar9 = 0;

        do {

          sVar1 = *(short *)(puVar4 + ((uVar7 & 0xff) * 0xc & 0xff) + 8);

          if (*(short *)(puVar2 + (unsigned int)(uVar9 << 3) + 6) == sVar1) {

            sVar1 = *(short *)(puVar2 + (unsigned int)(uVar9 << 3) + 4);

            **(short **)(puVar5 + (uVar7 & 0xffff) << 3) = sVar1;

          }

          uVar6 = (unsigned int)sVar1;

          uVar9 = uVar9 + 1;

        } while (uVar9 < 10);

      }

    }

    uVar9 = 0;

    do {

      if (**(short **)(puVar5 + (unsigned int)(uVar9 << 3) + 4) != 0) break;

      uVar9 = uVar9 + 1;

    } while (uVar9 < 0xe);

    if (uVar9 < 0xe) {

      uVar6 = (*(int(*)())0x06025148)();

      return uVar6;

    }

    for (uVar7 = 0; (uVar7 & 0xffff) < 0xe; uVar7 = uVar7 + 1) {

      uVar9 = 0;

      do {

        sVar1 = *(short *)(puVar4 + ((uVar7 & 0xff) * 0xc & 0xff) + 8);

        if (*(short *)(puVar3 + (unsigned int)(uVar9 << 3) + 6) == sVar1) {

          sVar1 = *(short *)(puVar3 + (unsigned int)(uVar9 << 3) + 4);

          **(short **)(puVar5 + (uVar7 & 0xffff) << 3 + 4) = sVar1;

        }

        uVar6 = (unsigned int)sVar1;

        uVar9 = uVar9 + 1;

      } while (uVar9 < 8);

    }

  }

  return uVar6;

}
