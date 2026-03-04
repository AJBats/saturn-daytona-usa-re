/* FUN_06016634  0x06016634 */


void FUN_06016634(void)

{
  undefined *puVar1;
  undefined1 *puVar2;
  byte unaff_r14;
  undefined1 auStack_14 [20];
  
  puVar2 = auStack_14;
  (*(code *)PTR_FUN_060166d8)();
  puVar1 = PTR_DAT_060166e0;
  if (*PTR_DAT_060166dc != '\0') {
    *(undefined4 *)(PTR_DAT_060166e0 + (short)((ushort)unaff_r14 * 0x44) + 0x2c) = 0;
    *(int *)(puVar1 + (short)((ushort)unaff_r14 * 0x44) + 4) =
         (int)*(short *)(puVar2 + (uint)unaff_r14 * 2) << 0x10;
    FUN_06016dd8(unaff_r14);
  }
  return;
}

