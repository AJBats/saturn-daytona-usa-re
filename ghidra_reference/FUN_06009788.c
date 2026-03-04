/* FUN_06009788  0x06009788 */


void FUN_06009788(void)

{
  ushort uVar1;
  short sVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  uint uVar7;
  undefined *puVar8;
  int iVar9;
  int iVar10;
  ushort uVar11;
  undefined *puVar12;
  
  puVar8 = PTR_DAT_060097f0;
  puVar5 = PTR_DAT_060097ec;
  puVar4 = PTR_DAT_060097e8;
  puVar3 = PTR_DAT_060097e4;
  uVar11 = *(ushort *)(PTR_DAT_060097f4 + 2);
  uVar1 = *(ushort *)PTR_DAT_060097f4;
  if (*DAT_060097f8 != '\0') {
    (*(code *)PTR_FUN_060097fc)(0);
  }
  if (*PTR_DAT_06009800 != '\0') {
    if (((uint)uVar11 & (uint)PTR_DAT_06009804) == 0) {
      if (((uVar11 & DAT_060098d4) != 0) && (1 < (byte)*puVar8)) {
        *puVar8 = *puVar8 + -1;
      }
    }
    else if ((byte)*puVar8 < 99) {
      *puVar8 = *puVar8 + '\x01';
    }
    (*(code *)PTR_FUN_060098e4)(8,(int)DAT_060098d6,puVar3,*puVar8);
    (*(code *)PTR_FUN_060098ec)(8,(int)DAT_060098d8,puVar3,PTR_s_Track_No____060098e8);
  }
  puVar6 = PTR_FUN_060098f0;
  iVar9 = (int)DAT_060098da;
  iVar10 = (int)DAT_060098dc;
  if ((((uVar11 & DAT_060098de) == 0) || (*(ushort *)PTR_DAT_060098f4 < 0x14)) ||
     (*PTR_DAT_060098f8 == '\x01')) {
    if ((uVar1 & 0x70) == 0x70) {
      FUN_0600a1b8();
      *(uint *)puVar4 = *(uint *)puVar4 | DAT_060099b8;
      if (*(short *)puVar5 == 0) {
        *DAT_060099cc = 1;
        *(undefined4 *)PTR_DAT_060099c0 = 0xe;
      }
      else {
        *(undefined4 *)PTR_DAT_060099bc = 1;
        *(undefined2 *)puVar5 = 2;
        *(undefined4 *)PTR_DAT_060099c0 = 0x18;
        (*(code *)PTR_FUN_060099c4)();
        *(undefined4 *)PTR_DAT_060099c8 = 0;
      }
    }
    else {
      sVar2 = *(short *)PTR_DAT_060099d0;
      *(ushort *)PTR_DAT_060099d0 = sVar2 + 1U;
      if ((sVar2 + 1U & 0x10) == 0) {
        if (*(short *)puVar5 == 0) {
          (*(code *)puVar6)(8,iVar9,iVar10,PTR_s_PRESS_X__Y__AND_Z_BUTTON_06009a40);
          puVar8 = PTR_s_TO_RESTART_GAME_06009a44;
        }
        else {
          (*(code *)puVar6)(8,iVar9,iVar10,PTR_s_PRESS_X__Y__AND_Z_BUTTON_060099d8);
          puVar8 = PTR_s_TO_SKIP_REPLAY_060099dc;
        }
        (*(code *)puVar6)(8,(int)DAT_06009a3c,iVar10,puVar8);
      }
      else {
        puVar8 = PTR_DAT_060099d4;
        (*(code *)puVar6)(8,iVar9,iVar10,PTR_DAT_060099d4);
        (*(code *)puVar6)(8,(int)PTR_DAT_060099b4._0_2_,iVar10,puVar8);
      }
    }
  }
  else {
    (*(code *)PTR_FUN_06009900)(0,DAT_060098fc);
    puVar12 = PTR_PTR_06009904;
    (*(code *)puVar6)(8,(int)DAT_060098e0,iVar10,PTR_PTR_06009904 + 0x3b);
    (*(code *)puVar6)(8,iVar9,iVar10,puVar12 + 0x28);
    (*(code *)puVar6)(8,(int)DAT_060098e2,iVar10,puVar12 + 0x2e);
    *(undefined4 *)PTR_DAT_0600990c = *(undefined4 *)PTR_DAT_06009908;
    *PTR_DAT_06009914 = *PTR_DAT_06009910;
    if (*PTR_DAT_060098f8 != '\0') {
      *PTR_DAT_060098f8 = 0;
      uVar7 = (uint)(byte)*puVar8;
      (*(code *)PTR_FUN_06009918)(uVar7,uVar7,0xf);
      (*(code *)PTR_FUN_060098ec)(8,(int)DAT_060098d8,puVar3,PTR_s__0600991c,uVar7);
    }
  }
  if (*(short *)puVar5 != 0) {
    (*(code *)PTR_FUN_06009a48)();
  }
  if (*PTR_DAT_06009a4c != '\0') {
    (*(code *)PTR_FUN_06009a54)(8,(int)DAT_06009a3e,puVar3,PTR_DAT_06009a50);
  }
  puVar3 = PTR_FUN_06009a58;
  *(uint *)puVar4 = *(uint *)puVar4 | 4;
  (*(code *)puVar3)();
  *(undefined4 *)PTR_DAT_06009a5c = 0;
  return;
}

