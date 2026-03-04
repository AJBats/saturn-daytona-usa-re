/* FUN_06015754  0x06015754 */


void FUN_06015754(short param_1)

{
  undefined *puVar1;
  byte unaff_r14;
  
  puVar1 = PTR_DAT_060157c8;
  *(int *)(PTR_DAT_060157c8 + (short)(param_1 * 0x44) + 4) =
       *(int *)(PTR_DAT_060157c8 + (short)(param_1 * 0x44) + 4) +
       *(int *)(PTR_DAT_060157c8 + (short)(param_1 * 0x44) + 0x10);
  *(int *)(puVar1 + (short)(param_1 * 0x44) + 8) =
       *(int *)(puVar1 + (short)(param_1 * 0x44) + 8) +
       *(int *)(puVar1 + (short)(param_1 * 0x44) + 0x14);
  *(int *)(puVar1 + (short)(param_1 * 0x44) + 0xc) =
       *(int *)(puVar1 + (short)(param_1 * 0x44) + 0xc) +
       *(int *)(puVar1 + (short)(param_1 * 0x44) + 0x18);
  if (unaff_r14 == 1 || unaff_r14 == 3) {
    if (*(int *)(puVar1 + (short)((ushort)unaff_r14 * 0x44) + 0x34) <=
        *(int *)(puVar1 + (short)((ushort)unaff_r14 * 0x44) + 4)) {
      *(undefined4 *)(puVar1 + (short)((ushort)unaff_r14 * 0x44) + 4) =
           *(undefined4 *)(puVar1 + (short)((ushort)unaff_r14 * 0x44) + 0x34);
    }
  }
  else if (*(int *)(puVar1 + (short)((ushort)unaff_r14 * 0x44) + 4) <=
           *(int *)(puVar1 + (short)((ushort)unaff_r14 * 0x44) + 0x34)) {
    *(undefined4 *)(puVar1 + (short)((ushort)unaff_r14 * 0x44) + 4) =
         *(undefined4 *)(puVar1 + (short)((ushort)unaff_r14 * 0x44) + 0x34);
  }
  if (-1 < *(int *)(puVar1 + (short)((ushort)unaff_r14 * 0x44) + 8)) {
    *(undefined4 *)(puVar1 + (short)((ushort)unaff_r14 * 0x44) + 8) = 0;
  }
  if ((int)PTR_DAT_060158a8 <= *(int *)(puVar1 + (short)((ushort)unaff_r14 * 0x44) + 0xc)) {
    *(undefined **)(puVar1 + (short)((ushort)unaff_r14 * 0x44) + 0xc) = PTR_DAT_060158a8;
  }
  (*(code *)PTR_FUN_060158ac)(unaff_r14);
  puVar1[(short)((ushort)unaff_r14 * 0x44) + 0x41] =
       puVar1[(short)((ushort)unaff_r14 * 0x44) + 0x41] + -1;
  if (puVar1[(short)((ushort)unaff_r14 * 0x44) + 0x41] == '\0') {
    puVar1[(short)((ushort)unaff_r14 * 0x44) + 2] =
         puVar1[(short)((ushort)unaff_r14 * 0x44) + 2] + '\x01';
  }
  return;
}

