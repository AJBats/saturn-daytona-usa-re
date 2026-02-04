extern int DAT_0601fa26;

extern int DAT_0601fac4;

extern int DAT_0601fac6;

extern int DAT_0601fac8;

extern int DAT_0601faca;

extern int DAT_0601facc;

extern int DAT_0601face;

extern int DAT_0601fba6;

extern int DAT_0601fba8;

extern int DAT_0601fbaa;

extern int DAT_0601fbac;

extern int DAT_0601fbae;

extern int DAT_0601fbb0;

extern int DAT_0601fbb2;

extern int DAT_0601fbb4;

extern int DAT_0601fbb6;

extern int DAT_0601fbb8;

extern int DAT_0601fbba;

extern int DAT_0601fbbc;

extern int DAT_0601fbbe;

extern int DAT_0601fbc0;

extern int DAT_0601fbc2;

extern int DAT_0601fbc4;

extern int DAT_0601fbc6;

extern int DAT_0601fbc8;

extern int DAT_0601fc8e;

extern int DAT_0601fc90;

extern int DAT_0601fc92;

extern int DAT_0601fc94;

extern int DAT_0601fc96;

extern int DAT_0601fc98;

extern int DAT_0601fc9a;

extern int DAT_0601fc9c;

extern int DAT_0601fc9e;

extern int DAT_0601fca0;

extern int DAT_0601fca2;

extern int DAT_0601fca4;

extern int DAT_0601fca6;

extern int DAT_0601fca8;

extern int PTR_DAT_0601fa28;

extern int PTR_DAT_0601fa28;

extern int PTR_DAT_0601fd48;

extern int PTR_DAT_0601fd48;

