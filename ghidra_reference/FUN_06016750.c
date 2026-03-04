/* FUN_06016750  0x06016750 */


undefined4 FUN_06016750(ushort param_1)

{
  ushort uVar1;
  undefined *puVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  undefined1 auStack_14 [20];
  
  puVar4 = auStack_14;
  (*(code *)PTR_FUN_060167c0)();
  puVar2 = PTR_DAT_060167c4;
  uVar1 = param_1 & 0xff;
  *(undefined4 *)(PTR_DAT_060167c4 + (short)(uVar1 * 0x44) + 0x3c) =
       *(undefined4 *)(puVar4 + (uint)(byte)PTR_DAT_060167c4[(short)(uVar1 * 0x44) + 0x40] * 4);
  puVar2[(short)(uVar1 * 0x44) + 2] = puVar2[(short)(uVar1 * 0x44) + 2] + '\x01';
  uVar3 = 0x40;
  puVar2[(short)(uVar1 * 0x44) + 0x40] = puVar2[(short)(uVar1 * 0x44) + 0x40] + '\x01';
  if (4 < (byte)puVar2[(short)(uVar1 * 0x44) + 0x40]) {
    uVar3 = 2;
    puVar2[(short)((param_1 & 0xff) * 0x44) + 2] = 2;
  }
  return uVar3;
}

