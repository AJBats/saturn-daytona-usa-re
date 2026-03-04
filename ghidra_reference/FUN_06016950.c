/* FUN_06016950  0x06016950 */


void FUN_06016950(undefined4 param_1)

{
  undefined *puVar1;
  int iVar2;
  int in_r2;
  int in_r3;
  int iVar3;
  undefined *puVar4;
  char unaff_r11;
  byte unaff_r14;
  
  puVar1 = PTR_DAT_06016a10;
  if (in_r3 < in_r2) {
    puVar4 = PTR_DAT_06016a10 + (short)((ushort)unaff_r14 * 0x44);
    iVar2 = (*(code *)PTR_FUN_06016a14)();
    iVar3 = *(int *)(puVar4 + 0x30);
    *(int *)(puVar4 + 0x30) = iVar3 + iVar2;
    if (iVar3 + iVar2 <= *(int *)(puVar4 + 0x38)) {
      *(undefined4 *)(puVar1 + (short)((ushort)unaff_r14 * 0x44) + 0x30) =
           *(undefined4 *)(puVar1 + (short)((ushort)unaff_r14 * 0x44) + 0x38);
      unaff_r11 = '\x01';
    }
  }
  else {
    iVar2 = (*(code *)PTR_FUN_06016a14)(param_1,4);
    *(int *)(puVar1 + (short)((ushort)unaff_r14 * 0x44) + 0x30) =
         *(int *)(puVar1 + (short)((ushort)unaff_r14 * 0x44) + 0x30) + iVar2;
    FUN_06016dd8(unaff_r14);
    if (*(int *)(puVar1 + (short)((ushort)unaff_r14 * 0x44) + 0x38) <=
        *(int *)(puVar1 + (short)((ushort)unaff_r14 * 0x44) + 0x30)) {
      *(undefined4 *)(puVar1 + (short)((ushort)unaff_r14 * 0x44) + 0x30) =
           *(undefined4 *)(puVar1 + (short)((ushort)unaff_r14 * 0x44) + 0x38);
      unaff_r11 = '\x01';
    }
  }
  FUN_06016dd8(unaff_r14);
  if (unaff_r11 != '\0') {
    puVar1[(short)((ushort)unaff_r14 * 0x44) + 2] = 2;
  }
  return;
}

