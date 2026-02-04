extern int DAT_06010042;

extern int DAT_06010044;

extern int DAT_06010046;

extern int DAT_060100f2;

extern int DAT_060100f4;

extern void FUN_060100a4();

unsigned int FUN_0600ffd0()
{

  short sVar1;

  char *puVar2;

  char *puVar3;

  int uVar4;

  int iVar5;

  unsigned int uVar6;

  puVar3 = 0x0607887F;

  puVar2 = 0x060284AE;

  iVar5 = (int)DAT_06010042;

  uVar6 = 0;

  do {

    FUN_060100a4(uVar6);

    uVar6 = uVar6 + 1;

  } while ((uVar6 & 0xff) < 3);

  if (*0x06078663 == '\0') {

    if (*(int *)0x0605AA98 != 0) {

      *(int *)0x0605AA98 = *(int *)0x0605AA98 + -1;

    }

    uVar6 = (unsigned int)(unsigned char)*puVar3;

    if ((uVar6 < 5) || (uVar6 == 9)) {

      if (*puVar3 == '\t') {

        uVar4 = 0xc;

        sVar1 = DAT_06010044;

      }

      else {

        uVar4 = 8;

        sVar1 = DAT_06010046;

      }

      uVar6 = (*puVar2)(uVar4,(int)sVar1,iVar5,0x0605ACE4);

    }

  }

  else {

    if (*(int *)0x0605AA98 != 0xc) {

      *(int *)0x0605AA98 = *(int *)0x0605AA98 + 1;

    }

    uVar6 = (unsigned int)(unsigned char)*puVar3;

    if ((uVar6 < 5) || (uVar6 == 9)) {

      if (*puVar3 == '\t') {

        uVar4 = 0xc;

        sVar1 = DAT_060100f2;

      }

      else {

        uVar4 = 8;

        sVar1 = DAT_060100f4;

      }

      uVar6 = (*puVar2)(uVar4,(int)sVar1,iVar5,0x0605AB19);

    }

  }

  return uVar6;

}
