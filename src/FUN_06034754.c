int FUN_06034754()
{

  int iVar1;

  unsigned int uVar2;

  int unaff_r14;

  iVar1 = (*(void(*)())0x0602755C)(*(int *)(*(int *)0x0607E944 + 0x00000008) << 0x10,0x012C0000);

  uVar2 = *(int *)(unaff_r14 + 0x00000008) + iVar1;

  if ((int)0x00060000 <= (int)uVar2) {

    uVar2 = 0;

  }

  *(unsigned int *)(unaff_r14 + 0x00000008) = uVar2;

  iVar1 = 0x0000000C;

  *(unsigned int *)(unaff_r14 + 0x0000000C) = uVar2 >> 0x10 & 0x00000007;

  return iVar1;

}
