extern int DAT_06017d92;

extern int DAT_06017d94;

extern int DAT_06017d96;

extern int DAT_06017d98;

extern int DAT_06017d9a;

extern int DAT_06017ea6;

extern int DAT_06017ea8;

extern int DAT_06017eaa;

extern int DAT_06017fdc;

extern int DAT_06017fde;

extern int DAT_06017fe0;

extern int DAT_06017fe2;

extern int DAT_06017fe4;

extern int DAT_06017fe6;

extern int DAT_060180fc;

extern int DAT_060180fe;

extern int DAT_06018100;

extern int DAT_06018102;

extern int DAT_06018104;

extern int PTR_DAT_06017d9c;

extern int PTR_DAT_06017d9c;

extern int FUN_06018278();

void FUN_06017cec()
{

  unsigned short uVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  char *puVar6;

  short uVar7;

  int uVar8;

  int iVar9;

  int iVar10;

  int iVar11;

  int *puVar12;

  unsigned int uVar13;

  unsigned int uVar14;

  puVar5 = 0x06063F64;

  puVar4 = 0x060684EC;

  puVar3 = 0x0605BE10;

  puVar2 = 0x00088734;

  iVar10 = *(int *)0x0607E944;

  uVar8 = *(int *)0x06089E28;

  *(short *)0x0605BE2C = *(short *)0x0605BE2C + 1;

  *(short *)0x0605BE2E = *(short *)0x0605BE2E + 1;

  if (*(unsigned int *)(iVar10 + DAT_06017d92) < *(int *)0x06063F28 - 1U) {

    uVar1 = *(unsigned short *)(puVar4 + DAT_06017d94);

    uVar7 = DAT_06017d98;

  }

  else {

    uVar8 = *(int *)0x06089E2C;

    uVar1 = *(unsigned short *)(puVar4 + DAT_06017d94);

    uVar7 = DAT_06017d96;

  }

  *(short *)(puVar5 + (unsigned int)uVar1 * 8 + 6) = uVar7;

  iVar11 = (int)DAT_06017d9a;

  if (*(short *)0x0605BE2C < 6) {

    iVar9 = (int)PTR_DAT_06017d9c;

    *(int *)(puVar5 + (unsigned int)*(unsigned short *)(puVar4 + DAT_06017d94) * 8) =

         *(int *)(puVar5 + (unsigned int)*(unsigned short *)(puVar4 + DAT_06017d94) * 8) + iVar9;

    *(int *)(puVar5 + (unsigned int)*(unsigned short *)(puVar4 + iVar11) * 8) =

         *(int *)(puVar5 + (unsigned int)*(unsigned short *)(puVar4 + iVar11) * 8) + iVar9;

  }

  else {

    *(int *)(puVar5 + (unsigned int)*(unsigned short *)(puVar4 + DAT_06017ea6) * 8) = uVar8;

    *(int *)(puVar5 + (unsigned int)*(unsigned short *)(puVar4 + iVar11) * 8) =

         *(int *)0x06089E30;

    *(short *)0x0605BE2C = 0;

  }

  puVar6 = 0x06089E34;

  iVar11 = (int)DAT_06017ea8;

  if ((*(unsigned short *)0x0605BE2E & 3) == 0) {

    iVar9 = (int)DAT_06017eaa;

    *(int *)(puVar5 + (unsigned int)*(unsigned short *)(puVar4 + iVar9) * 8) =

         *(int *)0x06089E34;

    *(int *)(puVar5 + (unsigned int)*(unsigned short *)(puVar4 + iVar9 + 0x18) * 8) = *(int *)puVar6;

    *(int *)(puVar5 + (unsigned int)*(unsigned short *)(puVar4 + iVar9 + 0x2a) * 8) = *(int *)puVar6;

    *(int *)(puVar5 + (unsigned int)*(unsigned short *)(puVar4 + iVar9 + 0x3a) * 8) = *(int *)puVar6;

    *(int *)(puVar5 + (unsigned int)*(unsigned short *)(puVar4 + iVar9 + 0x4a) * 8) = *(int *)puVar6;

    puVar6 = 0x06089E38;

    *(int *)(puVar5 + (unsigned int)*(unsigned short *)(puVar4 + iVar11 + -8) * 8) =

         *(int *)0x06089E38;

    *(int *)(puVar5 + (unsigned int)*(unsigned short *)(puVar4 + iVar11) * 8) = *(int *)puVar6;

    *(int *)(puVar5 + (unsigned int)*(unsigned short *)(puVar4 + iVar9 + 0x20) * 8) = *(int *)puVar6;

    *(int *)(puVar5 + (unsigned int)*(unsigned short *)(puVar4 + iVar9 + 0x32) * 8) = *(int *)puVar6;

    *(int *)(puVar5 + (unsigned int)*(unsigned short *)(puVar4 + iVar9 + 0x42) * 8) = *(int *)puVar6;

  }

  else {

    iVar9 = (int)DAT_06017fdc;

    *(int *)(puVar5 + (unsigned int)*(unsigned short *)(puVar4 + iVar9) * 8) =

         *(int *)(puVar5 + (unsigned int)*(unsigned short *)(puVar4 + iVar9) * 8) + 0x40;

    *(int *)(puVar5 + (unsigned int)*(unsigned short *)(puVar4 + iVar11 + -8) * 8) =

         *(int *)(puVar5 + (unsigned int)*(unsigned short *)(puVar4 + iVar11 + -8) * 8) + 0x40;

    *(int *)(puVar5 + (unsigned int)*(unsigned short *)(puVar4 + iVar11) * 8) =

         *(int *)(puVar5 + (unsigned int)*(unsigned short *)(puVar4 + iVar11) * 8) + 0x40;

    *(int *)(puVar5 + (unsigned int)*(unsigned short *)(puVar4 + iVar9 + 0x18) * 8) =

         *(int *)(puVar5 + (unsigned int)*(unsigned short *)(puVar4 + iVar9 + 0x18) * 8) + 0x40;

    *(int *)(puVar5 + (unsigned int)*(unsigned short *)(puVar4 + iVar9 + 0x20) * 8) =

         *(int *)(puVar5 + (unsigned int)*(unsigned short *)(puVar4 + iVar9 + 0x20) * 8) + 0x40;

    *(int *)(puVar5 + (unsigned int)*(unsigned short *)(puVar4 + iVar9 + 0x2a) * 8) =

         *(int *)(puVar5 + (unsigned int)*(unsigned short *)(puVar4 + iVar9 + 0x2a) * 8) + 0x40;

    *(int *)(puVar5 + (unsigned int)*(unsigned short *)(puVar4 + iVar9 + 0x32) * 8) =

         *(int *)(puVar5 + (unsigned int)*(unsigned short *)(puVar4 + iVar9 + 0x32) * 8) + 0x40;

    *(int *)(puVar5 + (unsigned int)*(unsigned short *)(puVar4 + iVar9 + 0x3a) * 8) =

         *(int *)(puVar5 + (unsigned int)*(unsigned short *)(puVar4 + iVar9 + 0x3a) * 8) + 0x40;

    *(int *)(puVar5 + (unsigned int)*(unsigned short *)(puVar4 + iVar9 + 0x42) * 8) =

         *(int *)(puVar5 + (unsigned int)*(unsigned short *)(puVar4 + iVar9 + 0x42) * 8) + 0x40;

    *(int *)(puVar5 + (unsigned int)*(unsigned short *)(puVar4 + iVar9 + 0x4a) * 8) =

         *(int *)(puVar5 + (unsigned int)*(unsigned short *)(puVar4 + iVar9 + 0x4a) * 8) + 0x40;

  }

  if ((*(unsigned short *)0x0605BE2E & 0x10) == 0) {

    *(int *)(puVar5 + (unsigned int)*(unsigned short *)(puVar4 + DAT_06017fde) * 8) =

         *(int *)0x06089E40;

  }

  else {

    *(int *)(puVar5 + (unsigned int)*(unsigned short *)(puVar4 + DAT_06017fde) * 8) =

         *(int *)0x06089E40 + (int)DAT_06017fe0;

  }

  iVar10 = *(int *)(iVar10 + DAT_06017fe2);

  if ((iVar10 < DAT_06017fe4) || (DAT_06017fe6 < iVar10)) {

    *(short *)0x0605BE36 = 0;

  }

  else {

    *(short *)0x0605BE36 = 1;

  }

  if ((iVar10 < 0x4b) || (0x57 < iVar10)) {

    *(short *)0x0605BE38 = 0;

  }

  else {

    *(short *)0x0605BE38 = 4;

  }

  if ((DAT_060180fc <= iVar10) && (iVar10 <= DAT_060180fe)) {

    *(int *)puVar3 = *(int *)puVar3 + (int)DAT_06018100;

    *(int *)(puVar3 + 4) = *(int *)(puVar3 + 4) + (int)DAT_06018102;

    puVar4 = 0x06089E98;

    uVar13 = 0;

    do {

      (*(void(*)())0x06026DBC)();

      puVar12 = (int *)(0x06048078 + ((uVar13 & 0xff) * 0xc & 0xff));

      (*(void(*)())0x06026E2E)(*puVar12,puVar12[1],-puVar12[2]);

      (*(void(*)())0x06026EDE)(0x0000C000);

      (*(void(*)())0x06026F2A)(*(int *)puVar3 + (uVar13 & 3) * (int)DAT_06018104);

      puVar5 = 0x00200000;

      (*(void(*)())0x06031D8C)(0x00200000 + (int)puVar2,0xc);

      (*(void(*)())0x06031A28)(puVar5 + (int)0x000887C4,(int)*(short *)puVar4,3);

      (*(void(*)())0x06026DF8)();

      uVar14 = uVar13 + 1;

      (*(void(*)())0x06026DBC)();

      puVar12 = (int *)(0x06048078 + ((uVar14 & 0xff) * 0xc & 0xff));

      (*(void(*)())0x06026E2E)(*puVar12,puVar12[1],-puVar12[2]);

      (*(void(*)())0x06026EDE)(0x0000C000);

      (*(void(*)())0x06026F2A)(*(int *)(puVar3 + (uVar14 & 1) * 4) + (uVar14 & 3) * (int)DAT_06018104);

      (*(void(*)())0x06031D8C)(puVar5 + (int)puVar2,0xc);

      (*(void(*)())0x06031A28)(puVar5 + (int)0x000887C4,(int)*(short *)puVar4,3);

      (*(void(*)())0x06026DF8)();

      uVar13 = uVar13 + 2;

    } while ((int)uVar13 < 0xe);

  }

  (*(void(*)())0x06021178)();

  FUN_06018278();

  return;

}
