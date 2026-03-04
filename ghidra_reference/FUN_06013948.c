/* FUN_06013948  0x06013948 */


void FUN_06013948(void)

{
  short sVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  
  puVar4 = PTR_DAT_06013a38;
  puVar3 = PTR_DAT_06013a34;
  puVar2 = PTR_FUN_06013a30;
  iVar10 = (int)DAT_06013a28;
  sVar1 = *(short *)PTR_DAT_06013a34;
  *(short *)PTR_DAT_06013a34 = sVar1 + -1;
  if ((short)(sVar1 + -1) == 0) {
    *PTR_DAT_06013a3c = 2;
  }
  (*(code *)PTR_FUN_06013a40)();
  puVar5 = PTR_DAT_06013a48;
  iVar8 = 0;
  piVar7 = (int *)(PTR_PTR_06013a44 + DAT_06013a2a);
  piVar9 = (int *)PTR_PTR_06013a44;
  do {
    (*(code *)PTR_FUN_06013a4c)();
    (*(code *)puVar2)(0,(int)DAT_06013a2c,puVar4);
    (*(code *)PTR_FUN_06013a50)((int)*(short *)(piVar9 + 6));
    iVar6 = (*(code *)PTR_FUN_06013a54)((uint)*(ushort *)puVar3 * (int)puVar4,(int)DAT_06013a2e);
    (*(code *)puVar2)(0,*piVar9 + iVar6,0);
    (*(code *)PTR_FUN_06013a50)(-(int)*(short *)(piVar9 + 6));
    (*(code *)PTR_FUN_06013a58)((uint)*(ushort *)puVar3 << 0xb);
    (*(code *)PTR_FUN_06013a5c)(iVar10,iVar10,iVar10);
    (*(code *)PTR_FUN_06013a64)(*(undefined4 *)(PTR_PTR_06013a60 + iVar8),4);
    (*(code *)PTR_FUN_06013a6c)(*(undefined4 *)(PTR_PTR_06013a68 + iVar8),(int)*(short *)puVar5,1);
    piVar9 = piVar9 + 8;
    *(int *)PTR_DAT_06013a70 = *(int *)PTR_DAT_06013a70 + -0x30;
    iVar8 = iVar8 + 4;
  } while (piVar9 < piVar7);
  return;
}

