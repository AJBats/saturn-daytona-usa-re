extern int DAT_0600a224;

extern int DAT_0600a226;

extern int DAT_0600a2d8;

extern int DAT_0600a2da;

extern int DAT_0600a2dc;

extern int DAT_0600a2de;

int FUN_0600a1f6()
{

  int iVar1;

  if (*(int *)0x0607EAD8 == 0) {

    iVar1 = 0;

    if (*(int *)0x0607EBCC == (int)DAT_0600a224) {

      *(short *)0x0605A016 = 3;

    }

    else if (*(int *)0x0607EBCC == (int)DAT_0600a226) {

      *(short *)0x0605A016 = 4;

    }

  }

  else {

    iVar1 = *(int *)0x0607EAD8;

    if (iVar1 == 1) {

      if (*(int *)0x0607EBCC == (int)DAT_0600a2d8) {

        *(short *)0x0605A016 = 3;

      }

      else if (*(int *)0x0607EBCC == (int)DAT_0600a2da) {

        *(short *)0x0605A016 = 4;

      }

    }

    else if (*(int *)0x0607EBCC == (int)DAT_0600a2dc) {

      *(short *)0x0605A016 = 3;

    }

    else if (*(int *)0x0607EBCC == (int)DAT_0600a2de) {

      *(short *)0x0605A016 = 4;

    }

  }

  return iVar1;

}
