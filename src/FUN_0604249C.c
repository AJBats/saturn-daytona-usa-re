extern int DAT_060424c8;

extern int DAT_060424ca;

int FUN_0604249c(param_1)
    int param_1;
{

  int iVar1;

  iVar1 = ((unsigned int)((int)0x005A0000 - param_1) >> 0x10) << 2;

  return (unsigned int)*(unsigned short *)(&DAT_060424ca + iVar1) +

         ((unsigned int)*(unsigned short *)(&DAT_060424c8 + iVar1) * ((int)0x005A0000 - param_1 & 0xffffU) >>

         0x10);

}
