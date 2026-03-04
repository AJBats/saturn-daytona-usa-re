/* FUN_06016CE6  0x06016CE6 */


void FUN_06016ce6(byte param_1,byte param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  short in_r3;
  int iVar3;
  uint uVar4;
  byte unaff_r14;
  
  puVar1 = PTR_DAT_06016dc0;
  PTR_DAT_06016dc0[(short)(in_r3 * 0x44) + 1] = param_1;
  uVar4 = (uint)param_1;
  if (((uint)(*PTR_DAT_06016dc4 == '\0') & *(uint *)PTR_DAT_06016dc8) != 0) {
    uVar4 = 0x28;
    *(undefined **)(puVar1 + (short)((ushort)unaff_r14 * 0x44) + 0x2c) = PTR_DAT_06016dcc;
  }
  puVar2 = PTR_DAT_06016dd0;
  iVar3 = (uint)param_2 * 5 + uVar4;
  *(int *)(puVar1 + (short)((ushort)unaff_r14 * 0x44) + 4) =
       (int)*(short *)(PTR_DAT_06016dd0 + iVar3 * 2) << 0x10;
  *(int *)(puVar1 + (short)((ushort)unaff_r14 * 0x44) + 8) =
       (int)*(short *)(puVar2 + (iVar3 + 1) * 2) << 0x10;
  *(int *)(puVar1 + (short)((ushort)unaff_r14 * 0x44) + 0xc) =
       (int)*(short *)(puVar2 + (iVar3 + 2) * 2) << 0x10;
  *(int *)(puVar1 + (short)((ushort)unaff_r14 * 0x44) + 0x10) =
       (int)*(short *)(puVar2 + (iVar3 + 3) * 2) << 0x10;
  *(int *)(puVar1 + (short)((ushort)unaff_r14 * 0x44) + 0x34) =
       (int)*(short *)(puVar2 + (iVar3 + 4) * 2) << 0x10;
  FUN_06016dd8(unaff_r14);
  puVar1 = PTR_DAT_06016dd4;
  *(ushort *)(PTR_DAT_06016dd4 + (short)((ushort)unaff_r14 * 0x18) + 6) = param_2 + 0x17;
  puVar1[(short)((ushort)unaff_r14 * 0x18) + 4] = 1;
  puVar1[(short)((ushort)unaff_r14 * 0x18) + 5] = 0x3a;
  return;
}

