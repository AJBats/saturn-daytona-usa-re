/* FUN_06022AE0  0x06022AE0 */


/* WARNING: Restarted to delay deadcode elimination for space: stack */

void FUN_06022ae0(int *param_1,short *param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  short local_24;
  short local_22;
  short local_20;
  short local_1e;
  
  iVar1 = (int)DAT_06022bba;
  local_24 = *param_2;
  local_22 = param_2[1];
  local_20 = param_2[2];
  local_1e = param_2[3];
  piVar8 = param_1 + 2;
  piVar3 = param_1 + 3;
  piVar5 = param_1 + 1;
  piVar2 = param_1 + 4;
  piVar4 = param_1 + 5;
  piVar6 = param_1 + 6;
  piVar7 = param_1 + 7;
  do {
    if (*param_2 == 0) {
      if (local_22 != 0) {
        *piVar8 = *piVar8 * 3 + *param_1 >> 2;
        *piVar3 = *piVar3 * 3 + *piVar5 >> 2;
        if ((((iVar1 <= *piVar8) && (*piVar8 <= (int)DAT_06022bbc)) && (iVar1 <= *piVar3)) &&
           (*piVar3 <= (int)DAT_06022bbe)) {
          local_22 = 0;
        }
      }
      if (local_20 != 0) {
        *piVar2 = *piVar2 * 3 + *param_1 >> 2;
        *piVar4 = *piVar4 * 3 + *piVar5 >> 2;
        if (((iVar1 <= *piVar2) && (*piVar2 <= (int)DAT_06022c7a)) &&
           ((iVar1 <= *piVar4 && (*piVar4 <= (int)DAT_06022c7c)))) {
          local_20 = 0;
        }
      }
      if (local_1e != 0) {
        *piVar6 = *piVar6 * 3 + *param_1 >> 2;
        *piVar7 = *piVar7 * 3 + *piVar5 >> 2;
        if (((iVar1 <= *piVar6) && (*piVar6 <= (int)DAT_06022c7a)) &&
           ((iVar1 <= *piVar7 && (*piVar7 <= (int)DAT_06022c7c)))) {
          local_1e = 0;
        }
      }
    }
    else if (param_2[1] == 0) {
      if (local_24 != 0) {
        *param_1 = *param_1 * 3 + *piVar8 >> 2;
        *piVar5 = *piVar5 * 3 + *piVar3 >> 2;
        if ((((iVar1 <= *param_1) && (*param_1 <= (int)DAT_06022d4e)) && (iVar1 <= *piVar5)) &&
           (*piVar5 <= (int)DAT_06022d50)) {
          local_24 = 0;
        }
      }
      if (local_20 != 0) {
        *piVar2 = *piVar2 * 3 + *piVar8 >> 2;
        *piVar4 = *piVar4 * 3 + *piVar3 >> 2;
        if (((iVar1 <= *piVar2) && (*piVar2 <= (int)DAT_06022d4e)) &&
           ((iVar1 <= *piVar4 && (*piVar4 <= (int)DAT_06022d50)))) {
          local_20 = 0;
        }
      }
      if (local_1e != 0) {
        *piVar6 = *piVar6 * 3 + *piVar8 >> 2;
        *piVar7 = *piVar7 * 3 + *piVar3 >> 2;
        if (((iVar1 <= *piVar6) && (*piVar6 <= (int)DAT_06022db0)) &&
           ((iVar1 <= *piVar7 && (*piVar7 <= (int)DAT_06022db2)))) {
          local_1e = 0;
        }
      }
    }
    else if (param_2[2] == 0) {
      if (local_24 != 0) {
        *param_1 = *param_1 * 3 + *piVar2 >> 2;
        *piVar5 = *piVar5 * 3 + *piVar4 >> 2;
        if ((((iVar1 <= *param_1) && (*param_1 <= (int)DAT_06022e84)) && (iVar1 <= *piVar5)) &&
           (*piVar5 <= (int)DAT_06022e86)) {
          local_24 = 0;
        }
      }
      if (local_22 != 0) {
        *piVar8 = *piVar8 * 3 + *piVar2 >> 2;
        *piVar3 = *piVar3 * 3 + *piVar4 >> 2;
        if (((iVar1 <= *piVar8) && (*piVar8 <= (int)DAT_06022e84)) &&
           ((iVar1 <= *piVar3 && (*piVar3 <= (int)DAT_06022e86)))) {
          local_22 = 0;
        }
      }
      if (local_1e != 0) {
        *piVar6 = *piVar6 * 3 + *piVar2 >> 2;
        *piVar7 = *piVar7 * 3 + *piVar4 >> 2;
        if (((iVar1 <= *piVar6) && (*piVar6 <= (int)DAT_06022ee6)) &&
           ((iVar1 <= *piVar7 && (*piVar7 <= (int)DAT_06022ee8)))) {
          local_1e = 0;
        }
      }
    }
    else if (param_2[3] == 0) {
      if (local_24 != 0) {
        *param_1 = *param_1 * 3 + *piVar6 >> 2;
        *piVar5 = *piVar5 * 3 + *piVar7 >> 2;
        if ((((iVar1 <= *param_1) && (*param_1 <= (int)DAT_06022fba)) && (iVar1 <= *piVar5)) &&
           (*piVar5 <= (int)DAT_06022fbc)) {
          local_24 = 0;
        }
      }
      if (local_22 != 0) {
        *piVar8 = *piVar8 * 3 + *piVar6 >> 2;
        *piVar3 = *piVar3 * 3 + *piVar7 >> 2;
        if (((iVar1 <= *piVar8) && (*piVar8 <= (int)DAT_06022fba)) &&
           ((iVar1 <= *piVar3 && (*piVar3 <= (int)DAT_06022fbc)))) {
          local_22 = 0;
        }
      }
      if (local_20 != 0) {
        *piVar2 = *piVar2 * 3 + *piVar6 >> 2;
        *piVar4 = *piVar4 * 3 + *piVar7 >> 2;
        if (((iVar1 <= *piVar2) && (*piVar2 <= (int)DAT_06023048)) &&
           ((iVar1 <= *piVar4 && (*piVar4 <= (int)DAT_0602304a)))) {
          local_20 = 0;
        }
      }
    }
  } while (((local_24 != 0 || local_22 != 0) || local_20 != 0) || local_1e != 0);
  return;
}

