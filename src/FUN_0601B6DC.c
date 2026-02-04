extern int DAT_0601b76c;

extern int DAT_0601b76e;

void FUN_0601b6dc()
{

  char cVar1;

  char *puVar2;

  int iVar3;

  unsigned char bVar4;

  unsigned char local_28 [4];

  unsigned char local_24 [8];

  puVar2 = 0x0608600E;

  (*0x06035228)();

  (*0x06035228)();

  if ((*(unsigned short *)(0x06063D98 + 2) & DAT_0601b76c) == 0) {

    if (((*(unsigned short *)(0x06063D98 + 2) & DAT_0601b76e) != 0) &&

       (cVar1 = *puVar2, *puVar2 = cVar1 + '\x01', '\x02' < (char)(cVar1 + '\x01'))) {

      *puVar2 = 0;

    }

  }

  else {

    cVar1 = *puVar2;

    *puVar2 = cVar1 + -1;

    if ((char)(cVar1 + -1) < '\0') {

      *puVar2 = 2;

    }

  }

  bVar4 = 0;

  do {

    if ((int)(char)*puVar2 == (unsigned int)bVar4) {

      if ((*(unsigned short *)0x0605D4F8 & 4) == 0) {

        iVar3 = 2;

      }

      else {

        iVar3 = 1;

      }

    }

    else {

      iVar3 = 2;

    }

    (*0x06028400)

              (8,*(int *)(0x06063750 + (bVar4 + 0x36) * 8),

               ((unsigned int)local_28[bVar4] * 0x40 + (unsigned int)local_24[bVar4]) * 2,

               iVar3 * 0x1000 + *(int *)((int)(0x06063750 + (bVar4 + 0x36) * 8) + 4));

    bVar4 = bVar4 + 1;

  } while (bVar4 < 3);

  return;

}
