/* FUN_06035A08  0x06035A08 */


undefined4 FUN_06035a08(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar5;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  undefined4 in_stack_00000034;
  uint *in_stack_00000038;
  
  uVar13 = param_1 ^ param_3;
  uVar10 = param_1 >> 0x14 & DAT_06035b20;
  uVar12 = param_3 >> 0x14 & DAT_06035b20;
  param_1 = param_1 & DAT_06035b24;
  param_3 = param_3 & DAT_06035b24;
  if (uVar10 == DAT_06035b20) {
    if ((param_1 == 0) && (param_2 == 0)) {
      if (uVar12 != DAT_06035b20) {
        if (((uVar12 == 0) && (param_3 == 0)) && (param_4 == 0)) {
          uVar6 = FUN_060359da();
          return uVar6;
        }
        goto code_r0x060359d2;
      }
      if ((param_3 == 0) && (param_4 == 0)) {
        uVar6 = FUN_060359d2();
        return uVar6;
      }
    }
code_r0x060359da:
    uVar13 = 0;
    uVar8 = 0;
    uVar12 = 8;
    uVar10 = DAT_06035b20;
  }
  else {
    if (uVar12 != DAT_06035b20) {
      if (uVar10 == 0) {
        if ((param_1 != 0) || (param_2 != 0)) {
          for (param_1 = param_1 << 1 | (uint)((param_2 & 0x80000000) != 0); param_2 = param_2 << 1,
              (int)param_1 < (int)PTR_DAT_06035b28;
              param_1 = param_1 << 1 | (uint)((param_2 & 0x80000000) != 0)) {
            uVar10 = uVar10 - 1;
          }
          goto LAB_06035a3a;
        }
      }
      else {
LAB_06035a3a:
        if (uVar12 == 0) {
          if ((param_3 == 0) && (param_4 == 0)) goto LAB_060359c8;
          for (param_3 = param_3 << 1 | (uint)((param_4 & 0x80000000) != 0); param_4 = param_4 << 1,
              (int)param_3 < (int)PTR_DAT_06035b28;
              param_3 = param_3 << 1 | (uint)((param_4 & 0x80000000) != 0)) {
            uVar12 = uVar12 - 1;
          }
        }
        uVar10 = (uVar10 + uVar12) - DAT_06035b30;
        if ((int)DAT_06035b20 <= (int)uVar10) goto code_r0x060359d2;
        if (-0x36 < (int)uVar10) {
          uVar5 = (uint)((ulonglong)param_4 * (ulonglong)param_2);
          lVar2 = (ulonglong)(param_3 | (uint)PTR_DAT_06035b28) *
                  (ulonglong)(param_1 | (uint)PTR_DAT_06035b28);
          uVar8 = (uint)lVar2;
          lVar3 = (ulonglong)param_4 * (ulonglong)(param_1 | (uint)PTR_DAT_06035b28);
          uVar9 = (uint)lVar3;
          lVar4 = (ulonglong)(param_3 | (uint)PTR_DAT_06035b28) * (ulonglong)param_2;
          uVar14 = (uint)((ulonglong)lVar4 >> 0x20);
          uVar1 = (uint)lVar4;
          uVar7 = uVar9 + (int)((ulonglong)param_4 * (ulonglong)param_2 >> 0x20);
          uVar12 = uVar14 + (int)((ulonglong)lVar3 >> 0x20);
          uVar9 = uVar12 + (uVar7 < uVar9);
          uVar7 = uVar1 + uVar7;
          uVar12 = uVar7 + (uVar12 < uVar14 || uVar9 < uVar12);
          uVar9 = uVar8 + uVar9;
          uVar7 = uVar9 + (uVar7 < uVar1 || uVar12 < uVar7);
          if (uVar5 != 0) {
            uVar12 = uVar12 | 1;
          }
          uVar1 = uVar12 >> 0x10;
          uVar14 = uVar7 >> 0x10;
          uVar9 = ((int)((ulonglong)lVar2 >> 0x20) + (uint)(uVar9 < uVar8 || uVar7 < uVar9)) *
                  0x10000 | uVar14;
          uVar8 = uVar9 >> 1;
          uVar7 = (uVar7 * 0x10000 | uVar1) >> 1 | (uint)((uVar14 & 1) == 1) * -0x80000000;
          uVar12 = (uVar12 << 0x10 | uVar5 >> 0x10) >> 1 | (uint)((uVar1 & 1) != 0) * -0x80000000;
          if ((uVar8 & (uint)PTR_DAT_06035b2c) != 0) {
            uVar8 = uVar9 >> 2;
            uVar7 = uVar7 >> 1 | (uint)((uVar14 & 2) == 2) * -0x80000000;
            uVar12 = uVar12 >> 1 | (uint)((uVar1 & 2) != 0) * -0x80000000;
            uVar10 = uVar10 + 1;
            if (uVar10 == DAT_06035b20) {
              uVar6 = FUN_060359d2();
              return uVar6;
            }
          }
          if (uVar12 != 0) {
            uVar7 = uVar7 | 1;
          }
          if ((int)uVar10 < 1) {
            iVar11 = 1 - uVar10;
            do {
              uVar10 = uVar8 & 1;
              uVar8 = uVar8 >> 1;
              iVar11 = iVar11 + -1;
              uVar7 = uVar7 >> 1 | (uint)(uVar10 == 1) * -0x80000000 | (uint)((uVar7 & 1) != 0);
              uVar10 = 0;
            } while (iVar11 != 0);
          }
          uVar12 = uVar7;
          if (((uVar7 & 4) != 0) && ((uVar7 & 0xb) != 0)) {
            uVar12 = uVar7 + 8;
            uVar8 = uVar8 + (uVar12 < uVar7);
            if ((int)PTR_DAT_06035b2c <= (int)uVar8) {
              uVar7 = uVar8 & 1;
              uVar8 = uVar8 >> 1;
              uVar12 = uVar12 >> 1 | (uint)(uVar7 == 1) * -0x80000000;
              uVar10 = uVar10 + 1;
            }
          }
          goto LAB_06035ad6;
        }
      }
LAB_060359c8:
      uVar12 = 0;
      uVar10 = (uint)((uVar13 & 0x80000000) != 0) << 0x1f;
      goto LAB_06035af4;
    }
    if ((param_3 != 0) || (param_4 != 0)) goto code_r0x060359da;
    if (((uVar10 == 0) && (param_1 == 0)) && (param_2 == 0)) {
      uVar6 = FUN_060359da();
      return uVar6;
    }
code_r0x060359d2:
    uVar8 = 0;
    uVar12 = 0;
    uVar10 = DAT_06035b20;
  }
LAB_06035ad6:
  uVar12 = ((uVar12 >> 1 | (uint)((uVar8 & 1) == 1) * -0x80000000) >> 1 |
           (uint)((uVar8 >> 1 & 1) == 1) * -0x80000000) >> 1 |
           (uint)((uVar8 >> 2 & 1) == 1) * -0x80000000;
  uVar10 = uVar8 >> 3 & DAT_06035b24 | (uVar10 & 0x7ff) << 0x14 |
           (uint)((uVar13 & 0x80000000) != 0) * -0x80000000;
LAB_06035af4:
  *in_stack_00000038 = uVar10;
  in_stack_00000038[1] = uVar12;
  return in_stack_00000034;
}

