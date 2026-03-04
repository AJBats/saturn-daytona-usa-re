/* FUN_0601574C  0x0601574C */


void FUN_0601574c(byte param_1)

{
  undefined *puVar1;
  
  puVar1 = PTR_DAT_060157c8;
  *(int *)(PTR_DAT_060157c8 + (short)((ushort)param_1 * 0x44) + 4) =
       *(int *)(PTR_DAT_060157c8 + (short)((ushort)param_1 * 0x44) + 4) +
       *(int *)(PTR_DAT_060157c8 + (short)((ushort)param_1 * 0x44) + 0x10);
  *(int *)(puVar1 + (short)((ushort)param_1 * 0x44) + 8) =
       *(int *)(puVar1 + (short)((ushort)param_1 * 0x44) + 8) +
       *(int *)(puVar1 + (short)((ushort)param_1 * 0x44) + 0x14);
  *(int *)(puVar1 + (short)((ushort)param_1 * 0x44) + 0xc) =
       *(int *)(puVar1 + (short)((ushort)param_1 * 0x44) + 0xc) +
       *(int *)(puVar1 + (short)((ushort)param_1 * 0x44) + 0x18);
  if (param_1 == 1 || param_1 == 3) {
    if (*(int *)(puVar1 + (short)((ushort)param_1 * 0x44) + 0x34) <=
        *(int *)(puVar1 + (short)((ushort)param_1 * 0x44) + 4)) {
      *(undefined4 *)(puVar1 + (short)((ushort)param_1 * 0x44) + 4) =
           *(undefined4 *)(puVar1 + (short)((ushort)param_1 * 0x44) + 0x34);
    }
  }
  else if (*(int *)(puVar1 + (short)((ushort)param_1 * 0x44) + 4) <=
           *(int *)(puVar1 + (short)((ushort)param_1 * 0x44) + 0x34)) {
    *(undefined4 *)(puVar1 + (short)((ushort)param_1 * 0x44) + 4) =
         *(undefined4 *)(puVar1 + (short)((ushort)param_1 * 0x44) + 0x34);
  }
  if (-1 < *(int *)(puVar1 + (short)((ushort)param_1 * 0x44) + 8)) {
    *(undefined4 *)(puVar1 + (short)((ushort)param_1 * 0x44) + 8) = 0;
  }
  if ((int)PTR_DAT_060158a8 <= *(int *)(puVar1 + (short)((ushort)param_1 * 0x44) + 0xc)) {
    *(undefined **)(puVar1 + (short)((ushort)param_1 * 0x44) + 0xc) = PTR_DAT_060158a8;
  }
  (*(code *)PTR_FUN_060158ac)(param_1);
  puVar1[(short)((ushort)param_1 * 0x44) + 0x41] =
       puVar1[(short)((ushort)param_1 * 0x44) + 0x41] + -1;
  if (puVar1[(short)((ushort)param_1 * 0x44) + 0x41] == '\0') {
    puVar1[(short)((ushort)param_1 * 0x44) + 2] =
         puVar1[(short)((ushort)param_1 * 0x44) + 2] + '\x01';
  }
  return;
}

