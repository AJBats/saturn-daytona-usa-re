/* FUN_0600FED0  0x0600FED0 */


void FUN_0600fed0(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  int iVar4;
  undefined *puVar5;
  int iVar6;
  
  puVar1 = PTR_DAT_0600ff60;
  iVar4 = *(int *)PTR_DAT_0600ff60;
  *(int *)PTR_DAT_0600ff60 = iVar4 + -1;
  if ((int)DAT_0600ff5c < iVar4 + -1) {
    (*(code *)PTR_FUN_0600ff68)(PTR_DAT_0600ff64 + -0x20);
  }
  puVar3 = PTR_DAT_0600ff7c;
  puVar5 = PTR_FUN_0600ff74;
  puVar2 = PTR_FUN_0600ff70;
  if (*(int *)puVar1 == (int)DAT_0600ff5c) {
    iVar6 = (int)DAT_0600ff5e;
    iVar4 = *(int *)PTR_DAT_0600ff80;
    if (iVar4 == 0) {
      (*(code *)PTR_FUN_0600ff78)(PTR_DAT_0600ff6c,PTR_PTR_0600ff84,0x20);
      (*(code *)puVar5)(PTR_DAT_0600ff88,puVar3);
      puVar5 = PTR_DAT_0600ff8c;
    }
    else if (iVar4 == 1) {
      (*(code *)PTR_FUN_0600ff78)(PTR_DAT_0600ff6c,PTR_PTR_0600ff90,0x20);
      (*(code *)puVar5)(PTR_DAT_0600ff94,puVar3);
      puVar5 = PTR_DAT_0600ff98;
    }
    else {
      if (iVar4 != 2) goto LAB_0600ffb4;
      (*(code *)PTR_FUN_0600ff78)(PTR_DAT_0600ff6c,PTR_PTR_0600ff9c,0x20);
      (*(code *)puVar5)(PTR_DAT_0600ffa0,puVar3);
      puVar5 = PTR_DAT_0600ffa4;
    }
    (*(code *)puVar2)(4,puVar5,0,iVar6);
  }
LAB_0600ffb4:
  if (*(int *)puVar1 == 0x78) {
    *(undefined4 *)puVar1 = 0;
  }
  return;
}

