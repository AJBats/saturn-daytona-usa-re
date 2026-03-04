/* FUN_0602F550  0x0602F550 */


int FUN_0602f550(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7
                ,int param_8,int param_9)

{
  code *in_r0;
  short sVar1;
  int iVar2;
  int iVar3;
  int unaff_r8;
  uint uVar4;
  undefined4 in_pr;
  
  while( true ) {
    sVar1 = (*in_r0)(param_1,param_2,param_3,param_4,in_pr);
    uVar4 = (int)-sVar1 - *(int *)(param_5 + 0x28);
    if (((uint)PTR_DAT_0602f580 & uVar4) == 0) {
      uVar4 = uVar4 & (uint)PTR_DAT_0602f5a0;
    }
    else {
      uVar4 = uVar4 | DAT_0602f584;
    }
    if ((int)uVar4 < 0) {
      uVar4 = -uVar4;
    }
    if ((int)uVar4 < DAT_0602f5a4) break;
    do {
      param_3 = param_7 + DAT_0602f5b4;
      param_8 = param_8 + -1;
      if (param_8 == 0) {
        return param_5;
      }
      iVar2 = param_6 - *(int *)(DAT_0602f51c + param_3);
      if (iVar2 < 1) {
        iVar2 = -iVar2;
      }
      iVar3 = unaff_r8 - *(int *)(DAT_0602f51e + param_3);
      if (iVar3 < 1) {
        iVar3 = -iVar3;
      }
      if (iVar2 < iVar3) {
        iVar3 = iVar3 + (iVar2 >> 1);
      }
      else {
        iVar3 = (iVar3 >> 1) + iVar2;
      }
      param_7 = param_3;
    } while ((int)PTR_DAT_0602f578 <= iVar3);
    param_1 = *(int *)(DAT_0602f51c + param_3) - param_6;
    param_2 = *(int *)(DAT_0602f51e + param_3) - unaff_r8;
    in_r0 = (code *)PTR_FUN_0602f57c;
    param_4 = param_6;
  }
  *(undefined2 *)(param_9 + param_5) = 0x14;
  return param_5;
}

