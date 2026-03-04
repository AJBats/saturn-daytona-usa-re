/* FUN_0603405A  0x0603405A */


int FUN_0603405a(void)

{
  longlong lVar1;
  code *in_r0;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 in_r7;
  int unaff_r11;
  int unaff_r12;
  int unaff_r14;
  undefined4 in_pr;
  
  iVar2 = (*in_r0)();
  *(uint *)(unaff_r14 + DAT_060340a8) =
       ((int)((ulonglong)((longlong)unaff_r11 * (longlong)iVar2) >> 0x20) << 0x10 |
       (uint)((longlong)unaff_r11 * (longlong)iVar2) >> 0x10) + *(int *)(unaff_r14 + DAT_060340a4);
  if (*(char *)(unaff_r14 + DAT_060340ac) == '\x02') {
    *(undefined4 *)PTR_DAT_06034148 = *(undefined4 *)(unaff_r14 + DAT_06034144);
    *(undefined4 *)PTR_DAT_06034150 = *(undefined4 *)(unaff_r14 + DAT_0603414c);
    uVar3 = (*(code *)PTR_FUN_06034154)();
    (*(code *)PTR_FUN_0603415c)(uVar3,PTR_DAT_06034148,PTR_DAT_06034158,in_r7,in_pr);
    iVar2 = DAT_06034164;
    *(undefined4 *)(unaff_r14 + DAT_06034164) = *(undefined4 *)PTR_DAT_06034160;
  }
  else {
    if (*(short *)(unaff_r14 + DAT_060340b0) == 0) {
      uVar5 = 0;
    }
    else {
      lVar1 = (longlong)(int)*(short *)(unaff_r14 + DAT_060340b0) * (longlong)unaff_r12;
      uVar5 = (int)((ulonglong)lVar1 >> 0x20) << 0x10 | (uint)lVar1 >> 0x10;
      uVar3 = (*DAT_060340f8)(uVar5);
      uVar4 = (*(code *)PTR_FUN_060340fc)(uVar5);
      iVar2 = (*(code *)PTR_FUN_06034100)(uVar3,uVar4);
      uVar5 = (int)((ulonglong)((longlong)unaff_r11 * (longlong)iVar2) >> 0x20) << 0x10 |
              (uint)((longlong)unaff_r11 * (longlong)iVar2) >> 0x10;
    }
    iVar2 = DAT_06034108;
    *(uint *)(unaff_r14 + DAT_06034108) = uVar5 + *(int *)(unaff_r14 + DAT_06034104);
  }
  return iVar2;
}

