void FUN_06035fec()
{

  char *in_r0;

  char cVar1;

  char *in_r1;

  if (((unsigned int)in_r1 & 3) == 0 && ((unsigned int)in_r0 & 3) == 0) {

    (*(int(*)())0x06036CB0)();

    return;

  }

  cVar1 = *in_r1;

  while( 1 ) {

    *in_r0 = cVar1;

    if (cVar1 == '\0') {

      return;

    }

    cVar1 = in_r1[1];

    in_r0[1] = cVar1;

    if (cVar1 == '\0') {

      return;

    }

    cVar1 = in_r1[2];

    in_r0[2] = cVar1;

    if (cVar1 == '\0') {

      return;

    }

    cVar1 = in_r1[3];

    in_r1 = in_r1 + 4;

    in_r0[3] = cVar1;

    if (cVar1 == '\0') break;

    cVar1 = *in_r1;

    in_r0 = in_r0 + 4;

  }

  return;

}
