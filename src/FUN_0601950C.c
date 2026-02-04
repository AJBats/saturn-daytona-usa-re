extern int DAT_060195ac;

extern int DAT_060195ae;

extern int DAT_06019694;

extern int DAT_06019696;

extern int PTR_DAT_060195b0;

extern int PTR_DAT_060195b0;

unsigned int FUN_0601950c()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  char *puVar6;

  unsigned int uVar7;

  int *puVar8;

  char cVar9;

  puVar5 = 0x06049AEC;

  puVar4 = 0x0605D244;

  puVar3 = 0x06063750;

  puVar2 = 0x06028400;

  puVar1 = 0x06049AF4;

  if (*0x06085FF1 != '\0') {

    (*0x06028400)

              (0xc,*(int *)(0x06063750 + DAT_060195ac),0x14,

               *(int *)((int)(0x06063750 + DAT_060195ac) + 4) + (int)DAT_060195ae);

    cVar9 = '\0';

    do {

      if (cVar9 != *puVar4) {

        puVar8 = (int *)(puVar3 + (unsigned int)*(unsigned short *)(puVar1 + cVar9 * 2) * 8);

        (*puVar2)(0xc,*puVar8,

                          ((unsigned int)(unsigned char)(puVar5 + cVar9 * 2)[1] * 0x40 +

                          (unsigned int)(unsigned char)puVar5[cVar9 * 2]) * 2,puVar8[1] + (int)PTR_DAT_060195b0

                         );

      }

      cVar9 = cVar9 + '\x01';

      *0x06085FF1 = 0;

    } while (cVar9 < '\x04');

  }

  puVar6 = 0x0605D242;

  uVar7 = (unsigned int)(unsigned char)*0x06085FF5;

  if (uVar7 == 0) {

    if ((unsigned char)*0x0605D242 < 0x10) {

      puVar8 = (int *)(puVar3 + (unsigned int)*(unsigned short *)(puVar1 + (char)*puVar4 * 2) * 8);

      uVar7 = (*puVar2)(0xc,*puVar8,

                                ((unsigned int)(unsigned char)(puVar5 + (char)*puVar4 * 2)[1] * 0x40 +

                                (unsigned int)(unsigned char)puVar5[(char)*puVar4 * 2]) * 2,

                                puVar8[1] + (int)DAT_06019694);

    }

    else {

      (*0x060284AE)

                (0xc,((unsigned int)(unsigned char)(puVar5 + (char)*puVar4 * 2)[1] * 0x40 +

                     (unsigned int)(unsigned char)puVar5[(char)*puVar4 * 2]) * 2,(int)DAT_06019696,

                 *(int *)0x0605D4EC);

      uVar7 = (*0x060284AE)

                        (0xc,(((unsigned char)(puVar5 + (char)*puVar4 * 2)[1] + 2) * 0x40 +

                             (unsigned int)(unsigned char)puVar5[(char)*puVar4 * 2]) * 2,(int)DAT_06019696,

                         *(int *)0x0605D4EC);

      if (0x1e < (unsigned char)*puVar6) {

        *puVar6 = 0;

      }

    }

  }

  return uVar7;

}
