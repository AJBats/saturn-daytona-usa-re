extern int DAT_060047d2;

extern int DAT_060047d4;

extern int DAT_0600498a;

extern int DAT_0600498c;

extern int DAT_0600498e;

extern int DAT_06004a88;

extern int DAT_06004a8a;

extern int DAT_06004a8c;

void FUN_06004670()
{

  short uVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  puVar3 = 0x06042CEE;

  puVar2 = 0x06063690;

  *(char **)0x06063690 = 0x06042CEE;

  *(short *)(puVar2 + 4) = DAT_060047d2;

  puVar2[6] = 1;

  puVar2[7] = 2;

  puVar2[9] = 1;

  *(short *)(puVar2 + 10) = (0x40 - (short)(char)puVar2[6] * (short)(char)puVar2[9]) * 2;

  puVar2[8] = puVar2[6] * puVar2[7] * '\x02';

  *(char **)(puVar2 + 0xc) = puVar3;

  *(short *)(puVar2 + 0x10) = DAT_060047d2;

  puVar2[0x12] = 1;

  puVar2[0x13] = 2;

  puVar2[0x15] = 2;

  *(short *)(puVar2 + 0x16) = (0x40 - (short)(char)puVar2[0x12] * (short)(char)puVar2[0x15]) * 2;

  puVar2[0x14] = puVar2[0x12] * puVar2[0x13] * '\x02';

  *(char **)(puVar2 + 0x18) = 0x06042D72;

  uVar1 = DAT_060047d4;

  *(short *)(puVar2 + 0x1c) = DAT_060047d4;

  puVar2[0x1e] = 2;

  puVar2[0x1f] = 2;

  puVar2[0x21] = 3;

  *(short *)(puVar2 + 0x22) = (0x40 - (short)(char)puVar2[0x1e] * (short)(char)puVar2[0x21]) * 2;

  puVar2[0x20] = puVar2[0x1e] * puVar2[0x1f] * '\x02';

  *(char **)(puVar2 + 0x24) = 0x06042D1A;

  *(short *)(puVar2 + 0x28) = uVar1;

  puVar2[0x2a] = 2;

  puVar2[0x2b] = 2;

  puVar2[0x2d] = 3;

  *(short *)(puVar2 + 0x2e) = (0x40 - (short)(char)puVar2[0x2a] * (short)(char)puVar2[0x2d]) * 2;

  puVar2[0x2c] = puVar2[0x2a] * puVar2[0x2b] * '\x02';

  *(char **)(puVar2 + 0x30) = 0x06042DCA;

  *(short *)(puVar2 + 0x34) = uVar1;

  puVar2[0x36] = 2;

  puVar2[0x37] = 3;

  puVar2[0x39] = 2;

  *(short *)(puVar2 + 0x3a) = (0x40 - (short)(char)puVar2[0x36] * (short)(char)puVar2[0x39]) * 2;

  puVar2[0x38] = puVar2[0x36] * puVar2[0x37] * '\x02';

  puVar3 = 0x06042CBC;

  *(char **)(puVar2 + 0x3c) = 0x06042CBC;

  *(short *)(puVar2 + 0x40) = uVar1;

  puVar2[0x42] = 1;

  puVar2[0x43] = 1;

  puVar2[0x45] = 2;

  *(short *)(puVar2 + 0x46) = (0x40 - (short)(char)puVar2[0x42] * (short)(char)puVar2[0x45]) * 2;

  puVar2[0x44] = puVar2[0x42] * puVar2[0x43] * '\x02';

  puVar4 = 0x06042CD2;

  *(char **)(puVar2 + 0x48) = 0x06042CD2;

  *(short *)(puVar2 + 0x4c) = uVar1;

  puVar2[0x4e] = 1;

  puVar2[0x4f] = 1;

  puVar2[0x51] = 0;

  *(short *)(puVar2 + 0x52) = 0;

  puVar2[0x50] = puVar2[0x4e] * puVar2[0x4f] * '\x02';

  *(char **)(puVar2 + 0x54) = puVar4;

  *(short *)(puVar2 + 0x58) = DAT_0600498a;

  puVar2[0x5a] = 1;

  puVar2[0x5b] = 1;

  puVar2[0x5d] = 0;

  *(short *)(puVar2 + 0x5e) = 0;

  puVar2[0x5c] = puVar2[0x5a] * puVar2[0x5b] * '\x02';

  *(char **)(puVar2 + 0x60) = 0x06042E4E;

  *(short *)(puVar2 + 100) = DAT_0600498c;

  puVar2[0x66] = 2;

  puVar2[0x67] = 2;

  puVar2[0x69] = 0x20;

  *(short *)(puVar2 + 0x6a) = 0;

  puVar2[0x68] = puVar2[0x66] * puVar2[0x67] * '\x02';

  *(char **)(puVar2 + 0x6c) = puVar3;

  *(short *)(puVar2 + 0x70) = DAT_0600498e;

  puVar2[0x72] = 1;

  puVar2[0x73] = 1;

  puVar2[0x75] = 1;

  *(short *)(puVar2 + 0x76) = (0x40 - (short)(char)puVar2[0x72] * (short)(char)puVar2[0x75]) * 2;

  puVar2[0x74] = puVar2[0x72] * puVar2[0x73] * '\x02';

  *(char **)(puVar2 + 0x78) = 0x0604304E;

  *(short *)(puVar2 + 0x7c) = DAT_0600498c;

  puVar2[0x7e] = 2;

  puVar2[0x7f] = 2;

  puVar2[0x81] = 0;

  *(short *)(puVar2 + 0x82) = 0;

  puVar2[0x80] = puVar2[0x7e] * puVar2[0x7f] * '\x02';

  *(char **)(puVar2 + 0x84) = puVar3;

  *(short *)(puVar2 + 0x88) = DAT_06004a88;

  puVar2[0x8a] = 1;

  puVar2[0x8b] = 1;

  puVar2[0x8d] = 1;

  *(short *)(puVar2 + 0x8e) = (0x40 - (short)(char)puVar2[0x8a] * (short)(char)puVar2[0x8d]) * 2;

  puVar2[0x8c] = puVar2[0x8a] * puVar2[0x8b] * '\x02';

  *(char **)(puVar2 + 0x90) = 0x06059CC0;

  *(short *)(puVar2 + 0x94) = DAT_06004a8a;

  puVar2[0x96] = 1;

  puVar2[0x97] = 2;

  puVar2[0x99] = 0x20;

  *(short *)(puVar2 + 0x9a) = 0;

  puVar2[0x98] = puVar2[0x96] * puVar2[0x97] * '\x02';

  *(char **)(puVar2 + 0x9c) = 0x06059DC0;

  *(short *)(puVar2 + 0xa0) = DAT_06004a8c;

  puVar2[0xa2] = 1;

  puVar2[0xa3] = 2;

  puVar2[0xa5] = 0;

  *(short *)(puVar2 + 0xa6) = 0;

  puVar2[0xa4] = puVar2[0xa2] * puVar2[0xa3] * '\x02';

  return;

}
