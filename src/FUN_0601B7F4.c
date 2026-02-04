extern int DAT_0601b87e;

extern int DAT_0601b946;

void FUN_0601b7f4()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char cVar4;

  int *puVar5;

  char *puVar6;

  int iVar7;

  unsigned char bVar8;

  char auStack_38 [4];

  unsigned char local_34 [4];

  int local_30 [3];

  unsigned char local_24;

  unsigned char local_23;

  puVar1 = 0x06063750;

  (*(int(*)())0x06035228)();

  (*(int(*)())0x06035168)();

  (*(int(*)())0x06035228)();

  puVar6 = auStack_38;

  (*(int(*)())0x06035228)();

  puVar2 = 0x0608600E;

  if ((*(unsigned short *)(0x06063D98 + 2) & DAT_0601b87e) == 0) {

    if ((((unsigned int)*(unsigned short *)(0x06063D98 + 2) & (unsigned int)0x00008000) != 0) &&

       (cVar4 = ((int *)0x0605D4F4)[(char)*(int *)0x0608600E] + '\x01',

       ((int *)0x0605D4F4)[(char)*(int *)0x0608600E] = cVar4, (char)puVar6[(char)*puVar2] <= cVar4)) {

      ((int *)0x0605D4F4)[(char)*puVar2] = 0;

    }

  }

  else {

    cVar4 = ((int *)0x0605D4F4)[(char)*(int *)0x0608600E] + -1;

    ((int *)0x0605D4F4)[(char)*(int *)0x0608600E] = cVar4;

    if (cVar4 < '\0') {

      ((int *)0x0605D4F4)[(char)*puVar2] = puVar6[(char)*puVar2] + -1;

    }

  }

  puVar2 = 0x0605D4F4;

  bVar8 = 0;

  do {

    if ((int)(char)*puVar2 == (unsigned int)bVar8) {

      iVar7 = 1;

    }

    else {

      iVar7 = 4;

    }

    (*(int(*)())0x06011AF4)(local_30[bVar8],0xFFD40000,0x002F0000,0x001C0000,0x00008000,

               0x00010000,(unsigned int)bVar8 + iVar7 + 0x100);

    if ((int)(char)*puVar2 == (unsigned int)bVar8) {

      if (((*(unsigned short *)0x0605D4F8 & 8) == 0) && (*(int *)0x0608600E == '\0')) {

        iVar7 = 4;

      }

      else {

        iVar7 = 3;

      }

    }

    else {

      iVar7 = 4;

    }

    puVar5 = (int *)(puVar1 + (bVar8 + 0x30) << 3);

    (*(int(*)())0x06028400)(8,*puVar5,((unsigned int)local_34[bVar8] + (unsigned int)(local_24 << 6)) << 1,

               (iVar7 << 12) + puVar5[1]);

    puVar3 = 0x0605D4F5;

    bVar8 = bVar8 + 1;

  } while (bVar8 < 3);

  bVar8 = 0;

  do {

    if ((int)(char)*puVar3 == (unsigned int)bVar8) {

      if (((*(unsigned short *)0x0605D4F8 & 8) == 0) && (*(int *)0x0608600E == '\x01')) {

        iVar7 = 4;

      }

      else {

        iVar7 = 3;

      }

    }

    else {

      iVar7 = 4;

    }

    puVar5 = (int *)(puVar1 + (bVar8 + 0x33) << 3);

    (*(int(*)())0x06028400)(8,*puVar5,((unsigned int)local_34[bVar8] + (unsigned int)(local_23 << 6)) << 1,

               (iVar7 << 12) + puVar5[1]);

    bVar8 = bVar8 + 1;

  } while (bVar8 < 3);

  return;

}
