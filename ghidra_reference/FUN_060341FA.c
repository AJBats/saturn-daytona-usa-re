/* FUN_060341FA  0x060341FA */


undefined4 FUN_060341fa(void)

{
  code *in_r0;
  undefined4 uVar1;
  undefined4 in_r7;
  int unaff_r14;
  undefined4 in_pr;
  
  (*in_r0)();
  (*(code *)PTR_FUN_06034264)
            (*(undefined4 *)(unaff_r14 + DAT_06034258),*(undefined4 *)(unaff_r14 + DAT_0603425c),
             *(undefined4 *)(unaff_r14 + DAT_06034260),in_r7,in_pr);
  (*(code *)PTR_FUN_06034270)
            ((int)(short)(*(short *)(unaff_r14 + DAT_06034268) + (short)PTR_DAT_0603426c));
  (*(code *)PTR_FUN_06034278)((int)*(char *)(unaff_r14 + DAT_06034274));
  uVar1 = (*(code *)PTR_FUN_0603427c)();
  return uVar1;
}

