/* FUN_0603493A  0x0603493A */


undefined4 FUN_0603493a(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  code *in_r0;
  undefined4 uVar1;
  uint uVar2;
  int unaff_r14;
  undefined4 in_pr;
  
  (*in_r0)();
  uVar2 = *(uint *)(unaff_r14 + DAT_06034976);
  if ((int)uVar2 < 0) {
    uVar2 = -uVar2;
  }
  uVar2 = uVar2 >> 10;
  if (7 < uVar2) {
    uVar2 = 7;
  }
  uVar1 = (*(code *)PTR_FUN_06034980)(2,uVar2,param_3,param_4,in_pr);
  return uVar1;
}

