/* FUN_060345E2  0x060345E2 */


int FUN_060345e2(void)

{
  int iVar1;
  code *in_r0;
  undefined4 uVar2;
  undefined4 in_r7;
  int unaff_r14;
  undefined4 in_pr;
  
  uVar2 = (*in_r0)();
  (*(code *)PTR_FUN_06034634)(uVar2,PTR_DAT_06034624,PTR_DAT_06034630,in_r7,in_pr);
  iVar1 = DAT_0603463c;
  *(undefined4 *)(unaff_r14 + DAT_0603463c) = *(undefined4 *)PTR_DAT_06034638;
  return iVar1;
}

