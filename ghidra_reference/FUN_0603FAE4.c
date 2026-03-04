/* FUN_0603FAE4  0x0603FAE4 */


ushort FUN_0603fae4(void)

{
  byte bVar1;
  ushort uVar3;
  int iVar2;
  undefined4 *unaff_r8;
  undefined4 uVar4;
  undefined4 uVar5;
  int unaff_r11;
  undefined4 unaff_r12;
  undefined4 *unaff_r14;
  
  uVar5 = *unaff_r14;
  uVar4 = unaff_r14[2];
  if ((int)unaff_r14[5] <= unaff_r11) {
    *unaff_r8 = unaff_r12;
    return 5;
  }
  if ((*(byte *)(unaff_r14 + 0xd) & DAT_0603fb22) != DAT_0603fb22) {
    *unaff_r8 = unaff_r12;
    return *(byte *)(unaff_r14 + 0xd) & DAT_0603fb24;
  }
  uVar3 = *(byte *)(unaff_r14 + 0xd) & DAT_0603fb24;
  bVar1 = (byte)DAT_0603fb22;
  if (uVar3 == 0) {
    FUN_0603fc60();
    if (unaff_r14[1] == 0) goto LAB_0603fc40;
    *(byte *)(unaff_r14 + 0xd) = *(byte *)(unaff_r14 + 0xd) & bVar1 | 1;
LAB_0603fb50:
    FUN_0603fce4();
    if (unaff_r14[3] == 0) goto LAB_0603fc40;
    *(byte *)(unaff_r14 + 0xd) = *(byte *)(unaff_r14 + 0xd) & bVar1 | 2;
LAB_0603fb74:
    iVar2 = (*(code *)unaff_r14[9])(unaff_r14[8]);
    if (iVar2 == 0) goto LAB_0603fc40;
    FUN_0603ff9c();
    *(byte *)(unaff_r14 + 0xd) = *(byte *)(unaff_r14 + 0xd) & bVar1 | 3;
LAB_0603fba0:
    iVar2 = (*(code *)unaff_r14[0xb])(unaff_r14[8]);
    if (0 < iVar2) goto LAB_0603fc40;
    unaff_r12 = 1;
    *(byte *)(unaff_r14 + 0xd) = *(byte *)(unaff_r14 + 0xd) & bVar1 | 4;
  }
  else {
    if (uVar3 == 1) goto LAB_0603fb50;
    if (uVar3 == 2) goto LAB_0603fb74;
    if (uVar3 == 3) goto LAB_0603fba0;
    if (uVar3 != 4) goto LAB_0603fc40;
  }
  if (unaff_r14[7] == *(int *)(unaff_r14[1] + 8)) {
    (*(code *)PTR_FUN_0603fc24)(uVar5,unaff_r14[1],0xffffffff);
    unaff_r14[6] = unaff_r14[6] + *(int *)(unaff_r14[1] + 0xc);
    unaff_r14[1] = unaff_r11;
  }
  (*(code *)PTR_FUN_0603fc24)(uVar4,unaff_r14[3],0xffffffff);
  unaff_r14[3] = unaff_r11;
  if ((int)unaff_r14[6] < (int)unaff_r14[5]) {
    *(byte *)(unaff_r14 + 0xd) = *(byte *)(unaff_r14 + 0xd) & bVar1;
  }
  else {
    *(byte *)(unaff_r14 + 0xd) = *(byte *)(unaff_r14 + 0xd) & bVar1 | 5;
  }
LAB_0603fc40:
  *unaff_r8 = unaff_r12;
  return *(byte *)(unaff_r14 + 0xd) & DAT_0603fcb6;
}

