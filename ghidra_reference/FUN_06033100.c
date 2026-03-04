/* FUN_06033100  0x06033100 */


int FUN_06033100(void)

{
  int in_r7;
  int unaff_r8;
  int unaff_r9;
  int unaff_r10;
  int iVar1;
  int iVar2;
  int unaff_r13;
  int unaff_r14;
  int in_stack_00000000;
  
  do {
    FUN_06033188();
    FUN_0603320c(PTR_DAT_06033168);
    do {
      do {
        in_stack_00000000 = in_stack_00000000 + unaff_r10;
        in_r7 = in_r7 + -1;
        if (in_r7 < 1) {
          return in_stack_00000000;
        }
        iVar1 = unaff_r13 - *(int *)(unaff_r8 + in_stack_00000000);
        iVar2 = unaff_r14 - *(int *)(unaff_r9 + in_stack_00000000);
        iVar1 = iVar1 + (iVar1 >> 1);
        if (iVar1 < 0) {
          iVar1 = -iVar1;
        }
      } while ((int)PTR_DAT_06033158 < iVar1);
      iVar1 = iVar2;
      if (iVar2 < 0) {
        iVar1 = -iVar2;
      }
    } while ((int)PTR_DAT_0603315c < iVar1);
    FUN_0603316c(iVar2);
  } while( true );
}

