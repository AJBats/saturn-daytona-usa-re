/* FUN_060340CE  0x060340CE */


int FUN_060340ce(void)

{
  int iVar1;
  code *in_r0;
  int iVar2;
  int unaff_r11;
  int unaff_r14;
  
  (*in_r0)();
  iVar2 = (*(code *)PTR_FUN_06034100)();
  iVar1 = DAT_06034108;
  *(uint *)(unaff_r14 + DAT_06034108) =
       ((int)((ulonglong)((longlong)unaff_r11 * (longlong)iVar2) >> 0x20) << 0x10 |
       (uint)((longlong)unaff_r11 * (longlong)iVar2) >> 0x10) + *(int *)(unaff_r14 + DAT_06034104);
  return iVar1;
}

