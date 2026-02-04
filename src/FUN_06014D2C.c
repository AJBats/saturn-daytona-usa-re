extern int DAT_06014de4;

extern void FUN_06014f34();

void FUN_06014d2c()
{

  char *puVar1;

  char *puVar2;

  short uVar3;

  int iVar4;

  char *puVar5;

  unsigned char bVar6;

  puVar2 = 0x06085F90;

  puVar1 = 0x06063F64;

  puVar5 = 0x06085F94;

  if ((*0x06085F89 == '\0') && ((*(unsigned short *)0x06063D9A & DAT_06014de4) != 0)) {

    if ((*(unsigned int *)0x0607EBF4 & 1) == 0) {

      if (*(unsigned short *)0x06085F90 < 0xc || 0x15 < *(unsigned short *)0x06085F90) {

        if (3 < *(unsigned short *)0x06085F90 && *(unsigned short *)0x06085F90 < 0x16) {

          *0x06085F89 = 1;

          *(short *)puVar5 = 1;

          *(short *)puVar2 = *(short *)puVar2 + 0x12;

        }

      }

      else {

        *0x06085F89 = 1;

        bVar6 = 8;

        do {

          (*0x060172E4)(bVar6);

          bVar6 = bVar6 + 1;

        } while (bVar6 < 0x10);

        *(short *)puVar5 = 1;

        uVar3 = 0x20;

        if (0x14 < *(unsigned short *)puVar2) {

          uVar3 = 0x22;

        }

        *(short *)puVar2 = uVar3;

      }

    }

    else if (*(unsigned short *)0x06085F90 < 0xc || 0x16 < *(unsigned short *)0x06085F90) {

      if (3 < *(unsigned short *)0x06085F90 && *(unsigned short *)0x06085F90 < 0x17) {

        *0x06085F89 = 1;

        *(short *)puVar5 = 1;

        *(short *)puVar2 = *(short *)puVar2 + 0x13;

      }

    }

    else {

      *0x06085F89 = 1;

      bVar6 = 8;

      do {

        (*0x060172E4)(bVar6);

        bVar6 = bVar6 + 1;

      } while (bVar6 < 0x10);

      *(short *)puVar5 = 1;

      uVar3 = 0x23;

      if (0x14 < *(unsigned short *)puVar2) {

        uVar3 = 0x26;

      }

      *(short *)puVar2 = uVar3;

    }

  }

  if (*0x06085F8A != '\0') {

    (*0x06020CF4)();

  }

  FUN_06014f34();

  (*0x0601712C)();

  bVar6 = 0;

  iVar4 = *(int *)0x06085F98;

  do {

    puVar5 = *(char **)(0x06084FC8 + (short)((unsigned short)bVar6 * 0x44) + 0x2c);

    if ((puVar5 == (char *)0x0 || puVar5 == 0x00008000) || puVar5 == 0x00010000) {

      *(short *)(puVar1 + ((unsigned int)bVar6 + iVar4) * 8 + 6) = 0x4c;

      uVar3 = 0x50;

    }

    else {

      *(short *)(puVar1 + ((unsigned int)bVar6 + iVar4) * 8 + 6) = 0x44;

      uVar3 = 0x48;

    }

    bVar6 = bVar6 + 1;

    *(short *)(puVar1 + (iVar4 + 6) * 8 + 6) = uVar3;

  } while (bVar6 < 8);

  return;

}
