/* FUN_06018938  0x06018938 */


void FUN_06018938(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  puVar5 = PTR_DAT_060189f4;
  puVar4 = PTR_FUN_060189f0;
  puVar3 = PTR_DAT_060189ec;
  puVar2 = PTR_DAT_060189e8;
  puVar1 = PTR_DAT_060189e4;
  (*(code *)PTR_FUN_060189f0)(PTR_DAT_060189f8,PTR_DAT_060189f4,(int)DAT_060189de);
  (*(code *)puVar4)(PTR_DAT_06018a00,puVar5 + DAT_060189de,PTR_DAT_060189fc);
  (*(code *)puVar4)(puVar3,PTR_DAT_06018a08 + (int)puVar5,PTR_DAT_06018a04);
  puVar5 = PTR_DAT_06018a10;
  (*(code *)puVar4)(PTR_DAT_06018a14,PTR_DAT_06018a10,PTR_DAT_06018a0c);
  (*(code *)puVar4)(PTR_DAT_06018a1c,PTR_DAT_06018a18 + (int)puVar5,(int)DAT_060189e0);
  (*(code *)puVar4)(PTR_DAT_06018a24,PTR_DAT_06018a20 + (int)puVar5,(int)DAT_060189e2);
  (*(code *)puVar4)(PTR_DAT_06018a2c,PTR_DAT_06018a28 + (int)puVar5,(int)DAT_060189e0);
  iVar8 = 0;
  iVar6 = 0;
  do {
    iVar8 = iVar8 + 2;
    iVar7 = iVar6 + 4;
    *(undefined **)(puVar2 + iVar6) = puVar3 + *(int *)(puVar1 + iVar6);
    *(undefined **)(puVar2 + iVar7) = puVar3 + *(int *)(puVar1 + iVar7);
    iVar6 = iVar6 + 8;
  } while (iVar8 < 8);
  (*(code *)PTR_FUN_06018a34)(*(undefined4 *)PTR_DAT_06018a30,iVar8,iVar7);
  (*(code *)PTR_FUN_06018a38)();
  return;
}

