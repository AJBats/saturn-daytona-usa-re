/* FUN_06016230  0x06016230 */


void FUN_06016230(uint param_1)

{
  undefined *puVar1;
  int iVar2;
  short in_r3;
  short *psVar3;
  short unaff_r14;
  short sVar4;
  
  puVar1 = PTR_DAT_0601628c;
  sVar4 = unaff_r14 * 4 + in_r3 * 0x40;
  *(undefined4 *)(PTR_DAT_0601628c + sVar4 + 0x2c) = 0;
  psVar3 = (short *)(PTR_DAT_06016290 + (param_1 & 0xff) * 8);
  *(int *)(puVar1 + sVar4 + 0x34) = (int)*psVar3 << 0x10;
  *(int *)(puVar1 + sVar4 + 0x10) = (int)psVar3[1] << 0x10;
  iVar2 = (*(code *)PTR_FUN_06016294)((int)psVar3[1]);
  *(int *)(puVar1 + sVar4 + 0x24) = iVar2 << 0x10;
  *(int *)(puVar1 + sVar4 + 0x20) = (int)psVar3[3] << 0x10;
  puVar1[sVar4 + 2] = puVar1[sVar4 + 2] + '\x01';
  return;
}

