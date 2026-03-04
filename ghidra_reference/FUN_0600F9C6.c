/* FUN_0600F9C6  0x0600F9C6 */


void FUN_0600f9c6(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  
  (*(code *)PTR_FUN_0600fa24)(0,DAT_0600fa20);
  (*(code *)PTR_FUN_0600fa28)(0xc);
  (*(code *)PTR_FUN_0600fa34)(PTR_DAT_0600fa30,PTR_DAT_0600fa2c,(int)PTR_DAT_0600fa04._0_2_);
  (*(code *)PTR_FUN_0600fa38)();
  puVar2 = PTR_FUN_0600fb20;
  puVar1 = PTR_DAT_0600fb1c;
  if (*(short *)(PTR_DAT_0600fa3c + 6) == 0) {
    iVar5 = 0x25;
    iVar4 = 0x23;
  }
  else {
    iVar5 = 0x28;
    iVar4 = 0x27;
  }
  (*(code *)PTR_FUN_0600fb20)
            (0xc,*(undefined4 *)(PTR_DAT_0600fb1c + iVar5 * 8),(int)DAT_0600fb0c,
             PTR_DAT_0600fb24 + *(int *)((int)(PTR_DAT_0600fb1c + iVar5 * 8) + 4));
  puVar3 = (undefined4 *)(puVar1 + iVar4 * 8);
  (*(code *)puVar2)(0xc,*puVar3,(int)DAT_0600fb0e,PTR_DAT_0600fb24 + puVar3[1]);
  puVar3 = (undefined4 *)(puVar1 + DAT_0600fb10);
  (*(code *)puVar2)(0xc,*puVar3,(int)DAT_0600fb14,puVar3[1] + (int)DAT_0600fb12);
  (*(code *)PTR_FUN_0600fb2c)(0,DAT_0600fb28);
  *PTR_DAT_0600fb30 = 9;
  *(undefined4 *)PTR_DAT_0600fb34 = 0;
  *(undefined4 *)PTR_DAT_0600fb38 = 0;
  *(undefined4 *)PTR_DAT_0600fb3c = 0;
  *(undefined4 *)PTR_DAT_0600fb40 = 0;
  *(undefined4 *)PTR_DAT_0600fb44 = 1;
  if (*PTR_DAT_0600fb48 != '\0') {
    *(undefined4 *)PTR_DAT_0600fb4c = 0;
    *(undefined **)PTR_DAT_0600fb54 = PTR_DAT_0600fb50;
    *(undefined4 *)PTR_DAT_0600fb58 = 0;
    *PTR_DAT_0600fb5c = 0;
    (*(code *)PTR_FUN_0600fb64)(0xc,(int)PTR_DAT_0600fb18._0_2_,(int)DAT_0600fb16,PTR_DAT_0600fb60);
  }
  if (*PTR_DAT_0600fb48 == '\0') {
    (*(code *)PTR_FUN_0600fb68)(1);
    (*(code *)PTR_FUN_0600fb6c)(1);
  }
  (*(code *)PTR_FUN_0600fb70)();
  (*(code *)PTR_FUN_0600fb74)();
  return;
}

