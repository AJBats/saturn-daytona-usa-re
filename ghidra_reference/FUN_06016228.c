/* FUN_06016228  0x06016228 */


void FUN_06016228(uint param_1)

{
  ushort uVar1;
  undefined *puVar2;
  int iVar3;
  short *psVar4;
  
  puVar2 = PTR_DAT_0601628c;
  uVar1 = (ushort)param_1 & 0xff;
  *(undefined4 *)(PTR_DAT_0601628c + (short)(uVar1 * 0x44) + 0x2c) = 0;
  psVar4 = (short *)(PTR_DAT_06016290 + (param_1 & 0xff) * 8);
  *(int *)(puVar2 + (short)(uVar1 * 0x44) + 0x34) = (int)*psVar4 << 0x10;
  *(int *)(puVar2 + (short)(uVar1 * 0x44) + 0x10) = (int)psVar4[1] << 0x10;
  iVar3 = (*(code *)PTR_FUN_06016294)((int)psVar4[1]);
  *(int *)(puVar2 + (short)(uVar1 * 0x44) + 0x24) = iVar3 << 0x10;
  *(int *)(puVar2 + (short)(uVar1 * 0x44) + 0x20) = (int)psVar4[3] << 0x10;
  puVar2[(short)(uVar1 * 0x44) + 2] = puVar2[(short)(uVar1 * 0x44) + 2] + '\x01';
  return;
}

