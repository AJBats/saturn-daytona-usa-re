/* FUN_060340DC  0x060340DC */


int FUN_060340dc(void)

{
  int iVar1;
  code *in_r0;
  int iVar2;
  int unaff_r11;
  int unaff_r14;
  
  iVar2 = (*in_r0)();
  iVar1 = DAT_06034108;
  *(uint *)(unaff_r14 + DAT_06034108) =
       ((int)((ulonglong)((longlong)unaff_r11 * (longlong)iVar2) >> 0x20) << 0x10 |
       (uint)((longlong)unaff_r11 * (longlong)iVar2) >> 0x10) + *(int *)(unaff_r14 + DAT_06034104);
  return iVar1;
}

