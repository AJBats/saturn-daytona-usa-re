/* FUN_0602E220  0x0602E220 */


void FUN_0602e220(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  code *unaff_r13;
  undefined4 in_pr;
  
  (*unaff_r13)();
  (*(code *)PTR_FUN_0602e2b4)();
  (*(code *)PTR_FUN_0602e2b8)();
  (*(code *)PTR_FUN_0602e2bc)();
  (*(code *)PTR_FUN_0602e2c0)();
  (*(code *)PTR_FUN_0602e2c8)();
  (*(code *)PTR_FUN_0602e2cc)();
  iVar1 = (*(code *)PTR_FUN_0602e2fc)();
  if (iVar1 < 2) {
    iVar1 = 1;
  }
  else if (0x7e < iVar1) {
    iVar1 = 0x7f;
  }
  (*(code *)PTR_FUN_0602e37c)(1,iVar1,param_3,param_4,in_pr);
  (*(code *)PTR_FUN_0602e384)(*(undefined4 *)((int)DAT_0602e372 + *(int *)PTR_DAT_0602e380));
  (*(code *)PTR_FUN_0602e388)();
  (*(code *)PTR_FUN_0602e38c)();
  (*(code *)PTR_FUN_0602e394)(DAT_0602e390);
  (*(code *)PTR_FUN_0602e398)(DAT_0602e390);
  *(undefined4 *)((int)DAT_0602e376 + *(int *)PTR_DAT_0602e380) =
       *(undefined4 *)((int)DAT_0602e374 + *(int *)PTR_DAT_0602e380);
  FUN_0602e3f4();
  return;
}

