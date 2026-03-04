/* FUN_0602EEB8  0x0602EEB8 */


void FUN_0602eeb8(void)

{
  int iVar1;
  uint *puVar2;
  
  (*(code *)PTR_FUN_0602ef00)();
  iVar1 = (*(code *)PTR_FUN_0602ef04)();
  *(undefined4 *)PTR_DAT_0602ef08 = 0;
  *(undefined2 *)(DAT_0602eefa + 2 + iVar1) = *(undefined2 *)(DAT_0602eefa + iVar1);
  (*(code *)PTR_FUN_0602ef0c)();
  (*(code *)PTR_FUN_0602ef10)();
  iVar1 = (*(code *)PTR_FUN_0602ef14)();
  if (*(short *)(PTR_DAT_0602eefc._0_2_ + iVar1) == 0) {
    (*(code *)PTR_FUN_0602ef64)();
  }
  else {
    (*DAT_0602ef18)();
  }
  (*(code *)PTR_FUN_0602ef68)();
  (*(code *)PTR_FUN_0602ef6c)();
  (*(code *)PTR_FUN_0602ef70)();
  (*(code *)PTR_FUN_0602ef74)();
  (*(code *)PTR_FUN_0602ef78)();
  (*(code *)PTR_FUN_0602ef7c)();
  iVar1 = (*(code *)PTR_FUN_0602ef80)();
  if (*(short *)(PTR_DAT_0602ef60._0_2_ + iVar1) == 0) {
    (*(code *)PTR_FUN_0602ef88)();
  }
  else {
    (*(code *)PTR_FUN_0602ef84)();
  }
  (*(code *)PTR_FUN_0602efbc)();
  (*(code *)PTR_FUN_0602efc0)();
  puVar2 = (uint *)(*(code *)PTR_FUN_0602efc4)();
  *puVar2 = *puVar2 & DAT_0602efc8;
  return;
}

