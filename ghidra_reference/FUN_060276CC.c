/* FUN_060276CC  0x060276CC */


int FUN_060276cc(int *param_1,short *param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  puVar2 = PTR_DAT_06027740;
  puVar1 = PTR_DAT_0602773c;
  iVar5 = *(int *)PTR_DAT_06027744;
  if (*param_2 == 1) {
    iVar3 = 1;
    if (param_1[5] < param_1[0xb]) {
      do {
        *param_1 = ((int)((ulonglong)((longlong)(int)puVar2 * (longlong)param_1[9]) >> 0x20) << 0x10
                   | (uint)((longlong)(int)puVar2 * (longlong)param_1[9]) >> 0x10) +
                   ((int)((ulonglong)((longlong)(int)puVar1 * (longlong)*param_1) >> 0x20) << 0x10 |
                   (uint)((longlong)(int)puVar1 * (longlong)*param_1) >> 0x10);
        param_1[1] = ((int)((ulonglong)((longlong)(int)puVar2 * (longlong)param_1[10]) >> 0x20) <<
                      0x10 | (uint)((longlong)(int)puVar2 * (longlong)param_1[10]) >> 0x10) +
                     ((int)((ulonglong)((longlong)(int)puVar1 * (longlong)param_1[1]) >> 0x20) <<
                      0x10 | (uint)((longlong)(int)puVar1 * (longlong)param_1[1]) >> 0x10);
        iVar4 = ((int)((ulonglong)((longlong)(int)puVar2 * (longlong)param_1[0xb]) >> 0x20) << 0x10
                | (uint)((longlong)(int)puVar2 * (longlong)param_1[0xb]) >> 0x10) +
                ((int)((ulonglong)((longlong)(int)puVar1 * (longlong)param_1[2]) >> 0x20) << 0x10 |
                (uint)((longlong)(int)puVar1 * (longlong)param_1[2]) >> 0x10) + 4;
        param_1[2] = iVar4;
      } while (iVar4 < iVar5);
    }
    else {
      do {
        *param_1 = ((int)((ulonglong)((longlong)(int)puVar2 * (longlong)param_1[3]) >> 0x20) << 0x10
                   | (uint)((longlong)(int)puVar2 * (longlong)param_1[3]) >> 0x10) +
                   ((int)((ulonglong)((longlong)(int)puVar1 * (longlong)*param_1) >> 0x20) << 0x10 |
                   (uint)((longlong)(int)puVar1 * (longlong)*param_1) >> 0x10);
        param_1[1] = ((int)((ulonglong)((longlong)(int)puVar2 * (longlong)param_1[4]) >> 0x20) <<
                      0x10 | (uint)((longlong)(int)puVar2 * (longlong)param_1[4]) >> 0x10) +
                     ((int)((ulonglong)((longlong)(int)puVar1 * (longlong)param_1[1]) >> 0x20) <<
                      0x10 | (uint)((longlong)(int)puVar1 * (longlong)param_1[1]) >> 0x10);
        iVar4 = ((int)((ulonglong)((longlong)(int)puVar2 * (longlong)param_1[5]) >> 0x20) << 0x10 |
                (uint)((longlong)(int)puVar2 * (longlong)param_1[5]) >> 0x10) +
                ((int)((ulonglong)((longlong)(int)puVar1 * (longlong)param_1[2]) >> 0x20) << 0x10 |
                (uint)((longlong)(int)puVar1 * (longlong)param_1[2]) >> 0x10) + 4;
        param_1[2] = iVar4;
      } while (iVar4 < iVar5);
    }
  }
  else if (param_2[1] == 1) {
    iVar3 = 1;
    if (param_1[8] < param_1[2]) {
      do {
        param_1[3] = ((int)((ulonglong)((longlong)(int)puVar2 * (longlong)*param_1) >> 0x20) << 0x10
                     | (uint)((longlong)(int)puVar2 * (longlong)*param_1) >> 0x10) +
                     ((int)((ulonglong)((longlong)(int)puVar1 * (longlong)param_1[3]) >> 0x20) <<
                      0x10 | (uint)((longlong)(int)puVar1 * (longlong)param_1[3]) >> 0x10);
        param_1[4] = ((int)((ulonglong)((longlong)(int)puVar2 * (longlong)param_1[1]) >> 0x20) <<
                      0x10 | (uint)((longlong)(int)puVar2 * (longlong)param_1[1]) >> 0x10) +
                     ((int)((ulonglong)((longlong)(int)puVar1 * (longlong)param_1[4]) >> 0x20) <<
                      0x10 | (uint)((longlong)(int)puVar1 * (longlong)param_1[4]) >> 0x10);
        iVar4 = ((int)((ulonglong)((longlong)(int)puVar2 * (longlong)param_1[2]) >> 0x20) << 0x10 |
                (uint)((longlong)(int)puVar2 * (longlong)param_1[2]) >> 0x10) +
                ((int)((ulonglong)((longlong)(int)puVar1 * (longlong)param_1[5]) >> 0x20) << 0x10 |
                (uint)((longlong)(int)puVar1 * (longlong)param_1[5]) >> 0x10) + 4;
        param_1[5] = iVar4;
      } while (iVar4 < iVar5);
    }
    else {
      do {
        param_1[3] = ((int)((ulonglong)((longlong)(int)puVar2 * (longlong)param_1[6]) >> 0x20) <<
                      0x10 | (uint)((longlong)(int)puVar2 * (longlong)param_1[6]) >> 0x10) +
                     ((int)((ulonglong)((longlong)(int)puVar1 * (longlong)param_1[3]) >> 0x20) <<
                      0x10 | (uint)((longlong)(int)puVar1 * (longlong)param_1[3]) >> 0x10);
        param_1[4] = ((int)((ulonglong)((longlong)(int)puVar2 * (longlong)param_1[7]) >> 0x20) <<
                      0x10 | (uint)((longlong)(int)puVar2 * (longlong)param_1[7]) >> 0x10) +
                     ((int)((ulonglong)((longlong)(int)puVar1 * (longlong)param_1[4]) >> 0x20) <<
                      0x10 | (uint)((longlong)(int)puVar1 * (longlong)param_1[4]) >> 0x10);
        iVar4 = ((int)((ulonglong)((longlong)(int)puVar2 * (longlong)param_1[8]) >> 0x20) << 0x10 |
                (uint)((longlong)(int)puVar2 * (longlong)param_1[8]) >> 0x10) +
                ((int)((ulonglong)((longlong)(int)puVar1 * (longlong)param_1[5]) >> 0x20) << 0x10 |
                (uint)((longlong)(int)puVar1 * (longlong)param_1[5]) >> 0x10) + 4;
        param_1[5] = iVar4;
      } while (iVar4 < iVar5);
    }
  }
  else {
    iVar3 = (int)param_2[2];
    if (iVar3 == 1) {
      if (param_1[0xb] < param_1[5]) {
        do {
          param_1[6] = ((int)((ulonglong)((longlong)(int)puVar2 * (longlong)param_1[3]) >> 0x20) <<
                        0x10 | (uint)((longlong)(int)puVar2 * (longlong)param_1[3]) >> 0x10) +
                       ((int)((ulonglong)((longlong)(int)puVar1 * (longlong)param_1[6]) >> 0x20) <<
                        0x10 | (uint)((longlong)(int)puVar1 * (longlong)param_1[6]) >> 0x10);
          param_1[7] = ((int)((ulonglong)((longlong)(int)puVar2 * (longlong)param_1[4]) >> 0x20) <<
                        0x10 | (uint)((longlong)(int)puVar2 * (longlong)param_1[4]) >> 0x10) +
                       ((int)((ulonglong)((longlong)(int)puVar1 * (longlong)param_1[7]) >> 0x20) <<
                        0x10 | (uint)((longlong)(int)puVar1 * (longlong)param_1[7]) >> 0x10);
          iVar4 = ((int)((ulonglong)((longlong)(int)puVar2 * (longlong)param_1[5]) >> 0x20) << 0x10
                  | (uint)((longlong)(int)puVar2 * (longlong)param_1[5]) >> 0x10) +
                  ((int)((ulonglong)((longlong)(int)puVar1 * (longlong)param_1[8]) >> 0x20) << 0x10
                  | (uint)((longlong)(int)puVar1 * (longlong)param_1[8]) >> 0x10) + 4;
          param_1[8] = iVar4;
        } while (iVar4 < iVar5);
      }
      else {
        do {
          param_1[6] = ((int)((ulonglong)((longlong)(int)puVar2 * (longlong)param_1[9]) >> 0x20) <<
                        0x10 | (uint)((longlong)(int)puVar2 * (longlong)param_1[9]) >> 0x10) +
                       ((int)((ulonglong)((longlong)(int)puVar1 * (longlong)param_1[6]) >> 0x20) <<
                        0x10 | (uint)((longlong)(int)puVar1 * (longlong)param_1[6]) >> 0x10);
          param_1[7] = ((int)((ulonglong)((longlong)(int)puVar2 * (longlong)param_1[10]) >> 0x20) <<
                        0x10 | (uint)((longlong)(int)puVar2 * (longlong)param_1[10]) >> 0x10) +
                       ((int)((ulonglong)((longlong)(int)puVar1 * (longlong)param_1[7]) >> 0x20) <<
                        0x10 | (uint)((longlong)(int)puVar1 * (longlong)param_1[7]) >> 0x10);
          iVar4 = ((int)((ulonglong)((longlong)(int)puVar2 * (longlong)param_1[0xb]) >> 0x20) <<
                   0x10 | (uint)((longlong)(int)puVar2 * (longlong)param_1[0xb]) >> 0x10) +
                  ((int)((ulonglong)((longlong)(int)puVar1 * (longlong)param_1[8]) >> 0x20) << 0x10
                  | (uint)((longlong)(int)puVar1 * (longlong)param_1[8]) >> 0x10) + 4;
          param_1[8] = iVar4;
        } while (iVar4 < iVar5);
      }
    }
    else if (param_1[2] < param_1[8]) {
      do {
        param_1[9] = ((int)((ulonglong)((longlong)(int)puVar2 * (longlong)param_1[6]) >> 0x20) <<
                      0x10 | (uint)((longlong)(int)puVar2 * (longlong)param_1[6]) >> 0x10) +
                     ((int)((ulonglong)((longlong)(int)puVar1 * (longlong)param_1[9]) >> 0x20) <<
                      0x10 | (uint)((longlong)(int)puVar1 * (longlong)param_1[9]) >> 0x10);
        param_1[10] = ((int)((ulonglong)((longlong)(int)puVar2 * (longlong)param_1[7]) >> 0x20) <<
                       0x10 | (uint)((longlong)(int)puVar2 * (longlong)param_1[7]) >> 0x10) +
                      ((int)((ulonglong)((longlong)(int)puVar1 * (longlong)param_1[10]) >> 0x20) <<
                       0x10 | (uint)((longlong)(int)puVar1 * (longlong)param_1[10]) >> 0x10);
        iVar4 = ((int)((ulonglong)((longlong)(int)puVar2 * (longlong)param_1[8]) >> 0x20) << 0x10 |
                (uint)((longlong)(int)puVar2 * (longlong)param_1[8]) >> 0x10) +
                ((int)((ulonglong)((longlong)(int)puVar1 * (longlong)param_1[0xb]) >> 0x20) << 0x10
                | (uint)((longlong)(int)puVar1 * (longlong)param_1[0xb]) >> 0x10) + 4;
        param_1[0xb] = iVar4;
      } while (iVar4 < iVar5);
    }
    else {
      do {
        param_1[9] = ((int)((ulonglong)((longlong)(int)puVar2 * (longlong)*param_1) >> 0x20) << 0x10
                     | (uint)((longlong)(int)puVar2 * (longlong)*param_1) >> 0x10) +
                     ((int)((ulonglong)((longlong)(int)puVar1 * (longlong)param_1[9]) >> 0x20) <<
                      0x10 | (uint)((longlong)(int)puVar1 * (longlong)param_1[9]) >> 0x10);
        param_1[10] = ((int)((ulonglong)((longlong)(int)puVar2 * (longlong)param_1[1]) >> 0x20) <<
                       0x10 | (uint)((longlong)(int)puVar2 * (longlong)param_1[1]) >> 0x10) +
                      ((int)((ulonglong)((longlong)(int)puVar1 * (longlong)param_1[10]) >> 0x20) <<
                       0x10 | (uint)((longlong)(int)puVar1 * (longlong)param_1[10]) >> 0x10);
        iVar4 = ((int)((ulonglong)((longlong)(int)puVar2 * (longlong)param_1[2]) >> 0x20) << 0x10 |
                (uint)((longlong)(int)puVar2 * (longlong)param_1[2]) >> 0x10) +
                ((int)((ulonglong)((longlong)(int)puVar1 * (longlong)param_1[0xb]) >> 0x20) << 0x10
                | (uint)((longlong)(int)puVar1 * (longlong)param_1[0xb]) >> 0x10) + 4;
        param_1[0xb] = iVar4;
      } while (iVar4 < iVar5);
    }
  }
  return iVar3;
}

