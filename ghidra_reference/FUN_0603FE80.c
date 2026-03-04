/* FUN_0603FE80  0x0603FE80 */


undefined4
FUN_0603fe80(undefined4 param_1,int param_2,int param_3,undefined4 param_4,int param_5,
            undefined4 param_6)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  puVar1 = PTR_SCU_IST_0603fee4;
  uVar6 = (uint)DAT_0603fedc;
  uVar3 = *(undefined4 *)PTR_DAT_0603fee8;
  if (param_2 == 0) {
    return 0;
  }
  *(undefined4 *)PTR_SCU_ASR1_0603fef0 = DAT_0603feec;
  (**(code **)PTR_DAT_0603fef4)(0xffffffff);
  *(int *)puVar1 = (int)DAT_0603fede;
  puVar2 = PTR_SCU_D0R_0603fef8;
  *(undefined4 *)PTR_SCU_D0R_0603fef8 = param_4;
  *(int *)(puVar2 + 4) = param_2;
  *(undefined4 *)(puVar2 + 8) = param_6;
  puVar2 = PTR_SCU_D0AD_0603ff4c;
  if (param_5 == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = (uint)PTR_DAT_0603fee0._0_2_;
  }
  if (param_3 == 0) {
    uVar5 = 0;
  }
  else {
    uVar5 = 2;
  }
  *(uint *)PTR_SCU_D0AD_0603ff4c = uVar4 | uVar5;
  *(undefined4 *)(puVar2 + 8) = 7;
  *(int *)(puVar2 + 4) = (int)DAT_0603ff4a;
  do {
  } while ((*(uint *)puVar1 & uVar6) == 0);
                    /* WARNING: Could not recover jumptable at 0x0603ff24. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar3 = (**(code **)PTR_DAT_0603ff50)(uVar3);
  return uVar3;
}

