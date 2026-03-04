/* FUN_0600F650  0x0600F650 */


void FUN_0600f650(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  
  puVar1 = PTR_FUN_0600f6d8;
  (*(code *)PTR_FUN_0600f6dc)();
  (*(code *)PTR_FUN_0600f6e4)(0,DAT_0600f6e0);
  (*(code *)PTR_FUN_0600f6e8)();
  puVar2 = PTR_DAT_0600f6ec;
  *(undefined2 *)(PTR_DAT_0600f6ec + 6) = 0;
  *(undefined2 *)(puVar2 + 4) = 0;
  *(undefined2 *)(puVar2 + 2) = 0;
  *(undefined2 *)puVar2 = 0;
  (*(code *)PTR_FUN_0600f6f8)(PTR_DAT_0600f6f4,PTR_PTR_0600f6f0,(int)PTR_DAT_0600f6d4._0_2_);
  puVar2 = PTR_DAT_0600f6fc;
  (*(code *)PTR_FUN_0600f704)(PTR_DAT_0600f700,PTR_DAT_0600f6fc);
  (*(code *)puVar1)(0xc,puVar2,0,PTR_DAT_0600f708);
  (*(code *)PTR_FUN_0600f70c)();
  (*(code *)PTR_FUN_0600f6e4)(0,DAT_0600f710);
  (*(code *)PTR_FUN_0600f714)(0);
  (*(code *)PTR_FUN_0600f718)(0);
  (*(code *)PTR_FUN_0600f71c)();
  puVar2 = PTR_DAT_0600f7cc;
  if (*(short *)(PTR_DAT_0600f720 + 6) == 0) {
    iVar4 = 0x24;
    iVar5 = 0x22;
  }
  else {
    iVar4 = 0x29;
    iVar5 = 0x26;
  }
  (*(code *)puVar1)(8,*(undefined4 *)(PTR_DAT_0600f7cc + iVar4 * 8),(int)DAT_0600f7c2,
                    PTR_DAT_0600f7d0 + *(int *)((int)(PTR_DAT_0600f7cc + iVar4 * 8) + 4));
  puVar3 = (undefined4 *)(puVar2 + iVar5 * 8);
  (*(code *)puVar1)(8,*puVar3,(int)DAT_0600f7c4,PTR_DAT_0600f7d0 + puVar3[1]);
  puVar3 = (undefined4 *)(puVar2 + DAT_0600f7c6);
  (*(code *)puVar1)(8,*puVar3,(int)DAT_0600f7c8,PTR_DAT_0600f7d4 + puVar3[1]);
  *(undefined4 *)PTR_DAT_0600f7d8 = 0;
  *(int *)PTR_DAT_0600f7dc = (int)DAT_0600f7ca;
  *PTR_DAT_0600f7e0 = 1;
  return;
}

