/* FUN_0602D934  0x0602D934 */


void FUN_0602d934(undefined4 param_1,int param_2)

{
  longlong lVar1;
  int iVar2;
  int extraout_r1;
  uint uVar3;
  undefined *puVar4;
  uint uVar5;
  uint uVar6;
  code *unaff_r12;
  uint *unaff_r14;
  undefined8 uVar7;
  
  (*unaff_r12)();
  iVar2 = extraout_r1;
  if ((*unaff_r14 & DAT_0602d958) == 0) {
    iVar2 = -extraout_r1;
  }
  unaff_r14[0xc] = param_2 + iVar2;
  unaff_r14[8] = param_2 + iVar2;
  uVar3 = *(uint *)((int)DAT_0602d9d0 + (int)unaff_r14);
  unaff_r14[10] = uVar3;
  puVar4 = (undefined *)
           ((int)((ulonglong)
                  ((longlong)
                   *(int *)(PTR_PTR_0602d9d4 + *(short *)((int)DAT_0602d9d2 + (int)unaff_r14) * 4) *
                  (longlong)(int)unaff_r14[3]) >> 0x20) << 0x10 |
           (uint)((longlong)
                  *(int *)(PTR_PTR_0602d9d4 + *(short *)((int)DAT_0602d9d2 + (int)unaff_r14) * 4) *
                 (longlong)(int)unaff_r14[3]) >> 0x10);
  unaff_r14[3] = (uint)puVar4;
  if ((int)unaff_r14[2] < 0x29) {
    puVar4 = PTR_DAT_0602d9d8;
  }
  uVar5 = unaff_r14[4];
  uVar6 = unaff_r14[6];
  unaff_r14[0xe] = uVar5;
  unaff_r14[0xf] = uVar6;
  iVar2 = (*(code *)PTR_FUN_0602d9dc)();
  uVar7 = (*DAT_0602d9e0)(-uVar3);
  lVar1 = (longlong)(int)puVar4 * (longlong)(int)uVar7;
  uVar3 = (int)((ulonglong)lVar1 >> 0x20) << 0x10 | (uint)lVar1 >> 0x10;
  *(uint *)(DAT_0602d9e4 + (int)unaff_r14) = uVar3;
  unaff_r14[4] = uVar5 + uVar3;
  lVar1 = (longlong)(int)((ulonglong)uVar7 >> 0x20) * (longlong)iVar2;
  uVar3 = (int)((ulonglong)lVar1 >> 0x20) << 0x10 | (uint)lVar1 >> 0x10;
  *(uint *)(DAT_0602d9e8 + (int)unaff_r14) = uVar3;
  unaff_r14[6] = uVar6 + uVar3;
  return;
}

