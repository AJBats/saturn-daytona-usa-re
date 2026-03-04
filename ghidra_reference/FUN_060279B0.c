/* FUN_060279B0  0x060279B0 */


void FUN_060279b0(int *param_1,short *param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  short local_20;
  short sStack_1e;
  short sStack_1c;
  short sStack_1a;
  
  puVar2 = PTR_DAT_06027a30;
  puVar1 = PTR_DAT_06027a2c;
  iVar4 = *(int *)PTR_DAT_06027a34;
  local_20 = *param_2;
  sStack_1e = param_2[1];
  sStack_1c = param_2[2];
  sStack_1a = param_2[3];
  do {
    if (local_20 == 1) {
      if (param_2[1] == 0) {
        *param_1 = ((int)((ulonglong)((longlong)(int)puVar2 * (longlong)param_1[3]) >> 0x20) << 0x10
                   | (uint)((longlong)(int)puVar2 * (longlong)param_1[3]) >> 0x10) +
                   ((int)((ulonglong)((longlong)(int)puVar1 * (longlong)*param_1) >> 0x20) << 0x10 |
                   (uint)((longlong)(int)puVar1 * (longlong)*param_1) >> 0x10);
        param_1[1] = ((int)((ulonglong)((longlong)(int)puVar2 * (longlong)param_1[4]) >> 0x20) <<
                      0x10 | (uint)((longlong)(int)puVar2 * (longlong)param_1[4]) >> 0x10) +
                     ((int)((ulonglong)((longlong)(int)puVar1 * (longlong)param_1[1]) >> 0x20) <<
                      0x10 | (uint)((longlong)(int)puVar1 * (longlong)param_1[1]) >> 0x10);
        iVar3 = ((int)((ulonglong)((longlong)(int)puVar2 * (longlong)param_1[5]) >> 0x20) << 0x10 |
                (uint)((longlong)(int)puVar2 * (longlong)param_1[5]) >> 0x10) +
                ((int)((ulonglong)((longlong)(int)puVar1 * (longlong)param_1[2]) >> 0x20) << 0x10 |
                (uint)((longlong)(int)puVar1 * (longlong)param_1[2]) >> 0x10);
      }
      else {
        *param_1 = ((int)((ulonglong)((longlong)(int)puVar2 * (longlong)param_1[9]) >> 0x20) << 0x10
                   | (uint)((longlong)(int)puVar2 * (longlong)param_1[9]) >> 0x10) +
                   ((int)((ulonglong)((longlong)(int)puVar1 * (longlong)*param_1) >> 0x20) << 0x10 |
                   (uint)((longlong)(int)puVar1 * (longlong)*param_1) >> 0x10);
        param_1[1] = ((int)((ulonglong)((longlong)(int)puVar2 * (longlong)param_1[10]) >> 0x20) <<
                      0x10 | (uint)((longlong)(int)puVar2 * (longlong)param_1[10]) >> 0x10) +
                     ((int)((ulonglong)((longlong)(int)puVar1 * (longlong)param_1[1]) >> 0x20) <<
                      0x10 | (uint)((longlong)(int)puVar1 * (longlong)param_1[1]) >> 0x10);
        iVar3 = ((int)((ulonglong)((longlong)(int)puVar2 * (longlong)param_1[0xb]) >> 0x20) << 0x10
                | (uint)((longlong)(int)puVar2 * (longlong)param_1[0xb]) >> 0x10) +
                ((int)((ulonglong)((longlong)(int)puVar1 * (longlong)param_1[2]) >> 0x20) << 0x10 |
                (uint)((longlong)(int)puVar1 * (longlong)param_1[2]) >> 0x10);
      }
      param_1[2] = iVar3 + 4;
      if (iVar4 < iVar3 + 4) {
        local_20 = 0;
      }
    }
    if (sStack_1e == 1) {
      if (param_2[2] == 0) {
        param_1[3] = ((int)((ulonglong)((longlong)(int)puVar2 * (longlong)param_1[6]) >> 0x20) <<
                      0x10 | (uint)((longlong)(int)puVar2 * (longlong)param_1[6]) >> 0x10) +
                     ((int)((ulonglong)((longlong)(int)puVar1 * (longlong)param_1[3]) >> 0x20) <<
                      0x10 | (uint)((longlong)(int)puVar1 * (longlong)param_1[3]) >> 0x10);
        param_1[4] = ((int)((ulonglong)((longlong)(int)puVar2 * (longlong)param_1[7]) >> 0x20) <<
                      0x10 | (uint)((longlong)(int)puVar2 * (longlong)param_1[7]) >> 0x10) +
                     ((int)((ulonglong)((longlong)(int)puVar1 * (longlong)param_1[4]) >> 0x20) <<
                      0x10 | (uint)((longlong)(int)puVar1 * (longlong)param_1[4]) >> 0x10);
        iVar3 = ((int)((ulonglong)((longlong)(int)puVar2 * (longlong)param_1[8]) >> 0x20) << 0x10 |
                (uint)((longlong)(int)puVar2 * (longlong)param_1[8]) >> 0x10) +
                ((int)((ulonglong)((longlong)(int)puVar1 * (longlong)param_1[5]) >> 0x20) << 0x10 |
                (uint)((longlong)(int)puVar1 * (longlong)param_1[5]) >> 0x10);
      }
      else {
        param_1[3] = ((int)((ulonglong)((longlong)(int)puVar2 * (longlong)*param_1) >> 0x20) << 0x10
                     | (uint)((longlong)(int)puVar2 * (longlong)*param_1) >> 0x10) +
                     ((int)((ulonglong)((longlong)(int)puVar1 * (longlong)param_1[3]) >> 0x20) <<
                      0x10 | (uint)((longlong)(int)puVar1 * (longlong)param_1[3]) >> 0x10);
        param_1[4] = ((int)((ulonglong)((longlong)(int)puVar2 * (longlong)param_1[1]) >> 0x20) <<
                      0x10 | (uint)((longlong)(int)puVar2 * (longlong)param_1[1]) >> 0x10) +
                     ((int)((ulonglong)((longlong)(int)puVar1 * (longlong)param_1[4]) >> 0x20) <<
                      0x10 | (uint)((longlong)(int)puVar1 * (longlong)param_1[4]) >> 0x10);
        iVar3 = ((int)((ulonglong)((longlong)(int)puVar2 * (longlong)param_1[2]) >> 0x20) << 0x10 |
                (uint)((longlong)(int)puVar2 * (longlong)param_1[2]) >> 0x10) +
                ((int)((ulonglong)((longlong)(int)puVar1 * (longlong)param_1[5]) >> 0x20) << 0x10 |
                (uint)((longlong)(int)puVar1 * (longlong)param_1[5]) >> 0x10);
      }
      param_1[5] = iVar3 + 4;
      if (iVar4 < iVar3 + 4) {
        sStack_1e = 0;
      }
    }
    if (sStack_1c == 1) {
      if (param_2[3] == 0) {
        param_1[6] = ((int)((ulonglong)((longlong)(int)puVar2 * (longlong)param_1[9]) >> 0x20) <<
                      0x10 | (uint)((longlong)(int)puVar2 * (longlong)param_1[9]) >> 0x10) +
                     ((int)((ulonglong)((longlong)(int)puVar1 * (longlong)param_1[6]) >> 0x20) <<
                      0x10 | (uint)((longlong)(int)puVar1 * (longlong)param_1[6]) >> 0x10);
        param_1[7] = ((int)((ulonglong)((longlong)(int)puVar2 * (longlong)param_1[10]) >> 0x20) <<
                      0x10 | (uint)((longlong)(int)puVar2 * (longlong)param_1[10]) >> 0x10) +
                     ((int)((ulonglong)((longlong)(int)puVar1 * (longlong)param_1[7]) >> 0x20) <<
                      0x10 | (uint)((longlong)(int)puVar1 * (longlong)param_1[7]) >> 0x10);
        iVar3 = ((int)((ulonglong)((longlong)(int)puVar2 * (longlong)param_1[0xb]) >> 0x20) << 0x10
                | (uint)((longlong)(int)puVar2 * (longlong)param_1[0xb]) >> 0x10) +
                ((int)((ulonglong)((longlong)(int)puVar1 * (longlong)param_1[8]) >> 0x20) << 0x10 |
                (uint)((longlong)(int)puVar1 * (longlong)param_1[8]) >> 0x10);
      }
      else {
        param_1[6] = ((int)((ulonglong)((longlong)(int)puVar2 * (longlong)param_1[3]) >> 0x20) <<
                      0x10 | (uint)((longlong)(int)puVar2 * (longlong)param_1[3]) >> 0x10) +
                     ((int)((ulonglong)((longlong)(int)puVar1 * (longlong)param_1[6]) >> 0x20) <<
                      0x10 | (uint)((longlong)(int)puVar1 * (longlong)param_1[6]) >> 0x10);
        param_1[7] = ((int)((ulonglong)((longlong)(int)puVar2 * (longlong)param_1[4]) >> 0x20) <<
                      0x10 | (uint)((longlong)(int)puVar2 * (longlong)param_1[4]) >> 0x10) +
                     ((int)((ulonglong)((longlong)(int)puVar1 * (longlong)param_1[7]) >> 0x20) <<
                      0x10 | (uint)((longlong)(int)puVar1 * (longlong)param_1[7]) >> 0x10);
        iVar3 = ((int)((ulonglong)((longlong)(int)puVar2 * (longlong)param_1[5]) >> 0x20) << 0x10 |
                (uint)((longlong)(int)puVar2 * (longlong)param_1[5]) >> 0x10) +
                ((int)((ulonglong)((longlong)(int)puVar1 * (longlong)param_1[8]) >> 0x20) << 0x10 |
                (uint)((longlong)(int)puVar1 * (longlong)param_1[8]) >> 0x10);
      }
      param_1[8] = iVar3 + 4;
      if (iVar4 < iVar3 + 4) {
        sStack_1c = 0;
      }
    }
    if (sStack_1a == 1) {
      if (*param_2 == 0) {
        param_1[9] = ((int)((ulonglong)((longlong)(int)puVar2 * (longlong)*param_1) >> 0x20) << 0x10
                     | (uint)((longlong)(int)puVar2 * (longlong)*param_1) >> 0x10) +
                     ((int)((ulonglong)((longlong)(int)puVar1 * (longlong)param_1[9]) >> 0x20) <<
                      0x10 | (uint)((longlong)(int)puVar1 * (longlong)param_1[9]) >> 0x10);
        param_1[10] = ((int)((ulonglong)((longlong)(int)puVar2 * (longlong)param_1[1]) >> 0x20) <<
                       0x10 | (uint)((longlong)(int)puVar2 * (longlong)param_1[1]) >> 0x10) +
                      ((int)((ulonglong)((longlong)(int)puVar1 * (longlong)param_1[10]) >> 0x20) <<
                       0x10 | (uint)((longlong)(int)puVar1 * (longlong)param_1[10]) >> 0x10);
        iVar3 = ((int)((ulonglong)((longlong)(int)puVar2 * (longlong)param_1[2]) >> 0x20) << 0x10 |
                (uint)((longlong)(int)puVar2 * (longlong)param_1[2]) >> 0x10) +
                ((int)((ulonglong)((longlong)(int)puVar1 * (longlong)param_1[0xb]) >> 0x20) << 0x10
                | (uint)((longlong)(int)puVar1 * (longlong)param_1[0xb]) >> 0x10);
      }
      else {
        param_1[9] = ((int)((ulonglong)((longlong)(int)puVar2 * (longlong)param_1[6]) >> 0x20) <<
                      0x10 | (uint)((longlong)(int)puVar2 * (longlong)param_1[6]) >> 0x10) +
                     ((int)((ulonglong)((longlong)(int)puVar1 * (longlong)param_1[9]) >> 0x20) <<
                      0x10 | (uint)((longlong)(int)puVar1 * (longlong)param_1[9]) >> 0x10);
        param_1[10] = ((int)((ulonglong)((longlong)(int)puVar2 * (longlong)param_1[7]) >> 0x20) <<
                       0x10 | (uint)((longlong)(int)puVar2 * (longlong)param_1[7]) >> 0x10) +
                      ((int)((ulonglong)((longlong)(int)puVar1 * (longlong)param_1[10]) >> 0x20) <<
                       0x10 | (uint)((longlong)(int)puVar1 * (longlong)param_1[10]) >> 0x10);
        iVar3 = ((int)((ulonglong)((longlong)(int)puVar2 * (longlong)param_1[8]) >> 0x20) << 0x10 |
                (uint)((longlong)(int)puVar2 * (longlong)param_1[8]) >> 0x10) +
                ((int)((ulonglong)((longlong)(int)puVar1 * (longlong)param_1[0xb]) >> 0x20) << 0x10
                | (uint)((longlong)(int)puVar1 * (longlong)param_1[0xb]) >> 0x10);
      }
      param_1[0xb] = iVar3 + 4;
      if (iVar4 < iVar3 + 4) {
        sStack_1a = 0;
      }
    }
  } while ((int)sStack_1a + (int)local_20 + (int)sStack_1e + (int)sStack_1c != 0);
  return;
}

