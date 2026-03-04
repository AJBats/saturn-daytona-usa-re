/* FUN_0603836C  0x0603836C */


void FUN_0603836c(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  uint uVar5;
  ushort uVar6;
  ushort uVar7;
  
  puVar3 = PTR_DAT_06038494;
  puVar2 = PTR_DAT_06038490;
  puVar1 = PTR_DAT_0603848c;
  *(undefined **)PTR_DAT_0603849c = PTR_VDP2_TVMD_06038498;
  puVar4 = PTR_DAT_060384a0;
  *(short *)puVar2 = (short)PTR_DAT_060384a0;
  *(undefined2 *)(puVar2 + 2) = 0;
  *(undefined2 *)(puVar2 + 6) = 0;
  *(undefined2 *)(puVar2 + 0xc) = 0;
  *(short *)(puVar2 + 0xe) = (short)((uint)puVar4 >> 2);
  uVar7 = 0;
  do {
    uVar5 = (uint)uVar7;
    uVar7 = uVar7 + 1;
    *(short *)(puVar2 + uVar5 * 2 + 0x10) = (short)puVar1;
  } while (uVar7 < 8);
  *(undefined2 *)(puVar2 + 0x20) = 0;
  *(undefined2 *)(puVar2 + 0x22) = 0;
  *(undefined2 *)(puVar2 + 0x24) = 0;
  *(undefined2 *)(puVar2 + 0x26) = 0;
  *(undefined2 *)puVar3 = 0;
  *(undefined2 *)(puVar3 + 2) = 0;
  *(undefined2 *)(puVar3 + 4) = 0;
  *(undefined2 *)(puVar3 + 6) = 0;
  *(undefined2 *)(puVar3 + 8) = 0;
  *(undefined2 *)(puVar3 + 10) = 0;
  *(undefined2 *)(puVar3 + 0xc) = 0;
  *(undefined2 *)(puVar3 + 0xe) = 0;
  *(undefined2 *)(puVar3 + 0x10) = 0;
  *(undefined2 *)(puVar3 + 0x12) = 0;
  uVar6 = 0;
  *(undefined2 *)(puVar3 + 0x14) = 0;
  *(undefined2 *)(puVar3 + 0x16) = 0;
  uVar7 = uVar6;
  do {
    uVar5 = (uint)uVar7;
    uVar7 = uVar7 + 1;
    *(undefined2 *)(puVar3 + uVar5 * 2 + 0x18) = 0;
  } while (uVar7 < 8);
  do {
    uVar5 = (uint)uVar6;
    uVar6 = uVar6 + 1;
    *(undefined2 *)(puVar3 + uVar5 * 2 + 0x28) = 0;
    puVar1 = PTR_DAT_060384a4;
  } while (uVar6 < 0x10);
  *(undefined4 *)PTR_DAT_060384a4 = 0;
  *(undefined4 *)(puVar1 + 4) = 0;
  puVar2 = PTR_DAT_060384a8;
  *(undefined **)(puVar1 + 8) = PTR_DAT_060384a8;
  *(undefined **)(puVar1 + 0xc) = puVar2;
  *(undefined4 *)(puVar1 + 0x10) = 0;
  *(undefined4 *)(puVar1 + 0x14) = 0;
  *(undefined **)(puVar1 + 0x18) = puVar2;
  *(undefined **)(puVar1 + 0x1c) = puVar2;
  *(undefined2 *)(puVar1 + 0x20) = 0;
  *(undefined2 *)(puVar1 + 0x22) = 0;
  *(undefined2 *)(puVar1 + 0x24) = 0;
  *(undefined2 *)(puVar1 + 0x26) = 0;
  *(undefined2 *)(puVar1 + 0x28) = 0;
  *(undefined2 *)(puVar1 + 0x2a) = 0;
  *(undefined4 *)(puVar1 + 0x2c) = 0;
  *(undefined4 *)(puVar1 + 0x30) = 0;
  *(undefined4 *)(puVar1 + 0x34) = 0;
  *(undefined4 *)(puVar1 + 0x38) = 0;
  *(undefined4 *)(puVar1 + 0x3c) = 0;
  puVar1 = PTR_DAT_060384ac;
  *(undefined2 *)PTR_DAT_060384ac = 0;
  *(undefined2 *)(puVar1 + 2) = 0;
  *(undefined2 *)(puVar1 + 4) = 0;
  *(undefined2 *)(puVar1 + 6) = 0;
  *(undefined2 *)(puVar1 + 8) = 0;
  *(undefined2 *)(puVar1 + 10) = 0;
  *(undefined4 *)(puVar1 + 0xc) = 0;
  puVar1 = PTR_DAT_060384b0;
  *(undefined2 *)PTR_DAT_060384b0 = 0;
  *(undefined2 *)(puVar1 + 2) = 0;
  *(undefined2 *)(puVar1 + 4) = 0;
  *(undefined2 *)(puVar1 + 6) = 0;
  *(undefined2 *)(puVar1 + 8) = 0;
  *(undefined2 *)(puVar1 + 10) = 0;
  *(undefined2 *)(puVar1 + 0xc) = 0;
  *(undefined2 *)(puVar1 + 0xe) = 0;
  *(undefined2 *)(puVar1 + 0x10) = 0;
  *(undefined2 *)(puVar1 + 0x12) = 0;
  *(undefined2 *)(puVar1 + 0x14) = 0;
  *(undefined2 *)(puVar1 + 0x16) = 0;
  *(undefined4 *)(puVar1 + 0x18) = 0;
  *(undefined4 *)(puVar1 + 0x1c) = 0;
  if (*(short *)PTR_DAT_06038534 == 0) {
    *(undefined2 *)PTR_DAT_06038534 = 1;
  }
  return;
}

