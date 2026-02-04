extern int FUN_0601d5f4();

unsigned int FUN_0601d9b0()
{

  short sVar1;

  unsigned short uVar2;

  char *puVar3;

  int uVar4;

  char *puVar5;

  unsigned int uVar6;

  short uVar7;

  puVar3 = 0x06086054;

  if ((int)(char)*(int *)0x06085FF4 != 0) {

    return (int)(char)*(int *)0x06085FF4;

  }

  if (((*(short *)0x06086056 == 0) || (*(int *)0x0608605A == '\x01')) ||

     (sVar1 = *(short *)0x06086056, *(short *)0x06086056 = sVar1 + -1,

     uVar4 = 0xAE112BFF, sVar1 != 1)) goto LAB_0601db20;

  if (*(int *)0x0607EAD8 != 0) {

    if (*(int *)0x0607EAD8 == 1) {

      sVar1 = *(short *)0x06086058;

      if (sVar1 == 1) {

        *(short *)0x06086056 = 0;

        FUN_0601d5f4(0,uVar4);

      }

      else if (sVar1 == 3) {

        *(short *)0x06086056 = 0;

        FUN_0601d5f4(0,uVar4);

      }

      else {

        if (sVar1 != 6) {

          *(short *)puVar3 = 100;

          goto LAB_0601db20;

        }

        *(short *)0x06086056 = 0;

        FUN_0601d5f4(0,0xAE112DFF);

      }

      *(short *)puVar3 = 0x28;

    }

    else if ((*(int *)0x0607EAD8 == 2) && (*(short *)0x06086058 == 8)) {

      *(short *)0x06086056 = 0;

      FUN_0601d5f4(0,0xAE112FFF);

      *(short *)puVar3 = 0x28;

    }

    goto LAB_0601db20;

  }

  sVar1 = *(short *)0x06086058;

  if (sVar1 == 1) {

    *(short *)0x06086056 = 0;

    FUN_0601d5f4(0,0xAE1129FF);

LAB_0601da72:

    uVar7 = 0x28;

  }

  else {

    if (sVar1 == 2) {

      *(short *)0x06086056 = 0;

      FUN_0601d5f4(0,uVar4);

      goto LAB_0601da72;

    }

    if (sVar1 == 3) {

      *(short *)0x06086056 = 0;

      FUN_0601d5f4(0,0xAE112AFF);

      uVar7 = 0x14;

    }

    else {

      if (sVar1 == 4) {

        *(short *)0x06086056 = 0;

        FUN_0601d5f4(0,uVar4);

        goto LAB_0601da72;

      }

      if (sVar1 == 5) {

        *(short *)0x06086056 = 0;

        FUN_0601d5f4(0,0xAE112CFF);

        uVar7 = 0x14;

      }

      else {

        if (sVar1 != 6) {

          *(short *)puVar3 = 100;

          goto LAB_0601db20;

        }

        *(short *)0x06086056 = 0;

        FUN_0601d5f4(0,uVar4);

        uVar7 = 0x28;

      }

    }

  }

  *(short *)puVar3 = uVar7;

LAB_0601db20:

  puVar5 = 0x0608605A;

  uVar6 = (unsigned int)(unsigned char)*(int *)0x0608605A;

  if (uVar6 == 1) {

    uVar2 = *(unsigned short *)0x06086056;

    *(unsigned short *)0x06086056 = uVar2 - 1;

    uVar6 = (unsigned int)uVar2;

    if (uVar6 == 1) {

      *puVar5 = 0;

      *(short *)0x06086056 = 0;

      *(short *)puVar3 = 0x28;

      uVar6 = FUN_0601d5f4(0,0xAE1120FF);

      return uVar6;

    }

  }

  return uVar6;

}
