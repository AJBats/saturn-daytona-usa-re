int FUN_06036d14()
{

  char cVar1;

  char cVar2;

  char *in_r0;

  char *in_r1;

  int iVar3;

  int iVar4;

  if (((unsigned int)in_r1 & 3) == 0 && ((unsigned int)in_r0 & 3) == 0) {

    iVar3 = (*0x06036E1C)();

    return iVar3;

  }

  cVar1 = *in_r0;

  cVar2 = *in_r1;

  while( true ) {

    iVar4 = (int)cVar2;

    iVar3 = (int)cVar1;

    if ((iVar3 == 0) || (iVar4 != iVar3)) break;

    iVar3 = (int)in_r0[1];

    iVar4 = (int)in_r1[1];

    if ((iVar3 == 0) || (iVar4 != iVar3)) break;

    iVar3 = (int)in_r0[2];

    iVar4 = (int)in_r1[2];

    if ((iVar3 == 0) || (iVar4 != iVar3)) break;

    iVar3 = (int)in_r0[3];

    in_r0 = in_r0 + 4;

    iVar4 = (int)in_r1[3];

    in_r1 = in_r1 + 4;

    if ((iVar3 == 0) || (iVar4 != iVar3)) break;

    cVar1 = *in_r0;

    cVar2 = *in_r1;

  }

  return iVar3 - iVar4;

}
