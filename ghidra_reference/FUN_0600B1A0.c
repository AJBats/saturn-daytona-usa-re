/* FUN_0600B1A0  0x0600B1A0 */


void FUN_0600b1a0(void)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  undefined *unaff_r12;
  undefined *puVar4;
  undefined *unaff_r13;
  undefined *puVar5;
  int iVar6;
  
  iVar3 = *(int *)PTR_DAT_0600b208;
  iVar6 = *(int *)PTR_DAT_0600b20c;
  *(int *)PTR_DAT_0600b210 = iVar6;
  iVar2 = *(int *)PTR_DAT_0600b214;
  puVar4 = PTR_PTR_0600b21c;
  puVar5 = PTR_LAB_0600b218;
  if (((iVar2 != 0) && (puVar4 = PTR_PTR_0600b224, puVar5 = PTR_PTR_0600b220, iVar2 != 1)) &&
     (puVar4 = unaff_r12, puVar5 = unaff_r13, iVar2 == 2)) {
    puVar4 = PTR_LAB_0600b22c;
    puVar5 = PTR_LAB_0600b228;
  }
  (*(code *)PTR_FUN_0600b304)();
  (*(code *)PTR_FUN_0600b308)
            (*(undefined4 *)(iVar6 + 0x10),*(undefined4 *)(iVar6 + 0x14),
             *(undefined4 *)(iVar6 + 0x18));
  (*(code *)PTR_FUN_0600b30c)(*(undefined4 *)(iVar6 + 0x20));
  (*(code *)PTR_FUN_0600b310)(*(undefined4 *)(iVar6 + 0x24));
  (*(code *)PTR_FUN_0600b314)(*(undefined4 *)(iVar6 + 0x1c));
  (*(code *)PTR_FUN_0600b30c)
            (*(int *)(iVar6 + DAT_0600b2fc) + *(int *)(iVar6 + DAT_0600b2fc + -0xc));
  if (*(int *)PTR_DAT_0600b318 != 0) {
    (*(code *)PTR_FUN_0600b320)(*(undefined4 *)(puVar5 + 0x18),*(undefined4 *)PTR_DAT_0600b31c);
    puVar1 = PTR_DAT_0600b328;
    (*(code *)PTR_FUN_0600b32c)
              (*(undefined4 *)(puVar4 + 0x18),(int)*(short *)PTR_DAT_0600b328,
               *(undefined4 *)PTR_DAT_0600b324);
    (*(code *)PTR_FUN_0600b308)(0,*(undefined4 *)(iVar6 + DAT_0600b2fe));
    (*(code *)PTR_FUN_0600b310)(*(undefined4 *)(iVar6 + DAT_0600b300));
    (*(code *)PTR_FUN_0600b314)(*(int *)(iVar6 + DAT_0600b302) + *(int *)PTR_DAT_0600b330);
    iVar2 = *(int *)(iVar3 + 0xc) * 4;
    (*(code *)PTR_FUN_0600b320)
              (*(undefined4 *)(puVar5 + iVar2),*(undefined4 *)(PTR_DAT_0600b334 + iVar2));
    iVar2 = *(int *)(iVar3 + 0xc) * 4;
    (*(code *)PTR_FUN_0600b32c)
              (*(undefined4 *)(puVar4 + iVar2),(int)*(short *)puVar1,
               *(undefined4 *)(PTR_DAT_0600b338 + iVar2));
    FUN_0600a614();
  }
  *(int *)PTR_DAT_0600b33c = *(int *)PTR_DAT_0600b33c + -0x30;
  return;
}

