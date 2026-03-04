/* FUN_0603E050  0x0603E050 */


undefined2 * FUN_0603e050(undefined4 param_1)

{
  short sVar1;
  short sVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined2 *puVar6;
  ushort uVar9;
  int iVar7;
  undefined4 uVar8;
  int iVar10;
  undefined *puVar11;
  int iVar12;
  int iVar13;
  undefined4 *puVar14;
  uint uVar15;
  ushort uVar16;
  char cVar17;
  undefined ***pppuVar18;
  int iVar19;
  int iVar20;
  undefined1 *local_9c;
  undefined4 local_98;
  undefined1 *local_90 [2];
  undefined1 auStack_88 [8];
  undefined2 *local_80;
  undefined **local_7c;
  undefined4 *local_78;
  int local_74;
  uint *local_70;
  int *piStack_6c;
  undefined *puStack_68;
  int local_64;
  int *local_60;
  int local_5c;
  int *piStack_58;
  int iStack_54;
  int iStack_50;
  int iStack_4c;
  int *piStack_48;
  int iStack_44;
  int *piStack_40;
  int iStack_3c;
  int iStack_38;
  int *piStack_34;
  int *piStack_30;
  int *piStack_2c;
  int iStack_28;
  
  puVar11 = PTR_DAT_0603e0c0;
  puVar5 = PTR_FUN_0603e0bc;
  puVar4 = PTR_DAT_0603e0b8;
  puVar3 = PTR_DAT_0603e0b4;
  puVar6 = *(undefined2 **)PTR_DAT_0603e0c4;
  if (puVar6 == (undefined2 *)&UNK_00000001) {
    uVar16 = 0;
    *(ushort *)(PTR_DAT_0603e0c0 + 4) = *(ushort *)(PTR_DAT_0603e0c0 + 4) & (ushort)PTR_DAT_0603e0c8
    ;
    uVar9 = *(ushort *)(puVar11 + 4) | 3;
  }
  else {
    if (puVar6 != (undefined2 *)&UNK_00000002) {
      return puVar6;
    }
    uVar16 = 1;
    *(ushort *)(PTR_DAT_0603e0c0 + 4) = *(ushort *)(PTR_DAT_0603e0c0 + 4) & 0xff;
    uVar9 = *(ushort *)(puVar11 + 4) | DAT_0603e0b2;
  }
  *(ushort *)(puVar11 + 4) = uVar9;
  iStack_54 = param_1;
  local_5c = FUN_0603d9ec(param_1);
  iStack_54 = FUN_0603da88(iStack_54);
  puVar11 = PTR_FUN_0603e1ac;
  cVar17 = (char)uVar16;
  puVar14 = (undefined4 *)(PTR_DAT_0603e1a8 + (char)(cVar17 * '$'));
  local_60 = puVar14 + 1;
  iStack_50 = *local_60;
  piStack_30 = puVar14 + 2;
  iStack_28 = *piStack_30;
  piStack_34 = puVar14 + 4;
  iStack_38 = *piStack_34;
  piStack_40 = puVar14 + 5;
  iStack_3c = *piStack_40;
  piStack_48 = puVar14 + 7;
  iStack_44 = *piStack_48;
  piStack_58 = puVar14 + 8;
  iStack_4c = *piStack_58;
  piStack_2c = local_60;
  local_64 = (*(code *)PTR_FUN_0603e1ac)(iStack_50,iStack_54);
  iVar7 = (*(code *)puVar11)(iStack_28,local_5c);
  *local_60 = iVar7 + local_64;
  local_60 = piStack_30;
  local_64 = (*(code *)puVar11)(iStack_50,local_5c);
  local_64 = -local_64;
  iVar7 = (*(code *)puVar11)(iStack_28,iStack_54);
  *local_60 = iVar7 + local_64;
  local_60 = piStack_34;
  local_64 = (*(code *)puVar11)(iStack_38,iStack_54);
  iVar7 = (*(code *)puVar11)(iStack_3c,local_5c);
  *local_60 = iVar7 + local_64;
  local_60 = piStack_40;
  local_64 = (*(code *)puVar11)(iStack_38,local_5c);
  local_64 = -local_64;
  iVar7 = (*(code *)puVar11)(iStack_3c,iStack_54);
  *local_60 = iVar7 + local_64;
  local_60 = piStack_48;
  local_64 = (*(code *)puVar11)(iStack_44,iStack_54);
  iVar7 = (*(code *)puVar11)(iStack_4c,local_5c);
  *local_60 = iVar7 + local_64;
  local_60 = piStack_58;
  local_64 = (*(code *)puVar11)(iStack_44,local_5c);
  local_64 = -local_64;
  iVar7 = (*(code *)puVar11)(iStack_4c,iStack_54);
  *local_60 = iVar7 + local_64;
  puVar11 = PTR_DAT_0603e2bc;
  *(undefined4 *)(PTR_DAT_0603e2bc + (uint)uVar16 * 0x80 + 0x1c) = *puVar14;
  *(int *)(puVar11 + (uint)uVar16 * 0x80 + 0x20) = *piStack_2c;
  *(int *)(puVar11 + (uint)uVar16 * 0x80 + 0x24) = *piStack_30;
  *(int *)(puVar11 + (uint)uVar16 * 0x80 + 0x2c) = *piStack_34;
  *(int *)(puVar11 + (uint)uVar16 * 0x80 + 0x30) = *piStack_40;
  iVar13 = puVar14[6];
  iVar12 = (int)*(short *)(puVar11 + (uint)uVar16 * 0x80 + 0x34);
  iVar19 = iVar13 * (iVar12 - *(short *)(puVar11 + (uint)uVar16 * 0x80 + 0x3c));
  iVar10 = *piStack_48;
  sVar1 = *(short *)(puVar11 + (uint)uVar16 * 0x80 + 0x36);
  sVar2 = *(short *)(puVar11 + (uint)uVar16 * 0x80 + 0x3e);
  iStack_54 = *piStack_58;
  local_5c = (int)*(short *)(puVar11 + (uint)uVar16 * 0x80 + 0x38);
  iVar20 = iStack_54 * (local_5c - *(short *)(puVar11 + (uint)uVar16 * 0x80 + 0x40));
  local_70 = (uint *)&local_70;
  (*(code *)PTR_FUN_0603e2c0)();
  local_74 = 0;
  local_78 = (undefined4 *)DAT_0603e2c4;
  local_7c = &puStack_68;
  pppuVar18 = &local_7c;
  (*(code *)PTR_FUN_0603e2c8)();
  iVar7 = (*(code *)PTR_FUN_0603e2cc)();
  puVar11 = PTR_DAT_0603e2bc;
  local_70 = (uint *)((uint)uVar16 * 4);
  iVar7 = iVar19 + iVar10 * ((int)sVar1 - (int)sVar2) + iVar20 + iVar7 +
          *(int *)(PTR_DAT_0603e2d0 + (int)local_70);
  local_74 = -((int)local_7c * local_74) - iVar12 * iVar13;
  if (*(int *)(PTR_DAT_0603e2d4 + (int)local_70) == 0) {
    if ((*(int *)(PTR_DAT_0603e448 + (uint)uVar16 * 4) == -1) ||
       (*(int *)(PTR_DAT_0603e448 + (uint)uVar16 * 4) == 0)) {
      *(undefined4 *)(PTR_DAT_0603e540 + (uint)uVar16 * 0x80 + 0x54) =
           *(undefined4 *)(PTR_DAT_0603e540 + (uint)uVar16 * 0x80 + 4);
    }
    else {
      puVar11 = PTR_DAT_0603e44c + (uint)uVar16 * 0x80;
      local_90[0] = (undefined1 *)local_90;
      (*(code *)PTR_FUN_0603e450)();
      local_98 = DAT_0603e454;
      local_9c = auStack_88;
      pppuVar18 = (undefined ***)&local_9c;
      (*(code *)PTR_FUN_0603e458)();
      iVar10 = (*(code *)PTR_FUN_0603e45c)();
      *(int *)(puVar11 + 0x54) = iVar10 + *(int *)(puVar11 + 4);
    }
    *pppuVar18 = (undefined **)(PTR_DAT_0603e540 + (uint)uVar16 * 0x80);
    ((int *)pppuVar18)[-1] = (int)(PTR_DAT_0603e540 + (uint)uVar16 * 0x80 + 0x58);
    uVar8 = FUN_0603da88(0);
    *(undefined4 *)((int *)pppuVar18)[-1] = uVar8;
    ((int *)pppuVar18)[-1] = (int)*pppuVar18 + 0x5c;
    uVar8 = FUN_0603d9ec(0);
    *(undefined4 *)((int *)pppuVar18)[-1] = uVar8;
    puVar11 = PTR_DAT_0603e544;
    *(uint *)(PTR_DAT_0603e544 + (uint)uVar16 * 4) = *(ushort *)PTR_PTR_0603e548 - 1;
    ((int *)pppuVar18)[4] = (int)(puVar11 + (uint)uVar16 * 4);
    ((int *)pppuVar18)[3] = (int)(PTR_DAT_0603e54c + (char)(cVar17 * '$') + 0x1c);
    ((int *)pppuVar18)[5] = (int)(PTR_DAT_0603e540 + (uint)uVar16 * 0x80);
    ((int *)pppuVar18)[1] = (int)(PTR_DAT_0603e550 + (short)(uVar16 * PTR_DAT_0603e53c._0_2_));
    puVar6 = (undefined2 *)PTR_DAT_0603e550;
    for (uVar15 = 0; uVar15 < *(uint *)((int *)pppuVar18)[4]; uVar15 = uVar15 + 1) {
      *pppuVar18 = (undefined **)
                   (*(int *)((int *)pppuVar18)[3] *
                    (uVar15 - (int)*(short *)(((int *)pppuVar18)[5] + 0x36)) + ((int *)pppuVar18)[2]
                   );
      iVar10 = (*(code *)PTR_FUN_0603e554)();
      if (iVar10 == 0) {
        puVar6 = (undefined2 *)(uVar15 * 2 + ((int *)pppuVar18)[1]);
LAB_0603e58c:
        *puVar6 = (short)puVar4;
      }
      else {
        iVar10 = (*(code *)puVar5)(iVar7,*pppuVar18);
        if (((int)puVar3 < -iVar10) || (iVar10 = (*(code *)puVar5)(iVar7,*pppuVar18), -iVar10 < 0))
        {
          puVar6 = (undefined2 *)(uVar15 * 2 + ((int *)pppuVar18)[1]);
          goto LAB_0603e58c;
        }
        ((int *)pppuVar18)[-1] = uVar15 * 2 + ((int *)pppuVar18)[1];
        iVar10 = (*(code *)puVar5)(iVar7,*pppuVar18);
        puVar6 = (undefined2 *)(-iVar10 >> 6 & 0xffffU & (int)DAT_0603e61e);
        *(short *)((int *)pppuVar18)[-1] = (short)puVar6;
      }
    }
  }
  else {
    *(undefined **)(PTR_DAT_0603e2bc + (uint)uVar16 * 0x80 + 0x54) =
         PTR_DAT_0603e2d8 + *(int *)(PTR_DAT_0603e2bc + (uint)uVar16 * 0x80 + 4);
    local_7c = (undefined **)((uint)uVar16 * 4);
    local_78 = (undefined4 *)(PTR_DAT_0603e2d4 + (int)local_7c);
    uVar8 = FUN_0603da88(*local_78);
    *(undefined4 *)(puVar11 + (uint)uVar16 * 0x80 + 0x58) = uVar8;
    uVar8 = FUN_0603d9ec(*local_78);
    *(undefined4 *)(puVar11 + (uint)uVar16 * 0x80 + 0x5c) = uVar8;
    puVar11 = PTR_DAT_0603e3c0;
    *(int *)(PTR_DAT_0603e3c0 + (int)local_7c) = (int)DAT_0603e3b6;
    local_70 = (uint *)(puVar11 + (uint)uVar16 * 4);
    piStack_6c = (int *)(PTR_DAT_0603e3c4 + (char)(cVar17 * '$') + 0x1c);
    puStack_68 = PTR_DAT_0603e3c8 + (uint)uVar16 * 0x80;
    local_78 = (undefined4 *)(PTR_DAT_0603e3cc + (short)(uVar16 * DAT_0603e3b8));
    puVar6 = (undefined2 *)PTR_DAT_0603e3cc;
    for (uVar15 = 0; uVar15 < *local_70; uVar15 = uVar15 + 1) {
      local_7c = (undefined **)
                 (*piStack_6c * ((uVar15 - (int)*(short *)(puStack_68 + 0x36)) + (int)DAT_0603e3ba)
                 + local_74);
      iVar10 = (*(code *)PTR_FUN_0603e3d0)();
      if (iVar10 == 0) {
        puVar6 = (undefined2 *)((int)local_78 + uVar15 * 2);
LAB_0603e3dc:
        *puVar6 = (short)puVar4;
      }
      else {
        iVar10 = (*(code *)puVar5)(iVar7,local_7c);
        if (((int)puVar3 < -iVar10) || (iVar10 = (*(code *)puVar5)(iVar7,local_7c), -iVar10 < 0)) {
          puVar6 = (undefined2 *)((int)local_78 + uVar15 * 2);
          goto LAB_0603e3dc;
        }
        local_80 = (undefined2 *)((int)local_78 + uVar15 * 2);
        iVar10 = (*(code *)puVar5)(iVar7,local_7c);
        puVar6 = (undefined2 *)(-iVar10 >> 6 & 0xffffU & (int)DAT_0603e3bc);
        *local_80 = (short)puVar6;
      }
    }
  }
  *(undefined2 *)(PTR_DAT_0603e624 + (uint)uVar16 * 2) = 1;
  return puVar6;
}

