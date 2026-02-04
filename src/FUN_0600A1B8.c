unsigned int FUN_0600a1b8()
{

  char *puVar1;

  unsigned int uVar2;

  puVar1 = 0x0607ED90;

  if ((*0x06078635 != '\0') ||

     ((uVar2 = (unsigned int)*(unsigned short *)0x0607ED8C, uVar2 == 0 &&

      (uVar2 = *(unsigned int *)0x0605AD00, uVar2 == 0)))) {

    *0x0607ED90 = (char)*(short *)0x06063F44;

    puVar1[1] = (char)*(int *)0x06078868;

    uVar2 = *(unsigned int *)0x0607EAB8 & 0xff;

    puVar1[2] = (char)*(unsigned int *)0x0607EAB8;

  }

  return uVar2;

}
