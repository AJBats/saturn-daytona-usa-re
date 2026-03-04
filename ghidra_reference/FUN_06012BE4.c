/* FUN_06012BE4  0x06012BE4 */


void FUN_06012be4(void)

{
  undefined *puVar1;
  uint uVar2;
  uint unaff_r13;
  int iVar3;
  
  puVar1 = PTR_FUN_06012c68;
  iVar3 = (int)DAT_06012c66;
  (*(code *)PTR_FUN_06012c74)(8,iVar3,PTR_DAT_06012c70,PTR_s_SET_DAYTONA_DISC___06012c6c);
  (*(code *)PTR_FUN_06012c80)(*(int *)PTR_DAT_06012c7c + iVar3,PTR_DAT_06012c78 + iVar3,0x24);
  (*(code *)PTR_FUN_06012c84)();
  do {
    uVar2 = (*(code *)puVar1)();
  } while ((uVar2 & unaff_r13) != 1);
  (*(code *)PTR_FUN_06012c74)(8,iVar3,PTR_DAT_06012c70,PTR_DAT_06012c88);
  (*(code *)PTR_FUN_06012c80)(*(int *)PTR_DAT_06012c7c + iVar3,PTR_DAT_06012c78 + iVar3,0x24);
  FUN_06012b58();
  return;
}

