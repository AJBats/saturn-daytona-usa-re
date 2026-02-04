extern int DAT_06005aba;

extern int DAT_06005abc;

extern int DAT_06005abe;

extern int DAT_06005ac0;

extern int DAT_06005ac2;

void FUN_06005a22()
{

  int iVar1;

  if (*(int *)0x0607EABC < 1) {

    return;

  }

  iVar1 = *(int *)0x0607EABC;

  *(unsigned int *)0x0607EABC = iVar1 - 1U;

  if ((iVar1 - 1U & 1) != 0) {

    if (*(int *)0x06085FF4 == '\0') {

      iVar1 = 0x21;

    }

    else {

      iVar1 = 0xb0;

    }

    if (*(int *)0x0607EAC0 != 0) {

      (*(int(*)())0x06028400)(8,*(int *)(0x06063750 + (iVar1 << 3)),(int)DAT_06005abe,

                 *(int *)((int)(0x06063750 + (iVar1 << 3)) + 4) + (int)DAT_06005abc);

      return;

    }

    (*(int(*)())0x06028400)(8,*(int *)(0x06063750 + (iVar1 << 3)),(int)DAT_06005ac0,

               *(int *)((int)(0x06063750 + (iVar1 << 3)) + 4) + (int)DAT_06005abc);

    return;

  }

  (*(int(*)())0x060284AE)(8,(int)DAT_06005abe,0x90,0x0605ACDD);

  (*(int(*)())0x060284AE)(8,(int)DAT_06005ac0,0x90,0x0605ACDD);

  return;

}
