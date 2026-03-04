/* FUN_06015E78  0x06015E78 */


void FUN_06015e78(byte param_1)

{
  undefined *puVar1;
  
  puVar1 = PTR_DAT_06015eb4;
  PTR_DAT_06015eb4[(short)((ushort)param_1 * 0x44) + 0x41] = 0;
  FUN_06015eb8(param_1);
  puVar1[(short)((ushort)param_1 * 0x44) + 2] = puVar1[(short)((ushort)param_1 * 0x44) + 2] + '\x01'
  ;
  return;
}

