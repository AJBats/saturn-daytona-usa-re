/* FUN_0602070C  0x0602070C */


void FUN_0602070c(undefined1 param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  puVar1 = PTR_DAT_060207d0;
  (*(code *)PTR_FUN_060207d4)(8);
  puVar2 = PTR_DAT_060207d8;
  *(int *)puVar1 = *(int *)puVar1 - (int)PTR_DAT_060207d8;
  iVar7 = *(int *)PTR_DAT_060207dc - (int)puVar2;
  *(int *)PTR_DAT_060207dc = iVar7;
  (*(code *)PTR_FUN_060207e0)(*(undefined4 *)puVar1,iVar7);
  puVar3 = PTR_DAT_060207e4;
  iVar7 = *(int *)PTR_DAT_060207e4 - (int)puVar2;
  *(int *)PTR_DAT_060207e4 = iVar7;
  puVar2 = PTR_DAT_060207e8;
  if ((int)PTR_DAT_060207ec < iVar7) {
    uVar4 = (*(code *)PTR_FUN_060207f8)(PTR_DAT_060207f4,*(int *)puVar3 + DAT_060207f0);
    iVar7 = (*(code *)PTR_FUN_060207fc)(uVar4,*(undefined4 *)puVar3);
    uVar4 = (*(code *)PTR_FUN_060207f8)(PTR_DAT_06020800,*(int *)puVar3 + DAT_060207f0);
    iVar5 = (*(code *)PTR_FUN_060207fc)(uVar4,*(undefined4 *)puVar3);
    puVar3 = PTR_DAT_06020804;
    iVar6 = *(int *)puVar2;
    iVar8 = *(int *)PTR_DAT_06020804;
    *(int *)puVar2 = iVar7;
    *(int *)puVar3 = iVar5;
    (*(code *)PTR_FUN_06020808)(iVar7 - iVar6,iVar5 - iVar8,0);
  }
  else {
    (*(code *)PTR_FUN_0602080c)(8,0);
    *(undefined4 *)puVar2 = 0;
  }
  (*(code *)PTR_FUN_06020810)();
  if (*(int *)puVar1 <= (int)PTR_DAT_060207ec) {
    FUN_06020dee(param_1);
    return;
  }
  return;
}

