int FUN_06019fb2()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  int uVar4;

  int iVar5;

  unsigned char bVar6;

  puVar3 = 0x0605D242;

  puVar2 = 0x06028400;

  puVar1 = 0x06049B2C;

  if (*(int *)0x06085FF0 == '\x02') {

    bVar6 = 0;

    do {

      if ((unsigned int)bVar6 == *(unsigned int *)0x0605AD04) {

        if ((unsigned char)*puVar3 < 8) {

          iVar5 = 6;

        }

        else {

          iVar5 = 7;

          if (0x10 < (unsigned char)*puVar3) {

            *puVar3 = 0;

          }

        }

      }

      else {

        iVar5 = 3;

      }

      uVar4 = (*(int(*)())puVar2)(0xc,*(int *)

                                     (0x06063750 +

                                     (unsigned int)*(unsigned short *)(puVar1 + (unsigned int)(bVar6 << 1)) << 3),

                                ((unsigned int)(unsigned char)((char *)(0x06049B22 + (unsigned int)(bVar6 << 1)))[1] * 0x40 +

                                (unsigned int)(unsigned char)((int *)0x06049B22)[(unsigned int)(bVar6 << 1)]) << 1,

                                (iVar5 << 12) +

                                *(int *)((int)(0x06063750 +

                                              (unsigned int)*(unsigned short *)(puVar1 + (unsigned int)(bVar6 << 1)) << 3) + 4))

      ;

      bVar6 = bVar6 + 1;

    } while (bVar6 < 5);

  }

  else {

    bVar6 = 0;

    do {

      if ((unsigned int)bVar6 == *(unsigned int *)0x0605AD04) {

        iVar5 = 6;

      }

      else {

        iVar5 = 5;

      }

      uVar4 = (*(int(*)())puVar2)(0xc,*(int *)

                                     (0x06063750 +

                                     (unsigned int)*(unsigned short *)(puVar1 + (unsigned int)(bVar6 << 1)) << 3),

                                ((unsigned int)(unsigned char)((char *)(0x06049B22 + (unsigned int)(bVar6 << 1)))[1] * 0x40 +

                                (unsigned int)(unsigned char)((int *)0x06049B22)[(unsigned int)(bVar6 << 1)]) << 1,

                                (iVar5 << 12) +

                                *(int *)((int)(0x06063750 +

                                              (unsigned int)*(unsigned short *)(puVar1 + (unsigned int)(bVar6 << 1)) << 3) + 4))

      ;

      bVar6 = bVar6 + 1;

    } while (bVar6 < 5);

  }

  return uVar4;

}
