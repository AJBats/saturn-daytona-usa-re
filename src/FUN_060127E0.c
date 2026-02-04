extern int DAT_06012884;

extern int DAT_06012886;

extern int DAT_06012888;

extern int DAT_0601288a;

extern int DAT_0601288c;

extern int DAT_0601288e;

extern int DAT_06012890;

extern int DAT_0601299a;

extern int DAT_0601299c;

extern int DAT_0601299e;

extern int DAT_060129a0;

extern int DAT_060129a2;

extern int DAT_060129a4;

extern int DAT_060129a6;

extern int DAT_06012a92;

extern int DAT_06012a94;

extern int DAT_06012a96;

extern int DAT_06012a98;

extern int DAT_06012a9a;

extern int DAT_06012a9c;

extern int DAT_06012a9e;

extern int DAT_06012aa0;

int FUN_060127e0()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  char *puVar6;

  char *puVar7;

  int iVar8;

  int iVar9;

  int *puVar10;

  int iVar11;

  int *local_24;

  puVar1 = 0x060788F8;

  *(int *)0x0605B714 = *(int *)0x060788F8;

  *(unsigned int *)0x0605B6D8 = *(unsigned int *)0x0605B6D8 | 0x80;

  *(char **)puVar1 = 0x0004CCCC + *(int *)puVar1;

  puVar7 = 0x060284AE;

  puVar6 = 0x060788F4;

  puVar5 = 0x06063750;

  puVar4 = 0x06028400;

  puVar3 = 0x0605ACDD;

  puVar2 = 0x0601D5F4;

  puVar1 = 0x060283E0;

  iVar9 = *(int *)(*(int *)0x0607E944 + (int)DAT_06012884);

  iVar11 = (int)DAT_06012886;

  iVar8 = *(int *)0x060788F4;

  if (iVar8 == 0) {

    (*(void(*)())0x06028400)(0xc,*(int *)(0x06063750 + DAT_06012888),(int)DAT_0601288a,

               *(int *)((int)(0x06063750 + DAT_06012888) + 4));

    iVar9 = (*(void(*)())puVar4)(0xc,*(int *)(puVar5 + DAT_0601288c),(int)DAT_0601288e,

                              *(int *)((int)(puVar5 + DAT_0601288c) + 4));

    *(int *)puVar6 = *(int *)puVar6 + 1;

  }

  else if (iVar8 == 1) {

    if (iVar9 == 0x52) {

      *(int *)0x060788F4 = *(int *)0x060788F4 + 1;

      (*(void(*)())puVar1)(8,(int)DAT_0601299e,0x0000F000,puVar3);

      (*(void(*)())puVar1)(8,(int)DAT_060129a0,0x0000F000,puVar3);

      (*(void(*)())puVar1)(8,(int)DAT_060129a2,0x0000F000,puVar3);

      (*(void(*)())puVar4)(8,*(int *)(puVar5 + 0x78),(int)DAT_060129a6,

                        *(int *)(puVar5 + 0x7c) + (int)DAT_060129a4);

      iVar9 = (*(void(*)())puVar2)(0,0xAE1122FF);

    }

    else {

      if (((*(unsigned short *)0x06063D98 & *(unsigned short *)0x0608188C) == 0) &&

         (*(short *)0x0607ED8C == 0)) {

        local_24 = (int *)(0x06063750 + DAT_0601299a);

        iVar9 = local_24[1] + (int)DAT_0601299c;

      }

      else {

        local_24 = (int *)(0x06063750 + iVar11);

        iVar9 = local_24[1] + (int)DAT_06012890;

      }

      iVar9 = (*(void(*)())0x06028400)(8,*local_24,(int)DAT_0601299e,iVar9);

    }

  }

  else if (iVar8 == 2) {

    if (iVar9 == 0x58) {

      puVar10 = (int *)(0x06063750 + 0x70);

      *(int *)0x060788F4 = *(int *)0x060788F4 + 1;

      (*(void(*)())puVar4)(8,*puVar10,(int)DAT_060129a6,*(int *)(puVar5 + 0x74) + (int)DAT_060129a4);

      *(int *)0x06078654 = 1;

      *(int *)0x06063EF0 = *(int *)(*(int *)0x0607E944 + 0x30);

      iVar9 = (*(void(*)())puVar2)(0,0xAE1123FF);

    }

  }

  else if (iVar8 == 3) {

    if (iVar9 == 0x5d) {

      puVar10 = (int *)(0x06063750 + 0x68);

      *(int *)0x060788F4 = *(int *)0x060788F4 + 1;

      (*(void(*)())puVar4)(8,*puVar10,(int)DAT_060129a6,*(int *)(puVar5 + 0x6c) + (int)DAT_060129a4);

      iVar9 = (*(void(*)())puVar2)(0,0xAE1124FF);

    }

  }

  else if (iVar8 == 4) {

    if (iVar9 == 0x61) {

      *(int *)0x060788F4 = *(int *)0x060788F4 + 1;

      (*(void(*)())puVar4)(8,*(int *)(puVar5 + DAT_06012a92),(int)DAT_06012a96,

                        *(int *)((int)(puVar5 + DAT_06012a92) + 4) + (int)DAT_06012a94);

      iVar9 = (*(void(*)())puVar2)(0,0xAE1125FF);

      *(short *)0x06086056 = 0x14;

      *(int *)0x0608605A = 1;

    }

  }

  else if (iVar8 == 0x13) {

    (*(void(*)())0x060284AE)(8,(int)DAT_06012a96,iVar11,0x0605ACDD);

    (*(void(*)())puVar7)(8,(int)DAT_06012a98,iVar11,puVar3);

    (*(void(*)())puVar7)(8,(int)DAT_06012a9a,iVar11,puVar3);

    (*(void(*)())puVar1)(8,(int)DAT_06012a9c,0x0000F000,puVar3);

    (*(void(*)())puVar7)(0xc,(int)DAT_06012a9e,iVar11,0x0605AC9C);

    iVar9 = (*(void(*)())puVar7)(0xc,(int)DAT_06012aa0,iVar11,0x0605AC9C);

    *(int *)0x0605B714 = 0;

    *(int *)0x06078636 = 0;

  }

  else {

    *(int *)0x060788F4 = *(int *)0x060788F4 + 1;

    iVar9 = iVar8;

  }

  return iVar9;

}
