int FUN_06018634()
{

  short *puVar1;

  char *puVar2;

  int iVar3;

  puVar2 = 0x0605BE36;

  puVar1 = 0x0605BE38;

  iVar3 = *(int *)0x0607EAD8;

  if (iVar3 == 0) {

    *(short *)0x0605BE24 = 0;

    *(short *)0x0605BE22 = 0;

    *(short *)0x0605BE20 = 0;

    *(short *)0x0605BE2A = 0;

    *(short *)0x0605BE26 = 0;

    *(short *)0x0605BE28 = 0;

    *(short *)0x0605BE36 = 0;

    *(short *)0x0605BE38 = 0;

    return 0;

  }

  if (iVar3 == 1) {

    *(short *)0x0605BE1C = 0;

    *(short *)0x0605BE1E = 0;

    iVar3 = 0;

    *(short *)puVar2 = 0;

  }

  else {

    if (iVar3 != 2) {

      return iVar3;

    }

    *(short *)0x0605BE36 = 0;

    iVar3 = 2;

  }

  *puVar1 = 0;

  return iVar3;

}
