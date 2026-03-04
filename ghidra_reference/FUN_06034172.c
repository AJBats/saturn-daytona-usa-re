/* FUN_06034172  0x06034172 */


undefined4 FUN_06034172(void)

{
  code *in_r0;
  undefined4 uVar1;
  undefined4 in_r7;
  int unaff_r14;
  undefined4 in_pr;
  
  (*in_r0)();
  (*(code *)PTR_FUN_060341dc)
            (*(undefined4 *)(unaff_r14 + DAT_060341d0),*(undefined4 *)(unaff_r14 + DAT_060341d4),
             *(undefined4 *)(unaff_r14 + DAT_060341d8),in_r7,in_pr);
  (*(code *)PTR_FUN_060341e4)((int)*(short *)(unaff_r14 + DAT_060341e0));
  (*(code *)PTR_FUN_060341ec)((int)*(char *)(unaff_r14 + DAT_060341e8));
  uVar1 = (*(code *)PTR_FUN_060341f0)();
  return uVar1;
}

