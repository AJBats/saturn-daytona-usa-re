/* FUN_0603D7B0  0x0603D7B0 */


uint FUN_0603d7b0(uint param_1)

{
  undefined *puVar1;
  uint uVar2;
  undefined *puVar3;
  uint uVar4;
  undefined *puVar5;
  
  puVar1 = PTR_DAT_0603d8c8;
  uVar4 = 1;
  puVar5 = PTR_DAT_0603d8c8 + -1;
  puVar3 = PTR_DAT_0603d8d0;
  (*(code *)PTR_FUN_0603d8d4)();
  *(ushort *)(puVar3 + 2) = *(ushort *)(puVar3 + 2) & (ushort)PTR_DAT_0603d8d8;
  (*(code *)PTR_FUN_0603d8d4)();
  *(ushort *)(puVar3 + 2) = *(ushort *)(puVar3 + 2) & (ushort)puVar1;
  (*(code *)PTR_FUN_0603d8d4)();
  *(ushort *)(puVar3 + 2) = *(ushort *)(puVar3 + 2) & (ushort)puVar5;
  (*(code *)PTR_FUN_0603d8d4)();
  *(ushort *)(puVar3 + 2) = *(ushort *)(puVar3 + 2) & (ushort)PTR_DAT_0603d8dc;
  (*(code *)PTR_FUN_0603d8d4)();
  *(ushort *)(puVar3 + 2) = *(ushort *)(puVar3 + 2) & (ushort)PTR_DAT_0603d8e0;
  (*(code *)PTR_FUN_0603d8d4)();
  *(ushort *)(puVar3 + 2) = *(ushort *)(puVar3 + 2) & (ushort)PTR_DAT_0603d8e4;
  (*(code *)PTR_FUN_0603d8d4)();
  uVar2 = (uint)*(ushort *)(puVar3 + 2) & (uint)PTR_DAT_0603d8e8;
  *(short *)(puVar3 + 2) = (short)uVar2;
  if (param_1 != 0) {
    (*(code *)PTR_FUN_0603d8d4)();
    uVar2 = (uint)*(ushort *)(puVar3 + 2) & (uint)PTR_DAT_0603d8d8 | (uint)PTR_DAT_0603d8c4._0_2_;
    *(short *)(puVar3 + 2) = (short)uVar2;
    if ((param_1 & 4) != 0) {
      (*(code *)PTR_FUN_0603d8d4)();
      uVar2 = (uint)*(ushort *)(puVar3 + 2) & (uint)puVar1 | uVar4 & 0xffff;
      *(short *)(puVar3 + 2) = (short)uVar2;
    }
    if ((param_1 & 2) != 0) {
      (*(code *)PTR_FUN_0603d9d4)();
      uVar2 = (uint)*(ushort *)(puVar3 + 2) & (uint)puVar1 | uVar4 & 0xffff;
      *(short *)(puVar3 + 2) = (short)uVar2;
    }
    if ((param_1 & 8) != 0) {
      (*(code *)PTR_FUN_0603d9d4)();
      uVar2 = (uint)*(ushort *)(puVar3 + 2) & (uint)puVar5 | 2;
      *(short *)(puVar3 + 2) = (short)uVar2;
    }
    if (((int)PTR_DAT_0603d9d0._0_2_ & param_1) != 0) {
      (*(code *)PTR_FUN_0603d9d4)();
      uVar2 = (uint)*(ushort *)(puVar3 + 2) & (uint)puVar5 | 2;
      *(short *)(puVar3 + 2) = (short)uVar2;
    }
    if ((param_1 & 0x10) != 0) {
      (*(code *)PTR_FUN_0603d9d4)();
      uVar2 = (uint)*(ushort *)(puVar3 + 2) & (uint)PTR_DAT_0603d9d8 | 4;
      *(short *)(puVar3 + 2) = (short)uVar2;
    }
    if ((param_1 & 0x20) != 0) {
      (*(code *)PTR_FUN_0603d9d4)();
      uVar2 = (uint)*(ushort *)(puVar3 + 2) & (uint)PTR_DAT_0603d9dc | 8;
      *(short *)(puVar3 + 2) = (short)uVar2;
    }
    if ((param_1 & uVar4) != 0) {
      (*(code *)PTR_FUN_0603d9d4)();
      uVar2 = (uint)*(ushort *)(puVar3 + 2) & (uint)PTR_DAT_0603d9e0 | 0x10;
      *(short *)(puVar3 + 2) = (short)uVar2;
    }
    if ((param_1 & (uint)PTR_DAT_0603d9e4) != 0) {
      (*(code *)PTR_FUN_0603d9d4)();
      uVar2 = (uint)*(ushort *)(puVar3 + 2) & (uint)PTR_DAT_0603d9e8 | 0x20;
      *(short *)(puVar3 + 2) = (short)uVar2;
    }
  }
  return uVar2;
}

