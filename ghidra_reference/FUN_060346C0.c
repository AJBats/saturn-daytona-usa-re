int FUN_060346c0()
{

  char cVar1;

  char cVar2;

  int iVar3;

  int iVar4;

  int unaff_r14;

  iVar4 = 0x00000010;

  iVar3 = *(char *)(unaff_r14 + 0x00000001) + -1;

  cVar1 = ((int *)0x060631B4)[iVar3];

  cVar2 = ((int *)0x060631B8)[iVar3];

  iVar3 = *(char *)(unaff_r14 + 0x00000010) + 1;

  *(char *)(unaff_r14 + 0x00000010) = (char)iVar3;

  if (cVar1 <= iVar3) {

    *(char *)(unaff_r14 + iVar4) = 0;

    iVar4 = 0x00000011;

    iVar3 = *(char *)(unaff_r14 + 0x00000011) + 1;

    if (cVar2 <= iVar3) {

      iVar3 = 0x00000000;

    }

    *(char *)(unaff_r14 + 0x00000011) = (char)iVar3;

  }

  return iVar4;

}
