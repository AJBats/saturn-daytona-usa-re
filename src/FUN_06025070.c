extern int DAT_06025136;

void FUN_06025070()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  unsigned int uVar4;

  unsigned int uVar5;

  unsigned short uVar6;

  unsigned int uVar7;

  int *puVar8;

  int *puVar9;

  unsigned short *puVar10;

  puVar3 = 0x06059094;

  puVar2 = 0x06060F2C;

  puVar1 = 0x060610BC;

  uVar5 = 0;

  do {

    uVar7 = uVar5 & 0xffff;

    uVar4 = uVar5 & 0xff;

    uVar5 = uVar5 + 1;

    puVar8 = (int *)(puVar2 + uVar7 * 8);

    *puVar8 = 0;

    *(short *)(puVar8 + 1) = 0;

    *(short *)((int)puVar8 + 6) = DAT_06025136;

    **(short **)(puVar1 + (uVar4 * 0xc & 0xff) + 4) = 0;

  } while ((uVar5 & 0xffff) < 10);

  for (uVar5 = 0; (uVar5 & 0xffff) < 0xe; uVar5 = uVar5 + 1) {

    uVar6 = 0;

    puVar8 = (int *)(0x06060D7C + (uVar5 & 0xffff) * 8);

    uVar4 = (uVar5 & 0xff) * 0xc & 0xff;

    do {

      if ((*(unsigned short *)(puVar3 + (unsigned int)uVar6 * 2) & *(unsigned short *)*puVar8) != 0) {

        puVar9 = (int *)(puVar2 + (unsigned int)uVar6 * 8);

        *puVar9 = *(int *)(puVar1 + uVar4 + 4);

        puVar10 = (unsigned short *)(puVar3 + (unsigned int)uVar6 * 2);

        *(unsigned short *)(puVar9 + 1) = *puVar10;

        *(short *)((int)puVar9 + 6) = *(short *)(puVar1 + uVar4 + 8);

        *(unsigned short *)*puVar9 = *(unsigned short *)*puVar9 | *puVar10;

      }

      uVar6 = uVar6 + 1;

    } while (uVar6 < 10);

  }

  return;

}
