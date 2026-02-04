extern int DAT_0601f6ba;

extern void FUN_0601f87a();

int FUN_0601f5e0()
{

  char *puVar1;

  char *puVar2;

  int iVar3;

  char *puVar4;

  unsigned int uVar5;

  unsigned int uVar6;

  puVar1 = 0x0607ED90;

  uVar6 = (unsigned int)DAT_0601f6ba;

  FUN_0601f87a(0);

  (*0x0601E2B4)();

  (*0x0601EB70)();

  (*0x0601F40C)();

  puVar2 = 0x060877F0;

  if (*0x06078635 == '\0') {

    iVar3 = 0;

  }

  else {

    *0x060877F0 = puVar1[4];

    puVar2[1] = puVar1[5];

    puVar2[2] = puVar1[6];

    puVar2[3] = puVar1[7];

    if ((*(unsigned int *)0x060786A4 < *(unsigned int *)0x060877F0) ||

       (iVar3 = *(int *)0x060877F0, iVar3 == 0)) {

      *0x0605E0A1 = 1;

      *0x0605E0A0 = (char)*(int *)0x0607EAD8;

      puVar2 = 0x060786A4;

      puVar4 = 0x060786A4 + 1;

      puVar1[4] = *0x060786A4;

      puVar1[5] = *puVar4;

      puVar1[6] = puVar2[2];

      puVar1[7] = puVar2[3];

      for (uVar5 = *(unsigned int *)0x0607ED88; uVar5 < uVar6; uVar5 = uVar5 + 2) {

        puVar1[uVar5] = 0x40;

        puVar1[uVar5 + 1] = 0x80;

      }

      FUN_0601f87a(*(int *)0x0607EAD8 + 1U & 0xff);

      puVar2 = 0x060877D8;

      puVar1 = 0x0605E06C;

      puVar4 = (char *)0x0;

      if (*(int *)0x06085FFC != 0) {

        puVar4 = *(char **)0x06085FFC;

      }

      if (*(int *)0x06086000 != 0) {

        puVar4 = *(char **)0x06086000;

      }

      if (puVar4 == (char *)0x0) {

        0x0605E06C[(char)(*0x060877D8 * '\v') + 7] = 0x44;

        puVar1[(char)(*puVar2 * '\v') + 8] = 0x41;

        puVar1[(char)(*puVar2 * '\v') + 9] = 0x59;

      }

      else {

        0x0605E06C[(char)(*0x060877D8 * '\v') + 7] = *puVar4;

        puVar1[(char)(*puVar2 * '\v') + 8] = puVar4[1];

        puVar1[(char)(*puVar2 * '\v') + 9] = puVar4[2];

      }

      (*0x0601E2B4)();

      iVar3 = (*0x0601EB1C)();

      return iVar3;

    }

  }

  return iVar3;

}
