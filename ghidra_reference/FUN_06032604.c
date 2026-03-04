/* FUN_06032604  0x06032604 */


undefined4 FUN_06032604(void)

{
  code *in_r0;
  undefined4 uVar1;
  int in_r7;
  int unaff_r14;
  int in_stack_00000000;
  
  do {
    (*in_r0)();
    (*(code *)PTR_FUN_06032678)(*(undefined4 *)(unaff_r14 + DAT_06032668));
    (*(code *)PTR_FUN_06032680)((int)*(char *)(DAT_0603267c + unaff_r14 + (DAT_0603266c - in_r7)));
    *(int *)(unaff_r14 + DAT_06032668) = *(int *)(unaff_r14 + DAT_06032668) + DAT_06032684;
    (*(code *)PTR_FUN_06032688)();
    in_r7 = in_stack_00000000 + -1;
    in_r0 = (code *)PTR_FUN_06032670;
    in_stack_00000000 = in_r7;
  } while (in_r7 != 0);
  uVar1 = (*(code *)PTR_FUN_06032688)();
  return uVar1;
}