void FUN_0601f9cc()
{

  short sVar1;

  char cVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  char *puVar6;

  int iVar7;

  int uVar8;

  int uVar9;

  int iVar10;

  int *puVar11;

  int iVar12;

  int *local_28;

  short auStack_24 [4];

  auStack_24[0] = DAT_0601fa26;

  (*(int(*)())0x0602853E)(0xc);

  (*(int(*)())0x06028560)();

  puVar4 = 0x06028400;

  puVar3 = 0x06063750;

  if (*(int *)0x06078644 == 1) {

    (*(int(*)())0x0600511E)(0x25E72194,0x00017700,0,8);

    (*(int(*)())0x0602761E)(0x25F00600,0x0604894C,0x20);

    cVar2 = *(int *)0x0605E05C;

    if (cVar2 == '\x04') {

      local_28 = (int *)(puVar3 + PTR_DAT_0601fa28);

      uVar8 = local_28[1];

      iVar7 = 0;

    }

    else {

      if (cVar2 != '\b') {

        if (cVar2 == '\f') {

          (*(int(*)())puVar4)(0xc,*(int *)(puVar3 + DAT_0601fac8),0x400,

                            *(int *)((int)(puVar3 + DAT_0601fac8) + 4));

        }

        goto LAB_0601fcd4;

      }

      local_28 = (int *)(puVar3 + DAT_0601fac4);

      uVar8 = local_28[1];

      iVar7 = 0x380;

    }

    (*(int(*)())puVar4)(0xc,*local_28,iVar7,uVar8);

  }

  else {

    (*(int(*)())0x0602761E)(0x25F00600,0x0605CD9C,0x20);

    puVar6 = 0x0605E0A4;

    puVar5 = 0x060284AE;

    iVar7 = 0x590;

    iVar10 = iVar7 + 8;

    iVar12 = 0x90;

    cVar2 = *(int *)0x0605E05C;

    if (cVar2 == '\x04') {

      (*(int(*)())0x060284AE)(0xc,0x80,iVar12,*(int *)0x0605E0A4);

      (*(int(*)())puVar4)(0xc,*(int *)(puVar3 + iVar10),0x98,

                        *(int *)((int)(puVar3 + iVar10) + 4));

      (*(int(*)())puVar5)(0xc,0x180,iVar12,*(int *)(puVar6 + 4));

      (*(int(*)())puVar5)(0xc,0x280,iVar12,*(int *)(puVar6 + 8));

      puVar11 = (int *)(puVar3 + iVar7);

      (*(int(*)())puVar4)(0xc,*puVar11,(int)DAT_0601fbae,puVar11[1]);

      (*(int(*)())puVar5)(0xc,0x400,iVar12,*(int *)(puVar6 + 0xc));

      (*(int(*)())puVar5)(0xc,0x500,iVar12,*(int *)(puVar6 + 0x10));

      (*(int(*)())puVar4)(0xc,*puVar11,(int)DAT_0601fbb4,puVar11[1]);

      (*(int(*)())puVar5)(0xc,0x600,iVar12,*(int *)(puVar6 + 0x14));

      (*(int(*)())puVar5)(0xc,0x700,iVar12,*(int *)(puVar6 + 0x18));

      (*(int(*)())puVar4)(0xc,*puVar11,0x730,puVar11[1]);

      (*(int(*)())puVar5)(0xc,0x800,iVar12,*(int *)(puVar6 + 0x1c));

      (*(int(*)())puVar5)(0xc,0x900,iVar12,*(int *)(puVar6 + 0x20));

      (*(int(*)())puVar5)(0xc,0xa00,iVar12,*(int *)(puVar6 + 0x24));

      (*(int(*)())puVar5)(0xc,0xb00,iVar12,*(int *)(puVar6 + 0x28));

      (*(int(*)())puVar4)(0xc,*puVar11,(int)DAT_0601fbc4,puVar11[1]);

      (*(int(*)())puVar5)(0xc,0xc80,iVar12,*(int *)0x0605E0E4);

      uVar9 = puVar11[1];

      uVar8 = *puVar11;

      sVar1 = DAT_0601fbc8;

    }

    else {

      if (cVar2 != '\b') {

        if (cVar2 == '\f') {

          (*(int(*)())0x060284AE)(0xc,0x480,iVar12,*(int *)0x0605E0DC);

          (*(int(*)())puVar4)(0xc,*(int *)(puVar3 + iVar10),0x498,

                            *(int *)((int)(puVar3 + iVar10) + 4));

          (*(int(*)())puVar5)(0xc,0x600,iVar12,*(int *)0x0605E0E0);

          puVar11 = (int *)(puVar3 + iVar7);

          (*(int(*)())puVar4)(0xc,*puVar11,0x620,puVar11[1]);

          (*(int(*)())puVar5)(0xc,0x800,iVar12,*(int *)0x0605E0E4);

          (*(int(*)())puVar4)(0xc,*puVar11,0x852,puVar11[1]);

        }

        goto LAB_0601fcd4;

      }

      (*(int(*)())0x060284AE)(0xc,0x380,iVar12,*(int *)0x0605E0D0);

      (*(int(*)())puVar4)(0xc,*(int *)(puVar3 + iVar10),0x398,

                        *(int *)((int)(puVar3 + iVar10) + 4));

      (*(int(*)())puVar5)(0xc,0x500,iVar12,*(int *)0x0605E0D4);

      puVar11 = (int *)(puVar3 + iVar7);

      (*(int(*)())puVar4)(0xc,*puVar11,(int)DAT_0601fc94,puVar11[1]);

      (*(int(*)())puVar5)(0xc,0x680,iVar12,*(int *)0x0605E0D8);

      (*(int(*)())puVar4)(0xc,*puVar11,0x6b2,puVar11[1]);

      (*(int(*)())puVar5)(0xc,0x880,iVar12,*(int *)0x0605E0E4);

      uVar9 = puVar11[1];

      uVar8 = *puVar11;

      sVar1 = DAT_0601fc9c;

    }

    (*(int(*)())puVar4)(0xc,uVar8,(int)sVar1,uVar9);

  }

LAB_0601fcd4:

  puVar3 = 0x06038BD4;

  (*(int(*)())0x06038BD4)(0x100,0);

  (*(int(*)())puVar3)(4,0);

  (*(int(*)())puVar3)(8,0);

  (*(int(*)())puVar3)(0x10,0);

  (*(int(*)())puVar3)(0x20,7);

  (*(int(*)())puVar3)(1,0);

  (*(int(*)())0x06036E90)(0x25E7FFFE,1,auStack_24);

  (*(int(*)())puVar3)(0x20,7);

  return;

}
