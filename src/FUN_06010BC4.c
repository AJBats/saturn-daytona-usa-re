extern int DAT_06010c4c;

extern int DAT_06010c4e;

extern int PTR_DAT_06010c50;

extern int PTR_DAT_06010c50;

extern int FUN_06010d94();
extern int FUN_060111e2();
extern int FUN_06011310();

int FUN_06010bc4()
{

  unsigned short uVar1;

  short sVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  char *puVar6;

  int uVar7;

  unsigned char *pbVar8;

  puVar6 = 0x06078878;

  puVar5 = 0x0608A52C;

  puVar4 = 0x06078898;

  puVar3 = 0x06078894;

  sVar2 = PTR_DAT_06010c50;

  uVar1 = DAT_06010c4e;

  pbVar8 = (unsigned char *)(int)DAT_06010c4c;

  if (*(int *)0x06085FF4 == '\0') {

    *(int *)0x060788A0 = 1;

    *(short *)puVar6 = *(short *)puVar6 + sVar2;

    FUN_06011310();

    puVar3 = 0x060270D0;

    *(int *)puVar5 = *(int *)puVar5 + 0x30;

    (*(void(*)())puVar3)();

    *(int *)0x0607884C = 1;

    *(char **)0x06078850 = 0x00038000;

    *(int *)0x06078854 = 0xFFFF0000;

    *(char **)0x06078858 = 0x0006B333;

    *(char **)0x06063574 = 0x06010F04;

    *(short *)0x21000000 = (short)0x0000FFFF;

    FUN_06010d94(0,0xFFFC8000,0xFFFF0000,0x0006B333);

    puVar3 = 0x0603C000;

    do {

    } while ((*pbVar8 & uVar1) != uVar1);

    *pbVar8 = *pbVar8 & 0xf;

    uVar7 = (*(void(*)())puVar3)();

  }

  else {

    *(short *)0x06078878 = *(short *)0x06078878 + PTR_DAT_06010c50;

    puVar6 = 0x0607889C;

    *(int *)puVar3 = *(int *)puVar3 + *(int *)0x0607889C;

    *(int *)puVar4 = *(int *)puVar4 + *(int *)puVar6;

    if (*(int *)puVar6 < 0) {

      if (*(int *)0x060788A8 == '\0') {

        if (*(int *)puVar3 < 1) {

          *(int *)puVar3 = 0;

          *(int *)puVar6 = 0;

        }

      }

      else if ((*(int *)0x060788A8 == '\x01') && (*(int *)puVar4 < 1)) {

        *(int *)puVar4 = 0;

        *(int *)puVar6 = 0;

      }

    }

    else if (*(int *)0x060788A8 == '\0') {

      if (-1 < *(int *)puVar3) {

        *(int *)puVar3 = 0;

        *(int *)puVar6 = 0;

      }

    }

    else if ((*(int *)0x060788A8 == '\x01') && (-1 < *(int *)puVar4)) {

      *(int *)puVar4 = 0;

      *(int *)puVar6 = 0;

    }

    FUN_060111e2();

    puVar6 = 0x060270D0;

    *(int *)puVar5 = *(int *)puVar5 + 0x30;

    (*(void(*)())puVar6)();

    *(int *)0x0607884C = 1;

    *(int *)0x06078850 = *(int *)puVar4;

    *(int *)0x06078854 = 0xFFFF3334;

    *(char **)0x06078858 = 0x00063333;

    *(char **)0x06063574 = 0x06010F04;

    *(short *)0x21000000 = (short)0x0000FFFF;

    FUN_06010d94(0,*(int *)puVar3,0xFFFF3334,0x00063333);

    puVar3 = 0x0603C000;

    do {

    } while ((*pbVar8 & uVar1) != uVar1);

    *pbVar8 = *pbVar8 & 0xf;

    uVar7 = (*(void(*)())puVar3)();

  }

  *(int *)puVar5 = *(int *)puVar5 + -0x30;

  return uVar7;

}
