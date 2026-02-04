extern int DAT_0601d974;

extern int DAT_0601d976;

extern int PTR_DAT_0601d884;

extern int PTR_DAT_0601d884;

extern int PTR_DAT_0601da3c;

extern int PTR_DAT_0601da3c;

extern void FUN_0601d5f4();

int FUN_0601d7d0()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  int uVar5;

  int iVar6;

  int iVar7;

  puVar4 = 0x06086058;

  puVar3 = 0x06087060;

  puVar2 = 0x0607EAD8;

  puVar1 = 0x06086054;

  iVar7 = *(int *)(0x0604A50C +

                  *(int *)0x0605AD00 * 4 +

                  (int)(char)((char)*(int *)0x0607EAD8 * '\f'));

  iVar6 = *(int *)0x0607E944;

  if (*0x06085FF4 == '\0') {

    if ((*(int *)0x0607EAD8 == 0) && (iVar7 - *(int *)(iVar6 + PTR_DAT_0601d884) < 9)) {

      if ((*0x06087060 == '\0') && (*(int *)0x0605AD00 != 0)) {

        *0x06087060 = 1;

        *(short *)puVar4 = 0;

      }

      else {

        *(short *)0x06086058 = *(short *)0x06086058 + 1;

      }

    }

    if ((*(int *)puVar2 == 1) && (iVar7 - *(int *)(iVar6 + DAT_0601d974) < 5)) {

      if ((*puVar3 == '\0') && (*(int *)0x0605AD00 != 0)) {

        *puVar3 = 1;

      }

      else {

        *(short *)puVar4 = *(short *)puVar4 + 1;

      }

    }

    if ((*(int *)puVar2 == 2) && (iVar7 - *(int *)(iVar6 + DAT_0601d974) < 3)) {

      if ((*puVar3 == '\0') && (*(int *)0x0605AD00 != 0)) {

        *puVar3 = 1;

      }

      else {

        *(short *)puVar4 = *(short *)puVar4 + 1;

      }

    }

    puVar2 = 0x06086056;

    if ((int)(iVar7 + (unsigned int)(iVar7 < 0)) >> 1 < *(int *)(iVar6 + DAT_0601d974) + 1) {

      if ((*(int *)(iVar6 + DAT_0601d974) == *(int *)0x06063F28 + -1) &&

         (*(int *)0x06086034 == 0)) {

        uVar5 = FUN_0601d5f4(0,0xAE1121FF);

        *(short *)puVar2 = 0x50;

        *(short *)puVar1 = 0x50;

        *(int *)0x06086034 = 1;

      }

      else {

        uVar5 = FUN_0601d5f4(0,0xAE1127FF);

        *(short *)puVar1 = PTR_DAT_0601da3c;

        *(short *)puVar2 = 0x14;

      }

    }

    else {

      uVar5 = FUN_0601d5f4(0,0xAE1126FF);

      *(short *)puVar1 = DAT_0601d976;

      *(short *)puVar2 = 0x14;

    }

  }

  else {

    if ((*(int *)(iVar6 + PTR_DAT_0601d884) != *(int *)0x06063F28 + -1) ||

       (*(int *)0x06086034 != 0)) {

      uVar5 = FUN_0601d5f4(0,0xAE1146FF);

      return uVar5;

    }

    uVar5 = FUN_0601d5f4(0,0xAE1121FF);

    *(short *)puVar1 = 0x50;

    *(int *)0x06086034 = 1;

  }

  return uVar5;

}
