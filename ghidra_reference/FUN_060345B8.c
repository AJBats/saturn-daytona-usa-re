/* FUN_060345B8  0x060345B8 */


int FUN_060345b8(void)

{
  code *in_r0;
  int iVar1;
  undefined4 uVar2;
  undefined4 in_r7;
  int unaff_r8;
  int unaff_r14;
  undefined4 in_pr;
  
  iVar1 = (*in_r0)();
  *(uint *)(unaff_r14 + DAT_06034620) =
       *(int *)(unaff_r14 + DAT_06034620) +
       ((int)((ulonglong)((longlong)unaff_r8 * (longlong)iVar1) >> 0x20) << 0x10 |
       (uint)((longlong)unaff_r8 * (longlong)iVar1) >> 0x10);
  *(undefined4 *)PTR_DAT_06034624 = *(undefined4 *)(unaff_r14 + DAT_06034618);
  *(undefined4 *)PTR_DAT_06034628 = *(undefined4 *)(unaff_r14 + DAT_06034620);
  uVar2 = (*(code *)PTR_FUN_0603462c)();
  (*(code *)PTR_FUN_06034634)(uVar2,PTR_DAT_06034624,PTR_DAT_06034630,in_r7,in_pr);
  iVar1 = DAT_0603463c;
  *(undefined4 *)(unaff_r14 + DAT_0603463c) = *(undefined4 *)PTR_DAT_06034638;
  return iVar1;
}

