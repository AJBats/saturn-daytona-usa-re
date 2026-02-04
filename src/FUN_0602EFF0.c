extern int DAT_0602f01e;

extern int DAT_0602f064;

extern int DAT_0602f066;

extern int PTR_DAT_0602f0e0;

extern int PTR_DAT_0602f0e0;

extern void FUN_0602eccc();

int FUN_0602eff0(param_1, param_2)
    int param_1;
    int param_2;
{

  int iVar1;

  int uVar2;

  int iVar3;

  int extraout_r1;

  int extraout_r1_00;

  int extraout_r3;

  int uVar4;

  iVar1 = *(int *)0x0607E944;

  uVar2 = FUN_0602eccc(0,param_2,*(int *)(DAT_0602f01e + iVar1),0);

  iVar3 = (int)DAT_0602f066;

  uVar4 = *(int *)(DAT_0602f064 + iVar1);

  *(int *)(DAT_0602f064 + iVar1) = uVar2;

  *(int *)(iVar3 + iVar1) = uVar4;

  FUN_0602eccc();

  *(int *)(extraout_r3 + iVar1) = extraout_r1;

  FUN_0602eccc();

  *(int *)(PTR_DAT_0602f0e0 + iVar1) = extraout_r1_00;

  return iVar1;

}
