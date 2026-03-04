/* FUN_06022820  0x06022820 */


/* WARNING: Restarted to delay deadcode elimination for space: stack */

int FUN_06022820(int *param_1,short *param_2)

{
  int iVar1;
  short *psVar2;
  short *psVar3;
  int *piVar4;
  short *psVar5;
  int *piVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  int *piVar10;
  int *piVar11;
  int *piVar12;
  short local_24;
  short local_22;
  short local_20;
  short local_1e;
  
  iVar7 = (int)DAT_060228d2;
  local_24 = *param_2;
  psVar2 = param_2 + 1;
  local_22 = *psVar2;
  psVar3 = param_2 + 2;
  local_20 = *psVar3;
  psVar5 = param_2 + 3;
  local_1e = *psVar5;
  piVar12 = param_1 + 1;
  piVar6 = param_1 + 2;
  piVar4 = param_1 + 3;
  piVar10 = param_1 + 6;
  piVar11 = param_1 + 7;
  piVar8 = param_1 + 4;
  piVar9 = param_1 + 5;
  do {
    if ((*param_2 != 0) && (local_24 != 0)) {
      if (*psVar2 == 0) {
        *param_1 = *param_1 * 3 + *piVar6 >> 2;
        *piVar12 = *piVar12 * 3 + *piVar4 >> 2;
      }
      else if (*psVar5 == 0) {
        *param_1 = *param_1 * 3 + *piVar10 >> 2;
        *piVar12 = *piVar12 * 3 + *piVar11 >> 2;
      }
      if ((((iVar7 <= *param_1) && (*param_1 <= (int)DAT_0602295c)) && (iVar7 <= *piVar12)) &&
         (*piVar12 <= (int)DAT_0602295e)) {
        local_24 = 0;
      }
    }
    if ((*psVar2 != 0) && (local_22 != 0)) {
      if (*psVar3 == 0) {
        *piVar6 = *piVar6 * 3 + *piVar8 >> 2;
        *piVar4 = *piVar4 * 3 + *piVar9 >> 2;
      }
      else if (*param_2 == 0) {
        *piVar6 = *piVar6 * 3 + *param_1 >> 2;
        *piVar4 = *piVar4 * 3 + *piVar12 >> 2;
      }
      if (((iVar7 <= *piVar6) && (*piVar6 <= (int)DAT_060229e4)) &&
         ((iVar7 <= *piVar4 && (*piVar4 <= (int)DAT_060229e6)))) {
        local_22 = 0;
      }
    }
    if ((*psVar3 != 0) && (local_20 != 0)) {
      if (*psVar5 == 0) {
        *piVar8 = *piVar8 * 3 + *piVar10 >> 2;
        *piVar9 = *piVar9 * 3 + *piVar11 >> 2;
      }
      else if (*psVar2 == 0) {
        *piVar8 = *piVar8 * 3 + *piVar6 >> 2;
        *piVar9 = *piVar9 * 3 + *piVar4 >> 2;
      }
      if ((((iVar7 <= *piVar8) && (*piVar8 <= (int)DAT_06022a68)) && (iVar7 <= *piVar9)) &&
         (*piVar9 <= (int)DAT_06022a6a)) {
        local_20 = 0;
      }
    }
    iVar1 = 0;
    if ((*psVar5 != 0) && (iVar1 = (int)local_1e, iVar1 != 0)) {
      if (*param_2 == 0) {
        *piVar10 = *piVar10 * 3 + *param_1 >> 2;
        *piVar11 = *piVar11 * 3 + *piVar12 >> 2;
      }
      else if (*psVar3 == 0) {
        *piVar10 = *piVar10 * 3 + *piVar8 >> 2;
        *piVar11 = *piVar11 * 3 + *piVar9 >> 2;
      }
      if (((iVar7 <= *piVar10) && (*piVar10 <= (int)DAT_06022adc)) &&
         ((iVar7 <= *piVar11 && (*piVar11 <= (int)DAT_06022ade)))) {
        local_1e = 0;
      }
    }
  } while (((local_24 != 0 || local_22 != 0) || local_20 != 0) || local_1e != 0);
  return iVar1;
}

