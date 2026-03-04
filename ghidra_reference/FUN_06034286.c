/* FUN_06034286  0x06034286 */


undefined4 FUN_06034286(void)

{
  code *in_r0;
  undefined4 uVar1;
  undefined4 in_r7;
  int unaff_r14;
  undefined4 in_pr;
  
  (*in_r0)();
  (*(code *)PTR_FUN_060342ec)
            (*(undefined4 *)(unaff_r14 + DAT_060342e0),*(undefined4 *)(unaff_r14 + DAT_060342e4),
             *(undefined4 *)(unaff_r14 + DAT_060342e8),in_r7,in_pr);
  (*(code *)PTR_FUN_060342f4)((int)*(short *)(unaff_r14 + DAT_060342f0));
  (*(code *)PTR_FUN_060342fc)((int)*(char *)(unaff_r14 + DAT_060342f8));
  uVar1 = (*(code *)PTR_FUN_06034300)();
  return uVar1;
}

