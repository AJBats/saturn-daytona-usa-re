/* FUN_0603DB28  0x0603DB28 */


undefined4 FUN_0603db28(undefined4 param_1,undefined2 param_2,int param_3,int param_4)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  undefined2 uVar9;
  int iVar8;
  undefined *puVar10;
  undefined *puVar11;
  short local_68;
  undefined1 *local_60 [2];
  undefined1 auStack_58 [12];
  undefined1 *local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined1 *local_40 [2];
  undefined1 auStack_38 [12];
  undefined4 local_2c;
  undefined2 uStack_28;
  
  puVar1 = PTR_DAT_0603dba0;
  if (((param_3 == 1) || (param_3 == 0)) || ((param_3 == DAT_0603db9e && (param_4 == 1)))) {
    if (((param_4 == 1) || (param_4 == 2)) || (param_4 == 0)) {
      *PTR_DAT_0603dba4 = (char)param_3;
      *PTR_DAT_0603dba8 = (char)param_4;
      if ((param_3 == 1) && (param_4 == 1)) {
        *(undefined2 *)puVar1 = 2;
      }
      else {
        if ((param_3 == 0) && (param_4 == 1)) {
          uVar9 = 1;
        }
        else {
          uVar9 = 0;
        }
        *(undefined2 *)puVar1 = uVar9;
      }
      *(undefined2 *)PTR_DAT_0603dcbc = *(undefined2 *)puVar1;
      puVar1 = PTR_DAT_0603dcc0;
      *(undefined4 *)PTR_DAT_0603dcc0 = 0;
      *(undefined4 *)(puVar1 + 4) = 0;
      puVar1 = PTR_DAT_0603dcc4;
      *(undefined4 *)PTR_DAT_0603dcc4 = 0;
      puVar2 = PTR_DAT_0603dcc8;
      *(undefined4 *)PTR_DAT_0603dcc8 = 0;
      *(undefined4 *)(puVar1 + 4) = 0;
      *(undefined4 *)(puVar2 + 4) = 0;
      puVar1 = PTR_DAT_0603dccc;
      local_40[0] = (undefined1 *)local_40;
      puVar10 = PTR_DAT_0603dccc;
      local_2c = param_1;
      uStack_28 = param_2;
      (*(code *)PTR_FUN_0603dcd4)();
      local_44 = 0;
      local_48 = DAT_0603dcd8;
      local_4c = auStack_38;
      (*(code *)PTR_FUN_0603dcdc)();
      uVar4 = (*(code *)PTR_FUN_0603dce0)();
      *(undefined4 *)puVar1 = uVar4;
      puVar3 = PTR_PTR_0603dce8;
      puVar2 = PTR_DAT_0603dce4;
      local_60[0] = (undefined1 *)local_60;
      puVar11 = PTR_DAT_0603dce4;
      (*(code *)PTR_FUN_0603dcd4)();
      uVar4 = DAT_0603dcd8;
      (*(code *)PTR_FUN_0603dcdc)();
      uVar5 = (*(code *)PTR_FUN_0603dce0)();
      *(undefined4 *)puVar2 = uVar5;
      *(undefined4 *)(puVar10 + 4) = *(undefined4 *)puVar1;
      *(undefined4 *)(puVar11 + 4) = *(undefined4 *)puVar2;
      *(undefined1 **)PTR_DAT_0603dcec = auStack_58;
      local_68 = (short)((uint)uVar4 >> 0x10);
      *DAT_0603dcf0 = local_68;
      puVar11 = PTR_DAT_0603dcf8;
      puVar10 = PTR_FUN_0603dcf4;
      iVar8 = *(int *)puVar1;
      uVar4 = FUN_0603da88(0);
      iVar6 = (*(code *)puVar10)(uVar4,iVar8);
      iVar7 = FUN_0603d9ec(0);
      iVar7 = (*(code *)puVar10)(-iVar7,*(undefined4 *)puVar2);
      *(int *)puVar11 = (iVar8 - iVar6) - iVar7;
      uVar4 = FUN_0603d9ec(0);
      iVar6 = (*(code *)puVar10)(uVar4,*(undefined4 *)puVar1);
      iVar8 = *(int *)puVar2;
      uVar4 = FUN_0603da88(0);
      iVar7 = (*(code *)puVar10)(uVar4,*(undefined4 *)puVar2);
      *(int *)(puVar11 + 4) = (iVar8 - iVar6) - iVar7;
      *(undefined4 *)(puVar11 + 8) = 0;
      iVar6 = FUN_0603d9ec(0);
      *(int *)(puVar11 + 0xc) = -iVar6;
      uVar4 = FUN_0603da88(0);
      *(undefined4 *)(puVar11 + 0x10) = uVar4;
      uVar4 = FUN_0603da88(0);
      *(undefined4 *)(puVar11 + 0x14) = uVar4;
      uVar4 = FUN_0603d9ec(0);
      *(undefined4 *)(puVar11 + 0x18) = uVar4;
      puVar1 = PTR_DAT_0603dcfc;
      *(undefined **)(puVar11 + 0x1c) = PTR_DAT_0603dcfc;
      *(undefined4 *)(puVar11 + 0x20) = 0;
      *(undefined4 *)(puVar11 + 0x24) = 0;
      *(undefined4 *)(puVar11 + 0x28) = 0;
      *(undefined **)(puVar11 + 0x2c) = puVar1;
      *(undefined4 *)(puVar11 + 0x30) = 0;
      *(ushort *)(puVar11 + 0x34) = *(ushort *)PTR_DAT_0603dcd0 >> 1;
      *(ushort *)(puVar11 + 0x36) = *(ushort *)puVar3 >> 1;
      *(undefined2 *)(puVar11 + 0x38) = DAT_0603ddea;
      *(ushort *)(puVar11 + 0x3c) = *(ushort *)PTR_DAT_0603ddec >> 1;
      *(ushort *)(puVar11 + 0x3e) = *(ushort *)puVar3 >> 1;
      *(undefined2 *)(puVar11 + 0x40) = 0;
      *(undefined4 *)(puVar11 + 0x44) = 0;
      *(undefined4 *)(puVar11 + 0x48) = 0;
      *(undefined **)(puVar11 + 0x4c) = puVar1;
      *(undefined **)(puVar11 + 0x50) = puVar1;
      puVar1 = PTR_DAT_0603ddf0;
      if (local_68 == 2) {
        *(undefined4 *)PTR_DAT_0603ddf0 = *(undefined4 *)(PTR_DAT_0603ddf0 + -0x80);
        *(undefined4 *)(puVar1 + 4) = *(undefined4 *)(puVar1 + -0x7c);
        *(undefined4 *)(puVar1 + 8) = *(undefined4 *)(puVar1 + -0x78);
        *(undefined4 *)(puVar1 + 0xc) = *(undefined4 *)(puVar1 + -0x74);
        *(undefined4 *)(puVar1 + 0x10) = *(undefined4 *)(puVar1 + -0x70);
        *(undefined4 *)(puVar1 + 0x14) = *(undefined4 *)(puVar1 + -0x6c);
        *(undefined4 *)(puVar1 + 0x18) = *(undefined4 *)(puVar1 + -0x68);
        *(undefined4 *)(puVar1 + 0x1c) = *(undefined4 *)(puVar1 + -100);
        *(undefined4 *)(puVar1 + 0x20) = *(undefined4 *)(puVar1 + -0x60);
        *(undefined4 *)(puVar1 + 0x24) = *(undefined4 *)(puVar1 + -0x5c);
        *(undefined4 *)(puVar1 + 0x28) = *(undefined4 *)(puVar1 + -0x58);
        *(undefined4 *)(puVar1 + 0x2c) = *(undefined4 *)(puVar1 + -0x54);
        *(undefined4 *)(puVar1 + 0x30) = *(undefined4 *)(puVar1 + -0x50);
        *(undefined2 *)(puVar1 + 0x34) = *(undefined2 *)(puVar1 + -0x4c);
        *(undefined2 *)(puVar1 + 0x36) = *(undefined2 *)(puVar1 + -0x4a);
        *(undefined2 *)(puVar1 + 0x38) = *(undefined2 *)(puVar1 + -0x48);
        *(undefined2 *)(puVar1 + 0x3c) = *(undefined2 *)(puVar1 + -0x44);
        *(undefined2 *)(puVar1 + 0x3e) = *(undefined2 *)(puVar1 + -0x42);
        *(undefined2 *)(puVar1 + 0x40) = *(undefined2 *)(puVar1 + -0x40);
        *(undefined4 *)(puVar1 + 0x44) = *(undefined4 *)(puVar1 + -0x3c);
        *(undefined4 *)(puVar1 + 0x48) = *(undefined4 *)(puVar1 + -0x38);
        *(undefined4 *)(puVar1 + 0x4c) = *(undefined4 *)(puVar1 + -0x34);
        *(undefined4 *)(puVar1 + 0x50) = *(undefined4 *)(puVar1 + -0x30);
      }
      *(uint *)PTR_DAT_0603ddf8 =
           (((uint)auStack_58 & (uint)PTR_DAT_0603ddf4) >> 1) + (((uint)auStack_58 & 0x3e) >> 2);
      uVar4 = 0;
    }
    else {
      uVar4 = 2;
    }
  }
  else {
    uVar4 = 2;
  }
  return uVar4;
}

