extern int DAT_060032b2;

extern int DAT_060032b4;

extern int DAT_060032b6;

extern int DAT_060032b8;

void FUN_06003218()
{

  char *puVar1;

  unsigned char *pbVar2;

  (**(void **)0x06000310)(0x65,0x060072E4);

  *(unsigned char *)(int)DAT_060032b2 = *(unsigned char *)(int)DAT_060032b2 & 0xf | 8;

  *(unsigned char *)(int)DAT_060032b4 = *(unsigned char *)(int)DAT_060032b4 | 1;

  pbVar2 = (unsigned char *)(int)DAT_060032b6;

  *pbVar2 = *pbVar2 & 0xfc;

  pbVar2[1] = pbVar2[1] & 0xef;

  puVar1 = (char *)(int)DAT_060032b8;

  *puVar1 = 1;

  puVar1[1] = 0x66;

  puVar1[-2] = 0;

  puVar1[-1] = 0;

  return;

}
