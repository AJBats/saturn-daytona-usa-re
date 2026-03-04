/* FUN_060340C0  0x060340C0 */


int FUN_060340c0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  code *in_r0;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int unaff_r11;
  int unaff_r14;
  undefined4 in_pr;
  
  uVar2 = (*in_r0)();
  uVar3 = (*(code *)PTR_FUN_060340fc)();
  iVar4 = (*(code *)PTR_FUN_06034100)(uVar2,uVar3,param_3,param_4,in_pr);
  iVar1 = DAT_06034108;
  *(uint *)(unaff_r14 + DAT_06034108) =
       ((int)((ulonglong)((longlong)unaff_r11 * (longlong)iVar4) >> 0x20) << 0x10 |
       (uint)((longlong)unaff_r11 * (longlong)iVar4) >> 0x10) + *(int *)(unaff_r14 + DAT_06034104);
  return iVar1;
}

