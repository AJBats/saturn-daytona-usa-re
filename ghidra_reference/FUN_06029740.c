/* FUN_06029740  0x06029740 */


void FUN_06029740(int *param_1,short *param_2)

{
  short sVar1;
  short sVar2;
  short sVar3;
  undefined *puVar4;
  undefined *puVar5;
  int iVar6;
  int iVar7;
  
  puVar5 = PTR_DAT_06029774;
  puVar4 = PTR_DAT_06029770;
  iVar7 = *(int *)PTR_DAT_06029778;
  sVar2 = param_2[1];
  sVar3 = param_2[2];
  sVar1 = *param_2;
  do {
    if (sVar1 == 0) {
      if (param_2[1] != 0) {
        param_1[3] = ((int)((ulonglong)((longlong)(int)puVar4 * (longlong)param_1[3]) >> 0x20) <<
                      0x10 | (uint)((longlong)(int)puVar4 * (longlong)param_1[3]) >> 0x10) +
                     ((int)((ulonglong)((longlong)(int)puVar5 * (longlong)*param_1) >> 0x20) << 0x10
                     | (uint)((longlong)(int)puVar5 * (longlong)*param_1) >> 0x10);
        param_1[4] = ((int)((ulonglong)((longlong)(int)puVar4 * (longlong)param_1[4]) >> 0x20) <<
                      0x10 | (uint)((longlong)(int)puVar4 * (longlong)param_1[4]) >> 0x10) +
                     ((int)((ulonglong)((longlong)(int)puVar5 * (longlong)param_1[1]) >> 0x20) <<
                      0x10 | (uint)((longlong)(int)puVar5 * (longlong)param_1[1]) >> 0x10);
        iVar6 = ((int)((ulonglong)((longlong)(int)puVar4 * (longlong)param_1[5]) >> 0x20) << 0x10 |
                (uint)((longlong)(int)puVar4 * (longlong)param_1[5]) >> 0x10) +
                ((int)((ulonglong)((longlong)(int)puVar5 * (longlong)param_1[2]) >> 0x20) << 0x10 |
                (uint)((longlong)(int)puVar5 * (longlong)param_1[2]) >> 0x10) + 4;
        param_1[5] = iVar6;
        if (iVar7 < iVar6) {
          param_2[1] = 0;
        }
      }
      if (param_2[2] != 0) {
        param_1[6] = ((int)((ulonglong)((longlong)(int)puVar4 * (longlong)param_1[6]) >> 0x20) <<
                      0x10 | (uint)((longlong)(int)puVar4 * (longlong)param_1[6]) >> 0x10) +
                     ((int)((ulonglong)((longlong)(int)puVar5 * (longlong)*param_1) >> 0x20) << 0x10
                     | (uint)((longlong)(int)puVar5 * (longlong)*param_1) >> 0x10);
        param_1[7] = ((int)((ulonglong)((longlong)(int)puVar4 * (longlong)param_1[7]) >> 0x20) <<
                      0x10 | (uint)((longlong)(int)puVar4 * (longlong)param_1[7]) >> 0x10) +
                     ((int)((ulonglong)((longlong)(int)puVar5 * (longlong)param_1[1]) >> 0x20) <<
                      0x10 | (uint)((longlong)(int)puVar5 * (longlong)param_1[1]) >> 0x10);
        iVar6 = ((int)((ulonglong)((longlong)(int)puVar4 * (longlong)param_1[8]) >> 0x20) << 0x10 |
                (uint)((longlong)(int)puVar4 * (longlong)param_1[8]) >> 0x10) +
                ((int)((ulonglong)((longlong)(int)puVar5 * (longlong)param_1[2]) >> 0x20) << 0x10 |
                (uint)((longlong)(int)puVar5 * (longlong)param_1[2]) >> 0x10) + 4;
        param_1[8] = iVar6;
        if (iVar7 < iVar6) {
          param_2[2] = 0;
        }
      }
      if (param_2[3] != 0) {
        param_1[9] = ((int)((ulonglong)((longlong)(int)puVar4 * (longlong)param_1[9]) >> 0x20) <<
                      0x10 | (uint)((longlong)(int)puVar4 * (longlong)param_1[9]) >> 0x10) +
                     ((int)((ulonglong)((longlong)(int)puVar5 * (longlong)*param_1) >> 0x20) << 0x10
                     | (uint)((longlong)(int)puVar5 * (longlong)*param_1) >> 0x10);
        param_1[10] = ((int)((ulonglong)((longlong)(int)puVar4 * (longlong)param_1[10]) >> 0x20) <<
                       0x10 | (uint)((longlong)(int)puVar4 * (longlong)param_1[10]) >> 0x10) +
                      ((int)((ulonglong)((longlong)(int)puVar5 * (longlong)param_1[1]) >> 0x20) <<
                       0x10 | (uint)((longlong)(int)puVar5 * (longlong)param_1[1]) >> 0x10);
        iVar6 = ((int)((ulonglong)((longlong)(int)puVar4 * (longlong)param_1[0xb]) >> 0x20) << 0x10
                | (uint)((longlong)(int)puVar4 * (longlong)param_1[0xb]) >> 0x10) +
                ((int)((ulonglong)((longlong)(int)puVar5 * (longlong)param_1[2]) >> 0x20) << 0x10 |
                (uint)((longlong)(int)puVar5 * (longlong)param_1[2]) >> 0x10) + 4;
        param_1[0xb] = iVar6;
        if (iVar7 < iVar6) {
          param_2[3] = 0;
        }
      }
    }
    else if (sVar2 == 0) {
      if (*param_2 != 0) {
        *param_1 = ((int)((ulonglong)((longlong)(int)puVar4 * (longlong)*param_1) >> 0x20) << 0x10 |
                   (uint)((longlong)(int)puVar4 * (longlong)*param_1) >> 0x10) +
                   ((int)((ulonglong)((longlong)(int)puVar5 * (longlong)param_1[3]) >> 0x20) << 0x10
                   | (uint)((longlong)(int)puVar5 * (longlong)param_1[3]) >> 0x10);
        param_1[1] = ((int)((ulonglong)((longlong)(int)puVar4 * (longlong)param_1[1]) >> 0x20) <<
                      0x10 | (uint)((longlong)(int)puVar4 * (longlong)param_1[1]) >> 0x10) +
                     ((int)((ulonglong)((longlong)(int)puVar5 * (longlong)param_1[4]) >> 0x20) <<
                      0x10 | (uint)((longlong)(int)puVar5 * (longlong)param_1[4]) >> 0x10);
        iVar6 = ((int)((ulonglong)((longlong)(int)puVar4 * (longlong)param_1[2]) >> 0x20) << 0x10 |
                (uint)((longlong)(int)puVar4 * (longlong)param_1[2]) >> 0x10) +
                ((int)((ulonglong)((longlong)(int)puVar5 * (longlong)param_1[5]) >> 0x20) << 0x10 |
                (uint)((longlong)(int)puVar5 * (longlong)param_1[5]) >> 0x10) + 4;
        param_1[2] = iVar6;
        if (iVar7 < iVar6) {
          *param_2 = 0;
        }
      }
      if (param_2[2] != 0) {
        param_1[6] = ((int)((ulonglong)((longlong)(int)puVar4 * (longlong)param_1[6]) >> 0x20) <<
                      0x10 | (uint)((longlong)(int)puVar4 * (longlong)param_1[6]) >> 0x10) +
                     ((int)((ulonglong)((longlong)(int)puVar5 * (longlong)param_1[3]) >> 0x20) <<
                      0x10 | (uint)((longlong)(int)puVar5 * (longlong)param_1[3]) >> 0x10);
        param_1[7] = ((int)((ulonglong)((longlong)(int)puVar4 * (longlong)param_1[7]) >> 0x20) <<
                      0x10 | (uint)((longlong)(int)puVar4 * (longlong)param_1[7]) >> 0x10) +
                     ((int)((ulonglong)((longlong)(int)puVar5 * (longlong)param_1[4]) >> 0x20) <<
                      0x10 | (uint)((longlong)(int)puVar5 * (longlong)param_1[4]) >> 0x10);
        iVar6 = ((int)((ulonglong)((longlong)(int)puVar4 * (longlong)param_1[8]) >> 0x20) << 0x10 |
                (uint)((longlong)(int)puVar4 * (longlong)param_1[8]) >> 0x10) +
                ((int)((ulonglong)((longlong)(int)puVar5 * (longlong)param_1[5]) >> 0x20) << 0x10 |
                (uint)((longlong)(int)puVar5 * (longlong)param_1[5]) >> 0x10) + 4;
        param_1[8] = iVar6;
        if (iVar7 < iVar6) {
          param_2[2] = 0;
        }
      }
      if (param_2[3] != 0) {
        param_1[9] = ((int)((ulonglong)((longlong)(int)puVar4 * (longlong)param_1[9]) >> 0x20) <<
                      0x10 | (uint)((longlong)(int)puVar4 * (longlong)param_1[9]) >> 0x10) +
                     ((int)((ulonglong)((longlong)(int)puVar5 * (longlong)param_1[3]) >> 0x20) <<
                      0x10 | (uint)((longlong)(int)puVar5 * (longlong)param_1[3]) >> 0x10);
        param_1[10] = ((int)((ulonglong)((longlong)(int)puVar4 * (longlong)param_1[10]) >> 0x20) <<
                       0x10 | (uint)((longlong)(int)puVar4 * (longlong)param_1[10]) >> 0x10) +
                      ((int)((ulonglong)((longlong)(int)puVar5 * (longlong)param_1[4]) >> 0x20) <<
                       0x10 | (uint)((longlong)(int)puVar5 * (longlong)param_1[4]) >> 0x10);
        iVar6 = ((int)((ulonglong)((longlong)(int)puVar4 * (longlong)param_1[0xb]) >> 0x20) << 0x10
                | (uint)((longlong)(int)puVar4 * (longlong)param_1[0xb]) >> 0x10) +
                ((int)((ulonglong)((longlong)(int)puVar5 * (longlong)param_1[5]) >> 0x20) << 0x10 |
                (uint)((longlong)(int)puVar5 * (longlong)param_1[5]) >> 0x10) + 4;
        param_1[0xb] = iVar6;
        if (iVar7 < iVar6) {
          param_2[3] = 0;
        }
      }
    }
    else if (sVar3 == 0) {
      if (*param_2 != 0) {
        *param_1 = ((int)((ulonglong)((longlong)(int)puVar4 * (longlong)*param_1) >> 0x20) << 0x10 |
                   (uint)((longlong)(int)puVar4 * (longlong)*param_1) >> 0x10) +
                   ((int)((ulonglong)((longlong)(int)puVar5 * (longlong)param_1[6]) >> 0x20) << 0x10
                   | (uint)((longlong)(int)puVar5 * (longlong)param_1[6]) >> 0x10);
        param_1[1] = ((int)((ulonglong)((longlong)(int)puVar4 * (longlong)param_1[1]) >> 0x20) <<
                      0x10 | (uint)((longlong)(int)puVar4 * (longlong)param_1[1]) >> 0x10) +
                     ((int)((ulonglong)((longlong)(int)puVar5 * (longlong)param_1[7]) >> 0x20) <<
                      0x10 | (uint)((longlong)(int)puVar5 * (longlong)param_1[7]) >> 0x10);
        iVar6 = ((int)((ulonglong)((longlong)(int)puVar4 * (longlong)param_1[2]) >> 0x20) << 0x10 |
                (uint)((longlong)(int)puVar4 * (longlong)param_1[2]) >> 0x10) +
                ((int)((ulonglong)((longlong)(int)puVar5 * (longlong)param_1[8]) >> 0x20) << 0x10 |
                (uint)((longlong)(int)puVar5 * (longlong)param_1[8]) >> 0x10) + 4;
        param_1[2] = iVar6;
        if (iVar7 < iVar6) {
          *param_2 = 0;
        }
      }
      if (param_2[1] != 0) {
        param_1[3] = ((int)((ulonglong)((longlong)(int)puVar4 * (longlong)param_1[3]) >> 0x20) <<
                      0x10 | (uint)((longlong)(int)puVar4 * (longlong)param_1[3]) >> 0x10) +
                     ((int)((ulonglong)((longlong)(int)puVar5 * (longlong)param_1[6]) >> 0x20) <<
                      0x10 | (uint)((longlong)(int)puVar5 * (longlong)param_1[6]) >> 0x10);
        param_1[4] = ((int)((ulonglong)((longlong)(int)puVar4 * (longlong)param_1[4]) >> 0x20) <<
                      0x10 | (uint)((longlong)(int)puVar4 * (longlong)param_1[4]) >> 0x10) +
                     ((int)((ulonglong)((longlong)(int)puVar5 * (longlong)param_1[7]) >> 0x20) <<
                      0x10 | (uint)((longlong)(int)puVar5 * (longlong)param_1[7]) >> 0x10);
        iVar6 = ((int)((ulonglong)((longlong)(int)puVar4 * (longlong)param_1[5]) >> 0x20) << 0x10 |
                (uint)((longlong)(int)puVar4 * (longlong)param_1[5]) >> 0x10) +
                ((int)((ulonglong)((longlong)(int)puVar5 * (longlong)param_1[8]) >> 0x20) << 0x10 |
                (uint)((longlong)(int)puVar5 * (longlong)param_1[8]) >> 0x10) + 4;
        param_1[5] = iVar6;
        if (iVar7 < iVar6) {
          param_2[1] = 0;
        }
      }
      if (param_2[3] != 0) {
        param_1[9] = ((int)((ulonglong)((longlong)(int)puVar4 * (longlong)param_1[9]) >> 0x20) <<
                      0x10 | (uint)((longlong)(int)puVar4 * (longlong)param_1[9]) >> 0x10) +
                     ((int)((ulonglong)((longlong)(int)puVar5 * (longlong)param_1[6]) >> 0x20) <<
                      0x10 | (uint)((longlong)(int)puVar5 * (longlong)param_1[6]) >> 0x10);
        param_1[10] = ((int)((ulonglong)((longlong)(int)puVar4 * (longlong)param_1[10]) >> 0x20) <<
                       0x10 | (uint)((longlong)(int)puVar4 * (longlong)param_1[10]) >> 0x10) +
                      ((int)((ulonglong)((longlong)(int)puVar5 * (longlong)param_1[7]) >> 0x20) <<
                       0x10 | (uint)((longlong)(int)puVar5 * (longlong)param_1[7]) >> 0x10);
        iVar6 = ((int)((ulonglong)((longlong)(int)puVar4 * (longlong)param_1[0xb]) >> 0x20) << 0x10
                | (uint)((longlong)(int)puVar4 * (longlong)param_1[0xb]) >> 0x10) +
                ((int)((ulonglong)((longlong)(int)puVar5 * (longlong)param_1[8]) >> 0x20) << 0x10 |
                (uint)((longlong)(int)puVar5 * (longlong)param_1[8]) >> 0x10) + 4;
        param_1[0xb] = iVar6;
        if (iVar7 < iVar6) {
          param_2[3] = 0;
        }
      }
    }
    else {
      if (*param_2 != 0) {
        *param_1 = ((int)((ulonglong)((longlong)(int)puVar4 * (longlong)*param_1) >> 0x20) << 0x10 |
                   (uint)((longlong)(int)puVar4 * (longlong)*param_1) >> 0x10) +
                   ((int)((ulonglong)((longlong)(int)puVar5 * (longlong)param_1[9]) >> 0x20) << 0x10
                   | (uint)((longlong)(int)puVar5 * (longlong)param_1[9]) >> 0x10);
        param_1[1] = ((int)((ulonglong)((longlong)(int)puVar4 * (longlong)param_1[1]) >> 0x20) <<
                      0x10 | (uint)((longlong)(int)puVar4 * (longlong)param_1[1]) >> 0x10) +
                     ((int)((ulonglong)((longlong)(int)puVar5 * (longlong)param_1[10]) >> 0x20) <<
                      0x10 | (uint)((longlong)(int)puVar5 * (longlong)param_1[10]) >> 0x10);
        iVar6 = ((int)((ulonglong)((longlong)(int)puVar4 * (longlong)param_1[2]) >> 0x20) << 0x10 |
                (uint)((longlong)(int)puVar4 * (longlong)param_1[2]) >> 0x10) +
                ((int)((ulonglong)((longlong)(int)puVar5 * (longlong)param_1[0xb]) >> 0x20) << 0x10
                | (uint)((longlong)(int)puVar5 * (longlong)param_1[0xb]) >> 0x10) + 4;
        param_1[2] = iVar6;
        if (iVar7 < iVar6) {
          *param_2 = 0;
        }
      }
      if (param_2[1] != 0) {
        param_1[3] = ((int)((ulonglong)((longlong)(int)puVar4 * (longlong)param_1[3]) >> 0x20) <<
                      0x10 | (uint)((longlong)(int)puVar4 * (longlong)param_1[3]) >> 0x10) +
                     ((int)((ulonglong)((longlong)(int)puVar5 * (longlong)param_1[9]) >> 0x20) <<
                      0x10 | (uint)((longlong)(int)puVar5 * (longlong)param_1[9]) >> 0x10);
        param_1[4] = ((int)((ulonglong)((longlong)(int)puVar4 * (longlong)param_1[4]) >> 0x20) <<
                      0x10 | (uint)((longlong)(int)puVar4 * (longlong)param_1[4]) >> 0x10) +
                     ((int)((ulonglong)((longlong)(int)puVar5 * (longlong)param_1[10]) >> 0x20) <<
                      0x10 | (uint)((longlong)(int)puVar5 * (longlong)param_1[10]) >> 0x10);
        iVar6 = ((int)((ulonglong)((longlong)(int)puVar4 * (longlong)param_1[5]) >> 0x20) << 0x10 |
                (uint)((longlong)(int)puVar4 * (longlong)param_1[5]) >> 0x10) +
                ((int)((ulonglong)((longlong)(int)puVar5 * (longlong)param_1[0xb]) >> 0x20) << 0x10
                | (uint)((longlong)(int)puVar5 * (longlong)param_1[0xb]) >> 0x10) + 4;
        param_1[5] = iVar6;
        if (iVar7 < iVar6) {
          param_2[1] = 0;
        }
      }
      if (param_2[2] != 0) {
        param_1[6] = ((int)((ulonglong)((longlong)(int)puVar4 * (longlong)param_1[6]) >> 0x20) <<
                      0x10 | (uint)((longlong)(int)puVar4 * (longlong)param_1[6]) >> 0x10) +
                     ((int)((ulonglong)((longlong)(int)puVar5 * (longlong)param_1[9]) >> 0x20) <<
                      0x10 | (uint)((longlong)(int)puVar5 * (longlong)param_1[9]) >> 0x10);
        param_1[7] = ((int)((ulonglong)((longlong)(int)puVar4 * (longlong)param_1[7]) >> 0x20) <<
                      0x10 | (uint)((longlong)(int)puVar4 * (longlong)param_1[7]) >> 0x10) +
                     ((int)((ulonglong)((longlong)(int)puVar5 * (longlong)param_1[10]) >> 0x20) <<
                      0x10 | (uint)((longlong)(int)puVar5 * (longlong)param_1[10]) >> 0x10);
        iVar6 = ((int)((ulonglong)((longlong)(int)puVar4 * (longlong)param_1[8]) >> 0x20) << 0x10 |
                (uint)((longlong)(int)puVar4 * (longlong)param_1[8]) >> 0x10) +
                ((int)((ulonglong)((longlong)(int)puVar5 * (longlong)param_1[0xb]) >> 0x20) << 0x10
                | (uint)((longlong)(int)puVar5 * (longlong)param_1[0xb]) >> 0x10) + 4;
        param_1[8] = iVar6;
        if (iVar7 < iVar6) {
          param_2[2] = 0;
        }
      }
    }
  } while ((int)param_2[3] + (int)*param_2 + (int)param_2[1] + (int)param_2[2] != 0);
  return;
}

