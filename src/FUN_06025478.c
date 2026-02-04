extern int DAT_060254de;

extern int DAT_060254e0;

extern int DAT_060254e2;

extern int DAT_060254e4;

extern int DAT_060254e6;

extern int DAT_060255cc;

extern int DAT_060255ce;

extern int DAT_060255d0;

extern int DAT_060255d2;

extern int DAT_060255d4;

extern int DAT_060255d6;

extern int DAT_060255d8;

extern int DAT_060255da;

extern int DAT_060255dc;

extern int DAT_060255de;

extern int PTR_DAT_060255e0;

extern int PTR_DAT_060255e0;

void FUN_06025478(param_1)
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

  sVar1 = DAT_060254de;

  iVar6 = 0xa8;

  iVar9 = 0xc08;

  iVar7 = 0x590;

  if (*(int *)0x06061198 == '\x04') {

    (*(int(*)())0x060284AE)(8,iVar9,0x90,0x060590B8);

    (*(int(*)())puVar3)(8,*(int *)(puVar2 + iVar7),(int)DAT_060254e6,

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

    (*(int(*)())puVar3)(8,*puVar10,(int)DAT_060255ce,puVar10[1]);

    (*(int(*)())puVar3)(8,*puVar10,(int)DAT_060255d0,puVar10[1]);

  }

  (*(int(*)())0x060284AE)(8,(int)DAT_060255d2,0x90,0x06058F94 + (param_1 << 3));

  (*(int(*)())puVar3)(8,*(int *)(puVar2 + DAT_060255d4),0x10,

                    *(int *)((int)(puVar2 + DAT_060255d4) + 4) + (int)DAT_060255d6);

  (*(int(*)())puVar3)(8,*(int *)(puVar2 + DAT_060255d8),0x2a0,

                    *(int *)((int)(puVar2 + DAT_060255d8) + 4) + (int)DAT_060255da);

  (*(int(*)())puVar3)(8,*(int *)(puVar2 + DAT_060255de),(int)PTR_DAT_060255e0,

                    *(int *)((int)(puVar2 + DAT_060255de) + 4) + (int)DAT_060255da);

  uVar11 = 0;

  piVar8 = (int *)(0x06061184 + (param_1 << 2));

  do {

    (*(int(*)())0x0601A3F4)(uVar11 & 0xffff,sVar1);

    if ((((unsigned int)*(unsigned short *)((uVar11 << 3) + *piVar8 + 6) != iVar6 + 0xcU) ||

        (*(int *)0x06061198 == '\x04')) || (*(int *)0x06061198 == '\x05')) {

      iVar7 = (uVar11 << 3);

      if ((unsigned int)*(unsigned short *)(*piVar8 + iVar7 + 6) == iVar6 + 0xcU) {

        uVar4 = 9;

      }

      else {

        uVar4 = 8;

      }

      piVar5 = (int *)(0x0605900C + iVar7);

      (*(int(*)())puVar3)(piVar5[1] << 2,*(int *)(puVar2 + *((int)(int)piVar5 << 3)),

                        ((unsigned int)(unsigned char)((char *)(0x06059074 + (uVar11 << 1)))[1] * 0x40 +

                        (unsigned int)(unsigned char)((int *)0x06059074)[(uVar11 << 1)]) << 1,

                        0x00008000 + *(int *)((int)(puVar2 + *((int)(int)piVar5 << 3)) + 4));

      (*(int(*)())puVar3)(piVar5[1] << 2,

                        *(int *)(puVar2 + (unsigned int)*(unsigned short *)(*piVar8 + iVar7 + 6) << 3),

                        ((unsigned int)(unsigned char)((char *)(0x06059084 + (uVar11 << 1)))[1] * 0x40 +

                        (unsigned int)(unsigned char)((int *)0x06059084)[(uVar11 << 1)]) << 1,

                        (unsigned int)(uVar4 << 12) +

                        *(int *)((int)(puVar2 + (unsigned int)*(unsigned short *)(*piVar8 + iVar7 + 6) << 3) + 4));

    }

    uVar11 = uVar11 + 1;

  } while ((int)uVar11 < 8);

  return;

}
