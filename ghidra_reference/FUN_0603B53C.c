/* FUN_0603B53C  0x0603B53C */


int FUN_0603b53c(undefined4 *param_1)

{
  int in_r0;
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  
  iVar2 = *(int *)PTR_DAT_0603b564;
  puVar3 = (undefined4 *)(iVar2 + 0x34);
  if (*(int *)((int)puVar3 + in_r0) == 0) {
    *param_1 = 0;
    iVar4 = 0;
  }
  else {
    uVar1 = *puVar3;
    *param_1 = uVar1;
    iVar4 = FUN_0603b424(uVar1);
    if (iVar4 == 0) {
      if (*(int *)(iVar2 + 0x94) == 0) {
        *param_1 = 0;
        iVar4 = 0;
      }
      else {
        iVar4 = 1;
      }
    }
  }
  FUN_0603b93c(0);
  return iVar4;
}

