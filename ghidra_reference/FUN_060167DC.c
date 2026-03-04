/* FUN_060167DC  0x060167DC */


void FUN_060167dc(short param_1)

{
  undefined *puVar1;
  int iVar2;
  short in_r3;
  int iVar3;
  uint uVar4;
  uint unaff_r12;
  byte unaff_r14;
  
  puVar1 = PTR_DAT_06016870;
  iVar2 = (int)DAT_0601686c;
  param_1 = param_1 + in_r3 * 0x10;
  iVar3 = *(int *)(PTR_DAT_06016870 + param_1 + 0x2c);
  *(int *)(PTR_DAT_06016870 + param_1 + 0x2c) = iVar3 + iVar2;
  uVar4 = unaff_r12 & 0xff;
  if (*(int *)(puVar1 + param_1 + 0x3c) <= iVar3 + iVar2) {
    *(undefined4 *)(puVar1 + (short)((ushort)unaff_r14 * 0x44) + 0x2c) =
         *(undefined4 *)(puVar1 + (short)((ushort)unaff_r14 * 0x44) + 0x3c);
    uVar4 = 1;
  }
  if (*(int *)(puVar1 + (short)((ushort)unaff_r14 * 0x44) + 0x30) != 0) {
    if (unaff_r14 < 7) {
      iVar2 = *(int *)(puVar1 + (short)((ushort)unaff_r14 * 0x44) + 0x30) + (int)DAT_0601686e;
      *(int *)(puVar1 + (short)((ushort)unaff_r14 * 0x44) + 0x30) = iVar2;
      if (-1 < iVar2) {
        *(uint *)(puVar1 + (short)((ushort)unaff_r14 * 0x44) + 0x30) = unaff_r12;
      }
    }
    else {
      iVar2 = *(int *)(puVar1 + (short)((ushort)unaff_r14 * 0x44) + 0x30) - (int)DAT_0601686e;
      *(int *)(puVar1 + (short)((ushort)unaff_r14 * 0x44) + 0x30) = iVar2;
      if (iVar2 < 1) {
        *(uint *)(puVar1 + (short)((ushort)unaff_r14 * 0x44) + 0x30) = unaff_r12;
      }
    }
  }
  FUN_06016dd8(unaff_r14);
  if (uVar4 != 0) {
    puVar1[(short)((ushort)unaff_r14 * 0x44) + 0x41] = 4;
    puVar1[(short)((ushort)unaff_r14 * 0x44) + 2] = 3;
  }
  return;
}

