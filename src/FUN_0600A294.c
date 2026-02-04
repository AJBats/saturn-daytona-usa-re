extern int DAT_0600a2e0;

extern int DAT_0600a2e2;

extern int DAT_0600a36a;

extern int DAT_0600a36c;

extern int DAT_0600a36e;

extern int DAT_0600a370;

extern int DAT_0600a372;

extern int PTR_DAT_0600a2e4;

extern int PTR_DAT_0600a2e4;

int FUN_0600a294()
{

  int iVar1;

  if (*(int *)0x0607EAD8 == 1) {

    iVar1 = 1;

    if (*(int *)0x0607EBCC == (int)DAT_0600a2e0) {

      *(short *)0x0605A016 = 3;

    }

    else if (*(int *)0x0607EBCC == (int)DAT_0600a2e2) {

      *(short *)0x0605A016 = 4;

    }

  }

  else {

    iVar1 = *(int *)0x0607EAD8;

    if (iVar1 == 2) {

      if (*(int *)0x0607EBCC == (int)PTR_DAT_0600a2e4) {

        *(short *)0x0605A016 = 3;

      }

      else if (*(int *)0x0607EBCC == (int)DAT_0600a36a) {

        *(short *)0x0605A016 = 4;

      }

      else if (*(int *)0x0607EBCC == (int)DAT_0600a36c) {

        *(short *)0x0605A016 = 3;

      }

      else if (*(int *)0x0607EBCC == (int)DAT_0600a36e) {

        *(short *)0x0605A016 = 4;

      }

      else if (*(int *)0x0607EBCC == (int)DAT_0600a370) {

        *(short *)0x0605A016 = 3;

      }

      else if (*(int *)0x0607EBCC == (int)DAT_0600a372) {

        *(short *)0x0605A016 = 4;

      }

    }

  }

  return iVar1;

}
