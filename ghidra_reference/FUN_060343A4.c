/* FUN_060343A4  0x060343A4 */


int FUN_060343a4(void)

{
  code *in_r0;
  int iVar1;
  undefined4 in_r7;
  int unaff_r14;
  undefined4 in_pr;
  
  (*in_r0)();
  (*(code *)PTR_FUN_06034448)();
  iVar1 = DAT_0603445c;
  if (DAT_0603445c <= *(int *)PTR_DAT_0603444c) {
    (*(code *)PTR_FUN_06034420)();
    (*(code *)PTR_FUN_06034434)
              (*(int *)(unaff_r14 + DAT_06034428) - (int)PTR_DAT_06034460,
               *(undefined4 *)(unaff_r14 + DAT_0603442c),
               *(int *)(unaff_r14 + DAT_06034430) - (int)PTR_DAT_06034464,in_r7,in_pr);
    (*(code *)PTR_FUN_0603443c)(*(short *)(unaff_r14 + DAT_06034438) + DAT_06034438);
    (*(code *)PTR_FUN_06034444)((int)*(char *)(unaff_r14 + DAT_06034440));
    iVar1 = (*(code *)PTR_FUN_06034448)();
  }
  return iVar1;
}

