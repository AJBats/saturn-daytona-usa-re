/* FUN_0600579C  0x0600579C */


void FUN_0600579c(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  int iVar4;
  undefined2 *puVar5;
  undefined2 *puVar6;
  undefined2 *puVar7;
  undefined2 *puVar8;
  int iVar9;
  int iVar10;
  int unaff_r11;
  int iVar11;
  int unaff_r14;
  
  puVar3 = PTR_DAT_06005860;
  puVar2 = PTR_DAT_0600585c;
  puVar1 = PTR_DAT_06005858;
  iVar10 = (int)DAT_0600584e;
  (*(code *)PTR_FUN_06005864)(8,*(undefined4 *)(PTR_DAT_0600585c + 0x20));
  if (*puVar1 != '\0') {
    iVar9 = (int)DAT_06005850;
    iVar11 = unaff_r14;
    do {
      puVar5 = (undefined2 *)(*(int *)puVar3 + iVar9 + 0x18);
      puVar7 = (undefined2 *)(*(int *)puVar3 + iVar11 + 0x18);
      iVar4 = unaff_r11;
      do {
        iVar4 = iVar4 + -3;
        *puVar7 = *puVar5;
        puVar6 = puVar5 + 2;
        puVar7[1] = puVar5[1];
        puVar8 = puVar7 + 2;
        puVar5 = puVar5 + 3;
        puVar7 = puVar7 + 3;
        *puVar8 = *puVar6;
      } while (iVar4 != 0);
      iVar9 = iVar9 + unaff_r14;
      iVar11 = iVar11 + unaff_r14;
    } while (iVar9 < iVar10);
    (*(code *)PTR_FUN_0600586c)(8,(int)DAT_06005852,0x60,PTR_DAT_06005868);
  }
  if (*puVar1 == '\0') {
    iVar10 = 7;
  }
  else {
    iVar10 = 5;
  }
  if ((*(uint *)PTR_DAT_06005870 & 1) == 0) {
    (*(code *)PTR_FUN_06005864)
              (8,*(undefined4 *)(puVar2 + 0x28),(iVar10 * 0x40 + 0x19) * 2,
               *(undefined4 *)(puVar2 + 0x2c));
  }
  if (*(uint *)PTR_DAT_06005874 < 10) {
    (*(code *)PTR_FUN_06005878)(8,(int)PTR_DAT_06005854._0_2_,0,*(undefined4 *)PTR_DAT_06005874);
  }
  else {
    (*(code *)PTR_FUN_06005914)(8,(int)DAT_0600590c,0xc,*(undefined4 *)PTR_DAT_06005874);
  }
  if (*(int *)PTR_DAT_06005918 == 0) {
    (*(code *)PTR_FUN_06005914)(8,(int)DAT_0600590e,0x30,*(undefined4 *)PTR_DAT_0600591c);
  }
  if (*(int *)PTR_DAT_06005920 == 0) {
    if (*puVar1 == '\0') {
      iVar10 = 6;
    }
    else {
      iVar10 = 4;
    }
    (*(code *)PTR_FUN_06005924)
              (8,*(undefined4 *)(puVar2 + 0x30),(iVar10 * 0x40 + 0x16) * 2,
               *(int *)(puVar2 + 0x34) + (int)DAT_06005910);
    return;
  }
  return;
}

