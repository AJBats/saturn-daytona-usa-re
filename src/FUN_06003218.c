extern int DAT_060032b2;

extern int DAT_060032b4;

extern int DAT_060032b6;

extern int DAT_060032b8;

void FUN_06003218()
{

  char *puVar1;

  unsigned char *pbVar2;

  (*(int(*)())(*(int *)0x06000310))(0x65,0x060072E4);

  *(unsigned char *)-496 = *(unsigned char *)-496 & 0xf | 8;

  *(unsigned char *)-495 = *(unsigned char *)-495 | 1;

  pbVar2 = (unsigned char *)-490;

  *pbVar2 = *pbVar2 & 0xfc;

  pbVar2[1] = pbVar2[1] & 0xef;

  puVar1 = (char *)-492;

  *puVar1 = 1;

  puVar1[1] = 0x66;

  puVar1[-2] = 0;

  puVar1[-1] = 0;

  return;

}
