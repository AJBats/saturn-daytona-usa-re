/* FUN_0600DBA0  0x0600DBA0 */


uint FUN_0600dba0(void)

{
  undefined *puVar1;
  uint uVar2;
  int in_r3;
  int iVar3;
  undefined4 uVar4;
  
  puVar1 = PTR_DAT_0600dbf4;
  if ((int)(*(ushort *)PTR_DAT_0600dbf8 & 7) < in_r3) {
    if (*(int *)PTR_DAT_0600dbfc == 1) {
      (*(code *)PTR_FUN_0600dc04)
                (8,*(undefined4 *)PTR_DAT_0600dc00,(int)DAT_0600dbde,
                 *(int *)(PTR_DAT_0600dc00 + 4) + (int)DAT_0600dbdc,PTR_DAT_0600dc00);
    }
    else {
      (*(code *)PTR_FUN_0600dca4)
                (8,*(undefined4 *)PTR_DAT_0600dca0,(int)DAT_0600dc9a,
                 *(int *)(PTR_DAT_0600dca0 + 4) + (int)DAT_0600dc98,PTR_DAT_0600dca0);
    }
  }
  else {
    FUN_0600dc74();
  }
  uVar2 = (uint)*(ushort *)PTR_DAT_0600dca8;
  if ((*(ushort *)PTR_DAT_0600dca8 & 0x3f) == 0) {
    iVar3 = *(int *)puVar1;
    *(uint *)puVar1 = iVar3 + 1U;
    if (iVar3 + 1U < 7) {
      uVar2 = (*(code *)PTR_FUN_0600dcac)(0,DAT_0600dcb0);
    }
    else {
      uVar4 = DAT_0600dcb0;
      if (*(int *)PTR_DAT_0600dcb4 == 1) {
        uVar4 = DAT_0600dcb8;
      }
      uVar2 = (*(code *)PTR_FUN_0600dcac)(0,uVar4);
      *(undefined2 *)PTR_DAT_0600dcbc = 0x28;
      *(undefined4 *)puVar1 = 0;
    }
  }
  return uVar2;
}

