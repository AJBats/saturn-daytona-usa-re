/* FUN_0600C7D8  0x0600C7D8 */


void FUN_0600c7d8(undefined4 param_1,int param_2)

{
  int iVar1;
  short sVar2;
  int unaff_r14;
  
  *(undefined4 *)(unaff_r14 + DAT_0600c8b6) = *(undefined4 *)(unaff_r14 + 0x20);
  sVar2 = (short)*(undefined4 *)(unaff_r14 + 0x28) - (short)*(undefined4 *)(unaff_r14 + 0x20);
  if ((int)DAT_0600c8b8 < *(int *)(unaff_r14 + 8)) {
    sVar2 = sVar2 >> 3;
  }
  else if ((int)DAT_0600c8ba < *(int *)(unaff_r14 + 8)) {
    sVar2 = sVar2 >> 2;
  }
  else if ((int)DAT_0600c8bc < *(int *)(unaff_r14 + 8)) {
    sVar2 = sVar2 >> 1;
  }
  sVar2 = (short)*(undefined4 *)(unaff_r14 + 0x20) + sVar2;
  *(int *)(unaff_r14 + 0x20) = (int)sVar2;
  *(int *)(unaff_r14 + 0x30) =
       (int)(short)((sVar2 - (short)*(undefined4 *)(unaff_r14 + DAT_0600c8be)) -
                   *(short *)(param_2 + 0x12));
  *(int *)(unaff_r14 + 0x1c) =
       (int)(short)(*(short *)(param_2 + 0xc) + (short)*(undefined4 *)(unaff_r14 + 0x1c)) >> 1;
  *(int *)(unaff_r14 + 0x24) =
       (int)(short)(*(short *)(param_2 + 0x10) + (short)*(undefined4 *)(unaff_r14 + 0x24)) >> 1;
  *(undefined4 *)(unaff_r14 + 0x38) = *(undefined4 *)(unaff_r14 + 0x10);
  *(undefined4 *)(unaff_r14 + 0x3c) = *(undefined4 *)(unaff_r14 + 0x18);
  *(int *)(unaff_r14 + 0x20) =
       (int)(short)((short)*(undefined4 *)(unaff_r14 + 0x20) +
                   (short)(-(int)*(short *)(param_2 + 0x12) >> 2));
  (*(code *)PTR_FUN_0600c8c4)
            (-*(int *)(unaff_r14 + 0x28),DAT_0600c8c2 + unaff_r14,DAT_0600c8c0 + unaff_r14);
  iVar1 = (*(code *)PTR_FUN_0600c8c8)
                    (*(undefined4 *)(unaff_r14 + 0xc),*(undefined4 *)(unaff_r14 + DAT_0600c8c2));
  *(int *)(unaff_r14 + 0x10) = *(int *)(unaff_r14 + 0x10) + iVar1;
  iVar1 = (*(code *)PTR_FUN_0600c8c8)
                    (*(undefined4 *)(unaff_r14 + 0xc),*(undefined4 *)(unaff_r14 + DAT_0600c8c0));
  *(int *)(unaff_r14 + 0x18) = *(int *)(unaff_r14 + 0x18) + iVar1;
  return;
}

