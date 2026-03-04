/* FUN_0602E16C  0x0602E16C */


void FUN_0602e16c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  undefined4 in_pr;
  
  puVar1 = PTR_DAT_0602e1a8;
  iVar2 = *(int *)PTR_DAT_0602e1a8;
  if (iVar2 != 0) {
    *(undefined4 *)PTR_DAT_0602e1b0 = *(undefined4 *)(PTR_DAT_0602e1ac + iVar2 * 4);
    *(int *)puVar1 = iVar2 + -1;
  }
  (*(code *)PTR_FUN_0602e1b8)();
  iVar2 = *(int *)PTR_DAT_0602e1b4;
  if (DAT_0602e1c0 <= *(int *)(DAT_0602e1bc + iVar2)) {
    FUN_0602e3a0();
    return;
  }
  iVar3 = *(int *)PTR_DAT_0602e298 - DAT_0602e29c;
  if (DAT_0602e2a0 == iVar3) {
    *(uint *)(DAT_0602e284 + iVar2) =
         *(uint *)(DAT_0602e284 + iVar2) & ~(int)DAT_0602e286 & ~(int)DAT_0602e288 &
         ~(int)DAT_0602e28a & ~(int)DAT_0602e28c;
    iVar3 = *(int *)PTR_DAT_0602e298 - DAT_0602e29c;
  }
  *(int *)PTR_DAT_0602e298 = iVar3;
  iVar3 = *(int *)(DAT_0602e28e + iVar2);
  if (iVar3 != DAT_0602e2a4) {
    *(int *)(DAT_0602e28e + iVar2) = iVar3 - DAT_0602e29c;
  }
  *(int *)(DAT_0602e2a8 + iVar2) = DAT_0602e2a4;
  (*(code *)PTR_FUN_0602e2ac)();
  (*(code *)PTR_FUN_0602e2b0)();
  (*(code *)PTR_FUN_0602e2b4)();
  (*(code *)PTR_FUN_0602e2b8)();
  (*(code *)PTR_FUN_0602e2bc)();
  (*(code *)PTR_FUN_0602e2c0)();
  (*(code *)PTR_FUN_0602e2c8)();
  (*(code *)PTR_FUN_0602e2cc)();
  iVar2 = (*(code *)PTR_FUN_0602e2fc)();
  if (iVar2 < 2) {
    iVar2 = 1;
  }
  else if (0x7e < iVar2) {
    iVar2 = 0x7f;
  }
  (*(code *)PTR_FUN_0602e37c)(1,iVar2,param_3,param_4,in_pr);
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

