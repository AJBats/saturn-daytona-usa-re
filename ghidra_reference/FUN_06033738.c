/* FUN_06033738  0x06033738 */


undefined4 FUN_06033738(void)

{
  short extraout_var;
  short *psVar1;
  code *in_r1;
  int iVar2;
  int iVar3;
  int unaff_r10;
  int unaff_r13;
  int iVar4;
  int in_stack_00000000;
  undefined4 in_stack_00000008;
  
  (*in_r1)();
  iVar4 = (int)extraout_var;
  if ('\0' < (char)*PTR_DAT_06033884) {
    iVar4 = -iVar4;
  }
  psVar1 = (short *)(PTR_DAT_060337d8 + in_stack_00000000);
  iVar4 = *psVar1 - iVar4;
  iVar2 = psVar1[1] - unaff_r13;
  if ('\0' < (char)*PTR_DAT_06033884) {
    iVar4 = iVar4 + psVar1[2];
    iVar2 = iVar2 + psVar1[3];
  }
  iVar3 = -unaff_r10;
  FUN_06033520(iVar3,iVar4 + iVar3,iVar2 + iVar3,iVar4 + unaff_r10);
  (*(code *)PTR_FUN_060337f8)(PTR_DAT_060337f0,*(undefined4 *)PTR_DAT_060337f4);
  FUN_06033504();
  return in_stack_00000008;
}

