extern int DAT_0600dbdc;

extern int DAT_0600dbde;

extern int DAT_0600dc98;

extern int DAT_0600dc9a;

extern int FUN_0600dc74();

unsigned int FUN_0600db9e()
{

  char *puVar1;

  unsigned int uVar2;

  int iVar3;

  int uVar4;

  puVar1 = 0x060786A8;

  if ((*(unsigned short *)0x06078698 & 7) < 4) {

    if (*(int *)0x06078644 == 1) {

      (*(void(*)())0x06028400)(8,*(int *)0x060637F8,(int)DAT_0600dbde,

                 *(int *)(0x060637F8 + 4) + (int)DAT_0600dbdc,0x060637F8);

    }

    else {

      (*(void(*)())0x06028400)(8,*(int *)0x06063808,(int)DAT_0600dc9a,

                 *(int *)(0x06063808 + 4) + (int)DAT_0600dc98,0x06063808);

    }

  }

  else {

    FUN_0600dc74();

  }

  uVar2 = (unsigned int)*(unsigned short *)0x06078698;

  if ((*(unsigned short *)0x06078698 & 0x3f) == 0) {

    iVar3 = *(int *)puVar1;

    *(unsigned int *)puVar1 = iVar3 + 1U;

    if (iVar3 + 1U < 7) {

      uVar2 = (*(void(*)())0x0601D5F4)(0,0xAE1138FF);

    }

    else {

      uVar4 = 0xAE1138FF;

      if (*(int *)0x06078644 == 1) {

        uVar4 = 0xAE1139FF;

      }

      uVar2 = (*(void(*)())0x0601D5F4)(0,uVar4);

      *(short *)0x06086054 = 0x28;

      *(int *)puVar1 = 0;

    }

  }

  return uVar2;

}
