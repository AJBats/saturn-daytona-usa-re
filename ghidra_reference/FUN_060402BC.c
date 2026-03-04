/* FUN_060402BC  0x060402BC */


undefined4 FUN_060402bc(int param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int local_3c;
  undefined1 auStack_38 [4];
  undefined4 local_34;
  int iStack_30;
  undefined4 uStack_2c;
  int iStack_28;
  undefined1 uStack_24;
  
  puVar2 = PTR_DAT_060402f0;
  puVar1 = PTR_FUN_060402ec;
  iVar8 = *(int *)(param_1 + 0x18);
  iVar7 = *(int *)(param_1 + 0x20) - *(int *)(param_1 + 0x24);
  iVar3 = FUN_060405b8(&local_3c,auStack_38);
  if (iVar3 == 0) {
    iVar6 = (*(code *)PTR_FUN_06040344)();
    if (iVar6 == 0) {
      return 1;
    }
  }
  else if ((iVar3 != 1) && (iVar3 != 2)) {
    if (iVar3 == 3) {
      return 3;
    }
    if (iVar3 != 4) {
      (*(code *)puVar1)(*(undefined4 *)(iVar8 + 0x28));
      return 6;
    }
    return 4;
  }
  if ((*(int *)(param_1 + 0x20) == 0) && (*(int *)(param_1 + 0x24) == 0)) {
    uVar4 = 2;
  }
  else {
    iVar6 = *(int *)(param_1 + 0x28);
    if (iVar7 < iVar6) {
      iVar6 = iVar7;
    }
    iVar7 = (*(code *)PTR_FUN_060403d8)(*(undefined4 *)(iVar8 + 0x28));
    if (iVar7 == 0) {
      iVar3 = (*(code *)PTR_FUN_060403e0)(*(undefined4 *)(param_1 + 0x18),DAT_060403dc,0);
      if (iVar3 < 0) {
        iVar3 = 0;
      }
      uVar4 = (*(code *)PTR_FUN_060403e4)(iVar8);
      iVar7 = FUN_06040722(param_1,uVar4);
      iVar7 = *(int *)(param_1 + 4) + iVar7;
      if ((0 < iVar3) && (iVar7 < *(int *)(*(int *)PTR_DAT_060403e8 + (int)DAT_060403d6))) {
        iVar3 = iVar3 - (*(int *)(*(int *)puVar2 + (int)DAT_060403d6) - iVar7);
      }
      if (iVar3 < iVar6) {
        iVar6 = iVar6 - iVar3;
        if (iVar6 < 1) {
          if (*(int *)(param_1 + 0x20) == *(int *)(param_1 + 0x24)) {
            uVar4 = 2;
          }
          else {
            uVar4 = 0;
          }
        }
        else {
          iVar3 = (*(code *)PTR_FUN_060403ec)();
          if (iVar3 < 0) {
            uVar4 = 6;
          }
          else {
            *(int *)(iVar8 + 0x28) = iVar3;
            iVar5 = (*(code *)PTR_FUN_060404c0)(iVar8);
            iVar5 = FUN_06040722(param_1,iVar6 + iVar5);
            *(int *)(param_1 + 8) = iVar5 + *(int *)(param_1 + 4);
            local_34 = 1;
            uStack_2c = 1;
            iStack_28 = *(int *)(param_1 + 8) - iVar7;
            uStack_24 = 0;
            iStack_30 = iVar7;
            FUN_060405b8(&local_3c,0);
            if ((((iStack_30 < *(int *)(*(int *)puVar2 + (int)DAT_060404ba)) ||
                 (*(int *)(*(int *)puVar2 + (int)PTR_DAT_060404bc._0_2_) <= iStack_30)) ||
                (*(int *)(param_1 + 8) <= *(int *)(*(int *)puVar2 + (int)DAT_060404ba))) ||
               (*(int *)(*(int *)puVar2 + (int)PTR_DAT_060404bc._0_2_) < *(int *)(param_1 + 8))) {
              (*(code *)PTR_FUN_060404c4)(*(undefined4 *)(iVar8 + 0x14),iVar3);
              iVar7 = (*(code *)PTR_FUN_060404c8)();
              if (iVar7 == 0) {
                (*(code *)PTR_FUN_060404cc)(&local_34,iVar3);
                *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + iVar6;
                iVar3 = (int)DAT_060404ba;
                *(int *)(*(int *)puVar2 + iVar3) = iStack_30;
                *(undefined4 *)(*(int *)puVar2 + iVar3 + 4) = *(undefined4 *)(param_1 + 8);
                uVar4 = 0;
              }
              else {
                uVar4 = 6;
              }
            }
            else {
              *(int *)(*(int *)puVar2 + (int)DAT_060404ba) = iStack_30;
              uVar4 = 0;
            }
          }
        }
      }
      else {
        iVar6 = *(int *)(param_1 + 0x24) + iVar6;
        *(int *)(param_1 + 0x24) = iVar6;
        if (*(int *)(param_1 + 0x20) == iVar6) {
          uVar4 = 2;
        }
        else {
          uVar4 = 0;
        }
      }
    }
    else if (local_3c < *(int *)(param_1 + 8)) {
      if (local_3c - *(int *)(*(int *)puVar2 + (int)DAT_06040538) < *(int *)(param_1 + 0x20)) {
        if (iVar3 == 0) {
          (*(code *)puVar1)(*(undefined4 *)(iVar8 + 0x28));
          uVar4 = 6;
        }
        else {
          uVar4 = 0;
        }
      }
      else {
        (*(code *)puVar1)(*(undefined4 *)(iVar8 + 0x28));
        uVar4 = 2;
      }
    }
    else {
      (*(code *)puVar1)(*(undefined4 *)(iVar8 + 0x28));
      if (local_3c < *(int *)(*(int *)puVar2 + (int)DAT_06040536)) {
        uVar4 = 0;
      }
      else {
        *(undefined4 *)(*(int *)puVar2 + DAT_06040536 + -4) =
             *(undefined4 *)(*(int *)puVar2 + (int)DAT_06040536);
        uVar4 = 2;
      }
    }
  }
  return uVar4;
}

