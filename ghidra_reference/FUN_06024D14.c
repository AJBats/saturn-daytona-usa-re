/* FUN_06024D14  0x06024D14 */


void FUN_06024d14(void)

{
  ushort uVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined2 uVar5;
  ushort uVar6;
  undefined *puVar7;
  int iVar8;
  undefined *puVar9;
  undefined *puVar10;
  uint uVar11;
  int iStack_28;
  
  puVar4 = PTR_DAT_06024dc4;
  puVar3 = PTR_DAT_06024dc0;
  puVar2 = PTR_DAT_06024dbc;
  uVar11 = (uint)DAT_06024db8;
  if (*PTR_DAT_06024dc0 == '\0') {
    *PTR_DAT_06024dc0 = 1;
    (*(code *)PTR_FUN_06024dcc)(0,DAT_06024dc8);
    puVar7 = PTR_DAT_06024dd4;
    *(uint *)PTR_DAT_06024dd4 = *(uint *)PTR_DAT_06024dd4 | DAT_06024dd0;
    *(uint *)puVar7 = *(uint *)puVar7 | 4;
    puVar9 = PTR_DAT_06024ddc;
    puVar7 = PTR_FUN_06024dd8;
    (*(code *)PTR_FUN_06024dd8)(PTR_DAT_06024de0,PTR_DAT_06024ddc,(int)DAT_06024dba);
    puVar10 = PTR_DAT_06024de4;
    (*(code *)puVar7)(PTR_DAT_06024de8,PTR_DAT_06024de4,0x20);
    (*(code *)puVar7)(PTR_DAT_06024dec,puVar9,(int)DAT_06024dba);
    (*(code *)puVar7)(PTR_DAT_06024df0,puVar10,0x20);
    (*(code *)PTR_FUN_06024dfc)(PTR_DAT_06024df8,PTR_DAT_06024df4,0,8);
    uVar5 = (*(code *)PTR_FUN_06024e00)();
    *(undefined2 *)puVar2 = uVar5;
    *(undefined2 *)PTR_DAT_06024e04 = 0;
    *(int *)puVar4 = (int)(char)*PTR_DAT_06024e08;
    FUN_06025070();
    FUN_06025148();
    if (*(ushort *)puVar2 == uVar11) {
      FUN_06025224(*(undefined4 *)puVar4);
    }
    else {
      FUN_06025478(*(undefined4 *)puVar4);
    }
  }
  if (*puVar3 == '\x01') {
    (*(code *)PTR_FUN_06024eac)((int)*(short *)PTR_DAT_06024ea8);
    uVar1 = *(ushort *)PTR_DAT_06024eb0;
    if (uVar1 != 0) {
      iStack_28 = 0;
      uVar6 = uVar1 & DAT_06024ea0;
      do {
        if ((*(int *)puVar4 == 4) && (uVar6 != 0)) {
          *puVar3 = 4;
          *(undefined4 *)PTR_DAT_06024eb4 = 0xffffffff;
          *(undefined2 *)PTR_DAT_06024eb8 = 0;
          *(undefined2 *)PTR_DAT_06024ebc = 0;
          (*(code *)PTR_FUN_06024eac)(0);
          if (*(ushort *)puVar2 == uVar11) {
            FUN_06025224(*(undefined4 *)puVar4);
          }
          else {
            FUN_06025478(*(undefined4 *)puVar4);
          }
          break;
        }
        if ((uVar1 & DAT_06024ea2) != 0) {
          *PTR_DAT_06024ec0 = (char)*(undefined4 *)puVar4;
          *puVar3 = 2;
          break;
        }
        if ((uVar1 & PTR_DAT_06024ea4._0_2_) != 0) {
          *puVar3 = 2;
          break;
        }
        if ((((uint)uVar1 & (uint)PTR_DAT_06024f74) != 0) &&
           (iVar8 = *(int *)puVar4, *(int *)puVar4 = iVar8 + 1, 4 < iVar8 + 1)) {
          *(undefined4 *)puVar4 = 0;
        }
        if (((uVar1 & DAT_06024f72) != 0) &&
           (iVar8 = *(int *)puVar4, *(int *)puVar4 = iVar8 + -1, iVar8 + -1 < 0)) {
          *(undefined4 *)puVar4 = 4;
        }
        if (*(ushort *)puVar2 == uVar11) {
          FUN_06025224(*(undefined4 *)puVar4);
        }
        else {
          FUN_06025478(*(undefined4 *)puVar4);
        }
        iStack_28 = iStack_28 + 1;
      } while (iStack_28 < 1);
    }
  }
  else if (*puVar3 == '\x04') {
    if (*(ushort *)puVar2 == uVar11) {
      FUN_060256cc();
    }
    else {
      FUN_06025bf4();
    }
  }
  else if (*puVar3 == '\x05') {
    (*(code *)PTR_FUN_06024f78)();
  }
  if (*puVar3 == '\x06') {
    if (*(short *)PTR_DAT_06024f7c == 0) {
      if (*(ushort *)puVar2 == uVar11) {
        FUN_06025070();
      }
      else {
        FUN_06025148();
      }
    }
    else {
      (*(code *)PTR_FUN_06025044)((int)(char)*(undefined4 *)puVar4,(int)*(short *)puVar2);
      iVar8 = 0;
      puVar7 = PTR_PTR_06025048;
      puVar9 = PTR_PTR_06025048;
      puVar10 = PTR_PTR_0602504c;
      do {
        if (*(ushort *)puVar2 == uVar11) {
          **(undefined2 **)(PTR_PTR_0602504c + iVar8 * 8) = **(undefined2 **)(puVar7 + 4);
        }
        else {
          **(undefined2 **)(puVar10 + 4) = **(undefined2 **)(puVar9 + 4);
        }
        iVar8 = iVar8 + 1;
        puVar9 = puVar9 + 0xc;
        puVar10 = puVar10 + 8;
        puVar7 = puVar7 + 0xc;
      } while (iVar8 < 0xe);
    }
    if (*(ushort *)puVar2 == uVar11) {
      FUN_06025224(*(undefined4 *)puVar4);
    }
    else {
      FUN_06025478(*(undefined4 *)puVar4);
    }
    *puVar3 = 1;
  }
  if (*puVar3 == '\x02') {
    *puVar3 = 0;
    *PTR_DAT_06025050 = 0;
    *(uint *)PTR_DAT_06025054 = *(uint *)PTR_DAT_06025054 | 4;
    (*(code *)PTR_FUN_06025058)(8);
    (*(code *)PTR_FUN_06025058)(0xc);
    (*(code *)PTR_FUN_0602505c)();
    *PTR_DAT_06025060 = *PTR_DAT_06025060 + '\x01';
  }
  *(short *)PTR_DAT_06025064 = *(short *)PTR_DAT_06025064 + 1;
  *(uint *)PTR_DAT_06025054 = *(uint *)PTR_DAT_06025054 | 4;
  *(undefined4 *)PTR_DAT_06025068 = 0;
  (*(code *)PTR_FUN_0602506c)();
  return;
}

