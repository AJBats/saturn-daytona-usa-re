/* FUN_0602F7F2  0x0602F7F2 */


void FUN_0602f7f2(void)

{
  char cVar1;
  short sVar2;
  undefined *puVar3;
  undefined *puVar4;
  short *psVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  undefined4 *unaff_r14;
  uint *puVar9;
  
  puVar3 = PTR_FUN_0602f84c;
  puVar9 = (uint *)*unaff_r14;
  iVar6 = (int)*(short *)(PTR_DAT_0602f854 + *(int *)PTR_DAT_0602f850 * 4);
  if (iVar6 != 0) {
    psVar5 = (short *)(PTR_DAT_0602f858 +
                      *(short *)((int)(PTR_DAT_0602f854 + *(int *)PTR_DAT_0602f850 * 4) + 2));
    do {
      if (((int)*psVar5 <= *(int *)((int)DAT_0602f842 + (int)puVar9)) &&
         (*(int *)((int)DAT_0602f842 + (int)puVar9) <= (int)psVar5[1])) {
        if (0x100000 < (int)puVar9[5]) {
          if (((int)DAT_0602f844 & *puVar9) == 0) {
            *puVar9 = *puVar9 | (int)DAT_0602f844;
            (*(code *)puVar3)(4,DAT_0602f85c);
          }
        }
        goto LAB_0602f87c;
      }
      iVar6 = iVar6 + -1;
      psVar5 = psVar5 + 2;
    } while (iVar6 != 0);
    if (((int)DAT_0602f890 & *puVar9) != 0) {
      *puVar9 = *puVar9 & ~(int)DAT_0602f890;
      (*(code *)puVar3)(4,DAT_0602f898);
    }
  }
LAB_0602f87c:
  iVar6 = FUN_0602eccc();
  if (iVar6 < 2) {
    iVar6 = 1;
  }
  else if (0x7e < iVar6) {
    iVar6 = 0x7f;
  }
  (*(code *)puVar3)(1,iVar6);
  if ((*(int *)((int)DAT_0602f8f0 + (int)puVar9) == 0) &&
     (sVar2 = *(short *)((int)DAT_0602f8f2 + (int)puVar9), sVar2 != 0)) {
    if (sVar2 == 10) {
      uVar7 = DAT_0602f8f8;
      if (*PTR_DAT_0602f8f4 != '\0') {
        uVar7 = DAT_0602f8fc;
      }
    }
    else {
      if (sVar2 != 3) goto LAB_0602f910;
      uVar7 = DAT_0602f984;
      if (*PTR_DAT_0602f8f4 != '\0') {
        uVar7 = DAT_0602f988;
      }
    }
    (*(code *)puVar3)(0,uVar7);
  }
LAB_0602f910:
  if (*(int *)((int)DAT_0602f97e + (int)puVar9) == 0x2c) {
    uVar7 = DAT_0602f990;
    if (*PTR_DAT_0602f98c != '\0') {
      uVar7 = DAT_0602f994;
    }
    (*(code *)puVar3)(0,uVar7);
  }
  puVar4 = PTR_DAT_0602fd9e_1_0602f998;
  cVar1 = *PTR_DAT_0602fd9e_1_0602f998;
  if (cVar1 == '\0') {
LAB_0602f93e:
    if ((puVar9[3] == 0) || (*(int *)((int)puVar9 + (int)DAT_0602f980) < 0xc9)) goto LAB_0602f95a;
    *puVar4 = 10;
    uVar7 = 1;
  }
  else {
    uVar7 = 0;
    *PTR_DAT_0602fd9e_1_0602f998 = cVar1 + -1;
    if (cVar1 != '\x01') goto LAB_0602f93e;
  }
  (*(code *)puVar3)(3,uVar7);
LAB_0602f95a:
  uVar8 = *(uint *)((int)puVar9 + (int)DAT_0602f982);
  if ((int)uVar8 < 0) {
    uVar8 = -uVar8;
  }
  uVar8 = uVar8 >> 10;
  if (7 < uVar8) {
    uVar8 = 7;
  }
  (*(code *)puVar3)(2,uVar8);
  return;
}

