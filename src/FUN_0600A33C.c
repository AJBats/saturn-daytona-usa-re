int FUN_0600a33c()
{

  int iVar1;

  if (*(int *)0x06063E1C == 0) {

    *(int *)0x0605A016 = 5;

    iVar1 = 0;

  }

  else if (*(int *)0x06063E1C == 1) {

    *(int *)0x0605A016 = 6;

    iVar1 = 1;

  }

  else if (*(int *)0x06063E1C == 2) {

    *(int *)0x0605A016 = 7;

    iVar1 = 2;

  }

  else {

    iVar1 = *(int *)0x06063E1C;

    if (iVar1 == 3) {

      *(int *)0x0605A016 = 8;

    }

  }

  return iVar1;

}
