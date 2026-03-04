/* FUN_0600D496  0x0600D496 */


void FUN_0600d496(void)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  uint uVar6;
  
  puVar2 = PTR_DAT_0600d4b4;
  puVar1 = PTR_DAT_0600d4ac;
  piVar4 = (int *)(PTR_DAT_0600d4ac + 4);
  piVar5 = piVar4;
  for (uVar6 = 1; uVar6 < *(int *)puVar2 - 1U; uVar6 = uVar6 + 1) {
    iVar3 = (int)DAT_0600d534;
    *(int *)(*piVar5 + iVar3) = piVar5[-1];
    *(int *)(*piVar5 + iVar3 + 4) = piVar5[1];
    piVar5 = piVar5 + 1;
  }
  *(int *)(*(int *)puVar1 + (int)DAT_0600d534) = *piVar5;
  iVar3 = (int)DAT_0600d536;
  *(int *)(*(int *)puVar1 + iVar3) = *piVar4;
  *(int *)(*piVar5 + iVar3 + -4) = piVar5[-1];
  *(undefined4 *)(*piVar5 + iVar3) = *(undefined4 *)puVar1;
  *(undefined4 *)PTR_DAT_0600d538 = *(undefined4 *)(*piVar5 + iVar3 + -0x50);
  return;
}

