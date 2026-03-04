/* FUN_0600C010  0x0600C010 */


void FUN_0600c010(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  int unaff_r11;
  uint unaff_r14;
  
  puVar3 = PTR_DAT_0600c09c;
  puVar2 = PTR_DAT_0600c098;
  puVar1 = PTR_DAT_0600c094;
  pbVar6 = (byte *)(int)DAT_0600c090;
  if (*PTR_DAT_0600c0a0 != '\0') {
    (*(code *)PTR_FUN_0600c0a8)(*(undefined4 *)PTR_DAT_0600c0a4);
  }
  if ((*(uint *)puVar1 & (uint)PTR_DAT_0600c0ac) == 0) {
    if (*PTR_DAT_0600c0b0 == '\0') {
      (*(code *)PTR_FUN_0600c0b8)();
    }
    else {
      (*(code *)PTR_FUN_0600c0b4)();
    }
  }
  if ((*(undefined **)puVar1 == PTR_DAT_0600c0bc) && (*(int *)PTR_DAT_0600c0c0 == 0)) {
    (*(code *)PTR_FUN_0600c0c4)();
  }
  iVar4 = *(int *)puVar2;
  *(int *)puVar2 = iVar4 + 0x30;
  (*(code *)PTR_FUN_0600c0cc)(iVar4 + 0x30,*(undefined4 *)PTR_DAT_0600c0c8,0x30);
  if (*(int *)PTR_DAT_0600c0d4 == 0) {
    *(short *)PTR_DAT_0600c0d0 = (short)(*(int *)PTR_DAT_0600c0d8 >> 1);
  }
  else {
    *(ushort *)PTR_DAT_0600c0d0 = (ushort)(byte)*puVar3;
  }
  *(undefined **)PTR_DAT_0600c18c = PTR_FUN_0600c188;
  *(short *)PTR_DAT_0600c194 = (short)PTR_DAT_0600c190;
  if ((*(uint *)puVar1 & (uint)PTR_DAT_0600c198) == 0) {
    (*(code *)PTR_FUN_0600c19c)();
  }
  (*(code *)PTR_FUN_0600c1a0)();
  FUN_0600b6a0();
  iVar4 = 0;
  if (*(undefined **)puVar1 != PTR_DAT_0600c1a4) {
    (*(code *)PTR_FUN_0600c1a8)();
  }
  do {
    iVar5 = iVar4;
    iVar4 = unaff_r11;
  } while ((*pbVar6 & unaff_r14) != unaff_r14);
  *pbVar6 = *pbVar6 & 0xf;
  if (iVar5 == 0) {
    if (unaff_r11 < (int)(uint)(byte)*puVar3) {
      *puVar3 = *puVar3 + -1;
    }
  }
  else if ((int)(uint)(byte)*puVar3 < *(int *)PTR_DAT_0600c1ac) {
    *puVar3 = *puVar3 + '\x01';
  }
  (*(code *)PTR_FUN_0600c1b0)();
  *(int *)puVar2 = *(int *)puVar2 + -0x30;
  return;
}

