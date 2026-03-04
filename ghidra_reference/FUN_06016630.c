/* FUN_06016630  0x06016630 */


void FUN_06016630(byte param_1)

{
  undefined *puVar1;
  undefined1 *puVar2;
  undefined1 auStack_18 [20];
  
  puVar2 = auStack_18;
  (*(code *)PTR_FUN_060166d8)();
  puVar1 = PTR_DAT_060166e0;
  if (*PTR_DAT_060166dc != '\0') {
    *(undefined4 *)(PTR_DAT_060166e0 + (short)((ushort)param_1 * 0x44) + 0x2c) = 0;
    *(int *)(puVar1 + (short)((ushort)param_1 * 0x44) + 4) =
         (int)*(short *)(puVar2 + (uint)param_1 * 2) << 0x10;
    FUN_06016dd8(param_1);
  }
  return;
}

