/* FUN_0603E5BC  0x0603E5BC */


short * FUN_0603e5bc(undefined4 param_1)

{
  short sVar1;
  short sVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  short *psVar7;
  ushort uVar10;
  int iVar8;
  undefined4 uVar9;
  short sVar11;
  short sVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  int *piVar16;
  int *piVar17;
  undefined4 *puVar18;
  uint uVar19;
  int iVar20;
  ushort uVar21;
  char cVar22;
  int iVar23;
  int iVar24;
  undefined1 *local_6c;
  int *piStack_68;
  uint *puStack_64;
  int local_60;
  int *local_5c;
  int local_58;
  int *piStack_54;
  int iStack_50;
  int iStack_4c;
  int iStack_48;
  int *piStack_44;
  int *piStack_40;
  int *piStack_3c;
  int *piStack_38;
  int iStack_34;
  int iStack_30;
  int iStack_2c;
  int iStack_28;
  
  puVar5 = PTR_DAT_0603e630;
  puVar4 = PTR_FUN_0603e62c;
  puVar3 = PTR_DAT_0603e628;
  sVar11 = DAT_0603e61e;
  uVar15 = (uint)DAT_0603e61e;
  sVar12 = DAT_0603e61e + 1;
  psVar7 = *(short **)PTR_DAT_0603e634;
  if (psVar7 == (short *)&UNK_00000001) {
    uVar21 = 0;
    *(ushort *)(PTR_DAT_0603e630 + 4) = *(ushort *)(PTR_DAT_0603e630 + 4) & (ushort)PTR_DAT_0603e638
    ;
    uVar10 = *(ushort *)(puVar5 + 4) | 3;
  }
  else {
    if (psVar7 != (short *)&UNK_00000002) {
      return psVar7;
    }
    uVar21 = 1;
    *(ushort *)(PTR_DAT_0603e630 + 4) = *(ushort *)(PTR_DAT_0603e630 + 4) & 0xff;
    uVar10 = *(ushort *)(puVar5 + 4) | PTR_DAT_0603e620._0_2_;
  }
  *(ushort *)(puVar5 + 4) = uVar10;
  iStack_50 = param_1;
  local_58 = FUN_0603d9ec(param_1);
  iStack_50 = FUN_0603da88(iStack_50);
  puVar5 = PTR_FUN_0603e720;
  cVar22 = (char)uVar21;
  piVar16 = (int *)(PTR_DAT_0603e71c + (char)(cVar22 * '$'));
  iStack_30 = *piVar16;
  piStack_40 = piVar16 + 2;
  iStack_48 = *piStack_40;
  piStack_38 = piVar16 + 3;
  iStack_4c = *piStack_38;
  piStack_3c = piVar16 + 5;
  iStack_2c = *piStack_3c;
  piStack_44 = piVar16 + 6;
  iStack_28 = *piStack_44;
  piStack_54 = piVar16 + 8;
  iStack_34 = *piStack_54;
  local_5c = (int *)(*(code *)PTR_FUN_0603e720)(iStack_30,iStack_50);
  iVar8 = (*(code *)puVar5)(iStack_48,local_58);
  *piVar16 = (int)local_5c - iVar8;
  local_5c = piStack_40;
  local_60 = (*(code *)puVar5)(iStack_30,local_58);
  iVar8 = (*(code *)puVar5)(iStack_48,iStack_50);
  *local_5c = iVar8 + local_60;
  local_5c = piStack_38;
  local_60 = (*(code *)puVar5)(iStack_4c,iStack_50);
  iVar8 = (*(code *)puVar5)(iStack_2c,local_58);
  *local_5c = local_60 - iVar8;
  local_5c = piStack_3c;
  local_60 = (*(code *)puVar5)(iStack_4c,local_58);
  iVar8 = (*(code *)puVar5)(iStack_2c,iStack_50);
  *local_5c = iVar8 + local_60;
  local_5c = piStack_44;
  local_60 = (*(code *)puVar5)(iStack_28,iStack_50);
  iVar8 = (*(code *)puVar5)(iStack_34,local_58);
  *local_5c = local_60 - iVar8;
  local_5c = piStack_54;
  local_60 = (*(code *)puVar5)(iStack_28,local_58);
  iVar8 = (*(code *)puVar5)(iStack_34,iStack_50);
  *local_5c = iVar8 + local_60;
  puVar5 = PTR_DAT_0603e838;
  *(int *)(PTR_DAT_0603e838 + (uint)uVar21 * 0x80 + 0x1c) = *piVar16;
  *(int *)(puVar5 + (uint)uVar21 * 0x80 + 0x24) = *piStack_40;
  *(int *)(puVar5 + (uint)uVar21 * 0x80 + 0x28) = *piStack_38;
  *(int *)(puVar5 + (uint)uVar21 * 0x80 + 0x2c) = piVar16[4];
  *(int *)(puVar5 + (uint)uVar21 * 0x80 + 0x30) = *piStack_3c;
  sVar1 = *(short *)(puVar5 + (uint)uVar21 * 0x80 + 0x34);
  sVar2 = *(short *)(puVar5 + (uint)uVar21 * 0x80 + 0x3c);
  iVar20 = *piStack_44;
  local_58 = piVar16[7];
  iStack_50 = (int)*(short *)(puVar5 + (uint)uVar21 * 0x80 + 0x36);
  iVar23 = local_58 * (iStack_50 - *(short *)(puVar5 + (uint)uVar21 * 0x80 + 0x3e));
  iVar13 = *piStack_54;
  iVar14 = (int)*(short *)(puVar5 + (uint)uVar21 * 0x80 + 0x38);
  iStack_4c = CONCAT22(*(short *)(puVar5 + (uint)uVar21 * 0x80 + 0x40),iStack_4c._2_2_);
  iVar24 = iVar13 * (iVar14 - *(short *)(puVar5 + (uint)uVar21 * 0x80 + 0x40));
  local_6c = (undefined1 *)&local_6c;
  (*(code *)PTR_FUN_0603e83c)();
  (*(code *)PTR_FUN_0603e844)();
  iVar8 = (*(code *)PTR_FUN_0603e848)();
  puVar5 = PTR_DAT_0603ea50;
  iVar8 = iVar20 * ((int)sVar1 - (int)sVar2) + iVar23 + iVar24 + iVar8 +
          *(int *)(PTR_DAT_0603e84c + (uint)uVar21 * 4);
  if (*(int *)(PTR_DAT_0603e850 + (uint)uVar21 * 4) == 0) {
    puVar18 = (undefined4 *)(PTR_DAT_0603ea4c + (uint)uVar21 * 0x80);
    puVar18[0x15] = *puVar18;
    uVar9 = FUN_0603da88(puVar5);
    puVar5 = PTR_DAT_0603ea50;
    puVar18[0x16] = uVar9;
    uVar9 = FUN_0603d9ec(puVar5);
    puVar18[0x17] = uVar9;
    puVar5 = PTR_DAT_0603ea54;
    *(uint *)(PTR_DAT_0603ea54 + (uint)uVar21 * 4) = *(ushort *)PTR_DAT_0603ea58 - 1;
    puVar6 = PTR_DAT_0603ea60;
    puStack_64 = (uint *)(puVar5 + (uint)uVar21 * 4);
    piStack_68 = (int *)(PTR_DAT_0603ea5c + (char)(cVar22 * '$') + 0x18);
    local_6c = PTR_DAT_0603ea4c + (uint)uVar21 * 0x80;
    sVar12 = uVar21 * DAT_0603ea46;
    psVar7 = (short *)PTR_DAT_0603ea60;
    for (uVar19 = 0; uVar19 < *puStack_64; uVar19 = uVar19 + 1) {
      iVar23 = *piStack_68 * (uVar19 - (int)*(short *)(local_6c + 0x34)) + -(iVar14 * iVar13);
      iVar20 = (*(code *)PTR_FUN_0603ea64)();
      if (iVar20 == 0) {
LAB_0603ea9c:
        psVar7 = (short *)(puVar6 + uVar19 * 2 + (int)sVar12);
        *psVar7 = sVar11 + 1;
      }
      else {
        iVar20 = (*(code *)puVar4)(iVar8,iVar23);
        iVar24 = (*(code *)puVar4)(iVar8,iVar23);
        if (-iVar24 < 0 || (int)puVar3 < -iVar20) goto LAB_0603ea9c;
        iVar20 = (*(code *)puVar4)(iVar8,iVar23);
        psVar7 = (short *)(-iVar20 >> 6 & 0xffffU & uVar15);
        *(short *)(puVar6 + uVar19 * 2 + (int)sVar12) = (short)psVar7;
      }
    }
  }
  else {
    piVar17 = (int *)(PTR_DAT_0603e838 + (uint)uVar21 * 0x80);
    piVar17[0x15] = (int)(PTR_DAT_0603e854 + *piVar17);
    piVar16 = (int *)(PTR_DAT_0603e850 + (uint)uVar21 * 4);
    iVar20 = FUN_0603da88(PTR_DAT_0603e858 + *piVar16);
    piVar17[0x16] = iVar20;
    iVar20 = FUN_0603d9ec(PTR_DAT_0603e944 + *piVar16);
    piVar17[0x17] = iVar20;
    puVar5 = PTR_DAT_0603e948;
    *(int *)(PTR_DAT_0603e948 + (uint)uVar21 * 4) = (int)DAT_0603e93a;
    puVar6 = PTR_DAT_0603e954;
    puStack_64 = (uint *)(puVar5 + (uint)uVar21 * 4);
    piStack_68 = (int *)(PTR_DAT_0603e94c + (char)(cVar22 * '$') + 0x18);
    local_6c = PTR_DAT_0603e950 + (uint)uVar21 * 0x80;
    sVar11 = uVar21 * DAT_0603e93c;
    psVar7 = (short *)PTR_DAT_0603e954;
    for (uVar19 = 0; uVar19 < *puStack_64; uVar19 = uVar19 + 1) {
      iVar23 = *piStack_68 * ((uVar19 - (int)*(short *)(local_6c + 0x34)) + (int)DAT_0603e93e) +
               -(iVar14 * iVar13);
      iVar20 = (*(code *)PTR_FUN_0603e958)();
      if (iVar20 == 0) {
LAB_0603e964:
        psVar7 = (short *)(puVar6 + uVar19 * 2 + (int)sVar11);
        *psVar7 = sVar12;
      }
      else {
        iVar20 = (*(code *)puVar4)(iVar8,iVar23);
        iVar24 = (*(code *)puVar4)(iVar8,iVar23);
        if (-iVar24 < 0 || (int)puVar3 < -iVar20) goto LAB_0603e964;
        iVar20 = (*(code *)puVar4)(iVar8,iVar23);
        psVar7 = (short *)(-iVar20 >> 6 & 0xffffU & uVar15);
        *(short *)(puVar6 + uVar19 * 2 + (int)sVar11) = (short)psVar7;
      }
    }
  }
  *(undefined2 *)(PTR_DAT_0603eb00 + (uint)uVar21 * 2) = 1;
  return psVar7;
}

