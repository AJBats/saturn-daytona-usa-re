/* FUN_06013B04  0x06013B04 */


uint FUN_06013b04(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  
  puVar3 = PTR_DAT_06013bb0;
  puVar2 = PTR_DAT_06013bac;
  puVar1 = PTR_FUN_06013ba8;
  *(short *)PTR_DAT_06013bb0 = *(short *)PTR_DAT_06013bb0 + 1;
  FUN_06013e3c();
  uVar5 = FUN_0601416c();
  uVar6 = *(ushort *)puVar3 - 0x1f;
  if ((int)uVar6 < 0) {
    uVar6 = 0;
  }
  if ((uVar6 >> 5 < 4) && (uVar5 = uVar6 & 0x1f, uVar5 == 0x1f)) {
    uVar5 = uVar6 >> 5;
    if ((uVar5 == 3) && (uVar5 = 0, *(short *)PTR_DAT_06013bb4 != 0)) {
      (*(code *)PTR_FUN_06013bb8)();
      iVar4 = DAT_06013bbc;
      if (*(uint *)puVar2 < 0x25) {
        (*(code *)PTR_FUN_06013bc0)();
      }
      else if (*(uint *)puVar2 < 0x44) {
        (*(code *)PTR_FUN_06013bc4)();
      }
      else {
        (*(code *)PTR_FUN_06013bc8)();
      }
      uVar5 = (*(code *)puVar1)(0,*(int *)(PTR_DAT_06013bcc + (*(int *)puVar2 + -1) * 4) * 0x100 +
                                  iVar4);
    }
    else if (uVar6 >> 5 < 3) {
      uVar7 = DAT_06013c4c;
      if (-1 < (int)((byte)PTR_DAT_06013c44[uVar6 >> 5] - 0x41)) {
        uVar7 = *(undefined4 *)(PTR_DAT_06013c48 + ((byte)PTR_DAT_06013c44[uVar6 >> 5] - 0x41) * 4);
      }
      uVar5 = (*(code *)puVar1)(0,uVar7);
    }
  }
  return uVar5;
}

