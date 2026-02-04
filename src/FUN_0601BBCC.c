extern int DAT_0601bcba;

int FUN_0601bbcc(param_1, param_2, param_3)
    int param_1;
    char param_2;
    unsigned int param_3;
{

  char cVar1;

  int bVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  char *puVar6;

  char *puVar7;

  int iVar8;

  int uVar9;

  int *puVar10;

  int iVar11;

  char *pcVar12;

  unsigned char bVar13;

  unsigned int uVar14;

  unsigned int local_44;

  char auStack_24 [8];

  puVar4 = 0x060284AE;

  puVar3 = 0x06028400;

  iVar11 = (int)DAT_0601bcba;

  iVar8 = (*(void(*)())0x06035228)();

  puVar7 = 0x06063920;

  puVar6 = 0x06063D08;

  puVar5 = 0x06063918;

  for (uVar14 = (unsigned int)param_2; (int)(uVar14 & 0xffff) < param_2 + 5; uVar14 = uVar14 + 1) {

    local_44 = (param_3 & 0xffff) * 0x40;

    (*(void(*)())puVar4)(8,(local_44 + 2) * 2,0x60,

                      *(int *)(0x0605DE64 + (uVar14 & 0xffff) * 4));

    pcVar12 = (char *)((uVar14 & 0xffff) * 0xc + param_1);

    (*(void(*)())puVar4)(8,(local_44 + 9) * 2,0x60,auStack_24);

    if (*pcVar12 != '\0') {

      (*(void(*)())puVar4)(8,((param_3 & 0xffff) * 0x40 + 9) * 2,0x60,pcVar12);

    }

    iVar8 = (uVar14 & 0xffff) * 0xc + param_1;

    uVar9 = (*(void(*)())0x06005DD4)(*(int *)(iVar8 + 4));

    (*(void(*)())puVar4)(8,((param_3 & 0xffff) * 0x40 + 0x10) * 2,0x78,uVar9);

    bVar13 = *(unsigned char *)(iVar8 + 8);

    bVar2 = 0xb < bVar13;

    if (bVar2) {

      bVar13 = bVar13 - 0xc;

    }

    if (9 < bVar13) {

      local_44 = 0x2000000;

    }

    iVar8 = (param_3 & 0xffff) * 0x40;

    (*(void(*)())puVar3)(8,*(int *)

                         (0x06063750 + ((local_44 >> 0x18) + (unsigned int)bVar2 + 0x3c) * 8),

                      (iVar8 + 0x21) * 2,

                      (unsigned int)bVar13 * 0x1000 +

                      *(int *)((int)(0x06063750 +

                                    ((local_44 >> 0x18) + (unsigned int)bVar2 + 0x3c) * 8) + 4));

    (*(void(*)())puVar4)(0xc,(iVar8 + 0x25) * 2,0x60,0x0604A4B8);

    if (*(char *)((uVar14 & 0xffff) * 0xc + param_1 + 10) != '\0') {

      if (*(int *)0x06078644 == 1) {

        iVar8 = *(int *)(puVar5 + 4);

        puVar10 = (int *)puVar5;

      }

      else {

        iVar8 = *(int *)(puVar6 + 4);

        puVar10 = (int *)puVar6;

      }

      (*(void(*)())puVar3)(0xc,*puVar10,((param_3 & 0xffff) * 0x40 + 0x25) * 2,iVar8 + iVar11);

    }

    cVar1 = *(char *)((uVar14 & 0xffff) * 0xc + param_1 + 9);

    iVar8 = (int)cVar1;

    if (cVar1 != '\0') {

      iVar8 = (*(void(*)())puVar3)(0xc,*(int *)puVar7,((param_3 & 0xffff) * 0x40 + 0x28) * 2,

                                0x00008000 + *(int *)(puVar7 + 4));

    }

    param_3 = param_3 + 3;

  }

  return iVar8;

}
