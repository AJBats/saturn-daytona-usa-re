/* FUN_06016470  0x06016470 */


void FUN_06016470(void)

{
  undefined *puVar1;
  int in_r0;
  byte unaff_r13;
  
  puVar1 = PTR_DAT_06016500;
  FUN_06016cdc(unaff_r13,PTR_DAT_06016500[in_r0 + (short)((ushort)unaff_r13 * 0x44)]);
  *(undefined **)(puVar1 + (short)((ushort)unaff_r13 * 0x44) + 0xc) = PTR_DAT_06016504;
  *(undefined **)(puVar1 + (short)((ushort)unaff_r13 * 0x44) + 0x18) = PTR_DAT_06016508;
  *(undefined **)(puVar1 + (short)((ushort)unaff_r13 * 0x44) + 0x24) = PTR_DAT_0601650c;
  puVar1[(short)((ushort)unaff_r13 * 0x44) + 2] =
       puVar1[(short)((ushort)unaff_r13 * 0x44) + 2] + '\x01';
  if (*PTR_DAT_06016510 != '\0') {
    PTR_DAT_06016500[(short)((ushort)unaff_r13 * 0x44) + 2] = 3;
  }
  return;
}

