/* FUN_06030E64  0x06030E64 */


int FUN_06030e64(undefined4 param_1,int param_2,int param_3)

{
  longlong lVar1;
  code *in_r0;
  int iVar2;
  int iVar3;
  int extraout_r3;
  undefined *puVar4;
  int unaff_r9;
  int unaff_r14;
  int iVar5;
  
  iVar2 = (*in_r0)();
  iVar3 = (*DAT_06030eb4)();
  iVar5 = (int)((ulonglong)((longlong)extraout_r3 * (longlong)iVar3) >> 0x20);
  *(uint *)(unaff_r14 + 0x10) =
       param_2 + (iVar5 << 0x10 | (uint)((longlong)extraout_r3 * (longlong)iVar3) >> 0x10);
  *(uint *)(unaff_r14 + 0x18) =
       param_3 + ((int)((ulonglong)((longlong)unaff_r9 * (longlong)iVar2) >> 0x20) << 0x10 |
                 (uint)((longlong)unaff_r9 * (longlong)iVar2) >> 0x10);
  puVar4 = PTR_DAT_06030edc;
  if ((*(short *)(DAT_06030eae + unaff_r14) < 8) &&
     (puVar4 = PTR_DAT_06030eb8, 5 < *(short *)(DAT_06030eae + unaff_r14))) {
    puVar4 = PTR_DAT_06030ebc;
  }
  lVar1 = (longlong)(int)puVar4 * (longlong)*(int *)(unaff_r14 + 0xc);
  *(uint *)(unaff_r14 + 0xc) = (int)((ulonglong)lVar1 >> 0x20) << 0x10 | (uint)lVar1 >> 0x10;
  return iVar5;
}

