/* FUN_06020430  0x06020430 */


void FUN_06020430(char param_1,undefined4 param_2,int param_3,int param_4)

{
  ushort uVar1;
  undefined *puVar2;
  short sVar3;
  uint unaff_r8;
  short *psVar4;
  int iVar5;
  short *psVar6;
  uint unaff_r13;
  short unaff_r14;
  
  puVar2 = PTR_PTR_060204ac;
  iVar5 = (int)DAT_060204a8;
  psVar6 = (short *)(PTR_PTR_060204ac + 4);
  psVar4 = (short *)(PTR_PTR_060204ac + 6);
  if ('\0' < param_1) {
    do {
      uVar1 = *(ushort *)(param_4 + (unaff_r13 & 0xff) * 2);
      if ((char)uVar1 == ' ') {
        *psVar6 = unaff_r14;
        *psVar4 = unaff_r14;
      }
      else {
        sVar3 = ((uVar1 & 0xff) - 0x40) * 2;
        *psVar6 = sVar3;
        *psVar4 = sVar3 + 1;
      }
      (*(code *)PTR_FUN_060204b0)(8,puVar2,((unaff_r8 & 0xffff) + param_3) * 2,iVar5);
      unaff_r13 = unaff_r13 + 1;
      unaff_r8 = unaff_r8 + 1;
    } while ((int)(unaff_r13 & 0xff) < (int)param_1);
  }
  return;
}

