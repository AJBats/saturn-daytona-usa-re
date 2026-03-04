/* FUN_0601667A  0x0601667A */


void FUN_0601667a(byte param_1)

{
  ushort uVar1;
  undefined *puVar2;
  byte bVar3;
  
  puVar2 = PTR_DAT_060166e0;
  bVar3 = 0;
  do {
    uVar1 = (ushort)bVar3;
    bVar3 = bVar3 + 1;
    puVar2[(short)(uVar1 * 0x44) + 2] = 6;
  } while (bVar3 < 8);
  puVar2[(short)((ushort)param_1 * 0x44) + 1] = 1;
  FUN_060172e4(param_1);
  return;
}

