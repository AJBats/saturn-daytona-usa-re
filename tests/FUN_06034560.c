int FUN_06034560()
{

  int iVar1;

  int unaff_r10;

  int unaff_r14;

  

  *(short *)(unaff_r14 + 0x00000002) = (short)*(int *)(unaff_r10 + 0x00000028);

  *(int *)(unaff_r14 + 0x00000028) = *(int *)(unaff_r10 + 0x0000000C) << 1;

  iVar1 = 0x00000026;

  *(char *)(unaff_r14 + 0x00000026) = 2;

  return iVar1;

}
