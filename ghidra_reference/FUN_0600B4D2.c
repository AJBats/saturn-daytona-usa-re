/* FUN_0600B4D2  0x0600B4D2 */


void FUN_0600b4d2(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  int iVar4;
  int iVar5;
  undefined *unaff_r11;
  undefined *puVar6;
  undefined *unaff_r12;
  undefined *puVar7;
  int iVar8;
  
  iVar5 = *(int *)PTR_DAT_0600b50c;
  iVar8 = *(int *)PTR_DAT_0600b510;
  *(int *)PTR_DAT_0600b514 = iVar8;
  puVar2 = PTR_DAT_0600b640;
  puVar1 = PTR_DAT_0600b63c;
  iVar4 = *(int *)PTR_DAT_0600b518;
  puVar6 = PTR_PTR_0600b520;
  puVar7 = PTR_LAB_0600b51c;
  if (((iVar4 != 0) && (puVar6 = PTR_PTR_0600b528, puVar7 = PTR_PTR_0600b524, iVar4 != 1)) &&
     (puVar6 = unaff_r11, puVar7 = unaff_r12, iVar4 == 2)) {
    puVar6 = PTR_LAB_0600b530;
    puVar7 = PTR_LAB_0600b52c;
  }
  *(int *)PTR_DAT_0600b640 =
       *(int *)PTR_DAT_0600b640 +
       ((int)(PTR_DAT_0600b63c + (*(int *)(iVar8 + 0x10) - *(int *)PTR_DAT_0600b640) +
             ((int)(PTR_DAT_0600b63c + (*(int *)(iVar8 + 0x10) - *(int *)PTR_DAT_0600b640)) < 0)) >>
       1);
  iVar4 = *(int *)(iVar8 + 0x14) - *(int *)(puVar2 + 4);
  *(int *)(puVar2 + 4) = *(int *)(puVar2 + 4) + ((int)(iVar4 + (uint)(iVar4 < 0)) >> 1);
  puVar3 = PTR_FUN_0600b644;
  iVar4 = (*(int *)(iVar8 + 0x18) - *(int *)(puVar2 + 8)) + (int)DAT_0600b630;
  *(int *)(puVar2 + 8) = *(int *)(puVar2 + 8) + ((int)(iVar4 + (uint)(iVar4 < 0)) >> 1);
  (*(code *)puVar3)();
  (*(code *)PTR_FUN_0600b648)
            (*(undefined4 *)puVar2,*(undefined4 *)(puVar2 + 4),*(undefined4 *)(puVar2 + 8));
  (*(code *)PTR_FUN_0600b64c)(*(undefined4 *)(iVar8 + 0x20));
  (*(code *)PTR_FUN_0600b650)(*(undefined4 *)(iVar8 + 0x24));
  (*(code *)PTR_FUN_0600b654)(*(undefined4 *)(iVar8 + 0x1c));
  (*(code *)PTR_FUN_0600b64c)
            (*(int *)(iVar8 + DAT_0600b632) + *(int *)(iVar8 + DAT_0600b632 + -0xc));
  if (*(int *)PTR_DAT_0600b658 != 0) {
    (*(code *)PTR_FUN_0600b65c)(puVar1,puVar1,puVar1);
    (*(code *)PTR_FUN_0600b664)(*(undefined4 *)(puVar7 + 0x18),*(undefined4 *)PTR_DAT_0600b660);
    puVar1 = PTR_DAT_0600b66c;
    (*(code *)PTR_FUN_0600b670)
              (*(undefined4 *)(puVar6 + 0x18),*(undefined2 *)PTR_DAT_0600b66c,
               *(undefined4 *)PTR_DAT_0600b668);
    (*(code *)PTR_FUN_0600b648)(0,*(undefined4 *)(iVar8 + DAT_0600b634));
    (*(code *)PTR_FUN_0600b650)(*(undefined4 *)(iVar8 + DAT_0600b636));
    (*(code *)PTR_FUN_0600b654)(*(int *)(iVar8 + PTR_DAT_0600b638._0_2_) + *(int *)PTR_DAT_0600b674)
    ;
    iVar4 = *(int *)(iVar5 + 0xc) * 4;
    (*(code *)PTR_FUN_0600b664)
              (*(undefined4 *)(puVar7 + iVar4),*(undefined4 *)(PTR_DAT_0600b678 + iVar4));
    iVar4 = *(int *)(iVar5 + 0xc) * 4;
    (*(code *)PTR_FUN_0600b6c8)
              (*(undefined4 *)(puVar6 + iVar4),*(undefined2 *)puVar1,
               *(undefined4 *)(PTR_DAT_0600b67c + iVar4));
  }
  *(int *)PTR_DAT_0600b6cc = *(int *)PTR_DAT_0600b6cc + -0x30;
  return;
}

