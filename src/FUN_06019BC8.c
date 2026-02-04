int FUN_06019bc8()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  int uVar4;

  int iVar5;

  unsigned char bVar6;

  puVar3 = 0x06028400;

  puVar2 = 0x06049B12;

  puVar1 = 0x0605D242;

  if (*(int *)0x06085FF0 == '\0') {

    bVar6 = 0;

    do {

      if ((unsigned int)bVar6 == *(unsigned int *)0x0605AD00) {

        if ((unsigned char)*puVar1 < 8) {

          iVar5 = 6;

        }

        else {

          iVar5 = 7;

          if (0x10 < (unsigned char)*puVar1) {

            *puVar1 = 0;

          }

        }

      }

      else {

        iVar5 = 3;

      }

      uVar4 = (*(void(*)())puVar3)(0xc,*(int *)

                                     (0x06063750 +

                                     (unsigned int)*(unsigned short *)(puVar2 + (unsigned int)bVar6 * 2) * 8),

                                ((unsigned int)(unsigned char)(0x06049B0C + (unsigned int)bVar6 * 2)[1] * 0x40 +

                                (unsigned int)(unsigned char)0x06049B0C[(unsigned int)bVar6 * 2]) * 2,

                                iVar5 * 0x1000 +

                                *(int *)((int)(0x06063750 +

                                              (unsigned int)*(unsigned short *)(puVar2 + (unsigned int)bVar6 * 2) * 8) + 4))

      ;

      bVar6 = bVar6 + 1;

    } while (bVar6 < 3);

  }

  else {

    bVar6 = 0;

    do {

      if ((unsigned int)bVar6 == *(unsigned int *)0x0605AD00) {

        iVar5 = 6;

      }

      else {

        iVar5 = 5;

      }

      uVar4 = (*(void(*)())puVar3)(0xc,*(int *)

                                     (0x06063750 +

                                     (unsigned int)*(unsigned short *)(puVar2 + (unsigned int)bVar6 * 2) * 8),

                                ((unsigned int)(unsigned char)(0x06049B0C + (unsigned int)bVar6 * 2)[1] * 0x40 +

                                (unsigned int)(unsigned char)0x06049B0C[(unsigned int)bVar6 * 2]) * 2,

                                iVar5 * 0x1000 +

                                *(int *)((int)(0x06063750 +

                                              (unsigned int)*(unsigned short *)(puVar2 + (unsigned int)bVar6 * 2) * 8) + 4))

      ;

      bVar6 = bVar6 + 1;

    } while (bVar6 < 3);

  }

  return uVar4;

}
