/* FUN_06016468  0x06016468 */


void FUN_06016468(byte param_1)

{
  undefined *puVar1;
  
  puVar1 = PTR_DAT_06016500;
  FUN_06016cdc(param_1,PTR_DAT_06016500[(short)((ushort)param_1 * 0x44) + 0x40]);
  *(undefined **)(puVar1 + (short)((ushort)param_1 * 0x44) + 0xc) = PTR_DAT_06016504;
  *(undefined **)(puVar1 + (short)((ushort)param_1 * 0x44) + 0x18) = PTR_DAT_06016508;
  *(undefined **)(puVar1 + (short)((ushort)param_1 * 0x44) + 0x24) = PTR_DAT_0601650c;
  puVar1[(short)((ushort)param_1 * 0x44) + 2] = puVar1[(short)((ushort)param_1 * 0x44) + 2] + '\x01'
  ;
  if (*PTR_DAT_06016510 != '\0') {
    PTR_DAT_06016500[(short)((ushort)param_1 * 0x44) + 2] = 3;
  }
  return;
}

