/* FUN_06038F78  0x06038F78 */


uint FUN_06038f78(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  uint uVar7;
  undefined4 unaff_r10;
  
  puVar4 = PTR_DAT_06038fec;
  puVar3 = PTR_DAT_06038fe8;
  puVar2 = PTR_DAT_06038fe4;
  puVar1 = PTR_FUN_06038fe0;
  *(undefined4 *)PTR_DAT_06038fe4 = unaff_r10;
  puVar6 = PTR_VDP1_FBCR_06038ff8;
  puVar5 = PTR_DAT_06038ff4;
  if (*(short *)PTR_PTR_06038ff0 == 2) {
    uVar7 = 0;
    if (*(int *)puVar3 != 0) {
      uVar7 = (*(code *)puVar1)();
      *(undefined4 *)puVar2 = 2;
    }
  }
  else if (*(short *)PTR_PTR_06038ff0 == 3) {
    uVar7 = 0;
    if (*(int *)puVar3 != 0) {
      *(ushort *)PTR_VDP1_TVMR_06039000 = *(ushort *)PTR_DAT_06038ffc | 8;
      *(ushort *)puVar6 = *(ushort *)puVar5 | 3;
      uVar7 = (*(code *)puVar1)();
      *(undefined4 *)puVar2 = 3;
    }
  }
  else if (*(short *)PTR_PTR_06038ff0 == 0) {
    uVar7 = (*(code *)puVar1)();
    *(undefined4 *)puVar3 = unaff_r10;
  }
  else {
    *(int *)puVar4 = *(int *)puVar4 + 1;
    uVar7 = *(uint *)PTR_DAT_06039088;
    if ((uVar7 == 1) && (*(int *)PTR_DAT_0603908c + -1 <= *(int *)puVar4)) {
      uVar7 = *(ushort *)puVar5 | 2;
      *(short *)puVar6 = (short)uVar7;
    }
    if (*(int *)PTR_DAT_0603908c <= *(int *)puVar4) {
      uVar7 = 0;
      if (*(int *)puVar3 != 0) {
        uVar7 = (*(code *)puVar1)();
        *(undefined4 *)puVar2 = 1;
      }
      *(undefined4 *)puVar4 = unaff_r10;
    }
  }
  return uVar7;
}

