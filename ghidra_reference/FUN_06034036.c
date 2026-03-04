/* FUN_06034036  0x06034036 */


int FUN_06034036(void)

{
  longlong lVar1;
  code *in_r0;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 in_r7;
  int iVar7;
  int unaff_r14;
  undefined4 in_pr;
  
  iVar2 = (*in_r0)();
  iVar7 = *(int *)(unaff_r14 + DAT_06034094);
  *(uint *)(unaff_r14 + DAT_0603409c) =
       ((int)((ulonglong)((longlong)iVar7 * (longlong)iVar2) >> 0x20) << 0x10 |
       (uint)((longlong)iVar7 * (longlong)iVar2) >> 0x10) + *(int *)(unaff_r14 + DAT_06034098);
  iVar3 = (*DAT_060340a0)();
  *(uint *)(unaff_r14 + DAT_060340a8) =
       ((int)((ulonglong)((longlong)iVar7 * (longlong)iVar3) >> 0x20) << 0x10 |
       (uint)((longlong)iVar7 * (longlong)iVar3) >> 0x10) + *(int *)(unaff_r14 + DAT_060340a4);
  if (*(char *)(unaff_r14 + DAT_060340ac) == '\x02') {
    *(undefined4 *)PTR_DAT_06034148 = *(undefined4 *)(unaff_r14 + DAT_06034144);
    *(undefined4 *)PTR_DAT_06034150 = *(undefined4 *)(unaff_r14 + DAT_0603414c);
    uVar4 = (*(code *)PTR_FUN_06034154)();
    (*(code *)PTR_FUN_0603415c)(uVar4,PTR_DAT_06034148,PTR_DAT_06034158,in_r7,in_pr);
    iVar2 = DAT_06034164;
    *(undefined4 *)(unaff_r14 + DAT_06034164) = *(undefined4 *)PTR_DAT_06034160;
  }
  else {
    if (*(short *)(unaff_r14 + DAT_060340b0) == 0) {
      uVar6 = 0;
    }
    else {
      lVar1 = (longlong)(int)*(short *)(unaff_r14 + DAT_060340b0) * (longlong)iVar2;
      uVar6 = (int)((ulonglong)lVar1 >> 0x20) << 0x10 | (uint)lVar1 >> 0x10;
      uVar4 = (*DAT_060340f8)(uVar6);
      uVar5 = (*(code *)PTR_FUN_060340fc)(uVar6);
      iVar2 = (*(code *)PTR_FUN_06034100)(uVar4,uVar5);
      uVar6 = (int)((ulonglong)((longlong)iVar7 * (longlong)iVar2) >> 0x20) << 0x10 |
              (uint)((longlong)iVar7 * (longlong)iVar2) >> 0x10;
    }
    iVar2 = DAT_06034108;
    *(uint *)(unaff_r14 + DAT_06034108) = uVar6 + *(int *)(unaff_r14 + DAT_06034104);
  }
  return iVar2;
}

