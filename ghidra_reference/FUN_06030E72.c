/* FUN_06030E72  0x06030E72 */


int FUN_06030e72(undefined4 param_1,int param_2,int param_3)

{
  longlong lVar1;
  code *in_r0;
  int iVar2;
  int extraout_r3;
  undefined *puVar3;
  int unaff_r8;
  int unaff_r9;
  int unaff_r14;
  int iVar4;
  
  iVar2 = (*in_r0)();
  iVar4 = (int)((ulonglong)((longlong)extraout_r3 * (longlong)iVar2) >> 0x20);
  *(uint *)(unaff_r14 + 0x10) =
       param_2 + (iVar4 << 0x10 | (uint)((longlong)extraout_r3 * (longlong)iVar2) >> 0x10);
  *(uint *)(unaff_r14 + 0x18) =
       param_3 + ((int)((ulonglong)((longlong)unaff_r9 * (longlong)unaff_r8) >> 0x20) << 0x10 |
                 (uint)((longlong)unaff_r9 * (longlong)unaff_r8) >> 0x10);
  puVar3 = PTR_DAT_06030edc;
  if ((*(short *)(DAT_06030eae + unaff_r14) < 8) &&
     (puVar3 = PTR_DAT_06030eb8, 5 < *(short *)(DAT_06030eae + unaff_r14))) {
    puVar3 = PTR_DAT_06030ebc;
  }
  lVar1 = (longlong)(int)puVar3 * (longlong)*(int *)(unaff_r14 + 0xc);
  *(uint *)(unaff_r14 + 0xc) = (int)((ulonglong)lVar1 >> 0x20) << 0x10 | (uint)lVar1 >> 0x10;
  return iVar4;
}

