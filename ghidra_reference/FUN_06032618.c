/* FUN_06032618  0x06032618 */


undefined4 FUN_06032618(undefined4 param_1)

{
  code *in_r0;
  undefined4 uVar1;
  int unaff_r14;
  int in_stack_00000000;
  int in_stack_00000004;
  
  while( true ) {
    (*in_r0)(param_1);
    (*(code *)PTR_FUN_06032680)
              ((int)*(char *)(DAT_0603267c + unaff_r14 + (DAT_0603266c - in_stack_00000000)));
    *(int *)(unaff_r14 + DAT_06032668) = *(int *)(unaff_r14 + DAT_06032668) + DAT_06032684;
    (*(code *)PTR_FUN_06032688)();
    in_stack_00000004 = in_stack_00000004 + -1;
    if (in_stack_00000004 == 0) break;
    in_stack_00000000 = in_stack_00000004;
    (*(code *)PTR_FUN_06032670)();
    param_1 = *(undefined4 *)(unaff_r14 + DAT_06032668);
    in_r0 = (code *)PTR_FUN_06032678;
  }
  uVar1 = (*(code *)PTR_FUN_06032688)();
  return uVar1;
}

