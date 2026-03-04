/* FUN_0603338E  0x0603338E */


undefined4 FUN_0603338e(int param_1,int param_2,int param_3,int param_4)

{
  code *in_r0;
  undefined4 uVar1;
  short *unaff_r8;
  int unaff_r9;
  int unaff_r10;
  undefined4 in_pr;
  
  while( true ) {
    (*in_r0)(param_1,param_2,param_3,param_4,in_pr);
    param_4 = param_4 + -1;
    if (param_4 < 1) break;
    param_1 = *unaff_r8 + unaff_r10;
    param_2 = *unaff_r8 + unaff_r9;
    param_3 = (int)unaff_r8[1];
    unaff_r8 = unaff_r8 + 2;
    in_r0 = (code *)PTR_FUN_060333d0;
  }
  uVar1 = (*(code *)PTR_FUN_060333d0)
                    (PTR_DAT_060333d4,PTR_DAT_060333cc,(int)PTR_DAT_060333b0._0_2_,param_4,in_pr);
  return uVar1;
}

