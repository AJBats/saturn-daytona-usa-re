extern int DAT_0600584e;

extern int DAT_06005850;

extern int DAT_06005852;

extern int DAT_0600590c;

extern int DAT_0600590e;

extern int DAT_06005910;

extern int PTR_DAT_06005854;

extern int PTR_DAT_06005854;

void FUN_06005788()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  int iVar4;

  short *puVar5;

  short *puVar6;

  short *puVar7;

  short *puVar8;

  int iVar9;

  int iVar10;

  int iVar11;

  puVar3 = 0x0606129C;

  puVar2 = 0x06063750;

  puVar1 = 0x06085FF4;

  iVar11 = 0x80;

  iVar10 = (int)DAT_0600584e;

  (*0x06028400)

            (8,*(int *)(0x06063750 + 0x20),0x80,

             *(int *)(0x06063750 + 0x24));

  if (*puVar1 != '\0') {

    iVar9 = (int)DAT_06005850;

    do {

      puVar5 = (short *)(*(int *)puVar3 + iVar9 + 0x18);

      puVar7 = (short *)(*(int *)puVar3 + iVar11 + 0x18);

      iVar4 = 0x15;

      do {

        iVar4 = iVar4 + -3;

        *puVar7 = *puVar5;

        puVar6 = puVar5 + 2;

        puVar7[1] = puVar5[1];

        puVar8 = puVar7 + 2;

        puVar5 = puVar5 + 3;

        puVar7 = puVar7 + 3;

        *puVar8 = *puVar6;

      } while (iVar4 != 0);

      iVar9 = iVar9 + 0x80;

      iVar11 = iVar11 + 0x80;

    } while (iVar9 < iVar10);

    (*0x060284AE)(8,(int)DAT_06005852,0x60,0x0605ACDF);

  }

  if (*puVar1 == '\0') {

    iVar10 = 7;

  }

  else {

    iVar10 = 5;

  }

  if ((*(unsigned int *)0x0607EAB8 & 1) == 0) {

    (*0x06028400)

              (8,*(int *)(puVar2 + 0x28),(iVar10 * 0x40 + 0x19) * 2,

               *(int *)(puVar2 + 0x2c));

  }

  if (*(unsigned int *)0x06063F28 < 10) {

    (*0x06028430)(8,(int)PTR_DAT_06005854,0,*(int *)0x06063F28);

  }

  else {

    (*0x06028430)(8,(int)DAT_0600590c,0xc,*(int *)0x06063F28);

  }

  if (*(int *)0x0607EAE0 == 0) {

    (*0x06028430)(8,(int)DAT_0600590e,0x30,*(int *)0x0607EA98);

  }

  if (*(int *)0x06078644 == 0) {

    if (*puVar1 == '\0') {

      iVar10 = 6;

    }

    else {

      iVar10 = 4;

    }

    (*0x06028400)

              (8,*(int *)(puVar2 + 0x30),(iVar10 * 0x40 + 0x16) * 2,

               *(int *)(puVar2 + 0x34) + (int)DAT_06005910);

    return;

  }

  return;

}
