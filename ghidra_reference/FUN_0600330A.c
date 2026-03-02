extern int DAT_06003366;
extern int DAT_06003368;
extern int DAT_0600336c;
extern int DAT_0600336e;
extern int DAT_06003370;
extern int DAT_06003372;
extern int DAT_06003374;
extern int DAT_06003376;

void FUN_0600330a()
{
  register int func asm("r3") = 0x06028400;
  register int base asm("r2") = 0x06063750;
  int *puVar3;

  puVar3 = (int *)(base + DAT_06003366);
  (*(int(*)())func)(0xc, *puVar3, 0xbc8, puVar3[1] + (int)DAT_06003368);

  puVar3 = (int *)(base + DAT_0600336c);
  (*(int(*)())func)(0xc, *puVar3, (int)DAT_06003370, puVar3[1] + (int)DAT_0600336e);

  puVar3 = (int *)(base + DAT_06003372);
  (*(void(*)())func)(0xc, *puVar3, (int)DAT_06003376, puVar3[1] + (int)DAT_06003374);
}
