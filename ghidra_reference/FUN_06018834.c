/* FUN_06018834  0x06018834 */


void FUN_06018834(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  puVar5 = PTR_DAT_060188f4;
  puVar4 = PTR_FUN_060188f0;
  puVar3 = PTR_DAT_060188ec;
  puVar2 = PTR_DAT_060188e8;
  puVar1 = PTR_DAT_060188e4;
  (*(code *)PTR_FUN_060188f0)(PTR_DAT_060188f8,PTR_DAT_060188f4,(int)DAT_060188da);
  (*(code *)puVar4)(PTR_DAT_060188fc,puVar5 + DAT_060188da,(int)DAT_060188dc);
  (*(code *)puVar4)(puVar3,PTR_DAT_06018904 + (int)puVar5,PTR_DAT_06018900);
  puVar5 = PTR_DAT_0601890c;
  (*(code *)puVar4)(PTR_DAT_06018910,PTR_DAT_0601890c,PTR_DAT_06018908);
  (*(code *)puVar4)(PTR_DAT_06018918,PTR_DAT_06018914 + (int)puVar5,(int)DAT_060188de);
  (*(code *)puVar4)(PTR_DAT_06018920,PTR_DAT_0601891c + (int)puVar5,(int)DAT_060188e0);
  (*(code *)puVar4)(PTR_DAT_06018928,PTR_DAT_06018924 + (int)puVar5,(int)DAT_060188de);
  iVar8 = 0;
  iVar6 = 0;
  do {
    iVar8 = iVar8 + 2;
    iVar7 = iVar6 + 4;
    *(undefined **)(puVar2 + iVar6) = puVar3 + *(int *)(puVar1 + iVar6);
    *(undefined **)(puVar2 + iVar7) = puVar3 + *(int *)(puVar1 + iVar7);
    iVar6 = iVar6 + 8;
  } while (iVar8 < 8);
  (*(code *)PTR_FUN_06018930)(*(undefined4 *)PTR_DAT_0601892c,iVar8,iVar7);
  (*(code *)PTR_FUN_06018934)();
  return;
}

