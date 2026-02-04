extern int DAT_060424c8;

extern int DAT_060424ca;

int FUN_060424a2(param_1)
    unsigned int param_1;
{

  int iVar1;

  iVar1 = (param_1 >> 0x10) << 2;

  return (unsigned int)*(unsigned short *)(&DAT_060424ca + iVar1) +

         ((unsigned int)*(unsigned short *)(&DAT_060424c8 + iVar1) * (param_1 & 0xffff) >> 0x10);

}
