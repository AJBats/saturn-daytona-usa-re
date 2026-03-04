/* FUN_0602F214  0x0602F214 */


void FUN_0602f214(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int unaff_r8;
  int unaff_r9;
  code *unaff_r12;
  int unaff_r14;
  
  uVar1 = (*unaff_r12)();
  *(uint *)(unaff_r8 + unaff_r14) = uVar1 >> 0x10;
  iVar4 = (*(int *)(DAT_0602f24c + unaff_r14) + *(int *)(PTR_DAT_0602f250._0_2_ + unaff_r14)) -
          *(int *)(DAT_0602f24e + unaff_r14);
  iVar2 = *(int *)(PTR_DAT_0602f25c + *(short *)(unaff_r9 + unaff_r14) * 8);
  iVar3 = *(int *)((int)(PTR_DAT_0602f25c + *(short *)(unaff_r9 + unaff_r14) * 8) + 4);
  if ((iVar2 < iVar4) && (iVar2 = iVar4, iVar3 < iVar4)) {
    iVar2 = iVar3;
  }
  *(int *)(PTR_DAT_0602f26e._0_2_ + unaff_r14) = *(int *)(DAT_0602f24e + unaff_r14) + iVar2;
  return;
}

