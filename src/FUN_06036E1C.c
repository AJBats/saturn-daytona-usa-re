long long FUN_06036e1c()
{

  int *in_r0;

  int *piVar1;

  int *in_r1;

  int *piVar2;

  int *piVar3;

  int iVar4;

  int iVar5;

  iVar4 = *in_r0;

  iVar5 = *in_r1;

  while( true ) {

    piVar2 = in_r1 + 1;

    piVar1 = in_r0 + 1;

    if ((((char)iVar5 == '\0' || (char)((unsigned int)iVar5 >> 8) == '\0') ||

        (char)((unsigned int)iVar5 >> 0x10) == '\0') || (char)((unsigned int)iVar5 >> 0x18) == '\0') break;

    piVar3 = piVar2;

    if (iVar5 != iVar4) goto LAB_06036e82;

    iVar5 = *piVar2;

    piVar2 = in_r1 + 2;

    iVar4 = *piVar1;

    piVar1 = in_r0 + 2;

    if ((((char)iVar5 == '\0' || (char)((unsigned int)iVar5 >> 8) == '\0') ||

        (char)((unsigned int)iVar5 >> 0x10) == '\0') || (char)((unsigned int)iVar5 >> 0x18) == '\0') break;

    piVar3 = piVar2;

    if (iVar5 != iVar4) goto LAB_06036e82;

    iVar5 = *piVar2;

    piVar2 = in_r1 + 3;

    iVar4 = *piVar1;

    piVar1 = in_r0 + 3;

    if ((((char)iVar5 == '\0' || (char)((unsigned int)iVar5 >> 8) == '\0') ||

        (char)((unsigned int)iVar5 >> 0x10) == '\0') || (char)((unsigned int)iVar5 >> 0x18) == '\0') break;

    piVar3 = piVar2;

    if (iVar5 != iVar4) goto LAB_06036e82;

    iVar5 = *piVar2;

    piVar2 = in_r1 + 4;

    iVar4 = *piVar1;

    piVar1 = in_r0 + 4;

    if ((((char)iVar5 == '\0' || (char)((unsigned int)iVar5 >> 8) == '\0') ||

        (char)((unsigned int)iVar5 >> 0x10) == '\0') || (char)((unsigned int)iVar5 >> 0x18) == '\0') break;

    piVar3 = piVar2;

    if (iVar5 != iVar4) goto LAB_06036e82;

    iVar4 = *piVar1;

    iVar5 = *piVar2;

    in_r0 = piVar1;

    in_r1 = piVar2;

  }

  iVar4 = (int)*(char *)(piVar1 + -1);

  iVar5 = (int)*(char *)(piVar2 + -1);

  piVar3 = (int *)((int)piVar2 + -3);

  if ((iVar5 != 0) && (iVar5 == iVar4)) {

    iVar4 = (int)*(char *)((int)piVar1 + -3);

    iVar5 = (int)*(char *)piVar3;

    piVar3 = (int *)((int)piVar2 + -2);

    if ((iVar5 != 0) && (iVar5 == iVar4)) {

      iVar4 = (int)*(char *)((int)piVar1 + -2);

      iVar5 = (int)*(char *)piVar3;

      piVar3 = (int *)((int)piVar2 + -1);

      if ((iVar5 != 0) && (iVar5 == iVar4)) {

        iVar4 = (int)*(char *)((int)piVar1 + -1);

        iVar5 = (int)*(char *)piVar3;

        piVar3 = piVar2;

      }

    }

  }

LAB_06036e82:

  return CONCAT44(piVar3,iVar4 - iVar5);

}
