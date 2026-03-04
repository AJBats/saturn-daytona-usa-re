/* FUN_0602E3A0  0x0602E3A0 */


void FUN_0602e3a0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int in_r0;
  int iVar1;
  undefined4 in_pr;
  
  *(undefined **)PTR_PTR_0602e3d0 = PTR_DAT_0602e3d4;
  *(undefined4 *)PTR_DAT_0602e3dc = *(undefined4 *)PTR_DAT_0602e3d8;
  *(undefined4 *)PTR_DAT_0602e3e0 = DAT_0602e3e4;
  *(int *)PTR_DAT_0602e3e8 = (int)DAT_0602e3ca;
  *(undefined4 *)(PTR_DAT_0602e3f0 + in_r0) = DAT_0602e3ec;
  *(int *)(PTR_DAT_0602e3cc._0_2_ + in_r0) = (int)DAT_0602e3ca;
  iVar1 = *(int *)(DAT_0602e28e + in_r0);
  if (iVar1 != DAT_0602e2a4) {
    *(int *)(DAT_0602e28e + in_r0) = iVar1 - DAT_0602e29c;
  }
  *(int *)(DAT_0602e2a8 + in_r0) = DAT_0602e2a4;
  (*(code *)PTR_FUN_0602e2ac)();
  (*(code *)PTR_FUN_0602e2b0)();
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

