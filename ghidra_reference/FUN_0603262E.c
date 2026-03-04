/* FUN_0603262E  0x0603262E */


undefined4 FUN_0603262e(int param_1)

{
  code *in_r0;
  undefined4 uVar1;
  int iVar2;
  int unaff_r14;
  int in_stack_00000000;
  
  while( true ) {
    (*in_r0)(param_1);
    *(int *)(unaff_r14 + DAT_06032668) = *(int *)(unaff_r14 + DAT_06032668) + DAT_06032684;
    (*(code *)PTR_FUN_06032688)();
    in_stack_00000000 = in_stack_00000000 + -1;
    if (in_stack_00000000 == 0) break;
    iVar2 = in_stack_00000000;
    (*(code *)PTR_FUN_06032670)();
    (*(code *)PTR_FUN_06032678)(*(undefined4 *)(unaff_r14 + DAT_06032668));
    param_1 = (int)*(char *)(DAT_0603267c + unaff_r14 + (DAT_0603266c - iVar2));
    in_r0 = (code *)PTR_FUN_06032680;
  }
  uVar1 = (*(code *)PTR_FUN_06032688)();
  return uVar1;
}

