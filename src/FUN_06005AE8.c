extern int DAT_06005b7c;

extern int DAT_06005b7e;

extern int DAT_06005b80;

extern int DAT_06005b82;

extern int DAT_06005b84;

extern int DAT_06005b86;

extern int DAT_06005b88;

extern int DAT_06005b8a;

extern int DAT_06005c74;

extern int DAT_06005c76;

extern int PTR_DAT_06005b8c;

extern int PTR_DAT_06005b8c;

extern int PTR_DAT_06005c78;

extern int PTR_DAT_06005c78;

int FUN_06005ae8()
{

  short sVar1;

  short sVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  char *puVar6;

  char *puVar7;

  int bVar8;

  unsigned int uVar9;

  int iVar10;

  puVar7 = 0x06028430;

  puVar6 = 0x06063E0C;

  puVar5 = 0x06063E10;

  puVar4 = 0x0607EAAC;

  puVar3 = 0x06085FF4;

  iVar10 = *(int *)0x0607E944;

  if (*(int *)(iVar10 + DAT_06005b7c) + 1U <= *(unsigned int *)0x06063F28) {

    (*(void(*)())0x06028430)(8,(int)DAT_06005b7e,0xc);

  }

  sVar1 = DAT_06005b82;

  if (*puVar3 != '\0') {

    sVar1 = DAT_06005b80;

  }

  if (*(int *)0x06078644 == 0) {

    uVar9 = (unsigned int)(*(int *)(iVar10 + 8) * (int)0x00009F1A) >> 0x10;

  }

  else {

    uVar9 = *(unsigned int *)(iVar10 + 8);

  }

  (*(void(*)())puVar7)(8,(int)sVar1,0x24,uVar9);

  if (*(int *)0x0607EAE0 == 0) {

    (*(void(*)())puVar7)(8,(int)DAT_06005b86,0x30,*(int *)(iVar10 + DAT_06005b84) + 1);

  }

  sVar1 = DAT_06005b8a;

  if (*puVar3 != '\0') {

    sVar1 = DAT_06005b88;

  }

  sVar2 = DAT_06005c74;

  if (*(int *)0x0607EAB8 != 0) {

    sVar2 = PTR_DAT_06005b8c;

  }

  (*(void(*)())puVar7)(8,(int)sVar1,0x6c,*(short *)(iVar10 + sVar2) + 1);

  iVar10 = (int)(char)*puVar3;

  if (iVar10 == 0) {

    bVar8 = 1;

    if ((*(unsigned int *)0x0607EBC4 & (unsigned int)0x00020000) != 0) {

      if (*(int *)puVar4 == 0x78) {

        *(int *)puVar6 = 0x3c;

        *(int *)puVar5 = 8;

      }

      if ((*(int *)puVar4 < 0x78) &&

         (iVar10 = *(int *)puVar5, *(int *)puVar5 = iVar10 + -1, iVar10 + -1 == 0)) {

        (*(void(*)())0x0601D5F4)(0,0xAE1114FF);

        iVar10 = *(int *)puVar6;

        *(int *)puVar6 = iVar10 + -3;

        if (iVar10 + -3 < 8) {

          *(int *)puVar6 = 8;

        }

        *(int *)puVar5 = (*(int *)puVar6 >> 3) + 1;

        bVar8 = 0;

      }

    }

    if (!bVar8) {

      iVar10 = (*(void(*)())0x060284AE)(8,0xa6,0x60,0x0605ACF3);

      return iVar10;

    }

    iVar10 = (*(void(*)())0x06034FE0)();

    if (DAT_06005c76 < iVar10) {

      iVar10 = (int)DAT_06005c76;

    }

    iVar10 = (*(void(*)())puVar7)(8,(int)PTR_DAT_06005c78,0x18,iVar10);

  }

  return iVar10;

}
