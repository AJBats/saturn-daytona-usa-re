/* FUN_06016A1C  0x06016A1C */


void FUN_06016a1c(byte param_1)

{
  undefined *puVar1;
  int in_r0;
  
  puVar1 = PTR_DAT_06016ad8;
  FUN_06016cdc(param_1,PTR_DAT_06016ad8[in_r0 + (short)((ushort)param_1 * 0x44)]);
  *(undefined **)(puVar1 + (short)((ushort)param_1 * 0x44) + 0xc) = PTR_DAT_06016adc;
  *(undefined **)(puVar1 + (short)((ushort)param_1 * 0x44) + 0x18) = PTR_DAT_06016ae0;
  *(undefined **)(puVar1 + (short)((ushort)param_1 * 0x44) + 0x24) = PTR_DAT_06016ae4;
  puVar1[(short)((ushort)param_1 * 0x44) + 2] = puVar1[(short)((ushort)param_1 * 0x44) + 2] + '\x01'
  ;
  return;
}

