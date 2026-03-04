/* FUN_06016A18  0x06016A18 */


void FUN_06016a18(byte param_1)

{
  undefined *puVar1;
  
  puVar1 = PTR_DAT_06016ad8;
  FUN_06016cdc(param_1,PTR_DAT_06016ad8[(short)((ushort)param_1 * 0x44) + 0x40]);
  *(undefined **)(puVar1 + (short)((ushort)param_1 * 0x44) + 0xc) = PTR_DAT_06016adc;
  *(undefined **)(puVar1 + (short)((ushort)param_1 * 0x44) + 0x18) = PTR_DAT_06016ae0;
  *(undefined **)(puVar1 + (short)((ushort)param_1 * 0x44) + 0x24) = PTR_DAT_06016ae4;
  puVar1[(short)((ushort)param_1 * 0x44) + 2] = puVar1[(short)((ushort)param_1 * 0x44) + 2] + '\x01'
  ;
  return;
}

