int FUN_060347a8()
{

  int iVar1;

  int iVar2;

  unsigned char bVar3;

  int unaff_r14;

  if ((*(int *)(unaff_r14 + 0x0000000C) == 1) && (*(int *)(unaff_r14 + 0x00000010) != 1)) {

    *(char *)(unaff_r14 + 0x00000001) = (char)0xFFFFFFFF;

    *(char *)(unaff_r14 + 0x00000002) = 0;

  }

  if ((*(int *)(unaff_r14 + 0x0000000C) == 5) && (*(int *)(unaff_r14 + 0x00000010) != 5)) {

    *(char *)(unaff_r14 + 0x00000004) = (char)0xFFFFFFFF;

    *(char *)(unaff_r14 + 0x00000005) = 0;

  }

  bVar3 = *(char *)(unaff_r14 + 0x00000002) + 1;

  *(unsigned char *)(unaff_r14 + 0x00000002) = bVar3;

  bVar3 = bVar3 & 3;

  *(unsigned char *)(unaff_r14 + 0x00000000) = bVar3;

  if (bVar3 == 3) {

    *(char *)(unaff_r14 + 0x00000001) = 0;

  }

  bVar3 = *(char *)(unaff_r14 + 0x00000005) + 1;

  *(unsigned char *)(unaff_r14 + 0x00000005) = bVar3;

  iVar2 = 0x00000003;

  bVar3 = bVar3 & 3;

  *(unsigned char *)(unaff_r14 + 0x00000003) = bVar3;

  iVar1 = 0x00000004;

  if (bVar3 == 3) {

    *(char *)(unaff_r14 + 0x00000004) = 0;

    iVar2 = iVar1;

  }

  return iVar2;

}
