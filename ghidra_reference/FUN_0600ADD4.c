/* FUN_0600ADD4  0x0600ADD4 */


void FUN_0600add4(void)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  
  puVar2 = PTR_FUN_0600ae50;
  puVar1 = PTR_DAT_0600ae4c;
  iVar4 = *(int *)PTR_DAT_0600ae54;
  *(int *)PTR_DAT_0600ae58 = iVar4;
  (*(code *)PTR_FUN_0600ae5c)();
  (*(code *)PTR_FUN_0600ae60)
            (*(undefined4 *)(iVar4 + 0x10),*(undefined4 *)(iVar4 + 0x14),
             *(undefined4 *)(iVar4 + 0x18));
  (*(code *)PTR_FUN_0600ae68)(PTR_DAT_0600ae64 + *(int *)(iVar4 + 0x20));
  (*(code *)PTR_FUN_0600ae6c)(-*(int *)(iVar4 + 0x24));
  if ((*(uint *)PTR_DAT_0600ae70 & (uint)PTR_DAT_0600ae74) == 0) {
    iVar3 = (*(int *)PTR_DAT_0600af1c - *(int *)(iVar4 + 0x1c)) +
            *(int *)(PTR_DAT_0600af20 + (uint)*(ushort *)puVar1 * 4);
  }
  else {
    iVar3 = *(int *)(PTR_DAT_0600ae78 + (uint)*(ushort *)puVar1 * 4) - *(int *)(iVar4 + 0x1c);
  }
  (*(code *)puVar2)(iVar3);
  (*(code *)PTR_FUN_0600af24)
            (*(int *)(iVar4 + DAT_0600af12) + *(int *)(iVar4 + DAT_0600af12 + -0xc));
  if (*(int *)PTR_DAT_0600af28 != 0) {
    (*(code *)PTR_FUN_0600af34)(*(undefined4 *)PTR_PTR_0600af30,*(undefined4 *)PTR_DAT_0600af2c);
    (*(code *)PTR_FUN_0600af44)
              (*(undefined4 *)PTR_PTR_0600af40,(int)*(short *)PTR_DAT_0600af3c,
               *(undefined4 *)PTR_DAT_0600af38);
    (*(code *)PTR_FUN_0600af48)(0,*(undefined4 *)(iVar4 + DAT_0600af14));
    (*(code *)PTR_FUN_0600af4c)(*(undefined4 *)(iVar4 + DAT_0600af16));
    (*(code *)puVar2)(*(undefined4 *)(iVar4 + PTR_DAT_0600af18._0_2_));
    if ((*PTR_DAT_0600af50 & 2) == 0) {
      FUN_0600aa98(iVar4,0);
    }
    iVar3 = 0;
    if ((*(byte *)(iVar4 + 1) & 1) == 0) {
      iVar4 = *(int *)PTR_DAT_0600b00c;
    }
    else {
      iVar3 = 0xd;
      iVar4 = (int)(char)PTR_PTR_0600af54[*(ushort *)puVar1] + *(int *)PTR_DAT_0600af58;
    }
    (*(code *)puVar2)(iVar4);
    iVar3 = iVar3 * 4;
    (*(code *)PTR_FUN_0600b018)
              (*(undefined4 *)(PTR_PTR_0600b014 + iVar3),*(undefined4 *)(PTR_DAT_0600b010 + iVar3));
    (*(code *)PTR_FUN_0600b028)
              (*(undefined4 *)(PTR_PTR_0600b024 + iVar3),(int)*(short *)PTR_DAT_0600b020,
               *(undefined4 *)(PTR_DAT_0600b01c + iVar3));
  }
  if ((*(uint *)PTR_DAT_0600b02c & (uint)PTR_DAT_0600b030) != 0) {
    (*(code *)PTR_FUN_0600b034)();
  }
  *(int *)PTR_DAT_0600b038 = *(int *)PTR_DAT_0600b038 + -0x30;
  return;
}

