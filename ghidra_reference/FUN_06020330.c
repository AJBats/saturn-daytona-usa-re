/* FUN_06020330  0x06020330 */


void FUN_06020330(byte param_1)

{
  if (*(short *)PTR_DAT_060203c0 != 0) {
    FUN_06020366((int)(char)PTR_DAT_060203c4[(short)((ushort)param_1 * 0x44) + 0x40]);
  }
  FUN_06020dee(param_1);
  return;
}

