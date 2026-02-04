extern int DAT_0601748a;

extern int DAT_0601748c;

extern int DAT_0601748e;

extern int DAT_06017490;

extern int DAT_06017492;

extern int DAT_060175b4;

extern int DAT_060175b6;

extern int DAT_060175b8;

extern int DAT_060175ba;

extern int DAT_06017692;

extern int DAT_06017694;

extern int DAT_06017696;

extern int DAT_06017698;

extern int DAT_0601769a;

extern int DAT_0601769c;

extern int DAT_06017728;

extern int DAT_0601772a;

extern int DAT_0601772c;

extern int FUN_06017784();

int FUN_060173ac()
{

  char *puVar1;

  char *puVar2;

  int iVar3;

  int uVar4;

  unsigned int uVar5;

  char *puVar6;

  unsigned char bVar8;

  int iVar7;

  unsigned int uVar9;

  unsigned int uVar10;

  int iVar11;

  int iVar12;

  int *puVar13;

  int iVar14;

  short *puVar15;

  short auStack_7c [14];

  short auStack_60 [14];

  char auStack_44 [4];

  short auStack_40 [6];

  short auStack_34 [12];

  puVar1 = 0x06063750;

  iVar11 = (int)DAT_0601748a;

  (*(int(*)())0x06035228)();

  (*(int(*)())0x06035228)();

  puVar15 = (short *)0x06044B84;

  if (*(int *)0x0607EAE0 != 0) {

    puVar15 = (short *)0x06044BB4;

  }

  puVar13 = (int *)(puVar1 + DAT_0601748c);

  FUN_06017784(*puVar13,puVar13[1] + iVar11,*puVar15,puVar15[1]);

  FUN_06017784(*(int *)(puVar1 + DAT_0601748e),puVar13[1] + iVar11,puVar15[3],puVar15[4]);

  FUN_06017784(*(int *)(puVar1 + DAT_06017490),puVar13[1] + iVar11,puVar15[9],puVar15[10]);

  puVar2 = 0x06078900;

  uVar4 = *(int *)(0x06078900 + DAT_06017492);

  puVar6 = *(char **)0x060786A4;

  if ((int)0x000927BF <= (int)*(char **)0x060786A4) {

    puVar6 = 0x000927BF;

  }

  if ((*(unsigned int *)0x0607EBF4 & 1) == 0) {

    puVar6 = (char *)(*(int *)0x0607EBD0 * 5);

  }

  iVar3 = (*(int(*)())0x06005DD4)(puVar6);

  bVar8 = 0;

  do {

    uVar9 = (unsigned int)bVar8;

    auStack_40[bVar8] = auStack_7c[*(unsigned char *)(uVar9 + iVar3)];

    uVar5 = (unsigned int)bVar8;

    bVar8 = bVar8 + 1;

    auStack_34[uVar5 + 2] = auStack_60[*(unsigned char *)(uVar9 + iVar3)];

  } while (bVar8 < 8);

  FUN_06017784(auStack_44,*(int *)(puVar1 + DAT_060175b4) + iVar11,puVar15[6],puVar15[7]);

  iVar3 = (*(int(*)())0x06005DD4)(uVar4);

  bVar8 = 0;

  do {

    uVar5 = (unsigned int)bVar8;

    uVar10 = (unsigned int)bVar8;

    uVar9 = (unsigned int)bVar8;

    bVar8 = bVar8 + 1;

    auStack_40[uVar5] = auStack_7c[*(unsigned char *)(uVar10 + iVar3)];

    auStack_34[uVar9 + 2] = auStack_60[*(unsigned char *)(uVar10 + iVar3)];

  } while (bVar8 < 8);

  FUN_06017784(auStack_44,*(int *)(puVar1 + DAT_060175b4) + iVar11,puVar15[0xc],puVar15[0xd]);

  iVar11 = (*(int(*)())0x06034FE0)(*(int *)(puVar2 + DAT_060175b6) + 1,10);

  iVar3 = (*(int(*)())0x06035C2C)();

  if (*(int *)0x0607EAE0 == 0) {

    iVar12 = (int)DAT_06017692;

    iVar14 = 0x348;

    iVar7 = *(int *)(puVar2 + DAT_06017696) + 1;

    if (iVar7 < 0xb || 0xd < iVar7) {

      if (iVar3 == 1) {

        FUN_06017784(*(int *)(puVar1 + iVar14),*(int *)((int)(puVar1 + iVar14) + 4) + iVar12,

                     puVar15[0x15],puVar15[0x16]);

      }

      else if (iVar3 == 2) {

        FUN_06017784(*(int *)(puVar1 + DAT_06017698),*(int *)(puVar1 + iVar14 + 4) + iVar12,

                     puVar15[0x15],puVar15[0x16]);

      }

      else if (iVar3 == 3) {

        FUN_06017784(*(int *)(puVar1 + DAT_0601769a),*(int *)(puVar1 + iVar14 + 4) + iVar12,

                     puVar15[0x15],puVar15[0x16]);

      }

      else {

        FUN_06017784(*(int *)(puVar1 + DAT_0601769c),*(int *)(puVar1 + iVar14 + 4) + iVar12,

                     puVar15[0x15],puVar15[0x16]);

      }

    }

    else {

      FUN_06017784(*(int *)(puVar1 + DAT_06017728),*(int *)(puVar1 + iVar14 + 4) + iVar12,

                   puVar15[0x15],puVar15[0x16]);

    }

    if (iVar11 != 0) {

      FUN_06017784(*(int *)(puVar1 + (iVar11 + 0x5f) << 3),

                   *(int *)(puVar1 + DAT_0601772a) + (int)DAT_0601772c,puVar15[0xf],puVar15[0x10]);

    }

    uVar4 = FUN_06017784(*(int *)(puVar1 + (iVar3 + 0x5f) << 3),

                         *(int *)(puVar1 + DAT_0601772a) + (int)DAT_0601772c,puVar15[0x12],

                         puVar15[0x13]);

  }

  else {

    uVar4 = FUN_06017784(*(int *)(puVar1 + DAT_060175b8),

                         *(int *)((int)(puVar1 + DAT_060175b8) + 4) + (int)DAT_060175ba,puVar15[0xf]

                         ,puVar15[0x10]);

  }

  return uVar4;

}
