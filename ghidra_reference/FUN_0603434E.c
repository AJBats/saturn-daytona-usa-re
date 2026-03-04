/* FUN_0603434E  0x0603434E */


int FUN_0603434e(void)

{
  code *in_r0;
  int iVar1;
  undefined4 in_r7;
  int unaff_r14;
  undefined4 in_pr;
  
  (*in_r0)();
  iVar1 = DAT_06034450;
  if (DAT_06034450 <= *(int *)PTR_DAT_0603444c) {
    (*(code *)PTR_FUN_06034420)();
    (*(code *)PTR_FUN_06034434)
              (*(int *)(unaff_r14 + DAT_06034428) - (int)PTR_DAT_06034454,
               *(undefined4 *)(unaff_r14 + DAT_0603442c),
               *(int *)(unaff_r14 + DAT_06034430) - (int)PTR_DAT_06034458,in_r7,in_pr);
    (*(code *)PTR_FUN_0603443c)((int)*(short *)(unaff_r14 + DAT_06034438));
    (*(code *)PTR_FUN_06034444)((int)*(char *)(unaff_r14 + DAT_06034440));
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
  }
  return iVar1;
}

