/* FUN_060343C6  0x060343C6 */


undefined4 FUN_060343c6(void)

{
  code *in_r0;
  undefined4 uVar1;
  undefined4 in_r7;
  int unaff_r14;
  undefined4 in_pr;
  
  (*in_r0)();
  (*(code *)PTR_FUN_06034434)
            (*(int *)(unaff_r14 + DAT_06034428) - (int)PTR_DAT_06034460,
             *(undefined4 *)(unaff_r14 + DAT_0603442c),
             *(int *)(unaff_r14 + DAT_06034430) - (int)PTR_DAT_06034464,in_r7,in_pr);
  (*(code *)PTR_FUN_0603443c)(*(short *)(unaff_r14 + DAT_06034438) + DAT_06034438);
  (*(code *)PTR_FUN_06034444)((int)*(char *)(unaff_r14 + DAT_06034440));
  uVar1 = (*(code *)PTR_FUN_06034448)();
  return uVar1;
}

