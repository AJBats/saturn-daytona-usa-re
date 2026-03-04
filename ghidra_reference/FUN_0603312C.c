/* FUN_0603312C  0x0603312C */


int FUN_0603312c(undefined *param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)

{
  int unaff_r8;
  int unaff_r9;
  int unaff_r10;
  int iVar1;
  int iVar2;
  int unaff_r13;
  int unaff_r14;
  
  do {
    FUN_0603320c(param_1);
    do {
      do {
        param_5 = param_5 + unaff_r10;
        param_4 = param_4 + -1;
        if (param_4 < 1) {
          return param_5;
        }
        iVar1 = unaff_r13 - *(int *)(unaff_r8 + param_5);
        iVar2 = unaff_r14 - *(int *)(unaff_r9 + param_5);
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
    FUN_06033188();
    param_1 = PTR_DAT_06033168;
  } while( true );
}

