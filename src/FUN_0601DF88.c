extern int DAT_0601e022;

extern int DAT_0601e024;

extern int DAT_0601e026;

extern int DAT_0601e028;

extern int DAT_0601e02a;

extern int DAT_0601e02c;

extern int DAT_0601e02e;

extern int DAT_0601e0e2;

extern int DAT_0601e0e4;

extern int DAT_0601e0e6;

extern int PTR_DAT_0601e030;

extern int PTR_DAT_0601e030;

extern int FUN_0601e26c();

int FUN_0601df88()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  char *puVar6;

  int uVar7;

  int iVar8;

  puVar5 = 0x06028400;

  puVar4 = 0x0607863C;

  puVar3 = 0x06063750;

  puVar2 = 0x000927BF;

  puVar1 = 0x0000A000;

  iVar8 = (int)DAT_0601e022;

  if (*(unsigned int *)(0x06078900 + iVar8 + -0x68) < *(unsigned int *)0x06086008) {

    (*(void(*)())0x06028400)(8,*(int *)(0x06063750 + DAT_0601e024),(int)DAT_0601e026,

               0x0000A000 + *(int *)((int)(0x06063750 + DAT_0601e024) + 4));

    FUN_0601e26c(*(int *)(0x06078900 + DAT_0601e028));

    (*(void(*)())puVar5)(8,0x0605DFF4,(int)DAT_0601e02a,puVar1 + *(int *)(puVar3 + iVar8 + 4));

  }

  FUN_0601e26c(*(int *)puVar4);

  uVar7 = (*(void(*)())puVar5)(8,0x0605DFF4,(int)DAT_0601e02c,

                            0x00009000 + *(int *)(puVar3 + iVar8 + 4));

  if (*(unsigned int *)puVar4 < *(unsigned int *)0x06086004) {

    (*(void(*)())puVar5)(8,*(int *)(puVar3 + DAT_0601e02e),(int)PTR_DAT_0601e030,

                      puVar1 + *(int *)((int)(puVar3 + DAT_0601e02e) + 4));

    if (*(char **)puVar4 < puVar2) {

      FUN_0601e26c(*(int *)puVar4);

    }

    else {

      FUN_0601e26c(puVar2);

    }

    (*(void(*)())puVar5)(8,0x0605DFF4,(int)DAT_0601e0e2,

                      0x00009000 + *(int *)(puVar3 + iVar8 + 4));

    puVar6 = 0x0605DFEC;

    *(int *)0x0605DFEC = *(int *)0x0605DFEC + '@';

    if ((char)*puVar6 < '\0') {

      uVar7 = (*(void(*)())0x060283E0)(8,(int)DAT_0601e0e6,0x0000E000,0x0605ACE3);

      return uVar7;

    }

    if (*(char **)puVar4 < puVar2) {

      FUN_0601e26c(*(int *)puVar4);

    }

    else {

      FUN_0601e26c(puVar2);

    }

    uVar7 = (*(void(*)())puVar5)(8,0x0605DFF4,(int)DAT_0601e0e4,

                              puVar1 + *(int *)(puVar3 + iVar8 + 4));

  }

  return uVar7;

}
