/* FUN_06034762  0x06034762 */


int FUN_06034762(void)

{
  code *in_r0;
  int iVar1;
  uint uVar2;
  int unaff_r14;
  
  iVar1 = (*in_r0)();
  uVar2 = *(int *)(unaff_r14 + DAT_06034790) + iVar1;
  if ((int)PTR_DAT_0603479c <= (int)uVar2) {
    uVar2 = 0;
  }
  *(uint *)(unaff_r14 + DAT_06034790) = uVar2;
  iVar1 = DAT_060347a4;
  *(uint *)(unaff_r14 + DAT_060347a4) = uVar2 >> 0x10 & DAT_060347a0;
  return iVar1;
}

