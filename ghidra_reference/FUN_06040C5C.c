/* FUN_06040C5C  0x06040C5C */


void FUN_06040c5c(undefined4 param_1,int param_2,int param_3)

{
  undefined1 auStack_14 [4];
  int iStack_10;
  undefined4 uStack_c;
  
  iStack_10 = param_2;
  uStack_c = param_1;
  (*(code *)PTR_FUN_06040c90)(auStack_14);
  if (param_3 == -1) {
    param_3 = *(int *)(iStack_10 + 0xc);
  }
  FUN_060409e6(uStack_c,param_3,1);
  PTR_DAT_06040c94[0x10] = 0;
  return;
}

