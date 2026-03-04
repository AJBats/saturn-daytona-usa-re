/* FUN_06007E08  0x06007E08 */


/* WARNING: Restarted to delay deadcode elimination for space: stack */

ushort FUN_06007e08(int *param_1,short *param_2)

{
  ushort uVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  int iVar9;
  int *piVar10;
  ushort local_24 [4];
  
  iVar2 = (int)DAT_06007edc;
  iVar9 = 0;
  do {
    local_24[(int)(iVar9 + (uint)(iVar9 < 0)) >> 1] = 0;
    if (((((int)DAT_06007ede < param_1[iVar9]) && (param_1[iVar9] < (int)DAT_06007ee0)) &&
        (-0x7f < param_1[iVar9 + 1])) && (param_1[iVar9 + 1] < 0x51)) {
      local_24[(int)(iVar9 + (uint)(iVar9 < 0)) >> 1] = 1;
    }
    iVar9 = iVar9 + 2;
  } while (iVar9 < 8);
  if (*param_2 == 0) {
    if (param_2[1] == 0) {
      if (param_2[2] == 0) {
        if (local_24[0] == local_24[2]) {
          local_24[0] = (ushort)(param_1[5] > param_1[1]);
          local_24[2] = (ushort)(param_1[5] <= param_1[1]);
        }
      }
      else if (local_24[3] == local_24[1]) {
        local_24[3] = (ushort)(param_1[3] > param_1[7]);
        local_24[1] = (ushort)(param_1[3] <= param_1[7]);
      }
    }
    else if (local_24[2] == local_24[0]) {
      local_24[2] = (ushort)(param_1[1] > param_1[5]);
      local_24[0] = (ushort)(param_1[1] <= param_1[5]);
    }
  }
  else if (local_24[1] == local_24[3]) {
    local_24[1] = (ushort)(param_1[7] > param_1[3]);
    local_24[3] = (ushort)(param_1[7] <= param_1[3]);
  }
  piVar6 = param_1 + 2;
  piVar7 = param_1 + 1;
  piVar5 = param_1 + 3;
  piVar10 = param_1 + 6;
  piVar8 = param_1 + 7;
  piVar3 = param_1 + 4;
  piVar4 = param_1 + 5;
  do {
    while( true ) {
      while (*param_2 != 0) {
        if (local_24[1] == 0) {
          uVar1 = local_24[3];
          if (local_24[3] != 0) {
            *param_1 = *param_1 * 3 + *piVar10 >> 2;
            *piVar7 = *piVar7 * 3 + *piVar8 >> 2;
          }
        }
        else {
          *param_1 = *param_1 * 3 + *piVar6 >> 2;
          *piVar7 = *piVar7 * 3 + *piVar5 >> 2;
          uVar1 = local_24[1];
        }
        if (((iVar2 <= *param_1) && (*param_1 <= (int)DAT_06008056)) &&
           ((iVar2 <= *piVar7 && (*piVar7 <= (int)DAT_06008058)))) {
          return uVar1;
        }
      }
      if (param_2[1] != 0) break;
      if (param_2[2] == 0) {
        if (local_24[0] == 0) {
          uVar1 = local_24[2];
          if (local_24[2] != 0) {
            *piVar10 = *piVar10 * 3 + *piVar3 >> 2;
            *piVar8 = *piVar8 * 3 + *piVar4 >> 2;
          }
        }
        else {
          *piVar10 = *piVar10 * 3 + *param_1 >> 2;
          *piVar8 = *piVar8 * 3 + *piVar7 >> 2;
          uVar1 = local_24[0];
        }
        if (((iVar2 <= *piVar10) && (*piVar10 <= (int)DAT_060081d8)) &&
           ((iVar2 <= *piVar8 && (*piVar8 <= (int)DAT_060081da)))) {
          return uVar1;
        }
      }
      else {
        if (local_24[3] == 0) {
          uVar1 = local_24[1];
          if (local_24[1] != 0) {
            *piVar3 = *piVar3 * 3 + *piVar6 >> 2;
            *piVar4 = *piVar4 * 3 + *piVar5 >> 2;
          }
        }
        else {
          *piVar3 = *piVar3 * 3 + *piVar10 >> 2;
          *piVar4 = *piVar4 * 3 + *piVar8 >> 2;
          uVar1 = local_24[3];
        }
        if (((iVar2 <= *piVar3) && (*piVar3 <= (int)DAT_060081d8)) &&
           ((iVar2 <= *piVar4 && (*piVar4 <= (int)DAT_060081da)))) {
          return uVar1;
        }
      }
    }
    if (local_24[2] == 0) {
      uVar1 = local_24[0];
      if (local_24[0] != 0) {
        *piVar6 = *piVar6 * 3 + *param_1 >> 2;
        *piVar5 = *piVar5 * 3 + *piVar7 >> 2;
      }
    }
    else {
      *piVar6 = *piVar6 * 3 + *piVar3 >> 2;
      *piVar5 = *piVar5 * 3 + *piVar4 >> 2;
      uVar1 = local_24[2];
    }
  } while ((((*piVar6 < iVar2) || ((int)DAT_060080f6 < *piVar6)) || (*piVar5 < iVar2)) ||
          ((int)DAT_060080f8 < *piVar5));
  return uVar1;
}

