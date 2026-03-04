/* FUN_06040C60  0x06040C60 */


void FUN_06040c60(undefined4 param_1,int param_2)

{
  int unaff_r14;
  undefined1 auStack_10 [4];
  int iStack_c;
  undefined4 uStack_8;
  
  iStack_c = param_2;
  uStack_8 = param_1;
  (*(code *)PTR_FUN_06040c90)(auStack_10);
  if (unaff_r14 == -1) {
    unaff_r14 = *(int *)(iStack_c + 0xc);
  }
  FUN_060409e6(uStack_8,unaff_r14,1);
  PTR_DAT_06040c94[0x10] = 0;
  return;
}

