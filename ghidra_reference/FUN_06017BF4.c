extern int DAT_06017c52;

void FUN_06017bf4()
{

  char *puVar1;

  puVar1 = 0x0605BE28;

  if (*(char **)0x0607EBC4 != 0x00020000) {

    return;

  }

  if ((*(short *)0x0605BE24 == *(short *)0x0605BE22) &&

     (*(short *)0x0605BE24 == *(short *)0x0605BE20)) {

    if (*(short *)0x0605BE24 == 0x2a) {

      *(int *)0x0607EAAC = *(int *)0x0607EAAC + (int)DAT_06017c52;

      *(short *)puVar1 = 1;

      (*(int(*)())0x0601D5F4)(0,0xAE1117FF);

      return;

    }

    if (*(short *)0x0605BE24 == 0x12) {

      *(int *)0x0607EAAC = *(int *)0x0607EAAC + 100;

      *(short *)puVar1 = 1;

      (*(int(*)())0x0601D5F4)(0,0xAE1117FF);

      return;

    }

  }

  return;

}
