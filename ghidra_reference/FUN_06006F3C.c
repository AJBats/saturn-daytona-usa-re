/* FUN_06006F3C  0x06006F3C */


uint FUN_06006f3c(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  undefined *puVar7;
  undefined *puVar8;
  uint uVar9;
  
  puVar6 = PTR_DAT_06006ff0;
  puVar5 = PTR_DAT_06006fec;
  puVar4 = PTR_DAT_06006fe8;
  puVar3 = PTR_FUN_06006fe4;
  puVar2 = PTR_FUN_06006fe0;
  puVar1 = PTR_FUN_06006fdc;
  *(int *)PTR_DAT_06006ff4 = *(int *)PTR_DAT_06006ff4 + 1;
  *(undefined4 *)PTR_DAT_06006ff8 = 1;
  uVar9 = (uint)*(ushort *)PTR_DAT_06006ffc;
  if (uVar9 == 0) {
    *(undefined4 *)PTR_DAT_06007000 = 0;
    puVar8 = PTR_DAT_0600700c;
    puVar7 = PTR_VDP1_FBCR_06007008;
    if (*(short *)PTR_PTR_06007004 == 2) {
      if (*(int *)puVar4 != 0) {
        (*(code *)puVar3)();
        *(undefined4 *)PTR_DAT_06007000 = 2;
      }
    }
    else if (*(short *)PTR_PTR_06007004 == 3) {
      if (*(int *)puVar4 != 0) {
        *(ushort *)PTR_VDP1_TVMR_06007014 = *(ushort *)PTR_DAT_06007010 | 8;
        *(ushort *)puVar7 = *(ushort *)puVar8 | 3;
        (*(code *)puVar3)();
        *(undefined4 *)PTR_DAT_06007000 = 3;
      }
    }
    else if (*(short *)PTR_PTR_06007004 == 0) {
      (*(code *)puVar3)();
      *(undefined4 *)puVar4 = 0;
    }
    else {
      *(int *)puVar5 = *(int *)puVar5 + 1;
      if ((*(int *)PTR_DAT_060070f0 == 1) && (*(int *)PTR_DAT_060070f4 + -1 <= *(int *)puVar5)) {
        *(ushort *)puVar7 = *(ushort *)puVar8 | 2;
      }
      if (*(int *)PTR_DAT_060070f4 <= *(int *)puVar5) {
        if (*(int *)puVar4 != 0) {
          (*(code *)puVar3)();
          *(undefined4 *)PTR_DAT_060070f8 = 1;
        }
        *(undefined4 *)puVar5 = 0;
      }
    }
    *(undefined **)PTR_DAT_06007108 =
         PTR_DAT_06007104 +
         (*(uint *)PTR_DAT_060070fc >> 2) * 0x50 + (*(uint *)PTR_DAT_06007100 >> 1);
    if ((*(uint *)puVar6 & (uint)PTR_DAT_0600710c) != 0) {
      (*(code *)PTR_FUN_06007114)
                (*(undefined4 *)PTR_DAT_06007110,*(undefined4 *)PTR_DAT_06007108,(int)DAT_060070ea);
    }
    if ((*(uint *)puVar6 & 4) != 0) {
      (*(code *)PTR_FUN_06007114)
                (*(undefined4 *)PTR_DAT_0600711c,*(undefined4 *)PTR_DAT_06007118,(int)DAT_060070ec);
    }
    if ((*(uint *)puVar6 & 0x10) != 0) {
      (*(code *)puVar1)(4,*(undefined4 *)PTR_DAT_06007124,*(undefined4 *)PTR_DAT_06007120);
    }
    if ((*(uint *)puVar6 & 0x20) != 0) {
      (*(code *)puVar1)(8,*(undefined4 *)PTR_DAT_0600712c,*(undefined4 *)PTR_DAT_06007128);
    }
    if ((*(uint *)puVar6 & 0x40) != 0) {
      (*(code *)puVar1)(0x10,*(undefined4 *)PTR_DAT_06007134,*(undefined4 *)PTR_DAT_06007130);
    }
    uVar9 = *(uint *)puVar6;
    if ((uVar9 & 0x80) != 0) {
      uVar9 = (*(code *)puVar1)(0x20,*(undefined4 *)PTR_DAT_06007208,*(undefined4 *)PTR_DAT_06007138
                               );
    }
    if ((*(uint *)puVar6 & (uint)PTR_DAT_0600720c) != 0) {
      uVar9 = (*(code *)puVar2)(4,*(undefined4 *)PTR_PTR_06007214,*(undefined4 *)PTR_PTR_06007210);
    }
    if ((*(uint *)puVar6 & (uint)PTR_DAT_06007218) != 0) {
      uVar9 = (*(code *)puVar2)(8,*(undefined4 *)PTR_PTR_06007220,*(undefined4 *)PTR_PTR_0600721c);
    }
    if ((*(uint *)puVar6 & (uint)PTR_DAT_06007224) != 0) {
      uVar9 = (*(code *)puVar2)(0x10,*(undefined4 *)PTR_PTR_0600722c,*(undefined4 *)PTR_PTR_06007228
                               );
    }
    if ((*(uint *)puVar6 & (uint)PTR_DAT_06007230) != 0) {
      uVar9 = (*(code *)puVar2)(0x20,*(undefined4 *)PTR_PTR_06007238,*(undefined4 *)PTR_PTR_06007234
                               );
    }
    if ((*(uint *)puVar6 & DAT_0600723c) != 0) {
      uVar9 = (*(code *)PTR_FUN_06007240)();
    }
    if ((*(uint *)puVar6 & DAT_06007244) != 0) {
      uVar9 = (*(code *)PTR_FUN_06007248)();
    }
    if ((*(uint *)puVar6 & (uint)PTR_DAT_0600724c) != 0) {
      uVar9 = (*(code *)PTR_FUN_06007250)();
    }
    if ((*(uint *)puVar6 & (uint)PTR_DAT_06007254) != 0) {
      uVar9 = (*(code *)PTR_FUN_06007258)();
    }
    if ((*(uint *)puVar6 & DAT_0600725c) != 0) {
      uVar9 = (*(code *)PTR_FUN_06007260)();
    }
    *(undefined4 *)puVar6 = 0;
  }
  *(undefined4 *)PTR_DAT_06007264 = 2;
  return uVar9;
}

