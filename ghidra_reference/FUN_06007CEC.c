/* FUN_06007CEC  0x06007CEC */


undefined4 FUN_06007cec(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  
  puVar5 = PTR_DAT_06007db4;
  puVar4 = PTR_DAT_06007db0;
  puVar3 = PTR_DAT_06007dac;
  puVar2 = PTR_DAT_06007da8;
  puVar1 = PTR_FUN_06007da4;
  uVar6 = (*(code *)PTR_FUN_06007db8)();
  for (uVar7 = 0; uVar7 < *(uint *)PTR_DAT_06007dc0; uVar7 = uVar7 + 1) {
    uVar8 = (uint)*(ushort *)(puVar2 + uVar7 * 2);
    if (*(short *)(puVar4 + (uVar8 * 0x18 & 0xffff) + 6) == 9) {
      uVar6 = (*(code *)puVar1)(puVar4 + (uVar8 * 0x18 & 0xffff),*(undefined4 *)puVar5,puVar3);
    }
    else {
      uVar6 = (*(code *)PTR_FUN_06007dbc)(puVar4 + (uVar8 * 0x18 & 0xffff),*(undefined4 *)puVar5);
    }
    *(int *)puVar5 = *(int *)puVar5 + 0x20;
  }
  *(short *)PTR_DAT_06007dc8 = (short)PTR_DAT_06007dc4;
  return uVar6;
}

