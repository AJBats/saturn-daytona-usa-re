/* FUN_06018738  0x06018738 */


void FUN_06018738(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  puVar5 = PTR_DAT_060187fc;
  puVar4 = PTR_FUN_060187f8;
  puVar3 = PTR_DAT_060187f4;
  puVar2 = PTR_DAT_060187f0;
  puVar1 = PTR_DAT_060187ec;
  (*(code *)PTR_FUN_060187f8)(PTR_DAT_06018800,PTR_DAT_060187fc,(int)DAT_060187de);
  (*(code *)puVar4)(PTR_DAT_06018804,puVar5 + DAT_060187de,(int)DAT_060187e0);
  (*(code *)puVar4)(puVar3,puVar5 + DAT_060187e4,(int)DAT_060187e2);
  puVar5 = PTR_DAT_0601880c;
  (*(code *)puVar4)(PTR_DAT_06018810,PTR_DAT_0601880c,PTR_DAT_06018808);
  (*(code *)puVar4)(PTR_DAT_06018818,PTR_DAT_06018814 + (int)puVar5,(int)DAT_060187e6);
  (*(code *)puVar4)(PTR_DAT_0601881c,puVar5 + DAT_060187ea,(int)DAT_060187e8);
  (*(code *)puVar4)(PTR_DAT_06018824,PTR_DAT_06018820 + (int)puVar5,(int)DAT_060187e6);
  iVar8 = 0;
  iVar6 = 0;
  do {
    iVar8 = iVar8 + 2;
    iVar7 = iVar6 + 4;
    *(undefined **)(puVar2 + iVar6) = puVar3 + *(int *)(puVar1 + iVar6);
    *(undefined **)(puVar2 + iVar7) = puVar3 + *(int *)(puVar1 + iVar7);
    iVar6 = iVar6 + 8;
  } while (iVar8 < 8);
  (*(code *)PTR_FUN_0601882c)(*(undefined4 *)PTR_DAT_06018828,iVar8,iVar7);
  (*(code *)PTR_FUN_06018830)();
  return;
}

