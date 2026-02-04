extern int DAT_0602528a;

extern int DAT_0602528c;

extern int DAT_0602528e;

extern int DAT_06025290;

extern int DAT_06025292;

extern int DAT_06025378;

extern int DAT_0602537a;

extern int DAT_0602537c;

extern int DAT_0602537e;

extern int DAT_06025380;

extern int DAT_06025382;

extern int DAT_06025384;

extern int DAT_06025386;

extern int DAT_06025388;

extern int DAT_0602538a;

extern int PTR_DAT_0602538c;

extern int PTR_DAT_0602538c;

void FUN_06025224(param_1)
    int param_1;
{

  short sVar1;

  char *puVar2;

  char *puVar3;

  unsigned short uVar4;

  int *piVar5;

  int iVar6;

  int iVar7;

  int *piVar8;

  int iVar9;

  int *puVar10;

  unsigned int uVar11;

  puVar3 = 0x06028400;

  puVar2 = 0x06063750;

  sVar1 = DAT_0602528a;

  iVar6 = 0xa9;

  iVar9 = 0xc08;

  iVar7 = 0x590;

  if (*(int *)0x06061198 == '\x04') {

    (*(int(*)())0x060284AE)(8,iVar9,0x90,0x060590B8);

    (*(int(*)())puVar3)(8,*(int *)(puVar2 + iVar7),(int)DAT_06025292,

                      *(int *)((int)(puVar2 + iVar7) + 4));

  }

  else {

    if (*(int *)0x06061198 == '\x05') {

      (*(int(*)())0x060284AE)(8,iVar9,0x90,0x060590E0);

    }

    else {

      (*(int(*)())0x060284AE)(8,iVar9,0x90,0x06059104);

    }

    puVar10 = (int *)(puVar2 + iVar7);

    (*(int(*)())puVar3)(8,*puVar10,(int)DAT_0602537a,puVar10[1]);

    (*(int(*)())puVar3)(8,*puVar10,(int)DAT_0602537c,puVar10[1]);

  }

  (*(int(*)())0x060284AE)(8,(int)DAT_0602537e,0x90,0x06058F94 + (param_1 << 3));

  (*(int(*)())puVar3)(8,*(int *)(puVar2 + DAT_06025380),0x10,

                    *(int *)((int)(puVar2 + DAT_06025380) + 4) + (int)DAT_06025382);

  (*(int(*)())puVar3)(8,*(int *)(puVar2 + DAT_06025384),0x2a0,

                    *(int *)((int)(puVar2 + DAT_06025384) + 4) + (int)DAT_06025386);

  (*(int(*)())puVar3)(8,*(int *)(puVar2 + DAT_0602538a),(int)PTR_DAT_0602538c,

                    *(int *)((int)(puVar2 + DAT_0602538a) + 4) + (int)DAT_06025386);

  uVar11 = 0;

  piVar8 = (int *)(0x06061170 + (param_1 << 2));

  do {

    (*(int(*)())0x0601A3F4)(uVar11 & 0xffff,sVar1);

    if ((((unsigned int)*(unsigned short *)((uVar11 << 3) + *piVar8 + 6) != iVar6 + 0xbU) ||

        (*(int *)0x06061198 == '\x04')) || (*(int *)0x06061198 == '\x05')) {

      iVar7 = (uVar11 << 3);

      if ((unsigned int)*(unsigned short *)(*piVar8 + iVar7 + 6) == iVar6 + 0xbU) {

        uVar4 = 9;

      }

      else {

        uVar4 = 8;

      }

      piVar5 = (int *)(0x06058FBC + iVar7);

      (*(int(*)())puVar3)(piVar5[1] << 2,*(int *)(puVar2 + *((int)(int)piVar5 << 3)),

                        ((unsigned int)(unsigned char)((char *)(0x0605904C + (uVar11 << 1)))[1] * 0x40 +

                        (unsigned int)(unsigned char)((int *)0x0605904C)[(uVar11 << 1)]) << 1,

                        0x00008000 + *(int *)((int)(puVar2 + *((int)(int)piVar5 << 3)) + 4));

      (*(int(*)())puVar3)(piVar5[1] << 2,

                        *(int *)(puVar2 + (unsigned int)*(unsigned short *)(*piVar8 + iVar7 + 6) << 3),

                        ((unsigned int)(unsigned char)((char *)(0x06059060 + (uVar11 << 1)))[1] * 0x40 +

                        (unsigned int)(unsigned char)((int *)0x06059060)[(uVar11 << 1)]) << 1,

                        (unsigned int)(uVar4 << 12) +

                        *(int *)((int)(puVar2 + (unsigned int)*(unsigned short *)(*piVar8 + iVar7 + 6) << 3) + 4));

    }

    uVar11 = uVar11 + 1;

  } while ((int)uVar11 < 10);

  return;

}
